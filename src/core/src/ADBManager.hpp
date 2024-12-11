#ifndef ADBMANAGER_HPP_
#define ADBMANAGER_HPP_

#include <string>

namespace core {
class ADBManager {
 public:
  ADBManager();
  ~ADBManager();

  static std::string executeCommand(std::string command);
  static std::string executeCommandOnDevice(std::string command,
                                            std::string device);
};
}  // namespace core

#endif /* !ADBMANAGER_HPP_ */
