#include "ADBManager.hpp"

core::ADBManager::ADBManager()
{
}

core::ADBManager::~ADBManager()
{
}

std::string core::ADBManager::executeCommand(std::string command)
{
    std::string full_command = "adb " + command;
    std::string res;
    char buffer[128];

    FILE *pipe = popen(full_command.c_str(), "r");
    if (!pipe) throw std::runtime_error("error: Failed to execute command.");

    while(fgets(buffer, sizeof buffer, pipe) != NULL)
        res += buffer;

    pclose(pipe);
    return res;
}

std::string core::ADBManager::executeCommandOnDevice(std::string command, std::string device)
{
    return executeCommand("-s " + device + " " + command);
}

std::vector<std::string> core::ADBManager::listDevices()
{
    return {};
}