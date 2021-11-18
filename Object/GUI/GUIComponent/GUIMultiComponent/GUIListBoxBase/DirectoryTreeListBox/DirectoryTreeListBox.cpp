// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/DirectoryTreeListBox/DirectoryTreeListBox.h"

UDirectoryTreeListBox::UDirectoryTreeListBox()
{
	//DefaultListClass = "GUI2K4.DirectoryTreeList";
}

void UDirectoryTreeListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (DefaultListClass != "")
	{
		List = DirectoryTreeList(AddComponent(DefaultListClass));
		if (List == None)
		{
			Log(Name $ ".InitComponent - Could not create default list [" $ DefaultListClass $ "]");
			Return;
		}
	}
	if (List == None)
	{
		Warn("Could not initialize list!");
		Return;
	}
	InitBaseList(List);
	*/
}

void UDirectoryTreeListBox::InitBaseList(UGUIListBase* LocalList)
{
	/*
	if (List == None || List != LocalList && GUIList(LocalList) != None)
	{
		List = DirectoryTreeList(LocalList);
	}
	List.__OnClick__Delegate = InternalOnClick;
	List.OnClickSound = 1;
	List.__OnDblClick__Delegate = InternalOnDblClick;
	List.__OnChange__Delegate = InternalOnChange;
	InitBaseList(LocalList);
	*/
}

bool UDirectoryTreeListBox::InternalOnClick(UGUIComponent* Sender)
{
	/*
	List.InternalOnClick(Sender);
	OnClick(Self);
	*/
	return true;
}

bool UDirectoryTreeListBox::InternalOnDblClick(UGUIComponent* Sender)
{
	return true;
}

void UDirectoryTreeListBox::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Controller != None && Controller.bCurMenuInitialized)
	{
		OnChange(Self);
	}
	*/
}

void UDirectoryTreeListBox::ItemCount()
{
	//Return List.ItemCount;
}

void UDirectoryTreeListBox::MyOpen(UGUIContextMenu* Menu, UGUIComponent* ContextMenuOwner)
{
	//Return HandleContextMenuOpen(Self, Menu, ContextMenuOwner);
}

void UDirectoryTreeListBox::MyClose(UGUIContextMenu* Sender)
{
	//Return HandleContextMenuClose(Sender);
}