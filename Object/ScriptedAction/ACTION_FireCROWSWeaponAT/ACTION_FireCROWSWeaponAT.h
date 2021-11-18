// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_FireCROWSWeaponAT.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_FireCROWSWeaponAT : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_FireCROWSWeaponAT();

	UPROPERTY()											AActor* ShootTarget;		//var Actor ShootTarget;
	UPROPERTY(EditAnywhere, Category = "Action")		FName ShootTargetTag;		//var(Action) name ShootTargetTag;
	UPROPERTY(EditAnywhere, Category = "Action")		bool bPressAltFire;			//var(Action) bool bPressAltFire;
	UPROPERTY(EditAnywhere, Category = "Action")		bool bPressFire;			//var(Action) bool bPressFire;

	bool InitActionFor(UScriptedController* C);
};
