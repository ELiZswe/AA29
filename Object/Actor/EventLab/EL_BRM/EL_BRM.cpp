// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_BRM/EL_BRM.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/AGP_NPC.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/HudOverlay/BRM_HudOverlay/BRM_HudOverlay.h"
#include "AA29/Object/Actor/FSTS_HelpMarker/FSTS_HelpMarker.h"
#include "AA29/Object/Actor/Keypoint/Marker/Marker.h"
#include "AA29/Object/Actor/Triggers/RandomDispatcher/TargetManager/TargetManager.h"
#include "AA29/Object/Actor/Controller/NPC_Shooting_Controller/NPC_Shooting_Controller.h"
#include "AA29/Object/Actor/Info/Security/Security.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/FSTS_PlayerController.h"

AEL_BRM::AEL_BRM()
{
	ResetActorTag = "Range_Reset";
	AmmoPickupObjectiveTag = "AmmoObjective";
	PracticeFireObjectiveTag = "PracticeObjective";
	RecordFireObjectiveTag = "QualifyObjective";
	MissionTitle = "Basic Rifle Marksmanship Qualification (BRM)";
	MouseMsg = "Move your mouse to look around.";
	MoveForwardMsg = "Press <MoveForward> to move forward.";
	AmmoPickupMsg1 = "Move your mouse to look around and press <MoveForward> to move forward.";
	AmmoPickupMsg2 = "Pick up ammunition at the table marked with the green arrow.";
	ActionMsg = "Press the <Action> key ";
	TalkMsg = "Press the <Action> key to talk to the Drill Sergeant.";
	RaiseWeaponMsg = "Press the <SwapHands> key to unsling your weapon.";
	FireModeMsg = "Press <AltFire> to change your weapon from single to semi automatic.";
	LoadMsg = "Press the <Reload> key to load your rifle .";
	ZoomMsg = "Press the <Zoom> key to bring the rifle sights up.";
	ReloadMsg = "Press the <Reload> key to load the next magazine.";
	FireMsg = "Press <Fire> to fire your weapon.";
	AltFireMsg = "Press <AltFire> to switch fire modes between Single and Burst fire.";
	WeaponJamMsg = "Press <Fixjam> to clear the jam.";
	MoveToLaneMsg = "Proceed to Lane 4 and talk to the Drill Sergeant.";
	ReadyMsg = "Press the <Action> key to tell the Drill Sergeant you're ready.";
	KneelMsg = "Press the <Reload> key to load your rifle and the <Zoom> key to bring the rifle sights up.";
	BreathMsg = "Time your firing at the top or bottom of the breathing cycle for better accuracy.";
	CeaseFireMsg = "Cease Fire!";
	HelpMarkerSmallOffset = FVector(0, 0, 25);
	HelpMarkerLargeOffset = FVector(0, 0, 100);
	AmmoPickupTimeout = 300;
	GameSounds = {
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_14_Cue.brm_record_14_Cue'"), NULL, LOAD_None, NULL),"brm_record_14",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_15_Cue.brm_record_15_Cue'"), NULL, LOAD_None, NULL),"brm_record_15",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_16_Cue.brm_record_16_Cue'"), NULL, LOAD_None, NULL),"brm_record_16",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_17_Cue.brm_record_17_Cue'"), NULL, LOAD_None, NULL),"brm_record_17",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_18_Cue.brm_record_18_Cue'"), NULL, LOAD_None, NULL),"brm_record_18",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_19_Cue.brm_record_19_Cue'"), NULL, LOAD_None, NULL),"brm_record_19",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_24_Cue.brm_record_24_Cue'"), NULL, LOAD_None, NULL),"brm_record_24",0 })
	};
	LSAnims = {
		FLSAnim({ "brm_ammo_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Ammo/brm_ammo_1_Cue.brm_ammo_1_Cue'"), NULL, LOAD_None, NULL),{"ae_convgest_k","None","None","None","None","None","None","None","None","None"},{1,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_ammo_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Ammo/brm_ammo_2_Cue.brm_ammo_2_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_ammo_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Ammo/brm_ammo_3_Cue.brm_ammo_3_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_ammo_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Ammo/brm_ammo_4_Cue.brm_ammo_4_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_ammo_5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Ammo/brm_ammo_5_Cue.brm_ammo_5_Cue'"), NULL, LOAD_None, NULL),{"ae_pointmedrt_c","None","None","None","None","None","None","None","None","None"}, {0.25,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_ammo_6",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Ammo/brm_ammo_6_Cue.brm_ammo_6_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_ammo_7",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Ammo/brm_ammo_7_Cue.brm_ammo_7_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_ammo_8",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Ammo/brm_ammo_8_Cue.brm_ammo_8_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_practice_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/practice/brm_practice_1_Cue.brm_practice_1_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_practice_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/practice/brm_practice_2_Cue.brm_practice_2_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_practice_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/practice/brm_practice_3_Cue.brm_practice_3_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_1_Cue.brm_record_1_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_2_Cue.brm_record_2_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_3_Cue.brm_record_3_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_4_Cue.brm_record_4_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_5_Cue.brm_record_5_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_6",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_6_Cue.brm_record_6_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_7",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_7_Cue.brm_record_7_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_8",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_8_Cue.brm_record_8_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_9",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_9_Cue.brm_record_9_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_10",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_10_Cue.brm_record_10_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_11",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_11_Cue.brm_record_11_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_12",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_12_Cue.brm_record_12_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_13",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_13_Cue.brm_record_13_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_20",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_20_Cue.brm_record_20_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_21",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_21_Cue.brm_record_21_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_22",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_22_Cue.brm_record_22_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_record_23",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/record/brm_record_23_Cue.brm_record_23_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_stage_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Stage/brm_stage_1_Cue.brm_stage_1_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_stage_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Stage/brm_stage_2_Cue.brm_stage_2_Cue'"), NULL, LOAD_None, NULL),{"ae_pointmedlt_a","None","None","None","None","None","None","None","None","None"}, {0.5,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_stage_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Stage/brm_stage_3_Cue.brm_stage_3_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_stage_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Stage/brm_stage_4_Cue.brm_stage_4_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_stage_5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Stage/brm_stage_5_Cue.brm_stage_5_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_stage_6",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Stage/brm_stage_6_Cue.brm_stage_6_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_stage_7",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Stage/brm_stage_7_Cue.brm_stage_7_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "brm_stage_8",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_BRMRange/Stage/brm_stage_8_Cue.brm_stage_8_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"}, {0,0,0,0,0,0,0,0,0,0} })
	};
	bEnableCheats = true;
}

/*
State LevelEntryTransition
{
	Function BeginState()
	{
		FadeOut(0,true);
		SetTimerEvent("LevelStartFadeIn",3,0,false);
		FadeIn(3,true);
	}
	Function bool Timer_Timer(FName TimerName)
	{
		GotoState("Briefing");
		return true;
	}
}
*/

/*
State Briefing
{
	Function BeginState()
	{
		PlayRangeIntro();
		WarnCount=0;
	}
	Function PlayRangeIntro()
	{
		PlayTip(MissionTitle,"",6);
		PlayLSAnim("brm_stage_1",DSJohnson);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "brm_stage_1")
		{
			PlayLSAnim("brm_stage_7",DSJohnson);
			return true;
		}
		else
		{
			if (Name == "brm_stage_7")
			{
				PlayLSAnim("brm_stage_8",DSJohnson);
				return true;
			}
			else
			{
				if (Name == "brm_stage_8")
				{
					PlayLSAnim("brm_stage_2",DSJohnson);
				}
				else
				{
					if (Name == "brm_stage_2")
					{
						ShowHelpMessage(AmmoPickupMsg1,AmmoPickupMsg2);
						PlayerLock(false,false);
						SetMarker(NCODavidson);
						SetTimer((10 + (FMath::FRand() * 5)),false);
						return true;
					}
				}
			}
		}
		return false;
	}
	Function Timer()
	{
		FName lipsync = "";
		if (WarnCount > 1)
		{
			ConsoleCommand("reconnect");
		}
		else
		{
			if (Rand(2) == 0)
			{
				lipsync="brm_stage_3";
			}
			else
			{
				lipsync="brm_stage_4";
			}
			PlayLSAnim(lipsync,DSJohnson);
			(++ WarnCount);
			SetTimer((10 + (FMath::FRand() * float(10))),false);
		}
	}
	Function bool AGP_Trigger_Trigger(AGP_Gameplay.AGP_Trigger* NotifyActor, AActor* Instigator)
	{
		if (NotifyActor.Tag == "DavidsonProximity")
		{
			HideHelpMessage();
			GotoState("AmmoPickup");
			return true;
		}
		return false;
	}
	Function NPCShot(APawn* NotifyActor)
	{
		if (NotifyActor != DSJohnson)
		{
			PlayLSAnim("brm_stage_6",DSJohnson);
		}
		GotoState("SeriousError");
	}
}
*/

/*
State AmmoPickup
{
	Function BeginState()
	{
		Super::BeginState();
		WarnCount=0;
		PlayerLock(true,false);
		PlayLSAnim("brm_ammo_1",NCODavidson);
		HelpMarker.DeactivateMarker();
	}
	Function Timer()
	{
		if (bCanRaiseWeapon && (! bRaisedWeapon))
		{
			if (Player.Weapon.bWeaponUp)
			{
				bRaisedWeapon=true;
				RaisedWeapon();
			}
			else
			{
				SetTimer(0.5,false);
			}
		}
		else
		{
			if ((bCanChangeFireMode && (! bChangedFireMode)) && bRaisedWeapon)
			{
				if (Player.Weapon.eROF == 2)
				{
					bChangedFireMode=true;
					ChangedFireMode();
				}
				else
				{
					SetTimer(0.5,false);
				}
			}
			else
			{
				if (((bCanClearJam && (! bClearedJam)) && bChangedFireMode) && bRaisedWeapon)
				{
					if (! Cast<AAGP_Weapon>(Player.Weapon).IsJammed())
					{
						bClearedJam=true;
						ClearedJam();
					}
					else
					{
						SetTimer(0.5,false);
					}
				}
				else
				{
					SetTimer(0.5,false);
				}
			}
		}
	}
	Function RaisedWeapon()
	{
		HideHelpMessage();
		Player.bCanSwapWeapons=false;
		PlayLSAnim("brm_ammo_8",NCODavidson);
		if (Player.Weapon != nullptr)
		{
			Player.Weapon.eROF=1;
		}
	}
	Function ChangedFireMode()
	{
		HideHelpMessage();
		PlayLSAnim("brm_ammo_2",NCODavidson);
	}
	Function ClearedJam()
	{
		HideHelpMessage();
		PlayLSAnim("brm_ammo_3",NCODavidson);
	}
	Function bool AGP_Trigger_Trigger(AGP_Gameplay.AGP_Trigger* NotifyActor, AActor* Instigator)
	{
		if (NotifyActor.Tag == "BakerProximity")
		{
			ShowHelpMessage(ReadyMsg);
			return true;
		}
		return false;
	}
	Function bool AGP_Trigger_UnTrigger(AGP_Gameplay.AGP_Trigger* NotifyActor, AActor* Instigator)
	{
		if (NotifyActor.Tag == "BakerProximity")
		{
			HideHelpMessage();
		}
		return true;
	}
	Function bool AGP_UseTrigger_UsedBy(AAGP_UseTrigger* NotifyActor, AActor* Instigator)
	{
		if (NotifyActor.Tag == "TalkToBaker")
		{
			DSBaker.bUseActionIcon=false;
			HideHelpMessage();
			GotoState("PracticeFire");
			return true;
		}
		return false;
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "brm_ammo_1")
		{
			Player.bCanSwapWeapons=true;
			ShowHelpMessage(RaiseWeaponMsg);
			bCanRaiseWeapon=true;
			SetTimer(0.5,false);
		}
		else
		{
			if (Name == "brm_ammo_8")
			{
				if (Player.Weapon.eROF != 2)
				{
					ShowHelpMessage(FireModeMsg);
				}
				bCanChangeFireMode=true;
				SetTimer(0.5,false);
			}
			else
			{
				if (Name == "brm_ammo_2")
				{
					Cast<AAGP_Weapon>(Player.Weapon).ClientHandleMisfire();
					Player.Weapon.AmmoType.AmmoAmount=1;
					ShowHelpMessage(WeaponJamMsg);
					bCanClearJam=true;
					SetTimer(0.5,false);
				}
				else
				{
					if (Name == "brm_ammo_3")
					{
						PlayerLock(false,false);
						PlayTip(MoveToLaneMsg,"",5);
						SetMarker(DSBaker);
						DSBaker.bUseActionIcon=true;
						Give20RoundMag();
						Controller.bNoReload=true;
						StartTimer("MoveToRange",AmmoPickupTimeout);
						GotoState("AmmoPickup","Idle");
					}
				}
			}
		}
		return true;
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		switch(TimerName)
		{
			case "MoveToRange":
			FadeOutBlack(2);
			StartTimer("FadeOutBlack",2);
			break;
			case "FadeOutBlack":
			FadeInBlack(2);
			StartTimer("FadeInBlack",2);
			Player.SetLocation(GetActorByTag(ResetActorTag).Location);
			Controller.SetRotation(GetActorByTag(ResetActorTag).Rotation);
			break;
			case "FadeInBlack":
			DSBaker.bUseActionIcon=false;
			HideHelpMessage();
			GotoState("PracticeFire");
			break;
			default:
			break;
		}
		return true;
	}
	Function EndState()
	{
		AmmoPickupObjective.AccomplishObjective(Level.GetLocalPlayerController().Pawn);
		AmmoPickupObjective.SendPercentage(Level.GetLocalPlayerController().Pawn);
	}
Begin:
	Sleep((15 + (FMath::FRand() * float(20))));
	if (WarnCount > 1)
	{
		ConsoleCommand("reconnect");
	}
	else
	{
		if (Rand(2) == 0)
		{
			PlayLSAnim("brm_ammo_4",NCODavidson);
		}
		else
		{
			PlayLSAnim("brm_ammo_5",NCODavidson);
		}
		(++ WarnCount);
		JL"Idle"
;
	}
}
*/

/*
State Cheater
{
	simulated Function BeginState()
	{
		if (Controller != nullptr)
		{
		}
	}
}
*/

/*
State Firing
{
	Function NPCShot(APawn* NotifyActor)
	{
		if (NotifyActor != DSBaker)
		{
			PlayGameSound("brm_record_24",tower,,,1600);
		}
		GotoState("Firing","SeriousError");
	}
	Function FiringOutOfLane()
	{
		if (! DSBaker.IsPlayingLIPSincAnim())
		{
			if (Rand(2) == 0)
			{
				PlayLSAnim("brm_record_8",DSBaker);
			}
			else
			{
				PlayLSAnim("brm_record_9",DSBaker);
			}
		}
	}
	Function FiringOffRange()
	{
		PlayGameSound("brm_record_24",tower,,,1600);
		GotoState("Firing","MildError");
	}
Begin:
	PlayerLock(true,true);
	Sleep(1);
	GotoState("MildError");
	PlayerLock(true,true);
	Sleep(1);
	GotoState("SeriousError");
}
*/

/*
State MildError
{
Begin:
	Sleep(2);
	ConsoleCommand("reconnect");
}
*/

/*
State SeriousError
{
Begin:
	Sleep(2);
	ConsoleCommand("open Leavenworth");
}
*/

/*
State PracticeFire extends Firing
{
	Function BeginState()
	{
		PlayerLock(true,false);
		DSBaker->StopLIPSincAnim();
		Cast<ADSController>(DSBaker.Controller).TurnTowardPlayer();
		PlayLSAnim("brm_practice_1",DSBaker);
		HelpMarker.DeactivateMarker();
		CurrentTM=ProneSupportedTM;
	}
	Function CheckPlayerIdle()
	{
		if ((! bResetIdle) && (OldWeaponAmmo == Player.Weapon.AmmoType.AmmoAmount))
		{
			if (WarnCount > 1)
			{
				ConsoleCommand("reconnect");
			}
			else
			{
				PlayTip("Fire your entire magazine soldier!","",1);
				(++ WarnCount);
				SetCustomTimer(10,false,"CheckPlayerIdle");
			}
		}
		else
		{
			WarnCount=0;
			bResetIdle=false;
			OldWeaponAmmo=Player.Weapon.AmmoType.AmmoAmount;
			SetCustomTimer(10,false,"CheckPlayerIdle");
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "brm_practice_1")
		{
			FadeOutBlack(2);
			SetTimer(2.5,false);
		}
		else
		{
			if (Name == "brm_practice_2")
			{
				TargetManagerPracticeMode(CurrentTM,true);
				TargetManagerActive(CurrentTM,true);
				bResetIdle=true;
				CheckPlayerIdle();
			}
			else
			{
				if (Name == "brm_practice_3")
				{
					TargetManagerActive(CurrentTM,false);
					GotoState("PracticeFireCrouched");
				}
			}
		}
		return true;
	}
	Function Timer()
	{
		if (FiringPosition != nullptr)
		{
			PlayerLock(true,false);
			Player.SetLocation(FiringPosition.Location);
			Controller.SetRotation(FiringPosition.Rotation);
			Controller.bNoReload=false;
			PlayerLock(false,false);
			if (Player.Weapon != nullptr)
			{
				Player.Weapon.eROF=1;
			}
			Controller.Reload();
			Controller.Crawl();
			PlayerLock(true,false);
			Cast<ADSController>(DSBaker.Controller).MoveToPoint("Coaching");
		}
		DSBaker.SetRotation(rotator((Player.Location - DSBaker.Location)));
		FadeInBlack(1);
		PlayLSAnim("brm_practice_2",DSBaker);
	}
	Function bool AGP_Weapon_Empty(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms)
	{
		PlayLSAnim("brm_practice_3",DSBaker);
		StopCustomTimer("CheckPlayerIdle");
		return true;
	}
Begin:
	if (Player.Weapon.IsZoomed())
	{
		PlayTip(BreathMsg,"",4);
	}
	else
	{
		Sleep(1);
		JL"Begin"
;
	}
}
*/

/*
State PracticeFireProne extends PracticeFire
{
}
*/

/*
State PracticeFireCrouched extends Firing
{
	Function BeginState()
	{
		Super::BeginState();
		PlayTip(KneelMsg,"",5);
		Give20RoundMag();
		PlayerLock(false,false);
		Controller.Crouch();
		PlayerLock(true,false);
		CurrentTM=ProneSupportedTM;
		SetTimer(2,false);
	}
	Function CheckPlayerIdle()
	{
		if ((! bResetIdle) && (OldWeaponAmmo == Player.Weapon.AmmoType.AmmoAmount))
		{
			if (WarnCount > 1)
			{
				ConsoleCommand("reconnect");
			}
			else
			{
				PlayTip("Fire your entire magazine soldier!","",1);
				(++ WarnCount);
				SetCustomTimer(10,false,"CheckPlayerIdle");
			}
		}
		else
		{
			WarnCount=0;
			bResetIdle=false;
			OldWeaponAmmo=Player.Weapon.AmmoType.AmmoAmount;
			SetCustomTimer(10,false,"CheckPlayerIdle");
		}
	}
	Function Timer()
	{
		TargetManagerPracticeMode(CurrentTM,true);
		TargetManagerActive(CurrentTM,true);
		bResetIdle=true;
		CheckPlayerIdle();
	}
	Function bool AGP_Weapon_Empty(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (CurrentTM == ProneSupportedTM)
		{
			PlayGameSound("brm_record_24",tower,,,1600);
			PlayTip(CeaseFireMsg,"",3);
		}
		StartTimer("TargetManagerDeactivate",2);
		return true;
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		switch(TimerName)
		{
			case "TargetManagerActivate":
			TargetManagerPracticeMode(CurrentTM,true);
			TargetManagerActive(CurrentTM,true);
			break;
			case "TargetManagerDeactivate":
			StopCustomTimer("CheckPlayerIdle");
			TargetManagerActive(CurrentTM,false);
			GotoState("RecordFireProneSupported");
			break;
			default:
			break;
		}
		return true;
	}
	Function EndState()
	{
		PracticeFireObjective.AccomplishObjective(Level.GetLocalPlayerController().Pawn);
		PracticeFireObjective.SendPercentage(Level.GetLocalPlayerController().Pawn);
	}
}
*/

/*
State RecordFire extends Firing
{
	Function SupportedWeapon(bool bSupported, bool bForce, bool bCanSet)
	{
		AGP_Inventory.Weapon_M16A2_Trainer* W = nullptr;
		W=Weapon_M16A2_Trainer(Player.Weapon);
		if (W != nullptr)
		{
			W.bCanSetSupported=true;
		}
		Player.SetSupported(bSupported,bForce);
		if (W != nullptr)
		{
			W.bCanSetSupported=bCanSet;
		}
	}
	Function bool AGP_Weapon_Empty(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (CurrentTM == CrouchedTM)
		{
			PlayGameSound("brm_record_24",tower,,,1600);
			PlayTip(CeaseFireMsg,"",3);
		}
		StartTimer("TargetEndDispatch",2);
		return true;
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		switch(TimerName)
		{
			case "TargetEndDispatch":
			CurrentTM.EndDispatch();
			break;
			default:
			break;
		}
		return true;
	}
}
*/

/*
State RecordFireProneSupported extends RecordFire
{
	simulated Function BeginState()
	{
		DSBaker->StopLIPSincAnim();
		PlayLSAnim("brm_record_1",DSBaker);
		CurrentTM=ProneSupportedTM;
	}
	Function bool Timer_Sound(FName Name)
	{
		if (Name == "brm_record_14")
		{
			PlayLSAnim("brm_record_21",DSBaker);
			return true;
		}
		else
		{
			if (Name == "brm_record_15")
			{
				if (Player.Weapon.AmmoType.AmmoAmount > 0)
				{
					Log("Player has ammo");
					PlayLSAnim("brm_record_3",DSBaker);
				}
				else
				{
					SetTimerEvent("ReloadCheck",0.5,0,true);
				}
				return true;
			}
		}
		return false;
	}
	Function bool Timer_Timer(FName TimerName)
	{
		switch(TimerName)
		{
			case "ReloadCheck":
			if (Player.Weapon.AmmoType.AmmoAmount > 0)
			{
				StopTimer("ReloadCheck",0);
				PlayLSAnim("brm_record_3",DSBaker);
				break;
			}
			PlayTip(ReloadMsg,"",0.5);
		}
		return true;
		GOTO JL0072;
		default:
		GOTO JL0072;
JL0072:
		return Super::Timer_Timer(TimerName);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "brm_record_1")
		{
			FadeOutBlack(2);
			GotoState("RecordFireProneSupported","GetInPosition");
			return true;
		}
		else
		{
			if (Name == "brm_record_21")
			{
				PlayLSAnim("brm_record_22",DSBaker);
				return true;
			}
			else
			{
				if (Name == "brm_record_22")
				{
					PlayLSAnim("brm_record_2",DSBaker);
					return true;
				}
				else
				{
					if (Name == "brm_record_2")
					{
						PlayGameSound("brm_record_15",tower,,,1600);
						return true;
					}
					else
					{
						if (Name == "brm_record_3")
						{
							BRMOverlay.bHidden=false;
							TargetManagerPracticeMode(CurrentTM,false);
							TargetManagerActive(CurrentTM,true);
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	Function bool TargerManager_DispatchComplete(AGP_Gameplay.TargetManager* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (NotifyActor == CurrentTM)
		{
			Player.Weapon.AmmoType.AmmoAmount=0;
			StopTimer("TargetEndDispatch",0);
			GotoState("RecordFireProneUnSupported");
			return true;
		}
		return false;
	}
Begin:
	Sleep(2.2);
	PlayerLock(false,true);
	Controller.SetRotation(FiringPosition.Rotation);
	Controller.Crawl();
	PlayerLock(true,true);
	Give20RoundMag();
	FadeInBlack(1);
	Sleep(3);
	SupportedWeapon(true,true,false);
	if (! Player.IsSupported())
	{
		Sleep(0.1);
		JL"Support"
;
	}
	Sleep(1);
	PlayerLock(true,false);
	PlayGameSound("brm_record_14",tower,,,1600);
}
*/

/*
State RecordFireProneUnSupported extends RecordFire
{
	protected Function ClearSandbags()
	{
		AStaticMeshActor* sandbag = nullptr;
		ForEach AllActors(Class'StaticMeshActor',sandbag,"sandbags")
		{
			sandbag.bHidden=true;
			sandbag.SetDrawType(DT_None);
			sandbag.SetCollision(false,false,false);
		}
	}
	simulated Function BeginState()
	{
		PlayGameSound("brm_record_16",tower,,,1600);
		CurrentTM=ProneUnsupportedTM;
	}
	Function bool Timer_Sound(FName Name)
	{
		if (Name == "brm_record_16")
		{
			Give10RoundMag();
			PlayLSAnim("brm_record_4",DSBaker);
			return true;
		}
		else
		{
			if (Name == "brm_record_17")
			{
				if (Player.Weapon.AmmoType.AmmoAmount > 0)
				{
					PlayLSAnim("brm_record_5",DSBaker);
				}
				else
				{
					SetTimerEvent("ReloadCheck",0.5,0,true);
				}
			}
		}
		return false;
	}
	Function bool Timer_Timer(FName TimerName)
	{
		switch(TimerName)
		{
			case "ReloadCheck":
			if (Player.Weapon.AmmoType.AmmoAmount > 0)
			{
				Log("Player has ammo");
				StopTimer("ReloadCheck",0);
				PlayLSAnim("brm_record_5",DSBaker);
				break;
			}
			PlayTip(ReloadMsg,"",0.5);
		}
		return true;
		GOTO JL0085;
		default:
		GOTO JL0085;
JL0085:
		return Super::Timer_Timer(TimerName);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "brm_record_4")
		{
			if (! Player.Weapon.HasAmmo())
			{
				ShowHelpMessage(ReloadMsg);
				SetTimer(0.5,false);
			}
			else
			{
				GotoState("RecordFireProneUnSupported","MoveSandbags");
			}
			return true;
		}
		if (Name == "brm_record_5")
		{
			TargetManagerPracticeMode(CurrentTM,false);
			TargetManagerActive(CurrentTM,true);
		}
		return false;
	}
	Function Timer()
	{
		if (Player.Weapon.HasAmmo())
		{
			HideHelpMessage();
			GotoState("RecordFireProneUnSupported","MoveSandbags");
		}
		else
		{
			SetTimer(0.5,false);
		}
	}
	Function bool TargerManager_DispatchComplete(AGP_Gameplay.TargetManager* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (NotifyActor == CurrentTM)
		{
			Player.Weapon.AmmoType.AmmoAmount=0;
			StopTimer("TargetEndDispatch",0);
			GotoState("RecordFireCrouched");
			return true;
		}
		return false;
	}
Begin:
	Sleep(1);
	FadeOutBlack(1);
	Sleep(1.2);
	ClearSandbags();
	SupportedWeapon(false,false,false);
	FadeInBlack(0.5);
	Sleep(1);
	PlayGameSound("brm_record_17",tower,,,1600);
}
*/

/*
State RecordFireCrouched extends RecordFire
{
	simulated Function BeginState()
	{
		PlayGameSound("brm_record_18",tower,,,1600);
		CurrentTM=CrouchedTM;
	}
	Function bool Timer_Sound(FName Name)
	{
		if (Name == "brm_record_18")
		{
			Give10RoundMag();
			PlayLSAnim("brm_record_6",DSBaker);
			return true;
		}
		else
		{
			if (Name == "brm_record_19")
			{
				if (Player.Weapon.AmmoType.AmmoAmount > 0)
				{
					PlayLSAnim("brm_record_7",DSBaker);
				}
				else
				{
					SetTimerEvent("ReloadCheck",0.5,0,true);
				}
			}
		}
		return false;
	}
	Function bool Timer_Timer(FName TimerName)
	{
		switch(TimerName)
		{
			case "ReloadCheck":
			if (Player.Weapon.AmmoType.AmmoAmount > 0)
			{
				StopTimer("ReloadCheck",0);
				PlayLSAnim("brm_record_7",DSBaker);
				break;
			}
			PlayTip(ReloadMsg,"",0.5);
		}
		return true;
		GOTO JL0072;
		default:
		GOTO JL0072;
JL0072:
		return Super::Timer_Timer(TimerName);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "brm_record_6")
		{
			if (! Player.Weapon.HasAmmo())
			{
				PlayTip(ReloadMsg,"",4);
			}
			SetTimer(0.5,false);
			return true;
		}
		if (Name == "brm_record_7")
		{
			TargetManagerPracticeMode(CurrentTM,false);
			TargetManagerActive(CurrentTM,true);
		}
		return false;
	}
	Function Timer()
	{
		if (Player.Weapon.HasAmmo())
		{
			GotoState("RecordFireCrouched","Firing");
		}
		else
		{
			SetTimer(0.5,false);
		}
	}
	Function bool TargerManager_DispatchComplete(AGP_Gameplay.TargetManager* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (NotifyActor == CurrentTM)
		{
			GotoState("RecordFireCrouched","Ending");
			return true;
		}
		return false;
	}
	Function EndState()
	{
		RecordFireObjective.AccomplishObjective(Level.GetLocalPlayerController().Pawn);
		RecordFireObjective.SendPercentage(Level.GetLocalPlayerController().Pawn);
	}
Begin:
	Sleep(2.5);
	GotoState("ScorePlayer");
	JL"LastLabel"
;
	Sleep(1);
	FadeOutBlack(1);
	Sleep(1.2);
	PlayerLock(false,false);
	Controller.Crouch();
	PlayerLock(true,false);
	FadeInBlack(0.5);
	Sleep(1);
	PlayGameSound("brm_record_19",tower,,,1600);
}
*/

/*
State ScorePlayer
{
	Function BeginState()
	{
		AuthFinalScore=GetTargetManagerTotalScore(ProneSupportedTM);
		(AuthFinalScore += GetTargetManagerTotalScore(ProneUnsupportedTM));
		(AuthFinalScore += GetTargetManagerTotalScore(CrouchedTM));
		ScoreRecordText="Targets Hit:  " + FString::FromInt(AuthFinalScore) + "/40";
		if (AuthFinalScore < 23)
		{
			PlayLSAnim("brm_record_10",DSBaker);
			DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_sf","You failed to qualify on BRM Training.","Would you like to try again?",128,128,7,"None","AGP_Interface.AAMissionCompletePageEx");
		}
		else
		{
			if (AuthFinalScore >= 36)
			{
				PlayLSAnim("brm_record_13",DSBaker);
				QualifyText="Expert";
			}
			else
			{
				if (AuthFinalScore >= 30)
				{
					PlayLSAnim("brm_record_12",DSBaker);
					QualifyText="Sharpshooter";
				}
				else
				{
					PlayLSAnim("brm_record_11",DSBaker);
					QualifyText="Marksman";
				}
			}
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (((Name == "brm_record_13") || (Name == "brm_record_12")) || (Name == "brm_record_11"))
		{
			if (AuthFinalScore >= 36)
			{
				PlayLSAnim("brm_record_23",DSBaker);
			}
			HandlePassResults();
			return true;
		}
		return false;
	}
}
*/

void AEL_BRM::PreInit()
{
	/*
		DSJohnson = AGP_Character(CaptureEvent('Johnson'));
	DSBaker = AGP_Character(CaptureEvent('Baker'));
	NCODavidson = AGP_Character(CaptureEvent('Davidson'));
	tower = AGP_NPC(CaptureEvent('tower'));
	ProneSupportedTM = Cast<ATargetManager>(CaptureEvent('ProneSupported'));
	ProneUnsupportedTM = Cast<ATargetManager>(CaptureEvent('ProneUnsupported'));
	CrouchedTM = Cast<ATargetManager>(CaptureEvent('Crouched'));
	ForEach AllActors(AMarker::StaticClass(), FiringPosition, 'FiringPosition')
	{
		GOTO JL00B3;
	JL00B3:
	}
	*/
}

void AEL_BRM::Init()
{
}

void AEL_BRM::PostInit()
{
	AActor* A = nullptr;
	/*
	ForEach AllActors(Class'Actor', A)
	{
		ReCaptureEvent(A);
	}
	DoReferenceLinking();
	*/
}

void AEL_BRM::PostPostInit()
{
	/*
	Controller.EventLab = this;
	Player.EventLab = this;
	PlayerLock(true, false);
	Player.GiveWeapon("AGP_Inventory.Weapon_M16A2_Trainer");
	Player.Weapon.AnimEnd(0);
	Player.Weapon.PutDown();
	Player.Weapon.AmmoType.AmmoAmount = 0;
	Player.bCanSwapWeapons = false;
	BRMOverlay = Spawn(ABRM_HudOverlay::StaticClass());
	BRMOverlay.BRMLab = this;
	Controller.myHUD.AddHudOverlay(BRMOverlay);
	Controller.bNoThrowWeapon = true;
	StartShooters();
	ChangeState('LevelEntryTransition');
	*/
}

void AEL_BRM::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == AmmoPickupObjectiveTag)
		{
			AmmoPickupObjective = Cast<AAGP_Objective>(SearchActor);
		}
		if (SearchActor.Tag == PracticeFireObjectiveTag)
		{
			PracticeFireObjective = Cast<AAGP_Objective>(SearchActor);
		}
		if (SearchActor.Tag == RecordFireObjectiveTag)
		{
			RecordFireObjective = Cast<AAGP_Objective>(SearchActor);
		}
	}
	*/
}

void AEL_BRM::Destroyed()
{
	AmmoPickupObjective = nullptr;
	PracticeFireObjective = nullptr;
	RecordFireObjective = nullptr;
	Super::Destroyed();
}

void AEL_BRM::StartShooters()
{
	AAGP_NPC* shooter = nullptr;
	ANPC_Shooting_Controller* shootingController = nullptr;
	/*
	ForEach AllActors(AAGP_NPC::StaticClass(), shooter, 'shooters')
	{
		shootingController = Spawn(ANPC_Shooting_Controller::StaticClass());
		shootingController.Possess(shooter);
	}
	*/
}

void AEL_BRM::EventLabNotifyCheat()
{
	if (bEnableCheats)
	{
		return;
	}
	else
	{
		//GotoState('Cheater');
	}
}

void AEL_BRM::Give10RoundMag()
{
	/*
	Player.CreateInventoryFromName("AGP_Inventory.Ammo_556mm_10_Mag");
	Cast<AAGP_Weapon>(Player.Weapon).RecountAmmo();
	*/
}

void AEL_BRM::Give20RoundMag()
{
	/*
	Player.CreateInventoryFromName("AGP_Inventory.Ammo_556mm_20_Mag");
	Cast<AAGP_Weapon>(Player.Weapon).RecountAmmo();
	*/
}

void AEL_BRM::SetMarker(AActor* Target)
{
	/*
	if (HelpMarker == nullptr)
	{
		HelpMarker = Spawn(AFSTS_HelpMarker::StaticClass(), this);
		HelpMarker.SetDisplayMesh(false);
	}
	HelpMarker.SetMarkingActor(Target, HelpMarkerLargeOffset);
	HelpMarker.ActivateMarker();
	*/
}

void AEL_BRM::ShowHelpMessage(FString Message, FString secondMessage)
{
	CurrentHelpMessage = Message;
	PlayTip(CurrentHelpMessage, secondMessage, 1000000000);
	bShowingMessage = true;
}

void AEL_BRM::HideHelpMessage()
{
	if (bShowingMessage)
	{
		PlayTip(CurrentHelpMessage, "", 0.1);
	}
	bShowingMessage = false;
}

bool AEL_BRM::AGP_NPC_Damaged(AAGP_NPC* NotifyActor, AController* aInstigator)
{
	/*
	if (NotifyActor != Player)
	{
		NPCShot(NotifyActor);
	}
	*/
	return true;
}

bool AEL_BRM::Pawn_Damaged(APawn* NotifyActor, AController* aInstigator)
{
	/*
	if (NotifyActor != Player)
	{
		NPCShot(NotifyActor);
	}
	*/
	return true;
}

void AEL_BRM::NPCShot(APawn* NotifyActor)
{
	FriendlyFire(NotifyActor);
}

void AEL_BRM::Suicide(APawn* Killer)
{
	//ConsoleCommand("Reconnect");
}

void AEL_BRM::FriendlyFire(APawn* HitActor)
{
	//ConsoleCommand("open leavenworth");
}

void AEL_BRM::RestartLevel()
{
	//ConsoleCommand("Reconnect");
}

void AEL_BRM::Leavenworth()
{
	//ConsoleCommand("open leavenworth");
}

bool AEL_BRM::AGP_Weapon_Fire(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	FVector FlatPlayerDir = FVector(0, 0, 0);
	FVector FlatFiringDir = FVector(0, 0, 0);
	float DotProduct = 0;
	if ((aInstigator == Player) && NotifyActor.HasAmmo())
	{
		FlatPlayerDir = Vector(Player.Rotation);
		FlatFiringDir = Vector(FiringPosition.Rotation);
		FlatPlayerDir.Z = 0;
		FlatFiringDir.Z = 0;
		DotProduct = (FlatPlayerDir Dot FlatFiringDir);
		if (DotProduct < 0.8)
		{
			FiringOffRange();
		}
		else
		{
			if (DotProduct < 0.99)
			{
				FiringOutOfLane();
			}
		}
	}
	*/
	return true;
}

void AEL_BRM::FiringOutOfLane()
{
}

void AEL_BRM::FiringOffRange()
{
}

bool AEL_BRM::HandlePassResults()
{
	ASecurity* secLocalSecurity = nullptr;
	ASecurity* scLocalSecurityClass = nullptr;
	TArray<FString> asMD5ForMap = {};
	TArray<FString> asMD5ForScript = {};
	FString sMD5ForMap = "";
	FString sMD5ForScript = "";
	/*
	DebugLog(DEBUG_EventLab, "uploadStats:");
	if (Cast<AFSTS_PlayerController>(Controller).IsUsingCheats())
	{
		DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_sf", "BRM Training Complete", "Would you like to try again?", 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageEx");
		return false;
	}
	Controller.SetAuthMissionPassFlag(true);
	Controller.ResetAuthExtraMissionData();
	Controller.AddAuthExtraMissionData("" + FString::FromInt(AuthFinalScore));
	Controller.iRifleRangeRating = AuthFinalScore;
	scLocalSecurityClass = class<Security>(DynamicLoadObject("Engine.Security", Class'Class'));
	if (scLocalSecurityClass != nullptr)
	{
		secLocalSecurity = Spawn(scLocalSecurityClass, Controller);
		if (secLocalSecurity != nullptr)
		{
			secLocalSecurity.LocalPerform(2, "../Maps/BRM_Range.aao", "", asMD5ForMap);
			secLocalSecurity.LocalPerform(2, "../System/FSTS.u", "", asMD5ForScript);
			sMD5ForMap = asMD5ForMap[0];
			sMD5ForScript = asMD5ForScript[0];
		}
	}
	Controller.AddAuthExtraMissionData("");
	Controller.AddAuthExtraMissionData("");
	Controller.AddAuthExtraMissionData("");
	Controller.AddAuthExtraMissionData("");
	Controller.AddAuthExtraMissionData("");
	Controller.AddAuthExtraMissionData("");
	Controller.AddAuthExtraMissionData("");
	Controller.AddAuthExtraMissionData("");
	Controller.AddAuthExtraMissionData("");
	Controller.AddAuthExtraMissionData("");
	Controller.AddAuthExtraMissionData(sMD5ForMap);
	Controller.AddAuthExtraMissionData(sMD5ForScript);
	DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_sf", "Congratulations!  You qualified " + QualifyText + ".", ScoreRecordText, 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageEx");
	*/
	return true;
}
