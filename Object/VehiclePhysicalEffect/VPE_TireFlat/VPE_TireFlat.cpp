// All the original content belonged to the US Army

#include "AA29/Object/VehiclePhysicalEffect/VPE_TireFlat/VPE_TireFlat.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"

UVPE_TireFlat::UVPE_TireFlat()
{

}

void UVPE_TireFlat::Activate(AAGP_Vehicle* V, int32 ZoneNum, int32 StateNum)
{
	if (!V->DamageZones[ZoneNum]->bWheelZone)
	{
		return;
	}
	V->Wheels[V->DamageZones[ZoneNum]->WheelNum]->WheelRadius = V->Wheels[V->DamageZones[ZoneNum]->WheelNum]->FlatWheelRadius;
}
