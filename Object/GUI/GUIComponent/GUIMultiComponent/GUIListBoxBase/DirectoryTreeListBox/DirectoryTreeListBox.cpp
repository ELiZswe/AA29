// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/DirectoryTreeListBox/DirectoryTreeListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/DirectoryTreeList/DirectoryTreeList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"

UDirectoryTreeListBox::UDirectoryTreeListBox()
{
	//DefaultListClass = "GUI2K4.DirectoryTreeList";
}

void UDirectoryTreeListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	if (DefaultListClass != "")
	{
		List = Cast<UDirectoryTreeList>(AddComponent(DefaultListClass,false));
		if (List == nullptr)
		{
			//Log(Name + ".InitComponent - Could not create default list [" + DefaultListClass + "]");
			return;
		}
	}
	if (List == nullptr)
	{
		//Warn("Could not initialize list!");
		return;
	}
	InitBaseList(List);
}

void UDirectoryTreeListBox::InitBaseList(UGUIListBase* LocalList)
{
	if (List == nullptr || List != LocalList && Cast<UGUIList>(LocalList) != nullptr)
	{
		List = Cast<UDirectoryTreeList>(LocalList);
	}
	//List.__OnClick__Delegate = InternalOnClick;
	//List.OnClickSound = 1;
	//List.__OnDblClick__Delegate = InternalOnDblClick;
	//List.__OnChange__Delegate = InternalOnChange;
	Super::InitBaseList(LocalList);
}

bool UDirectoryTreeListBox::InternalOnClick(UGUIComponent* Sender)
{
	List->InternalOnClick(Sender);
	OnClick(this);
	return true;
}

bool UDirectoryTreeListBox::InternalOnDblClick(UGUIComponent* Sender)
{
	return true;
}

void UDirectoryTreeListBox::InternalOnChange(UGUIComponent* Sender)
{
	if (Controller != nullptr && Controller->bCurMenuInitialized)
	{
		OnChange(this);
	}
}

int32 UDirectoryTreeListBox::ItemCount()
{
	return List->ItemCount;
}

bool UDirectoryTreeListBox::MyOpen(UGUIContextMenu* Menu, UGUIComponent* ContextMenuOwner)
{
	return HandleContextMenuOpen(this, Menu, ContextMenuOwner);
}

bool UDirectoryTreeListBox::MyClose(UGUIContextMenu* Sender)
{
	return HandleContextMenuClose(Sender);
}
