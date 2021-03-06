// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUINumericEdit/GUINumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUISpinnerButton/GUISpinnerButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UGUINumericEdit::UGUINumericEdit()
{
	
	UGUIEditBox* cMyEditBox = NewObject<UGUIEditBox>(UGUIEditBox::StaticClass());
	cMyEditBox->bIntOnly=true;
	cMyEditBox->bNeverScale=true;
	//cMyEditBox->OnActivate=cMyEditBox.InternalActivate;
	//cMyEditBox->OnDeActivate=cMyEditBox.InternalDeactivate;
	//cMyEditBox->OnKeyType=cMyEditBox.InternalOnKeyType;
	//cMyEditBox->OnKeyEvent=cMyEditBox.InternalOnKeyEvent;
	UGUISpinnerButton* cMySpinner = NewObject<UGUISpinnerButton>(UGUISpinnerButton::StaticClass());
	cMySpinner->bTabStop=false;
	cMySpinner->bNeverScale=true;
	//cMySpinner->OnClick=cMySpinner.InternalOnClick;
	//cMySpinner->OnKeyEvent=cMySpinner.InternalOnKeyEvent;
	UGUIToolTip* GUINumericEditToolTip = NewObject<UGUIToolTip>(UGUIToolTip::StaticClass());
	
	MyEditBox = cMyEditBox;
	MySpinner = cMySpinner;
	Value = "0";
	MinValue = -9999;
	MaxValue = 9999;
	Step = 1;
	PropagateVisibility = true;
	WinHeight = 0.06;
	bAcceptsInput = true;
	ToolTip = GUINumericEditToolTip;
	//OnDeActivate = GUINumericEdit.ValidateValue;
}

void UGUINumericEdit::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	if (MinValue < 0)
	{
		MyEditBox.bIncludeSign = true;
	}
	Super::InitComponent(MyController, MyOwner);
	MyEditBox.__OnChange__Delegate = EditOnChange;
	MyEditBox.SetText(Value);
	MyEditBox.__OnKeyEvent__Delegate = EditKeyEvent;
	MyEditBox.__OnDeActivate__Delegate = CheckValue;
	CalcMaxLen();
	MyEditBox.IniOption = IniOption;
	MyEditBox.IniDefault = IniDefault;
	MySpinner.bNeverFocus = true;
	MySpinner.FocusInstead = MyEditBox;
	MySpinner.__OnPlusClick__Delegate = SpinnerPlusClick;
	MySpinner.__OnMinusClick__Delegate = SpinnerMinusClick;
	SetReadOnly(bReadOnly);
	SetHint(Hint);
	*/
}

void UGUINumericEdit::CalcMaxLen()
{
	int32 digitcount = 0;
	int32 X = 0;
	digitcount = 1;
	X = 10;
	if (X <= MaxValue)
	{
		digitcount++;
		X *= float(10);
	}
	MyEditBox->MaxWidth = digitcount;
}

void UGUINumericEdit::SetValue(int32 V)
{
	if (V < MinValue)
	{
		V = MinValue;
	}
	if (V > MaxValue)
	{
		V = MaxValue;
	}
	//MyEditBox.SetText(string(Clamp(V, MinValue, MaxValue)));
}

bool UGUINumericEdit::SpinnerPlusClick(UGUIComponent* Sender)
{
	//SetValue((int(Value) + Step));
	return true;
}

bool UGUINumericEdit::SpinnerMinusClick(UGUIComponent* Sender)
{
	//SetValue((int(Value) - Step));
	return true;
}

bool UGUINumericEdit::EditKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((Key == 236) && (State == 3))
	{
		SpinnerPlusClick(nullptr);
		return true;
	}
	if ((Key == 237) && (State == 3))
	{
		SpinnerMinusClick(nullptr);
		return true;
	}
	return MyEditBox.InternalOnKeyEvent(Key, State, Delta);
	*/
	return false;    //FAKE   /ELiZ

}

void UGUINumericEdit::EditOnChange(UGUIComponent* Sender)
{
	/*
	Value = FString::FromInt(Clamp(int(MyEditBox.TextStr), MinValue, MaxValue));
	OnChange(this);
	*/
}

void UGUINumericEdit::SetHint(FString NewHint)
{
	/*
	int32 i = 0;
	Super::SetHint(NewHint);
	for (i = 0; i < Controls.Num(); i++)
	{
		Controls[i].SetHint(NewHint);
	}
	*/
}

void UGUINumericEdit::SetReadOnly(bool B)
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

void UGUINumericEdit::CheckValue()
{
	//SetValue(int(Value));
}

void UGUINumericEdit::SetFriendlyLabel(UGUILabel* NewLabel)
{
	/*
	Super::SetFriendlyLabel(NewLabel);
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

void UGUINumericEdit::ValidateValue()
{
	/*
	int32 i = 0;
	i = int(MyEditBox.TextStr);
	MyEditBox.TextStr = FString::FromInt(Clamp(i, MinValue, MaxValue));
	MyEditBox.bHasFocus = false;
	*/
}
