#ifndef DEVICEMANAGER_HPP
#define DEVICEMANAGER_HPP

#include <memory>
#include <string>
#include <vector>

namespace core {

typedef struct device_s {
  std::string id;
  std::string product;
  std::string model;
  std::string device;
} device_t;

class DeviceManager {
 public:
  DeviceManager();
  ~DeviceManager();

  std::vector<device_t> getDevices();
  void setDevices();

  device_t* getSelectedDevice();
  void setSelectedDevice(std::string device);

 private:
  std::vector<device_t> _devices;
  std::unique_ptr<device_t> _selectedDevice;

  std::vector<device_t> formatDevicesCommand(std::string output);
};
}  // namespace core

#endif  // DEVICEMANAGER_HPP
