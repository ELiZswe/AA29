// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_Trigger/PropertyTrigger/PropertyTrigger.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

APropertyTrigger::APropertyTrigger()
{
	bToggle = true;
}

void APropertyTrigger::BeginPlay()
{
	/*
	int32 i = 0;
	for (i = 0; i < TargetActors.Num(); i++)
	{
		TargetActors[i].ActorRef = GetActorByTag(TargetActors[i].ActorTag);
		if (TargetActors[i].ActorRef == nullptr)
		{
			Log("PropertyTrigger::BeginPlay(): WARNING: Actor not found for tag: " @ TargetActors[i].ActorTag);
		}
	}
	switch(StartType)
	{
			case 1:
				SetProperties();
				break;
			case 2:
				UnSetProperties();
				break;
			default:
				return;
	}
	*/
}
void APropertyTrigger::Touch(AActor* Other)
{
	APawn* Pawn = nullptr;
	if (!bTouchTriggered)
	{
		return;
	}
	Pawn = Cast<APawn>(Other);
	if (Pawn->Controller->IsA(AHumanController::StaticClass()))
	{
		Trigger(this, Pawn);
	}
}

void APropertyTrigger::UnTouch(AActor* Other)
{
	APawn* Pawn = nullptr;
	if (!bTouchTriggered)
	{
		return;
	}
	Pawn = Cast<APawn>(Other);
	if (Pawn->Controller->IsA(AHumanController::StaticClass()))
	{
		UnTrigger(this, Pawn);
	}
}
void APropertyTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (!bToggle)
	{
		SetProperties();
		return;
	}
	if (!bSet)
	{
		SetProperties();
	}
	else
	{
		UnSetProperties();
	}
}
void APropertyTrigger::UnTrigger(AActor* Other, APawn* EventInstigator)
{
	
	if (bToggle)
	{
		return;
	}
	else
	{
		UnSetProperties();
	}
}
void APropertyTrigger::SetProperties()
{
	/*
	int32 i = 0;
	Log("SETPROPERTIES");
	for (i = 0; i < TargetActors.Num(); i++)
	{
		if (TargetActors[i].ActorRef != nullptr)
		{
			if (TargetActors[i].PropertyFlags.bHidden)
			{
				Set_bHidden(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.bBlockActors)
			{
				Set_bBlockActors(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.bBlockPlayers)
			{
				Set_bBlockPlayers(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.bBlockZeroExtentTraces)
			{
				Set_bBlockZeroExtentTraces(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.bBlockNonZeroExtentTraces)
			{
				Set_bBlockNonZeroExtentTraces(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.AmbientGlow)
			{
				Set_AmbientGlow(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.DrawScale)
			{
				Set_DrawScale(TargetActors[i]);
			}
		}
	}
	bSet = true;
	*/
}
void APropertyTrigger::UnSetProperties()
{
	/*
	int32 i = 0;
	Log("UNSETPROPERTIES");
	for (i = 0; i < TargetActors.Num(); i++)
	{
		if (TargetActors[i].ActorRef != nullptr)
		{
			if (TargetActors[i].PropertyFlags.bHidden)
			{
				UnSet_bHidden(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.bBlockActors)
			{
				UnSet_bBlockActors(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.bBlockPlayers)
			{
				UnSet_bBlockPlayers(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.bBlockZeroExtentTraces)
			{
				UnSet_bBlockZeroExtentTraces(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.bBlockNonZeroExtentTraces)
			{
				UnSet_bBlockNonZeroExtentTraces(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.AmbientGlow)
			{
				UnSet_AmbientGlow(TargetActors[i]);
			}
			if (TargetActors[i].PropertyFlags.DrawScale)
			{
				UnSet_DrawScale(TargetActors[i]);
			}
		}
	}
	bSet = false;
	*/
}
void APropertyTrigger::Set_bHidden(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.bHidden = TargetActor.SetValues.bHidden;
}
void APropertyTrigger::UnSet_bHidden(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.bHidden = TargetActor.UnSetValues.bHidden;
}
void APropertyTrigger::Set_bBlockActors(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.bBlockActors = TargetActor.SetValues.bBlockActors;
}
void APropertyTrigger::UnSet_bBlockActors(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.bBlockActors = TargetActor.UnSetValues.bBlockActors;
}
void APropertyTrigger::Set_bBlockPlayers(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.bBlockPlayers = TargetActor.SetValues.bBlockPlayers;
}
void APropertyTrigger::UnSet_bBlockPlayers(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.bBlockPlayers = TargetActor.UnSetValues.bBlockPlayers;
}
void APropertyTrigger::Set_bBlockZeroExtentTraces(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.bBlockZeroExtentTraces = TargetActor.SetValues.bBlockZeroExtentTraces;
}
void APropertyTrigger::UnSet_bBlockZeroExtentTraces(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.bBlockZeroExtentTraces = TargetActor.UnSetValues.bBlockZeroExtentTraces;
}
void APropertyTrigger::Set_bBlockNonZeroExtentTraces(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.bBlockNonZeroExtentTraces = TargetActor.SetValues.bBlockNonZeroExtentTraces;
}
void APropertyTrigger::UnSet_bBlockNonZeroExtentTraces(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.bBlockNonZeroExtentTraces = TargetActor.UnSetValues.bBlockNonZeroExtentTraces;
}
void APropertyTrigger::Set_AmbientGlow(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.AmbientGlow = TargetActor.SetValues.AmbientGlow;
	//Log("SetAmbientGlow: " @ TargetActor.ActorRef.AmbientGlow);
}
void APropertyTrigger::UnSet_AmbientGlow(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.AmbientGlow = TargetActor.UnSetValues.AmbientGlow;
	//Log("UnSetAmbientGlow: " @ TargetActor.ActorRef.AmbientGlow);
}
void APropertyTrigger::Set_DrawScale(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.SetDrawScale(TargetActor.SetValues.DrawScale);
}
void APropertyTrigger::UnSet_DrawScale(FTargetActor TargetActor)
{
	//TargetActor.ActorRef.SetDrawScale(TargetActor.UnSetValues.DrawScale);
}
