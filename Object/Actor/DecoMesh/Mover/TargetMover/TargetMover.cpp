// All the original content belonged to the US Army

#include "AA29/Object/Actor/DecoMesh/Mover/TargetMover/TargetMover.h"
#include "AA29/Object/Actor/Triggers/RandomDispatcher/TargetManager/TargetManager.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"

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
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		if (! Other->IsA(ATargetManager::StaticClass()))
		{
			return;
		}
		my_manager=TargetManager(Other);
		bTargetPractice=my_manager.bTargetPractice;
		if (my_manager.bSkipTargets)
		{
			my_manager.ReportTargetSkipped(GroupNumber);
			return;
		}
		else
		{
			if (! bTargetPractice)
			{
				my_manager.ReportTargetUp(GroupNumber);
			}
		}
		bWasDamageTriggered=false;
		bDoUnTrigger=true;
		Super::Trigger(Other,EventInstigator);
	}
	Function UnTrigger(AActor* Other, APawn* EventInstigator)
	{
		if (bDoUnTrigger)
		{
			bTargetPractice=my_manager.bTargetPractice;
			bDoUnTrigger=false;
			Super::UnTrigger(Other,EventInstigator);
			if (! bTargetPractice)
			{
				my_manager.ReportTargetDown(GroupNumber,bWasDamageTriggered);
			}
		}
	}
	Function TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
	{
		if (bDamageTriggered && (float(Damage) >= DamageThreshold))
		{
			bWasDamageTriggered=true;
			Self.UnTrigger(this,instigatedBy);
		}
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this,ET_Destroyed,instigatedBy);
		}
	}
Begin:
	DoClose();
	FinishInterpolation();
	FinishedClosing();
	if (my_manager.bTargetPractice)
	{
		Sleep(fTargetPracticeDownTime);
		if (my_manager.bTargetPractice)
		{
			SavedTrigger=Self;
			bDoUnTrigger=true;
			GotoState("TriggerLogicControl","Open");
		}
	}
}
*/

