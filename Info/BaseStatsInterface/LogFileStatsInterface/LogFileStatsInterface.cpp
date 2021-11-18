// All the original content belonged to the US Army


#include "AA29/Info/BaseStatsInterface/LogFileStatsInterface/LogFileStatsInterface.h"

ALogFileStatsInterface::ALogFileStatsInterface()
{
	Delimiter = ",";
	LogFileLifespanMinutes = 60;
	LogFileName = "%Y-%M-%D_%H-%I-%S";
}

void ALogFileStatsInterface::PostBeginPlay()
{
	/*
	PostBeginPlay();
	Tab = Chr(9);
	Init();
	*/
}
void ALogFileStatsInterface::Destroyed()
{
	/*
	Shutdown();
	Destroyed();
	*/
}
void ALogFileStatsInterface::Init()
{
	/*
	LogFile = Spawn(Class'FileLog');
	if (LogFile == None)
	{
		DebugLog(DEBUG_Warn, "LogFileStatsInterface::Init()	Could not create file log!");
		Destroy();
	}
	else
	{
		MinimumLifespan = LogFileLifespanMinutes * 60;
		LogFile.SetFilePath("stats");
		LogFile.SetFileExtension("stats");
		NewLogFile(GetLogFilename());
	}
	*/
}
void ALogFileStatsInterface::Shutdown()
{
	/*
	if (LogFile != None)
	{
		LogFile.CloseLog();
		LogFile.Destroy();
	}
	*/
}
void ALogFileStatsInterface::GetLogFilename()
{
	/*
	local FString Result;
	Result = LogFileName;
	ReplaceText(Result, "%Y", Right("00" $ Level.Year, 2));
	ReplaceText(Result, "%M", Right("00" $ Level.Month, 2));
	ReplaceText(Result, "%D", Right("00" $ Level.Day, 2));
	ReplaceText(Result, "%H", Right("00" $ Level.Hour, 2));
	ReplaceText(Result, "%I", Right("00" $ Level.Minute, 2));
	ReplaceText(Result, "%S", Right("00" $ Level.Second, 2));
	Return Result;
	*/
}
void ALogFileStatsInterface::Logf(FString S)
{
	/*
	if (LogFile != None)
	{
		LogFile.Logf(S);
	}
	*/
}
void ALogFileStatsInterface::Flush()
{
	/*
	if (LogFile != None)
	{
		LogFile.FlushLog();
	}
	*/
}
void ALogFileStatsInterface::TimeStamp()
{
	/*
	local FString Seconds;
	Seconds = GetWorld()->GetTimeSeconds();
	if (InStr(Seconds, ".") != -1)
	{
		Seconds = Left(Seconds, InStr(Seconds, "."));
	}
	Return Seconds;
	*/
}
void ALogFileStatsInterface::Header()
{
	/*
	Return TimeStamp() $ Tab;
	*/
}
void ALogFileStatsInterface::SubHeader()
{
	/*
	Return TimeStamp() $ Tab;
	*/
}
void ALogFileStatsInterface::FullTimeDate()
{
	/*
	Return Level.Year $ "-" $ Level.Month $ "-" $ Level.Day $ " " $ Level.Hour $ ":" $ Level.Minute $ ":" $ Level.Second;
	*/
}
void ALogFileStatsInterface::TimeZone()
{
	/*
	Return "0";
	*/
}
void ALogFileStatsInterface::MapName()
{
	/*
	local FString MapName;
	MapName = Level.sLevelName;
	Return MapName;
	*/
}
void ALogFileStatsInterface::NewGame()
{
}
void ALogFileStatsInterface::GameInfo()
{
	/*
	local FString Out;
	local FString LevelName;
	local FString IP;
	local FString Port;
	LevelName = Level.sLevelName;
	IP = Level.GetAddressURL();
	Port = Level.Game.GetServerPort();
	Out $ = LevelName;
	if (AGP_GameInfo(Level.Game) != None && !AGP_GameInfo(Level.Game).IsTrainingMission())
	{
		Out $ = Delimiter;
		Out $ = IP;
	}
	Logf(Out);
	*/
}
void ALogFileStatsInterface::ServerInfo()
{
	/*
	local FString Out;
	local FString Flags;
	local FString siServerName;
	local FString siAdminName;
	local FString siAdminEmail;
	siServerName = GRI.ServerName;
	siAdminName = GRI.AdminName;
	siAdminEmail = GRI.AdminEmail;
	Out $ = TimeZone() $ Delimiter;
	if (siServerName != "")
	{
		Out $ = siServerName $ Delimiter;
	}
	if (siAdminName != "")
	{
		Out $ = siAdminName $ Delimiter;
	}
	if (siAdminEmail != "")
	{
		Out $ = siAdminEmail $ Delimiter;
	}
	Flags = "";
	if (Flags != "")
	{
		Out $ = Delimiter;
		Out $ = Flags;
	}
	Logf(Out);
	*/
}
void ALogFileStatsInterface::EndGame(FString Reason)
{
}
void ALogFileStatsInterface::NewLogFile(FString Filename)
{
	/*
	local FString Out;
	local float Counter;
	GRI = Level.Game.GameReplicationInfo;
	LogFile.CloseLog();
	LogFile.OpenLog(Filename, "stats");
	if (False)
	{
		DebugLog(DEBUG_Warn, "LogFileStatsInterface::NewLogFile()	Could not create file(" @ Filename @ ")");
	}
	else
	{
		LogFileStartTime = GetWorld()->GetTimeSeconds();
		Logf("Created a new log file (" @ Filename @ ")");
		Logf("============================================");
		Out = FullTimeDate();
		Logf(Out);
		Counter = Level.RealSeconds;
		Out = Counter;
		Logf(Out);
	}
	*/
}
void ALogFileStatsInterface::SuppressEvent(int32 EventKey)
{
	/*
	local int i;
	for (i = 0; i < SuppressStat.Length; i++)
	{
		if (SuppressStat[i] == EventKey)
		{
			Return True;
		}
	}
	Return False;
	*/
}
void ALogFileStatsInterface::GetActorStamp(AActor* Info)
{
	/*
	local PlayerController PC;
	local FString sID;
	if (Info.IsA('PlayerController'))
	{
		PC = PlayerController(Info);
	}
	else
	{
		if (Info.IsA('PlayerReplicationInfo'))
		{
			PC = PlayerController(Info.Owner);
		}
		else
		{
			if (Info.IsA('Pawn'))
			{
				PC = PlayerController(Pawn(Info).Controller);
			}
		}
	}
	if (PC != None)
	{
		sID = PC.iUID;
		if (sID == "0")
		{
			if (HumanController(PC) != None)
			{
				sID = HumanController(PC).UserName;
			}
			else
			{
				sID = PC.GetHumanReadableName();
			}
		}
	}
	else
	{
		if (Info.IsA('TeamInfo'))
		{
			sID = TeamInfo(Info).TeamIndex;
		}
		else
		{
			if (Info.IsA('LevelInfo'))
			{
				sID = LevelInfo(Info).sLevelName;
			}
			else
			{
				sID = "-1";
			}
		}
	}
	Return sID;
	*/
}
void ALogFileStatsInterface::GetTimeStamp()
{
	/*
	Return GetWorld()->GetTimeSeconds();
	*/
}
void ALogFileStatsInterface::StartEventLine(int32 Key, AActor* A)
{
	/*
	Return Key $ Delimiter $ GetTimeStamp() $ Delimiter $ Level.sLevelName $ Delimiter $ GetActorStamp(A);
	*/
}
void ALogFileStatsInterface::AddField(FString existing_line, FString Info)
{
	/*
	Return existing_line $ Delimiter $ Info;
	*/
}
void ALogFileStatsInterface::NotifyRoundEnded()
{
	/*
	local int CurrentLifespan;
	if (MinimumLifespan > 0)
	{
		CurrentLifespan = GetWorld()->GetTimeSeconds() - LogFileStartTime;
		if (LifeSpan > MinimumLifespan)
		{
			NewLogFile(GetLogFilename());
		}
	}
	Flush();
	*/
}
void ALogFileStatsInterface::RecordLogOn(AController* C)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 11;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, C);
	Logf(EventLine);
	Flush();
	*/
}
void ALogFileStatsInterface::RecordLogOut(AController* C)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 12;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, C);
	Logf(EventLine);
	Flush();
	*/
}
void ALogFileStatsInterface::RecordKickPlayer(AController* C, FString Reason)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 13;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, C);
	EventLine = AddField(EventLine, Reason);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordVoteKickInitiate(AAA2_PlayerState* PRI, AAA2_PlayerState* Vote, FString Reason)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 21;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, PRI);
	EventLine = AddField(EventLine, GetActorStamp(Vote));
	EventLine = AddField(EventLine, Reason);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordVoteKickCast(AAA2_PlayerState* PRI, AAA2_PlayerState* Vote)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 22;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, PRI);
	EventLine = AddField(EventLine, GetActorStamp(Vote));
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordTeamRoundBegin(ATeamInfo* t)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 31;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, t);
	EventLine = AddField(EventLine, t.Size);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordTeamRoundEnd(ATeamInfo* t, bool bWon)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 32;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, t);
	EventLine = AddField(EventLine, t.NumAlive());
	EventLine = AddField(EventLine, bWon);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordStartMatch(FString Message)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 41;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, Level);
	Logf(EventLine);
	if (Message != "")
	{
		EventLine = Message;
		Logf(EventLine);
	}
	*/
}
void ALogFileStatsInterface::RecordEndMatch(FString Message)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 42;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, Level);
	if (Message != "")
	{
		EventLine = AddField(EventLine, Message);
	}
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordStartPlayer(AController* C, FString Message)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 43;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, C);
	if (Message != "")
	{
		EventLine = AddField(EventLine, Message);
	}
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordPlayerRoundBegin(AAA2_PlayerState* PRI, ATeamInfo* t)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 51;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, PRI);
	EventLine = AddField(EventLine, GetActorStamp(t));
	EventLine = AddField(EventLine, t.GetPlayerUnitID(PRI));
	EventLine = AddField(EventLine, t.GetPlayerIndex(PRI));
	EventLine = AddField(EventLine, PRI.bIsMedic);
	EventLine = AddField(EventLine, PRI.myPawn.Location.X);
	EventLine = AddField(EventLine, PRI.myPawn.Location.Y);
	EventLine = AddField(EventLine, PRI.myPawn.Location.Z);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordPlayerRoundEnd(AAA2_PlayerState* PRI, ATeamInfo* t, bool bWon)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 52;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, PRI);
	EventLine = AddField(EventLine, GetActorStamp(t));
	EventLine = AddField(EventLine, bWon);
	EventLine = AddField(EventLine, !PRI.isDead());
	EventLine = AddField(EventLine, PRI.GetRoundScore_Total());
	EventLine = AddField(EventLine, PRI.GetRoundScore_Leadership());
	EventLine = AddField(EventLine, PRI.GetRoundScore_Wins());
	EventLine = AddField(EventLine, PRI.GetRoundScore_Objectives());
	EventLine = AddField(EventLine, PRI.GetRoundScore_Deaths());
	EventLine = AddField(EventLine, PRI.GetRoundScore_Kills());
	EventLine = AddField(EventLine, PRI.GetRoundScore_ROE());
	EventLine = AddField(EventLine, PRI.LocationX);
	EventLine = AddField(EventLine, PRI.LocationY);
	EventLine = AddField(EventLine, PRI.LocationZ);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordFireTrace(APawn* p, AWeapon* W)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 101;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, p);
	EventLine = AddField(EventLine, GetItemName(W.Class));
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationX);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationY);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationZ);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordFireProjectile(APawn* p, AWeapon* W)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 102;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, p);
	EventLine = AddField(EventLine, GetItemName(W.Class));
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationX);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationY);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationZ);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordFireThrow(APawn* p, AWeapon* W)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 103;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, p);
	EventLine = AddField(EventLine, GetItemName(W.Class));
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationX);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationY);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationZ);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordTakeDamage(APawn* p, AController* Killer, AActor* ResponsibleActor, UaDamageType* DamageType, FString BoneName, int32 DamageDealt, int32 ROE, bool bDead)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 111;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, p);
	EventLine = AddField(EventLine, GetActorStamp(Killer));
	if (ResponsibleActor != None)
	{
		EventLine = AddField(EventLine, GetItemName(ResponsibleActor.Class));
	}
	else
	{
		EventLine = AddField(EventLine, "");
	}
	if (DamageType != None)
	{
		EventLine = AddField(EventLine, GetItemName(DamageType));
	}
	else
	{
		EventLine = AddField(EventLine, "");
	}
	EventLine = AddField(EventLine, BoneName);
	EventLine = AddField(EventLine, DamageDealt);
	EventLine = AddField(EventLine, ROE);
	EventLine = AddField(EventLine, bDead);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationX);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationY);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationZ);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordKilled(APawn* p, APawn* Killer, UaDamageType* DamageType)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 112;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, p);
	EventLine = AddField(EventLine, GetActorStamp(Killer));
	EventLine = AddField(EventLine, GetItemName(DamageType));
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationX);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationY);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationZ);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordMedicTreatement(APawn* p, APawn* Healer, int32 HealthSaved, int32 Severity, int32 HealScore)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 151;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, p);
	EventLine = AddField(EventLine, GetActorStamp(Healer));
	EventLine = AddField(EventLine, HealthSaved);
	EventLine = AddField(EventLine, Severity);
	EventLine = AddField(EventLine, HealScore);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordMedicFailure(APawn* p, APawn* Healer, int32 HealthNotSaved, int32 Severity)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 152;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, p);
	EventLine = AddField(EventLine, GetActorStamp(Healer));
	EventLine = AddField(EventLine, HealthNotSaved);
	EventLine = AddField(EventLine, Severity);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordObjectiveAccomplished(APawn* p, ABaseObjective* O)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 131;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, p);
	EventLine = AddField(EventLine, O.GetAccomplishMessageByTeam(0, 0));
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationX);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationY);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationZ);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordObjectiveInterrupted(APawn* p, ABaseObjective* O)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 132;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, p);
	EventLine = AddField(EventLine, O.GetAccomplishMessageByTeam(0, 0));
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationX);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationY);
	EventLine = AddField(EventLine, p.PlayerReplicationInfo.LocationZ);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordMissionBegin(AController* C, FString Message)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 141;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	if (Message == "")
	{
		Message = "Mission Begin.";
	}
	EventLine = StartEventLine(EventKey, C);
	EventLine = AddField(EventLine, Message);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordMissionComplete(AController* C, FString Message)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 142;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	if (Message == "")
	{
		Message = "Mission Complete!";
	}
	EventLine = StartEventLine(EventKey, C);
	EventLine = AddField(EventLine, Message);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordStationComplete(AController* C, FString Message)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 143;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	if (Message == "")
	{
		Message = "Station Complete!";
	}
	EventLine = StartEventLine(EventKey, C);
	EventLine = AddField(EventLine, Message);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordCommoMessage(AController* C, AaLocalMessage* CommoType, int32 Index)
{
	/*
	local FString EventLine;
	local FString CommoHolder;
	local int EventKey;
	EventKey = 171;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, C);
	CommoHolder = CommoType;
	if (InStr(CommoHolder, "AGP.") != -1)
	{
		CommoHolder = Right(CommoHolder, Len(CommoHolder) - InStr(CommoHolder, "AGP.") + 3 - 1);
	}
	EventLine = AddField(EventLine, CommoHolder);
	EventLine = AddField(EventLine, Index);
	EventLine = AddField(EventLine, C.PlayerReplicationInfo.LocationX);
	EventLine = AddField(EventLine, C.PlayerReplicationInfo.LocationY);
	EventLine = AddField(EventLine, C.PlayerReplicationInfo.LocationZ);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordCommoSay(AController* C, FName CommoType, FString Message)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 172;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, C);
	EventLine = AddField(EventLine, CommoType);
	EventLine = AddField(EventLine, Message);
	EventLine = AddField(EventLine, C.PlayerReplicationInfo.LocationX);
	EventLine = AddField(EventLine, C.PlayerReplicationInfo.LocationY);
	EventLine = AddField(EventLine, C.PlayerReplicationInfo.LocationZ);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordPlayer(AController* C, FString Message)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 200;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	if (C != None && HumanController(C) != None)
	{
		EventLine = HumanController(C).UserName;
	}
	if (Message != "")
	{
		EventLine = AddField(EventLine, Message);
	}
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordPlayerLocation(AController* C, FString Message)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 201;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, C);
	EventLine = AddField(EventLine, C.PlayerReplicationInfo.LocationX);
	EventLine = AddField(EventLine, C.PlayerReplicationInfo.LocationY);
	EventLine = AddField(EventLine, C.PlayerReplicationInfo.LocationZ);
	if (Message != "")
	{
		EventLine = AddField(EventLine, Message);
	}
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordSpecial(AActor* A, FString Message)
{
	/*
	local FString EventLine;
	local int EventKey;
	EventKey = 999;
	if (SuppressEvent(EventKey))
	{
		Return;
	}
	EventLine = StartEventLine(EventKey, A);
	if (Message != "")
	{
		EventLine = AddField(EventLine, Message);
	}
	Logf(EventLine);
	*/
}