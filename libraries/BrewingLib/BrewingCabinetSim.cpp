#include "BrewingCabinetSim.h"

using namespace BrewingLib;

BrewingCabinetSim::BrewingCabinetSim()
{
}


BrewingCabinetSim::~BrewingCabinetSim()
{
}


void BrewingCabinetSim::Create(const char* fullName)
{
  CDPComponent::Create(fullName);
  Volume.Create("Volume",this);
  HeatCapacityAir.Create("HeatCapacityAir",this);
  DensityAir.Create("DensityAir",this);
  InsulationFactor.Create("InsulationFactor",this);
  InsideTemp.Create("InsideTemp",this);
  AmbientTemp.Create("AmbientTemp",this);
  HeatingPower.Create("HeatingPower",this);
  CoolingPower.Create("CoolingPower",this);
  HeatLossPower.Create("HeatLossPower",this);
}


void BrewingCabinetSim::CreateModel()
{
  CDPComponent::CreateModel();

  RegisterStateProcess("Null", (CDPCOMPONENT_STATEPROCESS)&BrewingCabinetSim::ProcessNull, "Initial Null state");
}


void BrewingCabinetSim::Configure(const char* componentXML)
{
  CDPComponent::Configure(componentXML);

  InsideTemp = AmbientTemp;
}


void BrewingCabinetSim::ProcessNull()
{
  // Calculate ares, assume a cubic box
  double side = cbrt(Volume);
  double surfaceArea = side*side * 6.0;

  double heatCapacityAirInside = HeatCapacityAir * DensityAir * Volume;                               // [kJ/kg*K] * [kg/m^3] * [m^3] = [kJ/K]
  HeatLossPower = (InsideTemp- AmbientTemp) * surfaceArea / InsulationFactor;         // [K] * [m^2] / [m^2*K/W] = [W]
  InsideTemp += ts*(HeatingPower - CoolingPower - HeatLossPower)*0.001 / heatCapacityAirInside;  // [kW]/[s] / [kJ/K] = K/S = C/s
}

