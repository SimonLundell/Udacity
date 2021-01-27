#include <bits/stdc++.h>
#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    if (file->d_type == DT_DIR) {
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

float LinuxParser::MemoryUtilization() {
  string line;
  string key;
  string value;
  float memTotal;
  float memFree;
  float memUsage;

  std::ifstream stream(kProcDirectory + kMeminfoFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key == filterMemTotalString) {
        memTotal = std::stof(value);
      } else if (key == filterMemFreeString) {
        memFree = std::stof(value);
      }
    }
  }
  stream.close();

  try {
    memUsage = (memTotal - memFree) / memTotal;
  } catch (...) {
    return 0;
  }
  return memUsage;
}

long int LinuxParser::UpTime() {
  string line;
  string key;
  string uptimeInclSuspend;
  string uptimeInclIdle;

  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    try {
      linestream >> uptimeInclSuspend >> uptimeInclIdle;
    } catch (...) {
      return 0.0;
    }
    stream.close();
  }
  return std::stol(uptimeInclSuspend);
}

long LinuxParser::Jiffies() {
  long jiffies;
  std::string key;
  std::string line;
  std::string value;

  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::stringstream linestream(line);
    while (linestream >> key) {
      if (key == filterCpu) {
        while (linestream >> value) {
          if (value == "") {
            value = "0";
            std::cout << "Invalid values Jiffies";
          }
          jiffies += std::stol(value);
        }
      }
    }
    stream.close();
    return jiffies;
  }
  return 0;
}

long LinuxParser::ActiveJiffies(int pid) {
  long processJiffies;
  string line;
  string ignore;
  string uTime, sTime;

  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    for (int i = 0; i < 13; i++) {
      linestream >> ignore;
    }
    linestream >> uTime >> sTime;
    if (uTime == "" || sTime == "") {
      uTime = "0";
      sTime = "0";
      std::cout << "Invalid values ActiveJiffies";
    }
    processJiffies = std::stol(uTime) + std::stol(sTime);

    stream.close();
    return processJiffies;
  }
  return 0;
}

long LinuxParser::ActiveJiffies() {
  string line;
  string key;
  string value;
  long activeJiffies = 0;

  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::stringstream linestream(line);
    while (linestream >> key) {
      if (key == filterCpu) {
        for (int i = 0; i < 3; i++) {
          linestream >> value;
          if (value == "") {
            value = "0";
            std::cout << "Invalid values ActiveJiffies"
                      << "\n";
          }
          activeJiffies += std::stol(value);
        }
      }
    }
    stream.close();
    return activeJiffies;
  }
  return 0;
}

long LinuxParser::IdleJiffies() {
  string line;
  string key;
  string value;
  string iowait;
  string ignore;

  long idleJiffies = 1;

  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    while (linestream >> key) {
      if (key == filterCpu) {
        for (int i = 0; i < 3; i++) {
          linestream >> ignore;
        }
        linestream >> value >> iowait;
        if (value == "" || iowait == "") {
          value = "0";
          iowait = "0";
          std::cout << "Invalid values IdleJiffies"
                    << "\n";
        }
        idleJiffies = std::stol(value) + std::stol(iowait);
      }
    }
    stream.close();
    return idleJiffies;
  }
  return 0;
}

vector<string> LinuxParser::CpuUtilization() {
  vector<string> cpuValues{};
  string key_;
  string line_;
  string user_, nice_, system_, idle_, iowait_, irq_, softirq_, steal_, guest_,
      guestnice_;

  std::ifstream statFile(LinuxParser::kProcDirectory +
                         LinuxParser::kStatFilename);
  if (statFile.is_open()) {
    while (std::getline(statFile, line_)) {
      std::istringstream linestream(line_);
      while (linestream >> key_ >> user_ >> nice_ >> system_ >> idle_ >>
             iowait_ >> irq_ >> softirq_ >> steal_ >> guest_ >> guestnice_) {
        if (key_ == filterCpu) {
          cpuValues.push_back(user_);
          cpuValues.push_back(nice_);
          cpuValues.push_back(system_);
          cpuValues.push_back(idle_);
          cpuValues.push_back(iowait_);
          cpuValues.push_back(irq_);
          cpuValues.push_back(softirq_);
          cpuValues.push_back(steal_);
          cpuValues.push_back(guest_);
          cpuValues.push_back(guestnice_);
        }
      }
    }
    return cpuValues;
  }
  return {};
}

int LinuxParser::TotalProcesses() {
  string line;
  string key;
  string value;
  int totalProcesses;

  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      if (linestream >> key >> value) {
        if (key == filterProcesses) {
          if (value == "") {
            value = "0";
            std::cout << "Invalid values TotalProcesses"
                      << "\n";
          }
          totalProcesses = std::stoi(value);
          stream.close();
          return totalProcesses;
        }
      }
    }
  }
  stream.close();

  return 0;
}

int LinuxParser::RunningProcesses() {
  string line;
  string key;
  string value;
  int runningProcesses;

  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      if (linestream >> key >> value) {
        if (key == filterRunningProcesses) {
          if (value == "") {
            value = "0";
            std::cout << "Invalid values RunningProcesses"
                      << "\n";
          }
          runningProcesses = std::stoi(value);
          stream.close();
          return runningProcesses;
        }
      }
    }
  }
  stream.close();

  return 0;
}

string LinuxParser::Command(int pid) {
  string line;
  string command;

  std::ifstream stream(LinuxParser::kProcDirectory + std::to_string(pid) +
                       LinuxParser::kCmdlineFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> command;
    }
    stream.close();
    return command;
  }
  return string();
}

string LinuxParser::Ram(int pid) {
  string line;
  string key;
  string value;
  string processRam;

  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      if (linestream >> key >> value) {
        if (key == filterProcMem) {
          if (value == "") {
            value = "0000";
            std::cout << "Invalid values Ram(pid)"
                      << "\n";
          }

          value.erase(value.end() - 3, value.end());
          processRam = value;
        }
      }
    }
    stream.close();
    return processRam;
  }
  return string();
}

string LinuxParser::Uid(int pid) {
  string line;
  string key, val1, val2, val3, val4;
  string uid;

  std::ifstream stream(LinuxParser::kProcDirectory + std::to_string(pid) +
                       LinuxParser::kStatusFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      if (linestream >> key >> val1 >> val2 >> val3 >> val4) {
        if (key == filterUID) {
          uid = val1;
        }
      }
    }
    stream.close();
    return uid;
  }
  return string{};
}

string LinuxParser::User(int pid) {
  string line;
  string key, val1, val2, val3;
  string id;
  string uid = LinuxParser::Uid(pid);

  std::ifstream stream(LinuxParser::kPasswordPath);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> val1 >> val2 >> val3) {
        if (val2 == uid && val3 == uid) {
          id = key;
        }
      }
    }
    stream.close();
    return id;
  }
  return string();
}

long LinuxParser::UpTime(int pid) {
  std::string line;
  std::string value;
  long processUptime;

  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    for (int i = 0; i < 22; i++) {
      linestream >> value;
    }
    if (value == "") {
      value = "0";
      std::cout << "Invalid values Uptime(pid)"
                << "\n";
    }
    processUptime = std::stol(value);
    stream.close();

    return processUptime;
  }
  return 0;
}

std::vector<float> LinuxParser::processCpuUtilization(int pid) {
  vector<float> cpuValues{};
  string line;
  string ignore;
  string uTime, sTime, cuTime, csTime, startTime;

  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    for (int i = 0; i < 13; i++) {
      linestream >> ignore;
    }

    linestream >> uTime >> sTime >> cuTime >> csTime;

    for (int j = 0; j < 4; j++) {
      linestream >> ignore;
    }

    linestream >> startTime;
  }
  stream.close();

  if (uTime == "") {
    uTime = "0";
    std::cout << "empty uTime";
  } else if (sTime == "") {
    sTime = "0";
    std::cout << "empty sTime";
  } else if (cuTime == "") {
    cuTime = "0";
    std::cout << "empty cuTime";
  } else if (csTime == "") {
    csTime = "0";
    std::cout << "empty csTime";
  } else if (startTime == "") {
    startTime = "0";
    std::cout << "empty startTime";
  }

  cpuValues.push_back(std::stof(uTime));
  cpuValues.push_back(std::stof(sTime));
  cpuValues.push_back(std::stof(cuTime));
  cpuValues.push_back(std::stof(csTime));
  cpuValues.push_back(std::stof(startTime));

  return cpuValues;
}