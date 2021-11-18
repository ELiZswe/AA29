// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_SpawnActor.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_SpawnActor : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_SpawnActor();

	UPROPERTY(EditAnywhere, Category = "Action")						FName ActorTag;						//var(Action) name ActorTag;
	UPROPERTY(EditAnywhere, Category = "Action")						bool bOffsetFromScriptedPawn;		//var(Action) bool bOffsetFromScriptedPawn;
	UPROPERTY(EditAnywhere, Category = "Action")						FRotator RotationOffset;			//var(Action) Object.Rotator RotationOffset;
	UPROPERTY(EditAnywhere, Category = "Action")						FVector LocationOffset;				//var(Action) Object.Vector LocationOffset;
	UPROPERTY(EditAnywhere, Category = "Action")						AActor* ActorClass;					//var(Action) class<Actor> ActorClass;

	bool InitActionFor(UScriptedController* C);
	FString GetActionString();
};
