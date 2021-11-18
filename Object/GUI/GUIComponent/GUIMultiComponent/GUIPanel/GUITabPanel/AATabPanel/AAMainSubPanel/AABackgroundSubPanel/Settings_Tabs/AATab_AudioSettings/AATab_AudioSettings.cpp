// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/AATab_AudioSettings/AATab_AudioSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moSlider/moSlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAATab_AudioSettings::UAATab_AudioSettings()
{
	UmoSlider* AudioMusicVolume = NewObject<UmoSlider>(UmoSlider::StaticClass());
	AudioMusicVolume->MaxValue=1;
	AudioMusicVolume->Caption="Music Volume";
	//AudioMusicVolume->OnCreateComponent=AudioMusicVolume.InternalOnCreateComponent;
	AudioMusicVolume->IniOption="@Internal";
	AudioMusicVolume->IniDefault="0.5";
	AudioMusicVolume->Hint="Adjusts the volume of the background music.";
	AudioMusicVolume->WinTop=0.080522;
	AudioMusicVolume->WinLeft=0.02;
	AudioMusicVolume->WinWidth=0.45;
	AudioMusicVolume->TabOrder=0;
	//AudioMusicVolume->OnChange=AATab_AudioSettings.InternalOnChange;
	//AudioMusicVolume->OnLoadINI=AATab_AudioSettings.InternalOnLoadINI;
	UmoComboBox* AudioMode = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	AudioMode->bReadOnly=true;
	AudioMode->Caption="Audio Mode";
	//AudioMode->OnCreateComponent=AudioMode.InternalOnCreateComponent;
	AudioMode->IniOption="@Internal";
	AudioMode->IniDefault="Software 3D Audio";
	AudioMode->Hint="Changes the audio system mode.";
	AudioMode->WinTop=0.18;
	AudioMode->WinLeft=0.02;
	AudioMode->WinWidth=0.45;
	AudioMode->WinHeight=0.035;
	AudioMode->TabOrder=1;
	//AudioMode->OnChange=AATab_AudioSettings.InternalOnChange;
	//AudioMode->OnLoadINI=AATab_AudioSettings.InternalOnLoadINI;
	UmoCheckBox* AudioLowDetail = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AudioLowDetail->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioLowDetail->CaptionWidth=0.94;
	AudioLowDetail->Caption="Low Sound Detail";
	//AudioLowDetail->OnCreateComponent=AudioLowDetail.InternalOnCreateComponent;
	AudioLowDetail->IniOption="@Internal";
	AudioLowDetail->IniDefault="False";
	AudioLowDetail->Hint="Lowers quality of sound.";
	AudioLowDetail->WinTop=0.225052;
	AudioLowDetail->WinLeft=0.02;
	AudioLowDetail->WinWidth=0.45;
	AudioLowDetail->WinHeight=0.035;
	AudioLowDetail->TabOrder=2;
	AudioLowDetail->bStandardized=false;
	//AudioLowDetail->OnChange=AATab_AudioSettings.InternalOnChange;
	//AudioLowDetail->OnLoadINI=AATab_AudioSettings.InternalOnLoadINI;
	UmoCheckBox* AudioDefaultDriver = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AudioDefaultDriver->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioDefaultDriver->CaptionWidth=0.94;
	AudioDefaultDriver->Caption="System Driver";
	//AudioDefaultDriver->OnCreateComponent=AudioDefaultDriver.InternalOnCreateComponent;
	AudioDefaultDriver->IniOption="@Internal";
	AudioDefaultDriver->IniDefault="False";
	AudioDefaultDriver->Hint="Use system installed OpenAL driver";
	AudioDefaultDriver->WinTop=0.270365;
	AudioDefaultDriver->WinLeft=0.02;
	AudioDefaultDriver->WinWidth=0.45;
	AudioDefaultDriver->WinHeight=0.035;
	AudioDefaultDriver->TabOrder=3;
	AudioDefaultDriver->bStandardized=false;
	//AudioDefaultDriver->OnChange=AATab_AudioSettings.InternalOnChange;
	//AudioDefaultDriver->OnLoadINI=AATab_AudioSettings.InternalOnLoadINI;
	UmoCheckBox* AudioMessageBeep = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AudioMessageBeep->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioMessageBeep->CaptionWidth=0.94;
	AudioMessageBeep->Caption="Message Beep";
	//AudioMessageBeep->OnCreateComponent=AudioMessageBeep.InternalOnCreateComponent;
	AudioMessageBeep->IniOption="@Internal";
	AudioMessageBeep->IniDefault="True";
	AudioMessageBeep->Hint="Enables a beep when receiving a text message from other players.";
	AudioMessageBeep->WinTop=0.315678;
	AudioMessageBeep->WinLeft=0.02;
	AudioMessageBeep->WinWidth=0.45;
	AudioMessageBeep->WinHeight=0.035;
	AudioMessageBeep->TabOrder=9;
	AudioMessageBeep->bStandardized=false;
	//AudioMessageBeep->OnChange=AATab_AudioSettings.InternalOnChange;
	//AudioMessageBeep->OnLoadINI=AATab_AudioSettings.InternalOnLoadINI;
	UmoCheckBox* DisableESSIntroductionAudio = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DisableESSIntroductionAudio->ComponentJustification = EeTextAlign::TXTA_Left;
	DisableESSIntroductionAudio->CaptionWidth=0.94;
	DisableESSIntroductionAudio->Caption="Disable ES2 Initial Orders Audio";
	//DisableESSIntroductionAudio->OnCreateComponent=DisableESSIntroductionAudio.InternalOnCreateComponent;
	DisableESSIntroductionAudio->IniOption="@Internal";
	DisableESSIntroductionAudio->IniDefault="True";
	DisableESSIntroductionAudio->Hint="This disables playing the Every Soldier Is A Sensor (ES2) audio introduction once per match.  You will still see the console radio message.";
	DisableESSIntroductionAudio->WinTop=0.360991;
	DisableESSIntroductionAudio->WinLeft=0.02;
	DisableESSIntroductionAudio->WinWidth=0.45;
	DisableESSIntroductionAudio->WinHeight=0.035;
	DisableESSIntroductionAudio->TabOrder=10;
	DisableESSIntroductionAudio->bStandardized=false;
	//DisableESSIntroductionAudio->OnChange=AATab_AudioSettings.InternalOnChange;
	//DisableESSIntroductionAudio->OnLoadINI=AATab_AudioSettings.InternalOnLoadINI;
	UmoSlider* AudioEffectsVolumeSlider = NewObject<UmoSlider>(UmoSlider::StaticClass());
	AudioEffectsVolumeSlider->MaxValue=1;
	AudioEffectsVolumeSlider->Caption="Effects Volume";
	//AudioEffectsVolumeSlider->OnCreateComponent=AudioEffectsVolumeSlider.InternalOnCreateComponent;
	AudioEffectsVolumeSlider->IniOption="@Internal";
	AudioEffectsVolumeSlider->IniDefault="0.9";
	AudioEffectsVolumeSlider->Hint="Adjusts the volume of all in game sound effects.";
	AudioEffectsVolumeSlider->WinTop=0.1285;
	AudioEffectsVolumeSlider->WinLeft=0.02;
	AudioEffectsVolumeSlider->WinWidth=0.45;
	AudioEffectsVolumeSlider->TabOrder=5;
	//AudioEffectsVolumeSlider->OnChange=AATab_AudioSettings.InternalOnChange;
	//AudioEffectsVolumeSlider->OnLoadINI=AATab_AudioSettings.InternalOnLoadINI;
	UGUIImageButton* DolbyImageButton = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	DolbyImageButton->Caption="http://www.dolby.com/digital/";
	DolbyImageButton->link="http://www.americasarmy.com/redir.php?r=18";
	//DolbyImageButton->Image=Texture'T_AA2_UI.Menu.Logo_Dolby';
	DolbyImageButton->ImageStyle = EImgStyle::ISTY_Scaled;
	DolbyImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	DolbyImageButton->WinTop=0.080522;
	DolbyImageButton->WinLeft=0.52;
	DolbyImageButton->WinWidth=0.3;
	DolbyImageButton->WinHeight=0.1;
	//DolbyImageButton->OnClick=AATab_AudioSettings.ButtonClick;
	//DolbyImageButton->OnKeyEvent=DolbyImageButton.InternalOnKeyEvent;
	UGUIImageButton* EAXImageButton = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	EAXImageButton->Caption="http://www.soundblaster.com/eax";
	EAXImageButton->link="http://www.americasarmy.com/redir.php?r=19";
	//EAXImageButton->Image=Texture'T_AA2_UI.Menu.Logo_EAX';
	EAXImageButton->ImageStyle = EImgStyle::ISTY_Scaled;
	EAXImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	EAXImageButton->WinTop=0.080522;
	EAXImageButton->WinLeft=0.77;
	EAXImageButton->WinWidth=0.3;
	EAXImageButton->WinHeight=0.1;
	//EAXImageButton->OnClick=AATab_AudioSettings.ButtonClick;
	//EAXImageButton->OnKeyEvent=EAXImageButton.InternalOnKeyEvent;
	UmoSlider* AudioTTSVolumeSlider = NewObject<UmoSlider>(UmoSlider::StaticClass());
	AudioTTSVolumeSlider->MaxValue=1;
	AudioTTSVolumeSlider->CaptionWidth=0.65;
	AudioTTSVolumeSlider->Caption="Volume";
	//AudioTTSVolumeSlider->OnCreateComponent=AudioTTSVolumeSlider.InternalOnCreateComponent;
	AudioTTSVolumeSlider->IniOption="@Internal";
	AudioTTSVolumeSlider->Hint="Adjusts the volume of Text-To-Speech messages.";
	AudioTTSVolumeSlider->WinTop=0.52;
	AudioTTSVolumeSlider->WinLeft=0.02;
	AudioTTSVolumeSlider->WinWidth=0.45;
	AudioTTSVolumeSlider->TabOrder=14;
	//AudioTTSVolumeSlider->OnChange=AATab_AudioSettings.InternalOnChange;
	//AudioTTSVolumeSlider->OnLoadINI=AATab_AudioSettings.InternalOnLoadINI;
	UmoCheckBox* AudioEnableTTS = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AudioEnableTTS->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioEnableTTS->CaptionWidth=0.94;
	AudioEnableTTS->Caption="Enable In Game";
	//AudioEnableTTS->OnCreateComponent=AudioEnableTTS.InternalOnCreateComponent;
	AudioEnableTTS->IniOption="@Internal";
	AudioEnableTTS->IniDefault="False";
	AudioEnableTTS->Hint="Enables Text-To-Speech message processing";
	AudioEnableTTS->WinTop=0.58;
	AudioEnableTTS->WinLeft=0.02;
	AudioEnableTTS->WinWidth=0.45;
	AudioEnableTTS->WinHeight=0.035;
	AudioEnableTTS->TabOrder=15;
	AudioEnableTTS->bStandardized=false;
	//AudioEnableTTS->OnChange=AATab_AudioSettings.InternalOnChange;
	//AudioEnableTTS->OnLoadINI=AATab_AudioSettings.InternalOnLoadINI;
	UmoCheckBox* IRCTextToSpeech = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	IRCTextToSpeech->ComponentJustification = EeTextAlign::TXTA_Left;
	IRCTextToSpeech->CaptionWidth=0.94;
	IRCTextToSpeech->Caption="Enable on IRC";
	//IRCTextToSpeech->OnCreateComponent=IRCTextToSpeech.InternalOnCreateComponent;
	IRCTextToSpeech->IniOption="@Internal";
	IRCTextToSpeech->Hint="Enables Text-To-Speech processing in the IRC client (only messages from active tab is processed)";
	IRCTextToSpeech->WinTop=0.64;
	IRCTextToSpeech->WinLeft=0.02;
	IRCTextToSpeech->WinWidth=0.45;
	IRCTextToSpeech->WinHeight=0.035;
	IRCTextToSpeech->TabOrder=16;
	IRCTextToSpeech->bStandardized=false;
	//IRCTextToSpeech->OnChange=AATab_AudioSettings.InternalOnChange;
	//IRCTextToSpeech->OnLoadINI=AATab_AudioSettings.InternalOnLoadINI;
	UmoCheckBox* OnlyTeamTTSCheck = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	OnlyTeamTTSCheck->ComponentJustification = EeTextAlign::TXTA_Left;
	OnlyTeamTTSCheck->CaptionWidth=0.94;
	OnlyTeamTTSCheck->Caption="Team Messages Only";
	//OnlyTeamTTSCheck->OnCreateComponent=OnlyTeamTTSCheck.InternalOnCreateComponent;
	OnlyTeamTTSCheck->IniOption="@Internal";
	OnlyTeamTTSCheck->Hint="If enabled, only team messages will be spoken in team games, unless the match or round is over.";
	OnlyTeamTTSCheck->WinTop=0.7;
	OnlyTeamTTSCheck->WinLeft=0.02;
	OnlyTeamTTSCheck->WinWidth=0.45;
	OnlyTeamTTSCheck->WinHeight=0.035;
	OnlyTeamTTSCheck->TabOrder=17;
	OnlyTeamTTSCheck->bStandardized=false;
	//OnlyTeamTTSCheck->OnChange=AATab_AudioSettings.InternalOnChange;
	//OnlyTeamTTSCheck->OnLoadINI=AATab_AudioSettings.InternalOnLoadINI;
	UGUILabel* DolbyText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DolbyText->Caption="DOLBY and the Double-D symbol are trademarks of Dolby Laboratories.";
	DolbyText->TextAlign = ETextAlign::TXTA_Center;
	DolbyText->TextColor=FColor(255, 255, 255, 255);
	DolbyText->TextFont="AAFontSmall";
	DolbyText->bMultiLine=true;
	DolbyText->WinTop=0.22;
	DolbyText->WinLeft=0.52;
	DolbyText->WinWidth=0.45;
	DolbyText->WinHeight=0.1;
	UGUILabel* EAXText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	EAXText->Caption="NVIDIA® nForce(TM) or other motherboards/soundboards containing the Dolby® Digital Interactive Content Encoder Required for Dolby Digital Audio.";
	EAXText->TextAlign = ETextAlign::TXTA_Center;
	EAXText->TextColor=FColor(255, 255, 255, 255);
	EAXText->TextFont="AAFontSmall";
	EAXText->bMultiLine=true;
	EAXText->WinTop=0.3;
	EAXText->WinLeft=0.52;
	EAXText->WinWidth=0.45;
	EAXText->WinHeight=0.1;
	UGUILabel* TextToSpeechLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TextToSpeechLabel->Caption="Text-To-Speech Settings:";
	TextToSpeechLabel->TextAlign = ETextAlign::TXTA_Center;
	TextToSpeechLabel->TextColor=FColor(156, 201, 168, 255);
	TextToSpeechLabel->TextFont="AAFontMedium";
	TextToSpeechLabel->bMultiLine=true;
	TextToSpeechLabel->WinTop=0.48;
	TextToSpeechLabel->WinLeft=0.02;
	TextToSpeechLabel->WinWidth=0.45;
	TextToSpeechLabel->WinHeight=0.075;
	
	AudioModes = { "Safe Mode","3D Audio","H/W 3D Audio","H/W 3D + EAX" };
	sl_MusicVol = AudioMusicVolume;
	sl_EffectsVol = AudioEffectsVolumeSlider;
	sl_TTS = AudioTTSVolumeSlider;
	co_Mode = AudioMode;
	ch_MessageBeep = AudioMessageBeep;
	ch_TTSIRC = IRCTextToSpeech;
	ch_OnlyTeamTTS = OnlyTeamTTSCheck;
	ch_LowDetail = AudioLowDetail;
	ch_Default = AudioDefaultDriver;
	ch_TTS = AudioEnableTTS;
	mchkbDisableESSIntroduction = DisableESSIntroductionAudio;
	ib_Dolby = DolbyImageButton;
	ib_EAX = EAXImageButton;
	l_Dolby = DolbyText;
	l_EAX = EAXText;
	l_TTS = TextToSpeechLabel;
	VoiceChatConfigMenu = "AGP_Interface.AAVoiceChatConfig";
	sCannotChangeAudioDetails = "You cannot change the audio driver while attached to a game server.  Disconnect from the server before changing audio drivers.";
	sCannotChangeAudioTitle = "Cannot Change Audio Driver Now";
	PanelCaption = "Audio";
	WinTop = 0.15;
	WinHeight = 0.74;
}


void UAATab_AudioSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	bool bIsWin32 = false;
	bIsWin32 = (PlatformIsWindows() && (!PlatformIs64Bit()));
	Super::InitComponent(MyController, MyOwner);
	if (bIsWin32)
	{
		for (i = 0; i < 4; i++)
		{
			co_Mode.addItem(AudioModes[i]);
		}
	}
	else
	{
		co_Mode.addItem("OpenAL");
	}
	if (!PlatformIsWindows())
	{
		ch_Default.DisableMe();
	}
	*/
}

void UAATab_AudioSettings::ResetClicked()
{
	/*
	local class<AudioSubsystem>  A;
	local PlayerController PC;
	int32 i = 0;
	Super::ResetClicked();
	PC = PlayerOwner();
	A = class<AudioSubsystem>(DynamicLoadObject(GetNativeClassName("Engine.Engine.AudioDevice"), Class'Class'));
	A.ResetConfig();
	Class'HUD'.ResetConfig("bMessageBeep");
	Class'LevelInfo'.ResetConfig("bLowSoundDetail");
	Class'PlayerController'.ResetConfig("bNoMatureLanguage");
	Class'PlayerController'.ResetConfig("bNoTextToSpeechVoiceMessages");
	Class'PlayerController'.ResetConfig("TextToSpeechVoiceVolume");
	Class'PlayerController'.ResetConfig("bOnlySpeakTeamText");
	class'AGP_Interface.AAIRC_Page'.ResetConfig("bIRCTextToSpeechEnabled");
	for (i = 0; i < Components.Length; i++)
	{
		Components[i].LoadINI();
	}
	*/
}

void UAATab_AudioSettings::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	local PlayerController PC;
	bool bIsWin32 = false;
	PC = PlayerOwner();
	switch (Sender)
	{
	case sl_MusicVol:
		fMusic = float(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice MusicVolume"));
		sl_MusicVol.SetComponentValue(string(fMusic), true);
		break;
	case sl_EffectsVol:
		fEffects = float(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice SoundVolume"));
		sl_EffectsVol.SetComponentValue(string(fEffects), true);
		break;
	case sl_TTS:
		fTTS = PC.Default.TextToSpeechVoiceVolume;
		sl_TTS.SetComponentValue(string(fTTS), true);
		break;
	case co_Mode:
		iMode = 1;
		bIsWin32 = (PlatformIsWindows() && (!PlatformIs64Bit()));
		if (!bIsWin32)
		{
			bCompat = false;
			b3DSound = true;
			iMode = 0;
		}
		else
		{
			if (bool(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice CompatibilityMode")))
			{
				bCompat = true;
				iMode = 0;
			}
			if (bool(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice Use3DSound")))
			{
				b3DSound = true;
				iMode = 2;
			}
			if (bool(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice UseEAX")))
			{
				bEAX = true;
				iMode = 3;
			}
		}
		co_Mode.SilentSetIndex(iMode);
		GOTO JL0655;
	case ch_Default:
		bDefault = bool(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice UseDefaultDriver"));
		ch_Default.SetComponentValue(string(bDefault), true);
		GOTO JL0655;
	case ch_MessageBeep:
		bBeep = Class'HUD'.Default.bMessageBeep;
		ch_MessageBeep.SetComponentValue(string(bBeep), true);
		GOTO JL0655;
	case mchkbDisableESSIntroduction:
		bDisableESSIntroduction = HumanController(PC).Default.bDisableES2Introduction;
		mchkbDisableESSIntroduction.SetComponentValue(string(bDisableESSIntroduction), true);
		GOTO JL0655;
	case ch_TTS:
		bTTS = (!PC.Default.bNoTextToSpeechVoiceMessages);
		ch_TTS.SetComponentValue(string(bTTS), true);
		GOTO JL0655;
	case ch_OnlyTeamTTS:
		bOnlyTeamTTS = PC.bOnlySpeakTeamText;
		ch_OnlyTeamTTS.SetComponentValue(string(bOnlyTeamTTS), true);
		GOTO JL0655;
	case ch_LowDetail:
		bLow = PC.Level.bLowSoundDetail;
		if (bLow != bool(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice LowQualitySound")))
		{
			PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice LowQualitySound" @ string(bLow));
			PC.ConsoleCommand("SOUND_REBOOT");
			if ((PC.Level.Song != "") && (PC.Level.Song != "None"))
			{
				PC.ClientSetMusic(PC.Level.Song, 1);
			}
			else
			{
				PC.ClientSetMusic(class'AGP_Interface.AAEntryPage'.Default.MenuSong, 1);
			}
		}
		ch_LowDetail.SetComponentValue(string(bLow), true);
		GOTO JL0655;
	case ch_TTSIRC:
		bTTSIRC = class'AGP_Interface.AAIRC_Page'.Default.bIRCTextToSpeechEnabled;
		ch_TTSIRC.SetComponentValue(string(bTTSIRC), true);
		GOTO JL0655;
	case ch_VoiceChat:
		bVoiceChat = bool(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice UseVoIP"));
		ch_VoiceChat.SetComponentValue(string(bVoiceChat), true);
		GOTO JL0655;
	default:
		Log(string(Name) @ "Unknown component calling LoadINI:" $ GUIMenuOption(Sender).Caption);
		GUIMenuOption(Sender).SetComponentValue(S, true);
	JL0655:
	}
	*/
}

void UAATab_AudioSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local PlayerController PC;
	bool bIsWin32 = false;
	bIsWin32 = (PlatformIsWindows() && (!PlatformIs64Bit()));
	Super::InternalOnChange(Sender);
	PC = PlayerOwner();
	switch (Sender)
	{
	case sl_MusicVol:
		fMusic = sl_MusicVol.GetValue();
		PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice MusicVolume" @ string(fMusic));
		PC.ConsoleCommand("SetMusicVolume" @ string(fMusic));
		if ((PC.Level.Song != "") && (PC.Level.Song != "None"))
		{
			PC.ClientSetMusic(PC.Level.Song, 1);
			break;
		}
		PC.ClientSetMusic(class'AGP_Interface.AAEntryPage'.Default.MenuSong, 1);
	}
	GOTO JL0727;
	case sl_EffectsVol:
		fEffects = sl_EffectsVol.GetValue();
		PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice SoundVolume" @ string(fEffects));
		PC.ConsoleCommand("stopsounds");
		GOTO JL0727;
	case sl_TTS:
		fTTS = sl_TTS.GetValue();
		GOTO JL0727;
	case co_Mode:
		if (!bIsWin32)
		{
			GOTO JL0727;
		}
		if (PC.Level.NetMode == NM_Client)
		{
			co_Mode.SilentSetIndex(iMode);
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", sCannotChangeAudioTitle, sCannotChangeAudioDetails);
		}
		else
		{
			iMode = co_Mode.GetIndex();
			if (iMode > 1)
			{
				ShowPerformanceWarning();
			}
			bCompat = (iMode < 1);
			b3DSound = (iMode > 1);
			bEAX = (iMode > 2);
			PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice CompatibilityMode" @ string(bCompat));
			PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice Use3DSound" @ string(b3DSound));
			PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice UseEAX" @ string(bEAX));
			PC.ConsoleCommand("SOUND_REBOOT");
			if ((PC.Level.Song != "") && (PC.Level.Song != "None"))
			{
				PC.ClientSetMusic(PC.Level.Song, 1);
			}
			else
			{
				PC.ClientSetMusic(class'AGP_Interface.AAEntryPage'.Default.MenuSong, 1);
			}
	case ch_MessageBeep:
		bBeep = ch_MessageBeep.IsChecked();
	case ch_Default:
		bDefault = ch_Default.IsChecked();
		PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice UseDefaultDriver" @ string(bDefault));
		PC.ConsoleCommand("SOUND_REBOOT");
	case ch_LowDetail:
		bLow = ch_LowDetail.IsChecked();
		Class'LevelInfo'.Default.bLowSoundDetail = bLow;
		Class'LevelInfo'.StaticSaveConfig();
		PC.Level.bLowSoundDetail = bLow;
		PC.Level.StaticSaveConfig();
		PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice LowQualitySound" @ string(bLow));
		PC.ConsoleCommand("SOUND_REBOOT");
		if ((PC.Level.Song != "") && (PC.Level.Song != "None"))
		{
			PC.ClientSetMusic(PC.Level.Song, 1);
		}
		else
		{
			PC.ClientSetMusic(class'AGP_Interface.AAEntryPage'.Default.MenuSong, 1);
		}
	case mchkbDisableESSIntroduction:
		bDisableESSIntroduction = mchkbDisableESSIntroduction.IsChecked();
	case ch_TTS:
		bTTS = ch_TTS.IsChecked();
	case ch_TTSIRC:
		bTTSIRC = ch_TTSIRC.IsChecked();
	case ch_VoiceChat:
		bVoiceChat = ch_VoiceChat.IsChecked();
	case ch_OnlyTeamTTS:
		bOnlyTeamTTS = ch_OnlyTeamTTS.IsChecked();
	default:
	JL0727:
		}
		SaveSettings();
	*/
}

void UAATab_AudioSettings::SaveSettings()
{
	/*
	local PlayerController PC;
	bool bSave = false;
	bool bReboot = false;
	float fTemp = 0;
	local AAIRC_Page MyPage;
	Super::SaveSettings();
	PC = PlayerOwner();
	if (PC.TextToSpeechVoiceVolume != fTTS)
	{
		PC.TextToSpeechVoiceVolume = fTTS;
		PC.Default.TextToSpeechVoiceVolume = fTTS;
		bSave = true;
	}
	if (PC.bOnlySpeakTeamText != bOnlyTeamTTS)
	{
		PC.bOnlySpeakTeamText = bOnlyTeamTTS;
		bSave = true;
	}
	if (PC.bNoTextToSpeechVoiceMessages == bTTS)
	{
		PC.bNoTextToSpeechVoiceMessages = (!bTTS);
		PC.Default.bNoTextToSpeechVoiceMessages = (!bTTS);
		bSave = true;
	}
	if (class'AGP_Interface.AAIRC_Page'.Default.bIRCTextToSpeechEnabled != bTTSIRC)
	{
		ForEach AllObjects(class'AGP_Interface.AAIRC_Page', MyPage)
		{
			MyPage.bIRCTextToSpeechEnabled = bTTSIRC;
		}
		class'AGP_Interface.AAIRC_Page'.Default.bIRCTextToSpeechEnabled = bTTSIRC;
		class'AGP_Interface.AAIRC_Page'.StaticSaveConfig();
	}
	if (PC.bNoMatureLanguage == bMature)
	{
		PC.bNoMatureLanguage = (!bMature);
		PC.Default.bNoMatureLanguage = (!bMature);
		bSave = true;
	}
	if (bDisableESSIntroduction != HumanController(PC).bDisableES2Introduction)
	{
		HumanController(PC).bDisableES2Introduction = bDisableESSIntroduction;
		bSave = true;
	}
	fTemp = float(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice MusicVolume" @ string(fMusic)));
	if (fTemp != sl_MusicVol.GetValue())
	{
		PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice MusicVolume" @ string(fMusic));
	}
	if (fEffects != sl_EffectsVol.GetValue())
	{
		PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice SoundVolume" @ string(fEffects));
	}
	if (bool(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice ReverseStereo")) != bRev)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice ReverseStereo" @ string(bRev));
	}
	if (bDefault != bool(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice UseDefaultDriver")))
	{
		PC.ConsoleCommand("set ini:Engine.Engine.AudioDevice UseDefaultDriver" @ string(bDefault));
		bReboot = true;
	}
	if (PC.myHUD != None)
	{
		if (PC.myHUD.bMessageBeep != bBeep)
		{
			PC.myHUD.bMessageBeep = bBeep;
			PC.myHUD.SaveConfig();
		}
	}
	else
	{
		if (Class'HUD'.Default.bMessageBeep != bBeep)
		{
			Class'HUD'.Default.bMessageBeep = bBeep;
			Class'HUD'.StaticSaveConfig();
		}
	}
	if (bVoiceChat != bool(PC.ConsoleCommand("get ini:Engine.Engine.AudioDevice UseVoIP")))
	{
		if (bVoiceChat)
		{
			PC.EnableVoiceChat();
		}
		else
		{
			PC.DisableVoiceChat();
		}
		bReboot = false;
	}
	if (bSave)
	{
		PC.SaveConfig();
	}
	if (PC.bAutoTaunt != bAuto)
	{
		PC.SetAutoTaunt(bAuto);
	}
	if (bReboot)
	{
		PC.ConsoleCommand("SOUND_REBOOT");
	}
	*/
}

bool UAATab_AudioSettings::ButtonClick(UGUIComponent* Sender)
{
	/*
	if (Sender == ib_Dolby)
	{
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", ib_Dolby.Caption, ib_Dolby.link);
	}
	else
	{
		if (Sender == ib_EAX)
		{
			Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", ib_EAX.Caption, ib_EAX.link);
		}
	}
	*/
	return true;
}