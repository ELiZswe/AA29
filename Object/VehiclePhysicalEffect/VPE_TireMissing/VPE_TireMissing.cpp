// All the original content belonged to the US Army

#include "AA29/Object/VehiclePhysicalEffect/VPE_TireMissing/VPE_TireMissing.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

UVPE_TireMissing::UVPE_TireMissing()
{

}

void UVPE_TireMissing::Activate(AAGP_Vehicle* V, int32 ZoneNum, int32 StateNum)
{
	if (!V->DamageZones[ZoneNum]->bWheelZone)
	{
		return;
	}
	V->Wheels[V->DamageZones[ZoneNum]->WheelNum]->WheelRadius = V->Wheels[V->DamageZones[ZoneNum]->WheelNum]->RimWheelRadius;
}
