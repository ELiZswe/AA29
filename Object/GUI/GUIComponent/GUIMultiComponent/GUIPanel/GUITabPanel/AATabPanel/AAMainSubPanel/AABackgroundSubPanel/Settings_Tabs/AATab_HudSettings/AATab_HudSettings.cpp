// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/AATab_HudSettings/AATab_HudSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moSlider/moSlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"

UAATab_HudSettings::UAATab_HudSettings()
{
	UmoCheckBox* GameHudVisible = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudVisible->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudVisible->CaptionWidth = 0.9;
	GameHudVisible->Caption = "Hide HUD";
	//GameHudVisible->OnCreateComponent=GameHudVisible.InternalOnCreateComponent;
	GameHudVisible->IniOption = "@Internal";
	GameHudVisible->Hint = "Hide the HUD while playing";
	GameHudVisible->WinTop = 0.09;
	GameHudVisible->WinLeft = 0.02;
	GameHudVisible->WinWidth = 0.45;
	GameHudVisible->WinHeight = 0.035;
	GameHudVisible->TabOrder = 0;
	GameHudVisible->bStandardized = false;
	//GameHudVisible->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudVisible->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowAmmoCount = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowAmmoCount->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowAmmoCount->CaptionWidth = 0.9;
	GameHudShowAmmoCount->Caption = "Show Ammo Count";
	//GameHudShowAmmoCount->OnCreateComponent=GameHudShowAmmoCount.InternalOnCreateComponent;
	GameHudShowAmmoCount->IniOption = "@Internal";
	GameHudShowAmmoCount->Hint = "Select whether the ammunition count should appear on the HUD";
	GameHudShowAmmoCount->WinTop = 0.13;
	GameHudShowAmmoCount->WinLeft = 0.02;
	GameHudShowAmmoCount->WinWidth = 0.45;
	GameHudShowAmmoCount->WinHeight = 0.035;
	GameHudShowAmmoCount->TabOrder = 1;
	GameHudShowAmmoCount->bStandardized = false;
	//GameHudShowAmmoCount->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudShowAmmoCount->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudWeaponInfo = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudWeaponInfo->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudWeaponInfo->CaptionWidth = 0.9;
	GameHudWeaponInfo->Caption = "Show Weapons Info";
	//GameHudWeaponInfo->OnCreateComponent=GameHudWeaponInfo.InternalOnCreateComponent;
	GameHudWeaponInfo->IniOption = "@Internal";
	GameHudWeaponInfo->Hint = "Select whether the weapons loadout should appear on the HUD";
	GameHudWeaponInfo->WinTop = 0.17;
	GameHudWeaponInfo->WinLeft = 0.02;
	GameHudWeaponInfo->WinWidth = 0.45;
	GameHudWeaponInfo->WinHeight = 0.035;
	GameHudWeaponInfo->TabOrder = 2;
	GameHudWeaponInfo->bStandardized = false;
	//GameHudWeaponInfo->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudWeaponInfo->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudGrenadeInfo = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudGrenadeInfo->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudGrenadeInfo->CaptionWidth = 0.9;
	GameHudGrenadeInfo->Caption = "Show Grenade Info";
	//GameHudGrenadeInfo->OnCreateComponent=GameHudGrenadeInfo.InternalOnCreateComponent;
	GameHudGrenadeInfo->IniOption = "@Internal";
	GameHudGrenadeInfo->Hint = "Select whether the grenade loadout should appear on the HUD";
	GameHudGrenadeInfo->WinTop = 0.21;
	GameHudGrenadeInfo->WinLeft = 0.02;
	GameHudGrenadeInfo->WinWidth = 0.45;
	GameHudGrenadeInfo->WinHeight = 0.035;
	GameHudGrenadeInfo->TabOrder = 3;
	GameHudGrenadeInfo->bStandardized = false;
	//GameHudGrenadeInfo->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudGrenadeInfo->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowCEM = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowCEM->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowCEM->CaptionWidth = 0.9;
	GameHudShowCEM->Caption = "Show CEM";
	//GameHudShowCEM->OnCreateComponent=GameHudShowCEM.InternalOnCreateComponent;
	GameHudShowCEM->IniOption = "@Internal";
	GameHudShowCEM->Hint = "Select whether the player's CEM should appear on the HUD";
	GameHudShowCEM->WinTop = 0.25;
	GameHudShowCEM->WinLeft = 0.02;
	GameHudShowCEM->WinWidth = 0.45;
	GameHudShowCEM->WinHeight = 0.035;
	GameHudShowCEM->TabOrder = 4;
	GameHudShowCEM->bStandardized = false;
	//GameHudShowCEM->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudShowCEM->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowPlayerInfo = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowPlayerInfo->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowPlayerInfo->CaptionWidth = 0.9;
	GameHudShowPlayerInfo->Caption = "Show Player Info";
	//GameHudShowPlayerInfo->OnCreateComponent=GameHudShowPlayerInfo.InternalOnCreateComponent;
	GameHudShowPlayerInfo->IniOption = "@Internal";
	GameHudShowPlayerInfo->Hint = "Select whether the player's health and posture should appear on the HUD";
	GameHudShowPlayerInfo->WinTop = 0.29;
	GameHudShowPlayerInfo->WinLeft = 0.02;
	GameHudShowPlayerInfo->WinWidth = 0.45;
	GameHudShowPlayerInfo->WinHeight = 0.035;
	GameHudShowPlayerInfo->TabOrder = 5;
	GameHudShowPlayerInfo->bStandardized = false;
	//GameHudShowPlayerInfo->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudShowPlayerInfo->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowTimer = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowTimer->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowTimer->CaptionWidth = 0.9;
	GameHudShowTimer->Caption = "Show Timer";
	//GameHudShowTimer->OnCreateComponent=GameHudShowTimer.InternalOnCreateComponent;
	GameHudShowTimer->IniOption = "@Internal";
	GameHudShowTimer->Hint = "Select whether the timer should appear on the HUD";
	GameHudShowTimer->WinTop = 0.33;
	GameHudShowTimer->WinLeft = 0.02;
	GameHudShowTimer->WinWidth = 0.45;
	GameHudShowTimer->WinHeight = 0.035;
	GameHudShowTimer->TabOrder = 6;
	GameHudShowTimer->bStandardized = false;
	//GameHudShowTimer->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudShowTimer->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowAccessories = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowAccessories->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowAccessories->CaptionWidth = 0.9;
	GameHudShowAccessories->Caption = "Show Accessories";
	//GameHudShowAccessories->OnCreateComponent=GameHudShowAccessories.InternalOnCreateComponent;
	GameHudShowAccessories->IniOption = "@Internal";
	GameHudShowAccessories->Hint = "Select whether acessories such as optics should appear on the HUD";
	GameHudShowAccessories->WinTop = 0.37;
	GameHudShowAccessories->WinLeft = 0.02;
	GameHudShowAccessories->WinWidth = 0.45;
	GameHudShowAccessories->WinHeight = 0.035;
	GameHudShowAccessories->TabOrder = 7;
	GameHudShowAccessories->bStandardized = false;
	//GameHudShowAccessories->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudShowAccessories->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowObjectives = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowObjectives->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowObjectives->CaptionWidth = 0.9;
	GameHudShowObjectives->Caption = "Show Objectives";
	//GameHudShowObjectives->OnCreateComponent=GameHudShowObjectives.InternalOnCreateComponent;
	GameHudShowObjectives->IniOption = "@Internal";
	GameHudShowObjectives->Hint = "Select whether the objectives should appear on the HUD";
	GameHudShowObjectives->WinTop = 0.41;
	GameHudShowObjectives->WinLeft = 0.02;
	GameHudShowObjectives->WinWidth = 0.45;
	GameHudShowObjectives->WinHeight = 0.035;
	GameHudShowObjectives->TabOrder = 8;
	GameHudShowObjectives->bStandardized = false;
	//GameHudShowObjectives->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudShowObjectives->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowRadar = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowRadar->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowRadar->CaptionWidth = 0.9;
	GameHudShowRadar->Caption = "Show SAI";
	//GameHudShowRadar->OnCreateComponent=GameHudShowRadar.InternalOnCreateComponent;
	GameHudShowRadar->IniOption = "@Internal";
	GameHudShowRadar->Hint = "Select whether the SAI should appear on the HUD";
	GameHudShowRadar->WinTop = 0.45;
	GameHudShowRadar->WinLeft = 0.02;
	GameHudShowRadar->WinWidth = 0.45;
	GameHudShowRadar->WinHeight = 0.035;
	GameHudShowRadar->TabOrder = 8;
	GameHudShowRadar->bStandardized = false;
	//GameHudShowRadar->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudShowRadar->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowRadarBlinking = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowRadarBlinking->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowRadarBlinking->CaptionWidth = 0.9;
	GameHudShowRadarBlinking->Caption = "Show SAI Flashes";
	//GameHudShowRadarBlinking->OnCreateComponent=GameHudShowRadarBlinking.InternalOnCreateComponent;
	GameHudShowRadarBlinking->IniOption = "@Internal";
	GameHudShowRadarBlinking->Hint = "Select whether the SAI should flash when teammates report in";
	GameHudShowRadarBlinking->WinTop = 0.53;
	GameHudShowRadarBlinking->WinLeft = 0.02;
	GameHudShowRadarBlinking->WinWidth = 0.45;
	GameHudShowRadarBlinking->WinHeight = 0.035;
	GameHudShowRadarBlinking->TabOrder = 8;
	GameHudShowRadarBlinking->bStandardized = false;
	//GameHudShowRadarBlinking->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudShowRadarBlinking->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* RotateRadar = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	RotateRadar->ComponentJustification = EeTextAlign::TXTA_Left;
	RotateRadar->CaptionWidth = 0.9;
	RotateRadar->Caption = "Rotating SAI";
	//RotateRadar->OnCreateComponent=RotateRadar.InternalOnCreateComponent;
	RotateRadar->IniOption = "@Internal";
	RotateRadar->Hint = "Select whether the SAI should rotate based on your players orientation";
	RotateRadar->WinTop = 0.57;
	RotateRadar->WinLeft = 0.02;
	RotateRadar->WinWidth = 0.45;
	RotateRadar->WinHeight = 0.035;
	RotateRadar->TabOrder = 8;
	RotateRadar->bStandardized = false;
	//RotateRadar->OnChange=AATab_HudSettings.InternalOnChange;
	//RotateRadar->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* RadarOpacity = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	RadarOpacity->ComponentJustification = EeTextAlign::TXTA_Left;
	RadarOpacity->CaptionWidth = 0.9;
	RadarOpacity->Caption = "Transparent SAI";
	//RadarOpacity->OnCreateComponent=RadarOpacity.InternalOnCreateComponent;
	RadarOpacity->IniOption = "@Internal";
	RadarOpacity->Hint = "Select whether the SAI should be semi-transparent";
	RadarOpacity->WinTop = 0.61;
	RadarOpacity->WinLeft = 0.02;
	RadarOpacity->WinWidth = 0.45;
	RadarOpacity->WinHeight = 0.035;
	RadarOpacity->TabOrder = 8;
	RadarOpacity->bStandardized = false;
	//RadarOpacity->OnChange=AATab_HudSettings.InternalOnChange;
	//RadarOpacity->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowRadarInfo = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowRadarInfo->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowRadarInfo->CaptionWidth = 0.9;
	GameHudShowRadarInfo->Caption = "Show SAI Player Info";
	//GameHudShowRadarInfo->OnCreateComponent=GameHudShowRadarInfo.InternalOnCreateComponent;
	GameHudShowRadarInfo->IniOption = "@Internal";
	GameHudShowRadarInfo->Hint = "Select whether the SAI should display information on players on your team";
	GameHudShowRadarInfo->WinTop = 0.65;
	GameHudShowRadarInfo->WinLeft = 0.02;
	GameHudShowRadarInfo->WinWidth = 0.45;
	GameHudShowRadarInfo->WinHeight = 0.035;
	GameHudShowRadarInfo->TabOrder = 8;
	GameHudShowRadarInfo->bStandardized = false;
	//GameHudShowRadarInfo->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudShowRadarInfo->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowDelayedStartWarning = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowDelayedStartWarning->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowDelayedStartWarning->CaptionWidth = 0.9;
	GameHudShowDelayedStartWarning->Caption = "Show Delayed Start Alerts";
	//GameHudShowDelayedStartWarning->OnCreateComponent=GameHudShowDelayedStartWarning.InternalOnCreateComponent;
	GameHudShowDelayedStartWarning->IniOption = "@Internal";
	GameHudShowDelayedStartWarning->Hint = "Select whether the you want to see mission start alert messages when the server is configured to use the delayed start feature.";
	GameHudShowDelayedStartWarning->WinTop = 0.74;
	GameHudShowDelayedStartWarning->WinLeft = 0.02;
	GameHudShowDelayedStartWarning->WinWidth = 0.45;
	GameHudShowDelayedStartWarning->WinHeight = 0.035;
	GameHudShowDelayedStartWarning->TabOrder = 8;
	GameHudShowDelayedStartWarning->bStandardized = false;
	//GameHudShowDelayedStartWarning->OnChange=AATab_HudSettings.InternalOnChange;
	//GameHudShowDelayedStartWarning->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoSlider* GameHudOpacity = NewObject<UmoSlider>(UmoSlider::StaticClass());
	GameHudOpacity->MaxValue = 100;
	GameHudOpacity->CaptionWidth = 0.45;
	GameHudOpacity->Caption = "HUD Opacity";
	GameHudOpacity->LabelColor = FColor(255, 255, 255, 255);
	//GameHudOpacity->OnCreateComponent=GameHudOpacity.InternalOnCreateComponent;
	GameHudOpacity->Hint = "Adjust the transparency of the HUD";
	GameHudOpacity->WinTop = 0.237957;
	GameHudOpacity->WinLeft = 0.52;
	GameHudOpacity->WinWidth = 0.45;
	GameHudOpacity->TabOrder = 13;
	//GameHudOpacity->OnChange=AATab_HudSettings.InternalOnChange;
	UmoCheckBox* CustomHUDColor = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	CustomHUDColor->ComponentJustification = EeTextAlign::TXTA_Left;
	CustomHUDColor->CaptionWidth = 0.9;
	CustomHUDColor->Caption = "Custom HUD Color";
	//CustomHUDColor->OnCreateComponent=CustomHUDColor.InternalOnCreateComponent;
	CustomHUDColor->IniOption = "@Internal";
	CustomHUDColor->Hint = "Use configured HUD color instead of team colors";
	CustomHUDColor->WinTop = 0.309406;
	CustomHUDColor->WinLeft = 0.52;
	CustomHUDColor->WinWidth = 0.45;
	CustomHUDColor->WinHeight = 0.035;
	CustomHUDColor->TabOrder = 14;
	CustomHUDColor->bStandardized = false;
	//CustomHUDColor->OnChange=AATab_HudSettings.InternalOnChange;
	//CustomHUDColor->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoSlider* HudColorR = NewObject<UmoSlider>(UmoSlider::StaticClass());
	HudColorR->MaxValue = 255;
	HudColorR->bIntSlider = true;
	HudColorR->CaptionWidth = 0.35;
	HudColorR->Caption = "Red:";
	HudColorR->LabelColor = FColor(0, 0, 255, 255);
	//HudColorR->OnCreateComponent=HudColorR.InternalOnCreateComponent;
	HudColorR->Hint = "Adjust the amount of red in the HUD.";
	HudColorR->WinTop = 0.4;
	HudColorR->WinLeft = 0.52;
	HudColorR->WinWidth = 0.45;
	HudColorR->TabOrder = 15;
	//HudColorR->OnChange=AATab_HudSettings.InternalOnChange;
	UmoSlider* HudColorB = NewObject<UmoSlider>(UmoSlider::StaticClass());
	HudColorB->MaxValue = 255;
	HudColorB->bIntSlider = true;
	HudColorB->CaptionWidth = 0.35;
	HudColorB->Caption = "Blue:";
	HudColorB->LabelColor = FColor(255, 0, 0, 255);
	//HudColorB->OnCreateComponent=HudColorB.InternalOnCreateComponent;
	HudColorB->Hint = "Adjust the amount of blue in the HUD.";
	HudColorB->WinTop = 0.45;
	HudColorB->WinLeft = 0.52;
	HudColorB->WinWidth = 0.45;
	HudColorB->TabOrder = 16;
	//HudColorB->OnChange=AATab_HudSettings.InternalOnChange;
	UmoSlider* HudColorG = NewObject<UmoSlider>(UmoSlider::StaticClass());
	HudColorG->MaxValue = 255;
	HudColorG->bIntSlider = true;
	HudColorG->CaptionWidth = 0.35;
	HudColorG->Caption = "Green:";
	HudColorG->LabelColor = FColor(0, 255, 0, 255);
	//HudColorG->OnCreateComponent=HudColorG.InternalOnCreateComponent;
	HudColorG->Hint = "Adjust the amount of green in the HUD.";
	HudColorG->WinTop = 0.5;
	HudColorG->WinLeft = 0.52;
	HudColorG->WinWidth = 0.45;
	HudColorG->TabOrder = 17;
	//HudColorG->OnChange=AATab_HudSettings.InternalOnChange;
	UmoComboBox* CrosshairBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	CrosshairBox->bReadOnly = true;
	CrosshairBox->ComponentJustification = EeTextAlign::TXTA_Left;
	CrosshairBox->CaptionWidth = 0.45;
	CrosshairBox->Caption = "Crosshair";
	//CrosshairBox->OnCreateComponent=CrosshairBox.InternalOnCreateComponent;
	CrosshairBox->IniOption = "@Internal";
	CrosshairBox->Hint = "What Crosshair do you want to use?";
	CrosshairBox->WinTop = 0.85;
	CrosshairBox->WinLeft = 0.52;
	CrosshairBox->WinWidth = 0.42;
	CrosshairBox->WinHeight = 0.035;
	CrosshairBox->TabOrder = 18;
	//CrosshairBox->OnChange=AATab_HudSettings.InternalOnChange;
	//CrosshairBox->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UmoComboBox* RadarPlayerInfoBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	RadarPlayerInfoBox->bReadOnly = true;
	RadarPlayerInfoBox->ComponentJustification = EeTextAlign::TXTA_Left;
	RadarPlayerInfoBox->CaptionWidth = 0.45;
	RadarPlayerInfoBox->Caption = "SAI Player Info";
	//RadarPlayerInfoBox->OnCreateComponent=RadarPlayerInfoBox.InternalOnCreateComponent;
	RadarPlayerInfoBox->IniOption = "@Internal";
	RadarPlayerInfoBox->Hint = "What to display when player info is visible on the SAI.";
	RadarPlayerInfoBox->WinTop = 0.7;
	RadarPlayerInfoBox->WinLeft = 0.04;
	RadarPlayerInfoBox->WinWidth = 0.42;
	RadarPlayerInfoBox->WinHeight = 0.035;
	RadarPlayerInfoBox->TabOrder = 18;
	//RadarPlayerInfoBox->OnChange=AATab_HudSettings.InternalOnChange;
	//RadarPlayerInfoBox->OnLoadINI=AATab_HudSettings.InternalOnLoadINI;
	UGUIImage* PreviewBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//PreviewBackground->Image=Texture'T_AA2_UI.HUD.hud_gren_smoke_01';
	PreviewBackground->ImageStyle = EImgStyle::ISTY_Justified;
	PreviewBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Additive;
	PreviewBackground->ImageAlign = EImgAlign::IMGA_Center;
	PreviewBackground->X1 = 0;
	PreviewBackground->Y1 = 110;
	PreviewBackground->X2 = 166;
	PreviewBackground->Y2 = 163;
	PreviewBackground->WinTop = 0.09;
	PreviewBackground->WinLeft = 0.749335;
	PreviewBackground->WinWidth = 0.163437;
	PreviewBackground->WinHeight = 0.121797;
	PreviewBackground->RenderWeight = 1.002;
	UGUIImage* CrosshairImg = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//CrosshairImg->Image=Texture'T_AA2_UI.Menu.crosshair_a_s';
	CrosshairImg->ImageStyle = EImgStyle::ISTY_Scaled;
	CrosshairImg->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	CrosshairImg->Hint = "Crosshair used in game.";
	CrosshairImg->WinTop = 0.71;
	CrosshairImg->WinLeft = 0.72;
	CrosshairImg->WinWidth = 0.09;
	CrosshairImg->WinHeight = 0.09;
	
	i_PreviewBG = PreviewBackground;
	sl_Opacity = GameHudOpacity;
	sl_Red = HudColorR;
	sl_Green = HudColorG;
	sl_Blue = HudColorB;
	ch_RotateRadar = RotateRadar;
	ch_Visible = GameHudVisible;
	ch_CustomColor = CustomHUDColor;
	ch_AmmoCount = GameHudShowAmmoCount;
	ch_WeaponInfo = GameHudWeaponInfo;
	ch_GrenadeInfo = GameHudGrenadeInfo;
	ch_CEM = GameHudShowCEM;
	ch_PlayerInfo = GameHudShowPlayerInfo;
	ch_Timer = GameHudShowTimer;
	ch_Accessories = GameHudShowAccessories;
	ch_Objectives = GameHudShowObjectives;
	ch_Radar = GameHudShowRadar;
	ch_RadarBlinking = GameHudShowRadarBlinking;
	ch_RadarOpacity = RadarOpacity;
	ch_RadarInfo = GameHudShowRadarInfo;
	mchkbDisplayDelayedStartWarning = GameHudShowDelayedStartWarning;
	co_Crosshair = CrosshairBox;
	co_RadarPlayerInfo = RadarPlayerInfoBox;
	CrosshairImage = CrosshairImg;
	DefaultBGPos = FFloatBox({ 0.749335, 0.167488, 0.163437, 0.121797 });
	DefaultHealthPos = FFloatBox({ 0.748164, 0.169572, 0.063241, 0.099531 });
	
	CrosshairText = { "Crosshair A","Crosshair B","Crosshair C","Crosshair D","Crosshair E","Crosshair F","Crosshair G" };

	//CrosshairImages(0) = Texture'T_AA2_UI.Menu.crosshair_a_s';
	//CrosshairImages(1) = Texture'T_AA2_UI.Menu.crosshair_d_s';
	//CrosshairImages(2) = Texture'T_AA2_UI.Menu.crosshair_g_s';
	//CrosshairImages(3) = Texture'T_AA2_UI.Menu.crosshair_f_s';
	//CrosshairImages(4) = Texture'T_AA2_UI.Menu.crosshair_e_s';
	//CrosshairImages(5) = Texture'T_AA2_UI.Menu.crosshair_c_s';
	//CrosshairImages(6) = Texture'T_AA2_UI.Menu.crosshair_b_s';
	RadarPlayerInfoText = { "Both","Names Only","Elevations Only" };
	PanelCaption = "HUD";
	WinTop = 0.15;
	WinHeight = 0.74;

}

void UAATab_HudSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < 7; i++)
	{
		co_Crosshair.addItem(CrosshairText[i]);
	}
	for (i = 0; i < 3; i++)
	{
		co_RadarPlayerInfo.addItem(RadarPlayerInfoText[i]);
	}
	sl_Opacity.MySlider.bDrawPercentSign = true;
	*/
}

bool UAATab_HudSettings::InternalOnClick(UGUIComponent* Sender)
{
	return true;
}

void UAATab_HudSettings::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	local HUD H;
	local AGP_HUD AGP_H;
	local PlayerController PC;
	local HumanController HC;
	H = PlayerOwner().myHUD;
	AGP_H = AGP_HUD(PlayerOwner().myHUD);
	PC = PlayerOwner();
	HC = HumanController(PC);
	switch (Sender)
	{
	case ch_RotateRadar:
		if (AGP_H != None)
		{
			bRotateRadar = AGP_H.bRotateRadarAroundPlayer;
			ch_RotateRadar.SetComponentValue(string(bRotateRadar), true);
		}
		break;
	case ch_Visible:
		bVis = H.bHideHUD;
		ch_Visible.SetComponentValue(string(bVis), true);
		break;
	case ch_AmmoCount:
		bAmmoCount = (!PC.bHUDHideAmmoCount);
		ch_AmmoCount.SetComponentValue(string(bAmmoCount), true);
		break;
	case ch_WeaponInfo:
		bWeaponInfo = ((!PC.bHUDHideWeaponStatus) || (!PC.bHUDHideWeapon));
		ch_WeaponInfo.SetComponentValue(string(bWeaponInfo), true);
		break;
	case ch_GrenadeInfo:
		bGrenadeInfo = (!PC.bHUDHideGrenades);
		ch_GrenadeInfo.SetComponentValue(string(bGrenadeInfo), true);
		break;
	case ch_CEM:
		bCEM = (!PC.bHUDHideCombatEffect);
		ch_CEM.SetComponentValue(string(bCEM), true);
		break;
	case ch_PlayerInfo:
		bPlayerInfo = (!PC.bHUDHideHealth);
		ch_PlayerInfo.SetComponentValue(string(bPlayerInfo), true);
		break;
	case ch_Timer:
		bTimer = (!PC.bHUDHideTimer);
		ch_Timer.SetComponentValue(string(bTimer), true);
		break;
	case ch_Accessories:
		bAccessories = ((!PC.bHUDHideOptics) || (!PC.bHUDHideMedical));
		ch_Accessories.SetComponentValue(string(bAccessories), true);
		break;
	case ch_Objectives:
		bObjectives = (!PC.bHUDHideObjectives);
		ch_Objectives.SetComponentValue(string(bObjectives), true);
		break;
	case ch_Radar:
		bRadar = (!PC.bHUDHideRadar);
		ch_Radar.SetComponentValue(string(bRadar), true);
		break;
	case ch_RadarBlinking:
		bRadarBlinking = PC.bShowRadarBlinking;
		ch_RadarBlinking.SetComponentValue(string(bRadarBlinking), true);
		break;
	case ch_RadarInfo:
		bRadarInfo = HC.bRadarShowPlayerInfo;
		ch_RadarInfo.SetComponentValue(string(bRadarInfo), true);
		if (bRadarInfo)
		{
			co_RadarPlayerInfo.EnableMe();
		}
		else
		{
			co_RadarPlayerInfo.DisableMe();
		}
		GOTO JL07E7;
	case mchkbDisplayDelayedStartWarning:
		bDisplayDelayedStartWarning = HC.bShowDelayedStartWarningMessage;
		mchkbDisplayDelayedStartWarning.SetComponentValue(string(HC.bShowDelayedStartWarningMessage), true);
		GOTO JL07E7;
	case ch_RadarOpacity:
		iRadarOpacityIndex = AGP_H.RadarMaskIndex;
		ch_RadarOpacity.SetComponentValue(string((iRadarOpacityIndex == 1)), true);
		GOTO JL07E7;
	case ch_Weapons:
		bWeapons = H.bShowWeaponInfo;
		ch_Weapons.SetComponentValue(string(bWeapons), true);
		GOTO JL07E7;
	case ch_Personal:
		bPersonal = H.bShowPersonalInfo;
		ch_Personal.SetComponentValue(string(bPersonal), true);
		GOTO JL07E7;
	case ch_Score:
		bScore = H.bShowPoints;
		ch_Score.SetComponentValue(string(bScore), true);
		GOTO JL07E7;
	case ch_WeaponBar:
		bWeaponBar = H.bShowWeaponBar;
		ch_WeaponBar.SetComponentValue(string(bWeaponBar), true);
		GOTO JL07E7;
	case ch_Portraits:
		bPortraits = H.bShowPortrait;
		ch_Portraits.SetComponentValue(string(bPortraits), true);
		GOTO JL07E7;
	case ch_EnemyNames:
		bNames = (!H.bNoEnemyNames);
		ch_EnemyNames.SetComponentValue(string(bNames), true);
		GOTO JL07E7;
	case nu_MsgCount:
		iCount = H.ConsoleMessageCount;
		nu_MsgCount.SetComponentValue(string(iCount), true);
		GOTO JL07E7;
	case nu_MsgScale:
		iScale = (8 - H.ConsoleFontSize);
		nu_MsgScale.SetComponentValue(string(iScale), true);
		GOTO JL07E7;
	case nu_MsgOffset:
		iOffset = (H.MessageFontOffset + 4);
		nu_MsgOffset.SetComponentValue(string(iOffset), true);
		GOTO JL07E7;
	case ch_CustomColor:
		bCustomColor = Class'AGP.AGP_HUD'.Default.bUsingCustomHUDColor;
		ch_CustomColor.SetComponentValue(string(bCustomColor), true);
		InitializeHUDColor();
		GOTO JL07E7;
	case ch_VCPortraits:
		bVCPortraits = H.bShowPortraitVC;
		ch_VCPortraits.SetComponentValue(string(bVCPortraits), true);
		GOTO JL07E7;
	case co_Crosshair:
		if (HC != None)
		{
			iCrosshair = HC.Default.HUDCrosshair;
		}
		co_Crosshair.SetIndex(iCrosshair);
		UpdateCrosshair(iCrosshair);
		GOTO JL07E7;
	case co_RadarPlayerInfo:
		if (HC != None)
		{
			if (HC.bRadarShowPlayerInfoNames && (!HC.bRadarShowPlayerInfoElevation))
			{
				iRadarPlayerInfo = 1;
			}
			else
			{
				if ((!HC.bRadarShowPlayerInfoNames) && HC.bRadarShowPlayerInfoElevation)
				{
					iRadarPlayerInfo = 2;
				}
				else
				{
					iRadarPlayerInfo = 0;
				}
			}
		}
		co_RadarPlayerInfo.SetIndex(iRadarPlayerInfo);
		iLastRadarPlayerInfo = iRadarPlayerInfo;
		GOTO JL07E7;
	default:
		Log(string(Name) @ "Unknown component calling LoadINI:" $ GUIMenuOption(Sender).Caption);
		GUIMenuOption(Sender).SetComponentValue(S, true);
	JL07E7:
	}
	*/
}

void UAATab_HudSettings::InitializeHUDColor()
{
	/*
	if (bCustomColor)
	{
		cCustom = Class'AGP.AGP_HUD'.Default.CustomHUDColor;
	}
	else
	{
		cCustom = GetDefaultColor();
		sl_Red.DisableMe();
		sl_Blue.DisableMe();
		sl_Green.DisableMe();
	}
	if (AGP_HUD(PlayerOwner().myHUD) != None)
	{
		fOpacity = ((AGP_HUD(PlayerOwner().myHUD).CustomHUDAlpha / float(255)) * float(100));
	}
	sl_Opacity.SetValue(fOpacity);
	sl_Red.SetValue(float(cCustom.R));
	sl_Blue.SetValue(float(cCustom.B));
	sl_Green.SetValue(float(cCustom.G));
	UpdatePreviewColor();
	*/
}

bool UAATab_HudSettings::UsingCustomColor()
{
	/*
	local AGP_HUD Base;
	Base = AGP_HUD(PlayerOwner().myHUD);
	if (Base != None)
	{
		return Base.bUsingCustomHUDColor;
	}
	return ((((Class'AGP.AGP_HUD'.Default.CustomHUDColor.R != 0) || (Class'AGP.AGP_HUD'.Default.CustomHUDColor.B != 0)) || (Class'AGP.AGP_HUD'.Default.CustomHUDColor.G != 0)) || (Class'AGP.AGP_HUD'.Default.CustomHUDColor.A != 0));
	*/
	return false;    //FAKE   /ELiZ
}

FColor UAATab_HudSettings::GetDefaultColor()
{
	int32 i = 0;
	FColor DefaultColor = FColor(0, 0, 0, 0);
	/*
	local PlayerController PC;
	PC = PlayerOwner();
	if ((PC.PlayerReplicationInfo == None) || (PC.PlayerReplicationInfo.Team == None))
	{
		i = int(PC.GetUrlOption("Team"));
	}
	else
	{
		i = PC.PlayerReplicationInfo.Team.TeamIndex;
	}
	DefaultColor.R = 0;
	DefaultColor.B = 0;
	DefaultColor.G = 255;
	DefaultColor.A = 150;
	*/
	return DefaultColor;
}

void UAATab_HudSettings::SaveSettings()
{
	/*
	local PlayerController PC;
	local HUD H;
	local AGP_HUD AGP_H;
	bool bSave = false;
	Super::SaveSettings();
	PC = PlayerOwner();
	H = PC.myHUD;
	AGP_H = AGP_HUD(H);
	if ((AGP_H != None) && (AGP_H.bRotateRadarAroundPlayer != bRotateRadar))
	{
		AGP_H.bRotateRadarAroundPlayer = bRotateRadar;
		bSave = true;
	}
	if (H.bHideHUD != bVis)
	{
		H.bHideHUD = bVis;
		bSave = true;
	}
	if (PC.bHUDHideAmmoCount != (!bAmmoCount))
	{
		PC.bHUDHideAmmoCount = (!bAmmoCount);
		bSave = true;
	}
	if ((PC.bHUDHideWeaponStatus != (!bWeaponInfo)) || (PC.bHUDHideWeapon != (!bWeaponInfo)))
	{
		PC.bHUDHideWeaponStatus = (!bWeaponInfo);
		PC.bHUDHideWeapon = (!bWeaponInfo);
		bSave = true;
	}
	if (PC.bHUDHideGrenades != (!bGrenadeInfo))
	{
		PC.bHUDHideGrenades = (!bGrenadeInfo);
		bSave = true;
	}
	if (PC.bHUDHideCombatEffect != (!bCEM))
	{
		PC.bHUDHideCombatEffect = (!bCEM);
		bSave = true;
	}
	if (PC.bHUDHideHealth != (!bPlayerInfo))
	{
		PC.bHUDHideHealth = (!bPlayerInfo);
		bSave = true;
	}
	if (PC.bHUDHideTimer != (!bTimer))
	{
		PC.bHUDHideTimer = (!bTimer);
		bSave = true;
	}
	if ((PC.bHUDHideOptics != (!bAccessories)) || (PC.bHUDHideMedical != (!bAccessories)))
	{
		PC.bHUDHideOptics = (!bAccessories);
		PC.bHUDHideMedical = (!bAccessories);
		bSave = true;
	}
	if (PC.bHUDHideObjectives != (!bObjectives))
	{
		PC.bHUDHideObjectives = (!bObjectives);
		bSave = true;
	}
	if (PC.bHUDHideRadar != (!bRadar))
	{
		PC.bHUDHideRadar = (!bRadar);
		bSave = true;
	}
	if (PC.bShowRadarBlinking != bRadarBlinking)
	{
		PC.bShowRadarBlinking = bRadarBlinking;
		bSave = true;
	}
	if (HumanController(PC) != None)
	{
		if (bDisplayDelayedStartWarning != HumanController(PC).bShowDelayedStartWarningMessage)
		{
			HumanController(PC).bShowDelayedStartWarningMessage = bDisplayDelayedStartWarning;
			bSave = true;
		}
		if (HumanController(PC).bRadarShowPlayerInfo != bRadarInfo)
		{
			HumanController(PC).bRadarShowPlayerInfo = bRadarInfo;
			bSave = true;
		}
		if (iRadarPlayerInfo != iLastRadarPlayerInfo)
		{
			if (iRadarPlayerInfo == 1)
			{
				HumanController(PC).bRadarShowPlayerInfoNames = true;
				HumanController(PC).bRadarShowPlayerInfoElevation = false;
			}
			else
			{
				if (iRadarPlayerInfo == 2)
				{
					HumanController(PC).bRadarShowPlayerInfoNames = false;
					HumanController(PC).bRadarShowPlayerInfoElevation = true;
				}
				else
				{
					HumanController(PC).bRadarShowPlayerInfoNames = true;
					HumanController(PC).bRadarShowPlayerInfoElevation = true;
				}
			}
			iLastRadarPlayerInfo = iRadarPlayerInfo;
			bSave = true;
		}
	}
	if (H.bShowWeaponInfo != bWeapons)
	{
		H.bShowWeaponInfo = bWeapons;
		bSave = true;
	}
	if (H.bShowPersonalInfo != bPersonal)
	{
		H.bShowPersonalInfo = bPersonal;
		bSave = true;
	}
	if (H.bShowPoints != bScore)
	{
		H.bShowPoints = bScore;
		bSave = true;
	}
	if (H.bShowWeaponBar != bWeaponBar)
	{
		H.bShowWeaponBar = bWeaponBar;
		bSave = true;
	}
	if (H.bShowPortrait != bPortraits)
	{
		H.bShowPortrait = bPortraits;
		bSave = true;
	}
	if (H.bShowPortraitVC != bVCPortraits)
	{
		H.bShowPortraitVC = bVCPortraits;
		bSave = true;
	}
	if (H.bNoEnemyNames == bNames)
	{
		H.bNoEnemyNames = (!bNames);
		bSave = true;
	}
	if (H.ConsoleMessageCount != iCount)
	{
		H.ConsoleMessageCount = iCount;
		bSave = true;
	}
	if (float(H.ConsoleFontSize) != Abs(float((iScale - 8))))
	{
		H.ConsoleFontSize = int(Abs(float((iScale - 8))));
		bSave = true;
	}
	if (H.MessageFontOffset != (iOffset - 4))
	{
		H.MessageFontOffset = (iOffset - 4);
		bSave = true;
	}
	if ((AGP_H != None) && (AGP_H.RadarMaskIndex != iRadarOpacityIndex))
	{
		AGP_H.RadarMaskIndex = iRadarOpacityIndex;
		bSave = true;
	}
	if (AGP_H.CustomHUDAlpha != ((fOpacity / 100) * 255))
	{
		AGP_H.CustomHUDAlpha = ((fOpacity / 100) * 255);
		bSave = true;
	}
	if (ch_CustomColor.IsChecked())
	{
		bSave = true;
	}
	if (AGP_H != None)
	{
		if (SaveCustomHUDColor() || bSave)
		{
			AGP_H.SaveConfig();
			H.SaveConfig();
		}
	}
	else
	{
		if (bSave)
		{
			AGP_H.SaveConfig();
			H.SaveConfig();
		}
		SaveCustomHUDColor();
	}
	if (bSave)
	{
		PC.SaveConfig();
	}
	*/
}

void UAATab_HudSettings::ResetClicked()
{
	/*
	int32 i = 0;
	Super::ResetClicked();
	Class'HUD'.ResetConfig("bHideHUD");
	Class'PlayerController'.ResetConfig("bHUDHideObjectives");
	Class'PlayerController'.ResetConfig("bHUDHideOptics");
	Class'PlayerController'.ResetConfig("bHUDHideMedical");
	Class'PlayerController'.ResetConfig("bShowTimer");
	Class'PlayerController'.ResetConfig("bHUDHideHealth");
	Class'PlayerController'.ResetConfig("bHUDHideCombatEffect");
	Class'PlayerController'.ResetConfig("bHUDHideGrenades");
	Class'PlayerController'.ResetConfig("bHUDHideWeaponStatus");
	Class'PlayerController'.ResetConfig("bHUDHideWeapon");
	Class'PlayerController'.ResetConfig("bHUDHideAmmoCount");
	Class'HUD'.ResetConfig("bShowWeaponInfo");
	Class'HUD'.ResetConfig("bShowPersonalInfo");
	Class'HUD'.ResetConfig("bShowPoints");
	Class'HUD'.ResetConfig("bShowWeaponBar");
	Class'HUD'.ResetConfig("bShowPortrait");
	Class'HUD'.ResetConfig("bShowPortraitVC");
	Class'HUD'.ResetConfig("bNoEnemyNames");
	Class'HUD'.ResetConfig("ConsoleMessageCount");
	Class'HUD'.ResetConfig("ConsoleFontSize");
	Class'HUD'.ResetConfig("MessageFontOffset");
	Class'HUD'.ResetConfig("HudScale");
	Class'HUD'.ResetConfig("HudOpacity");
	Class'AGP.AGP_HUD'.ResetConfig("CustomHUDAlpha");
	Class'XInterface.HudBase'.ResetConfig("CustomHudColor");
	for (i = 0; i < Components.Length; i++)
	{
		Components[i].LoadINI();
	}
	*/
}

bool UAATab_HudSettings::SaveCustomHUDColor()
{
	/*
	FColor Temp = FColor(0, 0, 0, 0);
	local AGP_HUD Base;
	Base = AGP_HUD(PlayerOwner().myHUD);
	Temp = Class'AGP.AGP_HUD'.Default.HUDColor;
	if (Base != None)
	{
		if (bCustomColor)
		{
			if (Base.HUDColor != cCustom)
			{
				Base.HUDColor = cCustom;
				Base.CustomHUDColor = cCustom;
				Base.Default.CustomHUDColor = cCustom;
				Base.Default.bUsingCustomHUDColor = bCustomColor;
				Base.bUsingCustomHUDColor = bCustomColor;
				Base.StaticSaveConfig();
				return true;
			}
		}
		else
		{
			if (Base.HUDColor != Temp)
			{
				Base.HUDColor = Temp;
				Base.Default.HUDColor = Temp;
				Base.Default.bUsingCustomHUDColor = false;
				Base.bUsingCustomHUDColor = false;
				Base.StaticSaveConfig();
				return true;
			}
		}
	}
	else
	{
		if (bCustomColor)
		{
			if (Class'AGP.AGP_HUD'.Default.CustomHUDColor != cCustom)
			{
				Class'AGP.AGP_HUD'.Default.CustomHUDColor = cCustom;
				Class'AGP.AGP_HUD'.Default.bUsingCustomHUDColor = bCustomColor;
				Class'AGP.AGP_HUD'.StaticSaveConfig();
				return false;
			}
		}
		else
		{
			if (Class'AGP.AGP_HUD'.Default.CustomHUDColor != Temp)
			{
				Class'AGP.AGP_HUD'.Default.HUDColor = Temp;
				Class'AGP.AGP_HUD'.Default.bUsingCustomHUDColor = false;
				Class'AGP.AGP_HUD'.StaticSaveConfig();
				return false;
			}
		}
	}
	*/
	return false;
}

void UAATab_HudSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Super::InternalOnChange(Sender);
	switch (Sender)
	{
	case ch_RotateRadar:
		bRotateRadar = ch_RotateRadar.IsChecked();
		break;
	case ch_Visible:
		bVis = ch_Visible.IsChecked();
		break;
	case ch_AmmoCount:
		bAmmoCount = ch_AmmoCount.IsChecked();
		break;
	case ch_WeaponInfo:
		bWeaponInfo = ch_WeaponInfo.IsChecked();
		break;
	case ch_GrenadeInfo:
		bGrenadeInfo = ch_GrenadeInfo.IsChecked();
		break;
	case ch_CEM:
		bCEM = ch_CEM.IsChecked();
		break;
	case ch_PlayerInfo:
		bPlayerInfo = ch_PlayerInfo.IsChecked();
		break;
	case ch_Timer:
		bTimer = ch_Timer.IsChecked();
		break;
	case ch_Accessories:
		bAccessories = ch_Accessories.IsChecked();
		break;
	case ch_Objectives:
		bObjectives = ch_Objectives.IsChecked();
		break;
	case ch_Radar:
		bRadar = ch_Radar.IsChecked();
		break;
	case ch_RadarBlinking:
		bRadarBlinking = ch_RadarBlinking.IsChecked();
		break;
	case ch_RadarInfo:
		bRadarInfo = ch_RadarInfo.IsChecked();
		if (bRadarInfo)
		{
			co_RadarPlayerInfo.EnableMe();
		}
		else
		{
			co_RadarPlayerInfo.DisableMe();
		}
		GOTO JL04CC;
	case ch_Weapons:
		bWeapons = ch_Weapons.IsChecked();
		GOTO JL04CC;
	case ch_Personal:
		bPersonal = ch_Personal.IsChecked();
		GOTO JL04CC;
	case ch_Score:
		bScore = ch_Score.IsChecked();
		GOTO JL04CC;
	case ch_WeaponBar:
		bWeaponBar = ch_WeaponBar.IsChecked();
		GOTO JL04CC;
	case ch_DeathMsgs:
		bNoMsgs = ch_DeathMsgs.IsChecked();
		GOTO JL04CC;
	case ch_Portraits:
		bPortraits = ch_Portraits.IsChecked();
		GOTO JL04CC;
	case ch_VCPortraits:
		bVCPortraits = ch_VCPortraits.IsChecked();
		GOTO JL04CC;
	case ch_EnemyNames:
		bNames = ch_EnemyNames.IsChecked();
		GOTO JL04CC;
	case nu_MsgCount:
		iCount = nu_MsgCount.GetValue();
		GOTO JL04CC;
	case nu_MsgScale:
		iScale = nu_MsgScale.GetValue();
		GOTO JL04CC;
	case nu_MsgOffset:
		iOffset = nu_MsgOffset.GetValue();
		GOTO JL04CC;
	case ch_RadarOpacity:
		if (ch_RadarOpacity.IsChecked())
		{
			iRadarOpacityIndex = 1;
		}
		else
		{
			iRadarOpacityIndex = 0;
		}
		GOTO JL04CC;
	case sl_Opacity:
		fOpacity = sl_Opacity.GetValue();
		UpdatePreviewColor();
		GOTO JL04CC;
	case ch_CustomColor:
		bCustomColor = ch_CustomColor.IsChecked();
		ChangeCustomStatus();
		UpdatePreviewColor();
		GOTO JL04CC;
	case sl_Red:
		cCustom.R = byte(sl_Red.GetValue());
		UpdatePreviewColor();
		GOTO JL04CC;
	case sl_Blue:
		cCustom.B = byte(sl_Blue.GetValue());
		UpdatePreviewColor();
		GOTO JL04CC;
	case sl_Green:
		cCustom.G = byte(sl_Green.GetValue());
		UpdatePreviewColor();
		GOTO JL04CC;
	case co_Crosshair:
		iCrosshair = byte(co_Crosshair.GetIndex());
		UpdateCrosshair(iCrosshair);
		GOTO JL04CC;
	case co_RadarPlayerInfo:
		iRadarPlayerInfo = byte(co_RadarPlayerInfo.GetIndex());
		GOTO JL04CC;
	case mchkbDisplayDelayedStartWarning:
		bDisplayDelayedStartWarning = mchkbDisplayDelayedStartWarning.IsChecked();
		GOTO JL04CC;
	default:
	JL04CC:
	}
	SaveSettings();
	*/
}

void UAATab_HudSettings::ChangeCustomStatus()
{
	/*
	if (bCustomColor)
	{
		sl_Red.EnableMe();
		sl_Blue.EnableMe();
		sl_Green.EnableMe();
		cCustom.R = byte(sl_Red.GetValue());
		cCustom.G = byte(sl_Green.GetValue());
		cCustom.B = byte(sl_Blue.GetValue());
		Class'AGP.AGP_HUD'.Default.bUsingCustomHUDColor = true;
		Class'AGP.AGP_HUD'.StaticSaveConfig();
	}
	else
	{
		sl_Red.DisableMe();
		sl_Blue.DisableMe();
		sl_Green.DisableMe();
		cCustom = GetDefaultColor();
		Class'AGP.AGP_HUD'.Default.bUsingCustomHUDColor = false;
		Class'AGP.AGP_HUD'.StaticSaveConfig();
	}
	*/
}

void UAATab_HudSettings::UpdatePreviewColor()
{
	/*
	float O = 0;
	i_PreviewBG.ImageColor = cCustom;
	O = (255 * (fOpacity / 100));
	i_PreviewBG.ImageColor.A = byte(O);
	*/
}

void UAATab_HudSettings::UpdateCrosshair(uint8 NewCrosshair)
{
	/*
	local AGP_HUD H;
	local PlayerController PC;
	local HumanController HC;
	PreviousCrosshair = iCrosshair;
	PC = PlayerOwner();
	HC = HumanController(PC);
	H = AGP_HUD(PC.myHUD);
	H.SetCrosshair(NewCrosshair);
	CrosshairImage.Image = CrosshairImages[NewCrosshair];
	HC.SetHUDCrosshair(NewCrosshair);
	HC.Default.HUDCrosshair = NewCrosshair;
	HC.StaticSaveConfig();
	*/
}