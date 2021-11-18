// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_PlayLIPSinc.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_PlayLIPSinc : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_PlayLIPSinc();


	UPROPERTY(EditAnywhere, Category = "Action")			float Pitch;					//var(Action) float Pitch;
	UPROPERTY(EditAnywhere, Category = "Action")			float Radius;					//var(Action) float Radius;
	UPROPERTY(EditAnywhere, Category = "Action")			float Volume;					//var(Action) float Volume;
	UPROPERTY(EditAnywhere, Category = "Action")			FName LIPSincAnimName;			//var(Action) name LIPSincAnimName;

	bool InitActionFor(UScriptedController* C);
	FString GetActionString();

};
