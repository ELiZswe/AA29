// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/Settings_Tabs.h"
#include "AATab_HudSettings.generated.h"

class UGUIImage;
class UmoSlider;
class UmoNumericEdit;
class UmoCheckBox;
class UmoComboBox;
class UGUIComboBox;
class UGUIButton;

UCLASS()
class AA29_API UAATab_HudSettings : public USettings_Tabs
{
	GENERATED_BODY()
public:
	UAATab_HudSettings();

	UPROPERTY(EditAnywhere)			UGUIImage*			i_PreviewBG;						//var() automated XInterface.GUIImage i_PreviewBG;
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_Opacity;							//var() automated XInterface.moSlider sl_Opacity;
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_Red;								//var() automated XInterface.moSlider sl_Red;
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_Green;							//var() automated XInterface.moSlider sl_Green;
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_Blue;							//var() automated XInterface.moSlider sl_Blue;
	UPROPERTY(EditAnywhere)			UmoNumericEdit*		nu_MsgCount;						//var() automated XInterface.moNumericEdit nu_MsgCount;
	UPROPERTY(EditAnywhere)			UmoNumericEdit*		nu_MsgScale;						//var() automated XInterface.moNumericEdit nu_MsgScale;
	UPROPERTY(EditAnywhere)			UmoNumericEdit*		nu_MsgOffset;						//var() automated XInterface.moNumericEdit nu_MsgOffset;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_RotateRadar;						//var() automated XInterface.moCheckBox ch_RotateRadar;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Visible;							//var() automated XInterface.moCheckBox ch_Visible;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Weapons;							//var() automated XInterface.moCheckBox ch_Weapons;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Personal;						//var() automated XInterface.moCheckBox ch_Personal;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Score;							//var() automated XInterface.moCheckBox ch_Score;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_WeaponBar;						//var() automated XInterface.moCheckBox ch_WeaponBar;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Portraits;						//var() automated XInterface.moCheckBox ch_Portraits;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_VCPortraits;						//var() automated XInterface.moCheckBox ch_VCPortraits;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_DeathMsgs;						//var() automated XInterface.moCheckBox ch_DeathMsgs;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_EnemyNames;						//var() automated XInterface.moCheckBox ch_EnemyNames;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_CustomColor;						//var() automated XInterface.moCheckBox ch_CustomColor;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_AmmoCount;						//var() automated XInterface.moCheckBox ch_AmmoCount;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_WeaponInfo;						//var() automated XInterface.moCheckBox ch_WeaponInfo;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_GrenadeInfo;						//var() automated XInterface.moCheckBox ch_GrenadeInfo;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_CEM;								//var() automated XInterface.moCheckBox ch_CEM;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_PlayerInfo;						//var() automated XInterface.moCheckBox ch_PlayerInfo;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Timer;							//var() automated XInterface.moCheckBox ch_Timer;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Accessories;						//var() automated XInterface.moCheckBox ch_Accessories;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Objectives;						//var() automated XInterface.moCheckBox ch_Objectives;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Radar;							//var() automated XInterface.moCheckBox ch_Radar;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_RadarBlinking;					//var() automated XInterface.moCheckBox ch_RadarBlinking;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_RadarOpacity;					//var() automated XInterface.moCheckBox ch_RadarOpacity;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_RadarInfo;						//var() automated XInterface.moCheckBox ch_RadarInfo;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		mchkbDisplayDelayedStartWarning;	//var() automated XInterface.moCheckBox mchkbDisplayDelayedStartWarning;
	UPROPERTY(EditAnywhere)			UGUIComboBox*		co_CustomHUD;						//var() automated XInterface.GUIComboBox co_CustomHUD;
	UPROPERTY(EditAnywhere)			UGUIButton*			b_CustomHUD;						//var() automated XInterface.GUIButton b_CustomHUD;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Crosshair;						//var() automated XInterface.moComboBox co_Crosshair;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_RadarPlayerInfo;					//var() automated XInterface.moComboBox co_RadarPlayerInfo;
	UPROPERTY(EditAnywhere)			UGUIImage*			CrosshairImage;						//var() automated XInterface.GUIImage CrosshairImage;
	UPROPERTY(EditAnywhere)			bool				bRotateRadar;						//var() bool bRotateRadar;
	UPROPERTY(EditAnywhere)			bool				bVis;								//var() bool bVis;
	UPROPERTY(EditAnywhere)			bool				bWeapons;							//var() bool bWeapons;
	UPROPERTY(EditAnywhere)			bool				bPersonal;							//var() bool bPersonal;
	UPROPERTY(EditAnywhere)			bool				bScore;								//var() bool bScore;
	UPROPERTY(EditAnywhere)			bool				bPortraits;							//var() bool bPortraits;
	UPROPERTY(EditAnywhere)			bool				bVCPortraits;						//var() bool bVCPortraits;
	UPROPERTY(EditAnywhere)			bool				bNames;								//var() bool bNames;
	UPROPERTY(EditAnywhere)			bool				bCustomColor;						//var() bool bCustomColor;
	UPROPERTY(EditAnywhere)			bool				bNoMsgs;							//var() bool bNoMsgs;
	UPROPERTY(EditAnywhere)			bool				bWeaponBar;							//var() bool bWeaponBar;
	UPROPERTY(EditAnywhere)			bool				bAmmoCount;							//var() bool bAmmoCount;
	UPROPERTY(EditAnywhere)			bool				bWeaponInfo;						//var() bool bWeaponInfo;
	UPROPERTY(EditAnywhere)			bool				bGrenadeInfo;						//var() bool bGrenadeInfo;
	UPROPERTY(EditAnywhere)			bool				bCEM;								//var() bool bCEM;
	UPROPERTY(EditAnywhere)			bool				bPlayerInfo;						//var() bool bPlayerInfo;
	UPROPERTY(EditAnywhere)			bool				bTimer;								//var() bool bTimer;
	UPROPERTY(EditAnywhere)			bool				bAccessories;						//var() bool bAccessories;
	UPROPERTY(EditAnywhere)			bool				bObjectives;						//var() bool bObjectives;
	UPROPERTY(EditAnywhere)			bool				bRadar;								//var() bool bRadar;
	UPROPERTY(EditAnywhere)			bool				bRadarBlinking;						//var() bool bRadarBlinking;
	UPROPERTY(EditAnywhere)			bool				bRadarInfo;							//var() bool bRadarInfo;
	UPROPERTY(EditAnywhere)			bool				bDisplayDelayedStartWarning;		//var() bool bDisplayDelayedStartWarning;
	UPROPERTY(EditAnywhere)			int32				iRadarOpacityIndex;					//var() int32 iRadarOpacityIndex;
	UPROPERTY(EditAnywhere)			int32				iCount;								//var() int32 iCount;
	UPROPERTY(EditAnywhere)			int32				iScale;								//var() int32 iScale;
	UPROPERTY(EditAnywhere)			int32				iOffset;							//var() int32 iOffset;
	UPROPERTY(EditAnywhere)			float				fOpacity;							//var() float fOpacity;
	UPROPERTY(EditAnywhere)			FColor				cCustom;							//var() Color cCustom;
	UPROPERTY(EditAnywhere)			FFloatBox			DefaultBGPos;						//var() FloatBox DefaultBGPos;
	UPROPERTY(EditAnywhere)			FFloatBox			DefaultHealthPos;					//var() FloatBox DefaultHealthPos;
	UPROPERTY(EditAnywhere)			uint8				iCrosshair;							//var() uint8 iCrosshair;
	UPROPERTY(EditAnywhere)			uint8				PreviousCrosshair;					//var uint8 PreviousCrosshair;
	UPROPERTY(EditAnywhere)			TArray<FString>		CrosshairText;						//var localized FString CrosshairText[7];
	UPROPERTY(EditAnywhere)			TArray<UMaterialInstance*>	CrosshairImages;			//var Material CrosshairImages[7];
	UPROPERTY(EditAnywhere)			uint8				iRadarPlayerInfo;					//var uint8 iRadarPlayerInfo;
	UPROPERTY(EditAnywhere)			uint8				iLastRadarPlayerInfo;				//var uint8 iLastRadarPlayerInfo;
	UPROPERTY(EditAnywhere)			TArray<FString>		RadarPlayerInfoText;				//var localized FString RadarPlayerInfoText[3];

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InitializeHUDColor();
	bool UsingCustomColor();
	FColor GetDefaultColor();
	void SaveSettings();
	void ResetClicked();
	bool SaveCustomHUDColor();
	void InternalOnChange(UGUIComponent* Sender);
	void ChangeCustomStatus();
	void UpdatePreviewColor();
	void UpdateCrosshair(uint8 NewCrosshair);
};
