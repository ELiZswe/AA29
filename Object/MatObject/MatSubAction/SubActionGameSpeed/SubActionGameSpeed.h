// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "AA29/MyStructs.h"
#include "SubActionGameSpeed.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API USubActionGameSpeed : public UMatSubAction
{
	GENERATED_BODY()
public:
	USubActionGameSpeed();

	//UPROPERTY(EditAnywhere, Category = "GameSpeed")										FRange GameSpeed;							//var(GameSpeed) Object.Range GameSpeed;
};
