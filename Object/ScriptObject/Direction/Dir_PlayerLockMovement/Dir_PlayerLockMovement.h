// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_PlayerLockMovement.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDir_PlayerLockMovement : public UDirection
{
	GENERATED_BODY()
public:
	UDir_PlayerLockMovement();

	UPROPERTY()						bool		_bLockMovement;		//var bool _bLockMovement;
	UPROPERTY()						bool		_bLockRotation;		//var bool _bLockRotation;

	void DirectionStart();
	bool ProcessParams();
};
