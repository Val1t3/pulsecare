#include <iostream>

#include "src/Cli.hpp"

int main() {
  std::cout << "Hello World!" << std::endl;

  cli::Cli cli(std::make_unique<cli::CommandParser>());

  cli.run();

  return 0;
}
