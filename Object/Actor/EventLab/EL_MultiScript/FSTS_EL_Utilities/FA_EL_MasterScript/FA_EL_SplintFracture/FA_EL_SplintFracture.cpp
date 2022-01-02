// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_SplintFracture/FA_EL_SplintFracture.h"

AFA_EL_SplintFracture::AFA_EL_SplintFracture()
{
	DrillSergeantTag = "FA_NPC_DS_Mateo";
	StationObjectiveTag = "Station4Objective";
	StationBeginPointTag = "Station_4_Stand_Point";
	bAcceptDrillSergeantUse = true;
	bStartFromDrillSergeantUse = true;
	bFadeMoveFromDrillSergeantUse = true;
	StationName = "Splint a Fracture";
	HelpInfoList = {
		FHelpInfo({ "PickupCravats",30,"Press the <Action> key on the cravat ties to pick them up.","Press the <Action> key on the leg to apply the cravats.","fa_station3_13",nullptr }),
		FHelpInfo({ "PickupSplintBoards",30,"Press the <Action> key on the splint boards to pick them up.","Press the <Action> key on the leg to apply the splint boards.","fa_station3_14",nullptr }),
		FHelpInfo({ "PickupCravatPads",30,"Press the <Action> key on the padding to pick it up.","Press the <Action> key on the leg to put the padding in place.","fa_station3_13",nullptr }),
		FHelpInfo({ "TieCravats",30,"Press the <Action> key on the mannequin's","left leg to tie the cravats.","fa_station3_14",nullptr })
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
		Log("Beginning ActiveExecute state for " $ string(Self));
		ActivatePlayerBlocking(GetPlayerBlockingVolume("Station4_StartBlock"));
		ActivatePlayerBlocking(GetPlayerBlockingVolume("Station4_EndBlock"));
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
		PlayTip("Station 4 - Splint a Fracture","",5);
		PlayLSAnim("fa_station3_1",DrillSergeant,,,,1.5);
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(string(Self) $ " Timer_LSAnim called for " $ string(LSName));
		switch(LSName)
		{
			case "fa_station3_1":
			PlayLSAnim("fa_station3_2",DrillSergeant);
			return true;
			case "fa_station3_2":
			PlayTip("Press the <Action> key on the cravat ties to pick them up.","Press the <Action> key on the leg to apply the cravats.",8);
			StartHelpTimer(0,true);
			CravatState=1;
			RolledCravatPickup.bUseActionIcon=true;
			SetHelpMarker(HelpMarker,RolledCravatPickup.Location,HelpMarkerSmallOffset,true);
			return true;
			case "fa_station3_3":
			return true;
			case "fa_station3_4":
			return true;
			case "fa_station3_5":
			return true;
			case "fa_station3_6":
			return true;
			case "fa_station3_7":
			PlayTip("Press the <Action> key on the splint boards to pick them up.","Press the <Action> key on the leg to apply the splint boards.",8);
			StartHelpTimer(1,true);
			SplintState=1;
			SplintPickup.bUseActionIcon=true;
			SetHelpMarker(HelpMarker,SplintPickup.Location,HelpMarkerSmallOffset,true);
			return true;
			case "fa_station3_8":
			PlayTip("Press the <Action> key on the padding to pick it up.","Press the <Action> key on the leg to put the padding in place.",8);
			StartHelpTimer(2,true);
			CravatPadState=1;
			CravatPadPickup.bUseActionIcon=true;
			SetHelpMarker(HelpMarker,CravatPadPickup.Location,HelpMarkerSmallOffset,true);
			return true;
			case "fa_station3_9":
			bTieCravats=true;
			PlayTip("Press the <Action> key on the mannequin's","left leg to tie the cravats.",4);
			StartHelpTimer(3,true);
			SetHelpMarker(HelpMarker,Mannequin.GetBoneCoords("LLegLow").Origin,HelpMarkerSmallOffset,true);
			return true;
			case "fa_station3_10":
			StationCompleted();
			return true;
			case "fa_station3_11":
			return true;
			case "fa_station3_12":
			return true;
			default:
			return false;
		}
	}
	simulated Function StationCompleted()
	{
		PlayTip("Station 4 - Splint a Fracture Completed","",5);
		FAMasterScript.DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station4_EndBlock"));
		LogStationEnd(Self,true);
		bStationComplete=true;
		StationObjective.SetDisabled(true);
		SetHelpMarker(DirectionMarker,GetActorByTag("ToStation5").Location,HelpMarkerLargeOffset,true,true);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("ToStation5").Rotation);
		PlayerLock(false,false);
		ForcePlayerCrouch(false);
		DSController(DrillSergeant.Controller).WaitForTimer(10);
		DSController(DrillSergeant.Controller).MoveToPoint("Station_3_Instruction_1");
		DSController(DrillSergeant.Controller).MoveToPoint("Station_3_Block_Return");
		DSController(DrillSergeant.Controller).TurnTowardPlayer();
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
	}
	simulated Function MannequinTrace(AActor* HitActor, Actor.BoneInfo HitBone)
	{
		if (((HitActor == nullptr) || (! HitActor.IsA("FA_NPC_SplintFractureMannequin"))) || (HitBone.HitBone == 0))
		{
			Log("Unable to run MannequinTrace(), improper parameters");
			return;
		}
		switch(HitBone.BoneRegion)
		{
			case 1:
			break;
			case 2:
			case 3:
			break;
			case 4:
			case 5:
			break;
			case 6:
			case 7:
			if (bTieCravats)
			{
				StopHelpTimer();
				bTieCravats=false;
				CravatAttachment.SwitchToAltStaticMesh();
				DeactivateHelpMarker(HelpMarker);
				PlayLSAnim("fa_station3_10",DrillSergeant);
				return;
			}
			if (CravatState == 2)
			{
				StopHelpTimer();
				CravatState=3;
				CravatAttachment=Spawn(class'FSTS.FA_CravatAttachment',Self);
				if (CravatAttachment != nullptr)
				{
					HitActor.AttachToBone(CravatAttachment,"LLegLow");
					CravatAttachment.SetRotation(HitActor.Rotation);
				}
				DeactivateHelpMarker(HelpMarker);
				PlayLSAnim("fa_station3_7",DrillSergeant);
			}
			if (SplintState == 2)
			{
				StopHelpTimer();
				SplintState=3;
				SplintAttachment=Spawn(class'FSTS.FA_SplintAttachment',Self);
				if (SplintAttachment != nullptr)
				{
					HitActor.AttachToBone(SplintAttachment,"LLegLow");
					SplintAttachment.SetRotation(HitActor.Rotation);
				}
				DeactivateHelpMarker(HelpMarker);
				PlayLSAnim("fa_station3_8",DrillSergeant);
			}
			if (CravatPadState == 2)
			{
				StopHelpTimer();
				CravatPadState=3;
				CravatPadAttachment=Spawn(class'FSTS.FA_CravatPadAttachment',Self);
				if (CravatPadAttachment != nullptr)
				{
					HitActor.AttachToBone(CravatPadAttachment,"LLegLow");
					CravatPadAttachment.SetRotation(HitActor.Rotation);
				}
				DeactivateHelpMarker(HelpMarker);
				PlayLSAnim("fa_station3_9",DrillSergeant);
			}
			break;
			case 8:
			case 9:
			break;
			case 10:
			case 11:
			break;
			case 0:
			break;
			default:
		}
	}
	simulated Function HandleMedPickup(AActor* HitActor)
	{
		if ((HitActor == RolledCravatPickup) && (CravatState == 1))
		{
			CravatState=2;
			RolledCravatPickup.DisablePickup();
			SetHelpMarker(HelpMarker,Mannequin.GetBoneCoords("LLegLow").Origin,HelpMarkerSmallOffset);
		}
		if ((HitActor == CravatPadPickup) && (CravatPadState == 1))
		{
			CravatPadState=2;
			CravatPadPickup.DisablePickup();
			SetHelpMarker(HelpMarker,Mannequin.GetBoneCoords("LLegLow").Origin,HelpMarkerSmallOffset);
		}
		if ((HitActor == SplintPickup) && (SplintState == 1))
		{
			SplintState=2;
			SplintPickup.DisablePickup();
			SetHelpMarker(HelpMarker,Mannequin.GetBoneCoords("LLegLow").Origin,HelpMarkerSmallOffset);
		}
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		HandleHelpTimerEvent(TimerName);
		return false;
	}
	simulated Function EndState()
	{
		SetPlayerWeapon(true,false);
		DeactivateHelpMarker(HelpMarker);
		DeactivateHelpMarker(DirectionMarker);
		DeactivateLocationMarker(LocationMarker);
		ForceDrawPlayerCrosshair(false);
		Log("Ending ActiveExecute state for " $ string(Self));
	}
}
*/

void AFA_EL_SplintFracture::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
}

void AFA_EL_SplintFracture::PostPostInit()
{
	Super::PostPostInit();
	//SetHelpMarker(HelpMarker, DrillSergeant.Location, HelpMarkerLargeOffset, true, true);
}

void AFA_EL_SplintFracture::DoReferenceLinking()
{
	/*
	local Actor SearchActor;
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "FA_CravatPadPickup")
		{
			CravatPadPickup = FA_CravatPadPickup(SearchActor);
		}
		if (SearchActor.Tag == "FA_RolledCravatPickup")
		{
			RolledCravatPickup = FA_RolledCravatPickup(SearchActor);
		}
		if (SearchActor.Tag == "FA_SplintPickup")
		{
			SplintPickup = FA_SplintPickup(SearchActor);
		}
		if (SearchActor.Tag == "FA_NPC_SplintFractureMannequin")
		{
			Mannequin = FA_NPC_SplintFractureMannequin(SearchActor);
		}
	}
	*/
	Super::DoReferenceLinking();
}

void AFA_EL_SplintFracture::AssignDrillSergeants(AFSTS_NPC_DrillSergeant* Sergeant)
{
	/*
	DS_Mateo = FA_NPC_DS_Mateo(Sergeant);
	SetHelpLSActor(DS_Mateo);
	Sergeant.EventLab = Self;
	SetDrillSergeantParams(true, true, true);
	*/
}

void AFA_EL_SplintFracture::Reset()
{
	/*
	SetDrillSergeantParams(true, true, true);
	bTieCravats = false;
	StationObjective.SetDisabled(false);
	StopHelpTimer();
	DrillSergeant.StopLIPSincAnim();
	CravatState = 0;
	CravatPadState = 0;
	SplintState = 0;
	CravatPadPickup.ActivatePickup();
	RolledCravatPickup.ActivatePickup();
	SplintPickup.ActivatePickup();
	if (CravatAttachment != None)
	{
		CravatAttachment.Destroy();
	}
	if (CravatPadAttachment != None)
	{
		CravatPadAttachment.Destroy();
	}
	if (SplintAttachment != None)
	{
		SplintAttachment.Destroy();
	}
	Player.SetLocation(GetActorByTag("Station3_Start").Location);
	Controller.SetRotation(GetActorByTag("Station3_Start").Rotation);
	SetHelpMarker(HelpMarker, DrillSergeant.Location, HelpMarkerLargeOffset, true, true);
	*/
	Super::Reset();
}

void AFA_EL_SplintFracture::Destroyed()
{
	CravatPadPickup = nullptr;
	RolledCravatPickup = nullptr;
	SplintPickup = nullptr;
	Mannequin = nullptr;
	//CravatAttachment.Destroy();
	//CravatPadAttachment.Destroy();
	//SplintAttachment.Destroy();
	Super::Destroyed();
}

void AFA_EL_SplintFracture::FFDrillSergeantScold()
{
	/*
	DrillSergeant->StopLIPSincAnim();
	StopTimerByType(3);
	StopTimerByType(0);
	PlayLSAnim("fa_station3_15", DrillSergeant);
	PlayTip("Watch your aim soldier!", "", 4);
	ForceLevelReset();
	*/
}

void AFA_EL_SplintFracture::DrillSergeantMoveOn(AFSTS_NPC_DrillSergeant* Sergeant)
{
	/*
	if (Rand(2) == 0)
	{
		PlayLSAnim("fa_station3_12", Sergeant);
	}
	else
	{
		PlayLSAnim("fa_station3_18", Sergeant);
	}
	*/
}
