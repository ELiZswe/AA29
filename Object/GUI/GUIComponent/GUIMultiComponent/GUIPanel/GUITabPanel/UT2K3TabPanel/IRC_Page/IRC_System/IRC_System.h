// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_Page.h"
#include "IRC_System.generated.h"

class UBrowser_IRC;
class UIRC_Private;

class UIRC_Channel;
class AIRCLink;
class UGUILabel;
class UGUIButton;
class UGUIComboBox;

UCLASS()
class AA29_API UIRC_System : public UIRC_Page
{
	GENERATED_BODY()
public:
	UIRC_System();

	UPROPERTY()			UBrowser_IRC*			IRCPage;					//var Browser_IRC IRCPage;
	UPROPERTY()			AIRCLink*				link;						//var IRCLink link;
	UPROPERTY()			TArray<UIRC_Channel*>	Channels;					//var TArray<IRC_Channel> Channels;
	UPROPERTY()			FString					TestIRCString;				//var FString TestIRCString;
	UPROPERTY(config)	FString					NickName;					//var config FString NickName;
	UPROPERTY(config)	FString					FullName;					//var config FString FullName;
	UPROPERTY(config)	FString					OldPlayerName;				//var config FString OldPlayerName;
	UPROPERTY(config)	FString					UserIdent;					//var config FString UserIdent;
	UPROPERTY(config)	TArray<FString>			ServerHistory;				//var config TArray<FString> ServerHistory;
	UPROPERTY(config)	TArray<FString>			ChannelHistory;				//var config TArray<FString> ChannelHistory;
	UPROPERTY(config)	TArray<FString>			DefaultChannels;			//var localized TArray<FString> DefaultChannels;
	UPROPERTY()			bool					bConnected;					//var bool bConnected;
	UPROPERTY()			bool					bAway;						//var bool bAway;
	UPROPERTY()			bool					bSysInitialised;			//var bool bSysInitialised;
	UPROPERTY()			FString					NotInAChannelText;			//var localized FString NotInAChannelText;
	UPROPERTY()			FString					KickedFromText;				//var localized FString KickedFromText;
	UPROPERTY()			FString					ByText;						//var localized FString ByText;
	UPROPERTY()			FString					IsAwayText;					//var localized FString IsAwayText;
	UPROPERTY()			FString					ConnectText;				//var localized FString ConnectText;
	UPROPERTY()			FString					DisconnectText;				//var localized FString DisconnectText;
	UPROPERTY()			UGUILabel*				ServerLabel;				//var GUILabel ServerLabel;
	UPROPERTY()			UGUIButton*				ConnectButton;				//var GUIButton ConnectButton;
	UPROPERTY()			UGUIComboBox*			ServerCombo;				//var GUIComboBox ServerCombo;
	UPROPERTY()			UGUIButton*				RemoveServerButton;			//var GUIButton RemoveServerButton;
	UPROPERTY()			UGUILabel*				ChannelLabel;				//var GUILabel ChannelLabel;
	UPROPERTY()			UGUIButton*				JoinChannelButton;			//var GUIButton JoinChannelButton;
	UPROPERTY()			UGUIComboBox*			ChannelCombo;				//var GUIComboBox ChannelCombo;
	UPROPERTY()			UGUIButton*				RemoveChannelButton;		//var GUIButton RemoveChannelButton;
	UPROPERTY()			int32					CurChannel;					//var int32 CurChannel;
	UPROPERTY()			int32					PrevChannel;				//var int32 PrevChannel;

	void UpdateConnectCaption();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	int32 FindServerHistoryIndex(FString ServerName);
	int32 FindChannelHistoryIndex(FString ChannelName);
	bool ConnectClick(UGUIComponent* Sender);
	bool JoinChannelClick(UGUIComponent* Sender);
	bool RemoveServerClick(UGUIComponent* Sender);
	bool RemoveChannelClick(UGUIComponent* Sender);
	void Timer();
	void SetCurrentChannelPage(UIRC_Channel* ChannelPage);
	void SetCurrentChannel(int32 idx);
	UIRC_Page* GetActivePage();
	void ProcessInput(FString Text);
	UIRC_Channel* FindChannelWindow(FString Channel);
	int32 FindChannelIndex(FString Channel);
	UIRC_Private* FindPrivateWindow(FString Nick);
	void Connect();
	void JoinChannel(FString ChannelName);
	void PartCurrentChannel();
	void PartChannel(FString ChannelName);
	void Disconnect();
	void NotifyQuitUnreal();
	void SystemText(FString Text);
	void ChannelText(FString Channel, FString Nick, FString Text);
	void PrivateText(FString Nick, FString Text);
	UIRC_Private* CreatePrivChannel(FString Nick, bool bMakeActive);
	void ChannelAction(FString Channel, FString Nick, FString Text);
	void PrivateAction(FString Nick, FString Text);
	void JoinedChannel(FString Channel, FString Nick);
	void RemoveChannel(FString Channel);
	void KickUser(FString Channel, FString KickedNick, FString Kicker, FString Reason);
	void UserInChannel(FString Channel, FString Nick);
	void PartedChannel(FString Channel, FString Nick);
	void ChangedNick(FString OldNick, FString NewNick);
	void UserQuit(FString Nick, FString Reason);
	void UserNotice(FString Nick, FString Text);
	void ChangeMode(FString Channel, FString Nick, FString Mode);
	void ChangeOp(FString Channel, FString Nick, bool bOp);
	void ChangeHalfOp(FString Channel, FString Nick, bool bHalfOp);
	void ChangeVoice(FString Channel, FString Nick, bool bVoice);
	void ChangeTopic(FString Channel, FString NewTopic);
	void IsAway(FString Nick, FString Message);
	void IRCVisible();
	void IRCClosed();
	void NotifyAfterLevelChange();
	bool InGame();
	void UpdateAway();
	void CheckAway();
	void CTCP(FString Channel, FString Nick, FString Message);
};
