// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_Ambush/FA_EL_Ambush.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/Actor/Brush/Volume/BlockingVolume/FSTS_Shot_Detection_Volume/FSTS_Shot_Detection_Volume.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_flashbang/em_bt_flashbang.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_DS_Johnson.h"

AFA_EL_Ambush::AFA_EL_Ambush()
{
	DrillSergeantTag = "FA_NPC_DS_Johnson";
	StationObjectiveTag = "Station5Objective";
	StationName = "React to an Ambush";
	HelpInfoList = {
		FHelpInfo({"HitTheDirt",30,"Press <Crawling> to get into the prone position","","fa_station4_7",nullptr}),
		FHelpInfo({ "FireIntoWoods",30,"Turn towards the woods on the right and","fire your entire clip by pressing the <fire> key","fa_station4_5",nullptr })
	};
	bDormant = true;
	bMasterScript = false;
	bDoGeneralInit = false;
}

/*
simulated State Dormant
{
	simulated Function BeginState()
	{
		if (! bStationComplete)
		{
			Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station_4_Cover");
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			Cast<ADSController>(DrillSergeant.Controller).Crouch();
		}
		Super::BeginState();
	}
}
*/

/*
simulated State ActiveExecute
{
	simulated Function BeginState()
	{
		Log("Beginning ActiveExecute state for " + FString::FromInt(this));
		SpawnFlashEffectStuff();
		Cast<ADSController>(DrillSergeant.Controller).Run();
		Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station_4_Instruction_1");
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
		Cast<ADSController>(DrillSergeant.Controller).Walk();
		SetPlayerWeapon(true,true);
		PlayerLock(true,false);
		if (! PlayerHasAmmo())
		{
			PlayerOutOfAmmo();
			PlayTip("You Entered an Ambush without ammunition!","Next time save your ammo for when you need it!",5);
		}
		else
		{
			PlayTip("Station 5 - React to an Ambush","Press <Crawling> to get into the prone position",5);
			PlayLSAnim("fa_station4_1",DrillSergeant);
			StartHelpTimer(0,true);
			if (Player.bIsProne)
			{
				CrawlEvent();
			}
		}
	}
	simulated Function bool PlayerHasAmmo()
	{
		if (Player.Weapon != nullptr)
		{
			return Player.Weapon.HasAmmo();
		}
		return false;
	}
	Function bool AGP_Weapon_Empty(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (! bEnemySuppressed)
		{
			if (! NotifyActor.HasAmmo())
			{
				SetCustomTimer(1,false,"PlayerOutOfAmmo");
			}
			else
			{
				PlayTip("Reload your weapon and continue suppressing the enemy!","",6);
			}
		}
		return true;
	}
	simulated Function EventLabTick(float DeltaTime)
	{
		Global.FA_RucksackPickup(DeltaTime);
		if (bPlayerMustBeProne)
		{
			if (((Player == nullptr) || (((Player != nullptr) && (! Player.bIsProne)) && (! Player.bWantsToProne))) && (! bNoGoMessageStarted))
			{
				PlayerLock(true,true);
				PlayerHit();
			}
		}
	}
	simulated Function PlayerHit()
	{
		DrillSergeant->StopLIPSincAnim();
		StopTimerByType(ETimerType::TT_LSAnim);
		StopHelpTimer();
		PlayerNoGoAwarded();
		FSTS_FA_Pawn(Player).PlayMILESDeathTone();
		PlayLSAnim("fa_station4_6",DrillSergeant);
		PlayTip("You have been hit by enemy fire!","",5);
	}
	simulated Function PlayerOutOfAmmo()
	{
		if (bEnemySuppressed)
		{
			return;
		}
		DrillSergeant->StopLIPSincAnim();
		StopTimerByType(ETimerType::TT_LSAnim);
		StopHelpTimer();
		PlayerNoGoAwarded();
		FSTS_FA_Pawn(Player).PlayMILESDeathTone();
		PlayLSAnim("fa_station4_6",DrillSergeant);
		PlayTip("You ran out of ammo in an Ambush!","",6);
	}
	simulated Function PlayerNoGoAwarded()
	{
		if (! bFriendlyFireFailure)
		{
			bPlayerNoGo=true;
			bNoGoMessageStarted=true;
		}
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(string(this) + " Timer_LSAnim called for " + FString::FromInt(LSName));
		switch(LSName)
		{
			case "fa_station4_1":
			if (bWaitingForStation4_1Finish)
			{
				PlayLSAnim("fa_station4_2",DrillSergeant);
				bWaitingForStation4_1Finish=false;
			}
			return true;
			case "fa_station4_2":
			StartHelpTimer(1,true);
			PlayerLock(true,false);
			bDetectShotVolumeHits=true;
			PlayTip("Hit the enemy targets with suppression fire!","Do not get up!",6);
			return true;
			case "fa_station4_3":
			StationCompleted();
			return true;
			case "fa_station4_4":
			return true;
			case "fa_station4_5":
			return true;
			case "fa_station4_6":
			StationCompletedFailed();
			return true;
			case "fa_station4_8":
			bPlayingOtherWayMsg=false;
			return true;
			default:
			return false;
		}
	}
	simulated Function StationCompletedFailed()
	{
		PlayTip("Station 5 - React to an Ambush Failed","",4);
		LogStationEnd(this,false);
		LeavingStation();
	}
	simulated Function StationCompleted()
	{
		PlayTip("Station 5 - React to an Ambush Complete","",4);
		LogStationEnd(this,true);
		LeavingStation();
	}
	simulated Function LeavingStation()
	{
		bStationComplete=true;
		StationObjective.SetDisabled(true);
		FAMasterScript.DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station5_EndBlock"));
		SetHelpMarker(DirectionMarker,GetActorByTag("ToStation6")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("ToStation6").Rotation);
		PlayerLock(false,false);
		ForcePlayerProne(false);
		Cast<ADSController>(DrillSergeant.Controller).WaitForTimer(10);
		Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station_4_Block_Return");
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		HandleHelpTimerEvent(TimerName);
		switch(TimerName)
		{
			case "FadeOutBlack":
			FadeInBlack(2);
			MasterScript.ResetScript(this);
			break;
			default:
		}
		return true;
	}
	simulated Function Register_Volume_Hit(AFSTS_Shot_Detection_Volume* HitVolume)
	{
		if (! bDetectShotVolumeHits)
		{
			return;
		}
		if (HitVolume == CorrectHitArea)
		{
			StopHelpTimer(1);
			StartHelpTimer(1,true);
			HitsOnShotVolume ++;
			Log("Hit number " + FString::FromInt(HitsOnShotVolume) + " registered");
			if (HitsOnShotVolume >= 20)
			{
				bDetectShotVolumeHits=false;
				bPlayerMustBeProne=false;
				bEnemySuppressed=true;
				PlayerLock(false,false);
				ForcePlayerProne(false);
				PlayerLock(true,false);
				PlayTip("You successfully suppressed the enemy","",5);
				StopHelpTimer(1);
				PlayLSAnim("fa_station4_3",DrillSergeant);
			}
		}
		else
		{
			if (HitVolume == WrongHitArea)
			{
				if (bPlayingOtherWayMsg)
				{
					return;
				}
				StopHelpTimer(1);
				StartHelpTimer(1,true);
				bPlayingOtherWayMsg=true;
				PlayLSAnim("fa_station4_8",DrillSergeant);
			}
		}
	}
	simulated Function SpawnFlashEffectStuff()
	{
		Aem_bt_flashbang*  FlashEffectClass;
		AGP_Effects.em_bt_flashbang* FlashEmitter = nullptr;
		AActor* FlashSpawnActor = nullptr;
		FlashEffectClass=Aem_bt_flashbang::StaticClass();
		FlashSpawnActor=GetActorByTag("Ambush_Flash");
		FlashEmitter=FlashSpawnActor.Spawn(FlashEffectClass,Self,,FlashSpawnActor->GetActorLocation(),FRotator(16384,0,0));
		FlashEmitter.bHidden=false;
		FlashSpawnActor.PlaySound(Sound'S_AA2_WeaponsUS.Grenades.WeaponsUS_Grenades_FlashBangPow',3,1,,1500,,true);
	}
	simulated Function CrouchEvent()
	{
		Log("CrouchEvent");
	}
	simulated Function CrawlEvent()
	{
		if ((! bFirstProneEvent) && (! bPlayerNoGo))
		{
			bFirstProneEvent=true;
			StopHelpTimer(0);
			bPlayerMustBeProne=true;
			if (HasTimerEventName("fa_station4_1"))
			{
				bWaitingForStation4_1Finish=true;
			}
			else
			{
				PlayLSAnim("fa_station4_2",DrillSergeant);
			}
		}
		Log("CrawlEvent");
	}
	simulated Function EndState()
	{
		SetPlayerWeapon(true,false);
		DeactivateHelpMarker(DirectionMarker);
		DeactivateLocationMarker(LocationMarker);
		Log("Ending ActiveExecute state for " + FString::FromInt(this));
	}
}
*/

void AFA_EL_Ambush::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
}

void AFA_EL_Ambush::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if ((SearchActor.Tag == "CorrectHitArea") && (Cast<AFSTS_Shot_Detection_Volume>(SearchActor) != nullptr))
		{
			CorrectHitArea = FSTS_Shot_Detection_Volume(SearchActor);
			CorrectHitArea.Ambush_Lab = this;
		}
		if ((SearchActor.Tag == "WrongHitArea") && (Cast<AFSTS_Shot_Detection_Volume>(SearchActor) != nullptr))
		{
			WrongHitArea = FSTS_Shot_Detection_Volume(SearchActor);
			WrongHitArea.Ambush_Lab = this;
		}
	}
	*/
	Super::DoReferenceLinking();
}

void AFA_EL_Ambush::AssignDrillSergeants(AFSTS_NPC_DrillSergeant* Sergeant)
{
	DS_Johnson = Cast<AFA_NPC_DS_Johnson>(Sergeant);
	//SetHelpLSActor(DS_Johnson);
	//Sergeant->SetEventLab(this);
	//Cast<ADSController>(DS_Johnson->Controller)->MoveToPoint("Station_4_Cover");
	//Cast<ADSController>(DS_Johnson->Controller)->TurnTowardPlayer();
	//Cast<ADSController>(DS_Johnson->Controller)->Crouch();
}

void AFA_EL_Ambush::PlayerHit()
{
}

void AFA_EL_Ambush::Reset()
{
	bDormant = true;
	bPlayerMustBeProne = false;
	bPlayerNoGo = false;
	bNoGoMessageStarted = false;
	bWaitingForStation4_1Finish = false;
	bFirstProneEvent = false;
	bDetectShotVolumeHits = false;
	bEnemySuppressed = false;
	HitsOnShotVolume = 0;
	PlayerLock(false, false);
	//Player.SetLocation(GetActorByTag("Station4_Start").Location);
	//Controller->SetRotation(GetActorByTag("Station4_Start").Rotation);
	//StationObjective->SetDisabled(false);
	//DrillSergeant->SetLocation(GetActorByTag("Station_4_Cover").Location);
	Cast<ADSController>(DrillSergeant->Controller)->MoveToPoint("Station_4_Cover");
	Cast<ADSController>(DrillSergeant->Controller)->TurnTowardPlayer();
	Cast<ADSController>(DrillSergeant->Controller)->Crouch();
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	//DrillSergeant->StopLIPSincAnim();
	if (Player->bIsCrouched)
	{
		//Controller.Crouching();
	}
	else
	{
		if (Player->bIsProne)
		{
			//Controller.Crawling();
		}
	}
	Super::Reset();
}

void AFA_EL_Ambush::FFDrillSergeantScold()
{
	//DrillSergeant->StopLIPSincAnim();
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	PlayLSAnim("fa_station4_9", DrillSergeant,0,0,0,0);
	PlayTip("Watch your aim soldier!", "", 4);
	ForceLevelReset();
}

void AFA_EL_Ambush::DrillSergeantMoveOn(AFSTS_NPC_DrillSergeant* Sergeant)
{
	if (FMath::Rand() %2 == 0)
	{
		PlayLSAnim("fa_station4_8", Sergeant,0,0,0,0);
	}
	else
	{
		PlayLSAnim("fa_station4_11", Sergeant,0,0,0,0);
	}
}

void AFA_EL_Ambush::SpawnFlashEffectStuff()
{
}

void AFA_EL_Ambush::Register_Volume_Hit(AFSTS_Shot_Detection_Volume* HitVolume)
{
}
