// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIScrollBarBase.h"
#include "GUIVertScrollBar.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIVertScrollBar : public UGUIScrollBarBase
{
	GENERATED_BODY()
public:
	UGUIVertScrollBar();

	void GripPressed(UGUIComponent* Sender, bool IsRepeat);
	bool GripPreDraw(UGUIComponent* Sender);
	void ZoneClick(float Delta);
};
