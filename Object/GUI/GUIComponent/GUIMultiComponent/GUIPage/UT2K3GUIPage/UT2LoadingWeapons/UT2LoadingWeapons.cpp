// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2LoadingWeapons/UT2LoadingWeapons.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UUT2LoadingWeapons::UUT2LoadingWeapons()
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

void UUT2LoadingWeapons::Timer()
{
	/*
	int32 i = 0;
	local TArray<class<Weapon> > WeaponClass;
	local TArray<FString> WeaponDesc;
	Controller.GetWeaponList(WeaponClass, WeaponDesc);
	for (i = 0; i < WeaponClass.Length; i++)
	{
		WeaponTab.MyCurWeaponList.List.Add(WeaponClass[i].Default.ItemName, WeaponClass[i], WeaponDesc[i]);
	}
	WeaponTab.MyCurWeaponList.List.SortList();
	WeaponTab.SpinnyWeap = PlayerOwner().Spawn(class'XInterface.SpinnyWeap');
	WeaponTab.SpinnyWeap.SetRotation(PlayerOwner().Rotation);
	WeaponTab.SpinnyWeap.SetStaticMesh(None);
	WeaponTab.MyCurWeaponList.List.SetIndex(0);
	WeaponTab.UpdateCurrentWeapon();
	WeaponTab.bWeapPrefInitialised = true;
	WeaponTab = nullptr;
	Controller.CloseMenu();
	*/
}

void UUT2LoadingWeapons::StartLoad(UTab_WeaponPref* Tab)
{
	/*
	WeaponTab = Tab;
	SetTimer(0.15);
	*/
}