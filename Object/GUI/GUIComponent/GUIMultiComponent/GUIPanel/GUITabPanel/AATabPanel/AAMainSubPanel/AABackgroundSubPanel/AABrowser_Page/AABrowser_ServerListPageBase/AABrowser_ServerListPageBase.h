// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_Page.h"
#include "AABrowser_ServerListPageBase.generated.h"

class UBrowserFilters;
class UGUISplitter;
class UGUILabel;
class UGUIButton;
class UmoComboBox;
class UmoCheckBox;
class UmoEditBox;
class UAABrowser_ServerListBox;
class UAABrowser_RulesListBox;
class UAABrowser_PlayersListBox;
class UAABrowser_ServersList;
class UAABrowser_RulesList;
class UAABrowser_PlayersList;

UCLASS(Config = Game)
class AA29_API UAABrowser_ServerListPageBase : public UAABrowser_Page
{
	GENERATED_BODY()
public:
	UAABrowser_ServerListPageBase();

	UPROPERTY(EditAnywhere)					UGUISplitter*				sp_Main;					//var() automated XInterface.GUISplitter sp_Main;
	UPROPERTY()								UGUISplitter*				sp_Detail;					//var XInterface.GUISplitter sp_Detail;
	UPROPERTY(EditAnywhere)					UGUILabel*					l_StatusBar;				//var() automated XInterface.GUILabel l_StatusBar;
	UPROPERTY(EditAnywhere)					UGUIButton*					b_Join;						//var() automated XInterface.GUIButton b_Join;
	UPROPERTY(EditAnywhere)					UGUIButton*					b_Spectate;					//var() automated XInterface.GUIButton b_Spectate;
	UPROPERTY(EditAnywhere)					UGUIButton*					b_Back;						//var() automated XInterface.GUIButton b_Back;
	UPROPERTY(EditAnywhere)					UGUIButton*					b_Refresh;					//var() automated XInterface.GUIButton b_Refresh;
	UPROPERTY(EditAnywhere)					UGUIButton*					b_Filter;					//var() automated XInterface.GUIButton b_Filter;
	UPROPERTY(EditAnywhere)					UmoComboBox*				co_BrowserSwitcher;			//var() automated XInterface.moComboBox co_BrowserSwitcher;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				ch_PunkBuster;				//var() automated XInterface.moCheckBox ch_PunkBuster;
	UPROPERTY(EditAnywhere)					UmoEditBox*					ed_Password;				//var() automated XInterface.moEditBox ed_Password;
	UPROPERTY(EditAnywhere, config)			FString						RulesListBoxClass;			//var() config FString RulesListBoxClass;
	UPROPERTY(EditAnywhere, config)			FString						PlayersListBoxClass;		//var() config FString PlayersListBoxClass;
	UPROPERTY(EditAnywhere, config)			float						MainSplitterPosition;		//var() config float MainSplitterPosition;
	UPROPERTY(EditAnywhere, config)			float						DetailSplitterPosition;		//var() config float DetailSplitterPosition;
	UPROPERTY(EditAnywhere, config)			TArray<FHeaderColumnPos>	HeaderColumnSizes2512;		//var() config TArray<HeaderColumnPos> HeaderColumnSizes2512;
	UPROPERTY(EditAnywhere)					UAABrowser_ServerListBox*	lb_Server;					//var AABrowser_ServerListBox lb_Server;
	UPROPERTY()								UAABrowser_RulesListBox*	lb_Rules;					//var AABrowser_RulesListBox lb_Rules;
	UPROPERTY()								UAABrowser_PlayersListBox*	lb_Players;					//var AABrowser_PlayersListBox lb_Players;
	UPROPERTY()								UAABrowser_ServersList*		li_Server;					//var AABrowser_ServersList li_Server;
	UPROPERTY()								UAABrowser_RulesList*		li_Rules;					//var AABrowser_RulesList li_Rules;
	UPROPERTY()								UAABrowser_PlayersList*		li_Players;					//var AABrowser_PlayersList li_Players;
	UPROPERTY()								UBrowserFilters*			FilterMaster;				//var BrowserFilters FilterMaster;
	UPROPERTY()								bool						bAllowUpdates;				//var bool bAllowUpdates;
	UPROPERTY()								bool						ConnectLAN;					//var bool ConnectLAN;
	UPROPERTY()								FString						PingingText;				//var localized FString PingingText;
	UPROPERTY()								FString						PingCompleteText;			//var localized FString PingCompleteText;
	UPROPERTY()								FString						sProgress;					//var localized FString sProgress;
	UPROPERTY()								FString						BrowserSwitchWarning;		//var localized FString BrowserSwitchWarning;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	void ShowPanel(bool bShow);
	void Refresh();
	void InitServerList();
	void RefreshList();
	void JoinClicked();
	void SpectateClicked();
	void UpdateStatusPingCount();
	void CancelPings();
	void PingServer(int32 ListID, EPingCause PingCause, FServerResponseLine S);
	void MousePressed(UGUIComponent* Sender, bool bRepeat);
	void MouseReleased(UGUIComponent* Sender);
	void RefreshCurrentServer();
	void ServerListChanged(UGUIComponent* Sender);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InternalReleaseSplitter(UGUIComponent* Sender, float NewPos);
	FString InternalOnSaveINI(UGUIComponent* Sender);
	bool IsRefreshAvailable(FString& ButtonCaption);
	bool IsSpectateAvailable(FString& ButtonCaption);
	bool IsJoinAvailable(FString& ButtonCaption);
	void SetProgress(FString Progress);
	bool InternalOnClick(UGUIComponent* Sender);
	void SwitchBrowserConfirm(bool bCancelled);
	void InternalOnChange(UGUIComponent* Sender);
	bool PreDrawStatus(UCanvas* C);
};
