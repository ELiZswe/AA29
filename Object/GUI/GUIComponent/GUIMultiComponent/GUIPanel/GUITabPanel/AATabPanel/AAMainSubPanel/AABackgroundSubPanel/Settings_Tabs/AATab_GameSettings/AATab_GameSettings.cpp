// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/AATab_GameSettings/AATab_GameSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"

UAATab_GameSettings::UAATab_GameSettings()
{
	UmoCheckBox* WeaponAutoSwitch = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	WeaponAutoSwitch->Caption="Auto Switch from Grenade";
	//WeaponAutoSwitch->OnCreateComponent=WeaponAutoSwitch.InternalOnCreateComponent;
	WeaponAutoSwitch->IniOption="@Internal";
	WeaponAutoSwitch->Hint="Automatically change weapons when grenade is thrown.";
	WeaponAutoSwitch->WinTop=0.09;
	WeaponAutoSwitch->WinLeft=0.02;
	WeaponAutoSwitch->WinWidth=0.45;
	WeaponAutoSwitch->WinHeight=0.035;
	WeaponAutoSwitch->RenderWeight=1.04;
	WeaponAutoSwitch->TabOrder=6;
	WeaponAutoSwitch->bStandardized=false;
	//WeaponAutoSwitch->OnChange=AATab_GameSettings.InternalOnChange;
	//WeaponAutoSwitch->OnLoadINI=AATab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* LeanToggle = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	LeanToggle->Caption="Toggle Lean";
	//LeanToggle->OnCreateComponent=LeanToggle.InternalOnCreateComponent;
	LeanToggle->IniOption="@Internal";
	LeanToggle->Hint="Lean buttons work as toggles instead of momentary";
	LeanToggle->WinTop=0.13;
	LeanToggle->WinLeft=0.02;
	LeanToggle->WinWidth=0.45;
	LeanToggle->WinHeight=0.035;
	LeanToggle->RenderWeight=1.04;
	LeanToggle->TabOrder=1;
	LeanToggle->bStandardized=false;
	//LeanToggle->OnChange=AATab_GameSettings.InternalOnChange;
	//LeanToggle->OnLoadINI=AATab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* WalkZoom = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	WalkZoom->Caption="Walk Zoom";
	//WalkZoom->OnCreateComponent=WalkZoom.InternalOnCreateComponent;
	WalkZoom->IniOption="@Internal";
	WalkZoom->Hint="Player walks slowly while zoomed";
	WalkZoom->WinTop=0.17;
	WalkZoom->WinLeft=0.02;
	WalkZoom->WinWidth=0.45;
	WalkZoom->WinHeight=0.035;
	WalkZoom->RenderWeight=1.04;
	WalkZoom->TabOrder=1;
	WalkZoom->bStandardized=false;
	//WalkZoom->OnChange=AATab_GameSettings.InternalOnChange;
	//WalkZoom->OnLoadINI=AATab_GameSettings.InternalOnLoadINI;
	UmoComboBox* OnlineNetSpeed = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	OnlineNetSpeed->bReadOnly=true;
	OnlineNetSpeed->ComponentJustification = EeTextAlign::TXTA_Left;
	OnlineNetSpeed->CaptionWidth=0.55;
	OnlineNetSpeed->Caption="Connection";
	//OnlineNetSpeed->OnCreateComponent=OnlineNetSpeed.InternalOnCreateComponent;
	OnlineNetSpeed->IniOption="@Internal";
	OnlineNetSpeed->IniDefault="Cable Modem/DSL";
	OnlineNetSpeed->Hint="How fast is your connection?";
	OnlineNetSpeed->WinTop=0.09;
	OnlineNetSpeed->WinLeft=0.52;
	OnlineNetSpeed->WinWidth=0.45;
	OnlineNetSpeed->WinHeight=0.035;
	OnlineNetSpeed->TabOrder=8;
	//OnlineNetSpeed->OnChange=AATab_GameSettings.InternalOnChange;
	//OnlineNetSpeed->OnLoadINI=AATab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* NetworkDynamicNetspeed = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	NetworkDynamicNetspeed->ComponentJustification = EeTextAlign::TXTA_Left;
	NetworkDynamicNetspeed->CaptionWidth=0.9;
	NetworkDynamicNetspeed->Caption="Dynamic Netspeed";
	//NetworkDynamicNetspeed->OnCreateComponent=NetworkDynamicNetspeed.InternalOnCreateComponent;
	NetworkDynamicNetspeed->IniOption="@Internal";
	NetworkDynamicNetspeed->Hint="Netspeed is automatically adjusted based on the speed of your network connection";
	NetworkDynamicNetspeed->WinTop=0.13;
	NetworkDynamicNetspeed->WinLeft=0.52;
	NetworkDynamicNetspeed->WinWidth=0.45;
	NetworkDynamicNetspeed->WinHeight=0.035;
	NetworkDynamicNetspeed->TabOrder=9;
	NetworkDynamicNetspeed->bStandardized=false;
	//NetworkDynamicNetspeed->OnChange=AATab_GameSettings.InternalOnChange;
	//NetworkDynamicNetspeed->OnLoadINI=AATab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* PrecacheSkins = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	PrecacheSkins->ComponentJustification = EeTextAlign::TXTA_Left;
	PrecacheSkins->CaptionWidth=0.9;
	PrecacheSkins->Caption="Preload all player skins";
	//PrecacheSkins->OnCreateComponent=PrecacheSkins.InternalOnCreateComponent;
	PrecacheSkins->IniOption="@Internal";
	PrecacheSkins->Hint="Preloads all player skins, increasing level load time but reducing hitches during network games.  You must have at least 512 MB of system memory to use this option.";
	PrecacheSkins->WinTop=0.17;
	PrecacheSkins->WinLeft=0.52;
	PrecacheSkins->WinWidth=0.45;
	PrecacheSkins->WinHeight=0.035;
	PrecacheSkins->TabOrder=14;
	PrecacheSkins->bStandardized=false;
	//PrecacheSkins->OnChange=AATab_GameSettings.InternalOnChange;
	//PrecacheSkins->OnLoadINI=AATab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* SpeechRecognition = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	SpeechRecognition->ComponentJustification = EeTextAlign::TXTA_Left;
	SpeechRecognition->CaptionWidth=0.9;
	SpeechRecognition->Caption="Speech Recognition";
	//SpeechRecognition->OnCreateComponent=SpeechRecognition.InternalOnCreateComponent;
	SpeechRecognition->IniOption="@Internal";
	SpeechRecognition->Hint="Enable speech recognition";
	SpeechRecognition->WinTop=0.21;
	SpeechRecognition->WinLeft=0.52;
	SpeechRecognition->WinWidth=0.45;
	SpeechRecognition->WinHeight=0.035;
	SpeechRecognition->TabOrder=15;
	SpeechRecognition->bBoundToParent=true;
	SpeechRecognition->bScaleToParent=true;
	SpeechRecognition->bStandardized=false;
	//SpeechRecognition->OnChange=AATab_GameSettings.InternalOnChange;
	//SpeechRecognition->OnLoadINI=AATab_GameSettings.InternalOnLoadINI;
	UmoComboBox* BrowserSwitcher = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	BrowserSwitcher->bReadOnly=true;
	BrowserSwitcher->ComponentJustification = EeTextAlign::TXTA_Left;
	BrowserSwitcher->CaptionWidth=0.27;
	BrowserSwitcher->Caption="Browser Service:";
	//BrowserSwitcher->OnCreateComponent=BrowserSwitcher.InternalOnCreateComponent;
	BrowserSwitcher->IniOption="@Internal";
	BrowserSwitcher->Hint="Change the system which locates servers on the Internet.";
	BrowserSwitcher->WinTop=0.246967;
	BrowserSwitcher->WinLeft=0.52;
	BrowserSwitcher->WinWidth=0.45;
	BrowserSwitcher->WinHeight=0.031746;
	BrowserSwitcher->RenderWeight=1.04;
	BrowserSwitcher->TabOrder=1;
	BrowserSwitcher->bBoundToParent=true;
	//BrowserSwitcher->OnChange=AATab_GameSettings.InternalOnChange;
	//BrowserSwitcher->OnLoadINI=AATab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* DisableServerColorsInBrowser = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DisableServerColorsInBrowser->ComponentJustification = EeTextAlign::TXTA_Left;
	DisableServerColorsInBrowser->CaptionWidth=0.9;
	DisableServerColorsInBrowser->Caption="Disable server name colors";
	//DisableServerColorsInBrowser->OnCreateComponent=DisableServerColorsInBrowser.InternalOnCreateComponent;
	DisableServerColorsInBrowser->IniOption="@Internal";
	DisableServerColorsInBrowser->Hint="Ignore embedded color codes in server names.  Displays all server names in the server browsers with the same color.";
	DisableServerColorsInBrowser->WinTop=0.3;
	DisableServerColorsInBrowser->WinLeft=0.52;
	DisableServerColorsInBrowser->WinWidth=0.45;
	DisableServerColorsInBrowser->WinHeight=0.035;
	DisableServerColorsInBrowser->TabOrder=15;
	DisableServerColorsInBrowser->bStandardized=false;
	//DisableServerColorsInBrowser->OnChange=AATab_GameSettings.InternalOnChange;
	//DisableServerColorsInBrowser->OnLoadINI=AATab_GameSettings.InternalOnLoadINI;
		
	ch_AutoSwitch = WeaponAutoSwitch;
	ch_Speech = SpeechRecognition;
	ch_LeanToggle = LeanToggle;
	ch_WalkZoom = WalkZoom;
	ch_DisableServerColorsInBrowser = DisableServerColorsInBrowser;
	co_BrowserSwitcher = BrowserSwitcher;
	NetSpeedText = { "Modem","ISDN","Cable/ADSL","LAN/T1" };
	StatsURL = "http://www.americasarmy.com/";
	ch_DynNetspeed = NetworkDynamicNetspeed;
	ch_Precache = PrecacheSkins;
	co_Netspeed = OnlineNetSpeed;
	PanelCaption = "Game";
	WinTop = 0.15;
	WinHeight = 0.74;
}


void UAATab_GameSettings::InitComponent (UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController,MyOwner);
	LastGameOption=ch_LandShake;
	for (i=0; i<4; i++)
	{
		co_Netspeed.addItem(NetSpeedText[i]);
	}
	co_BrowserSwitcher.addItem("MBS",,"AA Browser");
	co_BrowserSwitcher.addItem("GameSpy",,"GameSpy");
	*/
}

FString UAATab_GameSettings::FormatID (FString Id)
{
	/*
	Id=Caps(Id);
	return Mid(Id,0,8) $ "-" $ Mid(Id,8,8) $ "-" $ Mid(Id,16,8) $ "-" $ Mid(Id,24,8);
	*/
	return "FAKE";     //FAKE    /ELiZ
}

void UAATab_GameSettings::ShowPanel (bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
		if (bInit)
		{
			if (PlatformIsVista())
			{
				ch_Speech.DisableMe();
				ch_Speech.SetComponentValue(string(bSpeechRec),false);
			}
		}
		UpdateStatsItems();
	}
	*/
}

void UAATab_GameSettings::InternalOnLoadINI (UGUIComponent* Sender, FString S)
{
	/*
	int32 i = 0;
	local PlayerController PC;
	local HumanController HC;
	if (GUIMenuOption(Sender) != None)
	{
		PC=PlayerOwner();
		HC=HumanController(PC);
		switch(GUIMenuOption(Sender))
		{
			case ch_AutoSwitch:
			bAuto=HC.bAutoSwapFromGrenade;
			ch_AutoSwitch.Checked(bAuto);
			break;
			case ch_LeanToggle:
			bLeanToggle=HC.bToggleLean;
			ch_LeanToggle.Checked(bLeanToggle);
			break;
			case ch_WalkZoom:
			bWalkZoom=HC.bAutoWalkZoom;
			ch_WalkZoom.Checked(bWalkZoom);
			break;
			case ch_Precache:
			bPrecache=PC.Level.bDesireSkinPreload;
			ch_Precache.Checked(bPrecache);
			break;
			case ch_Speech:
			if (! PlatformIsVista())
			{
				bSpeechRec=bool(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager UseSpeechRecognition"));
				ch_Speech.SetComponentValue(string(bSpeechRec),true);
			}
			break;
			case co_Netspeed:
			if (PC.Player != None)
			{
				i=PC.Player.ConfiguredInternetSpeed;
			}
			else
			{
				i=Class'Player'.Default.ConfiguredInternetSpeed;
			}
			if (i <= 2600)
			{
				iNetspeed=0;
			}
			else
			{
				if (i <= 5000)
				{
					iNetspeed=1;
				}
				else
				{
					if (i <= 10000)
					{
						iNetspeed=2;
					}
					else
					{
						iNetspeed=3;
					}
				}
			}
			iNetSpeedD=iNetspeed;
			co_Netspeed.SetIndex(iNetspeed);
			case ch_DynNetspeed:
			bDynNet=PC.bDynamicNetSpeed;
			ch_DynNetspeed.Checked(bDynNet);
			case co_BrowserSwitcher:
			sBrowser=AGP_HUD(HC.myHUD).ServerBrowser;
			co_BrowserSwitcher.SetComponentValue(sBrowser,true);
			case ch_DisableServerColorsInBrowser:
			bDisableServerColorsInBrowser=HC.bDisableServerColorsInBrowser;
			ch_DisableServerColorsInBrowser.Checked(bDisableServerColorsInBrowser);
			default:
		}
	}
	*/
}

void UAATab_GameSettings::SaveSettings ()
{
	/*
	local PlayerController PC;
	bool bSave = false;
	local HumanController HC;
	Super::SaveSettings();
	PC=PlayerOwner();
	HC=HumanController(PC);
	if (! PlatformIsVista())
	{
		if (bSpeechRec != bool(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager UseSpeechRecognition")))
		{
			PC.ConsoleCommand("set ini:Engine.Engine.ViewportManager UseSpeechRecognition" @ string(bSpeechRec));
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox","Please Restart The Game","The game must be restarted in order for settings to take effect");
		}
	}
	if (HC.bAutoSwapFromGrenade != bAuto)
	{
		HC.bAutoSwapFromGrenade=bAuto;
		bSave=true;
	}
	if (HC.bToggleLean != bLeanToggle)
	{
		HC.bToggleLean=bLeanToggle;
		bSave=true;
	}
	if (HC.bAutoWalkZoom != bWalkZoom)
	{
		HC.bAutoWalkZoom=bWalkZoom;
		bSave=true;
	}
	if (PC.bLandingShake != bLandShake)
	{
		PC.bLandingShake=bLandShake;
		bSave=true;
	}
	if (PC.bNeverSwitchOnPickup == bAuto)
	{
		PC.bNeverSwitchOnPickup=(! bAuto);
		bSave=true;
	}
	if (PC.bAimingHelp != bAim)
	{
		PC.bAimingHelp=bAim;
		bSave=true;
	}
	if (PC.Pawn != None)
	{
		PC.Pawn.bWeaponBob=bBob;
		PC.Pawn.SaveConfig();
	}
	else
	{
		if (Class'Pawn'.Default.bWeaponBob != bBob)
		{
			Class'Pawn'.Default.bWeaponBob=bBob;
			Class'Pawn'.StaticSaveConfig();
		}
	}
	if ((PC.Level != None) && (PC.Level.Game != None))
	{
		if (PC.Level.Game.GoreLevel != iGore)
		{
			PC.Level.Game.GoreLevel=iGore;
			PC.Level.Game.SaveConfig();
		}
	}
	else
	{
		if (Class'GameInfo'.Default.GoreLevel != iGore)
		{
			Class'GameInfo'.Default.GoreLevel=iGore;
			Class'GameInfo'.StaticSaveConfig();
		}
	}
	if (bPrecache != PC.Level.bDesireSkinPreload)
	{
		PC.Level.bDesireSkinPreload=bPrecache;
		PC.Level.SaveConfig();
	}
	if ((iNetspeed != iNetSpeedD) || (Class'Player'.Default.ConfiguredInternetSpeed == 9636))
	{
		if (PC.Player != None)
		{
			switch(iNetspeed)
			{
				case 0:
				PC.Player.ConfiguredInternetSpeed=2600;
				break;
				case 1:
				PC.Player.ConfiguredInternetSpeed=5000;
				break;
				case 2:
				PC.Player.ConfiguredInternetSpeed=10000;
				break;
				case 3:
				PC.Player.ConfiguredInternetSpeed=20000;
				break;
				default:
			}
			PC.Player.SaveConfig();
		}
		else
		{
			switch(iNetspeed)
			{
				case 0:
				Class'Player'.Default.ConfiguredInternetSpeed=2600;
				break;
				case 1:
				Class'Player'.Default.ConfiguredInternetSpeed=5000;
				break;
				case 2:
				Class'Player'.Default.ConfiguredInternetSpeed=10000;
				break;
				case 3:
				Class'Player'.Default.ConfiguredInternetSpeed=15000;
				break;
				default:
			}
			Class'Player'.StaticSaveConfig();
		}
	}
	if (PC.bDynamicNetSpeed != bDynNet)
	{
		PC.bDynamicNetSpeed=bDynNet;
		bSave=true;
	}
	if (sBrowser != AGP_HUD(HC.myHUD).ServerBrowser)
	{
		AGP_HUD(HC.myHUD).ServerBrowser=sBrowser;
		if (AGP_HUD(HC.myHUD).GetCurrentServerBrowser(false).IsSupportsFavorites())
		{
			class'AGP_Interface.AABrowser_FavoritesPanel'.Default.Favorites.RefreshFavoritesFromServer(HC.UserName,HC.UserPassword,PlayerOwner());
		}
		bSave=true;
	}
	if (HC.bDisableServerColorsInBrowser != bDisableServerColorsInBrowser)
	{
		HC.bDisableServerColorsInBrowser=bDisableServerColorsInBrowser;
		bSave=true;
	}
	if (bSave)
	{
		PC.SaveConfig();
		HC.SaveConfig();
		AGP_HUD(HC.myHUD).SaveConfig();
	}
	*/
}

void UAATab_GameSettings::ResetClicked ()
{
	/*
	local class<Client>  ViewportClass;
	bool bTemp = false;
	local PlayerController PC;
	int32 i = 0;
	Super::ResetClicked();
	PC=PlayerOwner();
	ViewportClass=class<Client>(DynamicLoadObject(GetNativeClassName("Engine.Engine.ViewportManager"),Class'Class'));
	ViewportClass.ResetConfig("UseSpeechRecognition");
	ViewportClass.ResetConfig("ScreenFlashes");
	HumanController(PC).ResetConfig("bAutoSwapFromGrenade");
	HumanController(PC).ResetConfig("bToggleLean");
	HumanController(PC).ResetConfig("bAutoWalkZoom");
	PC.ResetConfig("bNeverSwitchOnPickup");
	PC.ResetConfig("bLandingShake");
	PC.ResetConfig("bAimingHelp");
	Class'Pawn'.ResetConfig("bWeaponBob");
	Class'GameInfo'.ResetConfig("GoreLevel");
	Class'LevelInfo'.ResetConfig("bDesireSkinPreload");
	Class'Player'.ResetConfig("ConfiguredInternetSpeed");
	PC.ResetConfig("bDynamicNetSpeed");
	PC.ResetConfig("bEnableStatsTracking");
	PC.ClearConfig("StatsUserName");
	PC.ClearConfig("StatsPassword");
	bTemp=Controller.bCurMenuInitialized;
	Controller.bCurMenuInitialized=false;
	for (i=0; i<Components.Length; i++)
	{
		Components[i].LoadINI();
	}
	Controller.bCurMenuInitialized=bTemp;
	*/
}

void UAATab_GameSettings::InternalOnChange (UGUIComponent* Sender)
{
	/*
	local PlayerController PC;
	Super::InternalOnChange(Sender);
	if (GUIMenuOption(Sender) != None)
	{
		PC=PlayerOwner();
		switch(GUIMenuOption(Sender))
		{
			case ch_AutoSwitch:
			bAuto=ch_AutoSwitch.IsChecked();
			break;
			case ch_LeanToggle:
			bLeanToggle=ch_LeanToggle.IsChecked();
			break;
			case ch_WalkZoom:
			bWalkZoom=ch_WalkZoom.IsChecked();
			break;
			case ch_Precache:
			bPrecache=ch_Precache.IsChecked();
			break;
			case ch_Speech:
			bSpeechRec=ch_Speech.IsChecked();
			break;
			case co_Netspeed:
			iNetspeed=co_Netspeed.GetIndex();
			break;
			case ch_DynNetspeed:
			bDynNet=ch_DynNetspeed.IsChecked();
			break;
			case co_BrowserSwitcher:
			if (! (co_BrowserSwitcher.GetText() ~= "MBS"))
			{
				if (! class'AGP_Interface.AABrowserSwitchWarningPage'.Default.Disabled)
				{
					Controller.OpenMenu("AGP_Interface.AABrowserSwitchWarningPage");
					Controller.ActivePage.__OnClose__Delegate=SwitchBrowserConfirm;
				}
				else
				{
					SwitchBrowserConfirm(false);
				}
			}
			else
			{
				sBrowser="AA Browser";
			}
			case ch_DisableServerColorsInBrowser:
			bDisableServerColorsInBrowser=ch_DisableServerColorsInBrowser.IsChecked();
			default:
		}
	}
	SaveSettings();
	*/
}

bool UAATab_GameSettings::ValidStatConfig ()
{
	/*
	if (bStats)
	{
		if (Len(ed_Name.GetText()) < 4)
		{
			return false;
		}
		if (Len(ed_Password.GetText()) < 6)
		{
			return false;
		}
	}
	*/
	return true;
}

bool UAATab_GameSettings::OnViewStats (UGUIComponent* Sender)
{
	//PlayerOwner().ConsoleCommand("start" @ StatsURL);
	return true;
}

void UAATab_GameSettings::SwitchBrowserConfirm (bool bCancelled)
{
	/*
	if (! bCancelled)
	{
		sBrowser="GameSpy";
	}
	else
	{
		sBrowser="AA Browser";
		co_BrowserSwitcher.SetComponentValue("AA Browser",true);
	}
	SaveSettings();
	*/
}

void UAATab_GameSettings::UpdateStatsItems ()
{
}
