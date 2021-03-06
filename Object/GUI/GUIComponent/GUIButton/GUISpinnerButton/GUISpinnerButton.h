// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "GUISpinnerButton.generated.h"

class UGUIComponent;
UCLASS()
class UGUISpinnerButton : public UGUIButton
{
	GENERATED_BODY()
public:
	UGUISpinnerButton();

	bool OnPlusClick(UGUIComponent* Sender);
	bool OnMinusClick(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
};
