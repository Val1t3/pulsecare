#ifndef CLI_HPP
#define CLI_HPP

#include "CommandParser.hpp"

#include <iostream>
#include <memory>

namespace cli {
class Cli {
 public:
  Cli(std::unique_ptr<CommandParser> commandParser);
  ~Cli();

  void run();

 private:
  std::unique_ptr<CommandParser> _commandParser;
  bool _running;
};
}  // namespace cli

#endif  // CLI_HPP