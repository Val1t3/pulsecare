#include "Core.hpp"

core::Core::Core()
{
    _devices = core::ADBManager::listDevices();
}

core::Core::~Core()
{
}

std::vector<std::string> core::Core::getDevices()
{
    return _devices;
}
