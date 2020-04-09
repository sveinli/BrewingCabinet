#include "SSRControlledHeater.h"

using namespace BrewingLib;

SSRControlledHeater::SSRControlledHeater()
{
}

SSRControlledHeater::~SSRControlledHeater()
{
}

void SSRControlledHeater::Create(const char* fullName)
{
  CDPComponent::Create(fullName);

  NominalPower.Create("NominalPower",this);
  MinPulseWidth.Create("MinPulseWidth",this);
  PWMPeriod.Create("PWMPeriod",this);
  SSROutput.Create("SSROutput",this);
  Setpoint.Create("Setpoint",this);
}


void SSRControlledHeater::CreateModel()
{
  CDPComponent::CreateModel();

  RegisterStateProcess("Null", (CDPCOMPONENT_STATEPROCESS)&SSRControlledHeater::ProcessNull, "Initial Null state");
}


void SSRControlledHeater::Configure(const char* componentXML)
{
    CDPComponent::Configure(componentXML);
}


void SSRControlledHeater::Activate()
{
  CDPComponent::Activate();

  PWMPeriod.Start();
}


void SSRControlledHeater::ProcessNull()
{
    double fraction = Setpoint / NominalPower;
    SSROutput = PWMPeriod.TimeElapsed() < fraction*PWMPeriod + ts/2;

    if ( PWMPeriod.TimedOut() )
        PWMPeriod.Restart();
}
