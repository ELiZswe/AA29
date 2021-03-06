// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/AvoidMarker/FearSpot/FearSpot.h"

AFearSpot::AFearSpot()
{
	CollisionRadius = 200;
}

void AFearSpot::Touch(AActor* Other)
{
	if ((bInitiallyActive && (Cast<APawn>(Other) != nullptr)) && (Cast<APawn>(Other)->Controller != nullptr))
	{
		//Cast<APawn>(Other)->Controller->FearThisSpot(this);
	}
}

void AFearSpot::Trigger(AActor* Other, APawn* EventInstigator)
{
	bInitiallyActive = !bInitiallyActive;
}
