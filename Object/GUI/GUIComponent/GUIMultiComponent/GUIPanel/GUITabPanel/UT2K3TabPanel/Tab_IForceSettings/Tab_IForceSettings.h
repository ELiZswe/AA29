// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_IForceSettings.generated.h"

class UmoCheckBox; 
class UmoFloatEdit;

UCLASS()
class AA29_API UTab_IForceSettings : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_IForceSettings();

	UPROPERTY()			UmoCheckBox*		AutoAim;			//var moCheckBox AutoAim;
	UPROPERTY()			UmoCheckBox*		AutoSlope;			//var moCheckBox AutoSlope;
	UPROPERTY()			UmoCheckBox*		InvertMouse;		//var moCheckBox InvertMouse;
	UPROPERTY()			UmoCheckBox*		MouseSmooth;		//var moCheckBox MouseSmooth;
	UPROPERTY()			UmoCheckBox*		MouseLag;			//var moCheckBox MouseLag;
	UPROPERTY()			UmoCheckBox*		UseJoystick;		//var moCheckBox UseJoystick;
	UPROPERTY()			UmoFloatEdit*		MouseSens;			//var moFloatEdit MouseSens;
	UPROPERTY()			UmoFloatEdit*		MenuSens;			//var moFloatEdit MenuSens;
	UPROPERTY()			UmoCheckBox*		ifWeapon;			//var moCheckBox ifWeapon;
	UPROPERTY()			UmoCheckBox*		ifPickup;			//var moCheckBox ifPickup;
	UPROPERTY()			UmoCheckBox*		ifDamage;			//var moCheckBox ifDamage;
	UPROPERTY()			UmoCheckBox*		ifGUI;				//var moCheckBox ifGUI;
	UPROPERTY()			UmoFloatEdit*		MouseSmoothStr;		//var moFloatEdit MouseSmoothStr;
	UPROPERTY()			UmoFloatEdit*		MouseThreshold;		//var moFloatEdit MouseThreshold;
	UPROPERTY()			UmoFloatEdit*		DoubleClick;		//var moFloatEdit DoubleClick;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnChange(UGUIComponent* Sender);
};
