#include "ADBManager.hpp"

core::ADBManager::ADBManager() {}

core::ADBManager::~ADBManager() {}

/**
 * Execute a command on the host machine
 * @param command std::string - Command to execute
 * @return std::string - Output of the command
 */
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

/**
 * Execute a command on a device
 * @param command std::string - Command to execute
 * @param device std::string - Device ID
 * @return std::string - Output of the command
 */
std::string core::ADBManager::executeCommandOnDevice(std::string command,
                                                     std::string device) {
  return executeCommand("-s " + device + " " + command);
}
