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
	if (anameUserActivatedAudio.Length == 0)
	{
		return;
	}
	if ((VSize((pawnSeen.Location - Pawn.Location)) < fpPlayerDetectionRange) && (anameUserActivatedAudio.Length > 0))
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
		Pawn.StopLIPSincAnim();
		NPCLog("PlayLSAnim(): Calling PlayLipSincAnim() for anim: " $ string(anameUserActivatedAudio[iAudioIndex]));
		Pawn.PlayLIPSincAnim(anameUserActivatedAudio[iAudioIndex], 1, 256, 1);
		if (bLockPlayerDuringSpeech)
		{
			PlayerController(pawnSeen.Controller).LockPlayer(true, true);
		}
		if (iAudioIndex < (anameUserActivatedAudio.Length - 1))
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
		if (pawnPlayerRequestingInformation != None)
		{
			Log("Player leaving talking area - leaveaudio: " $ string(nameUserLeavingAudio));
			if ((nameUserLeavingAudio != "None") && (pawnPlayerRequestingInformation != None))
			{
				Focus = None;
				if (Pawn.IsPlayingLIPSincAnim())
				{
					Pawn.StopLIPSincAnim();
				}
				Pawn.PlayLIPSincAnim(nameUserLeavingAudio, 1, 256, 1);
				GotoState("PawnStartsAsDummy", "RepeatAnim");
			}
			pawnPlayerRequestingInformation = None;
		}
	}
	*/
}

void ANPCRecruiterController::Timer()
{
	/*
	Super::Timer();
	if (pawnPlayerRequestingInformation != None)
	{
		if (VSize((pawnPlayerRequestingInformation.Location - Pawn.Location)) > fpPlayerDetectionRange)
		{
			NotifyPlayerPawnWatchingMe(pawnPlayerRequestingInformation);
		}
	}
	if (((bLockPlayerDuringSpeech && (pawnPlayerRequestingInformation != None)) && (pawnPlayerRequestingInformation.Controller != None)) && (!Pawn.IsPlayingLIPSincAnim()))
	{
		PlayerController(pawnPlayerRequestingInformation.Controller).LockPlayer(false, false);
	}
	*/
}

bool ANPCRecruiterController::UsedBy(APawn* User)
{
	//Super::UsedBy(User);
	return true;
}

