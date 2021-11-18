// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/SoldierClass/SoldierClass.h"
#include "ClassSF.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AClassSF : public ASoldierClass
{
	GENERATED_BODY()
public:
	AClassSF();


	void LoadWeapon();
	virtual void addClassInventory(bool bMaybeSkip) override;
	virtual float WeaponEffectivenessBonus(AAGP_Weapon* W) override;
};
