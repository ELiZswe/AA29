// All the original content belonged to the US Army


#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserSCI/ServerBrowserSCI.h"

AServerBrowserSCI::AServerBrowserSCI()
{
	//RemoteRole = ROLE_None;
	//bAlwaysTick = true;
}


//const QUICKSORT_THRESHOLD = 4;
//const GameType = "AAO";

void AServerBrowserSCI::PreBeginPlay()
{
	/*
	Log("ServerBrowserSCI: Spawning...");
	requestState = 0;
	link = Spawn(class'IpDrv.TcpLinkSCI', Self);
	pinger = Spawn(class'IpDrv.UdpLinkSCI', Self);
	Super::PreBeginPlay();
	*/
}

void AServerBrowserSCI::Destroyed()
{
	/*
	Log("ServerBrowserSCI: Destroying...");
	link.Disconnect();
	link.Destroy();
	pinger.Destroy();
	link = None;
	pinger = None;
	Super::Destroyed();
	*/
}

void AServerBrowserSCI::DoMasterServerQuery(int32 specific)
{
	/*
	local InternetLink.IpAddr tmpip;
	if ((requestState == 2) || (requestState == 4))
	{
		return;
	}
	if (specific != -1)
	{
		if ((specific >= 0) && (serverList.Length <= specific))
		{
			Log("ServerBrowserSCI: Request for bogus server (" $ string(specific) $ ") update.");
			return;
		}
	}
	specificServer = specific;
	if (requestState == 5)
	{
		tmpip.Addr = link.IP.Addr;
		tmpip.Port = link.IP.Port;
		link.Destroy();
		link = Spawn(class'IpDrv.TcpLinkSCI', Self);
		link.IP.Addr = tmpip.Addr;
		link.IP.Port = tmpip.Port;
	}
	else
	{
		if (requestState != 0)
		{
			bNewServerQueryPending = true;
			return;
		}
	}
	link.dlog("ServerBrowserSCI: Doing new master server query (" $ string(specific) $ ") ...");
	if (specificServer == -1)
	{
		serverList.Length = 0;
	}
	requestState = 1;
	link.Connect();
	*/
}

void AServerBrowserSCI::UpdateServerList()
{
	//DoMasterServerQuery(-1);
}

void AServerBrowserSCI::RefreshServerList()
{
	//DoMasterServerQuery(-1);
}

void AServerBrowserSCI::RePingAllServers()
{
	/*
	int32 i = 0;
	int32 Max = 0;
	Max = serverList.Length;
	for (i = 0; i < Max; i++)
	{
		serverList[i].Time = Level.TimeSeconds;
		pinger.SendPing(serverList[i].NetOrderIP, i);
	}
	*/
}

void AServerBrowserSCI::RefreshSpecificServer(int32 iIndex)
{
	//DoMasterServerQuery(iIndex);
}

void AServerBrowserSCI::GetPlayerInfo(int32 server_index, int32 player_index, FGameSpyPlayerInfo& player_info)
{
	/*
	if ((specificServer != server_index) || (player_index >= PlayerList.Length))
	{
		player_info.Name = "";
		player_info.Enemy = 0;
		player_info.KIA = 0;
		player_info.ROE = 0;
		player_info.Ping = 9999;
	}
	else
	{
		player_info.Name = PlayerList[player_index].Name;
		player_info.Enemy = PlayerList[player_index].Enemy;
		player_info.KIA = PlayerList[player_index].KIA;
		player_info.ROE = PlayerList[player_index].ROE;
		player_info.Ping = PlayerList[player_index].Ping;
	}
	*/
}

void AServerBrowserSCI::GetSpecificServer(int32 Index, FGameSpyServerItem& Item)
{
	/*
	if ((Index < 0) || (Index >= serverList.Length))
	{
		Item.bValid = 0;
	}
	else
	{
		Item.bValid = serverList[Index].bValid;
		Item.bOfficial = serverList[Index].bOfficial;
		Item.bLeased = serverList[Index].bLeased;
		Item.bNATO = serverList[Index].bNATO;
		Item.bMiles = serverList[Index].bMiles;
		Item.bPassword = serverList[Index].bPassword;
		Item.bPunkBuster = serverList[Index].bPunkBuster;
		Item.bCheats = serverList[Index].bCheats;
		Item.bTournament = serverList[Index].bTournament;
		Item.CustomFlags = serverList[Index].CustomFlags;
		Item.Name = serverList[Index].Name;
		Item.MapName = serverList[Index].MapName;
		Item.GameVer = serverList[Index].GameVer;
		Item.Guid = serverList[Index].Guid;
		Item.NetOrderIP = serverList[Index].NetOrderIP;
		Item.IP = serverList[Index].IP;
		Item.Port = serverList[Index].Port;
		Item.Ping = serverList[Index].Ping;
		Item.Index = serverList[Index].Index;
		Item.Tour = serverList[Index].Tour;
		Item.NumPlayers = serverList[Index].NumPlayers;
		Item.MaxPlayers = serverList[Index].MaxPlayers;
		Item.MinHonor = serverList[Index].MinHonor;
		Item.MaxHonor = serverList[Index].MaxHonor;
	}
	*/
}

void AServerBrowserSCI::GameSpyInit()
{
	//bDisplayWhenDone = true;
}

void AServerBrowserSCI::GameSpyClearList()
{
	//serverList.Length = 0;
}

int32 AServerBrowserSCI::cmpfn(int32 one, int32 two)
{
	return 0;    //FAKE   /EliZ
}

void AServerBrowserSCI::swapfn(int32 one, int32 two)
{
	/*
	local FGameSpyServerItem Item;
	Item = serverList[one];
	serverList[one] = serverList[two];
	serverList[two] = Item;
	*/
}

void AServerBrowserSCI::doServerBubbleSort(int32 lo, int32 hi)
{
	/*
	int32 i = 0;
	bool sorted = false;
	if (!sorted)
	{
		sorted = true;
		for (i = lo; i < hi; i++)
		{
			if (cmpfn(i, (i + 1)) > 0)
			{
				swapfn(i, (i + 1));
				sorted = false;
			}
		}
	}
	*/
}

void AServerBrowserSCI::doServerQuickSort(int32 lo, int32 hi)
{
	/*
	int32 i = 0;
	int32 j = 0;
	int32 V = 0;
	if ((hi - lo) <= 4)
	{
		doServerBubbleSort(lo, hi);
	}
	else
	{
		i = ((hi + lo) / 2);
		if (cmpfn(lo, i) > 0)
		{
			swapfn(lo, i);
		}
		if (cmpfn(lo, hi) > 0)
		{
			swapfn(lo, hi);
		}
		if (cmpfn(i, hi) > 0)
		{
			swapfn(i, hi);
		}
		j = (hi - 1);
		swapfn(i, j);
		i = lo;
		V = j;
		if (true)
		{
			if (cmpfn((++i), V) < 0)
			{
			}
			if (cmpfn((--j), V) > 0)
			{
			}
			if (j < i)
			{
			}
			swapfn(i, j);
		}
		swapfn(i, (hi - 1));
		doServerQuickSort(lo, j);
		doServerQuickSort((i + 1), hi);
	}
	*/
}

int32 AServerBrowserSCI::cmpHostnameAscending(int32 one, int32 two)
{
	/*
	FString valone = "";
	FString valtwo = "";
	valone = serverList[one].Name;
	valtwo = serverList[two].Name;
	if (valone < valtwo)
	{
		return -1;
	}
	else
	{
		if (valone > valtwo)
		{
			return 1;
		}
	}
	*/
	return 0;
}

int32 AServerBrowserSCI::cmpMapnameAscending(int32 one, int32 two)
{
	/*
	FString valone = "";
	FString valtwo = "";
	valone = serverList[one].MapName;
	valtwo = serverList[two].MapName;
	if (valone < valtwo)
	{
		return -1;
	}
	else
	{
		if (valone > valtwo)
		{
			return 1;
		}
	}
	*/
	return 0;
}

int32 AServerBrowserSCI::cmpNumPlayersAscending(int32 one, int32 two)
{
	/*
	int32 valone = 0;
	int32 valtwo = 0;
	valone = serverList[one].NumPlayers;
	valtwo = serverList[two].NumPlayers;
	if (valone < valtwo)
	{
		return -1;
	}
	else
	{
		if (valone > valtwo)
		{
			return 1;
		}
	}
	*/
	return 0;
}

int32 AServerBrowserSCI::cmpPingAscending(int32 one, int32 two)
{
	/*
	int32 valone = 0;
	int32 valtwo = 0;
	valone = serverList[one].Ping;
	valtwo = serverList[two].Ping;
	if (valone < valtwo)
	{
		return -1;
	}
	else
	{
		if (valone > valtwo)
		{
			return 1;
		}
	}
	*/
	return 0;
}

int32 AServerBrowserSCI::cmpHostnameDescending(int32 one, int32 two)
{
	/*
	FString valone = "";
	FString valtwo = "";
	valone = serverList[one].Name;
	valtwo = serverList[two].Name;
	if (valone > valtwo)
	{
		return -1;
	}
	else
	{
		if (valone < valtwo)
		{
			return 1;
		}
	}
	*/
	return 0;
}

int32 AServerBrowserSCI::cmpMapnameDescending(int32 one, int32 two)
{
	/*
	FString valone = "";
	FString valtwo = "";
	valone = serverList[one].MapName;
	valtwo = serverList[two].MapName;
	if (valone > valtwo)
	{
		return -1;
	}
	else
	{
		if (valone < valtwo)
		{
			return 1;
		}
	}
	*/
	return 0;
}

int32 AServerBrowserSCI::cmpNumPlayersDescending(int32 one, int32 two)
{
	/*
	int32 valone = 0;
	int32 valtwo = 0;
	valone = serverList[one].NumPlayers;
	valtwo = serverList[two].NumPlayers;
	if (valone > valtwo)
	{
		return -1;
	}
	else
	{
		if (valone < valtwo)
		{
			return 1;
		}
	}
	*/
	return 0;
}

int32 AServerBrowserSCI::cmpPingDescending(int32 one, int32 two)
{
	/*
	int32 valone = 0;
	int32 valtwo = 0;
	valone = serverList[one].Ping;
	valtwo = serverList[two].Ping;
	if (valone > valtwo)
	{
		return -1;
	}
	else
	{
		if (valone < valtwo)
		{
			return 1;
		}
	}
	*/
	return 0;
}

void AServerBrowserSCI::doServerListSort(FString sField, bool bAscending, EGameSpyCompareMode eType)
{
	/*
	link.dlog("ServerBrowserSCI: sorting on" @ sField @ "ascending" @ string(bAscending));
	if (bAscending)
	{
		if (sField == "hostname")
		{
			__cmpfn__Delegate = cmpHostnameAscending;
		}
		else
		{
			if (sField == "mapname")
			{
				__cmpfn__Delegate = cmpMapnameAscending;
			}
			else
			{
				if (sField == "numplayers")
				{
					__cmpfn__Delegate = cmpNumPlayersAscending;
				}
				else
				{
					if (sField == "ping")
					{
						__cmpfn__Delegate = cmpPingAscending;
					}
					else
					{
						Log("ServerBrowserSCI: Unknown sort \"" $ sField $ "\", ascending.");
						return;
					}
				}
			}
		}
	}
	else
	{
		if (sField == "hostname")
		{
			__cmpfn__Delegate = cmpHostnameDescending;
		}
		else
		{
			if (sField == "mapname")
			{
				__cmpfn__Delegate = cmpMapnameDescending;
			}
			else
			{
				if (sField == "numplayers")
				{
					__cmpfn__Delegate = cmpNumPlayersDescending;
				}
				else
				{
					if (sField == "ping")
					{
						__cmpfn__Delegate = cmpPingDescending;
					}
					else
					{
						Log("ServerBrowserSCI: Unknown sort \"" $ sField $ "\", descending.");
						return;
					}
				}
			}
		}
	}
	doServerQuickSort(0, (serverList.Length - 1));
	__cmpfn__Delegate = None;
	*/
}

void AServerBrowserSCI::GameSpyStatusDone()
{
	/*
	bool bAutoSort = false;
	Log("ServerBrowserSCI: StatusDone" @ string(bDisplayWhenDone));
	bAutoSort = false;
	if (HUD(Owner) != None)
	{
		bAutoSort = HUD(Owner).GetAutoSort();
	}
	if (bAutoSort && bSortSaved)
	{
		doServerListSort(sSortField, bSortAscending, eSortType);
	}
	if (bDisplayWhenDone)
	{
		bDisplayWhenDone = false;
		DisplayServerList();
	}
	*/
}

int32 AServerBrowserSCI::GetProgress()
{
	/*
	float expected = 0;
	float acquired = 0;
	float percent = 0;
	if (requestState == 4)
	{
		if (serverList.Length >= expectedServers)
		{
			return 100;
		}
		expected = float(expectedServers);
		acquired = float(serverList.Length);
		percent = ((acquired / expected) * 100);
		return int(percent);
	}
	*/
	return 100;
}

void AServerBrowserSCI::DisplayServerList()
{
	/*
	local FGameSpyServerItem Item;
	int32 i = 0;
	Log("ServerBrowserSCI: DisplayServerList");
	for (i = 0; i < serverList.Length; i++)
	{
		Item = serverList[i];
		if (Item.bValid != 0)
		{
			Log("ServerItem - Name:" @ Item.Name @ "IP:" @ string(Item.IP) @ "Port:" @ string(Item.Port) @ "Ping:" @ string(Item.Ping));
		}
		else
		{
			Log("Error: Invalid Server Item");
		}
	}
	Log("ServerBrowserSCI: DisplayServerList complete.");
	*/
}

int32 AServerBrowserSCI::GetNumServers()
{
	//return serverList.Length;
	return 0;    //FAKE   /ELiZ
}

void AServerBrowserSCI::SortServers(FString sField, bool bAscending, EGameSpyCompareMode eType)
{
	/*
	bSortSaved = true;
	sSortField = sField;
	bSortAscending = bAscending;
	eSortType = eType;
	doServerListSort(sField, bAscending, eType);
	*/
}

void AServerBrowserSCI::SetFilter(FString sFilter)
{
	/*
	FString expr = "";
	int32 pos = 0;
	FString Field = "";
	FString FilterType = "";
	FString Value = "";
	int32 numeric = 0;
	FString ver = "";
	link.dlog("ServerBrowserSCI: new filter [" $ sFilter $ "].");
	if (InStr(sFilter, "gamever") == -1)
	{
		link.dlog("ServerBrowserSCI: Adding gamever filter manually.");
		ver = "(gamever = " $ string(GetVersionAGPMajor()) $ "." $ string(GetVersionAGPMinor()) $ "." $ string(GetVersionAGPTiny()) $ "." $ string(GetVersionAGPSubTiny()) $ ")";
		if (Len(sFilter) == 0)
		{
			sFilter = ver;
		}
		else
		{
			sFilter = sFilter @ "AND" @ ver;
		}
	}
	filterxml = "";
	if (sFilter != "")
	{
		numeric = 0;
		pos = InStr(sFilter, ")");
		if (pos == -1)
		{
			return;
		}
		expr = Mid(sFilter, 1, (pos - 1));
		sFilter = Mid(sFilter, (pos + 1));
		pos = InStr(sFilter, "(");
		if (pos != -1)
		{
			sFilter = Mid(sFilter, pos);
		}
		pos = InStr(expr, " ");
		if (pos == -1)
		{
			return;
		}
		Field = Left(expr, pos);
		expr = Mid(expr, (pos + 1));
		pos = InStr(expr, " ");
		if (pos == -1)
		{
			return;
		}
		FilterType = Left(expr, pos);
		Value = Mid(expr, (pos + 1));
		if (Field == "mapname")
		{
			Field = "MBS_MAP";
			if (Left(Value, 1) == "'")
			{
				Value = Mid(Value, 1, (Len(Value) - 2));
			}
		}
		else
		{
			if (Field == "numplayers")
			{
				numeric = 1;
				Field = "MBS_PLAYERS";
			}
			else
			{
				if (Field == "gamever")
				{
					Field = "MBS_VERSION";
				}
				else
				{
					if (Field == "password")
					{
						Field = "MBS_PRIVATE";
					}
					else
					{
						if ((Field == "minhonor") || (Field == "maxhonor"))
						{
							numeric = 1;
						}
					}
				}
			}
		}
		if (FilterType == "=")
		{
			FilterType = "EQUAL";
		}
		else
		{
			if (FilterType == "<=")
			{
				FilterType = "LESSTHANOREQUAL";
			}
			else
			{
				if (FilterType == ">=")
				{
					FilterType = "GREATERTHANOREQUAL";
				}
				else
				{
					if (FilterType == "<")
					{
						FilterType = "LESSTHAN";
					}
					else
					{
						if (FilterType == ">")
						{
							FilterType = "GREATERTHAN";
						}
						else
						{
							Log("ServerBrowserSCI: unknown filter type:" @ FilterType);
							return;
						}
					}
				}
			}
		}
		filterxml = filterxml $ "<FIELD><NUMERIC>" $ string(numeric) $ "</NUMERIC><NAME>" $ Field $ "</NAME><FILTERTYPE>" $ FilterType $ "</FILTERTYPE>" $ "<VALUE>" $ Value $ "</VALUE></FIELD>";
	}
	if (Len(filterxml) > 0)
	{
		filterxml = "<FILTERS>" $ filterxml $ "</FILTERS>";
	}
	link.dlog("ServerBrowserSCI: filterxml is now [" $ filterxml $ "].");
	*/
}

void AServerBrowserSCI::SetSelectedServer(int32 Index)
{
	/*
	if (specificServer == Index)
	{
		return;
	}
	RefreshSpecificServer(Index);
	*/
}

void AServerBrowserSCI::SetPublic(bool bPublic)
{
}

void AServerBrowserSCI::parseServerCountResponse(FString responseString)
{
	/*
	int32 pos = 0;
	pos = InStr(responseString, "<COUNT>");
	if (pos != -1)
	{
		responseString = Mid(responseString, (pos + 7));
		pos = InStr(responseString, "<");
		if (pos != -1)
		{
			responseString = Left(responseString, pos);
			expectedServers = int(responseString);
		}
	}
	*/
}

bool AServerBrowserSCI::GetNextXMLBlock(FString& xml, FString& Key, FString& bLock)
{
	/*
	int32 pos = 0;
	pos = InStr(xml, "<");
	if (pos != -1)
	{
		xml = Mid(xml, (pos + 1));
		if (Left(xml, 1) == "/")
		{
			pos = InStr(xml, "<");
		}
		else
		{
			pos = InStr(xml, ">");
			if (pos != -1)
			{
				Key = Left(xml, pos);
				xml = Mid(xml, (pos + 1));
				pos = InStr(xml, "</" $ Key $ ">");
				if (pos != -1)
				{
					Key = Caps(Key);
					bLock = Left(xml, pos);
					xml = Mid(xml, (pos + 1));
					link.convFromMetaChars(bLock);
					return true;
				}
			}
			return false;
		}
	}
	*/
	return false;
}

void AServerBrowserSCI::handleServerProp(FString Key, FString Value, FGameSpyServerItem& Item)
{
	/*
	local InternetLink.IpAddr Addr;
	if (Key == "GUID")
	{
		Item.Guid = Value;
	}
	else
	{
		if (Key == "MBS_HOSTNAME")
		{
			Item.Name = Value;
		}
		else
		{
			if (Key == "MBS_HOSTPORT")
			{
				Item.Port = int(Value);
			}
			else
			{
				if (Key == "MBS_MAP")
				{
					Item.MapName = Value;
				}
				else
				{
					if (Key == "MBS_PLAYERS")
					{
						Item.NumPlayers = int(Value);
					}
					else
					{
						if (Key == "MBS_MAXPLAYERS")
						{
							Item.MaxPlayers = int(Value);
						}
						else
						{
							if (Key == "MBS_VERSION")
							{
								Item.GameVer = Value;
							}
							else
							{
								if (Key == "MBS_PRIVATE")
								{
									Item.bPassword = int(Value);
								}
								else
								{
									if (Key == "OFFICIAL")
									{
										Item.bOfficial = int(Value);
									}
									else
									{
										if (Key == "LEASED")
										{
											Item.bLeased = int(Value);
										}
										else
										{
											if (Key == "NATO")
											{
												Item.bNATO = int(Value);
											}
											else
											{
												if (Key == "MILES")
												{
													Item.bMiles = int(Value);
												}
												else
												{
													if (Key == "SV_PUNKBUSTER")
													{
														Item.bPunkBuster = int(Value);
													}
													else
													{
														if (Key == "CHEATS")
														{
															Item.bCheats = int(Value);
														}
														else
														{
															if (Key == "TOURNAMENT")
															{
																Item.bTournament = int(Value);
															}
															else
															{
																if (Key == "CUSTOMFLAGS")
																{
																	Item.CustomFlags = int(Value);
																}
																else
																{
																	if (Key == "TOUR")
																	{
																		Item.Tour = int(Value);
																	}
																	else
																	{
																		if (Key == "MINHONOR")
																		{
																			Item.MinHonor = int(Value);
																		}
																		else
																		{
																			if (Key == "MAXHONOR")
																			{
																				Item.MaxHonor = int(Value);
																			}
																			else
																			{
																				if (Key == "MBS_PING")
																				{
																					Item.Ping = int(Value);
																				}
																				else
																				{
																					if (Key == "MBS_IPADDRESS")
																					{
																						link.StringToIpAddr(Value, Addr, true);
																						Item.IP = Addr.Addr;
																						link.StringToIpAddr(Value, Addr, false);
																						Item.NetOrderIP = Addr.Addr;
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
				}
			}
		}
	}
	*/
}

void AServerBrowserSCI::parseServerPropertiesXML(FString xml, FGameSpyServerItem& Item)
{
	/*
	FString Key = "";
	FString Value = "";
	FString tmp = "";
	FString Name = "";
	if (GetNextXMLBlock(xml, Key, Value))
	{
		if (Key == "PROPERTY")
		{
			tmp = Value;
			if (GetNextXMLBlock(tmp, Key, Value) && (Key == "NAME"))
			{
				Name = Caps(Value);
				if (GetNextXMLBlock(tmp, Key, Value) && (Key == "VALUE"))
				{
					handleServerProp(Name, Value, Item);
				}
			}
		}
	}
	*/
}

void AServerBrowserSCI::parsePlayerPropertiesXML(FString xml, int32 idx)
{
	/*
	FString Key = "";
	FString Value = "";
	FString tmp = "";
	FString Name = "";
	if (GetNextXMLBlock(xml, Key, Value))
	{
		if (Key == "PROPERTY")
		{
			tmp = Value;
			if (GetNextXMLBlock(tmp, Key, Value) && (Key == "NAME"))
			{
				Name = Caps(Value);
				if (GetNextXMLBlock(tmp, Key, Value) && (Key == "VALUE"))
				{
					if (Name == "ENEMY")
					{
						PlayerList[idx].Enemy = int(Value);
					}
					else
					{
						if (Name == "KIA")
						{
							PlayerList[idx].KIA = int(Value);
						}
						else
						{
							if (Name == "ROE")
							{
								PlayerList[idx].ROE = int(Value);
							}
						}
					}
				}
			}
		}
	}
	*/
}

void AServerBrowserSCI::parsePlayerXML(FString xml, int32 idx)
{
	/*
	FString Key = "";
	FString Value = "";
	if (GetNextXMLBlock(xml, Key, Value))
	{
		if (Key == "MBS_PING")
		{
			PlayerList[idx].Ping = int(Value);
		}
		else
		{
			if (Key == "MBS_NAME")
			{
				PlayerList[idx].Name = Value;
			}
			else
			{
				if (Key == "PROPERTIES")
				{
					parsePlayerPropertiesXML(Value, idx);
				}
			}
		}
	}
	*/
}

void AServerBrowserSCI::parsePlayersXML(FString xml)
{
	/*
	FString Key = "";
	FString Value = "";
	PlayerList.Length = 0;
	if (GetNextXMLBlock(xml, Key, Value))
	{
		if (Key == "PLAYER")
		{
			PlayerList.Length = (PlayerList.Length + 1);
			parsePlayerXML(Value, (PlayerList.Length - 1));
		}
	}
	*/
}

void AServerBrowserSCI::parseOneServer(FString oneServer)
{
	/*
	FString Key = "";
	FString Value = "";
	local FGameSpyServerItem Item;
	int32 idx = 0;
	if (GetNextXMLBlock(oneServer, Key, Value))
	{
		if (Key == "PLAYERS")
		{
			parsePlayersXML(Value);
		}
		else
		{
			if (Key == "PROPERTIES")
			{
				parseServerPropertiesXML(Value, Item);
			}
			else
			{
				handleServerProp(Key, Value, Item);
			}
		}
	}
	idx = specificServer;
	if (idx == -1)
	{
		idx = serverList.Length;
		serverList.Length = (serverList.Length + 1);
	}
	serverList[idx].bValid = 1;
	serverList[idx].Index = idx;
	serverList[idx].bOfficial = Item.bOfficial;
	serverList[idx].bLeased = Item.bLeased;
	serverList[idx].bNATO = Item.bNATO;
	serverList[idx].bMiles = Item.bMiles;
	serverList[idx].bPassword = Item.bPassword;
	serverList[idx].bPunkBuster = Item.bPunkBuster;
	serverList[idx].bCheats = Item.bCheats;
	serverList[idx].bTournament = Item.bTournament;
	serverList[idx].CustomFlags = Item.CustomFlags;
	serverList[idx].Name = Item.Name;
	serverList[idx].MapName = Item.MapName;
	serverList[idx].GameVer = Item.GameVer;
	serverList[idx].Guid = Item.Guid;
	serverList[idx].IP = Item.IP;
	serverList[idx].NetOrderIP = Item.NetOrderIP;
	serverList[idx].Port = Item.Port;
	serverList[idx].Ping = Item.Ping;
	serverList[idx].Tour = Item.Tour;
	serverList[idx].NumPlayers = Item.NumPlayers;
	serverList[idx].MaxPlayers = Item.MaxPlayers;
	serverList[idx].MinHonor = Item.MinHonor;
	serverList[idx].MaxHonor = Item.MaxHonor;
	serverList[idx].Time = -1;
	if (Item.Ping >= 9999)
	{
		serverList[idx].Time = Level.TimeSeconds;
		pinger.SendPing(Item.NetOrderIP, idx);
	}
	if (requestState == 4)
	{
		OnReceivedServer(idx);
	}
	*/
}

void AServerBrowserSCI::parseServerListResponse(FString& responseString)
{
	/*
	int32 pos = 0;
	FString oneServer = "";
	pos = InStr(responseString, "</SERVER>");
	if (pos != -1)
	{
		(pos += 9);
		(responseBytesProcessed += pos);
		oneServer = Left(responseString, pos);
		responseString = Mid(responseString, pos);
		pos = InStr(oneServer, "<SERVER>");
		if (pos != -1)
		{
			oneServer = Mid(oneServer, (pos + 8));
			parseOneServer(oneServer);
			pos = InStr(responseString, "</SERVER>");
		}
	}
	*/
}

void AServerBrowserSCI::parseServerListResponseByValue(FString responseString)
{
	//parseServerListResponse(responseString);
}

void AServerBrowserSCI::doRequestServerList()
{
	/*
	FString extraxml = "";
	requestState = 4;
	extraxml = "<FIELDS>" $ "<FIELD><NAME>OFFICIAL</NAME></FIELD>" $ "<FIELD><NAME>LEASED</NAME></FIELD>" $ "<FIELD><NAME>NATO</NAME></FIELD>" $ "<FIELD><NAME>TOUR</NAME></FIELD>" $ "<FIELD><NAME>MAXHONOR</NAME></FIELD>" $ "<FIELD><NAME>MINHONOR</NAME></FIELD>" $ "<FIELD><NAME>MILES</NAME></FIELD>" $ "<FIELD><NAME>SV_PUNKBUSTER</NAME></FIELD>" $ "<FIELD><NAME>CHEATS</NAME></FIELD>" $ "<FIELD><NAME>TOURNAMENT</NAME></FIELD>" $ "<FIELD><NAME>ULTIMATEARENA</NAME></FIELD>" $ "<FIELD><NAME>CUSTOMFLAGS</NAME></FIELD>" $ "</FIELDS>" $ filterxml;
	link.RequestServerList("AAO", 0, 999999, extraxml);
	*/
}

void AServerBrowserSCI::Tick(float DeltaTime)
{
	/*
	FString str = "";
	HandlePings();
	if (requestState == 0)
	{
		return;
	}
	else
	{
		if (link.StillProcessing())
		{
			if (requestState == 4)
			{
				if ((link.GetCurrentResponseSize() - responseBytesProcessed) > 4096)
				{
					parseServerListResponse(link.responseString);
				}
			}
		}
		else
		{
			if (requestState == 5)
			{
				requestState = 0;
				if (bNewServerQueryPending)
				{
					bNewServerQueryPending = false;
					DoMasterServerQuery(specificServer);
				}
			}
			else
			{
				if (link.HadError())
				{
					if (requestState == 4)
					{
						parseServerListResponseByValue(link.GetResponseString());
						GameSpyStatusDone();
					}
					requestState = 5;
					link.Disconnect();
				}
				else
				{
					if (requestState == 1)
					{
						responseBytesProcessed = 0;
						if (specificServer != -1)
						{
							requestState = 3;
							link.RequestServerInfo("AAO", serverList[specificServer].Guid);
						}
						else
						{
							serverList.Length = 0;
							requestState = 2;
							link.RequestServerCount("AAO", filterxml);
						}
					}
					else
					{
						if (requestState == 3)
						{
							if (bNewServerQueryPending)
							{
								bNewServerQueryPending = false;
								if ((specificServer >= 0) && (specificServer < serverList.Length))
								{
									link.RequestServerInfo("AAO", serverList[specificServer].Guid);
								}
							}
							else
							{
								str = link.GetResponseString();
								link.Disconnect();
								parseServerListResponse(str);
								requestState = 5;
							}
						}
						else
						{
							if (requestState == 2)
							{
								str = link.GetResponseString();
								doRequestServerList();
								parseServerCountResponse(str);
							}
							else
							{
								if (requestState == 4)
								{
									str = link.GetResponseString();
									link.Disconnect();
									parseServerListResponse(str);
									requestState = 5;
									GameSpyStatusDone();
									if (bNewServerQueryPending)
									{
										bNewServerQueryPending = false;
										if ((specificServer >= 0) && (specificServer < serverList.Length))
										{
											requestState = 3;
											link.RequestServerInfo("AAO", serverList[specificServer].Guid);
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
	*/
}

void AServerBrowserSCI::HandlePings()
{
	/*
	float secs = 0;
	int32 IP = 0;
	int32 idx = 0;
	if (pinger.GetPing(IP, idx))
	{
		link.dlog("ServerBrowserSCI: incoming ping" @ string(IP) @ "index" @ string(idx));
		if ((idx < 0) || (idx >= serverList.Length))
		{
		}
		if (serverList[idx].NetOrderIP != IP)
		{
		}
		if (serverList[idx].Time < 0)
		{
		}
		secs = (Level.TimeSeconds - serverList[idx].Time);
		serverList[idx].Ping = int((secs * 1000));
		serverList[idx].Time = -1;
		link.dlog("ServerBrowserSCI: ping" @ string(IP) @ "index" @ string(idx) @ "was" @ string(serverList[idx].Ping) @ "ms.");
	}
	*/
}

FString AServerBrowserSCI::GetConnectingMessage()
{
	return "Connecting to Andromeda...";
}
