// All the original content belonged to the US Army


#include "AA29/Object/Actor/DecoMesh/Mover/TargetMover/TargetMover.h"

ATargetMover::ATargetMover()
{
	GroupNumber = -1;
	fTargetPracticeDownTime = 0.5;
	bDamageTriggered = true;
	//InitialState = "TriggerLogicControl";
}


/*
State TriggerLogicControl
{
	Function TakeDamage (int Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
	{
		if (bDamageTriggered && Damage >= DamageThreshold)
		{
			bWasDamageTriggered=True;
			Self.UnTrigger(Self,instigatedBy);
		}
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,8,instigatedBy);
		}
	}
	Function UnTrigger (Actor Other, Pawn EventInstigator)
	{
		if (bDoUnTrigger)
		{
			bTargetPractice=my_manager.bTargetPractice;
			bDoUnTrigger=False;
			UnTrigger(Other,EventInstigator);
			if (! bTargetPractice)
			{
				my_manager.ReportTargetDown(GroupNumber,bWasDamageTriggered);
			}
		}
	}
	Function Trigger (Actor Other, Pawn EventInstigator)
	{
		if (! Other.IsA('TargetManager'))
		{
			Return;
		}
		my_manager=TargetManager(Other);
		bTargetPractice=my_manager.bTargetPractice;
		if (my_manager.bSkipTargets)
		{
			my_manager.ReportTargetSkipped(GroupNumber);
			Return;
		}
		else
		{
			if (! bTargetPractice)
			{
				my_manager.ReportTargetUp(GroupNumber);
			}
		}
		bWasDamageTriggered=False;
		bDoUnTrigger=True;
		Trigger(Other,EventInstigator);
	}
}

*/