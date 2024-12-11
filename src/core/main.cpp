#include <iostream>

#include "src/ADBManager.hpp"
#include "src/Core.hpp"
#include "src/DeviceManager.hpp"

int main() {
  core::DeviceManager deviceManager;
  core::Core coreObject(deviceManager);

  coreObject.run();

  std::cout << "CORE" << std::endl;

  std::cout << core::ADBManager::executeCommand("devices") << std::endl;
  return 0;
}
