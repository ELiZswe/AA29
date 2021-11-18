// All the original content belonged to the US Army


#include "Ammunition.h"


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
/*
void AAmmunition::DisplayDebug(UCanvas* Canvas, float YL, float YPos)
{
	Canvas.DrawText("Ammunition " $ GetItemName(Self) $ " amount " $ AmmoAmount $ " Max " $ MaxAmmo);
	YPos += YL;
	Canvas.SetPos(4, YPos);
}
*/
void AAmmunition::HandlePickupQuery(APickup* Item)
{
	/*
	if (Class == Item.InventoryType)
	{
		if (AmmoAmount == MaxAmmo)
		{
			return true;
		}
		Item.AnnouncePickup(Pawn(Owner));
		AddAmmo(Ammo(Item).AmmoAmount);
		Item.SetRespawn();
		return true;
	}
	if (Inventory == None)
	{
		return false;
	}
	return Inventory.HandlePickupQuery(Item);
	*/
}
void AAmmunition::AddAmmo(int32 AmmoToAdd)
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
			AmmoAmount = Min(MaxAmmo, AmmoAmount + AmmoToAdd);
		}
	}
	NetUpdateTime = GetWorld()->GetTimeSeconds() - 1;
	return true;
	*/
}
void AAmmunition::SpawnProjectile(FVector Start, FRotator Dir)
{
	/*
	local Projectile Proj;
	AmmoAmount -= 1;
	Spawn(ProjectileClass, , , Start, Dir);
	return Proj;
	*/
}
float AAmmunition::GetDamageRadius()
{
	/*
	if (ProjectileClass != None)
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
/*
void AAmmunition::ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, Actor.BoneInfo HitBone, FVector HitLocation, FVector HitNormal, Material HitMaterial, FVector X, FVector Y, FVector Z, float fStrength)
{
}
*/
/*
void AAmmunition::NPC_ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, Actor.BoneInfo HitBone, FVector HitLocation, FVector HitNormal, Material HitMaterial, FVector X, FVector Y, FVector Z, float fStrength)
{
}
*/