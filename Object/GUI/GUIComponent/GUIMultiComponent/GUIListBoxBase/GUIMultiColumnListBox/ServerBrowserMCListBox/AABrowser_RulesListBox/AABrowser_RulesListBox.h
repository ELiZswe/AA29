// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/ServerBrowserMCListBox.h"
#include "AABrowser_RulesListBox.generated.h"

class UGUIComponent;
UCLASS()
class UAABrowser_RulesListBox : public UServerBrowserMCListBox
{
	GENERATED_BODY()
public:
	UAABrowser_RulesListBox();

	void Opened(UGUIComponent* Sender);
};
