// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAMissionCompletePage/AAMissionCompletePage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAMissionCompletePage::UAAMissionCompletePage()
{
	UGUIButton* RetryButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	RetryButton->Caption = "RETRY MISSION";
	RetryButton->Hint = "Retry the mission.";
	RetryButton->WinTop = 0.67;
	RetryButton->WinLeft = 0.15;
	RetryButton->WinWidth = 0.2;
	//RetryButton->OnClick=AAMissionCompletePage.InternalOnClick;
	//RetryButton->OnKeyEvent=RetryButton.InternalOnKeyEvent;
	UGUIButton* CancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CancelButton->Caption = "CANCEL";
	CancelButton->Hint = "Close this menu, discarding changes.";
	CancelButton->WinTop = 0.67;
	CancelButton->WinLeft = 0.65;
	CancelButton->WinWidth = 0.2;
	//CancelButton->OnClick=AAMissionCompletePage.InternalOnClick;
	//CancelButton->OnKeyEvent=CancelButton.InternalOnKeyEvent;
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "SAVE RESULTS";
	OkButton->Hint = "Save your results to your Personnel Jacket and return to the main menu..";
	OkButton->WinTop = 0.67;
	OkButton->WinLeft = 0.4;
	OkButton->WinWidth = 0.2;
	//OkButton->OnClick=AAMissionCompletePage.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUILabel* CheatText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CheatText->TextAlign = ETextAlign::TXTA_Center;
	CheatText->bMultiLine = true;
	CheatText->StyleName = "TextLabel";
	CheatText->WinTop = 0.48;
	CheatText->WinLeft = 0.04375;
	CheatText->WinWidth = 0.9125;
	CheatText->WinHeight = 0.126524;
	b_Cancel = CancelButton;
	b_Retry = RetryButton;
	b_CheatText = CheatText;
	b_OK = OkButton;
	WinTop = 0.2;
	WinLeft = 0;
	WinWidth = 1;
	WinHeight = 0.6;
}

void UAAMissionCompletePage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	bAuthContacted = false;
	b_OK.TabOrder = 0;
	b_Cancel.TabOrder = 1;
	Super::InitComponent(MyController, MyOwner);
	b_OK.bBoundToParent = true;
	b_OK.bStandardized = true;
	b_OK.bScaleToParent = true;
	b_Retry.bBoundToParent = true;
	b_Retry.bStandardized = true;
	b_Retry.bScaleToParent = true;
	b_Cancel.bBoundToParent = true;
	b_Cancel.bStandardized = true;
	b_Cancel.bScaleToParent = true;
	b_OK.Hint = "Upload changes.";
	if (HumanController(PlayerOwner()).bMissionPass == false)
	{
		l_Text2.Caption = "Click \"Retry Mission\" to try again or \"Cancel\" to return to the main menu.";
		b_Retry.Caption = "Retry Mission";
		b_OK.DisableMe();
	}
	if (((HumanController(PlayerOwner()).Level.Game.GetScreenplay() != None) && (HumanController(PlayerOwner()).Level.Game.GetScreenplay().bPlayerCheated == true)) && (HumanController(PlayerOwner()).bMissionPass == true))
	{
		b_OK.DisableMe();
		b_CheatText.Caption = "Cannot authorize due to use of player cheats.";
	}
	*/
}

bool UAAMissionCompletePage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_OK:
		OK();
		return true;
	case b_Cancel:
		Cancel();
		return true;
	case b_Retry:
		Retry();
		return true;
	default:
		return true;
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool UAAMissionCompletePage::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
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

void UAAMissionCompletePage::HandleObject(UObject* obj, UObject* OptionalObj_1, UObject* OptionalObj_2)
{
	/*
	if (Material(obj) != None)
	{
		i_Medal.Image = Material(obj);
	}
	Super::HandleObject(obj, OptionalObj_1, OptionalObj_2);
	*/
}

FString UAAMissionCompletePage::GetDataString()
{
	return l_Text2->Caption;
}

void UAAMissionCompletePage::SetDataString(FString str)
{
	/*
	l_Text2.Caption = str;
	Super::SetDataString(str);
	*/
}

void UAAMissionCompletePage::OK()
{
	/*
	b_OK.DisableMe();
	b_Cancel.DisableMe();
	b_Retry.DisableMe();
	l_Text.Caption = "Saving Your Mission Results";
	l_Text2.Caption = "Updating Personnel Jacket On Server, Please Wait...";
	Log("AAMissionCompletePage.OK() self ->" $ string(Self));
	iAuthDelDotCounter = 0;
	bAuthContacted = false;
	HumanController(PlayerOwner()).MissionCompleted();
	if (PlayerOwner().Level.DidPlayerCompleteNewMission(PlayerOwner()) == 1)
	{
		HumanController(PlayerOwner()).VerifyJacket();
		HumanController(PlayerOwner()).SaveJacket();
	}
	else
	{
		HumanController(PlayerOwner()).VerifyJacket();
		HumanController(PlayerOwner()).SaveJacket();
	}
	SetTimer(0.25, true);
	*/
}

void UAAMissionCompletePage::Timer()
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
				b_Cancel.EnableMe();
				l_Text2.Caption = "The server could not be updated.|(Error: " $ HumanController(PlayerOwner()).sAuthClientTransmissionText $ ").|Would you like to try again?";
				KillTimer();
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

void UAAMissionCompletePage::Cancel()
{
	/*
	l_Text.Caption = "Returning To Main Menu";
	l_Text2.Caption = "Please wait while we return to the main menu";
	PlayerOwner().ConsoleCommand("disconnect");
	Controller.CloseMenu();
	*/
}

void UAAMissionCompletePage::Retry()
{
	/*
	l_Text.Caption = "Restarting Mission";
	l_Text2.Caption = "Please wait while the mission restarts.";
	PlayerOwner().ConsoleCommand("reconnect");
	*/
}