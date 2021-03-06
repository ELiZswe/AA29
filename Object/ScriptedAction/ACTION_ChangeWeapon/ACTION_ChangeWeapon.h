// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_ChangeWeapon.generated.h"

class AWeapon;

class AScriptedController;
UCLASS()
class UACTION_ChangeWeapon : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_ChangeWeapon();

	UPROPERTY(EditAnywhere, Category = "Action")		AWeapon* newWeapon;		//var(Action) class<Weapon> newWeapon;

	bool InitActionFor(AScriptedController* C);
};
