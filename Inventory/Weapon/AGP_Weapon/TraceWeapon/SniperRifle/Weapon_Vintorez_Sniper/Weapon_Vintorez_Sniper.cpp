// All the original content belonged to the US Army


#include "Weapon_Vintorez_Sniper.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_9x39_10_Mag/Ammo_9x39_10_Mag.h"
#include "AA29/BaseAmmoRound/AmmoRound_9x39_Bullet.h"
#include "AA29/Pickup/AGP_WeaponPickup/PickupW_Vintorez_Sniper/PickupW_Vintorez_Sniper.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_Vintorez_Sniper/AttachW_Vintorez_Sniper.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762mm_Vintorez.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/SuppressorMuzzleFlash_1P/SuppressorMuzzleFlash_1P.h"

AWeapon_Vintorez_Sniper::AWeapon_Vintorez_Sniper()
{
	FireAdjustRapid							= 12;
	_RecoilDirInfo.MeanDirection			= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch					= 1;
	_RecoilDirInfo.PitchMean				= 2;
	_RecoilDirInfo.PitchMaxDeviation		= 0.75;
	_RecoilDirInfo.PitchFalloff				= 1;
	_RecoilDirInfo.bYaw						= 1;
	_RecoilDirInfo.YawMean					= 0.6;
	_RecoilDirInfo.YawMaxDeviation			= 0.7;
	_RecoilDirInfo.YawFalloff				= 1;
	_RecoilDirInfo.bRoll					= 0;
	_RecoilDirInfo.RollMean					= 0;
	_RecoilDirInfo.RollMaxDeviation			= 0;
	_RecoilDirInfo.RollFalloff				= 0;
	_RecoilDirInfo.SpeedMean				= 0;
	_RecoilDirInfo.SpeedMaxDeviation		= 0;
	_RecoilDirInfo.SpeedFalloff				= 0;
	_RecoilDirInfo.Base						= FRotator(0, 0, 0);
	bUseAutoRecoil							= true;
	_AutoRecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AutoRecoilDirInfo.bPitch				= 1;
	_AutoRecoilDirInfo.PitchMean			= 2.2;
	_AutoRecoilDirInfo.PitchMaxDeviation	= 1.4;
	_AutoRecoilDirInfo.PitchFalloff			= 1;
	_AutoRecoilDirInfo.bYaw					= 1;
	_AutoRecoilDirInfo.YawMean				= 0.6;
	_AutoRecoilDirInfo.YawMaxDeviation		= 0.9;
	_AutoRecoilDirInfo.YawFalloff			= 1;
	_AutoRecoilDirInfo.bRoll				= 0;
	_AutoRecoilDirInfo.RollMean				= 0;
	_AutoRecoilDirInfo.RollMaxDeviation		= 0;
	_AutoRecoilDirInfo.RollFalloff			= 0;
	_AutoRecoilDirInfo.SpeedMean			= 0;
	_AutoRecoilDirInfo.SpeedMaxDeviation	= 0;
	_AutoRecoilDirInfo.SpeedFalloff			= 0;
	_AutoRecoilDirInfo.Base					= FRotator(0, 0, 0);
	ShotsToStartRecoilBlend					= 1;
	ShotsForMaxRecoil						= 6;
	SingleFire								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Indoorfire.WeaponsOPFOR_AK47_Indoorfire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Outdoorfire.WeaponsOPFOR_AK47_Outdoorfire"), NULL, LOAD_None, NULL);
	SuppressedSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/VSS/WeaponsOPFOR_VSS_IndoorFire.WeaponsOPFOR_VSS_IndoorFire"), NULL, LOAD_None, NULL);
	SuppressedOutdoorSingleFire				= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/VSS/WeaponsOPFOR_VSS_OutdoorFire.WeaponsOPFOR_VSS_OutdoorFire"), NULL, LOAD_None, NULL);
	ReloadSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_ReloadEmpty.WeaponsOPFOR_AKS74U_ReloadEmpty"), NULL, LOAD_None, NULL);
	ProneReloadSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_ReloadEmpty.WeaponsOPFOR_AKS74U_ReloadEmpty"), NULL, LOAD_None, NULL);
	FixJamSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_FixJam.WeaponsOPFOR_AKS74U_FixJam"), NULL, LOAD_None, NULL);
	ProneFixJamSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_FixJam.WeaponsOPFOR_AKS74U_FixJam"), NULL, LOAD_None, NULL);
	ChangeFireSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_ChangeFireMode.WeaponsOPFOR_AK47_ChangeFireMode"), NULL, LOAD_None, NULL);
	SelectChargeSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/VSS/WeaponsOPFOR_VSS_SelectNew.WeaponsOPFOR_VSS_SelectNew"), NULL, LOAD_None, NULL);
	ReloadFullSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_ReloadFull.WeaponsOPFOR_AKS74U_ReloadFull"), NULL, LOAD_None, NULL);
	ReloadEmptyAnim							= "ReloadEmpty";
	ReloadFullAnim							= "ReloadFull";
	OwnerDamageType							= UProjectileDamage762mm_Vintorez::StaticClass();
	special_tag								= "_new";
	_FPMuzzleFlashClass						= ASuppressorMuzzleFlash_1P::StaticClass();
	_FPMuzzleFlashOffset.VOffset			= FVector(0, 0, 0);
	_FPMuzzleFlashOffset.ROffset			= FRotator(0, 0, 0);
	_FPMuzzleFlashOffset.nBone				= "Muzzle";
	_FPSuppressedMuzzleFlashClass			= ASuppressorMuzzleFlash_1P::StaticClass();
	_FPSuppressedMuzzleFlashOffset.VOffset	= FVector(0, 0, 0);
	_FPSuppressedMuzzleFlashOffset.ROffset	= FRotator(0, 0, 0);
	_FPSuppressedMuzzleFlashOffset.nBone	= "Muzzle";
	AmmoRoundClass							= AAmmoRound_9x39_Bullet::StaticClass();
	NumAmmoRounds							= 3;
	WM_Default								= {
									"WeaponMod_Vintorez_Scope",
									"none",
									"none",
									"none",
									"WeaponMod_Virtual_Harris_Bipod",
									"WeaponMod_Virtual_SPR_Suppressor" 
								};
		//\\LegalModList =
		//StaticMesh = True
	fpWeaponThreatLevel						= 11;
	AmmoName								= AAmmo_9x39_10_Mag::StaticClass();
	PickupAmmoCount							= 10;
	TraceDist								= 21000;
	SelectSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Down.WeaponsOPFOR_AK47_Down"), NULL, LOAD_None, NULL);
	DisplayFOV								= 40;
	MuzzleScale								= 1;
	vZoomAnimOffset							= FVector(-10, -675, 12);
	fZoomAnimFOV							= 25;
	WallTraceDist							= 55;
	weaponType								= EWeaponType::WEAPON_Sniper;
	_AccuracyDirInfo.MeanDirection			= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch					= 1;
	_AccuracyDirInfo.PitchMean				= 0;
	_AccuracyDirInfo.PitchMaxDeviation		= 2.7;
	_AccuracyDirInfo.PitchFalloff			= 1;
	_AccuracyDirInfo.bYaw					= 1;
	_AccuracyDirInfo.YawMean				= 0;
	_AccuracyDirInfo.YawMaxDeviation		= 2.7;
	_AccuracyDirInfo.YawFalloff				= 1;
	_AccuracyDirInfo.bRoll					= 0;
	_AccuracyDirInfo.RollMean				= 0;
	_AccuracyDirInfo.RollMaxDeviation		= 0;
	_AccuracyDirInfo.RollFalloff			= 0;
	_AccuracyDirInfo.SpeedMean				= 0;
	_AccuracyDirInfo.SpeedMaxDeviation		= 0;
	_AccuracyDirInfo.SpeedFalloff			= 0;
	_AccuracyDirInfo.Base					= FRotator(0, 0, 0);
	iMisFire								= 4000;
	PickupClass								= APickupW_Vintorez_Sniper::StaticClass();
	fWeight									= 3.41;
	PlayerViewOffset						= FVector(0, -2, -1);
	AttachmentClass							= { AAttachW_Vintorez_Sniper::StaticClass() };
	IconMaterial							= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_vss.hud_wpn_vss"), NULL, LOAD_None, NULL);
	ItemName								= "Vintorez";
	Mesh									= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsOPFOR/vss_1P.vss_1P"), NULL, LOAD_None, NULL);
	DrawScale								= 1;
}



bool AWeapon_Vintorez_Sniper::IsSuppressed()
{
	return true;
}
void AWeapon_Vintorez_Sniper::DoChangeFireMode()
{
	switch (eROF) 
	{
		case RateofFire::ROF_Single:
			eROF = RateofFire::ROF_Auto;
			break;
		case RateofFire::ROF_Auto:
			eROF = RateofFire::ROF_Single;
			break;
		default:
			// note, if it's not burst or single, here's our chance to catch it!
			eROF = RateofFire::ROF_Single;
			break;
	}
}
void AWeapon_Vintorez_Sniper::ChangeFireMode()
{
	
		if (eROF == AuxROF)
		{
			ChangeAuxMode(ENewAuxMode::NEWMODE_SwitchToNormal);
			return;
		}
		ServerChangeFireMode();
		if (GetNetMode()==ENetMode::NM_Client)
		{
			//GotoState('BusyChangingFireMode');
		}
	
}
void AWeapon_Vintorez_Sniper::AltFire(float Value)
{
	ChangeFireMode();
}
void AWeapon_Vintorez_Sniper::PlayFiring()
{
	/*
		local Object.Rotator Recoil;
		local int Num;
		local float Rate;
		SetupMuzzleFlash();
		if (BaseWeaponAttachment(ThirdPersonActor) != None)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
		}
		PlayWeaponSound(GetFireSound(),GetEnemyFireSound(),0.9,125);
		Rate=0.5 + 0.5 * FireAdjust;
		if (DrawType == 2 && ShouldUse3dSights() && IsZoomed())
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
				if (eROF == 3)
				{
					RunAnimation(ZoomFireAnims[Num],0.5 + 0.5 * FireAdjustRapid,0.05);
				}
				else
				{
					RunAnimation(ZoomFireAnims[Num],0.5 + 0.5 * FireAdjust,0.05);
				}
			}
			else
			{
				if (eROF == 3)
				{
					RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjustRapid,0.05);
				}
				else
				{
					RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjust,0.05);
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
			if (eROF == 3)
			{
				RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjustRapid,0.05);
			}
			else
			{
				RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjust,0.05);
			}
		}
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			if (bWpnRecoil)
			{
				Recoil=CalcRotation(_RecoilDirInfo) * FMax(1 - Instigator.CE_MeterValue,BaseRecoilModifier);
				Instigator.SetViewRotation(Recoil + Instigator.GetViewRotation());
			}
		}
	*/
}

