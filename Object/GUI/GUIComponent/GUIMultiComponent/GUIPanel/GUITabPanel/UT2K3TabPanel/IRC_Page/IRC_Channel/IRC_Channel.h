// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_Page.h"
#include "IRC_Channel.generated.h"

class UIRC_System;
class UGUIListBox;

UCLASS()
class AA29_API UIRC_Channel : public UIRC_Page
{
	GENERATED_BODY()
public:
	UIRC_Channel();

	UPROPERTY()			FString				ChannelName;					//var FString ChannelName;
	UPROPERTY()			UIRC_System*		SystemPage;						//var IRC_System SystemPage;
	UPROPERTY()			FString				ChannelTopic;					//var FString ChannelTopic;
	UPROPERTY()			bool				IsPrivate;						//var bool IsPrivate;
	UPROPERTY()			UGUIListBox*		UserListBox;					//var GUIListBox UserListBox;
	UPROPERTY()			bool				bUsersNeedSorting;				//var bool bUsersNeedSorting;

	void UserSetFlag(int32 i, FString flag, bool bSet);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool MyOnPreDraw(UCanvas* C);
	bool MyListDblClick(UGUIComponent* Sender);
	int32 MyCompareItem(FGUIListElem ElemA, FGUIListElem ElemB);
	void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	int32 GetUser(FString Nick);
	bool FindNick(FString Nick);
	void AddUser(FString Nick);
	void RemoveUser(FString Nick);
	void ChangeNick(FString OldNick, FString NewNick);
	void ChangeOp(FString Nick, bool NewOp);
	void ChangeHalfOp(FString Nick, bool NewHalfOp);
	void ChangeVoice(FString Nick, bool NewVoice);
	void ChangeTopic(FString NewTopic);
	void ChannelText(FString Nick, FString Text);
	void ChannelAction(FString Nick, FString Text);
	void UserNotice(FString Nick, FString Text);
	void ProcessInput(FString Text);
	void PartedChannel(FString Nick);
	void JoinedChannel(FString Nick);
	void KickUser(FString KickedNick, FString Kicker, FString Reason);
	void UserInChannel(FString Nick);
	void ChangedNick(FString OldNick, FString NewNick);
	void UserQuit(FString Nick, FString Reason);
	void ChangeMode(FString Nick, FString Mode);
};
