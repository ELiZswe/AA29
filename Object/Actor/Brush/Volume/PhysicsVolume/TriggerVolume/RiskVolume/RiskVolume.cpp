// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/TriggerVolume/RiskVolume/RiskVolume.h"
#include "AA29/Object/Actor/Info/VolumeTimer/VolumeTimer.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "Engine/Canvas.h"

ARiskVolume::ARiskVolume()
{
	RiskVolumeHelp.SetNum(7);
	RiskVolumeHelp = {
		"Designed for the E and E map, to create areas",
		"of high or low detection risk. This entity reports",
		"a 'Risk' parameter to Eventlab when entered or exited.",
		"[EnterRisk] The detection risk when this volume is entered",
		"[ExitRisk] The detection risk when this volume is exited",
	};
	EnterRisk = 1;
	ExitRisk = 1;
	//Group = "RiskVolume";
}

void ARiskVolume::PawnEnteredVolume(APawn* Other)
{
	/*
	if (Other.Controller->IsA(AHumanController::StaticClass()))
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this, ET_Exit, Other, "RISK," + FString::FromInt(EnterRisk));
		}
		TriggerEvent(Event, this, Other);
		Other.EnterVolume(this);
		Other.EnterTrigger(this);
	}
	*/
}

void ARiskVolume::PawnLeavingVolume(APawn* Other)
{
	/*
	if (Other.Controller->IsA(AHumanController::StaticClass()))
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this, ET_Damaged, Other, "RISK," + FString::FromInt(ExitRisk));
		}
		if (bDoUnTrigger)
		{
			UntriggerEvent(Event, this, Other);
		}
		Other.ExitVolume(this);
		Other.ExitTrigger(this);
	}
	*/
}

void ARiskVolume::PreBeginPlay()
{
}

void ARiskVolume::BeginPlay()
{
}

void ARiskVolume::PostBeginPlay()
{
}

void ARiskVolume::PhysicsChangedFor(AActor* Other)
{
}

void ARiskVolume::Touch(AActor* Other)
{
}

void ARiskVolume::UnTouch(AActor* Other)
{
}

void ARiskVolume::TimerPop(AVolumeTimer* t)
{
}

void ARiskVolume::Trigger(AActor* Other, APawn* EventInstigator)
{
}

void ARiskVolume::PlayEntrySplash(AActor* Other)
{
}

void ARiskVolume::PlayExitSplash(AActor* Other)
{
}

void ARiskVolume::CausePainTo(AActor* Other)
{
}

bool ARiskVolume::BetterThan(AActor* Other)
{
	return false;    //FAKE   /ELiZ
}

AActor* ARiskVolume::GetNearbyObjective(bool bDefender)
{
	return nullptr;     //FAKE   /ELiZ
}

void ARiskVolume::SetAssociatedActor(AActor* Other)
{
}

void ARiskVolume::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
}

void ARiskVolume::ActorEnteredVolume(AActor* Other)
{
}

void ARiskVolume::ActorLeavingVolume(AActor* Other)
{
}
