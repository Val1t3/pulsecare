#ifndef DEVICEMANAGER_HPP
#define DEVICEMANAGER_HPP

#include <string>
#include <vector>
namespace core {
class DeviceManager {
 public:
  DeviceManager();
  ~DeviceManager();

  std::vector<std::string> getDevices();
  void setDevices(std::vector<std::string> devices);

  std::string getDevice();
  void setDevice(std::string device);

 private:
  std::vector<std::string> _devices;
  std::string _selectedDevice;
};
}  // namespace core

#endif  // DEVICEMANAGER_HPP
