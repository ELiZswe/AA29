// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_TELEPORTTOPOINT.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_TELEPORTTOPOINT : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_TELEPORTTOPOINT();

	UPROPERTY()														AActor* Dest;								//var Actor Dest;
	UPROPERTY(EditAnywhere, Category = "Action")					bool bPlaySpawnEffect;						//var(Action) bool bPlaySpawnEffect;
	UPROPERTY(EditAnywhere, Category = "Action")					FName DestinationTag;						//var(Action) name DestinationTag;

	bool InitActionFor(UScriptedController* C);
};
