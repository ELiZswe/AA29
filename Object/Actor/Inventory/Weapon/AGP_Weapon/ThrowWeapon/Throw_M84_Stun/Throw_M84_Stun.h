// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon\AGP_Weapon\ThrowWeapon\ThrowWeapon.h"
#include "Throw_M84_Stun.generated.h"

UCLASS()
class AThrow_M84_Stun : public AThrowWeapon
{
	GENERATED_BODY()
public:
	AThrow_M84_Stun();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		float _FlashDuration;		//var float _FlashDuration;
};
