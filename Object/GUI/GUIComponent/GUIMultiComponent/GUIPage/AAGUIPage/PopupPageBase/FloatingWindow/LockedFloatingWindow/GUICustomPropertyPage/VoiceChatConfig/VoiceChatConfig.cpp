// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/GUICustomPropertyPage/VoiceChatConfig/VoiceChatConfig.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moSlider/moSlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"

UVoiceChatConfig::UVoiceChatConfig()
{
	UmoSlider* VoiceVolume = NewObject<UmoSlider>(UmoSlider::StaticClass());
	VoiceVolume->MaxValue = 10;
	VoiceVolume->MinValue = 1;
	VoiceVolume->CaptionWidth = 0.6;
	VoiceVolume->Caption = "Voice Chat Volume";
	//VoiceVolume->OnCreateComponent=VoiceVolume.InternalOnCreateComponent;
	VoiceVolume->IniOption = "@Internal";
	VoiceVolume->Hint = "Adjusts the volume of other players' voice chat communication.";
	VoiceVolume->WinTop = 0.142484;
	VoiceVolume->WinLeft = 0.518507;
	VoiceVolume->WinWidth = 0.408907;
	VoiceVolume->RenderWeight = 1.04;
	VoiceVolume->TabOrder = 0;
	VoiceVolume->bStandardized = false;
	//VoiceVolume->OnChange=VoiceChatConfig.InternalOnChange;
	//VoiceVolume->OnLoadINI=VoiceChatConfig.InternalOnLoadINI;
	UmoCheckBox* AutoJoinPublic = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AutoJoinPublic->CaptionWidth = 0.94;
	AutoJoinPublic->Caption = "Autojoin Public Channel";
	//AutoJoinPublic->OnCreateComponent=AutoJoinPublic.InternalOnCreateComponent;
	AutoJoinPublic->IniOption = "@Internal";
	AutoJoinPublic->Hint = "Automatically join the 'Public' channel upon connecting to a server.";
	AutoJoinPublic->WinTop = 0.042496;
	AutoJoinPublic->WinLeft = 0.08628;
	AutoJoinPublic->WinWidth = 0.826652;
	AutoJoinPublic->WinHeight = 0.06;
	AutoJoinPublic->TabOrder = 1;
	AutoJoinPublic->bBoundToParent = true;
	AutoJoinPublic->bScaleToParent = true;
	AutoJoinPublic->bStandardized = false;
	//AutoJoinPublic->OnChange=VoiceChatConfig.InternalOnChange;
	//AutoJoinPublic->OnLoadINI=VoiceChatConfig.InternalOnLoadINI;
	UmoCheckBox* AutoJoinLocal = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AutoJoinLocal->CaptionWidth = 0.94;
	AutoJoinLocal->Caption = "Autojoin Local Channel";
	//AutoJoinLocal->OnCreateComponent=AutoJoinLocal.InternalOnCreateComponent;
	AutoJoinLocal->IniOption = "@Internal";
	AutoJoinLocal->Hint = "Automatically join the 'Local' channel upon connecting to a server.";
	AutoJoinLocal->WinTop = 0.145784;
	AutoJoinLocal->WinLeft = 0.08628;
	AutoJoinLocal->WinWidth = 0.826652;
	AutoJoinLocal->WinHeight = 0.06;
	AutoJoinLocal->TabOrder = 2;
	AutoJoinLocal->bBoundToParent = true;
	AutoJoinLocal->bScaleToParent = true;
	AutoJoinLocal->bStandardized = false;
	//AutoJoinLocal->OnChange=VoiceChatConfig.InternalOnChange;
	//AutoJoinLocal->OnLoadINI=VoiceChatConfig.InternalOnLoadINI;
	UmoCheckBox* AutoJoinTeam = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AutoJoinTeam->Caption = "Autojoin Team Channel";
	//AutoJoinTeam->OnCreateComponent=AutoJoinTeam.InternalOnCreateComponent;
	AutoJoinTeam->IniOption = "@Internal";
	AutoJoinTeam->Hint = "Automatically join the 'Team' channel upon connecting to a server.";
	AutoJoinTeam->WinTop = 0.226937;
	AutoJoinTeam->WinWidth = 0.44091;
	AutoJoinTeam->WinHeight = 0.06;
	AutoJoinTeam->TabOrder = 3;
	AutoJoinTeam->bBoundToParent = true;
	AutoJoinTeam->bScaleToParent = true;
	AutoJoinTeam->bStandardized = false;
	//AutoJoinTeam->OnChange=VoiceChatConfig.InternalOnChange;
	//AutoJoinTeam->OnLoadINI=VoiceChatConfig.InternalOnLoadINI;
	UmoCheckBox* AutoSpeakCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AutoSpeakCheckbox->Caption = "Auto-select Active Channel";
	//AutoSpeakCheckbox->OnCreateComponent=AutoSpeakCheckbox.InternalOnCreateComponent;
	AutoSpeakCheckbox->IniOption = "@Internal";
	AutoSpeakCheckbox->Hint = "Automatically set an active channel when you join a server.  The default channel is determined by the gametype, but you can specify your own using the editbox below";
	AutoSpeakCheckbox->WinTop = 0.603526;
	AutoSpeakCheckbox->WinLeft = 0.039812;
	AutoSpeakCheckbox->WinWidth = 0.442638;
	AutoSpeakCheckbox->WinHeight = 0.06;
	AutoSpeakCheckbox->TabOrder = 3;
	AutoSpeakCheckbox->bBoundToParent = true;
	AutoSpeakCheckbox->bScaleToParent = true;
	AutoSpeakCheckbox->bStandardized = false;
	//AutoSpeakCheckbox->OnChange=VoiceChatConfig.InternalOnChange;
	//AutoSpeakCheckbox->OnLoadINI=VoiceChatConfig.InternalOnLoadINI;
	UmoEditBox* ChatPasswordEdit = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	ChatPasswordEdit->CaptionWidth = 0.6;
	ChatPasswordEdit->Caption = "Chat Password";
	//ChatPasswordEdit->OnCreateComponent=ChatPasswordEdit.InternalOnCreateComponent;
	ChatPasswordEdit->IniOption = "@Internal";
	ChatPasswordEdit->Hint = "Set a password on your personal chat room to limit who is allowed to join";
	ChatPasswordEdit->WinTop = 0.332828;
	ChatPasswordEdit->WinLeft = 0.032569;
	ChatPasswordEdit->WinWidth = 0.420403;
	ChatPasswordEdit->TabOrder = 4;
	ChatPasswordEdit->bStandardized = false;
	//ChatPasswordEdit->OnChange=VoiceChatConfig.InternalOnChange;
	//ChatPasswordEdit->OnLoadINI=VoiceChatConfig.InternalOnLoadINI;
	UmoEditBox* DefaultActiveChannelEditBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	DefaultActiveChannelEditBox->CaptionWidth = 0.6;
	DefaultActiveChannelEditBox->Caption = "Default Channel Name";
	//DefaultActiveChannelEditBox->OnCreateComponent=DefaultActiveChannelEditBox.InternalOnCreateComponent;
	DefaultActiveChannelEditBox->IniOption = "@Internal";
	DefaultActiveChannelEditBox->Hint = "Enter the name of the channel to speak on by default when you join the server.  To use the default chatroom for whichever gametype you're playing, leave this field empty";
	DefaultActiveChannelEditBox->WinTop = 0.757277;
	DefaultActiveChannelEditBox->WinLeft = 0.032569;
	DefaultActiveChannelEditBox->WinWidth = 0.420403;
	DefaultActiveChannelEditBox->TabOrder = 4;
	DefaultActiveChannelEditBox->bStandardized = false;
	//DefaultActiveChannelEditBox->OnChange=VoiceChatConfig.InternalOnChange;
	//DefaultActiveChannelEditBox->OnLoadINI=VoiceChatConfig.InternalOnLoadINI;
	UmoComboBox* VoiceQuality = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	VoiceQuality->bReadOnly = true;
	VoiceQuality->CaptionWidth = 0.6;
	VoiceQuality->Caption = "Internet Quality";
	//VoiceQuality->OnCreateComponent=VoiceQuality.InternalOnCreateComponent;
	VoiceQuality->IniOption = "@Internal";
	VoiceQuality->Hint = "Determines the codec used to transmit voice chat to and from internet servers.";
	VoiceQuality->WinTop = 0.241391;
	VoiceQuality->WinLeft = 0.52339;
	VoiceQuality->WinWidth = 0.408907;
	VoiceQuality->TabOrder = 5;
	VoiceQuality->bStandardized = false;
	//VoiceQuality->OnChange=VoiceChatConfig.InternalOnChange;
	//VoiceQuality->OnLoadINI=VoiceChatConfig.InternalOnLoadINI;
	UmoComboBox* VoiceQualityLAN = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	VoiceQualityLAN->bReadOnly = true;
	VoiceQualityLAN->CaptionWidth = 0.6;
	VoiceQualityLAN->Caption = "LAN Quality";
	//VoiceQualityLAN->OnCreateComponent=VoiceQualityLAN.InternalOnCreateComponent;
	VoiceQualityLAN->IniOption = "@Internal";
	VoiceQualityLAN->Hint = "Determines the codec used to transmit voice chat to and from LAN servers.";
	VoiceQualityLAN->WinTop = 0.333786;
	VoiceQualityLAN->WinLeft = 0.52339;
	VoiceQualityLAN->WinWidth = 0.408907;
	VoiceQualityLAN->TabOrder = 6;
	VoiceQualityLAN->bStandardized = false;
	//VoiceQualityLAN->OnChange=VoiceChatConfig.InternalOnChange;
	//VoiceQualityLAN->OnLoadINI=VoiceChatConfig.InternalOnLoadINI;
	ed_ChatPassword = ChatPasswordEdit;
	ed_Active = DefaultActiveChannelEditBox;
	sl_VoiceVol = VoiceVolume;
	ch_AJPublic = AutoJoinPublic;
	ch_AJLocal = AutoJoinLocal;
	ch_AJTeam = AutoJoinTeam;
	ch_AutoSpeak = AutoSpeakCheckbox;
	co_Quality = VoiceQuality;
	co_LANQuality = VoiceQualityLAN;
	//VoiceChatClass = Class'Engine.VoiceChatReplicationInfo';
	VoiceChatClassName = "UnrealGame.TeamVoiceReplicationInfo";
	ResetCaption = "Reset";
	ResetHint = "Reset values for all options to their default values";
	WindowName = "Voice Chat Configuration";
	bAcceptsInput = false;
}


void UVoiceChatConfig::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	/*
	int32 i = 0;
	FString cname = "";
	FString CDesc = "";
	local class<VoiceChatReplicationInfo>  Cls;
	Super::InitComponent(InController, InOwner);
	Cls = class<VoiceChatReplicationInfo>(DynamicLoadObject(VoiceChatClassName, Class'Class'));
	if (Cls != None)
	{
		VoiceChatClass = Cls;
	}
	VoiceChatClass.GetInstalledCodecs(InstalledCodecs);
	for (i = 0; i < InstalledCodecs.Length; i++)
	{
		VoiceChatClass.GetCodecInfo(InstalledCodecs[i], cname, CDesc);
		co_Quality.addItem(cname, , InstalledCodecs[i]);
		co_LANQuality.addItem(cname, , InstalledCodecs[i]);
	}
	ed_ChatPassword.MaskText(true);
	b_Cancel.Caption = ResetCaption;
	b_Cancel.Hint = ResetHint;
	b_Cancel.__OnClick__Delegate = ResetClick;
	ed_ChatPassword.MaskText(true);
	sb_Main.ManageComponent(sl_VoiceVol);
	sb_Main.ManageComponent(ch_AJPublic);
	sb_Main.ManageComponent(ch_AJLocal);
	sb_Main.ManageComponent(ch_AJTeam);
	sb_Main.ManageComponent(ch_AutoSpeak);
	sb_Main.ManageComponent(ed_Active);
	sb_Main.ManageComponent(ed_ChatPassword);
	sb_Main.ManageComponent(co_Quality);
	sb_Main.ManageComponent(co_LANQuality);
	*/
}

void UVoiceChatConfig::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	local PlayerController PC;
	if (GUIMenuOption(Sender) != None)
	{
		PC = PlayerOwner();
		switch (GUIMenuOption(Sender).Caption)
		{
		case ed_ChatPassword.Caption:
			sPwd = PC.ChatPassword;
			ed_ChatPassword.SetComponentValue(sPwd, true);
			break;
		case sl_VoiceVol.Caption:
			fVoice = float(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice VoiceVolume"));
			sl_VoiceVol.SetComponentValue(string(fVoice), true);
			break;
		case co_Quality.Caption:
			sCodec = PC.VoiceChatCodec;
			co_Quality.SetExtra(sCodec, true);
			break;
		case co_LANQuality.Caption:
			sLANCodec = PC.VoiceChatLANCodec;
			co_LANQuality.SetExtra(sLANCodec, true);
			break;
		case ch_AJPublic.Caption:
			bAJPublic = bool((PC.AutoJoinMask & 1));
			ch_AJPublic.SetComponentValue(string(bAJPublic), true);
			break;
		case ch_AJLocal.Caption:
			bAJLocal = bool((PC.AutoJoinMask & 2));
			ch_AJLocal.SetComponentValue(string(bAJLocal), true);
			break;
		case ch_AJTeam.Caption:
			bAJTeam = bool((PC.AutoJoinMask & 4));
			ch_AJTeam.SetComponentValue(string(bAJTeam), true);
			break;
		case ch_AutoSpeak.Caption:
			bAutoSpeak = PC.bEnableInitialChatRoom;
			if (bAutoSpeak)
			{
				EnableComponent(ed_Active);
			}
			else
			{
				DisableComponent(ed_Active);
			}
			ch_AutoSpeak.SetComponentValue(string(bAutoSpeak), true);
		case ed_Active.Caption:
			sActive = PC.DefaultActiveChannel;
			ed_Active.SetComponentValue(sActive, true);
		default:
		}
	}
	*/
}

void UVoiceChatConfig::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local PlayerController PC;
	if (GUIMenuOption(Sender) != None)
	{
		PC = PlayerOwner();
		switch (GUIMenuOption(Sender).Caption)
		{
		case ed_ChatPassword.Caption:
			sPwd = ed_ChatPassword.GetText();
			break;
		case sl_VoiceVol.Caption:
			fVoice = sl_VoiceVol.GetValue();
			break;
		case co_Quality.Caption:
			sCodec = co_Quality.GetExtra();
			break;
		case co_LANQuality.Caption:
			sLANCodec = co_LANQuality.GetExtra();
			break;
		case ch_AJPublic.Caption:
			bAJPublic = ch_AJPublic.IsChecked();
			break;
		case ch_AJLocal.Caption:
			bAJLocal = ch_AJLocal.IsChecked();
			break;
		case ch_AJTeam.Caption:
			bAJTeam = ch_AJTeam.IsChecked();
			break;
		case ch_AutoSpeak.Caption:
			bAutoSpeak = ch_AutoSpeak.IsChecked();
			if (bAutoSpeak)
			{
				EnableComponent(ed_Active);
			}
			else
			{
				DisableComponent(ed_Active);
			}
		case ed_Active.Caption:
			sActive = ed_Active.GetText();
		default:
		}
	}
	*/
}

void UVoiceChatConfig::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	local PlayerController PC;
	bool bSave = false;
	Super::Closed(Sender, bCancelled);
	PC = PlayerOwner();
	if (bAJPublic != bool((PC.AutoJoinMask & 1)))
	{
		if (bAJPublic)
		{
			PC.AutoJoinMask = byte((PC.AutoJoinMask | 1));
		}
		else
		{
			PC.AutoJoinMask = byte((PC.AutoJoinMask & (~1)));
		}
		bSave = true;
	}
	if (bAJLocal != bool((PC.AutoJoinMask & 2)))
	{
		if (bAJLocal)
		{
			PC.AutoJoinMask = byte((PC.AutoJoinMask | 2));
		}
		else
		{
			PC.AutoJoinMask = byte((PC.AutoJoinMask & (~2)));
		}
		bSave = true;
	}
	if (bAJTeam != bool((PC.AutoJoinMask & 4)))
	{
		if (bAJTeam)
		{
			PC.AutoJoinMask = byte((PC.AutoJoinMask | 4));
		}
		else
		{
			PC.AutoJoinMask = byte((PC.AutoJoinMask & (~4)));
		}
		bSave = true;
	}
	if (fVoice != float(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice VoiceVolume")))
	{
		PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice VoiceVolume" @ string(fVoice));
	}
	if (sCodec != PC.VoiceChatCodec)
	{
		PC.VoiceChatCodec = sCodec;
		bSave = true;
	}
	if (sLANCodec != PC.VoiceChatLANCodec)
	{
		PC.VoiceChatLANCodec = sLANCodec;
		bSave = true;
	}
	if (PC.bEnableInitialChatRoom != bAutoSpeak)
	{
		PC.bEnableInitialChatRoom = bAutoSpeak;
		bSave = true;
	}
	if (!(PC.DefaultActiveChannel ~= sActive))
	{
		PC.DefaultActiveChannel = sActive;
		bSave = true;
	}
	if (PC.ChatPassword != sPwd)
	{
		PC.SetChatPassword(sPwd);
		bSave = false;
	}
	if (bSave)
	{
		PC.SaveConfig();
	}
	*/
}

bool UVoiceChatConfig::ResetClick(UGUIComponent* Sender)
{
	/*
	int32 i = 0;
	FString str = "";
	local class<AudioSubsystem>  AudioClass;
	if (Sender == b_Cancel)
	{
		str = PlayerOwner().ConsoleCommand("get ini:Engine.Engine.AudioDevice Class");
		i = InStr(str, "'");
		if (i != -1)
		{
			str = Mid(str, (InStr(str, "'") + 1));
			str = Left(str, (Len(str) - 1));
		}
		AudioClass = class<AudioSubsystem>(DynamicLoadObject(str, Class'Class'));
		AudioClass.ResetConfig("VoiceVolume");
		Class'PlayerController'.ResetConfig("VoiceChatCodec");
		Class'PlayerController'.ResetConfig("VoiceChatLANCodec");
		Class'PlayerController'.ResetConfig("AutoJoinMask");
		Class'PlayerController'.ResetConfig("ChatPassword");
		Class'PlayerController'.ResetConfig("DefaultActiveChannel");
		Class'PlayerController'.ResetConfig("bEnableInitialChatRoom");
		for (i = 0; i < Components.Length; i++)
		{
			Components[i].LoadINI();
		}
	}
	*/
	return true;
}
