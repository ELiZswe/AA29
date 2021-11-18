// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "GUITreeListBox.generated.h"

class UGUITreeList;
class UGUIListBase;
class UGUIContextMenu;

UCLASS()
class AA29_API UGUITreeListBox : public UGUIListBoxBase
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
	void ItemCount();
	void MyOpen(UGUIContextMenu* Menu);
	void MyClose(UGUIContextMenu* Sender);
};
