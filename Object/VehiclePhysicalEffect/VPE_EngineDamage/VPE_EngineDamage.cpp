// All the original content belonged to the US Army

#include "AA29/Object/VehiclePhysicalEffect/VPE_EngineDamage/VPE_EngineDamage.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"

UVPE_EngineDamage::UVPE_EngineDamage()
{

}

void UVPE_EngineDamage::Activate(AAGP_Vehicle* V, int32 ZoneNum, int32 StateNum)
{
	if (Cast<AAGP_WheeledCraft>(V) == nullptr)
	{
		return;
	}
	Cast<AAGP_WheeledCraft>(V)->FTScale *= 5;
}
