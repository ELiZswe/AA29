// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_Page.h"
#include "AABrowser_IRC.generated.h"

class UGUITabControl;
class UAAIRC_System;
class UAAIRC_Channel;

UCLASS(Config = Game)
class AA29_API UAABrowser_IRC : public UAABrowser_Page
{
	GENERATED_BODY()
public:
	UAABrowser_IRC();

	UPROPERTY(EditAnywhere)					UGUITabControl*				c_Channel;				//var() automated XInterface.GUITabControl c_Channel;
	UPROPERTY()								UAAIRC_System*				tp_System;				//var AAIRC_System tp_System;
	UPROPERTY(EditAnywhere, config)			FString						SystemPageClass;		//var() config FString SystemPageClass;
	UPROPERTY(EditAnywhere, config)			FString						PublicChannelClass;		//var() config FString PublicChannelClass;
	UPROPERTY(EditAnywhere, config)			FString						PrivateChannelClass;	//var() config FString PrivateChannelClass;
	UPROPERTY()								FString						SystemLabel;			//var localized FString SystemLabel;
	UPROPERTY()								FString						ChooseNewNickText;		//var localized FString ChooseNewNickText;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void IRCDisconnected();
	void Closed(UGUIComponent* Sender, bool bCancelled);
	void ShowPanel(bool bShow);
	void TabChange(UGUIComponent* Sender);
	void SetCurrentChannel(int32 Index);
	void UpdateCurrentChannel(int32 Index);
	void SetCloseCaption(FString NewName);
	UAAIRC_Channel* AddChannel(FString ChannelName, bool bPrivate);
	bool RemoveChannel(FString ChannelName);
	void JoinClicked();
	void RefreshClicked();
	bool IsRefreshAvailable(FString& ButtonCaption);
	bool IsJoinAvailable(FString& ButtonCaption);

};
