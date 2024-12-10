#include "Cli.hpp"

Cli::Cli::Cli(std::unique_ptr<CommandParser> commandParser)
{
    this->_commandParser = std::move(commandParser);
    this->_running = false;
}

Cli::Cli::~Cli()
{
}

/**
 * Run the main loop of the CLI.
 */
void Cli::Cli::run()
{
    std::string input;

    std::cout << "\033[32mRunning Pulsecare CLI\033[0m" << std::endl;
    this->_running = true;
    while (this->_running) {
        std::cout << "\033[34mpulsecare > \033[0m";
        std::getline(std::cin, input);

        if (input == "exit")
            this->_running = false;
    }
    std::cout << "\033[31mExiting Pulsecare CLI\033[0m" << std::endl;
}