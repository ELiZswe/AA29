// All the original content belonged to the US Army


#include "AA29/Object/Actor/Inventory/Powerups/Armor/Armor.h"

AArmor::AArmor()
{

}

/*
State Activated
{
	Function BeginState()
	{
		Super::BeginState();
		if (ProtectionType != None)
		{
			Pawn(Owner).ReducedDamageType = ProtectionType;
		}
	}
	Function EndState()
	{
		Super::EndState();
		if ((Pawn(Owner) != None) && (ProtectionType != Pawn(Owner).ReducedDamageType))
		{
			Pawn(Owner).ReducedDamageType = None;
		}
	}
}
*/

int32 AArmor::ArmorAbsorbDamage(int32 Damage, UaDamageType* DamageType, FVector HitLocation)
{
	int32 ArmorDamage = 0;
	/*
	if (DamageType.Default.bArmorStops)
	{
		ArmorImpactEffect(HitLocation);
	}
	if ((DamageType != None) && (ProtectionType == DamageType))
	{
		return 0;
	}
	if (!DamageType.Default.bArmorStops)
	{
		return Damage;
	}
	ArmorDamage = ((Damage * ArmorAbsorption) / 100);
	if (ArmorDamage >= Charge)
	{
		ArmorDamage = Charge;
		Destroy();
	}
	else
	{
		(Charge -= ArmorDamage);
	}
	*/
	return (Damage - ArmorDamage);
}

int32 AArmor::ArmorPriority(UaDamageType* DamageType)
{
	/*
	if (DamageType.Default.bArmorStops)
	{
		return 0;
	}
	if ((DamageType != None) && (ProtectionType == DamageType))
	{
		return 1000000;
	}
	*/
	return AbsorptionPriority;
}

void AArmor::ArmorImpactEffect(FVector HitLocation)
{
}

AArmor* AArmor::PrioritizeArmor(int32 Damage, UaDamageType* DamageType, FVector HitLocation)
{
	AArmor* FirstArmor = nullptr;
	AArmor* InsertAfter = nullptr;
	/*
	if (Inventory != None)
	{
		FirstArmor = Inventory.PrioritizeArmor(Damage, DamageType, HitLocation);
	}
	else
	{
		FirstArmor = None;
	}
	if (FirstArmor == None)
	{
		NextArmor = None;
		return Self;
	}
	if (FirstArmor.ArmorPriority(DamageType) < ArmorPriority(DamageType))
	{
		NextArmor = FirstArmor;
		return Self;
	}
	InsertAfter = FirstArmor;
	if ((InsertAfter.NextArmor != None) && (InsertAfter.NextArmor.ArmorPriority(DamageType) > ArmorPriority(DamageType)))
	{
		InsertAfter = InsertAfter.NextArmor;
	}
	NextArmor = InsertAfter.NextArmor;
	InsertAfter.NextArmor = Self;
	*/
	return FirstArmor;

}


