#ifndef BREWINGLIB_CABINET_H
#define BREWINGLIB_CABINET_H

#include <CDPSystem/Base/CDPComponent.h>
#include <Signal/CDPSignal.h>
#include <CDPParameter/CDPParameter.h>
#include <CDPAlarm/CDPAlarm.h>

namespace BrewingLib {

class Cabinet : public CDPComponent
{
  public:
    Cabinet();
    ~Cabinet() override;

    void Create(const char* fullName) override;
    void CreateModel() override;
    void Configure(const char* componentXML) override;
    void ProcessNull() override;

  protected:
    CDPParameter TempSetPoint;
    CDPSignal<double> Heating;
    CDPSignal<double> CabinetAirTemp;
    CDPSignal<double> TankTemp;
    CDPSignal<double> OutsideTemp;
    using CDPComponent::requestedState;
    using CDPComponent::ts;
    using CDPComponent::fs;
};

} // namespace BrewingLib

#endif
