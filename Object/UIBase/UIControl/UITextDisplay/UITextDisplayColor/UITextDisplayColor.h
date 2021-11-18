// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UITextDisplay/UITextDisplay.h"
#include "UITextDisplayColor.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUITextDisplayColor : public UUITextDisplay
{
	GENERATED_BODY()
public:
	UUITextDisplayColor();

	UPROPERTY()										FColor _cColor;					//var Object.Color _cColor;

	void Draw(UCanvas* Canvas);
	void SetColor(FColor cColor);
};
