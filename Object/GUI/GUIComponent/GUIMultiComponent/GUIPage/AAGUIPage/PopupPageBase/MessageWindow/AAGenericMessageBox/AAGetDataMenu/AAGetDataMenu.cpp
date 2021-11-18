// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAGetDataMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAGetDataMenu::UAAGetDataMenu()
{
	UmoEditBox* Data = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	Data->ComponentJustification = EeTextAlign::TXTA_Center;
	Data->CaptionWidth = 0;
	//Data->OnCreateComponent=Data.InternalOnCreateComponent;
	Data->WinTop = 0.48771;
	Data->WinLeft = 0.25;
	Data->WinHeight = 0.047305;
	Data->TabOrder = 0;
	UGUIButton* CancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CancelButton->Caption = "CANCEL";
	CancelButton->Hint = "Close this menu, discarding changes.";
	CancelButton->WinTop = 0.554167;
	CancelButton->WinLeft = 0.573047;
	CancelButton->WinWidth = 0.131641;
	CancelButton->WinHeight = 0.036;
	//CancelButton->OnClick=AAGetDataMenu.InternalOnClick;
	//CancelButton->OnKeyEvent=CancelButton.InternalOnKeyEvent;
	UGUILabel* DialogText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText->TextAlign = ETextAlign::TXTA_Center;
	DialogText->FontScale = EFontScale::FNS_Large;
	DialogText->StyleName = "TextButton";
	DialogText->WinTop = 0.35;
	DialogText->WinHeight = 0.09375;
	b_Cancel = CancelButton;
	ed_Data = Data;
	l_Text = DialogText;
}

void UAAGetDataMenu::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	ed_Data->TabOrder = 0;
	b_OK->TabOrder = 1;
	b_Cancel->TabOrder = 2;
	//Super::InitComponent(MyController, MyOwner);
	//RemoveComponent(l_Text2);
	b_OK->bBoundToParent = true;
	b_OK->bStandardized = true;
	b_OK->bScaleToParent = true;
	b_Cancel->bBoundToParent = true;
	b_Cancel->bStandardized = true;
	b_Cancel->bScaleToParent = true;
}

void UAAGetDataMenu::HandleParameters(FString A, FString B)
{
	l_Text->Caption = A;
	ed_Data->SetCaption(B);
}

FString UAAGetDataMenu::GetDataString()
{
	return ed_Data->GetText();
}

void UAAGetDataMenu::SetDataString(FString str)
{
	/*
	Super::SetDataString(str);
	ed_Data.SetText(str);
	*/
}

bool UAAGetDataMenu::InternalOnClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu((Sender == b_Cancel));
	return true;
}

bool UAAGetDataMenu::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((State == 3) && (Key == 11))
	{
		return InternalOnClick(b_Cancel);
	}
	return Super::InternalOnKeyEvent(Key, State, Delta);
	*/
	return false;    //FAKE   /ELiZ

}

bool UAAGetDataMenu::InternalOnPreDraw(UCanvas* C)
{
	bool B = false;
	float W = 0;
	float L = 0;
	float t = 0;
	/*
	B = Super::InternalOnPreDraw(C);
	t = ((1 - (float(64) / ActualHeight())) - b_Cancel.WinHeight);
	W = (0.15 + (b_Cancel.WinWidth * 2));
	L = (0.5 - (W * 0.5));
	b_OK.SetPosition(L, t, b_Cancel.WinWidth, b_Cancel.WinHeight);
	(L += (0.15 + b_Cancel.WinWidth));
	b_Cancel.SetPosition(L, t, b_Cancel.WinWidth, b_Cancel.WinHeight);
	*/
	return B;
}