// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_InstantActionBaseRules.generated.h"

class UGUISlider;
class UmoCheckBox;
class UGUISlider;
class UmoNumericEdit;

UCLASS(Config = Game)
class AA29_API UTab_InstantActionBaseRules : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_InstantActionBaseRules();

	UPROPERTY(config)		float			LastFriendlyFire;			//var config float LastFriendlyFire;
	UPROPERTY(config)		bool			LastWeaponStay;				//var config bool LastWeaponStay;
	UPROPERTY(config)		bool			LastTranslocator;			//var config bool LastTranslocator;
	UPROPERTY(config)		float			LastGameSpeed;				//var config float LastGameSpeed;
	UPROPERTY(config)		int32			AutLastGoalScoreoAim;		//var config int32 LastGoalScore;
	UPROPERTY(config)		int32			LastTimeLimit;				//var config int32 LastTimeLimit;
	UPROPERTY(config)		int32			LastMaxLives;				//var config int32 LastMaxLives;
	UPROPERTY(config)		bool			bLastWeaponThrowing;		//var config bool bLastWeaponThrowing;
	UPROPERTY()				UGUISlider*		MyGameSpeed;				//var GUISlider MyGameSpeed;
	UPROPERTY()				UmoCheckBox*	MyWeaponStay;				//var moCheckBox MyWeaponStay;
	UPROPERTY()				UmoCheckBox*	MyTranslocator;				//var moCheckBox MyTranslocator;
	UPROPERTY()				UGUISlider*		MyFriendlyFire;				//var GUISlider MyFriendlyFire;
	UPROPERTY()				UmoNumericEdit*	MyGoalScore;				//var moNumericEdit MyGoalScore;
	UPROPERTY()				UmoNumericEdit*	MyTimeLimit;				//var moNumericEdit MyTimeLimit;
	UPROPERTY()				UmoNumericEdit*	MyMaxLives;					//var moNumericEdit MyMaxLives;
	UPROPERTY()				UmoCheckBox*	MyWeaponThrowing;			//var moCheckBox MyWeaponThrowing;
	UPROPERTY()				UmoCheckBox*	MyBrightSkins;				//var moCheckBox MyBrightSkins;
	UPROPERTY()				FString			PercentText;				//var localized FString PercentText;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString Play();
	FString InternalGameSpeedDraw();
	FString InternalFriendlyFireDraw();
	void BrightOnchange(UGUIComponent* Sender);
};
