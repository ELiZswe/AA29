// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_Trigger/AGP_VehicleCheckpoint/AGP_VehicleCheckpoint.h"

AAGP_VehicleCheckpoint::AAGP_VehicleCheckpoint()
{
	//CollisionRadius = 300;
	//CollisionHeight = 100;
}

void AAGP_VehicleCheckpoint::Touch(AActor* Other)
{
	/*
	if (bActive)
	{
		Other.EnterTrigger(this);
		if (EventLab != nullptr && Vehicle(Other) != nullptr)
		{
			EventLab.ActorNotify(this, 4, Other);
		}
	}
	*/
}
