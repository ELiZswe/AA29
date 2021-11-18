// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIImageStateButtonGroup/GUIImageStateButtonGroup.h"

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
	if (Button == None)
	{
		Return;
	}
	Buttons[Buttons.Length] = Button;
	Button.__OnClick__Delegate = ButtonClick;
	*/
}

void UGUIImageStateButtonGroup::Clear()
{
	/*
	local int i;
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
		Buttons[i] = None;
	}
	if (Buttons.Length > 0)
	{
		Buttons.remove(0, Buttons.Length);
	}
	*/
}

bool UGUIImageStateButtonGroup::ButtonClick(UGUIComponent* Sender)
{
	/*
	local GUIImageStateButton B;
	local int i;
	B = GUIImageStateButton(Sender);
	if (B == None || SelectedButton == B)
	{
		return true;
	}
	B.SetSelected(True);
	SelectedButton = B;
	for (i = 0; i < Buttons.Length; i++)
	{
		if (Buttons[i] != B)
		{
			Buttons[i].SetSelected(False);
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
	if (B == None && Buttons.Length > 0)
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

void UGUIImageStateButtonGroup::GetSelectionExtra()
{
	//Return SelectedButton.ExtraData;
}
