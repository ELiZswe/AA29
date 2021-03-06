// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/BaseScope/BaseScope.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Anpeq5_Laser/WeaponMod_Anpeq5_Laser.h"
#include "AA29/Object/Actor/BaseAmmoRound/BaseAmmoRound.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/AI_Primitive/Action/ActionFixJam/ActionFixJam.h"
#include "AA29/Object/Actor/AI_Primitive/Action/ActionReload/ActionReload.h"
#include "AA29/Object/Actor/Controller/AIController/AgentController/AgentController.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_30mm_1_Gren/Ammo_30mm_1_Gren.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_40mm_1_Gren/Ammo_40mm_1_Gren.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_40mm_1_Gren_Mod/Ammo_40mm_1_Gren_Mod.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_Flare_Gren.h"
#include "Particles/Emitter.h"

AAGP_Weapon::AAGP_Weapon()
{
	WM_Default.SetNum(6);
	ZoomIdleAnim.SetNum(6);
	AuxSupportedZoomFireAnims.SetNum(3);
	AuxZoomFireAnims.SetNum(3);
	SupportedZoomFireAnims.SetNum(3);
	ZoomFireAnims.SetNum(6);
	SupportedFireAnims.SetNum(3);
	FireAnims.SetNum(3);
	BaseAccuracyModifier			= 0.1;
	BaseRecoilModifier				= 0.1;
	_fShotNoise						= 1;
	_fHitNoise						= 0.5;
	_bCanBeMiles					= true;
	_bWeaponAlreadyRaised			= true;
	ProneFireOffset					= FVector(25, 0, 0);
	ShotsToStartRecoilBlend			= 3;
	ShotsForMaxRecoil				= 7;
	DryFireSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/General/WeaponsUS_General_DryFire.WeaponsUS_General_DryFire"), NULL, LOAD_None, NULL);
	FireAnims						= { "Fire", "FireB", "FireC" };
	SupportedFireAnims				= { "SupportedFire","SupportedFireB","SupportedFireC" };
	ZoomFireAnims					= { "ZoomFire","ZoomFireB","ZoomFireC" };
	SupportedZoomFireAnims			= { "SupportedZoomFire","SupportedZoomFireB","SupportedZoomFireC" };
	AuxZoomFireAnims				= { "ReflexFire","ReflexFireB","ReflexFireC" };
	AuxSupportedZoomFireAnims		= {"SupportedReflexFire","SupportedReflexFireB","SupportedReflexFireC"};
	ReloadEmptyAnim					= FName("Reload");
	ReloadFullAnim					= FName ("Reload");
	ProneReloadEmptyAnim			= FName("SupportedReload");
	ProneReloadFullAnim				= FName("SupportedReload");
	ZoomIdleAnim					= { FName("ZoomStill") };
	SupportedZoomIdleAnim			= FName("SupportedZoomStill");
	AuxZoomIdleAnim					= FName("ReflexStill");
	AuxSupportedZoomIdleAnim		= FName("SupportedReflexStill");
	AuxZoomInAnim					= FName("ReflexIn");
	AuxZoomOutAnim					= FName("ReflexOut");
	AuxSupportedZoomInAnim			= FName("SupportedReflexIn");
	AuxSupportedZoomOutAnim			= FName("SupportedReflexOut");
	AuxfZoomAnimFOV					= 25;
	FiringTweenTime					= 0.01;
	MaxClips						= 16;
	bWpnRecoil						= true;
	bWpnAccuracy					= true;
	_FPMuzzleFlashOffset.VOffset	= FVector(0, 179.901123046875, 0);
	_FPMuzzleFlashOffset.ROffset	= FRotator(0,0,0);
	_FPMuzzleFlashOffset.nBone		= "Muzzle";
	_sMILESBoxScale					= FVector( 1, 1, 1);
	_sBlankPlugScale				= FVector(1, 1, 1);
	iNextGrenadeType				= -1;
	num_mods						= -1;
	WM_Default						= { "NoMod","NoMod","NoMod","NoMod","NoMod" };
	bAllowsPlusOneLoading			= true;
	AutoFiringRate					= 2;
	SingleFiringRate				= 2;
	weapmFov						= 24;
	BurstPendingShots				= 2;
	AutoPendingShots				= 2;
	GlobalRecoilScaler				= 1.45;
	TraceAccuracy					= 1;
	TraceDist						= 18000;
	DisplayFOV						= 55;
	MuzzleScale						= 1.4;
	FlashOffsetY					= 0.32;
	FlashOffsetX					= 0.255;
	FlashLength						= 0.023;
	MuzzleFlashSize					= 256;
	bDrawMuzzleFlash				= true;
	MuzzleFlashStyle				= ERenderStyle::STY_Translucent;
	_ZoomDirInfo.MeanDirection		= FVector(0, 0, 0);
	_ZoomDirInfo.bPitch				= 1;
	_ZoomDirInfo.PitchMean			= 0;
	_ZoomDirInfo.PitchMaxDeviation	= 0.9;
	_ZoomDirInfo.PitchFalloff		= 1;
	_ZoomDirInfo.bYaw				= 1;
	_ZoomDirInfo.YawMean			= 0;
	_ZoomDirInfo.YawMaxDeviation	= 3.5;
	_ZoomDirInfo.YawFalloff			= 1;
	_ZoomDirInfo.bRoll				= 0;
	_ZoomDirInfo.RollMean			= 0;
	_ZoomDirInfo.RollMaxDeviation	= 0;
	_ZoomDirInfo.RollFalloff		= 0;
	_ZoomDirInfo.SpeedMean			= 0;
	_ZoomDirInfo.SpeedMaxDeviation	= 0;
	_ZoomDirInfo.SpeedFalloff		= 0;
	_ZoomDirInfo.Base				= FRotator(0, 0, 0);
	rSupportedLimit					= FRotator(38.4521484375, 29.9981689453125, 0);
	vZoomAnimOffset					= FVector(16, -43, -225);
	fZoomAnimFOV					= 10;
	fZoomAnimTime					= 0.19;
	eROF							= ERateofFire::ROF_Single;
	bMisFire						= true;
	PlayerViewOffset				= FVector( 3,  75, -125);
	BobDamping						= 0.5;
	DrawScale						= 0.5;
}

/*
State WaitingForReplication
{
	simulated Function bool IsBusy()
	{
		return true;
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		Log("AGP_Weapon.WaitinForReplication.CanUseWeapon() - disabling weapon");
		return false;
	}
}
*/

/*
simulated State Idle
{
	simulated Function Tick(float DeltaTime)
	{
		if (((((RepeatFire() && (Instigator != nullptr)) && Instigator.PressingFire()) && (Cast<AAGP_Pawn>(Instigator) != nullptr)) && (! Cast<AAGP_Pawn>(Instigator).PressingAction())) && GetCurrentAmmoType().HasAmmo())
		{
			Fire(1);
		}
		else
		{
			Global.pnCurrentRoadPathNode(DeltaTime);
		}
	}
	simulated Function bool CanZoom()
	{
		return ((_Scope != nullptr) && (eROF != AuxROF));
	}
	simulated Function bool PutDown()
	{
		return Global.bDebugPath();
	}
	simulated Function AnimEnd(int32 Channel)
	{
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		if (bUnZoomASAP)
		{
			ForceUnzoom();
			bUnZoomASAP=false;
		}
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
	}
Begin:
	if (! ((iPendingShots > 0) || ((((((RepeatFire() && (Instigator != nullptr)) && Instigator.PressingFire()) && (Cast<AAGP_Pawn>(Instigator) != nullptr)) && (! Cast<AAGP_Pawn>(Instigator).PressingAction())) && (GetCurrentAmmoType() != nullptr)) && GetCurrentAmmoType().HasAmmo())))
	{
		ConsecutiveShots=Default.ConsecutiveShots;
	}
	if (bIsJammed && (eROF != 4))
	{
		GotoState("Jammed");
	}
	else
	{
		if (bChangeWeapon)
		{
			GotoState("BusyLoweringWeapon");
		}
		else
		{
			if (bBusyLowerWeaponPending)
			{
				bBusyLowerWeaponPending=false;
				TempLowerWeapon();
			}
			else
			{
				if (((iPendingShots > 0) && ((eROF != 3) || (ConsecutiveShots <= AutoPendingShots))) || ((((((RepeatFire() && (Instigator != nullptr)) && Instigator.PressingFire()) && (Cast<AAGP_Pawn>(Instigator) != nullptr)) && (! Cast<AAGP_Pawn>(Instigator).PressingAction())) && (GetCurrentAmmoType() != nullptr)) && GetCurrentAmmoType().HasAmmo()))
				{
					Fire(1);
				}
				else
				{
					bPointing=false;
					PlayIdleAnim();
				}
			}
		}
	}
}
*/

/*
simulated State Jammed extends Idle
{
	simulated Function Fire(float Value)
	{
		DryFire();
	}
}
*/

/*
simulated State busy
{
	simulated Function StartCrawling()
	{
	}
	simulated Function Fire(float Value)
	{
	}
	simulated Function AltFire(float Value)
	{
	}
	simulated Function Reload()
	{
	}
	simulated Function ChangeFireMode()
	{
	}
	simulated Function FixJam()
	{
	}
	simulated Function GuardWeapon()
	{
	}
	simulated Function SetSupported(bool newSupported)
	{
	}
	simulated Function bool CheckForNoReload()
	{
		Log("AGP_Weapon.Busy.CheckForNoReload() - Too busy to reload");
		return true;
	}
	simulated Function Tick(float DeltaTime)
	{
		Global.pnCurrentRoadPathNode(DeltaTime);
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		return false;
	}
	simulated Function bool ShouldDrawCrosshair()
	{
		return false;
	}
	simulated Function bool IsBusy()
	{
		return true;
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::AnimEnd() - in state (Busy)" @ FString::FromInt(GetStateName()));
		}
		if (Role < 4)
		{
			ClientFinish();
		}
		else
		{
			Finish();
		}
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		GuardTimer=1;
		if (((Instigator != nullptr) && (Instigator.Controller != nullptr)) && Instigator.Controller->IsA(AAgentController::StaticClass()))
		{
			if ((Cast<AAgentController>(Instigator.Controller).ActiveAction != nullptr) && (Cast<AAgentController>(Instigator.Controller).ActiveAction->IsA(AActionReload::StaticClass()) || AgentController(Instigator.Controller).ActiveAction->IsA(AActionFixJam::StaticClass())))
			{
				AgentController(Instigator.Controller).NotifyComplete();
			}
		}
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		iPendingShots=0;
		_bActive=false;
		Enable("AnimEnd");
	}
	simulated Function bool DoBusyUnZoom()
	{
		return true;
	}
Begin:
	if (IsZoomed() && DoBusyUnZoom())
	{
		UnZoom();
		InterpolateZoomView(false);
		bInZoom=false;
	}
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
		AnimEnd(0);
	}
	else
	{
		FinishAnim();
	}
}
*/

/*
simulated State BusyReloading extends busy
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		PlayReloading();
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		UpdateCurrentAmmoRounds();
		Super::EndState();
	}
}
*/

/*
simulated State BusySuppressor extends busy
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		DoSuppressor((! bSuppressorOn));
		if (IsSuppressed())
		{
			if (GetSuppressor() != nullptr)
			{
				GetSuppressor().SetSuppressor();
			}
			if ((ThirdPersonActor != nullptr) && (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr))
			{
				BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
			}
		}
		PlaySuppressor();
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::EndState();
		if (! IsSuppressed())
		{
			if (GetSuppressor() != nullptr)
			{
				GetSuppressor().SetSuppressor();
			}
			if ((ThirdPersonActor != nullptr) && (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr))
			{
				BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
			}
		}
	}
}
*/

/*
simulated State BusySupporting extends busy
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		PlaySupporting();
	}
}
*/

/*
simulated State BusyZooming extends busy
{
	simulated Function AnimEnd(int32 Channel)
	{
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		bUnZoomASAP=false;
	}
	simulated Function bool CanSprint()
	{
		return true;
	}
	simulated Function bool CanCombatRoll(bool bActual)
	{
		return (! bActual);
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::EndState();
		if (Instigator != nullptr)
		{
			Instigator.ChangeAnimation();
		}
		bInZoom=bZoomDir;
		if (! bInZoom)
		{
			Instigator.Controller.FovAngle=Instigator.Controller.Class.Default.FovAngle;
		}
		else
		{
			if (_Scope != nullptr)
			{
				Instigator.Controller.FovAngle=_Scope.GetaZoomFOV();
			}
		}
	}
Begin:
	if ((ShouldUse3dSights() && (_Scope != nullptr)) && _Scope.bAux3dSights)
	{
		if (bZoomDir)
		{
			bInZoom=true;
			if (IsSupported())
			{
				RunAnimation(AuxSupportedZoomInAnim,1);
			}
			else
			{
				RunAnimation(AuxZoomInAnim,1);
			}
			fZoomAnimFOV=AuxfZoomAnimFOV;
			InterpolateZoomView(true);
			if (GetWorld()->GetNetMode() == NM_DedicatedServer)
			{
				Sleep(AnimTimerDuration);
				AnimEnd(0);
			}
			Zoom();
		}
		else
		{
			UnZoom();
			if (IsSupported())
			{
				RunAnimation(AuxSupportedZoomOutAnim,1);
			}
			else
			{
				RunAnimation(AuxZoomOutAnim,1);
			}
			InterpolateZoomView(false);
			if (GetWorld()->GetNetMode() == NM_DedicatedServer)
			{
				Sleep(AnimTimerDuration);
				AnimEnd(0);
			}
			bInZoom=false;
		}
	}
	else
	{
		if (bZoomDir)
		{
			bInZoom=true;
			if ((ShouldUse3dSights() && (_Scope != nullptr)) && _Scope.bUseScopeWeaponFOV)
			{
				fZoomAnimFOV=_Scope.ScopeZoomAnimFOV;
			}
			InterpolateZoomView(true);
			Zoom();
		}
		else
		{
			UnZoom();
			InterpolateZoomView(false);
			bInZoom=false;
		}
	}
	GotoState("Idle");
}
*/

/*
simulated State InCrawling extends busy
{
	simulated Function StartCrawling()
	{
	}
	simulated Function bool IsCrawling()
	{
		return true;
	}
	simulated Function SetFastMove(bool fast)
	{
		if (! fast)
		{
			GotoState("OutCrawling");
		}
	}
	simulated Function StopCrawling()
	{
		GotoState("OutCrawling");
	}
	simulated Function AnimEnd(int32 Channel)
	{
		GotoState("Crawling");
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		PlayHighCrawlIn();
	}
Begin:
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
		AnimEnd(0);
	}
	else
	{
		FinishAnim();
	}
}
*/

/*
simulated State Crawling extends busy
{
	simulated Function StartCrawling()
	{
	}
	simulated Function AnimEnd(int32 Channel)
	{
	}
	simulated Function bool IsCrawling()
	{
		return true;
	}
	simulated Function SetFastMove(bool fast)
	{
		if (! fast)
		{
			GotoState("OutCrawling");
		}
	}
	simulated Function StopCrawling()
	{
		GotoState("OutCrawling");
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		PlayCrawl();
	}
}
*/

/*
simulated State OutCrawling extends busy
{
	simulated Function StopCrawling()
	{
	}
	simulated Function bool IsCrawling()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		PlayHighCrawlOut();
	}
}
*/

/*
simulated State BusyChangingFireMode extends busy
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		PlayChangeFireMode();
		switch(NewAuxMode)
		{
			case 0:
			DoChangeFireMode();
			break;
			case 1:
			DoChangeFireModeAux();
			break;
			case 2:
			DoChangeFireModeLast();
			break;
			default:
		}
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::EndState();
		NewAuxMode=0;
	}
Begin:
	if (IsZoomed() && (NewAuxMode != 0))
	{
		UnZoom();
		InterpolateZoomView(false);
		bInZoom=false;
	}
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
		AnimEnd(0);
	}
	else
	{
		FinishAnim();
	}
}
*/

/*
simulated State BusyFixingJam extends busy
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		PlayFixJam();
		if (GetCurrentAmmoType() != nullptr)
		{
			GetCurrentAmmoType().DecrementAmmo();
			if (GetCurrentAmmoType().AmmoAmount <= 0)
			{
				NotifyOutOfAmmo();
			}
			UpdateCurrentAmmoRounds();
		}
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		DoFixJam();
		Super::EndState();
	}
}
*/

/*
simulated State BusyFiring extends busy
{
	simulated Function StartCrawling()
	{
		Global.npcpsIterator();
	}
	simulated Function bool ShouldDrawCrosshair()
	{
		return Global.Cmd();
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		if (GetRemoteRole() == ENetRole::ROLE_MAX)
		{
			if (Level.debugShoot)
			{
				DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() SERVER TRACE" @ FString::FromInt(GetCurrentAmmoType().AmmoAmount));
			}
			if ((GetCurrentAmmoType() != nullptr) && GetCurrentAmmoType().bInstantHit)
			{
				TraceFire(TraceAccuracy,0,0);
			}
			else
			{
				ProjectileFire();
			}
		}
		else
		{
			if (GetCurrentAmmoType() != nullptr)
			{
				GetCurrentAmmoType().DecrementAmmo();
			}
		}
		UpdateCurrentAmmoRounds();
		if (Instigator != nullptr)
		{
			Instigator.UpperBodyAnimComplete();
			if ((Cast<AHumanController>(Instigator.Controller) != nullptr) && Instigator.IsHumanControlled())
			{
				Cast<AHumanController>(Instigator.Controller).bSnapLevel=0;
				Cast<AHumanController>(Instigator.Controller).bCenterView=false;
			}
		}
		LocalFire();
		if ((eROF != 2) && (eROF != 3))
		{
			Enable("AnimEnd");
		}
	}
Begin:
	if (eROF == 3)
	{
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			Sleep(FMin(AnimTimerDuration,AutoFiringRate));
		}
		else
		{
			Sleep(AutoFiringRate);
		}
		GotoState("Idle");
	}
	else
	{
		if (eROF == 1)
		{
			if (GetWorld()->GetNetMode() == NM_DedicatedServer)
			{
				Sleep(FMin(AnimTimerDuration,SingleFiringRate));
			}
			else
			{
				Sleep(SingleFiringRate);
			}
			GotoState("Idle");
		}
		else
		{
			if (GetWorld()->GetNetMode() == NM_DedicatedServer)
			{
				Sleep(AnimTimerDuration);
				AnimEnd(0);
			}
			else
			{
				FinishAnim();
			}
		}
	}
}
*/

/*
simulated State NPC_BusyFiring extends busy
{
	simulated Function StartCrawling()
	{
		Global.npcpsIterator();
	}
	simulated Function bool ShouldDrawCrosshair()
	{
		return Global.Cmd();
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		if (GetRemoteRole() == ENetRole::ROLE_MAX)
		{
			if (Level.debugShoot)
			{
				DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() SERVER TRACE" @ FString::FromInt(GetCurrentAmmoType().AmmoAmount));
			}
			if ((GetCurrentAmmoType() != nullptr) && GetCurrentAmmoType().bInstantHit)
			{
				TraceFire(TraceAccuracy,0,0);
			}
			else
			{
				NPC_ProjectileFire();
			}
		}
		if (Instigator != nullptr)
		{
			Instigator.UpperBodyAnimComplete();
			if ((Cast<AHumanController>(Instigator.Controller) != nullptr) && Instigator.IsHumanControlled())
			{
				Cast<AHumanController>(Instigator.Controller).bSnapLevel=0;
				Cast<AHumanController>(Instigator.Controller).bCenterView=false;
			}
		}
		NPC_LocalFire();
		Enable("AnimEnd");
	}
Begin:
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
		AnimEnd(0);
	}
	else
	{
		FinishAnim();
	}
}
*/

/*
simulated State BusyRaisingWeapon extends busy
{
	simulated Function BringUp()
	{
	}
	simulated Function ClientTempLowerWeapon(bool bActive)
	{
	}
	Function TempLowerWeapon(bool bActive)
	{
		bBusyLowerWeaponPending=true;
	}
	simulated Function bool PutDown()
	{
		return true;
	}
	simulated Function EndState()
	{
		Super::EndState();
		bWeaponUp=true;
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		bWeaponUp=false;
		bChangeWeapon=false;
		if (Instigator != nullptr)
		{
			Instigator.WeaponSwap3p(GetUpperBodyRaiseAnim());
		}
		PlaySelect();
	}
}
*/

/*
simulated State BusyLoweringWeapon extends busy
{
	simulated Function uint8 GetUpperBodyReadyAnim()
	{
		if (Instigator != nullptr)
		{
			return Instigator.1;
		}
	}
	simulated Function bool PutDown()
	{
		return true;
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (bDropping)
		{
			bDropping=false;
			if (Cast<AAGP_Pawn>(Instigator) != nullptr)
			{
				Cast<AAGP_Pawn>(Instigator).DropSpecificItem(this);
			}
		}
	}
	simulated Function bool TweenDownImmediately()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (TweenDownImmediately())
		{
			TweenDown();
		}
		bWeaponUp=false;
		bChangeWeapon=false;
		if (Instigator != nullptr)
		{
			Instigator.WeaponSwap3p(GetUpperBodyLowerAnim());
		}
	}
}
*/

/*
simulated State BusyTempLowering extends busy
{
	simulated Function bool IsTempBusy()
	{
		return true;
	}
	simulated Function Fire(float Value)
	{
		if (_bActive)
		{
			Global.AgentController(Value);
		}
	}
	simulated Function AltFire(float Value)
	{
		if (_bActive)
		{
			Global.actionFailed(Value);
		}
	}
	simulated Function Reload()
	{
		if (_bActive)
		{
			Global.npcbcNew();
		}
	}
	simulated Function ChangeFireMode()
	{
		if (_bActive)
		{
			Global._cHUDFrame();
		}
	}
	simulated Function FixJam()
	{
		if (_bActive)
		{
			Global.CommoLocalMessage();
		}
	}
	simulated Function SetSupported(bool newSupported)
	{
		if (_bActive)
		{
			Global.BrowserGSPY(newSupported);
		}
	}
	simulated Function bool CanZoom()
	{
		if (_bActive)
		{
			return ((_Scope != nullptr) && (eROF != AuxROF));
		}
		else
		{
			return false;
		}
	}
	simulated Function bool CheckForNoReload()
	{
		Log("AGP_Weapon.BusyTempLowering.CheckForNoReload(): " + FString::FromInt(_bActive));
		if (_bActive)
		{
			return Global.iNode();
		}
		else
		{
			return false;
		}
	}
	simulated Function bool ShouldDrawCrosshair()
	{
		if (_bActive)
		{
			return Global.Cmd();
		}
		else
		{
			return false;
		}
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BusyTempLowering::CanUseWeapon _bActive=" + FString::FromInt(_bActive));
		if (_bActive)
		{
			return Global.dim(DesiredAction);
		}
		else
		{
			return false;
		}
	}
	simulated Function AnimEnd(int32 Channel)
	{
		GotoState("BusyTempDown");
	}
	Function TempLowerWeapon(bool bActive)
	{
		if (_bActive && (! bActive))
		{
			Global.sclass_name(bActive);
		}
	}
	Function TempRaiseWeapon()
	{
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			return;
		}
		GotoState("BusyTempRaising");
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			ClientGotoState("BusyTempRaising","None");
		}
	}
	simulated Function BeginState()
	{
		bool bSaveActive = false;
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		bSaveActive=_bActive;
		Super::BeginState();
		_bActive=bSaveActive;
		bWeaponUp=false;
		if ((! _bActive) || (! IsZoomed()))
		{
			TweenDown();
		}
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::EndState();
	}
Begin:
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
		AnimEnd(0);
	}
	else
	{
		FinishAnim();
	}
}
*/

/*
simulated State BusyTempDown extends busy
{
	simulated Function bool IsTempBusy()
	{
		return true;
	}
	simulated Function Fire(float Value)
	{
		if (_bActive)
		{
			Global.AgentController(Value);
		}
	}
	simulated Function AltFire(float Value)
	{
		if (_bActive)
		{
			Global.actionFailed(Value);
		}
	}
	simulated Function Reload()
	{
		if (_bActive)
		{
			Global.npcbcNew();
		}
	}
	simulated Function ChangeFireMode()
	{
		if (_bActive)
		{
			Global._cHUDFrame();
		}
	}
	simulated Function FixJam()
	{
		if (_bActive)
		{
			Global.CommoLocalMessage();
		}
	}
	simulated Function SetSupported(bool newSupported)
	{
		if (_bActive)
		{
			Global.BrowserGSPY(newSupported);
		}
	}
	simulated Function bool CheckForNoReload()
	{
		Log("AGP_Weapon.BusyTempDown.CheckForNoReload(): " + FString::FromInt(_bActive));
		if (_bActive)
		{
			return Global.iNode();
		}
		else
		{
			return false;
		}
	}
	simulated Function bool ShouldDrawCrosshair()
	{
		if (_bActive)
		{
			return Global.Cmd();
		}
		else
		{
			return false;
		}
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BusyTempDown::CanUseWeapon _bActive=" + FString::FromInt(_bActive));
		if (_bActive)
		{
			return Global.dim(DesiredAction);
		}
		else
		{
			return false;
		}
	}
	simulated Function bool CanZoom()
	{
		if (_bActive)
		{
			return ((_Scope != nullptr) && (eROF != AuxROF));
		}
		else
		{
			return false;
		}
	}
	simulated Function PlayIdleAnim()
	{
		if (IsZoomed() && ShouldUse3dSights())
		{
			if (IsSupported())
			{
				if (((_Scope != nullptr) && _Scope.bAux3dSights) && HasAnim(AuxSupportedZoomIdleAnim))
				{
					RunAnimation(AuxSupportedZoomIdleAnim,1,0,true);
				}
				else
				{
					if (HasAnim(SupportedZoomIdleAnim))
					{
						RunAnimation(SupportedZoomIdleAnim,1,0,true);
					}
					else
					{
						RunAnimation("Still",1,0.05,true);
					}
				}
			}
			else
			{
				if (((_Scope != nullptr) && _Scope.bAux3dSights) && HasAnim(AuxZoomIdleAnim))
				{
					RunAnimation(AuxZoomIdleAnim,1,0,true);
				}
				else
				{
					if (HasAnim(ZoomIdleAnim[ElevationIndex]))
					{
						RunAnimation(ZoomIdleAnim[ElevationIndex],1,0,true);
					}
					else
					{
						RunAnimation("Still",1,0.05,true);
					}
				}
			}
			return;
		}
		if (_bActive)
		{
			RunAnimation("DropStill",1,0.05,true);
		}
	}
	simulated Function AnimEnd(int32 Channel)
	{
	}
	Function TempLowerWeapon(bool bActive)
	{
		if (_bActive && (! bActive))
		{
			Global.sclass_name(bActive);
		}
	}
	Function TempRaiseWeapon()
	{
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			return;
		}
		GotoState("BusyTempRaising");
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			ClientGotoState("BusyTempRaising","None");
		}
	}
	simulated Function BeginState()
	{
		bool bSaveActive = false;
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		bSaveActive=_bActive;
		Super::BeginState();
		_bActive=bSaveActive;
		PlayIdleAnim();
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::EndState();
	}
}
*/

/*
simulated State BusyTempRaising extends busy
{
	simulated Function bool IsTempBusy()
	{
		return true;
	}
	simulated Function Fire(float Value)
	{
		if (_bActive)
		{
			Global.AgentController(Value);
		}
	}
	simulated Function AltFire(float Value)
	{
		if (_bActive)
		{
			Global.actionFailed(Value);
		}
	}
	simulated Function Reload()
	{
		if (_bActive)
		{
			Global.npcbcNew();
		}
	}
	simulated Function ChangeFireMode()
	{
		if (_bActive)
		{
			Global._cHUDFrame();
		}
	}
	simulated Function FixJam()
	{
		if (_bActive)
		{
			Global.CommoLocalMessage();
		}
	}
	simulated Function SetSupported(bool newSupported)
	{
		if (_bActive)
		{
			Global.BrowserGSPY(newSupported);
		}
	}
	simulated Function bool CheckForNoReload()
	{
		Log("AGP_Weapon.BusyTempRaising.CheckForNoReload(): " + FString::FromInt(_bActive));
		if (_bActive)
		{
			return Global.iNode();
		}
		else
		{
			return false;
		}
	}
	simulated Function bool ShouldDrawCrosshair()
	{
		if (_bActive)
		{
			return Global.Cmd();
		}
		else
		{
			return false;
		}
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BusyTempRaising::CanUseWeapon _bActive=" + FString::FromInt(_bActive));
		if (_bActive)
		{
			return Global.dim(DesiredAction);
		}
		else
		{
			return false;
		}
	}
	simulated Function bool DoBusyUnZoom()
	{
		return false;
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::EndState();
		bWeaponUp=true;
		_bWeaponAlreadyRaised=true;
	}
	simulated Function BeginState()
	{
		bool bSaveActive = false;
		if (Level.debugWeaponState)
		{
			DebugLog(DEBUG_Inv,string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		bSaveActive=_bActive;
		Super::BeginState();
		_bActive=bSaveActive;
		bWeaponUp=false;
		PlaySelect();
	}
}
*/

void AAGP_Weapon::InterpolateZoomView(bool moveToZoomed)
{

}

void AAGP_Weapon::Strawberry()
{
	ServerJamit();
}

void AAGP_Weapon::DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	DisplayDebug(Canvas,YL,YPos);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	Canvas.DrawText("bActive" @ _bActive,false);
	*/
}

void AAGP_Weapon::ClientGotoState(FName NewState, FName NewLabel)
{
	/*
	if (NewState == 'BusyTempRaising' && IsInState('BusyReloading'))
	{
		return;
	}
	else
	{
		GotoState(NewState,NewLabel);
	}
	*/
}

void AAGP_Weapon::StaticPrecache(ALevelInfo* L)
{
	/*
	if (Default.AmmoName != nullptr && Default.AmmoName.Default.IconMaterial != nullptr)
	{
		L->AddPrecacheMaterial(Default.AmmoName.Default.IconMaterial);
	}
	StaticPrecache(L);
	*/
}

void AAGP_Weapon::PreBeginPlay()
{
	/*
	PreBeginPlay();
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		return;
	}
	if (_FPMuzzleFlashClass != nullptr)
	{
		NormalMuzzleFlashEmitter=BaseMuzzleFlashEmitter(Spawn(_FPMuzzleFlashClass,Self));
		_FPMuzzleFlashEmitter=NormalMuzzleFlashEmitter;
		if (_FPMuzzleFlashEmitter != nullptr)
		{
			AttachToBoneOffset(_FPMuzzleFlashEmitter,_FPMuzzleFlashOffset);
		}
	}
	*/
}
void AAGP_Weapon::PostBeginPlay()
{
	/*
	PostBeginPlay();
	if (PickupClass != nullptr)
	{
		EnemyWeaponClass=class<AGP_Weapon>(PickupClass.Default.EnemyPickupClass.Default.InventoryType);
	}
	if (EnemyWeaponClass == nullptr)
	{
		EnemyWeaponClass=Class;
	}
	if (IsA('ThrowWeapon') && ! IsA('Throw_M83_Smoke'))
	{
		StatWeaponType=1;
	}
	else
	{
		if (IsA('RocketWeapon'))
		{
			StatWeaponType=2;
		}
		else
		{
			if (IsA('PistolWeapon'))
			{
				StatWeaponType=3;
			}
			else
			{
				if (IsA('SniperRifle'))
				{
					StatWeaponType=4;
				}
				else
				{
					if (IsA('Weapon_M249_SAW') || IsA('Weapon_RPK_SAW') || IsA('Weapon_M2_HMG') || IsA('Weapon_BTR_HMG'))
					{
						StatWeaponType=5;
					}
					else
					{
						if (IsA('Weapon_M16A2_Rifle') || IsA('Weapon_AK47_Rifle'))
						{
							StatWeaponType=6;
						}
					}
				}
			}
		}
	}
	*/
}
void AAGP_Weapon::Destroyed()
{
	Super::Destroyed();
	
	if (AmmoType != NULL)
	{
		AmmoType->Destroy();
		AmmoType=NULL;
	}
	if (AuxAmmoType != NULL)
	{
		AuxAmmoType->Destroy();
		AuxAmmoType=NULL;
	}
	if (_Scope != NULL)
	{
		//_Scope->Destroy();
		_Scope=NULL;
	}
	
	if (NormalMuzzleFlashEmitter != NULL)
	{
		//NormalMuzzleFlashEmitter->Destroy();
		NormalMuzzleFlashEmitter= NULL;
	}
	if (AuxMuzzleFlashEmitter != NULL)
	{
		//AuxMuzzleFlashEmitter->Destroy();
		AuxMuzzleFlashEmitter= NULL;
	}
	if (SuppressedMuzzleFlashEmitter != NULL)
	{
		//SuppressedMuzzleFlashEmitter->Destroy();
		SuppressedMuzzleFlashEmitter= NULL;
	}
	_FPMuzzleFlashEmitter= NULL;
	if (BlankPlug != NULL)
	{
		BlankPlug->Destroy();
		BlankPlug= NULL;
	}
	if (MILESBox != NULL)
	{
		MILESBox->Destroy();
		MILESBox= NULL;
	}
	if (AmmoRoundList != NULL)
	{
		//AmmoRoundList->Destroy();
		AmmoRoundList= NULL;
	}
	if (AuxAmmoRoundList != NULL)
	{
		//AuxAmmoRoundList->Destroy();
		AuxAmmoRoundList= NULL;
	}
	if (SpecialAmmoRoundList != NULL)
	{
		//SpecialAmmoRoundList->Destroy();
		SpecialAmmoRoundList= NULL;
	}
	if(GetNetMode() != ENetMode::NM_Client)
	{
		if (WeaponModList != NULL)
		{
			WeaponModList->Destroy();
			WeaponModList=NULL;
		}
	}
	//_AmmoMonitor=NULL;
	//_JammedMonitor=NULL;
	
}
void AAGP_Weapon::BeginPlay()
{
	Super::BeginPlay();
	if (iMisFire <= 0)
	{
		bMisFire=false;
	}
	if (bMisFire)
	{
		CalcNextMisFire();
	}
	//GotoState('Idle');
}
bool AAGP_Weapon::ShouldUse3dSights()
{
	//return _Scope != NULL && _Scope->b3dSights && bCanUse3dSights;
	return (_Scope != NULL && Cast<ABaseScope>(_Scope)->b3dSights && bCanUse3dSights); // Scope and weapon allow 3d sights
}

FVector AAGP_Weapon::Get3dScopeLocation()
{
	return GetInstigator()->GetActorLocation();
	//return Instigator.EyePosition();
}

FRotator AAGP_Weapon::Get3dScopeRotation()
{
	FRotator Rot = FRotator(0,0,0);
	int32 mypitch = 0;
	int32 myroll = 0;
	if (IsZoomed())
	{
		//Rot=Instigator.GetViewRotation();
		return Rot;
	}
	else
	{
		/*
		Rot=GetBoneRotation('Muzzle');
		mypitch=Rot.Roll;
		myroll=Rot.Pitch;
		Rot.Pitch=mypitch;
		Rot.Roll=myroll;
		Rot.Pitch += 16384;
		Rot.Roll += 32768;
		Rot.Yaw -= 16384;
		*/
		return Rot;
	}
}

void AAGP_Weapon::ServerJamit()
{
	iNextMisFire=0;
}

void AAGP_Weapon::AttachToPawn(APawn* p)
{
	AWeaponAttachment* WA = nullptr;
	/*
	AttachToPawn(p);
	WA= Cast<AWeaponAttachment>(ThirdPersonActor);
	if (WA != nullptr)
	{
		WA.AdjustAttachmentFor(this);
	}
	*/
}

FVector AAGP_Weapon::GetFireStart(FVector X, FVector Y, FVector Z)
{
	/*
	if (Instigator != nullptr)
	{
		if (! Instigator.IsHumanControlled())
		{
			return NPC_GetFireStart(X,Y,Z);
		}
		if (Instigator.bIsProne)
		{
			return Instigator.EyePosition() + ProneFireOffset.X * X + ProneFireOffset.Y * Y + ProneFireOffset.Z * Z;
		}
		else
		{
			return Instigator.EyePosition() + FireOffset.X * X + FireOffset.Y * Y + FireOffset.Z * Z;
		}
	}
	*/
	return X;
}

FVector AAGP_Weapon::NPC_GetFireStart(FVector X, FVector Y, FVector Z)
{
	FVector V = FVector(0,0,0);
	/*
	if (Instigator != nullptr)
	{
		V=Instigator.EyePosition();
	}
	*/
	return V;
}

void AAGP_Weapon::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	APlayerController* PlayerOwner = nullptr;
	float ScaledFlash = 0;
	FRotator Rot = FRotator(0,0,0);
	/*
	if (Instigator != nullptr && Instigator.Controller != nullptr)
	{
		PlayerOwner=Cast<APlayerController>(Instigator.Controller);
	}
	if (PlayerOwner == nullptr)
	{
		return;
	}
	if (PlayerOwner.bBehindView == false && bWeaponAndAttachmentsOnly == true)
	{
		if (! IsZoomed() || ShouldUse3dSights())
		{
			if (Instigator == nullptr)
			{
				return;
			}
			if (bMuzzleFlash && bDrawMuzzleFlash && MFTexture != nullptr)
			{
				if (! bSetFlashTime)
				{
					bSetFlashTime=true;
					FlashTime=GetWorld()->GetTimeSeconds() + FlashLength;
				}
				else
				{
					if (FlashTime < GetWorld()->GetTimeSeconds())
					{
						bMuzzleFlash=false;
					}
				}
				if (bMuzzleFlash)
				{
					ScaledFlash=0.5 * MuzzleFlashSize * MuzzleScale * Canvas.ClipX / 640;
					Canvas.SetPos(0.5 * Canvas.ClipX - ScaledFlash + Canvas.ClipX * FlashOffsetX,0.5 * Canvas.ClipY - ScaledFlash + Canvas.ClipY * FlashOffsetY);
					DrawMuzzleFlash(Canvas);
				}
			}
			else
			{
				bSetFlashTime=false;
			}
			SetActorLocation(Instigator.CalcDrawOffset(this));
			Rot=Instigator.GetViewRotation();
			if (IsInState('Crawling'))
			{
				Rot.Pitch=Instigator.FrontFloorRotation.Pitch;
			}
			SetActorRotation(Rot);
			Canvas.DrawActor(this,false,True,DisplayFOV);
		}
		if (_Scope != nullptr)
		{
			_Scope.RenderOverlays(Canvas,bWeaponAndAttachmentsOnly);
		}
	}
	*/
}

/*
void AAGP_Weapon::RenderTexture(ScriptedTexture Tex)
{
	FRotator Rot = FRotator(0,0,0);
	Rot=Instigator.GetViewRotation();
	Rot.Roll += 16355;
	if (Owner != nullptr && Instigator != nullptr && Tex != nullptr)
	{
		Tex.DrawPortal(0,0,Tex.USize,Tex.VSize,Owner,Instigator.EyePosition(),Rot,weapmFov);
	}
}
*/

FRotator AAGP_Weapon::AdjustAim(bool bBreatheBonus)
{
	FRotator Dir = FRotator(0,0,0);
	float mod = 0;
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponAcc)
	{
		DebugLog(DEBUG_Inv,"AdjustAim" @ Instigator @ Instigator.Controller.bPerfectAccuracy @ bWpnAccuracy);
	}
	if (Instigator == nullptr || Instigator.Controller.bPerfectAccuracy || ! bWpnAccuracy)
	{
		Dir=FRotator(0 0 0);
		if (_Scope != nullptr && _Scope.bUseAimAdjust && IsZoomed())
		{
			Dir += _Scope.GetAimAdjustment();
			Dir.Pitch += CurrentElevation;
		}
		return Dir;
	}
	mod=Instigator.CE_MeterValue;
	if (bBreatheBonus && IsZoomed())
	{
		mod *= 1.15;
	}
	mod=FMax(1 - mod,BaseAccuracyModifier);
	Dir=CalcRotation(_AccuracyDirInfo) * mod * GetWeightedAim();
	if (IsZoomed())
	{
		Dir.Pitch += CurrentElevation;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponAcc)
	{
		Dir=Normalize(Dir);
		DebugLog(DEBUG_Inv,"Weapon Accuracy Mod" @ mod @ "Adjusted Rotator" @ Dir @ "PitchDeg" @ Dir.Pitch / 182 @ "YawDeg" @ Dir.Yaw / 182);
	}
	if (_Scope != nullptr && _Scope.bUseAimAdjust && IsZoomed())
	{
		return Dir + _Scope.GetAimAdjustment();
	}
	else
	{
		return Dir;
	}
	*/
	return FRotator(0, 0, 0);      //FAKE   /EliZ
}

float AAGP_Weapon::GetWeightedAim()
{
	float randomAimMod = 0;
	/*
	if (! Cast<AAGP_Pawn>(Instigator).bNewAccuracy)
	{
		return 1;
	}
	randomAimMod=FMath::FRand();
	if (randomAimMod < 0.1)
	{
		return 1;
	}
	else
	{
		if (randomAimMod < 0.2)
		{
			return 0.75;
		}
		else
		{
			if (randomAimMod < 0.3)
			{
				return 0.5;
			}
			else
			{
				if (randomAimMod < 0.4)
				{
					return 0.35;
				}
				else
				{
					if (randomAimMod < 0.5)
					{
						return 0.3;
					}
					else
					{
						if (randomAimMod < 0.6)
						{
							return 0.25;
						}
						else
						{
							if (randomAimMod < 0.7)
							{
								return 0.2;
							}
							else
							{
								if (! IsZoomed())
								{
									return 0.2;
								}
								else
								{
									if (randomAimMod < 0.8)
									{
										return 0.15;
									}
									else
									{
										if (randomAimMod < 0.9)
										{
											return 0.1;
										}
										else
										{
											return 0.05;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	*/
	return 0;    //FAKE  /ELiZ
}

void AAGP_Weapon::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
	/*
	if (Instigator == nullptr || Owner != nullptr && Owner != Instigator)
	{
		DebugLog(DEBUG_Error,"AGP_Weapon::ServerFire() Trap: Got here with Instigator(" @ Instigator @ ") Owner(" @ Owner @ ")");
		return;
	}
	else
	{
		if (Instigator != nullptr && Instigator.isDead())
		{
			DebugLog(DEBUG_Warn,"AGP_Weapon::ServerFire() Cast<AWeapon>(" @ this @ ") Instigator(" @ Instigator @ ") Instigator is dead. Ignore fire request.");
			return;
		}
	}
	if (GetCurrentAmmoType() == nullptr && Pawn(GetOwner()) != nullptr)
	{
		GiveAmmo(Cast<APawn>(GetOwner()));
	}
	if (GetCurrentAmmoType() != nullptr && GetCurrentAmmoType().HasAmmo())
	{
		if (! bNoAdjustAim)
		{
			AdjustedAim=AdjustAim(bBreatheBonus);
		}
		iNextMisFire --;
		if (bMisFireOnRapid)
		{
			CheckRapidMisfire(bRapid);
		}
		if (bMisFire && iNextMisFire <= 0)
		{
			CalcNextMisFire();
			HandleMisFire();
		}
		else
		{
			if (IsInState('BusyFiring'))
			{
				BeginState();
			}
			else
			{
				if (! IsInState('BusyTempLowering'))
				{
					GotoState('BusyFiring');
				}
			}
		}
	}
	else
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::ServerFire() Got here with no ammo! " @ Self);
	}
	*/
}

void AAGP_Weapon::NPC_ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus, APawn* Enemy, float Value)
{
	/*
	NPC_SetEnemy(Enemy);
	NPC_SetValue(Value);
	if (GetCurrentAmmoType() == nullptr)
	{
		GiveAmmo(Cast<APawn>(GetOwner()));
	}
	if (GetCurrentAmmoType().HasAmmo())
	{
		if (! bNoAdjustAim)
		{
			AdjustedAim=AdjustAim(bBreatheBonus);
		}
		iNextMisFire --;
		if (bMisFireOnRapid)
		{
			CheckRapidMisfire(bRapid);
		}
		if (bMisFire && iNextMisFire <= 0)
		{
			CalcNextMisFire();
			HandleMisFire();
		}
		else
		{
			if (IsInState('NPC_BusyFiring'))
			{
				BeginState();
			}
			else
			{
				GotoState('NPC_BusyFiring');
			}
		}
	}
	*/
}

void AAGP_Weapon::LocalFire()
{
	bPointing=true;
	PlayFiring();
}
void AAGP_Weapon::NPC_LocalFire()
{
	bPointing=true;
	NPC_PlayFiring();
}

void AAGP_Weapon::ProjectileBackBlast(FVector Forward, FVector Right, FVector Up)
{
	FVector StartOffset = FVector(0, 0, 0);
	float Scale = 0;
	FVector vVec = FVector(0, 0, 0);
	APawn* p = nullptr;
	float fLen = 0;
	AActor* Hit = nullptr;
	FVector HitLoc = FVector(0, 0, 0);
	FVector HitNorm = FVector(0,0,0);
	Forward *= -1;
	/*
	Forward=Normal(Forward);
	StartOffset=Instigator.Location;
	ForEach CollidingActors(Class'Pawn',p,BackBlastRadius,StartOffset)
	{
		if (p != Instigator)
		{
			Hit=p.Trace(HitLoc,HitNorm,Instigator->GetActorLocation(),p->GetActorLocation(),true);
			if (Hit == Instigator)
			{
				vVec=p.Location - StartOffset;
				fLen=VSizeSquared(vVec);
				vVec=Normal(vVec);
				if (Forward Dot vVec > BackBlastCone && fLen < BackBlastRadius * BackBlastRadius)
				{
					Scale=1 - fLen / BackBlastRadius * BackBlastRadius;
					p.TakeDamage(BackBlastDamage * Scale,Instigator,FVector(0,0,0),FVector(0,0,0),RadiusDamageType,,Instigator.Controller,Self);
				}
			}
		}
	}
	*/
}

void AAGP_Weapon::ProjectileFire()
{
	APlayerController* PC = nullptr;
	FVector Start = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	AAmmunition* CurrentAmmoType = nullptr;
	/*
	Owner.MakeNoise(1,Self);
	GetAxes(GetFireRot(),X,Y,Z);
	Start=GetFireStart(X,Y,Z);
	CurrentAmmoType=GetCurrentAmmoType();
	_Projectile=CurrentAmmoType.SpawnProjectile(Start,X);
	PC=Cast<APlayerController>(Instigator.Controller);
	if (Level.Game.Stats != nullptr && PC != nullptr && PC.PlayerStatsIndex >= 0)
	{
		if (StatWeaponType == 1 || CurrentAmmoType->IsA(AAmmo_40mm_1_Gren::StaticClass()) || CurrentAmmoType->IsA(AAmmoRound_Flare_Gren::StaticClass()))
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredGrenade();
		}
		else
		{
			if (StatWeaponType == 2)
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredRocket();
			}
			else
			{
				if (StatWeaponType == 3)
				{
					Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredPistol();
				}
				else
				{
					if (StatWeaponType == 4)
					{
						Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredSniperRifle();
					}
					else
					{
						if (StatWeaponType == 5)
						{
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredMachineGun();
						}
						else
						{
							if (StatWeaponType == 6)
							{
								Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredAssaultRifle();
							}
						}
					}
				}
			}
		}
	}
	if (bHasBackBlast)
	{
		ProjectileBackBlast(X,Y,Z);
	}
	*/
}

void AAGP_Weapon::NPC_ProjectileFire()
{
	FVector StartPos = FVector(0, 0, 0);
	FVector EndPos = FVector(0, 0, 0);
	FVector D = FVector(0, 0, 0);
	/*
	StartPos=Instigator.Location;
	if (Instigator.bIsProne)
	{
		StartPos.Z += Instigator.ProneEyeHeight;
	}
	else
	{
		if (Instigator.bIsCrouched)
		{
			StartPos.Z += Instigator.CrouchEyeHeight;
		}
		else
		{
			StartPos.Z += Instigator.BaseEyeHeight;
		}
	}
	EndPos=dEnemy.Location;
	D=EndPos - StartPos;
	_Projectile=GetCurrentAmmoType().SpawnProjectile(StartPos,D);
	*/
}

void AAGP_Weapon::TraceFire(float Accuracy, float YOffset, float ZOffset)
{
	FVector StartTrace = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	ABaseWeaponAttachment* BA = nullptr;
	int32 total_traces = 0;
	APlayerController* PC = nullptr;
	/*
	if (Instigator != nullptr && Instigator.bIsDead)
	{
		Log("Dead guy trying to shoot - discarding");
		return;
	}
	Owner.MakeNoise(1,Self);
	GetAxes(GetFireRot(),X,Y,Z);
	StartTrace=GetFireStart(X,Y,Z);
	BA=BaseWeaponAttachment(ThirdPersonActor);
	VtoPV(StartTrace,BA.BulletTrace[0]);
	GetCurrentAmmoType().UseBullet(StartTrace,X);
	BA=BaseWeaponAttachment(ThirdPersonActor);
	if (BA != nullptr)
	{
		total_traces=DoTrace(BA.GetSource(),StartTrace,X,TraceDist,1,0,BA);
	}
	PC=Cast<APlayerController>(Instigator.Controller);
	if (Level.Game.Stats != nullptr && PC != nullptr && PC.PlayerStatsIndex >= 0)
	{
		if (StatWeaponType == 5)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredMachineGun();
		}
		else
		{
			if (StatWeaponType == 6)
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredAssaultRifle();
			}
			else
			{
				if (StatWeaponType == 3)
				{
					Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredPistol();
				}
				else
				{
					if (StatWeaponType == 1)
					{
						Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredGrenade();
					}
					else
					{
						if (StatWeaponType == 4)
						{
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredSniperRifle();
						}
						else
						{
							if (StatWeaponType == 2)
							{
								Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredRocket();
							}
						}
					}
				}
			}
		}
	}
	DebugLog(DEBUG_Bullet,"AGP_Weapon::TraceFire() Did (" @ total_traces @ ") total traces");
	if (Level.GamePlayMode != 1 && BA != nullptr)
	{
		BA.TraceCount ++;
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			BA.ThirdPersonTrace();
		}
	}
	DebugLog(DEBUG_Bullet,"-----------------------------");
	*/
}

FRotator AAGP_Weapon::GetFireRot()
{
	FRotator R = FRotator(0,0,0);
	/*
	if (Instigator != nullptr)
	{
		R=Instigator.GetViewRotation() + AdjustedAim;
	}
	*/
	return R;
}

void AAGP_Weapon::NPC_TraceFire(float Accuracy, float YOffset, float ZOffset)
{
	FVector StartTrace = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FRotator OwnerRot = FRotator(0,0,0);
	ABaseWeaponAttachment* BA = nullptr;
	int32 total_traces = 0;
	FVector StartPos = FVector(0,0,0);
	FVector EndPos = FVector(0,0,0);
	float Right = 0;
	float Up = 0;
	FVector D = FVector(0,0,0);
	FVector AimOffset = FVector(0, 0, 0);
	/*
	if (Owner != nullptr)
	{
		Owner.MakeNoise(1);
	}
	if (Instigator.isDead())
	{
		OwnerRot=Instigator.GetViewRotation() + AdjustedAim;
		GetAxes(OwnerRot,X,Y,Z);
		StartTrace=GetFireStart(X,Y,Z);
	}
	BA=BaseWeaponAttachment(ThirdPersonActor);
	VtoPV(StartTrace,BA.BulletTrace[0]);
	GetCurrentAmmoType().UseBullet(StartTrace,X);
	StartPos=Instigator.Location;
	if (Instigator.bIsProne)
	{
		StartPos.Z += Instigator.ProneEyeHeight;
	}
	else
	{
		if (Instigator.bIsCrouched)
		{
			StartPos.Z += Instigator.CrouchEyeHeight;
		}
		else
		{
			StartPos.Z += Instigator.BaseEyeHeight;
		}
	}
	if (dEnemy != nullptr)
	{
		EndPos=dEnemy.Location;
	}
	AimOffset.X=0;
	if (dValue == 0)
	{
		Right=FMath::FRand() * 64 - 32;
		Up=FMath::FRand() * 32;
		if (Right > 0)
		{
			AimOffset.Y=Right + dEnemy.CollisionRadius * 2;
		}
		else
		{
			AimOffset.Y=Right - dEnemy.CollisionRadius * 2;
		}
		if (dEnemy.bIsProne)
		{
			Up += dEnemy.ProneEyeHeight;
		}
		else
		{
			if (dEnemy.bIsCrouched)
			{
				Up += dEnemy.CrouchEyeHeight;
			}
			else
			{
				Up += dEnemy.BaseEyeHeight;
			}
		}
		AimOffset.Z=Up;
	}
	else
	{
		if (dEnemy.bIsProne)
		{
			Up += dEnemy.ProneEyeHeight;
			Up -= FMath::FRand() * 8;
		}
		else
		{
			if (dEnemy.bIsCrouched)
			{
				Up += dEnemy.CrouchEyeHeight;
				Up -= FMath::FRand() * 16;
			}
			else
			{
				Up += dEnemy.BaseEyeHeight;
				Up -= FMath::FRand() * 24;
			}
		}
		AimOffset.Z=Up;
	}
	EndPos += AimOffset;
	D=EndPos - StartPos;
	total_traces=NPC_DoTrace(Instigator,StartPos,D,TraceDist,1,0,BA);
	DebugLog(DEBUG_Bullet,"AGP_Weapon::TraceFire()	Did (" @ total_traces @ ") total traces");
	if (Level.GamePlayMode != 1)
	{
		BA.TraceCount ++;
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			BA.ThirdPersonTrace();
		}
	}
	DebugLog(DEBUG_Bullet,"-----------------------------");
	*/
}
float AAGP_Weapon::GetPenetrationPercent(AActor* A, UTexture2D* M)
{
	/*
	if (A != nullptr && A.fPenetrationOverridePercent != 0)
	{
		return A.fPenetrationOverridePercent;
	}
	if (M != nullptr)
	{
		return M.GetPercentPenetration();
	}
	*/
	return 0;
}

float AAGP_Weapon::GetRicochetThreshold(AActor* A, UTexture2D* M)
{
	/*
	if (A != nullptr && A.fRicochetOverrideThreshold != 0)
	{
		return A.fRicochetOverrideThreshold;
	}
	if (M != nullptr)
	{
		return M.GetRicochetThreshold();
	}
	*/
	return 0;
}

FVector AAGP_Weapon::GetRicochetDirection(FVector TraceDirection, FVector HitNormal, float CosTheta)
{
	/*
	TraceDirection=MirrorVectorByNormal(TraceDirection,HitNormal);
	TraceDirection -= 0.5 * CosTheta * HitNormal;
	TraceDirection += 0.5 * CosTheta * VRand();
	return Normal(TraceDirection);
	*/
	return FVector(0, 0, 0);    //FAKE   /ELiZ
}

FVector AAGP_Weapon::GetPenetrateDirection(FVector TraceDirection, float fStrength)
{
	/*
	TraceDirection += 0.5 * 1 - fStrength * VRand();
	return Normal(TraceDirection);
	*/
	return FVector(0, 0, 0);    //FAKE   /ELiZ
}

float AAGP_Weapon::GetPenetrateStrength(AActor* TraceFrom, FVector StartTrace, FVector EndTrace, float fStrength)
{
	FBoneInfo HitBone;
	UMaterialInstance* HitMaterial = nullptr;
	FVector HitLocation = FVector(0,0,0);
	FVector HitNormal = FVector(0, 0, 0);
	float penDepth = 0;
	/*
	TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,true);
	penDepth=VSize(EndTrace - HitLocation);
	if (HitMaterial != nullptr)
	{
		penDepth *= 1 - HitMaterial.GetPercentPenetration();
	}
	else
	{
		penDepth *= 1 - GetPenetrationPercent(TraceFrom,HitMaterial);
	}
	fStrength *= 1 - penDepth / 256;
	*/
	return fStrength;
}

bool AAGP_Weapon::CanTraceMore(ABaseWeaponAttachment* BA, int32 num_traces)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
	{
		return false;
	}
	else
	{
		return num_traces < BA->GetMaxBulletTraces();
	}
}

int32 AAGP_Weapon::DoTrace(AActor* TraceFrom, FVector StartTrace, FVector TraceDirection, float fTraceDistance, float fStrength, int32 num_traces, ABaseWeaponAttachment* BA, bool btestdepth)
{
	AActor* HitActor = nullptr;
	FBoneInfo HitBone;
	UMaterialInstance* HitMaterial = nullptr;
	FVector HitLocation = FVector(0,0,0);
	FVector HitNormal = FVector(0, 0, 0);;
	float CosTheta = 0;
	bool bDidRicochet = false;
	FVector EndTrace = FVector(0, 0, 0);;
	FVector Unused1 = FVector(0, 0, 0);;
	FVector Unused2 = FVector(0, 0, 0);;
	int32 total_traces = 0;
	num_traces ++;
	/*
	EndTrace=StartTrace + fTraceDistance * TraceDirection;
	TraceFrom.bUseCollisionStaticMesh=true;
	HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,true);
	TraceFrom.bUseCollisionStaticMesh=false;
	if (HitActor == nullptr)
	{
		return 0;
	}
	Cast<AAGP_Pawn>(Instigator).NotifyTrace(this,HitActor,"");
	if (HitActor == Instigator)
	{
		DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Don't ever hit yourself");
		return 0;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && GetNetMode() != ENetMode::NM_Client)
	{
		if (Instigator != nullptr && Instigator.Controller != nullptr && Instigator.Controller->IsA(APlayerController::StaticClass()))
		{
			MakeNoise(1,Self,True,HitLocation);
		}
	}
	if (btestdepth && TraceFrom.fPenetrationOverridePercent != 0)
	{
		fStrength=GetPenetrateStrength(HitActor,HitLocation,StartTrace,fStrength);
		if (fStrength < 0.1)
		{
			return 0;
		}
	}
	VtoPV(HitLocation,BA.BulletTrace[num_traces]);
	BA.SetBulletImpactType(num_traces,0);
	GetCurrentAmmoType().ProcessTraceHit(this,StartTrace,TraceDirection,HitActor,HitBone,HitLocation,HitNormal,HitMaterial,TraceDirection,Unused1,Unused2,fStrength);
	BA=BaseWeaponAttachment(ThirdPersonActor);
	if (BA == nullptr)
	{
		return 1;
	}
	if (CanTraceMore(BA,num_traces))
	{
		if (HitActor.bWorldGeometry || HitActor.bBulletRicochet)
		{
			CosTheta=FMath::Abs(- HitNormal Dot TraceDirection);
			if (CosTheta < GetRicochetThreshold(HitActor,HitMaterial) * FMath::FRand())
			{
				fStrength *= 0.9;
				TraceDirection=GetRicochetDirection(TraceDirection,HitNormal,CosTheta);
				fTraceDistance -= VSize(StartTrace - HitLocation);
				fTraceDistance *= fStrength;
				BA.SetBulletImpactType(num_traces,2);
				total_traces=DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,false);
				bDidRicochet=true;
			}
		}
		if (HitActor.bBulletPenetration && ! bDidRicochet)
		{
			fStrength *= GetPenetrationPercent(HitActor,HitMaterial);
			if (fStrength > 0.1)
			{
				DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Penetrate! " + fStrength);
				TraceDirection=GetPenetrateDirection(TraceDirection,fStrength);
				fTraceDistance -= VSize(StartTrace - HitLocation);
				fTraceDistance *= fStrength;
				BA.SetBulletImpactType(num_traces,1);
				total_traces=DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,true);
			}
			else
			{
				DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Didn't penetrate " + fStrength @ num_traces);
			}
		}
	}
	*/
	return total_traces + 1;
}

int32 AAGP_Weapon::NPC_DoTrace(AActor* TraceFrom, FVector StartTrace, FVector TraceDirection, float fTraceDistance, float fStrength, int32 num_traces, ABaseWeaponAttachment* BA, bool btestdepth)
{
	AActor* HitActor = nullptr;
	FBoneInfo HitBone;
	UMaterialInstance* HitMaterial = nullptr;;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	float CosTheta = 0;
	bool bDidRicochet = false;
	FVector EndTrace = FVector(0, 0, 0);
	FVector Unused1 = FVector(0, 0, 0);
	FVector Unused2 = FVector(0, 0, 0);
	int32 total_traces = 0;
	num_traces ++;
	/*
	EndTrace=StartTrace + fTraceDistance * TraceDirection;
	HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,true);
	if (HitActor == nullptr)
	{
		return 0;
	}
	if (btestdepth && TraceFrom.fPenetrationOverridePercent != 0)
	{
		fStrength=GetPenetrateStrength(HitActor,HitLocation,StartTrace,fStrength);
		if (fStrength < 0.1)
		{
			return 0;
		}
	}
	VtoPV(HitLocation,BA.BulletTrace[num_traces]);
	BA.SetBulletImpactType(num_traces,0);
	GetCurrentAmmoType().NPC_ProcessTraceHit(this,StartTrace,TraceDirection,HitActor,HitBone,HitLocation,HitNormal,HitMaterial,TraceDirection,Unused1,Unused2,fStrength);
	if (CanTraceMore(BA,num_traces))
	{
		if (HitActor.bWorldGeometry || HitActor.bBulletRicochet)
		{
			CosTheta=FMath::Abs(- HitNormal Dot TraceDirection);
			if (CosTheta < GetRicochetThreshold(HitActor,HitMaterial) * FMath::FRand())
			{
				fStrength *= 0.9;
				TraceDirection=GetRicochetDirection(TraceDirection,HitNormal,CosTheta);
				fTraceDistance -= VSize(StartTrace - HitLocation);
				fTraceDistance *= fStrength;
				BA.SetBulletImpactType(num_traces,2);
				total_traces=NPC_DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,false);
				bDidRicochet=true;
			}
		}
		if (HitActor.bBulletPenetration && ! bDidRicochet)
		{
			fStrength *= GetPenetrationPercent(HitActor,HitMaterial);
			if (fStrength > 0.1)
			{
				DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Penetrate! " + fStrength);
				TraceDirection=GetPenetrateDirection(TraceDirection,fStrength);
				fTraceDistance -= VSize(StartTrace - HitLocation);
				fTraceDistance *= fStrength;
				BA.SetBulletImpactType(num_traces,1);
				total_traces=NPC_DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,true);
			}
			else
			{
				DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Didn't penetrate " + fStrength @ num_traces);
			}
		}
	}
	*/
	return total_traces + 1;
}

bool AAGP_Weapon::RepeatFire()
{
	return eROF == ERateofFire::ROF_Auto;
}
void AAGP_Weapon::CheckRapidMisfire(bool bRapid)
{
	/*
	if (! bRapid && RapidFireShots > -1)
	{
		if (Level.debugMisFire)
		{
			DebugLog(DEBUG_Bullet,"AGP_Weapon::CheckRapidMisfire bRapid == FALSE RapidFireShots" @ RapidFireShots @ "RapidFireShotsNeeded" @ RapidFireShotsNeeded);
		}
		if (RapidFireShots < RapidFireShotsNeeded)
		{
			if (RapidMisFireRand < RapidMisFirePct)
			{
				if (Level.debugMisFire)
				{
					DebugLog(DEBUG_Bullet,"AGP_Weapon::CheckRapidMisfire JAM!" @ RapidMisFirePct @ "RapidMisFireRand" @ RapidMisFireRand);
				}
				iNextMisFire=0;
			}
			else
			{
				CalcNextMisFire();
			}
		}
		RapidFireShots=-1;
	}
	else
	{
		RapidFireShots ++;
		if (Level.debugMisFire)
		{
			DebugLog(DEBUG_Bullet,"AGP_Weapon::CheckRapidMisfire RapidFireShots" @ RapidFireShots);
		}
	}
	*/
}
void AAGP_Weapon::CalcNextMisFire()
{
	/*
	int32 iNoMisfire;
	iNoMisfire=Clamp(iMisFire * 0.01,2,100);
	iNextMisFire=Rand(iMisFire - iNoMisfire) + iNoMisfire;
	RapidMisFireRand=FMath::FRand();
	ClientSendNextMisFire(iNextMisFire,RapidMisFireRand);
	if (Level.debugMisFire)
	{
		DebugLog(DEBUG_Bullet,"CALC iNextMisFire" @ iNextMisFire @ "RapidMisFireRand" @ RapidMisFireRand);
	}
	*/
}
void AAGP_Weapon::ClientSendNextMisFire(int32 NextW, float Rand)
{
	/*
	iNextMisFire=NextW;
	RapidMisFireRand=Rand;
	if (Level.debugMisFire)
	{
		DebugLog(DEBUG_Bullet,"SET iNextMisFire" @ iNextMisFire @ "RapidMisFireRand" @ RapidMisFireRand);
	}
	*/
}
void AAGP_Weapon::ServerRequestMisFireInfo()
{
	/*
	if (Level.debugMisFire)
	{
		DebugLog(DEBUG_Bullet,"AGP_Weapon::ServerRequestMisFireInfo");
	}
	ClientSendNextMisFire(iNextMisFire,RapidMisFireRand);
	*/
}
void AAGP_Weapon::HandleMisFire()
{
	/*
	if (Level.debugMisFire)
	{
		DebugLog(DEBUG_Bullet,"--------- MisFire ----------");
	}
	iPendingShots=0;
	bIsJammed=true;
	if (Level.debugMisFire)
	{
		DebugLog(DEBUG_Bullet,"Normal MisFire");
	}
	ClientHandleMisfire();
	GotoState('Jammed');
	*/
}
void AAGP_Weapon::ClientHandleMisfire()
{
	/*
	bIsJammed=true;
	GotoState('Jammed');
	NotifyJammed();
	*/
}
void AAGP_Weapon::IncreaseElevation()
{
	/*
	if (Elevation.Num() == 0)
	{
		return;
	}
	if (ElevationIndex + 1 < Elevation.Num())
	{
		ElevationIndex ++;
	}
	ServerSetElevation(ElevationIndex);
	if (GetNetMode() == ENetMode::NM_Client && IsInState('Idle'))
	{
		ClientFinish();
	}
	*/
}
void AAGP_Weapon::DecreaseElevation()
{
	/*
	if (Elevation.Num() == 0)
	{
		return;
	}
	if (ElevationIndex != 0)
	{
		ElevationIndex --;
	}
	ServerSetElevation(ElevationIndex);
	if (GetNetMode() == ENetMode::NM_Client && IsInState('Idle'))
	{
		ClientFinish();
	}
	*/
}
void AAGP_Weapon::ZeroElevation()
{
	/*
	if (Elevation.Num() == 0)
	{
		return;
	}
	ElevationIndex=Default.ElevationIndex;
	ServerSetElevation(ElevationIndex);
	if (GetNetMode() == ENetMode::NM_Client && IsInState('Idle'))
	{
		ClientFinish();
	}
	*/
}
void AAGP_Weapon::ServerSetElevation(int32 NewElevation)
{
	/*
	CurrentElevation=Elevation[NewElevation];
	if (IsInState('Idle'))
	{
		Finish();
	}
	*/
}
void AAGP_Weapon::SetGuerrillaWeapon(bool newGuerrillaWeap)
{
	/*
	if (GetNetMode() != ENetMode::NM_Client)
	{
		bGuerrillaWeapon=newGuerrillaWeap;
	}
	EnemyWeaponClass=Class;
	*/
}
void AAGP_Weapon::AttachToBack()
{
	//AttachToBone(ThirdPersonActor,'LShoulder');
}
void AAGP_Weapon::GiveTo(APawn* Other, APickup* Pickup)
{
	/*
	if (AmmoType != nullptr)
	{
		AmmoType.Instigator=Other;
	}
	if (AuxAmmoType != nullptr)
	{
		AuxAmmoType.Instigator=Other;
	}
	if (Pickup != nullptr && Pickup.EventLab != nullptr)
	{
		SetEventLab(Pickup.EventLab);
	}
	Other.AddInventory(this);
	bUnZoomASAP=false;
	bInZoom=false;
	bTossedOut=false;
	Instigator=Other;
	LoadWeaponMods();
	SetupModAttachments();
	GiveAmmo(nullptr);
	SetTeamOwner();
	sleeve_tag=GetSleeve(true);
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		SetupClientWeapon();
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		SpawnAndAttachScope();
	}
	*/
}
void AAGP_Weapon::SpawnAndAttachScope()
{
	/*
	if (_cScopeClass != nullptr)
	{
		_Scope=Spawn(_cScopeClass,Self);
		if (_Scope.DrawType != 0)
		{
			AttachToBone(_Scope,'Muzzle');
		}
	}
	*/
}

void AAGP_Weapon::OwnerRecieved()
{
	//ServerRequestMisFireInfo();
}

bool AAGP_Weapon::IsLegalMod(ABaseWeaponMod* cmod)
{
	int32 i = 0;
	/*
	for (i=0; i<Default.LegalModList.Num(); i++)
	{
		if (Default.LegalModList[i] == cmod)
		{
			return true;
		}
	}
	*/
	return false;
}

void AAGP_Weapon::LoadWeaponMods()
{
	int32 i = 0;
	ABaseWeaponMod* WM = nullptr;
	FString nameWM = "";
	if (bAlreadyLoadedMods)
	{
		return;
	}
	if (!bLoadModsFromPickup)
	{
		for (i = 0; i < 6; i++)
		{
			nameWM = GetWeaponModName(i);
			/*
			if ((WM_Default[i] ~= "NoMod") || (nameWM ~= WM_Default[i]))
			{
				continue;
			}
			CreateWeaponMod(nameWM, i);
			*/
		}
	}
	LoadDefaultMods();
	num_mods = 0;
	for (WM = WeaponModList; WM != nullptr; WM = WM->NextWeaponMod)
	{
		num_mods++;
	}
	bAlreadyLoadedMods = true;
}

void AAGP_Weapon::SetupModAttachments()
{
	/*
	if (ThirdPersonActor != nullptr)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
		BaseWeaponAttachment(ThirdPersonActor).SpawnModAttachments(this);
	}
	*/
}

FString AAGP_Weapon::GetWeaponModName(int32 i)
{
	FString nameWM = "";
	AAGP_Pawn* p = nullptr;
	AHumanController* HC = nullptr;
	/*
		p=Cast<AAGP_Pawn>(GetOwner());
	if (p == nullptr || p.TeamClass == nullptr)
	{
		return "";
	}
	nameWM=p.TeamClass.WM_Override[i];
	if (nameWM == "")
	{
		HC=Cast<AHumanController>(p.Controller);
		if (HC == nullptr)
		{
			return "";
		}
		else
		{
			nameWM=HC.WM_Slot[i];
		}
	}
	*/
	return nameWM;
}

void AAGP_Weapon::LoadDefaultMods()
{
	ABaseWeaponMod* WM = nullptr;
	TArray<uint8> SlotFull = { 0,0,0,0,0,0 };
	int32 i = 0;
	for (WM = WeaponModList; WM != nullptr; WM = WM->NextWeaponMod)
	{
		SlotFull[WM->ModSlot] = 1;
	}
	for (i = 0; i < 6; i++)
	{
		/*
		if ((WM_Default[i] ~= "NoMod") || (SlotFull[i] == 1))
		{
			continue;
		}
		CreateWeaponMod(WM_Default[i], i);
		*/
	}
}

void AAGP_Weapon::CreateWeaponMod(FString nameWM, int32 Slot)
{
	ABaseWeaponMod* classWM = nullptr;
	ABaseWeaponMod* WM = nullptr;
	/*
	if (nameWM == "" || nameWM ~= "none")
	{
		return;
	}
	classWM=class<BaseWeaponMod>(DynamicLoadObject(nameWM,Class'Class'));
	WM=Spawn(classWM,Owner);
	if (WM == nullptr)
	{
		DebugLog(DEBUG_Warn,"AGP_Weapon::CreateWeaponMod()	Unknown mod (" @ nameWM @ ")");
		return;
	}
	if (WM.AttachToWeapon(this,Slot))
	{
		AddWeaponMod(WM);
	}
	else
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::CreateWeaponMod() Can't attach!" @ WM);
		WM.Destroy();
	}
	*/
}
void AAGP_Weapon::AddWeaponMod(ABaseWeaponMod* WM)
{
	/*
	if (WeaponModList == nullptr)
	{
		WeaponModList=WM;
	}
	else
	{
		WM.NextWeaponMod=WeaponModList;
		WeaponModList=WM;
	}
	*/
}

void AAGP_Weapon::NotifyWeaponModAnimations(FName Sequence, float Rate, float TweenTime, bool bLoop)
{
	ABaseWeaponMod* WM = nullptr;
	for (WM = WeaponModList; WM != nullptr; WM = WM->NextWeaponMod)
	{
		WM->NotifyWeaponAnimation(Sequence, Rate, TweenTime, bLoop);
	}
}

void AAGP_Weapon::NotifyWeaponModZoom()
{
	ABaseWeaponMod* WM = nullptr;
	for (WM = WeaponModList; WM != nullptr; WM = WM->NextWeaponMod)
	{
		WM->NotifyWeaponZoom(IsZoomed());
	}
}

void AAGP_Weapon::UpdateCurrentAmmoRounds(bool bRoundInBreech)
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		return;
	}
	if (GetCurrentAmmoType() == AmmoType)
	{
		if (AmmoRoundList != nullptr)
		{
			AmmoRoundList.bRoundInBreech=bRoundInBreech;
			AmmoRoundList.AdjustAmmoRound(AmmoType.AmmoAmount);
		}
	}
	else
	{
		if (AuxAmmoRoundList != nullptr)
		{
			AuxAmmoRoundList.AdjustAmmoRound(AuxAmmoType.AmmoAmount);
		}
	}
	*/
}

ABaseAmmoRound* AAGP_Weapon::SpawnSingleAmmoRound(bool bAux, int32 ammo_id, bool bSpecial)
{
	ABaseAmmoRound* Ar = nullptr;
	ABaseAmmoRound* ARClass = nullptr;
	if (bAux)
	{
		ARClass=Cast<ABaseAmmoRound>(AuxAmmoRoundClass);
	}
	else
	{
		if (bSpecial)
		{
			ARClass= Cast<ABaseAmmoRound>(SpecialAmmoRoundClass);
		}
		else
		{
			ARClass= Cast<ABaseAmmoRound>(AmmoRoundClass);
		}
	}
	//Ar=Spawn(ARClass,Instigator);
	Ar->SetAmmoID(ammo_id);
	//AttachToBone(Ar,Ar.GetBoneNameForAmmoAttach(bAux,bSpecial));
	//Ar->SetDrawScale(DrawScale);
	return Ar;
}

void AAGP_Weapon::SpawnAndAttachAmmoRounds()
{
	ABaseAmmoRound* Ar = nullptr;
	int32 i = 0;
	/*
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && AmmoRoundClass != nullptr && AmmoRoundList == nullptr)
	{
		AmmoRoundList=SpawnSingleAmmoRound(false,1);
		Ar=AmmoRoundList;
		for (i=2; i<=NumAmmoRounds; i++)
		{
			Ar.NextAmmoRound=SpawnSingleAmmoRound(false,i);
			Ar=Ar.NextAmmoRound;
		}
		AmmoRoundList.AdjustAmmoRound(AmmoType.AmmoAmount);
	}
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && AuxAmmoRoundClass != nullptr && AuxAmmoRoundList == nullptr)
	{
		AuxAmmoRoundList=SpawnSingleAmmoRound(true,1);
		Ar=AuxAmmoRoundList;
		for (i=2; i<=NumAuxAmmoRound; i++)
		{
			Ar.NextAmmoRound=SpawnSingleAmmoRound(true,i);
			Ar=Ar.NextAmmoRound;
		}
		AuxAmmoRoundList.AdjustAmmoRound(AuxAmmoType.AmmoAmount);
	}
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && SpecialAmmoRoundClass != nullptr && SpecialAmmoRoundList == nullptr)
	{
		SpecialAmmoRoundList=SpawnSingleAmmoRound(false,1,true);
		Ar=SpecialAmmoRoundList;
		for (i=2; i<=NumSpecialAmmoRounds; i++)
		{
			Ar.NextAmmoRound=SpawnSingleAmmoRound(false,i,true);
			Ar=Ar.NextAmmoRound;
		}
		SpecialAmmoRoundList.AdjustSpecialAmmoRounds(false);
	}
	*/
}

void AAGP_Weapon::SpawnAndAttachMILESGear()
{
	AActor* aClass = nullptr;
	/*
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && Level.GamePlayMode == 1)
	{
		if (BlankPlug == nullptr)
		{
			aClass=class<Actor>(DynamicLoadObject("AGP_Inventory.WAttch_BlankPlug_1P",Class'Class'));
			BlankPlug=Spawn(aClass,Instigator);
		}
		AttachToBone(BlankPlug,'Muzzle');
		BlankPlug.SetDrawScale3D(_sBlankPlugScale);
		if (MILESBox == nullptr)
		{
			aClass=class<Actor>(DynamicLoadObject("AGP_Inventory.WAttch_MILESBox_1P",Class'Class'));
			MILESBox=Spawn(aClass,Instigator);
		}
		AttachToBone(MILESBox,'Muzzle');
		MILESBox.SetRelativeLocation(_vMILESBoxOffset);
		MILESBox.SetDrawScale3D(_sMILESBoxScale);
	}
	*/
}

bool AAGP_Weapon::IsReplicationComplete()
{
	ABaseWeaponMod* WM = nullptr;
	int32 found_mods = 0;
	if (Cast<APawn>(GetOwner()) == nullptr)
	{
		return false;
	}
	if (sleeve_tag == "")
	{
		return false;
	}
	if ((GetCurrentAmmoType() == nullptr) && (AmmoName != nullptr))
	{
		return false;
	}
	for (WM = WeaponModList; WM != nullptr; WM = WM->NextWeaponMod)
	{
		found_mods++;
	}
	return (num_mods == found_mods);
}
void AAGP_Weapon::NotifyReplicationComplete()
{
	/*
	SetupClientWeapon();
	ServerNotifyReplicationComplete();
	*/
}
void AAGP_Weapon::SetupClientWeapon()
{
	/*
	Instigator=Pawn(GetOwner());
	SpawnAndAttachAmmoRounds();
	SpawnAndAttachMILESGear();
	SetWeaponSkins();
	SpawnMuzzleFlash();
	SpawnAndAttachScope();
	UpdateCurrentAmmoRounds();
	if (ThirdPersonActor != nullptr)
	{
		BaseWeaponAttachment(ThirdPersonActor).InitializeShellEmitter();
	}
	if (bBusyRaiseWeaponPending)
	{
		GotoState('BusyRaisingWeapon');
		bBusyRaiseWeaponPending=false;
	}
	*/
}

void AAGP_Weapon::SpawnMuzzleFlash()
{
	/*
	if (_FPAuxMuzzleFlashClass != nullptr)
	{
		AuxMuzzleFlashEmitter=BaseMuzzleFlashEmitter(Spawn(_FPAuxMuzzleFlashClass,Self));
	}
	if (_FPSuppressedMuzzleFlashClass != nullptr)
	{
		SuppressedMuzzleFlashEmitter=BaseMuzzleFlashEmitter(Spawn(_FPSuppressedMuzzleFlashClass,Self));
	}
	*/
}

void AAGP_Weapon::SetWeaponSkins()
{
	ABaseWeaponMod* WM = nullptr;
	//Level.SetActorLevelSkin(this, true);
	for (WM = WeaponModList; WM != nullptr; WM = WM->NextWeaponMod)
	{
		//Level.SetActorLevelSkin(WM, true);
	}
}

FString AAGP_Weapon::GetActorLevelSkin(int32 Index, UTexture2D* old_material, FString level_tag)
{
	/*
	switch(Index)
	{
		case 0:
		if (Index >= Instigator.Skins.Num())
		{
			return GetActorLevelSkin(Index,old_material,level_tag);
			break;
		}
		if (Instigator.Skins.Num() > 2)
		{
			return Instigator.Skins[2] + special_tag + "_1P";
			break;
		}
		return old_material;
	}
	case 1:
	if (Right(Cast<AAGP_Pawn>(Instigator).Mesh,3) ~= "ACU")
	{
		return "T_AA2_Skins.weapon.skn_weap_camosleeve_new_frst";
	}
	else
	{
		return "T_AA2_Skins.weapon.skn_weap_camosleeve" + special_tag + "_" + sleeve_tag;
	}
	default:
	return GetActorLevelSkin(Index,old_material,level_tag);
	*/
	return "FAKE";   //FAKE   /EliZ
}

FString AAGP_Weapon::GetSleeve(bool bFriendly)
{
	/*
	if (Instigator != nullptr && Instigator.PlayerReplicationInfo != nullptr && Instigator.PlayerReplicationInfo.bGuerrillaPS)
	{
		return "Green";
	}
	
	switch(Level.GetSkinSet(bFriendly))
	{
		case 5:
		case 7:
		case 0:
			return "Frst";
		case 1:
			return "Dsrt";
		case 10:
		case 4:
			return "Arctic";
		default:
			return "INVALID";
	}
	*/
	return "FAKE";   //FAKE   /EliZ
}

void AAGP_Weapon::GiveAmmo(APawn* p)
{
	/*
	if (p != nullptr)
	{
		return;
	}
	if (AmmoName == nullptr)
	{
		return;
	}
	if (AmmoType == nullptr)
	{
		AmmoType=Spawn(AmmoName,Instigator);
		if (AmmoType != nullptr)
		{
			AmmoType.AmmoAmount=PickupAmmoCount;
			AmmoType.Instigator=Instigator;
			AmmoType.GotoState("None");
		}
	}
	if (AuxAmmoType == nullptr)
	{
		AuxAmmoType=Spawn(AuxAmmoName,Instigator);
		if (AuxAmmoType != nullptr)
		{
			AuxAmmoType.AmmoAmount=AuxPickupAmmoCount;
			AuxAmmoType.Instigator=Instigator;
			AuxAmmoType.GotoState("None");
		}
	}
	*/
}
void AAGP_Weapon::RecountAmmo()
{
	
	int32 i = 0;
	AmmoMagCount=0;
	for (i=0; i<16; i++)
	{
		if (_AmmoClips[i] > 0)
		{
			AmmoMagCount ++;
		}
	}
	AuxAmmoMagCount=0;
	if (AuxAmmoType != NULL)
	{
		for (i=0; i<16; i++)
		{
			if (_AuxAmmoClips[i] > 0)
			{
				AuxAmmoMagCount ++;
			}
		}
	}
	
}
void AAGP_Weapon::TravelPostAccept()
{
	/*
	if (Cast<APawn>(GetOwner()) == nullptr)
	{
		return;
	}
	if (AuxAmmoName != nullptr)
	{
		AuxAmmoType=Cast<AAmmunition>(Cast<APawn>(GetOwner())->FindInventoryType(AuxAmmoName));
		if (AuxAmmoType == nullptr)
		{
			AuxAmmoType=Spawn(AuxAmmoName);
			Cast<APawn>(GetOwner())->AddInventory(AuxAmmoType);
			AuxAmmoType.AmmoAmount=AuxPickupAmmoCount;
			AuxAmmoType.GotoState("None");
		}
	}
	TravelPostAccept();
	*/
}

int32 AAGP_Weapon::GetPendingShots()
{
	switch(eROF)
	{
	case ERateofFire::ROF_Burst:
		return BurstPendingShots;
	case ERateofFire::ROF_Auto:
		return AutoPendingShots;
	default:
		return 0;
	}
}

void AAGP_Weapon::Fire(float Value)
{
	bool bRapid = false;
	bool bAdjust = false;
	bool bBreatheBonus = false;
	/*
	if (Instigator == nullptr)
	{
		Log("---- ERROR ----");
		Log("Fire requested with instigator None");
		return;
	}
	if (Instigator.Controller != nullptr && Instigator.Controller.IsInState('DelayedStart'))
	{
		return;
	}
	bRapid=Value != 0;
	bBreatheBonus=FMath::Abs(Instigator.fZoomCycle) < 0.2 * Instigator.CE_MeterValue;
	if (! Cast<AAGP_Pawn>(Instigator).AllowAnimFiring() && eROF == 2 && GetPendingShots() <= 0 && Instigator.UpperBodyAnim != 6 && Instigator.UpperBodyAnim != 40 && Instigator.UpperBodyAnim != 69 && Instigator.UpperBodyAnim != 74 && Instigator.UpperBodyAnim != 34 && Instigator.UpperBodyAnim != 26 && Instigator.UpperBodyAnim != 30)
	{
		return;
	}
	if (Instigator.Physics == 2)
	{
		iPendingShots=0;
		AutoPendingShots=0;
		return;
	}
	if (iPendingShots <= 0)
	{
		if (eROF != 3 || ConsecutiveShots <= AutoPendingShots)
		{
			bAdjust=true;
			iPendingShots=GetPendingShots();
		}
	}
	else
	{
		if (eROF == 3)
		{
			bAdjust=true;
		}
		iPendingShots --;
	}
	if (GetCurrentAmmoType() != nullptr && ! GetCurrentAmmoType().HasAmmo() || IsJammed())
	{
		DryFire();
		if (Cast<AAGP_Pawn>(Instigator) != nullptr)
		{
			if (IsJammed())
			{
				if (Cast<AAGP_Pawn>(Instigator) != nullptr)
				{
					Cast<AAGP_Pawn>(Instigator).NotifyFire(this,"FIREJAMMED");
				}
			}
			else
			{
				if (Cast<AAGP_Pawn>(Instigator) != nullptr)
				{
					Cast<AAGP_Pawn>(Instigator).NotifyFire(this,"FIREEMPTY");
				}
			}
		}
		return;
	}
	if (Cast<AAGP_Pawn>(Instigator) != nullptr)
	{
		Cast<AAGP_Pawn>(Instigator).NotifyFire(this,"FIRE");
	}
	if (Cast<AAGP_Pawn>(Instigator) != nullptr && Cast<AAGP_Pawn>(Instigator)._FireMonitor != nullptr)
	{
		Cast<AAGP_Pawn>(Instigator)._FireMonitor.Notify();
	}
	ServerFire(! bAdjust,bRapid,bBreatheBonus);
	if (Role < 4)
	{
		iNextMisFire --;
		if (bMisFireOnRapid)
		{
			CheckRapidMisfire(bRapid);
		}
		if (! bMisFire || iNextMisFire > 0)
		{
			GotoState('BusyFiring');
		}
	}
	*/
}

void AAGP_Weapon::NPC_Fire(float Value, APawn* Enemy)
{
	bool bRapid = false;
	bool bAdjust = false;
	bool bBreatheBonus = false;
	/*
	bRapid=Value != 0;
	bBreatheBonus=FMath::Abs(Instigator.fZoomCycle) < 0.2 * Instigator.CE_MeterValue;
	if (iPendingShots <= 0)
	{
		bAdjust=true;
		iPendingShots=GetPendingShots();
	}
	else
	{
		iPendingShots --;
	}
	if (Instigator == nullptr)
	{
		return;
	}
	if (GetCurrentAmmoType() != nullptr && ! GetCurrentAmmoType().HasAmmo())
	{
		if (Level.debugShoot)
		{
			DebugLog(DEBUG_Inv,"AGP_Weapon::Fire() - Has no ammo");
		}
		DryFire();
		return;
	}
	if (Cast<AAGP_Pawn>(Instigator) != nullptr && Cast<AAGP_Pawn>(Instigator)._FireMonitor != nullptr)
	{
		Cast<AAGP_Pawn>(Instigator)._FireMonitor.Notify();
	}
	ServerFire(! bAdjust,bRapid,bBreatheBonus);
	if (Instigator.Controller != nullptr && Cast<AHumanController>(Instigator.Controller) != nullptr && Cast<AHumanController>(Instigator.Controller).bPrintShootDebug)
	{
		Cast<AHumanController>(Instigator.Controller).PrintShoot();
	}
	if (Role < 4)
	{
		iNextMisFire --;
		if (bMisFireOnRapid)
		{
			CheckRapidMisfire(bRapid);
		}
		if (! bMisFire || iNextMisFire > 0)
		{
			GotoState('BusyFiring');
		}
		else
		{
			if (Level.debugMisFire)
			{
				DebugLog(DEBUG_Bullet,"PREDICTED MISFIRE" @ bMisFire @ iNextMisFire);
			}
		}
	}
	*/
}
void AAGP_Weapon::AltFire(float Value)
{
	//ChangeFireMode();
}
void AAGP_Weapon::StartCrawling()
{
	/*
	if (Instigator == nullptr || Instigator.bIsWalking)
	{
		return;
	}
	if (Instigator.Controller != nullptr)
	{
		Instigator.Controller.StopFiring();
	}
	GotoState('InCrawling');
	*/
}
void AAGP_Weapon::StopCrawling()
{
}
void AAGP_Weapon::SetSupported(bool newSupported)
{
	/*
	if (newSupported == IsSupported())
	{
		return;
	}
	ServerSetSupported(newSupported);
	if (GetNetMode() == ENetMode::NM_Client)
	{
		bIsSupported=! bIsSupported;
		GotoState('BusySupporting');
	}
	*/
}
void AAGP_Weapon::ServerSetSupported(bool newSupported)
{
	/*
	bIsSupported=! bIsSupported;
	GotoState('BusySupporting');
	*/
}
void AAGP_Weapon::ServerNotifyReplicationComplete()
{
	/*
	if (bBusyRaiseWeaponPending)
	{
		GotoState('BusyRaisingWeapon');
		bBusyRaiseWeaponPending=false;
	}
	*/
}
void AAGP_Weapon::ChangeFireMode()
{
	/*
	if (eROF == AuxROF)
	{
		ChangeAuxMode(2);
		return;
	}
	ServerChangeFireMode();
	if (GetNetMode() == ENetMode::NM_Client)
	{
		GotoState('BusyChangingFireMode');
	}
	*/
}
void AAGP_Weapon::ServerChangeFireMode()
{
	//GotoState('BusyChangingFireMode');
}
void AAGP_Weapon::FixJam()
{
	/*
	if (GetCurrentAmmoType().AmmoAmount == 0 || eROF == AuxROF)
	{
		return;
	}
	ServerFixJam();
	if (GetNetMode() == ENetMode::NM_Client)
	{
		GotoState('BusyFixingJam');
	}
	*/
}
void AAGP_Weapon::ServerFixJam()
{
	//GotoState('BusyFixingJam');
}
void AAGP_Weapon::Reload()
{
	/*
	if (Instigator != nullptr && Instigator.Controller != nullptr && Cast<AHumanController>(Instigator.Controller) != nullptr && Cast<AHumanController>(Instigator.Controller).IsInState("None"))
	{
		return;
	}
	GotoState('BusyReloading');
	*/
}
void AAGP_Weapon::TempLowerWeapon(bool bActive)
{
	/*
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	_bActive=bActive;
	GotoState('BusyTempLowering');
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientTempLowerWeapon(_bActive);
	}
	*/
}
void AAGP_Weapon::ClientTempLowerWeapon(bool bActive)
{
	/*
	_bActive=bActive;
	GotoState('BusyTempLowering');
	*/
}

void AAGP_Weapon::TempRaiseWeapon()
{
}

void AAGP_Weapon::GuardWeapon()
{
	//GuardTimer=1;
}

ABaseWeaponMod* AAGP_Weapon::GetSuppressor()
{
	ABaseWeaponMod* WM = nullptr;
	for (WM = WeaponModList; WM != nullptr; WM = WM->NextWeaponMod)
	{
		if (WM->IsSuppressor())
		{
			return WM;
		}
	}
	return nullptr;
}

bool AAGP_Weapon::IsSuppressed()
{
	return bSuppressorOn;
}

void AAGP_Weapon::ToggleSuppressor()
{
	/*
	if (GetSuppressor() != nullptr)
	{
		ServerToggleSuppressor();
		if (GetNetMode() == ENetMode::NM_Client)
		{
			GotoState('BusySuppressor');
		}
	}
	*/
}
void AAGP_Weapon::ServerToggleSuppressor()
{
	//GotoState('BusySuppressor');
}
void AAGP_Weapon::DoSuppressor(bool bNewSuppressor)
{
	/*
	bSuppressorOn=bNewSuppressor;
	if (bSuppressorOn)
	{
		_FPMuzzleFlashEmitter=SuppressedMuzzleFlashEmitter;
		if (_FPMuzzleFlashEmitter != nullptr)
		{
			AttachToBoneOffset(_FPMuzzleFlashEmitter,_FPSuppressedMuzzleFlashOffset);
		}
	}
	else
	{
		_FPMuzzleFlashEmitter=NormalMuzzleFlashEmitter;
		if (_FPMuzzleFlashEmitter != nullptr)
		{
			AttachToBoneOffset(_FPMuzzleFlashEmitter,_FPMuzzleFlashOffset);
		}
	}
	*/
}
void AAGP_Weapon::PlaySuppressor()
{
	/*
	if (IsSuppressed())
	{
		if (IsSupported())
		{
			RunAnimation('SupportedSuppressorOn',1);
		}
		else
		{
			RunAnimation('SuppressorOn',1);
		}
		PlayWeaponSound(SuppressorOnSound,EnemyWeaponClass.Default.SuppressorOnSound);
	}
	else
	{
		if (IsSupported())
		{
			RunAnimation('SupportedSuppressorOff',1);
		}
		else
		{
			RunAnimation('SuppressorOff',1);
		}
		PlayWeaponSound(SuppressorOffSound,EnemyWeaponClass.Default.SuppressorOffSound);
	}
	*/
}

void AAGP_Weapon::ToggleLeftRail()
{
	ABaseWeaponMod* WM = nullptr;
	for (WM = WeaponModList; WM != nullptr; WM = WM->NextWeaponMod)
	{
		if (WM->AttachmentBone == "RailLT")
		{
			WM->Toggle();
			return;
		}
	}
}

void AAGP_Weapon::ToggleRightRail()
{
	ABaseWeaponMod* WM = nullptr;
	for (WM = WeaponModList; WM != nullptr; WM = WM->NextWeaponMod)
	{
		if (WM->AttachmentBone == "RailRT")
		{
			WM->Toggle();
			return;
		}
	}
}

bool AAGP_Weapon::CanZoom()
{
	return false;
}

FRotator AAGP_Weapon::CalcZoomWander()
{
	//return CalcRotation(_ZoomDirInfo);
	return FRotator(0,0,0);   //FAKE   /EliZ
}
void AAGP_Weapon::CycleZoom()
{
	/*
	if (_Scope != nullptr && Instigator != nullptr && Instigator.Controller != nullptr)
	{
		_Scope.CycleZoom(Cast<APlayerController>(Instigator.Controller));
	}
	*/
}
void AAGP_Weapon::ToggleZoom()
{
	/*
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::ToggleZoom urrent weapon state is " + GetStateName());
	}
	if (CanZoom())
	{
		ServerZoom(! IsZoomed());
		if (GetNetMode() == ENetMode::NM_Client)
		{
			DoZoom(! IsZoomed());
		}
	}
	*/
}
void AAGP_Weapon::ForceUnzoom(bool bForce)
{
	/*
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::ForceUnzoom " + CanZoom() @ IsZoomed());
	}
	if (CanZoom() && IsZoomed())
	{
		ServerZoom(false);
		if (GetNetMode() == ENetMode::NM_Client)
		{
			DoZoom(false);
		}
	}
	else
	{
		if (bForce)
		{
			bUnZoomASAP=true;
		}
	}
	*/
}
void AAGP_Weapon::ServerZoom(bool bNewZoomDir)
{
	/*
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::ServerZoom");
	}
	DoZoom(bNewZoomDir);
	*/
}
void AAGP_Weapon::DoZoom(bool DoZoomDir)
{
	/*
	bZoomDir=DoZoomDir;
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::DoZoom Current weapon state is " + GetStateName());
	}
	if (GetNetMode() != ENetMode::NM_Client && Instigator != nullptr)
	{
		Instigator.SetZoomed(DoZoomDir);
	}
	GotoState('BusyZooming');
	*/
}
void AAGP_Weapon::UnZoom()
{
	/*
	APlayerController* PC = nullptr;
	if (_Scope == nullptr)
	{
		return;
	}
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::UnZoom");
	}
	if (Instigator != nullptr)
	{
		if (GetNetMode() != ENetMode::NM_Client)
		{
			Instigator.SetZoomed(false);
		}
		if (GetNetMode() != ENetMode::NM_DedicatedServer && Instigator.Controller != nullptr && Instigator.Controller->IsA(AHumanController::StaticClass()) && Cast<AHumanController>(Instigator.Controller).bAutoWalkZoom)
		{
			Instigator.SetWalking(Cast<AHumanController>(Instigator.Controller).bSavedWalkingState);
		}
		if (Instigator.Controller != nullptr && Instigator.Controller->IsA(APlayerController::StaticClass()))
		{
			PC=Cast<APlayerController>(Instigator.Controller);
			if (PC != nullptr)
			{
				PC.CalcSoundDampening();
				_Scope.UnZoom(PC);
			}
		}
		else
		{
			if (Instigator.Controller != nullptr && Instigator->IsA(AaAIController::StaticClass()))
			{
				if (_Scope != nullptr)
				{
					_Scope.GotoState("None");
				}
			}
		}
	}
	NotifyWeaponModZoom();
	*/
}
void AAGP_Weapon::Zoom()
{
	APlayerController* PC = nullptr;
	if (_Scope == nullptr)
	{
		return;
	}
	/*
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::Zoom");
	}
	if (Instigator != nullptr && Instigator.Controller != nullptr && Instigator.Controller->IsA(APlayerController::StaticClass()))
	{
		PC=Cast<APlayerController>(Instigator.Controller);
		if (PC != nullptr)
		{
			PC.CalcSoundDampening();
			_Scope.Zoom(PC);
		}
	}
	else
	{
		if (Instigator.Controller != nullptr && Instigator->IsA(AaAIController::StaticClass()))
		{
			if (_Scope != nullptr)
			{
				_Scope.GotoState('Zoomed');
			}
		}
	}
	NotifyWeaponModZoom();
	*/
}

bool AAGP_Weapon::IsZoomed()
{
	return _Scope != NULL && Cast<ABaseScope>(_Scope)->IsZoomed();
}

bool AAGP_Weapon::ShouldBreatheCycle()
{
	return IsZoomed();
}

float AAGP_Weapon::GetZoomMultiplier()
{
	if (IsZoomed() && _Scope != NULL)
	{
		return Cast<ABaseScope>(_Scope)->GetZoomMultiplier();
	}
	else
	{
		return 1.0f;
	}
}

bool AAGP_Weapon::IsCharged()
{
	return true;
}
bool AAGP_Weapon::IsJammed()
{
	return (bIsJammed && eROF != ERateofFire::ROF_SingleGren);
}
bool AAGP_Weapon::IsOpFor()
{
	return bWeaponIsOpFor;
}
void AAGP_Weapon::Finish()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponState)
	{
		//DebugLog(DEBUG_Inv,Self @ "AGP_Weapon::Finish - Instigator" @ Instigator @ "Controller" @ Instigator.Controller);
	}
	/*
	if (Instigator == nullptr || Instigator.Controller == nullptr)
	{
		GotoState("None");
		return;
	}
	GotoState('Idle');
	*/
}
void AAGP_Weapon::ClientFinish()
{
	
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponState)
	{
		//DebugLog(DEBUG_Inv,Self @ "AGP_Weapon::ClientFinish - Instigator" @ Instigator @ "Controller" @ Instigator.Controller);
	}
	/*
	if (Instigator == nullptr || Instigator.Controller == nullptr)
	{
		GotoState("None");
		return;
	}
	GotoState('Idle');
	*/
}
void AAGP_Weapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bPendingChangeWeapon)
	{
		if (PendingChangeWeaponTimeStamp < GetWorld()->GetTimeSeconds())
		{
			bPendingChangeWeapon=false;
		}
	}
	if (GuardTimer > 0)
	{
		GuardTimer -= DeltaTime;
	}
	else
	{
		/*
		if (Instigator != nullptr && ! IsBusy() && ! Instigator.bIsProne)
		{
			switch(Instigator.UpperBodyAnim)
			{
				case 69:
				case 74:
				case 6:
				case 26:
				case 30:
				case 34:
				case 40:
				TempLowerWeapon(true);
				default:
			}
		}
		*/
	}
}
bool AAGP_Weapon::CanUseWeapon(int32 DesiredAction)
{
	switch(DesiredAction)
	{
		case WEAPON_ACTION_DROP:
			return !IsSupported();
		case WEAPON_ACTION_RELOAD:
			return !CheckForNoReload();
		case WEAPON_ACTION_SUPPORT:
			return !bPendingChangeWeapon;
		default:
			return true;
	}
}

bool AAGP_Weapon::CanSprint()
{
	//return ! IsBusy() || AnimIsInGroup(0,'Crawling');
	return false;   //Fake /ELiZ
}

bool AAGP_Weapon::CanCombatRoll(bool bActual)
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		return true;
	}
	else
	{
		return ! IsBusy() || AnimIsInGroup(0,'Crawling');
	}
	*/
	return false;   //Fake /ELiZ
}

EUpperBodyAnim AAGP_Weapon::GetUpperBodyLowerAnim()
{
	return EUpperBodyAnim::UBANIM_WEAP_LowerLg;
}

EUpperBodyAnim AAGP_Weapon::GetUpperBodyRaiseAnim()
{
	return EUpperBodyAnim::UBANIM_WEAP_RaiseLg;
}

EUpperBodyAnim AAGP_Weapon::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_NONE_Large;
}

AInventory* AAGP_Weapon::GetSwapContainer()
{
	if (Cast<AAGP_Pawn>(GetInstigator()) != NULL)
	{
		return Cast<AAGP_Pawn>(GetInstigator())->getInvContainerShoulder();
	}
	return nullptr;
}
void AAGP_Weapon::ForceTempRaiseWeapon()
{
	/*
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	GotoState('BusyTempRaising');
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientGotoState('BusyTempRaising',"None");
	}
	*/
}
bool AAGP_Weapon::IsBusy()
{
	return false;
}

/* ======================================================================================
 * AGP Function getMyType
 *
 * Returns the weapon's type (in terms of EContactSpecialWeapons enum in Actor).
 *
 * input:	none
 * output: EContactSpecialWeapons - the type of the weapon
 * effects: none
 * notes:   only implemented for weapons current 28 November 2001
 * last modified by: dnback
 * ======================================================================================
 */

EContactSpecialWeapons AAGP_Weapon::getMyType()
{
	return Type;
}

void AAGP_Weapon::SetFastMove(bool fast)
{
}

bool AAGP_Weapon::ShouldDrawCrosshair()
{
	ABaseWeaponMod* WM = nullptr;
	if (IsZoomed() && (!bDebugSights))
	{
		return false;
	}
	for (WM = WeaponModList; WM != nullptr; WM = WM->NextWeaponMod)
	{
		if (WM->IsA(AWeaponMod_Anpeq5_Laser::StaticClass()))
		{
			return false;
		}
	}
	return true;
}

/*
 // ======================================================================================
 // AGP function - GetROFString
 // Gets the string name of the eROF enumerator for printout on the HUD
 // output:	String label of the firing mode
 // last modified by:  superville 03/13/02
 // ======================================================================================
*/

FString AAGP_Weapon::getROFString()
{
	switch(eROF)
	{
		case ERateofFire::ROF_Single:			return "Single";
		case ERateofFire::ROF_Burst:			return "Burst";
		case ERateofFire::ROF_Auto:				return "Auto";
		case ERateofFire::ROF_SingleGren:		return "Grenade - Single";
		default:								return "";
	}
}

/* =================================================================================== *
 * AGP function GetBreatheMultiplier()
 *	Lighter weapons (<5kg) have smaller breathe cycles.
 *
 * output:	float - multiplier to apply to the breathe cycle
 * last modified by: cmb
 * =================================================================================== */

float AAGP_Weapon::GetBreatheMultiplier()
{
	if (fWeight >= 5)
	{
		return 1;
	}
	else
	{
		return (fWeight + 1.0) / 6.0;	//range [0.16 , 1.0]
	}
}

/*
 // ======================================================================================
 // AGP function - AmmoStatus (Overrides Weapon)
 // Returns the percentage of ammo left in the gun for the ammotype currently being used
 // output: float [0,1] percentage of ammo left in the gun related to it's max count
 // last modified by:  superville 03/15/02
 // ======================================================================================
*/
float AAGP_Weapon::AmmoStatus()
{
	/*
	if (GetCurrentAmmoType() != nullptr)
	{
		return GetCurrentAmmoType().AmmoAmount / GetCurrentAmmoType().MaxAmmo;
	}
	*/
	return 0;
}

/*
 // ======================================================================================
 // AGP function - HasAmmo (Overrides Weapon)
 // Determines if weapon currently has ammo based on the current ammotype
 // output:	bool true if the weapon has ammo in it, false otherwise
 // last modified by:  superville 03/15/02
 // ======================================================================================
*/

bool AAGP_Weapon::HasAmmo()
{
	/*
	int32 i = 0;
	if (GetCurrentAmmoType() != nullptr)
	{
		if (GetCurrentAmmoType().HasAmmo())
		{
			return true;
		}
	}
	for (i=0; i<16; i++)
	{
		if (GetClipCount(i) > 0)
		{
			return true;
		}
	}
	*/
	return false;
}
void AAGP_Weapon::NotifyOutOfAmmo()
{
	/*
	if (_AmmoMonitor != nullptr)
	{
		_AmmoMonitor.update();
	}
	if (Instigator.EventLab != nullptr)
	{
		Instigator.EventLab.ActorNotify(this,21,Instigator,"WeaponOutOfAmmo");
	}
	*/
}
UScriptObject* AAGP_Weapon::GetAmmoMonitor()
{
	return _AmmoMonitor;
}

void AAGP_Weapon::SetAmmoMonitor(UScriptObject* sobj)
{
	_AmmoMonitor=sobj;
}
void AAGP_Weapon::NotifyJammed()
{
	/*
	if (_JammedMonitor != nullptr)
	{
		_JammedMonitor.update();
	}
	if (Instigator.EventLab != nullptr)
	{
		Instigator.EventLab.ActorNotify(this,20,Instigator,"WeaponJammed");
	}
	*/
}

UScriptObject* AAGP_Weapon::GetJammedMonitor()
{
	return _JammedMonitor;
}

void AAGP_Weapon::SetJammedMonitor(UScriptObject* sobj)
{
	_JammedMonitor=sobj;
}

void AAGP_Weapon::BringUp()
{
	/*
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientBringUp();
	}
	if (IsReplicationComplete())
	{
		GotoState('BusyRaisingWeapon');
	}
	else
	{
		bBusyRaiseWeaponPending=true;
	}
	*/
}
void AAGP_Weapon::ClientBringUp()
{
	/*
	if (IsReplicationComplete())
	{
		GotoState('BusyRaisingWeapon');
	}
	else
	{
		bBusyRaiseWeaponPending=true;
	}
	*/
}
bool AAGP_Weapon::PutDown()
{
	if(GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientPutDown();
	}
	bChangeWeapon=true;
	//GotoState('BusyLoweringWeapon');
	return true;
}
void AAGP_Weapon::ClientPutDown()
{
	bChangeWeapon=true;
	/*
	GotoState('BusyLoweringWeapon');
	*/
}

void AAGP_Weapon::DoChangeFireMode()
{
	switch(eROF)
	{
		case ERateofFire::ROF_Single:		eROF = ERateofFire::ROF_Burst;			break;
		case ERateofFire::ROF_Burst:		eROF = ERateofFire::ROF_Auto;			break;
		case ERateofFire::ROF_Auto:			eROF = ERateofFire::ROF_Single;			break;
		default:																	break;
	}
}
void AAGP_Weapon::DoChangeFireModeAux()
{
	LastROF=eROF;
	eROF=AuxROF;
}
void AAGP_Weapon::DoChangeFireModeLast()
{
	eROF=LastROF;
}
void AAGP_Weapon::DoFixJam()
{
	/*
	if (bIsRuined)
	{
		return;
	}
	if (Instigator != nullptr && Instigator.Controller != nullptr && Instigator.IsHumanControlled())
	{
		Instigator.Controller.StopFiring();
	}
	bIsJammed=false;
	*/
}
void AAGP_Weapon::DoSupported()
{
	/*
	if (Instigator != nullptr)
	{
		Instigator.LockMovement(bIsSupported);
		Instigator.LimitRotation(bIsSupported);
	}
	if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
	}
	*/
}

AActor* AAGP_Weapon::GetSoundActor()
{
	return this;
}

void AAGP_Weapon::PlayWeaponSound(USoundBase* pSound, USoundBase* esound, float Volume, float Radius)
{
	if (Volume == 0)
	{
		Volume=0.5;
	}
	if (Radius == 0)
	{
		Radius=60;
	}
	/*
	if (Instigator == Level.GetClientPawn())
	{
		GetSoundActor().PlaySound(pSound,0,Volume,true,Radius,1,false,true);
	}
	else
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
		{
			esound=pSound;
		}
		if (Instigator != nullptr && Instigator.Controller != nullptr && Instigator.Controller->IsA(AaAIController::StaticClass()))
		{
			esound=pSound;
		}
		GetSoundActor().PlayOwnedSound(pSound,0,Volume,false,Radius,1,true,false,esound,idTeamOwner);
	}
	*/
}
void AAGP_Weapon::ServerDryFire()
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		DryFire();
	}
	*/
}
void AAGP_Weapon::DryFire()
{
	/*
	if (GetNetMode() == ENetMode::NM_Client)
	{
		ServerDryFire();
	}
	PlayDryFire();
	*/
}
void AAGP_Weapon::PlayDryFire()
{
	//PlayWeaponSound(DryFireSound,EnemyWeaponClass.Default.DryFireSound);
}
void AAGP_Weapon::AnimEnd(int32 Channel)
{
	//GotoState('Idle');
}
void AAGP_Weapon::PlayIdleAnim()
{
	/*
	if (IsSupported())
	{
		if (IsZoomed() && ShouldUse3dSights())
		{
			if (_Scope != nullptr && _Scope.bAux3dSights && HasAnim(AuxSupportedZoomIdleAnim))
			{
				RunAnimation(AuxSupportedZoomIdleAnim,1,0.05,true);
			}
			else
			{
				if (HasAnim(SupportedZoomIdleAnim))
				{
					RunAnimation(SupportedZoomIdleAnim,1,0.05,true);
				}
			}
		}
		else
		{
			RunAnimation('SupportedStill',1,0.05,true);
		}
	}
	else
	{
		if (IsZoomed() && ShouldUse3dSights())
		{
			if (_Scope != nullptr && _Scope.bAux3dSights && HasAnim(AuxZoomIdleAnim))
			{
				RunAnimation(AuxZoomIdleAnim,1,0.05,true);
			}
			else
			{
				if (HasAnim(ZoomIdleAnim[ElevationIndex]))
				{
					RunAnimation(ZoomIdleAnim[ElevationIndex],1,0.05,true);
				}
			}
		}
		else
		{
			if (HasAnim('Still'))
			{
				RunAnimation('Still',1,0.05,true);
			}
			else
			{
				RunAnimation('Idle',1,0.05,true);
			}
		}
	}
	*/
}

AActor* AAGP_Weapon::GetAnimActor()
{
	return this;
}

void AAGP_Weapon::RunAnimation(FName Sequence, float Rate, float TweenTime, bool bLoop)
{
	
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponAcc)
	{
		UE_LOG(LogTemp, Warning, TEXT("entered runanimation()"));
	}

	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		if (bLoop)
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponAcc)
			{
				UE_LOG(LogTemp, Warning, TEXT("TweenTime = %d"), TweenTime);
			}
			//GetAnimActor().LoopAnim(Sequence,Rate,TweenTime);
		}
		else
		{
			//DebugLog(DEBUG_Inv,"Weapon animation '" + Sequence + "' for weapon " + this + " lasts for " + GetAnimActor().GetAnimDuration(Sequence,Rate));
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponAcc)
			{
				UE_LOG(LogTemp, Warning, TEXT("TweenTime = %d"),TweenTime);
			}
			//GetAnimActor().PlayAnim(Sequence,Rate,TweenTime);
		}
		NotifyWeaponModAnimations(Sequence,Rate,TweenTime,bLoop);
	}
	else
	{
		//AnimTimerDuration=GetAnimActor().GetAnimDuration(Sequence,Rate) + TweenTime;
	}
	NotifyWeaponAttachmentAnimations(Sequence,Rate,TweenTime,bLoop);
}
void AAGP_Weapon::NotifyWeaponAttachmentAnimations(FName Sequence, float Rate, float TweenTime, bool bLoop)
{
	ABaseWeaponAttachment* BWA = nullptr;
	/*
	BWA=BaseWeaponAttachment(ThirdPersonActor);
	if (BWA != nullptr && BWA != GetAnimActor())
	{
		BWA.NotifyWeaponAnimation(Sequence,Rate,TweenTime,bLoop);
	}
	*/
}

USoundBase* AAGP_Weapon::GetFireSound()
{
	/*
	if (Region.Zone.bIndoorZone)
	{
		if (eROF == 4)
		{
			return AuxSingleFire;
		}
		else
		{
			if (bSuppressorOn)
			{
				if (SuppressedSingleFire != nullptr)
				{
					return SuppressedSingleFire;
				}
			}
		}
		return SingleFire;
	}
	else
	{
		if (eROF == 4)
		{
			return AuxOutdoorSingleFire;
		}
		else
		{
			if (bSuppressorOn)
			{
				if (SuppressedOutdoorSingleFire != nullptr)
				{
					return SuppressedOutdoorSingleFire;
				}
			}
		}
		return OutdoorSingleFire;
	}
	*/
	return OutdoorSingleFire;    //FAKE   //ELiZ
}

USoundBase* AAGP_Weapon::GetEnemyFireSound()
{
	/*
	if (Region.Zone.bIndoorZone)
	{
		if (eROF == 4)
		{
			return EnemyWeaponClass.Default.AuxSingleFire;
		}
		else
		{
			if (bSuppressorOn)
			{
				if (EnemyWeaponClass.Default.SuppressedSingleFire != nullptr)
				{
					return EnemyWeaponClass.Default.SuppressedSingleFire;
				}
			}
		}
		return EnemyWeaponClass.Default.SingleFire;
	}
	else
	{
		if (eROF == 4)
		{
			return EnemyWeaponClass.Default.AuxOutdoorSingleFire;
		}
		else
		{
			if (bSuppressorOn)
			{
				if (EnemyWeaponClass.Default.SuppressedOutdoorSingleFire != nullptr)
				{
					return EnemyWeaponClass.Default.SuppressedOutdoorSingleFire;
				}
			}
		}
		return EnemyWeaponClass.Default.OutdoorSingleFire;
	}
	*/

	return OutdoorSingleFire;    //FAKE   //ELiZ
}

bool AAGP_Weapon::GetSpecialFireAnim(FName& SpecialAnimName)
{
	return false;    //FAKE   /ELiZ
}

void AAGP_Weapon::PlayFiring()
{
	int32 Num = 0;
	float Rate = 0;
	FName special_anim = "";
	/*
	SetupMuzzleFlash();
	if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
	}
	if (IsSuppressed())
	{
		PlayWeaponSound(GetFireSound(),GetEnemyFireSound(),0.9,125);
	}
	else
	{
		PlayWeaponSound(GetFireSound(),GetEnemyFireSound(),0.9,400);
	}
	Rate=0.5 + 0.5 * FireAdjust;
	if (GetSpecialFireAnim(special_anim))
	{
		RunAnimation(special_anim,Rate,FiringTweenTime);
	}
	else
	{
		if (IsSupported())
		{
			if (DrawType == 2 && ShouldUse3dSights() && IsZoomed())
			{
				if (_Scope.bAux3dSights)
				{
					if (DrawType == 2 && HasAnim(AuxSupportedZoomFireAnims[1]))
					{
						if (HasAnim(AuxSupportedZoomFireAnims[2]))
						{
							Num=Rand(3);
						}
						else
						{
							Num=Rand(2);
						}
					}
					else
					{
						Num=1;
					}
					if (HasAnim(AuxSupportedZoomFireAnims[Num]))
					{
						RunAnimation(AuxSupportedZoomFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
					else
					{
						RunAnimation(SupportedFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
				}
				else
				{
					if (DrawType == 2 && HasAnim(SupportedZoomFireAnims[1]))
					{
						if (HasAnim(SupportedZoomFireAnims[2]))
						{
							Num=Rand(3);
						}
						else
						{
							Num=Rand(2);
						}
					}
					else
					{
						Num=1;
					}
					if (HasAnim(SupportedZoomFireAnims[Num]))
					{
						RunAnimation(SupportedZoomFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
					else
					{
						RunAnimation(SupportedFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
				}
			}
			else
			{
				if (DrawType == 2 && HasAnim('SupportedFireB'))
				{
					if (HasAnim('SupportedFireC'))
					{
						Num=Rand(3);
					}
					else
					{
						Num=Rand(2);
					}
				}
				else
				{
					Num=1;
				}
				RunAnimation(SupportedFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
			}
		}
		else
		{
			if (DrawType == 2 && ShouldUse3dSights() && IsZoomed())
			{
				if (_Scope.bAux3dSights)
				{
					if (DrawType == 2 && HasAnim(AuxZoomFireAnims[1]))
					{
						if (HasAnim(AuxZoomFireAnims[2]))
						{
							Num=Rand(3);
						}
						else
						{
							Num=Rand(2);
						}
					}
					else
					{
						Num=1;
					}
					if (HasAnim(AuxZoomFireAnims[Num]))
					{
						RunAnimation(AuxZoomFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
					else
					{
						RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
				}
				else
				{
					if (DrawType == 2 && HasAnim(ZoomFireAnims[1]))
					{
						if (HasAnim(ZoomFireAnims[2]))
						{
							Num=Rand(3);
						}
						else
						{
							Num=Rand(2);
						}
					}
					else
					{
						Num=1;
					}
					if (HasAnim(ZoomFireAnims[Num]))
					{
						RunAnimation(ZoomFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
					else
					{
						RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
				}
			}
			else
			{
				if (DrawType == 2 && HasAnim('FireB'))
				{
					if (HasAnim('FireC'))
					{
						Num=Rand(3);
					}
					else
					{
						Num=Rand(2);
					}
				}
				else
				{
					Num=1;
				}
				RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
			}
		}
	}
	HandleRecoil();
	*/
}
void AAGP_Weapon::HandleRecoil()
{
	FRotator Recoil;
	float RecoilAlpha=0;
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		if (bWpnRecoil)
		{
			/*
			if (Instigator != nullptr)
			{
				ConsecutiveShots ++;
				if (bUseAutoRecoil && eROF == 3 || eROF == 2 && ConsecutiveShots >= ShotsToStartRecoilBlend)
				{
					RecoilAlpha=FClamp(ConsecutiveShots - ShotsToStartRecoilBlend - 1 / ShotsForMaxRecoil - ShotsToStartRecoilBlend - 1,0,1);
					Recoil=1 - RecoilAlpha * CalcRotation(_RecoilDirInfo) + RecoilAlpha * CalcRotation(_AutoRecoilDirInfo);
				}
				else
				{
					Recoil=CalcRotation(_RecoilDirInfo);
				}
				if (Cast<AAGP_Pawn>(Instigator).bNewAccuracy)
				{
					Recoil=Recoil * FMax(1 - Instigator.CE_MeterValue,BaseRecoilModifier) * GlobalRecoilScaler;
				}
				else
				{
					Recoil=Recoil * FMax(1 - Instigator.CE_MeterValue,BaseRecoilModifier);
				}
				Instigator.SetViewRotation(Recoil + Instigator.GetViewRotation());
			}
			*/
		}
	}
}

void AAGP_Weapon::NPC_PlayFiring()
{
	int32 Num = 0;
	float Rate = 0;
	FName special_anim = "";
	SetupMuzzleFlash();
	/*
	if (IsSuppressed())
	{
		PlayWeaponSound(GetFireSound(),GetEnemyFireSound(),0.9,125);
	}
	else
	{
		PlayWeaponSound(GetFireSound(),GetEnemyFireSound(),0.9,400);
	}
	Rate=0.5 + 0.5 * FireAdjust;
	if (GetSpecialFireAnim(special_anim))
	{
		RunAnimation(special_anim,Rate,0.05);
	}
	else
	{
		if (IsSupported())
		{
			if (HasAnim('SupportedFireB'))
			{
				if (HasAnim('SupportedFireC'))
				{
					Num=Rand(3);
				}
				else
				{
					Num=Rand(2);
				}
			}
			else
			{
				Num=1;
			}
			RunAnimation(SupportedFireAnims[Num],0.5 + 0.5 * FireAdjust,0.05);
		}
		else
		{
			if (HasAnim('FireB'))
			{
				if (HasAnim('FireC'))
				{
					Num=Rand(3);
				}
				else
				{
					Num=Rand(2);
				}
			}
			else
			{
				Num=1;
			}
			RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjust,0.05);
		}
	}
	HandleRecoil();
	*/
}

void AAGP_Weapon::PlayReloading()
{
	float fpReloadRate = 0;
	fpReloadRate = 1.4;
	/*
	if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
	}
	if (eROF == AuxROF)
	{
		if (GetAuxAmmoType() != nullptr && GetAuxAmmoType()->IsA(AAmmo_30mm_1_Gren::StaticClass()) || GetAuxAmmoType()->IsA(AAmmo_40mm_1_Gren::StaticClass()) || GetAuxAmmoType()->IsA(AAmmo_40mm_1_Gren_Mod::StaticClass()))
		{
			fpReloadRate=1;
		}
		if (HasAnim('ReloadEmpty'))
		{
			RunAnimation('ReloadEmpty',fpReloadRate,0.05);
		}
		else
		{
			RunAnimation('Reload',fpReloadRate,0.05);
		}
		if (ShouldDoDelayedEject())
		{
			DiscardShell();
		}
		if (! bUseAnimNotifySounds)
		{
			PlayWeaponSound(AltReloadSound,EnemyWeaponClass.Default.AltReloadSound);
		}
	}
	else
	{
		if (IsSupported())
		{
			if (GetCurrentAmmoType() != nullptr && GetCurrentAmmoType().HasAmmo())
			{
				RunAnimation(ProneReloadFullAnim,fpReloadRate);
				if (! bUseAnimNotifySounds)
				{
					PlayWeaponSound(ProneReloadFullSound,EnemyWeaponClass.Default.ProneReloadFullSound);
				}
			}
			else
			{
				RunAnimation(ProneReloadEmptyAnim,fpReloadRate);
				if (! bUseAnimNotifySounds)
				{
					PlayWeaponSound(ProneReloadSound,EnemyWeaponClass.Default.ReloadSound);
				}
			}
		}
		else
		{
			if (GetCurrentAmmoType() != nullptr && GetCurrentAmmoType().HasAmmo())
			{
				RunAnimation(ReloadFullAnim,fpReloadRate);
				if (! bUseAnimNotifySounds)
				{
					if (ReloadFullSound != nullptr)
					{
						PlayWeaponSound(ReloadFullSound,EnemyWeaponClass.Default.ReloadFullSound);
					}
					else
					{
						PlayWeaponSound(ReloadSound,EnemyWeaponClass.Default.ReloadSound);
					}
				}
			}
			else
			{
				RunAnimation(ReloadEmptyAnim,fpReloadRate);
				if (! bUseAnimNotifySounds)
				{
					PlayWeaponSound(ReloadSound,EnemyWeaponClass.Default.ReloadSound);
				}
			}
		}
	}
	*/
}
void AAGP_Weapon::PlayChangeFireMode()
{
	/*
	switch(NewAuxMode)
	{
		case 0:
		if (IsSupported())
		{
			if (ShouldUse3dSights() && IsZoomed())
			{
				if (_Scope != nullptr && _Scope.bAux3dSights)
				{
					RunAnimation(AuxSupportedZoomFireAnims[0],0.5);
					break;
				}
				RunAnimation(SupportedZoomFireAnims[0],0.5);
			}
		}
		else
		{
			if (eROF == 1)
			{
				RunAnimation('SupportedChangeFireMode',1);
			}
			else
			{
				RunAnimation('SupportedChangeFireModeBack',1);
			}
		}
	}
	else
	{
		if (ShouldUse3dSights() && IsZoomed())
		{
			if (_Scope != nullptr && _Scope.bAux3dSights)
			{
				RunAnimation(AuxZoomFireAnims[0],0.5);
			}
			else
			{
				RunAnimation(ZoomFireAnims[0],0.5);
			}
		}
		else
		{
			if (eROF == 1)
			{
				RunAnimation('ChangeFireMode',1);
			}
			else
			{
				RunAnimation('ChangeFireModeBack',1);
			}
		}
	}
	GOTO JL017A;
	case 1:
	SelectAuxFireMode();
	RunAnimation('Swap',1);
	GOTO JL017A;
	case 2:
	SelectNormalMode();
	RunAnimation('Swapback',1);
	GOTO JL017A;
	default:
JL017A:
	PlayWeaponSound(ChangeFireSound,EnemyWeaponClass.Default.ChangeFireSound);
	*/
}

void AAGP_Weapon::PlayFixJam()
{
	float fpFixJamRate = 0;
	fpFixJamRate = 1.4;
	/*
	if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
	}
	if (IsSupported())
	{
		RunAnimation('SupportedFixJam',fpFixJamRate,0.05);
		PlayWeaponSound(ProneFixJamSound,EnemyWeaponClass.Default.ProneFixJamSound);
	}
	else
	{
		RunAnimation('FixJam',fpFixJamRate,0.05);
		PlayWeaponSound(FixJamSound,EnemyWeaponClass.Default.FixJamSound);
	}
	*/
}

void AAGP_Weapon::PlaySupporting()
{
	float fpSupportedRate = 0;
	fpSupportedRate = 1.4;
	/*
	DoSupported();
	if (IsSupported())
	{
		RunAnimation('Supported',fpSupportedRate,0.05);
		PlayWeaponSound(SupportingSound,EnemyWeaponClass.Default.SupportingSound);
	}
	else
	{
		RunAnimation('Unsupported',fpSupportedRate,0.05);
		PlayWeaponSound(UnSupportingSound,EnemyWeaponClass.Default.UnSupportingSound);
	}
	*/
}

void AAGP_Weapon::PlaySelect()
{
	int32 initradius = 0;
	float fpDropRaiseRate = 0;
	fpDropRaiseRate = 1.4;
	/*
	if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
	}
	if (IsZoomed() && ShouldUse3dSights())
	{
		PlayIdleAnim();
	}
	else
	{
		if (! IsAnimating() || ! AnimIsInGroup(0,'Select') || ! AnimIsInGroup(0,'SelectNew'))
		{
			if (_bActive)
			{
				if (HasAnim('Raise'))
				{
					RunAnimation('Raise',fpDropRaiseRate);
				}
				else
				{
					RunAnimation('Select',fpDropRaiseRate);
				}
			}
			else
			{
				if (! _bCharged && HasAnim('SelectNew'))
				{
					if (Instigator != nullptr && Instigator.bIsSprinting)
					{
						Instigator.StopSprint();
					}
					_bCharged=true;
					RunAnimation('SelectNew',1);
					if (GetNetMode() == ENetMode::NM_Client)
					{
						initradius=1000000;
					}
					else
					{
						initradius=60;
					}
					PlayWeaponSound(SelectChargeSound,EnemyWeaponClass.Default.SelectChargeSound,,initradius);
				}
				else
				{
					RunAnimation('Select',fpDropRaiseRate);
					PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
				}
			}
		}
	}
	*/
}

void AAGP_Weapon::TweenDown()
{
	FName SeqName = "";
	float AnimFrame = 0;
	float AnimRate = 0;
	float fpDropAnimRate = 0;
	fpDropAnimRate = 1.3;
	/*
	GetAnimParams(0,SeqName,AnimFrame,AnimRate);
	if (IsAnimating() && AnimIsInGroup(0,'Select') || AnimIsInGroup(0,'SelectNew'))
	{
		TweenAnim(SeqName,AnimFrame * 0.4);
	}
	else
	{
		if (_bActive)
		{
			if (HasAnim('Drop'))
			{
				RunAnimation('Drop',fpDropAnimRate);
			}
			else
			{
				RunAnimation('Down',fpDropAnimRate);
			}
		}
		else
		{
			PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
			if (SeqName == 'Drop' || SeqName == 'DropStill')
			{
				RunAnimation('LowDown',fpDropAnimRate);
			}
			else
			{
				RunAnimation('Down',fpDropAnimRate);
			}
		}
	}
	*/
}

void AAGP_Weapon::PlayHighCrawlIn()
{
	/*
	if (_bTossNotThrow)
	{
		RunAnimation('LowHighCrawlIn',1);
	}
	else
	{
		RunAnimation('HighCrawlIn',1);
	}
	*/
}

void AAGP_Weapon::PlayCrawl()
{
	/*
	if (Instigator != nullptr && Instigator.bIsWalking)
	{
		GotoState('OutCrawling');
	}
	else
	{
		RunAnimation('HighCrawl',1,,true);
	}
	*/
}

void AAGP_Weapon::PlayHighCrawlOut()
{
	/*
	if (_bTossNotThrow)
	{
		RunAnimation('LowHighCrawlOut',1);
	}
	else
	{
		RunAnimation('HighCrawlOut',1);
	}
	*/
}

void AAGP_Weapon::SetupAuxWeaponMesh(USkeletalMesh* new_mesh, USkeletalMesh* new_aux_mesh)
{
	/*
	NrmFireMesh=new_mesh;
	AuxFireMesh=new_aux_mesh;
	if (NrmFireMesh != nullptr)
	{
		LinkMesh(new_mesh);
		RunAnimation('SelectNew',1);
	}
	*/
}
void AAGP_Weapon::SetupAuxAmmoRound(ABaseAmmoRound* new_aux_round, int32 new_num_aux)
{
	/*
	AuxAmmoRoundClass=new_aux_round;
	NumAuxAmmoRound=new_num_aux;
	*/
}
void AAGP_Weapon::SetupAuxAmmo(AAmmunition* new_aux_ammo, int32 new_aux_pcount)
{
	/*
	AuxAmmoName=new_aux_ammo;
	AuxROF=4;
	AuxPickupAmmoCount=new_aux_pcount;
	*/
}
void AAGP_Weapon::SetupAuxMuzzleFlash(AEmitter* new_muzzle, FBoneOffset new_offset)
{
	/*
	_FPAuxMuzzleFlashClass=new_muzzle;
	_FPAuxMuzzleFlashOffset=new_offset;
	*/
}
void AAGP_Weapon::SetupAuxSounds(USoundBase* new_fire, USoundBase* new_outdoor_fire, USoundBase* new_reload)
{
	/*
	AuxSingleFire=new_fire;
	AuxOutdoorSingleFire=new_outdoor_fire;
	AltReloadSound=new_reload;
	*/
}
void AAGP_Weapon::SelectAuxFireMode()
{
	/*
	LinkMesh(AuxFireMesh);
	_FPMuzzleFlashEmitter=AuxMuzzleFlashEmitter;
	if (_FPMuzzleFlashEmitter != nullptr)
	{
		AttachToBoneOffset(_FPMuzzleFlashEmitter,_FPAuxMuzzleFlashOffset);
	}
	*/
}
void AAGP_Weapon::SelectNormalMode()
{
	/*
	LinkMesh(NrmFireMesh);
	DoSuppressor(bSuppressorOn);
	*/
}
void AAGP_Weapon::FailedSupported()
{
	/*
	if (AuxROF != 0)
	{
		if (! IsBusy() || IsTempBusy())
		{
			if (eROF == AuxROF)
			{
				ChangeAuxMode(2);
			}
			else
			{
				ChangeAuxMode(1);
			}
		}
	}
	*/
}
void AAGP_Weapon::ChangeAuxMode(ENewAuxMode new_mode)
{
	/*
	NewAuxMode=new_mode;
	ServerChangeAuxMode(NewAuxMode);
	if (GetNetMode() == ENetMode::NM_Client)
	{
		GotoState('BusyChangingFireMode');
	}
	*/
}
void AAGP_Weapon::ServerChangeAuxMode(ENewAuxMode new_mode)
{
	/*
	NewAuxMode=new_mode;
	GotoState('BusyChangingFireMode');
	*/
}

void AAGP_Weapon::UpdateSpecialAttachment(bool bRenderAttachment)
{
}

void AAGP_Weapon::SetupMuzzleFlash()
{
	int32 i = 0;
	int32 Count = 0;
	AHumanController* HC = nullptr;
	bool bFirstPerson = false;
	/*
	if (Owner != nullptr && Pawn(GetOwner()) != nullptr)
	{
		HC=Cast<AHumanController>(Cast<APawn>(GetOwner())->Controller);
	}
	if (HC != nullptr)
	{
		bFirstPerson=! HC.bBehindView && Pawn(GetOwner()) != nullptr && HC.ViewTarget == Cast<APawn>(GetOwner());
	}
	else
	{
		bFirstPerson=false;
	}
	IncrementFlashCount();
	if (! IsZoomed() || ShouldUse3dSights() && bFirstPerson)
	{
		if (_FPMuzzleFlashClass == nullptr)
		{
			bMuzzleFlash=true;
			bSetFlashTime=false;
		}
		else
		{
			if (_FPMuzzleFlashEmitter != nullptr)
			{
				Count=_FPMuzzleFlashEmitter.EmitterCount();
				for (i=0; i<Count; i++)
				{
					_FPMuzzleFlashEmitter.Emitters[i].SpawnParticle(_FPMuzzleFlashEmitter.Emitters[i].iFlashSpawnCount);
				}
				_FPMuzzleFlashEmitter.DynamicFlash();
			}
		}
	}
	else
	{
		if (IsZoomed() && ! ShouldUse3dSights() && bFirstPerson)
		{
			if (_FPMuzzleFlashClass == nullptr)
			{
				bMuzzleFlash=true;
				bSetFlashTime=false;
			}
			else
			{
				if (_FPMuzzleFlashEmitter != nullptr)
				{
					_FPMuzzleFlashEmitter.DynamicFlash();
				}
			}
		}
	}
	*/
}

void AAGP_Weapon::IncrementFlashCount()
{
	ABaseWeaponAttachment* BA = nullptr;
	/*
	FlashCount=FlashCount + 1 % 254;
	BA=BaseWeaponAttachment(ThirdPersonActor);
	if (BA != nullptr)
	{
		switch(eROF)
		{
			case 1:
			BA.FiringMode='ROF_Single';
			break;
			case 2:
			BA.FiringMode='ROF_Burst';
			break;
			case 3:
			BA.FiringMode='ROF_Auto';
			break;
			case 4:
			BA.FiringMode='ROF_SingleGren';
			break;
			default:
		}
		BA.FlashCount=FlashCount;
		BA.ThirdPersonEffects();
	}
	else
	{
		DebugLog(DEBUG_Warn,"AGP_Weapon::IncrementFlashCount()	Could not find BaseWeaponAttachment " + ThirdPersonActor);
	}
	*/
}
void AAGP_Weapon::NotifyAddAmmo(AAmmunition* NewAmmo)
{
	if ((NewAmmo != NULL) && (NewAmmo->GetClass() == AuxAmmoName) && (Cast<AAmmunition>(NewAmmo)->AmmoAmount > 0))
	//if ((newAmmo.class == AuxAmmoName) && (newAmmo.AmmoAmount > 0))
	{
		AuxAmmoMagCount ++;
	}
	Super::NotifyAddAmmo(NewAmmo);
}
void AAGP_Weapon::NotifyDeleteAmmo(AAmmunition* OldAmmo)
{
	
	if ((OldAmmo != NULL) && (OldAmmo->GetClass() == AuxAmmoName))
	{
		AuxAmmoMagCount --;
	}
	Super::NotifyDeleteAmmo(OldAmmo);
}

bool AAGP_Weapon::WeaponDisabled()
{
	/*
	if (bIsRuined || bIsJammed || GetCurrentAmmoType() != nullptr && GetCurrentAmmoType().AmmoAmount <= 0)
	{
		return true;
	}
	*/
	return false;
}

float AAGP_Weapon::GetMinimumRange()
{
	return 0;
}
float AAGP_Weapon::GetOptimalRange()
{
	return 500;
}
float AAGP_Weapon::GetMaximumRange()
{
	return 4800;
}
TSubclassOf<AAmmunition> AAGP_Weapon::GetCurrentAmmoName()
{
	if (eROF == AuxROF)
	{
		return AuxAmmoName;
	}
	else
	{
		return AmmoName;
	}
}
AAmmunition* AAGP_Weapon::GetCurrentAmmoType()
{
	
	if (eROF == AuxROF)
	{
		return AuxAmmoType;
	}
	else
	{
		return AmmoType;
	}
	
}
void AAGP_Weapon::SetCurrentAmmoType(AAmmunition* newAmmoType)
{
	/*
	if (eROF == AuxROF)
	{
		AuxAmmoType=newAmmoType;
	}
	else
	{
		AmmoType=newAmmoType;
	}
	*/
}
void AAGP_Weapon::SetCurrentAmmoName(AAmmunition* newAmmoName)
{
	/*
	if (eROF == AuxROF)
	{
		AuxAmmoName=newAmmoName;
	}
	else
	{
		AmmoName=newAmmoName;
	}
	*/
}
TSubclassOf<AAmmunition> AAGP_Weapon::GetAuxAmmoName()
{
	return AuxAmmoName;
}
AAmmunition* AAGP_Weapon::GetAuxAmmoType()
{
	return AuxAmmoType;
}

/* =================================================================================== *
 * AGP function GetClipCount()
 *	Get the round count at the specified index for the current ammo type.
 *	If bAuxAmmo is true, get the round count for AuxAmmo
 *
 * input:	clip		- The clip index
 *			bAuxAmmo	- If true, get AuxAmmoClip
 *
 * output:	byte		- The round count
 * last modified by: cmb
 * =================================================================================== */
int32 AAGP_Weapon::GetClipCount(uint8 clip, bool bAuxAmmo)
{
	if (GetCurrentAmmoType() == AuxAmmoType || bAuxAmmo)
	{
		return _AuxAmmoClips[clip];
	}
	else
	{
		return _AmmoClips[clip];
	}
}

/* =================================================================================== *
 * AGP function SetClipCount()
 *	Set the round count at the specified clip index to the specified amount.
 *	By default, set it for the current ammo type, unless bAuxAmmo is used, in which
 *	case always set the auxAmmo.
 *
 * input:	clip		- The clip index
 *			count		- The number of rounds to set
 *			bAuxAmmo	- If true, always set AuxAmmoClip
 *
 * effects:	Sets a member of one of the clip arrays.
 * notes:
 * last modified by: cmb
 * =================================================================================== */
void AAGP_Weapon::SetClipCount(uint8 clip, int32 Count, bool bAuxAmmo)
{
	if (GetCurrentAmmoType() == AuxAmmoType || bAuxAmmo)
	{
		_AuxAmmoClips[clip]=Count;
	}
	else
	{
		_AmmoClips[clip]=Count;
	}
}

/* =================================================================================== *
 * AGP function GetBestClip()
 *	return the index of the clip of the current ammo type with the most rounds in it.
 *
 * input:	byte	- The index
 * last modified by: cmb
 * =================================================================================== */
uint8 AAGP_Weapon::GetBestClip()
{
	int32 i = 0;
	int32 best_index = 0;
	int32 best_count = 0;
	int32 this_count = 0;
	best_index=0;
	/*
	best_count=GetClipCount(0);
	for (i=1; i<16; i++)
	{
		this_count=GetClipCount(i);
		if (this_count > best_count)
		{
			best_index=i;
			best_count=this_count;
		}
	}
	*/
	return best_index;
}
bool AAGP_Weapon::CheckForNoReload()
{
	int32 i = 0;
	if (SingleShotWeapon())
	{
		return true;
	}
	if (eROF == ERateofFire::ROF_SingleGren && ! OutOfAmmo())
	{
		return true;
	}
	/*
	if (GetCurrentAmmoType() != nullptr && GetCurrentAmmoType().ProjectileClass != nullptr && GetCurrentAmmoType().AmmoAmount == GetCurrentAmmoType().MaxAmmo)
	{
		return true;
	}
	for (i=0; i<16; i++)
	{
		if (GetClipCount(i) > 0)
		{
			return false;
		}
	}
	*/
	return true;
}
bool AAGP_Weapon::OutOfAmmo()
{
	if (GetCurrentAmmoType() != NULL && GetCurrentAmmoType()->HasAmmo())
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool AAGP_Weapon::SingleShotWeapon()
{
	return false;
}
void AAGP_Weapon::ReloadClip(uint8 newclip)
{
	int32 Swap = 0 ;
	AAmmunition* my_ammo = nullptr;
	/*
	my_ammo=GetCurrentAmmoType();
	if (my_ammo != nullptr)
	{
		Swap=my_ammo.AmmoAmount;
		my_ammo.AmmoAmount=GetClipCount(newclip);
		if (Swap > 0 && bAllowsPlusOneLoading)
		{
			Swap -= 1;
			my_ammo.AmmoAmount += 1;
		}
		SetClipCount(newclip,Swap);
		RecountAmmo();
	}
	*/
}
bool AAGP_Weapon::AddClip(AAmmunition* AmmoClass)
{
	int32 i = 0;
	/*
	DebugLog(DEBUG_Inv,"AGP_Weapon::AddClip()	" + AmmoClass @ AmmoName @ AuxAmmoName);
	if (AmmoClass == nullptr)
	{
		return false;
	}
	else
	{
		if (AmmoClass == AmmoName)
		{
			if (AmmoMagCount < MaxClips)
			{
				for (i=0; i<16; i++)
				{
					if (GetClipCount(i) <= 0)
					{
						SetClipCount(i,AmmoClass.Default.AmmoAmount);
						AmmoMagCount ++;
						return true;
					}
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (AmmoClass == AuxAmmoName)
			{
				if (AuxAmmoMagCount < MaxClips)
				{
					for (i=0; i<16; i++)
					{
						if (GetClipCount(i,True) <= 0)
						{
							SetClipCount(i,AmmoClass.Default.AmmoAmount,true);
							AuxAmmoMagCount ++;
							return true;
						}
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AAGP_Weapon::ValidAmmo(TSubclassOf<AAmmunition> AmmoClass)
{
	
	if (AmmoClass == NULL)
	{
		return false;
	}
	else
	{
		if (AmmoClass == AmmoName && AmmoMagCount < MaxClips)
		{
			return true;
		}
		else
		{
			if (AmmoClass == AuxAmmoName && AmmoMagCount < MaxClips)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

AAmmunition* AAGP_Weapon::SpawnAmmoFor(AAGP_Weapon* OldW, AAmmunition* oldA)
{
	AAmmunition* newA = nullptr;
	/*
	if (oldA.Class == OldW.AmmoName)
	{
		newA=Spawn(AmmoName,Self);
	}
	else
	{
		if (oldA.Class == OldW.AuxAmmoName && AuxAmmoName != nullptr)
		{
			newA=Spawn(AuxAmmoName,Self);
		}
		else
		{
			DebugLog(DEBUG_Warn,"AGP_Weapon::SpawnWeaponFor()	Unable to spawn for " + this @ OldW @ oldA);
			return nullptr;
		}
	}
	newA.AmmoAmount=Min(oldA.AmmoAmount,newA.MaxAmmo);
	*/
	return newA;
}

bool AAGP_Weapon::IsLegalROF(ERateofFire testROF)
{
	ERateofFire storeROF;
	bool bIsLegal = false;
	bool bKeepChecking;
	if (testROF == AuxROF)
	{
		return true;
	}
	storeROF=eROF;
	bKeepChecking=true;
	if (bKeepChecking)
	{
		DoChangeFireMode();
		if (eROF == storeROF)
		{
			bKeepChecking=false;
		}
		if (eROF == testROF)
		{
			bIsLegal=true;
		}
	}
	eROF=storeROF;
	return bIsLegal;
}

void AAGP_Weapon::CopyROF(AAGP_Weapon* W)
{
	ERateofFire newROF;
	if (W == NULL)
	{
		return;
	}
	newROF=W->eROF;
	if (IsLegalROF(newROF))
	{
		eROF=newROF;
	}
	else
	{
		switch(newROF)
		{
		case ERateofFire::ROF_Burst:
			newROF= ERateofFire::ROF_Auto;
			break;
		case ERateofFire::ROF_Auto:
			newROF= ERateofFire::ROF_Burst;
			break;
		default:
			break;
		}
		if (IsLegalROF(newROF))
		{
			eROF=newROF;
		}
		else
		{
			//eROF=Default->eROF;
			eROF= Cast<AAGP_Weapon>(this)->eROF;   //First try to get a Default Value
		}
	}
}

void AAGP_Weapon::InitFor(AInventory* Inv)
{
	int32 i = 0;
	AAGP_Weapon* W = nullptr;
	bool bDoAux = false;
	W=Cast<AAGP_Weapon>(Inv);
	if (W == nullptr)
	{
		return;
	}
	bGuerrillaWeapon=W->bGuerrillaWeapon;
	/*
	CopyROF(W);
	CopyWeaponMods(W);
	if (AmmoType != nullptr)
	{
		AmmoType.Destroy();
	}
	if (W != nullptr && W.AmmoType != nullptr)
	{
		AmmoType=SpawnAmmoFor(W,W.AmmoType);
	}
	if (AuxAmmoName != nullptr)
	{
		if (AuxAmmoType != nullptr)
		{
			AuxAmmoType.Destroy();
		}
		if (W.AuxAmmoType != nullptr)
		{
			AuxAmmoType=SpawnAmmoFor(W,W.AuxAmmoType);
			bDoAux=true;
		}
	}
	for (i=0; i<16; i++)
	{
		_AmmoClips[i]=GetClipCountAllowed(W._AmmoClips[i],AmmoName);
		if (bDoAux)
		{
			_AuxAmmoClips[i]=GetClipCountAllowed(W._AuxAmmoClips[i],AuxAmmoName);
		}
	}
*/
}

void AAGP_Weapon::CopyWeaponMods(AAGP_Weapon* W)
{
	ABaseWeaponMod* WM = nullptr;
	int32 i = 0;
	bool bEnemyMods = false;
	if (W == nullptr)
	{
		return;
	}
	/*
	bEnemyMods = ((W.EnemyWeaponClass == Default.Class) && (!bGuerrillaWeapon));
	for (i = 0; i < 6; i++)
	{
		WM_Default[i] = "NoMod";
	}
	for (WM = W.WeaponModList; WM != nullptr; WM = WM.NextWeaponMod)
	{
		if (bEnemyMods)
		{
			WM_Default[WM.ModSlot] = FString::FromInt(WM.EnemyModClass);
		}
		else
		{
			WM_Default[WM.ModSlot] = FString::FromInt(WM.Class);
		}
	}
	*/
	bSuppressorOn = W->IsSuppressed();
	if (GetDefault<AAGP_Weapon>()->bSuppressorOn)
	{
		bSuppressorOn = true;
	}
	bLoadModsFromPickup = true;
	LoadWeaponMods();
}

int32 AAGP_Weapon::GetClipCountAllowed(int32 new_clip, AAmmunition* test_ammo)
{
	//return FMath::Min(new_clip,test_ammo->Default->MaxAmmo);
	return 0;   //Fake /ELiZ
}

void AAGP_Weapon::FixRuinedJam()
{
	bIsJammed=false;
	bIsRuined=false;
}

void AAGP_Weapon::NPC_SetEnemy(APawn* Enemy)
{
	dEnemy=Enemy;
}

APawn* AAGP_Weapon::NPC_GetEnemy()
{
	return dEnemy;
}

void AAGP_Weapon::NPC_SetValue(float Value)
{
	dValue=Value;
}

void AAGP_Weapon::MatchEnding()
{
	Destroy();
}
