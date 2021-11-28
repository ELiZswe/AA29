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
	/*
	local float offset;
	local float XL;
	local float YL;
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
	/*
	local float XL;
	local float YL;
	DrawNameAndPing(Canvas, PRI, XOffset, YOffset);
	Canvas.DrawColor = DeterminePlayerColor(PRI);
	Canvas.StrLen(PRI.GetGoalScore(), XL, YL);
	Canvas.SetPos(Canvas.SizeX * ObjPos - XL, YOffset);
	Canvas.DrawText(PRI.GetGoalScore(), False);
	Canvas.StrLen(PRI.Score_Leadership, XL, YL);
	Canvas.SetPos(Canvas.SizeX * LeaderPos - XL, YOffset);
	Canvas.DrawText(PRI.Score_Leadership, False);
	*/
}

int32 AAGP_ScoreboardTeamObjective::CompareScores(AAA2_PlayerState* PRI1, AAA2_PlayerState* PRI2)
{
	AAA2_PlayerState* TempPRI=nullptr;
	/*
	local int TeamOwner;
	if (PRI1 == PRI2)
	{
		Return 0;
	}
	if (PRI1.Team.TeamIndex != 255 && PRI2.Team.TeamIndex == 255)
	{
		Return 1;
	}
	if (PRI1.Team.TeamIndex == 255 && PRI2.Team.TeamIndex != 255)
	{
		Return - 1;
	}
	TeamOwner = GetTeamOrVirtualTeam();
	if (PRI1.Team.TeamIndex == TeamOwner && PRI2.Team.TeamIndex != TeamOwner)
	{
		Return 1;
	}
	if (PRI1.Team.TeamIndex != TeamOwner && PRI2.Team.TeamIndex == TeamOwner)
	{
		Return - 1;
	}
	if (PRI1.Team.TeamIndex == PlayerOwner.PlayerReplicationInfo.Team.TeamIndex)
	{
		TempPRI = PRI1.GetSquadLeader();
		if (PRI1 == TempPRI)
		{
			Return 1;
		}
		if (PRI2 == TempPRI)
		{
			Return - 1;
		}
		if (PRI1.isTeamLeader() && !PRI2.isTeamLeader())
		{
			Return 1;
		}
		if (!PRI1.isTeamLeader() && PRI2.isTeamLeader())
		{
			Return - 1;
		}
	}
	if (PRI1.Score_Total != PRI2.Score_Total)
	{
		Return PRI1.Score_Total - PRI2.Score_Total;
	}
	if (PRI1.PlayerName <= PRI2.PlayerName)
	{
		Return 1;
	}
	else
	{
		Return - 1;
	}
	*/
	return 0;      //FAKE   /ELiZ
}