// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_M9_Pistol.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/PistolWeaponAttachment/AttachW_M9_Pistol/AttachW_M9_Pistol.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_9x19mm_15_Mag/Ammo_9x19mm_15_Mag.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M9MuzzleFlash_1P/M9MuzzleFlash_1P.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_M9_Pistol/ScopeW_M9_Pistol.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_9mm_Bullet.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage9x19mm.h"

AWeapon_M9_Pistol::AWeapon_M9_Pistol()
{
	IdleAnim							= "Still2Frame";
	IdleEmptyAnim						= "IdleEmpty";
	IdleEmptyRandomAnim					= "IdleEmptyRandomA";
	IdleHammerFWAnim					= "idlehmrfw";
	ReloadAnim							= "ReloadEmpty";
	FullReloadAnim						= "ReloadFull";
	ReloadEmptyHFAnim					= "ReloadEmptyHmrFw";
	ReloadEmptyHBAnim					= "ReloadEmptyHmrBk";
	FixJamAnim							= "FixJam";
	SelectAnim							= "Select";
	SelectNewAnim						= "SelectNew";
	FireLastShotAnim					= "FireLast";
	FireEmptyFirstAnim					= "FireEmptyA";
	FireEmptyAnim						= "FireEmptyB";
	CrawlInAnim							= "HighCrawlIn";
	CrawlOutAnim						= "HighCrawlOut";
	CrawlAnim							= "HighCrawl";
	CrawlBackAnim						= "HighCrawlBack";
	CrawlInEmptyAnim					= "HighCrawlInEmpty";
	CrawlOutEmptyAnim					= "HighCrawlOutEmpty";
	CrawlEmptyAnim						= "HighCrawlEmpty";
	CrawlBackEmptyAnim					= "HighCrawlBackEmpty";
	CrawlInEmptyHFAnim					= "HighCrawlInHmrFw";
	CrawlOutEmptyHFAnim					= "HighCrawlOutHmrFw";
	CrawlEmptyHFAnim					= "HighCrawlHmrFw";
	CrawlBackEmptyHFAnim				= "HighCrawlBackHmrFw";
	GuardDown							= "Drop";
	GuardUp								= "Raise";
	GuardIdle							= "DropStill";
	GuardDownEmpty						= "DropEmpty";
	GuardUpEmpty						= "RaiseEmpty";
	GuardIdleEmpty						= "DropStillEmpty";
	GuardDownHammerFW					= "DropHmrFw";
	GuardUpHammerFW						= "RaiseHmrFw";
	GuardIdleHammerFW					= "DropStillHmrFw";
	PutAwayAnim							= "Down";
	PutAwayEmptyAnim					= "DownEmpty";
	PutAwayEmptyHFAnim					= "DownEmptyHmrFw";
	PutAwayLowAnim						= "LowDown";
	PutAwayLowEmptyAnim					= "LowDownEmpty";
	PutAwayLowHFAnim					= "LowDownHmrFw";
	ReloadEmptyHmrBkSound				= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_ReloadEmptyHmrBk.WeaponsUS_M9_ReloadEmptyHmrBk"), NULL, LOAD_None, NULL);
	_RecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch				= 1;
	_RecoilDirInfo.PitchMean			= 2;
	_RecoilDirInfo.PitchMaxDeviation	= 1.5;
	_RecoilDirInfo.PitchFalloff			= 1;
	_RecoilDirInfo.bYaw					= 1;
	_RecoilDirInfo.YawMean				= 1.8;
	_RecoilDirInfo.YawMaxDeviation		= 1.5;
	_RecoilDirInfo.YawFalloff			= 1;
	_RecoilDirInfo.bRoll				= 0;
	_RecoilDirInfo.RollMean				= 0;
	_RecoilDirInfo.RollMaxDeviation		= 0;
	_RecoilDirInfo.RollFalloff			= 0;
	_RecoilDirInfo.SpeedMean			= 0;
	_RecoilDirInfo.SpeedMaxDeviation	= 0;
	_RecoilDirInfo.SpeedFalloff			= 0;
	_RecoilDirInfo.Base					= FRotator(0, 0, 0);
	SingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_Fire_Inside_Cue.WeaponsUS_M9_Fire_Inside_Cue'"), NULL, LOAD_None, NULL);
	OutdoorSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_Fire_Outside_Cue.WeaponsUS_M9_Fire_Outside_Cue'"), NULL, LOAD_None, NULL);
	ReloadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_Reload_Cue.WeaponsUS_M9_Reload_Cue'"), NULL, LOAD_None, NULL);
	ProneReloadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_Reload_Cue.WeaponsUS_M9_Reload_Cue'"), NULL, LOAD_None, NULL);
	FixJamSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_FixJam_Cue.WeaponsUS_M9_FixJam_Cue'"), NULL, LOAD_None, NULL);
	ProneFixJamSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_FixJam_Cue.WeaponsUS_M9_FixJam_Cue'"), NULL, LOAD_None, NULL);
	ChangeFireSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_Reload_Cue.WeaponsUS_M9_Reload_Cue'"), NULL, LOAD_None, NULL);
	SelectChargeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_SelectNew_Cue.WeaponsUS_M9_SelectNew_Cue'"), NULL, LOAD_None, NULL);
	DryFireSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_FireEmptyA_Cue.WeaponsUS_M9_FireEmptyA_Cue'"), NULL, LOAD_None, NULL);
	ReloadFullSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_ReloadFull_Cue.WeaponsUS_M9_ReloadFull_Cue'"), NULL, LOAD_None, NULL);
	bCanUse3dSights						= true;
	_cScopeClass						= AScopeW_M9_Pistol::StaticClass();
	OwnerDamageType						= UProjectileDamage9x19mm::StaticClass();
	special_tag							= "_new";
	_FPMuzzleFlashClass					= AM9MuzzleFlash_1P::StaticClass();
	AmmoRoundClass						= AAmmoRound_9mm_Bullet::StaticClass();
	NumAmmoRounds						= 3;
	AmmoName							= AAmmo_9x19mm_15_Mag::StaticClass();
	PickupAmmoCount						= 15;
	SelectSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m9/WeaponsUS_M9_Select_Cue.WeaponsUS_M9_Select_Cue'"), NULL, LOAD_None, NULL);
	DisplayFOV							= 65;
	vZoomAnimOffset						= FVector(0, -9, 11);
	fZoomAnimFOV						= 45;
	fZoomAnimTime						= 0.25;
	WallTraceDist						= 65;
	_AccuracyDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch				= 1;
	_AccuracyDirInfo.PitchMean			= 0;
	_AccuracyDirInfo.PitchMaxDeviation	= 2.55;
	_AccuracyDirInfo.PitchFalloff		= 1;
	_AccuracyDirInfo.bYaw				= 1;
	_AccuracyDirInfo.YawMean			= 0;
	_AccuracyDirInfo.YawMaxDeviation	= 2.55;
	_AccuracyDirInfo.YawFalloff			= 1;
	_AccuracyDirInfo.bRoll				= 0;
	_AccuracyDirInfo.RollMean			= 0;
	_AccuracyDirInfo.RollMaxDeviation	= 0;
	_AccuracyDirInfo.RollFalloff		= 0;
	_AccuracyDirInfo.SpeedMean			= 0;
	_AccuracyDirInfo.SpeedMaxDeviation	= 0;
	_AccuracyDirInfo.SpeedFalloff		= 0;
	_AccuracyDirInfo.Base				= FRotator(0, 0, 0);
	fWeight								= 0.95;
	PlayerViewOffset					= FVector(0, 0, 0);
	AttachmentClass						= { AAttachW_M9_Pistol::StaticClass() };
	IconMaterial = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_m9_Mat.hud_wpn_m9_Mat'"), NULL, LOAD_None, NULL);
	ItemName = "M9";
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m9_1P.m9_1P'"), NULL, LOAD_None, NULL);
}
