// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "Attch_BinocM22_A.generated.h"

UCLASS()
class AAttch_BinocM22_A : public ABaseWeaponAttachment
{
	GENERATED_BODY()
public:
	AAttch_BinocM22_A();


	virtual float GetDrawScaleDecision(float PawnScale);
};
