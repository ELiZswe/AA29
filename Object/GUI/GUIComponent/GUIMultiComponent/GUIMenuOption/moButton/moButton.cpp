// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moButton/moButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

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
	MyButton = Cast<UGUIButton>(MyComponent);
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
	InternalOnChange(this);
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
			if (!OnClick(this))
			{
				Controller.OpenMenu(MenuClass, MenuTitle, Value);
			}
			Controller.ActivePage.__OnClose__Delegate = PageClosed;
			return true;
		}
		InternalOnChange(this);
		return true;
	}
	*/
	return false;
}

void UmoButton::PageClosed(bool bCancelled)
{
	/*
	Value = Controller.ActivePage.GetDataString();
	InternalOnChange(this);
	*/
}

void UmoButton::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	Super::InternalOnCreateComponent(NewComp, Sender);
	NewComp.StyleName = ButtonStyleName;
	*/
}
