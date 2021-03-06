// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_ObstacleArea/ET_EL_ObstacleArea.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_MasterScript.h"

AET_EL_ObstacleArea::AET_EL_ObstacleArea()
{
	MoveForwardMsg = "Press the <MoveForward> key to move toward the obstacle.";
	CrouchingMsg = "Press the <Crouching> key to duck under the obstacle.";
	StandingFromCrouchingMsg = "Press the <Crouching> or <Jump> key to stand back up.";
	JumpMsg = "Press the <jump> key to hop over the obstacle.";
	CrawlingMsg = "Press the <Crawling> key to crawl under the obstacle.";
	StandingFromCrawlingMsg = "Press the <Crawling> or <Jump> key to stand back up.";
	ClimbMsg = "Press the <MoveForward> key to use the rungs to climb over the wall.";
	StrafeMsg = "Press the <StrafeRight> and <StrafeLeft> keys to side step.";
	MoveMsg = "Proceed up the ladder to the rope bridge platform.";
	StationMsg = "Station 1";
	StationNameMsg = "Obstacle Area";
	OutOfBoundsMsg = "OUT OF BOUNDS!";
	AltDrillSergeantTag = "NPC_DS_Rieman";
	StationObjectiveTag = "Station1Objective";
	ResetActorTag = "Station1_Reset";
	StationName = "Confidence Course";
	HelpInfoList = {
		FHelpInfo({"MoveToSergeant",5,"Proceed through the obstacle area","Move near the Drill Sergeant","ea_station2_4",nullptr})
	};
	bDormant = true;
	bMasterScript = false;
	LSAnims = {
		FLSAnim({ "Reiman_Intro_Eagle_Tower",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/s_eagle_tower_Reiman_Intro_Cue.s_eagle_tower_Reiman_Intro_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_2_Cue.ea_station1_2_Cue'"), NULL, LOAD_None, NULL),{"DrillTalkHands","ae_convgest_i","None","None","None","None","None","None","None","None"},{1,5.5,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_3_Cue.ea_station1_3_Cue'"), NULL, LOAD_None, NULL),{"ae_pointmedlt_b","ae_pointnearlt_b","ae_pointmedlt_b","ae_pointnearbklt_b","None","None","None","None","None","None"},{2,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_4_Cue.ea_station1_4_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearlt_a","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_5_Cue.ea_station1_5_Cue'"), NULL, LOAD_None, NULL),{"ae_pointmedlt_b","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_6",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_6_Cue.ea_station1_6_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearlt_c","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_7",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_7_Cue.ea_station1_7_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearfw_b","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_8",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_8_Cue.ea_station1_8_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_9",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_9_Cue.ea_station1_9_Cue'"), NULL, LOAD_None, NULL),{"ae_pointmedlt_b","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_10",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_10_Cue.ea_station1_10_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_11",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_11_Cue.ea_station1_11_Cue'"), NULL, LOAD_None, NULL),{"ae_pointmedlt_b","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_12",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_12_Cue.ea_station1_12_Cue'"), NULL, LOAD_None, NULL),{"ae_pointfarlt_a","None","None","None","None","None","None","None","None","None"},{1,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_13",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_13_Cue.ea_station1_13_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_14",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_14_Cue.ea_station1_14_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_15",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_15_Cue.ea_station1_15_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_16",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_16_Cue.ea_station1_16_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_17",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_17_Cue.ea_station1_17_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_18",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_18_Cue.ea_station1_18_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station1_19",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_19_Cue.ea_station1_19_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
	};
	bDoGeneralInit = false;
}

/*
simulated State ActiveExecute
{
	simulated Function BeginState()
	{
		Log("Beginning ActiveExecute state for " + FString::FromInt(this),"Eagle_Tower");
		PlayLSAnim("Reiman_Intro_Eagle_Tower",AltDrillSergeant);
		Player.Health=100;
		PlayerLock(true,false);
		if (bEagleTowerMasterIntroHeard)
		{
			PlayTip(StationMsg + " " + StationNameMsg,"You can skip this introduction by pressing <action> if you feel you don't need to hear it.",2);
		}
		else
		{
			PlayTip(StationMsg,StationNameMsg,2);
		}
	}
	Function ELPlayerPressedActionKey()
	{
		if (! bEagleTowerMasterIntroHeard)
		{
			return;
		}
		Log("FSTS in state " + FString::FromInt(GetStateName()) + " and DrillSergeant is animating: " + FString::FromInt(AltDrillSergeant.IsPlayingLIPSincAnim()) + " lipsynch is " + AltDrillSergeant.CurrentLIPSincAnim());
		if (AltDrillSergeant.IsPlayingLIPSincAnim())
		{
			if (AltDrillSergeant.CurrentLIPSincAnim() ~= "Reiman_Intro_Eagle_Tower")
			{
				Log("Shutting down welcome speech animation");
				SetTimerEvent(string(AltDrillSergeant.CurrentLIPSincAnim()),0.1,3,false);
				AltDrillSergeant->StopLIPSincAnim();
			}
		}
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(string(this) + " Timer_LSAnim called for " + FString::FromInt(LSName),"Eagle_Tower");
		switch(LSName)
		{
			case "Reiman_Intro_Eagle_Tower":
			Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station_1_Instruction_5");
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			PlayerLock(false,false);
			PlayTip(MoveForwardMsg,"",5);
			CheckPlayerMove();
			bEagleTowerMasterIntroHeard=true;
			SaveConfig();
			break;
			case "ea_station1_12":
			break;
			case "ea_station1_14":
			break;
			default:
		}
		return true;
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		HandleHelpTimerEvent(TimerName);
		switch(TimerName)
		{
			case "FadeOutBlack":
			FadeInBlack(1);
			StartTimer("FadeInBlack",1);
			Player.Health=100;
			Player.SetLocation(GetActorByTag(ResetActorTag).Location);
			Controller.SetRotation(GetActorByTag(ResetActorTag).Rotation);
			PlayerLock(false,false);
			break;
			case "FadeInBlack":
			break;
			default:
			break;
		}
		return true;
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume* NotifyActor, AActor* Instigator)
	{
		Log("Trigger Volume enter called for " + FString::FromInt(NotifyActor.Tag),"Eagle_Tower");
		switch(NotifyActor.Tag)
		{
			case "Station1_Leave":
			Log("OUT OF BOUNDS!","Eagle_Tower");
			PlayerLock(true,false);
			PlayLSAnim("ea_station1_16",DrillSergeant);
			PlayTip(OutOfBoundsMsg,"",3);
			FadeOutBlack(1);
			StartTimer("FadeOutBlack",1);
			return true;
			break;
			default:
			break;
		}
		return false;
	}
	Function bool Volume_Enter(AVolume* NotifyActor, AActor* Instigator)
	{
		Log("Volume enter called for " + FString::FromInt(NotifyActor.Tag),"Eagle_Tower");
		switch(NotifyActor.Tag)
		{
			case "Station1_Obstacle1":
			Log("Reached Obstacle 1","Eagle_Tower");
			PlayLSAnim("ea_station1_4",DrillSergeant);
			PlayTip(CrouchingMsg,StandingFromCrouchingMsg,3);
			return true;
			break;
			case "Station1_Obstacle2":
			Log("Reached Obstacle 2","Eagle_Tower");
			PlayLSAnim("ea_station1_9",DrillSergeant);
			PlayTip(JumpMsg,"",3);
			return true;
			break;
			case "Station1_Obstacle3":
			Log("Reached Obstacle 3","Eagle_Tower");
			PlayLSAnim("ea_station1_7",DrillSergeant);
			PlayTip(CrawlingMsg,StandingFromCrawlingMsg,3);
			return true;
			break;
			case "Station1_Obstacle4":
			Log("Reached Obstacle 4","Eagle_Tower");
			PlayLSAnim("ea_station1_11",DrillSergeant);
			PlayTip(ClimbMsg,"",3);
			return true;
			break;
			case "Station1_Obstacle5":
			Log("Reached Obstacle 5","Eagle_Tower");
			PlayLSAnim("ea_station1_6",DrillSergeant);
			PlayTip(StrafeMsg,"",3);
			return true;
			break;
			case "Station1_Exit":
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			PlayLSAnim("ea_station1_12",DrillSergeant);
			SetHelpMarker(HelpMarker,GetActorByTag("Tower1_Move_Point")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			DetectProximityToActor(GetActorByTag("Tower1_Move_Point"),Player,60,"Tower1_Move_Point");
			PlayTip(MoveMsg,"",4);
			return true;
			break;
			default:
			break;
		}
		return false;
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if (AlertTag == "DrillSergeant")
		{
			DeactivateHelpMarker(HelpMarker);
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			PlayLSAnim("ea_station1_12",DrillSergeant);
			SetHelpMarker(HelpMarker,GetActorByTag("Tower1_Move_Point")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			DetectProximityToActor(GetActorByTag("Tower1_Move_Point"),Player,60,"Station1_End");
			PlayTip(MoveMsg,"",4);
		}
		else
		{
			if (AlertTag == "Tower1_Move_Point")
			{
				StationComplete();
			}
			else
			{
				if (AlertTag == "Station1_End")
				{
					StationComplete();
				}
			}
		}
	}
	simulated Function StationComplete()
	{
		bStationComplete=true;
		LogStationEnd(this,true);
		StationObjective.SetDisabled(true);
		DeactivateHelpMarker(HelpMarker);
		Cast<ADSController>(DrillSergeant.Controller).WaitForTimer(10);
		Cast<ADSController>(DrillSergeant.Controller).Walk();
		Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station_1_Instruction_6");
		MasterScript.SetActiveScript(Cast<AET_EL_MasterScript>(MasterScript).Station2);
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this),"Eagle_Tower");
	}
}
*/

void AET_EL_ObstacleArea::Reset()
{
	/*
	DeactivateHelpMarker(HelpMarker);
	StationObjective.SetDisabled(false);
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	PlayerLock(false, false);
	Player.SetLocation(GetActorByTag(ResetActorTag).Location);
	Controller.SetRotation(GetActorByTag(ResetActorTag).Rotation);
	Super::Reset();
	*/
}

void AET_EL_ObstacleArea::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
}

void AET_EL_ObstacleArea::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	Super::DoReferenceLinking();
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (((((((SearchActor.Tag == "Station1_Obstacle1") || (SearchActor.Tag == "Station1_Obstacle2")) || (SearchActor.Tag == "Station1_Obstacle3")) || (SearchActor.Tag == "Station1_Obstacle4")) || (SearchActor.Tag == "Station1_Obstacle5")) || (SearchActor.Tag == "Station1_Leave")) || (SearchActor.Tag == "Station1_Exit"))
		{
			SearchActor.EventLab = this;
		}
	}
	*/
}
