// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUITreeListBox/GUITreeListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIVertScrollBar/GUITreeScrollBar/GUITreeScrollBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUITreeList/GUITreeList.h"

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
	if (List == nullptr || List != LocalList && GUITreeList(LocalList) != nullptr)
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
			Log(Class + ".InitComponent - Could not create default list [" + DefaultListClass + "]");
			return;
		}
	}
	if (List == nullptr)
	{
		Warn("Could not initialize list!");
		return;
	}
	InitBaseList(List);
	*/
}

bool UGUITreeListBox::InternalOnClick(UGUIComponent* Sender)
{
	/*
	List.InternalOnClick(Sender);
	OnClick(this);
	*/
	return true;
}

void UGUITreeListBox::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Controller != nullptr && Controller.bCurMenuInitialized)
	{
		OnChange(this);
	}
	*/
}

bool UGUITreeListBox::InternalDblClick(UGUIComponent* Sender)
{
	/*
	List.InternalDblClick(Sender);
	OnDblClick(this);
	*/
	return true;
}

int32 UGUITreeListBox::ItemCount()
{
	//return List.ItemCount;
	return 0;    //FAKE   /EliZ
}

bool UGUITreeListBox::MyOpen(UGUIContextMenu* Menu)
{
	//return HandleContextMenuOpen(this, Menu, Menu.MenuOwner);
	return false;     //FAKE   /EliZ
}

bool UGUITreeListBox::MyClose(UGUIContextMenu* Sender)
{
	//return HandleContextMenuClose(Sender);
	return false;     //FAKE   /EliZ
}
