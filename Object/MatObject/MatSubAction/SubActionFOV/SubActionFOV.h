// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "AA29/AA29.h"
#include "AA29/MyEnums.h"
#include "SubActionFOV.generated.h"

UCLASS()
class USubActionFOV : public UMatSubAction
{
	GENERATED_BODY()
public:
	USubActionFOV();

	UPROPERTY(EditAnywhere, Category = "FOV")										FRange FOV;							//var(FOV) Object.Range FOV;
};
