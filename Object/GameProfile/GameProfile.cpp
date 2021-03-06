// All the original content belonged to the US Army

#include "AA29/Object/GameProfile/GameProfile.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/Object/LadderInfo/LadderInfo.h"
#include "AA29/Object/MatchInfo/MatchInfo.h"

UGameProfile::UGameProfile()
{
	PlayerLineup.SetNum(4);
	PositionName.SetNum(5);
	PackageName     = "Default";
	PositionName    = { "AUTO-ASSIGN",	"DEFENSE", "OFFENSE","ROAM","SUPPORT" };
	PlayerLineup    = { 1, 2, 3 };
	BaseDifficulty  = 1;
	PlayerName      = "Name";
	PlayerCharacter = "Roc";
	ladderrung      = { 0, -1,-1,-1,-1,-1 };
	GameLadderName  = "Engine.LadderInfo";

	PlayerPositions.SetNum(7);
	ladderrung.SetNum(6);
}

void UGameProfile::Initialize(AGameModeBase * currentGame, FString pn)
{
	AController* C = nullptr;
	if (GameLadder == nullptr)
	{
		//GameLadder = class<LadderInfo>(DynamicLoadObject(GameLadderName, Class'Class'));
	}
	PackageName = pn;
	PlayerName = pn;
	//C = currentGame->Level->ControllerList;
	if (C != nullptr)
	{
		if (Cast<APlayerController>(C) != nullptr)
		{
			currentGame->ChangeName(Cast<APlayerController>(C), PlayerName, false);
		}
		else
		{
			//C = C->nextController;
		}
	}
	NextMatchObject = nullptr;
	ChampBorderObject = nullptr;
}

void UGameProfile::CheatSkipMatch(AGameModeBase* currentGame)
{
	SpecialEvent = GameLadder->UpdateLadders(this, CurrentLadder);
	//ContinueSinglePlayerGame(currentGame->Level);
}

void UGameProfile::CheatJumpMatch(AGameModeBase* currentGame, int32 Param)
{
	AController* C = nullptr;
	int32 newladder = 0;
	int32 newrung = 0;
	newladder = Param / 10;
	newrung = Param - newladder * 10;
	if (newladder < 0 || newladder >= 6 || newrung < 0)
	{
		return;
	}
	bInLadderGame = true;
	CurrentLadder = newladder;
	ladderrung[CurrentLadder] = newrung;
	CurrentMenuRung = newrung;
	//C = currentGame->Level->ControllerList;
	if (C != nullptr)
	{
		if (Cast<APlayerController>(C) != nullptr)
		{
			//Cast<APlayerController>(C)->ConsoleCommand("START" @ GameLadder.MakeURLFor(this));
		}
		else
		{
			//C = C->nextController;
		}
	}
}

UMatchInfo* UGameProfile::GetMatchInfo(int32 Ladder, int32 rung)
{
	if (GameLadder != nullptr)
	{
		return GameLadder->GetMatchInfo(Ladder, rung);
	}
	else
	{
		return nullptr;
	}
}

void UGameProfile::RegisterGame(AGameModeBase* currentGame, APlayerState* PRI)
{
	//Log("SINGLEPLAYER GameProfile::RegisterGame for profile" @ Self.PackageName);
	//Kills += PRI->Kills;
	//Goals += PRI->GoalsScored;
	Matches++;
	if (bWonMatch)
	{
		SpecialEvent = GameLadder->UpdateLadders(this, CurrentLadder);
		Wins++;
	}
	bWonMatch = false;
}

void UGameProfile::StartNewMatch(int32 PickedLadder, AAA2_WorldSettings* CurrentLevel)
{
	AController* C = nullptr;
	bWonMatch = false;
	bInLadderGame = true;
	CurrentLadder = PickedLadder;
	//CurrentLevel->Game->SavePackage(PackageName);
	C = CurrentLevel->ControllerList;
	if (C != nullptr)
	{
		if (Cast<APlayerController>(C) != nullptr)
		{
			//Cast<APlayerController>(C)->ConsoleCommand("START" + GameLadder.MakeURLFor(this));
		}
		else
		{
			//C = C->nextController;
		}
	}
}

int32 UGameProfile::FindFirstUnfinishedLadder()
{
	int32 i = 0;
	for (i = 0; i < 6; i++)
	{
		if (ladderrung[i] < GameLadder->LengthOfLadder(i))
		{
			return i;
		}
	}
	return 0;
}

void UGameProfile::ContinueSinglePlayerGame(AAA2_WorldSettings* Level, bool bReplace)
{
	//Level.Game.SavePackage(PackageName);
	StartNewMatch(FindFirstUnfinishedLadder(), Level);
}

FString UGameProfile::GetMatchDescription()
{
	return GameLadder->GetMatchDescription(this);
}

int32 UGameProfile::GetNumPositions()
{
	return 5;
}

int32 UGameProfile::GetNumTeammatesForMatch()
{
	UMatchInfo* M = nullptr;
	M = GameLadder->GetCurrentMatchInfo(this);
	if (M->GameType.Compare("xGame.xDeathmatch",ESearchCase::IgnoreCase) || M->GameType.Compare("xGame.BossDM",ESearchCase::IgnoreCase))
	{
		return 0;
	}
	else
	{
		return M->NumBots / 2;
	}
}

FString UGameProfile::TextPositionDescription(int32 posnval)
{
	FString retval = "";
	if (posnval < 0 || posnval > 5)
	{
		return "Error";
	}
	switch(posnval)
	{
		case 0:
			retval = GetDefault<UGameProfile>()->PositionName[0];
			break;
		case 1:
			retval = GetDefault<UGameProfile>()->PositionName[1];
			break;
		case 2:
			retval = GetDefault<UGameProfile>()->PositionName[2];
			break;
		case 3:
			retval = GetDefault<UGameProfile>()->PositionName[3];
			break;
		case 4:
			retval = GetDefault<UGameProfile>()->PositionName[4];
			break;
		default:
			break;
	}
	return retval;
}

EPlayerPos UGameProfile::EnumPositionDescription(FString posnval)
{
	EPlayerPos retval = EPlayerPos::POS_Auto;
	if (posnval == GetDefault<UGameProfile>()->PositionName[0])
	{
		retval = EPlayerPos::POS_Auto;
	}
	else
	{
		if (posnval == GetDefault<UGameProfile>()->PositionName[1])
		{
			retval = EPlayerPos::POS_Defense;
		}
		else
		{
			if (posnval == GetDefault<UGameProfile>()->PositionName[2])
			{
				retval = EPlayerPos::POS_Offense;
			}
			else
			{
				if (posnval == GetDefault<UGameProfile>()->PositionName[3])
				{
					retval = EPlayerPos::POS_Roam;
				}
				else
				{
					if (posnval == GetDefault<UGameProfile>()->PositionName[4])
					{
						retval = EPlayerPos::POS_Supporting;
					}
					else
					{
						retval = EPlayerPos::POS_Auto;
					}
				}
			}
		}
	}
	return retval;
}

FString UGameProfile::GetPositionDescription(int32 PlayerNum)
{
	if (PlayerNum < 0 || PlayerNum >= 7)
	{
		return "Error";
	}
	//return TextPositionDescription(PlayerPositions[PlayerNum]);
	return "FAKE";     //FAKE   /ELiZ
}

void UGameProfile::SetPosition(int32 lineupnum, FString posn)
{
	if (lineupnum >= 0 && lineupnum < 4)
	{
		PlayerPositions[PlayerLineup[lineupnum]] = EnumPositionDescription(posn);
	}
}

void UGameProfile::SetLineup(int32 lineuppos, int32 teampos)
{
	int32 oldlineuppos = 0;
	int32 oldteammate = 0;
	int32 i = 0;
	if (lineuppos < 0 || lineuppos > 4)
	{
		return;
	}
	if (teampos < 0 || teampos >= 7)
	{
		return;
	}
	if (PlayerLineup[lineuppos] == teampos)
	{
		return;
	}
	oldlineuppos = -1;
	i = 0;
	if (i < 4)
	{
		if (PlayerLineup[i] == teampos)
		{
			oldlineuppos = i;
		}
		else
		{
			i++;
		}
	}
	if (oldlineuppos >= 0)
	{
		oldteammate = PlayerLineup[lineuppos];
	}
	PlayerLineup[lineuppos] = teampos;
	if (oldlineuppos >= 0)
	{
		PlayerLineup[oldlineuppos] = oldteammate;
	}
}

bool UGameProfile::AddTeammate(FString botname)
{
	int32 i = 0;
	if (botname == "")
	{
		return false;
	}
	for (i = 0; i < 7; i++)
	{
		if (i >= PlayerTeam.Num() || PlayerTeam[i] == "")
		{
			PlayerTeam[i] = botname;
			return true;
		}
		if (PlayerTeam[i].Compare(botname,ESearchCase::IgnoreCase))
		{
			return false;
		}
	}
	return false;
}

bool UGameProfile::ReleaseTeammate(FString botname)
{
	int32 i = 0;
	int32 j = 0;
	if (botname == "")
	{
		return false;
	}
	for (i = 0; i < PlayerTeam.Num(); i++)
	{
		if (PlayerTeam[i].Compare(botname,ESearchCase::IgnoreCase))
		{
			j = i;
			if (j < PlayerTeam.Num() - 1)
			{
				PlayerTeam[j] = PlayerTeam[j + 1];
				j++;
			}
			PlayerTeam[PlayerTeam.Num() - 1] = "";
			return true;
		}
	}
	return false;
}

void UGameProfile::ClearTeammates()
{
	int32 i = 0;
	for (i = 0; i < PlayerTeam.Max(); i++)
	{
		PlayerTeam[i] = "";
	}
}

void UGameProfile::ReportCheat(APlayerController* Cheater, FString cheat)
{
}

bool UGameProfile::CanChangeTeam(AController* Other, int NewTeam)
{
	return true;
}
