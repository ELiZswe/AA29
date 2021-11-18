// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/Settings_Tabs.h"
#include "AATab_IForceSettings.generated.h"

class UGUILabel;
class UmoCheckBox;
class UmoFloatEdit;
class UGUIButton;

UCLASS(Config = Game)
class AA29_API UAATab_IForceSettings : public USettings_Tabs
{
	GENERATED_BODY()
public:
	UAATab_IForceSettings();

	UPROPERTY(EditAnywhere)			UGUILabel*		l_IForce;						//var() automated XInterface.GUILabel l_IForce;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_AutoSlope;					//var() automated XInterface.moCheckBox ch_AutoSlope;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_InvertMouse;					//var() automated XInterface.moCheckBox ch_InvertMouse;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_MouseSmoothing;				//var() automated XInterface.moCheckBox ch_MouseSmoothing;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_Joystick;					//var() automated XInterface.moCheckBox ch_Joystick;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_WeaponEffects;				//var() automated XInterface.moCheckBox ch_WeaponEffects;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_PickupEffects;				//var() automated XInterface.moCheckBox ch_PickupEffects;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_DamageEffects;				//var() automated XInterface.moCheckBox ch_DamageEffects;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_GUIEffects;					//var() automated XInterface.moCheckBox ch_GUIEffects;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_MouseLag;					//var() automated XInterface.moCheckBox ch_MouseLag;
	UPROPERTY(EditAnywhere)			UmoFloatEdit*	fl_Sensitivity;					//var() automated XInterface.moFloatEdit fl_Sensitivity;
	UPROPERTY(EditAnywhere)			UmoFloatEdit*	fl_MenuSensitivity;				//var() automated XInterface.moFloatEdit fl_MenuSensitivity;
	UPROPERTY(EditAnywhere)			UmoFloatEdit*	fl_MouseAccel;					//var() automated XInterface.moFloatEdit fl_MouseAccel;
	UPROPERTY(EditAnywhere)			UmoFloatEdit*	fl_SmoothingStrength;			//var() automated XInterface.moFloatEdit fl_SmoothingStrength;
	UPROPERTY(EditAnywhere)			UGUIButton*		b_Controls;						//var() automated XInterface.GUIButton b_Controls;
	UPROPERTY(EditAnywhere)			UGUIButton*		b_Speech;						//var() automated XInterface.GUIButton b_Speech;
	UPROPERTY()						bool			bAim;							//var bool bAim;
	UPROPERTY()						bool			bSlope;							//var bool bSlope;
	UPROPERTY()						bool			bInvert;						//var bool bInvert;
	UPROPERTY()						bool			bSmoothing;						//var bool bSmoothing;
	UPROPERTY()						bool			bJoystick;						//var bool bJoystick;
	UPROPERTY()						bool			bWFX;							//var bool bWFX;
	UPROPERTY()						bool			bPFX;							//var bool bPFX;
	UPROPERTY()						bool			bDFX;							//var bool bDFX;
	UPROPERTY()						bool			bGFX;							//var bool bGFX;
	UPROPERTY()						bool			bLag;							//var bool bLag;
	UPROPERTY()						float			fSens;							//var float fSens;
	UPROPERTY()						float			fMSens;							//var float fMSens;
	UPROPERTY()						float			fAccel;							//var float fAccel;
	UPROPERTY()						float			fSmoothing;						//var float fSmoothing;
	UPROPERTY(config)				FString			ControlBindMenu;				//var config FString ControlBindMenu;
	UPROPERTY(config)				FString			SpeechBindMenu;					//var config FString SpeechBindMenu;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void SaveSettings();
	void ResetClicked();
	void InternalOnChange(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);

};
