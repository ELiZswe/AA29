// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_Page.h"
#include "Browser_MOTD.generated.h"

class AMasterServerClient;
class UGUIScrollTextBox;
class UGUIButton;
class UGUITitleBar;

UCLASS()
class AA29_API UBrowser_MOTD : public UBrowser_Page
{
	GENERATED_BODY()
public:
	UBrowser_MOTD();

	UPROPERTY()								AMasterServerClient*	MSC;					//var IpDrv.MasterServerClient MSC;
	UPROPERTY()								FString					MOTD;					//var FString MOTD;
	UPROPERTY()								UGUIScrollTextBox*		MOTDTextBox;			//var GUIScrollTextBox MOTDTextBox;
	UPROPERTY()								UGUIButton*				UpgradeButton;			//var GUIButton UpgradeButton;
	UPROPERTY()								bool					MustUpgrade;			//var bool MustUpgrade;
	UPROPERTY()								bool					GotMOTD;				//var bool GotMOTD;
	UPROPERTY()								UGUITitleBar*			StatusBar;				//var GUITitleBar StatusBar;
	UPROPERTY()								float					ReReadyPause;			//var float ReReadyPause;
	UPROPERTY()								FString					VersionString;			//var localized FString VersionString;

	void Timer();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void MyReceivedMOTDData(EMOTDResponse Command, FString Data);
	void MyQueryFinished(EResponseInfo ResponseInfo, int32 Info);
	void OnCloseBrowser();
	bool BackClick(UGUIComponent* Sender);
	bool RefreshClick(UGUIComponent* Sender);
	bool UpgradeClick(UGUIComponent* Sender);
};
