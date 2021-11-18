// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAPerformWarn/AAPerformWarn.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAPerformWarn::UAAPerformWarn()
{
	UmoCheckBox* HideCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	HideCheckbox->bFlipped = true;
	HideCheckbox->ComponentJustification = EeTextAlign::TXTA_Left;
	HideCheckbox->Caption = "  do not display this warning again";
	//HideCheckbox->OnCreateComponent=HideCheckbox.InternalOnCreateComponent;
	HideCheckbox->FontScale = EFontScale::FNS_Small;
	HideCheckbox->IniOption = "@Internal";
	HideCheckbox->Hint = "Check this to disable showing warning messages when adjusting properties in the Settings menu";
	HideCheckbox->WinTop = 0.5;
	HideCheckbox->WinLeft = 0.35;
	HideCheckbox->WinWidth = 0.3;
	HideCheckbox->WinHeight = 0.035;
	HideCheckbox->TabOrder = 1;
	HideCheckbox->bStandardized = false;
	//HideCheckbox->OnChange=AAPerformWarn.CheckBoxClick;
	//HideCheckbox->OnLoadINI=AAPerformWarn.InternalOnLoadINI;
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.55;
	OkButton->WinLeft = 0.439063;
	OkButton->WinWidth = 0.121875;
	OkButton->TabOrder = 0;
	//OkButton->OnClick=AAPerformWarn.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUILabel* DialogText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText->Caption = "WARNING";
	DialogText->TextAlign = ETextAlign::TXTA_Center;
	DialogText->FontScale = EFontScale::FNS_Large;
	DialogText->StyleName = "TextLabel";
	DialogText->WinTop = 0.4;
	DialogText->WinHeight = 0.04;
	UGUILabel* DialogText2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText2->Caption = "The change you are making may adversely affect your performance.";
	DialogText2->TextAlign = ETextAlign::TXTA_Center;
	DialogText2->StyleName = "TextLabel";
	DialogText2->WinTop = 0.45;
	DialogText2->WinHeight = 0.04;
	ch_NeverShowAgain = HideCheckbox;
	b_OK = OkButton;
	l_Text = DialogText;
	l_Text2 = DialogText2;
}

void UAAPerformWarn::HandleParameters(FString Param1, FString Param2)
{
	/*
	float F = 0;
	F = float(Param1);
	if (F != 0)
	{
		SetTimer(F);
	}
	*/
}

void UAAPerformWarn::Timer()
{
	//Controller.CloseMenu(false);
}

bool UAAPerformWarn::InternalOnClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}

void UAAPerformWarn::CheckBoxClick(UGUIComponent* Sender)
{
	//class'AGP_Interface.Settings_Tabs'.Default.bExpert = ch_NeverShowAgain.IsChecked();
	//class'AGP_Interface.Settings_Tabs'.StaticSaveConfig();
}

void UAAPerformWarn::InternalOnLoadINI(UGUIComponent* Sender, FString Value)
{
	//ch_NeverShowAgain.Checked(class'AGP_Interface.Settings_Tabs'.Default.bExpert);
}