#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : processID_(pid) {
  setCpuUtilization();
  setRam();
  setUptime();
  setCommand();
  setUser();
}

int Process::Pid() { return getProcessID(); }

float Process::CpuUtilization() { return getCpuUtilization(); }

string Process::Command() { return getCommand(); }

string Process::Ram() { return getRam(); }

string Process::User() { return getUser(); }

long int Process::UpTime() { return getUptime(); }

bool Process::operator<(Process const& a) const {
  return a.cpuUtilization_ < this->cpuUtilization_;
}

// Accessors definition
int Process::getProcessID() { return processID_; }

std::string Process::getUser() { return user_; }

std::string Process::getCommand() {
  if (command_.length() > 40) {
    command_.erase(command_.begin() + 40, command_.end());
    return command_ + "...";
  }
  return command_;
}

float Process::getCpuUtilization() { return cpuUtilization_; }

std::string Process::getRam() { return ram_; }

long int Process::getUptime() { return upTime_; }

// Mutators definition
void Process::setUser() { user_ = LinuxParser::User(getProcessID()); }

void Process::setCommand() { command_ = LinuxParser::Command(getProcessID()); }

void Process::setCpuUtilization() {
  long int upTime = LinuxParser::UpTime();
  std::vector<float> tempCpuValues{};
  tempCpuValues = LinuxParser::processCpuUtilization(getProcessID());
  float uTime = tempCpuValues[0];
  float sTime = tempCpuValues[1];
  float cuTime = tempCpuValues[2];
  float csTime = tempCpuValues[3];
  float startTime = tempCpuValues[4];

  float totalTime = uTime + sTime;
  totalTime = totalTime + cuTime + csTime;

  float seconds =
      static_cast<float>(upTime - (startTime / sysconf(_SC_CLK_TCK)));
  float cpuUsage = ((totalTime / sysconf(_SC_CLK_TCK)) / seconds);

  float diffCpuUsage = cpuUsage - prevCpu;
  prevCpu = cpuUsage;

  cpuUtilization_ = diffCpuUsage;
}

void Process::setRam() { ram_ = LinuxParser::Ram(getProcessID()); }

void Process::setUptime() {
  long processUpTimeTicksSinceStart = LinuxParser::UpTime(getProcessID());
  long processUpTimeSinceStart;
  string sKernel = LinuxParser::Kernel();

  sKernel.erase(sKernel.begin() + 3, sKernel.end());
  float kernel = std::stof(sKernel);
  if (kernel < 2.6) {
    processUpTimeSinceStart =
        processUpTimeTicksSinceStart / LinuxParser::Jiffies();
  } else {
    processUpTimeSinceStart =
        processUpTimeTicksSinceStart / sysconf(_SC_CLK_TCK);
  }
  int processUpTime = LinuxParser::UpTime() - processUpTimeSinceStart;

  upTime_ = processUpTime;
}
