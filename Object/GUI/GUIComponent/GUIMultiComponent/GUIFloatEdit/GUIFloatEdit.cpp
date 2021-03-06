// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIFloatEdit/GUIFloatEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUISpinnerButton/GUISpinnerButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UGUIFloatEdit::UGUIFloatEdit()
{
	UGUIEditBox* cMyEditBox = NewObject<UGUIEditBox>(UGUIEditBox::StaticClass());
	cMyEditBox->bFloatOnly = true;
	cMyEditBox->bNeverScale = true;
	//cMyEditBox->OnActivate=cMyEditBox.InternalActivate;
	//cMyEditBox->OnDeActivate=cMyEditBox.InternalDeactivate;
	//cMyEditBox->OnKeyType=cMyEditBox.InternalOnKeyType;
	//cMyEditBox->OnKeyEvent=cMyEditBox.InternalOnKeyEvent;
	UGUISpinnerButton* cMySpinner = NewObject<UGUISpinnerButton>(UGUISpinnerButton::StaticClass());
	cMySpinner->bTabStop = false;
	cMySpinner->bNeverScale = true;
	//cMySpinner->OnClick=cMySpinner.InternalOnClick;
	//cMySpinner->OnKeyEvent=cMySpinner.InternalOnKeyEvent;
	UGUIToolTip* GUIFloatEditToolTip = NewObject<UGUIToolTip>(UGUIToolTip::StaticClass());
	MyEditBox = cMyEditBox;
	MySpinner = cMySpinner;

	Value = "0.0";
	MinValue = -9999;
	MaxValue = 9999;
	Step = 0.1;
	PropagateVisibility = true;
	WinHeight = 0.06;
	bAcceptsInput = true;
	ToolTip = GUIFloatEditToolTip;
	//__OnDeActivate__Delegate = "GUIFloatEdit.ValidateValue";
}

void UGUIFloatEdit::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	if (MinValue < 0)
	{
		MyEditBox.bIncludeSign = true;
	}
	InitComponent(MyController, MyOwner);
	MyEditBox.__OnChange__Delegate = EditOnChange;
	MyEditBox.SetText(Value);
	MyEditBox.__OnKeyEvent__Delegate = EditKeyEvent;
	MyEditBox.__OnDeActivate__Delegate = CheckValue;
	MyEditBox.IniOption = IniOption;
	MyEditBox.IniDefault = IniDefault;
	CalcMaxLen();
	MySpinner.bNeverFocus = true;
	MySpinner.FocusInstead = MyEditBox;
	MySpinner.__OnPlusClick__Delegate = SpinnerPlusClick;
	MySpinner.__OnMinusClick__Delegate = SpinnerMinusClick;
	SetReadOnly(bReadOnly);
	SetHint(Hint);
	*/
}

void UGUIFloatEdit::SetHint(FString NewHint)
{
	/*
	int32 i = 0;
	SetHint(NewHint);
	for (i = 0; i < Controls.Num(); i++)
	{
		Controls[i].SetHint(NewHint);
	}
	*/
}

void UGUIFloatEdit::CalcMaxLen()
{
	/*
	int32 digitcount;
	int32 X;
	digitcount = 1;
	X = 10;
	if (X < MaxValue)
	{
		digitcount++;
		X *= 10;
	}
	MyEditBox.MaxWidth = digitcount + 4;
	*/
}

void UGUIFloatEdit::SetValue(float V)
{
	//MyEditBox.SetText(FClamp(V, MinValue, MaxValue));
}

bool UGUIFloatEdit::SpinnerPlusClick(UGUIComponent* Sender)
{
	//SetValue(Value + Step);
	return true;
}

bool UGUIFloatEdit::SpinnerMinusClick(UGUIComponent* Sender)
{
	//SetValue(Value - Step);
	return true;
}

bool UGUIFloatEdit::EditKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if (Key == 236 && State == 3)
	{
		SpinnerPlusClick(nullptr);
		return true;
	}
	if (Key == 237 && State == 3)
	{
		SpinnerMinusClick(nullptr);
		return true;
	}
	return MyEditBox.InternalOnKeyEvent(Key, State, Delta);
	*/
	return false;    //FAKE    /ELiZ
}

void UGUIFloatEdit::CheckValue()
{
	//SetValue(Value);
}

void UGUIFloatEdit::EditOnChange(UGUIComponent* Sender)
{
	/*
	Value =FMath::Clamp(MyEditBox.TextStr, MinValue, MaxValue);
	OnChange(Sender);
	*/
}

void UGUIFloatEdit::SetReadOnly(bool B)
{
	/*
	bReadOnly = B;
	MyEditBox.bReadOnly = B;
	if (B)
	{
		DisableComponent(MySpinner);
	}
	else
	{
		EnableComponent(MySpinner);
	}
	*/
}

void UGUIFloatEdit::SetFriendlyLabel(UGUILabel* NewLabel)
{
	/*
	SetFriendlyLabel(NewLabel);
	if (MyEditBox != nullptr)
	{
		MyEditBox.SetFriendlyLabel(NewLabel);
	}
	if (MySpinner != nullptr)
	{
		MySpinner.SetFriendlyLabel(NewLabel);
	}
	*/
}

void UGUIFloatEdit::ValidateValue()
{
	float F = 0;
	/*
	F = MyEditBox.TextStr;
	MyEditBox.TextStr =FMath::Clamp(F, MinValue, MaxValue);
	MyEditBox.bHasFocus = false;
	*/
}
