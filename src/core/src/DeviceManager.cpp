#include "DeviceManager.hpp"
#include "ADBManager.hpp"

#include <cstddef>
#include <iostream>
#include <string>

core::DeviceManager::DeviceManager() {
  _devices = {};
  _selectedDevice = nullptr;

  setDevices();
}

core::DeviceManager::~DeviceManager() {}

/**
 * @brief Get devices connected to the computer
 *
 * @return std::vector<core::device_t>
 */
std::vector<core::device_t> core::DeviceManager::getDevices() {
  return _devices;
}

/**
 * @brief Set the devices connected to the computer calling the 'devices -l' ADB command
 */
void core::DeviceManager::setDevices() {
  std::string outputAdb = core::ADBManager::executeCommand("devices -l");

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
core::device_t* core::DeviceManager::getSelectedDevice() {
  return _selectedDevice.get();
}

/**
 * @brief Set the selected device with the device ID, and throw an exception if the device ID is not found
 *
 * @param device std::string - Device ID
 */
void core::DeviceManager::setSelectedDevice(std::string device) {
  for (core::device_t& dev : _devices)
    if (dev.id.compare(device) == 0) {
      _selectedDevice = std::make_unique<core::device_t>(dev);
      return;
    }
  throw std::invalid_argument("Device ID not found");
}

/**
 * @brief Format the output of the 'devices -l' ADB command
 *
 * @param output std::string - Output of the 'devices -l' ADB command
 * @return std::vector<core::device_t>
 */
std::vector<core::device_t> core::DeviceManager::formatDevicesCommand(
    std::string output) {
  std::vector<std::string> devicesStr = {};
  std::vector<core::device_t> devices = {};

  // Split output
  size_t pos = 0;
  std::string token;

  while ((pos = output.find("\n")) != std::string::npos) {
    token = output.substr(0, pos);
    devicesStr.push_back(token);
    output.erase(0, pos + 1);
  }

  devicesStr.erase(devicesStr.begin());  // Remove the header of the command
  devicesStr.pop_back();                 // Remove the empty line of the vector

  // Parse the devices
  for (std::string& deviceStr : devicesStr) {
    std::string id, product, model, device;

    // Get the device ID
    size_t pos = deviceStr.find_first_of("\t ");
    if (pos != std::string::npos)
      id = deviceStr.substr(0, pos);
    std::cout << id << std::endl;

    // Get the product
    size_t posProd = deviceStr.find("product:");
    if (posProd != std::string::npos) {
      size_t posProdEnd = deviceStr.find(" ", posProd + 8);
      product = deviceStr.substr(posProd + 8, posProdEnd - posProd - 8);
    }
    std::cout << product << std::endl;

    // Get the model
    size_t posModel = deviceStr.find("model:");
    if (posModel != std::string::npos) {
      size_t posModelEnd = deviceStr.find(" ", posModel + 6);
      model = deviceStr.substr(posModel + 6, posModelEnd - posModel - 6);
    }

    // Get the device
    size_t posDevice = deviceStr.find("device:");
    if (posDevice != std::string::npos) {
      size_t posDeviceEnd = deviceStr.find(" ", posDevice + 7);
      device = deviceStr.substr(posDevice + 7, posDeviceEnd - posDevice - 7);
    }
    devices.push_back({id, product, model, device});
  }

  return devices;
}
