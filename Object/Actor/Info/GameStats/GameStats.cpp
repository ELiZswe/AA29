// All the original content belonged to the US Army


#include "GameStats.h"
#include "AA29/AA2_PlayerState.h"

AGameStats::AGameStats()
{
	LogFileName = "Stats_%P_%Y_%M_%D_%H_%I_%S";
}


void AGameStats::GetStatsIdentifier(AController* C)
{
}
void AGameStats::GetMapFileName()
{
}
void AGameStats::Init()
{
	/*
		if (bLocalLog)
		{
			TempLog=Spawn('FileLog');
			if (TempLog != None)
			{
				TempLog.OpenLog(GetLogFilename());
			}
			else
			{
				Warn("Could not create output file");
			}
		}
	*/
}
void AGameStats::Shutdown()
{
	/*
	if (TempLog != nullptr)
	{
		TempLog->Destroy();
	}
	*/
}
void AGameStats::Logf(FString LogString)
{
	/*
		if (TempLog != None)
		{
			TempLog.Logf(LogString);
		}
	*/
}
void AGameStats::PostBeginPlay()
{
	//Super::PostBeginPlay();
	//Tab=Chr(9);
	Init();
}
void AGameStats::Destroyed()
{
	Shutdown();
	Super::Destroyed();
}
void AGameStats::TimeStamp()
{
	/*
		local string Seconds;
		Seconds=GetWorld()->GetTimeSeconds();
		if (InStr(Seconds,".") != -1)
		{
			Seconds=Left(Seconds,InStr(Seconds,"."));
		}
		Return Seconds;
	*/
}
void AGameStats::Header()
{
	/*
		Return TimeStamp() $ Tab;
	*/
}
void AGameStats::FullTimeDate()
{
	/*
		Return Level.Year $ "-" $ Level.Month $ "-" $ Level.Day $ " " $ Level.Hour $ ":" $ Level.Minute $ ":" $ Level.Second;
	*/
}
FString AGameStats::TimeZone()
{
	return "0";
}
void AGameStats::MapName()
{
	/*
		local string MapName;
		MapName=GetMapFileName();
		if (InStr(MapName,".ut2") != -1)
		{
			MapName=Left(MapName,InStr(MapName,".ut2"));
		}
		ReplaceText(MapName,Tab,"_");
		Return MapName;
	*/
}
void AGameStats::NewGame()
{
	/*
		local string Out;
		local string tmp;
		local string ngTitle;
		local string ngAuthor;
		local string ngGameGameName;
		local int i;
		local Mutator MyMutie;
		local GameRules MyRules;
		ngTitle=Level.Title;
		ngAuthor=Level.Author;
		ngGameGameName=Level.Game.GameName;
		ReplaceText(ngTitle,Tab,"_");
		ReplaceText(ngAuthor,Tab,"_");
		ReplaceText(ngGameGameName,Tab,"_");
		GRI=Level.Game.GameReplicationInfo;
		Out=Header() $ "NG" $ Tab;
		Out $= FullTimeDate() $ Tab;
		Out $= TimeZone() $ Tab;
		Out $= MapName() $ Tab;
		Out $= ngTitle $ Tab;
		Out $= ngAuthor $ Tab;
		Out $= Level.Game.Class $ Tab;
		Out $= ngGameGameName;
		tmp="";
		i=0;
		ForEach AllActors('Mutator',MyMutie)
		{
			if (tmp != "")
			{
				tmp $= "|" $ MyMutie.Class;
			}
			else
			{
				tmp $= MyMutie.Class;
			}
			i ++;
		}
		ForEach AllActors('GameRules',MyRules)
		{
			if (tmp != "")
			{
				tmp $= "|" $ MyRules.Class;
			}
			else
			{
				tmp $= MyRules.Class;
			}
			i ++;
		}
		if (i > 0)
		{
			ReplaceText(tmp,Tab,"_");
			Out $= Tab $ "Mutators=" $ tmp;
		}
		Logf(Out);
	*/
}
void AGameStats::ServerInfo()
{
	/*
		local string Out;
		local string Flags;
		local string siServerName;
		local string siAdminName;
		local string siAdminEmail;
		local GameInfo.ServerResponseLine ServerState;
		local int i;
		siServerName=GRI.ServerName;
		siAdminName=GRI.AdminName;
		siAdminEmail=GRI.AdminEmail;
		ReplaceText(siServerName,Tab,"_");
		ReplaceText(siAdminName,Tab,"_");
		ReplaceText(siAdminEmail,Tab,"_");
		Out=Header() $ "SI" $ Tab;
		Out $= siServerName $ Tab;
		Out $= TimeZone() $ Tab;
		Out $= siAdminName $ Tab;
		Out $= siAdminEmail $ Tab;
		Out $= Tab;
		Flags="";
		Level.Game.GetServerDetails(ServerState);
		for (i=0; i<ServerState.ServerInfo.Length; i++)
		{
			Flags $= "\" $ ServerState.ServerInfo[i].Key $ "\" $ ServerState.ServerInfo[i].Value;
		}
		ReplaceText(Flags,Tab,"_");
		Out $= Flags;
		Logf(Out);
	*/
}
void AGameStats::StartGame()
{
	/*
		Logf(Header() $ "SG");
	*/
}
void AGameStats::EndGame(FString Reason)
{
	/*
		local string Out;
		local int i;
		local int j;
		local array<PlayerReplicationInfo> pris;
		local PlayerReplicationInfo PRI;
		local PlayerReplicationInfo t;
		Out=Header() $ "EG" $ Tab $ Reason;
		for (i=0; i<GRI.PRIArray.Length; i++)
		{
			PRI=GRI.PRIArray[i];
			if (! PRI.bOnlySpectator && ! PRI.bBot)
			{
				pris.Length=pris.Length + 1;
				j=0;
				if (j < pris.Length - 1)
				{
					if (pris[j].Score_Total < PRI.Score_Total || pris[j].Score_Total == PRI.Score_Total && pris[j].Score_Deaths > PRI.Score_Deaths)
					{
						t=pris[j];
						pris[j]=PRI;
						PRI=t;
					}
					j ++;
				}
				pris[j]=PRI;
			}
		}
		for (i=0; i<pris.Length; i++)
		{
			Out $= Tab $ Controller(pris[i].Owner).PlayerNum;
		}
		Logf(Out);
	*/
}

void AGameStats::ConnectEvent(AAA2_PlayerState*  Who)
{
	/*
		local string Out;
		if (Who.bBot || Who.bOnlySpectator)
		{
			Return;
		}
		Out=Header() $ "C" $ Tab $ Controller(Who.Owner).PlayerNum $ Tab;
		Out $= GetStatsIdentifier(Controller(Who.Owner));
		Logf(Out);
	*/
}
void AGameStats::DisconnectEvent(AAA2_PlayerState*  Who)
{
	/*
			local string Out;
		if (Who.bBot || Who.bOnlySpectator)
		{
			Return;
		}
		Out=Header() $ "D" $ Tab $ Controller(Who.Owner).PlayerNum;
		Logf(Out);
*/
}
void AGameStats::ScoreEvent(AAA2_PlayerState*  Who, float Points, FString Desc)
{
	/*
			if (Who.bBot || Who.bOnlySpectator)
		{
			Return;
		}
		Logf(Header() $ "S" $ Tab $ Controller(Who.Owner).PlayerNum $ Tab $ Points $ Tab $ Desc);
*/
}
void AGameStats::TeamScoreEvent(int32 Team, float Points, FString Desc)
{
	/*
		Logf(Header() $ "T" $ Tab $ Team $ Tab $ Points $ Tab $ Desc);
	*/
}
void AGameStats::KillEvent(FString KillType, AAA2_PlayerState*  Killer, AAA2_PlayerState*  Victim, UaDamageType* Damage)
{
	/*
			local string Out;
		if (Victim.bBot || Victim.bOnlySpectator || Killer != None && Killer.bBot)
		{
			Return;
		}
		Out=Header() $ KillType $ Tab;
		if (Killer != None)
		{
			Out $= Controller(Killer.Owner).PlayerNum $ Tab;
			Out $= GetItemName(Damage) $ Tab;
		}
		else
		{
			Out $= "-1" $ Tab $ GetItemName(Damage) $ Tab;
		}
		Out $= Controller(Victim.Owner).PlayerNum $ Tab $ GetItemName(Controller(Victim.Owner).GetLastWeapon());
		if (PlayerController(Victim.Owner) != None && PlayerController(Victim.Owner).bIsTyping)
		{
			if (PlayerController(Killer.Owner) != PlayerController(Victim.Owner))
			{
				SpecialEvent(Killer,"type_kill");
			}
		}
		Logf(Out);
*/
}

void AGameStats::SpecialEvent(AAA2_PlayerState*  Who, FString Desc)
{
	/*
			local string Out;
		if (Who != None)
		{
			if (Who.bBot || Who.bOnlySpectator)
			{
				Return;
			}
			Out=Controller(Who.Owner).PlayerNum;
		}
		else
		{
			Out="-1";
		}
		Logf(Header() $ "P" $ Tab $ Out $ Tab $ Desc);
*/
}
void AGameStats::GameEvent(FString GEvent, FString Desc, AAA2_PlayerState*  Who)
{
	/*
			local string Out;
		local string geDesc;
		if (Who != None)
		{
			if (Who.bBot || Who.bOnlySpectator)
			{
				Return;
			}
			Out=Controller(Who.Owner).PlayerNum;
		}
		else
		{
			Out="-1";
		}
		geDesc=Desc;
		ReplaceText(geDesc,Tab,"_");
		Logf(Header() $ "G" $ Tab $ GEvent $ Tab $ Out $ Tab $ geDesc);
		*/
}

void AGameStats::GetLogFilename()
{
	/*
		local string Result;
		Result=LogFileName;
		ReplaceText(Result,"%P",Level.Game.GetServerPort());
		ReplaceText(Result,"%N",Level.Game.GameReplicationInfo.ServerName);
		ReplaceText(Result,"%Y",Right("0000" $ Level.Year,4));
		ReplaceText(Result,"%M",Right("00" $ Level.Month,2));
		ReplaceText(Result,"%D",Right("00" $ Level.Day,2));
		ReplaceText(Result,"%H",Right("00" $ Level.Hour,2));
		ReplaceText(Result,"%I",Right("00" $ Level.Minute,2));
		ReplaceText(Result,"%W",Right("0" $ Level.DayOfWeek,1));
		ReplaceText(Result,"%S",Right("00" $ Level.Second,2));
		Return Result;
	*/
}