#include "Core.hpp"

#include <iostream>

core::Core::Core(DeviceManager deviceManager) : _deviceManager(deviceManager) {}

core::Core::~Core() {}

void core::Core::run() {
  std::cout << "core test" << std::endl;
}
