// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIStateButtonGroup/GUIStateButtonGroup.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIStateButton/GUIStateButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"

UGUIStateButtonGroup::UGUIStateButtonGroup()
{
	bVisible = false;
	bNeverFocus = true;
}

void UGUIStateButtonGroup::OnSelectionChanged(int32 NewIndex)
{
}

void UGUIStateButtonGroup::AddButton(UGUIStateButton* Button)
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

void UGUIStateButtonGroup::Clear()
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

bool UGUIStateButtonGroup::ButtonClick(UGUIComponent* Sender)
{
	UGUIStateButton* B = nullptr;
	int32 i = 0;
	B = Cast<UGUIStateButton>(Sender);
	/*
	if ((B == nullptr) || (SelectedButton == B))
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

void UGUIStateButtonGroup::SetSelection(UGUIStateButton* B)
{
	/*
	if ((B == nullptr) && (Buttons.Num() > 0))
	{
		B = Buttons[0];
	}
	ButtonClick(B);
	*/
}

UGUIStateButton* UGUIStateButtonGroup::GetSelection()
{
	return SelectedButton;
}

FString UGUIStateButtonGroup::GetSelectionExtra()
{
	return SelectedButton->ExtraData;
}
