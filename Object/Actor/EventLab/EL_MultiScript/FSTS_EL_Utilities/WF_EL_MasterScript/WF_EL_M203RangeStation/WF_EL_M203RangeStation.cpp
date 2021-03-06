// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_M203RangeStation/WF_EL_M203RangeStation.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Triggers/Counter/Counter.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/FSTS_WeaponPickup.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"

AWF_EL_M203RangeStation::AWF_EL_M203RangeStation()
{
	OutsideShotLimit = 1;
	iMinimumTargets = 10;
	iMaximumTargets = 15;
	WeaponName = "M203";
	StationMsg = "Station ";
	ActionMsg = "Use the <Action> key to prepare to fire the weapon.";
	MoveMsg = "Proceed to the next station.";
	StandardsMsg = "Shoot all %MINIMUM% of %MAXIMUM% rounds at the targets in your lane.";
	StationInstructionMsg = "Put one through the bunker window to qualify.";
	PracticeMsg = "Practice Beginning!";
	PracticeCountdownMsg = "Practice will begin in 10 seconds.";
	QualificationMsg = "Begin Qualification.";
	QualificationCountdownMsg = "Qualification will begin in 10 seconds.";
	WeaponPickupMsg = "Step over to the M203 firing position.";
	WeaponReloadMsg = "Reload your weapon and fire to qualify.";
	NumRoundsMsg = "You have %NUMROUNDS% rounds.";
	SuccessMsg = "Congratulations on qualifying with the M203.";
	FailureMsg = "You failed to qualify with the M203.";
	QualificationSuccessMsg = "You qualified using only %ROUNDS% rounds.";
	QualificationFailureMsg = "You have failed to qualify.";
	StationFailureMsg = "Station 5 Failed!";
	CompleteMsg = "Station complete.";
	IncompleteMsg = "Station Incomplete!";
	DoneMsg = "You are done.";
	OutsideLaneMsg = "You have shot outside the station lane!";
	HitMsg = "You hit %HITCOUNT% targets using %NUMROUNDS% rounds.";
	ShotsFiredMsg = "%SHOTSFIRED% shots went outside your lane.";
	ResultMsg = "%STATIONSCORE% of %TOTALSCORE% targets hit.";
	DrillSergeantTag = "NPC_DS_Koch";
	StationName = "M203 Grenade Launcher";
	HelpInfoList = {
		FHelpInfo({"MoveToStation",5,"Move to Station 4","M203","None",nullptr}),
		FHelpInfo({ "PrepareToFire",5,"Use the <Action> key to prepare to fire the weapon","","wf_station3_8",nullptr})
	};
	bDormant = true;
	bMasterScript = false;
	bDoGeneralInit = false;
}

/*
simulated State ActiveExecute
{
	simulated Function BeginState()
	{
		Log("Beginning ActiveExecute state for " + FString::FromInt(this),"M203_Range");
		if (! bNoGoRestart)
		{
			Lane04Counter=Counter(CaptureEvent("Lane_04_Window_Counter_100m"));
			CaptureEventGroup("FSTS_Shot_Detection_Volume");
			CaptureEventGroup("Trigger");
			DetectProximityToActor(GetActorByTag("Station4_Start"),Player,150,"PlayerAtStation4");
			SetHelpMarker(HelpMarker,GetActorByTag("Station4_Start")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			StartHelpTimer(0,true);
			ReCaptureEvent(Player);
		}
		else
		{
			PlayLSAnim("wf_station4_1",DrillSergeant);
		}
		Lane04Counter.NumToCount=0;
		bQualification=false;
		bStudentHasFired=false;
		HitCount=0;
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		HandleHelpTimerEvent(TimerName);
		return true;
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		FString sTempMsg = "";
		FString sTempMsg1 = "";
		FString sTempMsg2 = "";
		Log(" Timer_LSAnim called for " + FString::FromInt(LSName),"M203_Range");
		switch(LSName)
		{
			case "wf_station4_1":
			PlayerLock(false,false);
			PlayTip(WeaponPickupMsg,"",5);
			SetHelpMarker(HelpMarker,WeaponPickup->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			DetectProximityToActor(WeaponPickup,Player,80,"WeaponPickup");
			break;
			case "wf_station4_2":
			sTempMsg1=Repl(StandardsMsg,"%MINIMUM%",string(12));
			sTempMsg2=Repl(sTempMsg1," of %MAXIMUM%","");
			PlayTip(sTempMsg2,"",5);
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			break;
			case "wf_station4_3":
			sTempMsg=Repl(NumRoundsMsg,"%NUMROUNDS%",string(3));
			PlayTip(StationInstructionMsg,sTempMsg,5);
			bQualification=true;
			HitCount=0;
			OutsideShotCounter=0;
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_40mm_1_Gren");
			Controller.Reload();
			break;
			case "wf_Station4_4":
			StationComplete();
			break;
			case "wf_Station4_9":
			case "wf_Station4_7":
			Reset();
			BeginState();
			break;
			default:
		}
		return true;
	}
	simulated Function StationComplete()
	{
		PlayTip(CompleteMsg,MoveMsg,5);
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if (AlertTag == "PlayerAtStation4")
		{
			PlayTip(StationMsg + "5",StationName,6);
			PlayerLock(true,false);
			StopHelpTimer();
			DeactivateHelpMarker(HelpMarker);
			PlayLSAnim("wf_station4_1",DrillSergeant);
		}
		if (AlertTag == "WeaponPickup")
		{
			DeactivateHelpMarker(HelpMarker);
			PlayerLock(true,false);
			AGP_Character(Player).CreateInventoryFromName("FSTS.FSTS_Trainer_Weapon_M203_Gren");
			PlayLSAnim("wf_station4_2",DrillSergeant);
		}
	}
	simulated Function bool Pickup_PickedUp(APickup* PickupInQuestion, AActor* Instigator, FString Parms)
	{
		Log("PickupTaken called in " + FString::FromInt(this),"M203_Range");
		StopHelpTimer();
		if (PickupInQuestion == WeaponPickup)
		{
			StopHelpTimer();
			PlayLSAnim("wf_station4_3",DrillSergeant);
		}
		return true;
	}
	simulated Function bool AGP_Weapon_Fire(AAGP_Weapon* Weapon, AActor* Instigator, FString Parms)
	{
		FString sTempMsg1 = "";
		FString sTempMsg2 = "";
		ShotsRemaining=Weapon.GetCurrentAmmoType().AmmoAmount;
		if (bStudentHasFired == false)
		{
			StopHelpTimer();
			bStudentHasFired=true;
		}
		if (ShotsRemaining <= 0)
		{
			if (bQualification)
			{
				PlayLSAnim("wf_Station4_7",DrillSergeant);
				PlayTip(QualificationFailureMsg,IncompleteMsg,5);
				bNoGoRestart=true;
			}
			else
			{
				if (! HasTimerEventName("wf_station4_3"))
				{
					PlayLSAnim("wf_station4_3",DrillSergeant);
					sTempMsg1=Repl(HitMsg,"%HITCOUNT%",string(HitCount));
					sTempMsg1=Repl(sTempMsg1,"%NUMROUNDS%",string(14));
					sTempMsg2=Repl(ShotsFiredMsg,"%SHOTSFIRED%",string(OutsideShotCounter));
					PlayTip(sTempMsg1,sTempMsg2,5);
					Lane04Counter.NumToCount=1;
				}
			}
		}
		return true;
	}
	simulated Function bool Actor_Custom(AActor* NotifyActor, Actor.EEventType Event, AActor* Instigator, FString Parms)
	{
		FString sTempMsg = "";
		Log("ActorCustom event called with parms " + FString::FromInt(NotifyActor) + ", " + FString::FromInt(Instigator) + ", " + Parms,"M203_Range");
		if (Parms == "Lane_04_Complete")
		{
			Log("EventLab got counter complete event","M203_Range");
			PlayLSAnim("wf_Station4_4",DrillSergeant);
			sTempMsg=Repl(QualificationSuccessMsg,"%ROUNDS%",string((3 - ShotsRemaining)));
			PlayTip(sTempMsg,CompleteMsg,5);
			Player.EmptyInventory();
			PlayerLock(false,false);
			ForcePlayerProne(false);
			bStationComplete=true;
			return true;
		}
		if (Parms == "Shot_Out_Of_Lane")
		{
			if (OutsideShotCounter ++ > 2)
			{
				OutsideShotCounter=0;
				PlayLSAnim("wf_Station4_9",DrillSergeant);
				PlayTip(OutsideLaneMsg,IncompleteMsg,5);
				bNoGoRestart=true;
			}
			return true;
		}
		if (NotifyActor.Tag == "Trigger")
		{
			HitCount ++;
			return true;
		}
		return false;
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this),"M203_Range");
		Player.EmptyInventory();
	}
}
*/

void AWF_EL_M203RangeStation::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
}

void AWF_EL_M203RangeStation::DoReferenceLinking()
{
	


	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "PickupW_FSTS_Trainer_M203_Gren")
		{
			Log(" Linked weapon " + FString::FromInt(SearchActor) + " with tag " + FString::FromInt(SearchActor.Tag), "M203_Range");
			WeaponPickup = Cast<AFSTS_WeaponPickup>(SearchActor);
			WeaponPickup.EventLab = this;
			WeaponPickup.bAllowPickup = false;
		}
	}
	*/
	Super::DoReferenceLinking();
}

void AWF_EL_M203RangeStation::Reset()
{
	Super::Reset();
	//Player->EmptyInventory();
	//WeaponPickup->GotoState("Pickup");
	WeaponPickup->bAllowPickup = false;
	bQualification = false;
	bStudentHasFired = false;
	Lane04Counter->NumToCount = 0;
	HitCount = 0;
}
