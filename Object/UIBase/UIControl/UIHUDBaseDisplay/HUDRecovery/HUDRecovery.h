// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDRecovery.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDRecovery : public UUIHUDBaseDisplay
{
	GENERATED_BODY()

public:
	UHUDRecovery();

	UPROPERTY()										UMaterialInstance* _tMeter;			//var Texture _tMeter;


	void Destroyed();
	void Draw(UCanvas* Canvas);
	
};
