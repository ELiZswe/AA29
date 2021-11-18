// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon\AGP_Weapon\ThrowWeapon\ThrowWeapon.h"
#include "Throw_M67_Frag.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AThrow_M67_Frag : public AThrowWeapon
{
	GENERATED_BODY()
public:
	AThrow_M67_Frag();

	
	UPROPERTY()		float _FlashDuration;				//var float _FlashDuration;

	virtual void PlayFiring() override;
};
