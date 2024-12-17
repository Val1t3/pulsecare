#include "Core.hpp"
#include "ADBManager.hpp"

#include <iostream>
#include <map>
#include <sstream>
#include <string>

core::Core::Core(DeviceManager& deviceManager)
    : _deviceManager(deviceManager) {}

core::Core::~Core() {}

void core::Core::run() {
  // Run all the tests
  std::cout << "core test" << std::endl;
}

// --- EXTERNAL HARDWARE ---
//
// --- Battery ---
void core::Core::battery() {
  // Call the ADBManager to get the battery information
  std::string output = ADBManager::executeCommandOnDevice(
      "shell dumpsys battery", _deviceManager.getSelectedDevice()->id);

  // Parse the output
  // convert std::string to hashmap with: key - left part and value - right part
  std::map<std::string, std::string> battery_info;
  std::string key, value;
  std::istringstream stream(output);

  // Error handling
  if (stream.fail()) {
    std::cerr << "error: Failed to parse the battery information" << std::endl;
    return;
  }

  // Parse the output - key value pairs
  // Skip the first line
  std::getline(stream, key);
  // Remove the leading space from the 'key' string
  while (std::getline(stream, key, ':')) {
    if (key.find("  ") == 0)
      key = key.substr(2);
    std::getline(stream, value);
    // Remove the leading space from the 'value' string
    if (value[0] == ' ')
      value = value.substr(1);
    battery_info[key] = value;
  }

  // Print the battery information
  for (auto& info : battery_info) {
    std::cout << info.first << ">" << info.second << std::endl;
  }
}
