// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "UIHUDPercentageBar.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIHUDPercentageBar : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UUIHUDPercentageBar();

	UPROPERTY()										float EndTime;										//var float EndTime;
	UPROPERTY()										float FillPercentage;								//var float FillPercentage;
	UPROPERTY()										UMaterialInstance* FillBar;							//var Texture FillBar;
	UPROPERTY()										UMaterialInstance* Bracket;							//var Texture Bracket;

	void SetFillPercentage(float new_fill_p);
	void SetEndTime(float new_end_time);
	void Draw(UCanvas* Canvas);
};
