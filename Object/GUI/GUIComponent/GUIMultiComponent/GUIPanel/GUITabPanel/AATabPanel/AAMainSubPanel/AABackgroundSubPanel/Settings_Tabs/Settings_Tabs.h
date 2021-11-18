// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "Settings_Tabs.generated.h"

class UGUIFooter;

UCLASS(Config = Game)
class AA29_API USettings_Tabs : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	USettings_Tabs();

	UPROPERTY()					UGUIFooter*	t_Footer;					//var XInterface.GUIFooter t_Footer;
	UPROPERTY()					bool		bAlwaysApply;				//var bool bAlwaysApply;
	UPROPERTY()					bool		bNeedApply;					//var bool bNeedApply;
	UPROPERTY(globalconfig)		bool		bExpert;					//var globalconfig bool bExpert;
	UPROPERTY()					FString		PerformanceWarningMenu;		//var FString PerformanceWarningMenu;
	UPROPERTY()					FString		PerformanceWarningText;		//var localized FString PerformanceWarningText;
	UPROPERTY()					float		WarningCounter;				//var float WarningCounter;
	UPROPERTY()					float		WarningLength;				//var float WarningLength;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	void ShowPanel(bool bShow);
	void AcceptClicked();
	void Closed(UGUIComponent* Sender, bool bCancelled);
	void SaveSettings();
	void ResetClicked();
	FString GetNativeClassName(FString VarName);
	void ShowPerformanceWarning(float Seconds);
	void Timer();
	void DrawPerfWarn(UCanvas* C);
	void InternalOnChange(UGUIComponent* Sender);
};
