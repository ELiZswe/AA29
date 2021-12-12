// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_MasterScript.h"

AGC_EL_MasterScript::AGC_EL_MasterScript()
{
	bAllowGrenade = true;
	PlayerPassedStationString = "You received a \"Go\" for this station.";
	PlayerFailedStatioNString = "You received a \"No - Go\" for this station.";
	GoToNextStationString = "Proceed to the next station.";
	HelpMarkerSmallOffset = FVector(0, 0, 25);
	HelpMarkerLargeOffset = FVector(0, 0, 80);
	NumStationsRequired = 5;
	TrainingName = "Grenade Course Training";
	bMasterScript = true;
	LevelScriptsClasses = {
		//class'FSTS.GC_EL_LiveThrowArea'
		//class'FSTS.GC_EL_StagingArea'
		//class'FSTS.GC_EL_FightingPositionThrow'
		//class'FSTS.GC_EL_BunkerThrow'
		//class'FSTS.GC_EL_MortarThrow'
		//class'FSTS.GC_EL_ProneThrow'
		//class'FSTS.GC_EL_TrenchThrow'
		//class'FSTS.GC_EL_VehicleThrow'
	};
	bUseLevelBeginFadeIn = true;
	LevelBeginFadeInTime = 3.5;
}

/*
simulated State LevelBegin
{
	simulated Function BeginState()
	{
		PlayerLock(true,true);
		SetTimerEvent("InitialPlayerOrientation",0.5,0,false);
		PlayTip("Mills Range","Hand Grenade Training Live Throw",7);
	}
	simulated Function bool Timer_Timer(FName EventName)
	{
		switch(EventName)
		{
			case "LevelBeginFadeInComplete":
			PlayerLock(true,false);
			SetActiveScript(LiveThrowArea);
			return true;
			case "InitialPlayerOrientation":
			FacePlayerTo(LiveThrowArea.DrillSergeant,"Neck","CameraBone");
			break;
			default:
		}
		return false;
	}
	simulated Function EndState()
	{
	}
}
*/

/*
simulated State Dormant
{
	simulated Function BeginState()
	{
	}
	simulated Function EndState()
	{
	}
}
*/

void AGC_EL_MasterScript::EventLabTick(float DeltaTime)
{
	Super::EventLabTick(DeltaTime);
	if (bDormant)
	{
		return;
	}
}

void AGC_EL_MasterScript::PostInit()
{
	Super::PostInit();
	DoReferenceLinking();
	if (bMasterScript)
	{
		LinkDrillSergeants();
	}
}

void AGC_EL_MasterScript::PostPostInit()
{
	Super::PostPostInit();
	if (bMasterScript)
	{
		ChangeState("LevelBegin","");
	}
	else
	{
		ChangeState("Dormant","");
	}
}

void AGC_EL_MasterScript::DoReferenceLinking()
{
	/*
	local Actor SearchActor;
	local Actor GH;
	if (!bMasterScript)
	{
		Super::DoReferenceLinking();
		return;
	}
	if (bMasterScript)
	{
		GH = Level.GetGrenadeHelper();
		GH.EventLab = Self;
		ForEach AllActors(Class'Actor', SearchActor)
		{
		}
	}
	*/
}

bool AGC_EL_MasterScript::AllowGrenade()
{
	/*
	if (GC_EL_MasterScript(GetActiveScript()) != None)
	{
		return GC_EL_MasterScript(GetActiveScript()).bAllowGrenade;
	}
	else
	{
		return bAllowGrenade;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void AGC_EL_MasterScript::GrenadeExploded(AActor* Grenade, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	local GC_EL_MasterScript ActiveScript;
	if (bMasterScript)
	{
		ActiveScript = GC_EL_MasterScript(GetActiveScript());
		if ((ActiveScript == None) || (ActiveScript == Self))
		{
			Log("Breaking from masterscript GrenadeExploded().  ActiveScript is " $ string(ActiveScript));
			return;
		}
		else
		{
			if (ActiveScript != None)
			{
				ActiveScript.GrenadeExploded(Grenade, Event, aInstigator, Parms);
			}
		}
	}
	*/
}

bool AGC_EL_MasterScript::Volume_Enter(AVolume* NotifyActor, AActor* aInstigator)
{
	if (!bMasterScript)
	{
		return false;
	}
	return true;
}

void AGC_EL_MasterScript::Reset()
{
	Super::Reset();
	if (bMasterScript)
	{
	}
}

bool AGC_EL_MasterScript::GenerateLevelSpecificSuccessStrings(FString& Line1, FString& Line2)
{
	/*
	int32 numpassed = 0;
	FString QualifyLevel = "";
	numpassed = GetNumStationsPassed();
	numpassed--;
	Line1 = "Mission Complete!";
	if (numpassed >= 6)
	{
		QualifyLevel = "Expert";
	}
	else
	{
		if (numpassed == 5)
		{
			QualifyLevel = "First Class";
		}
		else
		{
			if (numpassed == 4)
			{
				QualifyLevel = "Second Class";
			}
			else
			{
				return false;
			}
		}
	}
	Line2 = "Congratulations!  You qualified " $ QualifyLevel $ ".";
	*/
	return true;
}

bool AGC_EL_MasterScript::GenerateLevelSpecificFailureStrings(FString& Line1, FString& Line2)
{
	int32 numpassed = 0;
	int32 numrequired = 0;
	/*
	numpassed = GetNumStationsPassed();
	numpassed--;
	numrequired = (NumStationsRequired - 1);
	Line1 = "Mission Failed.";
	Line2 = "You passed" @ string(numpassed) @ "out of a required" @ string(numrequired) @ "stations.";
	*/
	return true;
}

void AGC_EL_MasterScript::GenerateAuthNumStationsPassed(int32 StationsPassed)
{
	if (!bMasterScript)
	{
		return;
	}
	StationsPassed--;
	SetAuthNumStationsPassed(StationsPassed);
}

FString AGC_EL_MasterScript::GetTrainingMapName()
{
	return "Grenade_Range.aao";
}

void AGC_EL_MasterScript::SetMasterScript()
{
	/*
	Super::SetMasterScript();
	if (bMasterScript)
	{
		GCMasterScript = Self;
	}
	else
	{
		if (GC_EL_MasterScript(MasterScript) != None)
		{
			GCMasterScript = GC_EL_MasterScript(MasterScript);
		}
		else
		{
			Log("ERROR - " $ string(Self) $ " - GCMasterScript could not be set!");
		}
	}
	*/
}

void AGC_EL_MasterScript::CheatSkipToStation(int32 StationNum)
{
	int32 i = 0;
	/*
	local GC_EL_MasterScript OldScript;
	if (!bMasterScript)
	{
		return;
	}
	OldScript = GC_EL_MasterScript(GetActiveScript());
	if ((StationNum >= 0) && (StationNum < 7))
	{
		for (i = 0; i < LevelScriptsList.Length; i++)
		{
			if (i >= (StationNum + 2))
			{
				FSTS_EL_Utilities(LevelScriptsList[i]).bStationComplete = false;
			}
			else
			{
				FSTS_EL_Utilities(LevelScriptsList[i]).bStationComplete = true;
			}
		}
		LevelScriptsList[(StationNum + 2)].Reset();
		SetActiveScript(LevelScriptsList[(StationNum + 2)], OldScript);
		switch (StationNum)
		{
		case 0:
			Player.SetLocation(GetActorByTag("Station0_StartPt").Location);
			Controller.SetRotation(GetActorByTag("Station0_StartPt").Rotation);
			break;
		case 1:
			Player.SetLocation(GetActorByTag("Station1_StartPt").Location);
			Controller.SetRotation(GetActorByTag("Station1_StartPt").Rotation);
			break;
		case 2:
			Player.SetLocation(GetActorByTag("Station2_StartPt").Location);
			Controller.SetRotation(GetActorByTag("Station2_StartPt").Rotation);
			break;
		case 3:
			Player.SetLocation(GetActorByTag("Station3_StartPt").Location);
			Controller.SetRotation(GetActorByTag("Station3_StartPt").Rotation);
			break;
		case 4:
			Player.SetLocation(GetActorByTag("Station4_StartPt").Location);
			Controller.SetRotation(GetActorByTag("Station4_StartPt").Rotation);
			break;
		case 5:
			Player.SetLocation(GetActorByTag("Station5_StartPt").Location);
			Controller.SetRotation(GetActorByTag("Station5_StartPt").Rotation);
			break;
		case 6:
			Player.SetLocation(GetActorByTag("Station6_StartPt").Location);
			Controller.SetRotation(GetActorByTag("Station6_StartPt").Rotation);
			break;
		default:
		}
	}
	*/
}

void AGC_EL_MasterScript::CreateCustomLevelScriptsLinks()
{
	/*
	LiveThrowArea = GC_EL_LiveThrowArea(LevelScriptsList[1]);
	ConfidenceStagingArea = GC_EL_StagingArea(LevelScriptsList[2]);
	Station1 = GC_EL_FightingPositionThrow(LevelScriptsList[3]);
	Station2 = GC_EL_BunkerThrow(LevelScriptsList[4]);
	Station3 = GC_EL_MortarThrow(LevelScriptsList[5]);
	Station4 = GC_EL_ProneThrow(LevelScriptsList[6]);
	Station5 = GC_EL_TrenchThrow(LevelScriptsList[7]);
	Station6 = GC_EL_VehicleThrow(LevelScriptsList[8]);
	*/
}
