// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "AA29/MyStructs.h"
#include "SubActionFOV.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API USubActionFOV : public UMatSubAction
{
	GENERATED_BODY()
public:
	USubActionFOV();

	//UPROPERTY(EditAnywhere, Category = "FOV")										FRange FOV;							//var(FOV) Object.Range FOV;
};
