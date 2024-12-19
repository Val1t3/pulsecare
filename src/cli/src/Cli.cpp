#include "Cli.hpp"

#include <iostream>

cli::Cli::Cli(core::Core& core, std::unique_ptr<CommandParser> commandParser) : _core(core) {
  _commandParser = std::move(commandParser);
  _running = false;

  // --- INIT COMMANDS ---
  _commandParser->addCommand("help", "Print the help message", [this]() {
    this->_commandParser->help();
  });
  _commandParser->addCommand("exit", "Exit the CLI", [this]() {
    _running = false;
  });
  _commandParser->addCommand("battery", "Battery info", [this]() {
    batteryCommand();
  });
}

cli::Cli::~Cli() {}

/**
 * Get the command parser of the CLI.
 *
 * @return The command parser
 */
cli::CommandParser& cli::Cli::getCommandParser() const {
  return *_commandParser;
}

/**
 * Run the main loop of the CLI.
 */
void cli::Cli::run() {
  std::string input;

  std::cout << "\033[32mRunning Pulsecare CLI\033[0m" << std::endl;
  this->_running = true;
  while (this->_running) {
    std::cout << "\033[34mpulsecare > \033[0m";
    std::getline(std::cin, input);

    auto resPars = _commandParser->parse(input);
    _commandParser->execute(resPars.first, resPars.second);
  }
  std::cout << "\033[31mExiting Pulsecare CLI\033[0m" << std::endl;
}

void cli::Cli::batteryCommand() {
  if (_core.getDeviceManager().getSelectedDevice() == nullptr) {
    std::cerr << "error: No device selected" << std::endl;
    return;
  }
  _core.battery();
}
