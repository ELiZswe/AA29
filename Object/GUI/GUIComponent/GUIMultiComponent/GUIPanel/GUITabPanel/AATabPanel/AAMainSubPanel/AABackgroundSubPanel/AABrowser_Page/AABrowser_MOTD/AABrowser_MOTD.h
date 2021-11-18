// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_Page.h"
#include "AABrowser_MOTD.generated.h"

class AServerQueryClient;
class UGUIScrollTextBox;
class UGUILabel;
class UGUIButton;

UCLASS(Config = Game)
class AA29_API UAABrowser_MOTD : public UAABrowser_Page
{
	GENERATED_BODY()
public:
	UAABrowser_MOTD();

	UPROPERTY(EditAnywhere)				UGUIScrollTextBox*			lb_MOTD;				//var() automated XInterface.GUIScrollTextBox lb_MOTD;
	UPROPERTY(EditAnywhere)				UGUILabel*					l_Version;				//var() automated XInterface.GUILabel l_Version;
	UPROPERTY(EditAnywhere)				UGUIButton*					b_QuickConnect;			//var() automated XInterface.GUIButton b_QuickConnect;
	UPROPERTY()							FString						MOTD;					//var FString MOTD;
	UPROPERTY()							bool						bUpgrade;				//var bool bUpgrade;
	UPROPERTY()							bool						bOptionalUpgrade;		//var bool bOptionalUpgrade;
	UPROPERTY()							bool						GotMOTD;				//var bool GotMOTD;
	UPROPERTY()							float						ReReadyPause;			//var float ReReadyPause;
	UPROPERTY()							int32						RetryCount;				//var int32 RetryCount;
	UPROPERTY(EditAnywhere, config)		int32						RetryMax;				//var() config int32 RetryMax;
	UPROPERTY()							FString						UpgradeCaption;			//var localized FString UpgradeCaption;
	UPROPERTY()							FString						VersionString;			//var localized FString VersionString;
	UPROPERTY(config)					FString						QuickConnectMenu;		//var config FString QuickConnectMenu;
	UPROPERTY()							FString						ConnectFailed;			//var localized FString ConnectFailed;
	UPROPERTY()							FString						ConnectTimeout;			//var localized FString ConnectTimeout;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool LaunchURL(UGUIComponent* Sender);
	void Timer();
	void Opened(UGUIComponent* Sender);
	void ShowPanel(bool bShow);
	void Refresh();
	void ReceivedMOTD(EMOTDResponse Command, FString Data);
	void OpenStatusMessage(FString Code, FString Data);
	void QueryComplete(EResponseInfo ResponseInfo, int32 Info);
	void JoinClicked();
	bool IsJoinAvailable(FString& ButtonCaption);
	bool IsRefreshAvailable(FString& ButtonCaption);
	bool InternalOnClick(UGUIComponent* Sender);
	void ResetQueryClient(AServerQueryClient* Client);
	void BindQueryClient(AServerQueryClient* Client);


};
