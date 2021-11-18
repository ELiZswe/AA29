// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/AAExitPage/AALogoutPage/AALogoutPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAALogoutPage::UAALogoutPage()
{
	UGUIButton* cLogoutButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	cLogoutButton->Caption = "LOGOUT";
	cLogoutButton->FontScale = EFontScale::FNS_Small;
	cLogoutButton->WinTop = 0.65;
	cLogoutButton->WinLeft = 0.15;
	cLogoutButton->WinWidth = 0.15;
	cLogoutButton->WinHeight = 0.086;
	cLogoutButton->TabOrder = 2;
	cLogoutButton->bBoundToParent = true;
	cLogoutButton->bScaleToParent = true;
	//cLogoutButton->OnClick=AALogoutPage.InternalOnClick;
	//cLogoutButton->OnKeyEvent=cLogoutButton.InternalOnKeyEvent;
	UGUILabel* cLogoutDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	cLogoutDesc->Caption = "Or do you want to Log Out or Switch Accounts?";
	cLogoutDesc->TextAlign = ETextAlign::TXTA_Center;
	cLogoutDesc->TextColor = FColor(0, 180, 220, 255);
	cLogoutDesc->TextFont = "AAFontHeader";
	cLogoutDesc->WinTop = 0.3;
	cLogoutDesc->WinHeight = 32;
	cLogoutDesc->RenderWeight = 4;
	cLogoutDesc->bBoundToParent = true;
	cLogoutDesc->bScaleToParent = true;
	LogoutButton = cLogoutButton;
	LogoutDesc = cLogoutDesc;
	LoginText = "LOGIN";
	LogoutText = "LOGOUT";
	LoginDescriptionText = "Or do you want to Log In?";
	LogoutDescriptionText = "Or do you want to Log Out or Switch Accounts?";
	//OnKeyEvent = AALogoutPage.InternalOnKeyEvent;
}

void UAALogoutPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	ExitButton.WinLeft = 0.425;
	CancelButton.WinLeft = 0.7;
	ExitDesc.WinTop = 0.2;
	if (AAGUIController(Controller).bLoggedIn)
	{
		LogoutButton.Caption = LogoutText;
		LogoutDesc.Caption = LogoutDescriptionText;
	}
	else
	{
		LogoutButton.Caption = LoginText;
		LogoutDesc.Caption = LoginDescriptionText;
	}
	*/
}

bool UAALogoutPage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == LogoutButton)
	{
		Controller.OpenMenu("AGP_Interface.AAPreLoginPage");
		AAGUIController(Controller).bLoggedIn = false;
	}
	return Super::InternalOnClick(Sender);
	*/
	return false;    //FAKE     ELiZ
}

bool UAALogoutPage::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if (State == 3)
	{
		if (Key == 11)
		{
			InternalOnClick(CancelButton);
		}
		else
		{
			if (Key == 13)
			{
				InternalOnClick(LogoutButton);
			}
		}
	}
	*/
	return false;
}