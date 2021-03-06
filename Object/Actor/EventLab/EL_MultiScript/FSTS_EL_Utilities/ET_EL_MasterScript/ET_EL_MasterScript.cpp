// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_MasterScript.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_CargoNetDescent/ET_EL_CargoNetDescent.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_LadderClimb/ET_EL_LadderClimb.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_ObstacleArea/ET_EL_ObstacleArea.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_RopeBridges/ET_EL_RopeBridges.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_RopeRappel/ET_EL_RopeRappel.h"

AET_EL_MasterScript::AET_EL_MasterScript()
{
	MissionTitle = "Eagle Tower Confidence Course";
	BadLandingSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JumpTower/Script/BadLanding_Cue.BadLanding_Cue'"), NULL, LOAD_None, NULL);
	DrillSergeantTag = "NPC_DS_DSOY";
	HelpMarkerSmallOffset = FVector(0, 0, 25);
	HelpMarkerLargeOffset = FVector(0, 0, 80);
	NumStationsRequired = 5;
	TrainingName = "Eagle Tower Confidence Course";
	bMasterScript = true;
	LevelScriptsClasses = {
		//AET_EL_ObstacleArea::StaticClass(),
		//AET_EL_RopeBridges::StaticClass(),
		//AET_EL_CargoNetDescent::StaticClass(),
		//AET_EL_LadderClimb::StaticClass(),
		//AET_EL_RopeRappel::StaticClass()
	};
	bUseLevelBeginFadeIn = true;
	LevelBeginFadeInTime = 3.5;
}

/*
simulated State LevelBegin extends MasterActiveExecute
{
	simulated Function BeginState()
	{
		PlayerLock(true,true);
		PlayTip(MissionTitle,"",7);
	}
	simulated Function bool Timer_Timer(FName EventName)
	{
		switch(EventName)
		{
			case "LevelBeginFadeInComplete":
			PlayerLock(true,false);
			SetActiveScript(Station1);
			break;
			case "RestartStation":
			RestartStation();
			break;
			case "RestartLevel":
			RestartLevel();
			break;
			case "Leavenworth":
			Leavenworth();
			break;
			default:
		}
		return true;
	}
}
*/

void AET_EL_MasterScript::EventLabTick(float DeltaTime)
{
	Super::EventLabTick(DeltaTime);
	if (bDormant)
	{
		return;
	}
}

void AET_EL_MasterScript::PostInit()
{
	Super::PostInit();
	if (bMasterScript)
	{
		DoReferenceLinking();
		LinkDrillSergeants();
	}
}

void AET_EL_MasterScript::PostPostInit()
{
	Super::PostPostInit();
	if (bMasterScript)
	{
		//Player->EventLab = this;
		ChangeState("LevelBegin","");
	}
	else
	{
		ChangeState("Dormant", "");
	}
}

void AET_EL_MasterScript::DoReferenceLinking()
{
	


	if (bMasterScript)
	{
		/*
		ForEach AllActors(Class'Actor', SearchActor)
		{
		}
		*/
	}
	Super::DoReferenceLinking();
}

bool AET_EL_MasterScript::Volume_Enter(AVolume* NotifyActor, AActor* aInstigator)
{
	if (!bMasterScript)
	{
		return false;
	}
	/*
	switch (NotifyActor.Tag)
	{
	default:
		return true;
	}
	*/
	return false;   //FAKE   /ELiZ
}

void AET_EL_MasterScript::Reset()
{
	Super::Reset();
	if (bMasterScript)
	{
	}
}

FString AET_EL_MasterScript::GetTrainingMapName()
{
	return "Eagle_Tower.aao";
}

void AET_EL_MasterScript::ELPlayerPressedActionKey()
{
	if (GetActiveScript() != nullptr)
	{
		//GetActiveScript().ELPlayerPressedActionKey();
	}
}

void AET_EL_MasterScript::SetMasterScript()
{
	Super::SetMasterScript();
	/*
	if (bMasterScript)
	{
		ETMasterScript = this;
	}
	else
	{
		if (Cast<AET_EL_MasterScript>(MasterScript) != nullptr)
		{
			ETMasterScript = Cast<AET_EL_MasterScript>(MasterScript);
		}
		else
		{
			Log("ERROR - " + FString::FromInt(this) + " - MasterScript could not be set!", "Eagle_Tower");
		}
	}
	*/
}

void AET_EL_MasterScript::CheatSkipToStation(int32 StationNum)
{
	int32 i = 0;
	AET_EL_MasterScript* OldScript = nullptr;
	if (!bMasterScript)
	{
		return;
	}
	OldScript = Cast<AET_EL_MasterScript>(GetActiveScript());
	/*
	if ((StationNum >= 1) && (StationNum < 6))
	{
		for (i = 1; i < LevelScriptsList.Num(); i++)
		{
			if (i >= StationNum)
			{
				FSTS_EL_Utilities(LevelScriptsList[i]).bStationComplete = false;
			}
			else
			{
				FSTS_EL_Utilities(LevelScriptsList[i]).bStationComplete = true;
			}
			LevelScriptsList[StationNum].Reset();
			SetActiveScript(LevelScriptsList[StationNum], OldScript);
		}
		switch (StationNum)
		{
		case 1:
			Player.SetLocation(GetActorByTag("Station1_Reset").Location);
			Controller.SetRotation(GetActorByTag("Station1_Reset").Rotation);
			break;
		case 2:
			Player.SetLocation(GetActorByTag("Station2_Reset").Location);
			Controller.SetRotation(GetActorByTag("Station2_Reset").Rotation);
			break;
		case 3:
			Player.SetLocation(GetActorByTag("Station3_Reset").Location);
			Controller.SetRotation(GetActorByTag("Station3_Reset").Rotation);
			break;
		case 4:
			Player.SetLocation(GetActorByTag("Station4_Reset").Location);
			Controller.SetRotation(GetActorByTag("Station4_Reset").Rotation);
			break;
		case 5:
			Player.SetLocation(GetActorByTag("Station5_Reset").Location);
			Controller.SetRotation(GetActorByTag("Station5_Reset").Rotation);
			break;
		default:
		}
	}
	*/
}

void AET_EL_MasterScript::PlayKeepMoving()
{
	PlayTip("Keep moving soldier!", "", 2);
}

void AET_EL_MasterScript::CheckPlayerMove()
{
	/*
	if (Player.Location == PlayerLocation)
	{
		if (bHaveNotMoved)
		{
			ConsoleCommand("reconnect");
		}
		else
		{
			bHaveNotMoved = true;
			PlayKeepMoving();
		}
	}
	else
	{
		PlayerLocation = Player.Location;
		bHaveNotMoved = false;
	}
	SetCustomTimer(20, false, "CheckPlayerMove");
	*/
}

void AET_EL_MasterScript::CreateCustomLevelScriptsLinks()
{
	Station1 = Cast<AET_EL_ObstacleArea>(LevelScriptsList[1]);
	Station2 = Cast<AET_EL_RopeBridges>(LevelScriptsList[2]);
	Station3 = Cast<AET_EL_CargoNetDescent>(LevelScriptsList[3]);
	Station4 = Cast<AET_EL_LadderClimb>(LevelScriptsList[4]);
	Station5 = Cast<AET_EL_RopeRappel>(LevelScriptsList[5]);
}

bool AET_EL_MasterScript::Pawn_Died(APawn* NotifyActor, AController* aInstigator)
{
	/*
	if (Player == NotifyActor)
	{
		SetActiveScript(this, GetActiveScript());
		PlaySound(BadLandingSound, 0, 1, , , , false);
		DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_sf", "You have died.", "Level must be restarted to pass.", 128, 128, 7, "None");
		FadeOutBlack(1.5);
	}
	*/
	return true;
}

bool AET_EL_MasterScript::Pawn_Damaged(APawn* NotifyActor, AController* aInstigator)
{
	/*
	if (Player == NotifyActor)
	{
		SetActiveScript(this, GetActiveScript());
		PlaySound(BadLandingSound, 0, 1, , , , false);
		DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_sf", "You have died.", "Level must be restarted to pass.", 128, 128, 7, "None");
		FadeOutBlack(1);
	}
	else
	{
		FadeOutBlack(0.5);
		SetCustomTimer(0.5, false, "Leavenworth");
	}
	*/
	return true;
}

void AET_EL_MasterScript::Suicide(APawn* Killer)
{
	//ConsoleCommand("Reconnect");
}

void AET_EL_MasterScript::FriendlyFire(APawn* HitActor)
{
	//ConsoleCommand("open leavenworth");
}

void AET_EL_MasterScript::RestartLevel()
{
	//ConsoleCommand("Reconnect");
}

void AET_EL_MasterScript::Leavenworth()
{
	//ConsoleCommand("open leavenworth");
}

void AET_EL_MasterScript::RestartStation()
{
	FName CurrentResetActorTag = "";
	AET_EL_MasterScript* CurrentScript = nullptr;
	/*
	CurrentScript = Cast<AET_EL_MasterScript>(GetActiveScript());
	if (CurrentScript != nullptr)
	{
		CurrentResetActorTag = CurrentScript.ResetActorTag;
	}
	FadeInBlack(2);
	StartTimer("FadeInBlack", 2);
	Player.Health = 100;
	Player.SetLocation(GetActorByTag(CurrentResetActorTag).Location);
	Controller.SetRotation(GetActorByTag(CurrentResetActorTag).Rotation);
	*/
}
