// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_PLAYSOUND.generated.h"

class AScriptedController;
UCLASS()
class UAction_PLAYSOUND : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_PLAYSOUND();


	UPROPERTY(EditAnywhere, Category = "Action")			bool bAttenuate;				//var(Action) bool bAttenuate;
	UPROPERTY(EditAnywhere, Category = "Action")			float Pitch;					//var(Action) float Pitch;
	UPROPERTY(EditAnywhere, Category = "Action")			float Volume;					//var(Action) float Volume;
	UPROPERTY(EditAnywhere, Category = "Action")			USoundBase* Sound;				//var(Action) Sound Sound;

	bool InitActionFor(AScriptedController* C);
	FString GetActionString();

};
