// All the original content belonged to the US Army


#include "AA29/Object/Actor/DecoMesh/Mover/LogicMover/LogicMover.h"

ALogicMover::ALogicMover()
{
	GroupNumber = -1;
	//InitialState = "TriggerLogicControl"
}
/*
State TriggerLogicControl
{
	Function UnTrigger(Actor Other, Pawn EventInstigator)
	{
		SavedTrigger = Other;
		SavedTrigger.BeginEvent();
		GotoState('TriggerLogicControl','Close');
	}
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		SavedTrigger = Other;
		if (SavedTrigger != None)
		{
			SavedTrigger.BeginEvent();
		}
		GotoState('TriggerLogicControl','Open');
	}
}
*/
/*
void TakeDamage(int Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (bDamageTriggered && Damage >= DamageThreshold)
	{
		Self.UnTrigger(Self, instigatedBy);
	}
}

*/