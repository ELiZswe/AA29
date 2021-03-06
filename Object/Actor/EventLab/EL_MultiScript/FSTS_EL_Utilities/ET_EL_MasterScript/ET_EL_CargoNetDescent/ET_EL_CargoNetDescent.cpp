// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_CargoNetDescent/ET_EL_CargoNetDescent.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"

AET_EL_CargoNetDescent::AET_EL_CargoNetDescent()
{
	MoveIntoPositionMsg = "Move into position next to the cargo net.";
	MouseMsg = "Use the mouse to turn and face away from the cargo net.";
	MoveBackwardMsg = "Press the <MoveBackward> key to climb down.";
	SprintMsg = "Double-tap <MoveForward> or press the <Sprint> key to sprint.";
	MoveMsg = "Move to the next Drill Sergeant.";
	StationMsg = "Station 3";
	StationNameMsg = "Cargo Net Descent";
	DrillSergeantTag = "NPC_DS_Koch";
	AltDrillSergeantTag = "NPC_DS_Mateo";
	StationObjectiveTag = "Station3Objective";
	ResetActorTag = "Station3_Reset";
	StationName = "Cargo Net Rappel";
	HelpInfoList = {
		FHelpInfo({"MoveToSergeant",5,"Climb down the cargo net","Move near the Drill Sergeant","ea_station3_6",nullptr})
	};
	bDormant = true;
	bMasterScript = false;
	LSAnims = {
		FLSAnim({ "ea_station3_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station3/ea_station3_1_Cue.ea_station3_1_Cue'"), NULL, LOAD_None, NULL),{"ae_pointfarrt_b","None","None","None","None","None","None","None","None","None"},{1,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station3_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station3/ea_station3_2_Cue.ea_station3_2_Cue'"), NULL, LOAD_None, NULL),{"acf_convgest_e","ae_pointnearrt_a","None","None","None","None","None","None","None","None"},{0,3,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station3_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station3/ea_station3_3_Cue.ea_station3_3_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearfw_b","None","None","None","None","None","None","None","None","None"},{1,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station3_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station3/ea_station3_4_Cue.ea_station3_4_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station3_5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station3/ea_station3_5_Cue.ea_station3_5_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station3_6",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station3/ea_station3_6_Cue.ea_station3_6_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station4_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station4/ea_station4_1_Cue.ea_station4_1_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearfw_b","None","None","None","None","None","None","None","None","None"},{1,0,0,0,0,0,0,0,0,0} }),
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
		PlayLSAnim("ea_station3_1",DrillSergeant);
		Player.Health=100;
		PlayerLock(true,false);
		SetHelpMarker(HelpMarker,GetActorByTag("Station3_CargoNetTop")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		PlayTip(StationMsg,StationNameMsg,2);
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		switch(LSName)
		{
			case "ea_station3_1":
			PlayerLock(false,false);
			SetHelpMarker(HelpMarker,GetActorByTag("Station3_CargoNetTop")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			DetectProximityToActor(GetActorByTag("Station3_CargoNetTop"),Player,60,"Station3_CargoNetTop");
			PlayTip(MoveIntoPositionMsg,"",5);
			CheckPlayerMove();
			break;
			case "ea_station3_2":
			PlayLSAnim("ea_station3_3",DrillSergeant);
			break;
			case "ea_station4_1":
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
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if (AlertTag == "Station3_CargoNetTop")
		{
			DeactivateHelpMarker(HelpMarker);
			SetHelpMarker(HelpMarker,GetActorByTag("Station3_CargoNetBottom")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			DetectProximityToActor(GetActorByTag("Station3_CargoNetBottom"),Player,60,"Station3_CargoNetBottom");
			PlayTip(MouseMsg,MoveBackwardMsg,5);
			PlayLSAnim("ea_station3_2",DrillSergeant);
		}
		else
		{
			if (AlertTag == "Station3_CargoNetBottom")
			{
				DeactivateHelpMarker(HelpMarker);
				SetHelpMarker(HelpMarker,AltDrillSergeant->GetActorLocation(),HelpMarkerLargeOffset,true,true);
				DetectProximityToActor(AltDrillSergeant,Player,100,"AltDrillSergeant");
				PlayTip(SprintMsg,"",5);
				PlayLSAnim("ea_station4_1",AltDrillSergeant);
			}
			else
			{
				if (AlertTag == "AltDrillSergeant")
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
		MasterScript.SetActiveScript(ETMasterScript.Station4);
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this),"Eagle_Tower");
	}
}
*/

void AET_EL_CargoNetDescent::Reset()
{
	Super::Reset();
	//DrillSergeant->StopLIPSincAnim();
	bEnteredLadder = false;
	//Player->Health = 100;
}

void AET_EL_CargoNetDescent::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
}

void AET_EL_CargoNetDescent::DoReferenceLinking()
{
	


	Super::DoReferenceLinking();
	//ForEach AllActors(Class'Actor', SearchActor)
	//{
	//	if (SearchActor.Tag == "Station4_Entry")
	//	{
	//		SearchActor.EventLab = this;
	//	}
	//}
}
