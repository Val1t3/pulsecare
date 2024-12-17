#include <iostream>

#include "src/Cli.hpp"

int main() {
  core::DeviceManager deviceManager;
  core::Core coreObject(deviceManager);
  cli::Cli cli(coreObject, std::make_unique<cli::CommandParser>());

  cli.run();

  return 0;
}
