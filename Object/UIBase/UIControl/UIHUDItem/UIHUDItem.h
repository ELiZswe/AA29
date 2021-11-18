// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIHUDItem.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIHUDItem : public UUIControl
{
	GENERATED_BODY()
public:
	UUIHUDItem();

	UPROPERTY()										UMaterialInstance* _Texture;					//var Texture _Texture;

	void Destroyed();
	void Draw(UCanvas* Canvas);
	void SetTexture(UMaterialInstance* Tex);

};
