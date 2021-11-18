// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "ServerBrowserMCListBox.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UServerBrowserMCListBox : public UGUIMultiColumnListBox
{
	GENERATED_BODY()
public:
	UServerBrowserMCListBox();

	void InternalOnOpen(UGUIContextMenu* Menu);
	void InternalOnClose(UGUIContextMenu* Sender);
};
