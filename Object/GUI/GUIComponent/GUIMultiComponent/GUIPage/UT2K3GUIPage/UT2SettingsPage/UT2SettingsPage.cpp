// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2SettingsPage/UT2SettingsPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UUT2SettingsPage::UUT2SettingsPage()
{
	UGUIButton* BackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BackButton->Caption = "BACK";
	BackButton->StyleName = "SquareMenuButton";
	BackButton->Hint = "Return to Previous Menu";
	BackButton->WinTop = 0.93;
	BackButton->WinWidth = 0.12;
	BackButton->WinHeight = 0.055;
	//BackButton->OnClick=UT2SettingsPage.ButtonClicked;
	//BackButton->OnKeyEvent=BackButton.InternalOnKeyEvent;
	UGUITabControl* SettingTabs = NewObject<UGUITabControl>(UGUITabControl::StaticClass());
	SettingTabs->bDockPanels = true;
	SettingTabs->TabHeight = 0.04;
	SettingTabs->WinTop = 0.25;
	SettingTabs->WinHeight = 48;
	SettingTabs->bAcceptsInput = true;
	//SettingTabs->OnActivate=SettingTabs.InternalOnActivate;
	//SettingTabs->OnChange=UT2SettingsPage.TabChange;
	UGUITitleBar* SettingHeader = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	SettingHeader->Caption = "Settings";
	SettingHeader->StyleName = "Header";
	SettingHeader->WinTop = 0.036406;
	SettingHeader->WinHeight = 46;
	UGUITitleBar* SettingFooter = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	SettingFooter->bUseTextHeight = false;
	SettingFooter->StyleName = "Footer";
	SettingFooter->WinTop = 0.93;
	SettingFooter->WinLeft = 0.12;
	SettingFooter->WinWidth = 0.88;
	SettingFooter->WinHeight = 0.055;
	UGUIImage* LogoSymbol = NewObject<UGUIImage>(UGUIImage::StaticClass());
	LogoSymbol->ImageStyle = EImgStyle::ISTY_Scaled;
	LogoSymbol->WinTop = 0.800782;
	LogoSymbol->WinLeft = 0.830079;
	LogoSymbol->WinWidth = 0.26;
	LogoSymbol->WinHeight = 0.13;
	LogoSymbol->bVisible = false;
	VideoTabLabel = "Video";
	VideoTabHint = "Select your resolution and change your brightness...";
	DetailsTabLabel = "Details";
	DetailsTabHint = "Adjust the detail settings for better graphics or faster framerate...";
	AudioTabLabel = "Audio";
	AudioTabHint = "Adjust your audio experience...";
	PlayerTabLabel = "Player";
	PlayerTabHint = "Configure your UT2003 Avatar...";
	NetworkTabLabel = "Network";
	NetworkTabHint = "Configure UT2003 for Online and Lan play...";
	ControlsTabLabel = "Controls";
	ControlsTabHint = "Configure your controls...";
	IForceTabLabel = "Input";
	IForceTabHint = "Configure misc. input options...";
	WeaponsTabLabel = "Weapons";
	WeaponsTabHint = "Adjust your weapon priorities and settings...";
	GameTabLabel = "Game";
	GameTabHint = "Adjust various game related settings...";
	HudTabLabel = "Hud";
	HudTabHint = "Customize your hud...";
	SpeechBinderTabLabel = "Speech";
	SpeechBinderTabHint = "Bind messages to keys...";
	//OnReOpen = UT2SettingsPage.InternalOnReOpen;
	//OnClose = UT2SettingsPage.InternalOnClose;
	//OnCanClose = UT2SettingsPage.InternalOnCanClose;
	Controls = { SettingHeader,SettingTabs,SettingFooter,BackButton,LogoSymbol };
	WinHeight = 1;
}

void UUT2SettingsPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local GUITabControl TabC;
	FRotator PlayerRot = FRotator(0, 0, 0);
	Super::InitComponent(MyController, MyOwner);
	PlayerRot = PlayerOwner().Rotation;
	SavedPitch = float(PlayerRot.Pitch);
	PlayerRot.Pitch = 0;
	PlayerOwner().SetRotation(PlayerRot);
	TabC = GUITabControl(Controls[1]);
	GUITitleBar(Controls[0]).DockedTabs = TabC;
	TabC.AddTab(VideoTabLabel, "xinterface.Tab_VideoSettings", , VideoTabHint, true);
	TabC.AddTab(DetailsTabLabel, "xinterface.Tab_DetailSettings", , DetailsTabHint);
	TabC.AddTab(AudioTabLabel, "xinterface.Tab_AudioSettings", , AudioTabHint);
	pPlayer = Tab_PlayerSettings(TabC.AddTab(PlayerTabLabel, "xinterface.Tab_PlayerSettings", , PlayerTabHint));
	pNetwork = Tab_NetworkSettings(TabC.AddTab(NetworkTabLabel, "xinterface.Tab_NetworkSettings", , NetworkTabHint));
	TabC.AddTab(ControlsTabLabel, "xinterface.Tab_ControlSettings", , ControlsTabHint);
	TabC.AddTab(IForceTabLabel, "xinterface.Tab_IForceSettings", , IForceTabHint);
	pWeaponPref = Tab_WeaponPref(TabC.AddTab(WeaponsTabLabel, "xinterface.Tab_WeaponPref", , WeaponsTabHint));
	TabC.AddTab(HudTabLabel, "xinterface.Tab_HudSettings", , HudTabHint);
	TabC.AddTab(GameTabLabel, "xinterface.Tab_GameSettings", , GameTabHint);
	TabC.AddTab(SpeechBinderTabLabel, "xinterface.Tab_SpeechBinder", , SpeechBinderTabHint);
	*/
}

void UUT2SettingsPage::TabChange(UGUIComponent* Sender)
{
	/*
	if (GUITabButton(Sender) == nullptr)
	{
		return;
	}
	GUITitleBar(Controls[0]).SetCaption(GUITitleBar(Default.Controls[0]).GetCaption() @ "|" @ GUITabButton(Sender).Caption);
	*/
}

void UUT2SettingsPage::ChangeHint(FString NewHint)
{
	//GUITitleBar(Controls[2]).SetCaption(NewHint);
}

void UUT2SettingsPage::InternalOnReOpen()
{
	/*
	local GUITabControl TabC;
	TabC = GUITabControl(Controls[1]);
	if ((TabC.ActiveTab != None) && (TabC.ActiveTab.MyPanel != None))
	{
		TabC.ActiveTab.MyPanel.Refresh();
	}
	*/
}

bool UUT2SettingsPage::ButtonClicked(UGUIComponent* Sender)
{
	/*
	if (InternalOnCanClose(false))
	{
		GUITabControl(Controls[1]).ActiveTab.OnDeActivate();
		Controller.CloseMenu(true);
	}
	*/
	return true;
}

bool UUT2SettingsPage::InternalOnCanClose(bool bCanceled)
{
	/*
	if (!pNetwork.ValidStatConfig())
	{
		GUITabControl(Controls[1]).ActivateTabByName(NetworkTabLabel, true);
		return false;
	}
	else
	{
		return true;
	}
	*/
	return false;     //FAKE   /ELiZ
}

bool UUT2SettingsPage::NotifyLevelChange()
{
	//Controller.CloseMenu(true);
	return Super::NotifyLevelChange();
}

void UUT2SettingsPage::InternalOnClose(bool bCanceled)
{
	/*
	FRotator newRot = FRotator(0, 0, 0);
	if (pWeaponPref.SpinnyWeap != None)
	{
		pWeaponPref.SpinnyWeap.Destroy();
		pWeaponPref = nullptr;
	}
	if (pPlayer.SpinnyDude != None)
	{
		pPlayer.SpinnyDude.Destroy();
		pPlayer.SpinnyDude = nullptr;
	}
	newRot = PlayerOwner().Rotation;
	newRot.Pitch = int(SavedPitch);
	PlayerOwner().SetRotation(newRot);
	pNetwork.ApplyStatConfig();
	pPlayer.InternalApply(None);
	pWeaponPref.WeapApply(None);
	OnClose(bCanceled);
	*/
}