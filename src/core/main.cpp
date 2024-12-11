#include "src/Core.hpp"
#include "src/DeviceManager.hpp"

#include <iostream>

int main() {
  core::DeviceManager deviceManager;
  core::Core coreObject(deviceManager);

  auto devices = deviceManager.getDevices();
  for (auto device : devices) {
    std::cout << "Device: " << device << std::endl;
  }

  deviceManager.setSelectedDevice("test");

  std::cout << "selected: " << deviceManager.getSelectedDevice() << std::endl;

  return 0;
}
