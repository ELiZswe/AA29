// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoWhisper/CommoWhisper.h"

ACommoWhisper::ACommoWhisper()
{

	MsgStatic = 27;
	Punctuation = "...";
	Messaged = "whispered";
	_iNumMessages = 27;
	_Messages = { "Move out","Stop","Cover Me","Enemy Spotted","Take Cover","Enemy Down","Area Secure","Roger","Negative","Up","Down","Left","Right","North","South","East","West","Hooah","Sniper","Frag 'em","Smoke 'em","Flash 'em","Grenade","Ready","I'm Hit","Get The Door","Check Your Flanks","","","","Hold still so I can treat you." };
	_messagename = "Whispered Message";

	_Sounds1 = {
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_MoveOut_Cue.Voice1_Whisper_MoveOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Stop_Cue.Voice1_Whisper_Stop_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_CoverMe_Cue.Voice1_Whisper_CoverMe_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_EnemySpotted_Cue.Voice1_Whisper_EnemySpotted_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_TakeCover_Cue.Voice1_Whisper_TakeCover_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_EnemyDown_Cue.Voice1_Whisper_EnemyDown_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_AreaSecure_Cue.Voice1_Whisper_AreaSecure_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Roger_Cue.Voice1_Whisper_Roger_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Negative_Cue.Voice1_Whisper_Negative_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Up_Cue.Voice1_Whisper_Up_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Down_Cue.Voice1_Whisper_Down_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Left_Cue.Voice1_Whisper_Left_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Right_Cue.Voice1_Whisper_Right_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_North_Cue.Voice1_Whisper_North_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_South_Cue.Voice1_Whisper_South_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_East_Cue.Voice1_Whisper_East_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_West_Cue.Voice1_Whisper_West_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Hooah_Cue.Voice1_Whisper_Hooah_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Sniper_Cue.Voice1_Whisper_Sniper_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Frag_Cue.Voice1_Whisper_Frag_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Smoke_Cue.Voice1_Whisper_Smoke_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Flash_Cue.Voice1_Whisper_Flash_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Grenade_Cue.Voice1_Whisper_Grenade_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Ready_Cue.Voice1_Whisper_Ready_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_ImHit_Cue.Voice1_Whisper_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_GetTheDoor_Cue.Voice1_Whisper_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_CheckYourFlanks_Cue.Voice1_Whisper_CheckYourFlanks_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/psst_Cue.psst_Cue'"), NULL, LOAD_None, NULL),
		nullptr,
		nullptr,
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Stop_Cue.Voice1_Whisper_Stop_Cue"), NULL, LOAD_None, NULL)
	};
	_Sounds2 = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_MoveOut_Cue.Voice2_Whisper_MoveOut_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Stop_Cue.Voice2_Whisper_Stop_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_CoverMe_Cue.Voice2_Whisper_CoverMe_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_EnemySpotted_Cue.Voice2_Whisper_EnemySpotted_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_TakeCover_Cue.Voice2_Whisper_TakeCover_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_EnemyDown_Cue.Voice2_Whisper_EnemyDown_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_AreaSecure_Cue.Voice2_Whisper_AreaSecure_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Roger_Cue.Voice2_Whisper_Roger_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Negative_Cue.Voice2_Whisper_Negative_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Up_Cue.Voice2_Whisper_Up_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Down_Cue.Voice2_Whisper_Down_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Left_Cue.Voice2_Whisper_Left_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Right_Cue.Voice2_Whisper_Right_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_North_Cue.Voice2_Whisper_North_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_South_Cue.Voice2_Whisper_South_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_East_Cue.Voice2_Whisper_East_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_West_Cue.Voice2_Whisper_West_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Hooah_Cue.Voice2_Whisper_Hooah_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Sniper_Cue.Voice2_Whisper_Sniper_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Frag_Cue.Voice2_Whisper_Frag_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Smoke_Cue.Voice2_Whisper_Smoke_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Flash_Cue.Voice2_Whisper_Flash_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Grenade_Cue.Voice2_Whisper_Grenade_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Ready_Cue.Voice2_Whisper_Ready_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_ImHit_Cue.Voice2_Whisper_ImHit_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_GetTheDoor_Cue.Voice2_Whisper_GetTheDoor_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_CheckYourFlanks_Cue.Voice2_Whisper_CheckYourFlanks_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/psst_Cue.psst_Cue"), NULL, LOAD_None, NULL),
		nullptr,
		nullptr,
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Stop_Cue.Voice2_Whisper_Stop_Cue"), NULL, LOAD_None, NULL)
	};

	_Sounds3 = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_MoveOut_Cue.Voice3_Whisper_MoveOut_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Stop_Cue.Voice3_Whisper_Stop_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_CoverMe_Cue.Voice3_Whisper_CoverMe_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_EnemySpotted_Cue.Voice3_Whisper_EnemySpotted_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_TakeCover_Cue.Voice3_Whisper_TakeCover_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_EnemyDown_Cue.Voice3_Whisper_EnemyDown_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_AreaSecure_Cue.Voice3_Whisper_AreaSecure_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Roger_Cue.Voice3_Whisper_Roger_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Negative_Cue.Voice3_Whisper_Negative_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Up_Cue.Voice3_Whisper_Up_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Down_Cue.Voice3_Whisper_Down_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Left_Cue.Voice3_Whisper_Left_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Right_Cue.Voice3_Whisper_Right_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_North_Cue.Voice3_Whisper_North_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_South_Cue.Voice3_Whisper_South_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_East_Cue.Voice3_Whisper_East_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_West_Cue.Voice3_Whisper_West_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Hooah_Cue.Voice3_Whisper_Hooah_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Sniper_Cue.Voice3_Whisper_Sniper_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Frag_Cue.Voice3_Whisper_Frag_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Smoke_Cue.Voice3_Whisper_Smoke_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Flash_Cue.Voice3_Whisper_Flash_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Grenade_Cue.Voice3_Whisper_Grenade_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Ready_Cue.Voice3_Whisper_Ready_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_ImHit_Cue.Voice3_Whisper_ImHit_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor_Cue.Voice3_Whisper_GetTheDoor_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_CheckYourFLanks_Cue.Voice3_Whisper_CheckYourFLanks_Cue"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/General/psst_Cue.psst_Cue"), NULL, LOAD_None, NULL),
		nullptr,
		nullptr,
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Stop_Cue.Voice3_Whisper_Stop_Cue"), NULL, LOAD_None, NULL)
	};


	_fSoundVolume = 0.3;
	_fTravelDistance = 320;
	_fEnemyTravelDistance = 320;
	_commotype = ECommoType::COMMOTYPE_Whisper;


}