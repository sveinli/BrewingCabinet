#include "OneWireIOServer.h"

#include <StudioAPI/NodeStream.h>
#include "OneWireSensor.h"

using namespace OneWireIO;

OneWireIOServer::OneWireIOServer()
  : m_channelManager(new ServerIO::ChannelManager(this))
  , m_periodMs(0.0)
  , m_commProblem(false)
{
    m_retryTimer.Reset(10);
}

OneWireIOServer::~OneWireIOServer()
{
  delete m_channelManager;
}

void OneWireIOServer::Create(const char* fullName)
{
  CDPComponent::Create(fullName);
}

void OneWireIOServer::CreateModel()
{
  CDPComponent::CreateModel();
}

void OneWireIOServer::Configure(const char* componentXML)
{
  CDPComponent::Configure(componentXML);
  m_periodMs = ts * 1000;
}

std::string OneWireIOServer::GetNodeTypeName() const
{
  return "OneWireIO.OneWireIOServer";
}

void OneWireIOServer::FillNodeChildren(CDP::StudioAPI::NodeStream &serializer) const
{
  IOServer::FillNodeChildren(serializer);
  auto list = m_channelManager->GetChannelList();
  serializer.StdContainerStreamer(list);
}

void OneWireIOServer::Activate()
{
  IOServer::Activate();
  Start(CDPTHREAD_PRIORITY_ABOVE_NORMAL, m_shortName);
}

void OneWireIOServer::Suspend()
{
  IOServer::Suspend();
  Delete();
}

void OneWireIOServer::Main()
{
  while (!Stopped())
  {
    m_channelManager->SynchronizeValuesIn();
    for (auto iter = m_owSensors.begin(); iter != m_owSensors.end(); )
    {
      auto sensor = *iter;
      if (!sensor->Update())
      {
        iter = m_owSensors.erase(iter);
        m_owSensorsRetry.push_back(sensor);
        m_retryTimer.Start();
      }
      else
        ++iter;
    }
    if (m_retryTimer.TimedOut())
    {
      for (auto iter = m_owSensorsRetry.begin(); iter != m_owSensorsRetry.end(); )
      {
        auto sensor = *iter;
        if (sensor->Update())
        {
          iter = m_owSensorsRetry.erase(iter);
          m_owSensors.push_back(sensor);
        }
        else
          ++iter;
      }
      if(m_owSensorsRetry.size()>0)
        m_retryTimer.Restart();
      else
        m_retryTimer.Reset();
    }
    m_channelManager->SynchronizeValuesOut();
    OSAPISleep(m_periodMs);
  }
}

bool OneWireIOServer::IsCommProblem()
{
  return m_owSensors.size()<1;
}

unsigned int OneWireIOServer::NumberOfNodesOnline()
{
  return m_owSensors.size();
}

bool OneWireIOServer::HandleXMLElement(XMLElementEx *pEx)
{
  const XMLString& currentElement = pEx->GetName();

  std::string s_onewiresensor = "OneWireSensor";

  if(currentElement == "OneWireSensors") // this is just wrapper element for W1Sensor elements
    return false; //Call handleElement for childern also

  if(currentElement == s_onewiresensor.c_str())
  {
    bool cdpInput = false;
    std::string name     = pEx->GetAttributeValue("Name");
    std::string sensorID = pEx->GetAttributeValue("SensorID");
    OneWireSensor* channel = new OneWireSensor(sensorID);
    if (channel->Initialize())
    {
      channel->Create(name.c_str(), this);
      channel->Configure(pEx);
      channel->SetChannelParameters(cdpInput,0,0,0);

      m_channelManager->SetSyncGroupId(cdpInput, channel);
      m_channelManager->RegisterCDPChannel(channel);
      m_owSensors.push_back(channel);
    }
    else
    {
      CDPMessage("%s: Failed to initialize OneWireSensor %s\n", IOServer::ShortName(), name.c_str());
      delete channel;
    }

    return true;
  }

  return CDPComponent::HandleXMLElement(pEx);
}
