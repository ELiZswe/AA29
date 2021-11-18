// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon\AGP_Weapon\ThrowWeapon\ThrowWeapon.h"
#include "Throw_POM_2S.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AThrow_POM_2S : public AThrowWeapon
{
	GENERATED_BODY()
public:
	AThrow_POM_2S();

	
	UPROPERTY()		bool bMunitionArmed;				//var bool bMunitionArmed;

	void SetAltFireNotified(bool bNotify);
	bool IsAltFireNotified();
	void Tick(float DeltaTime);
	void ArmMunition();
};
