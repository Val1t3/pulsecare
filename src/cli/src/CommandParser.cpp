#include "CommandParser.hpp"
#include <iostream>
#include <sstream>
#include <utility>

cli::CommandParser::CommandParser() {
  _commands = std::unordered_map<std::string, command_t>();
}

cli::CommandParser::~CommandParser() {}

// TODO: Add args to the callback
/**
 * @brief Add a new command to the parser
 *
 * @param command The command name
 * @param description The command description
 * @param callback The function to be called when the command is executed
 */
void cli::CommandParser::addCommand(const std::string& command,
                                    const std::string& description,
                                    std::function<void()> callback) {
  _commands[command] = {description, callback};
}

/**
 * @brief Parse the input string of the command parser to return the command
 * name and the arguments
 *
 * @param input The input string
 * @return std::pair<std::string, std::vector<std::string>> The command name and
 * the arguments
 */
std::pair<std::string, std::vector<std::string>> cli::CommandParser::parse(
    const std::string& input) const {
  // DEBUG
  std::cout << "Parsing input: " << input << std::endl;

  std::istringstream stream(input);
  std::string commandName;
  std::vector<std::string> args;

  stream >> commandName;

  std::string arg;
  while (stream >> arg)
    args.push_back(arg);

  return {commandName, args};
}

// TODO: Add args to the callback
/**
 * @brief Execute the command with the given name
 *
 * @param commandName The command name
 * @param args The arguments
 */
void cli::CommandParser::execute(const std::string& commandName,
                                 std::vector<std::string>& args) {
  auto it = _commands.find(commandName);
  if (it != _commands.end())
    it->second.callback();
  else
    std::cout << "Command not found" << std::endl;
}

/**
 * @brief Print the help message with all the commands and their descriptions
 */
void cli::CommandParser::help() {
  for (const auto& command : _commands) {
    std::cout << command.first << " - " << command.second.description
              << std::endl;
  }
}

/**
 * @brief Get the commands of the parser
 *
 * @return const std::unordered_map<std::string, command_t>& The commands
 */
const std::unordered_map<std::string, cli::command_t>&
cli::CommandParser::getCommands() const {
  return _commands;
}
