// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/SoldierClass.h"
#include "ClassSF.generated.h"

class AAGP_Weapon;
UCLASS()
class AClassSF : public ASoldierClass
{
	GENERATED_BODY()
public:
	AClassSF();


	void LoadWeapon();
	virtual void addClassInventory(bool bMaybeSkip) override;
	virtual float WeaponEffectivenessBonus(AAGP_Weapon* W) override;
};
