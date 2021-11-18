// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_Page.h"
#include "AAIRC_Channel.generated.h"

class UAAIRC_System;
class UGUIButton;
class UGUIListBox;

UCLASS()
class AA29_API UAAIRC_Channel : public UAAIRC_Page
{
	GENERATED_BODY()
public:
	UAAIRC_Channel();

	UPROPERTY()						UAAIRC_System*				tp_System;				//var AAIRC_System tp_System;
	UPROPERTY()						FString						ChannelName;			//var FString ChannelName;
	UPROPERTY()						FString						ChannelTopic;			//var FString ChannelTopic;
	UPROPERTY()						FString						DefaultListClass;		//var FString DefaultListClass;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_Disconnect;			//var() automated XInterface.GUIButton b_Disconnect;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_Leave;				//var() automated XInterface.GUIButton b_Leave;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_NewNick;				//var() automated XInterface.GUIButton b_NewNick;
	UPROPERTY()						FString						OpUserText;				//var localized FString OpUserText;
	UPROPERTY()						FString						HelpUserText;			//var localized FString HelpUserText;
	UPROPERTY()						FString						VoiceUserText;			//var localized FString VoiceUserText;
	UPROPERTY()						FString						ReasonText;				//var localized FString ReasonText;
	UPROPERTY()						FString						MessageUserText;		//var localized FString MessageUserText;
	UPROPERTY()						FString						WhoisUserText;			//var localized FString WhoisUserText;
	UPROPERTY()						FString						DeopUserText;			//var localized FString DeopUserText;
	UPROPERTY()						FString						DehelpUserText;			//var localized FString DehelpUserText;
	UPROPERTY()						FString						DevoiceUserText;		//var localized FString DevoiceUserText;
	UPROPERTY()						FString						KickUserText;			//var localized FString KickUserText;
	UPROPERTY()						bool						IsPrivate;				//var bool IsPrivate;
	UPROPERTY()						UGUIListBox*				lb_User;				//var XInterface.GUIListBox lb_User;

	void ProcessInput(FString Text);
	void Whois(FString Nick);
	void Op(FString Nick);
	void Deop(FString Nick);
	void Voice(FString Nick);
	void DeVoice(FString Nick);
	void Help(FString Nick);
	void DeHelp(FString Nick);
	void Kick(FString Nick, FString Reason);
	void Ban(FString Nick, FString Reason);
	void Unban(FString Nick);
	void UserInChannel(FString Nick);
	void AddUser(FString Nick);
	void RemoveUser(FString Nick);
	void ChangeOwner(FString Nick, bool NewOwner);
	void ChangeProtected(FString Nick, bool NewProtected);
	void ChangeOp(FString Nick, bool NewOp);
	void ChangeHalfOp(FString Nick, bool NewHalfOp);
	void ChangeVoice(FString Nick, bool NewVoice);
	void ChangedNick(FString OldNick, FString NewNick);
	void ChangeTopic(FString NewTopic);
	void ChannelText(FString Nick, FString Text);
	void ChannelAction(FString Nick, FString Text);
	void UserNotice(FString Nick, FString Text);
	void JoinedChannel(FString Nick);
	void PartedChannel(FString Nick);
	void KickUser(FString KickedNick, FString Kicker, FString Reason);
	void UserQuit(FString Nick, FString Reason);
	void ChangeMode(FString Nick, FString Mode);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InternalOnReleaseSplitter(UGUIComponent* Sender, float NewPos);
	bool MyListDblClick(UGUIComponent* Sender);
	int32 MyCompareItem(FGUIListElem ElemA, FGUIListElem ElemB);
	void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);;
	int32 GetUser(FString Nick);
	FString GetFlags(FString NickName);
	bool FindNick(FString Nick);
	bool UserIsOp(FString NickName);
	bool UserIsHelper(FString NickName);
	bool UserIsVoice(FString NickName);
	void ChangeNick(FString OldNick, FString NewNick);
	void UserSetFlag(int32 i, FString flag, bool bSet);
	bool ContextMenuOpen(UGUIContextMenu* Sender);
	void AddUserContextOptions(UGUIContextMenu* Menu, FString Nick);
	void AddControlContextOptions(UGUIContextMenu* Menu, FString Nick);
	void ContextMenuClick(UGUIContextMenu* Sender, int32 ClickIndex);
	int32 GetAbsoluteIndex(UGUIContextMenu* Menu, int32 Index);
	void KickReasonClose(bool bCancelled);
	bool InternalOnClick(UGUIComponent* Sender);
	void DisconnectClicked();
	void LeaveClicked();
	void NewNickClicked();
	bool IsPunctuation(FString Text);
	FString StripEndPunctuation(FString Text);
	bool IRCTextDblClick(UGUIComponent* Sender);
};
