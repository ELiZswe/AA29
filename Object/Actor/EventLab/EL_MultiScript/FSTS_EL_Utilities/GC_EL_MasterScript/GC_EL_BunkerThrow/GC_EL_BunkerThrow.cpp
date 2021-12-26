// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_BunkerThrow/GC_EL_BunkerThrow.h"

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
		Log("Beginning ActiveExecute state for " $ string(Self));
		Level.GamePlayMode=1;
		SetDrillSergeantParams(true,true,true);
		SetHelpMarker(HelpMarker,DrillSergeant.GetBoneCoords("head").Origin,HelpMarkerLargeOffset,true,true);
		DSController(DrillSergeant.Controller).TurnTowardPlayer();
		PlayerLock(false,false);
	}
	simulated Function NotifyFadeMoveEnd(FName PlayerMoveName)
	{
		if (PlayerMoveName == "Station2_StartPt")
		{
			ActivatePlayerBlocking(GetPlayerBlockingVolume("Station2_StartBlock"));
			ActivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
			SetDrillSergeantParams(false,false,false);
			DSController(DrillSergeant.Controller).TurnTowardPlayer();
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
		DSController(DrillSergeant.Controller).Walk();
		DSController(DrillSergeant.Controller).MoveToPoint("Station2_Instruction_1");
		DSController(DrillSergeant.Controller).TurnTowardPlayer();
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
			GrenadeExploded(None,0,None,"");
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
	Function bool AGP_Weapon_Throw(AGP_Weapon NotifyActor, Actor Instigator, FString Parms)
	{
		StopTimer("ThrowGrenadesTimeout",0);
		SetTimerEvent("GrenadeFailsafeTimeout",10,0,false);
		bAllowGrenade=false;
		return true;
	}
	simulated Function ActorProximityAlert(Actor ProximityActor, FName AlertTag)
	{
		if (AlertTag == "PlayerLeaving")
		{
			DeactivateHelpMarker(DirectionMarker);
			DSController(DrillSergeant.Controller).Walk();
			DSController(DrillSergeant.Controller).MoveToPoint("Station2_BlockReturn");
			DSController(DrillSergeant.Controller).TurnTowardPlayer();
			GCMasterScript.SetActiveScript(GCMasterScript.Station3);
			return;
		}
	}
	simulated Function bool Pickup_PickedUp(Pickup PickupInQuestion, Actor Instigator, FString Parms)
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
		StopTimerByType(0);
		StopTimerByType(3);
		PlayLSAnim("gr_station2_12",DrillSergeant);
		bStationComplete=true;
		Player.EmptyInventory();
	}
	simulated Function CompleteStationFailed()
	{
		DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
		PlayTip(PlayerFailedStatioNString,GoToNextStationString,6);
		bStationComplete=true;
		LogStationEnd(Self,false);
		StationObjective.SetDisabled(true);
		PlayerLock(false,false);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("Station2_BlockReturn").Rotation);
		SetHelpMarker(DirectionMarker,GetActorByTag("Station2_BlockReturn").Location,HelpMarkerLargeOffset,true,true);
		DetectProximityToActor(GetActorByTag("Station2_BlockReturn"),Player,550,"PlayerLeaving");
	}
	simulated Function StationComplete()
	{
		DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
		PlayTip(PlayerPassedStationString,GoToNextStationString,6);
		ForcePlayerProne(false);
		Player.EmptyInventory();
		bStationComplete=true;
		LogStationEnd(Self,true);
		StationObjective.SetDisabled(true);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("Station2_BlockReturn").Rotation);
		SetHelpMarker(DirectionMarker,GetActorByTag("Station2_BlockReturn").Location,HelpMarkerLargeOffset,true,true);
		DetectProximityToActor(GetActorByTag("Station2_BlockReturn"),Player,600,"PlayerLeaving");
	}
	Function GrenadeExploded(Actor Grenade, Actor.EEventType Event, Actor Instigator, FString Parms)
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
			if (VSize((ExplodeLoc - DrillSergeant.Location)) < float(100))
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
				if ((Player == nullptr) || (((Player != None) && (! Player.bIsProne)) && (! Player.bWantsToProne)))
				{
					PlayerLock(true,false);
					PlayTip("You must remain prone.","Station 2 Failed.",6);
					bPlayerMustBeProne=false;
					ForcePlayerProne(false);
					PlayLSAnim("gr_station2_11",DrillSergeant);
				}
				if (FastTrace(BunkerTarget.Location,Player.EyePosition()))
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
		Log("Ending ActiveExecute state for " $ string(Self));
	}
}
*/

void AGC_EL_BunkerThrow::DoReferenceLinking()
{
	/*
	local Actor SearchActor;
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "Station2_Grenade")
		{
			GrenadePickup = FSTS_WeaponPickup(SearchActor);
			GrenadePickup.bAllowPickup = false;
			GrenadePickup.bUseActionIcon = false;
			GrenadePickup.EventLab = Self;
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
	StopTimerByType(3);
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
	DSController(DrillSergeant.Controller).Walk();
	DSController(DrillSergeant.Controller).MoveToPoint("Station2_Instruction_1");
	DSController(DrillSergeant.Controller).TurnTowardPlayer();
	DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station2_StartBlock"));
	ActivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
	*/
	Super::Reset();
}
