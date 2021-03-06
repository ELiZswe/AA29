// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRealHeroController/NPCRealHeroController.h"
#include "AA29/Object/Actor/RealHeroIcon/RealHeroIcon.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

ANPCRealHeroController::ANPCRealHeroController()
{
	fpVertCollisionOffsetDown = 10;
	MissionID = 0;
	fpPlayerDetectionRange = 40;
	bStartAsDummyPawn = true;
}

/*
State PawnStartsAsDummy
{
	Function float infront(Vector vec, APawn* Who)
	{
		FVector LookDir = FVector(0,0,0);
		FVector AimDir = FVector(0,0,0);
		LookDir= Vector(Who.Rotation);
		LookDir=Normal(LookDir);
		AimDir=(vec - Who.Location);
		AimDir=Normal(AimDir);
		return (LookDir Dot AimDir);
	}
	simulated Function Tick(float DeltaTime)
	{
		Global.pnCurrentRoadPathNode(DeltaTime);
		if (Cast<AAGP_Pawn>(Pawn)->bEyeTrack)
		{
			Cast<AAGP_Pawn>(Pawn)->EyeTrack();
		}
	}
	Event SeePlayer(APawn* Seen)
	{
		if (VSize((Pawn.Location - Seen.Location)) <= fpPlayerDetectionRange)
		{
			if (infront(Seen->GetActorLocation(),Pawn) < 0.7)
			{
				Pawn.RotationRate.Yaw=0;
				DesiredRotation=rotator((Seen.Location - Pawn.Location));
				FocalPoint=(Pawn.Location + (float(512) *  Vector(DesiredRotation)));
				bRotateToDesired=true;
			}
		}
		else
		{
			if (VSize((Pawn.Location - Seen.Location)) > (fpPlayerDetectionRange * 1.5))
			{
				DesiredRotation=rotInitialRotation;
				FocalPoint=(Pawn.Location + (float(512) *  Vector(DesiredRotation)));
				bRotateToDesired=true;
				Focus=nullptr;
			}
		}
		if ((Cast<AAGP_Pawn>(Seen) != nullptr) && Cast<AAGP_Pawn>(Seen).IsHumanControlled())
		{
			if (CanPawnSeeMe(Seen))
			{
				NotifyPlayerPawnWatchingMe(Seen);
			}
		}
	}
}
*/

void ANPCRealHeroController::PostBeginPlay()
{
	Super::PostBeginPlay();
}

bool ANPCRealHeroController::UsedBy(APawn* User)
{
	AStudentController* SC = nullptr;
	Super::UsedBy(User);
	SC = Cast<AStudentController>(User->Controller);
	if ((SC != nullptr) && (MissionID != 65536))
	{
		SC->iLastRealHeroVisited = MissionID;
	}
	return true;
}

void ANPCRealHeroController::DimAlpha()
{
	RHI->SetToMinAlpha();
}

void ANPCRealHeroController::BrightenAlpha()
{
	RHI->SetToMaxAlpha();
}

void ANPCRealHeroController::FocusOnPlayer(APawn* Player)
{
	Focus = Player;
	//bRotateToDesired = true;
}

void ANPCRealHeroController::LoseFocusOnPlayer()
{
	Focus = nullptr;
	//bRotateToDesired = false;
}

void ANPCRealHeroController::BackupAfterBump(APawn* pawnBumpedInto)
{
}

/*
void ANPCRealHeroController::Possess(APawn* aPawn)
{
	Super::Possess(aPawn);
	//Pawn.SetCollisionSize(aPawn.CollisionRadius, (aPawn.CollisionHeight - fpVertCollisionOffsetDown));
}
*/

void ANPCRealHeroController::NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
{
	if (anameUserActivatedAudio.Num() == 0)
	{
		return;
	}
	/*
	if ((VSize((pawnSeen.Location - Pawn.Location)) < fpPlayerDetectionRange) && (anameUserActivatedAudio.Num() > 0))
	{
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
