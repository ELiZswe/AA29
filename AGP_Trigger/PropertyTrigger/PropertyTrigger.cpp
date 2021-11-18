// All the original content belonged to the US Army


#include "AA29/AGP_Trigger/PropertyTrigger/PropertyTrigger.h"


APropertyTrigger::APropertyTrigger()
{
	bToggle = true;
}


void APropertyTrigger::BeginPlay()
{
	/*
	local int i;
	for (i = 0; i < TargetActors.Length; i++)
	{
		TargetActors[i].ActorRef = GetActorByTag(TargetActors[i].ActorTag);
		if (TargetActors[i].ActorRef == None)
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
				Return;
	}
	*/
}
void APropertyTrigger::Touch(AActor* Other)
{
	/*
	local Pawn Pawn;
	if (!bTouchTriggered)
	{
		Return;
	}
	Pawn = Pawn(Other);
	if (Pawn.Controller.IsA('HumanController'))
	{
		Trigger(Self, Pawn);
	}
	*/
}
void APropertyTrigger::UnTouch(AActor* Other)
{
	/*
	local Pawn Pawn;
	if (!bTouchTriggered)
	{
		Return;
	}
	Pawn = Pawn(Other);
	if (Pawn.Controller.IsA('HumanController'))
	{
		UnTrigger(Self, Pawn);
	}
	*/
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
	local int i;
	Log("SETPROPERTIES");
	for (i = 0; i < TargetActors.Length; i++)
	{
		if (TargetActors[i].ActorRef != None)
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
	local int i;
	Log("UNSETPROPERTIES");
	for (i = 0; i < TargetActors.Length; i++)
	{
		if (TargetActors[i].ActorRef != None)
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
	bSet = False;
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
