// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "GUITreeListBox.generated.h"

class UGUITreeList;
class UGUIListBase;
class UGUIContextMenu;

class UGUIComponent;
class UGUIController;
UCLASS()
class UGUITreeListBox : public UGUIListBoxBase
{
	GENERATED_BODY()
public:
	UGUITreeListBox();

	UPROPERTY()														UGUITreeList* List;							//var GUITreeList List;

	void InitBaseList(UGUIListBase* LocalList);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	bool InternalDblClick(UGUIComponent* Sender);
	int32 ItemCount();
	bool MyOpen(UGUIContextMenu* Menu);
	bool MyClose(UGUIContextMenu* Sender);
};
