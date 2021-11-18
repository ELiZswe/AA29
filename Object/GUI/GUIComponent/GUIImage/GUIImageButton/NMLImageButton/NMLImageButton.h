// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "NMLImageButton.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UNMLImageButton : public UGUIImageButton
{
	GENERATED_BODY()
public:
	UNMLImageButton();

	UPROPERTY()										FString LinkParam3;									//var string LinkParam3;
	UPROPERTY()										int32 LinkParam2;									//var int LinkParam2;
	UPROPERTY()										int32 LinkParam1;									//var int LinkParam1;
	UPROPERTY()										FString LinkPanelName;								//var string LinkPanelName;
};
