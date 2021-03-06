// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIImageStateButtonGroup/GUIImageStateButtonGroup.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIImageStateButton/GUIImageStateButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"

UGUIImageStateButtonGroup::UGUIImageStateButtonGroup()
{
	bVisible = false;
	bNeverFocus = true;
}

void UGUIImageStateButtonGroup::OnSelectionChanged(int32 NewIndex)
{
}

void UGUIImageStateButtonGroup::AddButton(UGUIImageStateButton* Button)
{
	/*
	if (Button == nullptr)
	{
		return;
	}
	Buttons[Buttons.Num()] = Button;
	Button.__OnClick__Delegate = ButtonClick;
	*/
}

void UGUIImageStateButtonGroup::Clear()
{
	/*
	int32 i = 0;
	for (i = 0; i < Buttons.Num(); i++)
	{
		if (Cast<UGUIMultiComponent>(Buttons[i].MenuOwner) != nullptr)
		{
			GUIMultiComponent(Buttons[i].MenuOwner).RemoveComponent(Buttons[i]);
		}
		else
		{
			Buttons[i].Free();
		}
		Buttons[i] = nullptr;
	}
	if (Buttons.Num() > 0)
	{
		Buttons.RemoveAt(0, Buttons.Num());
	}
	*/
}

bool UGUIImageStateButtonGroup::ButtonClick(UGUIComponent* Sender)
{
	UGUIImageStateButton* B = nullptr;
	int32 i = 0;
	B = Cast<UGUIImageStateButton>(Sender);
	/*
	if (B == nullptr || SelectedButton == B)
	{
		return true;
	}
	B.SetSelected(true);
	SelectedButton = B;
	for (i = 0; i < Buttons.Num(); i++)
	{
		if (Buttons[i] != B)
		{
			Buttons[i].SetSelected(false);
		}
		else
		{
			OnSelectionChanged(i);
		}
	}
	*/
	return true;
}

void UGUIImageStateButtonGroup::SetSelection(UGUIImageStateButton* B)
{
	/*
	if (B == nullptr && Buttons.Num() > 0)
	{
		B = Buttons[0];
	}
	ButtonClick(B);
	*/
}

UGUIImageStateButton* UGUIImageStateButtonGroup::GetSelection()
{
	return SelectedButton;
}

FString UGUIImageStateButtonGroup::GetSelectionExtra()
{
	return SelectedButton->ExtraData;
}
