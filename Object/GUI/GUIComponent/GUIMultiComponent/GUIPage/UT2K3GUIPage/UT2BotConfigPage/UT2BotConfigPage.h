// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2BotConfigPage.generated.h"

class UGUIImage;
class UGUILabel;
class UmoComboBox;
class UGUISlider;

UCLASS()
class AA29_API UUT2BotConfigPage : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2BotConfigPage();

	UPROPERTY()				FString					NoInformation;				//var localized FString NoInformation;
	UPROPERTY()				UGUIImage*				BotPortrait;				//var GUIImage BotPortrait;
	UPROPERTY()				UGUILabel*				botname;					//var GUILabel botname;
	UPROPERTY()				int32					ConfigIndex;				//var int32 ConfigIndex;
	UPROPERTY()				bool					bIgnoreChange;				//var bool bIgnoreChange;
	UPROPERTY()				UmoComboBox*			Wep;						//var moComboBox Wep;
	UPROPERTY()				TArray<FWeaponRecord>	Records;					//var TArray<CacheManager.WeaponRecord> Records;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool OkClick(UGUIComponent* Sender);
	bool ResetClick(UGUIComponent* Sender);
	FString DoPerc(UGUISlider* Control);
	FString AggDC();
	FString AccDC();
	FString ComDC();
	FString StrDC();
	FString TacDC();
	FString ReaDC();
	void SetDefaults();
	void SliderChange(UGUIComponent* Sender);
	void CheckBoxChange(UGUIComponent* Sender);
	void ComboBoxChange(UGUIComponent* Sender);
};
