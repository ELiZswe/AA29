// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/BufferedTCPLink/IRCLink/IRCLink.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_System/IRC_System.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/IRC_NewNick/IRC_NewNick.h"

AIRCLink::AIRCLink()
{
	InvalidAddressText = "Invalid server address, aborting.";
	ErrorBindingText = "Error binding local port, aborting.";
	ResolveFailedText = "Failed to resolve server address, aborting.";
	ConnectedText = "Connected.";
	ConnectingToText = "Connecting to";
	TimeOutError = "Timeout connecting to server.";
	InviteString = "invites you to join";
	NickInUseText = "Nickname Already In Use";
	NickInvalidText = "Nickname Is Invalid";
	DisconnectReason = "Disconnected";
	VersionString = "UT2004 IRC Client version ";
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
		UIRC_NewNick* NewNickDialog = nullptr;
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
			if (Cast<UIRC_NewNick>(SystemPage.Controller.TopPage()) == nullptr)
			{
				if (SystemPage.Controller.OpenMenu("xinterface.IRC_NewNick"))
				{
					NewNickDialog=IRC_NewNick(SystemPage.Controller.TopPage());
					NewNickDialog.NewNickPrompt.Caption=NickInUseText;
					NewNickDialog.SystemPage=SystemPage;
				}
			}
		}
		else
		{
			if (Temp == "432")
			{
				SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",3,true)));
				SetTimer(0,false);
				if (Cast<UIRC_NewNick>(SystemPage.Controller.TopPage()) == nullptr)
				{
					if (SystemPage.Controller.OpenMenu("xinterface.IRC_NewNick"))
					{
						NewNickDialog=IRC_NewNick(SystemPage.Controller.TopPage());
						NewNickDialog.NewNickPrompt.Caption=NickInvalidText;
						NewNickDialog.SystemPage=SystemPage;
					}
				}
			}
			else
			{
				if (int(Temp) != 0)
				{
					SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",3,true)));
					SetTimer(0,false);
					GotoState("LoggedIn");
				}
			}
		}
		Global.GUIMultiComponent(Line);
	}
	Function SendCommandText(FString Text)
	{
		Global.Message(Text);
		if (ParseDelimited(Text," ",1) ~= "NICK")
		{
			SystemPage.ChangedNick(NickName,Chop(ParseDelimited(Text," ",2)));
		}
	}
Begin:
	SendBufferedData("USER " + UserIdent + " localhost " + ServerAddress + " :" + FullName + CRLF);
	SendBufferedData("NICK " + NickName + CRLF);
	SetTimer(1,false);
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
		Global.GUIMultiComponent(Line);
		if (SystemPage == nullptr)
		{
			return;
		}
		Command=ParseDelimited(Line," ",2);
		if (ParseDelimited(Line," ",1) == "ERROR")
		{
			SystemPage.SystemText(ChopLeft(ParseDelimited(Line,":",2,true)));
		}
		else
		{
			if (Command == "JOIN")
			{
				Temp=ParseDelimited(Line,":!",2);
				if (Temp ~= NickName)
				{
					Temp="";
				}
				SystemPage.JoinedChannel(Chop(ParseDelimited(Line," ",3)),Temp);
			}
			else
			{
				if (Command == "PART")
				{
					Temp=ParseDelimited(Line,":!",2);
					if (Temp ~= NickName)
					{
						Temp="";
					}
					SystemPage.PartedChannel(Chop(ParseDelimited(Line," ",3)),Temp);
				}
				else
				{
					if (Command == "NICK")
					{
						SystemPage.ChangedNick(ParseDelimited(Line,":!",2),Chop(ParseDelimited(Line," ",3)));
					}
					else
					{
						if (Command == "QUIT")
						{
							SystemPage.UserQuit(ParseDelimited(Line,":!",2),ChopLeft(ParseDelimited(Line," ",3,true)));
						}
						else
						{
							if (Command == "353")
							{
								Temp2=ParseDelimited(Line,"#",2);
								Temp2=ParseDelimited(Temp2," :",1);
								Temp=ParseDelimited(Line,":",3,true);
								if (Temp != "")
								{
									Temp3=ParseDelimited(Temp," ",1);
									SystemPage.UserInChannel("#" + Temp2,RemoveNickPrefix(Temp3));
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
									Temp=ParseDelimited(Temp," ",2,true);
								}
							}
							else
							{
								if (Command == "333")
								{
								}
								if (Command == "366")
								{
								}
								if (Command == "331")
								{
								}
								if (Command == "332")
								{
									Temp=Chop(ParseDelimited(Line," ",4));
									Temp2=Chop(ParseDelimited(Line," ",5));
									SystemPage.ChangeTopic(Temp,Temp2);
								}
								else
								{
									if (Command == "341")
									{
									}
									if (Command == "301")
									{
										SystemPage.IsAway(Chop(ParseDelimited(Line," ",4)),ChopLeft(ParseDelimited(Line,":",3,true)));
									}
									else
									{
										if (Command == "NOTICE")
										{
											Temp=ParseDelimited(Line,": ",2);
											Temp2=ParseDelimited(Line,":! ",2);
											if ((InStr(Temp,"!") != -1) && (InStr(Temp2,".") == -1))
											{
												Temp=ChopLeft(ParseDelimited(Line," ",4,true));
												if ((Asc(Left(Temp,1)) == 1) && (Asc(Right(Temp,1)) == 1))
												{
													SystemPage.CTCP("",Temp2,Mid(Temp,1,(Len(Temp) - 2)));
												}
												else
												{
													SystemPage.UserNotice(Temp2,Temp);
												}
											}
											else
											{
												SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",4,true)));
											}
										}
										else
										{
											if (int(Command) != 0)
											{
												SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",4,true)));
											}
											else
											{
												if (Command == "MODE")
												{
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
														if (Temp2 == "-")
														{
															bAddModifier=false;
														}
														if (Temp2 == "o")
														{
															SystemPage.ChangeOp(Temp3,Chop(ParseDelimited(Line," ",i)),bAddModifier);
															i ++;
														}
														if (Temp2 == "h")
														{
															SystemPage.ChangeHalfOp(Temp3,Chop(ParseDelimited(Line," ",i)),bAddModifier);
															i ++;
														}
														if (Temp2 == "v")
														{
															SystemPage.ChangeVoice(Temp3,Chop(ParseDelimited(Line," ",i)),bAddModifier);
															i ++;
														}
														Temp=Mid(Temp,1);
													}
													SystemPage.ChangeMode(Temp3,ParseDelimited(Line,":!",2),ChopLeft(ParseDelimited(Line," ",4,true)));
												}
												else
												{
													if (Command == "KICK")
													{
														SystemPage.KickUser(Chop(ParseDelimited(Line," ",3)),Chop(ParseDelimited(Line," ",4)),ParseDelimited(Line,":!",2),ChopLeft(ParseDelimited(Line,":",3,true)));
													}
													else
													{
														if (Command == "INVITE")
														{
															SystemPage.SystemText(ParseDelimited(Line,":!",2) @ InviteString @ ParseDelimited(Line,":",3));
														}
														else
														{
															if (Command == "PRIVMSG")
															{
																Temp=Chop(ParseDelimited(Line," ",3));
																Temp2=ChopLeft(ParseDelimited(Line," ",4,true));
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
																			SendBufferedData("NOTICE " + ParseDelimited(Line,":!",2) + " :" + Chr(1) + "VERSION " + VersionString + Level.EngineVersion + Chr(1) + CRLF);
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
															}
															else
															{
																if (Command == "TOPIC")
																{
																	Temp=Chop(ParseDelimited(Line," ",3));
																	Temp2=ChopLeft(ParseDelimited(Line," ",4,true));
																	SystemPage.ChangeTopic(Temp,Temp2);
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
Begin:
	if (DefaultChannel != "")
	{
		JoinChannel(DefaultChannel);
	}
}
*/

void AIRCLink::PostBeginPlay()
{
	//Super::PostBeginPlay();
	//Disable("Tick");
}

void AIRCLink::Connect(UIRC_System* InSystemPage, FString InServer, FString InNickName, FString InUserIdent, FString InFullName, FString InDefaultChannel)
{
	int32 i = 0;
	//Log("IRCLink Connect:" + InServer + InNickName + InUserIdent + InFullName + InDefaultChannel, "IRC");
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
		ServerPort = int(Mid(InServer, (i + 1)));
	}
	ResetBuffer();
	ServerIpAddr.Port = ServerPort;
	SetTimer(20, false);
	SystemPage.SystemText(ConnectingToText @ ServerAddress);
	Resolve(ServerAddress);
	*/
}

FString AIRCLink::ChopLeft(FString Text)
{
	/*
	if ((Text != "") && (InStr(": !", Left(Text, 1)) != -1))
	{
		Text = Mid(Text, 1);
	}
	*/
	return Text;
}

FString AIRCLink::RemoveNickPrefix(FString Nick)
{
	/*
	if ((Nick != "") && (InStr(":@+%", Left(Nick, 1)) != -1))
	{
		Nick = Mid(Nick, 1);
	}
	*/
	return Nick;
}

FString AIRCLink::Chop(FString Text)
{
	/*
	if ((Text != "") && (InStr(": !", Left(Text, 1)) != -1))
	{
		Text = Mid(Text, 1);
	}
	if ((Text != "") && (InStr(": !", Right(Text, 1)) != -1))
	{
		Text = Left(Text, (Len(Text) - 1));
	}
	*/
	return Text;
}

void AIRCLink::Resolved(FIpAddr Addr)
{
	ServerIpAddr.Addr = Addr.Addr;
	if (ServerIpAddr.Addr == 0)
	{
		if (SystemPage != nullptr)
		{
			SystemPage->SystemText(InvalidAddressText);
			SystemPage->Disconnect();
		}
		return;
	}
	/*
	Log("UT2004 IRCLink: Server is " + ServerAddress + ":" + FString::FromInt(ServerIpAddr.Port), "IRC");
	if (BindPort() == 0)
	{
		if (SystemPage != nullptr)
		{
			SystemPage->SystemText(ErrorBindingText);
			SystemPage->Disconnect();
		}
		return;
	}
	Open(ServerIpAddr);
	*/
}

void AIRCLink::Closed()
{
	if (SystemPage != nullptr)
	{
		SystemPage->Disconnect();
	}
}

void AIRCLink::ResolveFailed()
{
	if (SystemPage != nullptr)
	{
		SystemPage->SystemText(ResolveFailedText);
		SystemPage->Disconnect();
	}
}

void AIRCLink::Timer()
{
	if (SystemPage != nullptr)
	{
		SystemPage->SystemText(TimeOutError);
		SystemPage->Disconnect();
		//Log("Failed to resolve " + ServerAddress, "IRC");
	}
}

void AIRCLink::Opened()
{
	/*
	SetTimer(0, false);
	if (SystemPage != nullptr)
	{
		SystemPage.SystemText(ConnectedText);
	}
	Enable("Tick");
	GotoState("LoggingIn");
	*/
}

void AIRCLink::Tick(float DeltaTime)
{
	FString Line = "";
	DoBufferQueueIO();
	/*
	if (ReadBufferedLine(Line))
	{
		ProcessInput(Line);
	}
	Super::Tick(DeltaTime);
	if (GetStateName() == "LoggedIn")
	{
		(SinceLastLevCheck += DeltaTime);
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

void AIRCLink::SendCommandText(FString Text)
{
	int32 i = 0;
	int32 j = 0;
	FString Cmd = "";
	FString Temp = "";
	FString Temp2 = "";
	/*
	if (Left(Text, 4) ~= "MSG ")
	{
		Text = "PRIVMSG " + Mid(Text, 4);
	}
	if (Left(Text, 6) ~= "LEAVE ")
	{
		Text = "PART " + Mid(Text, 6);
	}
	i = InStr(Text, " ");
	if (i != -1)
	{
		Cmd = Caps(Left(Text, i));
		Text = Cmd + Mid(Text, i);
		switch (Cmd)
		{
		case "PRIVMSG":
		case "NOTICE":
		case "KILL":
			Temp = ChopLeft(Mid(Text, (i + 1)));
			i = InStr(Temp, " ");
			if (i != -1)
			{
				Text = Cmd @ Left(Temp, i) + " :" + ChopLeft(Mid(Temp, (i + 1)));
			}
			break;
		case "CTCP":
			Temp = ChopLeft(Mid(Text, (i + 1)));
			i = InStr(Temp, " ");
			if (i != -1)
			{
				Text = "PRIVMSG " + Left(Temp, i) + " :" + Chr(1) + ChopLeft(Mid(Temp, (i + 1))) + Chr(1);
			}
			break;
		case "KICK":
			Temp = ChopLeft(Mid(Text, (i + 1)));
			i = InStr(Temp, " ");
			if (i != -1)
			{
				Temp2 = ChopLeft(Mid(Temp, (i + 1)));
				j = InStr(Temp2, " ");
				if (j != -1)
				{
					Text = Cmd @ Left(Temp, i) @ Left(Temp2, j) + " :" + ChopLeft(Mid(Temp2, (j + 1)));
				}
			}
			break;
		case "QUIT":
			Text = Cmd + " :" + ChopLeft(Mid(Text, (i + 1)));
			break;
		default:
		}
	}
	else
	{
		Text = Caps(Text);
	}
	SendBufferedData(Text + CRLF);
	*/
}

void AIRCLink::SendChannelText(FString Channel, FString Text)
{
	//SendBufferedData("PRIVMSG " + Channel + " :" + Text + CRLF);
}

void AIRCLink::SendChannelAction(FString Channel, FString Text)
{
	//SendBufferedData("PRIVMSG " + Channel + " :" + Chr(1) + "ACTION " + Text + Chr(1) + CRLF);
}

void AIRCLink::ProcessInput(FString Line)
{
	/*
	if (Left(Line, 5) == "PING ")
	{
		SendBufferedData("PONG " + Mid(Line, 5) + CRLF);
	}
	*/
}

void AIRCLink::JoinChannel(FString Channel)
{
	/*
	Log("IRCLink: JoinChannel: " + Channel, "IRC");
	if (Left(Channel, 1) == "#")
	{
		SendBufferedData("JOIN " + Channel + CRLF);
	}
	*/
}

void AIRCLink::PartChannel(FString Channel)
{
	/*
	if (Left(Channel, 1) == "#")
	{
		SendBufferedData("PART " + Channel + CRLF);
	}
	*/
}

void AIRCLink::SetNick(FString NewNick)
{
	//SendBufferedData("NICK " + NewNick + CRLF);
}

void AIRCLink::SetAway(FString AwayText)
{
	//SendBufferedData("AWAY :" + AwayText + CRLF);
}

void AIRCLink::DestroyLink()
{
	SystemPage = nullptr;
	/*
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
