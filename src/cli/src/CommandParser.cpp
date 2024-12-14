#include "CommandParser.hpp"
#include <iostream>
#include <utility>

cli::CommandParser::CommandParser() {
  _commands = std::unordered_map<std::string, command_t>();
}

cli::CommandParser::~CommandParser() {}

void cli::CommandParser::addCommand(const std::string& command,
                                    const std::string& description,
                                    std::function<void()> callback) {
  _commands[command] = {description, callback};
}

std::pair<std::string, std::vector<std::string>> cli::CommandParser::parse(
    const std::string& input) {
  return std::make_pair("command", std::vector<std::string>());
}

void cli::CommandParser::execute(const std::string& commandName,
                                 std::vector<std::string>& args) {}

void cli::CommandParser::help() {
  for (const auto& command : _commands) {
    std::cout << command.first << " - " << command.second.description
              << std::endl;
  }
}
