#include "DeviceManager.hpp"

core::DeviceManager::DeviceManager() {
  _devices = {};
  _selectedDevice = "";
}

core::DeviceManager::~DeviceManager() {}

std::vector<std::string> core::DeviceManager::getDevices() {
  return _devices;
}
void core::DeviceManager::setDevices(std::vector<std::string> devices) {
  _devices = devices;
}

std::string core::DeviceManager::getDevice() {
  return _selectedDevice;
}

void core::DeviceManager::setDevice(std::string device) {
  _selectedDevice = device;
}
