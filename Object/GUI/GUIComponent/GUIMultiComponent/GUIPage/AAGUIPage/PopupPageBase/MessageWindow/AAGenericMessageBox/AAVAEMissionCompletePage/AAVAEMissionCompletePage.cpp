// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAVAEMissionCompletePage/AAVAEMissionCompletePage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAVAEMissionCompletePage::UAAVAEMissionCompletePage()
{
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "SAVE RESULTS";
	OkButton->Hint = "Save your results to your Personnel Jacket and return to the main menu..";
	OkButton->WinTop = 0.67;
	OkButton->WinLeft = 0.4;
	OkButton->WinWidth = 0.2;
	//OkButton->OnClick=AAVAEMissionCompletePage.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUILabel* CheatText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CheatText->TextAlign = ETextAlign::TXTA_Center;
	CheatText->bMultiLine = true;
	CheatText->StyleName = "TextLabel";
	CheatText->WinTop = 0.48;
	CheatText->WinLeft = 0.04375;
	CheatText->WinWidth = 0.9125;
	CheatText->WinHeight = 0.126524;
	b_CheatText = CheatText;
	b_OK = OkButton;
	WinTop = 0.2;
	WinLeft = 0;
	WinWidth = 1;
	WinHeight = 0.6;
}

void UAAVAEMissionCompletePage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	bAuthContacted = false;
	b_OK.TabOrder = 0;
	Super::InitComponent(MyController, MyOwner);
	b_OK.bBoundToParent = true;
	b_OK.bStandardized = true;
	b_OK.bScaleToParent = true;
	l_Text.Caption = "Saving Your Mission Results";
	OK();
	b_OK.Hint = "Upload changes.";
	*/
}

bool UAAVAEMissionCompletePage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_OK:
		OK();
		return true;
	default:
		return true;
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool UAAVAEMissionCompletePage::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((State == 3) && (Key == 11))
	{
		Cancel();
	}
	return Super::InternalOnKeyEvent(Key, State, Delta);
	*/
	return false;    //FAKE   /ELiZ
}

void UAAVAEMissionCompletePage::HandleObject(UObject* obj, UObject* OptionalObj_1, UObject* OptionalObj_2)
{
	/*
	if (Material(obj) != None)
	{
		i_Medal.Image = Material(obj);
	}
	Super::HandleObject(obj, OptionalObj_1, OptionalObj_2);
	*/
}

FString UAAVAEMissionCompletePage::GetDataString()
{
	return l_Text2->Caption;
}

void UAAVAEMissionCompletePage::SetDataString(FString str)
{
	l_Text2->Caption = str;
	//Super::SetDataString(str);
}

void UAAVAEMissionCompletePage::OK()
{
	/*
	b_OK.DisableMe();
	l_Text.Caption = "Saving Your Mission Results";
	l_Text2.Caption = "Updating Personnel Jacket On Server, Please Wait...";
	Log("AAMissionCompletePage.OK() self ->" $ string(Self));
	iAuthDelDotCounter = 0;
	bAuthContacted = false;
	HumanController(PlayerOwner()).SendMissionComplete(19, 0);
	SetTimer(0.25, true);
	*/
}

void UAAVAEMissionCompletePage::Timer()
{
	/*
	if (bAuthContacted == false)
	{
		if (HumanController(PlayerOwner()).iAuthClientTransmissionComplete != 0)
		{
			Log("AAMissionCompletePage.Timer() - auth client transmission detected as complete: " $ string(HumanController(PlayerOwner()).iAuthClientTransmissionComplete));
			switch (HumanController(PlayerOwner()).iAuthClientTransmissionComplete)
			{
			case 1:
				Log("AAMissionCompletePage.TransmissionComplete.BeginState()");
				l_Text.Caption = "Your Personnel Jacket Has Been Updated";
				l_Text2.Caption = "You will return to the main menu in just a moment.";
				bAuthContacted = true;
				KillTimer();
				SetTimer(2, true);
				break;
			default:
				b_OK.Caption = "RETRY SAVE";
				b_OK.EnableMe();
				Log("Failure connecting to server for VAE data: " $ HumanController(PlayerOwner()).sAuthClientTransmissionText);
				KillTimer();
				PlayerOwner().ConsoleCommand("disconnect");
				Controller.CloseMenu();
				break;
			}
		}
		else
		{
			l_Text2.Caption = "Updating Personnel Jacket On Server, Please Wait...|";
			switch ((float(iAuthDelDotCounter++) % 4))
			{
			case 0:
				l_Text2.Caption = l_Text2.Caption $ "\\";
				break;
			case 1:
				l_Text2.Caption = l_Text2.Caption $ "-";
				break;
			case 2:
				l_Text2.Caption = l_Text2.Caption $ "/";
				break;
			case 3:
				l_Text2.Caption = l_Text2.Caption $ "-";
				break;
			default:
			}
		}
	}
	else
	{
		PlayerOwner().ConsoleCommand("disconnect");
		Controller.CloseMenu();
	}
	*/
}

void UAAVAEMissionCompletePage::Cancel()
{
	l_Text->Caption = "Returning To Main Menu";
	l_Text2->Caption = "Please wait while we return to the main menu";
	//PlayerOwner().ConsoleCommand("disconnect");
	//Controller.CloseMenu();
}

void UAAVAEMissionCompletePage::Retry()
{
	l_Text->Caption = "Restarting Mission";
	l_Text2->Caption = "Please wait while the mission restarts.";
	//PlayerOwner().ConsoleCommand("reconnect");
}