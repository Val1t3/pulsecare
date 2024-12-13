#ifndef CORE_HPP_
#define CORE_HPP_

#include "DeviceManager.hpp"

namespace core {
class Core {
 public:
  Core(DeviceManager& deviceManager);
  ~Core();

  void run();

 private:
  DeviceManager& _deviceManager;
};
};  // namespace core

#endif /* !CORE_HPP_ */
