// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ScoreBoard/AGP_Scoreboard/AGP_ScoreboardTeamDM/AGP_ScoreboardTeamObjective/AGP_ScoreboardTeamObjective.h"

AAGP_ScoreboardTeamObjective::AAGP_ScoreboardTeamObjective()
{
	ObjString = "Goals";
	LeaderString = "Leader";
	ObjPos = 0.51;
	LeaderPos = 0.58;
	FFPos = 0.79;
	TotalPos = 0.44;
	FragsPos = 0.65;
	DeathsPos = 0.72;
	PingPos = 0.86;
	iMaxNameLen = 20;
}

void AAGP_ScoreboardTeamObjective::DrawCategoryHeaders(UCanvas* Canvas)
{
	float offset = 0;
	float XL = 0;
	float YL = 0;
	/*
	offset = Canvas.CurY;
	DrawCategoryHeaders(Canvas);
	Canvas.StrLen(ObjString, XL, YL);
	Canvas.SetPos(Canvas.SizeX * ObjPos - XL * 0.5, offset);
	Canvas.DrawText(ObjString);
	Canvas.StrLen(LeaderString, XL, YL);
	Canvas.SetPos(Canvas.SizeX * LeaderPos - XL * 0.5, offset);
	Canvas.DrawText(LeaderString);
	*/
}

void AAGP_ScoreboardTeamObjective::DrawNameAndPing(UCanvas* Canvas, AAA2_PlayerState* PRI, float XOffset, float YOffset)
{
	float XL = 0;
	float YL = 0;
	/*
	DrawNameAndPing(Canvas, PRI, XOffset, YOffset);
	Canvas.DrawColor = DeterminePlayerColor(PRI);
	Canvas.StrLen(PRI.GetGoalScore(), XL, YL);
	Canvas.SetPos(Canvas.SizeX * ObjPos - XL, YOffset);
	Canvas.DrawText(PRI.GetGoalScore(), false);
	Canvas.StrLen(PRI.Score_Leadership, XL, YL);
	Canvas.SetPos(Canvas.SizeX * LeaderPos - XL, YOffset);
	Canvas.DrawText(PRI.Score_Leadership, false);
	*/
}

int32 AAGP_ScoreboardTeamObjective::CompareScores(AAA2_PlayerState* PRI1, AAA2_PlayerState* PRI2)
{
	AAA2_PlayerState* TempPRI=nullptr;
	int32 TeamOwner = 0;
	if (PRI1 == PRI2)
	{
		return 0;
	}
	/*
	if (PRI1.Team.TeamIndex != 255 && PRI2.Team.TeamIndex == 255)
	{
		return 1;
	}
	if (PRI1.Team.TeamIndex == 255 && PRI2.Team.TeamIndex != 255)
	{
		return - 1;
	}
	TeamOwner = GetTeamOrVirtualTeam();
	if (PRI1.Team.TeamIndex == TeamOwner && PRI2.Team.TeamIndex != TeamOwner)
	{
		return 1;
	}
	if (PRI1.Team.TeamIndex != TeamOwner && PRI2.Team.TeamIndex == TeamOwner)
	{
		return - 1;
	}
	if (PRI1.Team.TeamIndex == PlayerOwner.PlayerReplicationInfo.Team.TeamIndex)
	{
		TempPRI = PRI1.GetSquadLeader();
		if (PRI1 == TempPRI)
		{
			return 1;
		}
		if (PRI2 == TempPRI)
		{
			return - 1;
		}
		if (PRI1.isTeamLeader() && !PRI2.isTeamLeader())
		{
			return 1;
		}
		if (!PRI1.isTeamLeader() && PRI2.isTeamLeader())
		{
			return - 1;
		}
	}
	if (PRI1.Score_Total != PRI2.Score_Total)
	{
		return PRI1.Score_Total - PRI2.Score_Total;
	}
	if (PRI1.PlayerName <= PRI2.PlayerName)
	{
		return 1;
	}
	else
	{
		return - 1;
	}
	*/
	return 0;      //FAKE   /ELiZ
}
