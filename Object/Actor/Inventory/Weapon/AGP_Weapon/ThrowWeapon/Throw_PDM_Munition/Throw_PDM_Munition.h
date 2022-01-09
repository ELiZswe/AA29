// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon\AGP_Weapon\ThrowWeapon\ThrowWeapon.h"
#include "Throw_PDM_Munition.generated.h"

UCLASS()
class AThrow_PDM_Munition : public AThrowWeapon
{
	GENERATED_BODY()
public:
	AThrow_PDM_Munition();

	
	UPROPERTY()		bool bMunitionArmed;			//var bool bMunitionArmed;

	void SetAltFireNotified(bool bNotify);
	bool IsAltFireNotified();
	void Tick(float DeltaTime);
	void ArmMunition();

};
