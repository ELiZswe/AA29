// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/AI_Interface/AI_Overlord/AI_Overlord.h"

AAI_Overlord::AAI_Overlord()
{

}

void AAI_Overlord::GetTeam(ETeam Team)
{
	/*
	local TeamHandler temp_team;
	if (TopTeam == None)
	{
		return None;
	}
	temp_team = TopTeam;
	if (temp_team != None)
	{
		if (temp_team.team_id == Team)
		{
			return temp_team;
		}
		temp_team = TeamHandler(temp_team.nextTeam);
	}
	return None;
	*/
}
void AAI_Overlord::createTeam(ETeam Team)
{
	/*
	local TeamHandler temp_team;
	temp_team = new (None) class'TeamHandler';
	temp_team.team_id = Team;
	if (TopTeam == None)
	{
		TopTeam = temp_team;
		BottomTeam = temp_team;
		DebugLog(DEBUG_AI, "dnback:: AI_Overlord.createTeam(); no teams yet, creating " $ TopTeam);
	}
	else
	{
		BottomTeam.nextTeam = temp_team;
		BottomTeam = temp_team;
		Log("dnback:: AI_Overlord.createTeam(); adding " $ TopTeam $ " to the team list");
	}
	return temp_team;
	*/
}
void AAI_Overlord::getOrCreateTeam(ETeam Team)
{
	/*
	local TeamHandler temp_team;
	temp_team = GetTeam(Team);
	if (temp_team != None)
	{
		DebugLog(DEBUG_AI, "dnback:: AI_Overlord.getOrCreateTeam(); found team " $ temp_team $ " for this Pawn");
		return temp_team;
	}
	else
	{
		return createTeam(Team);
	}
	*/
}
void AAI_Overlord::Init()
{
	/*
	local AGP.AGP_Pawn lAGP_Pawn;
	local TeamHandler lTeam;
	local int Count;
	Count = 0;
	DebugLog(DEBUG_AI, "dnback:: AI_Overlord::init(); starting initialization of team");
	ForEach DynamicActors(Class'AGP_Pawn', lAGP_Pawn)
	{
		lAGP_Pawn.UID = Count;
		lTeam = getOrCreateTeam(lAGP_Pawn.idTeam);
		lTeam.addPawn(lAGP_Pawn);
		Count++;
	}
	DebugLog(DEBUG_AI, "dnback:: AI_Overlord::init(); went through " $ Count $ " APG_Pawns");
	lTeam = TopTeam;
	if (lTeam != None)
	{
		lTeam.Init();
		DebugLog(DEBUG_AI, "AI_Overlord::init()	Initialized Team " $ lTeam.team_id);
		lTeam = TeamHandler(lTeam.nextTeam);
	}
	*/
}
