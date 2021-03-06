// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_MasterScript.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/AGP_NPC.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/EL_MultiScript.h"
#include "AA29/Object/Actor/Triggers/RandomDispatcher/TargetManager/TargetManager.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_M249RangeStation/WF_EL_M249RangeStation.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_M9RangeStation/WF_EL_M9RangeStation.h"
#include "AA29/Object/Actor/HudOverlay/WF_HudOverlay/WF_HudOverlay.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

AWF_EL_MasterScript::AWF_EL_MasterScript()
{
	MissionTitle = "Weapon Familiarization Training";
	MissionLocation = "Malone Range";
	DrillSergeantTag = "NPC_DS_DSOY";
	HelpMarkerSmallOffset = FVector(0, 0, 25);
	HelpMarkerLargeOffset = FVector(0, 0, 90);
	NumStationsRequired = 3;
	TrainingName = "Weapons Fam Training";
	bMasterScript = true;
	LevelScriptsClasses = {
		//AWF_EL_M9RangeStation::StaticClass()
		//AWF_EL_M249RangeStation::StaticClass()
		//class'FSTS.WF_EL_ExplosiveWeaponsRangeStation'
	};
	GameSounds = {
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/StagingArea/wf_StagingArea_5_Cue.wf_StagingArea_5_Cue'"), NULL, LOAD_None, NULL),"wf_StagingArea_5",0})
	};
	LSAnims = {
		FLSAnim({ "wf_StagingArea_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/StagingArea/wf_StagingArea_1_Cue.wf_StagingArea_1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_StagingArea_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/StagingArea/wf_StagingArea_2_Cue.wf_StagingArea_2_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_StagingArea_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/StagingArea/wf_StagingArea_3_Cue.wf_StagingArea_3_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_StagingArea_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/StagingArea/wf_StagingArea_4_Cue.wf_StagingArea_4_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
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
		SetTimerEvent("InitialPlayerOrientation",0.5,0,false);
		if (bWFMasterIntroHeard)
		{
			PlayTip(MissionLocation + " " + MissionTitle,"You can skip this introduction by pressing <action> if you feel you don't need to hear it.",7);
		}
		else
		{
			PlayTip(MissionLocation,MissionTitle,7);
		}
	}
	simulated Function bool Timer_Timer(FName EventName)
	{
		switch(EventName)
		{
			case "LevelBeginFadeInComplete":
			PlayerLock(true,false);
			PlayLSAnim("wf_StagingArea_1",DrillSergeant);
			break;
			case "InitialPlayerOrientation":
			FacePlayerTo(DrillSergeant,"Neck","CameraBone");
			break;
			case "Station1_FadeIn":
			break;
			default:
		}
		return true;
	}
	Function ELPlayerPressedActionKey()
	{
		if (! bWFMasterIntroHeard)
		{
			return;
		}
		Log("FSTS in state " + FString::FromInt(GetStateName()) + " and DrillSergeant is animating: " + FString::FromInt(DrillSergeant.IsPlayingLIPSincAnim()) + " lipsynch is " + DrillSergeant.CurrentLIPSincAnim());
		if (DrillSergeant.IsPlayingLIPSincAnim())
		{
			if (((DrillSergeant.CurrentLIPSincAnim() ~= "wf_StagingArea_1") || (DrillSergeant.CurrentLIPSincAnim() ~= "wf_StagingArea_2")) || (DrillSergeant.CurrentLIPSincAnim() ~= "wf_StagingArea_3"))
			{
				Log("Shutting down welcome speech animation");
				SetTimerEvent(string(DrillSergeant.CurrentLIPSincAnim()),0.1,3,false);
				DrillSergeant->StopLIPSincAnim();
				bSkipIntro=true;
			}
		}
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(" Timer_LSAnim called for " + FString::FromInt(LSName),"WF_EL_MasterScript");
		switch(LSName)
		{
			case "wf_StagingArea_1":
			if (bSkipIntro)
			{
				SetActiveScript(Station1);
				return true;
			}
			PlayLSAnim("wf_StagingArea_2",DrillSergeant);
			return true;
			case "wf_StagingArea_2":
			if (bSkipIntro)
			{
				SetActiveScript(Station1);
				return true;
			}
			PlayLSAnim("wf_StagingArea_3",DrillSergeant);
			return true;
			case "wf_StagingArea_3":
			bWFMasterIntroHeard=true;
			SaveConfig();
			SetActiveScript(Station1);
			return true;
			case "wf_StagingArea_4":
			case "wf_StagingArea_5":
			return true;
			default:
			return false;
		}
	}
}
*/

void AWF_EL_MasterScript::EventLabTick(float DeltaTime)
{
	/*
	Super::EventLabTick(DeltaTime);
	if (bDormant)
	{
		return;
	}
	*/
}

void AWF_EL_MasterScript::PostInit()
{
	/*
	Super::PostInit();
	Cast<AHumanController>(Player.Controller).Player.Console.ClearMessages();
	DoReferenceLinking();
	if (bMasterScript)
	{
		LinkDrillSergeants();
	}
	*/
}

void AWF_EL_MasterScript::PostPostInit()
{
	/*
	Super::PostPostInit();
	if (bMasterScript)
	{
		Player.EventLab = this;
		QualificationHUDOverlay = Spawn(AWF_HudOverlay::StaticClass());
		QualificationHUDOverlay.TargetManager = nullptr;
		Controller.myHUD.AddHudOverlay(QualificationHUDOverlay);
		ChangeState("LevelBegin");
	}
	else
	{
		ChangeState("Dormant");
	}
	*/
}

AWF_EL_MasterScript* AWF_EL_MasterScript::GetWFActiveScript()
{
	AEL_MultiScript* ActiveScript = nullptr;
	AWF_EL_MasterScript* WF_ActiveScript = nullptr;
	/*
	ActiveScript = GetActiveScript();
	WF_ActiveScript = Cast<AWF_EL_MasterScript>(ActiveScript);
	*/
	return WF_ActiveScript;
}

void AWF_EL_MasterScript::ReloadEvent(AWeapon* ReloadedWeapon)
{
	AWF_EL_MasterScript* ActiveScript = nullptr;
	if (!bMasterScript)
	{
		return;
	}
	//Log("reload event detected", "WF_EL_MasterScript");
	ActiveScript = GetWFActiveScript();
	if (ActiveScript != nullptr)
	{
		ActiveScript->ReloadEvent(ReloadedWeapon);
	}
}

void AWF_EL_MasterScript::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	if (bMasterScript)
	{
		/*
		ForEach AllActors(Class'Actor', SearchActor)
		{
			if (SearchActor.Tag == "Station1_Start")
			{
				Station1_Start = SearchActor;
			}
			if ((SearchActor.Tag == "NPC_Ambient") || (SearchActor.Tag == "AGP_NPC"))
			{
				SearchActor.SetEventLab(this);
			}
			if (SearchActor.Tag == DrillSergeantTag)
			{
				DrillSergeant = FSTS_NPC_DrillSergeant(SearchActor);
			}
		}
		*/
	}
	if ((StationTargetManagerTag != "None") && (StationTargetManagerTag != "None"))
	{
		//StationTargetManager = Cast<ATargetManager>(GetActorByTag(StationTargetManagerTag));
		//StationTargetManager->EventLab = this;
	}
	Super::DoReferenceLinking();
}

void AWF_EL_MasterScript::CheatSkipToStation(int32 StationNum)
{
	int32 i = 0;
	AWF_EL_MasterScript* OldScript = nullptr;
	if (!bMasterScript)
	{
		return;
	}
	/*
	OldScript = Cast<AWF_EL_MasterScript>(GetActiveScript());
	if ((StationNum >= 1) && (StationNum < LevelScriptsList.Num()))
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
		}
		LevelScriptsList[StationNum].Reset();
		SetActiveScript(LevelScriptsList[StationNum], OldScript);
		switch (StationNum)
		{
		case 1:
			Player.SetLocation(GetActorByTag("Station1_Start").Location);
			Controller.SetRotation(GetActorByTag("Station1_Start").Rotation);
			break;
		case 2:
			Player.SetLocation(GetActorByTag("Station2_Start").Location);
			Controller.SetRotation(GetActorByTag("Station2_Start").Rotation);
			break;
		case 3:
			Player.SetLocation(GetActorByTag("Station3_Start").Location);
			Controller.SetRotation(GetActorByTag("Station3_Start").Rotation);
			break;
		default:
			Log("bad skiptostation index", "WF_EL_MasterScript");
			break;
		}
	}
	*/
}

void AWF_EL_MasterScript::Reset()
{
	/*
	Super::Reset();
	ForcePlayerProne(false);
	Player.SetZoomed(false);
	bNoGoRestart = false;
	if (bMasterScript)
	{
	}
	*/
}

bool AWF_EL_MasterScript::AGP_NPC_Damaged(AAGP_NPC* NotifyActor, AController* aInstigator)
{
	//FriendlyFire(NotifyActor);
	return true;
}

bool AWF_EL_MasterScript::Pawn_Damaged(APawn* NotifyActor, AController* aInstigator)
{
	//FriendlyFire(NotifyActor);
	return true;
}

void AWF_EL_MasterScript::FriendlyFire(APawn* HitActor)
{
	/*
	if (bFriendlyFireFailure)
	{
		return;
	}
	bFriendlyFireFailure = true;
	StopHelpTimer();
	PlayGameSound("wf_StagingArea_5", Player);
	ConsoleCommand("open Leavenworth");
	*/
}

FString AWF_EL_MasterScript::GetTrainingMapName()
{
	return "Weapons_Fam.aao";
}

void AWF_EL_MasterScript::SetMasterScript()
{
	/*
	Super::SetMasterScript();
	if (bMasterScript)
	{
		WFMasterScript = this;
	}
	else
	{
		if (Cast<AWF_EL_MasterScript>(MasterScript) != nullptr)
		{
			WFMasterScript = Cast<AWF_EL_MasterScript>(MasterScript);
		}
		else
		{
			Log("ERROR!  WFMasterScript could not be set!", "WF_EL_MasterScript");
		}
	}
	*/
}

void AWF_EL_MasterScript::CreateCustomLevelScriptsLinks()
{
	/*
	Station1 = WF_EL_M9RangeStation(LevelScriptsList[1]);
	Station2 = WF_EL_M249RangeStation(LevelScriptsList[2]);
	Station3 = WF_EL_ExplosiveWeaponsRangeStation(LevelScriptsList[3]);
	*/
}

void AWF_EL_MasterScript::ELPlayerPressedActionKey()
{
	/*
	if ((GetActiveScript() != nullptr) && (GetActiveScript() != Self))
	{
		GetActiveScript().ELPlayerPressedActionKey();
	}
	*/
}

void AWF_EL_MasterScript::ELPlayerPressedFireNotifier()
{
	/*
	if ((GetActiveScript() != nullptr) && (GetActiveScript() != Self))
	{
		GetActiveScript().ELPlayerPressedFireNotifier();
	}
	*/
}
