// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIStateButtonGroup/GUIStateButtonGroup.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIStateButton/GUIStateButton.h"

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
	Buttons[Buttons.Length] = Button;
	Button.__OnClick__Delegate = ButtonClick;
	*/
}

void UGUIStateButtonGroup::Clear()
{
	/*
	int32 i = 0;
	for (i = 0; i < Buttons.Length; i++)
	{
		if (GUIMultiComponent(Buttons[i].MenuOwner) != None)
		{
			GUIMultiComponent(Buttons[i].MenuOwner).RemoveComponent(Buttons[i]);
		}
		else
		{
			Buttons[i].Free();
		}
		Buttons[i] = nullptr;
	}
	if (Buttons.Length > 0)
	{
		Buttons.remove(0, Buttons.Length);
	}
	*/
}

bool UGUIStateButtonGroup::ButtonClick(UGUIComponent* Sender)
{
	/*
	local GUIStateButton B;
	int32 i = 0;
	B = GUIStateButton(Sender);
	if ((B == nullptr) || (SelectedButton == B))
	{
		return true;
	}
	B.SetSelected(true);
	SelectedButton = B;
	for (i = 0; i < Buttons.Length; i++)
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
	if ((B == nullptr) && (Buttons.Length > 0))
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
