// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2LoadingWeaponsArena/UT2LoadingWeaponsArena.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UUT2LoadingWeaponsArena::UUT2LoadingWeaponsArena()
{
	UGUIButton* LoadWeapBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	LoadWeapBackground->WinLeft = 0.25;
	LoadWeapBackground->WinWidth = 0.5;
	LoadWeapBackground->WinHeight = 1;
	LoadWeapBackground->bBoundToParent = true;
	LoadWeapBackground->bScaleToParent = true;
	LoadWeapBackground->bAcceptsInput = false;
	LoadWeapBackground->bNeverFocus = true;
	//LoadWeapBackground->OnKeyEvent=LoadWeapBackground.InternalOnKeyEvent;
	UGUILabel* LoadWeapText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	LoadWeapText->Caption = "Loading Weapon Database";
	LoadWeapText->TextAlign = ETextAlign::TXTA_Center;
	LoadWeapText->TextColor = FColor(0, 180, 220, 255);
	LoadWeapText->TextFont = "UT2HeaderFont";
	LoadWeapText->WinTop = 0.471667;
	LoadWeapText->WinHeight = 32;
	Controls = { LoadWeapBackground,LoadWeapText };
	WinTop = 0.425;
	WinHeight = 0.15;
}

void UUT2LoadingWeaponsArena::Timer()
{
	/*
	int32 i = 0;
	Controller.GetWeaponList(Config.WeaponClass, Config.WeaponDesc);
	for (i = 0; i < Config.WeaponClass.Length; i++)
	{
		Config.WeaponCombo.addItem(Config.WeaponClass[i].Default.ItemName, None, string(Config.WeaponClass[i]));
	}
	Config = None;
	Controller.CloseMenu();
	*/
}

void UUT2LoadingWeaponsArena::StartLoad(UUT2ArenaConfig* arena)
{
	/*
	Config = arena;
	SetTimer(0.15);
	*/
}