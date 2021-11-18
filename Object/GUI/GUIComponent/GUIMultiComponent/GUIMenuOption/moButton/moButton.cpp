// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moButton/moButton.h"

UmoButton::UmoButton()
{
	ButtonCaption = "Edit";
	ButtonStyleName = "SquareButton";
	CaptionWidth = 0.8;
	ComponentClassName = "XInterface.GUIButton";
	StandardHeight = 0.04;
}


void UmoButton::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyButton = GUIButton(MyComponent);
	MyButton.__OnClick__Delegate = InternalOnClick;
	MyButton.Caption = ButtonCaption;
	*/
}

void UmoButton::SetComponentValue(FString NewValue, bool bNoChange)
{
	/*
	if (bNoChange)
	{
		bIgnoreChange = bNoChange;
	}
	SetValue(NewValue);
	bIgnoreChange = false;
	*/
}

FString UmoButton::GetComponentValue()
{
	return Value;
}

void UmoButton::SetValue(FString NewValue)
{
	/*
	if (Value == NewValue)
	{
		bIgnoreChange = false;
		return;
	}
	Value = NewValue;
	InternalOnChange(Self);
	*/
}

void UmoButton::ResetComponent()
{
	Value = "";
}

bool UmoButton::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == MyButton)
	{
		if (MenuClass != "")
		{
			if (!OnClick(Self))
			{
				Controller.OpenMenu(MenuClass, MenuTitle, Value);
			}
			Controller.ActivePage.__OnClose__Delegate = PageClosed;
			return true;
		}
		InternalOnChange(Self);
		return true;
	}
	*/
	return false;
}

void UmoButton::PageClosed(bool bCancelled)
{
	/*
	Value = Controller.ActivePage.GetDataString();
	InternalOnChange(Self);
	*/
}

void UmoButton::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	Super::InternalOnCreateComponent(NewComp, Sender);
	NewComp.StyleName = ButtonStyleName;
	*/
}