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
	Function Timer()
	{
		SendBufferedData("NICK " $ NickName $ CRLF);
		SetTimer(1,false);
	}
	Function ProcessInput(FString Line)
	{
		FString Temp = "";
		local IRC_NewNick NewNickDialog;
		Log("LoggingIn: " $ Line,"IRC");
		Temp=ParseDelimited(Line," ",2);
		if (ParseDelimited(Line," ",1) == "ERROR")
		{
			SystemPage.SystemText(ChopLeft(ParseDelimited(Line,":",2,true)));
		}
		if (Temp == "433")
		{
			SystemPage.SystemText(ChopLeft(ParseDelimited(Line," ",3,true)));
			SetTimer(0,false);
			if (IRC_NewNick(SystemPage.Controller.TopPage()) == None)
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
				if (IRC_NewNick(SystemPage.Controller.TopPage()) == None)
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
	SendBufferedData("USER " $ UserIdent $ " localhost " $ ServerAddress $ " :" $ FullName $ CRLF);
	SendBufferedData("NICK " $ NickName $ CRLF);
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
		if (SystemPage == None)
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
									SystemPage.UserInChannel("#" $ Temp2,RemoveNickPrefix(Temp3));
									if (Left(Temp3,1) == "@")
									{
										SystemPage.ChangeOp("#" $ Temp2,RemoveNickPrefix(Temp3),true);
									}
									else
									{
										if (Left(Temp3,1) == "%")
										{
											SystemPage.ChangeHalfOp("#" $ Temp2,RemoveNickPrefix(Temp3),true);
										}
										else
										{
											if (Left(Temp3,1) == "+")
											{
												SystemPage.ChangeVoice("#" $ Temp2,RemoveNickPrefix(Temp3),true);
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

