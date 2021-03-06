// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_StartCROWSVehicle.generated.h"

class AScriptedController;
UCLASS()
class UACTION_StartCROWSVehicle : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_StartCROWSVehicle();

	UPROPERTY(EditAnywhere)						float MaxDesiredSpeed;					//var() float MaxDesiredSpeed;
	UPROPERTY(EditAnywhere)						float DesiredSpeed;						//var() float DesiredSpeed;

	bool InitActionFor(AScriptedController* C);
};
