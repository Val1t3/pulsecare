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
  void setDevices();

  std::string getSelectedDevice();
  void setSelectedDevice(std::string device);

 private:
  std::vector<std::string> _devices;
  std::string _selectedDevice;

  std::vector<std::string> formatDevicesCommand(std::string output);
};
}  // namespace core

#endif  // DEVICEMANAGER_HPP
