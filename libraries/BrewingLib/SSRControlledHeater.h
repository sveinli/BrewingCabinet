#ifndef BREWINGLIB_SSRCONTROLLEDHEATER_H
#define BREWINGLIB_SSRCONTROLLEDHEATER_H

#include <CDPSystem/Base/CDPComponent.h>
#include <Signal/CDPSignal.h>
#include <CDPParameter/CDPParameter.h>
#include <CDPAlarm/CDPAlarm.h>
#include <OSAPI/Timer/CDPParameterTimer.h>

namespace BrewingLib {

class SSRControlledHeater : public CDPComponent
{
public:
    SSRControlledHeater();
    ~SSRControlledHeater() override;

    void Create(const char* fullName) override;
    void CreateModel() override;
    void Configure(const char* componentXML) override;
    void ProcessNull() override;
    virtual void Activate() override;

protected:
    CDPSignal<double> Setpoint;
    CDPSignal<bool> SSROutput;

    CDPParameter NominalPower;
    CDPParameter MinPulseWidth;
    CDPParameterTimer PWMPeriod;

    using CDPComponent::requestedState;
    using CDPComponent::ts;
    using CDPComponent::fs;

    // CDPBaseObject interface
};

} // namespace BrewingLib

#endif
