#include "Cabinet.h"

using namespace BrewingLib;

Cabinet::Cabinet()
{
}

Cabinet::~Cabinet()
{
}

void Cabinet::Create(const char* fullName)
{
  CDPComponent::Create(fullName);
  TempSetPoint.Create("TempSetPoint",this);
  Heating.Create("Heating",this);
  CabinetAirTemp.Create("CabinetAirTemp",this);
  TankTemp.Create("TankTemp",this);
  OutsideTemp.Create("OutsideTemp",this);
}

void Cabinet::CreateModel()
{
  CDPComponent::CreateModel();

  RegisterStateProcess("Null", (CDPCOMPONENT_STATEPROCESS)&Cabinet::ProcessNull, "Initial Null state");
}

void Cabinet::Configure(const char* componentXML)
{
  CDPComponent::Configure(componentXML);
}

void Cabinet::ProcessNull()
{
  Heating = TempSetPoint;
}
