// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Powerups/Powerups.h"
#include "Armor.generated.h"

UCLASS()
class AArmor : public APowerups
{
	GENERATED_BODY()
public:
	AArmor();

	UPROPERTY(EditAnywhere)		UaDamageType*	ProtectionType;					//var() class<DamageType> ProtectionType;
	UPROPERTY(EditAnywhere)		int32			ArmorAbsorption;				//var() int32 ArmorAbsorption;
	UPROPERTY(EditAnywhere)		int32			AbsorptionPriority;				//var() int32 AbsorptionPriority;
	UPROPERTY()										AArmor*			NextArmor;						//var Armor NextArmor;

	int32 ArmorAbsorbDamage(int32 Damage, UaDamageType* DamageType, FVector HitLocation);
	int32 ArmorPriority(UaDamageType* DamageType);
	void ArmorImpactEffect(FVector HitLocation);
	AArmor* PrioritizeArmor(int32 Damage, UaDamageType* DamageType, FVector HitLocation);

};
