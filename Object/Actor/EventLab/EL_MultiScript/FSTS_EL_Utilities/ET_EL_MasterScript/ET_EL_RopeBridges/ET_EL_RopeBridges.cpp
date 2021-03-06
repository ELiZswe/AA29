// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_RopeBridges/ET_EL_RopeBridges.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/Brush/Volume/BlockingVolume/PlayerBlockingVolume/TriggeredPlayerBlockingVolume/TriggeredPlayerBlockingVolume.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_MasterScript.h"

AET_EL_RopeBridges::AET_EL_RopeBridges()
{
	ActionMsg = "Press the <Action> key ";
	MountTwoRopeBridgeMsg = "to mount the 2-rope bridge.";
	StrafeMsg = "Use the <StrafeLeft> and <StrafeRight> keys ";
	EndTwoRopeBridgeMsg = "to move across the 2-rope bridge sideways.";
	CommandoCrawlMsg = "Press the <MoveForward> key to commando crawl ";
	EndOneRopeBridgeMsg = "to the end of the 1-rope bridge.";
	MoveForwardMsg = "Press the <MoveForward> key to move ";
	EndThreeRopeBridgeMsg = "to the end of the 3-rope bridge.";
	MountOneRopeBridgeMsg = "to mount the 1-rope bridge.";
	MountThreeRopeBridgeMsg = "Mount the 3-rope bridge.";
	MoveMsg = "Proceed over to the cargo net.";
	StationMsg = "Station 2";
	StationNameMsg = "Rope Bridges";
	DrillSergeantTag = "NPC_DS_Baker";
	AltDrillSergeantTag = "NPC_DS_Koch";
	StationObjectiveTag = "Station2Objective";
	ResetActorTag = "Station2_Reset";
	StationName = "Rope Bridges";
	HelpInfoList = {
		FHelpInfo({"MoveToSergeant",5,"Proceed across the rope bridge platform","Move near the Drill Sergeant","ea_station2_4",nullptr})
	};
	bDormant = true;
	bMasterScript = false;
	LSAnims = {
		FLSAnim({ "ea_station2_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station2/ea_station2_1_Cue.ea_station2_1_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearrt_b","None","None","None","None","None","None","None","None","None"},{1,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station2_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station2/ea_station2_2_Cue.ea_station2_2_Cue'"), NULL, LOAD_None, NULL),{"ae_pointfarfw_b","None","None","None","None","None","None","None","None","None" },{1,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station2_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station2/ea_station2_3_Cue.ea_station2_3_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearrt_b","None","None","None","None","None","None","None","None","None" },{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station2_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station2/ea_station2_4_Cue.ea_station2_4_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearfw_b","None","None","None","None","None","None","None","None","None" },{1,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "ea_station3_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_EagleTower/Station3/ea_station3_1_Cue.ea_station3_1_Cue'"), NULL, LOAD_None, NULL),{"ae_pointnearfw_b","None","None","None","None","None","None","None","None","None" },{1,0,0,0,0,0,0,0,0,0} })
	};
	bDoGeneralInit = false;
}

/*
simulated State ActiveExecute
{
	simulated Function BeginState()
	{
		Log("Beginning ActiveExecute state for " + FString::FromInt(this),"Eagle_Tower");
		SetHelpMarker(HelpMarker,GetActorByTag("Station2_Tower")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		DetectProximityToActor(DrillSergeant,Player,80,"DrillSergeant");
		LowTowerBlockingVolume.DeactivatePlayerBlocking();
		HighTowerBlockingVolume.DeactivatePlayerBlocking();
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(string(this) + " Timer_LSAnim called for " + FString::FromInt(LSName),"Eagle_Tower");
		switch(LSName)
		{
			case "ea_station2_1":
			Player.Health=100;
			PlayerLock(false,false);
			PlayTip(MountThreeRopeBridgeMsg,"",3);
			CheckPlayerMove();
			break;
			case "ea_station3_1":
			case "ea_station2_2":
			StationComplete();
			break;
			default:
		}
		return true;
	}
	Function bool AGP_UseTrigger_UsedBy(AAGP_UseTrigger* NotifyActor, AActor* Instigator)
	{
		switch(NotifyActor)
		{
			case Rope1EntryTrigger:
			Player.SetLocation(Rope1Start.Location);
			Controller.SetRotation(Rope1Start.Rotation);
			DetectProximityToActor(GetActorByTag("Rope1End"),Player,60,"Rope1End");
			LowTowerBlockingVolume.DeactivatePlayerBlocking();
			HighTowerBlockingVolume.DeactivatePlayerBlocking();
			SetHelpMarker(HelpMarker,GetActorByTag("Rope1End")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			PlayTip(MoveForwardMsg,EndThreeRopeBridgeMsg,3);
			Rope1EntryTrigger.bActive=false;
			break;
			case Rope2EntryTrigger:
			Player.SetLocation(Rope2Start.Location);
			Controller.SetRotation(Rope2Start.Rotation);
			ForcePlayerProne(true);
			DetectProximityToActor(GetActorByTag("Rope2End"),Player,40,"Rope2End");
			LowTowerBlockingVolume.DeactivatePlayerBlocking();
			HighTowerBlockingVolume.DeactivatePlayerBlocking();
			SetHelpMarker(HelpMarker,GetActorByTag("Rope2End")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			PlayTip(CommandoCrawlMsg,EndOneRopeBridgeMsg,3);
			Rope2EntryTrigger.bActive=false;
			break;
			case Rope3EntryTrigger:
			Player.SetLocation(Rope3Start.Location);
			Controller.SetRotation(Rope3Start.Rotation);
			DetectProximityToActor(GetActorByTag("Rope3End"),Player,40,"Rope3End");
			LowTowerBlockingVolume.DeactivatePlayerBlocking();
			HighTowerBlockingVolume.DeactivatePlayerBlocking();
			SetHelpMarker(HelpMarker,GetActorByTag("Rope3End")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			PlayTip(MoveForwardMsg,EndTwoRopeBridgeMsg,3);
			Rope3EntryTrigger.bActive=false;
			break;
			default:
		}
		Log("Tag is " + FString::FromInt(NotifyActor.Tag) + " and event is " + FString::FromInt(NotifyActor.Event),"Eagle_Tower");
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
			DeactivateHelpMarker(HelpMarker);
			PlayTip(StationMsg,StationNameMsg,2);
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			PlayLSAnim("ea_station2_1",DrillSergeant);
			PlayerLock(true,false);
			Cast<ADSController>(AltDrillSergeant.Controller).MoveToPoint("TopOfRope2");
			Cast<ADSController>(AltDrillSergeant.Controller).TurnTowardPlayer();
			SetHelpMarker(HelpMarker,GetActorByTag("Rope1SnapPt")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			DetectProximityToActor(GetActorByTag("Rope1SnapPt"),Player,60,"Rope1SnapPt");
		}
		else
		{
			if (AlertTag == "Rope1SnapPt")
			{
				DetectProximityToActor(GetActorByTag("Rope1End"),Player,60,"Rope1End");
				SetHelpMarker(HelpMarker,GetActorByTag("Rope1End")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
				PlayTip(MoveForwardMsg,EndThreeRopeBridgeMsg,3);
			}
			else
			{
				if (AlertTag == "Rope1End")
				{
					PlayerLock(true,false);
					Cast<ADSController>(AltDrillSergeant.Controller).TurnTowardPlayer();
					PlayLSAnim("ea_station2_2",AltDrillSergeant);
					DeactivateHelpMarker(HelpMarker);
				}
				else
				{
					if (AlertTag == "Rope2End")
					{
					}
					if (AlertTag == "Rope3End")
					{
						StationComplete();
					}
				}
			}
		}
	}
	simulated Function StationComplete()
	{
		bStationComplete=true;
		LogStationEnd(this,true);
		StationObjective.SetDisabled(true);
		MasterScript.SetActiveScript(Cast<AET_EL_MasterScript>(MasterScript).Station3);
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this),"Eagle_Tower");
	}
}
*/

void AET_EL_RopeBridges::Reset()
{
	Super::Reset();
	//DrillSergeant->StopLIPSincAnim();
	//Player.Health = 100;
}

void AET_EL_RopeBridges::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
}

void AET_EL_RopeBridges::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	Super::DoReferenceLinking();
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (Cast<AAGP_UseTrigger>(SearchActor) != nullptr)
		{
			SearchActor.EventLab = this;
			AGP_UseTrigger(SearchActor).bActive = false;
		}
		if (SearchActor.Tag == "Station2_Complete")
		{
			SearchActor.EventLab = this;
		}
		switch (SearchActor.Tag)
		{
		case "HighRopeBlockVolume":
			SearchActor.EventLab = this;
			HighTowerBlockingVolume = TriggeredPlayerBlockingVolume(SearchActor);
			break;
		case "LowRopeBlockVolume":
			SearchActor.EventLab = this;
			LowTowerBlockingVolume = TriggeredPlayerBlockingVolume(SearchActor);
			break;
		case "Rope1SnapPt":
			Rope1Start = SearchActor;
			break;
		case "Rope2SnapPt":
			Rope2Start = SearchActor;
			break;
		case "Rope3SnapPt":
			Rope3Start = SearchActor;
			break;
		case "Rope1Entry":
			Rope1EntryTrigger = Cast<AAGP_UseTrigger>(SearchActor);
			break;
		case "Rope2Entry":
			Rope2EntryTrigger = Cast<AAGP_UseTrigger>(SearchActor);
			break;
		case "Rope3Entry":
			Rope3EntryTrigger = Cast<AAGP_UseTrigger>(SearchActor);
			break;
		default:
		}
	}
	*/
}
