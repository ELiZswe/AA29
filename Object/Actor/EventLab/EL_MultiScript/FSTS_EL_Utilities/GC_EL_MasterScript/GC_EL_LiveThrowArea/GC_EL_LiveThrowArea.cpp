// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_LiveThrowArea/GC_EL_LiveThrowArea.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/FSTS_WeaponPickup.h"
#include "AA29/Object/Actor/FSTS_HelpMarker/FSTS_DirectionMarker/FSTS_DirectionMarker.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_MasterScript.h"

AGC_EL_LiveThrowArea::AGC_EL_LiveThrowArea()
{
	DrillSergeantTag = "NPC_DS_Johnson";
	AltDrillSergeantTag = "NPC_DS_Kelly";
	StationObjectiveTag = "LiveThrowObjective";
	StationName = "Live Throw Pit";
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
		ReCaptureEvent(Player);
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
		FacePlayerTo(DrillSergeant,"Neck","CameraBone");
		PlayerLock(true,true);
		PlayLSAnim("gr_live1_1",DrillSergeant);
		Level.GamePlayMode=0;
	}
	simulated Function Restart()
	{
		Global.bAllowGrenade();
		PlayerLock(true,false);
		FadeOutBlack(3);
		SetTimerEvent("RestartFadeOut",3,0,false);
	}
	simulated Function RestartAtPit()
	{
		Global.bAllowGrenade();
		PlayerLock(true,false);
		FadeOutBlack(3);
		SetTimerEvent("RestartAtPitFadeOut",3,0,false);
	}
	simulated Function bool Pickup_PickedUp(APickup* PickupInQuestion, AActor* Instigator, FString Parms)
	{
		if (PickupInQuestion == GrenadePickup)
		{
			StopTimer("PickupGrenadeTimeout",0);
			GrenadePickup.bAllowPickup=false;
			GrenadePickup.bUseActionIcon=false;
			DeactivateHelpMarker(HelpMarker);
			PlayLSAnim("gr_live1_2",DrillSergeant);
			bAllowGrenade=false;
		}
		return true;
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		switch(LSName)
		{
			case "gr_live1_1":
			bDisableIdleTimers=false;
			PlayerLock(true,false);
			PlayTip("Press <ACTION> to pick up a live","grenade from the table",5);
			SetTimerEvent("PickupGrenadeTimeout",7,0,true);
			GrenadePickup.bAllowPickup=true;
			GrenadePickup.bUseActionIcon=true;
			break;
			case "gr_live1_2":
			PlayGameSound("gr_speaker_1",Player);
			break;
			case "gr_live1_3":
			PlayTip("Move out to the live throw pit","and get into position",5);
			SetTimerEvent("RangeWalkTimeout",15,0,true);
			break;
			case "gr_live2_1":
			PlayLSAnim("gr_live2_2",AltDrillSergeant);
			break;
			case "gr_live2_2":
			bDisableThrowTimers=false;
			bAllowGrenade=true;
			Controller.GrenadeFrag();
			SetTimerEvent("LiveThrowCountdown",3,0,false);
			if (Player.Weapon == nullptr)
			{
				PlayTip("Press '2' to select the grenade.","",3);
			}
			break;
			case "gr_live2_3":
			PlayTip("Aim with your raised hand.","",4);
			SetTimerEvent("PrepareThrowTimeout",3,0,false);
			break;
			case "gr_live2_4":
			SetTimerEvent("ThrowTimeout",5,0,false);
			bThrowIsAuthorized=true;
			Cast<ADSController>(AltDrillSergeant.Controller).Crouch();
			break;
			case "gr_live2_5":
			Cast<ADSController>(AltDrillSergeant.Controller).Crouch();
			break;
			case "gr_live2_6":
			PlayGameSound("gr_speaker_6",Player);
			StationComplete();
			break;
			case "gr_live2_8":
			PlayTip("Live Grenade Throw - Incomplete.","",2);
			ConsoleCommand("Reconnect");
			break;
			default:
		}
		return true;
	}
	simulated Function bool Timer_Sound(FName SoundName)
	{
		switch(SoundName)
		{
			case "gr_speaker_1":
			PlayerLock(false,false);
			PlayLSAnim("gr_live1_3",DrillSergeant);
			DetectProximityToActor(LiveThrowPosition,Player,60,"AtThrowPit");
			Cast<ADSController>(AltDrillSergeant.Controller).TurnTowardPlayer();
			SetHelpMarker(HelpMarker,LiveThrowPosition->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			SetHelpMarker(DirectionMarker,GetActorByTag("ToThrowPit")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			SetHelpMarkerRotation(DirectionMarker,GetActorByTag("ToThrowPit").Rotation);
			break;
			case "gr_speaker_3":
			if (bThrowTooShort)
			{
				PlayTip("Throw too short.","Live Grenade Throw - Incomplete.",2);
			}
			else
			{
				PlayTip("Throw only into the target area.","Live Grenade Throw - Incomplete.",2);
			}
			RestartAtPit();
			GOTO JL0221;
			case "gr_speaker_4":
			PlayLSAnim("gr_live2_3",AltDrillSergeant);
			PlayTip("Prepare The Throw","Press <FIRE> and HOLD.",3);
			GOTO JL0221;
			case "gr_speaker_5":
			PlayLSAnim("gr_live2_4",AltDrillSergeant);
			PlayTip("THROW!","Release <FIRE> to throw the grenade.",3);
			bThrowIsAuthorized=true;
			GOTO JL0221;
			default:
JL0221:
		}
		return true;
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume* NotifyActor, AActor* Instigator)
	{
		switch(NotifyActor.Tag)
		{
			case "floor_live_throw":
			case "left_wall_live_throw":
			case "rear_wall_live_throw":
			case "right_wall_live_throw":
			bLooseGrenadeOMG=true;
			PlayTip("LOOSE GRENADE!","TAKE COVER!",4);
			PlayLSAnim("gr_live2_8",AltDrillSergeant);
			break;
			default:
			break;
		}
		return true;
	}
	Function bool TriggerVolume_Exit(AGP_Gameplay.TriggerVolume* NotifyActor, AActor* Instigator)
	{
		switch(NotifyActor.Tag)
		{
			case "floor_live_throw":
			case "left_wall_live_throw":
			case "rear_wall_live_throw":
			case "right_wall_live_throw":
			if (bLooseGrenadeOMG)
			{
				break;
			}
			bLooseGrenadeOMG=true;
			PlayTip("LOOSE GRENADE!","TAKE COVER!",4);
			PlayLSAnim("gr_live2_8",AltDrillSergeant);
			break;
			default:
			break;
		}
		return true;
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		Log("Timer " + FString::FromInt(TimerName));
		if (! bDisableThrowTimers)
		{
			if (TimerName == "LiveThrowCountdown")
			{
				PlayGameSound("gr_speaker_4",Player);
				return true;
			}
			if (TimerName == "PrepareThrowTimeout")
			{
				PlayGameSound("gr_speaker_5",Player);
				return true;
			}
			if (TimerName == "LastChanceToPrepareTimeout")
			{
				PlayTip("Too slow to prepare.","Live Grenade Throw - Incomplete.",2);
				RestartAtPit();
				return true;
			}
			if (TimerName == "ThrowTimeout")
			{
				PlayTip("You must throw when told.","Live Grenade Throw - Incomplete.",2);
				RestartAtPit();
				return true;
			}
		}
		if (! bDisableIdleTimers)
		{
			if (TimerName == "PickupGrenadeTimeout")
			{
				PlayLSAnim("gr_live1_4",DrillSergeant);
				PlayTip("Press <ACTION> to pick up a live","grenade from the table",3);
				return true;
			}
			if (TimerName == "RangeWalkTimeout")
			{
				PlayTip("Move out to the live throw pit","and get into position",3);
				PlayGameSound("gr_speaker_2",Player);
				return true;
			}
		}
		if (TimerName == "RestartFadeOut")
		{
			Player.SetLocation(GetActorByTag("LiveThrow_Start").Location);
			Controller.SetRotation(GetActorByTag("LiveThrow_Start").Rotation);
			PlayerLock(true,true);
			FadeInBlack(2);
			FacePlayerTo(DrillSergeant,"Neck","CameraBone");
			PlayLSAnim("gr_live1_1",DrillSergeant);
			return true;
		}
		if (TimerName == "RestartAtPitFadeOut")
		{
			Player.SetLocation(LiveThrowPosition.Location);
			FacePlayerTo(AltDrillSergeant,"Neck","CameraBone");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Throw_M67_Frag");
			bAllowGrenade=false;
			FadeInBlack(2);
			ForcePlayerCrouch(false);
			PlayerLock(true,false);
			PlayLSAnim("gr_live2_1",AltDrillSergeant);
			return true;
		}
		if (TimerName == "fadeoutTimer")
		{
			LeavingStation();
			return true;
		}
		HandleHelpTimerEvent(TimerName);
		return true;
	}
	simulated Function StationComplete()
	{
		PlayTip("Live Grenade Throw - Complete!","",3);
		bStationComplete=true;
		LogStationEnd(this,true);
		StationObjective.SetDisabled(true);
		FadeOutBlack(2);
		SetTimerEvent("fadeoutTimer",3,0,false);
	}
	simulated Function LeavingStation()
	{
		MasterScript.SetActiveScript(Cast<AGC_EL_MasterScript>(MasterScript).ConfidenceStagingArea);
	}
	Function bool AGP_Weapon_Throw(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms)
	{
		bDisableIdleTimers=true;
		bDisableThrowTimers=true;
		StopTimer("ThrowTimeout",0);
		StopTimer("LastChanceToPrepareTimeout",0);
		if (bThrowIsAuthorized)
		{
			bThrowIsAuthorized=false;
			PlayLSAnim("gr_live2_5",AltDrillSergeant);
			PlayTip("Press the <Crouching> key to crouch down.","",3);
		}
		else
		{
			PlayTip("Do not throw until told by instructor.","Live Grenade Throw - Incomplete.",2);
			RestartAtPit();
		}
		return true;
	}
	simulated Function NotifyFadeMoveStart(FName PlayerMoveName)
	{
		if (PlayerMoveName == "LiveThrowPosition")
		{
			PlayerLock(true,false);
		}
	}
	simulated Function NotifyFadeMoveMiddle(FName PlayerMoveName)
	{
		if (PlayerMoveName == "LiveThrowPosition")
		{
			FacePlayerTo(AltDrillSergeant);
			ForcePlayerCrouch(false);
		}
	}
	simulated Function NotifyFadeMoveEnd(FName PlayerMoveName)
	{
		if (PlayerMoveName == "LiveThrowPosition")
		{
			PlayerLock(true,false);
			PlayLSAnim("gr_live2_1",AltDrillSergeant);
		}
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if (AlertTag == "AtThrowPit")
		{
			StopTimer("RangeWalkTimeout",0);
			StopHelpTimer();
			PlayerLock(true,false);
			FadeMoveStart(LiveThrowPosition,Self);
			DeactivateHelpMarker(HelpMarker);
			DeactivateHelpMarker(DirectionMarker);
			DeactivateLocationMarker(LocationMarker);
		}
	}
	Function GrenadeExploded(AActor* Grenade, Actor.EEventType Event, AActor* Instigator, FString Parms)
	{
		FVector ExplodeLoc = FVector(0,0,0);
		ExplodeLoc=Grenade.Location;
		bCrouchedInTime=(Player.bIsCrouched && Player.bWantsToCrouch);
		PlayerLock(true,false);
		if (bLooseGrenadeOMG)
		{
			return;
		}
		if (! bCrouchedInTime)
		{
			PlayTip("Crouch and remain crouched after throwing.","Live Grenade Throw - Incomplete.",2);
			RestartAtPit();
		}
		else
		{
			if ((bCrouchedInTime && (VSize((ExplodeLoc - Player.Location)) > float(787))) && (ExplodeLoc.Y < (LiveThrowPosition.Location.Y - 200)))
			{
				PlayLSAnim("gr_live2_6",AltDrillSergeant);
			}
			else
			{
				if ((VSize((ExplodeLoc - Player.Location)) > float(787)) && (ExplodeLoc.Y > (LiveThrowPosition.Location.Y + 10)))
				{
					bThrowTooShort=false;
					PlayGameSound("gr_speaker_3",Player);
				}
				else
				{
					bThrowTooShort=true;
					PlayGameSound("gr_speaker_3",Player);
				}
			}
		}
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this));
		Level.GamePlayMode=1;
	}
}
*/

void AGC_EL_LiveThrowArea::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "LiveThrow_M67")
		{
			GrenadePickup = Cast<AFSTS_WeaponPickup>(SearchActor);
			GrenadePickup.bAllowPickup = false;
			GrenadePickup.bUseActionIcon = false;
			GrenadePickup.EventLab = this;
		}
		if (SearchActor.Tag == "LiveThrowPosition")
		{
			LiveThrowPosition = SearchActor;
		}
		if ((((SearchActor.Tag == "floor_live_throw") || (SearchActor.Tag == "left_wall_live_throw")) || (SearchActor.Tag == "rear_wall_live_throw")) || (SearchActor.Tag == "right_wall_live_throw"))
		{
			Cast<ATriggerVolume>(SearchActor).bDoUnTrigger = true;
			SearchActor.EventLab = this;
		}
	}
	*/
	Super::DoReferenceLinking();
}

void AGC_EL_LiveThrowArea::Reset()
{
	StopTimer("PickupGrenadeTimeout", ETimerType::TT_Timer);
	StopTimer("ThrowTimeout", ETimerType::TT_Timer);
	StopTimer("LastChanceToPrepareTimeout", ETimerType::TT_Timer);
	StopTimer("RangeWalkTimeout", ETimerType::TT_Timer);
	bDisableThrowTimers = true;
	bDisableIdleTimers = true;
	//AltDrillSergeant->StopLIPSincAnim();
	//DrillSergeant->StopLIPSincAnim();
	if (AltDrillSergeant->bIsCrouched)
	{
		AltDrillSergeant->ShouldCrouch(false);
	}
	DeactivateHelpMarker(HelpMarker);
	DeactivateHelpMarker(DirectionMarker);
	//GrenadePickup->GotoState("Pickup");
	GrenadePickup->bAllowPickup = false;
	GrenadePickup->bUseActionIcon = false;
	bThrowIsAuthorized = false;
	bThrowTooShort = false;
	bCrouchedInTime = false;
	//Player.EmptyInventory();
	PlayerLock(false, false);
	Super::Reset();
}
