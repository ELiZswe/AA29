// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "DirectoryTreeListBox.generated.h"

class UDirectoryTreeList;
class UGUIListBase;
class UGUIComponent;
class UGUIContextMenu;

UCLASS()
class AA29_API UDirectoryTreeListBox : public UGUIListBoxBase
{
	GENERATED_BODY()
public:
	UDirectoryTreeListBox();

	UPROPERTY()					UDirectoryTreeList* List;				//var DirectoryTreeList List;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitBaseList(UGUIListBase* LocalList);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnDblClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	void ItemCount();
	void MyOpen(UGUIContextMenu* Menu, UGUIComponent* ContextMenuOwner);
	void MyClose(UGUIContextMenu* Sender);

};
