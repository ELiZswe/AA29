// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDAlphaBar.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDAlphaBar : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDAlphaBar();

	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;

	void Destroyed();
	void Draw(UCanvas* Canvas);
	void SetTexture(UMaterialInstance* Tex);
};
