// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAInternetSettingsPage/AAInternetSettingsPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"

UAAInternetSettingsPage::UAAInternetSettingsPage()
{
	UGUIButton* InternetSettingsCancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	InternetSettingsCancelButton->Caption = "CANCEL";
	InternetSettingsCancelButton->WinTop = 0.556666;
	InternetSettingsCancelButton->WinLeft = 0.595;
	InternetSettingsCancelButton->WinWidth = 0.13;
	InternetSettingsCancelButton->WinHeight = 0.045;
	//InternetSettingsCancelButton->OnClick=AAInternetSettingsPage.InternalOnClick;
	//InternetSettingsCancelButton->OnKeyEvent=InternetSettingsCancelButton.InternalOnKeyEvent;
	UGUIButton* InternetSettingsOKButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	InternetSettingsOKButton->Caption = "OK";
	InternetSettingsOKButton->WinTop = 0.556666;
	InternetSettingsOKButton->WinLeft = 0.741251;
	InternetSettingsOKButton->WinWidth = 0.13625;
	InternetSettingsOKButton->WinHeight = 0.045;
	//InternetSettingsOKButton->OnClick=AAInternetSettingsPage.InternalOnClick;
	//InternetSettingsOKButton->OnKeyEvent=InternetSettingsOKButton.InternalOnKeyEvent;
	UmoComboBox* NetspeedComboBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	NetspeedComboBox->bReadOnly = true;
	NetspeedComboBox->bVerticalLayout = true;
	NetspeedComboBox->LabelJustification = EeTextAlign::TXTA_Center;
	NetspeedComboBox->ComponentJustification = EeTextAlign::TXTA_Center;
	NetspeedComboBox->Caption = "Netspeed: ";
	//NetspeedComboBox->OnCreateComponent=NetspeedComboBox.InternalOnCreateComponent;
	NetspeedComboBox->WinTop = 0.401666;
	NetspeedComboBox->WinLeft = 0.5375;
	NetspeedComboBox->WinWidth = 0.34125;
	NetspeedComboBox->WinHeight = 0.09;
	NetspeedComboBox->bStandardized = false;
	b_OK = InternetSettingsOKButton;
	b_Cancel = InternetSettingsCancelButton;
	co_Netspeed = NetspeedComboBox;
}

void UAAInternetSettingsPage::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	/*
	Super::InitComponent(InController, InOwner);
	SetupPlayerName();
	SetupNetspeedCombo();
	*/
}

void UAAInternetSettingsPage::SetupPlayerName()
{
	/*
	local PlayerController PC;
	PC = PlayerOwner();
	if (PC.PlayerReplicationInfo != None)
	{
		ed_PlayerName.SetText(PC.PlayerReplicationInfo.PlayerName);
	}
	else
	{
		ed_PlayerName.SetText(PC.GetUrlOption("Name"));
	}
	*/
}

void UAAInternetSettingsPage::SetupNetspeedCombo()
{
	/*
	int32 i = 0;
	for (i = 0; i < 4; i++)
	{
		co_Netspeed.addItem(class'AGP_Interface.AATab_GameSettings'.Default.NetSpeedText[i], , GetNetspeedValue(i));
	}
	co_Netspeed.SetIndex(GetNetspeedIndex(Class'Player'.Default.ConfiguredInternetSpeed));
	*/
}

bool UAAInternetSettingsPage::InternalOnClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu((Sender == b_Cancel));
	return true;
}

void UAAInternetSettingsPage::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	if (!bCancelled)
	{
		PlayerOwner().ConsoleCommand("NetSpeed" @ co_Netspeed.GetExtra());
	}
	Super::Closed(Sender, bCancelled);
	*/
}

FString UAAInternetSettingsPage::GetNetspeedValue(int32 i)
{
	switch (i)
	{
	case 0:
		return "2600";
	case 1:
		return "5000";
	case 2:
		return "10000";
	case 3:
		return "15000";
	default:
		return "10000";
	}
	return "10000";    //FAKE   /ELiZ
}

int32 UAAInternetSettingsPage::GetNetspeedIndex(int32 Netspeed)
{
	if (Netspeed < 3500)
	{
		return 0;
	}
	if (Netspeed < 7500)
	{
		return 1;
	}
	if (Netspeed < 12500)
	{
		return 2;
	}
	return 3;
}