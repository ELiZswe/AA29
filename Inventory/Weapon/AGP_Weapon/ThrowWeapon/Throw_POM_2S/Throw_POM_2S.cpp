// All the original content belonged to the US Army


#include "Throw_POM_2S.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_POM_2S/AttachT_POM_2S.h"
#include "AA29/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_POM_2S/PickupT_POM_2S.h"
#include "AA29/Inventory/Weapon\AGP_Weapon\ThrowWeapon\Throw_M67_Frag\Throw_MILES_Grenade\Throw_MILES_Grenade.h"
#include "AA29/DamageType/AGP_DamageType/ExplosionDamage/GrenadeExplosionDamage/GrenadeExplosionDamage.h"
#include "AA29/DamageType/AGP_DamageType/FragDamage/FragDamage.h"

AThrow_POM_2S::AThrow_POM_2S()
{
	_fMinFuseTime           = 6;
	_fAddFuseTime           = 2;
	_fDamage                = 100;
	_fDamageRadius          = 787.200012;
	_fKillRadius            = 262.467194;
	_fMomentum              = 20000;
	FragDamageType          = UFragDamage::StaticClass();
	MyDamageType            = UGrenadeExplosionDamage::StaticClass();
//		\\DamageClasses =
//		System = 1
	_fEffectDuration        = 10;
	_bUseAnimNotifyAltFire  = true;
	BoomSound               = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M67explosion1.WeaponsUS_Grenades_M67explosion1"), NULL, LOAD_None, NULL);
	//cExplosionEmitter = Aem_bt_grenexplosionB::StaticClass();
	InvGrenadeIndex         = 4;
	_cMILESAltClass         = AThrow_MILES_Grenade::StaticClass();
	OwnerDamageType         = UGrenadeExplosionDamage::StaticClass();
	special_tag             = "_new";
	DisplayFOV              = 65;
	PickupClass             = APickupT_POM_2S::StaticClass();
	PlayerViewOffset        = FVector(0, 0, 0);
	AttachmentClass         = { AAttachT_POM_2S::StaticClass() };
	IconMaterial            = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_pdm.hud_pdm"), NULL, LOAD_None, NULL);
	ItemName                = "POM2S Munition";
	Mesh                    = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/PDM_1P.PDM_1P"), NULL, LOAD_None, NULL);
	DrawScale               = 1;
}

void AThrow_POM_2S::SetAltFireNotified(bool bNotify)
{
	_bAltFireNotified = bNotify;
}

bool AThrow_POM_2S::IsAltFireNotified()
{
	return _bAltFireNotified;
}

void AThrow_POM_2S::Tick(float DeltaTime)
{
	if (_FuseTime > 0)
	{
		_FuseCounter += DeltaTime;
		if (_FuseCounter > _FuseTime && !bMunitionArmed)
		{
			ArmMunition();
		}
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
		{
			UE_LOG(LogTemp, Log, TEXT("FUSECOUNTER %d TIME %d"), _FuseCounter, _FuseTime);
		}
	}
}
void AThrow_POM_2S::ArmMunition()
{
	/*
	bMunitionArmed = true;
	if (_PickupPtr != None)
	{
		PickupT_PDM_Munition(_PickupPtr).bArmed = true;
	}
	else
	{
		if (_PickupPtr == None)
		{
			ThirdPersonActor.Destroy();
			ThirdPersonActor = None;
			SpawnPickup(True);
			PickupT_PDM_Munition(_PickupPtr).bArmed = true;
			if (Instigator.Weapon == Self)
			{
				Instigator.GrenadeThrow3p(Instigator.1);
				Instigator.DeleteInventory(Self);
				Instigator.PendingWeapon = None;
				Instigator.ChangedWeapon();
			}
			GotoState('Idle');
		}
	}
	*/
}
