// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIContainer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIContainer : public UUIControl
{
	GENERATED_BODY()
public:
	UUIContainer();

	UPROPERTY()										UMaterialInstance* _Texture;				//var Texture _Texture;
	UPROPERTY()										FString sBitmapName;						//var string sBitmapName;

	void Destroyed();
	void CreateTexture();
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);

};
