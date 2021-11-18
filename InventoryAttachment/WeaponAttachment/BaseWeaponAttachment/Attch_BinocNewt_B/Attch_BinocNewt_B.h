// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "Attch_BinocNewt_B.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAttch_BinocNewt_B : public ABaseWeaponAttachment
{
	GENERATED_BODY()
public:
	AAttch_BinocNewt_B();

	virtual float GetDrawScaleDecision(float PawnScale);
};
