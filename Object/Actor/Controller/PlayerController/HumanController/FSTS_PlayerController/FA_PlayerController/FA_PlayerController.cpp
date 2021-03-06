// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/FA_PlayerController/FA_PlayerController.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_MasterScript.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FSTS_EL_Utilities.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_MasterScript.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalPickups/FSTS_FA_MedicalPickups.h"

AFA_PlayerController::AFA_PlayerController()
{
	bHUDHideAmmoCount = true;
	bHUDHideWeaponStatus = true;
	bHUDHideWeapon = true;
	bHUDHideGrenades = true;
	bHUDHideCombatEffect = true;
	bHUDHideOptics = true;
	bHUDHideCompass = true;
	bHUDHideTimer = true;
	bHUDHideObjectives = true;
	bHUDHideRadar = true;
}

void AFA_PlayerController::Fire(float F)
{
	AFSTS_EL_Utilities* ActiveScript = nullptr;
	Super::Fire(F);
	if (FAMasterScript != nullptr)
	{
		ActiveScript = Cast<AFSTS_EL_Utilities>(FAMasterScript->GetActiveScript());
		if (ActiveScript != nullptr)
		{
			ActiveScript->LMouseClickEvent();
		}
	}
}

void AFA_PlayerController::Crouching()
{
	//Super::Crouching();
	CrouchEvent();
}

void AFA_PlayerController::Crawling()
{
	bool bLockMovementChanged = false;
	/*
	if (GetLockMovement())
	{
		bLockMovementChanged = true;
		LockPlayer(false, GetLockRotation());
	}
	Super::Crawling();
	if (bLockMovementChanged)
	{
		LockPlayer(true, GetLockRotation());
	}
	*/
	CrawlEvent();
}

void AFA_PlayerController::CrouchEvent()
{
	AFSTS_EL_Utilities* ActiveScript = nullptr;
	if (FAMasterScript != nullptr)
	{
		ActiveScript = Cast<AFSTS_EL_Utilities>(FAMasterScript->GetActiveScript());
		if (ActiveScript != nullptr)
		{
			ActiveScript->CrouchEvent();
		}
	}
}

void AFA_PlayerController::CrawlEvent()
{
	AFSTS_EL_Utilities* ActiveScript = nullptr;
	if (FAMasterScript != nullptr)
	{
		ActiveScript = Cast<AFSTS_EL_Utilities>(FAMasterScript->GetActiveScript());
		if (ActiveScript != nullptr)
		{
			ActiveScript->CrawlEvent();
		}
	}
}

void AFA_PlayerController::MannequinTrace(AActor* HitActor, FBoneInfo HitBone)
{
	AFA_EL_MasterScript* ActiveScript = nullptr;
	/*
	if ((HitActor == nullptr) || (Cast<APawn>(HitActor) == nullptr))
	{
		return;
	}
	if (FAMasterScript != nullptr)
	{
		//ActiveScript = FAMasterScript.GetFAActiveScript();
		if ((ActiveScript == nullptr) || ActiveScript->bDeleteMe)
		{
			//Log("ActiveScript could not be assigned, breaking out of FA_PlayerController::MannequinTrace()");
			return;
		}
		ActiveScript->MannequinTrace(HitActor, HitBone);
	}
	else
	{
		//Log("FAMasterScript is none, breaking out of FA_PlayerController::MannequinTrace()");
		return;
	}
	*/
}

void AFA_PlayerController::MedicalPickupTrace(AActor* HitActor)
{
	AFA_EL_MasterScript* ActiveScript = nullptr;
	/*
	if ((HitActor == nullptr) || (Cast<AFSTS_FA_MedicalPickups>(HitActor) == nullptr))
	{
		return;
	}
	if (FAMasterScript != nullptr)
	{
		//ActiveScript = FAMasterScript.GetFAActiveScript();
		if ((ActiveScript == nullptr) || ActiveScript->bDeleteMe)
		{
			//Log("ActiveScript could not be assigned, breaking out of CheckIfProperMedPickup()");
			return;
		}
		ActiveScript->HandleMedPickup(HitActor);
	}
	else
	{
		//Log("FAMasterScript is none, breaking out of CheckIfProperMedPickup()");
		return;
	}
	*/
}

void AFA_PlayerController::SetMasterScriptEventLab()
{
	//Super::SetMasterScriptEventLab();
	//FAMasterScript = Cast<AFA_EL_MasterScript>(MasterScript);
}

