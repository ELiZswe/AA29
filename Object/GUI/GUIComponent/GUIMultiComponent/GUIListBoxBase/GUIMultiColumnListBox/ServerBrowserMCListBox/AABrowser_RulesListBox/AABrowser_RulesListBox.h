// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/ServerBrowserMCListBox.h"
#include "AABrowser_RulesListBox.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_RulesListBox : public UServerBrowserMCListBox
{
	GENERATED_BODY()
public:
	UAABrowser_RulesListBox();

	void Opened(UGUIComponent* Sender);
};
