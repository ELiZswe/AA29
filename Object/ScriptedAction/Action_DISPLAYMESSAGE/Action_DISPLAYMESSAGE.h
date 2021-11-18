// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_DISPLAYMESSAGE.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_DISPLAYMESSAGE : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_DISPLAYMESSAGE();

	UPROPERTY(EditAnywhere, Category = "Action")		FName messagetype;		//var(Action) name messagetype;
	UPROPERTY(EditAnywhere, Category = "Action")		bool bBroadcast;		//var(Action) bool bBroadcast;
	UPROPERTY(EditAnywhere, Category = "Action")		FString Message;		//var(Action) localized string Message;

	bool InitActionFor(UScriptedController* C);
	FString GetActionString();

};
