// All the original content belonged to the US Army


#include "AA29/Info/LocalMessage/CommoLocalMessage/CommoShout/CommoShout.h"



ACommoShout::ACommoShout()
{
	Punctuation = "!";
	Messaged = "shouted";
	_iNumMessages = 27;
	_Messages = { "Move out","Stop","Cover Me","Enemy Spotted","Take Cover","Enemy Down","Area Secure","Roger","Negative","Up","Down","Left","Right","North","South","East","West","Hooah","Sniper","Frag 'em","Smoke 'em","Flash 'em","Grenade","Ready","I'm Hit","Get The Door","Check Your Flanks","Frag Out!","","Medic on the way!","Hold still so I can treat you!","Medic!" };
	_messagename = "Shouted Message";
	_Sounds1 = {
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_MoveOut_Cue.Voice1_Shout_MoveOut_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Stop_Cue.Voice1_Shout_Stop_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_CoverMe_Cue.Voice1_Shout_CoverMe_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_EnemySpotted_Cue.Voice1_Shout_EnemySpotted_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_TakeCover_Cue.Voice1_Shout_TakeCover_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_EnemyDown_Cue.Voice1_Shout_EnemyDown_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_AreaSecure_Cue.Voice1_Shout_AreaSecure_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Roger_Cue.Voice1_Shout_Roger_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Negative_Cue.Voice1_Shout_Negative_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Up_Cue.Voice1_Shout_Up_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Down_Cue.Voice1_Shout_Down_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Left_Cue.Voice1_Shout_Left_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Right_Cue.Voice1_Shout_Right_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_North_Cue.Voice1_Shout_North_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_South_Cue.Voice1_Shout_South_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_East_Cue.Voice1_Shout_East_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_West_Cue.Voice1_Shout_West_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Hooah_Cue.Voice1_Shout_Hooah_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Sniper_Cue.Voice1_Shout_Sniper_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Frag_Cue.Voice1_Shout_Frag_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Smoke_Cue.Voice1_Shout_Smoke_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Flash_Cue.Voice1_Shout_Flash_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Grenade_Cue.Voice1_Shout_Grenade_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Ready_Cue.Voice1_Shout_Ready_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_ImHit_Cue.Voice1_Shout_ImHit_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_GetTheDoor_Cue.Voice1_Shout_GetTheDoor_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_CheckYourFlanks_Cue.Voice1_Shout_CheckYourFlanks_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_FragOut_Cue.Voice1_Shout_FragOut_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Stop_Cue.Voice1_Shout_Stop_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Medic_Cue.Voice1_Shout_Medic_Cue"), NULL, LOAD_None, NULL)
	};
	_Sounds2 = {
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_MoveOut_Cue.Voice2_Shout_MoveOut_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Stop_Cue.Voice2_Shout_Stop_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_CoverMe_Cue.Voice2_Shout_CoverMe_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_EnemySpotted_Cue.Voice2_Shout_EnemySpotted_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_TakeCover_Cue.Voice2_Shout_TakeCover_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_EnemyDown_Cue.Voice2_Shout_EnemyDown_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_AreaSecure_Cue.Voice2_Shout_AreaSecure_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Roger_Cue.Voice2_Shout_Roger_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Negative_Cue.Voice2_Shout_Negative_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Up_Cue.Voice2_Shout_Up_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Down_Cue.Voice2_Shout_Down_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Left_Cue.Voice2_Shout_Left_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Right_Cue.Voice2_Shout_Right_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_North_Cue.Voice2_Shout_North_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_South_Cue.Voice2_Shout_South_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_East_Cue.Voice2_Shout_East_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_West_Cue.Voice2_Shout_West_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Hooah_Cue.Voice2_Shout_Hooah_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Sniper_Cue.Voice2_Shout_Sniper_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Frag_Cue.Voice2_Shout_Frag_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Smoke_Cue.Voice2_Shout_Smoke_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Flash_Cue.Voice2_Shout_Flash_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Grenade_Cue.Voice2_Shout_Grenade_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Ready_Cue.Voice2_Shout_Ready_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_ImHit_Cue.Voice2_Shout_ImHit_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_GetTheDoor_Cue.Voice2_Shout_GetTheDoor_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_CheckYourFlanks_Cue.Voice2_Shout_CheckYourFlanks_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_FragOut_Cue.Voice2_Shout_FragOut_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Stop_Cue.Voice2_Shout_Stop_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Medic_Cue.Voice2_Shout_Medic_Cue"), NULL, LOAD_None, NULL),
	};
	_Sounds3 = {
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_MoveOut_Cue.Voice3_Shout_MoveOut_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Stop_Cue.Voice3_Shout_Stop_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_CoverMe_Cue.Voice3_Shout_CoverMe_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_EnemySpotted_Cue.Voice3_Shout_EnemySpotted_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover_Cue.Voice3_Shout_TakeCover_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_EnemyDown_Cue.Voice3_Shout_EnemyDown_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_AreaSecure_Cue.Voice3_Shout_AreaSecure_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Roger_Cue.Voice3_Shout_Roger_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Negative_Cue.Voice3_Shout_Negative_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Up_Cue.Voice3_Shout_Up_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Down_Cue.Voice3_Shout_Down_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Left_Cue.Voice3_Shout_Left_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Right_Cue.Voice3_Shout_Right_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_North_Cue.Voice3_Shout_North_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_South_Cue.Voice3_Shout_South_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_East_Cue.Voice3_Shout_East_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_West_Cue.Voice3_Shout_West_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Hooah_Cue.Voice3_Shout_Hooah_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Sniper_Cue.Voice3_Shout_Sniper_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Frag_Cue.Voice3_Shout_Frag_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Smoke_Cue.Voice3_Shout_Smoke_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Flash_Cue.Voice3_Shout_Flash_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Grenade_Cue.Voice3_Shout_Grenade_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Ready_Cue.Voice3_Shout_Ready_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_ImHit_Cue.Voice3_Shout_ImHit_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_GetTheDoor_Cue.Voice3_Shout_GetTheDoor_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_CheckYourFlanks_Cue.Voice3_Shout_CheckYourFlanks_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_FragOut_Cue.Voice3_Shout_FragOut_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Stop_Cue.Voice3_Shout_Stop_Cue"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Medic_Cue.Voice3_Shout_Medic_Cue"), NULL, LOAD_None, NULL)
	};
	_fTravelDistance = 2200;
	_fEnemyTravelDistance = 2200;
}

void ACommoShout::GetAnim(int32 Switch)
{
	//Return 'None';
}
bool ACommoShout::ReportLocation(int32 Switch)
{
	switch (Switch)
	{
	case 29:
	case 31:
		return true;
	default:
		return false;
	}
}