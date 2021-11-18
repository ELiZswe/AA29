// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAMissionCompletePageJavelinTraining_BST/AAMissionCompletePageJavelin_BST.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"


UAAMissionCompletePageJavelin_BST::UAAMissionCompletePageJavelin_BST()
{
	UGUIButton* DontSaveandCancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DontSaveandCancelButton->Caption = "QUIT TRAINING";
	DontSaveandCancelButton->Hint = "Quit to the main interface, discarding current results.";
	DontSaveandCancelButton->WinTop = 0.77;
	DontSaveandCancelButton->WinLeft = 0.55;
	DontSaveandCancelButton->WinWidth = 0.3;
	//DontSaveandCancelButton->OnClick=AAMissionCompletePageJavelinTraining_BST.InternalOnClick;
	//DontSaveandCancelButton->OnKeyEvent=DontSaveandCancelButton.InternalOnKeyEvent;
	UGUIButton* DontSaveandTryAgainButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DontSaveandTryAgainButton->Caption = "RESTART TRAINING";
	DontSaveandTryAgainButton->Hint = "Restart this training exercise without saving current results.";
	DontSaveandTryAgainButton->WinTop = 0.67;
	DontSaveandTryAgainButton->WinLeft = 0.55;
	DontSaveandTryAgainButton->WinWidth = 0.3;
	//DontSaveandTryAgainButton->OnClick=AAMissionCompletePageJavelinTraining_BST.InternalOnClick;
	//DontSaveandTryAgainButton->OnKeyEvent=DontSaveandTryAgainButton.InternalOnKeyEvent;
	UGUIButton* DontSaveAndContinueButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DontSaveAndContinueButton->Caption = "CONTINUE";
	DontSaveAndContinueButton->Hint = "Continue Training without saving current results.";
	DontSaveAndContinueButton->WinTop = 0.77;
	DontSaveAndContinueButton->WinLeft = 0.15;
	DontSaveAndContinueButton->WinWidth = 0.3;
	//DontSaveAndContinueButton->OnClick=AAMissionCompletePageJavelinTraining_BST.InternalOnClick;
	//DontSaveAndContinueButton->OnKeyEvent=DontSaveAndContinueButton.InternalOnKeyEvent;
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "SAVE AND CONTINUE";
	OkButton->Hint = "Upload your results.";
	OkButton->WinTop = 0.67;
	OkButton->WinLeft = 0.15;
	OkButton->WinWidth = 0.3;
	//OkButton->OnClick=AAMissionCompletePageJavelinTraining_BST.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUILabel* CheatText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CheatText->TextAlign = ETextAlign::TXTA_Center;
	CheatText->bMultiLine = true;
	CheatText->StyleName = "TextLabel";
	CheatText->WinTop = 0.48;
	CheatText->WinLeft = 0.04375;
	CheatText->WinWidth = 0.9125;
	CheatText->WinHeight = 0.126524;
	b_DontSaveAndContinue = DontSaveAndContinueButton;
	b_DontSaveAndCancel = DontSaveandCancelButton;
	b_DontSaveAndRetry = DontSaveandTryAgainButton;
	b_CheatText = CheatText;
	b_OK = OkButton;
	WinTop = 0.2;
	WinLeft = 0;
	WinWidth = 1;
	WinHeight = 0.6;
}

void UAAMissionCompletePageJavelin_BST::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	bAuthContacted = false;
	b_OK.TabOrder = 0;
	b_DontSaveAndCancel.TabOrder = 1;
	b_DontSaveAndContinue.TabOrder = 2;
	b_DontSaveAndRetry.TabOrder = 3;
	Super::InitComponent(MyController, MyOwner);
	b_OK.bBoundToParent = true;
	b_OK.bStandardized = true;
	b_OK.bScaleToParent = true;
	b_DontSaveAndContinue.bBoundToParent = true;
	b_DontSaveAndContinue.bStandardized = true;
	b_DontSaveAndContinue.bScaleToParent = true;
	b_DontSaveAndRetry.bBoundToParent = true;
	b_DontSaveAndRetry.bStandardized = true;
	b_DontSaveAndRetry.bScaleToParent = true;
	b_DontSaveAndCancel.bBoundToParent = true;
	b_DontSaveAndCancel.bStandardized = true;
	b_DontSaveAndCancel.bScaleToParent = true;
	if (HumanController(PlayerOwner()).bMissionPass == false)
	{
		l_Text2.Caption = "Click \"Retry Mission\" to try again or \"Cancel\" to return to the main menu.";
		b_DontSaveAndRetry.Caption = "Retry Mission";
		b_OK.DisableMe();
	}
	if (StudentController(PlayerOwner()).bUsedCheats)
	{
		b_OK.DisableMe();
		b_DontSaveAndContinue.DisableMe();
		b_CheatText.Caption = "Cannot authorize due to use of player cheats.";
	}
	*/
}

bool UAAMissionCompletePageJavelin_BST::InternalOnClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_OK:
		SaveAndContinue();
		return true;
	case b_DontSaveAndCancel:
		CancelAndDontSave();
		return true;
	case b_DontSaveAndContinue:
		DontSaveAndContinue();
		return true;
	case b_DontSaveAndRetry:
		DontSaveAndTryAgain();
		return true;
	default:
		return true;
		return true;
	}
	*/
	return false;    //FAKE   /EliZ
}

bool UAAMissionCompletePageJavelin_BST::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((State == 3) && (Key == 11))
	{
		DontSaveAndContinue();
	}
	return Super::InternalOnKeyEvent(Key, State, Delta);
	*/
	return false;    //FAKE   /EliZ

}

void UAAMissionCompletePageJavelin_BST::HandleObject(UObject* obj, UObject* OptionalObj_1, UObject* OptionalObj_2)
{
	/*
	if (Material(obj) != None)
	{
		i_Medal.Image = Material(obj);
	}
	Super::HandleObject(obj, OptionalObj_1, OptionalObj_2);
	*/
}

FString UAAMissionCompletePageJavelin_BST::GetDataString()
{
	return l_Text2->Caption;
}

void UAAMissionCompletePageJavelin_BST::SetDataString(FString str)
{
	/*
	l_Text2.Caption = str;
	Super::SetDataString(str);
	*/
}

void UAAMissionCompletePageJavelin_BST::SaveAndContinue()
{
	/*
	b_OK.DisableMe();
	b_DontSaveAndCancel.DisableMe();
	b_DontSaveAndContinue.DisableMe();
	b_DontSaveAndRetry.DisableMe();
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

void UAAMissionCompletePageJavelin_BST::Timer()
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
				l_Text2.Caption = "Please wait while we resume your training";
				KillTimer();
				EL_JavelinTraining(HumanController(PlayerOwner()).EventLab).GotoState('DelayAndCloseSaveAndContinue');
				break;
			default:
				b_OK.Caption = "RETRY SAVE";
				b_OK.EnableMe();
				b_DontSaveAndContinue.EnableMe();
				b_DontSaveAndRetry.EnableMe();
				b_DontSaveAndCancel.EnableMe();
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
	*/
}

void UAAMissionCompletePageJavelin_BST::CancelAndDontSave()
{
	/*
	l_Text.Caption = "Returning To Main Menu";
	l_Text2.Caption = "Please wait while we return to the main menu";
	PlayerOwner().ConsoleCommand("disconnect");
	Controller.CloseMenu();
	*/
}

void UAAMissionCompletePageJavelin_BST::DontSaveAndContinue()
{
	/*
	l_Text.Caption = "Continuing Training";
	l_Text2.Caption = "Please wait while we resume the training";
	EL_JavelinTraining(HumanController(PlayerOwner()).EventLab).bReadyForOpportunity = true;
	HumanController(PlayerOwner()).ClientCloseMenu(true, false);
	*/
}

void UAAMissionCompletePageJavelin_BST::DontSaveAndTryAgain()
{
	/*
	l_Text.Caption = "Restarting Mission";
	l_Text2.Caption = "Please wait while the mission restarts.";
	PlayerOwner().ConsoleCommand("reconnect");
	*/
}