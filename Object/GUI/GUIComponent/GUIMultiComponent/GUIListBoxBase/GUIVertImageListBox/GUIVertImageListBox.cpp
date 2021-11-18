// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIVertImageListBox/GUIVertImageListBox.h"

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
	MyScrollBar.SetVisibility(True);
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
		if (MyList == None)
		{
			Log(Class $ ".InitComponent - Could not create default list [" $ DefaultListClass $ "]");
			Return;
		}
	}
	if (MyList == None)
	{
		Warn("Could not initialize list!");
		Return;
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
	if (Controller != None && Controller.bCurMenuInitialized)
	{
		OnChange(Self);
	}
	*/
}

void UGUIVertImageListBox::ItemCount()
{
	//Return List.ItemCount;
}

void UGUIVertImageListBox::AddImage(UMaterialInstance* Image, int32 Item)
{
	//List.Add(Image, Item);
}

void UGUIVertImageListBox::MyOpen(UGUIContextMenu* Menu, UGUIComponent* ContextMenuOwner)
{
	//Return HandleContextMenuOpen(Self, Menu, ContextMenuOwner);
}

void UGUIVertImageListBox::MyClose(UGUIContextMenu* Sender)
{
	//Return HandleContextMenuClose(Sender);
}

void UGUIVertImageListBox::Clear()
{
	//List.Clear();
}