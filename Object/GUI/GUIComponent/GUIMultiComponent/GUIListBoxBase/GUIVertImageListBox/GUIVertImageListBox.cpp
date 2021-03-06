// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIVertImageListBox/GUIVertImageListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertImageList/GUIVertImageList.h"

UGUIVertImageListBox::UGUIVertImageListBox()
{
	ImageScale = 1;
	HorzBorder = 2;
	VertBorder = 2;
	//DefaultListClass = "XInterface.GUIVertImageList";
}

void UGUIVertImageListBox::InitBaseList(UGUIListBase* LocalList)
{
	/*
	List = GUIVertImageList(LocalList);
	List.CellStyle = CellStyle;
	List.ImageScale = ImageScale;
	List.NoVisibleRows = NoVisibleRows;
	List.NoVisibleCols = NoVisibleCols;
	List.HorzBorder = HorzBorder;
	List.VertBorder = VertBorder;
	LocalList.__OnClick__Delegate = InternalOnClick;
	LocalList.OnClickSound = 1;
	LocalList.__OnChange__Delegate = InternalOnChange;
	MyScrollBar.SetVisibility(true);
	MyScrollBar.Step = List.NoVisibleCols;
	InitBaseList(LocalList);
	*/
}

void UGUIVertImageListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (DefaultListClass != "")
	{
		MyList = GUIListBase(AddComponent(DefaultListClass));
		if (MyList == nullptr)
		{
			Log(Class + ".InitComponent - Could not create default list [" + DefaultListClass + "]");
			return;
		}
	}
	if (MyList == nullptr)
	{
		Warn("Could not initialize list!");
		return;
	}
	InitBaseList(MyList);
	*/
}

bool UGUIVertImageListBox::InternalOnClick(UGUIComponent* Sender)
{
	/*
	List.InternalOnClick(Sender);
	OnClick(Sender);
	*/
	return true;
}

void UGUIVertImageListBox::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Controller != nullptr && Controller.bCurMenuInitialized)
	{
		OnChange(this);
	}
	*/
}

int32 UGUIVertImageListBox::ItemCount()
{
	//return List.ItemCount;
	return 0;   //FAKE   /ELiZ
}

void UGUIVertImageListBox::AddImage(UMaterialInstance* Image, int32 Item)
{
	//List.Add(Image, Item);
}

bool UGUIVertImageListBox::MyOpen(UGUIContextMenu* Menu, UGUIComponent* ContextMenuOwner)
{
	//return HandleContextMenuOpen(this, Menu, ContextMenuOwner);
	return false;     //FAKE   /EliZ
}

bool UGUIVertImageListBox::MyClose(UGUIContextMenu* Sender)
{
	//return HandleContextMenuClose(Sender);
	return false;     //FAKE   /EliZ
}

void UGUIVertImageListBox::Clear()
{
	//List.Clear();
}
