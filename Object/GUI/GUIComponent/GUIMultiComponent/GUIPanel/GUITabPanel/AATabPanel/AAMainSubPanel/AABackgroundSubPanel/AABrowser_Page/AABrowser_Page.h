// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AABrowser_Page.generated.h"

class UAAServerBrowser;
class UAABrowser_Footer;
class AServerQueryClient;

UCLASS()
class AA29_API UAABrowser_Page : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAABrowser_Page();


	UPROPERTY(EditAnywhere)			UAAServerBrowser*			Browser;					//var() AAServerBrowser Browser;
	UPROPERTY(EditAnywhere)			UAABrowser_Footer*			t_Footer;					//var() AABrowser_Footer t_Footer;
	UPROPERTY(EditAnywhere)			FString						MustUpgradeString;			//var() localized FString MustUpgradeString;
	UPROPERTY(EditAnywhere)			FString						QueryCompleteString;		//var() localized FString QueryCompleteString;
	UPROPERTY(EditAnywhere)			FString						StartQueryString;			//var() localized FString StartQueryString;
	UPROPERTY(EditAnywhere)			FString						AuthFailString;				//var() localized FString AuthFailString;
	UPROPERTY(EditAnywhere)			FString						ConnFailString;				//var() localized FString ConnFailString;
	UPROPERTY(EditAnywhere)			FString						ConnTimeoutString;			//var() localized FString ConnTimeoutString;
	UPROPERTY(EditAnywhere)			FString						RetryString;				//var() localized FString RetryString;
	UPROPERTY(EditAnywhere)			FString						ReadyString;				//var() localized FString ReadyString;
	UPROPERTY(EditAnywhere)			FString						StartSBQueryString;			//var() localized FString StartSBQueryString;
	UPROPERTY(EditAnywhere)			FString						SBQueryCompleteString;		//var() localized FString SBQueryCompleteString;
	UPROPERTY(EditAnywhere)			FString						BackCaption;				//var() localized FString BackCaption;
	UPROPERTY(EditAnywhere)			FString						RefreshCaption;				//var() localized FString RefreshCaption;
	UPROPERTY(EditAnywhere)			FString						JoinCaption;				//var() localized FString JoinCaption;
	UPROPERTY(EditAnywhere)			FString						SpectateCaption;			//var() localized FString SpectateCaption;
	UPROPERTY(EditAnywhere)			FString						FilterCaption;				//var() localized FString FilterCaption;
	UPROPERTY(EditAnywhere)			FString						UnspecifiedNetworkError;	//var() localized FString UnspecifiedNetworkError;
	UPROPERTY(EditAnywhere)			FString						CurrentFooterCaption;		//var() FString CurrentFooterCaption;
	UPROPERTY(EditAnywhere)			FString						bCommonButtonWidth;			//var() bool bCommonButtonWidth;
	UPROPERTY(EditAnywhere)			FString						IconKeyCaption;				//var() localized FString IconKeyCaption;


	void OnOpenConnection(int32 Count);
	void OnCloseConnection(int32 Count);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	void ShowPanel(bool bShow);
	bool InternalOnRightClick(UGUIComponent* Sender);
	void QueryComplete(EResponseInfo ResponseInfo, int32 Info);
	void ReceivedPingInfo(int32 ServerID, EPingCause PingCause, FServerResponseLine S);
	void ReceivedPingTimeout(int32 ListID, EPingCause PingCause);
	void AddQueryTerm(FString Key, FString Value, EQueryType QueryType);
	void ResetQueryClient(AServerQueryClient* Client);
	void BindQueryClient(AServerQueryClient* Client);
	void CloseMSConnection();
	void CloseSBConnection();
	void RefreshFooter(UAABrowser_Page* page, FString bPerButtonSizes);
	void SetFooterCaption(FString NewCaption, bool bAppend);
	void SetJoinCaption(FString NewCaption, bool bAppend);
	void SetSpectateCaption(FString NewCaption, bool bAppend);
	void SetRefreshCaption(FString NewCaption, bool bAppend);
	void CheckJoinButton(bool Available);
	void CheckSpectateButton(bool Available);
	void CheckRefreshButton(bool Available);
	void JoinClicked();
	void SpectateClicked();
	void FilterClicked();
	void RefreshClicked();
	bool IsRefreshAvailable(FString& ButtonCaption);
	bool IsSpectateAvailable(FString& ButtonCaption);
	bool IsJoinAvailable(FString& ButtonCaption);
	bool IsFilterAvailable(FString& ButtonCaption);
	void ShowNetworkError(FString ErrorMsg);
	void NetworkErrorClosed(bool bCancelled);
	void CheckFilterButton(bool Available);
	void CheckIconKeyButton(bool Available);
	void IconKeyClicked();
	bool IsIconKeyAvailable(FString& ButtonCaption);


};
