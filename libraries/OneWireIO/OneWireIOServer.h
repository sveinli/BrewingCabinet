#ifndef ONEWIREIO_ONEWIREIOSERVER_H
#define ONEWIREIO_ONEWIREIOSERVER_H


#include <CDPSystem/Base/CDPProperty.h>
#include <IO/IOServer.h>
#include <IO/ServerIO/ChannelManager.h>


namespace OneWireIO {

class OneWireSensor;

class OneWireIOServer : public IOServer, public OSAPIThread
{
public:
  OneWireIOServer();
  ~OneWireIOServer();

  void Create(const char* fullName) override;
  void CreateModel() override;
  void Configure(const char* componentXML) override;
  std::string GetNodeTypeName() const override;
  void FillNodeChildren(CDP::StudioAPI::NodeStream &serializer) const override;
  bool IsCommProblem() override;
  void Activate() override;
  void Suspend() override;
  bool HandleXMLElement(XMLElementEx *pEx) override;
  unsigned int NumberOfNodesOnline() override;

protected:
  void Main(void) override;

private:
  ServerIO::ChannelManager* m_channelManager;
  std::vector<OneWireSensor*> m_owSensors;
  std::vector<OneWireSensor*> m_owSensorsRetry;
  CDPTimer m_retryTimer;
  double m_periodMs;
  bool m_commProblem;

};

}

#endif
