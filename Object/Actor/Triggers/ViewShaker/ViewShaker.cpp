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
	AController* C = nullptr;
	APlayerController* LocalPlayer = nullptr;
	/*
	LocalPlayer=Level.GetLocalPlayerController();
	if ((LocalPlayer != nullptr) && (VSize((Location - LocalPlayer.ViewTarget.Location)) < ShakeRadius))
	{
		LocalPlayer.ShakeView(RotMag,RotRate,RotTime,OffsetMag,OffsetRate,OffsetTime);
	}
	for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
	{
		if (((Cast<APlayerController>(C) != nullptr) && (C != LocalPlayer)) && (VSize((Location - PlayerController(C).ViewTarget.Location)) < ShakeRadius))
		{
			C.ShakeView(RotMag,RotRate,RotTime,OffsetMag,OffsetRate,OffsetTime);
		}
	}
	*/
}
