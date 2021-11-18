// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "SubActionTrigger.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API USubActionTrigger : public UMatSubAction
{
	GENERATED_BODY()
public:
	USubActionTrigger();


	UPROPERTY(EditAnywhere, Category = "Trigger")										FName EventName;							//var(Trigger) name EventName;
};
