#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"

class System {
 public:
  System();
  Processor& Cpu();                   // TODO: See src/system.cpp
  std::vector<Process>& Processes();  // TODO: See src/system.cpp
  float MemoryUtilization();          // TODO: See src/system.cpp
  long UpTime();                      // TODO: See src/system.cpp
  int TotalProcesses();               // TODO: See src/system.cpp
  int RunningProcesses();             // TODO: See src/system.cpp
  std::string Kernel();               // TODO: See src/system.cpp
  std::string OperatingSystem();      // TODO: See src/system.cpp

  // Mutator declarations
  void setMemoryUtilization();
  void setUpTime();
  void setTotalProcesses();
  void setRunningProcesses();
  void setKernel();
  void setOperatingSystem();

  // Accessor definitions
  float getMemoryUtilization();
  long getUpTime();
  int getTotalProcesses();
  int getRunningProcesses();
  std::string getKernel();
  std::string getOperatingSystem();

 private:
  Processor cpu_{};
  std::vector<Process> processes_{};
  float memoryUtilization_{0};
  long int upTime_{0};
  int totalProcesses_{0};
  int runningProcesses_{0};
  std::string kernel_{};
  std::string operatingSystem_{};
};

#endif