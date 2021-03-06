// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/GUICustomPropertyPage/GUIArrayPropPage/GUIArrayPropPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUISectionBackground/AltSectionBackground/AltSectionBackground.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiOptionListBox/GUIMultiOptionListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiOptionList/GUIMultiOptionList.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moFloatEdit/moFloatEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "Engine/Canvas.h"

UGUIArrayPropPage::UGUIArrayPropPage()
{
	UAltSectionBackground* Bk1 = NewObject<UAltSectionBackground>(UAltSectionBackground::StaticClass());
	Bk1->LeftPadding = 0.01;
	Bk1->RightPadding = 0.15;
	Bk1->WinTop = 0.095833;
	Bk1->WinLeft = 0.04375;
	Bk1->WinWidth = 0.7625;
	Bk1->WinHeight = 0.575;
	//Bk1->OnPreDraw=Bk1.InternalPreDraw;
	UGUIMultiOptionListBox* ValueListBox = NewObject<UGUIMultiOptionListBox>(UGUIMultiOptionListBox::StaticClass());
	ValueListBox->bVisibleWhenEmpty = true;
	//ValueListBox->OnCreateComponent=GUIArrayPropPage.InternalOnCreateComponent;
	ValueListBox->WinTop = 0.140209;
	ValueListBox->WinLeft = 0.02125;
	ValueListBox->WinWidth = 0.865001;
	ValueListBox->WinHeight = 0.714452;
	ValueListBox->TabOrder = 0;
	ValueListBox->bBoundToParent = true;
	ValueListBox->bScaleToParent = true;
	//ValueListBox->OnChange=GUIArrayPropPage.InternalOnChange;
	MOType = "XInterface.moEditBox";
	lb_Values = ValueListBox;
	ButtonStyle = "SquareButton";
	sb_Bk1 = Bk1;
	//OnCreateComponent = GUIArrayPropPage.InternalOnCreateComponent;
	WinTop = 0.145833;
	WinLeft = 0.090429;
	WinWidth = 0.842773;
	WinHeight = 0.75;
}

void UGUIArrayPropPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	li_Values = lb_Values->List;
	sb_Main->bVisible = false;
	sb_Bk1->ManageComponent(lb_Values);
}

void UGUIArrayPropPage::SetOwner(UGUIComponent* NewOwner)
{
	FString str = "";
	Super::SetOwner(NewOwner);
	/*
	PropName = Item.DisplayName;
	t_WindowTitle.Caption = PropName;
	str = Item.Value;
	strip(str, "(");
	strip(str, ")");
	if (Delim == "")
	{
		Delim = ",";
	}
	if (Left(str, 1) == "\"")
	{
		Delim = "\"" + Delim + "\"";
	}
	strip(str, "\"");
	Split(str, Delim, PropValue);
	*/
}

void UGUIArrayPropPage::SetReadOnly(bool bValue)
{
	//bReadOnly = bValue;
}

bool UGUIArrayPropPage::GetReadOnly()
{
	return bReadOnly;
}

FString UGUIArrayPropPage::GetDataString()
{
	FString Result = "";
	/*
	Result = JoinArray(PropValue, Delim);
	if (Left(Delim, 1) == "\"")
	{
		Result = "\"" + Result + "\"";
	}
	Result = "(" + Result + ")";
	*/
	return Result;
}

bool UGUIArrayPropPage::InternalOnPreDraw(UCanvas* C)
{
	/*
	if (!bListInitialized)
	{
		InitializeList();
	}
	return Super::InternalOnPreDraw(C);
	*/
	return false;    //FAKE    /EliZ
}

void UGUIArrayPropPage::InitializeList()
{
	/*
	int32 i = 0;
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
	Clear();
	for (i = 0; i < PropValue.Num(); i++)
	{
		AddListItem(i);
	}
	UpdateListCaptions();
	UpdateListValues();
	*/
}

UGUIMenuOption* UGUIArrayPropPage::AddListItem(int32 Index)
{
	UGUIMenuOption* mo=nullptr;
	/*
	mo = li_Values.InsertItem(Index, MOType, , FString::FromInt((Index + 1)) + ":");
	mo.CaptionWidth = 0.05;
	mo.ComponentWidth = 0.95;
	mo.bAutoSizeCaption = true;
	mo.SetReadOnly(bReadOnly);
	SetItemOptions(mo);
	*/
	return mo;
}

void UGUIArrayPropPage::Clear()
{
	//li_Values.Clear();
}

void UGUIArrayPropPage::UpdateListCaptions()
{
	/*
	int32 i = 0;
	for (i = 0; i < li_Values.Elements.Num(); i++)
	{
		li_Values.Elements[i].SetCaption(string((i + 1)) + ":");
	}
	*/
}

void UGUIArrayPropPage::UpdateListValues()
{
	/*
	int32 i = 0;
	RemapComponents();
	i = 0;
	if ((i < li_Values.Elements.Num()) && (i < PropValue.Num()))
	{
		li_Values.Elements[i].SetComponentValue(PropValue[i], true);
		i++;
	}
	*/
}

void UGUIArrayPropPage::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (Cast<UGUIMultiOptionList>(NewComp) != nullptr)
	{
		GUIMultiOptionList(NewComp).bDrawSelectionBorder = false;
		GUIMultiOptionList(NewComp).ItemPadding = 0.15;
		if (Sender == lb_Values)
		{
			lb_Values.InternalOnCreateComponent(NewComp, Sender);
		}
	}
	else
	{
		if (Cast<UGUIButton>(NewComp) != nullptr)
		{
			Cast<UGUIButton>(NewComp).StyleName = ButtonStyle;
			Cast<UGUIButton>(NewComp).bAutoSize = true;
		}
	}
	Super::InternalOnCreateComponent(NewComp, Sender);
	*/
}

void UGUIArrayPropPage::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Sender == li_Values)
	{
		if (li_Values.IsValid())
		{
			PropValue[li_Values.Index] = li_Values.Get().GetComponentValue();
		}
	}
	*/
}

int32 UGUIArrayPropPage::GetMaxValue(FString MaxLength)
{
	/*
	int32 i = 0;
	int32 maxl = 0;
	FString str = "";
	if (MaxLength == "")
	{
		return 0;
	}
	maxl = int(MaxLength);
	for (i = 0; i < maxl; i++)
	{
		str += "9";
	}
	return int(str);
	*/

	return 0;   //FAKE   /EliZ
}

void UGUIArrayPropPage::SetItemOptions(UGUIMenuOption* mo)
{
	UmoNumericEdit* nu = nullptr;
	UmoFloatEdit* fl = nullptr;
	UmoEditBox* ed = nullptr;
	FString str = "";
	FString str1 = "";
	FString str2 = "";
	nu = Cast<UmoNumericEdit>(mo);
	fl = Cast<UmoFloatEdit>(mo);
	ed = Cast<UmoEditBox>(mo);
	/*
	if (ed != nullptr)
	{
		if (Item.Data != "")
		{
			ed.MyEditBox.MaxWidth = int(Item.Data);
		}
	}
	else
	{
		if (fl != nullptr)
		{
			if (Item.Data != "")
			{
				if (Divide(Item.Data, ";", str, str1))
				{
					fl.MyNumericEdit.MyEditBox.MaxWidth = int(str);
					if (Divide(str1, ":", str, str2))
					{
						fl.Setup(float(str), float(str2), fl.Step);
					}
				}
				else
				{
					fl.Setup(0, float(GetMaxValue(Item.Data)), fl.Step);
				}
			}
		}
		else
		{
			if (nu != nullptr)
			{
				if (Item.Data != "")
				{
					if (Divide(Item.Data, ";", str, str1))
					{
						nu.MyNumericEdit.MyEditBox.MaxWidth = int(str);
						if (Divide(str1, ":", str, str2))
						{
							nu.Setup(int(str), int(str2), int(fl.Step));
						}
					}
					else
					{
						nu.Setup(0, GetMaxValue(Item.Data), nu.Step);
					}
				}
			}
		}
	}
	*/
}
