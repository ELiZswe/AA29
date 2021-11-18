// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "GUIListSpacer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIListSpacer : public UGUIMenuOption
{
	GENERATED_BODY()
public:
	UGUIListSpacer();

	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
};
