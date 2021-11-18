// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanel/AAGUIPanel.h"
#include "AAIRC_Panel.generated.h"

class UGUIButton;
class UmoComboBox;
class UAAIRC_System;
/**
 * 
 */
UCLASS(Config = Game)
class AA29_API UAAIRC_Panel : public UAAGUIPanel
{
	GENERATED_BODY()
public:
	UAAIRC_Panel();

	UPROPERTY(EditAnywhere)							bool				bDirty;					//var() transient bool bDirty;
	UPROPERTY(EditAnywhere)							FString				LocalChannel;			//var localized string LocalChannel;
	UPROPERTY(EditAnywhere)							FString				DisconnectText;			//var localized string DisconnectText;
	UPROPERTY(EditAnywhere)							FString				ConnectText;			//var localized string ConnectText;
	UPROPERTY(EditAnywhere)							TArray<FString>		ChannelHistory;			//var() globalconfig array<String> ChannelHistory;
	UPROPERTY(EditAnywhere)							TArray<FString>		ServerHistory;			//var() globalconfig array<String> ServerHistory;
	UPROPERTY(EditAnywhere)							UGUIButton*			SizingButton;			//var XInterface.GUIButton SizingButton;
	UPROPERTY(EditAnywhere)							UGUIButton*			b_RemChannel;			//var() XInterface.GUIButton b_RemChannel;
	UPROPERTY(EditAnywhere)							UGUIButton*			b_JoinChannel;			//var() XInterface.GUIButton b_JoinChannel;
	UPROPERTY(EditAnywhere)							UGUIButton*			b_RemServer;			//var() XInterface.GUIButton b_RemServer;
	UPROPERTY(EditAnywhere)							UGUIButton*			b_Connect;				//var() XInterface.GUIButton b_Connect;
	UPROPERTY(EditAnywhere)							UmoComboBox*		co_Channel;				//var() XInterface.moComboBox co_Channel;
	UPROPERTY(EditAnywhere)							UmoComboBox*		co_Server;				//var() XInterface.moComboBox co_Server;
	UPROPERTY(EditAnywhere)							UAAIRC_System*		tp_System;				//var AAIRC_System tp_System;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void LoadServerHistory();
	void LoadChannelHistory();
	void GetSizingButton();
	bool PositionButtons(UCanvas* C);
	void InternalOnChange(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
	void UpdateConnectionStatus(bool NowConnected);
	bool AddChannelToHistory(FString NewChannelName, int32 Position);
	bool RemoveChannelFromHistory(FString ChannelName);
	bool AddServerToHistory(FString NewServerName, int32 Position);
	bool RemoveServerFromHistory(FString ServerName);
	int32 FindServerHistoryIndex(FString ServerName);
	int32 FindChannelHistoryIndex(FString ChannelName);
	bool IsCurrentServer(FString ServerAddress);
	void Free();
};
