// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_LadderClimb/ET_EL_LadderClimb.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_MasterScript.h"

AET_EL_LadderClimb::AET_EL_LadderClimb()
{
	MoveForwardMsg = "Press the <MoveForward> key to climb the ladder.";
	SprintMsg = "Double-tap <MoveForward> or press the <Sprint> key to sprint.";
	MoveMsg = "Proceed to the ladder.";
	StationMsg = "Station 4";
	StationNameMsg = "Ladder Climb";
	DrillSergeantTag = "NPC_DS_Mateo";
	AltDrillSergeantTag = "NPC_DS_Lang";
	StationObjectiveTag = "Station4Objective";
	ResetActorTag = "Station4_Reset";
	StationName = "High Ladder Climb";
	HelpInfoList = {
		FHelpInfo({"MoveToSergeant",7,"Move next to the Drill Sergeant","","ea_station4_1",nullptr})
	};
	bDormant = true;
	bMasterScript = false;
	LSAnims = {
		FLSAnim({ "ea_station4_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station4/ea_station4_1_Cue.ea_station4_1_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearfw_b","None","None","None","None","None","None","None","None","None"},{1,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station4_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station4/ea_station4_2_Cue.ea_station4_2_Cue'"), NULL, LOAD_None, NULL),{"ae_pointfarlt_b","None","None","None","None","None","None","None","None","None" },{4,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station4_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station4/ea_station4_4_Cue.ea_station4_4_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None" },{0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "ea_station4_5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station4/ea_station4_5_Cue.ea_station4_5_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None" },{0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "ea_station4_6",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station4/ea_station4_6_Cue.ea_station4_6_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None" },{0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "ea_station4_7",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station4/ea_station4_7_Cue.ea_station4_7_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None" },{0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "ea_station4_8",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station4/ea_station4_8_Cue.ea_station4_8_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None" },{0,0,0,0,0,0,0,0,0,0 } })
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
		PlayLSAnim("ea_station4_2",DrillSergeant);
		DrillSergeant.Controller.bControlAnimations=false;
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
		Cast<ADSController>(DrillSergeant.Controller).WaitForTimer(6);
		Cast<ADSController>(DrillSergeant.Controller).SetViewTarget("Station_4_Instruction_2");
		Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station_4_Instruction_2");
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
		Cast<ADSController>(DrillSergeant.Controller).WaitForTimer(4);
		Cast<ADSController>(DrillSergeant.Controller).PlayAnimation("ae_pointwtfotlt_a");
		DetectProximityToActor(GetActorByTag("S4BottomOfLadder"),Player,100,"BottomOfLadder");
		Player.Health=100;
		PlayerLock(true,false);
		SetHelpMarker(HelpMarker,GetActorByTag("S4BottomOfLadder")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		PlayTip(StationMsg,StationNameMsg,2);
	}
	simulated Function bool Timer_LSAnim(FName LSAnim)
	{
		switch(LSAnim)
		{
			case "ea_station4_2":
			PlayerLock(false,false);
			PlayTip(MoveMsg,"",3);
			CheckPlayerMove();
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
		if (AlertTag == "DrillSergeant")
		{
			GOTO JL00BB;
		}
		if (AlertTag == "BottomOfLadder")
		{
			SetHelpMarker(HelpMarker,GetActorByTag("S4TopOfLadder")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			DrillSergeant.Controller.bControlAnimations=true;
			PlayLSAnim("ea_station4_5",DrillSergeant);
			PlayTip(MoveForwardMsg,"",3);
			DetectProximityToActor(GetActorByTag("S4TopOfLadder"),Player,60,"TopOfLadder");
		}
		else
		{
			if (AlertTag == "TopOfLadder")
			{
				StationComplete();
JL00BB:
			}
		}
	}
	simulated Function StationComplete()
	{
		bStationComplete=true;
		LogStationEnd(this,true);
		StationObjective.SetDisabled(true);
		DeactivateHelpMarker(HelpMarker);
		MasterScript.SetActiveScript(Cast<AET_EL_MasterScript>(MasterScript).Station5);
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this),"Eagle_Tower");
	}
}
*/

void AET_EL_LadderClimb::Reset()
{
	Super::Reset();
	//DrillSergeant->StopLIPSincAnim();
	//Player.Health = 100;
}

void AET_EL_LadderClimb::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
}

void AET_EL_LadderClimb::DoReferenceLinking()
{
	Super::DoReferenceLinking();
	for (TActorIterator<AActor> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator)
	{
		AActor* SearchActor = *ActorIterator;
		if (SearchActor->ActorHasTag("Station5_Entry"))
		{
			//SearchActor->EventLab = this;
		}
	}
}
