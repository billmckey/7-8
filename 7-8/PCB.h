#pragma once
#include <string>
struct PCB
{
	int processID;
	std::string processName;
	std::string processStatus;
	int commandCounter;
	int cpuRegisters[10];
};