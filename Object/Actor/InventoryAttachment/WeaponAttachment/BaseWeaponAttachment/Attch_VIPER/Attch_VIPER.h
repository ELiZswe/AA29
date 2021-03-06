// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "Attch_VIPER.generated.h"

UCLASS()
class AAttch_VIPER : public ABaseWeaponAttachment
{
	GENERATED_BODY()
public:
	AAttch_VIPER();

	virtual float GetDrawScaleDecision(float PawnScale);
};
