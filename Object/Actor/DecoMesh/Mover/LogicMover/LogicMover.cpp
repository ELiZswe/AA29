// All the original content belonged to the US Army

#include "AA29/Object/Actor/DecoMesh/Mover/LogicMover/LogicMover.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"

ALogicMover::ALogicMover()
{
	GroupNumber = -1;
	//InitialState = "TriggerLogicControl"
}

/*
State TriggerLogicControl
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		SavedTrigger=Other;
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.BeginEvent();
		}
		GotoState("TriggerLogicControl","Open");
	}
	Function UnTrigger(AActor* Other, APawn* EventInstigator)
	{
		SavedTrigger=Other;
		SavedTrigger.BeginEvent();
		GotoState("TriggerLogicControl","Close");
	}
Begin:
	bClosed=false;
	if (DelayTime > 0)
	{
		bDelaying=true;
		Sleep(DelayTime);
	}
	DoOpen();
	FinishInterpolation();
	FinishedOpening();
	SavedTrigger.EndEvent();
	if (bTriggerOnceOnly)
	{
		GotoState("None");
	}
	DoClose();
	FinishInterpolation();
	FinishedClosing();
}
*/

/*
void ALogicMover::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (bDamageTriggered && Damage >= DamageThreshold)
	{
		Self.UnTrigger(this, instigatedBy);
	}
}

*/
