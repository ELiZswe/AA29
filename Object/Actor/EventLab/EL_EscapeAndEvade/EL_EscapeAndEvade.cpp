// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_EscapeAndEvade/EL_EscapeAndEvade.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/AGP_NPC.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/Keypoint/Marker/CameraPoint/CameraPoint.h"
#include "AA29/Object/Actor/AAGameplay/EEBlackHawk/EEBlackHawk.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Keypoint/Marker/NoiseMarker/NoiseMarker.h"
#include "AA29/Object/Actor/Info/SceneManager/SceneManager.h"
#include "AA29/Object/Actor/Info/Security/Security.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

AEL_EscapeAndEvade::AEL_EscapeAndEvade()
{
	SoundMarkers.SetNum(8);
	BlueforHearSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_CheckYourFlanks_Cue.Voice1_Shout_CheckYourFlanks_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_CoverMe_Cue.Voice1_Shout_CoverMe_Cue'"), NULL, LOAD_None, NULL)
	};
	
	BlueforSeeSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_CoverMe_Cue.Voice1_Shout_CoverMe_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_TakeCover_Cue.Voice1_Shout_TakeCover_Cue'"), NULL, LOAD_None, NULL)
	};
	
	BlueforFalseSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Negative_Cue.Voice1_Shout_Negative_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_AreaSecure_Cue.Voice1_Shout_AreaSecure_Cue'"), NULL, LOAD_None, NULL)
	};
	
	BlueforBustedSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_EnemySpotted_Cue.Voice1_Shout_EnemySpotted_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_EnemyDown_Cue.Voice1_Shout_EnemyDown_Cue'"), NULL, LOAD_None, NULL)
	};
	
	OpforHearSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_CheckYourFlanks_Cue.Voice3_Shout_CheckYourFlanks_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_CoverMe_Cue.Voice3_Shout_CoverMe_Cue'"), NULL, LOAD_None, NULL)
	};
	
	OpforSeeSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_CoverMe_Cue.Voice3_Shout_CoverMe_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover_Cue.Voice3_Shout_TakeCover_Cue'"), NULL, LOAD_None, NULL)
	};
	
	OpforFalseSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Negative_Cue.Voice3_Shout_Negative_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_AreaSecure_Cue.Voice3_Shout_AreaSecure_Cue'"), NULL, LOAD_None, NULL)
	};
	
	OpforBustedSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_EnemySpotted_Cue.Voice3_Shout_EnemySpotted_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_EnemyDown_Cue.Voice3_Shout_EnemyDown_Cue'"), NULL, LOAD_None, NULL)
	};
	AlertLanguage = EAlertLanguage::LANG_Opfor;
	bUseDeathCameras = true;
	VolumeRisk = 1;
	PlayerPosture = EPlayerPosture::P_Standing;
	
	CommonAmbient = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Insects/Cricket_Short01_Cue.Cricket_Short01_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Insects/Cricket_Short01_Cue.Cricket_Short01_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Insects/Cricket_Short01_Cue.Cricket_Short01_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Insects/Cricket_Short01_Cue.Cricket_Short01_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Insects/Cricket_Short01_Cue.Cricket_Short01_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Insects/Cricket_Short01_Cue.Cricket_Short01_Cue'"), NULL, LOAD_None, NULL)
	};
	
	RareAmbient = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Animals/frog1_Cue.frog1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Animals/frog2_Cue.frog2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Animals/owl1_Cue.owl1_Cue'"), NULL, LOAD_None, NULL)
	};
	
	DogAmbient = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Animals/dog3_Cue.dog3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Animals/dog4_Cue.dog4_Cue'"), NULL, LOAD_None, NULL)
	};
	
	PlayerBones = {
		FBoneProfile({"head","Goggles1"}),
		FBoneProfile({ "Chest","RuckSack" }),
		FBoneProfile({ "ShoulderRight","RArmUp" }),
		FBoneProfile({ "ShoulderLeft","LArmUp" }),
		FBoneProfile({ "Abdomen","ButtPouch" }),
		FBoneProfile({ "Pelvis","Pelvis" }),
		FBoneProfile({ "KneeRight","RLegLow" }),
		FBoneProfile({ "KneeLeft","LLegLow" })
	};
	LastLocationTag = "L_PostInsertion";
	StartLocationTag = "L_PostInsertion";

	LSAnims = {
		FLSAnim({"01_ThirtySeconds",    LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_EandE/Insertion/01_ThirtySeconds_Cue.01_ThirtySeconds_Cue'"), NULL, LOAD_None, NULL),     {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "02_SlowAndLow",      LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_EandE/Insertion/02_SlowAndLow_Cue.02_SlowAndLow_Cue'"), NULL, LOAD_None, NULL),           {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "03_CrouchOrCrawl",   LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_EandE/Insertion/03_CrouchOrCrawl_Cue.03_CrouchOrCrawl_Cue'"), NULL, LOAD_None, NULL),     {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "04_ThreeObjectives", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_EandE/Insertion/04_ThreeObjectives_Cue.04_ThreeObjectives_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "05_MoveOut",         LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_EandE/Insertion/05_MoveOut_Cue.05_MoveOut_Cue'"), NULL, LOAD_None, NULL),                 {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "06_GoGoGo",          LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_EandE/Insertion/06_GoGoGo_Cue.06_GoGoGo_Cue'"), NULL, LOAD_None, NULL),                   {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0 } })
	};

}

/*
State PreInsertion
{
Begin:
	if (LastLocationTag == StartLocationTag)
	{
		ChangeState("Insertion");
	}
	else
	{
		Player.SetLocation(GetActorLocation(LastLocationTag));
		switch(LastLocationTag)
		{
			case "CheckpointA":
			PlayTip("You have been reset to Objective A","",5);
			StartClock();
			break;
			case "CheckpointB":
			PlayTip("You have been reset to Objective B","",5);
			StartClock();
			break;
			default:
		}
		ChangeState("PreEvade");
	}
}
*/

/*
State Insertion
{
	Function BeginState()
	{
		blackhawk.ResetAnims();
		ClearClock();
		DisableGuards();
		DisableAmbient();
		DisableHUD();
		PlayerLock(false,false);
		Controller.Crouch();
		PlayerLock(true,true);
		HidePlayer();
		GiveBinocs(Player,0);
		blackhawk.SetLocation(GetActorLocation("IP_Insertion"));
		blackhawk.SetRotation(GetActorRotation("IP_Insertion"));
		blackhawk.SetChopperSound("Interior");
		blackhawk.TurnOffLandingLights();
		CheckpointA.SetDisabled(false);
		CheckpointB.SetDisabled(true);
		CheckpointC.SetDisabled(true);
	}
	Function EventLabTick(float DeltaTime)
	{
		blackhawk.ViewMarker.SetRotation((blackhawk.PlayerView.Rotation + Player.GetViewRotation()));
	}
	Function bool Timer_Timer(FName Name)
	{
		return Global.Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		return true;
	}
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		blackhawk.LoopAnim("Idle");
	}
Begin:
	if (bSkipIntro && (! bStartAtEnd))
	{
		FadeIn(1,true);
		SetFOV(85);
		EnableHUD();
		PlayerLock(false,false);
		ChangeState("Dustoff");
		JL"End"
;
	}
	if (bStartAtEnd)
	{
		Player.SetLocation(GetActorLocation("LocExtraction"));
		Player.SetRotation(GetActorRotation("LocExtraction"));
		CheckpointC.SetDisabled(false);
		FadeIn(1,true);
		ChangeState("PreEvade");
		JL"End"
;
	}
	if (ViewedCinematicCount > 1)
	{
		FadeOut(2,true);
		StartClock();
		Player.SetLocation(GetActorLocation("L_PostInsertion"));
		Controller.SetRotation(GetActorRotation("L_PostInsertion"));
		ChangeState("PreEvade");
		JL"End"
;
	}
	ViewedCinematicCount ++;
	FadeOut(0,true);
	Sleep(1);
	StartScene("Insertion");
	blackhawk.SetChopperSound("exterior");
	FadeIn(5,true);
	DisableHUD();
	Cam01.SetActive(true);
	Log("EVENTLAB CUEING CAM01");
	CueCamera(Cam01);
	SetFOV(25);
	Sleep(9);
	Cam01.SetActive(false);
	Controller.SetRotation(blackhawk.Rotation);
	CueCamera(blackhawk.ViewMarker);
	blackhawk.SetChopperSound("Interior");
	SetFOV(85);
	PlayerLock(true,false);
	blackhawk.Crew[2].PlayLIPSincAnim("01_ThirtySeconds",1,128,1);
	Sleep(4);
	blackhawk.Crew[2].PlayLIPSincAnim("02_SlowAndLow_Short",1,128,1);
	Sleep(8);
	CueCamera(blackhawk.ChaseCamB);
	blackhawk.SetChopperSound("Exterior2");
	SetFOV(45);
	DisableHUD();
	Sleep(2.5);
	Cam02.SetActive(true);
	CueCamera(Cam02);
	blackhawk.SetChopperSound("exterior");
	SetFOV(45);
	DisableHUD();
	Sleep(6);
	Cam02.SetActive(false);
	Controller.SetRotation(blackhawk.Rotation);
	CueCamera(blackhawk.ViewMarker);
	blackhawk.SetChopperSound("Interior");
	SetFOV(85);
	blackhawk.Crew[2].PlayLIPSincAnim("03_CrouchOrCrawl",1,128,1);
	Sleep(9);
	Cam03.SetActive(true);
	CueCamera(Cam03);
	blackhawk.SetChopperSound("exterior");
	SetFOV(45);
	DisableHUD();
	Sleep(1);
	blackhawk.TurnOnLandingLights();
	Sleep(4);
	Cam03.SetActive(false);
	Controller.SetRotation((blackhawk.Rotation + FRotator(0,-16384,0)));
	CueCamera(blackhawk.ViewMarker);
	blackhawk.SetChopperSound("Interior");
	SetFOV(85);
	blackhawk.Crew[2].PlayLIPSincAnim("04_ThreeObjectives",1,128,1);
	Sleep(14);
	blackhawk.Crew[2].PlayLIPSincAnim("05_MoveOut",1,128,1);
	Sleep(2);
	ChangeState("Dustoff");
}
*/

/*
State Dustoff
{
	Function BeginState()
	{
		StartClock();
		Player.SetLocation(GetActorLocation("L_PostInsertion"));
		Controller.SetRotation(GetActorRotation("L_PostInsertion"));
		PlayerLock(false,false);
		Controller.Crouch();
		ShowPlayer();
		GiveBinocs(Player,2);
		CuePlayer();
		EnableHUD();
		SetFOV(85);
		blackhawk.SetChopperSound("Exterior2");
		StartTimer("DoDustOff",0.5);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "DoDustOff")
		{
			StartScene("Dustoff");
			return true;
		}
		return false;
	}
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		blackhawk.TurnOffLandingLights();
	}
	Function bool SceneManager_SceneEnd(ASceneManager* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (NotifyActor.Tag == "Dustoff")
		{
			ChangeState("PreEvade");
			return true;
		}
	}
}
*/

/*
State PreEvade
{
	Function BeginState()
	{
		ResetGuards();
		ResetScript();
		EnableAmbient();
		ShowPlayer();
		CuePlayer();
		EnableHUD();
		RestoreFOV();
		PlayerLock(false,false);
		GiveBinocs(Player,2);
		blackhawk.SetChopperSound("None");
		FadeIn(2,true);
	}
Begin:
	ChangeState("Evade");
}
*/

/*
State Evade
{
	Function BeginState()
	{
		StartTimer("PlayAmbient",0.2,true);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "PlayAmbient")
		{
			if (! bDisableAmbient)
			{
				PlayAmbientSounds();
			}
		}
		return Global.Timer_Timer(Name);
	}
	Function bool NoiseTrigger_Trigger(AGP_Gameplay.NoiseTrigger* NotifyActor, AActor* Instigator, FString Parms)
	{
		ParseParms(Parms);
		if (ParmList[0] == "EXTNOISE")
		{
			SendNoise(NotifyActor,float(ParmList[1]));
			return true;
		}
	}
	Function bool RiskVolume_Enter(AGP_Gameplay.RiskVolume* NotifyActor, AActor* Instigator, FString Parms)
	{
		ParseParms(Parms);
		if (ParmList[0] == "RISK")
		{
			VolumeRisk=float(ParmList[1]);
			return true;
		}
	}
	Function bool RiskVolume_Exit(AGP_Gameplay.RiskVolume* NotifyActor, AActor* Instigator, FString Parms)
	{
		return RiskVolume_Enter(NotifyActor,Instigator,Parms);
	}
	Function bool AGP_Character_Custom(AGP_Characters.AGP_Character* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (! NotifyActor.Controller->IsA(AHumanController::StaticClass()))
		{
			return false;
		}
		ParseParms(Parms);
		if (ParmList[0] == "SLOWMODE")
		{
			GOTO JL00D0;
		}
		if (ParmList[0] == "SPRINTMODE")
		{
			GOTO JL00D0;
		}
		if (ParmList[0] == "CROUCHMODE")
		{
			if (bool(ParmList[1]))
			{
				PlayerPosture=1;
			}
			else
			{
				PlayerPosture=2;
			}
		}
		else
		{
			if (ParmList[0] == "PRONEMODE")
			{
				if (bool(ParmList[1]))
				{
					PlayerPosture=0;
				}
				else
				{
					PlayerPosture=2;
JL00D0:
				}
			}
		}
		return true;
	}
	Function SendNoise(AActor* Instigator, float Loudness)
	{
		int32 i = 0;
		for (i=0; i<Guards.Num(); i++)
		{
			if (Guards[i] == nullptr)
			{
			}
			if (VSize((Instigator.Location - Guards[i].Location)) < float(4096))
			{
				if (bDebug)
				{
					Log("EL_EscapeAndEvade::SendNoise(): Noise Sent at loudness: " + FString::FromInt(Loudness));
				}
				Guards[i].ExtMakeNoise(Instigator,Loudness);
			}
		}
	}
	Function PlayAmbientSounds()
	{
		float RandNum = 0;
		RandNum=FMath::FRand();
		if (RandNum >= 0.9)
		{
			if (PlayerStealth > 0.6)
			{
				GetRandomMarker().PlaySound(GetCommonSound(),,(0.05 * PlayerStealth),false,128);
			}
		}
		if (RandNum >= 0.9)
		{
			if (PlayerStealth < 0.4)
			{
				GetRandomMarker().PlaySound(GetDogSound(),,(0.25 * (1 - PlayerStealth)),false,1024);
			}
		}
		if (RandNum >= 0.98)
		{
			if (PlayerStealth > 0.4)
			{
				GetRandomMarker().PlaySound(GetRareSound(),,0.1,false,256);
			}
		}
	}
	Function bool NPC_EEGuard_Custom(AGP_Characters.NPC_EEGuard* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (bDisableGuardScript)
		{
			return true;
		}
		ParseParms(Parms);
		switch(ParmList[0])
		{
			case "PLAYERSPOTTED":
			if (bDebug)
			{
				Log("PLAYER SPOTTED");
			}
			PlayerSpotted(NotifyActor);
			return true;
			case "HEARSOMETHING":
			if (bDebug)
			{
				Log("HEAR SOMETHING");
			}
			HearSomething(NotifyActor);
			return true;
			case "SEESOMETHING":
			if (bDebug)
			{
				Log("SEE SOMETHING");
			}
			SeeSomething(NotifyActor);
			return true;
			case "FALSEALARM":
			if (bDebug)
			{
				Log("FALSE ALARM");
			}
			FalseAlarm(NotifyActor);
			return true;
			default:
			return false;
		}
	}
	Function int32 GetReqVisBones()
	{
		return 2;
	}
	Function bool CanSeePlayer(AActor* Camera)
	{
		int32 i = 0;
		int32 NumVisible = 0;
		int32 ReqVisible = 0;
		bool bVisible = false;
		FVector BonePos = FVector(0,0,0);
		ReqVisible=GetReqVisBones();
		for (i=0; i<PlayerBones.Num(); i++)
		{
			BonePos=Player.GetBoneCoords(PlayerBones[i].BoneName).Origin;
			bVisible=FastTrace(BonePos,Camera.Location);
			if (bVisible)
			{
				NumVisible ++;
			}
			if (NumVisible >= ReqVisible)
			{
			}
		}
		return (NumVisible >= ReqVisible);
	}
	Function PlayerSpotted(AGP_Characters.NPC_EEGuard* Guard)
	{
		Player.PutAwayHandItem();
		PlayTip("You've been spotted!","Resetting to last completed objective...",5);
		PlayerLock(true,true);
		if ((bUseDeathCameras && (Guard.DeathCamera != nullptr)) && CanSeePlayer(Guard.DeathCamera))
		{
			CameraPoint(Guard.DeathCamera).SetActive(true);
			CueCamera(Guard.DeathCamera);
			DisableHUD();
			StartFOV=110;
			EndFOV=15;
			FOVTweenTime=1.2;
			SetFOV(StartFOV);
			StartTimer("StartZoom",3);
		}
		Guard.PlaySound(BustedSounds[Rand(2)],0,1,,512);
		ChangeState("STATE_PlayerSpotted");
	}
	Function HearSomething(AGP_Characters.NPC_EEGuard* Guard)
	{
		Guard.PlaySound(HearSounds[Rand(2)],0,1,,512);
	}
	Function SeeSomething(AGP_Characters.NPC_EEGuard* Guard)
	{
		Guard.PlaySound(SeeSounds[Rand(2)],0,1,,512);
	}
	Function FalseAlarm(AGP_Characters.NPC_EEGuard* Guard)
	{
		Guard.PlaySound(FalseSounds[Rand(2)],0,10,,2048);
	}
	Function bool AGP_Objective_Trigger(AAGP_Objective* NotifyActor, AActor* Instigator)
	{
		if (NotifyActor.Tag == "CheckpointA")
		{
			CheckpointA.SetDisabled(true);
			CheckpointB.SetDisabled(false);
			LastLocationTag=CheckpointA.Tag;
			PlayTip("You have reached Objective A","",5);
			return true;
		}
		if (NotifyActor.Tag == "CheckpointB")
		{
			CheckpointB.SetDisabled(true);
			CheckpointC.SetDisabled(false);
			LastLocationTag=CheckpointB.Tag;
			PlayTip("You have reached Objective B","",5);
			return true;
		}
		if (NotifyActor.Tag == "CheckpointC")
		{
			CheckpointC.SetDisabled(true);
			PlayTip("You have reached Objective C","",5);
			ChangeState("Signal");
			return true;
		}
	}
Begin:
	if (LastLocationTag == StartLocationTag)
	{
		PlayTip("Head for Objective A","Stay low and move slow to avoid being detected",5);
		Sleep(7);
	}
	PlayTip("Use your <FastMove> key","to control your movement speed",5);
	Sleep(7);
	PlayTip("If you think you might have been detected,","use your <crawling> key to go prone, and stay still for several seconds",8);
}
*/

/*
State STATE_PlayerSpotted
{
	Function BeginState()
	{
	}
	Function EndState()
	{
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "StartZoom")
		{
			StartZoom();
		}
		return Global.Timer_Timer(Name);
	}
	Function StartZoom()
	{
		ZoomFOV(StartFOV,EndFOV,FOVTweenTime);
	}
Begin:
	DisableGuards();
	Sleep(5);
	ChangeState("PreInsertion");
}
*/

/*
State Signal
{
	Function bool AGP_UseTrigger_UsedBy(AAGP_UseTrigger* NotifyActor, AActor* Instigator)
	{
		MissionTime=GetClockTime();
		ClearClock();
		ChangeState("Extraction");
		return Global.agpdoCurrentTarget(NotifyActor,Instigator);
	}
Begin:
	Sleep(7);
	PlayTip("Use the truck to signal for extraction","",5);
}
*/

/*
State Extraction
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
	}
	Function UpdateCompletionFields()
	{
		ASecurity* secLocalSecurity = nullptr;
		ASecurity* scLocalSecurityClass = nullptr;
		TArray<FString> asMD5ForMap = {};
		TArray<FString> asMD5ForScript = {};
		FString sMD5ForMap = "";
		FString sMD5ForScript = "";
		scLocalSecurityClass=class<Security>(DynamicLoadObject("Engine.Security",Class'Class'));
		if (scLocalSecurityClass != nullptr)
		{
			secLocalSecurity=Spawn(scLocalSecurityClass,Controller);
			if (secLocalSecurity != nullptr)
			{
				secLocalSecurity.LocalPerform(2,"../Maps/eande.aao","",asMD5ForMap);
				secLocalSecurity.LocalPerform(2,"../System/AGP_Script.u","",asMD5ForScript);
				sMD5ForMap=asMD5ForMap[0];
				sMD5ForScript=asMD5ForScript[0];
			}
		}
		Controller.AddAuthExtraMissionData(sMD5ForMap);
		Controller.AddAuthExtraMissionData(sMD5ForScript);
	}
Begin:
	TriggerEvent("Headlights",Self,Player);
	Sleep(1);
	TriggerEvent("Headlights",Self,Player);
	Sleep(1);
	TriggerEvent("Headlights",Self,Player);
	Sleep(1);
	TriggerEvent("Headlights",Self,Player);
	Sleep(1);
	Cam04.SetActive(true);
	CueCamera(Cam04);
	SetFOV(65);
	DisableHUD();
	PlayerLock(true,true);
	TriggerEvent("Headlights",Self,Player);
	Sleep(1);
	TriggerEvent("Headlights",Self,Player);
	Sleep(1);
	TriggerEvent("Headlights",Self,Player);
	Sleep(1);
	TriggerEvent("Headlights",Self,Player);
	Sleep(1);
	Cam04.SetActive(false);
	Cam05.SetActive(true);
	CueCamera(Cam05);
	SetFOV(20);
	DisableHUD();
	blackhawk.SetChopperSound("exterior");
	Scout.LoopAnim("StdBinocsUp",1,0.5);
	StartScene("Extraction");
	Sleep(1);
	Scout.LoopAnim("StdBinocsDn",1,0.5);
	Sleep(1.5);
	blackhawk.TurnOnLandingLights();
	Sleep(3);
	Cam05.SetActive(false);
	PlayerLock(false,false);
	EnableHUD();
	CuePlayer();
	SetFOV(85);
	Sleep(7);
	Cast<AStudentController>(Controller)->ResetAuthExtraMissionData();
	Cast<AStudentController>(Controller)->AddAuthExtraMissionData(GetClockTime());
	UpdateCompletionFields();
	if (Cast<AStudentController>(Controller)->IsCheating())
	{
		Cast<AStudentController>(Controller)->SetAuthMissionPassFlag(false);
		DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_SF","Cheats Detected!","Your time is: " + MissionTime,128,128,7,"None");
	}
	else
	{
		Cast<AStudentController>(Controller)->SetAuthMissionPassFlag(true);
		DisplayMissionSuccess("T_AA2_UI.tour_icons.hud_menu_touricon_SF","Congratulations! ","Your time is: " + MissionTime,128,128,7,"None");
	}
}
*/

void AEL_EscapeAndEvade::PreInit()
{
	/*
	MusicTrigger = Cast<AAGP_UseTrigger>(CaptureEvent('MusicTrigger'));
	MusicTrigger.HUDText = "Turn Music On";
	CaptureEventGroup('NoiseTrigger');
	CaptureEventGroup('RiskVolume');
	blackhawk = EEBlackHawk(GetActorByTag('blackhawk'));
	TruckUse = Cast<AAGP_UseTrigger>(CaptureEvent('TruckUse'));
	CheckpointA = Cast<AAGP_Objective>(CaptureEvent('CheckpointA'));
	CheckpointB = Cast<AAGP_Objective>(CaptureEvent('CheckpointB'));
	CheckpointC = Cast<AAGP_Objective>(CaptureEvent('CheckpointC'));
	Scout = AGP_NPC(GetActorByTag('Scout'));
	Cam01 = Cast<ACameraPoint>(GetActorByTag('Cam01'));
	Cam02 = Cast<ACameraPoint>(GetActorByTag('Cam02'));
	Cam03 = Cast<ACameraPoint>(GetActorByTag('Cam03'));
	Cam04 = Cast<ACameraPoint>(GetActorByTag('Cam04'));
	Cam05 = Cast<ACameraPoint>(GetActorByTag('Cam05'));
	Cam06 = Cast<ACameraPoint>(GetActorByTag('Cam06'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard00'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard01'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard02'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard03'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard04'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard05'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard06'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard07'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard08'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard09'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard10'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard11'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard12'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard13'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard14'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard15'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard16'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard17'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard18'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard19'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard20'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard21'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard22'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard23'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard24'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard25'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard26'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard27'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard28'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard29'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard30'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard31'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard32'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard33'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard34'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard35'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard36'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard37'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard38'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard39'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard40'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard41'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard42'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard43'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard44'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard45'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard46'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard47'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard48'));
	Guards[Guards.Num()] = NPC_EEGuard(CaptureEvent('Guard49'));
	*/
}

void AEL_EscapeAndEvade::Init()
{
	InitLanguage();
	InitVelocityArray();
	CreateSoundMarkers();
}

void AEL_EscapeAndEvade::PostInit()
{
}

void AEL_EscapeAndEvade::PostPostInit()
{
	/*
	ReCaptureEvent(Player);
	ChangeState('PreInsertion');
	*/
}

bool AEL_EscapeAndEvade::LevelInfo_FirstDraw(ALevelInfo* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	Log("EL_EscapeAndEvade::LevelInfo_FirstDraw()");
	ChangeState('PreInsertion');
	*/
	return true;
}

void AEL_EscapeAndEvade::InitLanguage()
{
	int32 i = 0;
	/*
	switch (AlertLanguage)
	{
	case 1:
		i = 0;
		if (i < OpforHearSounds.Num())
		{
			HearSounds[i] = OpforHearSounds[i];
			i++;
			break;
		}
		for (i = 0; i < OpforSeeSounds.Num(); i++)
		{
			SeeSounds[i] = OpforSeeSounds[i];
		}
		for (i = 0; i < OpforFalseSounds.Num(); i++)
		{
			FalseSounds[i] = OpforFalseSounds[i];
		}
		for (i = 0; i < OpforBustedSounds.Num(); i++)
		{
			BustedSounds[i] = OpforBustedSounds[i];
		}
		GOTO JL01DA;
	case 0:
		for (i = 0; i < BlueforHearSounds.Num(); i++)
		{
			HearSounds[i] = BlueforHearSounds[i];
		}
		for (i = 0; i < BlueforSeeSounds.Num(); i++)
		{
			SeeSounds[i] = BlueforSeeSounds[i];
		}
		for (i = 0; i < BlueforFalseSounds.Num(); i++)
		{
			FalseSounds[i] = BlueforFalseSounds[i];
		}
		for (i = 0; i < BlueforBustedSounds.Num(); i++)
		{
			BustedSounds[i] = BlueforBustedSounds[i];
		}
		GOTO JL01DA;
	default:
	JL01DA:
	}
	*/
}

void AEL_EscapeAndEvade::InitVelocityArray()
{
	int32 i = 0;
	/*
	for (i = 0; i < 8; i++)
	{
		PlayerVelocities[i] = 0;
	}
	AvgVelOldTime = 0.1;
	*/
}

void AEL_EscapeAndEvade::DisableGuards()
{
	int32 i = 0;
	/*
	for (i = 0; i < Guards.Num(); i++)
	{
		if (Guards[i] != nullptr)
		{
			Guards[i].DisableMe();
		}
	}
	*/
}

void AEL_EscapeAndEvade::ResetGuards()
{
	/*
	int32 i = 0;
	for (i = 0; i < Guards.Num(); i++)
	{
		if (Guards[i] != nullptr)
		{
			Guards[i].ResetMe();
		}
	}
	*/
}

void AEL_EscapeAndEvade::ResetScript()
{
	VolumeRisk = 1;
}

void AEL_EscapeAndEvade::EventLabTick(float DeltaTime)
{
	int32 i = 0;
	/*
	PlayerVelocity = VSize(Player.Velocity);
	PlayerVisibility = GetPlayerVisibility();
	PlayerAudibility = GetPlayerAudibility();
	PlayerStealth = GetStealth();
	UpdateVelocityAverage();
	for (i = 0; i < Guards.Num(); i++)
	{
		if (Guards[i] != nullptr)
		{
			Guards[i].PlayerVisibility = PlayerVisibility;
			Guards[i].PlayerAudibility = PlayerAudibility;
		}
	}
	UpdateSoundMarkers();
	*/
}

void AEL_EscapeAndEvade::PlayAmbientSounds()
{
}

void AEL_EscapeAndEvade::DisableAmbient()
{
	bDisableAmbient = true;
}

void AEL_EscapeAndEvade::EnableAmbient()
{
	bDisableAmbient = false;
}

ANoiseMarker* AEL_EscapeAndEvade::GetRandomMarker()
{
	ANoiseMarker* NewMarker=nullptr;
	ANoiseMarker* myMarker=nullptr;
	/*
	myMarker = SoundMarkers[Rand(8)];
	NewMarker = Spawn(Class'ANoiseMarker*', , , myMarker.Location);
	NewMarker.SetDestroyTimer(5);
	*/
	return NewMarker;
}

float AEL_EscapeAndEvade::GetStealth()
{
	/*
	float MyStealth = 0;
	MyStealth = (VolumeRisk * (((AverageVelocity / float(100)) + GetPostureRiskVisual()) / 2));
	MyStealth = (MyStealth / 2.5);
	return (1 -FMath::Clamp(MyStealth, 0, 1));
	*/
	return 0;    //FAKE   /ELiZ
}

USoundBase* AEL_EscapeAndEvade::GetRareSound()
{
	//return RareAmbient[Rand(RareAmbient.Num())];
	return nullptr;    //FAKE   /ELiZ
}

USoundBase* AEL_EscapeAndEvade::GetCommonSound()
{
	//return CommonAmbient[Rand(CommonAmbient.Num())];
	return nullptr;    //FAKE   /ELiZ
}

USoundBase* AEL_EscapeAndEvade::GetDogSound()
{
	//return DogAmbient[Rand(DogAmbient.Num())];
	return nullptr;    //FAKE   /ELiZ
}

void AEL_EscapeAndEvade::UpdateVelocityAverage()
{
	/*
	if ((GetWorld()->GetTimeSeconds() - AvgVelOldTime) >= 0.1)
	{
		PlayerVelocities[AvgVelCounter] = PlayerVelocity;
		AverageVelocity = AveragePlayerVelocities();
		AvgVelOldTime = GetWorld()->GetTimeSeconds();
		AvgVelCounter++;
		if (AvgVelCounter == PlayerVelocities.Num())
		{
			AvgVelCounter = 0;
		}
	}
	*/
}

float AEL_EscapeAndEvade::AveragePlayerVelocities()
{
	float Avg = 0;
	for (const auto& i : PlayerVelocities)
	{
		Avg += i;
	}
	return (Avg / PlayerVelocities.Num());
}

void AEL_EscapeAndEvade::CreateSoundMarkers()
{
	int32 i = 0;
	/*
	for (i = 0; i < 8; i++)
	{
		SoundMarkers[i] = Spawn(Class'ANoiseMarker*', Player);
	}
	*/
}

void AEL_EscapeAndEvade::UpdateSoundMarkers()
{
	/*
	FVector loc = FVector(0, 0, 0);
	loc = Player.Location;
	SoundMarkers[0].SetLocation(FVector((loc.X + float(256)), loc.Y, loc.Z));
	SoundMarkers[1].SetLocation(FVector((loc.X - float(256)), loc.Y, loc.Z));
	SoundMarkers[2].SetLocation(FVector(loc.X, (loc.Y + float(256)), loc.Z));
	SoundMarkers[3].SetLocation(FVector(loc.X, (loc.Y - float(256)), loc.Z));
	SoundMarkers[4].SetLocation(FVector((loc.X + (float(256) * 0.75)), (loc.Y + (float(256) * 0.75)), loc.Z));
	SoundMarkers[5].SetLocation(FVector((loc.X + (float(256) * 0.75)), (loc.Y - (float(256) * 0.75)), loc.Z));
	SoundMarkers[6].SetLocation(FVector((loc.X - (float(256) * 0.75)), (loc.Y + (float(256) * 0.75)), loc.Z));
	SoundMarkers[7].SetLocation(FVector((loc.X - (float(256) * 0.75)), (loc.Y - (float(256) * 0.75)), loc.Z));
	*/
}

bool AEL_EscapeAndEvade::AGP_UseTrigger_UsedBy(AAGP_UseTrigger* NotifyActor, AActor* aInstigator)
{
	/*
	if (NotifyActor.Tag == 'MusicTrigger')
	{
		if (bPlayingMusic)
		{
			bPlayingMusic = false;
			StopAllMusic(1);
			MusicTrigger.HUDText = "Turn Music On";
		}
		else
		{
			bPlayingMusic = true;
			PlayMusic("EscapeAndEvade", 3);
			MusicTrigger.HUDText = "Turn Music Off";
		}
		return true;
	}
	*/
	return false;
}

float AEL_EscapeAndEvade::GetPlayerVisibility()
{
	return (VolumeRisk * ((GetVelocityRiskVisual() + GetPostureRiskVisual()) / 2));
}

float AEL_EscapeAndEvade::GetPlayerAudibility()
{
	return GetVelocityRiskAudio();
}

float AEL_EscapeAndEvade::GetVelocityRiskVisual()
{
	return PlayerVelocity / 100;
}

float AEL_EscapeAndEvade::GetVelocityRiskAudio()
{
	return AverageVelocity / 80;
}

float AEL_EscapeAndEvade::GetPostureRiskVisual()
{
	/*
	switch (PlayerPosture)
	{
	case 0:
		return 0.9;
	case 1:
		return 1.2;
	case 2:
		return 1.6;
	default:
	}
	*/
	return 0;    //FAKE   /ELiZ
}

void AEL_EscapeAndEvade::SendNoise(AActor* aInstigator, float Loudness)
{
}

bool AEL_EscapeAndEvade::Timer_Timer(FName Name)
{
	return true;
}

