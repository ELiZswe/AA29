// All the original content belonged to the US Army


#include "Weapon_M203_Gren.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_40mm_1_Gren/Ammo_40mm_1_Gren.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M203_Gren/PickupW_M203_Gren.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M203_Gren/AttachW_M203_Gren.h"

AWeapon_M203_Gren::AWeapon_M203_Gren()
{
	MuzzleFlashTextureNormal    = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_flash_m16_a.fx_flash_m16_a"), NULL, LOAD_None, NULL);
	MuzzleFlashTextureGrenade   = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_flash_m249.fx_flash_m249"), NULL, LOAD_None, NULL);
	ProneFireOffset             = FVector(40, 0, 0);
	AuxSingleFire               = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire.WeaponsUS_M203_Fire"), NULL, LOAD_None, NULL);
	AuxOutdoorSingleFire        = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire.WeaponsUS_M203_Fire"), NULL, LOAD_None, NULL);
	AltReloadSound              = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Reload.WeaponsUS_M203_Reload"), NULL, LOAD_None, NULL);
		//_cScopeClass = class'AGP_Inventory.ScopeW_M203_Gren'
	AuxFireMesh                 = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m203G_1P.m203G_1P"), NULL, LOAD_None, NULL);
	fpWeaponThreatLevel         = 15;
	DisplayFOV                  = 50;
	vZoomAnimOffset             = FVector(0, -35, -28);
	fZoomAnimFOV                = 15;
	weaponType                  = EWeaponType::WEAPON_Gren;
	AuxAmmoName                 = AAmmo_40mm_1_Gren::StaticClass();
	AuxPickupAmmoCount          = 1;
	PickupClass                 = APickupW_M203_Gren::StaticClass();
	fWeight                     = 4.76;
	AttachmentClass             = { AAttachW_M203_Gren::StaticClass() };
	IconMaterial                = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_m16a2_m203.hud_wpn_m16a2_m203"), NULL, LOAD_None, NULL);
	ItemName                    = "M203";
	Mesh                        = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m203_1P.m203_1P"), NULL, LOAD_None, NULL);
}


void AWeapon_M203_Gren::SetClipCount(uint8 clip, int32 Count, bool bAuxAmmo)
{
	/*
		if (bAuxAmmo || GetCurrentAmmoType() == AuxAmmoType && Count == 0)
		{
			_AuxAmmoClips[clip]=Count;
		}
		else
		{
			_AmmoClips[clip]=Count;
		}
	*/
}
void AWeapon_M203_Gren::Destroyed()
{
	Super::Destroyed();
	MuzzleFlashTextureNormal=NULL;
	MuzzleFlashTextureGrenade=NULL;
	//_SavedMuzzleFlash=NULL;
}
void AWeapon_M203_Gren::BeginPlay()
{
	/*
		BeginPlay();
		_SavedMuzzleFlash=_FPMuzzleFlashEmitter;
	*/
}
bool AWeapon_M203_Gren::IsJammed()
{
	return (bIsJammed && eROF != RateofFire::ROF_SingleGren);
}
void AWeapon_M203_Gren::PlayChangeFireMode()
{
	/*
		if (bSwitchToGrenade)
		{
			SelectGrenadeMode();
			RunAnimation('Swap',1);
		}
		else
		{
			if (eROF == 1)
			{
				RunAnimation('ChangeFireMode',1);
			}
			else
			{
				if (eROF == 2 || eROF == 3)
				{
					RunAnimation('ChangeFireModeBack',1);
				}
				else
				{
					if (eROF == 4)
					{
						SelectNormalMode();
						RunAnimation('Swapback',1);
					}
				}
			}
		}
		PlayOwnedSound(ChangeFireSound,1,0.5,False,60,,True,False,EnemyWeaponClass.Default.ChangeFireSound,idTeamOwner);
	*/
}
void AWeapon_M203_Gren::ChangeFireModeToGrenade()
{
	if (eROF == RateofFire::ROF_SingleGren)
	{
		return;
	}
	ServerChangeFireModeToGrenade();
}
void AWeapon_M203_Gren::ClientChangeFireModeToGrenade()
{
	if(GetNetMode()==ENetMode::NM_Client)
	{
		bSwitchToGrenade=true;
		//GotoState('BusyChangingFireMode');
	}
}
void AWeapon_M203_Gren::ServerChangeFireModeToGrenade()
{
	/*
		if (IsInState('BusyChangingFireMode'))
		{
			Return;
		}
		bSwitchToGrenade=True;
		GotoState('BusyChangingFireMode');
		ClientChangeFireModeToGrenade();
	*/
}
void AWeapon_M203_Gren::FailedSupported()
{
	if (! IsBusy() || IsTempBusy())
	{
		if (eROF == RateofFire::ROF_SingleGren)
		{
			ChangeFireMode();
		}
		else
		{
			ChangeFireModeToGrenade();
		}
	}
}
void AWeapon_M203_Gren::DoChangeFireMode()
{
	if (bSwitchToGrenade)
	{
		LastROF=eROF;
		eROF=RateofFire::ROF_SingleGren;
	}
	else
	{
		switch(eROF)
		{
			case RateofFire::ROF_Single :
				eROF= RateofFire::ROF_Burst;
				break;
			case RateofFire::ROF_Burst:
				eROF= RateofFire::ROF_Single;
				break;
			case RateofFire::ROF_SingleGren:
				eROF=LastROF;
				break;
			default:
				eROF= RateofFire::ROF_Single;
				break;
		}
	}
}
void AWeapon_M203_Gren::FixJam()
{
	if (eROF != RateofFire::ROF_SingleGren)
	{
		FixJam();
	}
}
TSubclassOf<AAmmunition> AWeapon_M203_Gren::GetCurrentAmmoName()
{
	if (eROF == RateofFire::ROF_SingleGren)
	{
		return AuxAmmoName;
	}
	return Super::GetCurrentAmmoName();
}
TSubclassOf<AAmmunition> AWeapon_M203_Gren::GetAuxAmmoName()
{
	if (eROF == RateofFire::ROF_SingleGren)
	{
		return AmmoName;
	}
	return Super::GetAuxAmmoName();
}
AAmmunition* AWeapon_M203_Gren::GetCurrentAmmoType()
{
	if (eROF == RateofFire::ROF_SingleGren)
	{
		return AuxAmmoType;
	}
	return Super::GetCurrentAmmoType();
}
AAmmunition* AWeapon_M203_Gren::GetAuxAmmoType()
{
	if (eROF == RateofFire::ROF_SingleGren)
	{
		return AmmoType;
	}
	return Super::GetAuxAmmoType();
}
void AWeapon_M203_Gren::SetCurrentAmmoType(AAmmunition* newAmmoType)
{
	/*
		if (eROF == RateofFire::ROF_SingleGren)
		{
			AuxAmmoType=newAmmoType;
		}
		else
		{
			SetCurrentAmmoType(newAmmoType);
		}
	*/
}
void AWeapon_M203_Gren::SetCurrentAmmoName(AAmmunition* newAmmoName)
{
	/*
		if (eROF == RateofFire::ROF_SingleGren)
		{
			AuxAmmoName=newAmmoName;
		}
		else
		{
			SetCurrentAmmoName(newAmmoName);
		}
	*/
}
bool AWeapon_M203_Gren::CheckForNoReload()
{
	if (GetCurrentAmmoType() == AuxAmmoType && AuxAmmoType->AmmoAmount > 0)
	{
		return true;
	}
	else
	{
		return Super::CheckForNoReload();
	}
}
bool AWeapon_M203_Gren::ShouldDoDelayedEject()
{
	return (eROF == RateofFire::ROF_SingleGren);
}
void AWeapon_M203_Gren::DiscardShell()
{
	/*
		FlashCount=255;
		if (BaseWeaponAttachment(ThirdPersonActor) != None)
		{
			BaseWeaponAttachment(ThirdPersonActor).FiringMode='ROF_SingleGren';
			BaseWeaponAttachment(ThirdPersonActor).FlashCount=FlashCount;
			BaseWeaponAttachment(ThirdPersonActor).ThirdPersonEffects();
		}
	*/
}
void AWeapon_M203_Gren::PlaySelect()
{
	/*
		if (eROF == RateofFire::ROF_SingleGren)
		{
			if (! IsAnimating() || ! AnimIsInGroup(0,'Select') || ! AnimIsInGroup(0,'SelectNew'))
			{
				SelectGrenadeMode();
			}
		}
		PlaySelect();
	*/
}
void AWeapon_M203_Gren::PlayIdleAnim()
{
	if (eROF == RateofFire::ROF_Burst || eROF == RateofFire::ROF_Auto)
	{
		//RunAnimation('Still2FM',1,0.05,True);
	}
	else
	{
		//RunAnimation('Still',1,0.05,True);
	}
}
void AWeapon_M203_Gren::SelectGrenadeMode()
{
	//LinkMesh(AuxFireMesh);
	MFTexture=MuzzleFlashTextureGrenade;
	FireAdjust=2;
	bMisFire=false;
	_FPMuzzleFlashEmitter=NULL;
}
void AWeapon_M203_Gren::SelectNormalMode()
{
	//LinkMesh(Default.Mesh);
	MFTexture=MuzzleFlashTextureNormal;
	//FireAdjust=Default.FireAdjust;
	//FireOffset=Default.FireOffset;
	bMisFire=true;
	//_FPMuzzleFlashEmitter=_SavedMuzzleFlash;
}
void AWeapon_M203_Gren::PlayReloading()
{
	switch(eROF)
	{
		case RateofFire::ROF_SingleGren:
			//RunAnimation('Reload',1,0.05);
			//PlayOwnedSound(AltReloadSound,0,0.5,False,60,,True,False,EnemyWeaponClass.Default.AltReloadSound,idTeamOwner);
			break;
		default:
			//RunAnimation('Reload',1.4,0.05);
			//PlayOwnedSound(ReloadSound,1,0.5,False,60,,True,False,EnemyWeaponClass.Default.ReloadSound,idTeamOwner);
			break;
	}
	if (ShouldDoDelayedEject())
	{
		DiscardShell();
	}
}
