// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_TrenchThrow/GC_EL_TrenchThrow.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/FSTS_WeaponPickup.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"

AGC_EL_TrenchThrow::AGC_EL_TrenchThrow()
{
	DrillSergeantTag = "NPC_DS_Lang";
	StationObjectiveTag = "TrenchPositionThrowObjective";
	StationBeginPointTag = "Station5_StartPt";
	bAcceptDrillSergeantUse = true;
	bStartFromDrillSergeantUse = true;
	bFadeMoveFromDrillSergeantUse = true;
	StationName = "Trench Position Throw";
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
		PlayerLock(false,false);
	}
	simulated Function NotifyFadeMoveEnd(FName PlayerMoveName)
	{
		if (PlayerMoveName == "Station5_StartPt")
		{
			ActivatePlayerBlocking(GetPlayerBlockingVolume("Station5_StartBlock"));
			ActivatePlayerBlocking(GetPlayerBlockingVolume("Station5_EndBlock"));
			SetDrillSergeantParams(false,false,false);
			DeactivateHelpMarker(HelpMarker);
			ForcePlayerCrouch(false);
			PlayerLock(true,false);
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			PlayLSAnim("gr_station5_1",DrillSergeant);
			PlayTip("Station 5","Trench Position Throw",5);
		}
		else
		{
			if (PlayerMoveName == "Station5_ThrowArea")
			{
				SetTimerEvent("ThrowGrenadesTimeout",30,0,true);
				ForcePlayerCrouch(false);
				PlayerLock(true,false);
				PlayerLock(true,false);
				PlayLSAnim("gr_station5_4",DrillSergeant);
			}
		}
	}
	simulated Function Restart()
	{
		Reset();
		DeactivateHelpMarker(HelpMarker);
		Cast<ADSController>(DrillSergeant.Controller).Walk();
		Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station5_Instruction_1");
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
		FadeOutBlack(2);
		SetTimerEvent("RestartFadeOut",3,0,false);
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		if (TimerName == "PickupGrenadeTimeout")
		{
			PlayTip("Press <ACTION> to pick up 3 grenades.","",3);
		}
		if (TimerName == "MoveToPositionTimeout")
		{
			PlayTip("Move to the throwing position.","",3);
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
			Player.SetLocation(GetActorByTag("Station5_StartPt").Location);
			Controller.SetRotation(GetActorByTag("Station5_StartPt").Rotation);
			PlayerLock(true,false);
			FadeInBlack(2);
			PlayLSAnim("gr_Station5_3",DrillSergeant);
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
			Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station5_BlockReturn");
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			GCMasterScript.SetActiveScript(GCMasterScript.Station6);
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
			PlayTip("3 Grenades taken","Moving to position behind the wall.",4);
			bAllowGrenade=false;
			FadeMoveStart(GetActorByTag("Station5_ThrowArea"),Self);
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
		if (Grenade.IsInVolume(Target))
		{
			PlayLSAnim("gr_station5_5",DrillSergeant);
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
					PlayLSAnim("gr_station5_6",DrillSergeant);
					MissedThrows ++;
					SetTimerEvent("ThrowGrenadesTimeout",30,0,true);
				}
				else
				{
					if (MissedThrows == 1)
					{
						PlayLSAnim("gr_station5_7",DrillSergeant);
						MissedThrows ++;
						SetTimerEvent("ThrowGrenadesTimeout",30,0,true);
					}
					else
					{
						if (MissedThrows == 2)
						{
							PlayTip("Station 5 Incomplete.","You need to aim more carefully",4);
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
			case "gr_station5_1":
			PlayLSAnim("gr_station5_2",DrillSergeant);
			break;
			case "gr_station5_2":
			PlayTip("Pick up 3 grenades.","",6);
			GrenadePickup.bAllowPickup=true;
			GrenadePickup.bUseActionIcon=true;
			PlayerLock(false,false);
			SetTimerEvent("PickupGrenadeTimeout",7,0,true);
			break;
			case "gr_station5_4":
			PlayTip("A grenade must land within the trench.","",6);
			bAllowGrenade=true;
			Controller.GrenadeFrag();
			bAllowGrenade=false;
			break;
			case "gr_station5_5":
			StationComplete();
			break;
			case "gr_station5_6":
			case "gr_station5_7":
			bAllowGrenade=true;
			Controller.GrenadeFrag();
			bAllowGrenade=false;
			break;
			case "gr_station5_13":
			CompleteStationFailed();
			break;
			default:
		}
		return true;
	}
	simulated Function StationFailed()
	{
		StopTimer("PickupGrenadeTimeout",0);
		StopTimer("MoveToPositionTimeout",0);
		StopTimer("ThrowGrenadesTimeout",0);
		Player.EmptyInventory();
		bStationComplete=true;
		PlayLSAnim("gr_station5_13",DrillSergeant);
		PlayerLock(true,false);
	}
	simulated Function CompleteStationFailed()
	{
		DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station5_EndBlock"));
		PlayTip(PlayerFailedStatioNString,GoToNextStationString,6);
		PlayerLock(false,false);
		bStationComplete=true;
		LogStationEnd(this,false);
		StationObjective.SetDisabled(true);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("Station5_BlockReturn").Rotation);
		SetHelpMarker(DirectionMarker,GetActorByTag("Station5_BlockReturn")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		DetectProximityToActor(GetActorByTag("Station5_BlockReturn"),Player,550,"PlayerLeaving");
	}
	simulated Function StationComplete()
	{
		DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station5_EndBlock"));
		PlayerLock(false,false);
		PlayTip(PlayerPassedStationString,GoToNextStationString,6);
		Player.EmptyInventory();
		LogStationEnd(this,true);
		StationObjective.SetDisabled(true);
		bStationComplete=true;
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("Station5_BlockReturn").Rotation);
		SetHelpMarker(DirectionMarker,GetActorByTag("Station5_BlockReturn")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		DetectProximityToActor(GetActorByTag("Station5_BlockReturn"),Player,550,"PlayerLeaving");
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this));
	}
}
*/

void AGC_EL_TrenchThrow::Reset()
{
	/*
	Super::Reset();
	SetDrillSergeantParams(true, true, true);
	StopTimerByType(ETimerType::TT_LSAnim);
	GrenadePickup.GotoState("Pickup");
	GrenadePickup.bAllowPickup = false;
	GrenadePickup.bUseActionIcon = false;
	bAllowGrenade = true;
	bAllowGrenade = false;
	Player.EmptyInventory();
	PlayerLock(false, false);
	Cast<ADSController>(DrillSergeant.Controller).Walk();
	Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station5_Instruction_1");
	Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
	DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station5_StartBlock"));
	ActivatePlayerBlocking(GetPlayerBlockingVolume("Station5_EndBlock"));
	MissedThrows = 0;
	*/
}

void AGC_EL_TrenchThrow::DoReferenceLinking()
{
	


	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "Station5_Grenade")
		{
			GrenadePickup = Cast<AFSTS_WeaponPickup>(SearchActor);
			GrenadePickup.bAllowPickup = false;
			GrenadePickup.bUseActionIcon = false;
			GrenadePickup.EventLab = this;
		}
		if (SearchActor.Tag == "Station5_ThrowArea")
		{
			ThrowPosition = SearchActor;
		}
		if (SearchActor.Tag == "Station5_Target")
		{
			Target = Volume(SearchActor);
		}
		Super::DoReferenceLinking();
	}
	*/
}
