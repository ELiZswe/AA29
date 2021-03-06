// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_System/AAIRC_System.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/BufferedTCPLink/AAIRCLink/AAIRCLink.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_IRC/AABrowser_IRC.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_Channel/AAIRC_Channel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_Page.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanel/AAIRC_Panel/AAIRC_Panel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_Channel/AAIRC_Private/AAIRC_Private.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAIRC_ChanKey/AAIRC_ChanKey.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAIRC_NewNick/AAIRC_NewNick.h"

UAAIRC_System::UAAIRC_System()
{
	UGUISplitter* SplitterA = NewObject<UGUISplitter>(UGUISplitter::StaticClass());
	SplitterA->SplitPosition = 0.8;
	SplitterA->bFixedSplitter = true;
	SplitterA->DefaultPanels = {
		"XInterface.GUIScrollTextBox",
		"AGP_Interface.AAIRC_Panel"
	};
	//SplitterA->OnCreateComponent=AAIRC_System.InternalOnCreateComponent;
	SplitterA->WinHeight = 0.91;
	SplitterA->TabOrder = 1;

	//LinkClassName = "AGP_Interface.AAIRCLink";
	CurChannel = -2;
	PrevChannel = -1;
	//NewNickMenu = "AGP_Interface.AAIRC_NewNick";
	//ChanKeyMenu = "AGP_Interface.AAIRC_ChanKey";
	NotInAChannelText = "Not in a channel!";
	KickedFromText = "You were kicked from";
	ByText = "by";
	IsAwayText = "is away";
	ChooseNewNickText = "Choose A New IRC Nickname";
	NickInUseText = "Nickname Already In Use";
	NickInvalidText = "Nickname Is Invalid";
	LeavePrivateText = "CLOSE %ChanName% ";
	CloseWindowCaption = "LEAVE CHANNEL";
	DisconnectCaption = "DISCONNECT";
	ChangeNickCaption = "CHANGE NICK";
	InvalidModeText = "Invalid parameters for MODE - Syntax: /MODE [#]target [[+|-]modes [Extra Params]]";
	InvalidKickText = "Invalid parameters for %Cmd% - Syntax: /%Cmd% #ChannelName Nick :[Reason]";
	sp_Main = SplitterA;
	MainSplitterPosition = 0.5;

}

void UAAIRC_System::OnConnect()
{
}

void UAAIRC_System::OnDisconnect()
{
}

void UAAIRC_System::NewChannelSelected(int32 CurrentChannel)
{
}

void UAAIRC_System::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	UGUIComponent* C = nullptr;
	Super::InitComponent(MyController, MyOwner);
	/*
	sp_Main.bDrawSplitter = false;
	p_IRC.UpdateConnectionStatus(IsConnected());
	C = MenuOwner;
	if (C != nullptr)
	{
		if (Cast<UAABrowser_IRC>(C) != nullptr)
		{
			tp_Main = AABrowser_IRC(C);
		}
		else
		{
			C = C.MenuOwner;
		}
	}
	Assert((tp_Main != nullptr));
	*/
}

bool UAAIRC_System::CanShowPanel()
{
	return Controller->bCurMenuInitialized;
}

void UAAIRC_System::ShowPanel(bool bShow)
{
	Super::ShowPanel(bShow);
	if (bShow)
	{
		if (bInit)
		{
			sp_Main->SplitterUpdatePositions();
		}
		bInit = false;
	}
}

void UAAIRC_System::Timer()
{
	/*
	if ((bConnected && (Cast<AHumanController>(PlayerOwner()) != nullptr)) && (Repl("AA|" + Cast<AHumanController>(PlayerOwner())->UserName, " ", "") != OldPlayerName))
	{
		OldPlayerName = "AA|" + Cast<AHumanController>(PlayerOwner())->UserName;
		ReplaceText(OldPlayerName, " ", "");
		link.SetNick(OldPlayerName);
		SystemText("SetNick: " + OldPlayerName);
	}
	*/
}

bool UAAIRC_System::LeaveAvailable(FString& ButtonCaption)
{
	/*
	if (!ValidChannelIndex(CurChannel))
	{
		ButtonCaption = CloseWindowCaption;
		return false;
	}
	else
	{
		if (Channels[CurChannel].IsPrivate)
		{
			ButtonCaption = Repl(LeavePrivateText, "%ChanName%", GetCurrentChannelName());
			return true;
		}
		else
		{
			ButtonCaption = CloseWindowCaption;
			return true;
		}
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool UAAIRC_System::DisconnectAvailable(FString& ButtonCaption)
{
	//ButtonCaption = DisconnectCaption;
	return IsConnected();
}

bool UAAIRC_System::SetNickAvailable(FString& ButtonCaption)
{
	//ButtonCaption = ChangeNickCaption;
	return true;
}

bool UAAIRC_System::InGame()
{
	//return (!Controller.bActive);
	return false;   //FAKE   /ELiZ
}

bool UAAIRC_System::InMenus()
{
	/*
	if (InGame())
	{
		return false;
	}
	*/
	return true;
}

void UAAIRC_System::UpdateIdent()
{
	/*
	int32 i = 0;
	if (UserIdent == "")
	{
		UserIdent = "u";
		for (i = 0; i < 7; i++)
		{
			UserIdent += Chr((Rand(10) + 48));
		}
		Log("Created new UserIdent: " + UserIdent, 'IRC');
		SaveConfig();
	}
	*/
}

bool UAAIRC_System::IsMe(FString Test)
{
	//return (Test ~= NickName);
	return false;   //FAKE   /ELiZ
}

bool UAAIRC_System::IsConnected()
{
	//return (bConnected && (link != nullptr));
	return false;   //FAKE   /ELiZ
}

bool UAAIRC_System::IsAway()
{
	return bAway;
}

void UAAIRC_System::NotifyQuitUnreal()
{
	//CloseLink(link, false, "Exit Game");
}

void UAAIRC_System::ChangeConnectStatus(bool NewStatus)
{
	/*
	bConnected = NewStatus;
	p_IRC.UpdateConnectionStatus(bConnected);
	*/
}

void UAAIRC_System::ChangeAwayStatus(bool NewStatus)
{
	FString URL = "";
	bAway = NewStatus;
	/*
	if ((PlayerOwner() == nullptr) || (PlayerOwner().Level == nullptr))
	{
		return;
	}
	if (IsConnected())
	{
		if (IsAway())
		{
			URL = PlayerOwner().Level.GetAddressURL();
			if (InStr(URL, ":") > 0)
			{
				if ((AwayMode != 1) || (LastServer != URL))
				{
					LastServer = URL;
					link.SetAway(PlayerOwner().GetURLProtocol() + "://" + URL);
					AwayMode = 1;
				}
			}
			else
			{
				if (InGame())
				{
					if (AwayMode != 2)
					{
						AwayMode = 2;
						link.SetAway("local game");
					}
				}
				else
				{
					if (AwayMode != 3)
					{
						link.SetAway("in menus");
						AwayMode = 3;
					}
				}
			}
		}
		else
		{
			if (AwayMode != 0)
			{
				link.SetAway("");
				AwayMode = 0;
			}
		}
	}
	*/
}

void UAAIRC_System::NewNickPageClosed(bool bCancelled)
{
	FString NewNick = "";
	if (!bCancelled)
	{
		NewNick = Controller->ActivePage->GetDataString();
		if (NewNick != "")
		{
			if (link != nullptr)
			{
				link->SetNick(NewNick);
			}
			else
			{
				ChangedNick(NickName, NewNick);
			}
		}
	}
}

void UAAIRC_System::ChanKeyPageClosed(bool bCancelled)
{
	FString JoinReq = "";
	if (!bCancelled)
	{
		JoinReq = Controller->ActivePage->GetDataString();
		if (JoinReq != "")
		{
			if (link != nullptr)
			{
				link->JoinChannel(JoinReq);
			}
		}
	}
}

bool UAAIRC_System::Connect(FString NewServer)
{
	APlayerController* PC = nullptr;
	AAAIRCLink* NewLink = nullptr;
	AHumanController* HC = nullptr;
	PC = PlayerOwner();
	HC = Cast<AHumanController>(PC);
	if (NewServer == "")
	{
		return false;
	}
	NewLink = CreateNewLink();
	if (NewLink == nullptr)
	{
		return false;
	}
	/*
	if (HC != nullptr)
	{
		NickName = "AA|" + HC.UserName;
		ReplaceText(NickName, " ", "");
		OldPlayerName = NickName;
		if (FullName != NickName)
		{
			FullName = NickName;
		}
		SaveConfig();
	}
	else
	{
		NickName = PC.GetUrlOption("Name");
		ReplaceText(NickName, " ", "");
		OldPlayerName = NickName;
		if (FullName == "")
		{
			FullName = NickName;
		}
		SaveConfig();
	}
	UpdateIdent();
	NewLink.Connect(this, NewServer, NickName, UserIdent, FullName, GetDefaultChannel());
	ChangeConnectStatus(true);
	SetTimer(1, true);
	*/
	return true;
}

void UAAIRC_System::Disconnect()
{
	CloseLink(link, false,"");
}

void UAAIRC_System::CloseLink(AAAIRCLink* OldLink, bool bSwitchingServers, FString Reason)
{
	FString ServerName = "";
	ServerName = OldLink->ServerAddress;
	if (Reason == "")
	{
		Reason = "Disconnected";
	}
	if (link != nullptr)
	{
		if (link != OldLink)
		{
			OldLink->DestroyLink();
			return;
		}
		link->DisconnectReason = Reason;
		link->DestroyLink();
	}
	link = nullptr;
	//Channels.RemoveAt(0, Channels.Num());
	OnDisconnect();
	SystemText("Disconnected from server" + ServerName);
	ChangeConnectStatus(bSwitchingServers);
	SetCurrentChannel(-1);
	KillTimer();
}

void UAAIRC_System::ProcessInput(FString Text)
{
	int32 i = 0;
	/*
	if (CurChannel > -1)
	{
		Channels[CurChannel].ProcessInput(Text);
	}
	else
	{
		if (Left(Text, 1) != "/")
		{
			SystemText("*** " + NotInAChannelText);
		}
		else
		{
			Text = Mid(Text, 1);
			if ((Left(Text, 7) ~= "connect") || (Left(Text, 6) ~= "server"))
			{
				i = InStr(Text, " ");
				if (i != -1)
				{
					Connect(Mid(Text, (i + 1)));
				}
			}
			else
			{
				if (Left(Text, 4) ~= "echo")
				{
					i = InStr(Text, " ");
					if (i != -1)
					{
						SystemText(Mid(Text, (i + 1)));
					}
				}
				else
				{
					if (link != nullptr)
					{
						link.SendCommandText(Text);
					}
				}
			}
		}
	}
	*/
}

void UAAIRC_System::JoinChannel(FString ChannelName)
{
	UAAIRC_Channel* p = nullptr;
	p = FindChannelWindow(ChannelName, false);
	if (p == nullptr)
	{
		link->JoinChannel(ChannelName);
	}
	else
	{
		SetCurrentChannel(FindPublicChannelIndex(ChannelName,false));
	}
}

void UAAIRC_System::PartCurrentChannel()
{
	if (!ValidChannelIndex(CurChannel))
	{
		return;
	}
	PartChannel(Channels[CurChannel]->ChannelName);
}

void UAAIRC_System::PartChannel(FString ChannelName)
{
	UAAIRC_Channel* p;
	p = FindChannelWindow(ChannelName, true);
	if (p != nullptr)
	{
		if (p->IsPrivate)
		{
			RemoveChannel(ChannelName);
		}
		else
		{
			link->PartChannel(ChannelName);
		}
	}
}

void UAAIRC_System::ChangeCurrentNick()
{
	if (Controller->OpenMenu(NewNickMenu, ChooseNewNickText, NickName))
	{
		//Controller->ActivePage.__OnClose__Delegate = NewNickPageClosed;
	}
}

void UAAIRC_System::Whois(FString Nick)
{
	if (link == nullptr)
	{
		return;
	}
	link->SendCommandText("WHOIS" + Nick);
}

void UAAIRC_System::Op(FString Nick, FString ChannelName)
{
	if (link == nullptr)
	{
		return;
	}
	//SetMode("o", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" + ChannelName), true, Nick);
}

void UAAIRC_System::Deop(FString Nick, FString ChannelName)
{
	if (link == nullptr)
	{
		return;
	}
	//SetMode("o", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" + ChannelName), false, Nick);
}

void UAAIRC_System::Voice(FString Nick, FString ChannelName)
{
	if (link == nullptr)
	{
		return;
	}
	//SetMode("v", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" + ChannelName), true, Nick);
}

void UAAIRC_System::DeVoice(FString Nick, FString ChannelName)
{
	if (link == nullptr)
	{
		return;
	}
	//SetMode("v", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" + ChannelName), false, Nick);
}

void UAAIRC_System::Help(FString Nick, FString ChannelName)
{
	if (link == nullptr)
	{
		return;
	}
	//SetMode("h", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" + ChannelName), true, Nick);
}

void UAAIRC_System::DeHelp(FString Nick, FString ChannelName)
{
	if (link == nullptr)
	{
		return;
	}
	//SetMode("h", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" + ChannelName), false, Nick);
}

void UAAIRC_System::Kick(FString Nick, FString ChannelName, FString Reason)
{
	/*
	if (link == nullptr)
	{
		SystemText(NotInAChannelText);
		return;
	}
	if ((Nick == "") || (ChannelName == ""))
	{
		SystemText(Repl(InvalidKickText, "%Cmd%", "KICK"));
		return;
	}
	link.SendCommandText("KICK" @ Nick + Eval((Reason != ""), " :" + Reason, ""));
	*/
}

void UAAIRC_System::Ban(FString Nick, FString ChannelName, FString Reason)
{
	/*
	SetMode("b", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" + ChannelName), true, Nick);
	Kick(Nick, ChannelName, Reason);
	*/
}

void UAAIRC_System::Unban(FString Nick, FString ChannelName)
{
	/*
	SetMode("b", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" + ChannelName), false, Nick);
	*/
}

void UAAIRC_System::SetMode(FString modes, FString Target, bool On, FString Extra)
{
	/*
	if (link == nullptr)
	{
		SystemText(NotInAChannelText);
		return;
	}
	if ((modes == "") || (Target == ""))
	{
		SystemText(InvalidModeText);
		return;
	}
	if (link != nullptr)
	{
		link.SendCommandText("MODE" @ Target @ Eval(On, "+", "-") + modes + Eval((Extra != ""), " " + Extra, ""));
	}
	*/
}

void UAAIRC_System::SystemText(FString Text)
{
	/*
	if ((Text != "You have been marked as being away") && (Text != "You are no longer marked as being away"))
	{
		InterpretColorCodes(Text);
		lb_TextDisplay.AddText(MakeColorCode(IRCTextColor) + ColorizeLinks(Text));
		if (!MyButton.bActive)
		{
			MyButton.bForceFlash = true;
		}
	}
	*/
}

void UAAIRC_System::ChannelText(FString Channel, FString Nick, FString Text)
{
	UAAIRC_Channel* p = nullptr;
	p = FindChannelWindow(Channel,false);
	if (p != nullptr)
	{
		p->ChannelText(Nick, Text);
	}
}

void UAAIRC_System::PrivateText(FString Nick, FString Text)
{
	FindPrivateWindow(Nick)->PrivateText(Nick, Text);
}

void UAAIRC_System::ChannelAction(FString Channel, FString Nick, FString Text)
{
	UAAIRC_Channel* p = nullptr;
	p = FindChannelWindow(Channel,false);
	if (p != nullptr)
	{
		p->ChannelAction(Nick, Text);
	}
}

void UAAIRC_System::PrivateAction(FString Nick, FString Text)
{
	FindPrivateWindow(Nick)->PrivateAction(Nick, Text);
}

void UAAIRC_System::JoinedChannel(FString Channel, FString Nick)
{
	UAAIRC_Channel* NewCh = nullptr;
	UAAIRC_Channel* W = nullptr;
	/*
	Log(Nick @ "JoinedChannel " + Channel, 'IRC');
	if (Nick == "")
	{
		NewCh = AddChannel(Channel);
		if (NewCh != nullptr)
		{
			SetCurrentChannelPage(NewCh);
		}
	}
	if (Nick == "")
	{
		Nick = NickName;
	}
	W = FindChannelWindow(Channel);
	if (W != nullptr)
	{
		W.JoinedChannel(Nick);
	}
	*/
}

void UAAIRC_System::PartedChannel(FString Channel, FString Nick)
{
	UAAIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel,false);
	if (Nick == "")
	{
		RemoveChannel(Channel);
	}
	else
	{
		if (W != nullptr)
		{
			W->PartedChannel(Nick);
		}
	}
}

void UAAIRC_System::KickUser(FString Channel, FString KickedNick, FString Kicker, FString Reason)
{
	UAAIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel, false);
	if (KickedNick == NickName)
	{
		RemoveChannel(Channel);
		//SystemText("*** " + KickedFromText @ Channel @ ByText @ Kicker + " (" + Reason + ")");
	}
	else
	{
		if (W != nullptr)
		{
			W->KickUser(KickedNick, Kicker, Reason);
		}
	}
}

void UAAIRC_System::UserInChannel(FString Channel, FString Nick)
{
	UAAIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel,false);
	if (W != nullptr)
	{
		W->UserInChannel(Nick);
	}
}

void UAAIRC_System::NotifyNickInUse()
{
	if (Cast<UAAIRC_NewNick>(Controller->ActivePage) == nullptr)
	{
		if (Controller->OpenMenu(NewNickMenu, NickInUseText, NickName))
		{
			//Controller.ActivePage.__OnClose__Delegate = NewNickPageClosed;
		}
	}
}

void UAAIRC_System::NotifyInvalidNick()
{
	if (Cast<UAAIRC_NewNick>(Controller->ActivePage) == nullptr)
	{
		if (Controller->OpenMenu(NewNickMenu, NickInvalidText, NickName))
		{
			//Controller.ActivePage.__OnClose__Delegate = NewNickPageClosed;
		}
	}
}

void UAAIRC_System::NotifyChannelKey(FString chan)
{
	if (Cast<UAAIRC_ChanKey>(Controller->ActivePage) == nullptr)
	{
		if (Controller->OpenMenu(ChanKeyMenu, chan,""))
		{
			//Controller->ActivePage.__OnClose__Delegate = ChanKeyPageClosed;
		}
	}
}

void UAAIRC_System::ChangedNick(FString OldNick, FString NewNick)
{
	int32 i = 0;
	if (OldNick == NickName)
	{
		NickName = NewNick;
		if (link != nullptr)
		{
			link->NickName = NewNick;
		}
		SaveConfig();
	}
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i]->FindNick(OldNick))
		{
			Channels[i]->ChangedNick(OldNick, NewNick);
		}
	}
	/*
	if (GetCurrentChannelName() ~= NewNick)
	{
		tp_Main.SetCloseCaption(NewNick);
	}
	*/
}

void UAAIRC_System::UserQuit(FString Nick, FString Reason)
{
	int32 i = 0;
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i]->FindNick(Nick))
		{
			Channels[i]->UserQuit(Nick, Reason);
		}
	}
}

void UAAIRC_System::UserNotice(FString Nick, FString Text)
{
	int32 i = 0;
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i]->FindNick(Nick))
		{
			Channels[i]->UserNotice(Nick, Text);
		}
	}
}

void UAAIRC_System::ChangeMode(FString Channel, FString Nick, FString Mode)
{
	UAAIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel,false);
	if (W != nullptr)
	{
		W->ChangeMode(Nick, Mode);
	}
}

void UAAIRC_System::ChangeOwner(FString Channel, FString Nick, bool bOwner)
{
	UAAIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel,false);
	if (W != nullptr)
	{
		W->ChangeOwner(Nick, bOwner);
	}
}

void UAAIRC_System::ChangeProtected(FString Channel, FString Nick, bool bProtected)
{
	UAAIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel, false);
	if (W != nullptr)
	{
		W->ChangeProtected(Nick, bProtected);
	}
}

void UAAIRC_System::ChangeOp(FString Channel, FString Nick, bool bOp)
{
	UAAIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel,false);
	if (W != nullptr)
	{
		W->ChangeOp(Nick, bOp);
	}
}

void UAAIRC_System::ChangeHalfOp(FString Channel, FString Nick, bool bHalfOp)
{
	UAAIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel,false);
	if (W != nullptr)
	{
		W->ChangeHalfOp(Nick, bHalfOp);
	}
}

void UAAIRC_System::ChangeVoice(FString Channel, FString Nick, bool bVoice)
{
	UAAIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel,false);
	if (W != nullptr)
	{
		W->ChangeVoice(Nick, bVoice);
	}
}

void UAAIRC_System::ChangeTopic(FString Channel, FString NewTopic)
{
	UAAIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel,false);
	if (W != nullptr)
	{
		//Log("Topic (Channel: " + Channel + ") : " + NewTopic, 'IRC');
		W->ChangeTopic(NewTopic);
	}
}

void UAAIRC_System::CTCP(FString Channel, FString Nick, FString Message)
{
	/*
	if ((Channel == "") || (Channel == NickName))
	{
		SystemText("[" + Nick + ": " + Message + "]");
	}
	else
	{
		SystemText("[" + Nick + ":" + Channel + " " + Message + "]");
	}
	*/
}

UAAIRC_Page* UAAIRC_System::GetCurrentChannel()
{
	if (CurChannel != -1)
	{
		return Channels[CurChannel];
	}
	return this;
}

FString UAAIRC_System::GetCurrentChannelName()
{
	if (CurChannel != -1)
	{
		return Channels[CurChannel]->ChannelName;
	}
	return "";
}

FString UAAIRC_System::GetDefaultChannel()
{
	return DefaultChannel;
}

UAAIRC_Channel* UAAIRC_System::FindChannelWindow(FString Channel, bool bIncludePrivate)
{
	int32 i = 0;
	i = FindPublicChannelIndex(Channel, bIncludePrivate);
	if (i != -1)
	{
		return Channels[i];
	}
	return nullptr;
}

UAAIRC_Private* UAAIRC_System::FindPrivateWindow(FString Nick)
{
	int32 i = 0;
	i = FindPrivateChannelIndex(Nick);
	if (i != -1)
	{
		return Cast<UAAIRC_Private>(Channels[i]);
	}
	return Cast<UAAIRC_Private>(AddChannel(Nick, true,false));
}

int32 UAAIRC_System::FindPublicChannelIndex(FString ChannelName, bool bIncludePrivate)
{
	int32 i = 0;
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i]->ChannelName.Compare(ChannelName,ESearchCase::IgnoreCase))
		{
			if ((!Channels[i]->IsPrivate) || bIncludePrivate)
			{
				return i;
			}
		}
	}
	return -1;
}

int32 UAAIRC_System::FindPrivateChannelIndex(FString ChannelName)
{
	int32 i = 0;
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i]->IsPrivate && (Channels[i]->ChannelName.Compare(ChannelName,ESearchCase::IgnoreCase)))
		{
			return i;
		}
	}
	return -1;
}

void UAAIRC_System::SetCurrentChannelPage(UAAIRC_Channel* ChannelPage)
{
	int32 i = 0;
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i] == ChannelPage)
		{
			SetCurrentChannel(i);
			return;
		}
	}
}

void UAAIRC_System::SetCurrentChannel(int32 idx)
{
	/*
	if (idx == CurChannel)
	{
		return;
	}
	idx = Clamp(idx, -1, (Channels.Num() - 1));
	NewChannelSelected(idx);
	*/
}

void UAAIRC_System::UpdateCurrentChannel(int32 NewCurrent)
{
	/*
	PrevChannel = CurChannel;
	CurChannel = NewCurrent;
	if ((!ValidChannelIndex(CurChannel)) || (!Channels[CurChannel].IsPrivate))
	{
		tp_Main.SetCloseCaption();
	}
	else
	{
		tp_Main.SetCloseCaption(GetCurrentChannelName());
	}
	*/
}

void UAAIRC_System::UpdateAway()
{
	/*
	if (IsConnected())
	{
		if (InGame() || InMenus())
		{
			ChangeAwayStatus(true);
		}
		else
		{
			if (IsAway())
			{
				ChangeAwayStatus(false);
			}
		}
	}
	*/
}

void UAAIRC_System::PrintAwayMessage(FString Nick, FString Message)
{
	UAAIRC_Private* W = nullptr;
	W = FindPrivateWindow(Nick);
	if (W != nullptr)
	{
		W->PrintAwayMessage(Nick, Message);
	}
	else
	{
		SystemText(Nick + IsAwayText + ": " + Message);
	}
}

void UAAIRC_System::IRCClosed()
{
	UpdateAway();
}

AAAIRCLink* UAAIRC_System::CreateNewLink()
{
	AAAIRCLink* NewLink = nullptr;
	AAAIRCLink* NewLinkClass = nullptr;
	if (PlayerOwner() == nullptr)
	{
		return nullptr;
	}
	if (LinkClassName != "")
	{
		//NewLinkClass = class<AAIRCLink>(DynamicLoadObject(LinkClassName, Class'Class'));
	}
	if (NewLinkClass != nullptr)
	{
		//NewLink = PlayerOwner().Spawn(NewLinkClass);
	}
	return NewLink;
}

UAAIRC_Channel* UAAIRC_System::AddChannel(FString ChannelName, bool bPrivate, bool bActivate)
{
	UAAIRC_Channel* NewCh = nullptr;
	/*
	NewCh = tp_Main.AddChannel(ChannelName, bPrivate);
	if (NewCh != nullptr)
	{
		NewCh.tp_System = this;
		NewCh.IsPrivate = bPrivate;
		NewCh.ChannelName = ChannelName;
		Channels[Channels.Num()] = NewCh;
		if (bActivate)
		{
			SetCurrentChannel((Channels.Num() - 1));
		}
	}
	*/
	return NewCh;
}

bool UAAIRC_System::RemoveChannelAt(int32 Index)
{
	/*
	if (!ValidChannelIndex(Index))
	{
		return false;
	}
	tp_Main.RemoveChannel(Channels[Index].ChannelName);
	Channels.RemoveAt(Index, 1);
	*/
	return true;
}

void UAAIRC_System::RemoveChannel(FString Channel)
{
	/*
	int32 i = 0;
	i = FindPublicChannelIndex(Channel, true);
	if (i != -1)
	{
		RemoveChannelAt(i);
	}
	*/
}

bool UAAIRC_System::ValidChannelIndex(int32 Index)
{
	/*
	if ((Index < 0) || (Index >= Channels.Num()))
	{
		return false;
	}
	*/
	return true;
}

void UAAIRC_System::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (Cast<UAAIRC_Panel>(NewComp) != nullptr)
	{
		p_IRC = AAIRC_Panel(NewComp);
	}
	Super:InternalOnCreateComponent(NewComp, Sender);
	*/
}

bool UAAIRC_System::IsPunctuation(FString Text)
{
	/*
	switch (Left(Text, 1))
	{
	case ",":
	case ".":
	case "?":
	case "!":
	case ":":
	case ";":
		return true;
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

FString UAAIRC_System::StripEndPunctuation(FString Text)
{
	FString Out = "";
	Out = Text;
	/*
	if (IsPunctuation(Right(Out, 1)))
	{
		Out = Mid(Out, 0, (Len(Out) - 1));
	}
	*/
	return Out;
}

bool UAAIRC_System::IRCTextDblClick(UGUIComponent* Sender)
{
	FString ClickString = "";
	FString ChanName = "";
	Super::IRCTextDblClick(Sender);
	/*
	ClickString = StripColorCodes(lb_TextDisplay.MyScrollText.ClickedString);
	if (Left(ClickString, 1) == "#")
	{
		ChanName = StripEndPunctuation(ClickString);
		if (((InStr(Mid(ChanName, 1), "#") == -1) && (InStr(Mid(ChanName, 1), ",") == -1)) && (InStr(Mid(ChanName, 1), Chr(7)) == -1))
		{
			JoinChannel(ChanName);
		}
	}
	*/
	return true;
}

