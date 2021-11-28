// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/BufferedTCPLink/IRCLink/IRCLink.h"

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
	Function SendCommandText(string Text)
	{
		Global.Message(Text);
		if (ParseDelimited(Text," ",1) ~= "NICK")
		{
			SystemPage.ChangedNick(NickName,Chop(ParseDelimited(Text," ",2)));
		}
	}
	Function ProcessInput(string Line)
	{
		local string Temp;
		local IRC_NewNick NewNickDialog;
		Log("LoggingIn: " $ Line,'IRC');
		Temp = ParseDelimited(Line," ",2);
		if (ParseDelimited(Line," ",1) == "ERROR")
		{
			SystemPage.SystemText(ChopLeft(ParseDelimited(Line,":",2,True)));
		}
		if (Temp == "433")
		{
			SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",3,True)));
			SetTimer(0,False);
			if (IRC_NewNick(SystemPage.Controller.TopPage()) == None)
			{
				if (SystemPage.Controller.OpenMenu("xinterface.IRC_NewNick"))
				{
					NewNickDialog = IRC_NewNick(SystemPage.Controller.TopPage());
					NewNickDialog.NewNickPrompt.Caption = NickInUseText;
					NewNickDialog.SystemPage = SystemPage;
				}
			}
		}
		else
		{
			if (Temp == "432")
			{
				SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",3,True)));
				SetTimer(0,False);
				if (IRC_NewNick(SystemPage.Controller.TopPage()) == None)
				{
					if (SystemPage.Controller.OpenMenu("xinterface.IRC_NewNick"))
					{
						NewNickDialog = IRC_NewNick(SystemPage.Controller.TopPage());
						NewNickDialog.NewNickPrompt.Caption = NickInvalidText;
						NewNickDialog.SystemPage = SystemPage;
					}
				}
			}
			else
			{
				if (Temp != 0)
				{
					SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",3,True)));
					SetTimer(0,False);
					GotoState('LoggedIn');
				}
			}
		}
		Global.GUIMultiComponent(Line);
	}
	Function Timer()
	{
		SendBufferedData("NICK " $ NickName $ CRLF);
		SetTimer(1,False);
	}
}
State LoggedIn
{
	Function ProcessInput(string Line)
	{
		local string Temp;
		local string Temp2;
		local string Temp3;
		local bool bAddModifier;
		local int i;
		local string Command;
		Global.GUIMultiComponent(Line);
		if (SystemPage == None)
		{
			Return;
		}
		Command = ParseDelimited(Line," ",2);
		if (ParseDelimited(Line," ",1) == "ERROR")
		{
			SystemPage.SystemText(ChopLeft(ParseDelimited(Line,":",2,True)));
		}
		else
		{
			if (Command == "JOIN")
			{
				Temp = ParseDelimited(Line,":!",2);
				if (Temp ~= NickName)
				{
					Temp = "";
				}
				SystemPage.JoinedChannel(Chop(ParseDelimited(Line," ",3)),Temp);
			}
			else
			{
				if (Command == "PART")
				{
					Temp = ParseDelimited(Line,":!",2);
					if (Temp ~= NickName)
					{
						Temp = "";
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
							SystemPage.UserQuit(ParseDelimited(Line,":!",2),ChopLeft(ParseDelimited(Line," ",3,True)));
						}
						else
						{
							if (Command == "353")
							{
								Temp2 = ParseDelimited(Line,"#",2);
								Temp2 = ParseDelimited(Temp2," :",1);
								Temp = ParseDelimited(Line,":",3,True);
								if (Temp != "")
								{
									Temp3 = ParseDelimited(Temp," ",1);
									SystemPage.UserInChannel("#" $ Temp2,RemoveNickPrefix(Temp3));
									if (Left(Temp3,1) == "@")
									{
										SystemPage.ChangeOp("#" $ Temp2,RemoveNickPrefix(Temp3),True);
									}
									else
									{
										if (Left(Temp3,1) == "%")
										{
											SystemPage.ChangeHalfOp("#" $ Temp2,RemoveNickPrefix(Temp3),True);
										}
										else
										{
											if (Left(Temp3,1) == "+")
											{
												SystemPage.ChangeVoice("#" $ Temp2,RemoveNickPrefix(Temp3),True);
											}
										}
									}
									Temp = ParseDelimited(Temp," ",2,True);
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
									Temp = Chop(ParseDelimited(Line," ",4));
									Temp2 = Chop(ParseDelimited(Line," ",5));
									SystemPage.ChangeTopic(Temp,Temp2);
								}
								else
								{
									if (Command == "341")
									{
									}
									if (Command == "301")
									{
										SystemPage.IsAway(Chop(ParseDelimited(Line," ",4)),ChopLeft(ParseDelimited(Line,":",3,True)));
									}
									else
									{
										if (Command == "NOTICE")
										{
											Temp = ParseDelimited(Line,": ",2);
											Temp2 = ParseDelimited(Line,":! ",2);
											if (InStr(Temp,"!") != -1 && InStr(Temp2,".") == -1)
											{
												Temp = ChopLeft(ParseDelimited(Line," ",4,True));
												if (Asc(Left(Temp,1)) == 1 && Asc(Right(Temp,1)) == 1)
												{
													SystemPage.CTCP("",Temp2,Mid(Temp,1,Len(Temp) - 2));
												}
												else
												{
													SystemPage.UserNotice(Temp2,Temp);
												}
											}
											else
											{
												SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",4,True)));
											}
										}
										else
										{
											if (Command != 0)
											{
												SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",4,True)));
											}
											else
											{
												if (Command == "MODE")
												{
													Temp = Chop(ParseDelimited(Line," ",4));
													Temp3 = Chop(ParseDelimited(Line," ",3));
													i = 5;
													bAddModifier = true;
													if (Temp != "")
													{
														Temp2 = Left(Temp,1);
														if (Temp2 == "+")
														{
															bAddModifier = true;
														}
														if (Temp2 == "-")
														{
															bAddModifier = False;
														}
														if (Temp2 == "o")
														{
															SystemPage.ChangeOp(Temp3,Chop(ParseDelimited(Line," ",i)),bAddModifier);
															i++;
														}
														if (Temp2 == "h")
														{
															SystemPage.ChangeHalfOp(Temp3,Chop(ParseDelimited(Line," ",i)),bAddModifier);
															i++;
														}
														if (Temp2 == "v")
														{
															SystemPage.ChangeVoice(Temp3,Chop(ParseDelimited(Line," ",i)),bAddModifier);
															i++;
														}
														Temp = Mid(Temp,1);
													}
													SystemPage.ChangeMode(Temp3,ParseDelimited(Line,":!",2),ChopLeft(ParseDelimited(Line," ",4,True)));
												}
												else
												{
													if (Command == "KICK")
													{
														SystemPage.KickUser(Chop(ParseDelimited(Line," ",3)),Chop(ParseDelimited(Line," ",4)),ParseDelimited(Line,":!",2),ChopLeft(ParseDelimited(Line,":",3,True)));
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
																Temp = Chop(ParseDelimited(Line," ",3));
																Temp2 = ChopLeft(ParseDelimited(Line," ",4,True));
																if (Mid(Temp2,1,7) == "ACTION " && Asc(Left(Temp2,1)) == 1 && Asc(Right(Temp2,1)) == 1)
																{
																	Temp2 = Mid(Temp2,8);
																	Temp2 = Left(Temp2,Len(Temp2) - 1);
																	if (Temp != "" && InStr("&#@",Left(Temp,1)) != -1)
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
																	if (Asc(Left(Temp2,1)) == 1 && Asc(Right(Temp2,1)) == 1)
																	{
																		Temp2 = Mid(Temp2,1,Len(Temp2) - 2);
																		Switch(Temp2)
																		{
																			case "VERSION":
																			SendBufferedData("NOTICE " $ ParseDelimited(Line,":!",2) $ " :" $ Chr(1) $ "VERSION " $ VersionString $ Level.EngineVersion $ Chr(1) $ CRLF);
																			SystemPage.CTCP(Temp,ParseDelimited(Line,":!",2),Temp2);
																			break;
																			default:
																			SystemPage.CTCP(Temp,ParseDelimited(Line,":!",2),Temp2);
																			break;
																		}
																	}
																	else
																	{
																		if (Temp != "" && InStr("&#@",Left(Temp,1)) != -1)
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
																	Temp = Chop(ParseDelimited(Line," ",3));
																	Temp2 = ChopLeft(ParseDelimited(Line," ",4,True));
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
}
Function PostBeginPlay()
{
	PostBeginPlay();
	Disable('Tick');
}
Function Connect(IRC_System InSystemPage, string InServer, string InNickName, string InUserIdent, string InFullName, string InDefaultChannel)
{
	local int i;
	Log("IRCLink Connect:" $ InServer $ InNickName $ InUserIdent $ InFullName $ InDefaultChannel, 'IRC');
	SystemPage = InSystemPage;
	NickName = InNickName;
	FullName = InFullName;
	UserIdent = InUserIdent;
	DefaultChannel = InDefaultChannel;
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
}
Function ChopLeft(string Text)
{
	if (Text != "" && InStr(": !", Left(Text, 1)) != -1)
	{
		Text = Mid(Text, 1);
	}
	Return Text;
}
Function RemoveNickPrefix(string Nick)
{
	if (Nick != "" && InStr(":@+%", Left(Nick, 1)) != -1)
	{
		Nick = Mid(Nick, 1);
	}
	Return Nick;
}
Function Chop(string Text)
{
	if (Text != "" && InStr(": !", Left(Text, 1)) != -1)
	{
		Text = Mid(Text, 1);
	}
	if (Text != "" && InStr(": !", Right(Text, 1)) != -1)
	{
		Text = Left(Text, Len(Text) - 1);
	}
	Return Text;
}
Function Resolved(InternetLink.IpAddr Addr)
{
	ServerIpAddr.Addr = Addr.Addr;
	if (ServerIpAddr.Addr == 0)
	{
		if (SystemPage != None)
		{
			SystemPage.SystemText(InvalidAddressText);
			SystemPage.Disconnect();
		}
		Return;
	}
	Log("UT2004 IRCLink: Server is " $ ServerAddress $ ":" $ ServerIpAddr.Port, 'IRC');
	if (BindPort() == 0)
	{
		if (SystemPage != None)
		{
			SystemPage.SystemText(ErrorBindingText);
			SystemPage.Disconnect();
		}
		Return;
	}
	Open(ServerIpAddr);
}
Event Closed()
{
	if (SystemPage != None)
	{
		SystemPage.Disconnect();
	}
}
Function ResolveFailed()
{
	if (SystemPage != None)
	{
		SystemPage.SystemText(ResolveFailedText);
		SystemPage.Disconnect();
	}
}
Event Timer()
{
	if (SystemPage != None)
	{
		SystemPage.SystemText(TimeOutError);
		SystemPage.Disconnect();
		Log("Failed to resolve " $ ServerAddress, 'IRC');
	}
	Return;
}
Event Opened()
{
	SetTimer(0, false);
	if (SystemPage != None)
	{
		SystemPage.SystemText(ConnectedText);
	}
	Enable('Tick');
	GotoState('LoggingIn');
}
Function Tick(float DeltaTime)
{
	local string Line;
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
			if (SystemPage != None)
			{
				SystemPage.UpdateAway();
			}
			SinceLastLevCheck = 0;
		}
	}
}
Function SendCommandText(string Text)
{
	local int i;
	local int j;
	local string Cmd;
	local string Temp;
	local string Temp2;
	if (Left(Text, 4) ~= "MSG ")
	{
		Text = "PRIVMSG " $ Mid(Text, 4);
	}
	if (Left(Text, 6) ~= "LEAVE ")
	{
		Text = "PART " $ Mid(Text, 6);
	}
	i = InStr(Text, " ");
	if (i != -1)
	{
		Cmd = Caps(Left(Text, i));
		Text = Cmd $ Mid(Text, i);
		Switch(Cmd)
		{
				case "PRIVMSG":
				case "NOTICE":
				case "KILL":
					Temp = ChopLeft(Mid(Text, i + 1));
					i = InStr(Temp, " ");
					if (i != -1)
					{
						Text = Cmd @ Left(Temp, i) $ " :" $ ChopLeft(Mid(Temp, i + 1));
					}
					break;
				case "CTCP":
					Temp = ChopLeft(Mid(Text, i + 1));
					i = InStr(Temp, " ");
					if (i != -1)
					{
						Text = "PRIVMSG " $ Left(Temp, i) $ " :" $ Chr(1) $ ChopLeft(Mid(Temp, i + 1)) $ Chr(1);
					}
					break;
				case "KICK":
					Temp = ChopLeft(Mid(Text, i + 1));
					i = InStr(Temp, " ");
					if (i != -1)
					{
						Temp2 = ChopLeft(Mid(Temp, i + 1));
						j = InStr(Temp2, " ");
						if (j != -1)
						{
							Text = Cmd @ Left(Temp, i) @ Left(Temp2, j) $ " :" $ ChopLeft(Mid(Temp2, j + 1));
						}
					}
					break;
				case "QUIT":
					Text = Cmd $ " :" $ ChopLeft(Mid(Text, i + 1));
					break;
				default:
		}
	}
	else
	{
		Text = Caps(Text);
	}
	SendBufferedData(Text $ CRLF);
}
Function SendChannelText(string Channel, string Text)
{
	SendBufferedData("PRIVMSG " $ Channel $ " :" $ Text $ CRLF);
}
Function SendChannelAction(string Channel, string Text)
{
	SendBufferedData("PRIVMSG " $ Channel $ " :" $ Chr(1) $ "ACTION " $ Text $ Chr(1) $ CRLF);
}
Function ProcessInput(string Line)
{
	if (Left(Line, 5) == "PING ")
	{
		SendBufferedData("PONG " $ Mid(Line, 5) $ CRLF);
	}
}
Function JoinChannel(string Channel)
{
	Log("IRCLink: JoinChannel: " $ Channel, 'IRC');
	if (Left(Channel, 1) == "#")
	{
		SendBufferedData("JOIN " $ Channel $ CRLF);
	}
}
Function PartChannel(string Channel)
{
	if (Left(Channel, 1) == "#")
	{
		SendBufferedData("PART " $ Channel $ CRLF);
	}
}
Function SetNick(string NewNick)
{
	SendBufferedData("NICK " $ NewNick $ CRLF);
}
Function SetAway(string AwayText)
{
	SendBufferedData("AWAY :" $ AwayText $ CRLF);
}
Function DestroyLink()
{
	SystemPage = None;
	if (IsConnected())
	{
		SendText("QUIT :" $ DisconnectReason $ CRLF);
		Close();
	}
	else
	{
		Destroy();
	}
}

*/