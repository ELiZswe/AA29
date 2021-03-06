// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/BaseStatsInterface/LogFileStatsInterface/LogFileStatsInterface.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/BaseObjective.h"
#include "AA29/Object/Actor/Info/FileLog/FileLog.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"

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
	LogFile = Spawn(AFileLog::StaticClass());
	if (LogFile == nullptr)
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
	if (LogFile != nullptr)
	{
		LogFile.CloseLog();
		LogFile.Destroy();
	}
	*/
}

FString ALogFileStatsInterface::GetLogFilename()
{
	FString Result = "";
	/*
	Result = LogFileName;
	ReplaceText(Result, "%Y", Right("00" + Level.Year, 2));
	ReplaceText(Result, "%M", Right("00" + Level.Month, 2));
	ReplaceText(Result, "%D", Right("00" + Level.Day, 2));
	ReplaceText(Result, "%H", Right("00" + Level.Hour, 2));
	ReplaceText(Result, "%I", Right("00" + Level.Minute, 2));
	ReplaceText(Result, "%S", Right("00" + Level.Second, 2));
	*/
	return Result;
}

void ALogFileStatsInterface::Logf(FString S)
{
	/*
	if (LogFile != nullptr)
	{
		LogFile.Logf(S);
	}
	*/
}
void ALogFileStatsInterface::Flush()
{
	/*
	if (LogFile != nullptr)
	{
		LogFile.FlushLog();
	}
	*/
}

FString ALogFileStatsInterface::TimeStamp()
{
	FString Seconds = "";
	/*
	Seconds = GetWorld()->GetTimeSeconds();
	if (InStr(Seconds, ".") != -1)
	{
		Seconds = Left(Seconds, InStr(Seconds, "."));
	}
	*/
	return Seconds;
}

FString ALogFileStatsInterface::Header()
{
	//return TimeStamp() + Tab;
	return "FAKE";    //FAKE  /ELiZ
}

FString ALogFileStatsInterface::SubHeader()
{
	//return TimeStamp() + Tab;
	return "FAKE";    //FAKE  /ELiZ
}

FString ALogFileStatsInterface::FullTimeDate()
{
	//return Level.Year + "-" + Level.Month + "-" + Level.Day + " " + Level.Hour + ":" + Level.Minute + ":" + Level.Second;
	return "FAKE";    //FAKE  /ELiZ
}

FString ALogFileStatsInterface::TimeZone()
{
	return "0";
}

FString ALogFileStatsInterface::MapName()
{
	FString MapName = "";
	//MapName = Level.sLevelName;
	return MapName;
}
void ALogFileStatsInterface::NewGame()
{
}
void ALogFileStatsInterface::GameInfo()
{
	FString Out = "";
	FString LevelName = "";
	FString IP = "";
	FString Port = "";
	/*
	LevelName = Level.sLevelName;
	IP = Level.GetAddressURL();
	Port = Level.Game.GetServerPort();
	Out += LevelName;
	if (Cast<AAGP_GameInfo>(GetGameMode()) != nullptr && !AGP_GameInfo(GetGameMode()).IsTrainingMission())
	{
		Out += Delimiter;
		Out += IP;
	}
	Logf(Out);
	*/
}
void ALogFileStatsInterface::ServerInfo()
{
	FString Out = "";
	FString Flags = "";
	FString siServerName = "";
	FString siAdminName = "";
	FString siAdminEmail = "";
	/*
	siServerName = GRI.ServerName;
	siAdminName = GRI.AdminName;
	siAdminEmail = GRI.AdminEmail;
	Out += TimeZone() + Delimiter;
	if (siServerName != "")
	{
		Out += siServerName + Delimiter;
	}
	if (siAdminName != "")
	{
		Out += siAdminName + Delimiter;
	}
	if (siAdminEmail != "")
	{
		Out += siAdminEmail + Delimiter;
	}
	Flags = "";
	if (Flags != "")
	{
		Out += Delimiter;
		Out += Flags;
	}
	Logf(Out);
	*/
}

void ALogFileStatsInterface::EndGame(FString Reason)
{
}

void ALogFileStatsInterface::NewLogFile(FString Filename)
{
	FString Out = "";
	float aCounter = 0;
	/*
	GRI = Level.Game.GameReplicationInfo;
	LogFile.CloseLog();
	LogFile.OpenLog(Filename, "stats");
	if (false)
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
		aCounter = Level.RealSeconds;
		Out = aCounter;
		Logf(Out);
	}
	*/
}

bool ALogFileStatsInterface::SuppressEvent(int32 EventKey)
{
	/*
	int32 i = 0;
	for (i = 0; i < SuppressStat.Num(); i++)
	{
		if (SuppressStat[i] == EventKey)
		{
			return true;
		}
	}
	*/
	return false;
}

FString ALogFileStatsInterface::GetActorStamp(AActor* Info)
{
	APlayerController* PC = nullptr;
	FString sID = "";
	/*
	if (Info->IsA(APlayerController::StaticClass()))
	{
		PC = Cast<APlayerController>(Info);
	}
	else
	{
		if (Info->IsA(APlayerReplicationInfo::StaticClass()))
		{
			PC = Cast<APlayerController>(Info.Owner);
		}
		else
		{
			if (Info->IsA(APawn::StaticClass()))
			{
				PC = Cast<APlayerController>(Cast<APawn>(Info).Controller);
			}
		}
	}
	if (PC != nullptr)
	{
		sID = PC.iUID;
		if (sID == "0")
		{
			if (Cast<AHumanController>(PC) != nullptr)
			{
				sID = Cast<AHumanController>(PC).UserName;
			}
			else
			{
				sID = PC.GetHumanReadableName();
			}
		}
	}
	else
	{
		if (Info->IsA(ATeamInfo::StaticClass()))
		{
			sID = TeamInfo(Info).TeamIndex;
		}
		else
		{
			if (Info->IsA(ALevelInfo::StaticClass()))
			{
				sID = LevelInfo(Info).sLevelName;
			}
			else
			{
				sID = "-1";
			}
		}
	}
	*/
	return sID;
}

FString ALogFileStatsInterface::GetTimeStamp()
{
	//return GetWorld()->GetTimeSeconds();
	return "FAKE";    //FAKE   /EliZ
}

FString ALogFileStatsInterface::StartEventLine(int32 Key, AActor* A)
{
	//return Key + Delimiter + GetTimeStamp() + Delimiter + Level.sLevelName + Delimiter + GetActorStamp(A);
	return "FAKE";    //FAKE   /EliZ
}

FString ALogFileStatsInterface::AddField(FString existing_line, FString Info)
{
	//return existing_line + Delimiter + Info;
	return "FAKE";    //FAKE   /EliZ
}
void ALogFileStatsInterface::NotifyRoundEnded()
{
	/*
	int32 CurrentLifespan;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 11;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
	}
	EventLine = StartEventLine(EventKey, C);
	Logf(EventLine);
	Flush();
	*/
}
void ALogFileStatsInterface::RecordLogOut(AController* C)
{
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 12;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
	}
	EventLine = StartEventLine(EventKey, C);
	Logf(EventLine);
	Flush();
	*/
}
void ALogFileStatsInterface::RecordKickPlayer(AController* C, FString Reason)
{
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 13;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
	}
	EventLine = StartEventLine(EventKey, C);
	EventLine = AddField(EventLine, Reason);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordVoteKickInitiate(AAA2_PlayerState* PRI, AAA2_PlayerState* Vote, FString Reason)
{
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 21;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
	}
	EventLine = StartEventLine(EventKey, PRI);
	EventLine = AddField(EventLine, GetActorStamp(Vote));
	EventLine = AddField(EventLine, Reason);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordVoteKickCast(AAA2_PlayerState* PRI, AAA2_PlayerState* Vote)
{
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 22;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
	}
	EventLine = StartEventLine(EventKey, PRI);
	EventLine = AddField(EventLine, GetActorStamp(Vote));
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordTeamRoundBegin(ATeamInfo* t)
{
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 31;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
	}
	EventLine = StartEventLine(EventKey, t);
	EventLine = AddField(EventLine, t.Size);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordTeamRoundEnd(ATeamInfo* t, bool bWon)
{
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 32;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
	}
	EventLine = StartEventLine(EventKey, t);
	EventLine = AddField(EventLine, t.NumAlive());
	EventLine = AddField(EventLine, bWon);
	Logf(EventLine);
	*/
}
void ALogFileStatsInterface::RecordStartMatch(FString Message)
{
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 41;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 42;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 43;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 51;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 52;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 101;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 102;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 103;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 111;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
	}
	EventLine = StartEventLine(EventKey, p);
	EventLine = AddField(EventLine, GetActorStamp(Killer));
	if (ResponsibleActor != nullptr)
	{
		EventLine = AddField(EventLine, GetItemName(ResponsibleActor.Class));
	}
	else
	{
		EventLine = AddField(EventLine, "");
	}
	if (DamageType != nullptr)
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 112;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 151;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 152;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 131;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 132;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 141;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 142;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 143;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	FString CommoHolder = "";
	int32 EventKey = 0;
	EventKey = 171;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 172;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 200;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
	}
	if (C != nullptr && Cast<AHumanController>(C) != nullptr)
	{
		EventLine = Cast<AHumanController>(C).UserName;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 201;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
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
	FString EventLine = "";
	int32 EventKey = 0;
	EventKey = 999;
	/*
	if (SuppressEvent(EventKey))
	{
		return;
	}
	EventLine = StartEventLine(EventKey, A);
	if (Message != "")
	{
		EventLine = AddField(EventLine, Message);
	}
	Logf(EventLine);
	*/
}
