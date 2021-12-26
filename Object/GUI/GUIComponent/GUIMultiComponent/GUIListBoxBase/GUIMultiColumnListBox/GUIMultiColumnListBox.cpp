// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiColumnListHeader/GUIMultiColumnListHeader.h"

UGUIMultiColumnListBox::UGUIMultiColumnListBox()
{
	UGUIMultiColumnListHeader* MyHeader = NewObject<UGUIMultiColumnListHeader>(UGUIMultiColumnListHeader::StaticClass());
	Header = MyHeader;
	bDisplayHeader = true;
	//DefaultListClass = "Xinterface.GUIMultiColumnList";
	bRequiresStyle = true;
}

void UGUIMultiColumnListBox::InitBaseList(UGUIListBase* LocalList)
{
	/*
	if (List == nullptr || List != LocalList && GUIMultiColumnList(LocalList) != None)
	{
		List = GUIMultiColumnList(LocalList);
	}
	if (ColumnHeadings.Length > 0)
	{
		List.ColumnHeadings = ColumnHeadings;
	}
	Header.MyList = List;
	InitBaseList(LocalList);
	*/
}

void UGUIMultiColumnListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (DefaultListClass != "")
	{
		List = GUIMultiColumnList(AddComponent(DefaultListClass));
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
	if (bFullHeightStyle)
	{
		List.Style = nullptr;
	}
	*/
}

void UGUIMultiColumnListBox::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	local int i;
	if (GUIMultiColumnList(Sender) != None)
	{
		if (HeaderColumnPerc.Length == GUIMultiColumnList(Sender).InitColumnPerc.Length)
		{
			GUIMultiColumnList(Sender).InitColumnPerc = HeaderColumnPerc;
		}
		else
		{
			if (GUIMultiColumnList(Sender).InitColumnPerc.Length == 0)
			{
				GUIMultiColumnList(Sender).InitColumnPerc.Length = HeaderColumnPerc.Length;
			}
			i = 0;
			if (i < HeaderColumnPerc.Length && i < GUIMultiColumnList(Sender).InitColumnPerc.Length)
			{
				GUIMultiColumnList(Sender).InitColumnPerc[i] = HeaderColumnPerc[i];
				i++;
			}
		}
	}
	*/
}

void UGUIMultiColumnListBox::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (GUIMultiColumnList(NewComp) != None)
	{
		GUIMultiColumnList(NewComp).__OnColumnSized__Delegate = InternalOnColumnSized;
		NewComp.IniOption = "@Internal";
		NewComp.__OnLoadINI__Delegate = InternalOnLoadINI;
	}
	InternalOnCreateComponent(NewComp, Sender);
	*/
}
void UGUIMultiColumnListBox::InternalOnColumnSized(int32 Column)
{
	//HeaderColumnPerc[Column] = List.ColumnWidths[Column] / ActualWidth();
}