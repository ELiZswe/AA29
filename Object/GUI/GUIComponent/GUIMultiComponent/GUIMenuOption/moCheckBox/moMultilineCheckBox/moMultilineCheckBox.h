// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "moMultilineCheckBox.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UmoMultilineCheckBox : public UmoCheckBox
{
	GENERATED_BODY()
public:
	UmoMultilineCheckBox();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
