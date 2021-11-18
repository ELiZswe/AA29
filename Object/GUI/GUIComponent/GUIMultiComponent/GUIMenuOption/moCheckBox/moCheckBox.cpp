// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUICheckBoxButton/GUICheckBoxButton.h"

UmoCheckBox::UmoCheckBox()
{
	bSquare = true;
	CaptionWidth = 0.8;
	ComponentClassName = "XInterface.GUICheckBoxButton";
}


void UmoCheckBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local GUIStyles S;
	Super::InitComponent(MyController, MyOwner);
	MyCheckBox = GUICheckBoxButton(MyComponent);
	MyCheckBox.__OnChange__Delegate = ButtonChecked;
	MyCheckBox.__OnClick__Delegate = InternalClick;
	S = Controller.GetStyle(CheckStyleName, MyCheckBox.FontScale);
	if (S != None)
	{
		MyCheckBox.Graphic = S.Images[0];
	}
	*/
}

void UmoCheckBox::SetComponentValue(FString NewValue, bool bNoChange)
{
	/*
	if (bNoChange)
	{
		bIgnoreChange = true;
	}
	Checked(bool(NewValue));
	bIgnoreChange = false;
	*/
}

FString UmoCheckBox::GetComponentValue()
{
	return (IsChecked() ? "true" : "false");
}

void UmoCheckBox::ResetComponent()
{
	MyCheckBox->SetChecked(false);
}

bool UmoCheckBox::IsChecked()
{
	return MyCheckBox->bChecked;
}

bool UmoCheckBox::Checked(bool C)
{
	//MyCheckBox.SetChecked(C);
	return true;
}

void UmoCheckBox::ButtonChecked(UGUIComponent* Sender)
{
	/*
	if (Sender == MyCheckBox)
	{
		InternalOnChange(Self);
	}
	*/
}

bool UmoCheckBox::InternalClick(UGUIComponent* Sender)
{
	/*
	if (bValueReadOnly)
	{
		return true;
	}
	return MyCheckBox.InternalOnClick(Sender);
	*/
	return false;    //FAKE   /ELiZ
}