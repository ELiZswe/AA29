// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_Pawn.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FSTS_EL_Utilities.h"

AFSTS_Pawn::AFSTS_Pawn()
{

}

void AFSTS_Pawn::DoReload()
{
	/*
	Super::DoReload();
	if (Cast<AFSTS_EL_Utilities>(EventLab) != nullptr)
	{
		FSTS_EL_Utilities(EventLab).ReloadEvent(Weapon);
	}
	*/
}

void AFSTS_Pawn::ClientAlertOutOfBounds(int32 Seconds)
{
	/*
	if (Cast<APlayerController>(Controller).myHUD != nullptr)
	{
		Cast<APlayerController>(Controller).myHUD.DisplayCenteredMessage(1.1, "You have left the training area!", "You have" @ FString::FromInt(Seconds) @ "seconds to return...");
	}
	*/
}

void AFSTS_Pawn::OutOfBoundsNotifyKillPlayer()
{
	/*
	if (Cast<APlayerController>(Controller).myHUD != nullptr)
	{
		Cast<APlayerController>(Controller).myHUD.DisplayCenteredMessage(3, "Failed to return to the training area.");
	}
	*/
}

void AFSTS_Pawn::ClientAlertReturnedToCombat()
{
	/*
	if (Cast<APlayerController>(Controller).myHUD != nullptr)
	{
		Cast<APlayerController>(Controller).myHUD.DisplayCenteredMessage(3, "You have returned to the training area.");
	}
	*/
}

void AFSTS_Pawn::OutOfBoundsCheck()
{
	/*
	if (OutOfBounds > 0)
	{
		(TimeOutOfBounds += 0.5);
		ClientAlertOutOfBounds(int(Ceil((CurrentZoneTimeToKill - TimeOutOfBounds))));
	}
	if ((CurrentZoneTimeToKill - TimeOutOfBounds) <= 0)
	{
		StopCustomTimer("OutOfBoundsCheck");
		OutOfBounds++;
		Cast<AHumanController>(Controller).DisplayMissionFailure("", "You failed to stay within training areas.", "Come back tomorrow and try again.", 128, 128, 6, "None");
	}
	*/
}
