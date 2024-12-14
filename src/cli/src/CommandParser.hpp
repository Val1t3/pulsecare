#ifndef COMMANDPARSER_HPP
#define COMMANDPARSER_HPP

#include <functional>
#include <string>
#include <unordered_map>
#include <utility>

namespace cli {

typedef struct command_s {
  std::string description;
  std::function<void()> callback;
} command_t;

class CommandParser {
 public:
  CommandParser();
  ~CommandParser();

  const std::unordered_map<std::string, command_t>& getCommands() const;

  void addCommand(const std::string& command, const std::string& description,
                  std::function<void()> callback);
  std::pair<std::string, std::vector<std::string>> parse(
      const std::string& input) const;
  void execute(const std::string& commandName, std::vector<std::string>& args);
  void help();

 private:
  std::unordered_map<std::string, command_t> _commands;
};
}  // namespace cli

#endif  // COMMANDPARSER_HPP
