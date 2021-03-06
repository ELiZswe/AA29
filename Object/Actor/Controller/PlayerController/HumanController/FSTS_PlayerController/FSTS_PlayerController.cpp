// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/FSTS_PlayerController.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FSTS_EL_Utilities.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"

AFSTS_PlayerController::AFSTS_PlayerController()
{
	UseTraceDistance = 128;
}

void AFSTS_PlayerController::PostBeginPlay()
{
	//Super::PostBeginPlay();
	SetMasterScriptEventLab();
}

void AFSTS_PlayerController::SetMasterScriptEventLab()
{
	AFSTS_EL_Utilities* lab = nullptr;
	/*
	ForEach DynamicActors(AFSTS_EL_Utilities::StaticClass(), lab)
	{
		if ((lab != nullptr) && lab.IsMasterScript())
		{
			SetEventLab(lab);
			MasterScript = lab;
		}
		else
		{
		}
	}
	*/
}

void AFSTS_PlayerController::ThrowWeapon()
{
	if (bAllowThrowWeapon)
	{
		//Super::ThrowWeapon();
	}
}

void AFSTS_PlayerController::Fire(float F)
{
	//Super::Fire(F);
	/*
	Log(string(this) + ".Fire() pressed, event lab: " + FString::FromInt(EventLab));
	if (EventLab != nullptr)
	{
		EventLab.ELPlayerPressedFireNotifier();
	}
	*/
}

void AFSTS_PlayerController::Action()
{
	UseTrace();
	/*
	if (EventLab != nullptr)
	{
		EventLab.ELPlayerPressedActionKey();
	}
	Super::Action();
	*/
}

void AFSTS_PlayerController::LeanLeft()
{
	/*
	if (!GetLockMovement())
	{
		Super::LeanLeft();
	}
	*/
}

void AFSTS_PlayerController::LeanRight()
{
	/*
	if (!GetLockMovement())
	{
		Super::LeanRight();
	}
	*/
}

void AFSTS_PlayerController::UseTrace()
{
	AActor* HitActor = nullptr;
	AActor* BoneTraceActor = nullptr;
	FBoneInfo HitBone = FBoneInfo({});
	UMaterialInstance* HitMaterial = nullptr;
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	/*
	GetAxes(Pawn.GetViewRotation(), X, Y, Z);
	StartTrace = Pawn.EyePosition();
	EndTrace = (StartTrace + (X * UseTraceDistance));
	BoneTraceActor = BoneTrace(HitLocation, HitNormal, EndTrace, StartTrace, HitMaterial, HitBone, false);
	HitActor = Trace(HitLocation, HitNormal, EndTrace, StartTrace, true);
	MannequinTrace(BoneTraceActor, HitBone);
	MedicalPickupTrace(HitActor);
	DrillSergeantUsed(HitActor);
	*/
}

void AFSTS_PlayerController::MannequinTrace(AActor* HitActor, FBoneInfo HitBone)
{
}

void AFSTS_PlayerController::MedicalPickupTrace(AActor* HitActor)
{
}

void AFSTS_PlayerController::DrillSergeantUsed(AActor* Sarge)
{
	/*
	if (Cast<AFSTS_NPC_DrillSergeant>(Sarge) == nullptr)
	{
		return;
	}
	MasterScript.DrillSergeantUsed(Cast<AFSTS_NPC_DrillSergeant>(Sarge));
	*/
}

void AFSTS_PlayerController::DevMode(bool bSet)
{
}

bool AFSTS_PlayerController::IsUsingCheats()
{
	return bUsedCheats;
}

void AFSTS_PlayerController::MPCheat(FString cheat)
{
	ClientMessage("Cheating is not allowed");
}
