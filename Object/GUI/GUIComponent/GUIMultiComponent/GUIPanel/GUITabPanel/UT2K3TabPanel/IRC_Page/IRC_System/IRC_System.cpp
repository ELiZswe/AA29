// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_System/IRC_System.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/BufferedTCPLink/IRCLink/IRCLink.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_IRC/Browser_IRC.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_Channel/IRC_Channel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_Page.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_Channel/IRC_Private/IRC_Private.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"

UIRC_System::UIRC_System()
{
	UGUIButton* MyRemoveChannelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyRemoveChannelButton->Caption="REMOVE CHANNEL";
	MyRemoveChannelButton->WinTop=0.5;
	MyRemoveChannelButton->WinLeft=0.77;
	MyRemoveChannelButton->WinWidth=0.2;
	MyRemoveChannelButton->WinHeight=0.3;
	//MyRemoveChannelButton->OnClick=IRC_System.RemoveChannelClick;
	//MyRemoveChannelButton->OnKeyEvent=MyRemoveChannelButton.InternalOnKeyEvent;
	UGUIComboBox* MyChannelCombo = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	MyChannelCombo->WinTop=0.5;
	MyChannelCombo->WinLeft=0.15;
	MyChannelCombo->WinWidth=0.4;
	MyChannelCombo->WinHeight=0.3;
	//MyChannelCombo->OnKeyEvent=MyChannelCombo.InternalOnKeyEvent;
	UGUIButton* MyJoinChannelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyJoinChannelButton->Caption="JOIN CHANNEL";
	MyJoinChannelButton->WinTop=0.5;
	MyJoinChannelButton->WinLeft=0.56;
	MyJoinChannelButton->WinWidth=0.2;
	MyJoinChannelButton->WinHeight=0.3;
	//MyJoinChannelButton->OnClick=IRC_System.JoinChannelClick;
	//MyJoinChannelButton->OnKeyEvent=MyJoinChannelButton.InternalOnKeyEvent;
	UGUIButton* MyRemoveServerButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyRemoveServerButton->Caption="REMOVE SERVER";
	MyRemoveServerButton->WinTop=0.1;
	MyRemoveServerButton->WinLeft=0.77;
	MyRemoveServerButton->WinWidth=0.2;
	MyRemoveServerButton->WinHeight=0.3;
	//MyRemoveServerButton->OnClick=IRC_System.RemoveServerClick;
	//MyRemoveServerButton->OnKeyEvent=MyRemoveServerButton.InternalOnKeyEvent;
	UGUIComboBox* MyServerCombo = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	MyServerCombo->WinTop=0.1;
	MyServerCombo->WinLeft=0.15;
	MyServerCombo->WinWidth=0.4;
	MyServerCombo->WinHeight=0.3;
	//MyServerCombo->OnKeyEvent=MyServerCombo.InternalOnKeyEvent;
	UGUIButton* MyConnectButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyConnectButton->WinTop=0.1;
	MyConnectButton->WinLeft=0.56;
	MyConnectButton->WinWidth=0.2;
	MyConnectButton->WinHeight=0.3;
	//MyConnectButton->OnClick=IRC_System.ConnectClick;
	//MyConnectButton->OnKeyEvent=MyConnectButton.InternalOnKeyEvent;
	UGUILabel* MyServerLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyServerLabel->Caption="Server";
	MyServerLabel->TextColor=FColor(255, 255, 255, 255);
	MyServerLabel->StyleName="TextLabel";
	MyServerLabel->WinTop=0.1;
	MyServerLabel->WinLeft=0.03;
	MyServerLabel->WinWidth=0.2;
	MyServerLabel->WinHeight=0.3;
	UGUILabel* MyChannelLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyChannelLabel->Caption="Channel";
	MyChannelLabel->TextColor=FColor(255, 255, 255, 255);
	MyChannelLabel->StyleName="TextLabel";
	MyChannelLabel->WinTop=0.5;
	MyChannelLabel->WinLeft=0.03;
	MyChannelLabel->WinWidth=0.2;
	MyChannelLabel->WinHeight=0.3;
	
	NotInAChannelText = "Not in a channel!";
	KickedFromText = "You were kicked from";
	ByText = "by";
	IsAwayText = "is away";
	ConnectText = "CONNECT";
	DisconnectText = "DISCONNECT";
	ServerLabel =MyServerLabel;
	ConnectButton = MyConnectButton;
	ServerCombo = MyServerCombo;
	RemoveServerButton = MyRemoveServerButton;
	ChannelLabel = MyChannelLabel;
	JoinChannelButton = MyJoinChannelButton;
	ChannelCombo = MyChannelCombo;
	RemoveChannelButton = MyRemoveChannelButton;
	CurChannel = -1;
	PrevChannel = -1;
}

void UIRC_System::UpdateConnectCaption()
{
	/*
	if (bConnected)
	{
		ConnectButton.Caption = DisconnectText;
	}
	else
	{
		ConnectButton.Caption = ConnectText;
	}
	*/
}

void UIRC_System::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	UGUIPanel* UtilPanel = nullptr;
	int32 i = 0;
	int32 j = 0;
	/*
	if (!bSysInitialised)
	{
		Cast<UGUISplitter>(Controls[1]).bDrawSplitter = false;
		UtilPanel = Cast<UGUIPanel>(Cast<UGUISplitter>(Controls[1]).Controls[1]);
		UtilPanel.Controls.Num() = 8;
		UtilPanel.Controls[0] = ConnectButton;
		UtilPanel.Controls[1] = ServerCombo;
		UtilPanel.Controls[2] = RemoveServerButton;
		UtilPanel.Controls[3] = ServerLabel;
		UtilPanel.Controls[4] = JoinChannelButton;
		UtilPanel.Controls[5] = ChannelCombo;
		UtilPanel.Controls[6] = RemoveChannelButton;
		UtilPanel.Controls[7] = ChannelLabel;
	}
	Super::InitComponent(MyController, MyOwner);
	if (!bSysInitialised)
	{
		SetTimer(1, true);
		UpdateConnectCaption();
		Log(string(ServerHistory.Num()) + " Servers " + FString::FromInt(ChannelHistory.Num()) + " Channels");
		for (i = 0; i < ServerHistory.Num(); i++)
		{
			ServerCombo.addItem(ServerHistory[i]);
		}
		if (ServerHistory.Num() > 0)
		{
			ServerCombo.SetText(ServerHistory[0]);
		}
		if (ChannelHistory.Num() == 0)
		{
			for (i = 0; i < DefaultChannels.Num(); i++)
			{
				j = (ChannelHistory.Num() + 1);
				ChannelHistory.Num() = j;
				ChannelHistory[(j - 1)] = DefaultChannels[i];
			}
		}
		for (i = 0; i < ChannelHistory.Num(); i++)
		{
			ChannelCombo.addItem(ChannelHistory[i]);
		}
		if (ChannelHistory.Num() > 0)
		{
			ChannelCombo.SetText(ChannelHistory[0]);
		}
		bSysInitialised = true;
	}
	*/
}

int32 UIRC_System::FindServerHistoryIndex(FString ServerName)
{
	int32 ix = 0;
	int32 i = 0;
	ix = -1;
	i = 0;
	/*
	if ((i < ServerHistory.Num()) && (ix == -1))
	{
		if (ServerHistory[i] ~= ServerName)
		{
			ix = i;
		}
		i++;
	}
	*/
	return ix;
}

int32 UIRC_System::FindChannelHistoryIndex(FString ChannelName)
{
	int32 ix = 0;
	int32 i = 0;
	ix = -1;
	/*
	i = 0;
	if ((i < ChannelHistory.Num()) && (ix == -1))
	{
		if (ChannelHistory[i] ~= ChannelName)
		{
			ix = i;
		}
		i++;
	}
	*/
	return ix;
}

bool UIRC_System::ConnectClick(UGUIComponent* Sender)
{
	/*
	int32 i = 0;
	FString ServerName = "";
	if (Sender != ConnectButton)
	{
		return true;
	}
	if (bConnected)
	{
		Disconnect();
	}
	else
	{
		Connect();
		if (bConnected)
		{
			ServerName = ServerCombo.Edit.GetText();
			i = FindServerHistoryIndex(ServerName);
			if (i == -1)
			{
				i = (ServerHistory.Num() + 1);
				ServerHistory.Num() = i;
				ServerHistory[(i - 1)] = ServerName;
				SaveConfig();
				ServerCombo.addItem(ServerName);
				ServerCombo.SetText(ServerName);
				ServerCombo.List.Top = 0;
			}
		}
	}
	*/
	return true;
}

bool UIRC_System::JoinChannelClick(UGUIComponent* Sender)
{
	/*
	int32 i = 0;
	FString ChannelName = "";
	if ((Sender != JoinChannelButton) || (!bConnected))
	{
		return true;
	}
	JoinChannel(ChannelCombo.Edit.GetText());
	ChannelName = ChannelCombo.Edit.GetText();
	i = FindChannelHistoryIndex(ChannelName);
	if (i == -1)
	{
		i = (ChannelHistory.Num() + 1);
		ChannelHistory.Num() = i;
		ChannelHistory[(i - 1)] = ChannelName;
		SaveConfig();
		ChannelCombo.addItem(ChannelName);
		ChannelCombo.SetText(ChannelName);
		ChannelCombo.List.Top = 0;
	}
	*/
	return true;
}

bool UIRC_System::RemoveServerClick(UGUIComponent* Sender)
{
	/*
	FString ServerName = "";
	int32 i = 0;
	ServerName = ServerCombo.Edit.GetText();
	i = FindServerHistoryIndex(ServerName);
	if (i != -1)
	{
		ServerHistory.RemoveAt(i, 1);
		SaveConfig();
		ServerCombo.RemoveItem(i, 1);
		if (ServerHistory.Num() > 0)
		{
			ServerCombo.SetText(ServerHistory[0]);
		}
	}
	*/
	return true;
}

bool UIRC_System::RemoveChannelClick(UGUIComponent* Sender)
{
	/*
	FString ChannelName = "";
	int32 i = 0;
	ChannelName = ChannelCombo.Edit.GetText();
	i = FindChannelHistoryIndex(ChannelName);
	if (i != -1)
	{
		ChannelHistory.RemoveAt(i, 1);
		SaveConfig();
		ChannelCombo.RemoveItem(i, 1);
		if (ChannelHistory.Num() > 0)
		{
			ChannelCombo.SetText(ChannelHistory[0]);
		}
	}
	*/
	return true;
}

void UIRC_System::Timer()
{
	/*
	if (((bConnected && (PlayerOwner() != nullptr)) && (PlayerOwner().PlayerReplicationInfo != nullptr)) && (PlayerOwner().PlayerReplicationInfo.PlayerName != OldPlayerName))
	{
		OldPlayerName = PlayerOwner().PlayerReplicationInfo.PlayerName;
		link.SetNick(OldPlayerName);
		SystemText("SetNick: " + OldPlayerName);
	}
	*/
}

void UIRC_System::SetCurrentChannelPage(UIRC_Channel* ChannelPage)
{
	/*
	int32 i = 0;
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i] == ChannelPage)
		{
			SetCurrentChannel(i);
			return;
		}
	}
	*/
}

void UIRC_System::SetCurrentChannel(int32 idx)
{
	/*
	if (((idx < -1) || (idx > (Channels.Num() - 1))) || (idx == CurChannel))
	{
		return;
	}
	PrevChannel = CurChannel;
	CurChannel = idx;
	if (CurChannel == -1)
	{
		if (IRCPage.ChannelTabs.ActiveTab != MyButton)
		{
			IRCPage.ChannelTabs.ActivateTab(MyButton, true);
		}
	}
	else
	{
		if (IRCPage.ChannelTabs.ActiveTab != Channels[CurChannel].MyButton)
		{
			IRCPage.ChannelTabs.ActivateTab(Channels[CurChannel].MyButton, true);
		}
	}
	*/
}

UIRC_Page* UIRC_System::GetActivePage()
{
	/*
	if (CurChannel != -1)
	{
		return Channels[CurChannel];
	}
	return this;
	*/
	return nullptr;    //FAKE   /ELiZ
}

void UIRC_System::ProcessInput(FString Text)
{
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
			link.SendCommandText(Mid(Text, 1));
		}
	}
	*/
}

UIRC_Channel* UIRC_System::FindChannelWindow(FString Channel)
{
	/*
	int32 i = 0;
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i].IsPrivate == true)
		{
		}
		if (Channels[i].ChannelName ~= Channel)
		{
			return Channels[i];
		}
	}
	*/
	return nullptr;
}

int32 UIRC_System::FindChannelIndex(FString Channel)
{
	/*
	int32 i = 0;
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i].IsPrivate == true)
		{
		}
		if (Channels[i].ChannelName ~= Channel)
		{
			return i;
		}
	}
	*/
	return -1;
}

UIRC_Private* UIRC_System::FindPrivateWindow(FString Nick)
{
	/*
	int32 i = 0;
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i].IsPrivate == false)
		{
		}
		if (Channels[i].ChannelName ~= Nick)
		{
			return IRC_Private(Channels[i]);
		}
	}
	*/
	return CreatePrivChannel(Nick,false);
}

void UIRC_System::Connect()
{
	/*
	int32 i = 0;
	APlayerController* PC = nullptr;
	if (link != nullptr)
	{
		Disconnect();
	}
	PC = PlayerOwner();
	Assert((PC != nullptr));
	if (PC.PlayerReplicationInfo != nullptr)
	{
		if (PC.PlayerReplicationInfo.PlayerName != OldPlayerName)
		{
			NickName = PC.PlayerReplicationInfo.PlayerName;
			OldPlayerName = NickName;
			if (FullName == "")
			{
				FullName = NickName;
			}
			SaveConfig();
		}
	}
	else
	{
		NickName = PlayerOwner().GetUrlOption("Name");
		OldPlayerName = NickName;
		if (FullName == "")
		{
			FullName = NickName;
		}
		SaveConfig();
	}
	if (UserIdent == "")
	{
		UserIdent = "u";
		for (i = 0; i < 7; i++)
		{
			UserIdent = UserIdent + Chr((Rand(10) + 48));
		}
		Log("Created new UserIdent: " + UserIdent);
		SaveConfig();
	}
	link = PlayerOwner().GetEntryLevel().Spawn(AIRCLink::StaticClass());
	link.Connect(this, ServerCombo.Edit.GetText(), NickName, UserIdent, FullName, "");
	bConnected = true;
	UpdateConnectCaption();
	*/
}

void UIRC_System::JoinChannel(FString ChannelName)
{
	UIRC_Channel* p = nullptr;
	/*
	p = FindChannelWindow(ChannelName);
	if (p == nullptr)
	{
		link.JoinChannel(ChannelName);
	}
	else
	{
		SetCurrentChannel(FindChannelIndex(ChannelName));
	}
	*/
}

void UIRC_System::PartCurrentChannel()
{
	/*
	if (CurChannel == -1)
	{
		return;
	}
	if (Channels[CurChannel]->IsA(UIRC_Private::StaticClass()))
	{
		IRCPage.ChannelTabs.RemoveTab(Channels[CurChannel].MyButton.Caption);
		Channels.RemoveAt(CurChannel, 1);
		SetCurrentChannel(-1);
	}
	else
	{
		PartChannel(Channels[CurChannel].ChannelName);
	}
	*/
}

void UIRC_System::PartChannel(FString ChannelName)
{
	UIRC_Channel* p = nullptr;
	/*
	p = FindChannelWindow(ChannelName);
	if (p != nullptr)
	{
		link.PartChannel(ChannelName);
	}
	*/
}

void UIRC_System::Disconnect()
{
	/*
	int32 i = 0;
	if (link != nullptr)
	{
		link.DisconnectReason = "Disconnected";
		link.DestroyLink();
	}
	link = nullptr;
	for (i = 0; i < Channels.Num(); i++)
	{
		IRCPage.ChannelTabs.RemoveTab(Channels[i].MyButton.Caption);
	}
	Channels.Num() = 0;
	CurChannel = -1;
	SystemText("Server disconnected");
	bConnected = false;
	if (IRCPage.ChannelTabs.ActiveTab != Self.MyButton)
	{
		IRCPage.ChannelTabs.ActivateTab(Self.MyButton, true);
	}
	UpdateConnectCaption();
	*/
}

void UIRC_System::NotifyQuitUnreal()
{
	/*
	if (link != nullptr)
	{
		link.DisconnectReason = "Exit Game";
		link.DestroyLink();
	}
	*/
}

void UIRC_System::SystemText(FString Text)
{
	/*
	if ((Text != "You have been marked as being away") && (Text != "You are no longer marked as being away"))
	{
		TextDisplay.AddText(MakeColorCode(IRCTextColor) + ColorizeLinks(Text));
		if (!MyButton.bActive)
		{
			MyButton.bForceFlash = true;
		}
	}
	*/
}

void UIRC_System::ChannelText(FString Channel, FString Nick, FString Text)
{
	UIRC_Channel* p = nullptr;
	/*
	p = FindChannelWindow(Channel);
	if (p != nullptr)
	{
		p.ChannelText(Nick, Text);
	}
	*/
}

void UIRC_System::PrivateText(FString Nick, FString Text)
{
	//FindPrivateWindow(Nick).PrivateText(Nick, Text);
}

UIRC_Private* UIRC_System::CreatePrivChannel(FString Nick, bool bMakeActive)
{
	UIRC_Private* priv = nullptr;
	/*
	priv = IRC_Private(IRCPage.ChannelTabs.AddTab(Nick, "xinterface.IRC_Private"));
	Channels[Channels.Num()] = priv;
	priv.SystemPage = this;
	priv.IsPrivate = true;
	priv.ChannelName = Nick;
	if (bMakeActive)
	{
		SetCurrentChannel((Channels.Num() - 1));
	}
	*/
	return priv;
}

void UIRC_System::ChannelAction(FString Channel, FString Nick, FString Text)
{
	UIRC_Channel* p = nullptr;
	/*
	p = FindChannelWindow(Channel);
	if (p != nullptr)
	{
		p.ChannelAction(Nick, Text);
	}
	*/
}

void UIRC_System::PrivateAction(FString Nick, FString Text)
{
	//FindPrivateWindow(Nick).PrivateAction(Nick, Text);
}

void UIRC_System::JoinedChannel(FString Channel, FString Nick)
{
	UIRC_Channel* NewCh = nullptr;
	UIRC_Channel* W = nullptr;
	/*
	Log("JoinedChannel " + Channel, 'IRC');
	if (Nick == "")
	{
		NewCh = IRC_Channel(IRCPage.ChannelTabs.AddTab(Channel, "xinterface.IRC_Channel"));
		Channels[Channels.Num()] = NewCh;
		NewCh.SystemPage = this;
		NewCh.IsPrivate = false;
		NewCh.ChannelName = Channel;
		SetCurrentChannel((Channels.Num() - 1));
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

void UIRC_System::RemoveChannel(FString Channel)
{
	int32 i = 0;
	/*
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i].IsPrivate == true)
		{
		}
		if (Channels[i].ChannelName ~= Channel)
		{
		}
	}
	if (i < Channels.Num())
	{
		IRCPage.ChannelTabs.RemoveTab(Channels[i].MyButton.Caption);
		Channels.RemoveAt(i, 1);
		SetCurrentChannel(-1);
	}
	*/
}

void UIRC_System::KickUser(FString Channel, FString KickedNick, FString Kicker, FString Reason)
{
	UIRC_Channel* W = nullptr;
	/*
	W = FindChannelWindow(Channel);
	if (KickedNick == NickName)
	{
		RemoveChannel(Channel);
		SystemText("*** " + KickedFromText @ Channel @ ByText @ Kicker + " (" + Reason + ")");
	}
	else
	{
		if (W != nullptr)
		{
			W.KickUser(KickedNick, Kicker, Reason);
		}
	}
	*/
}

void UIRC_System::UserInChannel(FString Channel, FString Nick)
{
	UIRC_Channel* W = nullptr;
	/*
	W = FindChannelWindow(Channel);
	if (W != nullptr)
	{
		W.UserInChannel(Nick);
	}
	*/
}

void UIRC_System::PartedChannel(FString Channel, FString Nick)
{
	UIRC_Channel* W = nullptr;
	/*
	W = FindChannelWindow(Channel);
	if (Nick == "")
	{
		RemoveChannel(Channel);
	}
	else
	{
		if (W != nullptr)
		{
			W.PartedChannel(Nick);
		}
	}
	*/
}

void UIRC_System::ChangedNick(FString OldNick, FString NewNick)
{
	int32 i = 0;
	/*
	if (OldNick == NickName)
	{
		NickName = NewNick;
		link.NickName = NewNick;
		SaveConfig();
	}
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i].FindNick(OldNick) || (Channels[i].ChannelName ~= OldNick))
		{
			Channels[i].ChangedNick(OldNick, NewNick);
		}
	}
	*/
}

void UIRC_System::UserQuit(FString Nick, FString Reason)
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
void UIRC_System::UserNotice(FString Nick, FString Text)
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

void UIRC_System::ChangeMode(FString Channel, FString Nick, FString Mode)
{
	UIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel);
	if (W != nullptr)
	{
		W->ChangeMode(Nick, Mode);
	}
}

void UIRC_System::ChangeOp(FString Channel, FString Nick, bool bOp)
{
	UIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel);
	if (W != nullptr)
	{
		W->ChangeOp(Nick, bOp);
	}
}

void UIRC_System::ChangeHalfOp(FString Channel, FString Nick, bool bHalfOp)
{
	UIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel);
	if (W != nullptr)
	{
		W->ChangeHalfOp(Nick, bHalfOp);
	}
}

void UIRC_System::ChangeVoice(FString Channel, FString Nick, bool bVoice)
{
	UIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel);
	if (W != nullptr)
	{
		W->ChangeVoice(Nick, bVoice);
	}
}

void UIRC_System::ChangeTopic(FString Channel, FString NewTopic)
{
	UIRC_Channel* W = nullptr;
	W = FindChannelWindow(Channel);
	if (W != nullptr)
	{
		//Log("Topic (Channel: " + Channel + ") : " + NewTopic);
		W->ChangeTopic(NewTopic);
	}
}

void UIRC_System::IsAway(FString Nick, FString Message)
{
	UIRC_Private* W = nullptr;
	W = FindPrivateWindow(Nick);
	if (W != nullptr)
	{
		W->IsAway(Nick, Message);
	}
	else
	{
		SystemText(Nick + IsAwayText + ": " + Message);
	}
}

void UIRC_System::IRCVisible()
{
	if (bAway)
	{
		if (bConnected)
		{
			link->SetAway("");
		}
		bAway = false;
	}
}

void UIRC_System::IRCClosed()
{
	CheckAway();
}

void UIRC_System::NotifyAfterLevelChange()
{
	CheckAway();
}

bool UIRC_System::InGame()
{
	if (!Controller->bActive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UIRC_System::UpdateAway()
{
	FString URL = "";
	FString AwayString = "";
	if (bConnected)
	{
		if (!InGame())
		{
			link->SetAway("");
			bAway = false;
		}
		else
		{
			/*
			URL = PlayerOwner().Level.GetAddressURL();
			if (InStr(URL, ":") > 0)
			{
				//AwayString = PlayerOwner().GetURLProtocol() + "://" + URL;
			}
			else
			{
				AwayString = "local game";
			}
			*/
			link->SetAway(AwayString);
			bAway = true;
		}
	}
}

void UIRC_System::CheckAway()
{
	FString URL = "";
	/*
	if (bConnected)
	{
		bAway = true;
		URL = PlayerOwner().Level.GetAddressURL();
		if (InStr(URL, ":") > 0)
		{
			link.SetAway(PlayerOwner().GetURLProtocol() + "://" + URL);
		}
		else
		{
			if (InGame())
			{
				link.SetAway("local game");
			}
			else
			{
				link.SetAway("in menus");
			}
		}
	}
	*/
}

void UIRC_System::CTCP(FString Channel, FString Nick, FString Message)
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
