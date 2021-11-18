// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_Channel/IRC_Private/IRC_Private.h"

UIRC_Private::UIRC_Private()
{

}

void UIRC_Private::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	GUISplitter(Controls[1]).SplitOrientation = 1;
	GUISplitter(Controls[1]).SplitPosition = 1;
	GUISplitter(Controls[1]).bFixedSplitter = true;
	GUISplitter(Controls[1]).bDrawSplitter = false;
	*/
}

void UIRC_Private::ProcessInput(FString Text)
{
	/*
	if (Left(Text, 4) ~= "/me ")
	{
		PrivateAction(SystemPage.NickName, Mid(Text, 4));
		SystemPage.link.SendChannelAction(ChannelName, Mid(Text, 4));
	}
	else
	{
		if (Left(Text, 1) == "/")
		{
			SystemPage.link.SendCommandText(Mid(Text, 1));
		}
		else
		{
			if (Text != "")
			{
				PrivateText(SystemPage.NickName, Text);
				SystemPage.link.SendChannelText(ChannelName, Text);
			}
		}
	}
	*/
}

void UIRC_Private::ChangedNick(FString OldNick, FString NewNick)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCInfoColor) $ "*** " $ OldNick @ NowKnownAsText @ NewNick $ ".");
	ChannelName = NewNick;
	MyButton.Caption = NewNick;
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	else
	{
		SystemPage.IRCPage.LeaveButton.Caption = SystemPage.IRCPage.LeavePrivateCaptionHead $ Caps(NewNick) $ SystemPage.IRCPage.LeavePrivateCaptionTail;
	}
	*/
}

void UIRC_Private::UserQuit(FString Nick, FString Reason)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCInfoColor) $ "*** " $ Nick @ QuitText @ "(" $ Reason $ ").");
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Private::PrivateText(FString Nick, FString Text)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCNickColor) $ "<" $ Nick $ "> " $ MakeColorCode(IRCTextColor) $ ColorizeLinks(Text));
	if (SystemPage.InGame())
	{
		PlayerOwner().ClientMessage("IRC: <" $ Nick $ "> " $ Text);
	}
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Private::PrivateAction(FString Nick, FString Text)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCActionColor) $ "* " $ Nick $ " " $ Text);
	if (SystemPage.InGame())
	{
		PlayerOwner().ClientMessage("IRC: * " $ Nick $ " " $ Text);
	}
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Private::IsAway(FString Nick, FString Message)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCInfoColor) $ Nick @ SystemPage.IsAwayText $ ": " $ ColorizeLinks(Message));
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}