// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moFloatEdit/moFloatEdit.h"

UmoFloatEdit::UmoFloatEdit()
{
	MinValue = -9999;
	MaxValue = 9999;
	Step = 0.1;
	ComponentClassName = "XInterface.GUIFloatEdit";
}

void UmoFloatEdit::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyNumericEdit = GUIFloatEdit(MyComponent);
	MyNumericEdit.MinValue = MinValue;
	MyNumericEdit.MaxValue = MaxValue;
	MyNumericEdit.Step = Step;
	MyNumericEdit.CalcMaxLen();
	MyNumericEdit.SetReadOnly(bValueReadOnly);
	*/
}

void UmoFloatEdit::SetComponentValue(FString NewValue, bool bNoChange)
{
	/*
	if (bNoChange)
	{
		bIgnoreChange = true;
	}
	SetValue(float(NewValue));
	bIgnoreChange = false;
	*/
}

FString UmoFloatEdit::GetComponentValue()
{
	//return string(GetValue());
	return "FAKE";    //FAKE /ELiZ
}

void UmoFloatEdit::SetValue(float V)
{
	//MyNumericEdit.SetValue(V);
}

float UmoFloatEdit::GetValue()
{
	//return float(MyNumericEdit.Value);
	return 0;    //FAKE   /ELiZ
}

void UmoFloatEdit::Setup(float NewMin, float NewMax, float NewStep)
{
	/*
	MinValue = NewMin;
	MaxValue = NewMax;
	Step = NewStep;
	MyNumericEdit.MinValue = MinValue;
	MyNumericEdit.MaxValue = MaxValue;
	MyNumericEdit.Step = Step;
	MyNumericEdit.MyEditBox.bIncludeSign = (NewMin < 0);
	MyNumericEdit.CalcMaxLen();
	SetValue(FClamp(GetValue(), MinValue, MaxValue));
	*/
}

void UmoFloatEdit::SetReadOnly(bool B)
{
	/*
	Super::SetReadOnly(B);
	MyNumericEdit.SetReadOnly(B);
	*/
}
