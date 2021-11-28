// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_Page.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/BufferedTCPLink/AAIRCLink/AAIRCLink.h"
#include "AAIRC_System.generated.h"

class UAAIRC_Channel;
//class AAAIRCLink;
class UAABrowser_IRC;
class UAAIRC_Panel;
class UAAIRC_Private;

UCLASS()
class AA29_API UAAIRC_System : public UAAIRC_Page
{
	GENERATED_BODY()
public:
	UAAIRC_System();

	UPROPERTY()								TArray<UAAIRC_Channel*>		Channels;					//var TArray<AAIRC_Channel> Channels;
	UPROPERTY()								FString						LinkClassName;				//var FString LinkClassName;
	UPROPERTY()								AAAIRCLink*					link;						//var AAIRCLink link;
	UPROPERTY()								UAABrowser_IRC*				tp_Main;					//var AABrowser_IRC tp_Main;
	UPROPERTY()								UAAIRC_Panel*				p_IRC;						//var AAIRC_Panel p_IRC;
	UPROPERTY()								FString						TestIRCString;				//var FString TestIRCString;
	UPROPERTY()								FString						LastServer;					//var FString LastServer;
	UPROPERTY()								int32						CurChannel;					//var int32 CurChannel;
	UPROPERTY()								int32						PrevChannel;				//var int32 PrevChannel;
	UPROPERTY()								bool						bConnected;					//var bool bConnected;
	UPROPERTY()								bool						bAway;						//var bool bAway;
	UPROPERTY()								bool						bSysInitialized;			//var bool bSysInitialized;
	UPROPERTY(config)						FString						NewNickMenu;				//var config FString NewNickMenu;
	UPROPERTY(config)						FString						OldPlayerName;				//var() globalconfig FString OldPlayerName;
	UPROPERTY(config)						FString						NickName;					//var() globalconfig FString NickName;
	UPROPERTY(config)						FString						FullName;					//var() globalconfig FString FullName;
	UPROPERTY(config)						FString						UserIdent;					//var() globalconfig FString UserIdent;
	UPROPERTY(config)						FString						DefaultChannel;				//var() globalconfig FString DefaultChannel;
	UPROPERTY(config)						FString						ChanKeyMenu;				//var config FString ChanKeyMenu;
	UPROPERTY(config)						FString						NotInAChannelText;			//var localized FString NotInAChannelText;
	UPROPERTY(config)						FString						KickedFromText;				//var localized FString KickedFromText;
	UPROPERTY(config)						FString						ByText;						//var localized FString ByText;
	UPROPERTY(config)						FString						IsAwayText;					//var localized FString IsAwayText;
	UPROPERTY(config)						FString						ChooseNewNickText;			//var localized FString ChooseNewNickText;
	UPROPERTY(config)						FString						NickInUseText;				//var localized FString NickInUseText;
	UPROPERTY(config)						FString						NickInvalidText;			//var localized FString NickInvalidText;
	UPROPERTY(config)						FString						LeavePrivateText;			//var localized FString LeavePrivateText;
	UPROPERTY(config)						FString						CloseWindowCaption;			//var localized FString CloseWindowCaption;
	UPROPERTY(config)						FString						DisconnectCaption;			//var localized FString DisconnectCaption;
	UPROPERTY(config)						FString						ChangeNickCaption;			//var localized FString ChangeNickCaption;
	UPROPERTY(config)						FString						InvalidModeText;			//var localized FString InvalidModeText;
	UPROPERTY(config)						FString						InvalidKickText;			//var localized FString InvalidKickText;


	void OnConnect();
	void OnDisconnect();
	void NewChannelSelected(int32 CurrentChannel);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool CanShowPanel();
	void ShowPanel(bool bShow);
	void Timer();
	bool LeaveAvailable(FString& ButtonCaption);
	bool DisconnectAvailable(FString& ButtonCaption);
	bool SetNickAvailable(FString& ButtonCaption);
	bool InGame();
	bool InMenus();
	void UpdateIdent();
	bool IsMe(FString Test);
	bool IsConnected();
	bool IsAway();
	void NotifyQuitUnreal();
	void ChangeConnectStatus(bool NewStatus);
	void ChangeAwayStatus(bool NewStatus);
	void NewNickPageClosed(bool bCancelled);
	void ChanKeyPageClosed(bool bCancelled);
	bool Connect(FString NewServer);
	void Disconnect();
	void CloseLink(AAAIRCLink* OldLink, bool bSwitchingServers, FString Reason);
	void ProcessInput(FString Text);
	void JoinChannel(FString ChannelName);
	void PartCurrentChannel();
	void PartChannel(FString ChannelName);
	void ChangeCurrentNick();
	void Whois(FString Nick);
	void Op(FString Nick, FString ChannelName);
	void Deop(FString Nick, FString ChannelName);
	void Voice(FString Nick, FString ChannelName);
	void DeVoice(FString Nick, FString ChannelName);
	void Help(FString Nick, FString ChannelName);
	void DeHelp(FString Nick, FString ChannelName);
	void Kick(FString Nick, FString ChannelName, FString Reason);
	void Ban(FString Nick, FString ChannelName, FString Reason);
	void Unban(FString Nick, FString ChannelName);
	void SetMode(FString modes, FString Target, bool On, FString Extra);
	void SystemText(FString Text);
	void ChannelText(FString Channel, FString Nick, FString Text);
	void PrivateText(FString Nick, FString Text);
	void ChannelAction(FString Channel, FString Nick, FString Text);
	void PrivateAction(FString Nick, FString Text);
	void JoinedChannel(FString Channel, FString Nick);
	void PartedChannel(FString Channel, FString Nick);
	void KickUser(FString Channel, FString KickedNick, FString Kicker, FString Reason);
	void UserInChannel(FString Channel, FString Nick);
	void NotifyNickInUse();
	void NotifyInvalidNick();
	void NotifyChannelKey(FString chan);
	void ChangedNick(FString OldNick, FString NewNick);
	void UserQuit(FString Nick, FString Reason);
	void UserNotice(FString Nick, FString Text);
	void ChangeMode(FString Channel, FString Nick, FString Mode);
	void ChangeOwner(FString Channel, FString Nick, bool bOwner);
	void ChangeProtected(FString Channel, FString Nick, bool bProtected);
	void ChangeOp(FString Channel, FString Nick, bool bOp);
	void ChangeHalfOp(FString Channel, FString Nick, bool bHalfOp);
	void ChangeVoice(FString Channel, FString Nick, bool bVoice);
	void ChangeTopic(FString Channel, FString NewTopic);
	void CTCP(FString Channel, FString Nick, FString Message);
	UAAIRC_Page* GetCurrentChannel();
	FString GetCurrentChannelName();
	FString GetDefaultChannel();
	UAAIRC_Channel* FindChannelWindow(FString Channel, bool bIncludePrivate);
	UAAIRC_Private* FindPrivateWindow(FString Nick);
	int32 FindPublicChannelIndex(FString ChannelName, bool bIncludePrivate);
	int32 FindPrivateChannelIndex(FString ChannelName);
	void SetCurrentChannelPage(UAAIRC_Channel* ChannelPage);
	void SetCurrentChannel(int32 idx);
	void UpdateCurrentChannel(int32 NewCurrent);
	void UpdateAway();
	void PrintAwayMessage(FString Nick, FString Message);
	void IRCClosed();
	AAAIRCLink* CreateNewLink();
	UAAIRC_Channel* AddChannel(FString ChannelName, bool bPrivate, bool bActivate);
	bool RemoveChannelAt(int32 Index);
	void RemoveChannel(FString Channel);
	bool ValidChannelIndex(int32 Index);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	bool IsPunctuation(FString Text);
	FString StripEndPunctuation(FString Text);
	bool IRCTextDblClick(UGUIComponent* Sender);


};


