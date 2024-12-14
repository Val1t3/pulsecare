#include <iostream>

#include "src/Cli.hpp"

int main() {
  std::cout << "Hello World!" << std::endl;

  cli::Cli cli(std::make_unique<cli::CommandParser>());

  cli.getCommandParser().addCommand("help", "Print the help message", [&cli]() {
    cli.getCommandParser().help();
  });

  for (auto cmd : cli.getCommandParser().getCommands()) {
    std::cout << cmd.first << " - " << cmd.second.description << std::endl;
  }

  cli.run();

  return 0;
}
