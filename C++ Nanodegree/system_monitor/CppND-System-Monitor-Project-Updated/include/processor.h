#include <linux_parser.h>
#include <string>

#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  double Utilization();

 private:
  float prevCpuIdle{0};
  float prevCpuTime{0};
};

#endif