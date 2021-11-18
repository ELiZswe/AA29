// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAMissionCompletePageJavelinTraining_Died/AAMissionCompletePageJavelin_Die.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAMissionCompletePageJavelin_Die::UAAMissionCompletePageJavelin_Die()
{
	UGUIButton* DontSaveandCancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DontSaveandCancelButton->Caption = "QUIT TRAINING";
	DontSaveandCancelButton->Hint = "Quit to the main interface, discarding current results.";
	DontSaveandCancelButton->WinTop = 0.67;
	DontSaveandCancelButton->WinLeft = 0.55;
	DontSaveandCancelButton->WinWidth = 0.3;
	//DontSaveandCancelButton->OnClick=AAMissionCompletePageJavelinTraining_Died.InternalOnClick;
	//DontSaveandCancelButton->OnKeyEvent=DontSaveandCancelButton.InternalOnKeyEvent;
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "Retry Mission";
	OkButton->Hint = "Restart Javelin Training.";
	OkButton->WinTop = 0.67;
	OkButton->WinLeft = 0.15;
	OkButton->WinWidth = 0.3;
	//OkButton->OnClick=AAMissionCompletePageJavelinTraining_Died.InternalOnClick;
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
	b_CheatText = CheatText;
	b_OK = OkButton;
	WinTop = 0.2;
	WinLeft = 0;
	WinWidth = 1;
	WinHeight = 0.6;
}

void UAAMissionCompletePageJavelin_Die::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	bAuthContacted = false;
	b_OK->TabOrder = 0;
	b_DontSaveAndCancel->TabOrder = 1;
	//Super::InitComponent(MyController, MyOwner);
	b_OK->bBoundToParent = true;
	b_OK->bStandardized = true;
	b_OK->bScaleToParent = true;
	b_DontSaveAndCancel->bBoundToParent = true;
	b_DontSaveAndCancel->bStandardized = true;
	b_DontSaveAndCancel->bScaleToParent = true;
}

bool UAAMissionCompletePageJavelin_Die::InternalOnClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_OK:
		DontSaveAndTryAgain();
		return true;
	case b_DontSaveAndCancel:
		DontSaveAndCancel();
		return true;
	default:
		return true;
		return true;
	}
	*/
	return false;   //FAKE   /EliZ
}

bool UAAMissionCompletePageJavelin_Die::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((State == 3) && (Key == 11))
	{
		DontSaveAndCancel();
	}
	return Super::InternalOnKeyEvent(Key, State, Delta);
	*/
	return false;   //FAKE   /EliZ
}

void UAAMissionCompletePageJavelin_Die::HandleObject(UObject* obj, UObject* OptionalObj_1, UObject* OptionalObj_2)
{
	/*
	if (Material(obj) != None)
	{
		i_Medal.Image = Material(obj);
	}
	Super::HandleObject(obj, OptionalObj_1, OptionalObj_2);
	*/
}

FString UAAMissionCompletePageJavelin_Die::GetDataString()
{
	return l_Text2->Caption;
}

void UAAMissionCompletePageJavelin_Die::SetDataString(FString str)
{
	l_Text2->Caption = str;
	//Super::SetDataString(str);
}

void UAAMissionCompletePageJavelin_Die::DontSaveAndCancel()
{
	l_Text->Caption = "Returning To Main Menu";
	l_Text2->Caption = "Please wait while we return to the main menu";
	//PlayerOwner().ConsoleCommand("disconnect");
	//Controller.CloseMenu();
}

void UAAMissionCompletePageJavelin_Die::DontSaveAndTryAgain()
{
	l_Text->Caption = "Restarting Mission";
	l_Text2->Caption = "Please wait while the mission restarts.";
	//PlayerOwner().ConsoleCommand("reconnect");
}