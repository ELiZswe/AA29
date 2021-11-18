// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/VehicleWeapon/CROWS_Base/CROWS_Base.h"
#include "CROWS_Mk19GL.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ACROWS_Mk19GL : public ACROWS_Base
{
	GENERATED_BODY()
public:
	ACROWS_Mk19GL();

	void OwnerEffects();
};
