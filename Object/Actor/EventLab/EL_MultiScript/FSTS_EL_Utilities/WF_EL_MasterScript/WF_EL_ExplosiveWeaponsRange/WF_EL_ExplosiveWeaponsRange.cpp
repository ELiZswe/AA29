// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_ExplosiveWeaponsRange/WF_EL_ExplosiveWeaponsRange.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/FSTS_WeaponPickup.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_AT4_Rocket/Weapon_AT4_Rocket.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_BDM_Rocket/Weapon_BDM_Rocket.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

AWF_EL_ExplosiveWeaponsRange::AWF_EL_ExplosiveWeaponsRange()
{
	OutsideShotLimit = 1;
	iMinimumTargets = 10;
	iMaximumTargets = 15;
	WeaponName = "Explosive Weapons Training Station";
	StationMsg = "Station ";
	MoveMsg = "Proceed to the next station.";
	StandardsMsg = "You must hit atleast %MINIMUM% of %MAXIMUM% targets.";
	StationInstructionMsg = "Put an M203 grenade through the window.";
	PracticeMsg = "Practice Beginning!";
	PracticeCountdownMsg = "Practice will begin in 10 seconds.";
	QualificationMsg = "Begin Qualification.";
	QualificationCountdownMsg = "Qualification will begin in 10 seconds";
	WeaponPickupMsg = "Pick up the Explosives.";
	WeaponReloadMsg = "Reload your weapon and fire to qualify.";
	NumRoundsMsg = "You have %NUMROUNDS% rounds.";
	SuccessMsg = "Congratulations on qualifying with Explosive Weapons.";
	FailureMsg = "You failed to qualify with Explosive Weapons.";
	M203QualificationSuccessMsg = "You qualified on the M203.";
	AT4QualificationSuccessMsg = "You qualified on the AT4.";
	BDMQualificationSuccessMsg = "You qualified on the BDM.";
	M203QualificationFailureMsg = "You failed to qualify on the M203.";
	AT4QualificationFailureMsg = "You failed to qualify on the AT4.";
	BDMQualificationFailureMsg = "You failed to qualify on the BDM.";
	StationFailureMsg = "Station 3 Failed!";
	CompleteMsg = "Station complete.";
	IncompleteMsg = "Station Incomplete!";
	DoneMsg = "You are done.";
	OutsideLaneMsg = "You have shot outside the station lane!";
	HitMsg = "You hit %HITCOUNT% targets using %NUMROUNDS% rounds.";
	ShotsFiredMsg = "%SHOTSFIRED% shots went outside your lane.";
	ResultMsg = "%STATIONSCORE% of %TOTALSCORE% targets hit.";
	MissionCompleteMsg = "Mission Complete.";
	FireMsg = "Press <Fire> to fire at the hulk when ready.";
	ZoomMsg = "Use <Zoom> to adjust the sites.";
	ReloadMsg = "Press the <Reload> key reload.";
	ReloadAndFireMsg = "Press <Reload> to reload and <Fire> to fire your weapon and qualify.";
	SupportedMsg = "Press the <SupportedFire> key to change weapon modes.";
	ThrowMsg = "Press <ThrowWeapon> to discard the empty rocket tube.";
	TargetHitMsg = "Hit!";
	M203WeaponName = "M203";
	AT4WeaponName = "AT4";
	BDMWeaponName = "BDM";
	M203WeaponPickupMsg = "Pick up an M203 from the table.";
	AT4WeaponPickupMsg = "Pick up an AT4 from the table.";
	BDMWeaponPickupMsg = "Pick up a BDM from the table.";
	M203WeaponStandardsMsg = "Put an M203 grenade through the window.";
	AT4WeaponStandardsMsg = "Fire at the tank in your lane.";
	BDMWeaponStandardsMsg = "Destroy the bunker.";
	DrillSergeantTag = "NPC_DS_Koch";
	StationObjectiveTag = "Station3Objective";
	StationBeginPointTag = "Station3_Start";
	bStartFromDrillSergeantUse = true;
	bFadeMoveFromDrillSergeantUse = true;
	StationName = "Explosive Weapons";
	HelpInfoList = {
		FHelpInfo({ "PickupM203",6,"Pick up the M203.","","wf_station3_16",nullptr }),
		FHelpInfo({ "PickupAT4",6,"Pick up an AT4 from the table.","","wf_station3_16",nullptr }),
		FHelpInfo({ "PickupBDM",6,"Pick up a BDM and fire at the bunker for practice.","","wf_station3_16",nullptr })
	};
	bDormant = true;
	bMasterScript = false;
	LSAnims = {
		FLSAnim({ "wf_station3_1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_1_Cue.wf_station3_1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_2_Cue.wf_station3_2_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_3_Cue.wf_station3_3_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_4_Cue.wf_station3_4_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_5_Cue.wf_station3_5_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_6",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_6_Cue.wf_station3_6_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_7",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_7_Cue.wf_station3_7_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_8",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_8_Cue.wf_station3_8_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_9",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_9_Cue.wf_station3_9_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_10",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_10_Cue.wf_station3_10_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_11",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_11_Cue.wf_station3_11_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_12",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_12_Cue.wf_station3_12_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_13",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_13_Cue.wf_station3_13_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_14",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_14_Cue.wf_station3_14_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_15",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_15_Cue.wf_station3_15_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_16",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_16_Cue.wf_station3_16_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_17",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_17_Cue.wf_station3_17_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "wf_station3_18",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LvL_WeaponsFam/Station3/wf_station3_18_Cue.wf_station3_18_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} })
	};
	bDoGeneralInit = false;
}

void AWF_EL_ExplosiveWeaponsRange::Reset()
{
	/*
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	DrillSergeant->StopLIPSincAnim();
	Player.EmptyInventory();
	M203Pickup.GotoState("Pickup");
	M203Pickup.SetAllowPickup(false);
	M203QualState = 0;
	AT4Pickup.GotoState("Pickup");
	AT4Pickup.SetAllowPickup(false);
	AT4QualState = 0;
	BDMPickup.GotoState("Pickup");
	BDMPickup.SetAllowPickup(false);
	BDMQualState = 0;
	HitCount = 0;
	M203QualificationFireCounter = 0;
	AT4PracticeFireCounter = 0;
	BDMPracticeFireCounter = 0;
	OutsideShotCounter = 0;
	FSTS_PlayerController(Controller).bAllowThrowWeapon = false;
	SetHelpMarker(HelpMarker, DrillSergeant->GetActorLocation(), HelpMarkerLargeOffset, true, true);
	Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
	SetDrillSergeantParams(true, true, true);
	StationObjective.SetDisabled(false);
	Player.SetLocation(GetActorByTag("Station3_Start").Location);
	Controller.SetRotation(GetActorByTag("Station3_Start").Rotation);
	Super::Reset();
	*/
}

void AWF_EL_ExplosiveWeaponsRange::GivePlayerAT4()
{
	AInventory* newWeapon = nullptr;
	/*
	newWeapon = Spawn(AWeapon_AT4_Rocket::StaticClass(), Player);
	newWeapon.GiveTo(Player);
	newWeapon.SetEventLab(this);
	*/
}

void AWF_EL_ExplosiveWeaponsRange::GivePlayerBDM()
{
	AInventory* newWeapon = nullptr;
	/*
	newWeapon = Spawn(AWeapon_BDM_Rocket::StaticClass(), Player);
	newWeapon.GiveTo(Player);
	newWeapon.SetEventLab(this);
	*/
}

void AWF_EL_ExplosiveWeaponsRange::DoReferenceLinking()
{
	


	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "PickupW_FSTS_Trainer_M203_Gren")
		{
			Log(" Linked weapon " + FString::FromInt(SearchActor) + " with tag " + FString::FromInt(SearchActor.Tag), "Explosive_Range");
			M203Pickup = Cast<AFSTS_WeaponPickup>(SearchActor);
			M203Pickup.EventLab = this;
			M203Pickup.SetAllowPickup(false);
		}
		else
		{
			if (SearchActor.Tag == "PickupW_FSTS_Trainer_AT4_Rocket")
			{
				Log(string(this) + " linked weapon " + FString::FromInt(SearchActor));
				AT4Pickup = Cast<AFSTS_WeaponPickup>(SearchActor);
				AT4Pickup.EventLab = this;
				AT4Pickup.SetAllowPickup(false);
			}
			else
			{
				if (SearchActor.Tag == "PickupW_FSTS_Trainer_BDM_Rocket")
				{
					Log(string(this) + " linked weapon " + FString::FromInt(SearchActor));
					BDMPickup = Cast<AFSTS_WeaponPickup>(SearchActor);
					BDMPickup.EventLab = this;
					BDMPickup.SetAllowPickup(false);
				}
			}
		}
		if (SearchActor.Tag == "M203WindowTrigger")
		{
			actTargetM203 = SearchActor;
		}
		if (SearchActor.Tag == "S3_M203WindowShot")
		{
			SearchActor.EventLab = this;
		}
		if (SearchActor.Tag == "AT4TankTarget")
		{
			actTargetAT4 = SearchActor;
			SearchActor.EventLab = this;
		}
		if (SearchActor.Tag == "BDMBunkerTarget")
		{
			actTargetBDM = SearchActor;
			SearchActor.EventLab = this;
		}
	}
	*/
	Super::DoReferenceLinking();
}

void AWF_EL_ExplosiveWeaponsRange::skiptoat4()
{
}

void AWF_EL_ExplosiveWeaponsRange::skiptobdm()
{
}
