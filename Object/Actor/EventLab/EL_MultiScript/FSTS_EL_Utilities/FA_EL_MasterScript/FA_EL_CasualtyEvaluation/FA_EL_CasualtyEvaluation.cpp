// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_CasualtyEvaluation/FA_EL_CasualtyEvaluation.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_CasualtyEvalMannequin.h"
#include "AA29/Object/Actor/FSTS_HelpMarker/FSTS_HelpMarker.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_DS_Moore.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"

AFA_EL_CasualtyEvaluation::AFA_EL_CasualtyEvaluation()
{
	DrillSergeantTag = "FA_NPC_DS_Moore";
	StationObjectiveTag = "Station1Objective";
	StationBeginPointTag = "Station_1_Stand_Point";
	bAcceptDrillSergeantUse = true;
	bStartFromDrillSergeantUse = true;
	bFadeMoveFromDrillSergeantUse = true;
	StationName = "Evaluate a Casualty";
	HelpInfoList = {
		FHelpInfo({"ClickOnMannequinAppendages",30,"Press the <Action> key on each major body part:","the head, chest, and legs","fa_station1_11",nullptr})
	};
	bDormant = true;
	bMasterScript = false;
	bDoGeneralInit = false;
}

/*
simulated State ActiveExecute
{
	simulated Function BeginState()
	{
		Log("Beginning ActiveExecute state for " + FString::FromInt(this));
		ActivatePlayerBlocking(GetPlayerBlockingVolume("Station1_StartBlock"));
		ActivatePlayerBlocking(GetPlayerBlockingVolume("Station1_EndBlock"));
		ForceDrawPlayerCrosshair(true);
	}
	simulated Function NotifyFadeMoveStart(FName PlayerMoveName)
	{
		SetDrillSergeantParams(false,false,false);
	}
	simulated Function NotifyFadeMoveMiddle(FName PlayerMoveName)
	{
		SetPlayerWeapon(false,true);
		DeactivateHelpMarker(HelpMarker);
	}
	simulated Function NotifyFadeMoveEnd(FName PlayerMoveName)
	{
		PlayerLock(false,false);
		ForcePlayerCrouch(true);
		PlayerLock(true,false);
		PlayTip("Station 1 - Evaluate a Casualty","",5);
		PlayLSAnim("fa_station1_1",DrillSergeant);
	}
	simulated Function EventLabTick(float DeltaTime)
	{
		Global.FA_RucksackPickup(DeltaTime);
	}
	simulated Function MannequinTrace(AActor* HitActor, FBoneInfo HitBone)
	{
		if (((HitActor == nullptr) || (! HitActor->IsA(AFA_NPC_CasualtyEvalMannequin::StaticClass()))) || (HitBone.HitBone == 0))
		{
			Log("Unable to run MannequinTrace(), improper parameters");
			return;
		}
		Log("hit the dummy at " + FString::FromInt(GetEnum(Enum'Core.Object.EBoneRegion',HitBone.BoneRegion)));
		switch(HitBone.BoneRegion)
		{
			case 1:
			if (bSearchForInjury)
			{
				bHeadChecked=true;
				DeactivateHelpMarker(HelpMarker);
				CheckedIfHurt();
			}
			break;
			case 2:
			case 3:
			if (bSearchForInjury)
			{
				bChestChecked=true;
				DeactivateHelpMarker(ExtraHelpMarker1);
				CheckedIfHurt();
			}
			break;
			case 4:
			case 5:
			break;
			case 10:
			case 11:
			case 6:
			case 7:
			if (bSearchForInjury)
			{
				bLegsChecked=true;
				DeactivateHelpMarker(ExtraHelpMarker2);
				DeactivateHelpMarker(ExtraHelpMarker3);
				CheckedIfHurt();
			}
			break;
			case 8:
			case 9:
			break;
			case 0:
			break;
			default:
		}
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
	}
	simulated Function CheckedIfHurt()
	{
		if ((bHeadChecked && bChestChecked) && bLegsChecked)
		{
			PlayTip("You found the wound.","",6);
			DeactivateHelpMarker(HelpMarker);
			DeactivateHelpMarker(ExtraHelpMarker1);
			DeactivateHelpMarker(ExtraHelpMarker2);
			DeactivateHelpMarker(ExtraHelpMarker3);
			StopHelpTimer();
			bSearchForInjury=false;
			PlayLSAnim("fa_station1_9",DrillSergeant);
		}
	}
	simulated Function StationComplete()
	{
		PlayTip("Station 1 - Evaluate a Casualty Completed","",4);
		FAMasterScript.DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station1_EndBlock"));
		LogStationEnd(this,true);
		bStationComplete=true;
		StationObjective.SetDisabled(true);
		SetHelpMarker(DirectionMarker,GetActorByTag("ToStation2")->GetActorLocation(),HelpMarkerLargeOffset,true);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("ToStation2").Rotation);
		PlayerLock(false,false);
		ForcePlayerCrouch(false);
		Cast<ADSController>(DrillSergeant.Controller).WaitForTimer(10);
		Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station_1_Instruction_1");
		Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station_1_Block_Return");
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(string(this) + " Timer_LSAnim called for " + FString::FromInt(LSName));
		switch(LSName)
		{
			case "fa_station1_1":
			PlayLSAnim("fa_station1_3",DrillSergeant);
			return true;
			case "fa_station1_2":
			return true;
			case "fa_station1_3":
			PlayTip("Check the mannequin over","from the head to his feet.",8);
			SetHelpMarker(HelpMarker,Mannequin.GetBoneCoords("head").Origin,HelpMarkerSmallOffset,true);
			SetHelpMarker(ExtraHelpMarker1,Mannequin.GetBoneCoords("Spine02").Origin,HelpMarkerSmallOffset,true);
			SetHelpMarker(ExtraHelpMarker2,Mannequin.GetBoneCoords("RLegLow").Origin,HelpMarkerSmallOffset,true);
			SetHelpMarker(ExtraHelpMarker3,Mannequin.GetBoneCoords("LLegLow").Origin,HelpMarkerSmallOffset,true);
			StartHelpTimer(0,true);
			bSearchForInjury=true;
			return true;
			case "fa_station1_4":
			return true;
			case "fa_station1_5":
			return true;
			case "fa_station1_6":
			return true;
			case "fa_station1_7":
			return true;
			case "fa_station1_8":
			return true;
			case "fa_station1_9":
			StationComplete();
			return true;
			case "fa_station1_10":
			return true;
			case "fa_station1_11":
			return true;
			default:
			return false;
		}
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		HandleHelpTimerEvent(TimerName);
		return true;
	}
	simulated Function EndState()
	{
		DeactivateHelpMarker(HelpMarker);
		DeactivateHelpMarker(DirectionMarker);
		DeactivateLocationMarker(LocationMarker);
		DeactivateHelpMarker(ExtraHelpMarker1);
		DeactivateHelpMarker(ExtraHelpMarker2);
		SetPlayerWeapon(true,false);
		ForceDrawPlayerCrosshair(false);
		Log("Ending ActiveExecute state for " + FString::FromInt(this));
	}
}
*/

void AFA_EL_CasualtyEvaluation::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
	CreateMarkers();
}

void AFA_EL_CasualtyEvaluation::PostPostInit()
{
	Super::PostPostInit();
	//SetHelpMarker(HelpMarker, DrillSergeant->GetActorLocation(), HelpMarkerLargeOffset, true, true);
}

void AFA_EL_CasualtyEvaluation::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor->IsA(AFA_NPC_CasualtyEvalMannequin::StaticClass()))
		{
			Mannequin = FA_NPC_CasualtyEvalMannequin(SearchActor);
		}
	}
	*/
	Super::DoReferenceLinking();
}

void AFA_EL_CasualtyEvaluation::CreateMarkers()
{
	Super::CreateMarkers();
	/*
	ExtraHelpMarker1 = Spawn(AFSTS_HelpMarker::StaticClass(), this);
	DeactivateHelpMarker(ExtraHelpMarker1);
	ExtraHelpMarker2 = Spawn(AFSTS_HelpMarker::StaticClass(), this);
	DeactivateHelpMarker(ExtraHelpMarker2);
	ExtraHelpMarker3 = Spawn(AFSTS_HelpMarker::StaticClass(), this);
	DeactivateHelpMarker(ExtraHelpMarker3);
	*/
}

void AFA_EL_CasualtyEvaluation::AssignDrillSergeants(AFSTS_NPC_DrillSergeant* Sergeant)
{
	DS_Moore = Cast<AFA_NPC_DS_Moore>(Sergeant);
	//SetHelpLSActor(DS_Moore);
	//Sergeant->EventLab = this;
	SetDrillSergeantParams(true, true, true);
}

void AFA_EL_CasualtyEvaluation::Reset()
{
	SetDrillSergeantParams(true, true, true);
	bSearchForInjury = false;
	bHeadChecked = false;
	bChestChecked = false;
	bLegsChecked = false;
	StopHelpTimer(0);
	SetHelpMarker(HelpMarker, DrillSergeant->GetActorLocation(), HelpMarkerLargeOffset, true, true);
	DeactivateHelpMarker(ExtraHelpMarker1);
	DeactivateHelpMarker(ExtraHelpMarker2);
	DeactivateHelpMarker(ExtraHelpMarker3);
	//StationObjective->SetDisabled(false);
	//Player.SetLocation(GetActorByTag("Station1_Start").Location);
	//Controller.SetRotation(GetActorByTag("Station1_Start").Rotation);
	Super::Reset();
}

void AFA_EL_CasualtyEvaluation::Destroyed()
{
	Mannequin = nullptr;
	if (ExtraHelpMarker1 != nullptr)
	{
		ExtraHelpMarker1->Destroy();
	}
	if (ExtraHelpMarker2 != nullptr)
	{
		ExtraHelpMarker2->Destroy();
	}
	if (ExtraHelpMarker3 != nullptr)
	{
		ExtraHelpMarker3->Destroy();
	}
	Super::Destroyed();
}

void AFA_EL_CasualtyEvaluation::FFDrillSergeantScold()
{
	//DrillSergeant->StopLIPSincAnim();
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	PlayLSAnim("fa_station1_13", DrillSergeant,0,0,0,0);
	PlayTip("Watch your aim soldier!", "", 4);
	ForceLevelReset();
}

void AFA_EL_CasualtyEvaluation::DrillSergeantMoveOn(AFSTS_NPC_DrillSergeant* Sergeant)
{
	if (FMath::Rand() % 2 == 0)
	{
		PlayLSAnim("fa_station1_14", Sergeant,0,0,0,0);
	}
	else
	{
		PlayLSAnim("fa_station1_17", Sergeant,0,0,0,0);
	}
}

void AFA_EL_CasualtyEvaluation::CheckedIfHurt()
{
}
