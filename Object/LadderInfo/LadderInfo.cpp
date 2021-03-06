// All the original content belonged to the US Army

#include "AA29/Object/LadderInfo/LadderInfo.h"
#include "AA29/Object/GameProfile/GameProfile.h"
#include "AA29/Object/MatchInfo/MatchInfo.h"

ULadderInfo::ULadderInfo()
{
	OpenNextLadderAtRung.SetNum(5);
	UMatchInfo* CTFMatchInfo1 = NewObject<UMatchInfo>(UMatchInfo::StaticClass());
	CTFMatchInfo1->LevelName = "CTF-Maul";
	CTFMatchInfo1->EnemyTeamName = "xGame.TeamIronGuard";
	CTFMatchInfo1->GoalScore = 3;
	CTFMatchInfo1->URLString = "?mutator=xgame.mutinstagib";
	CTFMatchInfo1->MenuDescription = "Instagib!";
	CTFMatches = { CTFMatchInfo1 };
	OpenNextLadderAtRung = { 3,3,2,3,3 };
}

FString ULadderInfo::UpdateLadders(UGameProfile* G, int32 CurrentLadder)
{
	FString SpecialEvent = "";
	/*
	if (G.ladderrung[CurrentLadder] > G.CurrentMenuRung)
	{
		return "";
	}
	switch(CurrentLadder)
	{
			case 0:
				SpecialEvent = Default.DMMatches[G.ladderrung[CurrentLadder]].SpecialEvent;
				break;
			case 1:
				SpecialEvent = Default.TDMMatches[G.ladderrung[CurrentLadder]].SpecialEvent;
				break;
			case 2:
				SpecialEvent = Default.DOMMatches[G.ladderrung[CurrentLadder]].SpecialEvent;
				break;
			case 3:
				SpecialEvent = Default.CTFMatches[G.ladderrung[CurrentLadder]].SpecialEvent;
				break;
			case 4:
				SpecialEvent = Default.BRMatches[G.ladderrung[CurrentLadder]].SpecialEvent;
				break;
			case 5:
				SpecialEvent = Default.ChampionshipMatches[G.ladderrung[CurrentLadder]].SpecialEvent;
				break;
			default:
	}
	if (InStr(SpecialEvent, "OPENED") >= 0)
	{
		if (Left(SpecialEvent, 3) == "TDM")
		{
			G.ladderrung[1] = 0;
		}
		else
		{
			if (Left(SpecialEvent, 3) == "CTF")
			{
				G.ladderrung[3] = 0;
			}
			else
			{
				if (Left(SpecialEvent, 3) == "DOM")
				{
					G.ladderrung[2] = 0;
				}
				else
				{
					if (Left(SpecialEvent, 2) == "BR")
					{
						G.ladderrung[4] = 0;
					}
				}
			}
		}
	}
	G.ladderrung[CurrentLadder] += 1;
	if (G.ladderrung[5] == -1 && G.ladderrung[0] >= Default.DMMatches.Num() && G.ladderrung[1] >= Default.TDMMatches.Num() && G.ladderrung[2] >= Default.DOMMatches.Num() && G.ladderrung[3] >= Default.CTFMatches.Num() && G.ladderrung[4] >= Default.BRMatches.Num())
	{
		G.ladderrung[5] = 0;
		SpecialEvent = "CHAMPIONSHIP OPENED";
	}
	*/
	return SpecialEvent;
}

UMatchInfo* ULadderInfo::GetMatchInfo(int32 Ladder, int32 rung)
{
	TArray<UMatchInfo*> matcharray;
	if (rung < 0)
	{
		return nullptr;
	}
	switch(Ladder)
	{
		case 0:
			matcharray = GetDefault<ULadderInfo>()->DMMatches;
			break;
		case 1:
			matcharray = GetDefault<ULadderInfo>()->TDMMatches;
			break;
		case 2:
			matcharray = GetDefault<ULadderInfo>()->DOMMatches;
			break;
		case 3:
			matcharray = GetDefault<ULadderInfo>()->CTFMatches;
			break;
		case 4:
			matcharray = GetDefault<ULadderInfo>()->BRMatches;
			break;
		case 5:
			matcharray = GetDefault<ULadderInfo>()->ChampionshipMatches;
			break;
		default:
			break;
	}
	if (matcharray.Max() <= 0)
	{
		return nullptr;
	}
	if (rung >= matcharray.Max())
	{
		return matcharray[matcharray.Max() - 1];
	}
	return matcharray[rung];
}

UMatchInfo* ULadderInfo::GetCurrentMatchInfo(UGameProfile* G)
{
	return GetMatchInfo(G->CurrentLadder, G->CurrentMenuRung);
}

FString ULadderInfo::MakeURLFor(UGameProfile* G)
{
	FString URL = "";
	UMatchInfo* M;
	M = GetCurrentMatchInfo(G);
	/*
	if (M == nullptr)
	{
		Log("SINGLEPLAYER LadderInfo::MakeURLFor MatchInfo invalid.");
		return "";
	}
	G.EnemyTeam = M.EnemyTeamName;
	G.Difficulty = G.BaseDifficulty + M.DifficultyModifier;
	URL = M.LevelName + "?Name=" + G.PlayerName + "?Character=" + G.PlayerCharacter + "?SaveGame=" + G.PackageName + M.URLString;
	if (M.GoalScore != 0)
	{
		URL = URL + "?GoalScore=" + M.GoalScore;
	}
	if (M.NumBots > 0)
	{
		URL = URL + "?NumBots=" + M.NumBots;
	}
	if (M.GameType != "")
	{
		URL = URL + "?Game=" + M.GameType;
	}
	URL = URL + "?Team=1";
	*/
	return URL;
}
FString ULadderInfo::GetMatchDescription(UGameProfile* G)
{
	FString retval;
	switch(G->CurrentLadder)
	{
		case 0:
			retval = "Deathmatch";
			break;
		case 1:
			retval = "Team Deathmatch";
			break;
		case 2:
			retval = "Domination";
			break;
		case 3:
			retval = "Capture the Flag";
			break;
		case 4:
			retval = "Bombing Run";
			break;
		case 5:
			retval = "Championship Match";
			break;
		default:
			break;
	}
	return retval;
}
int32 ULadderInfo::LengthOfLadder(int32 Ladder)
{
	switch (Ladder)
	{
		case 0:
			return GetDefault<ULadderInfo>()->DMMatches.Max();
		case 1:
			return GetDefault<ULadderInfo>()->TDMMatches.Max();
		case 2:
			return GetDefault<ULadderInfo>()->DOMMatches.Max();
		case 3:
			return GetDefault<ULadderInfo>()->CTFMatches.Max();
		case 4:
			return GetDefault<ULadderInfo>()->BRMatches.Max();
		case 5:
			return GetDefault<ULadderInfo>()->ChampionshipMatches.Max();
		default:
			return - 1;
	}
}
