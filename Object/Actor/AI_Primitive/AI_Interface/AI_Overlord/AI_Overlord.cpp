// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/AI_Interface/AI_Overlord/AI_Overlord.h"
#include "AA29/Object/Team_Interface/TeamHandler/TeamHandler.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AAI_Overlord::AAI_Overlord()
{

}

UTeamHandler* AAI_Overlord::GetTeam(ETeam Team)
{
	UTeamHandler* temp_team = nullptr;
	if (TopTeam == nullptr)
	{
		return nullptr;
	}
	temp_team = TopTeam;
	if (temp_team != nullptr)
	{
		if (temp_team->team_id == Team)
		{
			return temp_team;
		}
		temp_team = Cast<UTeamHandler>(temp_team->nextTeam);
	}
	return nullptr;
}

UTeamHandler* AAI_Overlord::createTeam(ETeam Team)
{
	UTeamHandler* temp_team = nullptr;
	/*
	temp_team = new (None) UTeamHandler::StaticClass();
	temp_team.team_id = Team;
	if (TopTeam == nullptr)
	{
		TopTeam = temp_team;
		BottomTeam = temp_team;
		DebugLog(DEBUG_AI, "dnback:: AI_Overlord.createTeam(); no teams yet, creating " + TopTeam);
	}
	else
	{
		BottomTeam.nextTeam = temp_team;
		BottomTeam = temp_team;
		Log("dnback:: AI_Overlord.createTeam(); adding " + TopTeam + " to the team list");
	}
	*/
	return temp_team;
}

UTeamHandler* AAI_Overlord::getOrCreateTeam(ETeam Team)
{
	UTeamHandler* temp_team = nullptr;
	temp_team = GetTeam(Team);
	if (temp_team != nullptr)
	{
		//DebugLog(DEBUG_AI, "dnback:: AI_Overlord.getOrCreateTeam(); found team " + temp_team + " for this Pawn");
		return temp_team;
	}
	else
	{
		return createTeam(Team);
	}
}
void AAI_Overlord::Init()
{
	AAGP_Pawn* lAGP_Pawn = nullptr;
	UTeamHandler* lTeam = nullptr;
	int32 Count = 0;
	Count = 0;
	/*
	DebugLog(DEBUG_AI, "dnback:: AI_Overlord::init(); starting initialization of team");
	ForEach DynamicActors(AAGP_Pawn::StaticClass(), lAGP_Pawn)
	{
		lAGP_Pawn.UID = Count;
		lTeam = getOrCreateTeam(lAGP_Pawn.idTeam);
		lTeam.addPawn(lAGP_Pawn);
		Count++;
	}
	DebugLog(DEBUG_AI, "dnback:: AI_Overlord::init(); went through " + Count + " APG_Pawns");
	lTeam = TopTeam;
	if (lTeam != nullptr)
	{
		lTeam.Init();
		DebugLog(DEBUG_AI, "AI_Overlord::init()	Initialized Team " + lTeam.team_id);
		lTeam = TeamHandler(lTeam.nextTeam);
	}
	*/
}
