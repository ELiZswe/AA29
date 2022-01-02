// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_FightingPositionThrow/GC_EL_FightingPositionThrow.h"

AGC_EL_FightingPositionThrow::AGC_EL_FightingPositionThrow()
{
	DrillSergeantTag = "NPC_DS_Acosta";
	StationObjectiveTag = "FightingPositionThrowObjective";
	StationBeginPointTag = "Station1_StartPt";
	bAcceptDrillSergeantUse = true;
	bStartFromDrillSergeantUse = true;
	bFadeMoveFromDrillSergeantUse = true;
	StationName = "Fighting Position 35M Throw";
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
		PlayerLock(false,false);
	}
	simulated Function NotifyFadeMoveEnd(FName PlayerMovePoint)
	{
		if (PlayerMovePoint == "Station1_StartPt")
		{
			ActivatePlayerBlocking(GetPlayerBlockingVolume("Station1_StartBlock"));
			ActivatePlayerBlocking(GetPlayerBlockingVolume("Station1_EndBlock"));
			SetDrillSergeantParams(false,false,false);
			DeactivateHelpMarker(HelpMarker);
			DSController(DrillSergeant.Controller).TurnTowardPlayer();
			ForcePlayerCrouch(false);
			PlayerLock(true,false);
			PlayLSAnim("gr_station1_1",DrillSergeant);
			PlayTip("Station 1","Fighting Position 35 Meter Throw",5);
		}
		else
		{
			if (PlayerMovePoint == "Station1_ThrowArea")
			{
				ForcePlayerCrouch(false);
				PlayerLock(true,false);
				PlayLSAnim("gr_station1_4",DrillSergeant);
			}
		}
	}
	simulated Function Restart()
	{
		Reset();
		DeactivateHelpMarker(HelpMarker);
		DSController(DrillSergeant.Controller).Walk();
		DSController(DrillSergeant.Controller).MoveToPoint("Station1_Instruction_1");
		DSController(DrillSergeant.Controller).TurnTowardPlayer();
		FadeOutBlack(2);
		SetTimerEvent("RestartFadeOut",3,0,false);
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		if (TimerName == "PickupGrenadeTimeout")
		{
			PlayTip("Press <ACTION> to pick up 3 grenades.","",3);
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
			Player.SetLocation(GetActorByTag("Station1_StartPt").Location);
			Controller.SetRotation(GetActorByTag("Station1_StartPt").Rotation);
			PlayerLock(true,false);
			FadeInBlack(2);
			PlayLSAnim("gr_station1_3",DrillSergeant);
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
			DSController(DrillSergeant.Controller).Walk();
			DSController(DrillSergeant.Controller).MoveToPoint("Station1_BlockReturn");
			DSController(DrillSergeant.Controller).TurnTowardPlayer();
			GCMasterScript.SetActiveScript(GCMasterScript.Station2);
		}
	}
	simulated Function bool Pickup_PickedUp(APickup* PickupInQuestion, AActor* Instigator, FString Parms)
	{
		if (PickupInQuestion == GrenadePickup)
		{
			StopTimer("PickupGrenadeTimeout",0);
			GrenadePickup.bAllowPickup=false;
			GrenadePickup.bUseActionIcon=false;
			DeactivateHelpMarker(HelpMarker);
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Throw_MILES_Grenade");
			AGP_Character(Player).CreateInventoryFromName("AGP_Inventory.Throw_MILES_Grenade");
			PlayTip("3 Grenades taken","",4);
			bAllowGrenade=false;
			FadeMoveStart(GetActorByTag("Station1_ThrowArea"),Self);
		}
		return true;
	}
	Function GrenadeExploded(AActor* Grenade, Actor.EEventType Event, AActor* Instigator, FString Parms)
	{
		FVector ExplodeLoc = FVector(0,0,0);
		if (Grenade == nullptr)
		{
			Log("Grenade is none, breaking out of GrenadeExploded()");
			return;
		}
		StopTimer("ThrowGrenadesTimeout",0);
		ExplodeLoc=Grenade.Location;
		if ((VSize((ExplodeLoc - Target1.Location)) < float(250)) || (VSize((ExplodeLoc - target2.Location)) < float(250)))
		{
			PlayLSAnim("gr_station1_7",DrillSergeant);
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
					PlayLSAnim("gr_station1_5",DrillSergeant);
					MissedThrows ++;
					SetTimerEvent("ThrowGrenadesTimeout",30,0,true);
				}
				else
				{
					if (MissedThrows == 1)
					{
						PlayLSAnim("gr_station1_6",DrillSergeant);
						MissedThrows ++;
						SetTimerEvent("ThrowGrenadesTimeout",30,0,true);
					}
					else
					{
						if (MissedThrows == 2)
						{
							PlayTip("Station 1 Failed.","You need to aim more carefully",4);
							StationFailed();
						}
					}
				}
			}
		}
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		switch(LSName)
		{
			case "gr_station1_1":
			PlayLSAnim("gr_station1_2",DrillSergeant);
			break;
			case "gr_station1_2":
			PlayLSAnim("gr_station1_3",DrillSergeant);
			break;
			case "gr_station1_3":
			PlayTip("Press <ACTION> to pick up 3 grenades.","",5);
			GrenadePickup.bAllowPickup=true;
			GrenadePickup.bUseActionIcon=true;
			PlayerLock(false,false);
			SetTimerEvent("PickupGrenadeTimeout",7,0,true);
			break;
			case "gr_station1_4":
			PlayTip("You must get a grenade within 5 meters of the targets.","",6);
			bAllowGrenade=true;
			Controller.GrenadeFrag();
			bAllowGrenade=false;
			break;
			case "gr_station1_5":
			case "gr_station1_6":
			bAllowGrenade=true;
			Controller.GrenadeFrag();
			bAllowGrenade=false;
			break;
			case "gr_station1_7":
			StationComplete();
			break;
			case "gr_station1_14":
			CompleteStationFailed();
			break;
			default:
		}
		return true;
	}
	simulated Function StationFailed()
	{
		StopTimer("PickupGrenadeTimeout",0);
		StopTimer("ThrowGrenadesTimeout",0);
		Player.EmptyInventory();
		bStationComplete=true;
		PlayLSAnim("gr_station1_14",DrillSergeant);
	}
	simulated Function CompleteStationFailed()
	{
		DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station1_EndBlock"));
		PlayTip(PlayerFailedStatioNString,GoToNextStationString,6);
		Player.EmptyInventory();
		bStationComplete=true;
		LogStationEnd(Self,false);
		StationObjective.SetDisabled(true);
		PlayerLock(false,false);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("Station1_BlockReturn").Rotation);
		SetHelpMarker(DirectionMarker,GetActorByTag("Station1_BlockReturn").Location,HelpMarkerLargeOffset,true,true);
		DetectProximityToActor(GetActorByTag("Station1_BlockReturn"),Player,550,"PlayerLeaving");
	}
	simulated Function StationComplete()
	{
		DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station1_EndBlock"));
		PlayTip(PlayerPassedStationString,GoToNextStationString,6);
		Player.EmptyInventory();
		bStationComplete=true;
		LogStationEnd(Self,true);
		StationObjective.SetDisabled(true);
		PlayerLock(false,false);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("Station1_BlockReturn").Rotation);
		SetHelpMarker(DirectionMarker,GetActorByTag("Station1_BlockReturn").Location,HelpMarkerLargeOffset,true,true);
		DetectProximityToActor(GetActorByTag("Station1_BlockReturn"),Player,550,"PlayerLeaving");
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " $ string(Self));
	}
}
*/

void AGC_EL_FightingPositionThrow::Reset()
{
	/*
	SetDrillSergeantParams(true, true, true);
	MissedThrows = 0;
	StopTimerByType(3);
	GrenadePickup.GotoState("Pickup");
	GrenadePickup.bAllowPickup = false;
	GrenadePickup.bUseActionIcon = false;
	bAllowGrenade = false;
	Player.EmptyInventory();
	PlayerLock(false, false);
	DSController(DrillSergeant.Controller).Walk();
	DSController(DrillSergeant.Controller).MoveToPoint("Station1_Instruction_1");
	DSController(DrillSergeant.Controller).TurnTowardPlayer();
	DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station1_StartBlock"));
	ActivatePlayerBlocking(GetPlayerBlockingVolume("Station1_EndBlock"));
	*/
	Super::Reset();
}

void AGC_EL_FightingPositionThrow::DoReferenceLinking()
{
	/*
	local Actor SearchActor;
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "Station1_Grenade")
		{
			GrenadePickup = FSTS_WeaponPickup(SearchActor);
			GrenadePickup.bAllowPickup = false;
			GrenadePickup.bUseActionIcon = false;
			GrenadePickup.EventLab = Self;
		}
		if (SearchActor.Tag == "Station1_ThrowArea")
		{
			ThrowPosition = SearchActor;
		}
		if (SearchActor.Tag == "Station1_Target1")
		{
			Target1 = SearchActor;
		}
		if (SearchActor.Tag == "Station1_Target2")
		{
			target2 = SearchActor;
		}
	}
	*/
	Super::DoReferenceLinking();
}
