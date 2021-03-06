// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_LocalizedMessage.generated.h"

class ULocalMessage;

class AScriptedController;
UCLASS()
class UACTION_LocalizedMessage : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_LocalizedMessage();

	UPROPERTY(EditAnywhere, Category = "Action")		int32 MessageNum;						//var(Action) int MessageNum;
	UPROPERTY(EditAnywhere, Category = "Action")		ULocalMessage* MessageClass;			//var(Action) class<LocalMessage> MessageClass;

	bool InitActionFor(AScriptedController* C);
	FString GetActionString();
};
