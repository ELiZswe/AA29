// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_BunkerThrow/GC_EL_BunkerThrow.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/FSTS_WeaponPickup.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"

AGC_EL_BunkerThrow::AGC_EL_BunkerThrow()
{
	DrillSergeantTag = "NPC_DS_Koch";
	StationObjectiveTag = "BunkerPositionThrowObjective";
	StationBeginPointTag = "Station2_StartPt";
	bAcceptDrillSergeantUse = true;
	bStartFromDrillSergeantUse = true;
	bFadeMoveFromDrillSergeantUse = true;
	StationName = "Bunker Position Throw";
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
		Level.GamePlayMode=1;
		SetDrillSergeantParams(true,true,true);
		SetHelpMarker(HelpMarker,DrillSergeant.GetBoneCoords("head").Origin,HelpMarkerLargeOffset,true,true);
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
		PlayerLock(false,false);
	}
	simulated Function NotifyFadeMoveEnd(FName PlayerMoveName)
	{
		if (PlayerMoveName == "Station2_StartPt")
		{
			ActivatePlayerBlocking(GetPlayerBlockingVolume("Station2_StartBlock"));
			ActivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
			SetDrillSergeantParams(false,false,false);
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			DeactivateHelpMarker(HelpMarker);
			bFirstProneEvent=false;
			ForcePlayerCrouch(false);
			PlayerLock(true,false);
			PlayLSAnim("gr_station2_1",DrillSergeant);
			PlayTip("Station 2","Bunker Position Throw",5);
		}
		else
		{
			if (PlayerMoveName == "Station2_ThrowPosition")
			{
				ForcePlayerProne(true);
				bPlayerMustBeProne=true;
				PlayerLock(true,false);
				SetTimerEvent("ThrowGrenadesTimeout",30,0,true);
				PlayTip("Assault the bunker.","Try rolling grenades by pressing <ALTFIRE>",5);
			}
		}
	}
	simulated Function Restart()
	{
		Reset();
		DeactivateHelpMarker(HelpMarker);
		Cast<ADSController>(DrillSergeant.Controller).Walk();
		Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station2_Instruction_1");
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
		FadeOutBlack(2);
		SetTimerEvent("RestartFadeOut",3,0,false);
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		if (TimerName == "PickupGrenadeTimeout")
		{
			PlayTip("Press <ACTION> to pick up 3 grenades","",3);
		}
		if (TimerName == "ProneTimeout")
		{
			PlayTip("Press <Crawling> to go prone.","",3);
		}
		if (TimerName == "ThrowGrenadesTimeout")
		{
			PlayTip("You must throw within 30 seconds.","",3);
		}
		if (TimerName == "GrenadeFailsafeTimeout")
		{
			PlayTip("Grenade failed to explode.","",3);
			GrenadeExploded(nullptr,0,nullptr,"");
		}
		if (TimerName == "RestartFadeOut")
		{
			Player.SetLocation(GetActorByTag("Station2_StartPt").Location);
			Controller.SetRotation(GetActorByTag("Station2_StartPt").Rotation);
			PlayerLock(true,false);
			FadeInBlack(2);
			PlayLSAnim("gr_station2_1",DrillSergeant);
		}
		return true;
	}
	Function bool AGP_Weapon_Throw(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms)
	{
		StopTimer("ThrowGrenadesTimeout",0);
		SetTimerEvent("GrenadeFailsafeTimeout",10,0,false);
		bAllowGrenade=false;
		return true;
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if (AlertTag == "PlayerLeaving")
		{
			DeactivateHelpMarker(DirectionMarker);
			Cast<ADSController>(DrillSergeant.Controller).Walk();
			Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station2_BlockReturn");
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			GCMasterScript.SetActiveScript(GCMasterScript.Station3);
			return;
		}
	}
	simulated Function bool Pickup_PickedUp(APickup* PickupInQuestion, AActor* Instigator, FString Parms)
	{
		if (PickupInQuestion == GrenadePickup)
		{
			PlayLSAnim("gr_station2_2",DrillSergeant);
			bWaitingForStation2_2Finish=false;
			StopTimer("PickupGrenadeTimeout",0);
			GrenadePickup.bAllowPickup=false;
			GrenadePickup.bUseActionIcon=false;
			bHasGrenades=true;
			bAllowGrenade=false;
			bStationHasBegun=true;
			DeactivateHelpMarker(HelpMarker);
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Throw_MILES_Grenade");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Throw_MILES_Grenade");
			PlayTip("3 Grenades taken","Moving to throw area.",4);
			FadeMoveStart(GetActorByTag("Station2_ThrowPosition"),Self);
		}
		return true;
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		switch(LSName)
		{
			case "gr_station2_1":
			PlayerLock(false,false);
			GrenadePickup.bAllowPickup=true;
			GrenadePickup.bUseActionIcon=true;
			PlayTip("Pick up 3 grenades.","",4);
			SetTimerEvent("PickupGrenadeTimeout",7,0,true);
			break;
			case "gr_station2_2":
			PlayLSAnim("gr_station2_3",DrillSergeant);
			break;
			case "gr_station2_3":
			SetTimerEvent("ThrowGrenadesTimeout",30,0,true);
			PlayTip("Assault the bunker.","Try rolling grenades by pressing <ALTFIRE>.",6);
			bAllowGrenade=true;
			Controller.GrenadeFrag();
			bAllowGrenade=false;
			PlayerLock(false,false);
			break;
			case "gr_station2_4":
			StationComplete();
			break;
			case "gr_station2_5":
			case "gr_station2_6":
			bAllowGrenade=true;
			Controller.GrenadeFrag();
			bAllowGrenade=false;
			break;
			case "gr_station2_7":
			StationFailed();
			break;
			case "gr_station2_11":
			StationFailed();
			break;
			case "gr_station2_12":
			CompleteStationFailed();
			break;
			default:
		}
		return true;
	}
	simulated Function StationFailed()
	{
		PlayerLock(true,false);
		StopTimerByType(ETimerType::TT_Timer);
		StopTimerByType(ETimerType::TT_LSAnim);
		PlayLSAnim("gr_station2_12",DrillSergeant);
		bStationComplete=true;
		Player.EmptyInventory();
	}
	simulated Function CompleteStationFailed()
	{
		DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
		PlayTip(PlayerFailedStatioNString,GoToNextStationString,6);
		bStationComplete=true;
		LogStationEnd(this,false);
		StationObjective.SetDisabled(true);
		PlayerLock(false,false);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("Station2_BlockReturn").Rotation);
		SetHelpMarker(DirectionMarker,GetActorByTag("Station2_BlockReturn")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		DetectProximityToActor(GetActorByTag("Station2_BlockReturn"),Player,550,"PlayerLeaving");
	}
	simulated Function StationComplete()
	{
		DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
		PlayTip(PlayerPassedStationString,GoToNextStationString,6);
		ForcePlayerProne(false);
		Player.EmptyInventory();
		bStationComplete=true;
		LogStationEnd(this,true);
		StationObjective.SetDisabled(true);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("Station2_BlockReturn").Rotation);
		SetHelpMarker(DirectionMarker,GetActorByTag("Station2_BlockReturn")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		DetectProximityToActor(GetActorByTag("Station2_BlockReturn"),Player,600,"PlayerLeaving");
	}
	Function GrenadeExploded(AActor* Grenade, Actor.EEventType Event, AActor* Instigator, FString Parms)
	{
		FVector ExplodeLoc = FVector(0,0,0);
		StopTimer("ThrowGrenadesTimeout",0);
		ExplodeLoc=Grenade.Location;
		if (Grenade.IsInVolume(BunkerVolume) && bPlayerMustBeProne)
		{
			bPlayerMustBeProne=false;
			PlayLSAnim("gr_station2_4",DrillSergeant);
		}
		else
		{
			if (VSize((ExplodeLoc - DrillSergeant->GetActorLocation())) < float(100))
			{
				Pawn_Damaged_Miles(DrillSergeant,Player.Controller);
			}
			else
			{
				if (MissedThrows == 0)
				{
					PlayLSAnim("gr_station2_5",DrillSergeant);
					MissedThrows ++;
				}
				else
				{
					if (MissedThrows == 1)
					{
						PlayLSAnim("gr_station2_6",DrillSergeant);
						MissedThrows ++;
					}
					else
					{
						if (MissedThrows == 2)
						{
							PlayTip("You need to aim more carefully.","",4);
							bPlayerMustBeProne=false;
							StationFailed();
						}
					}
				}
			}
		}
	}
	simulated Function EventLabTick(float DeltaTime)
	{
		Global.FA_RucksackPickup(DeltaTime);
		if (! bStationComplete)
		{
			if (bPlayerMustBeProne)
			{
				if ((Player == nullptr) || (((Player != nullptr) && (! Player.bIsProne)) && (! Player.bWantsToProne)))
				{
					PlayerLock(true,false);
					PlayTip("You must remain prone.","Station 2 Failed.",6);
					bPlayerMustBeProne=false;
					ForcePlayerProne(false);
					PlayLSAnim("gr_station2_11",DrillSergeant);
				}
				if (FastTrace(BunkerTarget->GetActorLocation(),Player.EyePosition()))
				{
					PlayLSAnim("gr_station2_7",DrillSergeant);
					bPlayerMustBeProne=false;
					ForcePlayerProne(false);
					PlayerLock(true,false);
					PlayTip("You were seen by the enemy.","Station 2 Failed.",6);
				}
			}
		}
	}
	simulated Function CrawlEvent()
	{
		if (! bStationHasBegun)
		{
			return;
		}
		Log("CrawlEvent");
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this));
	}
}
*/

void AGC_EL_BunkerThrow::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "Station2_Grenade")
		{
			GrenadePickup = Cast<AFSTS_WeaponPickup>(SearchActor);
			GrenadePickup.bAllowPickup = false;
			GrenadePickup.bUseActionIcon = false;
			GrenadePickup.EventLab = this;
		}
		if (SearchActor.Tag == "Station2_BunkerTarget")
		{
			BunkerTarget = SearchActor;
		}
		if (SearchActor.Tag == "Station2_ThrowPosition")
		{
			ThrowPosition = SearchActor;
		}
		if (SearchActor.Tag == "Station2_Target")
		{
			BunkerVolume = Volume(SearchActor);
		}
	}
	*/
	Super::DoReferenceLinking();
}

void AGC_EL_BunkerThrow::Reset()
{
	/*
	SetDrillSergeantParams(true, true, true);
	StopTimerByType(ETimerType::TT_LSAnim);
	GrenadePickup.GotoState("Pickup");
	GrenadePickup.bAllowPickup = false;
	GrenadePickup.bUseActionIcon = false;
	bPlayerMustBeProne = false;
	bStationHasBegun = false;
	bHasGrenades = false;
	bFirstProneEvent = false;
	Player.EmptyInventory();
	PlayerLock(false, false);
	MissedThrows = 0;
	Cast<ADSController>(DrillSergeant.Controller).Walk();
	Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station2_Instruction_1");
	Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
	DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station2_StartBlock"));
	ActivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
	*/
	Super::Reset();
}
