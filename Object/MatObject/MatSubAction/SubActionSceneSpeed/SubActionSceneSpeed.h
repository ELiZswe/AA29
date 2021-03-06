// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "SubActionSceneSpeed.generated.h"

UCLASS()
class USubActionSceneSpeed : public UMatSubAction
{
	GENERATED_BODY()
public:
	USubActionSceneSpeed();

	UPROPERTY(EditAnywhere, Category = "SceneSpeed")										FRange SceneSpeed;							//var(SceneSpeed) Object.Range SceneSpeed;
};
