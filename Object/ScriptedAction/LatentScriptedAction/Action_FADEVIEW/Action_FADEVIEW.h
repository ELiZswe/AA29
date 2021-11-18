// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_FADEVIEW.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_FADEVIEW : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_FADEVIEW();



	UPROPERTY(EditAnywhere, Category = "Action")					FVector TargetFlash;				//var(Action) Object.Vector TargetFlash;
	UPROPERTY(EditAnywhere, Category = "Action")					float FadeTime;						//var(Action) float FadeTime;


	bool InitActionFor(UScriptedController* C);
	FString GetActionString();
	bool TickedAction();
	bool StillTicking(UScriptedController* C, float DeltaTime);

};
