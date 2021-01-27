#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
 public:
  Process(int pid);

  int Pid();                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

  // Accessors declaration
  int getProcessID();
  std::string getUser();
  std::string getCommand();
  float getCpuUtilization();
  std::string getRam();
  long int getUptime();

  // Mutators declaration
  void setUser();
  void setCommand();
  void setCpuUtilization();
  void setRam();
  void setUptime();

 private:
  int processID_{0};
  std::string user_{};
  std::string command_{};
  float cpuUtilization_{0};
  std::string ram_{};
  int upTime_{0};
  float prevCpu{0};
};

#endif