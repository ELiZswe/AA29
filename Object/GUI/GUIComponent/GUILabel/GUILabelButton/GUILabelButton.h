// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "GUILabelButton.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUILabelButton : public UGUILabel
{
	GENERATED_BODY()
public:
	UGUILabelButton();

	UPROPERTY()										FString link;					//var() localized string link;


	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
};
