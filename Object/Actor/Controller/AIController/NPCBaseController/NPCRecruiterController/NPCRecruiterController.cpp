// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRecruiterController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

ANPCRecruiterController::ANPCRecruiterController()
{
	Volume = 1;
	Radius = 255;
	Pitch = 1;
	fpPlayerDetectionRange = 200;
}

/*
State PawnStartsAsDummy
{
	Function NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
		Global.myPawn(pawnSeen);
	}
}
*/

void ANPCRecruiterController::PostBeginPlay()
{
	//Super::PostBeginPlay();
}

void ANPCRecruiterController::NotifyPlayerPawnSeen(APawn* Seen)
{
	if ((Cast<AAGP_Pawn>(Seen) != nullptr) && Cast<AAGP_Pawn>(Seen)->IsHumanControlled())
	{
		if (CanPawnSeeMe(Seen,false))
		{
			NotifyPlayerPawnWatchingMe(Seen);
		}
	}
}

void ANPCRecruiterController::NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
{
	/*
	if (anameUserActivatedAudio.Num() == 0)
	{
		return;
	}
	if ((VSize((pawnSeen.Location - Pawn.Location)) < fpPlayerDetectionRange) && (anameUserActivatedAudio.Num() > 0))
	{
		Focus = pawnSeen;
		if (Pawn.IsPlayingLIPSincAnim())
		{
			return;
		}
		if (!pawnSeen.IsHumanControlled())
		{
			return;
		}
		if (pawnPlayerRequestingInformation == pawnSeen)
		{
			return;
		}
		pawnPlayerRequestingInformation = pawnSeen;
		Pawn->StopLIPSincAnim();
		NPCLog("PlayLSAnim(): Calling PlayLipSincAnim() for anim: " + FString::FromInt(anameUserActivatedAudio[iAudioIndex]));
		Pawn.PlayLIPSincAnim(anameUserActivatedAudio[iAudioIndex], 1, 256, 1);
		if (bLockPlayerDuringSpeech)
		{
			Cast<APlayerController>(pawnSeen.Controller).LockPlayer(true, true);
		}
		if (iAudioIndex < (anameUserActivatedAudio.Num() - 1))
		{
			iAudioIndex++;
		}
		else
		{
			iAudioIndex = 0;
		}
	}
	else
	{
		if (pawnPlayerRequestingInformation != nullptr)
		{
			Log("Player leaving talking area - leaveaudio: " + FString::FromInt(nameUserLeavingAudio));
			if ((nameUserLeavingAudio != "None") && (pawnPlayerRequestingInformation != nullptr))
			{
				Focus = nullptr;
				if (Pawn.IsPlayingLIPSincAnim())
				{
					Pawn->StopLIPSincAnim();
				}
				Pawn.PlayLIPSincAnim(nameUserLeavingAudio, 1, 256, 1);
				GotoState("PawnStartsAsDummy", "RepeatAnim");
			}
			pawnPlayerRequestingInformation = nullptr;
		}
	}
	*/
}

void ANPCRecruiterController::Timer()
{
	/*
	Super::Timer();
	if (pawnPlayerRequestingInformation != nullptr)
	{
		if (VSize((pawnPlayerRequestingInformation.Location - Pawn.Location)) > fpPlayerDetectionRange)
		{
			NotifyPlayerPawnWatchingMe(pawnPlayerRequestingInformation);
		}
	}
	if (((bLockPlayerDuringSpeech && (pawnPlayerRequestingInformation != nullptr)) && (pawnPlayerRequestingInformation.Controller != nullptr)) && (!Pawn.IsPlayingLIPSincAnim()))
	{
		Cast<APlayerController>(pawnPlayerRequestingInformation.Controller).LockPlayer(false, false);
	}
	*/
}

bool ANPCRecruiterController::UsedBy(APawn* User)
{
	//Super::UsedBy(User);
	return true;
}

