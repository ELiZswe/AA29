// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUITreeListBox/GUITreeListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIVertScrollBar/GUITreeScrollBar/GUITreeScrollBar.h"

UGUITreeListBox::UGUITreeListBox()
{
	UGUITreeScrollBar* TreeScrollbar = NewObject<UGUITreeScrollBar>(UGUITreeScrollBar::StaticClass());
	TreeScrollbar->bVisible = false;
	//TreeScrollbar->OnPreDraw=TreeScrollbar.GripPreDraw;
	DefaultListClass = "XInterface.GUITreeList";
	MyScrollBar =TreeScrollbar;
}

void UGUITreeListBox::InitBaseList(UGUIListBase* LocalList)
{
	/*
	if (List == nullptr || List != LocalList && GUITreeList(LocalList) != None)
	{
		List = GUITreeList(LocalList);
	}
	List.__OnClick__Delegate = InternalOnClick;
	List.OnClickSound = 1;
	List.__OnChange__Delegate = InternalOnChange;
	List.__OnDblClick__Delegate = InternalDblClick;
	InitBaseList(LocalList);
	*/
}

void UGUITreeListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (DefaultListClass != "")
	{
		List = GUITreeList(AddComponent(DefaultListClass));
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

bool UGUITreeListBox::InternalOnClick(UGUIComponent* Sender)
{
	/*
	List.InternalOnClick(Sender);
	OnClick(Self);
	*/
	return true;
}

void UGUITreeListBox::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Controller != None && Controller.bCurMenuInitialized)
	{
		OnChange(Self);
	}
	*/
}

bool UGUITreeListBox::InternalDblClick(UGUIComponent* Sender)
{
	/*
	List.InternalDblClick(Sender);
	OnDblClick(Self);
	*/
	return true;
}

int32 UGUITreeListBox::ItemCount()
{
	//Return List.ItemCount;
	return 0;    //FAKE   /EliZ
}

bool UGUITreeListBox::MyOpen(UGUIContextMenu* Menu)
{
	//Return HandleContextMenuOpen(Self, Menu, Menu.MenuOwner);
	return false;     //FAKE   /EliZ
}

bool UGUITreeListBox::MyClose(UGUIContextMenu* Sender)
{
	//Return HandleContextMenuClose(Sender);
	return false;     //FAKE   /EliZ
}
