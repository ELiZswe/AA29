// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCVAERecruiterController/NPCVAERecruiterController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"

ANPCVAERecruiterController::ANPCVAERecruiterController()
{
	fpVertCollisionOffsetDown = 10;
	fpPlayerDetectionRange = 40;
	bStartAsDummyPawn = true;
}

/*
State HandOutLanyard
{
	Function EndState()
	{
		PlayCustomAnimation("LanyardIdle",true);
	}
	Function RemoveBlockingNPC()
	{
		AAGP_Pawn* agppIterator = nullptr;
		if (nameVAEBlockingNPC != "None")
		{
			ForEach DynamicActors(AAGP_Pawn::StaticClass(),agppIterator,nameVAEBlockingNPC)
			{
				Log("Destroying NPC");
				agppIterator.Destroy();
			}
		}
	}
Begin:
	scPlayer.Focus=Pawn;
	scPlayer.bRotateToDesired=true;
	scPlayer.FinishRotation();
	RemoveBlockingNPC();
	ivaelLanyard=Spawn(class<InventoryAttachment>(DynamicLoadObject("AGP_Inventory.Item_VAELanyard",Class'Class')));
	Pawn.AttachToBone(ivaelLanyard,"RHandObject");
	ivaelLanyard.SetDrawScale(0.75);
	ivaelLanyard.SetRelativeLocation(FVector(-3.5,-0.75,-1.5));
	ivaelLanyard.SetRelativeRotation(FRotator(-2048,4096,0));
	Sleep(0.5);
	Pawn->StopLIPSincAnim();
	if ((anameUserActivatedAudio.Num() > iAudioIndex) && (anameUserActivatedAudio[iAudioIndex] != "None"))
	{
		Pawn.PlayLIPSincAnim(anameUserActivatedAudio[iAudioIndex],1,256,1);
	}
	Pawn.AnimBlendParams(1,1,0.1,0);
	Pawn.PlayAnim("LanyardHandoff",1,2,1);
	Sleep(4.5);
	ivaelLanyard.bHidden=false;
	if (bDebug)
	{
		Sleep(3.5);
		Pawn.StopAnimating();
		scPlayer.ClientMessage("NPC Animation paused for attachment adjustment");
		JL"End"
;
	}
	Sleep(4.1);
	ivaelLanyard.Destroy();
	scPlayer.LockPlayer(false,false);
	scPlayer.Focus=nullptr;
	scPlayer.bRotateToDesired=false;
	Sleep(1.93);
	Pawn.StopAnimating(true);
	bRotateToDesired=false;
	Focus=nullptr;
	Cast<AAGP_Pawn>(Pawn)->AnimLoopAction="LanyardIdle";
	Pawn.PlayWaiting();
}
*/

/*
State ReceiveLanyard
{
	Function EndState()
	{
		PlayCustomAnimation("LanyardIdle",true);
	}
	Function RemoveBlockingNPC()
	{
		AAGP_Pawn* agppIterator = nullptr;
		if (nameVAEBlockingNPC != "None")
		{
			ForEach DynamicActors(AAGP_Pawn::StaticClass(),agppIterator,nameVAEBlockingNPC)
			{
				Log("On lanyard return, destroying NPC: " + FString::FromInt(nameVAEBlockingNPC));
				agppIterator.Destroy();
			}
		}
	}
Begin:
	scPlayer.Focus=Pawn;
	scPlayer.bRotateToDesired=true;
	scPlayer.FinishRotation();
	RemoveBlockingNPC();
	ivaelLanyard=Spawn(class<InventoryAttachment>(DynamicLoadObject("AGP_Inventory.Item_VAELanyard",Class'Class')));
	Pawn.AttachToBone(ivaelLanyard,"RHandObject");
	ivaelLanyard.SetDrawScale(0.75);
	ivaelLanyard.SetRelativeLocation(FVector(-3.5,-0.75,-1.5));
	ivaelLanyard.SetRelativeRotation(FRotator(-2048,4096,0));
	Sleep(0.5);
	Pawn->StopLIPSincAnim();
	if ((anameUserActivatedAudio.Num() > iAudioIndex) && (anameUserActivatedAudio[iAudioIndex] != "None"))
	{
		Pawn.PlayLIPSincAnim(anameUserActivatedAudio[iAudioIndex],1,256,1);
	}
	Pawn.AnimBlendParams(1,1,0.1,0);
	Pawn.PlayAnim("LanyardReturn",1,2,1);
	Sleep(2.3);
	ivaelLanyard.bHidden=false;
	Sleep(3.7);
	ivaelLanyard.Destroy();
	scPlayer.LockPlayer(false,false);
	scPlayer.Focus=nullptr;
	scPlayer.bRotateToDesired=false;
	Sleep(1.2);
	Pawn.StopAnimating(true);
	bRotateToDesired=false;
	Focus=nullptr;
	Cast<AAGP_Pawn>(Pawn)->AnimLoopAction="LanyardIdle";
	Pawn.PlayWaiting();
}
*/

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
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		Super::NotifyPlayerPawnInSight(pawnSeen);
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

void ANPCVAERecruiterController::PostBeginPlay()
{
	Super::PostBeginPlay();
	//Cast<AAGP_Pawn>(GetPawn())->AnimLoopAction = "LanyardIdle";
	//Cast<AAGP_Pawn>(GetPawn())->PlayWaiting();
}

bool ANPCVAERecruiterController::UsedBy(APawn* User)
{
	if (Cast<AStudentController>(User->Controller) != nullptr)
	{
		scPlayer = Cast<AStudentController>(User->Controller);
		scPlayer->npcvrcActive = this;
		if (bGivesLanyards)
		{
			if (scPlayer->bHasLanyard)
			{
				scPlayer->NotifyAdminMessage("You already have a lanyard, please proceed.");
				return true;
			}
			scPlayer->fpVAETimeLanyardTaken = GetWorld()->GetTimeSeconds();
			scPlayer->bHasLanyard = true;
			//scPlayer->LockPlayer(true, true);
			//GotoState("HandOutLanyard");
		}
		if (!bGivesLanyards)
		{
			if (!scPlayer->bHasLanyard)
			{
				scPlayer->NotifyAdminMessage("You need to pick up a lanyard from the entry area.");
				return true;
			}
			scPlayer->bHasLanyard = false;
			scPlayer->fpVAETimeLanyardReturned = GetWorld()->GetTimeSeconds();
			//scPlayer->LockPlayer(true, true);
			//GotoState("ReceiveLanyard");
		}
	}
	return false;    //FAKE  /ELiZ
}

void ANPCVAERecruiterController::FocusOnPlayer(APawn* Player)
{
	Focus = Player;
	//bRotateToDesired = true;
}

void ANPCVAERecruiterController::LoseFocusOnPlayer()
{
	Focus = nullptr;
	//bRotateToDesired = false;
}

void ANPCVAERecruiterController::BackupAfterBump(APawn* pawnBumpedInto)
{
}

/*
void ANPCVAERecruiterController::Possess(APawn* aPawn)
{
	Super::Possess(aPawn);
	Pawn.SetCollisionSize(aPawn.CollisionRadius, (aPawn.CollisionHeight - fpVertCollisionOffsetDown));
}
*/

void ANPCVAERecruiterController::NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
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
