// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanel/AAIRC_Panel/AAIRC_Panel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_System/AAIRC_System.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "Engine/Canvas.h"

UAAIRC_Panel::UAAIRC_Panel()
{
	UGUIButton* MyRemoveChannelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyRemoveChannelButton->Caption = "REMOVE";
	MyRemoveChannelButton->WinTop = 0.5;
	MyRemoveChannelButton->WinLeft = 0.73;
	MyRemoveChannelButton->WinWidth = 0.2;
	MyRemoveChannelButton->WinHeight = 0.26738;
	MyRemoveChannelButton->RenderWeight = 3;
	MyRemoveChannelButton->TabOrder = 5;
	MyRemoveChannelButton->bBoundToParent = true;
	MyRemoveChannelButton->bScaleToParent = true;
	//MyRemoveChannelButton->OnClick=AAIRC_Panel.InternalOnClick;
	//MyRemoveChannelButton->OnKeyEvent=MyRemoveChannelButton.InternalOnKeyEvent;
	UGUIButton* MyRemoveServerButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyRemoveServerButton->Caption = "REMOVE";
	MyRemoveServerButton->WinTop = 0.1;
	MyRemoveServerButton->WinLeft = 0.73;
	MyRemoveServerButton->WinWidth = 0.2;
	MyRemoveServerButton->WinHeight = 0.26738;
	MyRemoveServerButton->RenderWeight = 3;
	MyRemoveServerButton->TabOrder = 4;
	MyRemoveServerButton->bBoundToParent = true;
	MyRemoveServerButton->bScaleToParent = true;
	//MyRemoveServerButton->OnClick=AAIRC_Panel.InternalOnClick;
	//MyRemoveServerButton->OnKeyEvent=MyRemoveServerButton.InternalOnKeyEvent;
	UGUIButton* MyJoinChannelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyJoinChannelButton->Caption = "JOIN";
	MyJoinChannelButton->WinTop = 0.5;
	MyJoinChannelButton->WinLeft = 0.52;
	MyJoinChannelButton->WinWidth = 0.2;
	MyJoinChannelButton->WinHeight = 0.26738;
	MyJoinChannelButton->RenderWeight = 3;
	MyJoinChannelButton->TabOrder = 3;
	MyJoinChannelButton->bBoundToParent = true;
	MyJoinChannelButton->bScaleToParent = true;
	//MyJoinChannelButton->OnClick=AAIRC_Panel.InternalOnClick;
	//MyJoinChannelButton->OnKeyEvent=MyJoinChannelButton.InternalOnKeyEvent;
	UGUIButton* MyConnectButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyConnectButton->Caption = "CONNECT";
	MyConnectButton->WinTop = 0.1;
	MyConnectButton->WinLeft = 0.52;
	MyConnectButton->WinWidth = 0.2;
	MyConnectButton->WinHeight = 0.26738;
	MyConnectButton->RenderWeight = 3;
	MyConnectButton->TabOrder = 2;
	MyConnectButton->bBoundToParent = true;
	MyConnectButton->bScaleToParent = true;
	//MyConnectButton->OnClick=AAIRC_Panel.InternalOnClick;
	//MyConnectButton->OnKeyEvent=MyConnectButton.InternalOnKeyEvent;
	UmoComboBox* MyChannelCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MyChannelCombo->CaptionWidth = 0.25;
	MyChannelCombo->Caption = "Channel";
	//MyChannelCombo->OnCreateComponent=MyChannelCombo.InternalOnCreateComponent;
	MyChannelCombo->WinTop = 0.5;
	MyChannelCombo->WinLeft = 0.02;
	MyChannelCombo->WinWidth = 0.45;
	MyChannelCombo->WinHeight = 0.26738;
	MyChannelCombo->RenderWeight = 3;
	MyChannelCombo->TabOrder = 1;
	MyChannelCombo->bBoundToParent = true;
	MyChannelCombo->bScaleToParent = true;
	MyChannelCombo->bStandardized = false;
	UmoComboBox* MyServerCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MyServerCombo->CaptionWidth = 0.25;
	MyServerCombo->Caption = "Server";
	//MyServerCombo->OnCreateComponent=MyServerCombo.InternalOnCreateComponent;
	MyServerCombo->WinTop = 0.102967;
	MyServerCombo->WinLeft = 0.02;
	MyServerCombo->WinWidth = 0.45;
	MyServerCombo->WinHeight = 0.26738;
	MyServerCombo->RenderWeight = 3;
	MyServerCombo->TabOrder = 0;
	MyServerCombo->bBoundToParent = true;
	MyServerCombo->bScaleToParent = true;
	MyServerCombo->bStandardized = false;
	//MyServerCombo->OnChange=AAIRC_Panel.InternalOnChange;
	co_Server = MyServerCombo;
	co_Channel = MyChannelCombo;
	b_Connect = MyConnectButton;
	b_RemServer = MyRemoveServerButton;
	b_JoinChannel = MyJoinChannelButton;
	b_RemChannel = MyRemoveChannelButton;

	ServerHistory = { "irc.americasarmy.com" };
	ChannelHistory = { "#aa-support", "#americasarmy", "#aa-newplayers" };
	ConnectText = "CONNECT";
	DisconnectText = "DISCONNECT";
	LocalChannel = "#aa-support";
	//__OnPreDraw__Delegate = "AAIRC_Panel.PositionButtons";
}

void UAAIRC_Panel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	UGUIComponent* C = nullptr;
	Super::InitComponent(MyController, MyOwner);
	/*
	C = MenuOwner;
	if (C != nullptr)
	{
		if (Cast<UAAIRC_System>(C) != nullptr)
		{
			tp_System = AAIRC_System(C);
		}
		else
		{
			C = C.MenuOwner;
		}
	}
	Assert(tp_System != nullptr);
	GetSizingButton();
	Log(ServerHistory.Num() + " Servers " + ChannelHistory.Num() + " Channels", 'IRC');
	LoadServerHistory();
	LoadChannelHistory();
	*/
}

void UAAIRC_Panel::LoadServerHistory()
{
	int32 i = 0;
	/*
	if (ServerHistory.Num() == 0)
	{
		ResetConfig("ServerHistory");
	}
	co_Server.MyComboBox.List.Clear();
	for (i = 0; i < ServerHistory.Num(); i++)
	{
		co_Server.addItem(ServerHistory[i]);
	}
	*/
}

void UAAIRC_Panel::LoadChannelHistory()
{
	int32 i = 0;
	/*
	if (ChannelHistory.Num() == 0)
	{
		ResetConfig("ChannelHistory");
	}
	co_Channel.MyComboBox.List.Clear();
	co_Channel.addItem(LocalChannel);
	for (i = 0; i < ChannelHistory.Num(); i++)
	{
		if (Caps(ChannelHistory[i]) != Caps(LocalChannel))
		{
			co_Channel.addItem(ChannelHistory[i]);
		}
	}
	*/
}

void UAAIRC_Panel::GetSizingButton()
{
	int32 i = 0;
	/*
	for (i = 0; i < Components.Num(); i++)
	{
		if (Cast<UGUIButton>(Components[i]) == nullptr)
		{
		}
		if (SizingButton == nullptr || Len(Cast<UGUIButton>(Components[i]).Caption) > Len(SizingButton.Caption))
		{
			SizingButton = Cast<UGUIButton>(Components[i]);
		}
	}
	*/
}

bool UAAIRC_Panel::PositionButtons(UCanvas* C)
{
	float X = 0;
	float XL = 0;
	float YL = 0;
	/*
	SizingButton.Style.TextSize(C, SizingButton.MenuState, SizingButton.Caption, XL, YL, SizingButton.FontScale);
	XL += 14;
	X = b_Connect.ActualLeft();
	b_Connect.WinWidth = b_Connect.RelativeWidth(XL);
	b_JoinChannel.WinWidth = b_JoinChannel.RelativeWidth(XL);
	b_RemServer.WinLeft = b_RemServer.RelativeLeft(X + XL + XL * 0.1);
	b_RemServer.WinWidth = b_RemServer.RelativeWidth(XL);
	b_RemChannel.WinLeft = b_RemChannel.RelativeLeft(X + XL + XL * 0.1);
	b_RemChannel.WinWidth = b_RemChannel.RelativeWidth(XL);
	*/
	return false;
}

void UAAIRC_Panel::InternalOnChange(UGUIComponent* Sender)
{
	if (Sender == co_Server)
	{
		UpdateConnectionStatus(IsCurrentServer(co_Server->GetText()));
	}
}

bool UAAIRC_Panel::InternalOnClick(UGUIComponent* Sender)
{
	FString str = "";
	/*
	switch(Sender)
	{
			case b_Connect:
				if (IsCurrentServer(co_Server.GetText()))
				{
					tp_System.Disconnect();
					break;
				}
				tp_System.Connect(co_Server.GetText());
				if (tp_System.IsConnected())
				{
					str = co_Server.GetText();
					AddServerToHistory(str);
				}
	}
	GOTO JL0130;
		case b_JoinChannel:
			if (!tp_System.IsConnected())
			{
				return false;
			}
			str = co_Channel.GetText();
			if (str != "")
			{
				tp_System.JoinChannel(str);
				AddChannelToHistory(str);
			}
			GOTO JL0130;
		case b_RemServer:
			RemoveServerFromHistory(co_Server.GetText());
			GOTO JL0130;
		case b_RemChannel:
			RemoveChannelFromHistory(co_Channel.GetText());
			GOTO JL0130;
		default:
		JL0130:
			return true;
	*/
	return false;    //FAKE    /ELiZ
}

void UAAIRC_Panel::UpdateConnectionStatus(bool NowConnected)
{
	if (NowConnected)
	{
		b_Connect->Caption = DisconnectText;
	}
	else
	{
		b_Connect->Caption = ConnectText;
	}
}

bool UAAIRC_Panel::AddChannelToHistory(FString NewChannelName,int32 Position)
{
	if (NewChannelName == "")
	{
		return false;
	}
	/*
	if (Left(NewChannelName, 1) != "#")
	{
		NewChannelName = "#" + NewChannelName;
	}
	RemoveChannelFromHistory(NewChannelName);
	if (Position < 0 || Position >= ChannelHistory.Num())
	{
		Position = ChannelHistory.Num();
	}
	ChannelHistory.insert(Position, 1);
	ChannelHistory[Position] = NewChannelName;
	co_Channel.MyComboBox.List.Insert(Position, NewChannelName);
	co_Channel.Find(NewChannelName);
	bDirty = true;
	*/
	return true;
}

bool UAAIRC_Panel::RemoveChannelFromHistory(FString ChannelName)
{
	/*
	int32 i = 0;
	if (Left(ChannelName, 1) != "#")
	{
		ChannelName = "#" + ChannelName;
	}
	i = FindChannelHistoryIndex(ChannelName);
	if (i != -1)
	{
		ChannelHistory.RemoveAt(i, 1);
		co_Channel.RemoveItem(i, 1);
		bDirty = true;
		return true;
	}
	*/
	return false;
}

bool UAAIRC_Panel::AddServerToHistory(FString NewServerName,int32 Position)
{
	/*
	if (NewServerName == "")
	{
		return false;
	}
	RemoveServerFromHistory(NewServerName);
	if (Position < 0 || Position >= ServerHistory.Num())
	{
		Position = ServerHistory.Num();
	}
	ServerHistory.insert(Position, 1);
	ServerHistory[Position] = NewServerName;
	co_Server.MyComboBox.List.Insert(Position, NewServerName);
	co_Server.Find(NewServerName);
	bDirty = true;
	*/
	return true;
}

bool UAAIRC_Panel::RemoveServerFromHistory(FString ServerName)
{
	/*
	int32 i = 0;
	if (ServerName == "")
	{
		return false;
	}
	i = FindServerHistoryIndex(ServerName);
	if (i != -1)
	{
		ServerHistory.RemoveAt(i, 1);
		co_Server.RemoveItem(i, 1);
		bDirty = true;
		return true;
	}
	*/
	return false;
}

int32 UAAIRC_Panel::FindServerHistoryIndex(FString ServerName)
{
	/*
	int32 i = 0;
	for (i = 0; i < ServerHistory.Num(); i++)
	{
		if (ServerHistory[i] ~= ServerName)
		{
			return i;
		}
	}
	*/
	return -1;
}

int32 UAAIRC_Panel::FindChannelHistoryIndex(FString ChannelName)
{
	/*
	int32 i = 0;
	for (i = 0; i < ChannelHistory.Num(); i++)
	{
		if (ChannelHistory[i] ~= ChannelName)
		{
			return i;
		}
	}
	*/
	return -1;
}

bool UAAIRC_Panel::IsCurrentServer(FString ServerAddress)
{
	/*
	if (tp_System == nullptr || !tp_System.IsConnected() || tp_System.link == nullptr || tp_System.link.ServerAddress == "" || ServerAddress == "")
	{
		return false;
	}
	return InStr(ServerAddress, tp_System.link.ServerAddress) != -1;
	*/
	return false;   //FAKE    /ELiZ
}

void UAAIRC_Panel::Free()
{
	/*
	Super::Free();
	if (bDirty)
	{
		SaveConfig();
	}
	*/
}
