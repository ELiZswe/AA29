// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "ServerBrowserMCListBox.generated.h"

class UGUIContextMenu;
UCLASS()
class UServerBrowserMCListBox : public UGUIMultiColumnListBox
{
	GENERATED_BODY()
public:
	UServerBrowserMCListBox();

	bool InternalOnOpen(UGUIContextMenu* Menu);
	bool InternalOnClose(UGUIContextMenu* Sender);
};
