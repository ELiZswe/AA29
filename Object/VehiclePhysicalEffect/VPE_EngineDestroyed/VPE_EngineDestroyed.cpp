// All the original content belonged to the US Army

#include "AA29/Object/VehiclePhysicalEffect/VPE_EngineDestroyed/VPE_EngineDestroyed.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"

UVPE_EngineDestroyed::UVPE_EngineDestroyed()
{

}

void UVPE_EngineDestroyed::Activate(AAGP_Vehicle* V, int32 ZoneNum, int32 StateNum)
{
	if (Cast<AAGP_WheeledCraft>(V) == nullptr)
	{
		return;
	}
	Cast<AAGP_WheeledCraft>(V)->TorqueCurve = GetDefault<UVPE_EngineDestroyed>()->NoTorque;
	Cast<AAGP_WheeledCraft>(V)->WheelInertia = 0;
}
