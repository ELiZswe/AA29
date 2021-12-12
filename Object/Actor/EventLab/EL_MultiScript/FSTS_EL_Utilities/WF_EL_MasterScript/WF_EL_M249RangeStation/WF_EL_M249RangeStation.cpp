// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_M249RangeStation/WF_EL_M249RangeStation.h"

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
		FLSAnim({ "wf_station2_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_1_Que.wf_station2_1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_2_Que.wf_station2_2_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_3_Que.wf_station2_3_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_4_Que.wf_station2_4_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_5_Que.wf_station2_5_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_6",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_6_Que.wf_station2_6_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_7",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_7_Que.wf_station2_7_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_8",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_8_Que.wf_station2_8_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_Station2_9",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_Station2_9_Que.wf_Station2_9_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_10",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_10_Que.wf_station2_10_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_11",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_11_Que.wf_station2_11_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station2_12",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station2/wf_station2_12_Que.wf_station2_12_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} })
	};
	bDoGeneralInit = false;
}

/*
simulated State ActiveExecute
{
	simulated Function BeginState()
	{
		HumanController(Player.Controller).Player.Console.ClearMessages();
		SetupTraining(false);
	}
	Function SetupTraining(bool bRepeatingStation)
	{
		bPlayerSkippingIntro=false;
		HumanController(Player.Controller).Player.Console.ClearMessages();
		if (bRepeatingStation)
		{
			if (AGP_Pawn(Controller.Pawn).Weapon != None)
			{
				if ((Player.Weapon != None) && Player.Weapon.IsZoomed())
				{
					Player.Weapon.ForceUnzoom(true);
				}
				Player.SetSupported(false,true);
				ForcePlayerCrouch(false);
				AGP_Pawn(Controller.Pawn).SwapHands();
			}
		}
		bQualification=false;
		Log("Beginning ActiveExecute state for " $ string(Self),"M249_Range");
		PlayerLock(false,false);
		SetHelpMarker(HelpMarker,DrillSergeant.Location,HelpMarkerLargeOffset,true,true);
		DSController(DrillSergeant.Controller).TurnTowardPlayer();
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
		Log("FSTS in state " $ string(GetStateName()) $ " and DrillSergeant is animating: " $ string(DrillSergeant.IsPlayingLIPSincAnim()));
		if (DrillSergeant.IsPlayingLIPSincAnim())
		{
			if ((DrillSergeant.CurrentLIPSincAnim() ~= "wf_station2_1") || (DrillSergeant.CurrentLIPSincAnim() ~= "wf_station2_4"))
			{
				bPlayerSkippingIntro=true;
				Log("Shutting down welcome speech animation");
				SetTimerEvent(string(DrillSergeant.CurrentLIPSincAnim()),0.1,3,false);
				DrillSergeant.StopLIPSincAnim();
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
				PlayTip(StationMsg $ "2 " $ StationName,"You can skip this introduction by pressing your <action> key.",6);
			}
			else
			{
				PlayTip(StationMsg $ "2",StationName,6);
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
			HumanController(Player.Controller).Player.Console.ClearMessages();
			TargetManagerResetScores(StationTargetManager);
			TargetManagerPracticeMode(StationTargetManager,false);
			TargetManagerActive(StationTargetManager,true);
			PlayTip(QualificationMsg,"",4);
			WFMasterScript.QualificationHUDOverlay.TargetManager=StationTargetManager;
			break;
			case "FadeOutBlack":
			FadeInBlack(2);
			MasterScript.ResetScript(Self,true);
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
		Log(" Timer_LSAnim called for " $ string(LSName),"M249_Range");
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
		sTempMsg=Repl(ReloadMsg,"%NUMROUNDS%",string(100) $ "-round");
		PlayTip(sTempMsg,"",8);
		Player.CreateInventoryFromName("AGP_Inventory.Ammo_556mm_100_Belt");
		AGP_Weapon(Player.Weapon).RecountAmmo();
		if (bFailedStation)
		{
			if (AGP_Pawn(Controller.Pawn).Weapon == None)
			{
				AGP_Pawn(Controller.Pawn).SwapHands();
			}
			if (Player.Weapon.AmmoType != None)
			{
				Player.Weapon.AmmoType.AmmoAmount=0;
			}
			AGP_Weapon(Player.Weapon).RecountAmmo();
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
		sTempMsg=Repl(ReloadMsg,"%NUMROUNDS%",string(50) $ "-round");
		PlayTip(sTempMsg,"",8);
		StartHelpTimer(3,true);
		Player.CreateInventoryFromName("AGP_Inventory.Ammo_556mm_50_Belt");
		AGP_Weapon(Player.Weapon).RecountAmmo();
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
			MasterScript.SetActiveScript(WF_EL_MasterScript(MasterScript).Station3);
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
	simulated Function ActorProximityAlert(Actor ProximityActor, FName AlertTag)
	{
		if (AlertTag == "Station2_M249")
		{
			DeactivateHelpMarker(HelpMarker);
		}
	}
	simulated Function ReloadEvent(Weapon ReloadedWeapon)
	{
		Log("StationTargetManager is " $ string(StationTargetManager),"M249_Range");
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
	Function bool AGP_Weapon_Empty(AGP_Weapon NotifyActor, Actor Instigator, FString Parms)
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
	simulated Function bool Pickup_PickedUp(Pickup NotifyActor, Actor Instigator, FString Parms)
	{
		if (NotifyActor == SAWPickup)
		{
			StopHelpTimer();
			SAWPickup.SetAllowPickup(false);
			FadeMoveStart(GetActorByTag("Station2_M249"),Self);
		}
		return true;
	}
	Function bool TargerManager_DispatchComplete(AGP_Gameplay.TargetManager NotifyActor, Actor Instigator, FString Parms)
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
		ResultString=string(StationScore) @ "of" @ string(TotalScore) @ "targets hit.";
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
		LogStationEnd(Self,true);
		PlayTip(SuccessMsg,ResultString,6);
		PlayLSAnim("wf_station2_7",DrillSergeant);
	}
	simulated Function AwardPlayerFailure(FString ResultString)
	{
		bFailedStation=true;
		LogStationEnd(Self,false);
		PlayTip(FailureMsg,ResultString,6);
		PlayLSAnim("wf_station2_12",DrillSergeant);
	}
	simulated Function bool AGP_Weapon_Fire(AGP_Weapon Weapon, Actor Instigator, FString Parms)
	{
		return true;
	}
	simulated Function bool Actor_Custom(Actor NotifyActor, Actor.EEventType Event, Actor Instigator, FString Parms)
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
		if ((FSTS_Shot_Detection_Volume(Instigator) != None) || (Parms == "Shot_Out_Of_Lane"))
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
		Log("Ending ActiveExecute state for " $ string(Self),"M249_Range");
		PlayerLock(false,false);
		StopHelpTimer();
		Player.EmptyInventory();
		WFMasterScript.QualificationHUDOverlay.TargetManager=None;
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
	/*
	local Actor SearchActor;
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "PickupW_FSTS_Trainer_M249_SAW")
		{
			SAWPickup = PickupW_FSTS_Trainer_M249_SAW(SearchActor);
			SAWPickup.EventLab = Self;
			SAWPickup.SetAllowPickup(false);
		}
	}
	Super::DoReferenceLinking();
	*/
}

void AWF_EL_M249RangeStation::Reset()
{
	/*
	StopTimerByType(3);
	StopTimerByType(0);
	DrillSergeant.StopLIPSincAnim();
	TargetManagerActive(StationTargetManager, false);
	TargetManagerResetScores(StationTargetManager);
	Player.EmptyInventory();
	SAWPickup.GotoState("Pickup");
	SAWPickup.SetAllowPickup(false);
	SetHelpMarker(HelpMarker, DrillSergeant.Location, HelpMarkerLargeOffset, true, true);
	DSController(DrillSergeant.Controller).TurnTowardPlayer();
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
