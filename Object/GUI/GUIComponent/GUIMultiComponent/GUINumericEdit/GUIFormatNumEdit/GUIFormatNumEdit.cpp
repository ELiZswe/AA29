// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUINumericEdit/GUIFormatNumEdit/GUIFormatNumEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUIFormatNumEdit::UGUIFormatNumEdit()
{

}

FString UGUIFormatNumEdit::FormatValue(int32 NewValue)
{
	//return "$ " + FString::FromInt(NewValue);
	return "FAKE";    //FAKE   /ELiZ
}

void UGUIFormatNumEdit::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyEditBox.__OnActivate__Delegate = FormatToValue;
	MyEditBox.__OnDeActivate__Delegate = ValueToFormat;
	MySpinner.bNeverFocus = false;
	MySpinner.FocusInstead = nullptr;
	*/
}

void UGUIFormatNumEdit::CalcMaxLen()
{
}

void UGUIFormatNumEdit::EditOnChange(UGUIComponent* Sender)
{
}

void UGUIFormatNumEdit::ValidateValue()
{
}

void UGUIFormatNumEdit::ValueToFormat()
{
	/*
	if (!bUnformated)
	{
		return;
	}
	SetValue(int(MyEditBox.GetText()));
	*/
}

void UGUIFormatNumEdit::FormatToValue()
{
	/*
	MyEditBox.SetText(Value);
	bUnformated = true;
	*/
}

void UGUIFormatNumEdit::SetValue(int32 V)
{
	/*
	if (V < MinValue)
	{
		V = MinValue;
	}
	if (V > MaxValue)
	{
		V = MaxValue;
	}
	Value = FString::FromInt(V);
	MyEditBox.SetText(FormatValue(int(Value)));
	bUnformated = false;
	OnChange(this);
	*/
}

bool UGUIFormatNumEdit::SpinnerPlusClick(UGUIComponent* Sender)
{
	int32 V = 0;
	/*
	V = (int(Value) + Step);
	SetValue(V);
	*/
	return true;
}

bool UGUIFormatNumEdit::SpinnerMinusClick(UGUIComponent* Sender)
{
	int32 V = 0;
	/*
	V = (int(Value) - Step);
	SetValue(V);
	*/
	return true;
}
