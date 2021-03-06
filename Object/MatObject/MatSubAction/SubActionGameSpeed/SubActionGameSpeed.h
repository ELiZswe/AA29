// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "AA29/AA29.h"
#include "AA29/MyEnums.h"
#include "SubActionGameSpeed.generated.h"

UCLASS()
class USubActionGameSpeed : public UMatSubAction
{
	GENERATED_BODY()
public:
	USubActionGameSpeed();

	UPROPERTY(EditAnywhere, Category = "GameSpeed")										FRange GameSpeed;							//var(GameSpeed) Object.Range GameSpeed;
};
