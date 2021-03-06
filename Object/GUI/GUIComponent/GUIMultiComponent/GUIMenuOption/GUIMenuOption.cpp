// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UGUIMenuOption::UGUIMenuOption()
{
	UGUIToolTip* GUIMenuOptionToolTip = NewObject<UGUIToolTip>(UGUIToolTip::StaticClass());
	bAutoSizeCaption = true;
	ComponentJustification = EeTextAlign::TXTA_Right;
	CaptionWidth = 0.5;
	ComponentWidth = -1;
	LabelFont = "UT2MenuFont";
	LabelStyleName = "TextLabel";
	LabelColor = FColor(64, 0, 0, 255);
	PropagateVisibility = true;
	//OnCreateComponent = GUIMenuOption.InternalOnCreateComponent;
	WinTop = 0.347656;
	WinLeft = 0.496094;
	WinWidth = 0.5;
	WinHeight = 0.03;
	bAcceptsInput = true;
	ToolTip = GUIMenuOptionToolTip;
	OnClickSound = EClickSound::CS_Click;
	bStandardized = true;
	StandardHeight = 0.03;
}

void UGUIMenuOption::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	if (bVerticalLayout)
	{
		(StandardHeight *= 2);
	}
	Super::InitComponent(MyController, MyOwner);
	MyLabel = Cast<UGUILabel>(AddComponent("XInterface.GUILabel"));
	if (MyLabel == nullptr)
	{
		Log("Failed to create " @ FString::FromInt(this) @ " due to problems creating GUILabel");
		return;
	}
	if (bFlipped)
	{
		if (LabelJustification == 0)
		{
			LabelJustification = 2;
		}
		else
		{
			if (LabelJustification == 2)
			{
				LabelJustification = 0;
			}
		}
		if (ComponentJustification == 0)
		{
			ComponentJustification = 2;
		}
		else
		{
			if (ComponentJustification == 2)
			{
				ComponentJustification = 0;
			}
		}
	}
	MyLabel.Caption = Caption;
	if (LabelStyleName == "")
	{
		MyLabel.TextColor = LabelColor;
		MyLabel.TextFont = LabelFont;
	}
	else
	{
		MyLabel.Style = Controller.GetStyle(LabelStyleName, MyLabel.FontScale);
	}
	MyLabel.FontScale = FontScale;
	MyLabel.TextAlign = LabelJustification;
	MyLabel.IniOption = IniOption;
	MyLabel.bNeverScale = true;
	if (ComponentClassName == "")
	{
		return;
	}
	MyComponent = AddComponent(ComponentClassName);
	if (MyComponent == nullptr)
	{
		Log("Could not create requested menu component" @ ComponentClassName);
		return;
	}
	SetHint(Hint);
	MyComponent.IniOption = IniOption;
	if (bHeightFromComponent && (!bVerticalLayout))
	{
		WinHeight = MyComponent.WinHeight;
	}
	else
	{
		MyComponent.WinHeight = WinHeight;
	}
	MyComponent.__OnChange__Delegate = InternalOnChange;
	MyComponent.bTabStop = true;
	MyComponent.TabOrder = 1;
	MyComponent.bNeverScale = true;
	MyComponent.bNeverFocus = bNeverFocus;
	SetFriendlyLabel(MyLabel);
	if (MenuState == 4)
	{
		MenuState = 0;
		DisableMe();
	}
	*/
}

void UGUIMenuOption::SetComponentValue(FString NewValue, bool bNoChange)
{
}

FString UGUIMenuOption::GetComponentValue()
{
	return "";
}

void UGUIMenuOption::ResetComponent()
{
	SetComponentValue(IniDefault,false);
}

void UGUIMenuOption::SetReadOnly(bool bValue)
{
	bValueReadOnly = bValue;
}

void UGUIMenuOption::SetHint(FString NewHint)
{
	Super::SetHint(NewHint);
	MyLabel->SetHint(NewHint);
	MyComponent->SetHint(NewHint);
}

void UGUIMenuOption::SetCaption(FString NewCaption)
{
	Caption = NewCaption;
	MyLabel->Caption = NewCaption;
}

bool UGUIMenuOption::MenuOptionClicked(UGUIComponent* Sender)
{
	return true;
}

void UGUIMenuOption::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if ((Controller != nullptr) && Controller.bCurMenuInitialized)
	{
		if (!bIgnoreChange)
		{
			OnChange(this);
		}
	}
	bIgnoreChange = false;
	*/
}

void UGUIMenuOption::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
}

void UGUIMenuOption::CenterMouse()
{
	if (MyComponent != nullptr)
	{
		MyComponent->CenterMouse();
	}
	else
	{
		Super::CenterMouse();
	}
}

void UGUIMenuOption::SetFriendlyLabel(UGUILabel* NewLabel)
{
	//Super::SetFriendlyLabel(NewLabel);
	if (MyComponent != nullptr)
	{
		//MyComponent->SetFriendlyLabel(NewLabel);
	}
}
