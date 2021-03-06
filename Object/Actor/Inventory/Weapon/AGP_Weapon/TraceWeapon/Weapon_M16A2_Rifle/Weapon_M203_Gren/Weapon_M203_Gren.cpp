// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M203_Gren/Weapon_M203_Gren.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_40mm_1_Gren/Ammo_40mm_1_Gren.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M203_Gren/PickupW_M203_Gren.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M203_Gren/AttachW_M203_Gren.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_M203_Gren/ScopeW_M203_Gren.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"

AWeapon_M203_Gren::AWeapon_M203_Gren()
{
	MuzzleFlashTextureNormal	= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_flash_m16_a_Mat.fx_flash_m16_a_Mat'"), NULL, LOAD_None, NULL);
	MuzzleFlashTextureGrenade	= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_flash_m249_Mat.fx_flash_m249_Mat'"), NULL, LOAD_None, NULL);
	ProneFireOffset             = FVector(40, 0, 0);
	AuxSingleFire				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire_Cue.WeaponsUS_M203_Fire_Cue'"), NULL, LOAD_None, NULL);
	AuxOutdoorSingleFire		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire_Cue.WeaponsUS_M203_Fire_Cue'"), NULL, LOAD_None, NULL);
	AltReloadSound				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Reload_Cue.WeaponsUS_M203_Reload_Cue'"), NULL, LOAD_None, NULL);
	//_cScopeClass				= AScopeW_M203_Gren::StaticClass()
	AuxFireMesh					= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m203G_1P.m203G_1P'"), NULL, LOAD_None, NULL);
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
	IconMaterial				= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_m16a2_m203_Mat.hud_wpn_m16a2_m203_Mat'"), NULL, LOAD_None, NULL);
	ItemName					= "M203";
	Mesh						= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m203_1P.m203_1P'"), NULL, LOAD_None, NULL);
}

/*
simulated State BusyChangingFireMode
{
	simulated Function EndState()
	{
		Super::EndState();
		bSwitchToGrenade=false;
	}
Begin:
	if (IsZoomed() && (bSwitchToGrenade || (eROF == 4)))
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
simulated State Idle
{
	simulated Function bool CanZoom()
	{
		if (eROF == 4)
		{
			return false;
		}
		return Super::CanZoom();
	}
}
*/

/*
simulated State BusyTempDown
{
	simulated Function bool CanZoom()
	{
		if (eROF == 4)
		{
			return false;
		}
		return Super::CanZoom();
	}
}
*/

/*
simulated State BusyTempLowering
{
	simulated Function bool CanZoom()
	{
		if (eROF == 4)
		{
			return false;
		}
		return Super::CanZoom();
	}
	simulated Function Fire(float Value)
	{
		if (eROF == 4)
		{
			return;
		}
		Global.HitNormal(Value);
	}
}
*/

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
	MuzzleFlashTextureNormal= nullptr;
	MuzzleFlashTextureGrenade= nullptr;
	_SavedMuzzleFlash=nullptr;
}
void AWeapon_M203_Gren::BeginPlay()
{
	Super::BeginPlay();
	//_SavedMuzzleFlash=_FPMuzzleFlashEmitter;
}

bool AWeapon_M203_Gren::IsJammed()
{
	return (bIsJammed && eROF != ERateofFire::ROF_SingleGren);
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
		PlayOwnedSound(ChangeFireSound,1,0.5,false,60,,True,false,EnemyWeaponClass.Default.ChangeFireSound,idTeamOwner);
	*/
}
void AWeapon_M203_Gren::ChangeFireModeToGrenade()
{
	if (eROF == ERateofFire::ROF_SingleGren)
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
			return;
		}
		bSwitchToGrenade=true;
		GotoState('BusyChangingFireMode');
		ClientChangeFireModeToGrenade();
	*/
}
void AWeapon_M203_Gren::FailedSupported()
{
	if (! IsBusy() || IsTempBusy())
	{
		if (eROF == ERateofFire::ROF_SingleGren)
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
		LastROF = eROF;
		eROF = ERateofFire::ROF_SingleGren;
	}
	else
	{
		switch(eROF)
		{
			case ERateofFire::ROF_Single :
				eROF= ERateofFire::ROF_Burst;
				break;
			case ERateofFire::ROF_Burst:
				eROF= ERateofFire::ROF_Single;
				break;
			case ERateofFire::ROF_SingleGren:
				eROF=LastROF;
				break;
			default:
				eROF= ERateofFire::ROF_Single;
				break;
		}
	}
}
void AWeapon_M203_Gren::FixJam()
{
	if (eROF != ERateofFire::ROF_SingleGren)
	{
		FixJam();
	}
}

TSubclassOf<AAmmunition> AWeapon_M203_Gren::GetCurrentAmmoName()
{
	if (eROF == ERateofFire::ROF_SingleGren)
	{
		return AuxAmmoName;
	}
	return Super::GetCurrentAmmoName();
}

TSubclassOf<AAmmunition> AWeapon_M203_Gren::GetAuxAmmoName()
{
	if (eROF == ERateofFire::ROF_SingleGren)
	{
		return AmmoName;
	}
	return Super::GetAuxAmmoName();
}

AAmmunition* AWeapon_M203_Gren::GetCurrentAmmoType()
{
	if (eROF == ERateofFire::ROF_SingleGren)
	{
		return AuxAmmoType;
	}
	return Super::GetCurrentAmmoType();
}
AAmmunition* AWeapon_M203_Gren::GetAuxAmmoType()
{
	if (eROF == ERateofFire::ROF_SingleGren)
	{
		return AmmoType;
	}
	return Super::GetAuxAmmoType();
}
void AWeapon_M203_Gren::SetCurrentAmmoType(AAmmunition* newAmmoType)
{
	if (eROF == ERateofFire::ROF_SingleGren)
	{
		AuxAmmoType=newAmmoType;
	}
	else
	{
		SetCurrentAmmoType(newAmmoType);
	}
}
void AWeapon_M203_Gren::SetCurrentAmmoName(AAmmunition* newAmmoName)
{
	if (eROF == ERateofFire::ROF_SingleGren)
	{
		//AuxAmmoName=newAmmoName;
	}
	else
	{
		SetCurrentAmmoName(newAmmoName);
	}
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
	return (eROF == ERateofFire::ROF_SingleGren);
}
void AWeapon_M203_Gren::DiscardShell()
{
	/*
		FlashCount=255;
		if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
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
		if (eROF == ERateofFire::ROF_SingleGren)
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
	if (eROF == ERateofFire::ROF_Burst || eROF == ERateofFire::ROF_Auto)
	{
		//RunAnimation('Still2FM',1,0.05,true);
	}
	else
	{
		//RunAnimation('Still',1,0.05,true);
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
		case ERateofFire::ROF_SingleGren:
			//RunAnimation('Reload',1,0.05);
			//PlayOwnedSound(AltReloadSound,0,0.5,false,60,,True,false,EnemyWeaponClass.Default.AltReloadSound,idTeamOwner);
			break;
		default:
			//RunAnimation('Reload',1.4,0.05);
			//PlayOwnedSound(ReloadSound,1,0.5,false,60,,True,false,EnemyWeaponClass.Default.ReloadSound,idTeamOwner);
			break;
	}
	if (ShouldDoDelayedEject())
	{
		DiscardShell();
	}
}
