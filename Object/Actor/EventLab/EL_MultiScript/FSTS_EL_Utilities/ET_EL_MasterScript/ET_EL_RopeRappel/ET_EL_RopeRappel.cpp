// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_RopeRappel/ET_EL_RopeRappel.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"

AET_EL_RopeRappel::AET_EL_RopeRappel()
{
	CrawlingMsg = "Press the <Crawling> key to crawl.";
	MoveForwardMsg = "Press the <MoveForward> key to move toward the drill sergeant.";
	MouseMsg = "Use the mouse to turn and face away from the rappel wall and ";
	MoveBackwardMsg = "Press the <MoveBackward> key to climb down.";
	MoveMsg = "Move to the next drill instructor.";
	CongratulationsMsg = "Congratulations!";
	MissionCompleteMsg = "Eagle Tower Confidence Course Completed!";
	StationMsg = "Station 5";
	StationNameMsg = "Rope Rappel";
	DrillSergeantTag = "NPC_DS_Lang";
	AltDrillSergeantTag = "NPC_DS_DSOY";
	StationObjectiveTag = "Station5Objective";
	ResetActorTag = "Station5_Reset";
	StationName = "Rope Rappel";
	HelpInfoList = {
		FHelpInfo({"MoveToSergeant",5,"Go prone","Move near the Drill Sergeant","ea_station5_1",nullptr})
	};
	bDormant = true;
	bMasterScript = false;
	LSAnims = {
		FLSAnim({ "ea_station5_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station5/ea_station5_1_Cue.ea_station5_1_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearfw_b","None","None","None","None","None","None","None","None","None"},{1,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station5_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station5/ea_station5_2_Cue.ea_station5_2_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearrt_b","None","None","None","None","None","None","None","None","None" }, { 3,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station4_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station5/ea_station5_3_Cue.ea_station5_3_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None" }, { 0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "ea_station4_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station5/ea_station5_4_Cue.ea_station5_4_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None" }, { 0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "ea_station4_5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station5/ea_station5_5_Cue.ea_station5_5_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None" }, { 0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "ea_station1_13",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station1/ea_station1_13_Cue.ea_station1_13_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None" }, { 0,0,0,0,0,0,0,0,0,0 } })
	};
	bDoGeneralInit = false;
}

/*
simulated State ActiveExecute
{
	simulated Function BeginState()
	{
		Log("Beginning ActiveExecute state for " + FString::FromInt(this),"Eagle_Tower");
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
		PlayLSAnim("ea_station5_1",DrillSergeant);
		Player.Health=100;
		PlayerLock(true,false);
		DetectProximityToActor(DrillSergeant,Player,100,"DrillSergeant");
		SetHelpMarker(HelpMarker,GetActorByTag("S5TopOfRappel")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		PlayTip(StationMsg,StationNameMsg,2);
	}
	simulated Function bool Timer_LSAnim(FName LSAnim)
	{
		switch(LSAnim)
		{
			case "ea_station5_1":
			PlayerLock(false,false);
			PlayTip(MoveForwardMsg,"",3);
			CheckPlayerMove();
			break;
			case "ea_station1_13":
			MissionComplete();
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
			FadeInBlack(2);
			StartTimer("FadeInBlack",2);
			Player.Health=100;
			Player.SetLocation(GetActorByTag(ResetActorTag).Location);
			Controller.SetRotation(GetActorByTag(ResetActorTag).Rotation);
			break;
			case "FadeInBlack":
			break;
			default:
			break;
		}
		return true;
	}
	Function bool Volume_Enter(AVolume* NotifyActor, AActor* Instigator)
	{
		Log("Volume enter called for " + FString::FromInt(NotifyActor.Tag),"Eagle_Tower");
		switch(NotifyActor.Tag)
		{
			case "Station5_Complete":
			if (Player.Health == 100)
			{
				StationComplete();
				return true;
			}
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
			SetHelpMarker(HelpMarker,GetActorByTag("S5BottomOfRappel")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			PlayLSAnim("ea_station5_2",DrillSergeant);
			PlayTip(MouseMsg,MoveBackwardMsg,5);
		}
		if (AlertTag == "BottomOfRappel")
		{
			DeactivateHelpMarker(HelpMarker);
			SetHelpMarker(HelpMarker,AltDrillSergeant->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			DetectProximityToActor(AltDrillSergeant,Player,100,"AltDrillSergeant");
			PlayTip(MoveMsg,"",5);
		}
		if (AlertTag == "AltDrillSergeant")
		{
			StationComplete();
		}
	}
	simulated Function StationComplete()
	{
		bStationComplete=true;
		LogStationEnd(this,true);
		StationObjective.SetDisabled(true);
		DeactivateHelpMarker(HelpMarker);
		StopCustomTimer("CheckPlayerMove");
		Cast<ADSController>(AltDrillSergeant.Controller).TurnTowardPlayer();
		PlayLSAnim("ea_station1_13",AltDrillSergeant);
		PlayTip(CongratulationsMsg,MissionCompleteMsg,5);
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this),"Eagle_Tower");
	}
}
*/

void AET_EL_RopeRappel::Reset()
{
	Super::Reset();
	//DrillSergeant->StopLIPSincAnim();
	//Player.Health = 100;
}

void AET_EL_RopeRappel::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
}

void AET_EL_RopeRappel::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	Super::DoReferenceLinking();
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if ((SearchActor.Tag == "Station5_Complete") || (SearchActor.Tag == "Station5_Entry"))
		{
			SearchActor.EventLab = this;
		}
	}
	*/
}
