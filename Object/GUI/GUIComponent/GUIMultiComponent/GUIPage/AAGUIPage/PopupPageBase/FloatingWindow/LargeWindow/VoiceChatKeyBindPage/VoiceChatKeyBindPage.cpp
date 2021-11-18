// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/VoiceChatKeyBindPage/VoiceChatKeyBindPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UVoiceChatKeyBindPage::UVoiceChatKeyBindPage()
{
	UmoEditBox* ChannelName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	ChannelName->bVerticalLayout = true;
	ChannelName->LabelJustification = EeTextAlign::TXTA_Center;
	ChannelName->Caption = "Channel Name";
	//ChannelName->OnCreateComponent=ChannelName.InternalOnCreateComponent;
	ChannelName->WinTop = 0.486458;
	ChannelName->WinLeft = 0.142383;
	ChannelName->WinWidth = 0.278125;
	ChannelName->WinHeight = 0.087695;
	//ChannelName->OnChange=VoiceChatKeyBindPage.InternalOnChange;
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "Apply";
	OkButton->WinTop = 0.616667;
	OkButton->WinLeft = 0.673633;
	OkButton->WinWidth = 0.116992;
	//OkButton->OnClick=VoiceChatKeyBindPage.CloseClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUILabel* Title = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Title->Caption = "Modify Quick Switch KeyBind";
	Title->FontScale = EFontScale::FNS_Large;
	Title->StyleName = "TextLabel";
	Title->WinTop = 0.388802;
	Title->WinLeft = 0.185352;
	Title->WinWidth = 0.629687;
	Title->WinHeight = 0.068164;
	UGUILabel* KeyLabel1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	KeyLabel1->Caption = "Key 1";
	KeyLabel1->StyleName = "TextLabel";
	KeyLabel1->WinTop = 0.48776;
	KeyLabel1->WinLeft = 0.464649;
	KeyLabel1->WinWidth = 0.082813;
	KeyLabel1->WinHeight = 0.038867;
	UGUILabel* KeyLabel2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	KeyLabel2->Caption = "Key 2";
	KeyLabel2->StyleName = "TextLabel";
	KeyLabel2->WinTop = 0.48776;
	KeyLabel2->WinLeft = 0.654102;
	KeyLabel2->WinWidth = 0.2;
	KeyLabel2->WinHeight = 0.038867;
	UGUILabel* key1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	key1->bMultiLine = true;
	key1->StyleName = "TextLabel";
	key1->WinTop = 0.529427;
	key1->WinLeft = 0.463673;
	key1->WinWidth = 0.163867;
	key1->WinHeight = 0.082813;
	key1->bAcceptsInput = true;
	//key1->OnClick=VoiceChatKeyBindPage.KeyClick;
	UGUILabel* Key2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Key2->bMultiLine = true;
	Key2->StyleName = "TextLabel";
	Key2->WinTop = 0.529427;
	Key2->WinLeft = 0.654102;
	Key2->WinWidth = 0.130664;
	Key2->WinHeight = 0.082813;
	Key2->bAcceptsInput = true;
	//Key2->OnClick=VoiceChatKeyBindPage.KeyClick;
	l_PageTitle = Title;
	l_KeyLabel1 = KeyLabel1;
	l_KeyLabel2 = KeyLabel2;
	l_Key1 = key1;
	l_Key2 = Key2;
	ed_ChannelName = ChannelName;
	b_OK = OkButton;
	NoneText = "None";
	AnyKeyText = "Press Any Key|To Bind Command";
	WinTop = 0.375;
	WinLeft = 0;
	WinWidth = 1;
	WinHeight = 0.3;
}

void UVoiceChatKeyBindPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	l_Key1.Caption = NoneText;
	l_Key2.Caption = NoneText;
	*/
}

void UVoiceChatKeyBindPage::HandleParameters(FString Value, FString Nothing)
{
	/*
	Channel = Value;
	ed_ChannelName.SetText(Channel);
	GetBinds();
	*/
}

void UVoiceChatKeyBindPage::GetBinds()
{
	/*
	UpdateLabel(l_Key1, false);
	UpdateLabel(l_Key2, false);
	Controller.GetAssignedKeys("Speak" @ Channel, Keys, LocalizedKeys);
	if (LocalizedKeys.Length > 0)
	{
		l_Key1.Caption = LocalizedKeys[0];
	}
	if (LocalizedKeys.Length > 1)
	{
		l_Key2.Caption = LocalizedKeys[1];
	}
	*/
}

bool UVoiceChatKeyBindPage::CloseClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}

void UVoiceChatKeyBindPage::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case ed_ChannelName:
		Channel = ed_ChannelName.GetText();
		break;
	default:
	}
	*/
}

bool UVoiceChatKeyBindPage::KeyClick(UGUIComponent* Sender)
{
	/*
	if (GUILabel(Sender) != None)
	{
		UpdateLabel(GUILabel(Sender), true);
		Controller.__OnNeedRawKeyPress__Delegate = RawKeyPress;
		Controller.Master.bRequireRawJoystick = true;
		PlayerOwner().ConsoleCommand("toggleime 0");
		return true;
	}
	*/
	return false;
}

void UVoiceChatKeyBindPage::UpdateLabel(UGUILabel* Label, bool bWaitingForRawInput)
{
	/*
	if (Label == None)
	{
		return;
	}
	if (bWaitingForRawInput)
	{
		Label.Caption = AnyKeyText;
		Label.FontScale = 0;
	}
	else
	{
		Label.FontScale = 1;
		Label.Caption = NoneText;
	}
	*/
}

bool UVoiceChatKeyBindPage::RawKeyPress(uint8 NewKey)
{
	/*
	FString NewKeyName = "";
	FString LocalizedKeyName = "";
	Controller.__OnNeedRawKeyPress__Delegate = None;
	Controller.Master.bRequireRawJoystick = false;
	PlayerOwner().ConsoleCommand("toggleime 1");
	if (NewKey == 27)
	{
		GetBinds();
		return true;
	}
	Controller.KeyNameFromIndex(NewKey, NewKeyName, LocalizedKeyName);
	Controller.SetKeyBind(NewKeyName, "Speak" @ Channel);
	PlayerOwner().ClientPlaySound(Controller.ClickSound);
	GetBinds();
	*/
	return true;
}