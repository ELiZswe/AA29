// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "DirectoryTreeListBox.generated.h"

class UDirectoryTreeList;
class UGUIListBase;
class UGUIComponent;
class UGUIContextMenu;

class UGUIController;
UCLASS()
class UDirectoryTreeListBox : public UGUIListBoxBase
{
	GENERATED_BODY()
public:
	UDirectoryTreeListBox();

	UPROPERTY()		UDirectoryTreeList*			List;				//var DirectoryTreeList List;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitBaseList(UGUIListBase* LocalList);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnDblClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	int32 ItemCount();
	bool MyOpen(UGUIContextMenu* Menu, UGUIComponent* ContextMenuOwner);
	bool MyClose(UGUIContextMenu* Sender);
};
