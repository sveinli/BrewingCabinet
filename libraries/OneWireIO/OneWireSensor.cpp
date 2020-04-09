#include "OneWireSensor.h"

#include <fstream>
#include <string>
#include <iostream>

#include <IO/ServerIO/DeltaValidatorSendTrigger.h>

#include <ext/stdio_filebuf.h>

using namespace CDP::StudioAPI;

namespace {

bool ReadDouble(const std::string& file, double &value)
{
  std::ifstream ofs(file.c_str());
  if (!ofs)
  {
    CDPMessage("OneWireSensor: Reading file %s failed\n", file.c_str());
    return false;
  }
  std::string fileContents((std::istreambuf_iterator<char>(ofs)), std::istreambuf_iterator<char>());
  ofs.close();

  std::string::size_type posVerify = fileContents.find("YES");
  if (posVerify == std::string::npos)
  {
    CDPMessage("OneWireSensor: CRC test failed while reading file %s\n%s\n", file.c_str(), fileContents.c_str());
    return false;
  }

  std::string::size_type posTemp = fileContents.find("t=");
  if (posTemp != std::string::npos)
  {
    std::string strValue = fileContents.substr(posTemp+2);
    value = atof( strValue.c_str() );
  }
  else
  {
    CDPMessage("OneWireSensor: Couldn't find t= in file %s\n%s\n", file.c_str(),fileContents.c_str());
    return false;
  }
  return true;
}

}

namespace OneWireIO {

OneWireSensor::OneWireSensor(const std::string& sensorID)
  : m_sensorValue(0.0)
{
  m_sensorPath = "/sys/bus/w1/devices/w1_bus_master1/" + sensorID + "/w1_slave";
  SetDataPointer(&m_sensorValue);
}


OneWireSensor::~OneWireSensor()
{
}


bool OneWireSensor::Initialize()
{
  std::ifstream ofs(m_sensorPath.c_str());
  if (!ofs)
    return false;

  ofs.close();
  return true;
}


bool OneWireSensor::Update()
{
  return ReadDouble(m_sensorPath, m_sensorValue);
}


std::string OneWireSensor::GetNodeTypeName() const
{
  return "OneWireIO.OneWireSensor";
}

}

