// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AAPersonnelJacket_Weapon.generated.h"

class AAGP_Weapon;
class ABaseWeaponMod;
class UmoComboBox;
class UGUIImage;
class UGUIScrollTextBox;
class UGUIButton;
class UGUILabel;

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API UAAPersonnelJacket_Weapon : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAAPersonnelJacket_Weapon();

	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Set;				//var() automated XInterface.moComboBox co_Set;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_TopRail;			//var() automated XInterface.moComboBox co_TopRail;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_FrontRail;		//var() automated XInterface.moComboBox co_FrontRail;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_BottomRail;		//var() automated XInterface.moComboBox co_BottomRail;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Barrel;			//var() automated XInterface.moComboBox co_Barrel;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_BG1;				//var() automated XInterface.GUIImage i_BG1;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_BG2;				//var() automated XInterface.GUIImage i_BG2;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_BG3;				//var() automated XInterface.GUIImage i_BG3;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_BG4;				//var() automated XInterface.GUIImage i_BG4;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_BG5;				//var() automated XInterface.GUIImage i_BG5;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_BG6;				//var() automated XInterface.GUIImage i_BG6;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_WeaponBK;			//var() automated XInterface.GUIImage i_WeaponBK;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_WeaponBase;		//var() automated XInterface.GUIImage i_WeaponBase;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_Mod;				//var() automated XInterface.GUIImage i_Mod;
	UPROPERTY(EditAnywhere)			TArray<UGUIImage*>	i_WeaponLayer;		//var() automated XInterface.GUIImage i_WeaponLayer[6];
	UPROPERTY(EditAnywhere)			UGUIScrollTextBox*	lb_Weapons;			//var() automated XInterface.GUIScrollTextBox lb_Weapons;
	UPROPERTY(EditAnywhere)			UGUIScrollTextBox*	lb_Mods;			//var() automated XInterface.GUIScrollTextBox lb_Mods;
	UPROPERTY(EditAnywhere)			UGUIButton*			b_WeaponInfo;		//var() automated XInterface.GUIButton b_WeaponInfo;
	UPROPERTY(EditAnywhere)			UGUIButton*			b_WeaponModInfo;	//var() automated XInterface.GUIButton b_WeaponModInfo;
	UPROPERTY(EditAnywhere)			UGUILabel*			l_Rails;			//var() automated XInterface.GUILabel l_Rails;
	UPROPERTY()						AAGP_Weapon*		CurrentWeapon;		//var class<AGP_Weapon> CurrentWeapon;
	UPROPERTY()						ABaseWeaponMod*		CurrentWeaponMod;	//var class<BaseWeaponMod> CurrentWeaponMod;
	UPROPERTY()						bool				bLoadingSet;		//var bool bLoadingSet;
	UPROPERTY()						uint8				TeamIndex;			//var uint8 TeamIndex;
	UPROPERTY(EditAnywhere)			TArray<FString>		Teams;				//var() localized FString Teams[2];
	UPROPERTY(EditAnywhere)			TArray<FString>		Skins;				//var() localized FString Skins[3];
	UPROPERTY(EditAnywhere)			TArray<FString>		SkinTags;			//var() localized FString SkinTags[3];
	UPROPERTY()						int32				Team;				//var int32 Team;
	UPROPERTY()						FString				Skin;				//var FString Skin;
	UPROPERTY()						FString				HiddenText;			//var localized FString HiddenText;
	UPROPERTY()						FString				LoadingText;		//var localized FString LoadingText;
	UPROPERTY(config)				bool				bDebugPriority;		//var config bool bDebugPriority;
	UPROPERTY(config)				bool				bDebugScale;		//var config bool bDebugScale;
	UPROPERTY(config)				bool				bDebugWeapon;		//var config bool bDebugWeapon;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitializeCombos();
	void IntializeWeapons();
	void ReallyInitializeWeapons(UCanvas* C);
	void ShowPanel(bool bShow);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InternalOnChange(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalDraw(UCanvas* Canvas);
	void Opened(UGUIComponent* Sender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	void InternalDeactivate();
	void Free();
	void Refresh();
	void SaveSettings();
	void WeaponsInitialized();
	void LoadSet();
	void SetChanged();
	void LoadMod(UGUIComponent* Sender, FString S);
	void ModChanged(UGUIComponent* Sender, FString S);
	void SetModImages(int32 Slot, UMaterialInstance* Image, UMaterialInstance* Overlay);
	bool InfoClicked(UGUIComponent* Sender);
	void UpdateCurrentWeapon();
	void UpdateCurrentWeaponMod();
	void AttachModsToWeapon();
	int32 GetModIndex(UGUIComponent* Sender);
	void RefreshMods();
	ABaseWeaponMod* GetWeaponModClass(int32 slot_index);
	FString GetModDescription(int32 slot_index);
	void ResetModOverlay(int32 slot_index);
	void HideSpinnyWeaponAndMod();

};
