// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/BufferedTCPLink/AAIRCLink/AAIRCLink.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_Channel/AAIRC_Channel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_System/AAIRC_System.h"

AAAIRCLink::AAAIRCLink()
{
	InvalidAddressText = "Invalid server address, aborting.";
	ErrorBindingText = "Error binding local port, aborting.";
	ResolveFailedText = "Failed to resolve server address, aborting.";
	ConnectedText = "Connected.";
	ConnectingToText = "Connecting to";
	TimeOutError = "Timeout connecting to server.";
	InviteString = "invites you to join";
	DisconnectReason = "Disconnected";
	VersionString = "Americas Army IRC Client version ";
	Shortcuts = { { "MSG", "PRIVMSG" },{ "LEAVE", "PART" }, {"J", "JOIN" }, {"P", "PART" }, {"N", "NICK" } };
}

/*
State LoggingIn
{
	Function Timer()
	{
		SendBufferedData("NICK " + NickName + CRLF);
		SetTimer(1,false);
	}
	Function ProcessInput(FString Line)
	{
		FString Temp = "";
		Log("LoggingIn: " + Line,"IRC");
		Temp=ParseDelimited(Line," ",2);
		if (ParseDelimited(Line," ",1) == "ERROR")
		{
			SystemPage.SystemText(ChopLeft(ParseDelimited(Line,":",2,true)));
		}
		if (Temp == "433")
		{
			SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",3,true)));
			SetTimer(0,false);
			SystemPage.NotifyNickInUse();
		}
		else
		{
			if (Temp == "432")
			{
				SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",3,true)));
				SetTimer(0,false);
				SystemPage.NotifyInvalidNick();
			}
			else
			{
				if (SystemPage.IsDigit(Temp))
				{
					SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",3,true)));
					SetTimer(0,false);
					GotoState("LoggedIn");
				}
			}
		}
		Global.serverList(Line);
	}
	Function SendCommandText(FString Text)
	{
		if (ParseDelimited(Text," ",1) ~= "NICK")
		{
			SystemPage.ChangedNick(NickName,Chop(ParseDelimited(Text," ",2)));
		}
		Global.Text(Text);
	}
Begin:
	if ((SystemPage.link != nullptr) && (SystemPage.link != Self))
	{
		SystemPage.CloseLink(SystemPage.link,true);
		SystemPage.link=Self;
	}
	else
	{
		if (SystemPage.link == nullptr)
		{
			SystemPage.link=Self;
		}
	}
	SendBufferedData("USER " + UserIdent + " localhost " + ServerAddress + " :" + FullName + CRLF);
	SendBufferedData("NICK " + NickName + CRLF);
}
*/

/*
State LoggedIn
{
	Function ProcessInput(FString Line)
	{
		FString Temp = "";
		FString Temp2 = "";
		FString Temp3 = "";
		bool bAddModifier = false;
		int32 i = 0;
		FString Command = "";
		UAAIRC_Channel* CurrentChannel = nullptr;
		Global.serverList(Line);
		if (SystemPage == nullptr)
		{
			return;
		}
		Command=ParseDelimited(Line," ",2);
		if (ParseDelimited(Line," ",1) == "ERROR")
		{
			SystemPage.SystemText(ChopLeft(ParseDelimited(Line,":",2,true)));
		}
		switch(Command)
		{
			case "JOIN":
			Temp=ParseDelimited(Line,":!",2);
			if (Temp ~= NickName)
			{
				Temp="";
			}
			SystemPage.JoinedChannel(Chop(ParseDelimited(Line," ",3)),Temp);
			break;
			case "PART":
			Temp=ParseDelimited(Line,":!",2);
			if (Temp ~= NickName)
			{
				Temp="";
			}
			SystemPage.PartedChannel(Chop(ParseDelimited(Line," ",3)),Temp);
			break;
			case "NICK":
			SystemPage.ChangedNick(ParseDelimited(Line,":!",2),Chop(ParseDelimited(Line," ",3)));
			break;
			case "QUIT":
			SystemPage.UserQuit(ParseDelimited(Line,":!",2),ChopLeft(ParseDelimited(Line," ",3,true)));
			break;
			case "353":
			Temp2=ParseDelimited(Line,"#",2);
			Temp2=ParseDelimited(Temp2," :",1);
			Temp=ParseDelimited(Line,":",3,true);
			if (Temp != "")
			{
				Temp3=ParseDelimited(Temp," ",1);
				SystemPage.UserInChannel("#" + Temp2,RemoveNickPrefix(Temp3));
				if (Left(Temp3,1) == "~")
				{
					SystemPage.ChangeOwner("#" + Temp2,RemoveNickPrefix(Temp3),true);
				}
				else
				{
					if (Left(Temp3,1) == "&")
					{
						SystemPage.ChangeProtected("#" + Temp2,RemoveNickPrefix(Temp3),true);
					}
					else
					{
						if (Left(Temp3,1) == "@")
						{
							SystemPage.ChangeOp("#" + Temp2,RemoveNickPrefix(Temp3),true);
						}
						else
						{
							if (Left(Temp3,1) == "%")
							{
								SystemPage.ChangeHalfOp("#" + Temp2,RemoveNickPrefix(Temp3),true);
							}
							else
							{
								if (Left(Temp3,1) == "+")
								{
									SystemPage.ChangeVoice("#" + Temp2,RemoveNickPrefix(Temp3),true);
								}
							}
						}
					}
				}
				Temp=ParseDelimited(Temp," ",2,true);
			}
			GOTO JL0CA4;
			case "333":
			case "366":
			case "331":
			GOTO JL0CA4;
			case "332":
			Temp=Chop(ParseDelimited(Line," ",4));
			Temp2=Chop(ParseDelimited(Line," ",5,true));
			SystemPage.ChangeTopic(Temp,Temp2);
			GOTO JL0CA4;
			case "341":
			GOTO JL0CA4;
			case "301":
			SystemPage.PrintAwayMessage(Chop(ParseDelimited(Line," ",4)),ChopLeft(ParseDelimited(Line,":",3,true)));
			GOTO JL0CA4;
			case "NOTICE":
			Temp=ParseDelimited(Line,": ",2);
			Temp2=ParseDelimited(Line,":! ",2);
			if (InStr(Temp,"services@") == -1)
			{
				Temp=ChopLeft(ParseDelimited(Line," ",4,true));
				if ((Asc(Left(Temp,1)) == 1) && (Asc(Right(Temp,1)) == 1))
				{
					SystemPage.CTCP("",Temp2,Mid(Temp,1,(Len(Temp) - 2)));
				}
				else
				{
					CurrentChannel=AAIRC_Channel(SystemPage.GetCurrentChannel());
					if (CurrentChannel == nullptr)
					{
						SystemPage.UserNotice(Temp2,Temp);
					}
					else
					{
						CurrentChannel.UserNotice(Temp2,Temp);
					}
				}
			}
			else
			{
				SystemPage.SystemText("-" + Temp2 + "- " + ChopLeft(ParseDelimited(Line," ",4,true)));
			}
			GOTO JL0CA4;
			case "MODE":
			Temp=Chop(ParseDelimited(Line," ",4));
			Temp3=Chop(ParseDelimited(Line," ",3));
			i=5;
			bAddModifier=true;
			if (Temp != "")
			{
				Temp2=Left(Temp,1);
				if (Temp2 == "+")
				{
					bAddModifier=true;
				}
				else
				{
					if (Temp2 == "-")
					{
						bAddModifier=false;
					}
					else
					{
						if (Temp2 == "q")
						{
							SystemPage.ChangeOwner(Temp3,Chop(ParseDelimited(Line," ",i)),bAddModifier);
							i ++;
						}
						else
						{
							if (Temp2 == "a")
							{
								SystemPage.ChangeProtected(Temp3,Chop(ParseDelimited(Line," ",i)),bAddModifier);
								i ++;
							}
							else
							{
								if (Temp2 == "o")
								{
									SystemPage.ChangeOp(Temp3,Chop(ParseDelimited(Line," ",i)),bAddModifier);
									i ++;
								}
								else
								{
									if (Temp2 == "h")
									{
										SystemPage.ChangeHalfOp(Temp3,Chop(ParseDelimited(Line," ",i)),bAddModifier);
										i ++;
									}
									else
									{
										if (Temp2 == "v")
										{
											SystemPage.ChangeVoice(Temp3,Chop(ParseDelimited(Line," ",i)),bAddModifier);
											i ++;
										}
									}
								}
							}
						}
					}
				}
				Temp=Mid(Temp,1);
			}
			SystemPage.ChangeMode(Temp3,ParseDelimited(Line,":!",2),ChopLeft(ParseDelimited(Line," ",4,true)));
			GOTO JL0CA4;
			case "KICK":
			SystemPage.KickUser(Chop(ParseDelimited(Line," ",3)),Chop(ParseDelimited(Line," ",4)),ParseDelimited(Line,":!",2),ChopLeft(ParseDelimited(Line,":",3,true)));
			GOTO JL0CA4;
			case "INVITE":
			SystemPage.SystemText(ParseDelimited(Line,":!",2) @ InviteString @ ParseDelimited(Line,":",3));
			GOTO JL0CA4;
			case "PRIVMSG":
			Temp=Chop(ParseDelimited(Line," ",3));
			Temp2=ChopLeftSpaces(ParseDelimited(Line,":",3,true));
			if (((Mid(Temp2,1,7) == "ACTION ") && (Asc(Left(Temp2,1)) == 1)) && (Asc(Right(Temp2,1)) == 1))
			{
				Temp2=Mid(Temp2,8);
				Temp2=Left(Temp2,(Len(Temp2) - 1));
				if ((Temp != "") && (InStr("&#@",Left(Temp,1)) != -1))
				{
					SystemPage.ChannelAction(Temp,ParseDelimited(Line,":!",2),Temp2);
				}
				else
				{
					SystemPage.PrivateAction(ParseDelimited(Line,":!",2),Temp2);
				}
			}
			else
			{
				if ((Asc(Left(Temp2,1)) == 1) && (Asc(Right(Temp2,1)) == 1))
				{
					Temp2=Mid(Temp2,1,(Len(Temp2) - 2));
					switch(Temp2)
					{
						case "VERSION":
						SendBufferedData("NOTICE " + ParseDelimited(Line,":!",2) + " :" + Chr(1) + "VERSION " + VersionString + FString::FromInt(GetVersionAGPMajor()) + "." + FString::FromInt(GetVersionAGPMinor()) + "." + FString::FromInt(GetVersionAGPTiny()) + "." + FString::FromInt(GetVersionAGPSubTiny()) + Chr(1) + CRLF);
						SystemPage.CTCP(Temp,ParseDelimited(Line,":!",2),Temp2);
						break;
						default:
						SystemPage.CTCP(Temp,ParseDelimited(Line,":!",2),Temp2);
						break;
					}
				}
				else
				{
					if ((Temp != "") && (InStr("&#@",Left(Temp,1)) != -1))
					{
						SystemPage.ChannelText(Temp,ParseDelimited(Line,":!",2),Temp2);
					}
					else
					{
						SystemPage.PrivateText(ParseDelimited(Line,":!",2),Temp2);
					}
				}
			}
			GOTO JL0CA4;
			case "TOPIC":
			Temp=Chop(ParseDelimited(Line," ",3));
			Temp2=ChopLeft(ParseDelimited(Line," ",4,true));
			SystemPage.ChangeTopic(Temp,Temp2);
			GOTO JL0CA4;
			case "305":
			case "306":
			GOTO JL0CA4;
			case "475":
			SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",4,true)));
			SystemPage.NotifyChannelKey(Chop(ParseDelimited(ChopLeft(ParseDelimited(Line," ",4,true)),":",1)));
			GOTO JL0CA4;
			default:
			if (SystemPage.IsDigit(Command))
			{
				SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",4,true)));
			}
			GOTO JL0CA4;
JL0CA4:
		}
	}
Begin:
	if (DefaultChannel != "")
	{
		JoinChannel(DefaultChannel);
	}
}
*/

void AAAIRCLink::ProcessInput(FString Line)
{
	/*
	if (Left(Line, 5) == "PING ")
	{
		SendBufferedData("PONG " + Mid(Line, 5) + CRLF);
	}
	*/
}

void AAAIRCLink::PostBeginPlay()
{
	/*
	PostBeginPlay();
	Disable('Tick');
	*/
}
void AAAIRCLink::CloseMe()
{
	/*
	if (SystemPage != nullptr)
	{
		SystemPage.CloseLink(this, false);
	}
	else
	{
		DestroyLink();
	}
	*/
}

void AAAIRCLink::Connect(UAAIRC_System* InSystemPage, FString InServer, FString InNickName, FString InUserIdent, FString InFullName, FString InDefaultChannel)
{
	int32 i = 0;
	//Log("AAIRCLink Connect:" @ InServer @ InNickName @ InUserIdent @ InFullName @ InDefaultChannel, 'IRC');
	SystemPage = InSystemPage;
	NickName = InNickName;
	FullName = InFullName;
	UserIdent = InUserIdent;
	DefaultChannel = InDefaultChannel;
	/*
	i = InStr(InServer, ":");
	if (i == -1)
	{
		ServerAddress = InServer;
		ServerPort = 6667;
	}
	else
	{
		ServerAddress = Left(InServer, i);
		ServerPort = Mid(InServer, i + 1);
	}
	ResetBuffer();
	ServerIpAddr.Port = ServerPort;
	SetTimer(20, false);
	SystemPage.SystemText(ConnectingToText @ ServerAddress);
	Resolve(ServerAddress);
	*/
}

FString AAAIRCLink::ChopLeft(FString Text)
{
	/*
	if (Text != "" && InStr(": !", Left(Text, 1)) != -1)
	{
		Text = Mid(Text, 1);
	}
	*/
	return Text;
}

FString AAAIRCLink::RemoveNickPrefix(FString Nick)
{
	/*
	if (Nick != "" && InStr(":~&@+%", Left(Nick, 1)) != -1)
	{
		Nick = Mid(Nick, 1);
	}
	*/
	return Nick;
}

FString AAAIRCLink::Chop(FString Text)
{
	/*
	if (Text != "" && InStr(": !", Left(Text, 1)) != -1)
	{
		Text = Mid(Text, 1);
	}
	if (Text != "" && InStr(": !", Right(Text, 1)) != -1)
	{
		Text = Left(Text, Len(Text) - 1);
	}
	*/
	return Text;
}

void AAAIRCLink::Resolved(FIpAddr Addr)
{
	/*
	ServerIpAddr.Addr = Addr.Addr;
	if (ServerIpAddr.Addr == 0)
	{
		if (SystemPage != nullptr)
		{
			SystemPage.SystemText(InvalidAddressText);
			CloseMe();
		}
		return;
	}
	Log("America's Army AAIRCLink: Server is " + ServerAddress + ":" + ServerIpAddr.Port, 'IRC');
	if (BindPort() == 0)
	{
		if (SystemPage != nullptr)
		{
			SystemPage.SystemText(ErrorBindingText);
			CloseMe();
		}
		return;
	}
	Open(ServerIpAddr);
	*/
}
void AAAIRCLink::Closed()
{
	CloseMe();
}
void AAAIRCLink::ResolveFailed()
{
	/*
	if (SystemPage != nullptr)
	{
		SystemPage.SystemText(ResolveFailedText);
		CloseMe();
	}
	*/
}
void AAAIRCLink::Timer()
{
	//Another State
	/*
	SendBufferedData("NICK " + NickName + CRLF);
	SetTimer(1,false);
	*/

	//Another State
	/*
	if (SystemPage != nullptr)
	{
		SystemPage.SystemText(TimeOutError);
		CloseMe();
		Log("Failed to resolve " + ServerAddress, 'IRC');
	}
	return;
	*/
}
void AAAIRCLink::Opened()
{
	/*
	SetTimer(0, false);
	if (SystemPage != nullptr)
	{
		SystemPage.SystemText(ConnectedText);
	}
	Enable('Tick');
	GotoState('LoggingIn');
	*/
}
void AAAIRCLink::Tick(float DeltaTime)
{
	/*
	FString Line;
	DoBufferQueueIO();
	if (ReadBufferedLine(Line))
	{
		ProcessInput(Line);
	}
	Tick(DeltaTime);
	if (GetStateName() == 'LoggedIn')
	{
		SinceLastLevCheck += DeltaTime;
		if (SinceLastLevCheck > 5)
		{
			if (SystemPage != nullptr)
			{
				SystemPage.UpdateAway();
			}
			SinceLastLevCheck = 0;
		}
	}
	*/
}

FString AAAIRCLink::ChopLeftSpaces(FString Text)
{
	/*
	if (Text != "" && InStr(" ", Left(Text, 1)) != -1)
	{
		Text = Mid(Text, 1);
	}
	*/
	return Text;
}

void AAAIRCLink::SendCommandText(FString Cmd)
{
	//Another State
	/*
	if (ParseDelimited(Text," ",1) ~= "NICK")
	{
		SystemPage.ChangedNick(NickName,Chop(ParseDelimited(Text," ",2)));
	}
	Global.Text(Text);
	*/

	//Another State
	/*
	int32 i = 0;
	FString Text;
	FString Temp;
	Divide(Cmd, " ", Cmd, Text);
	ReplaceCommandAlias(Cmd);
	switch(Cmd)
	{
			case "PRIVMSG":
			case "NOTICE":
			case "KILL":
				if (Text == "")
				{
					break;
				}
				Text = ChopLeft(Text);
				if (Divide(Text, " ", Temp, Text))
				{
					Temp @ = ":" + ChopLeftSpaces(Text);
					Text = Temp;
				}
				break;
			case "CTCP":
				break;
			case "KICK":
				if (Text == "")
				{
					break;
				}
				Text = ChopLeft(Text);
				if (Divide(Text, " ", Temp, Text))
				{
					i = InStr(Text, " ");
					if (i != -1)
					{
						Temp @ = ":" + Text;
					}
					else
					{
						if (Text != "")
						{
							Temp @ = Text;
						}
					}
					Text = Temp;
				}
				Text = SystemPage.GetCurrentChannelName() @ Text;
				GOTO JL01E8;
			case "QUIT":
				if (Text != "")
				{
					Text = " :" + ChopLeft(Text);
				}
				GOTO JL01E8;
			case "JOIN":
				JoinChannel(Text);
				return;
			case "PART":
				if (Text == "")
				{
					Text = SystemPage.GetCurrentChannelName();
				}
				PartChannel(Text);
				return;
			default:
			JL01E8:
	}
	if (Cmd != "")
	{
		SendBufferedData(Cmd + Eval(Text != "", " " + Text, "") + CRLF);
	}
	*/
}

void AAAIRCLink::ReplaceCommandAlias(FString &Text)
{
	/*
	int32 i = 0;
	for (i = 0; i < Shortcuts.Num(); i++)
	{
		if (Shortcuts[i].AliasText ~= Text)
		{
			Text = Shortcuts[i].RealCommand;
			return;
		}
	}
	*/
}

void AAAIRCLink::SendBufferedData(FString Text)
{
	/*
	ReplaceText(Text, "$*", "");
	ReplaceText(Text, "#*", "");
	SendBufferedData(Text);
	*/
}

void AAAIRCLink::SendChannelText(FString Channel, FString Text)
{
	/*
	if (Channel == "")
	{
		Channel = SystemPage.GetCurrentChannelName();
	}
	SendBufferedData("PRIVMSG " + Channel + " :" + Text + CRLF);
	*/
}
void AAAIRCLink::SendChannelAction(FString Channel, FString Text)
{
	/*
	if (Channel == "")
	{
		Channel = SystemPage.GetCurrentChannelName();
	}
	if (Left(Channel, 1) != "#")
	{
		Channel = "#" + Channel;
	}
	SendBufferedData("PRIVMSG " + Channel + " :" + Chr(1) + "ACTION " + Text + Chr(1) + CRLF);
	*/
}
void AAAIRCLink::JoinChannel(FString Channel)
{
	/*
	Log("AAIRCLink: JoinChannel: " + Channel, 'IRC');
	if (Channel == "")
	{
		Channel = SystemPage.GetCurrentChannelName();
	}
	if (Left(Channel, 1) != "#")
	{
		Channel = "#" + Channel;
	}
	SendBufferedData("JOIN " + Channel + CRLF);
	*/
}
void AAAIRCLink::PartChannel(FString Channel)
{
	/*
	if (Channel == "")
	{
		Channel = SystemPage.GetCurrentChannelName();
	}
	if (Left(Channel, 1) != "#")
	{
		Channel = "#" + Channel;
	}
	SendBufferedData("PART " + Channel + CRLF);
	*/
}
void AAAIRCLink::SetNick(FString NewNick)
{
	/*
	if (NewNick == "")
	{
		return;
	}
	if (NewNick ~= "chanserv")
	{
		return;
	}
	if (NewNick ~= "q")
	{
		return;
	}
	if (NewNick ~= "nickserv")
	{
		return;
	}
	SendCommandText("NICK " + NewNick);
	*/
}
void AAAIRCLink::SetAway(FString AwayText)
{
	/*
	SendBufferedData("AWAY :" + AwayText + CRLF);
	*/
}
void AAAIRCLink::DestroyLink()
{
	/*
	SystemPage = nullptr;
	SetTimer(0, false);
	if (IsConnected())
	{
		SendText("QUIT :" + DisconnectReason + CRLF);
		Close();
	}
	else
	{
		Destroy();
	}
	*/
}
