// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/GC_EL_MasterScript/GC_EL_VehicleThrow/GC_EL_VehicleThrow.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/FSTS_WeaponPickup.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"

AGC_EL_VehicleThrow::AGC_EL_VehicleThrow()
{
	DrillSergeantTag = "NPC_DS_Moore";
	StationObjectiveTag = "VehiclePositionThrowObjective";
	StationBeginPointTag = "Station6_StartPt";
	bAcceptDrillSergeantUse = true;
	bStartFromDrillSergeantUse = true;
	bFadeMoveFromDrillSergeantUse = true;
	StationName = "Wheeled Vehicle Throw";
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
		if (PlayerMoveName == "Station6_StartPt")
		{
			ActivatePlayerBlocking(GetPlayerBlockingVolume("Station6_StartBlock"));
			SetDrillSergeantParams(false,false,false);
			DeactivateHelpMarker(HelpMarker);
			ForcePlayerCrouch(false);
			PlayerLock(true,false);
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			PlayLSAnim("gr_station6_1",DrillSergeant);
			PlayTip("Station 6","Wheeled Vehicle Position Throw",5);
		}
		else
		{
			if (PlayerMoveName == "Station6_ThrowArea")
			{
				SetTimerEvent("ThrowGrenadesTimeout",30,0,true);
				PlayLSAnim("gr_station6_4",DrillSergeant);
				ForcePlayerCrouch(false);
				PlayerLock(true,false);
				StationObjective.SetDisabled(true);
			}
		}
	}
	simulated Function Restart()
	{
		Reset();
		DeactivateHelpMarker(HelpMarker);
		Cast<ADSController>(DrillSergeant.Controller).Walk();
		Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station6_Instruction_1");
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
			Player.SetLocation(GetActorByTag("Station6_StartPt").Location);
			Controller.SetRotation(GetActorByTag("Station6_StartPt").Rotation);
			PlayerLock(true,false);
			FadeInBlack(2);
			PlayLSAnim("gr_station6_3",DrillSergeant);
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
			PlayTip("The End","",5);
			DeactivateHelpMarker(HelpMarker);
			Cast<ADSController>(DrillSergeant.Controller).Walk();
			Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station6_BlockReturn");
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			MissionComplete();
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
			DetectProximityToActor(ThrowPosition,Player,48,"FightingPosition");
			PlayTip("3 Grenades taken","Moving to throwing position.",4);
			bAllowGrenade=false;
			FadeMoveStart(GetActorByTag("Station6_ThrowArea"),Self);
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
			PlayLSAnim("gr_station6_7",DrillSergeant,,,,5);
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
					PlayLSAnim("gr_station6_5",DrillSergeant);
					MissedThrows ++;
					SetTimerEvent("ThrowGrenadesTimeout",30,0,true);
				}
				else
				{
					if (MissedThrows == 1)
					{
						PlayLSAnim("gr_station6_6",DrillSergeant);
						MissedThrows ++;
						SetTimerEvent("ThrowGrenadesTimeout",30,0,true);
					}
					else
					{
						if (MissedThrows == 2)
						{
							PlayTip("Station 6 Failed.","You need to aim more carefully",4);
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
			case "gr_station6_1":
			PlayLSAnim("gr_station6_2",DrillSergeant);
			break;
			case "gr_station6_2":
			PlayLSAnim("gr_station6_3",DrillSergeant);
			break;
			case "gr_station6_3":
			PlayTip("Pick up 3 grenades.","",6);
			GrenadePickup.bAllowPickup=true;
			GrenadePickup.bUseActionIcon=true;
			PlayerLock(false,false);
			SetTimerEvent("PickupGrenadeTimeout",7,0,true);
			break;
			case "gr_station6_4":
			bAllowGrenade=true;
			Controller.GrenadeFrag();
			bAllowGrenade=false;
			PlayTip("You can hold <Fire> then press <AltFire> to 'cook' a grenade.","Release <Fire> to throw it.",5);
			break;
			case "gr_station6_5":
			case "gr_station6_6":
			bAllowGrenade=true;
			Controller.GrenadeFrag();
			bAllowGrenade=false;
			break;
			case "gr_station6_7":
			StationComplete();
			break;
			case "gr_station6_13":
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
		PlayLSAnim("gr_station6_13",DrillSergeant);
	}
	simulated Function CompleteStationFailed()
	{
		PlayTip(PlayerFailedStatioNString,"This completes the course",6);
		LogStationEnd(this,false);
		StationObjective.SetDisabled(true);
		bStationComplete=true;
		MissionComplete();
	}
	simulated Function StationComplete()
	{
		Player.EmptyInventory();
		LogStationEnd(this,true);
		StationObjective.SetDisabled(true);
		PlayTip(PlayerPassedStationString,"This completes the course",6);
		bStationComplete=true;
		MissionComplete();
	}
	simulated Function EndState()
	{
		Log("Ending ActiveExecute state for " + FString::FromInt(this));
	}
}
*/

void AGC_EL_VehicleThrow::Reset()
{
	Super::Reset();
	SetDrillSergeantParams(true, true, true);
	StopTimerByType(ETimerType::TT_LSAnim);
	//GrenadePickup->GotoState("Pickup");
	GrenadePickup->bAllowPickup = false;
	GrenadePickup->bUseActionIcon = false;
	bAllowGrenade = false;
	//Player->EmptyInventory();
	PlayerLock(false, false);
	Cast<ADSController>(DrillSergeant->Controller)->Walk();
	Cast<ADSController>(DrillSergeant->Controller)->MoveToPoint("Station6_Instruction_1");
	Cast<ADSController>(DrillSergeant->Controller)->TurnTowardPlayer();
	DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station6_StartBlock"));
	MissedThrows = 0;
}

void AGC_EL_VehicleThrow::DoReferenceLinking()
{
	


	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "Station6_Grenade")
		{
			GrenadePickup = Cast<AFSTS_WeaponPickup>(SearchActor);
			GrenadePickup.bAllowPickup = false;
			GrenadePickup.bUseActionIcon = false;
			GrenadePickup.EventLab = this;
		}
		if (SearchActor.Tag == "Station6_ThrowArea")
		{
			ThrowPosition = SearchActor;
		}
		if (SearchActor.Tag == "Station6_Target")
		{
			Target = Volume(SearchActor);
		}
	}
	Super::DoReferenceLinking();
	*/
}
