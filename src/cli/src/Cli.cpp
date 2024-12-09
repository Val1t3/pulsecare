#include "Cli.hpp"

Cli::Cli::Cli(std::unique_ptr<CommandParser> commandParser)
{
}

Cli::Cli::~Cli()
{
}

void Cli::Cli::run()
{
    std::cout << "Running CLI" << std::endl;
}