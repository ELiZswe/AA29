// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoSquad/CommoSquad.h"

ACommoSquad::ACommoSquad()
{
	Punctuation = "";
	Messaged = "radioed";
	_iNumMessages = 18;
	_Messages = { "Squad, Form Up!","Squad, Spread Out.","Fall back!  Fall back!","Squad, Open Fire.","Cease Fire, Cease Fire!","Squad, Hold This Position.","Squad, Report In.","Squad, Silence, Silence!","Squad, Operate As A Unit.","There's no I in team.","That may be your way, but that's not the Army way...","What are you doing, soldier!?","Hit The Dirt!","Stay Down!","Grandma was slow, but she was old...","That don't make no sense at all...","Good job, soldier!","Great job, team!","Squad, Check Your Objectives."};
	_messagename = "Squad Radio";
	_Sounds1 = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_FormUp_Cue.SquadLeader_Radio_FormUp_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_SpreadOut_Cue.SquadLeader_Radio_SpreadOut_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_FallBack_Cue.SquadLeader_Radio_FallBack_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_OpenFire_Cue.SquadLeader_Radio_OpenFire_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_CeaseFire_Cue.SquadLeader_Radio_CeaseFire_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_HoldThisPosition_Cue.SquadLeader_Radio_HoldThisPosition_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_ReportIn_Cue.SquadLeader_Radio_ReportIn_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_Silence_Cue.SquadLeader_Radio_Silence_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_OperateAsAUnit_Cue.SquadLeader_Radio_OperateAsAUnit_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_TheresNoIinTeam_Cue.SquadLeader_Radio_TheresNoIinTeam_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_ThatMayBeYourWay_Cue.SquadLeader_Radio_ThatMayBeYourWay_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_WhatAreYouDoingSoldier_Cue.SquadLeader_Radio_WhatAreYouDoingSoldier_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_HitTheDirt_Cue.SquadLeader_Radio_HitTheDirt_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_StayDown_Cue.SquadLeader_Radio_StayDown_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_Grandma_Cue.SquadLeader_Radio_Grandma_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_ThatDontMakeNoSenseatAll_Cue.SquadLeader_Radio_ThatDontMakeNoSenseatAll_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_GoodJobSoldier_Cue.SquadLeader_Radio_GoodJobSoldier_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_GreatJobTeam_Cue.SquadLeader_Radio_GreatJobTeam_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/SquadLeader/SquadLeader_Radio_CheckYourObjective_Cue.SquadLeader_Radio_CheckYourObjective_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL)
	};

	_Sounds2 = {
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL)
	};
	_Sounds3 = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/commo_keymicrophone_Cue.commo_keymicrophone_Cue"), NULL, LOAD_None, NULL)
	};


	_fEnemyTravelDistance = 300;
	_commotype = ECommoType::COMMOTYPE_Squad;
		bNo3D = true;

}


void ACommoSquad::GetAnim(int32 Switch)
{
	//Return 'None';
}