#ifndef CLI_HPP
#define CLI_HPP

#include "CommandParser.hpp"
#include "Core.hpp"

#include <memory>

namespace cli {
class Cli {
 public:
  Cli(core::Core& core, std::unique_ptr<CommandParser> commandParser);
  ~Cli();

  CommandParser& getCommandParser() const;

  void run();

 private:
  core::Core& _core;
  std::unique_ptr<CommandParser> _commandParser;
  bool _running;
};
}  // namespace cli

#endif  // CLI_HPP
