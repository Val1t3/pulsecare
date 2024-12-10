#include <iostream>

#include "src/ADBManager.hpp"

int main() {
    std::cout << "CORE" << std::endl;

    std::cout << core::ADBManager::executeCommand("devices") << std::endl;
    return 0;
}