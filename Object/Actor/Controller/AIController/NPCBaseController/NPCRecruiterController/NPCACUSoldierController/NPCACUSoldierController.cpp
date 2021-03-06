// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCACUSoldierController/NPCACUSoldierController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"

ANPCACUSoldierController::ANPCACUSoldierController()
{
}

/*
State GuardMode
{
	Function float InitializeGuardMode()
	{
		Super::InitializeGuardMode();
		ShoulderWeapon();
		return 2;
	}
}
*/

void ANPCACUSoldierController::InitializePawn()
{
	AAGP_Weapon* agpwPrimary = nullptr;
	Super::InitializePawn();
	if (namePrimaryWeapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->FindInventoryType(namePrimaryWeapon) == nullptr)
		{
			//agpwPrimary = Spawn(namePrimaryWeapon);
			if (agpwPrimary != nullptr)
			{
				//NPCLog("Pawn's primary weapon is " + FString::FromInt(agpwPrimary));
				agpwPrimary->GiveTo(Cast<AAGP_Pawn>(GetPawn()),nullptr);
				agpwPrimary->PickupFunction(Cast<AAGP_Pawn>(GetPawn()));
				Cast<AAGP_Pawn>(GetPawn())->Weapon = agpwPrimary;
				agpwPrimary->bGuerrillaWeapon = true;
			}
		}
	}
}

void ANPCACUSoldierController::ShoulderWeapon()
{
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->Weapon->PutDown();
	}
}

void ANPCACUSoldierController::Start()
{
	Super::Start();
}

bool ANPCACUSoldierController::UsedBy(APawn* User)
{
	Super::UsedBy(User);
	if (anameUserActivatedAudio.Num() > 0)
	{
		//Cast<AAGP_Pawn>(GetPawn())->StopLIPSincAnim();
		//Cast<AAGP_Pawn>(GetPawn())->PlayLIPSincAnim(anameUserActivatedAudio[iAudioIndex], 1, 256, 1);
		if (iAudioIndex < (anameUserActivatedAudio.Num() - 1))
		{
			iAudioIndex++;
		}
		else
		{
			iAudioIndex = 0;
		}
	}
	return true;
}
