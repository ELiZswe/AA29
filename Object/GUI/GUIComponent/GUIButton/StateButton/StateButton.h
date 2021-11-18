// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "StateButton.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UStateButton : public UGUIButton
{
	GENERATED_BODY()
public:
	UStateButton();


	UPROPERTY()											TArray<UMaterialInstance*> Images;				//var() Material Images;
	UPROPERTY()											EImgStyle ImageStyle;							//var() GUI.eImgStyle ImageStyle;		// How should we display this image
};
