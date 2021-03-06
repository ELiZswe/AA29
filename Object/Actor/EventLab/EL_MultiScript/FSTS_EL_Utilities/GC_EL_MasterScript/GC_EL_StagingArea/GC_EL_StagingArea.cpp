// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_StagingArea/GC_EL_StagingArea.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"

AGC_EL_StagingArea::AGC_EL_StagingArea()
{
	DrillSergeantTag = "NPC_DS_DSOY";
	bNoReportStationToAAR = true;
	StationObjectiveTag = "StagingAreaObjective";
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
		FadeInBlack(2);
		Player.SetLocation(GetActorByTag("Station0_StartPt").Location);
		Controller.SetRotation(GetActorByTag("Station0_StartPt").Rotation);
		PlayerLock(false,false);
		ForcePlayerCrouch(false);
		PlayTip("Mills Range","Hand Grenade Confidence Course",5);
		PlayLSAnim("gr_stagingarea_1",DrillSergeant);
		PlayerLock(true,false);
	}
	simulated Function bool Timer_LSAnim(FName LSAnim)
	{
		switch(LSAnim)
		{
			case "gr_stagingarea_1":
			PlayLSAnim("gr_stagingarea_2",DrillSergeant);
			break;
			case "gr_stagingarea_2":
			SetTimerEvent("MoveAlongTimeout",10,0,true);
			StationComplete();
			break;
			default:
		}
		return true;
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		if (TimerName == "MoveAlongTimeout")
		{
			PlayLSAnim(LSAnims[(3 + Rand(4))].Anim,DrillSergeant);
			PlayTip("Follow the path to the first station.","",5);
			return true;
		}
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if (AlertTag == "PlayerLeaving")
		{
			Cast<ADSController>(DrillSergeant.Controller).Walk();
			Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station0_BlockReturn");
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			GCMasterScript.SetActiveScript(GCMasterScript.Station1);
		}
	}
	simulated Function StationComplete()
	{
		bStationComplete=true;
		SetHelpMarker(DirectionMarker,GetActorByTag("ToStation1")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("ToStation1").Rotation);
		PlayerLock(false,false);
		DetectProximityToActor(GetActorByTag("Station0_BlockReturn"),Player,350,"PlayerLeaving");
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this));
	}
}
*/

void AGC_EL_StagingArea::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
	}
	*/
}

void AGC_EL_StagingArea::Reset()
{
	Super::Reset();
}
