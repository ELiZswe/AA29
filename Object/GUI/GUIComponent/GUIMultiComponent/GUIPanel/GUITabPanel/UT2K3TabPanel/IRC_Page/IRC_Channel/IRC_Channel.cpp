// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_Channel/IRC_Channel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"

UIRC_Channel::UIRC_Channel()
{
	UGUIListBox* MyUserListBox = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	MyUserListBox->bVisibleWhenEmpty=true;
	//MyUserListBox->OnCreateComponent=MyUserListBox.InternalOnCreateComponent;
	MyUserListBox->StyleName="ServerBrowserGrid";
	MyUserListBox->WinHeight=1;
	MyUserListBox->bScaleToParent=true;

	UserListBox = MyUserListBox;
}

void UIRC_Channel::UserSetFlag(int32 i, FString flag, bool bSet)
{
	/*
	FString Flags = "";
	int32 FlagPos = 0;
	Flags = UserListBox.List.GetExtraAtIndex(i);
	if (bSet)
	{
		if (InStr(Flags, flag) != -1)
		{
			return;
		}
		UserListBox.List.SetExtraAtIndex(i, Flags $ flag);
	}
	else
	{
		FlagPos = InStr(Flags, flag);
		if (FlagPos == -1)
		{
			return;
		}
		Flags = Left(Flags, FlagPos) $ Mid(Flags, (FlagPos + 1));
		UserListBox.List.SetExtraAtIndex(i, Flags);
	}
	*/
}

void UIRC_Channel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local GUIPanel UtilPanel;
	GUISplitter(Controls[1]).SplitOrientation = 1;
	GUISplitter(Controls[1]).SplitPosition = 0.75;
	GUISplitter(Controls[1]).bFixedSplitter = false;
	UtilPanel = GUIPanel(GUISplitter(Controls[1]).Controls[1]);
	UtilPanel.Controls[0] = UserListBox;
	Super::InitComponent(MyController, MyOwner);
	UserListBox.List.__OnDrawItem__Delegate = MyOnDrawItem;
	UserListBox.List.__CompareItem__Delegate = MyCompareItem;
	UserListBox.List.__OnDblClick__Delegate = MyListDblClick;
	UserListBox.__OnPreDraw__Delegate = MyOnPreDraw;
	*/
}

bool UIRC_Channel::MyOnPreDraw(UCanvas* C)
{
	/*
	if (bUsersNeedSorting)
	{
		UserListBox.List.SortList();
		bUsersNeedSorting = false;
	}
	*/
	return true;
}

bool UIRC_Channel::MyListDblClick(UGUIComponent* Sender)
{
	/*
	FString UserName = "";
	UserName = UserListBox.List.Get();
	if (UserName == "")
	{
		return true;
	}
	SystemPage.CreatePrivChannel(UserName, true);
	*/
	return true;
}

int32 UIRC_Channel::MyCompareItem(FGUIListElem ElemA, FGUIListElem ElemB)
{
	/*
	FString s1 = "";
	FString s2 = "";
	if (InStr(ElemA.ExtraStrData, "o") != -1)
	{
		s1 = "   " $ ElemA.Item;
	}
	else
	{
		if (InStr(ElemA.ExtraStrData, "h") != -1)
		{
			s1 = "  " $ ElemA.Item;
		}
		else
		{
			if (InStr(ElemA.ExtraStrData, "v") != -1)
			{
				s1 = " " $ ElemA.Item;
			}
			else
			{
				s1 = ElemA.Item;
			}
		}
	}
	if (InStr(ElemB.ExtraStrData, "o") != -1)
	{
		s2 = "   " $ ElemB.Item;
	}
	else
	{
		if (InStr(ElemB.ExtraStrData, "h") != -1)
		{
			s2 = "  " $ ElemB.Item;
		}
		else
		{
			if (InStr(ElemB.ExtraStrData, "v") != -1)
			{
				s2 = " " $ ElemB.Item;
			}
			else
			{
				s2 = ElemB.Item;
			}
		}
	}
	s1 = Caps(s1);
	s2 = Caps(s2);
	if (s1 > s2)
	{
		return 1;
	}
	else
	{
		if (s1 < s2)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
	*/
	return 0;    //FAKE   /ELiZ
}

void UIRC_Channel::MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	FString DrawName = "";
	FString NickName = "";
	FString Flags = "";
	NickName = UserListBox.List.getItemAtIndex(i);
	Flags = UserListBox.List.GetExtraAtIndex(i);
	if (InStr(Flags, "o") != -1)
	{
		DrawName = "@" $ NickName;
	}
	else
	{
		if (InStr(Flags, "h") != -1)
		{
			DrawName = "%" $ NickName;
		}
		else
		{
			if (InStr(Flags, "v") != -1)
			{
				DrawName = "+" $ NickName;
			}
			else
			{
				DrawName = NickName;
			}
		}
	}
	UserListBox.Style.DrawText(Canvas, 0, X, Y, W, H, 0, DrawName, UserListBox.FontScale);
	*/
}

int32 UIRC_Channel::GetUser(FString Nick)
{
	/*
	int32 i = 0;
	for (i = 0; i < UserListBox.List.ItemCount; i++)
	{
		if (UserListBox.List.getItemAtIndex(i) ~= Nick)
		{
			return i;
		}
	}
	*/
	return -1;
}

bool UIRC_Channel::FindNick(FString Nick)
{
	/*
	if (GetUser(Nick) > -1)
	{
		return true;
	}
	*/
	return false;
}

void UIRC_Channel::AddUser(FString Nick)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i > -1)
	{
		return;
	}
	UserListBox.List.Add(Nick);
	bUsersNeedSorting = true;
	*/
}

void UIRC_Channel::RemoveUser(FString Nick)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i < 0)
	{
		return;
	}
	UserListBox.List.RemoveItem(Nick);
	bUsersNeedSorting = true;
	*/
}

void UIRC_Channel::ChangeNick(FString OldNick, FString NewNick)
{
	/*
	int32 i = 0;
	i = GetUser(OldNick);
	if (i < 0)
	{
		return;
	}
	UserListBox.List.SetItemAtIndex(i, NewNick);
	*/
}

void UIRC_Channel::ChangeOp(FString Nick, bool NewOp)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i < 0)
	{
		return;
	}
	UserSetFlag(i, "o", NewOp);
	bUsersNeedSorting = true;
	*/
}

void UIRC_Channel::ChangeHalfOp(FString Nick, bool NewHalfOp)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i < 0)
	{
		return;
	}
	UserSetFlag(i, "h", NewHalfOp);
	bUsersNeedSorting = true;
	*/
}

void UIRC_Channel::ChangeVoice(FString Nick, bool NewVoice)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i < 0)
	{
		return;
	}
	UserSetFlag(i, "v", NewVoice);
	bUsersNeedSorting = true;
	*/
}

void UIRC_Channel::ChangeTopic(FString NewTopic)
{
	/*
	ChannelTopic = NewTopic;
	TextDisplay.AddText(MakeColorCode(IRCInfoColor) $ "*** " $ NewTopicText $ ": " $ NewTopic);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Channel::ChannelText(FString Nick, FString Text)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCNickColor) $ "<" $ Nick $ "> " $ MakeColorCode(IRCTextColor) $ ColorizeLinks(Text));
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Channel::ChannelAction(FString Nick, FString Text)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCActionColor) $ "* " $ Nick $ " " $ Text);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Channel::UserNotice(FString Nick, FString Text)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCActionColor) $ "-" $ Nick $ "- " $ Text);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Channel::ProcessInput(FString Text)
{
	/*
	if (Left(Text, 4) ~= "/me ")
	{
		ChannelAction(SystemPage.NickName, Mid(Text, 4));
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
				ChannelText(SystemPage.NickName, Text);
				SystemPage.link.SendChannelText(ChannelName, Text);
			}
		}
	}
	*/
}

void UIRC_Channel::PartedChannel(FString Nick)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCInfoColor) $ "*** " $ Nick @ HasLeftText @ ChannelName $ ".");
	RemoveUser(Nick);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Channel::JoinedChannel(FString Nick)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCInfoColor) $ "*** " $ Nick @ HasJoinedText @ ChannelName $ ".");
	AddUser(Nick);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Channel::KickUser(FString KickedNick, FString Kicker, FString Reason)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCInfoColor) $ "*** " $ KickedNick @ WasKickedByText @ Kicker $ " (" $ Reason $ ")");
	RemoveUser(KickedNick);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Channel::UserInChannel(FString Nick)
{
	//AddUser(Nick);
}

void UIRC_Channel::ChangedNick(FString OldNick, FString NewNick)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCInfoColor) $ "*** " $ OldNick @ NowKnownAsText @ NewNick $ ".");
	ChangeNick(OldNick, NewNick);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Channel::UserQuit(FString Nick, FString Reason)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCInfoColor) $ "*** " $ Nick @ QuitText @ "(" $ Reason $ ").");
	RemoveUser(Nick);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UIRC_Channel::ChangeMode(FString Nick, FString Mode)
{
	/*
	TextDisplay.AddText(MakeColorCode(IRCInfoColor) $ "*** " $ Nick @ SetsModeText $ ": " $ Mode);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}