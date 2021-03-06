// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "Attch_BinocM24_B.generated.h"

UCLASS()
class AAttch_BinocM24_B : public ABaseWeaponAttachment
{
	GENERATED_BODY()
public:
	AAttch_BinocM24_B();

	virtual float GetDrawScaleDecision(float PawnScale);
};
