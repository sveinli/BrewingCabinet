/**
ONEWIREIOBuilder header file.
*/

#ifndef ONEWIREIO_ONEWIREIOBUILDER_H
#define ONEWIREIO_ONEWIREIOBUILDER_H

#include <CDPSystem/Application/CDPBuilder.h>

namespace OneWireIO {

class OneWireIOBuilder : public CDPBuilder
{
public:
  OneWireIOBuilder(const char* libName,const char* timeStamp);
  CDPComponent* CreateNewComponent(const std::string& type) override;
    CDPObject* CreateNewObject(const std::string& type) override;
    CDP::StudioAPI::CDPNode* CreateNewCDPNode(const std::string& type) override;
  CDPBaseObject* CreateNewCDPOperator(const std::string& modelName,const std::string& type,const CDPPropertyBase* inputProperty) override;
};

}

#endif
