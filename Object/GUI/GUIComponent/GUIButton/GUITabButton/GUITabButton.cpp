// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIButton/GUITabButton/GUITabButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/GUITabPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"

UGUITabButton::UGUITabButton()
{
	StyleName = "TabButton";
	WinHeight = 0.075;
	bBoundToParent = true;
	bNeverFocus = true;
	OnClickSound = EClickSound::CS_Edit;
}

void UGUITabButton::SetFocus(UGUIComponent* Who)
{
}

bool UGUITabButton::ChangeActiveState(bool IsActive, bool bFocusPanel)
{
	if (MyPanel == nullptr)
	{
		return false;
	}
	if (IsActive)
	{
		if (!CanShowPanel())
		{
			return false;
		}
		MyPanel->ShowPanel(true);
		if (bFocusPanel)
		{
			if (!MyPanel->FocusFirst(nullptr))
			{
				MyPanel->ShowPanel(bActive);
				return false;
			}
			bActive = true;
			return true;
		}
		bActive = true;
		return true;
	}
	MyPanel->ShowPanel(false);
	bActive = false;
	return true;
}

bool UGUITabButton::CanShowPanel()
{
	if ((MenuState == EMenuState::MSAT_Disabled) || (MyPanel == nullptr))
	{
		return false;
	}
	return MyPanel->CanShowPanel();
}
