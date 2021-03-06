// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_MK19RangeStation/WF_EL_MK19RangeStation.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Triggers/Counter/Counter.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/FSTS_WeaponPickup.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"

AWF_EL_MK19RangeStation::AWF_EL_MK19RangeStation()
{
	OutsideShotLimit = 1;
	iMinimumTargets = 10;
	iMaximumTargets = 15;
	WeaponName = "MK19";
	StationMsg = "Station ";
	ActionMsg = "Use the <Action> key to prepare to fire the weapon.";
	MoveMsg = "Proceed to the next station.";
	StandardsMsg = "Hit %MINIMUM% of the %MAXIMUM% closest targets in your lane.";
	StationInstructionMsg = "Shoot all 32 rounds at the targets in your lane";
	PracticeMsg = "Practice Beginning!";
	PracticeCountdownMsg = "Practice will begin in 10 seconds.";
	QualificationMsg = "Begin Qualification.";
	QualificationCountdownMsg = "Qualification will begin in 10 seconds.";
	WeaponPickupMsg = "Step up behind the MK19 and press the <Action> key.";
	WeaponReloadMsg = "Reload your weapon and fire to qualify.";
	NumRoundsMsg = "You have %NUMROUNDS% rounds.";
	SuccessMsg = "Congratulations on qualifying with the MK19.";
	FailureMsg = "You failed to qualify with the MK19.";
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
	DrillSergeantTag = "NPC_DS_Kelly";
	StationName = "Mk.19 Automatic Grenade Launcher";
	HelpInfoList = {
		FHelpInfo({"MoveToStation",5,"Move to Station 5","MK19","None",nullptr}),
		FHelpInfo({ "PrepareToFire",5,"Use the <Action> key to prepare to fire the weapon","","wf_station5_8",nullptr })
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
		Log("Beginning ActiveExecute state for " + FString::FromInt(this),"MK19_Range");
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
		if (! bNoGoRestart)
		{
			LaneCounter=Counter(CaptureEvent("Lane_05_Counter_350m"));
			CaptureEventGroup("FSTS_Shot_Detection_Volume");
			CaptureEventGroup("Trigger");
			DetectProximityToActor(GetActorByTag("Station5_Start"),Player,150,"PlayerAtStation5");
			StartHelpTimer(0,true);
			ReCaptureEvent(Player);
		}
		else
		{
			PlayLSAnim("wf_station5_4",DrillSergeant);
		}
		LaneCounter.NumToCount=0;
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
		Log(" Timer_LSAnim called for " + FString::FromInt(LSName),"MK19_Range");
		switch(LSName)
		{
			case "wf_station5_1":
			PlayLSAnim("wf_station5_2",DrillSergeant);
			break;
			case "wf_station5_2":
			PlayLSAnim("wf_station5_3",DrillSergeant);
			break;
			case "wf_station5_3":
			PlayLSAnim("wf_station5_4",DrillSergeant);
			break;
			case "wf_station5_4":
			PlayerLock(false,false);
			PlayTip(WeaponPickupMsg,StationInstructionMsg,5);
			SetHelpMarker(HelpMarker,WeaponPickup->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			DetectProximityToActor(WeaponPickup,Player,80,"WeaponPickup");
			break;
			case "wf_station5_5":
			sTempMsg=Repl(NumRoundsMsg,"%NUMROUNDS%",string(8));
			sTempMsg1=Repl(StandardsMsg,"%MINIMUM%",string(3));
			sTempMsg2=Repl(sTempMsg1," of the %MAXIMUM%","");
			PlayTip(sTempMsg2,sTempMsg,5);
			bQualification=true;
			HitCount=0;
			OutsideShotCounter=0;
			Controller.Reload();
			Player.Weapon.GetCurrentAmmoType().AmmoAmount=8;
			break;
			case "wf_Station5_6":
			PlayTip(CompleteMsg,DoneMsg,5);
			PlayLSAnim("wf_station5_7",DrillSergeant);
			break;
			case "wf_station5_7":
			StationComplete();
			break;
			case "wf_station5_10":
			case "wf_Station5_11":
			case "wf_Station5_12":
			ForcePlayerProne(false);
			Reset();
			BeginState();
			break;
			default:
		}
		return true;
	}
	simulated Function StationComplete()
	{
		MissionComplete();
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if (AlertTag == "PlayerAtStation5")
		{
			PlayTip(StationMsg + "6",StationName,6);
			PlayerLock(true,false);
			StopHelpTimer();
			DeactivateHelpMarker(HelpMarker);
			PlayLSAnim("wf_station5_1",DrillSergeant);
		}
		if (AlertTag == "WeaponPickup")
		{
			DeactivateHelpMarker(HelpMarker);
			ForcePlayerProne(true);
			PlayerLock(true,false);
			WeaponPickup.bAllowPickup=true;
			PlayTip(ActionMsg,"",5);
			StartHelpTimer(1,true);
		}
	}
	simulated Function bool Pickup_PickedUp(APickup* PickupInQuestion, AActor* Instigator, FString Parms)
	{
		StopHelpTimer();
		if (PickupInQuestion == WeaponPickup)
		{
			StopHelpTimer();
			Player.Weapon.GetCurrentAmmoType().AmmoAmount=32;
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
		if ((! bQualification) && (ShotsRemaining > 40))
		{
			Weapon.GetCurrentAmmoType().AmmoAmount=40;
		}
		if (((! bQualification) && (ShotsRemaining <= 9)) || (bQualification && (ShotsRemaining <= 0)))
		{
			if (bQualification)
			{
				PlayLSAnim("wf_Station5_12",DrillSergeant);
				PlayTip(QualificationFailureMsg,IncompleteMsg,5);
				bNoGoRestart=true;
			}
			else
			{
				if (! HasTimerEventName("wf_station5_5"))
				{
					PlayLSAnim("wf_station5_5",DrillSergeant);
					sTempMsg1=Repl(HitMsg,"%HITCOUNT%",string(HitCount));
					sTempMsg1=Repl(sTempMsg1,"%NUMROUNDS%",string(32));
					sTempMsg2=Repl(ShotsFiredMsg,"%SHOTSFIRED%",string(OutsideShotCounter));
					PlayTip(sTempMsg1,sTempMsg2,5);
					LaneCounter.NumToCount=1;
				}
			}
		}
		return true;
	}
	simulated Function bool Actor_Custom(AActor* NotifyActor, Actor.EEventType Event, AActor* Instigator, FString Parms)
	{
		FString sTempMsg = "";
		Log("ActorCustom event called with parms " + FString::FromInt(NotifyActor) + ", " + FString::FromInt(Instigator) + ", " + Parms,"MK19_Range");
		if (Parms == "Lane_05_Complete")
		{
			Log("EventLab got counter complete event","MK19_Range");
			PlayLSAnim("wf_Station5_6",DrillSergeant);
			sTempMsg=Repl(QualificationSuccessMsg,"%ROUNDS%",string((8 - ShotsRemaining)));
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
				PlayLSAnim("wf_Station5_11",DrillSergeant);
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
		Log("Ending ActiveExecute state for " + FString::FromInt(this),"MK19_Range");
		Player.EmptyInventory();
	}
}
*/

void AWF_EL_MK19RangeStation::PostBeginPlay()
{
	Super::PostBeginPlay();
}

void AWF_EL_MK19RangeStation::Reset()
{
	Super::Reset();
	//Player->EmptyInventory();
	//WeaponPickup->GotoState("Pickup");
	WeaponPickup->bAllowPickup = false;
	bQualification = false;
	bStudentHasFired = false;
	LaneCounter->NumToCount = 0;
	HitCount = 0;
}

void AWF_EL_MK19RangeStation::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "PickupW_FSTS_Trainer_MK19_AGL")
		{
			Log(" Linked weapon " + FString::FromInt(SearchActor) + " with tag " + FString::FromInt(SearchActor.Tag), "MK19_Range");
			WeaponPickup = Cast<AFSTS_WeaponPickup>(SearchActor);
			WeaponPickup.EventLab = this;
			WeaponPickup.bAllowPickup = false;
		}
	}
	*/
}
