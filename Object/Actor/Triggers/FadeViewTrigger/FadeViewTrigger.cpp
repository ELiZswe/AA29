// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/FadeViewTrigger/FadeViewTrigger.h"

AFadeViewTrigger::AFadeViewTrigger()
{
	TargetFlash = FVector(-2, -2, -2);
	FadeSeconds = 5;
	//bObsolete = true;
}

/*
State IsTriggered
{
	Event Tick(float DeltaTime)
	{
		FVector V = FVector(0,0,0);
		bool bXDone = false;
		bool bYDone = false;
		bool bZDone = false;
		if (bTriggered)
		{
			bXDone=false;
			bYDone=false;
			bZDone=false;
			V=(PhysicsVolume.ViewFlash - ((OldViewFlash - TargetFlash) * (DeltaTime / FadeSeconds)));
			if (V.X < TargetFlash.X)
			{
				V.X=TargetFlash.X;
				bXDone=true;
			}
			if (V.Y < TargetFlash.Y)
			{
				V.Y=TargetFlash.Y;
				bYDone=true;
			}
			if (V.Z < TargetFlash.Z)
			{
				V.Z=TargetFlash.Z;
				bZDone=true;
			}
			PhysicsVolume.ViewFlash=V;
			if ((bXDone && bYDone) && bZDone)
			{
				GotoState("None");
			}
		}
	}
}
*/

void AFadeViewTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (bTriggered && (!bTriggerOnceOnly))
	{
		bTriggered = false;
		PhysicsVolume.ViewFlash = OldViewFlash;
	}
	else
	{
		bTriggered = true;
		OldViewFlash = PhysicsVolume.ViewFlash;
		GotoState("IsTriggered");
	}
	*/
}
