#include "ADBManager.hpp"

#include <iostream>

core::ADBManager::ADBManager() {}

core::ADBManager::~ADBManager() {}

std::string core::ADBManager::executeCommand(std::string command) {
  std::string full_command = "adb " + command;
  std::string res;
  char buffer[128];

  FILE* pipe = popen(full_command.c_str(), "r");
  if (!pipe)
    return "error";

  while (fgets(buffer, sizeof buffer, pipe) != NULL)
    res += buffer;

  pclose(pipe);
  return res;
}

std::string core::ADBManager::executeCommandOnDevice(std::string command,
                                                     std::string device) {
  return executeCommand("-s " + device + " " + command);
}
