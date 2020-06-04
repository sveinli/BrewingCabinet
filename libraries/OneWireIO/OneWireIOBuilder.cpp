/**
OneWireIOBuilder implementation.
*/

//#include "OneWireSensor.h"
#include "OneWireIOBuilder.h"

using namespace OneWireIO;

OneWireIOBuilder::OneWireIOBuilder(const char* libName, const char* timeStamp)
  : CDPBuilder(libName, timeStamp)
{
}

CDPComponent* OneWireIOBuilder::CreateNewComponent(const std::string& type)
{
  return CDPBuilder::CreateNewComponent(type);
}

CDPBaseObject* OneWireIOBuilder::CreateNewCDPOperator(const std::string& modelName, const std::string& type, const CDPPropertyBase* inputProperty)
{
  return CDPBuilder::CreateNewCDPOperator(modelName, type, inputProperty);
}

/**
Do not edit. Autogenerated Builder CDPObject factory function.
*/
CDPObject* OneWireIOBuilder::CreateNewObject(const std::string& type)
{
//    if (type=="OneWireIO.OneWireSensor")
//        return new OneWireSensor;

  return CDPBuilder::CreateNewObject(type);
}

/**
CDPNode factory function.
*/
CDP::StudioAPI::CDPNode* OneWireIOBuilder::CreateNewCDPNode(const std::string& type)
{
    return CDPBuilder::CreateNewCDPNode(type);
}
