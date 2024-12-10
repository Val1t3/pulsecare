#ifndef CLI_HPP
#define CLI_HPP

#include "CommandParser.hpp"

#include <iostream>
#include <memory>

namespace Cli {
  class Cli {
    public:
        Cli(std::unique_ptr<CommandParser> commandParser);
        ~Cli();

        void run();

    private:
        std::unique_ptr<CommandParser> _commandParser;
        bool _running;
  };
}

#endif // CLI_HPP