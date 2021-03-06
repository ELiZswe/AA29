// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatAction/MatAction.h"
#include "AA29/MyEnums.h"
#include "ActionMoveCamera.generated.h"

UCLASS(Config = Game)
class UActionMoveCamera : public UMatAction
{
	GENERATED_BODY()
public:
	UActionMoveCamera();

	UPROPERTY(EditAnywhere, Category = "Path", Config)						EPathStyle PathStyle;								//var(Path) config EPathStyle PathStyle;
};
