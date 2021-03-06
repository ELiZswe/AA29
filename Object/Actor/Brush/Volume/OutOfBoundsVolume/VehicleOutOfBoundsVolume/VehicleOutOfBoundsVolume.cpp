// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/OutOfBoundsVolume/VehicleOutOfBoundsVolume/VehicleOutOfBoundsVolume.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"

AVehicleOutOfBoundsVolume::AVehicleOutOfBoundsVolume()
{
	TimeToKillVehicle = 10;
}

void AVehicleOutOfBoundsVolume::Touch(AActor* Other)
{
	AAGP_Vehicle* V = nullptr;
	Super::Touch(Other);
	V = Cast<AAGP_Vehicle>(Other);
	if (V != nullptr)
	{
		V->OutOfBounds++;
		V->CurrentZoneTimeToKill = TimeToKillVehicle;
		//V->NotifyControllerOutOfBounds(int(Ceil((TimeToKillVehicle - V.TimeOutOfBounds))));
		//V->SetCustomTimer(0.5, true, "VehicleOutOfBoundsCheck");
	}
}

void AVehicleOutOfBoundsVolume::UnTouch(AActor* Other)
{
	AAGP_Vehicle* V = nullptr;
	Super::UnTouch(Other);
	V = Cast<AAGP_Vehicle>(Other);
	if ((V != nullptr) && (V->OutOfBounds > 0))
	{
		V->OutOfBounds--;
		if (V->OutOfBounds == 0)
		{
			V->TimeOutOfBounds = 0;
			V->AlertClientReturnedToCombat();
			//StopCustomTimer("VehicleOutOfBoundsCheck");
		}
	}
}
