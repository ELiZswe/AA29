// All the original content belonged to the US Army


#include "AA29/Info/LocalMessage/CommoLocalMessage/CommoEventRadio/CommoEventRadio.h"

ACommoEventRadio::ACommoEventRadio()
{
	MsgMissionCompleted = 1;
	MsgMissionFailed = 2;
	MsgSquadDead = 3;
	MsgEnemyDead = 4;
	MsgTimeLimit = 5;
	MsgMissionImpossible = 6;
	MsgStatic = 7;
	Punctuation = "";
	Messaged = "radioed";
	_iNumMessages = 8;
	_Messages = {"Watch your fire!",	"Mission Completed",	"Mission Failed",	"Your squad has been eliminated",	"Opposing forces eliminated",	"Time Limit Exceeded",	"Mission can no longer be completed"};
	_messagename = "EventRadio";
	_Sounds1 = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_WatchYourFire_Cue.SquadLeader_Radio_WatchYourFire_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_MissionComplete_Cue.SquadLeader_Radio_MissionComplete_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_MissionFailed_Cue.SquadLeader_Radio_MissionFailed_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_YourSquadHasBeenEliminated_Cue.SquadLeader_Radio_YourSquadHasBeenEliminated_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_OpposingForcesEliminated_Cue.SquadLeader_Radio_OpposingForcesEliminated_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_TimeLimitExceeded_Cue.SquadLeader_Radio_TimeLimitExceeded_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_MissionCanNoLongerBeCompleted_Cue.SquadLeader_Radio_MissionCanNoLongerBeCompleted_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL)
	};
	_Sounds2 = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_WatchYourFire_Cue.SquadLeader_Radio_WatchYourFire_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_MissionComplete_Cue.SquadLeader_Radio_MissionComplete_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_MissionFailed_Cue.SquadLeader_Radio_MissionFailed_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_YourSquadHasBeenEliminated_Cue.SquadLeader_Radio_YourSquadHasBeenEliminated_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_OpposingForcesEliminated_Cue.SquadLeader_Radio_OpposingForcesEliminated_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_TimeLimitExceeded_Cue.SquadLeader_Radio_TimeLimitExceeded_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_MissionCanNoLongerBeCompleted_Cue.SquadLeader_Radio_MissionCanNoLongerBeCompleted_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL)
	};
	_Sounds3 = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_WatchYourFire_Cue.SquadLeader_Radio_WatchYourFire_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_MissionComplete_Cue.SquadLeader_Radio_MissionComplete_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_MissionFailed_Cue.SquadLeader_Radio_MissionFailed_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_YourSquadHasBeenEliminated_Cue.SquadLeader_Radio_YourSquadHasBeenEliminated_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_OpposingForcesEliminated_Cue.SquadLeader_Radio_OpposingForcesEliminated_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_TimeLimitExceeded_Cue.SquadLeader_Radio_TimeLimitExceeded_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_MissionCanNoLongerBeCompleted_Cue.SquadLeader_Radio_MissionCanNoLongerBeCompleted_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL)
	};
	_fSoundVolume = 0.75;
	_fEnemyTravelDistance = 300;
	_commotype = ECommoType::COMMOTYPE_Radio;
	bNo3D = true;
}

void ACommoEventRadio::GetAnim(int32 Switch)
{
	//Return 'None';
}
void ACommoEventRadio::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	//Return GetMessage(Switch);
}