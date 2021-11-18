// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UITextButton/UITextButton.h"
#include "UITextButtonSize.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUITextButtonSize : public UUITextButton
{
	GENERATED_BODY()
public:
	UUITextButtonSize();

	UPROPERTY()										UMaterialInstance* _tSelected;			//var Texture _tSelected;
	UPROPERTY()										int32 _iSize;							//var int _iSize;

	void Draw(UCanvas* Canvas);
	void CreateTexture();
	void ScaleControl(UCanvas* Canvas);
	void SetSize(int32 Size);

};
