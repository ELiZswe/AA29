// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/GameMessage/GameMessage.h"

AGameMessage::AGameMessage()
{
	
	SwitchLevelMessage = "Switching Levels";
	LeftMessage = " left the game.";
	FailedTeamMessage = "Could not find team for player";
	FailedPlaceMessage = "Could not find a starting spot";
	FailedSpawnMessage = "Could not spawn player";
	EnteredMessage = " entered the game.";
	MaxedOutMessage = "Server is already at capacity.";
	OvertimeMessage = "Score tied at the end of regulation. Sudden Death Overtime!!!";
	GlobalNameChange = "changed name to";
	NewTeamMessage = "is now on";
	NoNameChange = "Name is already in use.";
	VoteStarted = "started a vote.";
	VotePassed = "Vote passed.";
	MustHaveStats = "Must have stats enabled to join this server.";
	CantBeSpectator = "Sorry, you cannot become a spectator at this time.";
	CantBePlayer = "Sorry, you cannot become an active player at this time.";
	BecameSpectator = "became a spectator.";
	NewPlayerMessage = "A new player entered the game.";
	KickWarning = "You are about to be kicked for idling!";
	NewSpecMessage = "A spectator entered the game/";
	SpecEnteredMessage = " joined as a spectator.";
	bIsSpecial = false;
}

void AGameMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	Return "";
	*/
}