// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAMissionCompletePageEx/AAMissionCompletePageEx.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UAAMissionCompletePageEx::UAAMissionCompletePageEx()
{
	UGUIButton* SaveAndTryAgainButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SaveAndTryAgainButton->Caption = "SAVE & TRY AGAIN";
	SaveAndTryAgainButton->Hint = "Upload your results and restart this training exercise.";
	SaveAndTryAgainButton->WinTop = 0.77;
	SaveAndTryAgainButton->WinLeft = 0.15;
	SaveAndTryAgainButton->WinWidth = 0.3;
	//SaveAndTryAgainButton->OnClick=AAMissionCompletePageEx.InternalOnClick;
	//SaveAndTryAgainButton->OnKeyEvent=SaveAndTryAgainButton.InternalOnKeyEvent;
	UGUIButton* RetryButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	RetryButton->Caption = "RESTART TRAINING";
	RetryButton->Hint = "Restart this training exercise without saving current results.";
	RetryButton->WinTop = 0.77;
	RetryButton->WinLeft = 0.55;
	RetryButton->WinWidth = 0.3;
	//RetryButton->OnClick=AAMissionCompletePageEx.InternalOnClick;
	//RetryButton->OnKeyEvent=RetryButton.InternalOnKeyEvent;
	UGUIButton* CancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CancelButton->Caption = "QUIT TRAINING";
	CancelButton->Hint = "Quit to the main interface, discarding current results.";
	CancelButton->WinTop = 0.67;
	CancelButton->WinLeft = 0.55;
	CancelButton->WinWidth = 0.3;
	//CancelButton->OnClick=AAMissionCompletePageEx.InternalOnClick;
	//CancelButton->OnKeyEvent=CancelButton.InternalOnKeyEvent;
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "SAVE RESULTS";
	OkButton->Hint = "Upload your results, which will be posted to the %MISSIONNAME% scoreboard.";
	OkButton->WinTop = 0.67;
	OkButton->WinLeft = 0.15;
	OkButton->WinWidth = 0.3;
	//OkButton->OnClick=AAMissionCompletePageEx.InternalOnClick;
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
	b_CheatText = CheatText;
	b_OK = OkButton;
	WinTop = 0.2;
	WinLeft = 0;
	WinWidth = 1;
	WinHeight = 0.6;
}

void UAAMissionCompletePageEx::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	FString sTempHint = "";
	FString sTourMissionName = "";
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
	b_SaveAndTryAgain.bBoundToParent = true;
	b_SaveAndTryAgain.bStandardized = true;
	b_SaveAndTryAgain.bScaleToParent = true;
	if (Cast<AHumanController>(PlayerOwner())->bMissionPass == false)
	{
		l_Text2.Caption = "Click \"Retry Mission\" to try again or \"Cancel\" to return to the main menu.";
		b_Retry.Caption = "Retry Mission";
		b_OK.DisableMe();
		b_SaveAndTryAgain.DisableMe();
	}
	if ((Cast<AHumanController>(PlayerOwner())->Level.Game.GetScreenplay().bPlayerCheated == true) && (Cast<AHumanController>(PlayerOwner())->bMissionPass == true))
	{
		b_OK.DisableMe();
		b_SaveAndTryAgain.DisableMe();
		b_CheatText.Caption = "Cannot authorize due to use of player cheats.";
	}
	sTourMissionName = PlayerOwner().Level.GetTourMissionTitle(PlayerOwner().Level.iTour, PlayerOwner().Level.iMission);
	sTempHint = Repl(b_OK.Hint, "%MISSIONNAME%", sTourMissionName);
	b_OK.Hint = sTempHint;
	*/
}

bool UAAMissionCompletePageEx::InternalOnClick(UGUIComponent* Sender)
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
	case b_SaveAndTryAgain:
		SaveAndTryAgain();
		return true;
	default:
		return true;
		return true;
	}
	*/
	return false;  //FAKE   /EliZ

}

bool UAAMissionCompletePageEx::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((State == 3) && (Key == 11))
	{
		Cancel();
	}
	return Super::InternalOnKeyEvent(Key, State, Delta);
	*/
	return false;  //FAKE   /EliZ

}

void UAAMissionCompletePageEx::HandleObject(UObject* obj, UObject* OptionalObj_1, UObject* OptionalObj_2)
{
	/*
	if (Cast<UMaterialInstance>(obj) != nullptr)
	{
		i_Medal.Image = Cast<UMaterialInstance>(obj);
	}
	Super::HandleObject(obj, OptionalObj_1, OptionalObj_2);
	*/
}

FString UAAMissionCompletePageEx::GetDataString()
{
	return l_Text2->Caption;
}

void UAAMissionCompletePageEx::SetDataString(FString str)
{
	l_Text2->Caption = str;
	//Super::SetDataString(str);
}

void UAAMissionCompletePageEx::SaveAndTryAgain()
{
	bTryAgain = true;
	OK();
}

void UAAMissionCompletePageEx::OK()
{
	/*
	b_OK.DisableMe();
	b_Cancel.DisableMe();
	b_Retry.DisableMe();
	b_SaveAndTryAgain.DisableMe();
	l_Text.Caption = "Saving Your Mission Results";
	l_Text2.Caption = "Updating Personnel Jacket On Server, Please Wait...";
	iAuthDelDotCounter = 0;
	bAuthContacted = false;
	Cast<AHumanController>(PlayerOwner())->MissionCompleted();
	if (PlayerOwner().Level.DidPlayerCompleteNewMission(PlayerOwner()) == 1)
	{
		Cast<AHumanController>(PlayerOwner())->VerifyJacket();
		Cast<AHumanController>(PlayerOwner())->SaveJacket();
	}
	else
	{
		Cast<AHumanController>(PlayerOwner())->VerifyJacket();
		Cast<AHumanController>(PlayerOwner())->SaveJacket();
	}
	SetTimer(0.25, true);
	*/
}

void UAAMissionCompletePageEx::Timer()
{
	/*
	if (bAuthContacted == false)
	{
		if (Cast<AHumanController>(PlayerOwner())->iAuthClientTransmissionComplete != 0)
		{
			Log("Auth client transmission detected as complete: " + FString::FromInt(Cast<AHumanController>(PlayerOwner())->iAuthClientTransmissionComplete), 'MissionComplete');
			switch (Cast<AHumanController>(PlayerOwner())->iAuthClientTransmissionComplete)
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
				b_Cancel.EnableMe();
				l_Text2.Caption = "The server could not be updated.|(Error: " + Cast<AHumanController>(PlayerOwner())->sAuthClientTransmissionText + ").|Would you like to try again?";
				KillTimer();
			}
		}
		else
		{
			l_Text2.Caption = "Updating Personnel Jacket On Server, Please Wait...|";
			switch ((float(iAuthDelDotCounter++) % 4))
			{
			case 0:
				l_Text2.Caption = l_Text2.Caption + "\\";
				break;
			case 1:
				l_Text2.Caption = l_Text2.Caption + "-";
				break;
			case 2:
				l_Text2.Caption = l_Text2.Caption + "/";
				break;
			case 3:
				l_Text2.Caption = l_Text2.Caption + "-";
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

void UAAMissionCompletePageEx::Cancel()
{
	/*
	l_Text.Caption = "Returning To Main Menu";
	l_Text2.Caption = "Please wait while we return to the main menu";
	PlayerOwner().ConsoleCommand("disconnect");
	Controller.CloseMenu();
	*/
}

void UAAMissionCompletePageEx::Retry()
{
	/*
	l_Text.Caption = "Restarting Mission";
	l_Text2.Caption = "Please wait while the mission restarts.";
	PlayerOwner().ConsoleCommand("reconnect");
	*/
}
