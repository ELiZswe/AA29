// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2ArenaConfig/UT2ArenaConfig.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UUT2ArenaConfig::UUT2ArenaConfig()
{
	UmoComboBox* WeaponSelect = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	WeaponSelect->bReadOnly = true;
	WeaponSelect->ComponentJustification = EeTextAlign::TXTA_Left;
	WeaponSelect->CaptionWidth = 0.3;
	WeaponSelect->Caption = "Weapon";
	//WeaponSelect->OnCreateComponent=WeaponSelect.InternalOnCreateComponent;
	WeaponSelect->IniOption = "@INTERNAL";
	WeaponSelect->WinTop = 0.467448;
	WeaponSelect->WinLeft = 0.29375;
	WeaponSelect->WinWidth = 0.431641;
	WeaponSelect->WinHeight = 0.04;
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.6;
	OkButton->WinLeft = 0.4;
	OkButton->WinWidth = 0.2;
	//OkButton->OnClick=UT2ArenaConfig.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUIButton* DialogBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DialogBackground->StyleName = "ComboListBox";
	DialogBackground->WinHeight = 1;
	DialogBackground->bBoundToParent = true;
	DialogBackground->bScaleToParent = true;
	DialogBackground->bAcceptsInput = false;
	DialogBackground->bNeverFocus = true;
	//DialogBackground->OnKeyEvent=DialogBackground.InternalOnKeyEvent;
	UGUILabel* DialogText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText->Caption = "Weapon Arena";
	DialogText->TextAlign = ETextAlign::TXTA_Center;
	DialogText->TextColor = FColor(0, 180, 220, 255);
	DialogText->TextFont = "UT2HeaderFont";
	DialogText->WinTop = 0.325;
	DialogText->WinHeight = 32;
	UGUILabel* DialogText2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText2->Caption = "Choose the weapon to populate your Arena.";
	DialogText2->TextAlign = ETextAlign::TXTA_Center;
	DialogText2->TextColor = FColor(0, 180, 220, 255);
	DialogText2->WinTop = 0.390626;
	DialogText2->WinHeight = 32;
	Controls = { DialogBackground,OkButton,DialogText,DialogText2,WeaponSelect };
	WinTop = 0.3;
	WinHeight = 0.4;
}

void UUT2ArenaConfig::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	WeaponCombo = moComboBox(Controls[4]);
	if (Controller.OpenMenu("XInterface.UT2LoadingWeaponsArena"))
	{
		UT2LoadingWeaponsArena(Controller.TopPage()).StartLoad(Self);
	}
	*/
}

bool UUT2ArenaConfig::InternalOnClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}