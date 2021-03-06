// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_Channel/AAIRC_Channel.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_System/AAIRC_System.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "Engine/Canvas.h"

UAAIRC_Channel::UAAIRC_Channel()
{
	UGUIButton* IRCLeave = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IRCLeave->Caption = "LEAVE";
	IRCLeave->StyleName = "SquareMenuButton";
	IRCLeave->WinTop = 0.83;
	IRCLeave->WinLeft = 0.59;
	IRCLeave->WinWidth = 0.16;
	IRCLeave->WinHeight = 0.036;
	IRCLeave->RenderWeight = 2;
	IRCLeave->TabOrder = 2;
	IRCLeave->bBoundToParent = true;
	//IRCLeave->OnClick=AAIRC_Channel.InternalOnClick;
	//IRCLeave->OnKeyEvent=IRCLeave.InternalOnKeyEvent;
	UGUIButton* IRCDisconnect = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IRCDisconnect->Caption = "DISCONNECT";
	IRCDisconnect->StyleName = "SquareMenuButton";
	IRCDisconnect->WinTop = 0.83;
	IRCDisconnect->WinLeft = 0.8;
	IRCDisconnect->WinWidth = 0.16;
	IRCDisconnect->WinHeight = 0.036;
	IRCDisconnect->RenderWeight = 2;
	IRCDisconnect->TabOrder = 1;
	IRCDisconnect->bBoundToParent = true;
	//IRCDisconnect->OnClick=AAIRC_Channel.InternalOnClick;
	//IRCDisconnect->OnKeyEvent=IRCDisconnect.InternalOnKeyEvent;
	UGUISplitter* SplitterA = NewObject<UGUISplitter>(UGUISplitter::StaticClass());
	SplitterA->SplitOrientation = EGUISplitterType::SPLIT_Horizontal;
	SplitterA->SplitPosition = 0.75;
	SplitterA->DefaultPanels = {
		"XInterface.GUIScrollTextBox",
		"XInterface.GUIListBox"
	};
	//SplitterA->OnReleaseSplitter = AAIRC_Channel.InternalOnReleaseSplitter;
	//SplitterA->OnCreateComponent=AAIRC_Channel.InternalOnCreateComponent;
	SplitterA->IniOption = "@Internal";
	SplitterA->WinHeight = 0.81;
	//SplitterA->OnLoadINI=AAIRC_Channel.InternalOnLoadINI;
	UGUIContextMenu* RCMenu = NewObject<UGUIContextMenu>(UGUIContextMenu::StaticClass());
	//RCMenu->OnOpen=AAIRC_Channel.ContextMenuOpen;
	//RCMenu->OnSelect=AAIRC_Channel.ContextMenuClick;
	b_Disconnect = IRCDisconnect;
	b_Leave = IRCLeave;

	OpUserText = "Make Op";
	HelpUserText = "Make Helper";
	VoiceUserText = "Make Voice";
	ReasonText = "Reason: ";
	MessageUserText = "Send PM";
	WhoisUserText = "Whois";
	DeopUserText = "Remove Op";
	DehelpUserText = "Remove Helper";
	DevoiceUserText = "Remove Voice";
	KickUserText = "Kick User";
	sp_Main = SplitterA;
	MainSplitterPosition = 0.75;
	ContextMenu = RCMenu;
}

void UAAIRC_Channel::ProcessInput(FString Text)
{
	/*
	if (Left(Text, 4) ~= "/me ")
	{
		ChannelAction(tp_System.NickName, Mid(Text, 4));
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
				ChannelText(tp_System.NickName, Text);
				if (Left(ChannelName, 1) != "#")
				{
					ChannelName = "#" + ChannelName;
				}
				tp_System.link.SendChannelText(ChannelName, Text);
			}
		}
	}
	*/
}

void UAAIRC_Channel::Whois(FString Nick)
{
	/*
	if (tp_System == nullptr)
	{
		return;
	}
	tp_System.Whois(Nick);
	*/
}

void UAAIRC_Channel::Op(FString Nick)
{
	/*
	if (tp_System == nullptr)
	{
		return;
	}
	tp_System.Op(Nick, ChannelName);
	*/
}

void UAAIRC_Channel::Deop(FString Nick)
{
	/*
	if (tp_System == nullptr)
	{
		return;
	}
	tp_System.Deop(Nick, ChannelName);
	*/
}

void UAAIRC_Channel::Voice(FString Nick)
{
	/*
	if (tp_System == nullptr)
	{
		return;
	}
	tp_System.Voice(Nick, ChannelName);
	*/
}

void UAAIRC_Channel::DeVoice(FString Nick)
{
	/*
	if (tp_System == nullptr)
	{
		return;
	}
	tp_System.DeVoice(Nick, ChannelName);
	*/
}

void UAAIRC_Channel::Help(FString Nick)
{
	/*
	if (tp_System == nullptr)
	{
		return;
	}
	tp_System.Help(Nick, ChannelName);
	*/
}

void UAAIRC_Channel::DeHelp(FString Nick)
{
	/*
	if (tp_System == nullptr)
	{
		return;
	}
	tp_System.DeHelp(Nick, ChannelName);
	*/
}

void UAAIRC_Channel::Kick(FString Nick, FString Reason)
{
	/*
	if (tp_System == nullptr)
	{
		return;
	}
	tp_System.Kick(Nick, ChannelName, Reason);
	*/
}

void UAAIRC_Channel::Ban(FString Nick, FString Reason)
{
	/*
	if (tp_System == nullptr)
	{
		return;
	}
	tp_System.Ban(Nick, ChannelName, Reason);
	*/
}

void UAAIRC_Channel::Unban(FString Nick)
{
	/*
	if (tp_System == nullptr)
	{
		return;
	}
	tp_System.Unban(Nick, ChannelName);
	*/
}

void UAAIRC_Channel::UserInChannel(FString Nick)
{
	/*
	AddUser(Nick);
	*/
}

void UAAIRC_Channel::AddUser(FString Nick)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i > -1)
	{
		return;
	}
	lb_User.List.Add(Nick);
	*/
}

void UAAIRC_Channel::RemoveUser(FString Nick)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i < 0)
	{
		return;
	}
	lb_User.List.RemoveItem(Nick);
	*/
}

void UAAIRC_Channel::ChangeOwner(FString Nick, bool NewOwner)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i < 0)
	{
		return;
	}
	UserSetFlag(i, "q", NewOwner);
	lb_User.List.Sort();
	*/
}

void UAAIRC_Channel::ChangeProtected(FString Nick, bool NewProtected)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i < 0)
	{
		return;
	}
	UserSetFlag(i, "a", NewProtected);
	lb_User.List.Sort();
	*/
}

void UAAIRC_Channel::ChangeOp(FString Nick, bool NewOp)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i < 0)
	{
		return;
	}
	UserSetFlag(i, "o", NewOp);
	lb_User.List.Sort();
	*/
}

void UAAIRC_Channel::ChangeHalfOp(FString Nick, bool NewHalfOp)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i < 0)
	{
		return;
	}
	UserSetFlag(i, "h", NewHalfOp);
	lb_User.List.Sort();
	*/
}

void UAAIRC_Channel::ChangeVoice(FString Nick, bool NewVoice)
{
	/*
	int32 i = 0;
	i = GetUser(Nick);
	if (i < 0)
	{
		return;
	}
	UserSetFlag(i, "v", NewVoice);
	lb_User.List.Sort();
	*/
}

void UAAIRC_Channel::ChangedNick(FString OldNick, FString NewNick)
{
	FString S = "";
	/*
	S = MakeColorCode(IRCInfoColor);
	(S += Repl(NowKnownAsText, "%OldName%", OldNick));
	S = Repl(S, "%NewName%", NewNick);
	lb_TextDisplay.AddText(S);
	ChangeNick(OldNick, NewNick);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Channel::ChangeTopic(FString NewTopic)
{
	/*
	ChannelTopic = NewTopic;
	InterpretColorCodes(NewTopic);
	lb_TextDisplay.AddText(MakeColorCode(IRCInfoColor) + "*** " + NewTopicText + ": " + NewTopic);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Channel::ChannelText(FString Nick, FString Text)
{
	/*
	if (MyButton.bActive && bIRCTextToSpeechEnabled)
	{
		PlayerOwner().TextToSpeech(StripColorCodes(Text), 1);
	}
	InterpretColorCodes(Text);
	lb_TextDisplay.AddText(MakeColorCode(IRCNickColor) + "<" + Nick + "> " + MakeColorCode(IRCTextColor) + ColorizeLinks(Text));
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Channel::ChannelAction(FString Nick, FString Text)
{
	/*
	InterpretColorCodes(Text);
	lb_TextDisplay.AddText(MakeColorCode(IRCActionColor) + "* " + Nick + " " + Text);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Channel::UserNotice(FString Nick, FString Text)
{
	/*
	InterpretColorCodes(Text);
	lb_TextDisplay.AddText(MakeColorCode(IRCActionColor) + "-" + Nick + "- " + Text);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Channel::JoinedChannel(FString Nick)
{
	FString S = "";
	/*
	S = MakeColorCode(IRCInfoColor);
	(S += Repl(HasJoinedText, "%Name%", Nick));
	S = Repl(S, "%Chan%", ChannelName);
	InterpretColorCodes(Nick);
	lb_TextDisplay.AddText(S);
	AddUser(Nick);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Channel::PartedChannel(FString Nick)
{
	FString S = "";
	/*
	S = MakeColorCode(IRCInfoColor);
	(S += Repl(HasLeftText, "%Name%", Nick));
	S = Repl(S, "%Chan%", ChannelName);
	InterpretColorCodes(Nick);
	lb_TextDisplay.AddText(S);
	RemoveUser(Nick);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Channel::KickUser(FString KickedNick, FString Kicker, FString Reason)
{
	FString S = "";
	/*
	S = MakeColorCode(IRCInfoColor);
	(S += Repl(WasKickedByText, "%Kicked%", KickedNick));
	S = Repl(S, "%Kicker%", Kicker);
	S = Repl(S, "%Reason%", Reason);
	InterpretColorCodes(Reason);
	lb_TextDisplay.AddText(S);
	RemoveUser(KickedNick);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Channel::UserQuit(FString Nick, FString Reason)
{
	FString S = "";
	/*
	S = MakeColorCode(IRCInfoColor);
	(S += Repl(QuitText, "%Name%", Nick));
	S = Repl(S, "%Reason%", Reason);
	InterpretColorCodes(Reason);
	lb_TextDisplay.AddText(S);
	RemoveUser(Nick);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Channel::ChangeMode(FString Nick, FString Mode)
{
	FString S = "";
	/*
	S = MakeColorCode(IRCInfoColor);
	(S += Repl(SetsModeText, "%Name%", Nick));
	S = Repl(S, "%Mode%", Mode);
	lb_TextDisplay.AddText(S);
	if (!MyButton.bActive)
	{
		MyButton.bForceFlash = true;
	}
	*/
}

void UAAIRC_Channel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	if (lb_User != nullptr)
	{
		lb_User->List->bSorted = true;
		//lb_User.List.__OnDrawItem__Delegate = MyOnDrawItem;
		//lb_User.List.__CompareItem__Delegate = MyCompareItem;
		//lb_User.List.__OnDblClick__Delegate = MyListDblClick;
	}
}

void UAAIRC_Channel::ShowPanel(bool bShow)
{
	/*
	Super:ShowPanel(bShow);
	if (bShow && bInit)
	{
		sp_Main.SplitterUpdatePositions();
		bInit = false;
	}
	*/
}

void UAAIRC_Channel::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (Cast<UGUIListBox>(NewComp) != nullptr)
	{
		lb_User = Cast<UGUIListBox>(NewComp);
		lb_User.FillOwner();
	}
	else
	{
		Super:InternalOnCreateComponent(NewComp, Sender);
	}
	*/
}

void UAAIRC_Channel::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	if (Sender == sp_Main)
	{
		sp_Main.SplitPosition = MainSplitterPosition;
	}
	*/
}

void UAAIRC_Channel::InternalOnReleaseSplitter(UGUIComponent* Sender, float NewPos)
{
	/*
	if (Sender == sp_Main)
	{
		MainSplitterPosition = NewPos;
		SaveConfig();
	}
	*/
}

bool UAAIRC_Channel::MyListDblClick(UGUIComponent* Sender)
{
	FString UserName = "";
	/*
	UserName = lb_User.List.Get();
	if (UserName == "")
	{
		return true;
	}
	tp_System.AddChannel(UserName, true, true);
	*/
	return true;
}

int32 UAAIRC_Channel::MyCompareItem(FGUIListElem ElemA, FGUIListElem ElemB)
{
	FString s1 = "";
	FString s2 = "";
	/*
	if (InStr(ElemA.ExtraStrData, "q") != -1)
	{
		s1 = "     " + ElemA.Item;
	}
	else
	{
		if (InStr(ElemA.ExtraStrData, "a") != -1)
		{
			s1 = "    " + ElemA.Item;
		}
		else
		{
			if (InStr(ElemA.ExtraStrData, "o") != -1)
			{
				s1 = "   " + ElemA.Item;
			}
			else
			{
				if (InStr(ElemA.ExtraStrData, "h") != -1)
				{
					s1 = "  " + ElemA.Item;
				}
				else
				{
					if (InStr(ElemA.ExtraStrData, "v") != -1)
					{
						s1 = " " + ElemA.Item;
					}
					else
					{
						s1 = ElemA.Item;
					}
				}
			}
		}
	}
	if (InStr(ElemB.ExtraStrData, "q") != -1)
	{
		s2 = "     " + ElemB.Item;
	}
	else
	{
		if (InStr(ElemB.ExtraStrData, "a") != -1)
		{
			s2 = "    " + ElemB.Item;
		}
		else
		{
			if (InStr(ElemB.ExtraStrData, "o") != -1)
			{
				s2 = "   " + ElemB.Item;
			}
			else
			{
				if (InStr(ElemB.ExtraStrData, "h") != -1)
				{
					s2 = "  " + ElemB.Item;
				}
				else
				{
					if (InStr(ElemB.ExtraStrData, "v") != -1)
					{
						s2 = " " + ElemB.Item;
					}
					else
					{
						s2 = ElemB.Item;
					}
				}
			}
		}
	}
	s1 = Caps(s1);
	s2 = Caps(s2);
	return StrCmp(s1, s2);
	*/
	return 0;    //FAKE   /ELiZ
}

void UAAIRC_Channel::MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	FString DrawName = "";
	FString NickName = "";
	FString Flags = "";
	UGUIStyles* S = nullptr;
	/*
	if (lb_User.List.Style == nullptr)
	{
		return;
	}
	NickName = lb_User.List.getItemAtIndex(i);
	Flags = lb_User.List.GetExtraAtIndex(i);
	if (InStr(Flags, "q") != -1)
	{
		DrawName = "~" + NickName;
	}
	else
	{
		if (InStr(Flags, "a") != -1)
		{
			DrawName = "&" + NickName;
		}
		else
		{
			if (InStr(Flags, "o") != -1)
			{
				DrawName = "@" + NickName;
			}
			else
			{
				if (InStr(Flags, "h") != -1)
				{
					DrawName = "%" + NickName;
				}
				else
				{
					if (InStr(Flags, "v") != -1)
					{
						DrawName = "+" + NickName;
					}
					else
					{
						DrawName = NickName;
					}
				}
			}
		}
	}
	if (bSelected && (lb_User.List.SelectedStyle != nullptr))
	{
		S = lb_User.List.SelectedStyle;
		S.Draw(Canvas, lb_User.List.MenuState, X, Y, W, H);
	}
	else
	{
		S = lb_User.List.Style;
	}
	S.DrawText(Canvas, 0, X, Y, W, H, 0, DrawName, lb_User.FontScale);
	*/
}

int32 UAAIRC_Channel::GetUser(FString Nick)
{
	return lb_User->List->FindIndex(Nick,false,false,nullptr);
}

FString UAAIRC_Channel::GetFlags(FString NickName)
{
	int32 i = 0;
	i = GetUser(NickName);
	if (i != -1)
	{
		return lb_User->List->GetExtraAtIndex(i);
	}
	return "";
}

bool UAAIRC_Channel::FindNick(FString Nick)
{
	if (GetUser(Nick) > -1)
	{
		return true;
	}
	return false;
}

bool UAAIRC_Channel::UserIsOp(FString NickName)
{
	//return (InStr(GetFlags(NickName), "o") != -1);
	return false;     //FAKE   /ELiZ
}

bool UAAIRC_Channel::UserIsHelper(FString NickName)
{
	//return (InStr(GetFlags(NickName), "h") != -1);
	return false;     //FAKE   /ELiZ
}

bool UAAIRC_Channel::UserIsVoice(FString NickName)
{
	//return (InStr(GetFlags(NickName), "v") != -1);
	return false;     //FAKE   /ELiZ
}

void UAAIRC_Channel::ChangeNick(FString OldNick, FString NewNick)
{
	int32 i = 0;
	i = GetUser(OldNick);
	if (i < 0)
	{
		return;
	}
	lb_User->List->SetItemAtIndex(i, NewNick);
	lb_User->List->Sort();
}

void UAAIRC_Channel::UserSetFlag(int32 i, FString flag, bool bSet)
{
	FString Flags = "";
	FString S = "";
	int32 FlagPos = 0;
	Flags = lb_User->List->GetExtraAtIndex(i);
	/*
	S = Left(flag, 1);
	if (S != "")
	{
		if (bSet)
		{
			if (InStr(Flags, S) != -1)
			{
				return;
			}
			lb_User.List.SetExtraAtIndex(i, Flags + S);
		}
		else
		{
			FlagPos = InStr(Flags, S);
			if (FlagPos == -1)
			{
				return;
			}
			Flags = Repl(Flags, S, "");
			lb_User.List.SetExtraAtIndex(i, Flags);
		}
		S = Mid(S, 1);
	}
	*/
}

bool UAAIRC_Channel::ContextMenuOpen(UGUIContextMenu* Sender)
{
	FString SelectedNick = "";
	/*
	if (Sender.ContextItems.Num() > 0)
	{
		Sender.ContextItems.RemoveAt(0, Sender.ContextItems.Num());
	}
	if ((Controller == nullptr) || (Controller.ActiveControl != lb_User.List))
	{
		return false;
	}
	SelectedNick = lb_User.List.Get();
	if (tp_System.IsMe(SelectedNick))
	{
		return false;
	}
	AddUserContextOptions(Sender, SelectedNick);
	AddControlContextOptions(Sender, SelectedNick);
	*/
	return true;
}

void UAAIRC_Channel::AddUserContextOptions(UGUIContextMenu* Menu, FString Nick)
{
	Menu->addItem(MessageUserText);
	Menu->addItem(WhoisUserText);
}

void UAAIRC_Channel::AddControlContextOptions(UGUIContextMenu* Menu, FString Nick)
{
	/*
	if (((Menu == nullptr) || (tp_System == nullptr)) || (!UserIsOp(tp_System.NickName)))
	{
		return;
	}
	Menu.addItem("-");
	if (UserIsOp(Nick))
	{
		Menu.addItem(DeopUserText);
	}
	else
	{
		Menu.addItem(OpUserText);
	}
	if (UserIsHelper(Nick))
	{
		Menu.addItem(DehelpUserText);
	}
	else
	{
		Menu.addItem(HelpUserText);
	}
	if (UserIsVoice(Nick))
	{
		Menu.addItem(DevoiceUserText);
	}
	else
	{
		Menu.addItem(VoiceUserText);
	}
	Menu.addItem("-");
	Menu.addItem(KickUserText);
	Menu.addItem(KickUserText + "...");
	*/
}

void UAAIRC_Channel::ContextMenuClick(UGUIContextMenu* Sender, int32 ClickIndex)
{
	int32 AbsIndex = 0;
	FString Nick = "";
	Nick = lb_User->List->Get(false);
	/*
	AbsIndex = GetAbsoluteIndex(Sender, ClickIndex);
	switch (AbsIndex)
	{
	case 0:
		tp_System.AddChannel(Nick, true, true);
		break;
	case 1:
		Whois(Nick);
		break;
	case 2:
		Op(Nick);
		break;
	case 3:
		Deop(Nick);
		break;
	case 4:
		Help(Nick);
		break;
	case 5:
		DeHelp(Nick);
		break;
	case 6:
		Voice(Nick);
		break;
	case 7:
		DeVoice(Nick);
		break;
	case 8:
		Kick(Nick);
		break;
	case 9:
		if (Controller.OpenMenu(Controller.RequestDataMenu, "", ReasonText))
		{
			Controller.ActivePage.__OnClose__Delegate = KickReasonClose;
		}
		break;
	default:
	}
	*/
}

int32 UAAIRC_Channel::GetAbsoluteIndex(UGUIContextMenu* Menu, int32 Index)
{
	/*
	if (((Menu == nullptr) || (Index < 0)) || (Index >= Menu.ContextItems.Num()))
	{
		return -1;
	}
	if ((Index == 0) || (Index == 1))
	{
		return Index;
	}
	if (Menu.ContextItems[Index] == "-")
	{
		Index++;
	}
	switch (Menu.ContextItems[Index])
	{
	case MessageUserText:
		return 0;
	case WhoisUserText:
		return 1;
	case OpUserText:
		return 2;
	case DeopUserText:
		return 3;
	case HelpUserText:
		return 4;
	case DehelpUserText:
		return 5;
	case VoiceUserText:
		return 6;
	case DevoiceUserText:
		return 7;
	case KickUserText:
		return 8;
	case KickUserText + "...":
		return 9;
	default:
		return 1;
	}
	*/
	return 0;    //FAKE  /ELiZ
}

void UAAIRC_Channel::KickReasonClose(bool bCancelled)
{
	/*
	if (!bCancelled)
	{
		Kick(lb_User.List.Get(), Controller.ActivePage.GetDataString());
	}
	*/
}

bool UAAIRC_Channel::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Cast<UGUIButton>(Sender) == nullptr)
	{
		return false;
	}
	if (Sender == b_Disconnect)
	{
		DisconnectClicked();
		return true;
	}
	if (Sender == b_Leave)
	{
		LeaveClicked();
		return true;
	}
	if (Sender == b_NewNick)
	{
		NewNickClicked();
		return true;
	}
	*/
	return false;
}

void UAAIRC_Channel::DisconnectClicked()
{
	/*
	if (tp_System != nullptr)
	{
		tp_System.Disconnect();
	}
	*/
}

void UAAIRC_Channel::LeaveClicked()
{
	/*
	if (tp_System != nullptr)
	{
		tp_System.PartCurrentChannel();
	}
	*/
}

void UAAIRC_Channel::NewNickClicked()
{
	/*
	if (tp_System != nullptr)
	{
		tp_System.ChangeCurrentNick();
	}
	*/
}

bool UAAIRC_Channel::IsPunctuation(FString Text)
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

FString UAAIRC_Channel::StripEndPunctuation(FString Text)
{
	FString Out="";
	Out = Text;
	/*
	if (IsPunctuation(Right(Out, 1)))
	{
		Out = Mid(Out, 0, (Len(Out) - 1));
	}
	*/
	return Out;
}

bool UAAIRC_Channel::IRCTextDblClick(UGUIComponent* Sender)
{
	FString ClickString = "";
	FString ChanName = "";
	FString NickName = "";
	Super::IRCTextDblClick(Sender);
	/*
	ClickString = StripColorCodes(lb_TextDisplay.MyScrollText.ClickedString);
	if (Left(ClickString, 1) == "#")
	{
		ChanName = StripEndPunctuation(ClickString);
		if (((InStr(Mid(ChanName, 1), "#") == -1) && (InStr(Mid(ChanName, 1), ",") == -1)) && (InStr(Mid(ChanName, 1), Chr(7)) == -1))
		{
			tp_System.JoinChannel(ChanName);
		}
	}
	else
	{
		NickName = ClickString;
		if ((Left(ClickString, 1) == "<") && (Right(ClickString, 1) == ">"))
		{
			NickName = Mid(NickName, 1, (Len(NickName) - 2));
		}
		if (lb_User.List.FindIndex(NickName, false) != -1)
		{
			tp_System.PrivateText(NickName, "");
		}
	}
	*/
	return true;
}
