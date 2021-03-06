// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameStats/GameStats.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Info/FileLog/FileLog.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Info/GameRules/GameRules.h"
#include "AA29/Object/Actor/Info/Mutator/Mutator.h"

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
			if (TempLog != nullptr)
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
		if (TempLog != nullptr)
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
FString AGameStats::TimeStamp()
{
	FString Seconds = "";
	/*
	Seconds=GetWorld()->GetTimeSeconds();
	if (InStr(Seconds,".") != -1)
	{
		Seconds=Left(Seconds,InStr(Seconds,"."));
	}
	*/
	return Seconds;
}
FString AGameStats::Header()
{
	//return TimeStamp() + Tab;
	return "FAKE";    //FAKE   /EliZ
}

FString AGameStats::FullTimeDate()
{
	//return Level.Year + "-" + Level.Month + "-" + Level.Day + " " + Level.Hour + ":" + Level.Minute + ":" + Level.Second;
	return "FAKE";    //FAKE   /EliZ
}

FString AGameStats::TimeZone()
{
	return "0";
}

FString AGameStats::MapName()
{
	FString MapName = "";
	/*
	MapName=GetMapFileName();
	if (InStr(MapName,".ut2") != -1)
	{
		MapName=Left(MapName,InStr(MapName,".ut2"));
	}
	ReplaceText(MapName,Tab,"_");
	*/
	return MapName;
}
void AGameStats::NewGame()
{
	FString Out = "";
	FString tmp = "";
	FString ngTitle = "";
	FString ngAuthor = "";
	FString ngGameGameName = "";
	int32 i = 0;
	AMutator* MyMutie = nullptr;
	AGameRules* MyRules = nullptr;
	/*
	ngTitle=Level.Title;
	ngAuthor=Level.Author;
	ngGameGameName=Level.Game.GameName;
	ReplaceText(ngTitle,Tab,"_");
	ReplaceText(ngAuthor,Tab,"_");
	ReplaceText(ngGameGameName,Tab,"_");
	GRI=Level.Game.GameReplicationInfo;
	Out=Header() + "NG" + Tab;
	Out $= FullTimeDate() + Tab;
	Out $= TimeZone() + Tab;
	Out $= MapName() + Tab;
	Out $= ngTitle + Tab;
	Out $= ngAuthor + Tab;
	Out $= Level.Game.Class + Tab;
	Out $= ngGameGameName;
	tmp="";
	i=0;
	ForEach AllActors('Mutator',MyMutie)
	{
		if (tmp != "")
		{
			tmp $= "|" + MyMutie.Class;
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
			tmp $= "|" + MyRules.Class;
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
		Out $= Tab + "Mutators=" + tmp;
	}
	Logf(Out);
	*/
}
void AGameStats::ServerInfo()
{
	FString Out = "";
	FString Flags = "";
	FString siServerName = "";
	FString siAdminName = "";
	FString siAdminEmail = "";
	FServerResponseLine ServerState = FServerResponseLine({});
	int32 i = 0;
	/*
	siServerName=GRI.ServerName;
	siAdminName=GRI.AdminName;
	siAdminEmail=GRI.AdminEmail;
	ReplaceText(siServerName,Tab,"_");
	ReplaceText(siAdminName,Tab,"_");
	ReplaceText(siAdminEmail,Tab,"_");
	Out=Header() + "SI" + Tab;
	Out $= siServerName + Tab;
	Out $= TimeZone() + Tab;
	Out $= siAdminName + Tab;
	Out $= siAdminEmail + Tab;
	Out $= Tab;
	Flags="";
	Level.Game.GetServerDetails(ServerState);
	for (i=0; i<ServerState.ServerInfo.Num(); i++)
	{
		Flags $= "\" + ServerState.ServerInfo[i].Key + "\" + ServerState.ServerInfo[i].Value;
	}
	ReplaceText(Flags,Tab,"_");
	Out $= Flags;
	Logf(Out);
	*/
}
void AGameStats::StartGame()
{
	/*
	Logf(Header() + "SG");
	*/
}
void AGameStats::EndGame(FString Reason)
{
	FString Out = "";
	int32 i = 0;
	int32 j = 0;
	TArray<AAA2_PlayerState*> pris ={};
	AAA2_PlayerState* PRI = nullptr;
	AAA2_PlayerState* t = nullptr;
	Out=Header() + "EG" + Tab + Reason;
	/*
	for (i=0; i<GRI.PRIArray.Num(); i++)
	{
		PRI=GRI.PRIArray[i];
		if (! PRI.bOnlySpectator && ! PRI.bBot)
		{
			pris.Num()=pris.Num() + 1;
			j=0;
			if (j < pris.Num() - 1)
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
	for (i=0; i<pris.Num(); i++)
	{
		Out $= Tab + Cast<AController>(pris[i].Owner).PlayerNum;
	}
	Logf(Out);
	*/
}

void AGameStats::ConnectEvent(AAA2_PlayerState*  Who)
{
	FString Out = "";
	/*
	if (Who.bBot || Who.bOnlySpectator)
	{
		return;
	}
	Out=Header() + "C" + Tab + Cast<AController>(Who.Owner).PlayerNum + Tab;
	Out $= GetStatsIdentifier(Cast<AController>(Who.Owner));
	Logf(Out);
	*/
}
void AGameStats::DisconnectEvent(AAA2_PlayerState*  Who)
{
	FString Out = "";
	/*
	if (Who.bBot || Who.bOnlySpectator)
	{
		return;
	}
	Out=Header() + "D" + Tab + Cast<AController>(Who.Owner).PlayerNum;
	Logf(Out);
	*/
}
void AGameStats::ScoreEvent(AAA2_PlayerState*  Who, float Points, FString Desc)
{
	/*
	if (Who.bBot || Who.bOnlySpectator)
			{
				return;
			}
			Logf(Header() + "S" + Tab + Cast<AController>(Who.Owner).PlayerNum + Tab + Points + Tab + Desc);
	*/
}
void AGameStats::TeamScoreEvent(int32 Team, float Points, FString Desc)
{
	//Logf(Header() + "T" + Tab + Team + Tab + Points + Tab + Desc);
}
void AGameStats::KillEvent(FString KillType, AAA2_PlayerState*  Killer, AAA2_PlayerState*  Victim, UaDamageType* Damage)
{
	FString Out = "";
	/*
	if (Victim.bBot || Victim.bOnlySpectator || Killer != nullptr && Killer.bBot)
	{
		return;
	}
	Out=Header() + KillType + Tab;
	if (Killer != nullptr)
	{
		Out $= Cast<AController>(Killer.Owner).PlayerNum + Tab;
		Out $= GetItemName(Damage) + Tab;
	}
	else
	{
		Out $= "-1" + Tab + GetItemName(Damage) + Tab;
	}
	Out $= Cast<AController>(Victim.Owner).PlayerNum + Tab + GetItemName(Cast<AController>(Victim.Owner).GetLastWeapon());
	if (Cast<APlayerController>(Victim.Owner) != nullptr && PlayerController(Victim.Owner).bIsTyping)
	{
		if (Cast<APlayerController>(Killer.Owner) != Cast<APlayerController>(Victim.Owner))
		{
			SpecialEvent(Killer,"type_kill");
		}
	}
	Logf(Out);
	*/
}

void AGameStats::SpecialEvent(AAA2_PlayerState*  Who, FString Desc)
{
	FString Out = "";
	/*
	if (Who != nullptr)
	{
		if (Who.bBot || Who.bOnlySpectator)
		{
			return;
		}
		Out=Controller(Who.Owner).PlayerNum;
	}
	else
	{
		Out="-1";
	}
	Logf(Header() + "P" + Tab + Out + Tab + Desc);
	*/
}
void AGameStats::GameEvent(FString GEvent, FString Desc, AAA2_PlayerState*  Who)
{
	FString Out = "";
	FString geDesc = "";
	/*
	if (Who != nullptr)
	{
		if (Who.bBot || Who.bOnlySpectator)
		{
			return;
		}
		Out=Controller(Who.Owner).PlayerNum;
	}
	else
	{
		Out="-1";
	}
	geDesc=Desc;
	ReplaceText(geDesc,Tab,"_");
	Logf(Header() + "G" + Tab + GEvent + Tab + Out + Tab + geDesc);
	*/
}

FString AGameStats::GetLogFilename()
{
	FString Result = "";
	/*
	Result=LogFileName;
	ReplaceText(Result,"%P",Level.Game.GetServerPort());
	ReplaceText(Result,"%N",Level.Game.GameReplicationInfo.ServerName);
	ReplaceText(Result,"%Y",Right("0000" + Level.Year,4));
	ReplaceText(Result,"%M",Right("00" + Level.Month,2));
	ReplaceText(Result,"%D",Right("00" + Level.Day,2));
	ReplaceText(Result,"%H",Right("00" + Level.Hour,2));
	ReplaceText(Result,"%I",Right("00" + Level.Minute,2));
	ReplaceText(Result,"%W",Right("0" + Level.DayOfWeek,1));
	ReplaceText(Result,"%S",Right("00" + Level.Second,2));
	*/
	return Result;
}
