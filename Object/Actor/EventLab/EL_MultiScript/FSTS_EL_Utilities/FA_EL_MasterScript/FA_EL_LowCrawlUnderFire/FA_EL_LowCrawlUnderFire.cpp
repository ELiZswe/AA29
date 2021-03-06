// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_LowCrawlUnderFire/FA_EL_LowCrawlUnderFire.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_DS_Acosta.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M249MuzzleFlash/M249MuzzleFlash.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/M83SmokeEmitter/M83SmokeEmitter.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M83_Smoke/PickupT_M83_Smoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"

AFA_EL_LowCrawlUnderFire::AFA_EL_LowCrawlUnderFire()
{
	DrillSergeantTag = "FA_NPC_DS_Acosta";
	StationObjectiveTag = "Station2Objective";
	StationName = "Low Crawl and Concealment Under Fire";
	HelpInfoList = {
		FHelpInfo({"HitTheDirt",30,"Press <Crawling> to get into the prone position","","fa_station2_8",nullptr}),
		FHelpInfo({ "CrawlForward",30,"Press <MoveForward> to low-crawl forward","","fa_station2_8",nullptr })
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
		Log("Beginning ActiveExecute state for " + FString::FromInt(this));
		Cast<ADSController>(DS_Acosta.Controller).TurnTowardPlayer();
		PlayLSAnim("fa_station2_1",DS_Acosta);
		SetPlayerWeapon(true,true);
		PlayerLock(true,false);
		QueueFiring(10);
		PlayTip("Quickly press <Crawling> to get into the prone position.","",5);
		DeactivateHelpMarker(HelpMarker);
		if (Player.bIsProne)
		{
			CrawlEvent();
		}
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume* NotifyActor, AActor* Instigator)
	{
		switch(NotifyActor.Tag)
		{
			case "LowCrawl_OutsideTrench":
			if (bStationComplete)
			{
				return true;
				break;
			}
			bPlayerStoodUp=true;
			RemoveGrenadeFromInventory();
			PlayerLock(true,false);
			PlayerNoGoAwarded();
			return true;
		}
		GOTO JL004D;
		default:
		GOTO JL004D;
JL004D:
		return false;
	}
	Function bool Volume_Enter(AVolume* NotifyActor, AActor* Instigator)
	{
		Log("Volume enter called for " + FString::FromInt(NotifyActor.Tag));
		switch(NotifyActor.Tag)
		{
			case "Station_2_StartCrawl":
			if ((! bPlayerReachedFirstBoulder) && (! bStationComplete))
			{
				Cast<ADSController>(DS_Acosta.Controller).MoveToPoint("Station_2_Instruction_2");
				Cast<ADSController>(DS_Acosta.Controller).TurnTowardPlayer();
				PlayLSAnim("fa_station2_4",DS_Acosta);
				PlayTip("You are in position.","",3);
				DeactivateHelpMarker(HelpMarker);
				DeactivateLocationMarker(LocationMarker);
				bPlayerReachedFirstBoulder=true;
				PlayerLock(true,false);
				DetectProximityToActor(GetActorByTag("Station_2_SmokeGrenade"),Player,500,"NearSmokeGrenade");
				StopHelpTimer();
				return true;
			}
			break;
			case "Station_2_SmokeGrenade":
			if ((SmokeGrenadeStatus == 0) && (! bStationComplete))
			{
				DeactivateLocationMarker(LocationMarker);
				DeactivateHelpMarker(HelpMarker);
				PlayTip("You are in position.","",4);
				PlayLSAnim("fa_station2_5",DS_Acosta);
				SmokeGrenadeStatus=1;
				PlayerLock(true,false);
				return true;
			}
			break;
			case "Station_2_CheckGrenade":
			if ((SmokeGrenadeStatus != 2) && (! bStationComplete))
			{
				RemoveGrenadeFromInventory();
				PlayerLock(true,false);
				PlayerNoGoAwarded();
			}
			return true;
			break;
			case "Station_2_EndCrawl":
			if (! bStationComplete)
			{
				PlayerLock(true,false);
				bPlayerMustBeProne=false;
				DeactivateHelpMarker(HelpMarker);
				Cast<ADSController>(DS_Acosta.Controller).Walk();
				Cast<ADSController>(DS_Acosta.Controller).TurnTowardPlayer();
				PlayLSAnim("fa_station2_6",DS_Acosta);
				PlayTip("You have reached the end of the crawl zone.","",4);
				return true;
			}
			break;
			default:
		}
		return false;
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if ((AlertTag == "NearSmokeGrenade") && (! bStationComplete))
		{
			if (DrillSergeant.bIsCrouched)
			{
				DrillSergeant.ShouldCrouch(false);
			}
			Cast<ADSController>(DS_Acosta.Controller).MoveToPoint("Station_2_Instruction_3");
			Cast<ADSController>(DS_Acosta.Controller).TurnTowardPlayer();
		}
	}
	simulated Function EventLabTick(float DeltaTime)
	{
		Global.FA_RucksackPickup(DeltaTime);
		if (bPlayerMustBeProne)
		{
			if (((Player == nullptr) || (((Player != nullptr) && (! Player.bIsProne)) && (! Player.bWantsToProne))) && (! bNoGoMessageStarted))
			{
				PlayerLock(true,true);
				bPlayerStoodUp=true;
				PlayerNoGoAwarded();
			}
		}
	}
	Function GrenadeExploded(AActor* Grenade, Actor.EEventType Event, AActor* Instigator, FString Parms)
	{
		if (Grenade.IsInVolume(GrenadeExplodeVolume))
		{
			SmokeGrenadeStatus=2;
			StartTimer("SmokeGrenadeEnd",40,false);
		}
		else
		{
			bBadSmokeGrenadeThrow=true;
			PlayerNoGoAwarded();
		}
	}
	simulated Function PlayerNoGoAwarded()
	{
		if (bBadSmokeGrenadeThrow)
		{
			QueueFiring(10);
			FSTS_FA_Pawn(Player).PlayMILESDeathTone();
			bPlayerNoGo=true;
			bNoGoMessageStarted=true;
			StopHelpTimer();
			StopTimerByType(ETimerType::TT_Timer);
			StopTimerByType(ETimerType::TT_LSAnim);
			DrillSergeant->StopLIPSincAnim();
			PlayLSAnim("fa_station2_9",DS_Acosta);
			PlayerLock(true,false);
			PlayTip("Your grenade didn't land in an effective spot.","",4);
			return;
		}
		if (((! bFriendlyFireFailure) && (! bPlayerWaitedTooLong)) || bPlayerStoodUp)
		{
			QueueFiring(10);
			FSTS_FA_Pawn(Player).PlayMILESDeathTone();
			bPlayerNoGo=true;
			bNoGoMessageStarted=true;
			StopHelpTimer();
			StopTimerByType(ETimerType::TT_Timer);
			StopTimerByType(ETimerType::TT_LSAnim);
			DrillSergeant->StopLIPSincAnim();
			PlayLSAnim("fa_station2_8",DS_Acosta);
			PlayerLock(true,false);
			PlayTip("You have been hit by enemy fire!","",5);
			return;
		}
		if (bPlayerWaitedTooLong)
		{
			QueueFiring(8);
			FSTS_FA_Pawn(Player).PlayMILESDeathTone();
			bPlayerNoGo=true;
			bNoGoMessageStarted=true;
			StopHelpTimer();
			StopTimerByType(ETimerType::TT_Timer);
			StopTimerByType(ETimerType::TT_LSAnim);
			DrillSergeant->StopLIPSincAnim();
			PlayLSAnim("fa_station2_9",DS_Acosta);
			PlayerLock(true,false);
			PlayTip("You waiting too long to move out!","",4);
			return;
		}
		if (SmokeGrenadeStatus == 1)
		{
			FSTS_FA_Pawn(Player).PlayMILESDeathTone();
			bPlayerNoGo=true;
			bNoGoMessageStarted=true;
			StopHelpTimer();
			StopTimerByType(ETimerType::TT_Timer);
			StopTimerByType(ETimerType::TT_LSAnim);
			DrillSergeant->StopLIPSincAnim();
			PlayLSAnim("fa_station2_9",DS_Acosta);
			PlayerLock(true,false);
			PlayTip("Use the smoke grenade before crawling out into the open!","",4);
			return;
		}
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(string(this) + " Timer_LSAnim called for " + FString::FromInt(LSName));
		switch(LSName)
		{
			case "fa_station2_1":
			if (bWaitingForStation2_1Finish)
			{
				PlayLSAnim("fa_station2_2",DS_Acosta);
				bWaitingForStation2_1Finish=false;
				break;
			}
			StartHelpTimer(0,true);
		}
		return true;
		case "fa_station2_2":
		PlayLSAnim("fa_station2_3",DS_Acosta);
		return true;
		case "fa_station2_3":
		SetLocationMarker(LocationMarker,GetActorByTag("Station_2_Boulder_Marker")->GetActorLocation(),,true);
		SetHelpMarker(HelpMarker,GetActorByTag("Station_2_Boulder_Marker")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		QueueFiring(10);
		StartTimer("Butt_Down_Reminder",6,false);
		PlayerLock(false,false);
		StartHelpTimer(1,true);
		return true;
		case "fa_station2_4":
		PlayerLock(false,false);
		StartTimer("MovingToSecondBoulder",2,false);
		SetLocationMarker(LocationMarker,GetActorByTag("Station_2_Sandbag_Marker")->GetActorLocation(),,true);
		SetHelpMarker(HelpMarker,GetActorByTag("Station_2_Sandbag_Marker")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		return true;
		case "fa_station2_5":
		Player.CreateInventoryFromName("AGP_Inventory.Throw_M83_Smoke",false);
		Controller.GrenadeSmoke();
		PlayTip("Throw the smoke grenade between you and the arrow to mask the trail.","",6);
		SetLocationMarker(LocationMarker,GetActorByTag("Station_2_Finishline_Marker")->GetActorLocation(),,true);
		SetHelpMarker(HelpMarker,GetActorByTag("Station_2_Finishline_Marker")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		PlayerLock(false,false);
		return true;
		case "fa_station2_6":
		StationCompleted();
		return true;
		case "fa_station2_7":
		return true;
		case "fa_station2_8":
		case "fa_station2_9":
		if (bPlayerNoGo)
		{
			StationCompletedFailed();
		}
		return true;
		default:
		return false;
	}
	simulated Function StationCompletedFailed()
	{
		bStationComplete=true;
		StationObjective.SetDisabled(true);
		LogStationEnd(this,false);
		StopTimerByType(ETimerType::TT_Timer);
		bPlayerMustBeProne=false;
		PlayerLock(false,false);
		ForcePlayerCrouch(false);
		PlayTip("Station 2 - Low Crawl and Concealment Failed","",4);
		RemoveGrenadeFromInventory();
		SetHelpMarker(DirectionMarker,GetActorByTag("ToStation3")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("ToStation3").Rotation);
		Cast<ADSController>(DS_Acosta.Controller).Stand();
		Cast<ADSController>(DS_Acosta.Controller).Run();
		Cast<ADSController>(DS_Acosta.Controller).MoveToPoint("Station_2_Block_Return");
		Cast<ADSController>(DS_Acosta.Controller).TurnTowardPlayer();
		DeactivateHelpMarker(HelpMarker);
		DeactivateLocationMarker(LocationMarker);
		FAMasterScript.DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
	}
	simulated Function StationCompleted()
	{
		bStationComplete=true;
		StationObjective.SetDisabled(true);
		LogStationEnd(this,true);
		StopTimerByType(ETimerType::TT_Timer);
		bPlayerMustBeProne=false;
		PlayerLock(false,false);
		ForcePlayerCrouch(false);
		PlayTip("Station 2 - Low Crawl and Concealment Completed","",4);
		SetHelpMarker(DirectionMarker,GetActorByTag("ToStation3")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("ToStation3").Rotation);
		Cast<ADSController>(DS_Acosta.Controller).Walk();
		Cast<ADSController>(DS_Acosta.Controller).MoveToPoint("Station_2_Block_Return");
		Cast<ADSController>(DS_Acosta.Controller).TurnTowardPlayer();
		DeactivateHelpMarker(HelpMarker);
		DeactivateLocationMarker(LocationMarker);
		FAMasterScript.DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
	}
	simulated Function QueueFiring(int32 BurstLength)
	{
		if (BurstLength >= 0)
		{
			BurstNum=byte(BurstLength);
		}
		BurstNum --;
		if (BurstNum > 0)
		{
			bInFiringMode=true;
			if (! HasTimerEventName("Burst_Fire"))
			{
				SetTimerEvent("Burst_Fire",0.1,0,true);
			}
		}
		else
		{
			StopTimer("Burst_Fire",0);
			BurstNum=0;
			bInFiringMode=false;
		}
	}
	simulated Function PlayFire()
	{
		int32 i = 0;
		if (FlashEmitter != nullptr)
		{
			for (i=0; i<FlashEmitter.EmitterCount(); i++)
			{
				FlashEmitter.Emitters[i].SpawnParticle(FlashEmitter.Emitters[i].iFlashSpawnCount);
			}
			FlashEmitter.DynamicFlash();
			FlashEmitter.PlayOwnedSound(Sound'S_AA2_WeaponsUS.M249.WeaponsUS_M249_Outdoorfire',0,1,false,400,1,true,false);
		}
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		HandleHelpTimerEvent(TimerName);
		switch(TimerName)
		{
			case "Burst_Fire":
			PlayFire();
			QueueFiring(BurstNum);
			break;
			case "Butt_Down_Reminder":
			PlayLSAnim("fa_station2_7",DS_Acosta);
			break;
			case "MovingToSecondBoulder":
			QueueFiring(15);
			break;
			case "SmokeGrenadeEnd":
			bPlayerWaitedTooLong=true;
			PlayerNoGoAwarded();
			break;
			case "FadeOutBlack":
			FadeInBlack(2);
			MasterScript.ResetScript(this);
			break;
			default:
		}
		return true;
	}
	simulated Function CrouchEvent()
	{
		Log("CrouchEvent");
	}
	simulated Function CrawlEvent()
	{
		if (! bFirstProneEvent)
		{
			bPlayerMustBeProne=true;
			bFirstProneEvent=true;
			StopHelpTimer();
			if (HasTimerEventName("fa_station2_1"))
			{
				bWaitingForStation2_1Finish=true;
			}
			else
			{
				PlayLSAnim("fa_station2_2",DS_Acosta);
			}
			PlayerLock(true,false);
		}
		Log("CrawlEvent");
	}
	simulated Function EndState()
	{
		Log("Exiting crawling section");
		Log("Ending ActiveExecute state for " + FString::FromInt(this));
		SetPlayerWeapon(true,false);
		DeactivateHelpMarker(HelpMarker);
		DeactivateHelpMarker(DirectionMarker);
		DeactivateLocationMarker(LocationMarker);
	}
}
*/

void AFA_EL_LowCrawlUnderFire::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
}

void AFA_EL_LowCrawlUnderFire::PostPostInit()
{
	Super::PostPostInit();
	SetHelpMarker(HelpMarker, DrillSergeant->GetActorLocation(), HelpMarkerLargeOffset, true, true);
}

void AFA_EL_LowCrawlUnderFire::DoReferenceLinking()
{
	for (TActorIterator<AActor> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator)
	{
		AActor* Actor = *ActorIterator;
		if (((((Actor->ActorHasTag("Station_2_StartCrawl")) || (Actor->ActorHasTag("Station_2_EndCrawl"))) || (Actor->ActorHasTag("Station_2_SmokeGrenade"))) || (Actor->ActorHasTag("Station_2_CheckGrenade"))) || (Actor->ActorHasTag("LowCrawl_OutsideTrench")))
		{
			//Actor->EventLab = this;
		}
		if (Actor->ActorHasTag("Station_2_Flasher"))
		{
			//FlashEmitter = Spawn(AM249MuzzleFlash::StaticClass(), this, , Actor->GetActorLocation(), Actor.Rotation);
		}
		if (Actor->ActorHasTag("station2_grenade_volume"))
		{
			GrenadeExplodeVolume = Cast<AVolume>(Actor);
		}
	}
	Super::DoReferenceLinking();
}

void AFA_EL_LowCrawlUnderFire::AssignDrillSergeants(AFSTS_NPC_DrillSergeant* Sergeant)
{
	DS_Acosta = Cast<AFA_NPC_DS_Acosta>(Sergeant);
	//SetHelpLSActor(DS_Acosta);
	//Sergeant->EventLab = this;
}

void AFA_EL_LowCrawlUnderFire::RemoveGrenadeFromInventory()
{
	AInventory* Nade = nullptr;
	/*
	if ((Player.Weapon != nullptr) && Player.Weapon->IsA(AThrow_M83_Smoke::StaticClass()))
	{
		Player.Weapon.Destroy();
	}
	Nade = Player.FindInventoryType(AThrow_M83_Smoke::StaticClass());
	Player.DeleteInventory(Nade);
	*/
}

void AFA_EL_LowCrawlUnderFire::Reset()
{
	AActor* SearchActor = nullptr;
	bDormant = true;
	bPlayerMustBeProne = false;
	bPlayerNoGo = false;
	bNoGoMessageStarted = false;
	bWaitingForStation2_1Finish = false;
	bFirstProneEvent = false;
	bPlayerReachedFirstBoulder = false;
	bPlayerWaitedTooLong = false;
	bBadSmokeGrenadeThrow = false;
	bPlayerStoodUp = false;
	SmokeGrenadeStatus = ESmokeGrenadeStatus::SGS_None;
	DeactivateHelpMarker(HelpMarker);
	DeactivateLocationMarker(LocationMarker);
	StationObjective->SetDisabled(false);
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	RemoveGrenadeFromInventory();
	for (TActorIterator<AActor> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator)
	{
		AActor* Actor = *ActorIterator;
		if (Actor->IsA(AM83SmokeEmitter::StaticClass()) || Actor->IsA(APickupT_M83_Smoke::StaticClass()))
		{
			Actor->Destroy();
		}
	}
	//DS_Acosta->SetLocation(GetActorByTag("Station_2_Instruction_1")->GetActorLocation());
	Cast<ADSController>(DS_Acosta->Controller)->Stand();
	Cast<ADSController>(DS_Acosta->Controller)->MoveToPoint("Station_2_Instruction_1");
	Cast<ADSController>(DS_Acosta->Controller)->TurnTowardPlayer();
	PlayerLock(false, false);
	//Player.SetLocation(GetActorByTag("Station2_Start").Location);
	//Controller.SetRotation(GetActorByTag("Station2_Start").Rotation);
	SetHelpMarker(HelpMarker, DrillSergeant->GetActorLocation(), HelpMarkerLargeOffset, true, true);
	ForcePlayerProne(false);
	Super::Reset();
}

void AFA_EL_LowCrawlUnderFire::FFDrillSergeantScold()
{
	//DS_Acosta->StopLIPSincAnim();
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	PlayLSAnim("fa_station2_12", DS_Acosta,0,0,0,0);
	PlayTip("Watch your aim soldier!", "", 4);
	ForceLevelReset();
}

void AFA_EL_LowCrawlUnderFire::DrillSergeantMoveOn(AFSTS_NPC_DrillSergeant* Sergeant)
{
	if (FMath::Rand() %2 == 0)
	{
		PlayLSAnim("fa_station2_15", Sergeant,0,0,0,0);
	}
	else
	{
		PlayLSAnim("fa_station2_11", Sergeant,0,0,0,0);
	}
}

void AFA_EL_LowCrawlUnderFire::PlayFire()
{
}

void AFA_EL_LowCrawlUnderFire::QueueFiring(int32 BurstLength)
{
}
