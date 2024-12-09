#ifndef CLI_HPP
#define CLI_HPP

#include "CommandParser.hpp"

// #include <memory>
#include <iostream>

namespace Cli {
  class Cli {
    public:
      Cli(std::unique_ptr<CommandParser> commandParser);
      ~Cli();

      void run();

    private:
      std::unique_ptr<CommandParser> commandParser;
  };
}

#endif // CLI_HPP


