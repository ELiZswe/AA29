// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_Channel/AAIRC_Private/AAIRC_Private.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UAAIRC_Private::UAAIRC_Private()
{
	UGUIButton* IRCLeave = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IRCLeave->Caption = "CLOSE PM";
	IRCLeave->StyleName = "SquareMenuButton";
	IRCLeave->WinTop = 0.83;
	IRCLeave->WinLeft = 0.59;
	IRCLeave->WinWidth = 0.16;
	IRCLeave->WinHeight = 0.036;
	IRCLeave->RenderWeight = 2;
	IRCLeave->TabOrder = 2;
	IRCLeave->bBoundToParent = true;
	//IRCLeave->OnClick=AAIRC_Private.InternalOnClick;
	//IRCLeave->OnKeyEvent=IRCLeave.InternalOnKeyEvent;
	b_Leave = IRCLeave;
}

void UAAIRC_Private::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super:InitComponent(MyController, MyOwner);
	sp_Main.SplitPosition = 1;
	sp_Main.__OnReleaseSplitter__Delegate = nullptr;
	sp_Main.__OnLoadINI__Delegate = nullptr;
	sp_Main.bFixedSplitter = true;
	sp_Main.bDrawSplitter = false;
	*/
}

void UAAIRC_Private::ProcessInput(FString Text)
{
	/*
	if (Left(Text, 4) ~= "/me ")
	{
		PrivateAction(tp_System.NickName, Mid(Text, 4));
		tp_System.link.SendChannelAction(ChannelName, Mid(Text, 4));
	}
	else
	{
		if (Left(Text, 1) == "/")
		{
			tp_System.link.SendCommandText(Mid(Text, 1));
		}
		else
		{
			if (Text != "")
			{
				PrivateText(tp_System.NickName, Text);
				tp_System.link.SendChannelText(ChannelName, Text);
			}
		}
	}
	*/
}

void UAAIRC_Private::PrivateText(FString Nick, FString Text)
{
	/*
	if (MyButton.bActive && bIRCTextToSpeechEnabled)
	{
		PlayerOwner().TextToSpeech(StripColorCodes(Text), 1);
	}
	InterpretColorCodes(Text);
	lb_TextDisplay.AddText(MakeColorCode(IRCNickColor) $ "<" $ Nick $ "> " $ MakeColorCode(IRCTextColor) $ ColorizeLinks(Text));
	if (tp_System.InGame())
	{
		PlayerOwner().ClientMessage("IRC: <" $ Nick $ "> " $ Text);
	}
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Private::PrivateAction(FString Nick, FString Text)
{
	/*
	InterpretColorCodes(Text);
	lb_TextDisplay.AddText(MakeColorCode(IRCActionColor) $ "* " $ Nick $ " " $ Text);
	if (tp_System.InGame())
	{
		PlayerOwner().ClientMessage("IRC: * " $ Nick $ " " $ Text);
	}
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Private::PrintAwayMessage(FString Nick, FString Message)
{
	/*
	InterpretColorCodes(Message);
	lb_TextDisplay.AddText(MakeColorCode(IRCInfoColor) $ Nick @ tp_System.IsAwayText $ ": " $ ColorizeLinks(Message));
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

int32 UAAIRC_Private::GetUser(FString Nick)
{
	/*
	if (Nick ~= ChannelName)
	{
		return 0;
	}
	*/
	return -1;
}

bool UAAIRC_Private::FindNick(FString Nick)
{
	/*
	if (Nick ~= ChannelName)
	{
		return true;
	}
	*/
	return false;
}

void UAAIRC_Private::AddUser(FString Nick)
{
}

void UAAIRC_Private::RemoveUser(FString Nick)
{
}

void UAAIRC_Private::ChangeNick(FString OldNick, FString NewNick)
{
	/*
	if (OldNick ~= ChannelName)
	{
		ChannelName = NewNick;
		MyButton.Caption = NewNick;
	}
	*/
}

void UAAIRC_Private::ChangeOwner(FString Nick, bool NewOwner)
{
}

void UAAIRC_Private::ChangeProtected(FString Nick, bool NewProtected)
{
}

void UAAIRC_Private::ChangeOp(FString Nick, bool NewOp)
{
}

void UAAIRC_Private::ChangeHalfOp(FString Nick, bool NewHalfOp)
{
}

void UAAIRC_Private::ChangeVoice(FString Nick, bool NewVoice)
{
}

bool UAAIRC_Private::ContextMenuOpen(UGUIContextMenu* Sender)
{
	return false;
}
