#ifndef BREWINGLIB_BREWINGCABINETSIM_H
#define BREWINGLIB_BREWINGCABINETSIM_H

#include <CDPSystem/Base/CDPComponent.h>
#include <Signal/CDPSignal.h>
#include <CDPParameter/CDPParameter.h>
#include <CDPAlarm/CDPAlarm.h>

namespace BrewingLib {

class BrewingCabinetSim : public CDPComponent
{
  public:
    BrewingCabinetSim();
    ~BrewingCabinetSim() override;

    void Create(const char* fullName) override;
    void CreateModel() override;
    void Configure(const char* componentXML) override;
    void ProcessNull() override;

  protected:
    CDPParameter Volume;
    CDPParameter HeatCapacityAir;
    CDPParameter DensityAir;
    CDPParameter InsulationFactor;
    CDPSignal<double> InsideTemp;
    CDPSignal<double> AmbientTemp;
    CDPSignal<double> HeatingPower;
    CDPSignal<double> CoolingPower;
    CDPSignal<double> HeatLossPower;
    using CDPComponent::requestedState;
    using CDPComponent::ts;
    using CDPComponent::fs;
};

} // namespace BrewingLib

#endif
