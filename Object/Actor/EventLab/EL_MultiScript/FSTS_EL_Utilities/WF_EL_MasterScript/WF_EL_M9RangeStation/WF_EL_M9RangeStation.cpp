// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_M9RangeStation/WF_EL_M9RangeStation.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/FSTS_WeaponPickup.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/Brush/Volume/BlockingVolume/FSTS_Shot_Detection_Volume/FSTS_Shot_Detection_Volume.h"

AWF_EL_M9RangeStation::AWF_EL_M9RangeStation()
{
	OutsideShotLimit = 5;
	iMinimumTargets = 10;
	iMaximumTargets = 15;
	iTallyTargets = 10;
	WeaponName = "M9 Pistol";
	StationMsg = "Station ";
	MoveMsg = "Proceed to the next station.";
	StandardsMsg = "You must hit at least %MINIMUM% of %MAXIMUM% targets.";
	StationInstructionMsg = "Fire from the standing or crouched postions.";
	PracticeMsg = "Practice Beginning!";
	PracticeCountdownMsg = "Practice will begin in 10 seconds.";
	QualificationMsg = "Begin Qualification.";
	QualificationCountdownMsg = "Qualification will begin in %SECONDS% seconds.";
	WeaponPickupMsg = "Pick up the M9 pistol from the table";
	WeaponReloadMsg = "Reload your weapon and fire to qualify.";
	NumRoundsMsg = "You have %NUMROUNDS% rounds.";
	SuccessMsg = "Congratulations on qualifying with the M9 Pistol.";
	FailureMsg = "You failed to qualify with the M9 Pistol.";
	QualificationSuccessMsg = "You qualified using only %ROUNDS% rounds.";
	QualificationFailureMsg = "You have failed to qualify.";
	StationFailureMsg = "Station 1 Failed!";
	CompleteMsg = "Station complete.";
	IncompleteMsg = "Station Incomplete!";
	DoneMsg = "You are done.";
	OutsideLaneMsg = "You have shot outside the station lane!";
	HitMsg = "You hit %HITCOUNT% targets using %NUMROUNDS% rounds.";
	ShotsFiredMsg = "%SHOTSFIRED% shots went outside your lane.";
	ResultMsg = "%STATIONSCORE% of %TOTALSCORE% targets hit.";
	MissionBeginMsg = "Proceed to the first station.";
	CrouchMsg = "Press <Crouching> to crouch.";
	StandMsg = "Press <Crouching> again to stand.";
	ReloadMsg = "Press <Reload> to load a magazine.";
	StationTargetManagerTag = "S1RangeTargetManager";
	DrillSergeantTag = "NPC_DS_Johnson";
	StationObjectiveTag = "Station1Objective";
	StationBeginPointTag = "Station1_Start";
	bAcceptDrillSergeantUse = true;
	bStartFromDrillSergeantUse = true;
	bFadeMoveFromDrillSergeantUse = true;
	StationName = "M9 Pistol";
	HelpInfoList = {
		FHelpInfo({"PickupPistol",6,"Pick up the M9 pistol from the table","","None",nullptr}),
		FHelpInfo({ "PrepareToFire",5,"Use the <Action> key to prepare to fire the weapon","","wf_station5_8",nullptr })
	};
	bDormant = true;
	bMasterScript = false;
	LSAnims = {
		FLSAnim({ "wf_station1_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_1_Cue.wf_station1_1_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station1_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_2_Cue.wf_station1_2_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station1_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_3_Cue.wf_station1_3_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station1_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_4_Cue.wf_station1_4_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station1_5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_5_Cue.wf_station1_5_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station1_6",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_6_Cue.wf_station1_6_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_Station1_7",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_Station1_7_Cue.wf_Station1_7_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station1_8",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_8_Cue.wf_station1_8_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station1_9",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_9_Cue.wf_station1_9_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station1_10",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_10_Cue.wf_station1_10_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station1_11",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_11_Cue.wf_station1_11_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station1_12",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_12_Cue.wf_station1_12_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_Station1_13",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_Station1_13_Cue.wf_Station1_13_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_Station1_14",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_Station1_14_Cue.wf_Station1_14_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station1_15",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station1/wf_station1_15_Cue.wf_station1_15_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} })
	};
	bDoGeneralInit = false;
}

/*
simulated State ActiveExecute
{
	simulated Function BeginState()
	{
		Cast<AHumanController>(Player.Controller).Player.Console.ClearMessages();
		SetupTraining(false);
	}
	Function SetupTraining(bool bRepeatingStation)
	{
		bPlayerSkippingIntro=false;
		if (bRepeatingStation)
		{
			Cast<AAGP_Pawn>(Controller.Pawn).SwapHolster();
		}
		else
		{
			PlayTip(MissionBeginMsg,"",6);
		}
		ForcePlayerCrouch(false);
		WF_PlayerController(Controller).bBlockCrawlingChanges=true;
		PlayerLock(false,false);
		SetHelpMarker(HelpMarker,DrillSergeant->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
		CaptureEventGroup("FSTS_Shot_Detection_Volume");
		CaptureEventGroup("Trigger");
		ReCaptureEvent(Player);
		SetDrillSergeantParams(true,true,true);
		bQualification=false;
		HitCount=0;
	}
	simulated Function NotifyFadeMoveStart(FName PlayerMoveName)
	{
		if (PlayerMoveName == "Station1_Start")
		{
			PlayerLock(true,false);
			SetDrillSergeantParams(false,false,false);
			DeactivateHelpMarker(HelpMarker);
		}
		else
		{
			if (PlayerMoveName == "Station1_M9")
			{
				PlayerLock(true,false);
			}
		}
	}
	simulated Function NotifyFadeMoveEnd(FName PlayerMoveName)
	{
		if (PlayerMoveName == "Station1_Start")
		{
			PlayerLock(true,false);
			if (bWFM9IntroHeard)
			{
				PlayTip(StationMsg + "1 " + StationName,"You can skip this introduction by pressing your <action> key.",6);
			}
			else
			{
				PlayTip(StationMsg + "1",StationName,6);
			}
			PlayLSAnim("wf_station1_1",DrillSergeant);
		}
		else
		{
			if (PlayerMoveName == "Station1_M9")
			{
				PlayLSAnim("wf_station1_3",DrillSergeant);
				PlayTip(StationInstructionMsg,ReloadMsg,6);
				PlayerLock(true,false);
			}
		}
	}
	Function ELPlayerPressedActionKey()
	{
		if (! bWFM9IntroHeard)
		{
			return;
		}
		Log("FSTS in state " + FString::FromInt(GetStateName()) + " and DrillSergeant is animating: " + FString::FromInt(DrillSergeant.IsPlayingLIPSincAnim()));
		if (DrillSergeant.IsPlayingLIPSincAnim())
		{
			if ((DrillSergeant.CurrentLIPSincAnim() ~= "wf_station1_1") || (DrillSergeant.CurrentLIPSincAnim() ~= "wf_station1_2"))
			{
				bPlayerSkippingIntro=true;
				Log("Shutting down welcome speech animation");
				SetTimerEvent(string(DrillSergeant.CurrentLIPSincAnim()),0.1,3,false);
				DrillSergeant->StopLIPSincAnim();
			}
		}
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		HandleHelpTimerEvent(TimerName);
		switch(TimerName)
		{
			case "BeginQualification":
			TargetManagerResetScores(StationTargetManager);
			TargetManagerPracticeMode(StationTargetManager,false);
			TargetManagerActive(StationTargetManager,true);
			PlayTip(QualificationMsg,"",4);
			WFMasterScript.QualificationHUDOverlay.TargetManager=StationTargetManager;
			break;
			case "FadeOutBlack":
			FadeInBlack(2);
			MasterScript.ResetScript(this,true);
			break;
			default:
			break;
		}
		return true;
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(" Timer_LSAnim called for " + FString::FromInt(LSName),"M9_Range");
		switch(LSName)
		{
			case "wf_station1_1":
			if (bFailedStation)
			{
				ForcePlayerCrouch(false);
				PlayerLock(false,false);
				FadeMoveStart(GetActorByTag("Station1_M9"),Self);
				break;
			}
			if (bPlayerSkippingIntro)
			{
				Timer_LSAnim("wf_station1_2");
				break;
			}
			PlayLSAnim("wf_station1_2",DrillSergeant);
		}
		GOTO JL030C;
		case "wf_station1_2":
		PlayTip(WeaponPickupMsg,"",6);
		StartHelpTimer(0,true);
		WeaponPickup.SetAllowPickup(true);
		PlayerLock(false,false);
		bWFM9IntroHeard=true;
		SaveConfig();
		GOTO JL030C;
		case "wf_station1_3":
		PlayTip(CrouchMsg,StandMsg,6);
		if (bFailedStation)
		{
			Cast<AAGP_Pawn>(Controller.Pawn).SwapHolster();
			if (Player.Weapon.AmmoType != nullptr)
			{
				Log("Resetting ammo ammount from " + FString::FromInt(Player.Weapon.AmmoType.AmmoAmount));
				Player.Weapon.AmmoType.AmmoAmount=0;
			}
			Player.CreateInventoryFromName("AGP_Inventory.Ammo_9x19mm_15_Mag");
			Player.CreateInventoryFromName("AGP_Inventory.Ammo_9x19mm_15_Mag");
			Cast<AAGP_Weapon>(Player.Weapon).RecountAmmo();
			TargetManagerResetScores(StationTargetManager);
			TargetManagerPracticeMode(StationTargetManager,true);
			TargetManagerActive(StationTargetManager,true);
		}
		else
		{
			Player.CreateInventoryFromName("AGP_Inventory.Ammo_9x19mm_15_Mag");
			Player.CreateInventoryFromName("AGP_Inventory.Ammo_9x19mm_15_Mag");
			Cast<AAGP_Weapon>(Player.Weapon).RecountAmmo();
		}
		GOTO JL030C;
		case "wf_station1_4":
		GOTO JL030C;
		case "wf_station1_5":
		case "wf_station1_6":
		StationComplete();
		GOTO JL030C;
		case "wf_station1_15":
		if (bNoGoRestart)
		{
			AwardPlayerFailure("");
		}
		GOTO JL030C;
		default:
		GOTO JL030C;
JL030C:
		return true;
	}
	simulated Function ReloadEvent(AWeapon* ReloadedWeapon)
	{
		if ((! StationTargetManager.bActive) && (! bDidFirstReload))
		{
			SetTargetManagerScoreKeeper(StationTargetManager);
			TargetManagerPracticeMode(StationTargetManager,true);
			TargetManagerActive(StationTargetManager,true);
			bDidFirstReload=true;
		}
		else
		{
			if (bQualification)
			{
				GotoState("ActiveExecute","CountDown");
			}
		}
	}
	Function bool AGP_Weapon_Empty(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms)
	{
		FString sTempMsg1 = "";
		FString sTempMsg2 = "";
		if (! NotifyActor.HasAmmo())
		{
			if (! bQualification)
			{
				sTempMsg1=Repl(StandardsMsg,"%MINIMUM%",string(10));
				sTempMsg2=Repl(sTempMsg1,"%MAXIMUM%",string(15));
				PlayTip(ReloadMsg,sTempMsg2,8);
				PlayLSAnim("wf_station1_4",DrillSergeant);
				Player.CreateInventoryFromName("AGP_Inventory.Ammo_9x19mm_15_Mag");
				TargetManagerActive(StationTargetManager,false);
				bQualification=true;
			}
			else
			{
				SetCustomTimer(0.5,false,"EndTMDispatching");
			}
		}
		return true;
	}
	simulated Function EndTMDispatching()
	{
		StationTargetManager.EndDispatch();
		TargetManagerActive(StationTargetManager,false);
	}
	simulated Function bool Pickup_PickedUp(APickup* PickupInQuestion, AActor* Instigator, FString Parms)
	{
		if (PickupInQuestion == WeaponPickup)
		{
			StopHelpTimer();
			WeaponPickup.SetAllowPickup(false);
			FadeMoveStart(GetActorByTag("Station1_M9"),Self);
		}
		return true;
	}
	Function bool TargerManager_DispatchComplete(AGP_Gameplay.TargetManager* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (NotifyActor == StationTargetManager)
		{
			TallyScore();
			return true;
		}
		return false;
	}
	simulated Function TallyScore()
	{
		int32 StationScore = 0;
		int32 TotalScore = 0;
		FString ResultString = "";
		StationScore=GetTargetManagerTotalScore(StationTargetManager);
		TotalScore=15;
		ResultString=string(StationScore) @ "of" @ FString::FromInt(TotalScore) @ "targets hit.";
		if (StationScore >= iTallyTargets)
		{
			AwardPlayerPass(ResultString);
		}
		else
		{
			AwardPlayerFailure(ResultString);
		}
	}
	simulated Function AwardPlayerPass(FString ResultString)
	{
		bFailedStation=false;
		LogStationEnd(this,true);
		PlayTip(SuccessMsg,ResultString,6);
		PlayLSAnim("wf_station1_5",DrillSergeant);
	}
	simulated Function AwardPlayerFailure(FString ResultString)
	{
		bFailedStation=true;
		LogStationEnd(this,false);
		PlayTip(FailureMsg,ResultString,6);
		PlayLSAnim("wf_station1_6",DrillSergeant);
	}
	simulated Function StationComplete()
	{
		PlayerLock(false,false);
		if (! bFailedStation)
		{
			PlayTip(MoveMsg,"",6);
			StationObjective.SetDisabled(true);
			bStationComplete=true;
			WFMasterScript.SetActiveScript(WFMasterScript.Station2);
		}
		else
		{
			PlayTip("Try this training again.","",4);
			SetupTraining(true);
		}
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if (AlertTag == "Station1_M9")
		{
			DeactivateHelpMarker(HelpMarker);
		}
	}
	simulated Function bool AGP_Weapon_Fire(AAGP_Weapon* Weapon, AActor* Instigator, FString Parms)
	{
		return true;
	}
	simulated Function bool Actor_Custom(AActor* NotifyActor, Actor.EEventType Event, AActor* Instigator, FString Parms)
	{
		if ((Cast<AFSTS_Shot_Detection_Volume>(Instigator) != nullptr) || (Parms == "Shot_Out_Of_Lane"))
		{
			OutsideShotCounter ++;
			if ((! bNoGoRestart) && (OutsideShotCounter > OutsideShotLimit))
			{
				bNoGoRestart=true;
				bQualification=false;
				TargetManagerActive(StationTargetManager,false);
				PlayLSAnim("wf_station1_15",DrillSergeant);
				PlayTip(OutsideLaneMsg,"",5);
			}
			return true;
		}
		return false;
	}
	simulated Function EndState()
	{
		WF_PlayerController(Controller).bBlockCrawlingChanges=false;
		ForcePlayerCrouch(false);
		Log("Ending ActiveExecute state for " + FString::FromInt(this),"M9_Range");
		Player.EmptyInventory();
		WFMasterScript.QualificationHUDOverlay.TargetManager=nullptr;
	}
Begin:
	secondsLeft=10;
	countDownMessage=Repl(QualificationCountdownMsg,"%SECONDS%",string(secondsLeft));
	PlayTip(countDownMessage,"",1.5);
	Sleep(1);
	secondsLeft --;
	if (secondsLeft > 0)
	{
		JL"CountDownLoop"
;
	}
	else
	{
		PlayTip("","",0);
		Timer_Timer("BeginQualification");
	}
}
*/

void AWF_EL_M9RangeStation::Reset()
{
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	//DrillSergeant->StopLIPSincAnim();
	TargetManagerActive(StationTargetManager, false);
	TargetManagerResetScores(StationTargetManager);
	Player->EmptyInventory(false);
	//WeaponPickup->GotoState("Pickup");
	WeaponPickup->SetAllowPickup(false);
	SetDrillSergeantParams(true, true, true);
	bQualification = false;
	HitCount = 0;
	OutsideShotCounter = 0;
	bDidFirstReload = false;
	DeactivateHelpMarker(HelpMarker);
	StationObjective->SetDisabled(false);
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	PlayerLock(false, false);
	//Player->SetLocation(GetActorByTag("Station1_Start").Location);
	//Controller->SetRotation(GetActorByTag("Station1_Start").Rotation);
	Super::Reset();
}

void AWF_EL_M9RangeStation::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "PickupW_FSTS_Trainer_M9_Pistol")
		{
			Log(" Linked weapon " + FString::FromInt(SearchActor) + " with tag " + FString::FromInt(SearchActor.Tag), "M9_Range");
			WeaponPickup = Cast<AFSTS_WeaponPickup>(SearchActor);
			WeaponPickup.EventLab = this;
			WeaponPickup.SetAllowPickup(false);
		}
	}
	*/
	Super::DoReferenceLinking();
}
