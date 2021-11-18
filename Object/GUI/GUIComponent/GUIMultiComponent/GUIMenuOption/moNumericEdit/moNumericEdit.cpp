// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"

UmoNumericEdit::UmoNumericEdit()
{
	MinValue = -9999;
	MaxValue = 9999;
	Step = 1;
	ComponentClassName = "XInterface.GUINumericEdit";
}

void UmoNumericEdit::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyNumericEdit = GUINumericEdit(MyComponent);
	MyNumericEdit.MinValue = MinValue;
	MyNumericEdit.MaxValue = MaxValue;
	MyNumericEdit.Step = Step;
	MyNumericEdit.CalcMaxLen();
	MyNumericEdit.__OnChange__Delegate = InternalOnChange;
	MyNumericEdit.SetReadOnly(bValueReadOnly);
	*/
}

void UmoNumericEdit::SetComponentValue(FString NewValue, bool bNoChange)
{
	/*
	if (bNoChange)
	{
		bIgnoreChange = true;
	}
	SetValue(int(NewValue));
	bIgnoreChange = false;
	*/
}

FString UmoNumericEdit::GetComponentValue()
{
	//return string(GetValue());
	return "FAKE";    //FAKE   /ELiZ
}

void UmoNumericEdit::SetValue(int32 V)
{
	//MyNumericEdit.SetValue(V);
}

int32 UmoNumericEdit::GetValue()
{
	//return int(MyNumericEdit.Value);
	return 0;    //FAKE   /ELiZ
}

void UmoNumericEdit::Setup(int32 NewMin, int32 NewMax, int32 NewStep)
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
	SetValue(Clamp(GetValue(), NewMin, NewMax));
	*/
}

void UmoNumericEdit::SetReadOnly(bool B)
{
	/*
	Super::SetReadOnly(B);
	MyNumericEdit.SetReadOnly(B);
	*/
}