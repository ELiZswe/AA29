// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_NetworkSettings/Tab_NetworkSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"

UTab_NetworkSettings::UTab_NetworkSettings()
{
	UmoCheckBox* NetworkDynamicNetspeed = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	NetworkDynamicNetspeed->ComponentJustification = EeTextAlign::TXTA_Left;
	NetworkDynamicNetspeed->CaptionWidth = 0.9;
	NetworkDynamicNetspeed->Caption = "Dynamic Netspeed";
	//NetworkDynamicNetspeed->OnCreateComponent=NetworkDynamicNetspeed.InternalOnCreateComponent;
	NetworkDynamicNetspeed->Hint = "Dynamic adjust your netspeed on slower connections.";
	NetworkDynamicNetspeed->WinTop = 0.179011;
	NetworkDynamicNetspeed->WinLeft = 0.25;
	NetworkDynamicNetspeed->WinHeight = 0.04;
	UGUIButton* ViewOnlineStats = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ViewOnlineStats->Caption = "View Stats";
	ViewOnlineStats->Hint = "Click to launch the UT stats website.";
	ViewOnlineStats->WinTop = 0.742708;
	ViewOnlineStats->WinLeft = 0.536721;
	ViewOnlineStats->WinWidth = 0.21;
	//ViewOnlineStats->OnClick=Tab_NetworkSettings.OnViewStats;
	//ViewOnlineStats->OnKeyEvent=ViewOnlineStats.InternalOnKeyEvent;
	UmoCheckBox* OnlineTrackStats = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	OnlineTrackStats->ComponentJustification = EeTextAlign::TXTA_Left;
	OnlineTrackStats->CaptionWidth = 0.9;
	OnlineTrackStats->Caption = "Track Stats";
	//OnlineTrackStats->OnCreateComponent=OnlineTrackStats.InternalOnCreateComponent;
	OnlineTrackStats->IniOption = "@Internal";
	OnlineTrackStats->IniDefault = "True";
	OnlineTrackStats->Hint = "Enable this option to join the online ranking system.";
	OnlineTrackStats->WinTop = 0.742708;
	OnlineTrackStats->WinLeft = 0.251565;
	OnlineTrackStats->WinWidth = 0.21;
	OnlineTrackStats->WinHeight = 0.04;
	//OnlineTrackStats->OnLoadINI=Tab_NetworkSettings.InternalOnLoadINI;
	UmoEditBox* OnlineStatsPW = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	OnlineStatsPW->CaptionWidth = 0.4;
	OnlineStatsPW->Caption = "Stats Password";
	//OnlineStatsPW->OnCreateComponent=OnlineStatsPW.InternalOnCreateComponent;
	OnlineStatsPW->IniOption = "@Internal";
	OnlineStatsPW->Hint = "Please select a password that will secure your UT Stats!";
	OnlineStatsPW->WinTop = 0.583594;
	OnlineStatsPW->WinLeft = 0.25;
	OnlineStatsPW->WinHeight = 0.06;
	//OnlineStatsPW->OnLoadINI=Tab_NetworkSettings.InternalOnLoadINI;
	UmoEditBox* OnlineStatsName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	OnlineStatsName->CaptionWidth = 0.4;
	OnlineStatsName->Caption = "Stats UserName";
	//OnlineStatsName->OnCreateComponent=OnlineStatsName.InternalOnCreateComponent;
	OnlineStatsName->IniOption = "@Internal";
	OnlineStatsName->Hint = "Please select a name to use for UT Stats!";
	OnlineStatsName->WinTop = 0.494271;
	OnlineStatsName->WinLeft = 0.25;
	OnlineStatsName->WinHeight = 0.06;
	//OnlineStatsName->OnLoadINI=Tab_NetworkSettings.InternalOnLoadINI;
	UmoComboBox* OnlineNetSpeed = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	OnlineNetSpeed->bReadOnly = true;
	OnlineNetSpeed->ComponentJustification = EeTextAlign::TXTA_Left;
	OnlineNetSpeed->CaptionWidth = 0.4;
	OnlineNetSpeed->Caption = "Connection";
	//OnlineNetSpeed->OnCreateComponent=OnlineNetSpeed.InternalOnCreateComponent;
	OnlineNetSpeed->IniOption = "@Internal";
	OnlineNetSpeed->IniDefault = "Cable Modem/DSL";
	OnlineNetSpeed->Hint = "How fast is your connection?";
	OnlineNetSpeed->WinTop = 0.085678;
	OnlineNetSpeed->WinLeft = 0.25;
	OnlineNetSpeed->WinHeight = 0.06;
	//OnlineNetSpeed->OnLoadINI=Tab_NetworkSettings.InternalOnLoadINI;
	UGUIImage* OnlineBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//OnlineBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	OnlineBK1->ImageColor = FColor(255, 255, 255, 160);
	OnlineBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	OnlineBK1->WinTop = 0.355208;
	OnlineBK1->WinLeft = 0.216797;
	OnlineBK1->WinWidth = 0.57664;
	OnlineBK1->WinHeight = 0.489999;
	UGUILabel* OnlineStatDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	OnlineStatDesc->Caption = "UT2003 Global Stats";
	OnlineStatDesc->TextAlign = ETextAlign::TXTA_Center;
	OnlineStatDesc->TextColor = FColor(0, 200, 230, 255);
	OnlineStatDesc->TextFont = "UT2HeaderFont";
	OnlineStatDesc->WinTop = 0.391145;
	OnlineStatDesc->WinLeft = 0.25;
	OnlineStatDesc->WinWidth = 0.5;
	OnlineStatDesc->WinHeight = 32;
	UGUILabel* InvalidWarning = NewObject<UGUILabel>(UGUILabel::StaticClass());
	InvalidWarning->Caption = "Your stats username or password is invalid.  Your username must be at least 4 characters long, and your password must be at least 6 characters long.";
	InvalidWarning->TextAlign = ETextAlign::TXTA_Center;
	InvalidWarning->TextColor = FColor(0, 0, 255, 255);
	InvalidWarning->bMultiLine = true;
	InvalidWarning->WinTop = 0.870832;
	InvalidWarning->WinLeft = 0.215625;
	InvalidWarning->WinWidth = 0.576561;
	InvalidWarning->WinHeight = 0.125001;
	UGUILabel* EpicID = NewObject<UGUILabel>(UGUILabel::StaticClass());
	EpicID->Caption = "Your Unique id is:";
	EpicID->TextAlign = ETextAlign::TXTA_Center;
	EpicID->TextColor = FColor(0, 255, 255, 255);
	EpicID->TextFont = "UT2SmallFont";
	EpicID->bMultiLine = true;
	EpicID->WinTop = 0.313279;
	EpicID->WinHeight = 0.066407;

	NetSpeedText = { "Modem","ISDN","Cable/ADSL","LAN/T1" };
	StatsURL = "http://ut2003stats.epicgames.com/";
	EpicIDMsg = "Your Unique id is:";
	Controls = { OnlineBK1,OnlineNetSpeed,OnlineStatsName,OnlineStatsPW,OnlineStatDesc,OnlineTrackStats,ViewOnlineStats,InvalidWarning,EpicID,NetworkDynamicNetspeed };
	WinTop = 0.15;
	WinHeight = 0.74;
}

void UTab_NetworkSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].__OnChange__Delegate = InternalOnChange;
	}
	for (i = 0; i < 4; i++)
	{
		moComboBox(Controls[1]).addItem(NetSpeedText[i]);
	}
	moEditBox(Controls[2]).MyEditBox.bConvertSpaces = true;
	moEditBox(Controls[2]).MyEditBox.MaxWidth = 14;
	moEditBox(Controls[3]).MyEditBox.MaxWidth = 14;
	moEditBox(Controls[3]).MaskText(true);
	moEditBox(Controls[2]).MenuStateChange(4);
	moEditBox(Controls[3]).MenuStateChange(4);
	GUILabel(Controls[8]).Caption = EpicIDMsg @ FormatID(PlayerOwner().GetPlayerIDHash());
	moCheckBox(Controls[9]).Checked(PlayerOwner().bDynamicNetSpeed);
	*/
}

FString UTab_NetworkSettings::FormatID(FString Id)
{
	/*
	Id = Caps(Id);
	return Mid(Id, 0, 8) $ "-" $ Mid(Id, 8, 8) $ "-" $ Mid(Id, 16, 8) $ "-" $ Mid(Id, 24, 8);
	*/
	return "FAKE";    //FAKE    /ELiZ
}

void UTab_NetworkSettings::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	int32 i = 0;
	if (Sender == Controls[1])
	{
		i = Class'Player'.Default.ConfiguredInternetSpeed;
		if (i <= 2600)
		{
			moComboBox(Sender).SetText(NetSpeedText[0]);
		}
		else
		{
			if (i <= 5000)
			{
				moComboBox(Sender).SetText(NetSpeedText[1]);
			}
			else
			{
				if (i <= 10000)
				{
					moComboBox(Sender).SetText(NetSpeedText[2]);
				}
				else
				{
					moComboBox(Sender).SetText(NetSpeedText[3]);
				}
			}
		}
	}
	else
	{
		if (Sender == Controls[2])
		{
			if ((PlayerOwner().StatsUsername != "") && (PlayerOwner().StatsPassword != ""))
			{
				moEditBox(Sender).SetText(PlayerOwner().StatsUsername);
				moEditBox(Sender).MenuStateChange(0);
			}
			else
			{
				moEditBox(Sender).SetText("");
				moEditBox(Sender).MenuStateChange(4);
			}
		}
		else
		{
			if (Sender == Controls[3])
			{
				if ((PlayerOwner().StatsUsername != "") && (PlayerOwner().StatsPassword != ""))
				{
					moEditBox(Sender).SetText(PlayerOwner().StatsPassword);
					moEditBox(Sender).MenuStateChange(0);
				}
				else
				{
					moEditBox(Sender).SetText("");
					moEditBox(Sender).MenuStateChange(4);
				}
			}
			else
			{
				if (Sender == Controls[5])
				{
					GUICheckBoxButton(GUIMenuOption(Sender).MyComponent).SetChecked(((PlayerOwner().StatsUsername != "") && (PlayerOwner().StatsPassword != "")));
				}
			}
		}
	}
	Controls[7].bVisible = (!ValidStatConfig());
	*/
}

bool UTab_NetworkSettings::ValidStatConfig()
{
	/*
	if (moCheckBox(Controls[5]).IsChecked())
	{
		if (Len(moEditBox(Controls[2]).GetText()) < 4)
		{
			return false;
		}
		if (Len(moEditBox(Controls[3]).GetText()) < 6)
		{
			return false;
		}
	}
	*/
	return true;
}

void UTab_NetworkSettings::ApplyStatConfig()
{
	/*
	if (moCheckBox(Controls[5]).IsChecked())
	{
		PlayerOwner().StatsUsername = moEditBox(Controls[2]).GetText();
		PlayerOwner().StatsPassword = moEditBox(Controls[3]).GetText();
	}
	else
	{
		PlayerOwner().StatsUsername = moEditBox(Controls[2]).GetText();
		PlayerOwner().StatsPassword = moEditBox(Controls[3]).GetText();
	}
	PlayerOwner().SaveConfig();
	*/
}

void UTab_NetworkSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local GUIMenuOption O;
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	if (Sender == Controls[1])
	{
		if (moComboBox(Sender).GetText() == NetSpeedText[0])
		{
			PlayerOwner().ConsoleCommand("netspeed 2600");
		}
		else
		{
			if (moComboBox(Sender).GetText() == NetSpeedText[1])
			{
				PlayerOwner().ConsoleCommand("netspeed 5000");
			}
			else
			{
				if (moComboBox(Sender).GetText() == NetSpeedText[2])
				{
					PlayerOwner().ConsoleCommand("netspeed 10000");
				}
				else
				{
					if (moComboBox(Sender).GetText() == NetSpeedText[3])
					{
						PlayerOwner().ConsoleCommand("netspeed 20000");
					}
				}
			}
		}
	}
	else
	{
		if (Sender == Controls[5])
		{
			O = GUIMenuOption(Sender);
			if (!GUICheckBoxButton(O.MyComponent).bChecked)
			{
				moEditBox(Controls[2]).SetText("");
				moEditBox(Controls[3]).SetText("");
				moEditBox(Controls[2]).MenuStateChange(4);
				moEditBox(Controls[3]).MenuStateChange(4);
			}
			else
			{
				moEditBox(Controls[2]).MenuStateChange(0);
				moEditBox(Controls[3]).MenuStateChange(0);
			}
		}
		else
		{
			if (Sender == Controls[9])
			{
				PlayerOwner().bDynamicNetSpeed = moCheckBox(Controls[9]).IsChecked();
				PlayerOwner().SaveConfig();
			}
		}
	}
	Controls[7].bVisible = (!ValidStatConfig());
	*/
}

bool UTab_NetworkSettings::OnViewStats(UGUIComponent* Sender)
{
	//PlayerOwner().ConsoleCommand("start" @ StatsURL);
	return true;
}