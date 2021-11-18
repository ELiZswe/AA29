// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_FORCEMOVETOPOINT.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_FORCEMOVETOPOINT : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_FORCEMOVETOPOINT();

	UPROPERTY()											uint8 originalPhys;			//var byte originalPhys;
	UPROPERTY()											AActor* Dest;				//var Actor Dest;
	UPROPERTY(EditAnywhere, Category = "Action")		FName DestinationTag;		//var(Action) name DestinationTag;

	bool InitActionFor(UScriptedController * C);
};
