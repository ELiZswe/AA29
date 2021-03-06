// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Pickup/Ammo/Ammo.h"

AAmmunition::AAmmunition()
{
	InitialAmount       = 10;
	WarnTargetPct       = 0.5f;
	RefireRate          = 0.5f;
	NetUpdateFrequency  = 1;
	MyDamageType = UDamageType::StaticClass();
}

void AAmmunition::CheckOutOfAmmo()
{
}
bool AAmmunition::UseAmmo(int32 AmountNeeded, bool bAmountNeededIsMax)
{
	if (bAmountNeededIsMax && AmmoAmount < AmountNeeded)
	{
		AmountNeeded = AmmoAmount;
	}
	if (AmmoAmount < AmountNeeded)
	{
		CheckOutOfAmmo();
		return false;
	}
	AmmoAmount -= AmountNeeded;
	//NetUpdateTime = GetWorld()->GetTimeSeconds() - 1;
	if(GetNetMode() == ENetMode::NM_Standalone || GetNetMode() == ENetMode::NM_Client)
	{
		CheckOutOfAmmo();
	}
	return true;
}
bool AAmmunition::HasAmmo()
{
	return AmmoAmount > 0;
}

void AAmmunition::DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	Canvas.DrawText("Ammunition " + GetItemName(this) + " amount " + AmmoAmount + " Max " + MaxAmmo);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	*/
}

bool AAmmunition::HandlePickupQuery(APickup* Item)
{
	/*
	if (Class == Item.InventoryType)
	{
		if (AmmoAmount == MaxAmmo)
		{
			return true;
		}
		Item.AnnouncePickup(Cast<APawn>(GetOwner()));
		AddAmmo(Cast<AAmmo>(Item).AmmoAmount);
		Item.SetRespawn();
		return true;
	}
	if (Inventory == nullptr)
	{
		return false;
	}
	return Inventory.HandlePickupQuery(Item);
	*/
	return false;     //FAKE   /ELiZ
}

bool AAmmunition::AddAmmo(int32 AmmoToAdd)
{
	/*
	if (Level.GRI.WeaponBerserk > 1)
	{
		AmmoAmount = MaxAmmo;
	}
	else
	{
		if (AmmoAmount < MaxAmmo)
		{
			AmmoAmount = FMath::Min(MaxAmmo, AmmoAmount + AmmoToAdd);
		}
	}
	NetUpdateTime = GetWorld()->GetTimeSeconds() - 1;
	*/
	return true;
}

AProjectile* AAmmunition::SpawnProjectile(FVector Start, FRotator Dir)
{
	AProjectile* Proj = nullptr;
	AmmoAmount -= 1;
	//Spawn(ProjectileClass, , , Start, Dir);
	return Proj;
}

float AAmmunition::GetDamageRadius()
{
	/*
	if (ProjectileClass != nullptr)
	{
		return ProjectileClass.Default.DamageRadius;
	}
	*/
	return 0;
	
}
void AAmmunition::DecrementAmmo()
{
}
void AAmmunition::UseBullet(FVector StartTrace, FRotator Direction)
{
}

void AAmmunition::ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, FBoneInfo HitBone, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, FVector X, FVector Y, FVector Z, float fStrength)
{
}

void AAmmunition::NPC_ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, FBoneInfo HitBone, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, FVector X, FVector Y, FVector Z, float fStrength)
{
}

