// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_ThrowWeapon.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_ThrowWeapon : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_ThrowWeapon();

	UPROPERTY(EditAnywhere, Category = "Action")						FVector WeaponVelocity;						//var(Action) Object.Vector WeaponVelocity;

	bool InitActionFor(UScriptedController* C);
};
