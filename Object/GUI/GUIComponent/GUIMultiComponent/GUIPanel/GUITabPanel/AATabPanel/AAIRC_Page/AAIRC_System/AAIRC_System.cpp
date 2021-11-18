// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_System/AAIRC_System.h"

UAAIRC_System::UAAIRC_System()
{
	/*
	Begin Object Class=GUISplitter Name=SplitterA
		SplitPosition=0.8
		bFixedSplitter=True
		DefaultPanels="XInterface.GUIScrollTextBox"
		DefaultPanels="AGP_Interface.AAIRC_Panel"
		OnCreateComponent=AAIRC_System.InternalOnCreateComponent
		WinHeight=0.91
		TabOrder=1
	End Object
	*/
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
	//sp_Main = GUISplitter'AGP_Interface.AAIRC_System.SplitterA';
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
	/*
		local UGUIComponent* C;
	Super:InitComponent(MyController, MyOwner);
	sp_Main.bDrawSplitter = false;
	p_IRC.UpdateConnectionStatus(IsConnected());
	C = MenuOwner;
	if (C != None)
	{
		if (AABrowser_IRC(C) != None)
		{
			tp_Main = AABrowser_IRC(C);
		}
		else
		{
			C = C.MenuOwner;
		}
	}
	Assert((tp_Main != None));
	*/
}

bool UAAIRC_System::CanShowPanel()
{
	//return Controller.bCurMenuInitialized;
	return false;   //FAKE   /ELiZ
}

void UAAIRC_System::ShowPanel(bool bShow)
{
	/*
	Super:ShowPanel(bShow);
	if (bShow)
	{
		if (bInit)
		{
			sp_Main.SplitterUpdatePositions();
		}
		bInit = false;
	}
	*/
}

void UAAIRC_System::Timer()
{
	/*
	if ((bConnected && (HumanController(PlayerOwner()) != None)) && (Repl("AA|" $ HumanController(PlayerOwner()).UserName, " ", "") != OldPlayerName))
	{
		OldPlayerName = "AA|" $ HumanController(PlayerOwner()).UserName;
		ReplaceText(OldPlayerName, " ", "");
		link.SetNick(OldPlayerName);
		SystemText("SetNick: " $ OldPlayerName);
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
	local int32 i;
	if (UserIdent == "")
	{
		UserIdent = "u";
		for (i = 0; i < 7; i++)
		{
			UserIdent $ = Chr((Rand(10) + 48));
		}
		Log("Created new UserIdent: " $ UserIdent, 'IRC');
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
	//return (bConnected && (link != None));
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
	/*
	local FString URL;
	bAway = NewStatus;
	if ((PlayerOwner() == None) || (PlayerOwner().Level == None))
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
					link.SetAway(PlayerOwner().GetURLProtocol() $ "://" $ URL);
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
	/*
	local FString NewNick;
	if (!bCancelled)
	{
		NewNick = Controller.ActivePage.GetDataString();
		if (NewNick != "")
		{
			if (link != None)
			{
				link.SetNick(NewNick);
			}
			else
			{
				ChangedNick(NickName, NewNick);
			}
		}
	}
	*/
}

void UAAIRC_System::ChanKeyPageClosed(bool bCancelled)
{
	/*
	local FString JoinReq;
	if (!bCancelled)
	{
		JoinReq = Controller.ActivePage.GetDataString();
		if (JoinReq != "")
		{
			if (link != None)
			{
				link.JoinChannel(JoinReq);
			}
		}
	}
	*/
}

bool UAAIRC_System::Connect(FString NewServer)
{
	/*
	local PlayerController PC;
	local AAIRCLink NewLink;
	local HumanController HC;
	PC = PlayerOwner();
	HC = HumanController(PC);
	if (NewServer == "")
	{
		return false;
	}
	NewLink = CreateNewLink();
	if (NewLink == None)
	{
		return false;
	}
	if (HC != None)
	{
		NickName = "AA|" $ HC.UserName;
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
	NewLink.Connect(Self, NewServer, NickName, UserIdent, FullName, GetDefaultChannel());
	ChangeConnectStatus(true);
	SetTimer(1, true);
	*/
	return true;
}

void UAAIRC_System::Disconnect()
{
	//CloseLink(link, false);
}

void UAAIRC_System::CloseLink(AAAIRCLink* OldLink, bool bSwitchingServers, FString Reason)
{
	/*
	local FString ServerName;
	ServerName = OldLink.ServerAddress;
	if (Reason == "")
	{
		Reason = "Disconnected";
	}
	if (link != None)
	{
		if (link != OldLink)
		{
			OldLink.DestroyLink();
			return;
		}
		link.DisconnectReason = Reason;
		link.DestroyLink();
	}
	link = None;
	Channels.remove(0, Channels.Length);
	OnDisconnect();
	SystemText("Disconnected from server" @ ServerName);
	ChangeConnectStatus(bSwitchingServers);
	SetCurrentChannel(-1);
	KillTimer();
	*/
}

void UAAIRC_System::ProcessInput(FString Text)
{
	/*
	local int32 i;
	if (CurChannel > -1)
	{
		Channels[CurChannel].ProcessInput(Text);
	}
	else
	{
		if (Left(Text, 1) != "/")
		{
			SystemText("*** " $ NotInAChannelText);
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
					if (link != None)
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
	/*
	local AAIRC_Channel p;
	p = FindChannelWindow(ChannelName);
	if (p == None)
	{
		link.JoinChannel(ChannelName);
	}
	else
	{
		SetCurrentChannel(FindPublicChannelIndex(ChannelName));
	}
	*/
}

void UAAIRC_System::PartCurrentChannel()
{
	/*
	if (!ValidChannelIndex(CurChannel))
	{
		return;
	}
	PartChannel(Channels[CurChannel].ChannelName);
	*/
}

void UAAIRC_System::PartChannel(FString ChannelName)
{
	/*
	local AAIRC_Channel p;
	p = FindChannelWindow(ChannelName, true);
	if (p != None)
	{
		if (p.IsPrivate)
		{
			RemoveChannel(ChannelName);
		}
		else
		{
			link.PartChannel(ChannelName);
		}
	}
	*/
}

void UAAIRC_System::ChangeCurrentNick()
{
	/*
	if (Controller.OpenMenu(NewNickMenu, ChooseNewNickText, NickName))
	{
		Controller.ActivePage.__OnClose__Delegate = NewNickPageClosed;
	}
	*/
}

void UAAIRC_System::Whois(FString Nick)
{
	/*
	if (link == None)
	{
		return;
	}
	link.SendCommandText("WHOIS" @ Nick);
	*/
}

void UAAIRC_System::Op(FString Nick, FString ChannelName)
{
	/*
	if (link == None)
	{
		return;
	}
	SetMode("o", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" $ ChannelName), true, Nick);
	*/
}

void UAAIRC_System::Deop(FString Nick, FString ChannelName)
{
	/*
	if (link == None)
	{
		return;
	}
	SetMode("o", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" $ ChannelName), false, Nick);
	*/
}

void UAAIRC_System::Voice(FString Nick, FString ChannelName)
{
	/*
	if (link == None)
	{
		return;
	}
	SetMode("v", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" $ ChannelName), true, Nick);
	*/
}

void UAAIRC_System::DeVoice(FString Nick, FString ChannelName)
{
	/*
	if (link == None)
	{
		return;
	}
	SetMode("v", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" $ ChannelName), false, Nick);
	*/
}

void UAAIRC_System::Help(FString Nick, FString ChannelName)
{
	/*
	if (link == None)
	{
		return;
	}
	SetMode("h", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" $ ChannelName), true, Nick);
	*/
}

void UAAIRC_System::DeHelp(FString Nick, FString ChannelName)
{
	/*
	if (link == None)
	{
		return;
	}
	SetMode("h", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" $ ChannelName), false, Nick);
	*/
}

void UAAIRC_System::Kick(FString Nick, FString ChannelName, FString Reason)
{
	/*
	if (link == None)
	{
		SystemText(NotInAChannelText);
		return;
	}
	if ((Nick == "") || (ChannelName == ""))
	{
		SystemText(Repl(InvalidKickText, "%Cmd%", "KICK"));
		return;
	}
	link.SendCommandText("KICK" @ Nick $ Eval((Reason != ""), " :" $ Reason, ""));
	*/
}

void UAAIRC_System::Ban(FString Nick, FString ChannelName, FString Reason)
{
	/*
	SetMode("b", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" $ ChannelName), true, Nick);
	Kick(Nick, ChannelName, Reason);
	*/
}

void UAAIRC_System::Unban(FString Nick, FString ChannelName)
{
	/*
	SetMode("b", Eval((Left(ChannelName, 1) == "#"), ChannelName, "#" $ ChannelName), false, Nick);
	*/
}

void UAAIRC_System::SetMode(FString modes, FString Target, bool On, FString Extra)
{
	/*
	if (link == None)
	{
		SystemText(NotInAChannelText);
		return;
	}
	if ((modes == "") || (Target == ""))
	{
		SystemText(InvalidModeText);
		return;
	}
	if (link != None)
	{
		link.SendCommandText("MODE" @ Target @ Eval(On, "+", "-") $ modes $ Eval((Extra != ""), " " $ Extra, ""));
	}
	*/
}

void UAAIRC_System::SystemText(FString Text)
{
	/*
	if ((Text != "You have been marked as being away") && (Text != "You are no longer marked as being away"))
	{
		InterpretColorCodes(Text);
		lb_TextDisplay.AddText(MakeColorCode(IRCTextColor) $ ColorizeLinks(Text));
		if (!MyButton.bActive)
		{
			MyButton.bForceFlash = true;
		}
	}
	*/
}

void UAAIRC_System::ChannelText(FString Channel, FString Nick, FString Text)
{
	/*
	local AAIRC_Channel p;
	p = FindChannelWindow(Channel);
	if (p != None)
	{
		p.ChannelText(Nick, Text);
	}
	*/
}

void UAAIRC_System::PrivateText(FString Nick, FString Text)
{
	/*
	FindPrivateWindow(Nick).PrivateText(Nick, Text);
	*/
}

void UAAIRC_System::ChannelAction(FString Channel, FString Nick, FString Text)
{
	/*
	local AAIRC_Channel p;
	p = FindChannelWindow(Channel);
	if (p != None)
	{
		p.ChannelAction(Nick, Text);
	}
	*/
}

void UAAIRC_System::PrivateAction(FString Nick, FString Text)
{
	/*
	FindPrivateWindow(Nick).PrivateAction(Nick, Text);
	*/
}

void UAAIRC_System::JoinedChannel(FString Channel, FString Nick)
{
	/*
	local AAIRC_Channel NewCh;
	local AAIRC_Channel W;
	Log(Nick @ "JoinedChannel " $ Channel, 'IRC');
	if (Nick == "")
	{
		NewCh = AddChannel(Channel);
		if (NewCh != None)
		{
			SetCurrentChannelPage(NewCh);
		}
	}
	if (Nick == "")
	{
		Nick = NickName;
	}
	W = FindChannelWindow(Channel);
	if (W != None)
	{
		W.JoinedChannel(Nick);
	}
	*/
}

void UAAIRC_System::PartedChannel(FString Channel, FString Nick)
{
	/*
	local AAIRC_Channel W;
	W = FindChannelWindow(Channel);
	if (Nick == "")
	{
		RemoveChannel(Channel);
	}
	else
	{
		if (W != None)
		{
			W.PartedChannel(Nick);
		}
	}
	*/
}

void UAAIRC_System::KickUser(FString Channel, FString KickedNick, FString Kicker, FString Reason)
{
	/*
	local AAIRC_Channel W;
	W = FindChannelWindow(Channel);
	if (KickedNick == NickName)
	{
		RemoveChannel(Channel);
		SystemText("*** " $ KickedFromText @ Channel @ ByText @ Kicker $ " (" $ Reason $ ")");
	}
	else
	{
		if (W != None)
		{
			W.KickUser(KickedNick, Kicker, Reason);
		}
	}
	*/
}

void UAAIRC_System::UserInChannel(FString Channel, FString Nick)
{
	/*
	local AAIRC_Channel W;
	W = FindChannelWindow(Channel);
	if (W != None)
	{
		W.UserInChannel(Nick);
	}
	*/
}

void UAAIRC_System::NotifyNickInUse()
{
	/*
	if (AAIRC_NewNick(Controller.ActivePage) == None)
	{
		if (Controller.OpenMenu(NewNickMenu, NickInUseText, NickName))
		{
			Controller.ActivePage.__OnClose__Delegate = NewNickPageClosed;
		}
	}
	*/
}

void UAAIRC_System::NotifyInvalidNick()
{
	/*
	if (AAIRC_NewNick(Controller.ActivePage) == None)
	{
		if (Controller.OpenMenu(NewNickMenu, NickInvalidText, NickName))
		{
			Controller.ActivePage.__OnClose__Delegate = NewNickPageClosed;
		}
	}
	*/
}

void UAAIRC_System::NotifyChannelKey(FString chan)
{
	/*
	if (AAIRC_ChanKey(Controller.ActivePage) == None)
	{
		if (Controller.OpenMenu(ChanKeyMenu, chan))
		{
			Controller.ActivePage.__OnClose__Delegate = ChanKeyPageClosed;
		}
	}
	*/
}

void UAAIRC_System::ChangedNick(FString OldNick, FString NewNick)
{
	/*
	local int32 i;
	if (OldNick == NickName)
	{
		NickName = NewNick;
		if (link != None)
		{
			link.NickName = NewNick;
		}
		SaveConfig();
	}
	for (i = 0; i < Channels.Length; i++)
	{
		if (Channels[i].FindNick(OldNick))
		{
			Channels[i].ChangedNick(OldNick, NewNick);
		}
	}
	if (GetCurrentChannelName() ~= NewNick)
	{
		tp_Main.SetCloseCaption(NewNick);
	}
	*/
}

void UAAIRC_System::UserQuit(FString Nick, FString Reason)
{
	/*
	local int32 i;
	for (i = 0; i < Channels.Length; i++)
	{
		if (Channels[i].FindNick(Nick))
		{
			Channels[i].UserQuit(Nick, Reason);
		}
	}
	*/
}

void UAAIRC_System::UserNotice(FString Nick, FString Text)
{
	/*
	local int32 i;
	for (i = 0; i < Channels.Length; i++)
	{
		if (Channels[i].FindNick(Nick))
		{
			Channels[i].UserNotice(Nick, Text);
		}
	}
	*/
}

void UAAIRC_System::ChangeMode(FString Channel, FString Nick, FString Mode)
{
	/*
	local AAIRC_Channel W;
	W = FindChannelWindow(Channel);
	if (W != None)
	{
		W.ChangeMode(Nick, Mode);
	}
	*/
}

void UAAIRC_System::ChangeOwner(FString Channel, FString Nick, bool bOwner)
{
	/*
	local AAIRC_Channel W;
	W = FindChannelWindow(Channel);
	if (W != None)
	{
		W.ChangeOwner(Nick, bOwner);
	}
	*/
}

void UAAIRC_System::ChangeProtected(FString Channel, FString Nick, bool bProtected)
{
	/*
	local AAIRC_Channel W;
	W = FindChannelWindow(Channel);
	if (W != None)
	{
		W.ChangeProtected(Nick, bProtected);
	}
	*/
}

void UAAIRC_System::ChangeOp(FString Channel, FString Nick, bool bOp)
{
	/*
	local AAIRC_Channel W;
	W = FindChannelWindow(Channel);
	if (W != None)
	{
		W.ChangeOp(Nick, bOp);
	}
	*/
}

void UAAIRC_System::ChangeHalfOp(FString Channel, FString Nick, bool bHalfOp)
{
	/*
	local AAIRC_Channel W;
	W = FindChannelWindow(Channel);
	if (W != None)
	{
		W.ChangeHalfOp(Nick, bHalfOp);
	}
	*/
}

void UAAIRC_System::ChangeVoice(FString Channel, FString Nick, bool bVoice)
{
	/*
	local AAIRC_Channel W;
	W = FindChannelWindow(Channel);
	if (W != None)
	{
		W.ChangeVoice(Nick, bVoice);
	}
	*/
}

void UAAIRC_System::ChangeTopic(FString Channel, FString NewTopic)
{
	/*
	local AAIRC_Channel W;
	W = FindChannelWindow(Channel);
	if (W != None)
	{
		Log("Topic (Channel: " $ Channel $ ") : " $ NewTopic, 'IRC');
		W.ChangeTopic(NewTopic);
	}
	*/
}

void UAAIRC_System::CTCP(FString Channel, FString Nick, FString Message)
{
	/*
	if ((Channel == "") || (Channel == NickName))
	{
		SystemText("[" $ Nick $ ": " $ Message $ "]");
	}
	else
	{
		SystemText("[" $ Nick $ ":" $ Channel $ " " $ Message $ "]");
	}
	*/
}

UAAIRC_Page* UAAIRC_System::GetCurrentChannel()
{
	/*
	if (CurChannel != -1)
	{
		return Channels[CurChannel];
	}
	return Self;
	*/
	return nullptr;   //FAKE   /ELiZ
}

FString UAAIRC_System::GetCurrentChannelName()
{
	/*
	if (CurChannel != -1)
	{
		return Channels[CurChannel].ChannelName;
	}
	*/
	return "";
}

FString UAAIRC_System::GetDefaultChannel()
{
	return DefaultChannel;
}

UAAIRC_Channel* UAAIRC_System::FindChannelWindow(FString Channel, bool bIncludePrivate)
{
	/*
	local int32 i;
	i = FindPublicChannelIndex(Channel, bIncludePrivate);
	if (i != -1)
	{
		return Channels[i];
	}
	*/
	return nullptr;
}

UAAIRC_Private* UAAIRC_System::FindPrivateWindow(FString Nick)
{
	/*
	local int32 i;
	i = FindPrivateChannelIndex(Nick);
	if (i != -1)
	{
		return AAIRC_Private(Channels[i]);
	}
	return AAIRC_Private(AddChannel(Nick, true));
	*/
	return nullptr;   //FAKE   /ELiZ
}

int32 UAAIRC_System::FindPublicChannelIndex(FString ChannelName, bool bIncludePrivate)
{
	/*
	local int32 i;
	for (i = 0; i < Channels.Length; i++)
	{
		if (Channels[i].ChannelName ~= ChannelName)
		{
			if ((!Channels[i].IsPrivate) || bIncludePrivate)
			{
				return i;
			}
		}
	}
	*/
	return -1;
}

int32 UAAIRC_System::FindPrivateChannelIndex(FString ChannelName)
{
	/*
	local int32 i;
	for (i = 0; i < Channels.Length; i++)
	{
		if (Channels[i].IsPrivate && (ChannelName ~= Channels[i].ChannelName))
		{
			return i;
		}
	}
	*/
	return -1;
}

void UAAIRC_System::SetCurrentChannelPage(UAAIRC_Channel* ChannelPage)
{
	/*
	local int32 i;
	for (i = 0; i < Channels.Length; i++)
	{
		if (Channels[i] == ChannelPage)
		{
			SetCurrentChannel(i);
			return;
		}
	}
	*/
}

void UAAIRC_System::SetCurrentChannel(int32 idx)
{
	/*
	if (idx == CurChannel)
	{
		return;
	}
	idx = Clamp(idx, -1, (Channels.Length - 1));
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
	/*
	local AAIRC_Private W;
	W = FindPrivateWindow(Nick);
	if (W != None)
	{
		W.PrintAwayMessage(Nick, Message);
	}
	else
	{
		SystemText(Nick @ IsAwayText $ ": " $ Message);
	}
	*/
}

void UAAIRC_System::IRCClosed()
{
	UpdateAway();
}

AAAIRCLink* UAAIRC_System::CreateNewLink()
{
	AAAIRCLink* NewLink = nullptr
		/*
		local class<AAIRCLink>  NewLinkClass;

		if (PlayerOwner() == None)
		{
			return None;
		}
		if (LinkClassName != "")
		{
			NewLinkClass = class<AAIRCLink>(DynamicLoadObject(LinkClassName, Class'Class'));
		}
		if (NewLinkClass != None)
		{
			NewLink = PlayerOwner().Spawn(NewLinkClass);
		}
		*/;
	return NewLink;
}

UAAIRC_Channel* UAAIRC_System::AddChannel(FString ChannelName, bool bPrivate, bool bActivate)
{
	UAAIRC_Channel* NewCh = nullptr;
	/*
	NewCh = tp_Main.AddChannel(ChannelName, bPrivate);
	if (NewCh != None)
	{
		NewCh.tp_System = Self;
		NewCh.IsPrivate = bPrivate;
		NewCh.ChannelName = ChannelName;
		Channels[Channels.Length] = NewCh;
		if (bActivate)
		{
			SetCurrentChannel((Channels.Length - 1));
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
	Channels.remove(Index, 1);
	*/
	return true;
}

void UAAIRC_System::RemoveChannel(FString Channel)
{
	/*
	local int32 i;
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
	if ((Index < 0) || (Index >= Channels.Length))
	{
		return false;
	}
	*/
	return true;
}

void UAAIRC_System::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (AAIRC_Panel(NewComp) != None)
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
	/*
	local FString ClickString;
	local FString ChanName;
	Super:IRCTextDblClick(Sender);
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

