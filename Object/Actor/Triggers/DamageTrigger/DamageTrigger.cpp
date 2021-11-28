// All the original content belonged to the US Army


#include "AA29/Object/Actor/Triggers/DamageTrigger/DamageTrigger.h"

ADamageTrigger::ADamageTrigger()
{

}

void ADamageTrigger::InitializeFor(AThrowWeaponPickup* p)
{
	/*
	int32 i = 0;
	local class<ThrowWeapon>  W;
	W = class<ThrowWeapon>(p.InventoryType);
	Instigator = p.Instigator;
	InstigatorController = Instigator.Controller;
	SetCollisionSize(W.Default.sDamageRadius, W.Default.sDamageHeight);
	PrePivot.Z = CollisionHeight;
	SetPhysics(PHYS_Trailer);
	bTrailerAllowRotation = true;
	bTrailerPrePivot = true;
	DamageType = W.Default.SmokeDamageType;
	fDamageTime = W.Default.sDamagePerTime;
	fDamageCenter = W.Default.sDamageAtCenter;
	fDamageEdge = W.Default.sDamageAtEdge;
	for (i = 0; i < W.Default.DamageClasses.Length; i++)
	{
		DamageClasses[i] = W.Default.DamageClasses[i];
	}
	*/
}

void ADamageTrigger::NotifyLanded(AThrowWeaponPickup* p)
{
	/*
	SetCollision(false, false, false);
	SetCollision(Default.bCollideActors, Default.bBlockActors, Default.bBlockPlayers);
	*/
}

void ADamageTrigger::Touch(AActor* Other)
{
	/*
	int32 i = 0;
	for (i = 0; i < DamageClasses.Length; i++)
	{
		if (ClassIsChildOf(Other.Class, DamageClasses[i]))
		{
			if (FastTrace(Location, Other.Location))
			{
				AddDamageActor(Other);
			}
		}
	}
	*/
}

void ADamageTrigger::UnTouch(AActor* Other)
{
	/*
	int32 i = 0;
	for (i = 0; i < DamageActors.Length; i++)
	{
		if (DamageActors[i] == Other)
		{
			DamageActors.remove(i, 1);
		}
	}
	if (DamageActors.Length == 0)
	{
		SetTimer(0, false);
	}
	*/
}

void ADamageTrigger::AddDamageActor(AActor* Other)
{
	/*
	int32 i = 0;
	for (i = 0; i < DamageActors.Length; i++)
	{
		if (DamageActors[i] == Other)
		{
			return;
		}
	}
	if (DamageActors.Length == 0)
	{
		SetTimer(fDamageTime, true);
	}
	DamageActors[DamageActors.Length] = Other;
	DamageActor(Other);
	*/
}

void ADamageTrigger::Timer()
{
	/*
	int32 i = 0;
	for (i = 0; i < DamageActors.Length; i++)
	{
		DamageActor(DamageActors[i]);
	}
	*/
}

void ADamageTrigger::DamageActor(AActor* Other)
{
	float Damage = 0;
	FVector Delta = FVector(0, 0, 0);
	float ratio = 0;
	/*
	Delta = (Location - Other.Location);
	ratio = ((VSize(Delta) - Other.CollisionRadius) / CollisionRadius);
	ratio = FClamp(ratio, 0, 1);
	Damage = ((ratio * fDamageEdge) + ((1 - ratio) * fDamageCenter));
	Other.TakeDamage(int(Damage), Instigator, Other.Location, vect(0, 0, 0), DamageType, , InstigatorController, Self);
	*/
}
