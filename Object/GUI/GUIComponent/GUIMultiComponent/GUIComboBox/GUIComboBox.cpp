// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIVertScrollButton/GUIComboButton/GUIComboButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"

UGUIComboBox::UGUIComboBox()
{
	UGUIEditBox* EditBox1 = NewObject<UGUIEditBox>(UGUIEditBox::StaticClass());
	EditBox1->bNeverScale = true;
	//EditBox1->OnActivate=EditBox1.InternalActivate;
	//EditBox1->OnDeActivate=EditBox1.InternalDeactivate;
	//EditBox1->OnKeyType=EditBox1.InternalOnKeyType;
	//EditBox1->OnKeyEvent=EditBox1.InternalOnKeyEvent;
	UGUIListBox* ListBox1 = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	//ListBox1->OnCreateComponent=ListBox1.InternalOnCreateComponent;
	ListBox1->StyleName = "ComboListBox";
	ListBox1->RenderWeight = 0.7;
	ListBox1->bTabStop = false;
	ListBox1->bVisible = false;
	ListBox1->bNeverScale = true;
	UGUIComboButton* ShowList = NewObject<UGUIComboButton>(UGUIComboButton::StaticClass());
	ShowList->RenderWeight = 0.6;
	ShowList->bNeverScale = true;
	//ShowList->OnKeyEvent=ShowList.InternalOnKeyEvent;
	UGUIToolTip* GUIComboBoxToolTip = NewObject<UGUIToolTip>(UGUIToolTip::StaticClass());
	MaxVisibleItems = 8;
	Index = -1;
	Edit = EditBox1;
	MyShowListBtn = ShowList;
	MyListBox = ListBox1;
	PropagateVisibility = true;
	WinHeight = 0.06;
	bAcceptsInput = true;
	ToolTip = GUIComboBoxToolTip;
	//OnKeyEvent = GUIComboBox.InternalOnKeyEvent;


}


void UGUIComboBox::OnShowList()
{
}

void UGUIComboBox::OnHideList()
{
}

void UGUIComboBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	List = MyListBox.List;
	List.__OnChange__Delegate = ItemChanged;
	List.bHotTrack = True;
	List.bHotTrackSound = False;
	List.OnClickSound = 1;
	List.__OnClick__Delegate = InternalListClick;
	List.__OnInvalidate__Delegate = InternalOnInvalidate;
	List.TextAlign = 0;
	MyListBox.Hide();
	Edit.__OnChange__Delegate = TextChanged;
	Edit.__OnMousePressed__Delegate = InternalEditPressed;
	Edit.IniOption = IniOption;
	Edit.IniDefault = IniDefault;
	Edit.bReadOnly = bReadOnly;
	List.__OnDeActivate__Delegate = InternalListDeActivate;
	MyShowListBtn.__OnClick__Delegate = ShowListBox;
	MyShowListBtn.FocusInstead = List;
	SetHint(Hint);
	*/
}

void UGUIComboBox::SetHint(FString NewHint)
{
	/*
	SetHint(NewHint);
	MyShowListBtn.SetHint(NewHint);
	Edit.SetHint(NewHint);
	*/
}

bool UGUIComboBox::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	local Interactions.EInputKey iKey;
	if (State == 3)
	{
		iKey = Key;
		if (iKey == 40 && Controller.ShiftPressed)
		{
			ShowListBox(Self);
			return true;
		}
		if (iKey == 13 && !bReadOnly && !bValueReadOnly && bIgnoreChangeWhenTyping && TextStr != Edit.GetText())
		{
			TextStr = Edit.TextStr;
			OnChange(Self);
		}
	}
	*/
	return false;
}

void UGUIComboBox::InternalListDeActivate()
{
	/*
	if (bDebugging)
	{
		Log(Name @ "ListDeactivate Edit.bPendingFocus: " $ Edit.bPendingFocus);
	}
	if (!Edit.bPendingFocus)
	{
		HideListBox();
	}
	*/
}

void UGUIComboBox::InternalOnInvalidate(UGUIComponent* Who)
{
	/*
	if (bDebugging)
	{
		Log(Name @ "Invalidate Who:" $ Who);
	}
	if (Who != Controller.ActivePage)
	{
		Return;
	}
	Edit.SetFocus(None);
	HideListBox();
	*/
}

void UGUIComboBox::InternalEditPressed(UGUIComponent* Sender, bool bRepeat)
{
	/*
	if (bDebugging)
	{
		Log(Name @ "EditPressed MyListBox.bVisible:" @ MyListBox.bVisible);
	}
	if (Edit.bReadOnly && !bRepeat)
	{
		if (!MyListBox.bVisible)
		{
			Controller.bIgnoreNextRelease = True;
			ShowListBox(Self);
		}
		else
		{
			HideListBox();
		}
	}
	Return;
	*/
}

bool UGUIComboBox::InternalListClick(UGUIComponent* Sender)
{
	/*
	if (bDebugging)
	{
		Log(Name @ "ListClick");
	}
	if (!bValueReadOnly)
	{
		List.InternalOnClick(Sender);
	}
	Edit.SetFocus(None);
	HideListBox();
	*/
	return true;
}

void UGUIComboBox::InternalOnSaveINI(UGUIComponent* Sender)
{
	//Return OnSaveINI(Sender);
}

void UGUIComboBox::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	//OnLoadINI(Sender, S);
}

void UGUIComboBox::HideListBox()
{
	/*
	if (bDebugging)
	{
		Log(Name @ "HideListBox");
	}
	OnHideList();
	if (Controller != None)
	{
		MyShowListBtn.Graphic = Controller.ImageList[7];
	}
	MyListBox.Hide();
	List.SilentSetIndex(List.FindIndex(TextStr));
	*/
}

void UGUIComboBox::SetVisibility(bool bIsVisible)
{
	/*
	local bool bTemp;
	SetVisibility(bIsVisible);
	bTemp = bDebugging;
	bDebugging = False;
	HideListBox();
	MyShowListBtn.SetVisibility(bIsVisible);
	Edit.SetVisibility(bIsVisible);
	bDebugging = bTemp;
	*/
}

bool UGUIComboBox::ShowListBox(UGUIComponent* Sender)
{
	/*
	if (bDebugging)
	{
		Log(Name @ "ShowListBox MyListBox.bVisible:" $ MyListBox.bVisible);
	}
	OnShowList();
	MyListBox.SetVisibility(!MyListBox.bVisible);
	if (MyListBox.bVisible)
	{
		MyShowListBtn.Graphic = Controller.ImageList[2];
	}
	else
	{
		MyShowListBtn.Graphic = Controller.ImageList[7];
	}
	if (MyListBox.bVisible)
	{
		List.SetFocus(None);
		List.SetTopItem(List.Index);
	}
	*/
	return true;
}

void UGUIComboBox::ItemChanged(UGUIComponent* Sender)
{
	/*
	Index = List.Index;
	SetText(List.Get());
	if (!bReadOnly && !bValueReadOnly && bIgnoreChangeWhenTyping)
	{
		TextStr = Edit.TextStr;
		OnChange(Self);
	}
	*/
}

void UGUIComboBox::TextChanged(UGUIComponent* Sender)
{
	/*
	if (bValueReadOnly)
	{
		Edit.TextStr = TextStr;
	}
	else
	{
		if (bReadOnly || !bIgnoreChangeWhenTyping)
		{
			TextStr = Edit.TextStr;
			OnChange(Self);
		}
	}
	*/
}

void UGUIComboBox::SetText(FString NewText,bool bListItemsOnly)
{
	/*
	local int i;
	i = List.FindIndex(NewText);
	if (bReadOnly || bListItemsOnly && i < 0)
	{
		Return;
	}
	Edit.SetText(NewText);
	TextStr = Edit.TextStr;
	*/
}

void UGUIComboBox::SetExtra(FString NewExtra,bool bListItemsOnly)
{
	/*
	local int i;
	i = FindExtra(NewExtra);
	if (bReadOnly || bListItemsOnly && i < 0)
	{
		Return;
	}
	Edit.SetText(List.getItemAtIndex(i));
	*/
}

void UGUIComboBox::Get()
{
	//Return Edit.GetText();
}

void UGUIComboBox::GetText()
{
	//Return Get();
}

void UGUIComboBox::GetObject()
{
	/*
	local FString Temp;
	Temp = List.Get();
	if (Temp ~= Edit.GetText())
	{
		Return List.GetObject();
	}
	Return None;
	*/
}

FString UGUIComboBox::GetExtra()
{
	/*
	local FString Temp;
	Temp = List.Get();
	if (Temp ~= Edit.GetText())
	{
		Return List.GetExtra();
	}
	*/
	return "";
}

void UGUIComboBox::SetIndex(int32 i)
{
	//List.SetIndex(i);
}

void UGUIComboBox::GetIndex()
{
	//Return List.Index;
}

void UGUIComboBox::addItem(FString Item,UObject* Extra, FString str)
{
	//List.Add(Item, Extra, str);
}

void UGUIComboBox::RemoveItem(int32 Item,int32 Count)
{
	//List.Remove(Item, Count);
}

void UGUIComboBox::GetItem(int32 aIndex)
{
	//Return List.getItemAtIndex(aIndex);
}

void UGUIComboBox::GetItemObject(int32 aIndex)
{
	//Return List.GetObjectAtIndex(aIndex);
}

void UGUIComboBox::Find(FString Text,bool bExact,bool bExtra)
{
	//Return List.Find(Text, bExact, bExtra);
}

void UGUIComboBox::FindExtra(FString Text,bool bExact)
{
	//Return List.FindExtra(Text, bExact);
}

void UGUIComboBox::FindIndex(FString Test,bool bExact,bool bExtra,UObject* obj)
{
	//Return List.FindIndex(Test, bExact, bExtra, obj);
}

void UGUIComboBox::ItemCount()
{
	//Return List.ItemCount;
}

void UGUIComboBox::ReadOnly(bool B)
{
	//Edit.bReadOnly = B;
}

void UGUIComboBox::InternalOnMousePressed(UGUIComponent* Sender, bool bRepeat)
{
	/*
	if (!bRepeat)
	{
		if (bDebugging)
		{
			Log(Name @ "MousePressed");
		}
		ShowListBox(Sender);
	}
	*/
}

void UGUIComboBox::Clear()
{
	/*
	List.Clear();
	if (bReadOnly)
	{
		Edit.SetText("");
	}
	TextStr = "";
	Index = -1;
	*/
}

void UGUIComboBox::CenterMouse()
{
	/*
	if (MyShowListBtn != None)
	{
		MyShowListBtn.CenterMouse();
	}
	else
	{
		CenterMouse();
	}
	*/
}

void UGUIComboBox::SetFriendlyLabel(UGUILabel* NewLabel)
{
	/*
	SetFriendlyLabel(NewLabel);
	if (Edit != None)
	{
		Edit.SetFriendlyLabel(NewLabel);
	}
	if (MyShowListBtn != None)
	{
		MyShowListBtn.SetFriendlyLabel(NewLabel);
	}
	if (MyListBox != None)
	{
		MyListBox.SetFriendlyLabel(NewLabel);
	}
	*/
}

void UGUIComboBox::LoseFocus(UGUIComponent* Sender)
{
	/*
	if (bDebugging)
	{
		Log(Name @ "LoseFocus  Sender:" $ Sender);
	}
	LoseFocus(Sender);
	*/
}

bool UGUIComboBox::FocusFirst(UGUIComponent* Sender)
{
	/*
	if (Edit != None)
	{
		HideListBox();
		Edit.SetFocus(None);
		return true;
	}
	if (bAcceptsInput)
	{
		SetFocus(None);
		return true;
	}
	*/
	return false;
}

bool UGUIComboBox::FocusLast(UGUIComponent* Sender)
{
	/*
	if (Edit != None)
	{
		HideListBox();
		Edit.SetFocus(None);
		return true;
	}
	if (bAcceptsInput)
	{
		SetFocus(None);
		return true;
	}
	*/
	return false;
}