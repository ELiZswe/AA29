// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"

UGUIListBox::UGUIListBox()
{
	//DefaultListClass = "XInterface.GUIList";
}

void UGUIListBox::InitBaseList(UGUIListBase* LocalList)
{
	/*
	if (List == nullptr || List != LocalList && GUIList(LocalList) != None)
	{
		List = GUIList(LocalList);
	}
	List.__OnClick__Delegate = InternalOnClick;
	List.OnClickSound = 1;
	List.__OnDblClick__Delegate = InternalOnDblClick;
	List.__OnChange__Delegate = InternalOnChange;
	InitBaseList(LocalList);
	*/
}

void UGUIListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (DefaultListClass != "")
	{
		List = GUIList(AddComponent(DefaultListClass));
		if (List == nullptr)
		{
			Log(Class $ ".InitComponent - Could not create default list [" $ DefaultListClass $ "]");
			Return;
		}
	}
	if (List == nullptr)
	{
		Warn("Could not initialize list!");
		Return;
	}
	InitBaseList(List);
	*/
}

bool UGUIListBox::InternalOnClick(UGUIComponent* Sender)
{
	/*
	List.InternalOnClick(Sender);
	OnClick(Self);
	*/
	return true;
}

bool UGUIListBox::InternalOnDblClick(UGUIComponent* Sender)
{
	return true;
}

void UGUIListBox::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Controller != None && Controller.bCurMenuInitialized)
	{
		OnChange(Self);
	}
	*/
}

int32 UGUIListBox::ItemCount()
{
	//Return List.ItemCount;
	return 0;   //FAKE   /EliZ
}

bool UGUIListBox::MyOpen(UGUIContextMenu* Menu)
{
	//Return HandleContextMenuOpen(Self, Menu, Menu.MenuOwner);
	return false;   //FAKE   /EliZ
}

bool UGUIListBox::MyClose(UGUIContextMenu* Sender)
{
	//Return HandleContextMenuClose(Sender);
	return false;   //FAKE   /EliZ
}
