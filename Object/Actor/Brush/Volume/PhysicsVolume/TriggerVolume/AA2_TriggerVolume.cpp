// All the original content belonged to the US Army


#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/TriggerVolume/AA2_TriggerVolume.h"

AAA2_TriggerVolume::AAA2_TriggerVolume()
{
	TriggerVolumeHelp.SetNum(12);
	TriggerVolumeHelp[0] = "Works like a standard trigger but uses a volume;";
	TriggerVolumeHelp[1] = "this allows triggers to be brush-shaped.";
	TriggerVolumeHelp[3] = "[ActorType] Determines which actors trigger the volume.";
	TriggerVolumeHelp[4] = "[bDoUnTrigger] If true, the UnTrigger event is called on actor exit";
	TriggerVolumeHelp[5] = "[SpecificActors] Add actors to the list -- only these actors will";
	TriggerVolumeHelp[6] = "trigger the volume. Make sure ActorType is ACTOR_SpecificActors to";
	TriggerVolumeHelp[7] = "use this feature";
	ActorType = EActorType::ACTOR_PlayersOnly;
	bActive = true;
	//bStatic = false;
	//Group = "TriggerVolume";
}

void AAA2_TriggerVolume::SetActive(bool Active)
{
	bActive = Active;
}

void AAA2_TriggerVolume::EnableTrigger()
{
	bActive = true;
}

void AAA2_TriggerVolume::DisableTrigger()
{
	bActive = false;
}

void AAA2_TriggerVolume::ActorEnteredVolume(AActor* Other)
{
	int32 i = 0;
	if (!bActive)
	{
		return;
	}
	/*
	switch (ActorType)
	{
	case 1:
		TriggerEvent(Event, Other, None);
		break;
	case 4:
		i = 0;
		if (i < SpecificActors.Length)
		{
			if (ClassIsChildOf(Other.Class, SpecificActors[i]))
			{
				if (EventLab != None)
				{
					EventLab.ActorNotify(Self, ET_Exit, Other);
				}
				TriggerEvent(Event, Other, None);
				Other.EnterVolume(Self);
				Other.EnterTrigger(Self);
			}
			else
			{
				i++;
			}
		}
		GOTO JL00D1;
	default:
		GOTO JL00D1;
	JL00D1:
	}
	*/
}

void AAA2_TriggerVolume::ActorLeavingVolume(AActor* Other)
{
	/*
	int32 i = 0;
	if (!bActive)
	{
		return;
	}
	switch (ActorType)
	{
	case 1:
		if (bDoUnTrigger)
		{
			UntriggerEvent(Event, Other, None);
		}
		break;
	case 4:
		i = 0;
		if (i < SpecificActors.Length)
		{
			if (ClassIsChildOf(Other.Class, SpecificActors[i]))
			{
				if (bDoUnTrigger)
				{
					UntriggerEvent(Event, Other, None);
				}
				if (EventLab != None)
				{
					EventLab.ActorNotify(Self, ET_Damaged, Other);
				}
				Other.ExitVolume(Self);
				Other.ExitTrigger(Self);
			}
			else
			{
				i++;
			}
		}
		GOTO JL00E3;
	default:
		GOTO JL00E3;
	JL00E3:
	}
	*/
}

void AAA2_TriggerVolume::PawnEnteredVolume(APawn* Other)
{
	/*
	if (!bActive)
	{
		return;
	}
	switch (ActorType)
	{
	case 2:
		TriggerEvent(Event, Self, Other);
		Other.EnterVolume(Self);
		Other.EnterTrigger(Self);
		break;
	case 3:
		if (Other.IsPlayerPawn())
		{
			if (EventLab != None)
			{
				EventLab.ActorNotify(Self, ET_Exit, Other);
			}
			TriggerEvent(Event, Self, Other);
			Other.EnterVolume(Self);
			Other.EnterTrigger(Self);
		}
		break;
	default:
		break;
	}
	*/
}

void AAA2_TriggerVolume::PawnLeavingVolume(APawn* Other)
{
	/*
	if (!bActive)
	{
		return;
	}
	switch (ActorType)
	{
	case 2:
		if (bDoUnTrigger)
		{
			UntriggerEvent(Event, Self, Other);
		}
		Other.ExitVolume(Self);
		Other.ExitTrigger(Self);
		break;
	case 3:
		if (Other.IsPlayerPawn())
		{
			if (EventLab != None)
			{
				EventLab.ActorNotify(Self, ET_Damaged, Other);
			}
			if (bDoUnTrigger)
			{
				UntriggerEvent(Event, Self, Other);
			}
			Other.ExitVolume(Self);
			Other.ExitTrigger(Self);
		}
		break;
	default:
		break;
	}
	*/
}

void AAA2_TriggerVolume::PreBeginPlay()
{
}

void AAA2_TriggerVolume::BeginPlay()
{
}

void AAA2_TriggerVolume::PostBeginPlay()
{
}

void AAA2_TriggerVolume::PhysicsChangedFor(AActor* Other)
{
}

void AAA2_TriggerVolume::Touch(AActor* Other)
{
}

void AAA2_TriggerVolume::UnTouch(AActor* Other)
{
}

void AAA2_TriggerVolume::TimerPop(AVolumeTimer* t)
{
}

void AAA2_TriggerVolume::Trigger(AActor* Other, APawn* EventInstigator)
{
}

void AAA2_TriggerVolume::PlayEntrySplash(AActor* Other)
{
}

void AAA2_TriggerVolume::PlayExitSplash(AActor* Other)
{
}

void AAA2_TriggerVolume::CausePainTo(AActor* Other)
{
}

bool AAA2_TriggerVolume::BetterThan(AActor* Other)
{
	return false;    //FAKE   /ELiZ
}

AActor* AAA2_TriggerVolume::GetNearbyObjective(bool bDefender)
{
	return nullptr;    //FAKE   /ELiZ
}

void AAA2_TriggerVolume::SetAssociatedActor(AActor* Other)
{
}

void AAA2_TriggerVolume::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
}

void AAA2_TriggerVolume::Reset()
{
}

void AAA2_TriggerVolume::MatchStarting()
{
}