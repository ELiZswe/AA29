// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageBase.h"
#include "Browser_ServerListPageFavorites.generated.h"

class AServerQueryClient;
class UGUIButton;

/**
 * 
 */
UCLASS()
class AA29_API UBrowser_ServerListPageFavorites : public UBrowser_ServerListPageBase
{
	GENERATED_BODY()
public:
	UBrowser_ServerListPageFavorites();

	UPROPERTY()				TArray<FFavoritesServerInfo>	Favorites;					//var() config TArray<FavoritesServerInfo> Favorites;
	UPROPERTY()				FString							RemoveFavoriteCaption;		//var localized FString RemoveFavoriteCaption;
	UPROPERTY()				FString							AddIPCaption;				//var localized FString AddIPCaption;
	UPROPERTY()				FString							RePingCaption;				//var localized FString RePingCaption;
	UPROPERTY()				AServerQueryClient*				SQC;						//var IpDrv.ServerQueryClient SQC;
	UPROPERTY()				UGUIButton*						MyAddIPButton;				//var GUIButton MyAddIPButton;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool AddIPClick(UGUIComponent* Sender);
	void RefreshList();
	void ShowPanel(bool bShow);
	void CancelPings();
	void OnCloseBrowser();
	void PingServer(int32 ListID, EPingCause PingCause, FServerResponseLine S);
	bool RemoveFavoriteClick(UGUIComponent* Sender);
	void SaveFavorites();
	void FavoriteToServer(int32 i, FServerResponseLine& Server);
	void MyAddFavorite(FServerResponseLine Server);
	void StaticAddFavorite(FString IPString, int32 Port, int32 QueryPort);
};
