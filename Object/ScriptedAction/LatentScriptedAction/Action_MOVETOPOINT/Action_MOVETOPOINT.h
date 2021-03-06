// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_MOVETOPOINT.generated.h"

class AScriptedController;
UCLASS()
class UAction_MOVETOPOINT : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_MOVETOPOINT();


	UPROPERTY()														AActor* MoveTarget;						//var Actor MoveTarget;
	UPROPERTY(EditAnywhere, Category = "Action")					FName DestinationTag;						//var(Action) name DestinationTag;


	bool MoveToGoal();
	AActor* GetMoveTargetFor(AScriptedController* C);
	FString GetActionString();
};
