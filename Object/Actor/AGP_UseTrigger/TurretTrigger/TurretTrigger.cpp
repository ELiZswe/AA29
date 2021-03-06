// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_UseTrigger/TurretTrigger/TurretTrigger.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

ATurretTrigger::ATurretTrigger()
{
	UseFOV = 85;
	bUseTriggered = true;
	bToggle = true;
	SwitchState = "Manning_Turret";
	//bStatic = true;
	//bBlockNonZeroExtentTraces = true;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP_Gameplay/S_TurretTrigger.S_TurretTrigger'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}

void ATurretTrigger::SetActive(bool Active)
{
	bActive = Active;
}

bool ATurretTrigger::IsActive()
{
	return bActive;
}

void ATurretTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (bActive)
	{
		HC = Cast<AHumanController>(EventInstigator->Controller);
		C = EventInstigator->Controller;
		if (IsError())
		{
			return;
		}
		//AssociatedActor = GetActorByTag(ViewActorTag);
		HC->SetTurret(AssociatedActor);
		HC->turretFOV = UseFOV;
		//	C->GotoState(SwitchState);
	}
}

void ATurretTrigger::UnTrigger(AActor* Other, APawn* EventInstigator)
{
}

bool ATurretTrigger::UsedBy(APawn* User)
{
	if (bActive && bUseTriggered)
	{
		HC = Cast<AHumanController>(User->Controller);
		if (!IsError())
		{
			Trigger(this, User);
			return true;
		}
	}
	return false;
}

bool ATurretTrigger::IsError()
{
	if (HC == nullptr)
	{
		//Log("TurretTrigger::IsError(): ERROR: Invalid HumanController in Pawn");
		return true;
	}
	if (ViewActorTag == "None")
	{
		//Log("TurretTrigger::IsError(): ERROR: ViewActorTag == nullptr");
		return true;
	}
	if (SwitchState == "None")
	{
		//Log("TurretTrigger::IsError(): ERROR: SwitchState == nullptr");
		return true;
	}
	return false;    //FAKE   /ELiZ
}

FRotator ATurretTrigger::LookRotation(FVector LookActorLoc, FVector TargetActorLoc)
{
	//return FRotator((TargetActorLoc - LookActorLoc));
	return FRotator(0, 0, 0);
}
