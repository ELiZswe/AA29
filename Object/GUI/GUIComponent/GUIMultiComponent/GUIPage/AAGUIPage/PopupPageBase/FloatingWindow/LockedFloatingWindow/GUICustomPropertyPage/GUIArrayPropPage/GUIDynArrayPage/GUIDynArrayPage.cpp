// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/GUICustomPropertyPage/GUIArrayPropPage/GUIDynArrayPage/GUIDynArrayPage.h"

UGUIDynArrayPage::UGUIDynArrayPage()
{
	NewText = "New";
	RemoveText = "Remove";
}

void UGUIDynArrayPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	li_Values.__OnAdjustTop__Delegate = InternalOnAdjustTop;
	SizingCaption = RemoveText;
	*/
}

void UGUIDynArrayPage::InitializeList()
{
	/*
	int32 i = 0;
	float AW = 0;
	float AL = 0;
	float Y = 0;
	if (!li_Values.bPositioned)
	{
		return;
	}
	bListInitialized = true;
	if (Item.RenderType == 0)
	{
		MOType = "XInterface.moCheckBox";
	}
	else
	{
		if (Item.RenderType == 1)
		{
			MOType = "XInterface.moComboBox";
		}
	}
	AW = li_Values.ActualWidth();
	AL = li_Values.ActualLeft();
	Clear();
	for (i = 0; i < PropValue.Length; i++)
	{
		AddListItem(i);
	}
	ArrayButton.Length = li_Values.ItemsPerPage;
	Y = li_Values.ClientBounds[1];
	for (i = 0; i < li_Values.ItemsPerPage; i++)
	{
		ArrayButton[i] = AddButton(i);
		ArrayButton[i].b_New.WinLeft = ArrayButton[i].b_New.RelativeLeft(((AL + AW) + 5));
		ArrayButton[i].b_Remove.WinLeft = ArrayButton[i].b_New.WinLeft;
		ArrayButton[i].b_New.WinTop = ArrayButton[i].b_New.RelativeTop(Y);
		ArrayButton[i].b_Remove.WinTop = ArrayButton[i].b_Remove.RelativeTop(Y);
		Y += li_Values.ItemHeight;
	}
	UpdateListCaptions();
	UpdateListValues();
	UpdateButtons();
	RemapComponents();
	*/
}

FArrayControl UGUIDynArrayPage::AddButton(int32 Index)
{
	FArrayControl AC;
	/*
	AC.b_New = GUIButton(AddComponent("XInterface.GUIButton", true));
	AC.b_New.TabOrder = (Index + 1);
	AC.b_New.Tag = Index;
	AC.b_New.__OnClick__Delegate = InternalOnClick;
	AC.b_New.Caption = NewText;
	AC.b_New.SizingCaption = SizingCaption;
	AC.b_Remove = GUIButton(AddComponent("XInterface.GUIButton", true));
	AC.b_Remove.TabOrder = (Index + 1);
	AC.b_Remove.Tag = Index;
	AC.b_Remove.__OnClick__Delegate = InternalOnClick;
	AC.b_Remove.Caption = RemoveText;
	AC.b_Remove.SizingCaption = SizingCaption;
	*/
	return AC;
}

void UGUIDynArrayPage::Clear()
{
	/*
	int32 i = 0;
	for (i = 0; i < ArrayButton.Length; i++)
	{
		RemoveComponent(ArrayButton[i].b_New, true);
		RemoveComponent(ArrayButton[i].b_Remove, true);
	}
	ArrayButton.remove(0, ArrayButton.Length);
	Super::Clear();
	RemapComponents();
	*/
}

void UGUIDynArrayPage::UpdateButtons()
{
	/*
	int32 i = 0;
	int32 j = 0;
	j = li_Values.Top;
	for (i = 0; i < ArrayButton.Length; i++)
	{
		SetElementState(i, ((j == li_Values.Elements.Length) && (j < (li_Values.Top + li_Values.ItemsPerPage))), ((j < li_Values.Elements.Length) && (j < (li_Values.Top + li_Values.ItemsPerPage))));
		SetElementCaption(i, j);
		j++;
	}
	*/
}

void UGUIDynArrayPage::SetElementState(int32 Index, bool bNewOn, bool bRemoveOn)
{
	/*
	if ((Index < 0) || (Index >= ArrayButton.Length))
	{
		return;
	}
	ArrayButton[Index].b_New.TabOrder = (Index + 1);
	ArrayButton[Index].b_Remove.TabOrder = (Index + 1);
	if (ArrayButton[Index].b_New.bVisible != bNewOn)
	{
		ArrayButton[Index].b_New.SetVisibility(bNewOn);
	}
	if (ArrayButton[Index].b_Remove.bVisible != bRemoveOn)
	{
		ArrayButton[Index].b_Remove.SetVisibility(bRemoveOn);
	}
	if (bNewOn)
	{
		EnableComponent(ArrayButton[Index].b_New);
	}
	else
	{
		DisableComponent(ArrayButton[Index].b_New);
	}
	if (bRemoveOn)
	{
		EnableComponent(ArrayButton[Index].b_Remove);
	}
	else
	{
		DisableComponent(ArrayButton[Index].b_Remove);
	}
	*/
}

void UGUIDynArrayPage::SetElementCaption(int32 ButtonArrayIndex, int32 ListElementIndex)
{
	/*
	ArrayButton[ButtonArrayIndex].b_New.Caption = NewText;
	ArrayButton[ButtonArrayIndex].b_New.Tag = ListElementIndex;
	ArrayButton[ButtonArrayIndex].b_Remove.Caption = RemoveText;
	ArrayButton[ButtonArrayIndex].b_Remove.Tag = ListElementIndex;
	*/
}

bool UGUIDynArrayPage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	int32 i = 0;
	if (Super::InternalOnClick(Sender))
	{
		return true;
	}
	if (GUIButton(Sender) != None)
	{
		i = 0;
		if (i < ArrayButton.Length)
		{
			if (Sender == ArrayButton[i].b_New)
			{
				PropValue.insert(ArrayButton[i].b_New.Tag, 1);
				AddListItem(ArrayButton[i].b_New.Tag).SetFocus(None);
			}
			else
			{
				if (Sender == ArrayButton[i].b_Remove)
				{
					if ((ArrayButton[i].b_Remove.Tag != -1) && (ArrayButton[i].b_Remove.Tag < li_Values.Elements.Length))
					{
						li_Values.RemoveItem(ArrayButton[i].b_Remove.Tag);
						PropValue.remove(ArrayButton[i].b_Remove.Tag, 1);
					}
				}
				else
				{
					i++;
				}
			}
		}
		if (i < ArrayButton.Length)
		{
			UpdateListCaptions();
			UpdateButtons();
			RemapComponents();
		}
	}
	*/
	return false;
}

void UGUIDynArrayPage::InternalOnAdjustTop(UGUIComponent* Sender)
{
	/*
	UpdateButtons();
	li_Values.InternalOnAdjustTop(Sender);
	*/
}

bool UGUIDynArrayPage::FloatingPreDraw(UCanvas* C)
{
	/*
	float XL = 0;
	float YL = 0;
	float XL2 = 0;
	float YL2 = 0;
	if (bInit)
	{
		b_OK.Style.TextSize(C, 0, NewText, XL, YL, 1);
		b_OK.Style.TextSize(C, 0, RemoveText, XL2, YL2, 1);
		if (XL > XL2)
		{
			SizingCaption = NewText;
		}
		else
		{
			SizingCaption = RemoveText;
		}
	}
	return Super::FloatingPreDraw(C);
	*/
	return false;    //FAKE   /ELiZ
}