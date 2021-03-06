// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_FireWeaponAt.generated.h"

class AScriptedController;
UCLASS()
class UACTION_FireWeaponAt : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_FireWeaponAt();

	UPROPERTY()											AActor* ShootTarget;		//var Actor ShootTarget;
	UPROPERTY(EditAnywhere, Category = "Action")		FName ShootTargetTag;		//var(Action) name ShootTargetTag;

	bool InitActionFor(AScriptedController* C);
};
