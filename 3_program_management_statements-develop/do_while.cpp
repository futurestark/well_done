#include <iostream>

/*
bool WgUtilsApplier::SetWgDevice() const {
  int ret = 0;
  wg_device device{};

  memcpy(device.name, wg_dev_name_.c_str(), wg_dev_name_.length());
  device.listen_port = GetWgListeningPort();
  device.flags = static_cast<wg_device_flags>(WGDEVICE_HAS_PRIVATE_KEY |
                                              WGDEVICE_HAS_LISTEN_PORT);

  if (wg_key_is_zero(private_key_)) {
    OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: wg key is zero for ",
                      wg_dev_name_.c_str());
  } else {
    memcpy(device.private_key, private_key_, sizeof(private_key_));
    if ((ret = wg_set_device(&device)) < 0) {
      OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: Unable to set device for ",
                        wg_dev_name_.c_str(), " : ", strerror(ret));
      ret = 0;
    } else {
      ret = 1;
    }
  }
  return !!ret;
*/

/*
bool WgUtilsApplier::SetWgDevice(const std::string& own_public_key) const {
  bool result = false;
  wg_device device{};

  memcpy(device.name, wg_dev_name_.c_str(), wg_dev_name_.length());
  device.listen_port = GetWgListeningPort();
  device.flags = static_cast<wg_device_flags>(WGDEVICE_HAS_PRIVATE_KEY |
                                              WGDEVICE_HAS_LISTEN_PORT);

  do {
    if (wg_key_is_zero(private_key_)) {
      OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: wg key is zero for ",
                        wg_dev_name_.c_str());
      break;
    }

    memcpy(device.private_key, private_key_, sizeof(private_key_));

    // Set public key to device
    if (!own_public_key.empty()) {
      wg_key public_key;

      int ret = wg_key_from_base64(public_key, own_public_key.c_str());
      if (ret < 0) {
        OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: Unable to convert the public key ",
                          own_public_key, ": ", strerror(ret));
        break;
      }

      if (wg_key_is_zero(public_key)) {
        OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: public wg key is zero for ",
                          wg_dev_name_.c_str());
        break;
      }

      memcpy(device.public_key, public_key, sizeof(public_key));
      device.flags = static_cast<wg_device_flags>(device.flags | WGDEVICE_HAS_PUBLIC_KEY);
    }

    int ret = wg_set_device(&device);
    if (ret < 0) {
      OLU_DLT_LOG_ERROR(__FUNCTION__, "Error: Unable to set device for ",
                        wg_dev_name_.c_str(), " : ", strerror(ret));
      break;
    }

    result = true;
  } while (false);

  return result;
}
*/

int main(int argc, char const *argv[]) {
  char ch;
  do {
    size_t value;
    std::cout << "Please enter number " << std::endl;
    std::cin >> value;
    std::cout << "You are enter " << value << std::endl;
    //если раскомитеть эту строку, то компилятор выдаст ошибку, что переменная опредена в не области видимости
/*    char ch = 'Y'; 
  } while (ch == 'Y');
*/
   std::cout << "Exit? Y : N" << std::endl;
   std::cin >> ch;
  } while (ch != 'Y');

  http://www.diag.com/news/DoWhileFalse.html


  return 0;
}
