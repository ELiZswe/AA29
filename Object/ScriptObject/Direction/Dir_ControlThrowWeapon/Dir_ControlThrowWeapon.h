// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_ControlThrowWeapon.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDir_ControlThrowWeapon : public UDirection
{
	GENERATED_BODY()
public:
	UDir_ControlThrowWeapon();

	UPROPERTY()						bool						_bThrow;				//var bool _bThrow;

	void DirectionStart();
	bool ProcessParams();
};
