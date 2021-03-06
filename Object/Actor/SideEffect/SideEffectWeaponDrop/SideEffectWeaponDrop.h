// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/SideEffect/SideEffect.h"
#include "SideEffectWeaponDrop.generated.h"

class AAGP_Weapon;

UCLASS()
class ASideEffectWeaponDrop : public ASideEffect
{
	GENERATED_BODY()
public:
	ASideEffectWeaponDrop();

	void ScaleByDamage(int32 Damage);
	bool HasValidDropAnimation(AAGP_Weapon* AffectedWeapon);
	void Start();
	void update(float DeltaTime);
	void End();
};
