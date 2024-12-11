#ifndef ADBMANAGER_HPP_
#define ADBMANAGER_HPP_

#include <iostream>
#include <string>
#include <vector>

namespace core {
class ADBManager {
 public:
  ADBManager();
  ~ADBManager();

  static std::string executeCommand(std::string command);
  static std::string executeCommandOnDevice(std::string command,
                                            std::string device);
  static std::vector<std::string> listDevices();

 protected:
 private:
};
}  // namespace core

#endif /* !ADBMANAGER_HPP_ */