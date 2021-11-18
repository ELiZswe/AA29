// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"
#include "GUIScrollButtonBase.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIScrollButtonBase : public UGUIGFXButton
{
	GENERATED_BODY()
public:
	UGUIScrollButtonBase();

	UPROPERTY()											bool bIncreaseButton;							//var() bool bIncreaseButton;
};
