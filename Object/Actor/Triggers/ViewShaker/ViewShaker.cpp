// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/ViewShaker/ViewShaker.h"

AViewShaker::AViewShaker()
{
	ShakeRadius = 2000;
	OffsetMag = FVector(10, 10, 10);
	OffsetRate = FVector(1000, 1000, 1000);
	OffsetTime = 3;
	bCollideActors = false;
}

void AViewShaker::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	local Controller C;
	local PlayerController LocalPlayer;
	LocalPlayer = Level.GetLocalPlayerController();
	if ((LocalPlayer != None) && (VSize((Location - LocalPlayer.ViewTarget.Location)) < ShakeRadius))
	{
		LocalPlayer.ShakeView(RotMag, RotRate, RotTime, OffsetMag, OffsetRate, OffsetTime);
	}
	C = Level.ControllerList;
	if (C != None)
	{
		if (((PlayerController(C) != None) && (C != LocalPlayer)) && (VSize((Location - PlayerController(C).ViewTarget.Location)) < ShakeRadius))
		{
			C.ShakeView(RotMag, RotRate, RotTime, OffsetMag, OffsetRate, OffsetTime);
		}
		C = C.nextController;
	}
	*/
}
