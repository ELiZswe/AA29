// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAMainPanel.h"
#include "AAServerBrowser.generated.h"

class UGUIHeader;
class UButtonFooter;
class UmoComboBox;
class AMasterServerClient;
class UBrowserFilters;
class UPlayInfo;
class UAABrowser_Footer;
class UAABrowser_Page;
//class AServerBrowserBase;
class UAABrowser_ServersList;

UCLASS(Config = Game)
class AA29_API UAAServerBrowser : public UAAMainPanel
{
	GENERATED_BODY()
public:
	UAAServerBrowser();


	UPROPERTY(EditAnywhere)						UGUIHeader*				t_Header;						//var() automated XInterface.GUIHeader t_Header;
	UPROPERTY(EditAnywhere)						UButtonFooter*			t_Footer;						//var() automated ButtonFooter t_Footer;
	UPROPERTY(EditAnywhere, globalconfig)		bool					bStandardServersOnly;			//var() globalconfig bool bStandardServersOnly;
	UPROPERTY(EditAnywhere)						FString					CurrentGameType;				//var() config FString CurrentGameType;
	UPROPERTY(EditAnywhere, config)				bool					bPlayerVerified;				//var config bool bPlayerVerified;
	UPROPERTY(EditAnywhere)						FString					InternetSettingsPage;			//var FString InternetSettingsPage;
	UPROPERTY(EditAnywhere)						UmoComboBox*			co_GameType;					//var() automated XInterface.moComboBox co_GameType;
	UPROPERTY()									AMasterServerClient*	MSC;							//var IpDrv.MasterServerClient MSC;
	UPROPERTY()									UBrowserFilters*		FilterMaster;					//var BrowserFilters FilterMaster;
	UPROPERTY()									UPlayInfo*				FilterInfo;						//var PlayInfo FilterInfo;
	UPROPERTY()									UAABrowser_Footer*		f_Browser;						//var AABrowser_Footer f_Browser;
	UPROPERTY()									bool					Verified;						//var transient bool Verified;
	UPROPERTY()									int32					ThreadCount;					//var int32 ThreadCount;
	UPROPERTY()									FGameRecord				Records;						//var TArray<CacheManager.GameRecord> Records;
	UPROPERTY()									UAABrowser_Page*		tp_Active;						//var AABrowser_Page tp_Active;
	UPROPERTY()									FString					InternetOptionsText;			//var localized FString InternetOptionsText;
	UPROPERTY()									bool					bHideNetworkMessage;			//var bool bHideNetworkMessage;
	UPROPERTY()									TArray<FString>			OfficialSubnets;				//var FString OfficialSubnets[2];
	//UPROPERTY()									AServerBrowserBase*		SBLink;							//var IpDrv.ServerBrowserBase SBLink;
	UPROPERTY(EditAnywhere, globalconfig)		bool					bPunkBusterEnabled;				//var() globalconfig bool bPunkBusterEnabled;
	UPROPERTY(EditAnywhere, globalconfig)		FString					sBrowserPassword;				//var() localized globalconfig FString sBrowserPassword;
	UPROPERTY(EditAnywhere, globalconfig)		FeServerCacheInfo		ServerCache;					//var() globalconfig TArray<eServerCacheInfo> ServerCache;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	AMasterServerClient* Uplink();
	void Opened(UGUIComponent* Sender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	bool ComboOnPreDraw(UCanvas* Canvas);
	void InitializeGameTypeCombo( bool ClearFirst);
	void BrowserOpened();
	void MOTDVerified(bool bMSVerified);
	void CheckPlayerOptions();
	bool InternetOptionsConfirm(uint8 ButtonMask);
	void InternetOptionsClosed(bool bCancelled);
	void CreateTabs();
	void EnableMSTabs();
	void DisableMSTabs();
	UAABrowser_Page* AddTab(FString TabCaption, FString PanelClassName, FString TabHint);
	void OnAddFavorite(FServerResponseLine Server);
	bool NotifyLevelChange();
	void InternalOnChange(UGUIComponent* Sender);
	void StandardOptionChanged(UGUIComponent* Sender);
	void SetStandardServersOption(bool bOnlyStandard);
	void RefreshFooter(UAABrowser_Page* NewActive, FString bPerButtonSizes);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void PopulateGameTypes();
	//FString GetDesc(FString Desc);
	void SetFilterInfo(FString NewGameType);
	void JoinClicked();
	void SpectateClicked();
	void RefreshClicked();
	void FilterClicked();
	void Refresh();
	int32 CalculateMaxConnections();
	int32 GetMaxConnections(bool bCurrentlyAvailable);
	void ConnectionOpened(int32 Num);
	void ConnectionClosed(int32 Num);
	void ClearServerCache();
	void AddToServerCache(FServerResponseLine Entry);
	void GetFromServerCache(UAABrowser_ServersList* List);
	void ShowPanel(bool bShow);
	//AServerBrowserBase* SBUplink(bool bLAN);
	void PunkBusterOptionChanged(UGUIComponent* Sender);
	void SetPunkBusterOption(bool bEnablePunkBuster);
	void BrowserPasswordChanged(UGUIComponent* Sender);
	void SetBrowserPassword(FString sPassword);
	void IconKeyClicked();
};
