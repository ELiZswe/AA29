// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpGamespyQuery/UdpGamespyQuery.h"

AUdpGamespyQuery::AUdpGamespyQuery()
{
	QueryName = "MasterUplink";
	bRestartServerOnPortSwap = true;
	bDebugPortSwaps = true;
}

void AUdpGamespyQuery::PreBeginPlay()
{
	/*
	local int boundport;
	local int requestport;
	Tag = QueryName;
	requestport = Level.Game.GetServerPort() + 10;
	boundport = BindPort(requestport, true);
	if (boundport == 0)
	{
		Log("UdpServerQuery: Port failed to bind.");
		Return;
	}
	Log("UdpServerQuery(crt): Port " $ boundport $ " successfully bound.");
	if (bRestartServerOnPortSwap)
	{
		if (OldQueryPortNumber != 0)
		{
			if (OldQueryPortNumber != boundport)
			{
				Log("PORTSWAP detected, exiting...  old port: " $ OldQueryPortNumber $ ", new port: " $ boundport $ ", requested port: " $ requestport);
				if (bDebugPortSwaps)
				{
					DebugPortSwap(Level);
				}
				Assert(OldQueryPortNumber == boundport);
			}
		}
		OldQueryPortNumber = boundport;
		SaveConfig();
	}
	*/
}
void AUdpGamespyQuery::DebugPortSwap(AActor* Ref)
{
	/*
	local array<UdpGamespyQuery> Queries;
	local array<Object> Referencers;
	local UdpGamespyQuery Q;
	local int i;
	local int j;
	local string str;
	Log("***************");
	Log(" Complete OBJ LIST:");
	Ref.ConsoleCommand("obj list", true);
	Log("***************");
	Log("");
	Log("Current UdpGameSpyQuery objects:");
	ForEach Ref.('UdpGamespyQuery', Q)
	{
		Queries[Queries.Length] = Q;
	}
	if (Queries.Length == 0)
	{
		Log("No UdpGamespyQuery objects found!");
		Return;
	}
	Ref.ConsoleCommand("obj list class=udpgamespyquery", true);
	Log("***************");
	Log("Tracing UdpGamespyQuery objects");
	for (i = 0; i < Queries.Length; i++)
	{
		str = GetFullName(Queries[i]);
		Log("===================================================================");
		Log(" Referencers of '" $ str $ "'");
		Ref.ConsoleCommand("obj refs class=udpgamespyquery name=" $ str, true);
		Ref.GetReferencers(Queries[i], Referencers);
		for (j = 0; j < Referencers.Length; j++)
		{
			if (Level(Referencers[j]) == nullptr && GameEngine(Referencers[j]) == nullptr)
			{
				str = GetFullName(Referencers[j]);
				Log("");
				Log(" Referencers of '" $ str $ "'");
				Ref.ConsoleCommand("obj refs class=" $ Referencers[j].Class $ " name=" $ str, true);
				Log("**************************************************************************");
			}
		}
		Log("===================================================================");
		Log("");
	}
	Log("Performing garbage collection");
	Ref.ConsoleCommand("obj garbage", true);
	Log("***************");
	Log("Remaining UdpGameSpyQuery objects:");
	Ref.ConsoleCommand("obj list class=udpgamespyquery", true);
	Log("***************");
	*/
}
FString AUdpGamespyQuery::GetFullName(UObject* obj)
{
	FString FullName = "";
	/*
	local array<Object> Outers;
	local int i;
	if (obj == nullptr)
	{
		return "";
	}
	Outers[0] = obj;
	if (Outers[0].Outer != None)
	{
		Outers.insert(0, 1);
		Outers[0] = Outers[1].Outer;
	}
	for (i = 0; i < Outers.Length; i++)
	{
		if (FullName != "")
		{
			FullName $ = ".";
		}
		FullName $ = Outers[i].Name;
	}
	*/
	return FullName;
}

void AUdpGamespyQuery::ReceivedText(FIpAddr Addr, FString Text)
{
	/*
	local string Query;
	local bool QueryRemaining;
	local int QueryNum;
	local int PacketNum;
	CurrentQueryNum++;
	if (CurrentQueryNum > 100)
	{
		CurrentQueryNum = 1;
	}
	QueryNum = CurrentQueryNum;
	Query = Text;
	if (Query == "")
	{
		QueryRemaining = False;
	}
	else
	{
		QueryRemaining = true;
	}
	PacketNum = 0;
	ReplyData = "";
	if (QueryRemaining)
	{
		Query = ParseQuery(Addr, Query, QueryNum, PacketNum);
		if (Query == "")
		{
			QueryRemaining = False;
		}
		else
		{
			QueryRemaining = true;
		}
	}
	*/
}

bool AUdpGamespyQuery::ParseNextQuery(FString Query, FString &QueryType, FString &QueryValue, FString &QueryRest, int32 &bFinalPacket)
{
	/*
	local string TempQuery;
	local int ClosingSlash;
	if (Query == "")
	{
		return false;
	}
	if (Left(Query, 1) == "\")
	{
		ClosingSlash = InStr(Right(Query, Len(Query) - 1), "\");
			if (ClosingSlash == 0)
			{
				return false;
			}
		TempQuery = Query;
		QueryType = Right(Query, Len(Query) - 1);
		QueryType = Left(QueryType, ClosingSlash);
		QueryRest = Right(Query, Len(Query) - Len(QueryType) + 2);
		if (QueryRest == "" || Len(QueryRest) == 1)
		{
			bFinalPacket = 1;
			return true;
		}
		else
		{
			if (Left(QueryRest, 1) == "\")
			{
				return true;
			}
		}
		ClosingSlash = InStr(QueryRest, "\");
			if (ClosingSlash >= 0)
			{
				QueryValue = Left(QueryRest, ClosingSlash);
			}
			else
			{
				QueryValue = QueryRest;
			}
		QueryRest = Right(Query, Len(Query) - Len(QueryType) + Len(QueryValue) + 3);
		if (QueryRest == "")
		{
			bFinalPacket = 1;
			return true;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

FString AUdpGamespyQuery::ParseQuery(FIpAddr Addr, FString Query, int32 QueryNum, int32 &PacketNum)
{
	FString QueryType = "";
	FString QueryValue = "";
	FString QueryRest = "";
	FString ValidationString = "";
	bool Result = false;
	int bFinalPacket = 0;
	bFinalPacket = 0;
	/*
	Result = ParseNextQuery(Query, QueryType, QueryValue, QueryRest, bFinalPacket);
	if (!Result)
	{
		return "";
	}
	if (QueryType == "basic")
	{
		Result = SendQueryPacket(Addr, GetBasic(), QueryNum, PacketNum, bFinalPacket);
	}
	else
	{
		if (QueryType == "info")
		{
			Result = SendQueryPacket(Addr, GetInfo(), QueryNum, PacketNum, bFinalPacket);
		}
		else
		{
			if (QueryType == "rules")
			{
				Result = SendQueryPacket(Addr, GetRules(), QueryNum, PacketNum, bFinalPacket);
			}
			else
			{
				if (QueryType == "players")
				{
					if (Level.Game.NumPlayers > 0)
					{
						Result = SendPlayers(Addr, QueryNum, PacketNum, bFinalPacket);
					}
					else
					{
						Result = SendQueryPacket(Addr, "", QueryNum, PacketNum, bFinalPacket);
					}
				}
				else
				{
					if (QueryType == "status")
					{
						Result = SendQueryPacket(Addr, GetBasic(), QueryNum, PacketNum, 0);
						Result = SendQueryPacket(Addr, GetInfo(), QueryNum, PacketNum, 0);
						if (Level.Game.NumPlayers == 0)
						{
							Result = SendQueryPacket(Addr, GetRules(), QueryNum, PacketNum, bFinalPacket);
						}
						else
						{
							Result = SendQueryPacket(Addr, GetRules(), QueryNum, PacketNum, 0);
							Result = SendPlayers(Addr, QueryNum, PacketNum, bFinalPacket);
						}
					}
					else
					{
						if (QueryType == "echo")
						{
							Result = SendQueryPacket(Addr, "\ignoring\" $ QueryValue,QueryNum,PacketNum,bFinalPacket);
						}
						else
						{
							if (QueryType == "secure")
							{
								ValidationString = "\validate\" $ GameSpyValidate(QueryValue);
									Result = SendQueryPacket(Addr, ValidationString, QueryNum, PacketNum, bFinalPacket);
							}
							else
							{
								if (QueryType == "level_property")
								{
									Result = SendQueryPacket(Addr, GetLevelProperty(QueryValue), QueryNum, PacketNum, bFinalPacket);
								}
								else
								{
									if (QueryType == "game_property")
									{
										Result = SendQueryPacket(Addr, GetGameProperty(QueryValue), QueryNum, PacketNum, bFinalPacket);
									}
									else
									{
										if (QueryType == "player_property")
										{
											Result = SendQueryPacket(Addr, GetPlayerProperty(QueryValue), QueryNum, PacketNum, bFinalPacket);
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
	return QueryRest;
}
bool AUdpGamespyQuery::SendAPacket(FIpAddr Addr, int32 QueryNum, int32 &PacketNum, int32 bFinalPacket)
{
	bool Result = false;
	/*
	ReplyData = ReplyData $ "\queryid\" $ QueryNum $ "." $ ++ PacketNum;
		if (bFinalPacket == 1)
		{
			ReplyData = ReplyData $ "\final\";
		}
	Result = SendText(Addr, ReplyData);
	ReplyData = "";
	*/
	return Result;
}

bool AUdpGamespyQuery::SendQueryPacket(FIpAddr Addr, FString SendString, int32 QueryNum, int32 &PacketNum, int32 &bFinalPacket)
{
	bool Result = false;
	Result = true;
	/*
	if (Len(ReplyData) + Len(SendString) > 1000)
	{
		Result = SendAPacket(Addr, QueryNum, PacketNum, 0);
	}
	ReplyData = ReplyData $ SendString;
	if (bFinalPacket == 1)
	{
		Result = SendAPacket(Addr, QueryNum, PacketNum, bFinalPacket);
	}
	*/
	return Result;
}

FString AUdpGamespyQuery::GetBasic()
{
	/*
	local string ResultSet;
	ResultSet = "\gamename\" $ GameSpyGameName();
		ResultSet = ResultSet $ "\gamever\" $ Level.EngineVersion;
		if (MinNetVer >= Level.MinNetVersion && MinNetVer <= Level.EngineVersion)
		{
			ResultSet = ResultSet $ "\minnetver\" $ MinNetVer;
		}
		else
		{
			ResultSet = ResultSet $ "\minnetver\" $ Level.MinNetVersion;
		}
	ResultSet = ResultSet $ "\location\" $ 'UdpGamespyUplink'.Default.ServerRegion;
		return ResultSet;
	*/
	return "FAKE";     //FAKE   /EliZ
}

FString AUdpGamespyQuery::GetInfo()
{
	FString ResultSet = "";
	FString ServerName = "";
	int32 NumPlayers = 0;
	/*
	ServerName = Level.Game.GameReplicationInfo.ServerName;
	ReplaceText(ServerName, "\","");
		ResultSet = "\hostname\" $ ServerName;
		ResultSet = ResultSet $ "\hostport\" $ Level.Game.GetServerPort();
		ResultSet = ResultSet $ "\maptitle\" $ Level.Title;
		ResultSet = ResultSet $ "\mapname\" $ Left(Level,InStr(Level,"."));
		ResultSet = ResultSet $ "\gametype\" $ GetItemName(Level.Game.Class);
		NumPlayers = Level.Game.GetNumPlayers();
	if (NumPlayers == 0)
	{
		NumPlayers = Min(Level.Game.MultiMinPlayers(), Level.Game.MaxPlayers - 1);
	}
	ResultSet = ResultSet $ "\numplayers\" $ NumPlayers;
		ResultSet = ResultSet $ "\maxplayers\" $ Level.Game.MaxPlayers;
		ResultSet = ResultSet $ "\gamemode\openplaying";
	ResultSet = ResultSet $ "\gamever\" $ Level.EngineVersion;
		if (MinNetVer >= Level.MinNetVersion && MinNetVer <= Level.EngineVersion)
		{
			ResultSet = ResultSet $ "\minnetver\" $ MinNetVer;
		}
		else
		{
			ResultSet = ResultSet $ "\minnetver\" $ Level.MinNetVersion;
		}
	*/
	return ResultSet;
}

FString AUdpGamespyQuery::GetRules()
{
	FString ResultSet = "";
	/*
	if (Level.Game.GameReplicationInfo.AdminName != "")
	{
		ResultSet = ResultSet $ "\AdminName\" $ Level.Game.GameReplicationInfo.AdminName;
	}
	if (Level.Game.GameReplicationInfo.AdminEmail != "")
	{
		ResultSet = ResultSet $ "\AdminEMail\" $ Level.Game.GameReplicationInfo.AdminEmail;
	}
	if (Level.Game.AccessControl != None && Level.Game.AccessControl.RequiresPassword())
	{
		ResultSet = ResultSet $ "\password\1";
	}
	else
	{
		ResultSet = ResultSet $ "\password\0";
	}
	*/
	return ResultSet;
}

FString AUdpGamespyQuery::GetPlayer(APlayerController* p, int32 PlayerNum)
{
	FString ResultSet = "";
	FString PlayerName = "";
	/*
	PlayerName = p.PlayerReplicationInfo.PlayerName;
	ReplaceText(PlayerName, "\","");
	ResultSet = "\player_" $ PlayerNum $ "\" $ PlayerName;
	ResultSet = ResultSet $ "\frags_" $ PlayerNum $ "\" $ p.PlayerReplicationInfo.Score_Kills;
	ResultSet = ResultSet $ "\ping_" $ PlayerNum $ "\" $ p.ConsoleCommand("GETPING");
	if (p.PlayerReplicationInfo.Team != None)
	{
		ResultSet = ResultSet $ "\team_" $ PlayerNum $ "\" $ p.PlayerReplicationInfo.Team.TeamIndex;
	}
	else
	{
		ResultSet = ResultSet $ "\team_" $ PlayerNum $ "\0";
	}
	*/
	return ResultSet;
}

bool AUdpGamespyQuery::SendPlayers(FIpAddr Addr, int32 QueryNum, int32 &PacketNum, int32 bFinalPacket)
{
	AController* C = nullptr;
	int32 i = 0;
	bool Result = false;
	bool SendResult = false;
	Result = false;
	/*
	C = Level.ControllerList;
	if (i < Level.Game.NumPlayers)
	{
		if (C == nullptr)
		{
			if (bFinalPacket == 1)
			{
				SendResult=SendAPacket(Addr,QueryNum,PacketNum,bFinalPacket);
			}
			Result=(SendResult || Result);
		}
		else
		{
			else
			{
				if ((C.IsA("PlayerController") && (C.PlayerReplicationInfo != None)) && (! C.PlayerReplicationInfo.bOnlySpectator))
				{
					if ((i == (Level.Game.NumPlayers - 1)) && (bFinalPacket == 1))
					{
						SendResult=SendQueryPacket(Addr,GetPlayer(PlayerController(C),i),QueryNum,PacketNum,1);
					}
					else
					{
						SendResult=SendQueryPacket(Addr,GetPlayer(PlayerController(C),i),QueryNum,PacketNum,0);
					}
					Result=(SendResult || Result);
					i ++;
				}
			}
			C=C.nextController;
		}
	}
	*/
	return Result;
}

FString AUdpGamespyQuery::GetLevelProperty(FString Prop)
{
	FString ResultSet = "";
	//ResultSet = "\" $ Prop $ "\" $ Level.GetPropertyText(Prop);
	return ResultSet;
}

FString AUdpGamespyQuery::GetGameProperty(FString Prop)
{
	FString ResultSet = "";
	//ResultSet = "\" $ Prop $ "\" $ Level.Game.GetPropertyText(Prop);
	return ResultSet;
}

FString AUdpGamespyQuery::GetPlayerProperty(FString Prop)
{
	FString ResultSet = "";
	int32 i = 0;
	AController* C = nullptr;
	/*
	ForEach AllActors(Class'Controller', C)
	{
		if (C.PlayerReplicationInfo != None && !C.PlayerReplicationInfo.bBot)
		{
			i++;
			ResultSet = ResultSet $ "\" $ Prop $ "_" $ i $ "\" $ C.GetPropertyText(Prop);
		}
	}
	*/
	return ResultSet;
}