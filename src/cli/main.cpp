#include <iostream>

#include "src/Cli.hpp"

int main() {
	std::cout << "Hello World!" << std::endl;

	Cli::Cli cli(std::make_unique<Cli::CommandParser>());
	cli.run();

	return 0;
}