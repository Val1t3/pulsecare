#include "src/Core.hpp"
#include "src/DeviceManager.hpp"

#include <iostream>

int main() {
  core::DeviceManager deviceManager;
  core::Core coreObject(deviceManager);

  for (core::device_t& device : deviceManager.getDevices()) {
    std::cout << "ID: " << device.id << std::endl;
    std::cout << "Product: " << device.product << std::endl;
    std::cout << "Model: " << device.model << std::endl;
    std::cout << "Device: " << device.device << std::endl;
  }

  deviceManager.setSelectedDevice("emulator-5554");
  coreObject.battery();

  return 0;
}
