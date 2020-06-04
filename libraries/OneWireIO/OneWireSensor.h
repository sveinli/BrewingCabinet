#ifndef ONEWIREIO_ONEWIRESENSOR_H
#define ONEWIREIO_ONEWIRESENSOR_H

#include <IO/ServerIO/CDPSignalChannel.h>
#include <CDPSystem/Base/CDPSetting.h>

namespace ServerIO {
  class IChannel;
}

namespace OneWireIO {
class OneWireSensor : public ServerIO::CDPSignalChannel<double>
{
public:
   OneWireSensor(const std::string& sensorID);
  ~OneWireSensor();

  bool Initialize();
  bool Update();

  std::string GetNodeTypeName() const override;

private:
  std::string m_sensorPath;
  double m_sensorValue;
};

}

#endif
