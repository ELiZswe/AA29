// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDColorDisplay.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDColorDisplay : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDColorDisplay();
		
	UPROPERTY()										UMaterialInstance* _Texture;		//var Texture _Texture;

	void Destroyed();
	void CreateTexture();
	void Draw(UCanvas* Canvas);

	
};
