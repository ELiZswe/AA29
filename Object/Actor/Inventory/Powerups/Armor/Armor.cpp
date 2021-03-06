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
		if (ProtectionType != nullptr)
		{
			Cast<APawn>(GetOwner())->ReducedDamageType=ProtectionType;
		}
	}
	Function EndState()
	{
		Super::EndState();
		if ((Cast<APawn>(GetOwner()) != nullptr) && (ProtectionType != Cast<APawn>(GetOwner())->ReducedDamageType))
		{
			Cast<APawn>(GetOwner())->ReducedDamageType=nullptr;
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
	if ((DamageType != nullptr) && (ProtectionType == DamageType))
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
	if ((DamageType != nullptr) && (ProtectionType == DamageType))
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
	if (Inventory != nullptr)
	{
		FirstArmor = Inventory.PrioritizeArmor(Damage, DamageType, HitLocation);
	}
	else
	{
		FirstArmor = nullptr;
	}
	if (FirstArmor == nullptr)
	{
		NextArmor = nullptr;
		return this;
	}
	if (FirstArmor.ArmorPriority(DamageType) < ArmorPriority(DamageType))
	{
		NextArmor = FirstArmor;
		return this;
	}
	InsertAfter = FirstArmor;
	if ((InsertAfter.NextArmor != nullptr) && (InsertAfter.NextArmor.ArmorPriority(DamageType) > ArmorPriority(DamageType)))
	{
		InsertAfter = InsertAfter.NextArmor;
	}
	NextArmor = InsertAfter.NextArmor;
	InsertAfter.NextArmor = this;
	*/
	return FirstArmor;

}

