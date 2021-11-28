// All the original content belonged to the US Army


#include "AA29/Object/Actor/Triggers/AvoidMarker/FearSpot/FearSpot.h"


AFearSpot::AFearSpot()
{
	CollisionRadius = 200;
}


void AFearSpot::Touch(AActor* Other)
{
	/*
	if ((bInitiallyActive && (Pawn(Other) != None)) && (Pawn(Other).Controller != None))
	{
		Pawn(Other).Controller.FearThisSpot(Self);
	}
	*/
}

void AFearSpot::Trigger(AActor* Other, APawn* EventInstigator)
{
	//bInitiallyActive = (!bInitiallyActive);
}