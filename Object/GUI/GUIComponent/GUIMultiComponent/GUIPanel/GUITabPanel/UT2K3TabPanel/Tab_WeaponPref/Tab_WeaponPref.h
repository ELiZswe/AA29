// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_WeaponPref.generated.h"

class UGUIListBox;
class UmoCheckBox;
class UGUIScrollTextBox;
class AWeapon;
class ASpinnyWeap;

UCLASS()
class AA29_API UTab_WeaponPref : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_WeaponPref();

	UPROPERTY()			UGUIListBox*			MyCurWeaponList;			//var GUIListBox MyCurWeaponList;
	UPROPERTY()			UmoCheckBox*			SwitchWeaponCheckBox;		//var moCheckBox SwitchWeaponCheckBox;
	UPROPERTY()			UGUIScrollTextBox*		WeaponDescriptionBox;		//var GUIScrollTextBox WeaponDescriptionBox;
	UPROPERTY()			AWeapon*				MyCurWeapon;				//var class<Weapon> MyCurWeapon;
	UPROPERTY()			ASpinnyWeap*			SpinnyWeap;					//var SpinnyWeap SpinnyWeap;
	UPROPERTY()			FVector					SpinnyWeapOffset;			//var Vector SpinnyWeapOffset;
	UPROPERTY()			bool					bWeapPrefInitialised;		//var bool bWeapPrefInitialised;
	UPROPERTY()			bool					bChanged;					//var bool bChanged;
	UPROPERTY()			bool					bUseDefaultPriority;		//var bool bUseDefaultPriority;

	int32 CompareWeaponPriority(FGUIListElem ElemA, FGUIListElem ElemB);
	void ShowPanel(bool bShow);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void UpdateWeaponPriorities();
	bool WeapDefaults(UGUIComponent* Sender);
	bool WeapApply(UGUIComponent* Sender);
	void OnDeActivate();
	void SwapWeapons(int32 IndexA, int32 IndexB);
	bool WeapUp(UGUIComponent* Sender);
	bool WeapDown(UGUIComponent* Sender);
	bool InternalDraw(UCanvas* Canvas);
	void UpdateCurrentWeapon();
	void InternalOnChange(UGUIComponent* Sender);
};
