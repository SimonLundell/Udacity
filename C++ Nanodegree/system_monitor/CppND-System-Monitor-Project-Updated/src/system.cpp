#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"

using namespace std;

System::System() {
  setMemoryUtilization();
  setUpTime();
  setTotalProcesses();
  setRunningProcesses();
  setKernel();
  setOperatingSystem();
}

Processor& System::Cpu() { return cpu_; }

vector<Process>& System::Processes() {
  /*
  vector<Process> tempProcesses{};
  for (auto& i : LinuxParser::Pids()) {
    Process proc{i};
    tempProcesses.push_back(proc);
  }
  std::sort(tempProcesses.begin(), tempProcesses.end());
  processes_ = tempProcesses;
  */
  processes_.clear();
  const vector<int> &pids = LinuxParser::Pids();
  for (const int &pid : pids) {
    processes_.emplace_back(pid);
  }
  std::sort(processes_.begin(), processes_.end());
  
  return processes_;
}

std::string System::Kernel() { return getKernel(); }

float System::MemoryUtilization() { return getMemoryUtilization(); }

std::string System::OperatingSystem() { return getOperatingSystem(); }

int System::RunningProcesses() { return getRunningProcesses(); }

int System::TotalProcesses() { return getTotalProcesses(); }

long int System::UpTime() { return getUpTime(); }

void System::setMemoryUtilization() {
  memoryUtilization_ = LinuxParser::MemoryUtilization();
}
void System::setUpTime() { upTime_ = LinuxParser::UpTime(); }
void System::setTotalProcesses() {
  totalProcesses_ = LinuxParser::TotalProcesses();
}
void System::setRunningProcesses() {
  runningProcesses_ = LinuxParser::RunningProcesses();
}
void System::setKernel() { kernel_ = LinuxParser::Kernel(); }
void System::setOperatingSystem() {
  operatingSystem_ = LinuxParser::OperatingSystem();
}

float System::getMemoryUtilization() {
  setMemoryUtilization();
  return memoryUtilization_;
}

long int System::getUpTime() {
  setUpTime();
  return upTime_;
}

int System::getTotalProcesses() {
  setTotalProcesses();
  return totalProcesses_;
}
int System::getRunningProcesses() {
  setRunningProcesses();
  return runningProcesses_;
}

std::string System::getKernel() { return kernel_; }
std::string System::getOperatingSystem() { return operatingSystem_; }