// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod.h"
#include "WeaponMod_AKs74u_Ironsight.generated.h"

class USkeletalMesh;

UCLASS()
class AA29_API AWeaponMod_AKs74u_Ironsight : public ABaseWeaponMod
{
	GENERATED_BODY()
public:
	AWeaponMod_AKs74u_Ironsight();

	virtual void SetupScope() override;
};
