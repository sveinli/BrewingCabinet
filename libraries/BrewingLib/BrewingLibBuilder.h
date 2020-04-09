/**
BrewingLibBuilder header file.
*/

#ifndef BREWINGLIB_BREWINGLIBBUILDER_H
#define BREWINGLIB_BREWINGLIBBUILDER_H

#include <CDPSystem/Application/CDPBuilder.h>

namespace BrewingLib {

class BrewingLibBuilder : public CDPBuilder
{
public:
    BrewingLibBuilder(const char* libName,const char* timeStamp);
    CDPComponent* CreateNewComponent(const std::string& type) override;
    CDPObject* CreateNewObject(const std::string& type) override;
    CDP::StudioAPI::CDPNode* CreateNewCDPNode(const std::string& type) override;
    CDPBaseObject* CreateNewCDPOperator(const std::string& modelName,const std::string& type,const CDPPropertyBase* inputProperty) override;
};

}

#endif // BREWINGLIB_BREWINGLIBBUILDER_H
