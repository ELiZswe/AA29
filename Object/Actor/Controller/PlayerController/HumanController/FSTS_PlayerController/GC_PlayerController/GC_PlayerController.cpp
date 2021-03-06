// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/GC_PlayerController/GC_PlayerController.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FSTS_EL_Utilities.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_MasterScript.h"

AGC_PlayerController::AGC_PlayerController()
{

}

void AGC_PlayerController::Crouching()
{
	bool bOldLockMovement = false;
	bool bOldLockRotation = false;
	/*
	bOldLockMovement = GetLockMovement();
	bOldLockRotation = GetLockRotation();
	LockPlayer(false, false);
	Super::Crouching();
	LockPlayer(bOldLockMovement, bOldLockRotation);
	*/
	CrouchEvent();
}

void AGC_PlayerController::Crawling()
{
	bool bOldLockMovement = false;
	bool bOldLockRotation = false;
	/*
	bOldLockMovement = GetLockMovement();
	bOldLockRotation = GetLockRotation();
	LockPlayer(false, false);
	Super::Crawling();
	LockPlayer(bOldLockMovement, bOldLockRotation);
	*/
	CrawlEvent();
}

void AGC_PlayerController::CrouchEvent()
{
	AFSTS_EL_Utilities* ActiveScript = nullptr;
	if (MasterScript != nullptr)
	{
		//ActiveScript = Cast<AFSTS_EL_Utilities>(MasterScript.GetActiveScript());
		if (ActiveScript != nullptr)
		{
			ActiveScript->CrouchEvent();
		}
	}
}

void AGC_PlayerController::CrawlEvent()
{
	AFSTS_EL_Utilities* ActiveScript = nullptr;
	if (MasterScript != nullptr)
	{
		//ActiveScript = Cast<AFSTS_EL_Utilities>(MasterScript.GetActiveScript());
		if (ActiveScript != nullptr)
		{
			ActiveScript->CrawlEvent();
		}
	}
}

void AGC_PlayerController::ThrowWeapon()
{
}

void AGC_PlayerController::Grenade(uint8 Index)
{
	/*
	if (Cast<AGC_EL_MasterScript>(EventLab) != nullptr)
	{
		if (Cast<AGC_EL_MasterScript>(EventLab).AllowGrenade())
		{
			Super::Grenade(Index);
		}
	}
	else
	{
		Super::Grenade(Index);
	}
	*/
}
