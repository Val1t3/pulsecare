#include "DeviceManager.hpp"
#include "ADBManager.hpp"

#include <cstddef>
#include <string>

core::DeviceManager::DeviceManager() {
  _devices = {};
  _selectedDevice = "";

  setDevices();
}

core::DeviceManager::~DeviceManager() {}

std::vector<std::string> core::DeviceManager::getDevices() {
  return _devices;
}

/**
 * @brief Set the devices connected to the computer calling the 'devices' ADB command
 */
void core::DeviceManager::setDevices() {
  std::string outputAdb = core::ADBManager::executeCommand("devices");

  // Error handling: check if ADB command was successful
  if (outputAdb.compare("error") == 0)
    return;

  _devices = formatDevicesCommand(outputAdb);
}

/**
 * @brief Get the selected device
 *
 * @return std::string
 */
std::string core::DeviceManager::getSelectedDevice() {
  return _selectedDevice;
}

/**
 * @brief Set the selected device with the device ID
 *
 * @param device std::string - Device ID
 */
void core::DeviceManager::setSelectedDevice(std::string device) {
  _selectedDevice = device;
}

/**
 * @brief Format the output of the 'devices' ADB command
 *
 * @param output std::string - Output of the 'devices' ADB command
 * @return std::vector<std::string>
 */
std::vector<std::string> core::DeviceManager::formatDevicesCommand(
    std::string output) {
  std::vector<std::string> devices = {};

  // Split output
  size_t pos = 0;
  std::string token;

  while ((pos = output.find("\n")) != std::string::npos) {
    token = output.substr(0, pos);
    devices.push_back(token);
    output.erase(0, pos + 1);
  }

  devices.erase(devices.begin());  // Remove the header of the command
  devices.pop_back();              // Remove the empty line of the vector

  // For each device, keep only the device ID
  for (std::string& device : devices) {
    device = device.substr(0, device.find("\t"));
  }

  return devices;
}
