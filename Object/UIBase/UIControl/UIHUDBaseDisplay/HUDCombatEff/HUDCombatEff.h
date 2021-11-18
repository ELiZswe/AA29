// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDCombatEff.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDCombatEff : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDCombatEff();


	UPROPERTY()										UMaterialInstance* _tMaxBar;		//var Texture _tMaxBar;
	UPROPERTY()										UMaterialInstance* _tMeter;			//var Texture _tMeter;

	void Destroyed();
	void Draw(UCanvas* Canvas);

};
