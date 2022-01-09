// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "MapListBox.generated.h"

class UGUIContextMenu;
class UGUIComponent;
class UGUIController;

UCLASS()
class UMapListBox : public UGUIListBox
{
	GENERATED_BODY()
public:
	UMapListBox();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ContextClick(UGUIContextMenu* Sender, int32 Index);
	bool MyRealOpen(UGUIComponent* MenuOwner);
	bool MyOpen(UGUIContextMenu* Menu);
	bool MyClose(UGUIContextMenu* Sender);
};
