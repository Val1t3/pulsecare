#ifndef CORE_HPP_
#define CORE_HPP_

#include "DeviceManager.hpp"

namespace core {
class Core {
 public:
  Core(DeviceManager& deviceManager);
  ~Core();

  void run();

  DeviceManager& getDeviceManager();

  // --- EXTERNAL HARDWARE ---
  //
  // TODO: Define the function templates for the following functions
  // Battery
  void battery();

 private:
  DeviceManager& _deviceManager;
};
};  // namespace core

#endif /* !CORE_HPP_ */
