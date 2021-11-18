// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_FireWeapon.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_FireWeapon : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_FireWeapon();

	UPROPERTY(EditAnywhere, Category = "Action")		bool bPressAltFire;		//var(Action) bool bPressAltFire;
	UPROPERTY(EditAnywhere, Category = "Action")		bool bPressFire;		//var(Action) bool bPressFire;

	bool InitActionFor(UScriptedController* C);
};
