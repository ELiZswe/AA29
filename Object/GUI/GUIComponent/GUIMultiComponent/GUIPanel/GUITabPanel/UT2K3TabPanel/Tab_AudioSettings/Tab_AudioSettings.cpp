// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_AudioSettings/Tab_AudioSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUISlider/GUISlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UTab_AudioSettings::UTab_AudioSettings()
{
	UGUISlider* AudioMusicVolumeSlider = NewObject<UGUISlider>(UGUISlider::StaticClass());
	AudioMusicVolumeSlider->MaxValue=1;
	AudioMusicVolumeSlider->IniOption="ini:Engine.Engine.AudioDevice MusicVolume";
	AudioMusicVolumeSlider->IniDefault="0.5";
	AudioMusicVolumeSlider->Hint="Changes the volume of the background music.";
	AudioMusicVolumeSlider->WinTop=0.156146;
	AudioMusicVolumeSlider->WinLeft=0.0625;
	AudioMusicVolumeSlider->WinWidth=0.25;
	//AudioMusicVolumeSlider->OnClick=AudioMusicVolumeSlider.InternalOnClick;
	//AudioMusicVolumeSlider->OnMousePressed=AudioMusicVolumeSlider.InternalOnMousePressed;
	//AudioMusicVolumeSlider->OnMouseRelease=AudioMusicVolumeSlider.InternalOnMouseRelease;
	//AudioMusicVolumeSlider->OnKeyEvent=AudioMusicVolumeSlider.InternalOnKeyEvent;
	//AudioMusicVolumeSlider->OnCapturedMouseMove=AudioMusicVolumeSlider.InternalCapturedMouseMove;
	UGUISlider* AudioEffectsVolumeSlider = NewObject<UGUISlider>(UGUISlider::StaticClass());
	AudioEffectsVolumeSlider->MaxValue=1;
	AudioEffectsVolumeSlider->IniOption="ini:Engine.Engine.AudioDevice SoundVolume";
	AudioEffectsVolumeSlider->IniDefault="0.9";
	AudioEffectsVolumeSlider->Hint="Changes the volume of all in game sound effects.";
	AudioEffectsVolumeSlider->WinTop=0.156146;
	AudioEffectsVolumeSlider->WinLeft=0.6875;
	AudioEffectsVolumeSlider->WinWidth=0.25;
	//AudioEffectsVolumeSlider->OnClick=AudioEffectsVolumeSlider.InternalOnClick;
	//AudioEffectsVolumeSlider->OnMousePressed=AudioEffectsVolumeSlider.InternalOnMousePressed;
	//AudioEffectsVolumeSlider->OnMouseRelease=AudioEffectsVolumeSlider.InternalOnMouseRelease;
	//AudioEffectsVolumeSlider->OnKeyEvent=AudioEffectsVolumeSlider.InternalOnKeyEvent;
	//AudioEffectsVolumeSlider->OnCapturedMouseMove=AudioEffectsVolumeSlider.InternalCapturedMouseMove;
	UGUISlider* AudioVoiceVolumeSlider = NewObject<UGUISlider>(UGUISlider::StaticClass());
	AudioVoiceVolumeSlider->MinValue=1;
	AudioVoiceVolumeSlider->MaxValue=4;
	AudioVoiceVolumeSlider->bIntSlider=true;
	AudioVoiceVolumeSlider->IniOption="@Internal";
	AudioVoiceVolumeSlider->Hint="Changes the volume of all in game voice messages.";
	AudioVoiceVolumeSlider->WinTop=0.156146;
	AudioVoiceVolumeSlider->WinLeft=0.375;
	AudioVoiceVolumeSlider->WinWidth=0.25;
	//AudioVoiceVolumeSlider->OnClick=AudioVoiceVolumeSlider.InternalOnClick;
	//AudioVoiceVolumeSlider->OnMousePressed=AudioVoiceVolumeSlider.InternalOnMousePressed;
	//AudioVoiceVolumeSlider->OnMouseRelease=AudioVoiceVolumeSlider.InternalOnMouseRelease;
	//AudioVoiceVolumeSlider->OnKeyEvent=AudioVoiceVolumeSlider.InternalOnKeyEvent;
	//AudioVoiceVolumeSlider->OnCapturedMouseMove=AudioVoiceVolumeSlider.InternalCapturedMouseMove;
	//AudioVoiceVolumeSlider->OnLoadINI=Tab_AudioSettings.InternalOnLoadINI;
	UmoComboBox* AudioMode = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	AudioMode->bReadOnly=true;
	AudioMode->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioMode->CaptionWidth=0.3;
	AudioMode->Caption="Audio Mode";
	//AudioMode->OnCreateComponent=AudioMode.InternalOnCreateComponent;
	AudioMode->IniOption="@Internal";
	AudioMode->IniDefault="Software 3D Audio";
	AudioMode->Hint="Changes the audio system mode.";
	AudioMode->WinTop=0.278646;
	AudioMode->WinLeft=0.15;
	AudioMode->WinWidth=0.7;
	AudioMode->WinHeight=0.06;
	//AudioMode->OnLoadINI=Tab_AudioSettings.InternalOnLoadINI;
	//AudioMode->OnSaveINI=Tab_AudioSettings.InternalOnSaveINI;
	UmoCheckBox* AudioReverseStereo = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AudioReverseStereo->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioReverseStereo->CaptionWidth=0.9;
	AudioReverseStereo->Caption="Reverse Stereo";
	//AudioReverseStereo->OnCreateComponent=AudioReverseStereo.InternalOnCreateComponent;
	AudioReverseStereo->IniOption="ini:Engine.Engine.AudioDevice ReverseStereo";
	AudioReverseStereo->IniDefault="False";
	AudioReverseStereo->Hint="Reverses the left and right audio channels.";
	AudioReverseStereo->WinTop=0.433333;
	AudioReverseStereo->WinLeft=0.1;
	AudioReverseStereo->WinWidth=0.3;
	AudioReverseStereo->WinHeight=0.04;
	//AudioReverseStereo->OnLoadINI=Tab_AudioSettings.InternalOnLoadINI;
	//AudioReverseStereo->OnSaveINI=Tab_AudioSettings.InternalOnSaveINI;
	UmoCheckBox* AudioMessageBeep = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AudioMessageBeep->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioMessageBeep->CaptionWidth=0.9;
	AudioMessageBeep->Caption="Message Beep";
	//AudioMessageBeep->OnCreateComponent=AudioMessageBeep.InternalOnCreateComponent;
	AudioMessageBeep->IniOption="@Internal";
	AudioMessageBeep->IniDefault="True";
	AudioMessageBeep->Hint="Enables a beep when receiving a text message from other players.";
	AudioMessageBeep->WinTop=0.433333;
	AudioMessageBeep->WinLeft=0.6;
	AudioMessageBeep->WinWidth=0.3;
	AudioMessageBeep->WinHeight=0.04;
	//AudioMessageBeep->OnLoadINI=Tab_AudioSettings.InternalOnLoadINI;
	//AudioMessageBeep->OnSaveINI=Tab_AudioSettings.InternalOnSaveINI;
	UmoCheckBox* AudioAutoTaunt = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AudioAutoTaunt->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioAutoTaunt->CaptionWidth=0.9;
	AudioAutoTaunt->Caption="Auto-Taunt";
	//AudioAutoTaunt->OnCreateComponent=AudioAutoTaunt.InternalOnCreateComponent;
	AudioAutoTaunt->IniOption="@Internal";
	AudioAutoTaunt->IniDefault="True";
	AudioAutoTaunt->Hint="Enables your in-game player to automatically taunt opponents.";
	AudioAutoTaunt->WinTop=0.533333;
	AudioAutoTaunt->WinLeft=0.1;
	AudioAutoTaunt->WinWidth=0.3;
	AudioAutoTaunt->WinHeight=0.04;
	//AudioAutoTaunt->OnLoadINI=Tab_AudioSettings.InternalOnLoadINI;
	//AudioAutoTaunt->OnSaveINI=Tab_AudioSettings.InternalOnSaveINI;
	UmoCheckBox* AudioMatureTaunts = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AudioMatureTaunts->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioMatureTaunts->CaptionWidth=0.9;
	AudioMatureTaunts->Caption="Mature Taunts";
	//AudioMatureTaunts->OnCreateComponent=AudioMatureTaunts.InternalOnCreateComponent;
	AudioMatureTaunts->IniOption="@Internal";
	AudioMatureTaunts->IniDefault="True";
	AudioMatureTaunts->Hint="Enables off-color commentary.";
	AudioMatureTaunts->WinTop=0.53333;
	AudioMatureTaunts->WinLeft=0.6;
	AudioMatureTaunts->WinWidth=0.3;
	AudioMatureTaunts->WinHeight=0.04;
	//AudioMatureTaunts->OnLoadINI=Tab_AudioSettings.InternalOnLoadINI;
	//AudioMatureTaunts->OnSaveINI=Tab_AudioSettings.InternalOnSaveINI;
	UmoCheckBox* AudioLowDetail = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AudioLowDetail->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioLowDetail->CaptionWidth=0.9;
	AudioLowDetail->Caption="Low Sound Detail";
	//AudioLowDetail->OnCreateComponent=AudioLowDetail.InternalOnCreateComponent;
	AudioLowDetail->IniOption="@Internal";
	AudioLowDetail->IniDefault="False";
	AudioLowDetail->Hint="Lowers quality of sound.";
	AudioLowDetail->WinTop=0.63333;
	AudioLowDetail->WinLeft=0.1;
	AudioLowDetail->WinWidth=0.3;
	AudioLowDetail->WinHeight=0.04;
	//AudioLowDetail->OnLoadINI=Tab_AudioSettings.InternalOnLoadINI;
	//AudioLowDetail->OnSaveINI=Tab_AudioSettings.InternalOnSaveINI;
	UmoComboBox* AudioPlayVoices = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	AudioPlayVoices->bReadOnly=true;
	AudioPlayVoices->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioPlayVoices->Caption="Play Voices";
	//AudioPlayVoices->OnCreateComponent=AudioPlayVoices.InternalOnCreateComponent;
	AudioPlayVoices->IniOption="@Internal";
	AudioPlayVoices->IniDefault="All";
	AudioPlayVoices->Hint="Defines the types of voice messages to play.";
	AudioPlayVoices->WinTop=0.733291;
	AudioPlayVoices->WinLeft=0.260352;
	AudioPlayVoices->WinWidth=0.46875;
	AudioPlayVoices->WinHeight=0.06;
	//AudioPlayVoices->OnLoadINI=Tab_AudioSettings.InternalOnLoadINI;
	//AudioPlayVoices->OnSaveINI=Tab_AudioSettings.InternalOnSaveINI;
	UmoComboBox* AudioAnnounce = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	AudioAnnounce->bReadOnly=true;
	AudioAnnounce->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioAnnounce->Caption="Announcements";
	//AudioAnnounce->OnCreateComponent=AudioAnnounce.InternalOnCreateComponent;
	AudioAnnounce->IniOption="@Internal";
	AudioAnnounce->IniDefault="All";
	AudioAnnounce->Hint="Adjusts the amount of in-game announcements.";
	AudioAnnounce->WinTop=0.816597;
	AudioAnnounce->WinLeft=0.260352;
	AudioAnnounce->WinWidth=0.46875;
	AudioAnnounce->WinHeight=0.06;
	//AudioAnnounce->OnLoadINI=Tab_AudioSettings.InternalOnLoadINI;
	//AudioAnnounce->OnSaveINI=Tab_AudioSettings.InternalOnSaveINI;
	UmoComboBox* AudioAnnouncerPack = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	AudioAnnouncerPack->bReadOnly=true;
	AudioAnnouncerPack->ComponentJustification = EeTextAlign::TXTA_Left;
	AudioAnnouncerPack->Caption="Announcer Voice";
	//AudioAnnouncerPack->OnCreateComponent=AudioAnnouncerPack.InternalOnCreateComponent;
	AudioAnnouncerPack->IniOption="@Internal";
	AudioAnnouncerPack->Hint="Select the Announcer for tonight's game.";
	AudioAnnouncerPack->WinTop=0.900069;
	AudioAnnouncerPack->WinLeft=0.260352;
	AudioAnnouncerPack->WinWidth=0.46875;
	AudioAnnouncerPack->WinHeight=0.06;
	//AudioAnnouncerPack->OnLoadINI=Tab_AudioSettings.InternalOnLoadINI;
	//AudioAnnouncerPack->OnSaveINI=Tab_AudioSettings.InternalOnSaveINI;
	UGUIImage* AudioBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//AudioBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	AudioBK1->ImageColor=FColor(255, 255, 255, 160);
	AudioBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	AudioBK1->WinTop=0.083281;
	AudioBK1->WinLeft=0.021641;
	AudioBK1->WinWidth=0.9575;
	AudioBK1->WinHeight=0.166289;
	UGUIImage* AudioBK2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//AudioBK2->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	AudioBK2->ImageColor=FColor(255, 255, 255, 160);
	AudioBK2->ImageStyle = EImgStyle::ISTY_Stretched;
	AudioBK2->WinTop=0.362446;
	AudioBK2->WinLeft=0.021641;
	AudioBK2->WinWidth=0.9575;
	AudioBK2->WinHeight=0.625897;
	UGUILabel* AudioMusicVolumeLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	AudioMusicVolumeLabel->Caption="Music Volume";
	AudioMusicVolumeLabel->TextAlign = ETextAlign::TXTA_Center;
	AudioMusicVolumeLabel->TextColor=FColor(255, 255, 255, 255);
	AudioMusicVolumeLabel->WinTop=0.1;
	AudioMusicVolumeLabel->WinLeft=0.055664;
	AudioMusicVolumeLabel->WinWidth=0.25;
	AudioMusicVolumeLabel->WinHeight=32;
	UGUILabel* AudioEffectsVolumeLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	AudioEffectsVolumeLabel->Caption="Effects Volume";
	AudioEffectsVolumeLabel->TextAlign = ETextAlign::TXTA_Center;
	AudioEffectsVolumeLabel->TextColor=FColor(255, 255, 255, 255);
	AudioEffectsVolumeLabel->WinTop=0.1;
	AudioEffectsVolumeLabel->WinLeft=0.685547;
	AudioEffectsVolumeLabel->WinWidth=0.25;
	AudioEffectsVolumeLabel->WinHeight=32;
	UGUILabel* AudioVoiceVolumeLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	AudioVoiceVolumeLabel->Caption="Announcer Volume";
	AudioVoiceVolumeLabel->TextAlign = ETextAlign::TXTA_Center;
	AudioVoiceVolumeLabel->TextColor=FColor(255, 255, 255, 255);
	AudioVoiceVolumeLabel->WinTop=0.1;
	AudioVoiceVolumeLabel->WinLeft=0.369141;
	AudioVoiceVolumeLabel->WinWidth=0.25;
	AudioVoiceVolumeLabel->WinHeight=32;

	AudioModes = { "Software 3D Audio","Hardware 3D Audio","Hardware 3D Audio + EAX","Safe Mode" };
	VoiceModes = { "All","No auto-taunts","No taunts","None" };
	AnnounceModes = { "None","Minimal","All" };

	Controls = { AudioBK1,AudioBK2,AudioMusicVolumeLabel,AudioMusicVolumeSlider,AudioEffectsVolumeLabel,AudioEffectsVolumeSlider,AudioVoiceVolumeLabel,AudioVoiceVolumeSlider,AudioMode,AudioReverseStereo,AudioMessageBeep,AudioAutoTaunt,AudioMatureTaunts,AudioLowDetail,AudioPlayVoices,AudioAnnouncerPack };
	WinTop = 0.15;
	WinHeight = 0.74;
}

void UTab_AudioSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	FString DefPack = "";
	Super::InitComponent(MyController, MyOwner);
	bInitialized = false;
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].__OnChange__Delegate = InternalOnChange;
	}
	for (i = 0; i < 4; i++)
	{
		moComboBox(Controls[8]).addItem(AudioModes[i]);
	}
	for (i = 0; i < 4; i++)
	{
		moComboBox(Controls[14]).addItem(VoiceModes[i]);
	}
	for (i = 0; i < 3; i++)
	{
		moComboBox(Controls[15]).addItem(AnnounceModes[i]);
	}
	Controls[3].FriendlyLabel = GUILabel(Controls[2]);
	Controls[5].FriendlyLabel = GUILabel(Controls[4]);
	APack = moComboBox(Controls[16]);
	for (i = 0; i < 4; i++)
	{
		if (BonusPackInfo[i].Description != "")
		{
			APack.addItem(BonusPackInfo[i].Description, None, BonusPackInfo[i].PackageName);
			if (BonusPackInfo[i].PackageName ~= DefPack)
			{
				APack.SetText(BonusPackInfo[i].Description);
			}
		}
	}
	for (i = 0; i < PackInfo.Length; i++)
	{
		APack.addItem(PackInfo[i].Description, None, PackInfo[i].PackageName);
		if (PackInfo[i].PackageName ~= DefPack)
		{
			APack.SetText(PackInfo[i].Description);
		}
	}
	bInitialized = true;
	*/
}

void UTab_AudioSettings::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	bool b1 = false;
	bool b2 = false;
	bool b3 = false;
	if (Sender == Controls[7])
	{
		GUISlider(Controls[7]).SetValue(float(PlayerOwner().AnnouncerVolume));
	}
	else
	{
		if (Sender == Controls[8])
		{
			b1 = bool(PlayerOwner().ConsoleCommand("get ini:Engine.Engine.AudioDevice UseEAX"));
			b2 = bool(PlayerOwner().ConsoleCommand("get ini:Engine.Engine.AudioDevice CompatibilityMode"));
			b3 = bool(PlayerOwner().ConsoleCommand("get ini:Engine.Engine.AudioDevice Use3DSound"));
			if (b2)
			{
				moComboBox(Controls[8]).SetText(AudioModes[3]);
			}
			else
			{
				if (b1)
				{
					moComboBox(Controls[8]).SetText(AudioModes[2]);
				}
				else
				{
					if (b3)
					{
						moComboBox(Controls[8]).SetText(AudioModes[1]);
					}
					else
					{
						moComboBox(Controls[8]).SetText(AudioModes[0]);
					}
				}
			}
		}
		else
		{
			if (Sender == Controls[9])
			{
				moCheckBox(Sender).Checked(bool(S));
			}
			else
			{
				if (Sender == Controls[14])
				{
					if (((!PlayerOwner().bNoVoiceMessages) && (!PlayerOwner().bNoVoiceTaunts)) && (!PlayerOwner().bNoAutoTaunts))
					{
						moComboBox(Controls[14]).SetText(VoiceModes[0]);
					}
					else
					{
						if (((!PlayerOwner().bNoVoiceMessages) && (!PlayerOwner().bNoVoiceTaunts)) && PlayerOwner().bNoAutoTaunts)
						{
							moComboBox(Controls[14]).SetText(VoiceModes[1]);
						}
						else
						{
							if (((!PlayerOwner().bNoVoiceMessages) && PlayerOwner().bNoVoiceTaunts) && PlayerOwner().bNoAutoTaunts)
							{
								moComboBox(Controls[14]).SetText(VoiceModes[2]);
							}
							else
							{
								moComboBox(Controls[14]).SetText(VoiceModes[3]);
							}
						}
					}
				}
				else
				{
					if (Sender == Controls[10])
					{
						moCheckBox(Sender).Checked(Class'HUD'.Default.bMessageBeep);
					}
					else
					{
						if (Sender == Controls[11])
						{
							moCheckBox(Sender).Checked(PlayerOwner().bAutoTaunt);
						}
						else
						{
							if (Sender == Controls[12])
							{
								moCheckBox(Sender).Checked((!PlayerOwner().bNoMatureLanguage));
							}
							else
							{
								if (Sender == Controls[13])
								{
									b1 = PlayerOwner().Level.bLowSoundDetail;
									b2 = bool(PlayerOwner().ConsoleCommand("get ini:Engine.Engine.AudioDevice LowQualitySound"));
									if (b1 != b2)
									{
										PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice LowQualitySound" @ string(b1));
										PlayerOwner().ConsoleCommand("SOUND_REBOOT");
										if ((PlayerOwner().Level.Song != "") && (PlayerOwner().Level.Song != "None"))
										{
											PlayerOwner().ClientSetMusic(PlayerOwner().Level.Song, 1);
										}
									}
									moCheckBox(Sender).Checked(b1);
								}
								else
								{
									if (Sender == Controls[15])
									{
										moComboBox(Sender).SetIndex(PlayerOwner().AnnouncerLevel);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	*/
}

FString UTab_AudioSettings::InternalOnSaveINI(UGUIComponent* Sender)
{
	return "FAKE";    //FAKE   /ELiZ
}

void UTab_AudioSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	FString t = "";
	bool b1 = false;
	bool b2 = false;
	bool b3 = false;
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	if (Sender == Controls[3])
	{
		PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice MusicVolume " $ string(GUISlider(Sender).Value));
	}
	else
	{
		if (Sender == Controls[5])
		{
			PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice SoundVolume " $ string(GUISlider(Sender).Value));
			PlayerOwner().ConsoleCommand("stopsounds");
		}
		else
		{
			if (Sender == Controls[7])
			{
				PlayerOwner().AnnouncerVolume = byte(GUISlider(Controls[7]).Value);
				PlayerOwner().SaveConfig();
				PlayerOwner().PlayRewardAnnouncement('adrenalin', 0, true);
			}
			else
			{
				if (Sender == Controls[8])
				{
					t = moComboBox(Sender).GetText();
					if (t == AudioModes[3])
					{
						PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice UseEAX false");
						PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice Use3DSound false");
						PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice CompatibilityMode true");
					}
					else
					{
						if (t == AudioModes[0])
						{
							PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice UseEAX false");
							PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice Use3DSound false");
							PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice CompatibilityMode false");
						}
						else
						{
							if (t == AudioModes[1])
							{
								PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice UseEAX false");
								PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice Use3DSound true");
								PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice CompatibilityMode false");
								Controller.OpenMenu("XInterface.UT2PerformWarn");
							}
							else
							{
								if (t == AudioModes[2])
								{
									PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice UseEAX true");
									PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice Use3DSound true");
									PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice CompatibilityMode false");
									Controller.OpenMenu("XInterface.UT2PerformWarn");
								}
							}
						}
					}
					PlayerOwner().ConsoleCommand("SOUND_REBOOT");
					if ((PlayerOwner().Level.Song != "") && (PlayerOwner().Level.Song != "None"))
					{
						PlayerOwner().ClientSetMusic(PlayerOwner().Level.Song, 1);
					}
				}
				else
				{
					if (Sender == Controls[9])
					{
						PlayerOwner().ConsoleCommand("set" @ Sender.IniOption @ string(moCheckBox(Sender).IsChecked()));
					}
					else
					{
						if (Sender == Controls[10])
						{
							if (PlayerOwner().myHUD != None)
							{
								PlayerOwner().myHUD.bMessageBeep = moCheckBox(Sender).IsChecked();
							}
							Class'HUD'.Default.bMessageBeep = moCheckBox(Sender).IsChecked();
							Class'HUD'.StaticSaveConfig();
						}
						else
						{
							if (Sender == Controls[11])
							{
								PlayerOwner().SetAutoTaunt(moCheckBox(Sender).IsChecked());
							}
							else
							{
								if (Sender == Controls[12])
								{
									PlayerOwner().bNoMatureLanguage = (!moCheckBox(Sender).IsChecked());
									PlayerOwner().SaveConfig();
								}
								else
								{
									if (Sender == Controls[14])
									{
										t = moComboBox(Sender).GetText();
										if (t == VoiceModes[0])
										{
											b1 = false;
											b2 = false;
											b3 = false;
										}
										else
										{
											if (t == VoiceModes[1])
											{
												b1 = true;
												b2 = false;
												b3 = false;
											}
											else
											{
												if (t == VoiceModes[2])
												{
													b1 = true;
													b2 = true;
													b3 = false;
												}
												else
												{
													b1 = true;
													b2 = true;
													b3 = true;
												}
											}
										}
										PlayerOwner().bNoAutoTaunts = b1;
										PlayerOwner().bNoVoiceTaunts = b2;
										PlayerOwner().bNoVoiceMessages = b3;
										PlayerOwner().SaveConfig();
									}
									else
									{
										if (Sender == Controls[13])
										{
											b1 = moCheckBox(Sender).IsChecked();
											PlayerOwner().Level.bLowSoundDetail = b1;
											PlayerOwner().Level.SaveConfig();
											PlayerOwner().ConsoleCommand("set ini:Engine.Engine.AudioDevice LowQualitySound" @ string(b1));
											PlayerOwner().ConsoleCommand("SOUND_REBOOT");
											if ((PlayerOwner().Level.Song != "") && (PlayerOwner().Level.Song != "None"))
											{
												PlayerOwner().ClientSetMusic(PlayerOwner().Level.Song, 1);
											}
										}
										else
										{
											if (Sender == Controls[15])
											{
												PlayerOwner().AnnouncerLevel = byte(moComboBox(Sender).GetIndex());
												PlayerOwner().SaveConfig();
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	*/
}