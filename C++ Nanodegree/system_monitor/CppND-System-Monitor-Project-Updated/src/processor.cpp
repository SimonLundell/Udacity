#include "processor.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "linux_parser.h"

using std::string;
using std::vector;

double Processor::Utilization() {
  float diffIdle = static_cast<float>(LinuxParser::IdleJiffies()) - prevCpuIdle;
  float diffTotal = static_cast<float>(LinuxParser::Jiffies()) - prevCpuTime;
  float diffUsage = (diffTotal - diffIdle) / diffTotal;
  prevCpuIdle = static_cast<float>(LinuxParser::IdleJiffies());
  prevCpuTime = static_cast<float>(LinuxParser::Jiffies());
  return diffUsage;
}