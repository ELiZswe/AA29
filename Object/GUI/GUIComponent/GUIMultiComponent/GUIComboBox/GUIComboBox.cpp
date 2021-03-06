// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIVertScrollButton/GUIComboButton/GUIComboButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIScrollButtonBase.h"

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
	List.bHotTrack = true;
	List.bHotTrackSound = false;
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
	EInputKey iKey = EInputKey::IK_None;
	/*
	if (State == 3)
	{
		iKey = Key;
		if (iKey == 40 && Controller.ShiftPressed)
		{
			ShowListBox(this);
			return true;
		}
		if (iKey == 13 && !bReadOnly && !bValueReadOnly && bIgnoreChangeWhenTyping && TextStr != Edit.GetText())
		{
			TextStr = Edit.TextStr;
			OnChange(this);
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
		Log(Name @ "ListDeactivate Edit.bPendingFocus: " + Edit.bPendingFocus);
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
		Log(Name @ "Invalidate Who:" + Who);
	}
	if (Who != Controller.ActivePage)
	{
		return;
	}
	Edit.SetFocus(nullptr);
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
			Controller.bIgnoreNextRelease = true;
			ShowListBox(this);
		}
		else
		{
			HideListBox();
		}
	}
	return;
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
	Edit.SetFocus(nullptr);
	HideListBox();
	*/
	return true;
}

FString UGUIComboBox::InternalOnSaveINI(UGUIComponent* Sender)
{
	return OnSaveINI(Sender);
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
	if (Controller != nullptr)
	{
		MyShowListBtn.Graphic = Controller.ImageList[7];
	}
	MyListBox.Hide();
	List.SilentSetIndex(List.FindIndex(TextStr));
	*/
}

void UGUIComboBox::SetVisibility(bool bIsVisible)
{
	bool bTemp = false;
	/*
	SetVisibility(bIsVisible);
	bTemp = bDebugging;
	bDebugging = false;
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
		Log(Name @ "ShowListBox MyListBox.bVisible:" + MyListBox.bVisible);
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
		List.SetFocus(nullptr);
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
		OnChange(this);
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
			OnChange(this);
		}
	}
	*/
}

void UGUIComboBox::SetText(FString NewText,bool bListItemsOnly)
{
	/*
	int32 i = 0;
	i = List.FindIndex(NewText);
	if (bReadOnly || bListItemsOnly && i < 0)
	{
		return;
	}
	Edit.SetText(NewText);
	TextStr = Edit.TextStr;
	*/
}

void UGUIComboBox::SetExtra(FString NewExtra,bool bListItemsOnly)
{
	/*
	int32 i = 0;
	i = FindExtra(NewExtra);
	if (bReadOnly || bListItemsOnly && i < 0)
	{
		return;
	}
	Edit.SetText(List.getItemAtIndex(i));
	*/
}

FString UGUIComboBox::Get()
{
	return Edit->GetText();
}

FString UGUIComboBox::GetText()
{
	return Get();
}

UObject* UGUIComboBox::GetObject()
{
	FString Temp = "";
	/*
	Temp = List.Get();
	if (Temp ~= Edit.GetText())
	{
		return List.GetObject();
	}
	*/
	return nullptr;
}

FString UGUIComboBox::GetExtra()
{
	FString Temp = "";
	/*
	Temp = List.Get();
	if (Temp ~= Edit.GetText())
	{
		return List.GetExtra();
	}
	*/
	return "";
}

void UGUIComboBox::SetIndex(int32 i)
{
	List->SetIndex(i);
}

int32 UGUIComboBox::GetIndex()
{
	return List->Index;
}

void UGUIComboBox::addItem(FString Item,UObject* Extra, FString str)
{
	List->Add(Item, Extra, str,false);
}

void UGUIComboBox::RemoveItem(int32 Item,int32 Count)
{
	List->Remove(Item, Count,false);
}

FString UGUIComboBox::GetItem(int32 aIndex)
{
	return List->getItemAtIndex(aIndex);
}

UObject* UGUIComboBox::GetItemObject(int32 aIndex)
{
	return List->GetObjectAtIndex(aIndex);
}

FString UGUIComboBox::Find(FString Text,bool bExact,bool bExtra)
{
	return List->Find(Text, bExact, bExtra);
}

int32 UGUIComboBox::FindExtra(FString Text,bool bExact)
{
	return List->FindExtra(Text, bExact);
}

int32 UGUIComboBox::FindIndex(FString Test,bool bExact,bool bExtra,UObject* obj)
{
	return List->FindIndex(Test, bExact, bExtra, obj);
}

int32 UGUIComboBox::ItemCount()
{
	return List->ItemCount;
}

void UGUIComboBox::ReadOnly(bool B)
{
	//Edit.bReadOnly = B;
}

void UGUIComboBox::InternalOnMousePressed(UGUIComponent* Sender, bool bRepeat)
{
	if (!bRepeat)
	{
		if (bDebugging)
		{
			//Log(Name @ "MousePressed");
		}
		ShowListBox(Sender);
	}
}

void UGUIComboBox::Clear()
{
	List->Clear();
	if (bReadOnly)
	{
		//Edit.SetText("");
	}
	TextStr = "";
	Index = -1;
}

void UGUIComboBox::CenterMouse()
{
	/*
	if (MyShowListBtn != nullptr)
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
	if (Edit != nullptr)
	{
		Edit.SetFriendlyLabel(NewLabel);
	}
	if (MyShowListBtn != nullptr)
	{
		MyShowListBtn.SetFriendlyLabel(NewLabel);
	}
	if (MyListBox != nullptr)
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
		Log(Name @ "LoseFocus  Sender:" + Sender);
	}
	LoseFocus(Sender);
	*/
}

bool UGUIComboBox::FocusFirst(UGUIComponent* Sender)
{
	/*
	if (Edit != nullptr)
	{
		HideListBox();
		Edit.SetFocus(nullptr);
		return true;
	}
	if (bAcceptsInput)
	{
		SetFocus(nullptr);
		return true;
	}
	*/
	return false;
}

bool UGUIComboBox::FocusLast(UGUIComponent* Sender)
{
	/*
	if (Edit != nullptr)
	{
		HideListBox();
		Edit.SetFocus(nullptr);
		return true;
	}
	if (bAcceptsInput)
	{
		SetFocus(nullptr);
		return true;
	}
	*/
	return false;
}
