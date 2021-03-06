// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M24_Sniper/Weapon_M24_Sniper.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_M24_Sniper/ScopeW_M24_Sniper.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_5_Rounds/Ammo_762mm_5_Rounds.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M24_Sniper/PickupW_M24_Sniper.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M24_Sniper/AttachW_M24_Sniper.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash_1P/AK47MuzzleFlash_1P.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762Sniper.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
AWeapon_M24_Sniper::AWeapon_M24_Sniper()
{
	_RecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch				= 1;
	_RecoilDirInfo.PitchMean			= 8;
	_RecoilDirInfo.PitchMaxDeviation	= 8;
	_RecoilDirInfo.PitchFalloff			= 1;
	_RecoilDirInfo.bYaw					= 1;
	_RecoilDirInfo.YawMean				= 5;
	_RecoilDirInfo.YawMaxDeviation		= 5;
	_RecoilDirInfo.YawFalloff			= 0.75;
	_RecoilDirInfo.bRoll				= 0;
	_RecoilDirInfo.RollMean				= 0;
	_RecoilDirInfo.RollMaxDeviation		= 0;
	_RecoilDirInfo.RollFalloff			= 0;
	_RecoilDirInfo.SpeedMean			= 0;
	_RecoilDirInfo.SpeedMaxDeviation	= 0;
	_RecoilDirInfo.SpeedFalloff			= 0;
	_RecoilDirInfo.Base					= FRotator(0, 0, 0);
	SingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Indoorfire_Cue.WeaponsUS_M24_Indoorfire_Cue'"), NULL, LOAD_None, NULL);
	OutdoorSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Outdoorfire_Cue.WeaponsUS_M24_Outdoorfire_Cue'"), NULL, LOAD_None, NULL);
	ReloadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Reload_Cue.WeaponsUS_M24_Reload_Cue'"), NULL, LOAD_None, NULL);
	ProneReloadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Reload_Cue.WeaponsUS_M24_Reload_Cue'"), NULL, LOAD_None, NULL);
	FixJamSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_FixJam_Cue.WeaponsUS_M24_FixJam_Cue'"), NULL, LOAD_None, NULL);
	ProneFixJamSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_FixJam_Cue.WeaponsUS_M24_FixJam_Cue'"), NULL, LOAD_None, NULL);
	SelectChargeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_SelectNew_Cue.WeaponsUS_M24_SelectNew_Cue'"), NULL, LOAD_None, NULL);
	SupportingSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Supported_Cue.WeaponsUS_M24_Supported_Cue'"), NULL, LOAD_None, NULL);
	UnSupportingSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Unsupported_Cue.WeaponsUS_M24_Unsupported_Cue'"), NULL, LOAD_None, NULL);
	ReloadStartSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_ReloadStart_Cue.WeaponsUS_M24_ReloadStart_Cue'"), NULL, LOAD_None, NULL);
	ReloadEndSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_ReloadEnd_Cue.WeaponsUS_M24_ReloadEnd_Cue'"), NULL, LOAD_None, NULL);
	_cScopeClass						= AScopeW_M24_Sniper::StaticClass();
	OwnerDamageType						= UProjectileDamage762Sniper::StaticClass();
	_FPMuzzleFlashClass					= AAK47MuzzleFlash_1P::StaticClass();
	bAllowsPlusOneLoading				= false;
	fpWeaponThreatLevel					= 11;
	AmmoName							= AAmmo_762mm_5_Rounds::StaticClass();
	PickupAmmoCount						= 5;
	TraceDist							= 40000;
	SelectSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/General/WeaponsUS_General_Select_Cue.WeaponsUS_General_Select_Cue'"), NULL, LOAD_None, NULL);
	DisplayFOV							= 50;
	bCanSupport							= true;
	_ZoomDirInfo.MeanDirection			= FVector(0, 0, 0);
	_ZoomDirInfo.bPitch					= 1;
	_ZoomDirInfo.PitchMean				= 0;
	_ZoomDirInfo.PitchMaxDeviation		= 2;
	_ZoomDirInfo.PitchFalloff			= 1;
	_ZoomDirInfo.bYaw					= 1;
	_ZoomDirInfo.YawMean				= 0;
	_ZoomDirInfo.YawMaxDeviation		= 5;
	_ZoomDirInfo.YawFalloff				= 1;
	_ZoomDirInfo.bRoll					= 0;
	_ZoomDirInfo.RollMean				= 0;
	_ZoomDirInfo.RollMaxDeviation		= 0;
	_ZoomDirInfo.RollFalloff			= 0;
	_ZoomDirInfo.SpeedMean				= 0;
	_ZoomDirInfo.SpeedMaxDeviation		= 0;
	_ZoomDirInfo.SpeedFalloff			= 0;
	_ZoomDirInfo.Base					= FRotator(0, 0, 0);
	vZoomAnimOffset						= FVector(-6, -3, -3);
	fZoomAnimFOV						= 30;
	WallTraceDist						= 77;
	weaponType							= EWeaponType::WEAPON_Sniper;
	_AccuracyDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch				= 1;
	_AccuracyDirInfo.PitchMean			= 0;
	_AccuracyDirInfo.PitchMaxDeviation	= 3.25;
	_AccuracyDirInfo.PitchFalloff		= 1;
	_AccuracyDirInfo.bYaw				= 1;
	_AccuracyDirInfo.YawMean			= 0;
	_AccuracyDirInfo.YawMaxDeviation	= 3.25;
	_AccuracyDirInfo.YawFalloff			= 1;
	_AccuracyDirInfo.bRoll				= 0;
	_AccuracyDirInfo.RollMean			= 0;
	_AccuracyDirInfo.RollMaxDeviation	= 0;
	_AccuracyDirInfo.RollFalloff		= 0;
	_AccuracyDirInfo.SpeedMean			= 0;
	_AccuracyDirInfo.SpeedMaxDeviation	= 0;
	_AccuracyDirInfo.SpeedFalloff		= 0;
	_AccuracyDirInfo.Base				= FRotator(0, 0, 0);
	bMisFire							= false;
	PickupClass							= APickupW_M24_Sniper::StaticClass();
	fWeight								= 5.4;
	PlayerViewOffset					= FVector(6, 15, -61);
	AttachmentClass						= { AAttachW_M24_Sniper::StaticClass() };
	IconMaterial = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_m24_Mat.hud_wpn_m24_Mat'"), NULL, LOAD_None, NULL);
	ItemName = "M24";
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M24_1P.M24_1P'"), NULL, LOAD_None, NULL);
	DrawScale							= 1;
}

/*
simulated State BusyFiring
{
	simulated Function AnimEnd(int32 Channel)
	{
	}
	simulated Function StartCrawling()
	{
	}
	simulated Function ToggleZoom()
	{
		if (bRequireRecharge)
		{
			ServerZoom((! IsZoomed()));
			if (GetWorld()->GetNetMode() == NM_Client)
			{
				DoZoom((! IsZoomed()));
			}
		}
	}
	Function ServerZoom(bool bNewZoomDir)
	{
		DoZoom(bNewZoomDir);
	}
	simulated Function DoZoom(bool DoZoomDir)
	{
		bZoomDir=DoZoomDir;
		if (GetNetMode() != ENetMode::NM_Client)
		{
			Instigator.SetZoomed(DoZoomDir);
		}
		GotoState("BusyZoomingAndRecharging");
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		if ((DesiredAction == 6) && bRequireRecharge)
		{
			return true;
		}
		return Super::CanUseWeapon(DesiredAction);
	}
Begin:
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
	}
	else
	{
		FinishAnim();
	}
	bRequireRecharge=true;
	if (MustWorkBolt())
	{
		LocalFire();
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			Sleep(AnimTimerDuration);
			DiscardShell();
		}
		else
		{
			FinishAnim();
		}
	}
	bRequireRecharge=false;
	AnimEnd(0);
}
*/

/*
simulated State BusyZoomingAndRecharging extends busy
{
	simulated Function AnimEnd(int32 Channel)
	{
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		if (DesiredAction == 6)
		{
			return true;
		}
		return Super::CanUseWeapon(DesiredAction);
	}
Begin:
	if (bZoomDir)
	{
		bInZoom=true;
		InterpolateZoomView(true);
		Zoom();
	}
	else
	{
		UnZoom();
		InterpolateZoomView(false);
		bInZoom=false;
	}
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		DiscardShell();
	}
	else
	{
		FinishAnim();
	}
	bRequireRecharge=false;
	if (((! IsZoomed()) && (AmmoType.AmmoAmount > 0)) && Instigator.CanUseWeapon(6))
	{
		Instigator.SetWalking(true);
		DoZoom(true);
	}
	else
	{
		AnimEnd(0);
	}
	GotoState("Idle");
}
*/

/*
simulated State BusyReloading
{
	simulated Function AnimEnd(int32 Channel)
	{
	}
	simulated Function BeginState()
	{
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		if (DesiredAction == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	simulated Function Fire(float Value)
	{
		ServerStopReload();
		if (Role < 4)
		{
			StopReload();
		}
	}
	simulated Function SetReloadAnimations()
	{
		if (IsSupported())
		{
			ReloadStartAnim="SupportedReloadStart";
			ReloadAnim="SupportedReload";
			ReloadEndAnim="SupportedReloadEnd";
		}
		else
		{
			ReloadStartAnim="ReloadStart";
			ReloadAnim="Reload";
			ReloadEndAnim="ReloadEnd";
		}
	}
Begin:
	clientAmmo=GetCurrentAmmoType().AmmoAmount;
	clientClip=GetClipCount(0);
	bStopReload=false;
	if (IsZoomed())
	{
		UnZoom();
		InterpolateZoomView(false);
		bInZoom=false;
	}
	SetReloadAnimations();
	RunAnimation(ReloadStartAnim,1,0.05);
	PlayOwnedSound(ReloadStartSound,0,0.5,false,60,,true,false,EnemyWeaponClass.Default.ReloadStartSound,idTeamOwner);
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
		DiscardShell();
	}
	else
	{
		FinishAnim();
	}
	if (ReloadBullet())
	{
		RunAnimation(ReloadAnim,1,0.05);
		PlayOwnedSound(ReloadSound,0,0.5,false,60,,true,false,EnemyWeaponClass.Default.ReloadSound,idTeamOwner);
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			Sleep(AnimTimerDuration);
		}
		else
		{
			FinishAnim();
		}
	}
	RunAnimation(ReloadEndAnim,1,0.05);
	PlayOwnedSound(ReloadEndSound,0,0.5,false,60,,true,false,EnemyWeaponClass.Default.ReloadEndSound,idTeamOwner);
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
	}
	else
	{
		FinishAnim();
	}
	bWorkBolt=false;
	AnimEnd(0);
}
*/

void AWeapon_M24_Sniper::PlayReloading()
{
}
bool AWeapon_M24_Sniper::IsCharged()
{
	return ! bRequireRecharge;
}
bool AWeapon_M24_Sniper::MustWorkBolt()
{
	return bWorkBolt && AmmoType->AmmoAmount > 0;
}
void AWeapon_M24_Sniper::Fire(float Value)
{
	/*
		if (MustWorkBolt())
		{
			ServerFire();
			if (GetNetMode() == ENetMode::NM_Client)
			{
				GotoState('BusyFiring');
			}
		}
		else
		{
			Fire(Value);
		}
	*/
}
void AWeapon_M24_Sniper::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
	/*
		if (MustWorkBolt())
		{
			GotoState('BusyFiring');
		}
		else
		{
			ServerFire(bNoAdjustAim,bRapid,bBreatheBonus);
		}
	*/
}
void AWeapon_M24_Sniper::PlayFiring()
{
	/*
		if (bWorkBolt)
		{
			if (IsZoomed())
			{
				DoZoom(false);
			}
			if (IsSupported())
			{
				RunAnimation('SupportedFixJam',1,0.05);
			}
			else
			{
				RunAnimation('FixJam',1,0.05);
			}
			PlayOwnedSound(FixJamSound,1,0.5,false,60,,True,false,EnemyWeaponClass.Default.FixJamSound,idTeamOwner);
		}
		else
		{
			PlayFiring();
		}
		bWorkBolt=! bWorkBolt;
	*/
}
void AWeapon_M24_Sniper::DiscardShell()
{
	/*
		if (bRequireRecharge || AmmoType.AmmoAmount == 0)
		{
			FlashCount=255;
			if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
			{
				BaseWeaponAttachment(ThirdPersonActor).FiringMode='ROF_Single';
				BaseWeaponAttachment(ThirdPersonActor).FlashCount=FlashCount;
				BaseWeaponAttachment(ThirdPersonActor).ThirdPersonEffects();
			}
		}
	*/
}
void AWeapon_M24_Sniper::ServerStopReload()
{
	//StopReload();
}

void AWeapon_M24_Sniper::StopReload()
{
	//bStopReload=true;
}

int32 AWeapon_M24_Sniper::GetClipCountAllowed(int32 new_clip, AAmmunition* test_ammo)
{
	return new_clip;
}

bool AWeapon_M24_Sniper::ReloadBullet()
{
	/*
	if (clientClip < 1 || clientAmmo == AmmoType.Default.AmmoAmount || bStopReload)
	{
		return false;
	}
	clientAmmo ++;
	clientClip --;
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		AmmoType.AmmoAmount=clientAmmo;
		_AmmoClips[0]=clientClip;
		RecountAmmo();
	}
	else
	{
		AmmoMagCount=clientClip;
	}
	*/
	return true;
}

bool AWeapon_M24_Sniper::CheckForNoReload()
{
	/*
		if (AmmoType.AmmoAmount == AmmoType.Default.AmmoAmount)
		{
			return true;
		}
		else
		{
			return CheckForNoReload();
		}
	*/
	return false;    //FAKE /ELiZ
}
void AWeapon_M24_Sniper::ReloadClip(uint8 newclip)
{
}

int32 AWeapon_M24_Sniper::GetClipCount(uint8 clip, bool bAuxAmmo)
{
	if (clip == 0)
	{
		return _AmmoClips[0];
	}
	else
	{
		//DebugLog(DEBUG_Warn,"M24::GetClipCount()	Weapon has no clips");
		return 0;
	}
}

uint8 AWeapon_M24_Sniper::GetBestClip()
{
	return 0;
}

bool AWeapon_M24_Sniper::AddClip(AAmmunition* AmmoClass)
{
	/*
	DebugLog(DEBUG_Inv,"AGP_Weapon::AddClip()	" + AmmoClass @ AmmoName @ AuxAmmoName);
	if (AmmoClass == AmmoName)
	{
		_AmmoClips[0] += AmmoClass.Default.AmmoAmount;
		RecountAmmo();
		return true;
	}
	*/
	return false;
}
void AWeapon_M24_Sniper::RecountAmmo()
{
	AmmoMagCount=_AmmoClips[0];
}

