// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_M2RangeStation/WF_EL_M2RangeStation.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Triggers/Counter/Counter.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/FSTS_WeaponPickup.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"

AWF_EL_M2RangeStation::AWF_EL_M2RangeStation()
{
	OutsideShotLimit = 1;
	iMinimumTargets = 10;
	iMaximumTargets = 15;
	WeaponName = "M2";
	StationMsg = "Station ";
	ActionMsg = "Use the <Action> key to prepare to fire the weapon.";
	MoveMsg = "Proceed to the next station.";
	StandardsMsg = "Hit %MINIMUM% of the %MAXIMUM% closest targets in your lane.";
	StationInstructionMsg = "Fire from the standing or crouched postions.";
	PracticeMsg = "Practice Beginning!";
	PracticeCountdownMsg = "Practice will begin in 10 seconds.";
	QualificationMsg = "Begin Qualification.";
	QualificationCountdownMsg = "Qualification will begin in 10 seconds.";
	WeaponPickupMsg = "Step up to the M2 and press the <Action> key.";
	WeaponReloadMsg = "Reload your weapon and fire to qualify.";
	NumRoundsMsg = "You have %NUMROUNDS% rounds.";
	SuccessMsg = "Congratulations on qualifying with the M2.";
	FailureMsg = "You failed to qualify with the M2.";
	QualificationSuccessMsg = "You qualified using only %ROUNDS% rounds.";
	QualificationFailureMsg = "You have failed to qualify.";
	StationFailureMsg = "Station 4 Failed!";
	CompleteMsg = "Station complete.";
	IncompleteMsg = "Station Incomplete!";
	DoneMsg = "You are done.";
	OutsideLaneMsg = "You have shot outside the station lane!";
	HitMsg = "You hit %HITCOUNT% targets using %NUMROUNDS% rounds.";
	ShotsFiredMsg = "%SHOTSFIRED% shots went outside your lane.";
	ResultMsg = "%STATIONSCORE% of %TOTALSCORE% targets hit.";
	NumRoundsPracticeMsg = "You have 200 rounds to practice firing at the targets.";
	DrillSergeantTag = "NPC_DS_Baker";
	StationName = "M2 Heavy Machine Gun";
	HelpInfoList = {
		FHelpInfo({"MoveToStation",5,"Move to Station 3","M2","wf_station3_11",nullptr}),
		FHelpInfo({ "PrepareToFire",5,"Use the <Action> key to prepare to fire the weapon","","wf_station3_8",nullptr })
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
		Log("Beginning ActiveExecute state for " + FString::FromInt(this),"M2_Range");
		if (! bNoGoRestart)
		{
			Lane03Counter=Counter(CaptureEvent("Lane_03_Counter_200m"));
			CaptureEventGroup("FSTS_Shot_Detection_Volume");
			CaptureEventGroup("Trigger");
			DetectProximityToActor(GetActorByTag("Station3_Start"),Player,150,"PlayerAtStation3");
			SetHelpMarker(HelpMarker,GetActorByTag("Station3_Start")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			ReCaptureEvent(Player);
		}
		else
		{
			PlayLSAnim("wf_station3_2",DrillSergeant);
		}
		Lane03Counter.NumToCount=0;
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
		Log(string(this) + " Timer_LSAnim called for " + FString::FromInt(LSName),"M2_Range");
		switch(LSName)
		{
			case "wf_station3_1":
			PlayLSAnim("wf_station3_2",DrillSergeant);
			break;
			case "wf_station3_2":
			PlayerLock(false,false);
			PlayTip(WeaponPickupMsg,"",5);
			SetHelpMarker(HelpMarker,WeaponPickup->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			DetectProximityToActor(WeaponPickup,Player,80,"WeaponPickup");
			break;
			case "wf_station3_3":
			sTempMsg=Repl(NumRoundsPracticeMsg,"%NUMROUNDS%",string(200));
			sTempMsg1=Repl(StandardsMsg,"%MINIMUM%",string(3));
			sTempMsg2=Repl(sTempMsg1," of the %MAXIMUM%","");
			PlayTip(sTempMsg2,sTempMsg,5);
			break;
			case "wf_station3_4":
			sTempMsg=Repl(NumRoundsMsg,"%NUMROUNDS%",string(50));
			PlayTip(StandardsMsg,sTempMsg,5);
			bQualification=true;
			HitCount=0;
			OutsideShotCounter=0;
			Controller.Reload();
			Player.Weapon.GetCurrentAmmoType().AmmoAmount=50;
			break;
			case "wf_station3_5":
			StationComplete();
			break;
			case "wf_station3_8":
			case "wf_station3_9":
			case "wf_station3_10":
			case "wf_station3_11":
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
		PlayTip(CompleteMsg,MoveMsg,5);
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if (AlertTag == "PlayerAtStation3")
		{
			PlayTip(StationMsg + "4",StationName,6);
			PlayerLock(true,false);
			StopHelpTimer();
			DeactivateHelpMarker(HelpMarker);
			PlayLSAnim("wf_station3_1",DrillSergeant);
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
			PlayLSAnim("wf_station3_3",DrillSergeant);
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
				PlayLSAnim("wf_station3_10",DrillSergeant);
				PlayTip(QualificationFailureMsg,IncompleteMsg,5);
				bNoGoRestart=true;
			}
			else
			{
				if (! HasTimerEventName("wf_station3_4"))
				{
					PlayLSAnim("wf_station3_4",DrillSergeant);
					sTempMsg1=Repl(HitMsg,"%HITCOUNT%",string(HitCount));
					sTempMsg1=Repl(sTempMsg1,"%NUMROUNDS%",string(100));
					sTempMsg2=Repl(ShotsFiredMsg,"%SHOTSFIRED%",string(OutsideShotCounter));
					PlayTip(sTempMsg1,sTempMsg2,5);
					AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Ammo_556mm_200_Belt");
					Lane03Counter.NumToCount=3;
				}
			}
		}
		return true;
	}
	simulated Function bool Actor_Custom(AActor* NotifyActor, Actor.EEventType Event, AActor* Instigator, FString Parms)
	{
		FString sTempMsg = "";
		Log("ActorCustom event called with parms " + FString::FromInt(NotifyActor) + ", " + FString::FromInt(Instigator) + ", " + Parms,"M2_Range");
		if (Parms == "Lane_03_Complete")
		{
			Log("EventLab got counter complete event","M2_Range");
			PlayLSAnim("wf_station3_5",DrillSergeant);
			sTempMsg=Repl(QualificationSuccessMsg,"%ROUNDS%",string((50 - ShotsRemaining)));
			PlayTip(sTempMsg,CompleteMsg,5);
			Player.EmptyInventory();
			PlayerLock(false,false);
			ForcePlayerProne(false);
			bStationComplete=true;
			return true;
		}
		if (Parms == "Shot_Out_Of_Lane")
		{
			if (OutsideShotCounter ++ > 20)
			{
				OutsideShotCounter=0;
				PlayLSAnim("wf_station3_9",DrillSergeant);
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
		Log("Ending ActiveExecute state for " + FString::FromInt(this),"M2_Range");
		Player.EmptyInventory();
	}
}
*/

void AWF_EL_M2RangeStation::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
}

void AWF_EL_M2RangeStation::DoReferenceLinking()
{
	for (TActorIterator<AActor> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator)
	{
		AActor* SearchActor = *ActorIterator;
		if (SearchActor->ActorHasTag("PickupW_FSTS_Trainer_M2_HMG"))
		{
			//Log(" Linked weapon " + SearchActor + " with tag " + SearchActor.Tag, "M2_Range");
			WeaponPickup = Cast<AFSTS_WeaponPickup>(SearchActor);
			//WeaponPickup->EventLab = this;
			WeaponPickup->bAllowPickup = false;
		}
	}
}

void AWF_EL_M2RangeStation::Reset()
{
	Super::Reset();
	//Player->EmptyInventory();
	//WeaponPickup->GotoState("Pickup");
	WeaponPickup->bAllowPickup = false;
	bQualification = false;
	bStudentHasFired = false;
	Lane03Counter->NumToCount = 0;
	HitCount = 0;
}
