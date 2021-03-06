// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiColumnListHeader/GUIMultiColumnListHeader.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"

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
	if (List == nullptr || List != LocalList && GUIMultiColumnList(LocalList) != nullptr)
	{
		List = GUIMultiColumnList(LocalList);
	}
	if (ColumnHeadings.Num() > 0)
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
	if (bFullHeightStyle)
	{
		List.Style = nullptr;
	}
	*/
}

void UGUIMultiColumnListBox::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	int32 i = 0;
	if (Cast<UGUIMultiColumnList>(Sender) != nullptr)
	{
		if (HeaderColumnPerc.Num() == GUIMultiColumnList(Sender).InitColumnPerc.Num())
		{
			GUIMultiColumnList(Sender).InitColumnPerc = HeaderColumnPerc;
		}
		else
		{
			if (Cast<UGUIMultiColumnList>(Sender).InitColumnPerc.Num() == 0)
			{
				GUIMultiColumnList(Sender).InitColumnPerc.Num() = HeaderColumnPerc.Num();
			}
			i = 0;
			if (i < HeaderColumnPerc.Num() && i < GUIMultiColumnList(Sender).InitColumnPerc.Num())
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
	if (Cast<UGUIMultiColumnList>(NewComp) != nullptr)
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
