// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_M249RangeStation/WF_EL_M249RangeStation.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/PickupW_FSTS_Trainer_M249_SAW/PickupW_FSTS_Trainer_M249_SAW.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/Brush/Volume/BlockingVolume/FSTS_Shot_Detection_Volume/FSTS_Shot_Detection_Volume.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_MasterScript.h"

AWF_EL_M249RangeStation::AWF_EL_M249RangeStation()
{
	OutsideShotLimit = 20;
	iMinimumTargets = 10;
	iMaximumTargets = 15;
	iTallyTargets = 6;
	WeaponName = "M249 SAW";
	StationMsg = "Station ";
	MoveMsg = "Proceed to the next station.";
	StandardsMsg = "You must hit atleast %MINIMUM% of %MAXIMUM% targets.";
	StationInstructionMsg = "Fire from the standing or crouched postions.";
	PracticeMsg = "Practice Beginning!";
	PracticeCountdownMsg = "Practice will begin in %SECONDS% seconds.";
	QualificationMsg = "Begin Qualification.";
	QualificationCountdownMsg = "Qualification will begin in %SECONDS% seconds.";
	WeaponPickupMsg = "Pick up the M249 rifle from the table";
	WeaponReloadMsg = "Reload your weapon and fire to qualify.";
	NumRoundsMsg = "You have %NUMROUNDS% rounds.";
	SuccessMsg = "Congratulations on qualifying with the M249 Rifle.";
	FailureMsg = "You failed to qualify with the M249 Rifle.";
	QualificationSuccessMsg = "You qualified using only %ROUNDS% rounds.";
	QualificationFailureMsg = "You have failed to qualify.";
	StationFailureMsg = "Station 2 Failed!";
	CompleteMsg = "Station complete.";
	IncompleteMsg = "Station Incomplete!";
	DoneMsg = "You are done.";
	OutsideLaneMsg = "You have shot outside the station lane!";
	HitMsg = "You hit %HITCOUNT% targets using %NUMROUNDS% rounds.";
	ShotsFiredMsg = "%SHOTSFIRED% shots went outside your lane.";
	ResultMsg = "%STATIONSCORE% of %TOTALSCORE% targets hit.";
	ProneMsg = "Press <Crawling> to go prone.";
	ReloadMsg = "Press the <Reload> key to load the %NUMROUNDS% ammo belt.";
	SupportedMsg = "Press the <SupportedFire> key while prone to deploy the bipod.";
	StationTargetManagerTag = "S2RangeTargetManager";
	DrillSergeantTag = "NPC_DS_Lang";
	StationObjectiveTag = "Station2Objective";
	StationBeginPointTag = "Station2_Start";
	bStartFromDrillSergeantUse = true;
	bFadeMoveFromDrillSergeantUse = true;
	StationName = "M249 Squad Automatic Weapon";
	HelpInfoList = {
		FHelpInfo({"PickupSAW",8,"Pick up the M249 from the table.","","wf_station2_8",nullptr}),
		FHelpInfo({ "DoFirstReload",8,"Press the <reload> key to load the 100 rd. ammo belt.","Press the <SupportedFire> key while prone to deploy the bipod","wf_station2_8",nullptr }),
		FHelpInfo({ "Finish100RdBelt",30,"You must fire the full 100 rd. load before qualifying","","wf_station2_8",nullptr }),
		FHelpInfo({ "ReloadForQual",8,"Press <reload> to load the 50 rd. ammo belt","","wf_station2_8",nullptr })
	};
	bDormant = true;
	bMasterScript = false;
	LSAnims = {
		FLSAnim({ "wf_station2_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_1_Cue.wf_station2_1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_2_Cue.wf_station2_2_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_3_Cue.wf_station2_3_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_4_Cue.wf_station2_4_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_5_Cue.wf_station2_5_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_6",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_6_Cue.wf_station2_6_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_7",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_7_Cue.wf_station2_7_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_8",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_8_Cue.wf_station2_8_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_Station2_9",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_Station2_9_Cue.wf_Station2_9_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_10",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_10_Cue.wf_station2_10_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_11",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_11_Cue.wf_station2_11_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_12",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_12_Cue.wf_station2_12_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} })
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
		Cast<AHumanController>(Player.Controller).Player.Console.ClearMessages();
		if (bRepeatingStation)
		{
			if (Cast<AAGP_Pawn>(Controller.Pawn).Weapon != nullptr)
			{
				if ((Player.Weapon != nullptr) && Player.Weapon.IsZoomed())
				{
					Player.Weapon.ForceUnzoom(true);
				}
				Player.SetSupported(false,true);
				ForcePlayerCrouch(false);
				Cast<AAGP_Pawn>(Controller.Pawn).SwapHands();
			}
		}
		bQualification=false;
		Log("Beginning ActiveExecute state for " + FString::FromInt(this),"M249_Range");
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
	Function ELPlayerPressedActionKey()
	{
		if (! bWFM249IntroHeard)
		{
			return;
		}
		Log("FSTS in state " + FString::FromInt(GetStateName()) + " and DrillSergeant is animating: " + FString::FromInt(DrillSergeant.IsPlayingLIPSincAnim()));
		if (DrillSergeant.IsPlayingLIPSincAnim())
		{
			if ((DrillSergeant.CurrentLIPSincAnim() ~= "wf_station2_1") || (DrillSergeant.CurrentLIPSincAnim() ~= "wf_station2_4"))
			{
				bPlayerSkippingIntro=true;
				Log("Shutting down welcome speech animation");
				SetTimerEvent(string(DrillSergeant.CurrentLIPSincAnim()),0.1,3,false);
				DrillSergeant->StopLIPSincAnim();
			}
		}
	}
	simulated Function NotifyFadeMoveStart(FName PlayerMoveName)
	{
		if (PlayerMoveName == "Station2_Start")
		{
			PlayerLock(true,false);
			SetDrillSergeantParams(false,false,false);
			DeactivateHelpMarker(HelpMarker);
		}
		else
		{
			if (PlayerMoveName == "Station2_M249")
			{
				PlayerLock(true,false);
			}
		}
	}
	simulated Function NotifyFadeMoveEnd(FName PlayerMoveName)
	{
		if (PlayerMoveName == "Station2_Start")
		{
			PlayerLock(true,false);
			if (bWFM249IntroHeard)
			{
				PlayTip(StationMsg + "2 " + StationName,"You can skip this introduction by pressing your <action> key.",6);
			}
			else
			{
				PlayTip(StationMsg + "2",StationName,6);
			}
			PlayLSAnim("wf_station2_1",DrillSergeant);
		}
		else
		{
			if (PlayerMoveName == "Station2_M249")
			{
				PlayLSAnim("wf_station2_4",DrillSergeant);
				PlayTip(ProneMsg,SupportedMsg,8);
				PlayerLock(true,false);
			}
		}
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		HandleHelpTimerEvent(TimerName);
		switch(TimerName)
		{
			case "BeginQualification":
			Cast<AHumanController>(Player.Controller).Player.Console.ClearMessages();
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
		int32 iNumRounds = 0;
		FString sTempMsg = "";
		Log(" Timer_LSAnim called for " + FString::FromInt(LSName),"M249_Range");
		switch(LSName)
		{
			case "wf_station2_1":
			if (bFailedStation)
			{
				PlayerLock(false,false);
				FadeMoveStart(GetActorByTag("Station2_M249"),Self);
				break;
			}
			if (bPlayerSkippingIntro)
			{
				Timer_LSAnim("wf_station2_3");
				break;
			}
			PlayLSAnim("wf_station2_3",DrillSergeant);
		}
		GOTO JL03B9;
		case "wf_station2_3":
		bWFM249IntroHeard=true;
		SaveConfig();
		PlayTip(WeaponPickupMsg,"",6);
		StartHelpTimer(0,true);
		SAWPickup.SetAllowPickup(true);
		PlayerLock(false,false);
		GOTO JL03B9;
		case "wf_station2_4":
		iNumRounds=100;
		sTempMsg=Repl(ReloadMsg,"%NUMROUNDS%",string(100) + "-round");
		PlayTip(sTempMsg,"",8);
		Player.CreateInventoryFromName("AGP_Inventory.Ammo_556mm_100_Belt");
		Cast<AAGP_Weapon>(Player.Weapon).RecountAmmo();
		if (bFailedStation)
		{
			if (Cast<AAGP_Pawn>(Controller.Pawn).Weapon == nullptr)
			{
				Cast<AAGP_Pawn>(Controller.Pawn).SwapHands();
			}
			if (Player.Weapon.AmmoType != nullptr)
			{
				Player.Weapon.AmmoType.AmmoAmount=0;
			}
			Cast<AAGP_Weapon>(Player.Weapon).RecountAmmo();
			TargetManagerResetScores(StationTargetManager);
			TargetManagerPracticeMode(StationTargetManager,true);
			TargetManagerActive(StationTargetManager,true);
		}
		else
		{
			StartHelpTimer(1,true);
		}
		GOTO JL03B9;
		case "wf_station2_5":
		PlayTip("You can tap the <Fire> button to fire in bursts.","This conserves ammunition and makes aiming much easier.",7);
		GOTO JL03B9;
		case "wf_station2_6":
		bQualification=true;
		iNumRounds=50;
		sTempMsg=Repl(ReloadMsg,"%NUMROUNDS%",string(50) + "-round");
		PlayTip(sTempMsg,"",8);
		StartHelpTimer(3,true);
		Player.CreateInventoryFromName("AGP_Inventory.Ammo_556mm_50_Belt");
		Cast<AAGP_Weapon>(Player.Weapon).RecountAmmo();
		GOTO JL03B9;
		case "wf_station2_7":
		StationComplete();
		GOTO JL03B9;
		case "wf_station2_8":
		GOTO JL03B9;
		case "wf_station2_10":
		bFailedStation=true;
		StationComplete();
		GOTO JL03B9;
		case "wf_station2_12":
		StationComplete();
		GOTO JL03B9;
		default:
		GOTO JL03B9;
JL03B9:
		return true;
	}
	simulated Function StationComplete()
	{
		if (! bFailedStation)
		{
			PlayTip(MoveMsg,"",5);
			PlayerLock(false,false);
			StationObjective.SetDisabled(true);
			bStationComplete=true;
			MasterScript.SetActiveScript(Cast<AWF_EL_MasterScript>(MasterScript).Station3);
		}
		else
		{
			if (Player.Weapon.IsZoomed())
			{
				Player.Weapon.ForceUnzoom(true);
			}
			Player.SetSupported(false,true);
			ForcePlayerCrouch(false);
			PlayTip("Try this training again.","",4);
			SetupTraining(true);
		}
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if (AlertTag == "Station2_M249")
		{
			DeactivateHelpMarker(HelpMarker);
		}
	}
	simulated Function ReloadEvent(AWeapon* ReloadedWeapon)
	{
		Log("StationTargetManager is " + FString::FromInt(StationTargetManager),"M249_Range");
		if ((! StationTargetManager.bActive) && (! bDidFirstReload))
		{
			StopHelpTimer();
			SetTargetManagerScoreKeeper(StationTargetManager);
			TargetManagerPracticeMode(StationTargetManager,true);
			TargetManagerActive(StationTargetManager,true);
			PlayLSAnim("wf_station2_5",DrillSergeant);
			bDidFirstReload=true;
		}
		else
		{
			if (bQualification)
			{
				GotoState("ActiveExecute","CountDown");
				TargetManagerActive(StationTargetManager,false);
				StopHelpTimer();
			}
		}
	}
	Function bool AGP_Weapon_Empty(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (! NotifyActor.HasAmmo())
		{
			if (! bQualification)
			{
				TargetManagerActive(StationTargetManager,false);
				PlayLSAnim("wf_station2_6",DrillSergeant);
			}
			else
			{
				if (Player.Weapon.IsZoomed())
				{
					Player.Weapon.ForceUnzoom(true);
				}
				Player.SetSupported(false,true);
				ForcePlayerCrouch(false);
				SetCustomTimer(0.5,false,"EndTMDispatching");
			}
		}
		return true;
	}
	simulated Function EndTMDispatching()
	{
		StationTargetManager.EndDispatch();
	}
	simulated Function bool Pickup_PickedUp(APickup* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (NotifyActor == SAWPickup)
		{
			StopHelpTimer();
			SAWPickup.SetAllowPickup(false);
			FadeMoveStart(GetActorByTag("Station2_M249"),Self);
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
		TotalScore=18;
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
		PlayLSAnim("wf_station2_7",DrillSergeant);
	}
	simulated Function AwardPlayerFailure(FString ResultString)
	{
		bFailedStation=true;
		LogStationEnd(this,false);
		PlayTip(FailureMsg,ResultString,6);
		PlayLSAnim("wf_station2_12",DrillSergeant);
	}
	simulated Function bool AGP_Weapon_Fire(AAGP_Weapon* Weapon, AActor* Instigator, FString Parms)
	{
		return true;
	}
	simulated Function bool Actor_Custom(AActor* NotifyActor, Actor.EEventType Event, AActor* Instigator, FString Parms)
	{
		if (Parms == "Lane_01_Complete")
		{
			Log("EventLab got counter complete event","M249_Range");
			if (bQualification)
			{
			}
			Log("Station1 Got lane complete but not while qualifying","M249_Range");
			return true;
		}
		if ((Cast<AFSTS_Shot_Detection_Volume>(Instigator) != nullptr) || (Parms == "Shot_Out_Of_Lane"))
		{
			OutsideShotCounter ++;
			if ((! bNoGoRestart) && (OutsideShotCounter > OutsideShotLimit))
			{
				bNoGoRestart=true;
				bQualification=false;
				TargetManagerActive(StationTargetManager,false);
				PlayLSAnim("wf_station2_10",DrillSergeant);
				PlayTip(OutsideLaneMsg,"",5);
			}
			return true;
		}
		if (NotifyActor.Tag == "Trigger")
		{
			HitCount ++;
			return true;
		}
		return false;
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this),"M249_Range");
		PlayerLock(false,false);
		StopHelpTimer();
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

void AWF_EL_M249RangeStation::PostPostInit()
{
	Super::PostPostInit();
}

void AWF_EL_M249RangeStation::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "PickupW_FSTS_Trainer_M249_SAW")
		{
			SAWPickup = Cast<APickupW_FSTS_Trainer_M249_SAW>(SearchActor);
			SAWPickup.EventLab = this;
			SAWPickup.SetAllowPickup(false);
		}
	}
	Super::DoReferenceLinking();
	*/
}

void AWF_EL_M249RangeStation::Reset()
{
	/*
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	DrillSergeant->StopLIPSincAnim();
	TargetManagerActive(StationTargetManager, false);
	TargetManagerResetScores(StationTargetManager);
	Player.EmptyInventory();
	SAWPickup.GotoState("Pickup");
	SAWPickup.SetAllowPickup(false);
	SetHelpMarker(HelpMarker, DrillSergeant->GetActorLocation(), HelpMarkerLargeOffset, true, true);
	Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
	SetDrillSergeantParams(true, true, true);
	bQualification = false;
	bDidFirstReload = false;
	StationObjective.SetDisabled(false);
	HitCount = 0;
	OutsideShotCounter = 0;
	Player.SetLocation(GetActorByTag("Station2_Start").Location);
	Controller.SetRotation(GetActorByTag("Station2_Start").Rotation);
	Super::Reset();
	*/
}
