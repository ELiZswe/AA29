// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAMissionCompletePageJavelinTraining/AAMissionCompletePageJavelinTrai.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAMissionCompletePageJavelinTrai::UAAMissionCompletePageJavelinTrai()
{
	UGUIButton* ContinueButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ContinueButton->Caption = "CONTINUE";
	ContinueButton->Hint = "Continue Training without saving current results.";
	ContinueButton->WinTop = 0.87;
	ContinueButton->WinLeft = 0.35;
	ContinueButton->WinWidth = 0.3;
	//ContinueButton->OnClick=AAMissionCompletePageJavelinTraining.InternalOnClick;
	//ContinueButton->OnKeyEvent=ContinueButton.InternalOnKeyEvent;
	UGUIButton* SaveAndTryAgainButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SaveAndTryAgainButton->Caption = "SAVE & TRY AGAIN";
	SaveAndTryAgainButton->Hint = "Upload your results and restart this training exercise.";
	SaveAndTryAgainButton->WinTop = 0.77;
	SaveAndTryAgainButton->WinLeft = 0.15;
	SaveAndTryAgainButton->WinWidth = 0.3;
	//SaveAndTryAgainButton->OnClick=AAMissionCompletePageJavelinTraining.InternalOnClick;
	//SaveAndTryAgainButton->OnKeyEvent=SaveAndTryAgainButton.InternalOnKeyEvent;
	UGUIButton* RetryButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	RetryButton->Caption = "RESTART TRAINING";
	RetryButton->Hint = "Restart this training exercise without saving current results.";
	RetryButton->WinTop = 0.77;
	RetryButton->WinLeft = 0.55;
	RetryButton->WinWidth = 0.3;
	//RetryButton->OnClick=AAMissionCompletePageJavelinTraining.InternalOnClick;
	//RetryButton->OnKeyEvent=RetryButton.InternalOnKeyEvent;
	UGUIButton* CancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CancelButton->Caption = "QUIT TRAINING";
	CancelButton->Hint = "Quit to the main interface, discarding current results.";
	CancelButton->WinTop = 0.67;
	CancelButton->WinLeft = 0.55;
	CancelButton->WinWidth = 0.3;
	//CancelButton->OnClick=AAMissionCompletePageJavelinTraining.InternalOnClick;
	//CancelButton->OnKeyEvent=CancelButton.InternalOnKeyEvent;
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "SAVE RESULTS";
	OkButton->Hint = "Upload your results, which will be posted to the Javelin scoreboard.";
	OkButton->WinTop = 0.67;
	OkButton->WinLeft = 0.15;
	OkButton->WinWidth = 0.3;
	//OkButton->OnClick=AAMissionCompletePageJavelinTraining.InternalOnClick;
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
	b_SaveAndTryAgain = SaveAndTryAgainButton;
	b_Continue = ContinueButton;
	b_CheatText = CheatText;
	b_OK = OkButton;
	WinTop = 0.2;
	WinLeft = 0;
	WinWidth = 1;
	WinHeight = 0.6;
}

void UAAMissionCompletePageJavelinTrai::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	bAuthContacted = false;
	b_OK.TabOrder = 0;
	b_Cancel.TabOrder = 1;
	b_Continue.TabOrder = 2;
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
	b_Continue.bBoundToParent = true;
	b_Continue.bStandardized = true;
	b_Continue.bScaleToParent = true;
	b_SaveAndTryAgain.bBoundToParent = true;
	b_SaveAndTryAgain.bStandardized = true;
	b_SaveAndTryAgain.bScaleToParent = true;
	if (HumanController(PlayerOwner()).bMissionPass == false)
	{
		l_Text2.Caption = "Click \"Retry Mission\" to try again or \"Cancel\" to return to the main menu.";
		b_Retry.Caption = "Retry Mission";
		b_OK.DisableMe();
		b_SaveAndTryAgain.DisableMe();
	}
	if ((HumanController(PlayerOwner()).Level.Game.GetScreenplay().bPlayerCheated == true) && (HumanController(PlayerOwner()).bMissionPass == true))
	{
		b_OK.DisableMe();
		b_SaveAndTryAgain.DisableMe();
		b_CheatText.Caption = "Cannot authorize due to use of player cheats.";
	}
	*/
}

bool UAAMissionCompletePageJavelinTrai::InternalOnClick(UGUIComponent* Sender)
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
	case b_Continue:
		ContinueButtonBox();
		return true;
	case b_Retry:
		Retry();
		return true;
	case b_SaveAndTryAgain:
		SaveAndTryAgain();
		return true;
	default:
		return true;
		return true;
	}
	*/

	return false;    //FAKE   /EliZ
}

bool UAAMissionCompletePageJavelinTrai::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((State == 3) && (Key == 11))
	{
		Cancel();
	}
	return Super::InternalOnKeyEvent(Key, State, Delta);
	*/
	return false;    //FAKE   /EliZ
}

void UAAMissionCompletePageJavelinTrai::HandleObject(UObject* obj, UObject* OptionalObj_1, UObject* OptionalObj_2)
{
	/*
	if (Material(obj) != None)
	{
		i_Medal.Image = Material(obj);
	}
	Super::HandleObject(obj, OptionalObj_1, OptionalObj_2);
	*/
}

FString UAAMissionCompletePageJavelinTrai::GetDataString()
{
	return l_Text2->Caption;
}

void UAAMissionCompletePageJavelinTrai::SetDataString(FString str)
{
	/*
	l_Text2.Caption = str;
	Super::SetDataString(str);
	*/
}

void UAAMissionCompletePageJavelinTrai::SaveAndTryAgain()
{
	/*
	bTryAgain = true;
	OK();
	*/
}

void UAAMissionCompletePageJavelinTrai::OK()
{
	/*
	b_OK.DisableMe();
	b_Cancel.DisableMe();
	b_Continue.DisableMe();
	b_Retry.DisableMe();
	b_SaveAndTryAgain.DisableMe();
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

void UAAMissionCompletePageJavelinTrai::Timer()
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
				if (bTryAgain)
				{
					l_Text2.Caption = "You will restart the mission in just a moment.";
				}
				bAuthContacted = true;
				KillTimer();
				SetTimer(2, true);
				break;
			default:
				if (bTryAgain)
				{
					b_SaveAndTryAgain.Caption = "RETRY SAVE";
					b_SaveAndTryAgain.EnableMe();
				}
				else
				{
					b_OK.Caption = "RETRY SAVE";
					b_OK.EnableMe();
				}
				b_Cancel.EnableMe();
				l_Text2.Caption = "The server could not be updated.|(Error: " $ HumanController(PlayerOwner()).sAuthClientTransmissionText $ ").|Would you like to try again?";
				KillTimer();
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
		if (bTryAgain)
		{
			Retry();
		}
		else
		{
			PlayerOwner().ConsoleCommand("disconnect");
		}
		Controller.CloseMenu();
	}
	*/
}

void UAAMissionCompletePageJavelinTrai::Cancel()
{
	/*
	l_Text.Caption = "Returning To Main Menu";
	l_Text2.Caption = "Please wait while we return to the main menu";
	PlayerOwner().ConsoleCommand("disconnect");
	Controller.CloseMenu();
	*/
}

void UAAMissionCompletePageJavelinTrai::ContinueButtonBox()
{
	/*
	l_Text.Caption = "Continuing Training";
	l_Text2.Caption = "Please wait while we resume the training";
	HumanController(PlayerOwner()).ClientCloseMenu(false, false);
	*/
}

void UAAMissionCompletePageJavelinTrai::Retry()
{
	/*
	l_Text.Caption = "Restarting Mission";
	l_Text2.Caption = "Please wait while the mission restarts.";
	PlayerOwner().ConsoleCommand("reconnect");
	*/
}