// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAMissionCompletePageJavelinTraining_LF/AAMissionCompletePageJavelinT_LF.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAMissionCompletePageJavelinT_LF::UAAMissionCompletePageJavelinT_LF()
{
	UGUIButton* DontSaveandCancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DontSaveandCancelButton->Caption = "QUIT TRAINING";
	DontSaveandCancelButton->Hint = "Quit to the main interface, discarding current results.";
	DontSaveandCancelButton->WinTop = 0.67;
	DontSaveandCancelButton->WinLeft = 0.55;
	DontSaveandCancelButton->WinWidth = 0.3;
	//DontSaveandCancelButton->OnClick=AAMissionCompletePageJavelinTraining_LF.InternalOnClick;
	//DontSaveandCancelButton->OnKeyEvent=DontSaveandCancelButton.InternalOnKeyEvent;
	UGUIButton* SaveAndTryAgainButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SaveAndTryAgainButton->Caption = "SAVE & TRY AGAIN";
	SaveAndTryAgainButton->Hint = "Upload your results and restart this training exercise.";
	SaveAndTryAgainButton->WinTop = 0.77;
	SaveAndTryAgainButton->WinLeft = 0.15;
	SaveAndTryAgainButton->WinWidth = 0.3;
	//SaveAndTryAgainButton->OnClick=AAMissionCompletePageJavelinTraining_LF.InternalOnClick;
	//SaveAndTryAgainButton->OnKeyEvent=SaveAndTryAgainButton.InternalOnKeyEvent;
	UGUIButton* DontSaveandTryAgainButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DontSaveandTryAgainButton->Caption = "RESTART TRAINING";
	DontSaveandTryAgainButton->Hint = "Restart this training exercise without uploading your results.";
	DontSaveandTryAgainButton->WinTop = 0.77;
	DontSaveandTryAgainButton->WinLeft = 0.55;
	DontSaveandTryAgainButton->WinWidth = 0.3;
	//DontSaveandTryAgainButton->OnClick=AAMissionCompletePageJavelinTraining_LF.InternalOnClick;
	//DontSaveandTryAgainButton->OnKeyEvent=DontSaveandTryAgainButton.InternalOnKeyEvent;
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "SAVE RESULTS";
	OkButton->Hint = "Upload your results.";
	OkButton->WinTop = 0.67;
	OkButton->WinLeft = 0.15;
	OkButton->WinWidth = 0.3;
	//OkButton->OnClick=AAMissionCompletePageJavelinTraining_LF.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUILabel* CheatText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CheatText->TextAlign = ETextAlign::TXTA_Center;
	CheatText->bMultiLine = true;
	CheatText->StyleName = "TextLabel";
	CheatText->WinTop = 0.48;
	CheatText->WinLeft = 0.04375;
	CheatText->WinWidth = 0.9125;
	CheatText->WinHeight = 0.126524;
	b_DontSaveAndCancel = DontSaveandCancelButton;
	b_DontSaveAndTryAgain = DontSaveandTryAgainButton;
	b_SaveAndTryAgain = SaveAndTryAgainButton;
	b_CheatText = CheatText;
	b_OK = OkButton;
	WinTop = 0.2;
	WinLeft = 0;
	WinWidth = 1;
	WinHeight = 0.6;
}

void UAAMissionCompletePageJavelinT_LF::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	bAuthContacted = false;
	b_OK.TabOrder = 0;
	b_DontSaveAndCancel.TabOrder = 1;
	b_DontSaveAndTryAgain.TabOrder = 2;
	Super::InitComponent(MyController, MyOwner);
	b_OK.bBoundToParent = true;
	b_OK.bStandardized = true;
	b_OK.bScaleToParent = true;
	b_DontSaveAndTryAgain.bBoundToParent = true;
	b_DontSaveAndTryAgain.bStandardized = true;
	b_DontSaveAndTryAgain.bScaleToParent = true;
	b_SaveAndTryAgain.bBoundToParent = true;
	b_SaveAndTryAgain.bStandardized = true;
	b_SaveAndTryAgain.bScaleToParent = true;
	b_DontSaveAndCancel.bBoundToParent = true;
	b_DontSaveAndCancel.bStandardized = true;
	b_DontSaveAndCancel.bScaleToParent = true;
	if (HumanController(PlayerOwner()).bMissionPass == false)
	{
		l_Text2.Caption = "Click \"TRY AGAIN\" to try again or \"QUIT TRAINING\" to return to the main menu.";
		b_DontSaveAndTryAgain.Caption = "TRY AGAIN";
		b_OK.DisableMe();
	}
	if (StudentController(PlayerOwner()).bUsedCheats)
	{
		b_OK.DisableMe();
		b_SaveAndTryAgain.DisableMe();
		b_CheatText.Caption = "Cannot authorize due to use of player cheats.";
	}
	*/
}

bool UAAMissionCompletePageJavelinT_LF::InternalOnClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_SaveAndTryAgain:
		bTryAgain = true;
		OK();
		return true;
	case b_OK:
		OK();
		return true;
	case b_DontSaveAndCancel:
		CancelAndDontSave();
		return true;
	case b_DontSaveAndTryAgain:
		DontSaveAndTryAgain();
		return true;
	default:
		return true;
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool UAAMissionCompletePageJavelinT_LF::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((State == 3) && (Key == 11))
	{
		CancelAndDontSave();
	}
	return Super::InternalOnKeyEvent(Key, State, Delta);
	*/
	return false;    //FAKE   /ELiZ
}

void UAAMissionCompletePageJavelinT_LF::HandleObject(UObject* obj, UObject* OptionalObj_1, UObject* OptionalObj_2)
{
	/*
	if (Material(obj) != None)
	{
		i_Medal.Image = Material(obj);
	}
	Super::HandleObject(obj, OptionalObj_1, OptionalObj_2);
	*/
}

FString UAAMissionCompletePageJavelinT_LF::GetDataString()
{
	return l_Text2->Caption;
}

void UAAMissionCompletePageJavelinT_LF::SetDataString(FString str)
{
	l_Text2->Caption = str;
	//Super::SetDataString(str);
}

void UAAMissionCompletePageJavelinT_LF::OK()
{
	/*
	b_OK.DisableMe();
	b_DontSaveAndCancel.DisableMe();
	b_DontSaveAndTryAgain.DisableMe();
	b_SaveAndTryAgain.DisableMe();
	l_Text.Caption = "Saving Your Mission Results";
	l_Text2.Caption = "Updating Personnel Jacket On Server, Please Wait...";
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

void UAAMissionCompletePageJavelinT_LF::Timer()
{
	/*
	if (bAuthContacted == false)
	{
		if (HumanController(PlayerOwner()).iAuthClientTransmissionComplete != 0)
		{
			switch (HumanController(PlayerOwner()).iAuthClientTransmissionComplete)
			{
			case 1:
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
				b_DontSaveAndTryAgain.EnableMe();
				b_DontSaveAndCancel.EnableMe();
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
			l_Text.Caption = "Restarting Mission";
			l_Text2.Caption = "Please wait while the mission restarts.";
			PlayerOwner().ConsoleCommand("reconnect");
		}
		else
		{
			PlayerOwner().ConsoleCommand("disconnect");
		}
		Controller.CloseMenu();
	}
	*/
}

void UAAMissionCompletePageJavelinT_LF::CancelAndDontSave()
{
	l_Text->Caption = "Returning To Main Menu";
	l_Text2->Caption = "Please wait while we return to the main menu";
	//PlayerOwner().ConsoleCommand("disconnect");
	//Controller.CloseMenu();
}

void UAAMissionCompletePageJavelinT_LF::DontSaveAndTryAgain()
{
	l_Text->Caption = "Restarting Mission";
	l_Text2->Caption = "Please wait while the mission restarts.";
	//PlayerOwner().ConsoleCommand("reconnect");
}