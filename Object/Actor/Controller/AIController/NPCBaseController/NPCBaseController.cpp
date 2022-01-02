// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"

ANPCBaseController::ANPCBaseController()
{
	nameWaitingAnimation = "acf_checkwatch_a";
	iMaxContactAge = 15;
	sShoutEnemy = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_MoveOut_Cue.Voice3_Shout_MoveOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Stop_Cue.Voice3_Shout_Stop_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_CoverMe_Cue.Voice3_Shout_CoverMe_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_EnemySpotted_Cue.Voice3_Shout_EnemySpotted_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover_Cue.Voice3_Shout_TakeCover_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_EnemyDown_Cue.Voice3_Shout_EnemyDown_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_AreaSecure_Cue.Voice3_Shout_AreaSecure_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Roger_Cue.Voice3_Shout_Roger_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Negative_Cue.Voice3_Shout_Negative_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Up_Cue.Voice3_Shout_Up_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Down_Cue.Voice3_Shout_Down_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Left_Cue.Voice3_Shout_Left_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Right_Cue.Voice3_Shout_Right_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_North_Cue.Voice3_Shout_North_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_South_Cue.Voice3_Shout_South_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_East_Cue.Voice3_Shout_East_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_West_Cue.Voice3_Shout_West_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Hooah_Cue.Voice3_Shout_Hooah_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Sniper_Cue.Voice3_Shout_Sniper_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Frag_Cue.Voice3_Shout_Frag_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Smoke_Cue.Voice3_Shout_Smoke_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Flash_Cue.Voice3_Shout_Flash_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Grenade_Cue.Voice3_Shout_Grenade_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Ready_Cue.Voice3_Shout_Ready_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_ImHit_Cue.Voice3_Shout_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_GetTheDoor_Cue.Voice3_Shout_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_CheckYourFlanks_Cue.Voice3_Shout_CheckYourFlanks_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_FragOut_Cue.Voice3_Shout_FragOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_WatchOut_Cue.Pilot_WatchOut_Cue'"), NULL, LOAD_None, NULL)
	};
	sWhisperEnemy = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_MoveOut_Cue.Voice3_Whisper_MoveOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Stop_Cue.Voice3_Whisper_Stop_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_CoverMe_Cue.Voice3_Whisper_CoverMe_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_EnemySpotted_Cue.Voice3_Whisper_EnemySpotted_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_TakeCover_Cue.Voice3_Whisper_TakeCover_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_EnemyDown_Cue.Voice3_Whisper_EnemyDown_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_AreaSecure_Cue.Voice3_Whisper_AreaSecure_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Roger_Cue.Voice3_Whisper_Roger_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Negative_Cue.Voice3_Whisper_Negative_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Up_Cue.Voice3_Whisper_Up_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Down_Cue.Voice3_Whisper_Down_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Left_Cue.Voice3_Whisper_Left_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Right_Cue.Voice3_Whisper_Right_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_North_Cue.Voice3_Whisper_North_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_South_Cue.Voice3_Whisper_South_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_East_Cue.Voice3_Whisper_East_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_West_Cue.Voice3_Whisper_West_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Hooah_Cue.Voice3_Whisper_Hooah_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Sniper_Cue.Voice3_Whisper_Sniper_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Frag_Cue.Voice3_Whisper_Frag_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Smoke_Cue.Voice3_Whisper_Smoke_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Flash_Cue.Voice3_Whisper_Flash_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Grenade_Cue.Voice3_Whisper_Grenade_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Ready_Cue.Voice3_Whisper_Ready_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_ImHit_Cue.Voice3_Whisper_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor_Cue.Voice3_Whisper_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_CheckYourFLanks_Cue.Voice3_Whisper_CheckYourFLanks_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_FragOut_Cue.Voice3_Shout_FragOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_WatchOut_Cue.Pilot_WatchOut_Cue'"), NULL, LOAD_None, NULL)
	};
	sShoutFriendly = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_MoveOut_Cue.Voice2_Shout_MoveOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Stop_Cue.Voice2_Shout_Stop_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_CoverMe_Cue.Voice2_Shout_CoverMe_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_EnemySpotted_Cue.Voice2_Shout_EnemySpotted_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_TakeCover_Cue.Voice2_Shout_TakeCover_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_EnemyDown_Cue.Voice2_Shout_EnemyDown_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_AreaSecure_Cue.Voice2_Shout_AreaSecure_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Roger_Cue.Voice2_Shout_Roger_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Negative_Cue.Voice2_Shout_Negative_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Up_Cue.Voice2_Shout_Up_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Down_Cue.Voice2_Shout_Down_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Left_Cue.Voice2_Shout_Left_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Right_Cue.Voice2_Shout_Right_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_North_Cue.Voice2_Shout_North_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_South_Cue.Voice2_Shout_South_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_East_Cue.Voice2_Shout_East_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_West_Cue.Voice2_Shout_West_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Hooah_Cue.Voice2_Shout_Hooah_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Sniper_Cue.Voice2_Shout_Sniper_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Frag_Cue.Voice2_Shout_Frag_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Smoke_Cue.Voice2_Shout_Smoke_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Flash_Cue.Voice2_Shout_Flash_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Grenade_Cue.Voice2_Shout_Grenade_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Ready_Cue.Voice2_Shout_Ready_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_ImHit_Cue.Voice2_Shout_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_GetTheDoor_Cue.Voice2_Shout_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_CheckYourFlanks_Cue.Voice2_Shout_CheckYourFlanks_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_FragOut_Cue.Voice2_Shout_FragOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_GetDown_Cue.Pilot_GetDown_Cue'"), NULL, LOAD_None, NULL)
	};
	sWhisperFriendly = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_MoveOut_Cue.Voice2_Whisper_MoveOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Stop_Cue.Voice2_Whisper_Stop_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_CoverMe_Cue.Voice2_Whisper_CoverMe_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_EnemySpotted_Cue.Voice2_Whisper_EnemySpotted_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_TakeCover_Cue.Voice2_Whisper_TakeCover_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_EnemyDown_Cue.Voice2_Whisper_EnemyDown_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_AreaSecure_Cue.Voice2_Whisper_AreaSecure_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Roger_Cue.Voice2_Whisper_Roger_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Negative_Cue.Voice2_Whisper_Negative_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Up_Cue.Voice2_Whisper_Up_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Down_Cue.Voice2_Whisper_Down_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Left_Cue.Voice2_Whisper_Left_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Right_Cue.Voice2_Whisper_Right_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_North_Cue.Voice2_Whisper_North_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_South_Cue.Voice2_Whisper_South_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_East_Cue.Voice2_Whisper_East_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_West_Cue.Voice2_Whisper_West_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Hooah_Cue.Voice2_Whisper_Hooah_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Sniper_Cue.Voice2_Whisper_Sniper_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Frag_Cue.Voice2_Whisper_Frag_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Smoke_Cue.Voice2_Whisper_Smoke_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Flash_Cue.Voice2_Whisper_Flash_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Grenade_Cue.Voice2_Whisper_Grenade_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Ready_Cue.Voice2_Whisper_Ready_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_ImHit_Cue.Voice2_Whisper_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_GetTheDoor_Cue.Voice2_Whisper_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_CheckYourFlanks_Cue.Voice2_Whisper_CheckYourFlanks_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_FragOut_Cue.Voice2_Shout_FragOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_GetDown_Cue.Pilot_GetDown_Cue'"), NULL, LOAD_None, NULL)
	};
	sShoutSquad = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_MoveOut_Cue.Voice1_Shout_MoveOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Stop_Cue.Voice1_Shout_Stop_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_CoverMe_Cue.Voice1_Shout_CoverMe_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_EnemySpotted_Cue.Voice1_Shout_EnemySpotted_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_TakeCover_Cue.Voice1_Shout_TakeCover_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_EnemyDown_Cue.Voice1_Shout_EnemyDown_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_AreaSecure_Cue.Voice1_Shout_AreaSecure_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Roger_Cue.Voice1_Shout_Roger_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Negative_Cue.Voice1_Shout_Negative_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Up_Cue.Voice1_Shout_Up_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Down_Cue.Voice1_Shout_Down_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Left_Cue.Voice1_Shout_Left_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Right_Cue.Voice1_Shout_Right_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_North_Cue.Voice1_Shout_North_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_South_Cue.Voice1_Shout_South_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_East_Cue.Voice1_Shout_East_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_West_Cue.Voice1_Shout_West_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Hooah_Cue.Voice1_Shout_Hooah_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Sniper_Cue.Voice1_Shout_Sniper_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Frag_Cue.Voice1_Shout_Frag_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Smoke_Cue.Voice1_Shout_Smoke_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Flash_Cue.Voice1_Shout_Flash_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Grenade_Cue.Voice1_Shout_Grenade_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Ready_Cue.Voice1_Shout_Ready_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_ImHit_Cue.Voice1_Shout_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_GetTheDoor_Cue.Voice1_Shout_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_CheckYourFlanks_Cue.Voice1_Shout_CheckYourFlanks_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_FragOut_Cue.Voice1_Shout_FragOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_EnemySoldiers_Cue.Pilot_EnemySoldiers_Cue'"), NULL, LOAD_None, NULL)
	};
	sWhisperSquad = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_MoveOut_Cue.Voice1_Whisper_MoveOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Stop_Cue.Voice1_Whisper_Stop_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_CoverMe_Cue.Voice1_Whisper_CoverMe_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_EnemySpotted_Cue.Voice1_Whisper_EnemySpotted_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_TakeCover_Cue.Voice1_Whisper_TakeCover_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_EnemyDown_Cue.Voice1_Whisper_EnemyDown_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_AreaSecure_Cue.Voice1_Whisper_AreaSecure_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Roger_Cue.Voice1_Whisper_Roger_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Negative_Cue.Voice1_Whisper_Negative_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Up_Cue.Voice1_Whisper_Up_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Down_Cue.Voice1_Whisper_Down_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Left_Cue.Voice1_Whisper_Left_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Right_Cue.Voice1_Whisper_Right_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_North_Cue.Voice1_Whisper_North_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_South_Cue.Voice1_Whisper_South_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_East_Cue.Voice1_Whisper_East_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_West_Cue.Voice1_Whisper_West_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Hooah_Cue.Voice1_Whisper_Hooah_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Sniper_Cue.Voice1_Whisper_Sniper_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Frag_Cue.Voice1_Whisper_Frag_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Smoke_Cue.Voice1_Whisper_Smoke_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Flash_Cue.Voice1_Whisper_Flash_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Grenade_Cue.Voice1_Whisper_Grenade_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Ready_Cue.Voice1_Whisper_Ready_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_ImHit_Cue.Voice1_Whisper_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_GetTheDoor_Cue.Voice1_Whisper_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_CheckYourFlanks_Cue.Voice1_Whisper_CheckYourFlanks_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_FragOut_Cue.Voice1_Shout_FragOut_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_EnemySoldiers_Cue.Pilot_EnemySoldiers_Cue'"), NULL, LOAD_None, NULL)
	};
	sEnemyLeader = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Up_Cue.Voice3_Shout_Up_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Down_Cue.Voice3_Shout_Down_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Left_Cue.Voice3_Shout_Left_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Right_Cue.Voice3_Shout_Right_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor_Cue.Voice3_Whisper_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor_Cue.Voice3_Whisper_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor_Cue.Voice3_Whisper_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor_Cue.Voice3_Whisper_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor_Cue.Voice3_Whisper_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor_Cue.Voice3_Whisper_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor_Cue.Voice3_Whisper_GetTheDoor_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover_Cue.Voice3_Shout_TakeCover_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover_Cue.Voice3_Shout_TakeCover_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover_Cue.Voice3_Shout_TakeCover_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover_Cue.Voice3_Shout_TakeCover_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_ImHit_Cue.Voice3_Whisper_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_ImHit_Cue.Voice3_Whisper_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_ImHit_Cue.Voice3_Whisper_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_ImHit_Cue.Voice3_Whisper_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_ImHit_Cue.Voice3_Shout_ImHit_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_ImHit_Cue.Voice3_Shout_ImHit_Cue'"), NULL, LOAD_None, NULL)
	};
	iNPCInitialMentalState = 10;
	iNPCTeamID = 2;
	fpNPCHearingRadius = 2048;
	fpNPCVisionConeAngle = 16384;
	fpNPCMaxVisualRange = 1000;
	fpNPCWeaponAccuracy = 50;
	fpNodeMentalStateChangeModifier = 1;
	fpNodeVisionRangeModifier = 1;
	fpNodeHearingRangeModifier = 1;
	fpNodeMentalStateRecoveryModifier = 1;
	fNPCExperience = 70;
	fNPCLikesToCrouch = 50;
	iMinThreatLevel = 2;
	bMaleVoice = true;
	bLikesToCloseDoorBehindSelf = true;
	bScanWhenStopped = true;
	fChanceOfStoppingAtNode = 100;
	bAscendingNodeDirection = true;
	bAdvancedTactics = false;
}

/*
State FlashBanged
{
	Function ReceiveWarning(APawn* shooter, float projSpeed, Vector FireDir)
	{
	}
	Function NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade)
	{
	}
	Event bool NotifyBump(AActor* Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
	Function ArrivedAtPathnode()
	{
	}
	Function EndState()
	{
		NPCLog(string(Self) $ string(GetStateName()) $ ".EndState() - exiting, last state name: " $ string(GetLastStateName()));
		fpFlashBangedEndTime=0;
		fpFlashBangedVisualIntensity=0;
		fpFlashBangedAudioIntensity=0;
	}
	Function float PerformFlashedAnimation()
	{
		if ((fpFlashBangedAudioIntensity / 1.13) >= 0.8)
		{
			switch(Rand(3))
			{
				case 0:
				return PlayCustomAnimation("Smokebanged",false,((FMath::FRand() * 0.3) + 0.9));
				case 1:
				return PlayCustomAnimation("FlashBanged",false,((FMath::FRand() * 0.3) + 0.9));
				case 2:
				return PlayCustomAnimation("FlashbangedMid",false,((FMath::FRand() * 0.3) + 0.9));
				default:
				break;
			}
			if ((fpFlashBangedAudioIntensity / 1.13) >= 0.25)
			{
				switch(Rand(3))
				{
					case 0:
					return PlayCustomAnimation("GrdBiglookAroundLg",false,1.2);
					case 1:
					return PlayCustomAnimation("FlashbangedFar",false,((FMath::FRand() * 0.3) + 0.9));
					case 2:
					return PlayCustomAnimation("GrdSwatFly",false,1);
					default:
					break;
				}
				if (FMath::FRand() > 0.5)
				{
					return PlayCustomAnimation("GrdDigsEar",false,((FMath::FRand() * 0.3) + 0.9));
					break;
				}
				return PlayCustomAnimation("StartledLg",false,((FMath::FRand() * 0.3) + 0.9));
			}
		}
	}
	Function AdjustFlashedMentalState()
	{
		IncreaseNervousness(10);
		IncreaseNervousness(9);
		IncreaseNervousness(7);
		IncreaseNervousness(1);
	}
	Function FlashBangEffectEnded()
	{
		NPCLog(string(Self) $ "." $ string(GetStateName()) $ ".FlashBangEffectEnded()");
		if (GetLastStateName() == "WalkingPatrol")
		{
			GotoState("ReturnToPatrol");
		}
		else
		{
			if (GetLastStateName() != "FlashBanged")
			{
				GotoState(GetLastStateName());
			}
			else
			{
				GotoState("FindCover");
			}
		}
	}
	Function Timer()
	{
		if (GetWorld()->GetTimeSeconds() >= fpFlashBangedEndTime)
		{
			FlashBangEffectEnded();
		}
	}
	Function NPCFlashedAudioYell()
	{
		NPCSay(24,true,true);
	}
	Function float PrepForFlashing()
	{
		return 0;
	}
	Function float PlayFinalAnimation()
	{
		return PlayCustomAnimation("GrdDigsEar",false,((FMath::FRand() * 0.25) + 1));
	}
Begin:
	SetTimer(1,true);
	Sleep(0);
	NPCLog(string(Self) $ "." $ string(GetStateName()) $ " Begin entered");
	NPCLog(string(Self) $ "." $ string(GetStateName()) $ " Intensity percent: " $ string((fpFlashBangedAudioIntensity / 1.13)));
	Sleep(PrepForFlashing());
	Enemy=nullptr;
	Focus=nullptr;
	NPCFlashedAudioYell();
	AdjustFlashedMentalState();
	Stand();
	StopMovement();
	NPCLog("Flashbang intensity: " $ string(fpFlashBangedAudioIntensity) $ " duration: " $ string((fpFlashBangedEndTime - GetWorld()->GetTimeSeconds())));
	if ((fpFlashBangedAudioIntensity / 1.13) >= 0.1)
	{
		Sleep((0.25 + (FMath::FRand() * 0.75)));
		if ((FMath::FRand() < 0.5) || ((fpFlashBangedAudioIntensity / 1.13) < 0.95))
		{
			Sleep(PerformFlashedAnimation());
			if (GetWorld()->GetTimeSeconds() < (fpFlashBangedEndTime - 2))
			{
				Crouch();
				Sleep(PlayFinalAnimation());
			}
		}
		if ((fpFlashBangedAudioIntensity / 1.13) >= 0.1)
		{
			JL"RepeatAnim"
;
		}
	}
	Crouch();
	if (GetWorld()->GetTimeSeconds() >= (fpFlashBangedEndTime - 1))
	{
		NPCLog("Hit end of flashbang");
		JL"End"
;
	}
	if (FMath::FRand() > 0.5)
	{
		LookLeft(fpTurnRate);
	}
	else
	{
		LookRight(fpTurnRate);
	}
	FinishRotation();
	Sleep((0.25 + (FMath::FRand() * 2)));
	JL"KeepSpinning"
;
}
*/

/*
State WaitForPawnToLeavePathnode
{
Begin:
	Sleep(0);
	if (iBumpsThisPathnode ++ > 3)
	{
		bAscendingNodeDirection=(! bAscendingNodeDirection);
		NPCLog("WaitForPawnToLeavePathnode entered with too many bumps - reversing course since we're obviously stuck");
	}
	NPCLog("");
	NPCLog("");
	NPCLog("WaitForPawnToLeavePathnode entered");
	StopMovement();
	NPCLog("Stopped, now waiting for pathnode to clear by playing animation \"" $ string(nameWaitingAnimation) $ "\"");
	Sleep(PlayCustomAnimation(nameWaitingAnimation));
	NPCLog("Finished animation, waiting a bit more");
	Sleep(0.25);
	NPCChangeState("WalkingPatrol","Begin");
}
*/

/*
State WalkingPatrol
{
	Function bool EndActionIdleAnimation()
	{
		return false;
	}
	Function bool PrepActionForIdleAnimation()
	{
		return false;
	}
	Function EndState()
	{
		pnCurrentNodeLeadingToPathNode=nullptr;
	}
	Function bool ShouldMoveToNextPathNode()
	{
		return true;
	}
	Function ArrivedAtPathnode()
	{
		ANPCItemOfInterest* npcioi = nullptr;
		if ((bSupportItemOfInterestSearch && pnCurrentPathNode.IsA("NPCWaypointPathNode")) && NPCWaypointPathNode(pnCurrentPathNode).bSearchForItemsOfInterest)
		{
			npcioi=GetNearbyItemOfInterest();
			if (npcioi != nullptr)
			{
				if ((npcioiLastFound == npcioi) && ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastSawIOI) < 30))
				{
					return;
				}
				if ((FMath::FRand() * 100) < npcioi.fpLikelihoodItemWillBeNoticed)
				{
					fpTimeSinceLastSawIOI=GetWorld()->GetTimeSeconds();
					npcioiLastFound=npcioi;
					NotifyItemOfInterestFound(npcioi);
				}
			}
		}
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		if (Wall.IsA("Mover") && (! Mover(Wall).bNotADoor))
		{
			if (Mover(Wall).bInterpolating)
			{
				return false;
			}
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState("WalkingPatrol","OpeningDoor");
			return true;
		}
		return Global.pos(HitNormal,Wall);
	}
	Function DumpPathNodes()
	{
		int32 i = 0;
		for (i=0; i<apnPathNodesForPatrol.Length; i++)
		{
			DebugLog(DEBUG_AIPathing,"Pathnode[" $ string(i) $ "] -> " $ string(apnPathNodesForPatrol[i]) $ " tag: " $ string(apnPathNodesForPatrol[i].Tag));
		}
	}
	Function MoverFinished()
	{
	}
	Function PathNode GetPathNodeFromRoute()
	{
		int32 i = 0;
		if (pnCurrentNodeLeadingToPathNode == nullptr)
		{
			return PathNode(FindPathToward(pnCurrentPathNode,true));
		}
		for (i=0; i<61; i++)
		{
			if ((RouteCache[i] == pnCurrentNodeLeadingToPathNode) && (RouteCache[(i + 1)] != nullptr))
			{
				return PathNode(RouteCache[(i + 1)]);
			}
			if (RouteCache[i] == nullptr)
			{
				return PathNode(FindPathToward(pnCurrentPathNode,true));
			}
		}
		return PathNode(FindPathToward(pnCurrentPathNode,true));
	}
Begin:
	Sleep(0);
	if ((Pawn == nullptr) || (! bStart))
	{
		NPCChangeState("None");
		JL"End"
;
	}
	NPCPathLog("");
	NPCPathLog("");
	NPCPathLog("");
	NPCPathLog("NPCBaseController::WalkPatrol.Begin Started");
	ResumeTravelSpeed();
	FindNextPatrolPathNode();
	if (pnCurrentPathNode == nullptr)
	{
		NPCPathLog("No path node to move to!");
		NPCChangeState("None");
		JL"End"
;
	}
	JL"MoveOn"
;
	if (pnCurrentPathNode == nullptr)
	{
		NPCChangeState("None");
		JL"End"
;
	}
	NPCPathLog("Turning to node " $ string(pnCurrentPathNode.Tag));
	Focus=pnCurrentLocation;
	TurnToActor(pnCurrentPathNode,fpTurnRate);
	FinishRotation();
	NPCPathLog("Finished turning to node " $ string(pnCurrentPathNode.Tag));
	if (iCurrentPathNodeIndex == 0)
	{
		bUseAlternatePath=(FMath::FRand() > 0.5);
		NPCPathLog("Alternate path: " $ string(bUseAlternatePath));
	}
	pnCurrentNodeLeadingToPathNode=nullptr;
	AGP_Pawn(Pawn).bNPCMovingToPathNode=true;
	if ((pnCurrentPathNode != nullptr) && pnCurrentPathNode.bMustCrouch)
	{
		WantsToCrouch();
		Crouch();
	}
	else
	{
		if ((pnCurrentPathNode != nullptr) && pnCurrentPathNode.bMustProne)
		{
			WantsToCrawl();
			Prone();
		}
		else
		{
			if ((pnCurrentPathNode != nullptr) && pnCurrentPathNode.bMustStand)
			{
				Stand();
			}
		}
	}
	if ((((pnCurrentPathNode != nullptr) && pnCurrentPathNode.bMustRun) && (! Pawn.bIsProne)) && (! pnCurrentPathNode.bMustProne))
	{
		WantsToRun();
		if (pnCurrentPathNode.bMustSprint)
		{
			Run(false);
		}
		else
		{
			Run(true);
		}
	}
	else
	{
		if ((pnCurrentPathNode != nullptr) && pnCurrentPathNode.bMustWalk)
		{
			WantsToWalk();
			Walk();
		}
		else
		{
			ResumeTravelSpeed();
		}
	}
	if (((Pawn == nullptr) || (Pawn.Health < 0)) || (! bStart))
	{
		NPCChangeState("None");
		JL"End"
;
	}
	pnCurrentNodeLeadingToPathNode=GetPathNodeFromRoute();
	if (pnCurrentNodeLeadingToPathNode == nullptr)
	{
		pnCurrentNodeLeadingToPathNode=PathNode(FindPathToward(pnCurrentPathNode,false));
	}
	if (bDebugPath)
	{
		DebugDumpRoute();
	}
	NPCPathLog("Moving to node " $ string(pnCurrentPathNode) $ " via " $ string(pnCurrentNodeLeadingToPathNode));
	if ((pnCurrentNodeLeadingToPathNode != nullptr) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
	{
		if (NPCPathNode(pnCurrentNodeLeadingToPathNode).IsHallwayEntry())
		{
			if (! NPCPathNode(pnCurrentNodeLeadingToPathNode).RequestHallway(Self))
			{
				Sleep(1);
			}
		}
		DebugMarkNextNode(pnCurrentNodeLeadingToPathNode);
		UpdatePathNodeBonuses(nullptr);
		Focus=pnCurrentNodeLeadingToPathNode;
		MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,false,Pawn.bIsWalking);
		NPCPathNode(pnCurrentNodeLeadingToPathNode).ReleaseHallway(Self);
		if (VSize((pnCurrentNodeLeadingToPathNode.Location - Pawn.Location)) > float(100))
		{
			DebugLog(DEBUG_AIPathing,"Pawn Tag: " $ string(Pawn.Tag) $ " failed to make it to final node " $ string(pnCurrentNodeLeadingToPathNode) $ " on his way to waypoint: " $ string(pnCurrentPathNode) $ " Last waypoint node: " $ string(pnCurrentLocation));
			Sleep(1);
			(pnCurrentNodeLeadingToPathNode.FearCost += 100);
			pnCurrentNodeLeadingToPathNode=nullptr;
		}
		JL"NextTravelNode"
;
	}
	else
	{
		if ((pnCurrentPathNode != nullptr) && pnCurrentPathNode.IsHallwayEntry())
		{
			if (! pnCurrentPathNode.RequestHallway(Self))
			{
				Sleep(1);
			}
		}
		NPCPathLog("No more nodes found on the way - moving to last node: " $ string(pnCurrentPathNode.Tag));
		DebugMarkNextNode(pnCurrentPathNode);
		Focus=pnCurrentPathNode;
		MoveToward(pnCurrentPathNode,pnCurrentPathNode,,false,Pawn.bIsWalking);
		if (pnCurrentPathNode != nullptr)
		{
			pnCurrentPathNode.ReleaseHallway(Self);
		}
		if (VSize((pnCurrentPathNode.Location - Pawn.Location)) > float(100))
		{
			DebugLog(DEBUG_AIPathing,"Pawn Tag: " $ string(Pawn.Tag) $ " failed to make it to final waypoint: " $ string(pnCurrentPathNode) $ " Last waypoint node: " $ string(pnCurrentLocation));
			DumpPathNodes();
			NPCPathLog("Pawn Tag: " $ string(Pawn.Tag) $ " failed to make it to final waypoint: " $ string(pnCurrentPathNode) $ " Last waypoint node: " $ string(pnCurrentLocation));
			NPCPathLog("Pawn Tag: " $ string(Pawn.Tag) $ " aborting patrol mode");
			DebugLog(DEBUG_AIPathing,"Pawn Tag: " $ string(Pawn.Tag) $ " aborting patrol mode");
			GotoState("StuckByBadPath");
			JL"End"
;
		}
	}
	UpdatePathNodeBonuses(pnCurrentPathNode);
	if (bDebugPath)
	{
		NPCPathLog("Done moving to node: " $ string(pnCurrentLocation));
	}
	AGP_Pawn(Pawn).bNPCMovingToPathNode=false;
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCDoorEntryPathNode"))
	{
		if ((FindDoor(NPCDoorEntryPathNode(pnCurrentLocation)) != nullptr) && FindDoor(NPCDoorEntryPathNode(pnCurrentLocation)).bClosed)
		{
			AGP_Pawn(Pawn).GuardWeapon3p(6);
		}
		if (! OpenDoor(NPCDoorEntryPathNode(pnCurrentLocation)))
		{
			if (bAutoReversePath)
			{
				NPCPathLog("Door was locked, trying to reverse direction");
				bAscendingNodeDirection=(! bAscendingNodeDirection);
			}
			else
			{
				NPCPathLog("Ack - no auto-reverse and no way to get through door, quitting movement!");
				StopMovement();
				JL"End"
;
			}
		}
		else
		{
			if (mLastDoorOpened != nullptr)
			{
				Sleep(mLastDoorOpened.MoveTime);
				if (mLastDoorOpened.bClosed)
				{
					NPCPathLog("ARGH! Door didn't open");
					bAscendingNodeDirection=(! bAscendingNodeDirection);
				}
				else
				{
					Sleep(NPCDoorEntryPathNode(pnCurrentLocation).fpTimeToWaitForOpenDoor);
					NPCPathLog("Done sleeping after opening door");
				}
			}
			Pawn.UpperBodyAnimComplete();
		}
	}
	ArrivedAtPathnode();
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCRestStopPathNode"))
	{
		if (bDebugPath)
		{
			NPCPathLog("Rest stop hit, performing actions");
		}
		NPCChangeState("ArrivedAtRestStop");
		JL"End"
;
	}
	else
	{
		if ((pnCurrentLocation != nullptr) && pnCurrentLocation.bStopHere)
		{
			NPCChangeState("ForcedIdle");
			JL"End"
;
		}
		if ((FMath::FRand() < (fChanceOfStoppingAtNode / 100)) && (anpcassNPCIdleAnimations.Length > 0))
		{
			if (SelectIdleRelatedAnimation() && Pawn.bNetRelevant)
			{
				PrepActionForIdleAnimation();
				Sleep(0.75);
				Sleep(PlayCustomAnimation(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animStart,false));
				if (anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animMiddle != "None")
				{
					Sleep(PlayCustomAnimation(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animMiddle,false));
				}
				if (anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].AnimEnd != "None")
				{
					Sleep(PlayCustomAnimation(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].AnimEnd,false));
				}
				if (EndActionIdleAnimation())
				{
					Sleep(0.75);
				}
			}
			if (bDebugPath)
			{
				NPCPathLog("Hit random sleep for node");
			}
			Sleep((FMath::FRand() * 2));
		}
	}
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCLadderPathNode"))
	{
		if (NPCLadderPathNode(pnCurrentLocation).bNearLadderTop)
		{
			NPCPathLog("At top of ladder pathnode - and pawn onLadder: " $ string(bOnLadder));
			if ((DetermineNodeAfterCurrentNode() != nullptr) && NPCLadderPathNode(DetermineNodeAfterCurrentNode()).bNearLadderBase)
			{
				NPCPathLog("Node after current node is at bottom of ladder so use it");
				lvLadderEntry=GetNearbyLadderVolume(pnCurrentLocation);
				if (lvLadderEntry != nullptr)
				{
					NPCPathLog("Moving to ladder");
					AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
					Sleep(0.25);
					NPCPathLog("About to move to end of ladder node: " $ string(GetLadderPathnodeByName(NPCLadderPathNode(pnCurrentPathNode).nameLadderNodeToExitFrom)) $ " at " $ string(GetWorld()->GetTimeSeconds()));
					MoveToward(GetLadderPathnodeByName(NPCLadderPathNode(pnCurrentLocation).nameLadderNodeToExitFrom));
					Sleep(0.25);
					NPCPathLog("Done moving to end of ladder node " $ string(GetLadderPathnodeByName(NPCLadderPathNode(pnCurrentLocation).nameLadderNodeToExitFrom)) $ ", leaving ladder at " $ string(GetWorld()->GetTimeSeconds()));
					EndClimbLadder();
					NPCPathLog("Ended ladder climbing, pausing");
					Walk();
					NPCPathLog("Left ladder volume mode - now moving towards node: " $ string(DetermineNodeAfterCurrentNode()));
					DebugMarkNextNode(DetermineNodeAfterCurrentNode());
					MoveToward(DetermineNodeAfterCurrentNode(),DetermineNodeAfterCurrentNode(),,false,(! ShouldRun()));
					ResumeTravelSpeed();
					DetermineNextPathNode();
					DetermineNextPathNode();
					NPCPathLog("Determined node after ladder to skip past it");
					JL"MoveOn"
;
				}
			}
		}
	}
	NPCPathLog("Looking for next node");
	if (! ShouldMoveToNextPathNode())
	{
		JL"End"
;
	}
	DetermineNextPathNode();
	if (bScanWhenStopped && Pawn.bNetRelevant)
	{
		NPCChangeState("LookAround");
	}
	else
	{
		JL"FacePathNode"
;
	}
	JL"End"
;
	Sleep(1.5);
	MoveTo((Pawn.Location + (( Vector(Pawn.Rotation) * float(-1)) * float(75))),,true);
	JL"Begin"
;
}
*/

/*
State PawnStartsAsDummy
{
	Event HearNoise(float Loudness, AActor* NoiseMaker, Vector vSoundLocation)
	{
	}
	Event bool NotifyBump(AActor* Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		int32 iRandomAudioIndex = 0;
		if ((VSize((Pawn.Location - pawnSeen.Location)) > fpAudioTriggerRangeToPlayerUU) || (fpUnmanagedAudioMinDelayTime == 0))
		{
			return;
		}
		if (GetWorld()->GetTimeSeconds() >= fpUnmanagedAudioTimeNextPlay)
		{
			if (((asndIdleRandomAudio.Length > 0) && (! bUseLipSynch)) || ((anameIdleRandomLipSyncAudio.Length > 0) && bUseLipSynch))
			{
				if (bUseLipSynch)
				{
					iRandomAudioIndex=Rand(anameIdleRandomLipSyncAudio.Length);
					Pawn.StopLIPSincAnim();
					Pawn.PlayLIPSincAnim(anameIdleRandomLipSyncAudio[iRandomAudioIndex],1,fpAudioFullVolumeRadius,1);
				}
				else
				{
					iRandomAudioIndex=Rand(asndIdleRandomAudio.Length);
					Pawn.PlaySound(asndIdleRandomAudio[iRandomAudioIndex],0,1,false,fpAudioFullVolumeRadius,,true);
				}
				fpUnmanagedAudioTimeNextPlay=((GetWorld()->GetTimeSeconds() + (FMath::FRand() * 10)) + fpUnmanagedAudioMinDelayTime);
			}
		}
	}
	Function NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
	{
		if (bDummyPawnIgnoreAllEvents)
		{
			return;
		}
		Global.agpwSecondary(twpGrenade);
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
		if (bDummyPawnIgnoreAllEvents)
		{
			return;
		}
		Global.YPos(aShooter);
	}
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
		if (bDummyPawnIgnoreAllEvents)
		{
			return;
		}
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
	}
	Function ArrivedAtPathnode()
	{
	}
	Function bool UsedBy(APawn* User)
	{
		if (npccpCurrentConversation != nullptr)
		{
			NPCLog(string(Self) $ "UsedBy() - should interrupt conversation");
			npccpCurrentConversation.EndConversation();
		}
		return Global.YPos(User);
	}
	Function BeginState()
	{
		NPCLog("Pawn is starting out doing nothing (dummy)");
	}
	Function EndState()
	{
		NPCLog("Pawn is leaving doing nothing (dummy)");
	}
	Event AnimEnd(int32 Channel)
	{
		NPCLog("Animation end signalled for channel " $ string(Channel));
	}
	Function float PlayStartupAnim()
	{
		float fpLength = 0;
		if ((AnimSequence == "None") || (AnimSequence == "None"))
		{
			return 0;
		}
		fpLength=PlayCustomAnimation(AnimSequence,true);
		NPCLog("Anim: " $ string(AnimSequence) $ " length: " $ string(fpLength));
		if (fpLength >= 0)
		{
			return fpLength;
		}
		else
		{
			return 0;
		}
	}
	simulated Function PlayLoopingAnimation()
	{
		if (AnimChannel >= 1)
		{
			Pawn.AnimBlendParams(AnimChannel,1,Pawn.BlendChangeTime,Pawn.BlendChangeTime);
		}
		if (Level.NetMode == NM_Standalone)
		{
			Pawn.LoopAnim(AnimSequence);
		}
		else
		{
			Pawn.SetLoopingAnimAction(AnimSequence);
		}
	}
	simulated Function StopAnimation()
	{
		StopAnimating(false);
	}
Begin:
	NPCLog("Begin dummy pawn: " $ string(Pawn) $ " playing anim: " $ string(AnimSequence));
	if (bDummyPawnLoopIdleAnim)
	{
		NPCLog("Dummy Pawn wants to loop idle animation and then do nothing");
		Disable("AnimEnd");
		PlayLoopingAnimation();
		if (fpAnimFreezeTime > 0)
		{
			Sleep(fpAnimFreezeTime);
			StopAnimation();
		}
		JL"DoNothing"
;
	}
	Sleep(0.5);
	Sleep(PlayStartupAnim());
	AGP_Pawn(Pawn).nmNPCIdleAnim=AnimSequence;
	ArrivedAtPathnode();
	NPCLog("Now doing nothing (aside from any idle animations...");
	if (Pawn.bNetRelevant)
	{
		SelectIdleRelatedAnimation(true);
		NPCLog("idle animation index selected: " $ string(iCurrentIdleAnimIndex));
		if (iCurrentIdleAnimIndex >= 0)
		{
			NPCLog("Selected start idle animation of " $ string(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animStart));
			NPCLog("Selected middle idle animation of " $ string(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animMiddle));
			NPCLog("Selected end idle animation of " $ string(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].AnimEnd));
			if (AnimTime == 0)
			{
				AnimTime=0.75;
			}
			Sleep(PlayCustomAnimation(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animStart,false));
			if (anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animMiddle != "None")
			{
				Sleep(PlayCustomAnimation(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animMiddle,false));
			}
			if (anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].AnimEnd != "None")
			{
				Sleep(PlayCustomAnimation(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].AnimEnd,false));
			}
			Sleep(0.25);
		}
		if (bRotateToDesired)
		{
			FinishRotation();
		}
	}
	Sleep((2.5 + (FMath::FRand() * 4)));
	JL"RepeatAnim"
;
	if (bRotateToDesired)
	{
		FinishRotation();
	}
	Sleep(1);
	JL"DoNothing"
;
}
*/

/*
State GuardMode
{
	Function PrepIdleAnimationPlay()
	{
	}
	Function PrepPostIdleAnimationPlay()
	{
	}
	Function float InitializeGuardMode()
	{
		return 0;
	}
	Event AnimEnd(int32 Channel)
	{
		NPCLog("Animation end signalled for channel " $ string(Channel));
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		if (Wall.IsA("Mover") && (! Mover(Wall).bNotADoor))
		{
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState("GuardMode","PauseForDoor");
			return true;
		}
		return Global.pos(HitNormal,Wall);
	}
	Function float PlayStartupAnim()
	{
		float fpLength = 0;
		fpLength=PlayCustomAnimation(AnimSequence,true);
		NPCLog("Anim: " $ string(AnimSequence) $ " length: " $ string(fpLength));
		if (fpLength >= 0)
		{
			return fpLength;
		}
		else
		{
			return 0;
		}
	}
	Function NPCPathNode FindClosePathNode()
	{
		ANPCPathNode* npcpnFound = nullptr;
		int32 iTry = 0;
		if (apnPathNodesForPatrol.Length == 0)
		{
			return nullptr;
		}
		iTry=0;
		if (iTry < (apnPathNodesForPatrol.Length * 2))
		{
			npcpnFound=apnPathNodesForPatrol[Rand(apnPathNodesForPatrol.Length)];
			if ((fpMaxDistanceForGuardWandering == 0) || (VSize((npcpnFound.Location - Pawn.Location)) <= fpMaxDistanceForGuardWandering))
			{
				return npcpnFound;
			}
			iTry ++;
		}
		return nullptr;
	}
Begin:
	Sleep(0);
	Stand();
	Walk();
	InitializeGuardMode();
	AGP_Pawn(Pawn).nmNPCIdleAnim=AnimSequence;
	if ((AnimSequence != "None") && (AnimSequence != "None"))
	{
		if (AnimChannel > 1)
		{
			Pawn.AnimBlendParams(AnimChannel,1,Pawn.BlendChangeTime,Pawn.BlendChangeTime);
		}
		if (Level.NetMode == NM_Standalone)
		{
			Pawn.LoopAnim(AnimSequence,1,0.75,AnimChannel);
		}
		else
		{
			Pawn.SetLoopingAnimAction(AnimSequence);
		}
	}
	if (FMath::FRand() > 0.8)
	{
		pnCurrentPathNode=FindClosePathNode();
		if (pnCurrentPathNode != nullptr)
		{
			JL"MoveToNewNode"
;
			Sleep(1.5);
			if (pnCurrentPathNode == nullptr)
			{
				Sleep(0.5);
				JL"RepeatAnim"
;
			}
			pnCurrentNodeLeadingToPathNode=PathNode(FindPathToward(pnCurrentPathNode,true));
			if (pnCurrentNodeLeadingToPathNode != nullptr)
			{
				MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,false,true);
				if (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode)
				{
					JL"MoveToNewNode"
;
				}
			}
			else
			{
				MoveToward(pnCurrentPathNode,pnCurrentPathNode,,false,true);
			}
			StopMovement();
			LookRight();
			FinishRotation();
			Sleep((FMath::FRand() * 1.5));
			LookLeft();
			FinishRotation();
			LookLeft();
			FinishRotation();
			Pawn.RotationRate.Yaw=int((fpTurnRate + float(2000)));
			Focus=nullptr;
			FocalPoint=(Pawn.Location + (float(512) *  Vector(pnCurrentPathNode.Rotation)));
			bRotateToDesired=true;
			FinishRotation();
		}
	}
	else
	{
		LookRight();
		FinishRotation();
		Sleep((FMath::FRand() * 1.5));
		LookLeft();
		FinishRotation();
		LookLeft();
		FinishRotation();
		LookRight();
		FinishRotation();
	}
	NPCLog("Now doing nothing (aside from any idle animations...");
	if (Pawn.bNetRelevant)
	{
		if (SelectIdleRelatedAnimation())
		{
			PrepIdleAnimationPlay();
			Sleep(1);
			if (AnimTime == 0)
			{
				AnimTime=0.75;
			}
			StopMovement();
			if (anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animStart != "None")
			{
				Sleep((PlayCustomAnimation(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animStart,false) - 0.1));
			}
			if (anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animMiddle != "None")
			{
				Sleep((PlayCustomAnimation(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animMiddle,false) - 0.1));
			}
			if (anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].AnimEnd != "None")
			{
				Sleep(PlayCustomAnimation(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].AnimEnd,false));
			}
			Sleep(0.5);
			PrepPostIdleAnimationPlay();
			Sleep(1);
		}
		if (AnimSequence != "None")
		{
			if (AnimChannel > 1)
			{
				Pawn.AnimBlendParams(AnimChannel,1,Pawn.BlendChangeTime,Pawn.BlendChangeTime);
			}
			if (Level.NetMode == NM_Standalone)
			{
				Pawn.LoopAnim(AnimSequence,1,0.75,AnimChannel);
			}
			else
			{
				Pawn.SetLoopingAnimAction(AnimSequence);
			}
		}
	}
	Sleep((2.5 + (FMath::FRand() * 4)));
	JL"RepeatAnim"
;
}
*/

/*
State PawnHavingConversation extends PawnStartsAsDummy
{
}
*/

/*
State ForcedIdle
{
	Event HearNoise(float Loudness, AActor* NoiseMaker, Vector vSoundLocation)
	{
	}
	Event bool NotifyBump(AActor* Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
	}
	Function Timer()
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
	Function BeginState()
	{
	}
Begin:
	Sleep(0);
	NPCLog("Entered ForcedIdle state where we will do nothing: " $ string(pnCurrentPathNode));
	if ((pnCurrentPathNode != nullptr) && pnCurrentPathNode.IsA("NPCRestStopPathNode"))
	{
		NPCLog("ForcedIdle - at rest stop node");
		if (NPCRestStopPathNode(pnCurrentPathNode).npcassNPCAnimationToPerform.animStart != "None")
		{
			Sleep(PlayCustomAnimation(NPCRestStopPathNode(pnCurrentPathNode).npcassNPCAnimationToPerform.animStart));
			if (NPCRestStopPathNode(pnCurrentPathNode).npcassNPCAnimationToPerform.animMiddle != "None")
			{
				Sleep(PlayCustomAnimation(NPCRestStopPathNode(pnCurrentPathNode).npcassNPCAnimationToPerform.animMiddle));
			}
			if (NPCRestStopPathNode(pnCurrentPathNode).npcassNPCAnimationToPerform.AnimEnd != "None")
			{
				Sleep(PlayCustomAnimation(NPCRestStopPathNode(pnCurrentPathNode).npcassNPCAnimationToPerform.AnimEnd));
			}
		}
		Sleep(NPCRestStopPathNode(pnCurrentPathNode).fpTimeToRest);
	}
	Sleep(2.5);
	JL"Begin"
;
}
*/

/*
State ArrivedAtRestStop
{
	Function PrepRestStopArrival()
	{
	}
	Function PrepRestStopDeparture()
	{
	}
	Function EndState()
	{
		AGP_Pawn(Pawn).nmNPCIdleAnim="None";
		AGP_Pawn(Pawn).AnimLoopAction="None";
		AGP_Pawn(Pawn).AnimAction="None";
		AGP_Pawn(Pawn).PlayWaiting();
		AGP_Pawn(Pawn).PlayMoving();
		NPCPathLog(" Leaving ArrivedAtRestStop State");
	}
	Event PatrolResumeTriggerEvent()
	{
		NPCLog("PatrolResumeTriggerEvent() entered");
		if (! ShouldMoveToNextPathNode())
		{
			return;
		}
		DetermineNextPathNode();
		NPCChangeState("WalkingPatrol");
	}
Begin:
	NPCPathLog("Rest stop hit, performing actions");
	if (Pawn.bNetRelevant)
	{
		DesiredRotation=pnCurrentLocation.Rotation;
		Focus=nullptr;
		FocalPoint=(Pawn.Location + (float(512) *  Vector(pnCurrentLocation.Rotation)));
		bRotateToDesired=true;
		FinishRotation();
		if (NPCRestStopPathNode(pnCurrentLocation).npcassNPCAnimationToPerform.animStart != "None")
		{
			PrepRestStopArrival();
			Sleep(FMath::FRand());
			Sleep(PlayCustomAnimation(NPCRestStopPathNode(pnCurrentLocation).npcassNPCAnimationToPerform.animStart));
			if ((NPCRestStopPathNode(pnCurrentLocation).npcassNPCAnimationToPerform.animMiddle != "None") && (NPCRestStopPathNode(pnCurrentLocation).npcassNPCAnimationToPerform.animMiddle != "None"))
			{
				Sleep(PlayCustomAnimation(NPCRestStopPathNode(pnCurrentLocation).npcassNPCAnimationToPerform.animMiddle));
			}
			if ((NPCRestStopPathNode(pnCurrentLocation).npcassNPCAnimationToPerform.AnimEnd != "None") && (NPCRestStopPathNode(pnCurrentLocation).npcassNPCAnimationToPerform.AnimEnd != "None"))
			{
				Sleep(PlayCustomAnimation(NPCRestStopPathNode(pnCurrentLocation).npcassNPCAnimationToPerform.AnimEnd));
			}
			Sleep(0);
			PrepRestStopDeparture();
		}
	}
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation.bStopHere)
	{
		NPCPathLog("Stop being forced here to ForcedIdle");
		NPCChangeState("ForcedIdle");
		JL"End"
;
	}
	NPCPathLog("Finished rest stop actions aside from any delay timer");
	if (NPCRestStopPathNode(pnCurrentLocation).bWaitForResumePatrolTrigger && bUseResumePatrolStartTrigger)
	{
		JL"End"
;
	}
	if (! ShouldMoveToNextPathNode())
	{
		JL"End"
;
	}
	DetermineNextPathNode();
	NPCChangeState("WalkingPatrol");
}
*/

/*
State LookAround
{
Begin:
	if (! Pawn.bNetRelevant)
	{
		Sleep(2.5);
		JL"End"
;
	}
	Sleep(0);
	NPCPathLog("Starting look around mode");
	if (FMath::FRand() > 0.5)
	{
		LookLeft();
		FinishRotation();
		Sleep((FMath::FRand() * 1.5));
		LookRight();
		FinishRotation();
		LookRight();
		FinishRotation();
	}
	else
	{
		LookRight();
		FinishRotation();
		Sleep((FMath::FRand() * 1.5));
		LookLeft();
		FinishRotation();
		LookLeft();
		FinishRotation();
	}
	NPCPathLog("Done looking");
	Sleep((FMath::FRand() * 1.5));
	Pawn.RotationRate.Yaw=iDefaultYawTurnRate;
	NPCChangeState("WalkingPatrol","FacePathNode");
}
*/

/*
State Cowering
{
	Function BeginState()
	{
		NPCLog("");
		NPCLog("");
		NPCLog("");
		NPCLog("ENTERING COWERING");
		NPCLog("Pawn is cowering at current location");
		if (GetConfidenceLevel() > float(-90))
		{
			SetConfidenceLevel((-90 - 1));
		}
	}
	Function PlayCowerAnimation()
	{
	}
	Function AdjustConfidenceByTime()
	{
		float fpUpdateDeltaTime = 0;
		fpUpdateDeltaTime=5;
		if (GetWorld()->GetTimeSeconds() > (fpTimeLastNervousnessChange + fpUpdateDeltaTime))
		{
			IncreaseConfidence(14);
		}
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		NPCLog("Cowering - current confidence: " $ string(GetConfidenceLevel()) $ " vs. min for movement" $ string(-40));
		if (GetConfidenceLevel() >= float(-40))
		{
			NPCLog("");
			NPCLog("");
			NPCLog("");
			NPCLog("Pawn leaving cowering due to confidence change");
			NPCChangeState("ReturnToPatrol");
		}
	}
Begin:
	Sleep(0);
	StopMovement();
	PlayCowerAnimation();
}
*/

/*
State LiveGrenade
{
	Function Timer()
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
	}
	Event HearNoise(float Loudness, AActor* NoiseMaker, Vector vSoundLocation)
	{
	}
	Function PathNode GetPathNodeFromRoute(APathNode* pnLastNode, APathNode* pnDesiredLocation)
	{
		int32 i = 0;
		if (pnLastNode == nullptr)
		{
			return PathNode(FindPathToward(pnDesiredLocation,true));
		}
		for (i=0; i<61; i++)
		{
			if ((RouteCache[i] == pnLastNode) && (RouteCache[(i + 1)] != nullptr))
			{
				return PathNode(RouteCache[(i + 1)]);
			}
			if (RouteCache[i] == nullptr)
			{
				return PathNode(FindPathToward(pnDesiredLocation,true));
			}
		}
		return PathNode(FindPathToward(pnDesiredLocation,true));
	}
	Event WeaponCollision(AActor* actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding.IsA("Mover") && (! Mover(actorColliding).bNotADoor))
		{
			if (Mover(actorColliding).bInterpolating)
			{
				return;
			}
			OpenDoorFromHere(Pawn.Location,Mover(actorColliding));
			NPCChangeState(GetStateName(),"PauseAfterBumpOnWayToPath");
		}
		if (actorColliding != nullptr)
		{
			AGP_Pawn(Pawn).GuardWeapon3p(6);
		}
		else
		{
			Pawn.UpperBodyAnimComplete();
		}
	}
	Function bool IsInMortalDanger()
	{
		if ((actThreat != nullptr) && (VSize((Pawn.Location - actThreat.Location)) < float(600)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	Event bool NotifyBump(AActor* Other)
	{
		NPCLog("Running for cover and bumped into something.");
		if (Other.IsA("Pawn") && Other.IsInState("InCover"))
		{
			NPCLog("Running for cover, pawn we bumped is in cover, we must go elsewhere.");
			NPCChangeState(GetStateName());
			return true;
		}
		if (((((pnCoverNode != nullptr) && (VSize((Pawn.Location - pnCoverNode.Location)) < float(175))) && LineOfSightTo(pnCoverNode)) && (pnCoverNode.cControllerUsingNode != nullptr)) && (pnCoverNode.cControllerUsingNode != Self))
		{
			StopMovement();
			NPCPathLog("PANIC BUMPED someone and destination node is now full, trying somewhere else");
			NPCChangeState(GetStateName());
			return false;
		}
		return Global.fpTimeToEndLastInterrupt(Other);
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		if (Pawn == nullptr)
		{
			return true;
		}
		if (Wall.IsA("Mover"))
		{
			if (Mover(Wall).bNotADoor)
			{
				PickWallAdjust(HitNormal);
				return true;
			}
			else
			{
				if (Mover(Wall).bInterpolating)
				{
					NPCLog(string(Self) $ "." $ string(Tag) $ "." $ string(GetStateName()) $ ".NotifyHitWall() hit mover that is interpolating: " $ string(Wall));
					return true;
				}
				OpenDoorFromHere(Pawn.Location,Mover(Wall));
				NPCChangeState(GetStateName(),"PauseAfterBumpOnWayToPath");
				return true;
			}
			return false;
		}
		if (Wall.IsA("LevelInfo"))
		{
			return false;
		}
		if (pnCoverNode == nullptr)
		{
			return false;
		}
		if ((VSize((Pawn.Location - pnCoverNode.Location)) < float(50)) && ((actThreat != nullptr) || (! LineOfSightTo(actThreat))))
		{
			InCoverAction();
			return true;
		}
		return false;
	}
	Function EndState()
	{
		NPCLog("");
		NPCLog("");
		NPCLog("");
		NPCLog("LEAVING " $ string(GetStateName()));
	}
	Function AdjustStateByConfidenceLevel()
	{
	}
	Function NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
	{
		NPCLog("Another grenade while already in LiveGrenade mode...");
		if (LineOfSightTo(twpGrenade))
		{
			if (VSize((twpGrenade.Location - Pawn.Location)) < float(1000))
			{
				actThreat=twpGrenade;
				SetConfidenceLevel((-40 - float(GetConfidencePenalty())));
				NPCLog("Close grenade is dangerous to our hiding spot - we've got to move");
				NPCChangeState("LiveGrenade","Begin");
			}
		}
	}
	Function int32 GetConfidencePenalty()
	{
		return 15;
	}
	Function PerformGrenadeReaction()
	{
	}
	Function FName GetNoCoverState()
	{
		return "Cowering";
	}
	Function FName GetCoverState()
	{
		return "InCover";
	}
	Function InLastNodeBeforeCover()
	{
	}
	Function InCoverAction()
	{
		NPCLog("InCoverAction() - default action - stop and crouch");
		StopMovement();
		Crouch();
	}
	Function BeginState()
	{
		if (twpLastGrenadeHeard != nullptr)
		{
			PerformGrenadeReaction();
		}
	}
	Function AdjustConfidence()
	{
		if (GetConfidenceLevel() > float(-40))
		{
			if ((twpLastGrenadeHeard != nullptr) && twpLastGrenadeHeard.IsA("Throw_M67_Frag"))
			{
				IncreaseNervousness(8);
				IncreaseNervousness(10);
			}
		}
	}
	Function bool FinalCoverAction()
	{
		DesiredRotation=pnCoverNode.Rotation;
		Focus=nullptr;
		FocalPoint=(Pawn.Location + (float(1024) *  Vector(pnCoverNode.Rotation)));
		bRotateToDesired=true;
		return true;
	}
Begin:
	Sleep(0);
	NPCLog("");
	NPCLog("");
	NPCLog("");
	NPCLog("ENTERING LIVEGRENADE");
	if (twpLastGrenadeHeard != nullptr)
	{
		NPCLog("Grenade distance: " $ string(VSize((twpLastGrenadeHeard.Location - Pawn.Location))));
	}
	else
	{
		if (actThreat != nullptr)
		{
			NPCLog("Threat distance: " $ string(VSize((actThreat.Location - Pawn.Location))));
		}
	}
	StopMovement();
	AdjustConfidence();
	fpTimeGrenadeHeard=GetWorld()->GetTimeSeconds();
	pnCoverNode=FindCoverPathNode(false);
	NPCLog("1 - Initial find cover path node: " $ string(pnCoverNode));
	pnCurrentNodeOnPathToCover=nullptr;
	if (pnCoverNode == nullptr)
	{
		NPCLog("Couldn't find nearest cover, trying farthest");
		pnCoverNode=FindCoverPathNode(true);
	}
	if (pnCoverNode == nullptr)
	{
		NPCLog("Couldn't find farthest, looking for escape path");
		pnCoverNode=FindEscapePathNode(2000);
	}
	if (pnCoverNode == nullptr)
	{
		NPCLog("No cover node found, just dropping to ground and going to cower");
		NPCChangeState(GetNoCoverState());
	}
	else
	{
		if ((VSize((pnCoverNode.Location - Pawn.Location)) < float(4500)) || ((actThreat != nullptr) && (VSize((actThreat.Location - Pawn.Location)) < float(300))))
		{
			NPCPathLog("Trying to run to cover point " $ string(pnCoverNode) $ "." $ string(pnCoverNode.Tag) $ " distance: " $ string(VSize((pnCoverNode.Location - Pawn.Location))));
			if (FindPathToward(pnCoverNode,true) == nullptr)
			{
				NPCPathLog("ALMOST PANIC - Failed to find path to " $ string(pnCoverNode) $ ", trying to find alternate");
				DebugDumpRoute();
				pnCoverNode=FindEscapePathNode();
				NPCPathLog("Trying to run to alternate cover point " $ string(pnCoverNode) $ "." $ string(pnCoverNode.Tag) $ " distance: " $ string(VSize((pnCoverNode.Location - Pawn.Location))));
				if ((pnCoverNode == nullptr) || (FindPathToward(pnCoverNode,false) == nullptr))
				{
					DebugDumpRoute();
					NPCPathLog("PANIC - Found cover node, but no path to get there, node: " $ string(pnCoverNode));
					Prone();
					NPCChangeState(GetNoCoverState());
					JL"End"
;
				}
			}
			Stand();
			Run();
			if (true)
			{
				if (pnCurrentNodeOnPathToCover == nullptr)
				{
					pnCurrentNodeOnPathToCover=GetPathNodeFromRoute(nullptr,pnCoverNode);
					JL"MoveToNextNode"
;
					Sleep(0.75);
					MoveTo((Pawn.Location + (( Vector(Pawn.Rotation) * float(-1)) * (float(150) + (FMath::FRand() * float(50))))),,true);
					if (bDebugPath)
					{
						DebugDumpRoute();
					}
					if (pnCurrentNodeOnPathToCover != nullptr)
					{
						Pawn.RotationRate.Yaw=int((fpTurnRate + float(8000)));
						FocalPoint=(Pawn.Location + (float(512) *  Vector(Normalize(rotator((pnCurrentNodeOnPathToCover.Location - Pawn.Location))))));
						bRotateToDesired=true;
						FinishRotation();
					}
					else
					{
						NPCPathLog("PANIC - No actual path to cover node (Probably an ERROR in pathnoding), stopping here");
						Prone();
						NPCChangeState(GetNoCoverState());
						JL"End"
;
					}
				}
				else
				{
					pnCurrentNodeOnPathToCover=GetPathNodeFromRoute(pnCurrentNodeOnPathToCover,pnCoverNode);
				}
				NPCPathLog("PANIC - Moving to node " $ string(pnCoverNode) $ " via " $ string(pnCurrentNodeOnPathToCover));
				if (pnCurrentNodeOnPathToCover == nullptr)
				{
					Prone();
					NPCChangeState(GetNoCoverState());
					JL"End"
;
				}
				if ((pnCurrentNodeOnPathToCover != nullptr) && (pnCurrentNodeOnPathToCover != pnCoverNode))
				{
					DebugMarkNextNode(pnCurrentNodeOnPathToCover);
					UpdatePathNodeBonuses(nullptr);
					if (LineOfSightTo(pnCoverNode))
					{
						NPCLog("Can see cover node from here");
						if ((pnCoverNode.IsA("NPCCoverPositionPathNode") && (pnCoverNode.cControllerUsingNode != nullptr)) && (pnCoverNode.cControllerUsingNode != Self))
						{
							NPCPathLog("PANIC - destination node is now full, trying somewhere else");
							NPCChangeState("LiveGrenade");
							JL"End"
;
						}
					}
					Run();
					if ((NPCPathNode(pnCurrentNodeOnPathToCover) != nullptr) && NPCPathNode(pnCurrentNodeOnPathToCover).IsHallwayEntry())
					{
						if (! NPCPathNode(pnCurrentNodeOnPathToCover).RequestHallway(Self))
						{
							Sleep(0.5);
						}
					}
					MoveToward(pnCurrentNodeOnPathToCover,pnCurrentNodeOnPathToCover,,false,false);
					NPCPathNode(pnCurrentNodeOnPathToCover).ReleaseHallway(Self);
					if (pnCurrentNodeOnPathToCover.IsA("NPCDoorEntryPathNode"))
					{
						NPCLog("At door node while running for cover, opening it");
						if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)) != nullptr) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)).bClosed)
						{
							StopMovement();
							if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)))
							{
								NPCLog("opened door (or it was open): " $ string(mLastDoorOpened));
								Sleep(0.1);
								if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
								{
									Sleep(mLastDoorOpened.MoveTime);
									NPCLog("Door done moving (probably): " $ string(mLastDoorOpened));
								}
							}
						}
					}
					else
					{
						if (pnCurrentNodeOnPathToCover.IsA("NPCLadderPathNode"))
						{
							if (NPCLadderPathNode(pnCurrentNodeOnPathToCover).bNearLadderTop)
							{
								if (! ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume")))
								{
									StopMovement();
									lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeOnPathToCover);
									AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
									Sleep(0.25);
								}
							}
							else
							{
								if (NPCLadderPathNode(pnCurrentNodeOnPathToCover).bNearLadderBase)
								{
									Log("Ladder node is base of ladder, current ladder volume: " $ string(Pawn.PhysicsVolume));
									if ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume"))
									{
										AGP_Pawn(Pawn).EndClimbLadder(nullptr);
									}
									else
									{
										lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeOnPathToCover);
										AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
									}
								}
							}
						}
					}
				}
				else
				{
					if ((pnCoverNode.IsA("NPCCoverPositionPathNode") && (pnCoverNode.cControllerUsingNode != nullptr)) && (pnCoverNode.cControllerUsingNode != Self))
					{
						NPCPathLog("PANIC - destination node is now full, trying somewhere else");
						NPCChangeState("LiveGrenade");
						JL"End"
;
					}
					NPCPathLog("PANIC - No more nodes found on the way - moving to last node");
					DebugMarkNextNode(pnCoverNode);
					Run();
					MoveToward(pnCoverNode,pnCoverNode,,false,false);
				}
				else
				{
				}
			}
			NPCPathLog("PANIC - Made it to cover point");
			if (actThreat != nullptr)
			{
				NPCLog("PANIC - Turning towards threat");
				TurnToActor(actThreat,(fpTurnRate + float(6000)));
				Focus=actThreat;
				FinishRotation();
				NPCLog("PANIC - Finished turning towards threat");
			}
			else
			{
				Pawn.RotationRate.Yaw=int((fpTurnRate + float(2000)));
				Focus=nullptr;
				FocalPoint=(Pawn.Location + (float(512) *  Vector(pnCoverNode.Rotation)));
				bRotateToDesired=true;
				FinishRotation();
			}
			UpdatePathNodeBonuses(pnCoverNode);
			InCoverAction();
			NPCLog("Changing to cover state of: " $ string(GetCoverState()));
			NPCChangeState(GetCoverState());
		}
		else
		{
			NPCLog("Cover too far - just going prone and entering cowering state");
			Prone();
			NPCChangeState(GetNoCoverState());
		}
	}
	if (FinalCoverAction())
	{
		FinishRotation();
	}
}
*/

/*
State Panic extends LiveGrenade
{
	Function InitialPanicResponse()
	{
	}
Begin:
	InitialPanicResponse();
	JL"Begin"
;
}
*/

/*
State InCover
{
	Function AdjustStateByConfidenceLevel()
	{
		if (actThreat == nullptr)
		{
			Global.myPRI();
		}
	}
	Function BeginState()
	{
		NPCLog("ENTERING INCOVER state");
	}
	Function NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
	{
		NPCLog("Another grenade while in cover...");
		if (LineOfSightTo(twpGrenade))
		{
			actThreat=twpGrenade;
			if (VSize((twpGrenade.Location - Pawn.Location)) < float(1000))
			{
				NPCLog("Close grenade is dangerous to our hiding spot - we've got to move");
				NPCChangeState("LiveGrenade","Begin");
			}
		}
	}
	Function AdjustConfidenceByTime()
	{
		IncreaseConfidence(14);
	}
	Function ThreatEnded()
	{
		if (GetConfidenceLevel() > float((-40 + 5)))
		{
			NPCLog("Ending grenade state because of confidence");
			NPCChangeState("ReturnToPatrol");
		}
	}
	Function Timer()
	{
		NPCLog("Threat is: " $ string(actThreat));
		if ((actThreat == nullptr) || (GetWorld()->GetTimeSeconds() > (fpTimeGrenadeHeard + float(15))))
		{
			NPCLog("Live grenade - current confidence: " $ string(GetConfidenceLevel()) $ " vs. min for movement" $ string(-40));
			ThreatEnded();
			Global.pnCurrentNodeLeadingToPathNode();
		}
	}
}
*/

/*
State FindCover extends LiveGrenade
{
	Function PerformGrenadeReaction()
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Function AdjustStateByConfidenceLevel()
	{
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
	}
	Function int32 GetConfidencePenalty()
	{
		return 10;
	}
	Function FName GetCoverState()
	{
		return "InCover";
	}
	Function InCoverAction()
	{
		StopMovement();
		Crouch();
		fpTimeGrenadeHeard=GetWorld()->GetTimeSeconds();
	}
}
*/

/*
State ReturnToPatrol
{
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		if (Wall.IsA("Mover") && (! Mover(Wall).bNotADoor))
		{
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState("WalkingPatrol","OpeningDoor");
			return true;
		}
		return Global.pos(HitNormal,Wall);
	}
	Function EndState()
	{
		NPCPathLog("");
		NPCPathLog("");
		NPCPathLog("Leaving RETURNTOPATROL");
	}
	Function PathNode GetPathNodeFromRoute()
	{
		int32 i = 0;
		if (pnCurrentNodeOnPathToCover == nullptr)
		{
			return PathNode(FindPathToward(pnCurrentPathNode,false));
		}
		for (i=0; i<61; i++)
		{
			if ((RouteCache[i] == pnCurrentNodeOnPathToCover) && (RouteCache[(i + 1)] != nullptr))
			{
				return PathNode(RouteCache[(i + 1)]);
			}
			if (RouteCache[i] == nullptr)
			{
				return PathNode(FindPathToward(pnCurrentPathNode,false));
			}
		}
		return PathNode(FindPathToward(pnCurrentPathNode,false));
	}
Begin:
	Sleep(0);
	NPCPathLog("");
	NPCPathLog("");
	NPCPathLog("RETURNTOPATROL entered");
	if (iNPCCurrentOrders == 9)
	{
		NPCChangeState("AssaultLocation");
		JL"End"
;
	}
	if (pnCurrentPathNode == nullptr)
	{
		NPCPathLog("Determining next path node for patrol");
		FindNextPatrolPathNode();
	}
	if (pnCurrentPathNode == nullptr)
	{
		if (IsA(ANPCBaseSoldierController::StaticClass()))
		{
			NPCChangeState("FindCoverThenFight");
		}
		else
		{
			NPCChangeState("FindCover");
		}
		Log(string(Self) $ "." $ string(Tag) $ " cannot return to patrol - unable to find patrol - potential invalid orders");
		JL"End"
;
	}
	Stand();
	Walk();
	fpNodeVisionConeAngle=0;
	pnCurrentNodeOnPathToCover=nullptr;
	if (true)
	{
		pnCurrentNodeOnPathToCover=GetPathNodeFromRoute();
		NPCPathLog("Moving to node " $ string(pnCurrentPathNode) $ " via " $ string(pnCurrentNodeOnPathToCover));
		if ((pnCurrentNodeOnPathToCover != nullptr) && (pnCurrentNodeOnPathToCover != pnCurrentPathNode))
		{
			DebugMarkNextNode(pnCurrentNodeOnPathToCover);
			UpdatePathNodeBonuses(nullptr);
			MoveToward(pnCurrentNodeOnPathToCover,pnCurrentNodeOnPathToCover,,false,(! ShouldRun()));
			if (VSize((pnCurrentNodeOnPathToCover.Location - Pawn.Location)) > float(100))
			{
				DebugLog(DEBUG_AIPathing,"ReturningToPatrol - Pawn Tag: " $ string(Pawn.Tag) $ " failed to make it to node " $ string(pnCurrentNodeOnPathToCover) $ " on his way to waypoint: " $ string(pnCurrentPathNode) $ " Last waypoint node: " $ string(pnCurrentLocation));
				Sleep(1);
				(pnCurrentNodeOnPathToCover.FearCost += 100);
				pnCurrentNodeOnPathToCover=nullptr;
			}
			NPCPathLog("Finished moving to node " $ string(pnCurrentNodeOnPathToCover));
		}
		else
		{
			NPCPathLog("No more nodes found on the way - moving to last node");
			DebugMarkNextNode(pnCurrentPathNode);
			MoveToward(pnCurrentPathNode,pnCurrentPathNode,,false,(! ShouldRun()));
			if (VSize((pnCurrentPathNode.Location - Pawn.Location)) > float(100))
			{
				DebugLog(DEBUG_AIPathing,"ReturnToPatrol - Pawn Tag: " $ string(Pawn.Tag) $ " failed to make it to final waypoint: " $ string(pnCurrentPathNode) $ " Last waypoint node: " $ string(pnCurrentLocation));
				DebugLog(DEBUG_AIPathing,"Pawn Tag: " $ string(Pawn.Tag) $ " aborting return to patrol mode");
				GotoState("StuckByBadPath");
				JL"End"
;
			}
			NPCPathLog("Finished moving to final node ");
		}
		else
		{
		}
	}
	UpdatePathNodeBonuses(nullptr);
	NPCPathLog("Made it back to previous patrol point");
	NPCChangeState("WalkingPatrol");
}
*/

/*
State StuckByBadPath
{
	Function BeginState()
	{
	}
Begin:
	StopMovement();
	Sleep(0.5);
	GotoState("ReturnToPatrol");
}
*/

/*
State HeardPlayer
{
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		StopMovement();
		return true;
	}
	Function bool PerformPreLook()
	{
		return false;
	}
	Function PerformFinishedLooking()
	{
		NPCChangeState("ReturnToPatrol");
	}
	Event WeaponCollision(AActor* actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding != nullptr)
		{
			AGP_Pawn(Pawn).GuardWeapon3p(6);
		}
		else
		{
			Pawn.UpperBodyAnimComplete();
		}
	}
Begin:
	Sleep(0);
	StopMovement();
	if (PerformPreLook())
	{
		JL"End"
;
	}
	Sleep(0.25);
	Pawn.RotationRate.Yaw=int(fpTurnRate);
	bRotateToDesired=true;
	FinishRotation();
	fpTimeLastPawnHeard=GetWorld()->GetTimeSeconds();
	Sleep(0.25);
	PerformFinishedLooking();
}
*/

/*
State MoveBackAfterBump
{
	Event bool NotifyBump(AActor* Other)
	{
		if (! AdjustAround(Pawn(Other)))
		{
			BackupAfterBump(Pawn(Other));
			return false;
		}
		return true;
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		StopMovement();
		return true;
	}
	Function PlayBumpedAudio()
	{
	}
	Function ResumePreviousState()
	{
		NPCLog("Resuming previous state of: " $ string(GetLastStateName()));
		NPCChangeState(GetLastStateName());
	}
Begin:
	Sleep(0);
	StopMovement();
	PlayBumpedAudio();
	NPCLog("Try to move backward from " $ string(Pawn.Location) $ " to " $ string((Pawn.Location + (( Vector(Pawn.Rotation) * float(-1)) * float(100)))));
	MoveTo((Pawn.Location + (( Vector(Pawn.Rotation) * (-0.6 + (FMath::FRand() * 0.2))) * (float(150) + (FMath::FRand() * float(50))))),pawnBumped,true);
	NPCLog("Try to move backward");
	StopMovement();
	Sleep((5 * FMath::FRand()));
	if (Focus != Enemy)
	{
		Focus=nullptr;
	}
	DetermineNextPathNode();
	if (pnCurrentPathNode != nullptr)
	{
		if (! actorReachable(pnCurrentPathNode))
		{
			pnCurrentPathNode=nullptr;
		}
	}
	pawnBumped=nullptr;
	ResumePreviousState();
}
*/

/*
State Dead
{
	Function KilledBy(APawn* EventInstigator)
	{
	}
	Function Touch(AActor* Other)
	{
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
	}
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
	}
	Event EnemyNotVisible()
	{
	}
	Function NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
	}
	Event bool NotifyBump(AActor* Other)
	{
	}
	Function Timer()
	{
	}
	Function BeginState()
	{
		if (actLastSoundPlayedEffect != nullptr)
		{
			actLastSoundPlayedEffect.StopSound(sndLastSoundPlayed);
		}
		bStart=false;
	}
	Function PawnDied(APawn* p)
	{
		if (Level.NetMode != NM_Client)
		{
			NPCLog(" Pawn died while dead");
		}
	}
	Function ServerReStartPlayer()
	{
		if (Level.NetMode == NM_Client)
		{
			return;
		}
		NPCLog("Dead:ServerRestartPlayer() entered");
		Level.Game.RestartPlayer(Self);
	}
}
*/

/*
State GameEnded
{
	Function KilledBy(APawn* EventInstigator)
	{
	}
	Function TakeDamage(int32 Damage, APawn* EventInstigator, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, Actor.BoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterial* HitMaterial)
	{
	}
	Function ReceiveWarning(APawn* shooter, float projSpeed, Vector FireDir)
	{
	}
	Function BeginState()
	{
		NPCLog("GameEnded.BeginState() entered, pawn is " $ string(Pawn));
		bStart=false;
	}
}
*/

/*
State RoundEnded
{
	Function KilledBy(APawn* EventInstigator)
	{
	}
	Function TakeDamage(int32 Damage, APawn* EventInstigator, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, Actor.BoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterial* HitMaterial)
	{
	}
	Function ReceiveWarning(APawn* shooter, float projSpeed, Vector FireDir)
	{
	}
	Function BeginState()
	{
		NPCLog("RoundEnded.BeginState() entered, pawn is " $ string(Pawn));
		bStart=false;
	}
}
*/

/*
State Surrender
{
	Event HearNoise(float Loudness, AActor* NoiseMaker, Vector vSoundLocation)
	{
	}
	Event bool NotifyBump(AActor* Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
	Function BeginState()
	{
	}
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
	}
	Function bool UsedBy(APawn* User)
	{
		Crouch();
		return true;
	}
	Function InitialSurrenderActions()
	{
		NPCSay(1,true,true);
		Stand();
	}
	Function float PlaySurrenderAnimation()
	{
		return PlayCustomAnimation("SurrenderKneesStart");
	}
Begin:
	Sleep(0);
	StopMovement();
	iNPCTeamID=2;
	Pawn.HUDText="Surrendered Enemy Soldier";
	InitialSurrenderActions();
	SetCustomTimer(1,false,"SurrenderedThrowDownWeapon");
	Sleep(PlaySurrenderAnimation());
	if (AnimChannel > 1)
	{
		Pawn.AnimBlendParams(AnimChannel,1,Pawn.BlendChangeTime,Pawn.BlendChangeTime);
	}
	if (Level.NetMode == NM_Standalone)
	{
		Pawn.LoopAnim("SurrenderKneesLoop",1,0,AnimChannel);
	}
	else
	{
		Pawn.SetLoopingAnimAction("SurrenderKneesLoop");
	}
}
*/

void ANPCBaseController::WarnAboutToRunOverTeammate(AController* ctrlTeammate)
{
}
//native final Function FastPreloadPathNodeList();
void ANPCBaseController::FastPreloadPathNodeList()
{
}

//native final Function FastGetPathnodeByTagString (FString sTag);
APathNode* ANPCBaseController::FastGetPathnodeByTagString(FString sTag)
{
	return nullptr;   //FAKE  /EliZ
}

//native final Function FastFindCoverPathNode (bool bFindFarthestPointFromThreat);
void ANPCBaseController::FastFindCoverPathNode(bool bFindFarthestPointFromThreat)
{
}

//native final Function FastFindEscapePathNode (float fpMinDistance);
void ANPCBaseController::FastFindEscapePathNode(float fpMinDistance)
{
}

//native final Function LocateClosestNodeToLocation (FVector vLocation);
void ANPCBaseController::LocateClosestNodeToLocation(FVector vLocation)
{
}

//native final Function NPCPrivateLog (FString sLogText);
void ANPCBaseController::NPCPrivateLog(FString sLogText)
{
}

//native final Function IsLocationInFront (FVector vLocation);
void ANPCBaseController::IsLocationInFront(FVector vLocation)
{
}

//native final Function GetAngleToLocation (FVector vLocation);
void ANPCBaseController::GetAngleToLocation(FVector vLocation)
{
}

void ANPCBaseController::DisplayDebugNoSpam(AAGP_HUD* AGPHUD, UCanvas* C, float& YL, float& YPos, FColor NewColor)
{
	if (YL < 8)
	{
		YL=10;
	}
	/*
	DisplayDebug(Canvas,YL,YPos);
	*/
}

/*
void ANPCBaseController::GameHasEnded()
{
		bStart=False;
		NPCLog("GameHasEnded() entered, stopping controller");
		GotoState('None');
}
*/

bool ANPCBaseController::IsNormal()
{
	if (GetConfidenceLevel() > -10 && GetConfidenceLevel() < 70)
	{
		return true;
	}
	return false;
}
bool ANPCBaseController::IsConcerned()
{
	if (GetConfidenceLevel() < -10 && GetConfidenceLevel() >= -40)
	{
		return true;
	}
	return false;
}
bool ANPCBaseController::IsInPain()
{
	if (GetConfidenceLevel() <= -90)
	{
		return true;
	}
	return false;
}
bool ANPCBaseController::IsReckless()
{
	if (GetConfidenceLevel() >= 90)
	{
		return true;
	}
	return false;
}
bool ANPCBaseController::IsBrave()
{
	if (GetConfidenceLevel() < 90 && GetConfidenceLevel() >= 70)
	{
		return true;
	}
	return false;
}
bool ANPCBaseController::IsAgitated()
{
	return IsSuppressed();
}
bool ANPCBaseController::IsSuppressed()
{
	if (GetConfidenceLevel() <= -40 && GetConfidenceLevel() > -60)
	{
		return true;
	}
	return false;
}
bool ANPCBaseController::IsInPanic()
{
	if (GetConfidenceLevel() <= -60 && GetConfidenceLevel() > -90)
	{
		return true;
	}
	return false;
}

void ANPCBaseController::DecrementConfidenceLevel()
{
	fpConfidence -= fpNodeMentalStateChangeModifier;
	if (fpConfidence < -99)
	{
		fpConfidence = -99;
	}
}

void ANPCBaseController::IncrementConfidenceLevel()
{
	fpConfidence += fpNodeMentalStateRecoveryModifier;
	if (fpConfidence > 99)
	{
		fpConfidence = 99;
	}
}

void ANPCBaseController::SetConfidenceLevel(float fpNewConfidence)
{
	if (fpNewConfidence > 99)
	{
		fpNewConfidence = 99;
	}
	else
	{
		if (fpNewConfidence < -99)
		{
			fpNewConfidence = -99;
		}
	}
	fpConfidence = fpNewConfidence;
}

float ANPCBaseController::GetConfidenceLevel()
{
	return fpConfidence + fpNodeMentalStateBonus;
}
void ANPCBaseController::ChangeOrders(int32 iNewOrders)
{
	switch (iNewOrders)
	{
		case 0:
			NPCLog("ORDER-PATROL - Starting patrol");
			NPCChangeState("ReturnToPatrol","");
			break;
		case 1:
			NPCLog("ORDER_GUARD");
			NPCChangeState("GuardMode","");
			break;
		case 2:
			NPCLog("ORDER_AMBUSH");
			if (IsA(ANPCBaseSoldierController::StaticClass()))
			{
				NPCLog("Moving to a new fire position in Harass orders mode");
				NPCChangeState("MoveToNewCamperPosition","");
			}
			break;
		case 3:
			NPCLog("ORDER_HUNT");
			NPCChangeState("AdvanceOnEnemyLocation","");
			break;
		case 4:
			NPCLog("ORDER_DEFEND");
			if (IsA(ANPCBaseSoldierController::StaticClass()))
			{
				NPCLog("Moving to a new fire position in Harass orders mode");
				NPCChangeState("MoveToNewFiringPosition","");
			}
			break;
		case 5:
			NPCLog("ORDER_HARASS");
			if (IsA(ANPCBaseSoldierController::StaticClass()))
			{
				NPCLog("Moving to a new fire position in Harass orders mode");
				NPCChangeState("MoveToNewFiringPosition","");
			}
			break;
		case 6:
			NPCLog("ORDER_FLEE");
			if (iNPCCurrentOrders == iNewOrders)
			{
				return;
			}
			if (IsA(ANPCBaseSoldierController::StaticClass()))
			{
				Cast<ANPCBaseSoldierController>(this)->MoveToAlamoFirePosition();
			}
			break;
		case 9:
			if (IsA(ANPCBaseSoldierController::StaticClass()))
			{
				Cast<ANPCBaseSoldierController>(this)->NPCChangeState("AssaultLocation","");
			}
			break;
		case 8:
			NPCLog("ORDER_RUSH");
			NPCChangeState("AdvanceOnEnemyLocation","");
			break;
		default:
			NotifyTacticalOrderChange(iNewOrders);
			return;
	}
	iNPCCurrentOrders = iNewOrders;
}
void ANPCBaseController::NPCChangeState(FName nmState, FName nmLabel)
{
	if (GetStateName() == "Dead")
	{
		NPCLog("Dead pawn trying to change state from Dead state - discarding");
		return;
	}
	if (nmState == "Dead")
	{
		ChangeState(nmState);
		//GotoState(nmState, nmLabel);
		return;
	}
	if (GetStateName() == "PawnStartsAsDummy")
	{
		if (bDummyPawnIgnoreAllEvents)
		{
			return;
		}
	}
	if ((GetStateName() == "FlashBanged") && (GetWorld()->GetTimeSeconds() < fpFlashBangedEndTime))
	{
		if (nmState == "FlashBanged")
		{
			ChangeState(nmState);
			//GotoState(nmState, nmLabel);
		}
		NPCLog("Flashbanged pawn trying to change state from Flashbanged state - discarding");
		return;
	}
	ChangeState(nmState);
	//GotoState(nmState, nmLabel);
}

void ANPCBaseController::NotifyTacticalOrderChange(int32 iNewTacOrders)
{
	iNPCTacticalOrders = iNewTacOrders;
}

void ANPCBaseController::Reset()
{
	/*
	local AGP_Pawn agpPawnIterator;
	Reset();
	NPCLog("Reset() entered");
	bStart=False;
	Enemy=None;
	pnCurrentPathNode=None;
	SetConfidenceLevel(iNPCInitialMentalState);
	if (Pawn == nullptr)
	{
		Log("FAILURE - NPC has no pawn, starting search for pawn!");
		ForEach AllActors('AGP_Pawn',agpPawnIterator)
		{
			Log("Examining pawn " $ agpPawnIterator.Name $ " vs. needed " $ namePawnName);
			if (agpPawnIterator.Name ~= namePawnName)
			{
				Log("Found pawn for controller: " $ namePawnName);
				Possess(Pawn);
			}
			else
			{
			}
		}
		if (Pawn == nullptr)
		{
			Log("MUST RECREATE PAWN");
		}
	}
	if (Pawn != None)
	{
		NPCLog("Restoring draw type of DT_Mesh");
		SetDrawType(2);
		if (iStartingPathNodeIndex > 0)
		{
			iCurrentPathNodeIndex=iStartingPathNodeIndex - 1;
		}
		else
		{
			iCurrentPathNodeIndex=0;
		}
		Pawn.MatchStarting();
		if (! Pawn.IsA('Vehicle'))
		{
			InitializePawn();
			WantsToWalk();
		}
		SetLocation(Pawn.Location);
		NPCLog("Finished initializing pawn, setting controller to pawn's location");
	}
	else
	{
		NPCChangeState('None');
	}
*/
}
void ANPCBaseController::InitializePawn()
{
	/*
	local Actor Item;
	local int iAttach;
	NPCLog("Pawn location is " $ Pawn.Location.X $ "," $ Pawn.Location.Y $ "," $ Pawn.Location.Z);
	Pawn.PlayWaiting();
	Pawn.bTearOff=False;
	Pawn.bPlayedDeath=False;
	Pawn.bReplicateAnimations=True;
	Pawn.bReplicateMovement=True;
	Pawn.bPhysicsAnimUpdate=True;
	Pawn.bAlwaysRelevant=False;
	Pawn.SetMovementPhysics();
	Pawn.bProjTarget=True;
	Pawn.SightRadius=fpNPCMaxVisualRange;
	if (bDebugCombat)
	{
		Log("Initializing sight radius for pawn to " $ Pawn.SightRadius);
	}
	Pawn.SoundOcclusion=3;
	InitPlayerReplicationInfo();
	if (Pawn._InvHands == nullptr)
	{
		Pawn._InvHands=AGP_Pawn(Pawn).SpawnContainer("AGP_Inventory.InvHands");
		Pawn._InvShoulder=AGP_Pawn(Pawn).SpawnContainer("AGP_Inventory.InvShoulder");
	}
	Pawn.bStopAtLedges=False;
	Pawn.bCanJump=True;
	Pawn.bCanWalkOffLedges=True;
	Pawn.SetPhysics(2);
	for (iAttach=0; iAttach<aoAttachments.Length; iAttach++)
	{
		Item=Spawn(aoAttachments[iAttach].Attachment);
		actAttachments.insert (0,1);
		actAttachments[0]=Item;
		if (Item != None)
		{
			Pawn.AttachToBone(Item,aoAttachments[iAttach].Bone);
		}
		else
		{
			Log("AGP_NPC::SetAttachments(): ERROR: Item is NONE");
		}
		else
		{
			Item.SetRelativeLocation(aoAttachments[iAttach].LocationOffset);
			Item.SetRelativeRotation(aoAttachments[iAttach].RotationOffset);
			if (aoAttachments[iAttach].bUseParentScale)
			{
				Item.SetDrawScale(Pawn.DrawScale);
			}
			else
			{
				if (aoAttachments[iAttach].Scale == 0)
				{
					Item.SetDrawScale(1);
				}
				else
				{
					Item.SetDrawScale(aoAttachments[iAttach].Scale);
				}
			}
		}
	}
*/
}
void ANPCBaseController::Destroyed()
{
	/*
	local int iAttach;
	apnPathNodesForPatrol.remove (0,apnPathNodesForPatrol.Length);
	if (Pawn != None)
	{
		NPCLog("Pawn controller being destroyed for  " $ Pawn.Tag $ " name: " $ Pawn.Name);
	}
	else
	{
		NPCLog("NPCBaseController being destroyed!");
	}
	if (Pawn != None)
	{
		if (Pawn._InvHands != None)
		{
			Pawn._InvHands.Destroy();
			Pawn._InvHands=None;
		}
		if (Pawn._InvShoulder != None)
		{
			Pawn._InvShoulder.Destroy();
			Pawn._InvShoulder=None;
		}
		if (Pawn._InvHolster != None)
		{
			Pawn._InvHolster.Destroy();
			Pawn._InvHolster=None;
		}
		if (Pawn._InvUtility != None)
		{
			Pawn._InvUtility.Destroy();
			Pawn._InvUtility=None;
		}
		Pawn.Destroy();
	}
	for (iAttach=0; iAttach<actAttachments.Length; iAttach++)
	{
		if (actAttachments[iAttach] != None)
		{
			NPCLog(Self $ ".Destroyed() - cleaning up attachment: " $ actAttachments[iAttach]);
			actAttachments[iAttach].Destroy();
		}
	}
	actAttachments.remove (0,actAttachments.Length);
	RemoveController();
*/
}
/*
void ANPCBaseController::Possess(APawn* aPawn)
{
	NPCLog("NPCBaseController::Possess entered for " $ aPawn.Tag);
	if (aPawn.IsA('Vehicle') || ! AGP_Pawn(aPawn).bDummyPawn)
	{
		Possess(aPawn);
		if (PlayerReplicationInfo == nullptr)
		{
			InitPlayerReplicationInfo();
		}
		namePawnName=aPawn.Name;
		if (Len(sNPCWaypointTag) == 0)
		{
			sNPCWaypointTag=aPawn.Tag;
		}
		NPCLog("Pawn class is: " $ Pawn.Class);
		vInitialLocation=Pawn.Location;
		rotInitialRotation=Pawn.Rotation;
		Pawn.bCanClimbLadders=True;
		iNPCCurrentOrders=iNPCPrimaryOrders;
		NPCLog("NPCBaseController::Possess initalizing " $ aPawn.Tag);
		iDefaultYawTurnRate=Pawn.RotationRate.Yaw;
		if (iStartingPathNodeIndex > 0)
		{
			iCurrentPathNodeIndex=iStartingPathNodeIndex - 1;
		}
		else
		{
			iCurrentPathNodeIndex=0;
		}
		if (! Pawn.IsA('Vehicle'))
		{
			InitializePawn();
		}
		if (! Pawn.IsA('Vehicle'))
		{
			AGP_Pawn(Pawn).bIsScriptedWalking=False;
			Pawn.NavigationPointRange=Pawn.CollisionRadius * -0.9;
		}
		bPerfectAccuracy=False;
		SetConfidenceLevel(iNPCInitialMentalState);
		if (bDebugSenses && ! Pawn.IsA('Vehicle'))
		{
			Log("Creating debugging sphere on client for audio/visual senses");
			AGP_Pawn(Pawn).CreateVisualHearingDebugSpheres(fpNPCHearingRadius,fpNPCMaxVisualRange);
			DebugEnableVisionCone(True);
		}
		NPCLog("NPCBaseController::Possess starting timer and pawn for " $ aPawn.Tag);
		SetTimer(2,True);
	}
}
*/

void ANPCBaseController::DebugEnableVisionCone(bool bEnable)
{
	/*
	local float fpVisionScale;
	if (! bEnable)
	{
		if (AGP_Pawn(Pawn).VisionDistActor != None)
		{
			AGP_Pawn(Pawn).VisionDistActor.bHidden=True;
		}
		Return;
	}
	if (AGP_Pawn(Pawn).VisionDistActor == nullptr)
	{
		AGP_Pawn(Pawn).CreateVisualHearingDebugSpheres(0,fpNPCMaxVisualRange);
		fpVisionScale=Sin(fpNPCVisionConeAngle / 2 / 65536 * 2 * 3.1214) * fpNPCMaxVisualRange;
		AGP_Pawn(Pawn).VisionDistActor.SetDrawScale3D(MakeVect(fpVisionScale,fpNPCMaxVisualRange,fpVisionScale));
	}
	else
	{
		AGP_Pawn(Pawn).VisionDistActor.bHidden=False;
	}
*/
}
void ANPCBaseController::Start()
{
	/*
	local Actor actObjectiveIterator;
	local Object.BoneOffset BO;
	if (Pawn == nullptr)
	{
		Return;
	}
	bStart=True;
	Disable('MayFall');
	Disable('SeeMonster');
	Enable('HearNoise');
	Enable('SeePlayer');
	Enable('EnemyNotVisible');
	if (bStartAsDummyPawn)
	{
		NPCLog("Starting as Dummy Pawn, anim sequence: " $ AnimSequence);
		NPCChangeState('PawnStartsAsDummy');
		Return;
	}
	Pawn.PlayWaiting();
	WantsToWalk();
	if (bTriggerLinkedToObjective && TriggerToActivate != 'None')
	{
		BO.VOffset=vect(-33 -56 2);
		BO.ROffset.Roll=-16384;
		BO.nBone='Pelvis';
		ForEach AllActors(Class'Actor',actObjectiveIterator,TriggerToActivate)
		{
			AGP_Pawn(Pawn).AttachToBoneOffset(actObjectiveIterator,BO);
		}
	}
	if (fpDelayedInitialOrderExecutionTime > 0)
	{
		SetCustomTimer(fpDelayedInitialOrderExecutionTime,False,'DelayedInitialOrders');
	}
	else
	{
		ChangeOrders(iNPCPrimaryOrders);
	}
*/
}
void ANPCBaseController::DelayedInitialOrders()
{
	//ChangeOrders(iNPCPrimaryOrders);
}
void ANPCBaseController::Timer()
{
	/*
	if (Pawn == nullptr)
	{
		Return;
	}
	if (! bStart)
	{
		if (Level.Game.GameReplicationInfo.bMatchHasBegun || Level.NetMode == 0)
		{
			Start();
		}
	}
	else
	{
		AdjustConfidenceByTime();
		AdjustStateByConfidenceLevel();
		if (GetWorld()->GetTimeSeconds() > fpTimeLastHeard + 10)
		{
			aLastActorHeard=None;
		}
		if (GetWorld()->GetTimeSeconds() > fpTimeLastSeen + 5)
		{
			aLastActorSeen=None;
		}
		AgeHistoryContacts();
	}
*/
}
void ANPCBaseController::Run(bool bJog)
{
	/*
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Pawn.IsA('Vehicle'))
	{
		Return;
	}
	Stand();
	if (Pawn.Weapon != None && Pawn.Weapon.IsA('RocketWeapon'))
	{
		bJog=True;
	}
	AGP_Pawn(Pawn).ResetLean();
	if (IsInState('LiveGrenade') || IsInState('MoveToAlamoPosition') || IsInState('FindCoverThenFight') && IsA('NPCBaseSoldierController') && Cast<ANPCBaseSoldierController>(this)->sLastAICCMessage == "FallBack" && FMath::FRand() >= 0.5)
	{
		AGP_Pawn(Pawn).fWalkSpeed=150;
		AGP_Pawn(Pawn).fRunSpeed=300;
		Pawn.MovementAnimRate[0]=1.25;
		Pawn.MovementAnimRate[1]=1.25;
		Pawn.MovementAnimRate[2]=1.25;
		Pawn.MovementAnimRate[3]=1.25;
	}
	else
	{
		AGP_Pawn(Pawn).fWalkSpeed=120;
		AGP_Pawn(Pawn).fRunSpeed=220;
		Pawn.MovementAnimRate[0]=1;
		Pawn.MovementAnimRate[1]=1;
		Pawn.MovementAnimRate[2]=1;
		Pawn.MovementAnimRate[3]=1;
	}
	if (! bJog)
	{
		AGP_Pawn(Pawn).bWantsToSprint=True;
	}
	else
	{
		AGP_Pawn(Pawn).bWantsToSprint=False;
	}
	AGP_Pawn(Pawn).SetWalking(False);
	if (! bJog)
	{
		if (fpRunAnimRate > 0 && fpRunAnimRate != 1)
		{
			Log("Setting animation rate to " $ fpRunAnimRate);
			Pawn.MovementAnimRate[0]=fpRunAnimRate;
			Pawn.MovementAnimRate[1]=fpRunAnimRate;
			Pawn.MovementAnimRate[2]=fpRunAnimRate;
			Pawn.MovementAnimRate[3]=fpRunAnimRate;
		}
	}
	AGP_Pawn(Pawn).ChangeAnimation();
*/
}
void ANPCBaseController::Walk()
{
	/*
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Pawn.IsA('Vehicle'))
	{
		Return;
	}
	if (AGP_Pawn(Pawn).fWalkSpeed > 120)
	{
		AGP_Pawn(Pawn).fWalkSpeed=120;
		AGP_Pawn(Pawn).fRunSpeed=220;
		Pawn.MovementAnimRate[0]=1;
		Pawn.MovementAnimRate[1]=1;
		Pawn.MovementAnimRate[2]=1;
		Pawn.MovementAnimRate[3]=1;
	}
	AGP_Pawn(Pawn).StopSprint();
	Stand();
	AGP_Pawn(Pawn).SetPhysics(1);
	AGP_Pawn(Pawn).Acceleration=vect(0 0 1);
	Pawn.SetMovementPhysics();
	Pawn.SetWalking(True);
	Pawn.PlayMoving();
	AGP_Pawn(Pawn).ChangeAnimation();
*/
}
void ANPCBaseController::Stand()
{
	/*
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Pawn.IsA('Vehicle'))
	{
		Return;
	}
	AGP_Pawn(Pawn).StopSprint();
	if (Pawn.bIsCrouched)
	{
		Pawn.ShouldCrouch(False);
		AGP_Pawn(Pawn).ChangeAnimation();
	}
	else
	{
		if (Pawn.bIsProne)
		{
			Pawn.ShouldProne(False);
			AGP_Pawn(Pawn).ChangeAnimation();
		}
	}
*/
}
void ANPCBaseController::Jump()
{
	/*
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Pawn.IsA('Vehicle'))
	{
		Return;
	}
	AGP_Pawn(Pawn).DoJump(False);
	AGP_Pawn(Pawn).ChangeAnimation();
*/
}
void ANPCBaseController::Crouch()
{
	/*
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Pawn.IsA('Vehicle'))
	{
		Return;
	}
	AGP_Pawn(Pawn).StopSprint();
	if (! Pawn.bIsCrouched)
	{
		Pawn.ShouldCrouch(True);
		Pawn.GroundSpeed=Pawn.fFastCrouchSpeed;
	}
	AGP_Pawn(Pawn).ChangeAnimation();
*/
}
void ANPCBaseController::Prone()
{
	/*
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Pawn.IsA('Vehicle'))
	{
		Return;
	}
	if (! Pawn.bIsProne)
	{
		Pawn.bIsSprinting=False;
		Pawn.SetWalking(False);
		Pawn.ShouldProne(True);
		Pawn.AccelRate=2048;
		Pawn.bWantsToSprint=False;
		Pawn.bIsWalking=False;
		Pawn.GroundSpeed=Pawn.fHCrawlSpeed;
		AGP_Pawn(Pawn).UpdateGroundspeeds();
		Pawn.PlayMoving();
	}
	AGP_Pawn(Pawn).ChangeAnimation();
*/
}
void ANPCBaseController::StopMovement()
{
	/*
	NPCLog("StopMovement called");
	if (Pawn == nullptr)
	{
		Return;
	}
	Pawn.Acceleration=vect(0 0 0);
	Pawn.PlayWaiting();
	if (Pawn.IsA('AGP_Pawn'))
	{
		AGP_Pawn(Pawn).ChangeAnimation();
	}
*/
}
void ANPCBaseController::TurnToActor(AActor* aActor, float Rate)
{
	/*
	local FRotator TempRot;
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Rate == 0)
	{
		Pawn.RotationRate.Yaw=fpTurnRate;
	}
	else
	{
		Pawn.RotationRate.Yaw=Rate;
	}
	TempRot=Normalize(aActor.Location - Pawn.Location);
	DesiredRotation.Yaw=TempRot.Yaw;
	bRotateToDesired=True;
*/
}
void ANPCBaseController::PlayTakingFireAudio()
{
}
void ANPCBaseController::NotifyBuzzedByBullet(AActor* aShooter)
{
	/*
	if (bTrainingCadre)
	{
		Return;
	}
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	NPCLog("Buzzed by bullet, confidence: " $ GetConfidenceLevel());
	IncreaseNervousness(0);
	PlayTakingFireAudio();
*/
}
void ANPCBaseController::AlertSquadMatesOfDamage(APawn* pawnInstigator)
{
}
void ANPCBaseController::MayFall()
{
	/*
	Pawn.bCanJump=True;
	Pawn.bCanWalkOffLedges=True;
*/
}
void ANPCBaseController::NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
	/*
	if (Pawn == nullptr || Pawn.Health <= 0)
	{
		Return;
	}
	if (VisIntensity / 1.13 < 0.1)
	{
		Return;
	}
	NPCLog(Self $ "." $ GetStateName() $ ".NotifyFlashBanged() - Dur: " $ Duration $ ", VisInt: " $ VisIntensity $ ", AudInt: " $ AudIntensity);
	if (GetWorld()->GetTimeSeconds() > fpFlashBangedEndTime)
	{
		fpFlashBangedVisualIntensity=VisIntensity;
		fpFlashBangedAudioIntensity=AudIntensity;
	}
	else
	{
		if (fpFlashBangedVisualIntensity < VisIntensity)
		{
			fpFlashBangedVisualIntensity=VisIntensity;
		}
		if (fpFlashBangedAudioIntensity < AudIntensity)
		{
			fpFlashBangedAudioIntensity=AudIntensity;
		}
	}
	fpFlashBangedEndTime=GetWorld()->GetTimeSeconds() + Duration;
	fpFlashBangDuration=Duration;
	NPCLog(GetWorld()->GetTimeSeconds() $ " - Wanting to change to FlashBanged state until " $ fpFlashBangedEndTime $ " duration " $ Duration $ " currently in state " $ GetStateName());
	NPCChangeState('FlashBanged');
*/
}
void ANPCBaseController::NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone)
{
	AController* ctrlIterator = nullptr;
	if (! bStart)
	{
		return;
	}
	/*
	if ((Pawn != nullptr) && (Pawn.Health <= 0))
	{
		return;
	}
	if ((Pawn.Health - Damage) <= 0)
	{
		if (Bone.Name == "BN_HeadEnd")
		{
			return;
		}
	}
	if (DamageType == class'AGP.BleedDamage')
	{
		return;
	}
	for (ctrlIterator=Level.ControllerList; ctrlIterator!=nullptr; ctrlIterator=ctrlIterator.nextController)
	{
		if (! ctrlIterator.IsA("NPCBaseController"))
		{
		}
		if ((ctrlIterator != Self) && (instigatedBy != nullptr))
		{
			NPCBaseController(ctrlIterator).NotifyAnotherPawnTookDamage(instigatedBy,Self);
		}
	}
	NPCLog("Damage \"" $ string(DamageType) $ "\" received by NPC: " $ string(Damage));
	IncreaseNervousness(7);
	if (instigatedBy != nullptr)
	{
		AlertSquadMatesOfDamage(instigatedBy);
	}
	if (Pawn.Health > 0)
	{
		NPCLog("Pawn saying I'm hit!");
	}
*/
}
void ANPCBaseController::NotifyAnotherPawnDied(ANPCBaseController* npcpc)
{
}
void ANPCBaseController::NotifyAnotherPawnTookDamage(APawn* pInstigator, ANPCBaseController* anpcbcDamaged)
{
}
void ANPCBaseController::EnemyNotVisible()
{
	/*
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	if (Enemy != None)
	{
		NPCLog("Lost sight on enemy!");
		NotifyEnemyNotVisible();
	}
*/
}
void ANPCBaseController::NotifyEnemyNotVisible()
{
	/*
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	NPCLog("NotifyEnemyNotVisible() entered for Enemy: " $ Enemy);
	LostHistoryContact(Enemy);
	if (Focus == Enemy)
	{
		Focus=None;
	}
	Enemy=None;
*/
}
void ANPCBaseController::NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
{
	/*
	local float fpRange;
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	if (twpGrenade == nullptr)
	{
		Return;
	}
	fpRange=VSize(Pawn.Location - twpGrenade.Location);
	if (fpRange < 1500 && LineOfSightTo(twpGrenade))
	{
		AddGrenadeContact(twpGrenade);
		NPCLog("Close grenade - we need to react as it's only " $ VSize(Pawn.Location - twpGrenade.Location) $ " units away");
		if (! twpGrenade.IsA('PickupT_M83_Smoke'))
		{
			NPCChangeState('LiveGrenade','Begin');
		}
	}
	else
	{
		if (fpRange < fpNPCMaxVisualRange)
		{
			AddGrenadeContact(twpGrenade);
		}
	}
	if (AGP_Pawn(Pawn) != None && AGP_Pawn(Pawn).MyDebug_InterruptIcon != None)
	{
		AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("SeeGrenade");
	}
*/
}
void ANPCBaseController::HearBulletImpactNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation)
{
	/*
	if (bTrainingCadre)
	{
		Return;
	}
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	if (NoiseMaker == Pawn)
	{
		Return;
	}
	if (VSize(Pawn.Location - vSoundLocation) < 250)
	{
		NotifyHeardBulletImpactNoise(NoiseMaker,vSoundLocation);
	}
*/
}
void ANPCBaseController::NotifyHeardBulletImpactNoise(AActor* NoiseMaker, FVector vImpactLocation)
{
	//NPCChangeState('FindCover');
}
void ANPCBaseController::HearNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation)
{
	/*
	local FVector vLocationToConsider;
	local float fpDistanceToNoiseLocation;
	if (bTrainingCadre)
	{
		Return;
	}
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	if (NoiseMaker == Pawn)
	{
		Return;
	}
	if (! NoiseMaker.IsA('Vehicle') && ! NoiseMaker.IsA('Pawn') && ! NoiseMaker.IsA('Weapon') && ! NoiseMaker.IsA('Pickup'))
	{
		NPCLog("sound we don't care about - ignoring it...");
		Return;
	}
	vLocationToConsider=NoiseMaker.Location;
	if (vSoundLocation != NoiseMaker.Location)
	{
		Log(NoiseMaker $ " has a location different than sound location");
		vLocationToConsider=vSoundLocation;
	}
	fpDistanceToNoiseLocation=VSize(vLocationToConsider - Pawn.Location);
	if (NoiseMaker.IsA('AGP_Pawn') && AGP_Pawn(NoiseMaker).Controller != None && AGP_Pawn(NoiseMaker).Controller.IsA('NPCBaseController'))
	{
		Return;
	}
	if (NoiseMaker.IsA('Vehicle') || NoiseMaker.IsA('AGP_Weapon'))
	{
		if (fpDistanceToNoiseLocation > fpNPCHearingRadius * fpNodeHearingRangeModifier * 4)
		{
			Return;
		}
	}
	else
	{
		if (fpDistanceToNoiseLocation > fpNPCHearingRadius * fpNodeHearingRangeModifier)
		{
			NPCLog("Pawn noise sound too far away");
			Return;
		}
	}
	if (! NoiseMaker.IsA('Vehicle') && NoiseMaker.IsA('Pawn') && Pawn(NoiseMaker).IsHumanControlled() && ! NoiseMaker.bCollideWorld)
	{
		Return;
	}
	NPCLog("NPC evaluating noise: " $ NoiseMaker);
	if (LineOfSightTo(NoiseMaker))
	{
		NPCLog("NPC can see the noise maker if he's looking the right way");
		if (NoiseMaker.IsA('Throw_M83_Smoke') || NoiseMaker.IsA('Throw_M67_Frag') || NoiseMaker.IsA('Throw_M84_Stun'))
		{
			NPCLog("Grenade of some kind!");
			IncreaseNervousness(8);
			if (twpLastGrenadeHeard == nullptr)
			{
				NPCLog("Saw grenade");
				if (fpDistanceToNoiseLocation < 2000)
				{
					twpLastGrenadeHeard=ThrowWeaponPickup(NoiseMaker);
					fpTimeGrenadeHeard=GetWorld()->GetTimeSeconds();
					NPCLog("Saw grenade really close!");
					NotifyEnemyGrenadeClose(ThrowWeaponPickup(NoiseMaker));
				}
			}
		}
		if (NoiseMaker.IsA('Vehicle'))
		{
			if (aLastActorHeard != NoiseMaker)
			{
				NotifyHeardPlayerNoise(Loudness,Pawn(NoiseMaker));
			}
		}
		else
		{
			if (NoiseMaker.IsA('AGP_Pawn') && AGP_Pawn(NoiseMaker).IsHumanControlled())
			{
				if (aLastActorHeard != NoiseMaker)
				{
					NotifyHeardPlayerNoise(Loudness,Pawn(NoiseMaker));
				}
			}
			else
			{
				if (NoiseMaker.IsA('AGP_Weapon'))
				{
					if (AGP_Weapon(NoiseMaker).Instigator != None && ! AGP_Weapon(NoiseMaker).Instigator.Controller.IsA('NPCBaseController'))
					{
						NPCLog(Self $ Tag $ " Heard weapon noise " $ NoiseMaker);
						NotifyHeardWeaponNoise(Loudness,AGP_Weapon(NoiseMaker),vSoundLocation);
					}
				}
			}
		}
	}
	else
	{
		if (NoiseMaker.IsA('Throw_M83_Smoke') || NoiseMaker.IsA('Throw_M67_Frag') || NoiseMaker.IsA('Throw_M84_Stun'))
		{
			twpLastGrenadeHeard=ThrowWeaponPickup(NoiseMaker);
			fpTimeGrenadeHeard=GetWorld()->GetTimeSeconds();
			if (fpDistanceToNoiseLocation < 1500)
			{
				NPCLog("Heard grenade really close!");
				NotifyEnemyGrenadeClose(ThrowWeaponPickup(NoiseMaker));
			}
			NPCLog("Grenade heard!");
			IncreaseNervousness(10);
		}
		if (NoiseMaker.IsA('CROWS_HMMWV'))
		{
			NotifyHeardPlayerNoise(Loudness,Pawn(NoiseMaker));
		}
		else
		{
			if (NoiseMaker.IsA('AGP_Pawn') && AGP_Pawn(NoiseMaker).IsHumanControlled() || NoiseMaker.IsA('Weapon'))
			{
				if (Focus != NoiseMaker)
				{
					if (NoiseMaker.IsA('AGP_Weapon'))
					{
						if (AGP_Weapon(NoiseMaker).Instigator != None && ! AGP_Weapon(NoiseMaker).Instigator.Controller.IsA('NPCBaseController'))
						{
							NotifyHeardWeaponNoise(Loudness,AGP_Weapon(NoiseMaker),vSoundLocation);
						}
					}
					else
					{
						NotifyHeardPlayerNoise(Loudness,AGP_Pawn(NoiseMaker));
					}
				}
			}
		}
	}
	fpTimeLastHeard=GetWorld()->GetTimeSeconds();
	aLastActorHeard=NoiseMaker;
*/
}
void ANPCBaseController::Touch(AActor* Other)
{
	/*
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	NotifyNPCTouchedByPlayer(Pawn(Other));
*/
}
bool ANPCBaseController::UsedBy(APawn* User)
{
	/*
	local Actor actTrigger;
	if (bEnableUseToActivateTrigger && TriggerToActivate != 'None')
	{
		if (Pawn.Health >= iNPCHealthLevelToTrigger)
		{
			ForEach AllActors(Class'Actor',actTrigger,TriggerToActivate)
			{
				actTrigger.Trigger(Pawn,User);
			}
		}
	}
	if (bCaptureToActiveLinkedObjective)
	{
		AGP_Pawn(Pawn).ActivateLinkedObjective(User);
		NPCChangeState('Surrender');
		return true;
	}
	if (Level.NetMode == 0)
	{
		if (Len(sMovieToPlayOnUse) > 0)
		{
			StopMovement();
			bRotateToDesired=True;
			NPCLog("Trying to play movie " $ sMovieToPlayOnUse);
			AGP_HUD(HumanController(User.Controller).myHUD).sMovieTitle=sMovieTitleForPlayOnUse;
			AGP_HUD(HumanController(User.Controller).myHUD).sMOSMovieTitle=sMOSMovieTitleForPlayOnUse;
			AGP_HUD(HumanController(User.Controller).myHUD).sndMovieSoundToPlay=sndAudioToPlayOnUse;
			AGP_HUD(HumanController(User.Controller).myHUD).iMovieFrameRate=iMovieToPlayOnUseFramerate;
			AGP_HUD(HumanController(User.Controller).myHUD).fpVolumeMovieToPlayOnUse=fpVolumeMovieToPlayOnUse;
			AGP_HUD(HumanController(User.Controller).myHUD).sRHModalText=sRHModalText;
			AGP_HUD(HumanController(User.Controller).myHUD).sMovieCaption=sMovieCaption;
			AGP_HUD(HumanController(User.Controller).myHUD).sMOSMovieCaption=sMOSMovieCaption;
			AGP_HUD(HumanController(User.Controller).myHUD).sRHExternalLinkTitle=sRHExternalLinkTitle;
			AGP_HUD(HumanController(User.Controller).myHUD).sRHExternalLinkCaption=sRHExternalLinkCaption;
			HumanController(User.Controller).ClientOpenMenu("AGP_Interface.AAGameMenu_RHModal",,sMovieToPlayOnUse,sMOSMovieToPlayOnUse);
			return true;
		}
	}
*/
	return false;
}
void ANPCBaseController::NotifyNPCTouchedByPlayer(APawn* pawnTouch)
{
	/*
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
*/
}
void ANPCBaseController::NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
{
	/*
	if (bTrainingCadre)
	{
		Return;
	}
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	NPCLog("Enemy pawn is watching me!");
	if (EvaluateEnemyThreat(pawnSeen,True) >= 2)
	{
		actThreat=pawnSeen;
		IncreaseNervousness(2);
	}
*/
}

void ANPCBaseController::NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
{
	/*
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	NPCLog("Found item of interest: " $ npcioi.Tag);
	*/
}

void ANPCBaseController::NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation)
{
	/*
	if (bTrainingCadre)
	{
		Return;
	}
	NPCLog("Turning towards weapon that was heard: " $ agpwWeaponHeard);
	Crouch();
	Focus=agpwWeaponHeard;
	FocalPoint=Pawn.Location + 512 *  Vector(Normalize(agpwWeaponHeard.Location - Pawn.Location));
	IncreaseNervousness(1);
	NPCChangeState('HeardPlayer');
*/
}
void ANPCBaseController::NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
{
	/*
	if (bTrainingCadre)
	{
		Return;
	}
	Focus=pawnHeard;
	FocalPoint=Pawn.Location + 512 *  Vector(Normalize(pawnHeard.Location - Pawn.Location));
	IncreaseNervousness(1);
	NPCChangeState('HeardPlayer');
*/
}
void ANPCBaseController::NotifyPlayerPawnInSight(APawn* pawnSeen)
{
	/*
	if (bTrainingCadre)
	{
		Return;
	}
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	NPCLog("NotifyPlayerPawnInSIght - pawn in sight: " $ pawnSeen);
	pawnHCLastSeen=pawnSeen;
	fpPawnHCLastSeen=GetWorld()->GetTimeSeconds();
	AddHistoryContact(pawnSeen);
*/
}
bool ANPCBaseController::IsInMortalDanger()
{
	return false;
}
void ANPCBaseController::NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade)
{
	/*
	if (bTrainingCadre)
	{
		Return;
	}
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	if (VSize(twpGrenade.Location - Pawn.Location) < 1500)
	{
		NPCLog("Grenade landed pretty close: " $ twpGrenade);
		actThreat=twpGrenade;
		twpLastGrenadeHeard=twpGrenade;
		fpTimeGrenadeHeard=GetWorld()->GetTimeSeconds();
		NotifyEnemyGrenadeClose(twpGrenade);
	}
*/
}

float ANPCBaseController::IncreaseNervousness(EMentalStateAdjustor msa)
{
	float fpConfidenceDelta = 0;
	/*
	if (bTrainingCadre)
	{
		return fpConfidenceDelta;
	}
	fpConfidenceDelta=0;
	switch(msa)
	{
		case 1:
		if (GetConfidenceLevel() >= 0)
		{
			return 0;
		}
		fpConfidenceDelta=1;
		break;
		case 0:
		if (GetConfidenceLevel() < -40)
		{
			return 0;
		}
		fpConfidenceDelta=1;
		break;
		case 2:
		if (GetConfidenceLevel() < -10)
		{
			return 0;
		}
		fpConfidenceDelta=2;
		break;
		case 3:
		if (GetConfidenceLevel() < -10)
		{
			return 0;
		}
		fpConfidenceDelta=3;
		break;
		case 4:
		if (GetConfidenceLevel() < -10)
		{
			return 0;
		}
		fpConfidenceDelta=5;
		break;
		case 7:
		if (GetConfidenceLevel() < -60)
		{
			return 0;
		}
		fpConfidenceDelta=30;
		break;
		case 8:
		if (GetConfidenceLevel() < -60)
		{
			return 0;
		}
		fpConfidenceDelta=2;
		break;
		case 9:
		if (GetConfidenceLevel() < -60)
		{
			return 0;
		}
		fpConfidenceDelta=5;
		break;
		case 10:
		if (GetConfidenceLevel() < -10)
		{
			return 0;
		}
		fpConfidenceDelta=1;
		break;
		case 11:
		if (GetConfidenceLevel() < -60)
		{
			return 0;
		}
		if (fpConfidence < 70)
		{
			fpConfidenceDelta=5;
		}
		else
		{
			fpConfidenceDelta=1;
		}
		GOTO JL01EA;
		default:
JL01EA:
	}
	SetConfidenceLevel(GetConfidenceLevel() - fpConfidenceDelta * fpNodeMentalStateChangeModifier);
	fpTimeLastNervousnessChange=GetWorld()->GetTimeSeconds();
*/
	return fpConfidenceDelta;
}
void ANPCBaseController::AdjustStateByConfidenceLevel()
{
	/*
	if (GetConfidenceLevel() <= -90)
	{
		if (! IsInState('Cowering') && ! IsInState('LiveGrenade'))
		{
			NPCChangeState('Cowering');
		}
	}
	else
	{
		if (GetConfidenceLevel() <= -60)
		{
			if (! IsInState('Panic') && ! IsInState('Cowering'))
			{
				NPCChangeState('Panic');
			}
		}
		else
		{
			if (GetConfidenceLevel() <= -40)
			{
				if (! IsInState('FindCover') && ! IsInState('LiveGrenade') && ! IsInState('ReturnToPatrol') && ! IsInState('Cowering'))
				{
					NPCLog("Current state before find cover is: " $ GetStateName());
					NPCChangeState('FindCover');
				}
			}
		}
	}
*/
}
void ANPCBaseController::AdjustConfidenceByTime()
{
	/*
	local float fpUpdateDeltaTime;
	fpUpdateDeltaTime=1;
	if (GetWorld()->GetTimeSeconds() > fpTimeLastNervousnessChange + fpUpdateDeltaTime)
	{
		IncreaseConfidence(13);
	}
*/
}
void ANPCBaseController::IncreaseConfidence(EMentalStateAdjustor msa)
{
	/*
	local int fpConfidenceDelta;
	fpConfidenceDelta=0;
	switch(msa)
	{
		case 13:
		if (GetConfidenceLevel() >= iNPCInitialMentalState)
		{
			Return;
		}
		fpConfidenceDelta=1;
		break;
		case 14:
		if (GetConfidenceLevel() >= iNPCInitialMentalState)
		{
			Return;
		}
		fpConfidenceDelta=3;
		break;
		case 12:
		fpConfidenceDelta=10;
		break;
		case 5:
		if (GetConfidenceLevel() >= iNPCInitialMentalState)
		{
			Return;
		}
		if (fpConfidence < 0)
		{
			fpConfidenceDelta=2;
		}
		else
		{
			fpConfidenceDelta=0;
		}
		GOTO JL00CB;
		case 6:
		if (fpConfidence < 0)
		{
			fpConfidenceDelta += 5;
		}
		else
		{
			fpConfidenceDelta=0;
		}
		GOTO JL00CB;
		default:
JL00CB:
	}
	SetConfidenceLevel(GetConfidenceLevel() + fpConfidenceDelta * fpNodeMentalStateRecoveryModifier);
	fpTimeLastNervousnessChange=GetWorld()->GetTimeSeconds();
*/
}

bool ANPCBaseController::CanPawnSeeMe(APawn* pawnSeen, bool bTestForAimingAtMe)
{
	/*
	local FRotator rotEnemyToSelf;
	local int iUUAngleToSelf;
	if (Pawn != None && Pawn.Health <= 0)
	{
		return false;
	}
	if (pawnSeen.LineOfSightTo(Pawn))
	{
		rotEnemyToSelf=Pawn.Location - pawnSeen.Location;
		iUUAngleToSelf=pawnSeen.Rotation.Yaw - rotEnemyToSelf.Yaw;
		if (iUUAngleToSelf < 0)
		{
			iUUAngleToSelf=iUUAngleToSelf * -1;
		}
		if (iUUAngleToSelf < 16384)
		{
			if (bTestForAimingAtMe)
			{
				if (iUUAngleToSelf <= 3268)
				{
					return true;
				}
				return false;
			}
			return true;
		}
	}
	*/
	return false;
}
void ANPCBaseController::NotifyNPCSeen(APawn* Seen)
{
}
void ANPCBaseController::SeeMonster(APawn* Seen)
{
	/*
	if (Pawn != None && Pawn.Health <= 0 || Seen == nullptr)
	{
		Return;
	}
	if (Pawn == Enemy || Pawn == Focus)
	{
		Return;
	}
	NotifyNPCSeen(Seen);
*/
}

float ANPCBaseController::GetMaxVisionCone()
{
	if (fpNodeVisionConeAngle > 0)
	{
		return fpNodeVisionConeAngle;
	}
	return 19660;
}

FRotator ANPCBaseController::GetPawnViewRotation()
{
	//return Pawn.Rotation;
	return GetPawn()->GetActorRotation();
}

float ANPCBaseController::EvaluateEnemyThreat(APawn* pawnToEvaluate, bool bWatchingMe, float fpClosureRate)
{
	float fpThreatLevel=0;
	/*
	if (pawnToEvaluate == nullptr)
	{
		return 0;
	}
	if (AGP_Pawn(pawnToEvaluate) == nullptr)
	{
		if (pawnToEvaluate.IsA('SHelicopter'))
		{
			return 5;
		}
		return 0;
	}
	fpThreatLevel=AGP_Pawn(pawnToEvaluate).GetThreatLevel();
	if (pawnToEvaluate.IsA('Vehicle'))
	{
		if (fpClosureRate > 0)
		{
			fpThreatLevel += 1;
		}
		else
		{
			fpThreatLevel -= 1;
		}
	}
	if (bWatchingMe)
	{
		if (CanPawnSeeMe(pawnToEvaluate,True))
		{
			fpThreatLevel *= 1.25;
		}
	}
	*/
	return fpThreatLevel;
}
void ANPCBaseController::PreloadPathNodeList()
{
	FastPreloadPathNodeList();
}

APathNode* ANPCBaseController::GetPathnodeByTag(FName Tag)
{
	ANavigationPoint* N = nullptr;
	/*
	if (Tag != "None")
	{
		for (N = Level.NavigationPointList; N != nullptr; N = N.nextNavigationPoint)
		{
			if (N.IsA("PathNode") && (Tag == N.Tag))
			{
				return PathNode(N);
			}
		}
	}
	*/
	return nullptr;
}

APathNode* ANPCBaseController::GetPathnodeByTagString(FString sTag)
{
	ANavigationPoint* N = nullptr;
	/*
	if (Len(sTag) > 0)
	{
		for (N = Level.NavigationPointList; N != nullptr; N = N.nextNavigationPoint)
		{
			if (N.IsA("PathNode") && (sTag == string(N.Tag)))
			{
				return PathNode(N);
			}
		}
	}
	*/
	return nullptr;
}

ALadder* ANPCBaseController::GetLadderPathnodeByName(FName nameOfNode)
{
	ANavigationPoint* N = nullptr;
	if (nameOfNode != "None")
	{
		/*
		for (N = Level.NavigationPointList; N != nullptr; N = N.nextNavigationPoint)
		{
			if (!N.IsA("Ladder"))
			{
			}
			if (string(nameOfNode) ~= string(N.Name))
			{
				return Ladder(N);
			}
		}
		*/
	}
	return nullptr;
}

ALadderVolume* ANPCBaseController::GetNearbyLadderVolume(APathNode* pnToSearchNear)
{
	/*
	local LadderVolume lvIterator;
	if (NPCLadderPathNode(pnToSearchNear).nameLadderVolumeToUse != 'None')
	{
		NPCPathLog("Looking through all ladder volumes for one with name: " $ NPCLadderPathNode(pnToSearchNear).nameLadderVolumeToUse);
		ForEach AllActors(Class'LadderVolume',lvIterator)
		{
			if (lvIterator.Name ~= NPCLadderPathNode(pnToSearchNear).nameLadderVolumeToUse)
			{
				NPCPathLog("Found ladder: """ $ lvIterator.Name $ """");
				return lvIterator;
			}
		}
	}
	NPCPathLog("Looking for close-by ladder near: " $ pnToSearchNear.Tag);
	ForEach RadiusActors(Class'LadderVolume',lvIterator,250,pnToSearchNear.Location)
	{
		NPCPathLog("Found ladder volume" $ lvIterator.Tag);
		return lvIterator;
	}
	*/
	return nullptr;
}
bool ANPCBaseController::IsLocationDirectlyInFront(FVector vLocation)
{
	/*
	if (GetAngleToLocation(vLocation) > 0)
	{
		return true;
	}
	*/
	return false;
}
void ANPCBaseController::DetermineNextPathNode()
{
	/*
	if (apnPathNodesForPatrol.Length == 0)
	{
		Return;
	}
	if (bUseAlternatePath)
	{
		if (apnPathNodesForPatrol[iCurrentPathNodeIndex] != None && apnPathNodesForPatrol[iCurrentPathNodeIndex].bPathBranchAsc && bAscendingNodeDirection)
		{
			if (apnPathNodesForPatrol[iCurrentPathNodeIndex].iBranchIndex - 1 > iCurrentPathNodeIndex && bAutoReversePath)
			{
				bAscendingNodeDirection=False;
			}
			iCurrentPathNodeIndex=apnPathNodesForPatrol[iCurrentPathNodeIndex].iBranchIndex - 1;
		}
		else
		{
			if (apnPathNodesForPatrol[iCurrentPathNodeIndex] != None && apnPathNodesForPatrol[iCurrentPathNodeIndex].bPathBranchDesc && ! bAscendingNodeDirection)
			{
				iCurrentPathNodeIndex=apnPathNodesForPatrol[iCurrentPathNodeIndex].iBranchIndex;
			}
		}
	}
	if (bAscendingNodeDirection)
	{
		if (iCurrentPathNodeIndex < apnPathNodesForPatrol.Length - 1)
		{
			iCurrentPathNodeIndex ++;
		}
		else
		{
			if (bAutoReversePath)
			{
				if (apnPathNodesForPatrol[iCurrentPathNodeIndex] != None && apnPathNodesForPatrol[iCurrentPathNodeIndex].bPathBranchAsc && bUseAlternatePath)
				{
					NPCPathLog("Overriding pathnode index based on branch to " $ apnPathNodesForPatrol[iCurrentPathNodeIndex].iBranchIndex);
					iCurrentPathNodeIndex=apnPathNodesForPatrol[iCurrentPathNodeIndex].iBranchIndex;
				}
				if (apnPathNodesForPatrol.Length > 0)
				{
					NPCPathLog("Reversing direction back to descending");
					bAscendingNodeDirection=False;
					DetermineNextPathNode();
					Return;
				}
			}
			else
			{
				iCurrentPathNodeIndex=0;
			}
		}
		NPCPathLog("");
		NPCPathLog("");
		NPCPathLog("Ascending pathnodes - new index: " $ iCurrentPathNodeIndex $ " node: " $ apnPathNodesForPatrol[iCurrentPathNodeIndex].Tag);
	}
	else
	{
		if (iCurrentPathNodeIndex > 0)
		{
			iCurrentPathNodeIndex --;
		}
		else
		{
			NPCPathLog("Descending path hit when on first node, see about reverse or wrap");
			if (bAutoReversePath)
			{
				if (apnPathNodesForPatrol.Length > 0)
				{
					NPCPathLog("Reversing direction back to ascending");
					bAscendingNodeDirection=True;
					DetermineNextPathNode();
					Return;
				}
			}
			else
			{
				iCurrentPathNodeIndex=apnPathNodesForPatrol.Length - 1;
			}
		}
		NPCPathLog("Descending pathnodes - new index: " $ iCurrentPathNodeIndex);
	}
	FindNextPatrolPathNode();
*/
}

ANPCPathNode* ANPCBaseController::FindNextPatrolPathNode()
{
	/*
	NPCPathLog("Searching for next navpoint to move to: " $ iCurrentPathNodeIndex + 1);
	if (iCurrentPathNodeIndex < apnPathNodesForPatrol.Length)
	{
		NPCPathLog("Found pathnode: " $ apnPathNodesForPatrol[iCurrentPathNodeIndex]);
		pnCurrentPathNode=apnPathNodesForPatrol[iCurrentPathNodeIndex];
		return pnCurrentPathNode;
	}
	NPCPathLog("FindNextPatrolPathNode() - Couldn't find pathnode");
	*/
	return nullptr;
}

APathNode* ANPCBaseController::DetermineNodeAfterCurrentNode()
{
	int32 iSavedCurrentPathNodeIndex = 0;
	APathNode* pnNextNodeFound = nullptr;
	iSavedCurrentPathNodeIndex=iCurrentPathNodeIndex;
	DetermineNextPathNode();
	//pnNextNodeFound=FindNextPatrolPathNode();
	iCurrentPathNodeIndex=iSavedCurrentPathNodeIndex;
	if (pnNextNodeFound != nullptr)
	{
		return pnNextNodeFound;
	}
	else
	{
		return nullptr;
	}
}

void ANPCBaseController::CloseDoor(AMover* mDoor)
{
	if (! mDoor->bClosed)
	{
		mDoor->ReallyDoClose();
	}
}

bool ANPCBaseController::OpenDoor(ANPCDoorEntryPathNode* npcdepn)
{
	AMover* mIterator = nullptr;
	bool bFirstDoorOpened = false;
	/*
	mLastDoorOpened=None;
	ForEach RadiusActors(Class'Mover',mIterator,100,npcdepn.Location)
	{
		if (mIterator.Name != npcdepn.nameDoorToOpen)
		{
		}
		else
		{
			if (mIterator.bNotADoor)
			{
			}
			else
			{
				if (mLastDoorOpened == nullptr)
				{
					mLastDoorOpened=mIterator;
				}
				mIterator.Instigator=Pawn;
				mIterator.ReallyOpen();
				bFirstDoorOpened=True;
			}
		}
	}
	if (bFirstDoorOpened)
	{
		return true;
	}
	if (mLastDoorOpened == nullptr)
	{
		NPCPathLog("*** WARNING *** - Door not found!");
		return true;
	}
	NPCPathLog("Door locked and can't be opened by this NPC");
	*/
	return false;
}

bool ANPCBaseController::OpenDoorFromHere(FVector vLocation, AMover* moverBumpedDoor)
{
	/*
	local Mover mIterator;
	local bool bFirstDoorOpened;
	if (moverBumpedDoor != None)
	{
		if (moverBumpedDoor.bNotADoor)
		{
			return false;
		}
		mLastDoorOpened=moverBumpedDoor;
		moverBumpedDoor.Instigator=Pawn;
		moverBumpedDoor.ReallyOpen();
		bFirstDoorOpened=True;
		return true;
	}
	else
	{
		mLastDoorOpened=None;
		ForEach RadiusActors(Class'Mover',mIterator,100,vLocation)
		{
			Log("OpenDoorFromHere() Found mover " $ mIterator.Name);
			if (mIterator.bNotADoor)
			{
			}
			else
			{
				Log("Found door " $ mIterator.Name $ ", trying to use it to open it by using it's recommended trigger: " $ mIterator);
				mLastDoorOpened=mIterator;
				mIterator.Instigator=Pawn;
				mIterator.ReallyOpen();
				bFirstDoorOpened=True;
			}
		}
	}
	if (bFirstDoorOpened)
	{
		return true;
	}
	if (mLastDoorOpened == nullptr)
	{
		Log("*** WARNING *** - Door not found!");
		return true;
	}
	Log("Door locked and can't be opened by this NPC");
	*/
	return false;
}

AMover* ANPCBaseController::FindDoor(ANPCDoorEntryPathNode* npcdepn)
{
	AMover* mIterator = nullptr;
	/*
	if (mLastDoorOpened != None && npcdepn.nameDoorToOpen == mLastDoorOpened.Name)
	{
		return mLastDoorOpened;
	}
	mLastDoorOpened=nullptr;
	ForEach RadiusActors(Class'Mover',mIterator,250,npcdepn.Location)
	{
		if (mIterator.Name != npcdepn.nameDoorToOpen)
		{
		}
		else
		{
			mLastDoorOpened=mIterator;
		}
	}
	*/
	return mLastDoorOpened;
}

bool ANPCBaseController::ShouldMoveToNextPathNode()
{
	return true;
}
void ANPCBaseController::DebugDumpRoute()
{
	/*
	local int i;
	if (! bDebugPath)
	{
		Return;
	}
	if (Pawn != None)
	{
		NPCPathLog("Route goal: " $ RouteGoal $ ", distance: " $ RouteDist);
		for (i=0; i<62; i++)
		{
			if (RouteCache[i] != None)
			{
				NPCPathLog("Route[ " $ i $ "] => " $ RouteCache[i] $ ": " $ RouteCache[i].Tag);
			}
		}
	}
*/
}
void ANPCBaseController::DebugMarkNextNode(APathNode* pnNext)
{
	/*
	if (bDebugPath)
	{
		if (pnLastDebuggedNavPoint != None)
		{
			pnLastDebuggedNavPoint.DebugNavMarker(False);
			pnLastDebuggedNavPoint=None;
		}
		if (pnNext.IsA('NPCPathNode'))
		{
			NPCPathNode(pnNext).DebugNavMarker(True);
			pnLastDebuggedNavPoint=NPCPathNode(pnNext);
		}
	}
*/
}

void ANPCBaseController::UpdatePathNodeBonuses(ANPCPathNode* npcpn)
{
	/*
	pnCurrentLocation=npcpn;
	if (npcpn != None && npcpn.IsA('NPCFirePositionPathNode') && ! NPCFirePositionPathNode(npcpn).bIsCover)
	{
		npcpn=None;
	}
	if (npcpn != None)
	{
		fpNodeMentalStateBonus=npcpn.fpMentalStateBonus;
		fpNodeWeaponAccuracyBonus=npcpn.fpWeaponAccuracyBonus;
		fpNodeMentalStateChangeModifier=npcpn.fpMentalStateChangeModifier;
		fpNodeVisionRangeModifier=npcpn.fpVisionRangeModifier;
		fpNodeVisionConeAngle=npcpn.fpVisionConeAngle;
		fpNodeHearingRangeModifier=npcpn.fpHearingRangeModifier;
		fpNodeMentalStateRecoveryModifier=npcpn.fpMentalStateRecoveryModifier;
	}
	else
	{
		fpNodeMentalStateBonus=0;
		fpNodeWeaponAccuracyBonus=0;
		fpNodeMentalStateChangeModifier=1;
		fpNodeVisionRangeModifier=1;
		fpNodeVisionConeAngle=fpNPCVisionConeAngle;
		fpNodeHearingRangeModifier=1;
		fpNodeMentalStateRecoveryModifier=1;
	}
	*/
}

void ANPCBaseController::PatrolStartTriggerEvent()
{
	/*
	Log("PatrolStartTriggerEvent() entered");
	if (bUsePatrolStartTrigger)
	{
		GotoState('ReturnToPatrol');
	}
*/
}
void ANPCBaseController::PatrolResumeTriggerEvent()
{
	/*
	Log("PatrolResumeTriggerEvent() entered");
	if (bUseResumePatrolStartTrigger)
	{
		GotoState('ReturnToPatrol');
	}
*/
}
void ANPCBaseController::FallBackTriggerEvent()
{
}
void ANPCBaseController::DefendAreaTriggerEvent(FVector vLocToMoveTo)
{
}
void ANPCBaseController::EndClimbLadder()
{
	/*
	EndClimbLadder();
	Log("Leaving ladder");
	bOnLadder=False;
*/
}

void ANPCBaseController::StartClimbingLadder(ALadderVolume* lvLadder)
{
	//Log("Entering ladder");
	bOnLadder=true;
}

void ANPCBaseController::NotifyConversationPackStart(ANPCConversationPack* npccpNew)
{
	/*
	NPCLog(Self $ "Pawn conversation start signalled for pack: " $ npccpNew $ " while in state " $ GetStateName());
	npccpCurrentConversation=npccpNew;
	namePreConversationPackState=GetStateName();
	NPCChangeState("PawnHavingConversation");
	*/
}

void ANPCBaseController::NotifyConversationPackEnded(ANPCConversationPack* npccpJustEnded)
{
	npccpCurrentConversation=nullptr;
	/*
	if (GetStateName() ~= "PawnHavingConversation")
	{
		NPCChangeState(namePreConversationPackState);
	}
	*/
}

int32 ANPCBaseController::GetLookRotationRate()
{
	return 8192;
}

void ANPCBaseController::LookRight(float fpYaw)
{
	/*
	if (! Pawn.bNetRelevant)
	{
		Return;
	}
	NPCLog("Looking Right");
	Focus=None;
	Pawn.RotationRate.Yaw=GetLookRotationRate();
	DesiredRotation=Pawn.Rotation;
	if (fpYaw > 0)
	{
		DesiredRotation.Yaw += fpYaw;
	}
	else
	{
		DesiredRotation.Yaw += 16384;
	}
	if (DesiredRotation.Yaw > 65535)
	{
		DesiredRotation.Yaw -= 65535;
	}
	FocalPoint=Pawn.Location + 2048 *  Vector(DesiredRotation);
	bRotateToDesired=True;
*/
}
void ANPCBaseController::LookLeft(float fpYaw)
{
	/*
	if (! Pawn.bNetRelevant)
	{
		Return;
	}
	NPCLog("Looking Left");
	Focus=None;
	Pawn.RotationRate.Yaw=GetLookRotationRate();
	DesiredRotation=Pawn.Rotation;
	if (fpYaw > 0)
	{
		DesiredRotation.Yaw -= fpYaw;
	}
	else
	{
		DesiredRotation.Yaw -= 16384;
	}
	if (DesiredRotation.Yaw < 0)
	{
		DesiredRotation.Yaw += 65535;
	}
	FocalPoint=Pawn.Location + 512 *  Vector(DesiredRotation);
	bRotateToDesired=True;
*/
}
void ANPCBaseController::NPCSay(int32 theSound, bool shout, bool forceplay)
{
	/*
	local Actor SoundActor;
	local Sound SoundPtr;
	local int R;
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Pawn.Health <= 0)
	{
		Return;
	}
	if (fNPCLastTalkTime < GetWorld()->GetTimeSeconds() || forceplay == True)
	{
		fNPCLastTalkTime=GetWorld()->GetTimeSeconds() + 5 * FMath::FRand() + 5;
		if (! AGP_Pawn(Pawn).bIsBoss)
		{
			if (theSound == 999)
			{
				R=Rand(27);
			}
			else
			{
				R=theSound;
			}
			if (shout == True)
			{
				if (bNPCSpeaksEnglish)
				{
					SoundPtr=sShoutFriendly[R];
				}
				else
				{
					SoundPtr=sShoutEnemy[R];
				}
			}
			else
			{
				R=Rand(27);
				if (bNPCSpeaksEnglish)
				{
					SoundPtr=sWhisperFriendly[R];
				}
				else
				{
					SoundPtr=sWhisperEnemy[R];
				}
			}
		}
		else
		{
			R=theSound;
			SoundPtr=sEnemyLeader[R];
		}
		if (SoundPtr != None)
		{
			SoundActor=Spawn(Class'EffectLocation',,,Pawn.Location);
			SoundActor.LifeSpan=GetSoundDuration(SoundPtr);
			SoundActor.PlaySound(SoundPtr,0,1,,,,False);
		}
	}
*/
}

ANPCCoverPositionPathNode* ANPCBaseController::FindCoverPathNode(bool bFindFarthestPointFromThreat)
{
	//Return FastFindCoverPathNode(bFindFarthestPointFromThreat);
	return nullptr;  //FAKE   /ELiZ
}

ANPCPathNode* ANPCBaseController::FindEscapePathNode(float fpMinDistance)
{
	ANPCPathNode* pnIterator = nullptr;
	ANPCPathNode* pnBestCover = nullptr;
	AActor* traceHit = nullptr;
	FVector HitLocation = FVector(0,0,0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	float fpThreatFacing = 0;
	float fpNodeFacing = 0;
	ANavigationPoint* N = nullptr;
	/*
	if ((Pawn == nullptr) || (Pawn.Health <= 0))
	{
		return nullptr;
	}
	if (actThreat == nullptr)
	{
		if (GetConfidenceLevel() <= float(-60))
		{
			N=Level.NavigationPointList;
			if (N != nullptr)
			{
				if (! N.IsA("NPCPathNode"))
				{
				}
				pnIterator=NPCPathNode(N);
				if ((pnIterator.cControllerUsingNode != nullptr) && (pnIterator.cControllerUsingNode != Self))
				{
				}
				if ((fpMinDistance > 0) && (VSize((pnIterator.Location - Pawn.Location)) < fpMinDistance))
				{
				}
				if (pnBestCover == nullptr)
				{
					pnBestCover=pnIterator;
				}
				else
				{
					if (VSize((pnBestCover.Location - Pawn.Location)) < VSize((pnIterator.Location - Pawn.Location)))
					{
						pnBestCover=pnIterator;
						if (fpMinDistance > 0)
						{
						}
					}
				}
				else
				{
					N=N.nextNavigationPoint;
				}
			}
			return pnBestCover;
		}
	}
	if (actThreat != nullptr)
	{
		fpThreatFacing=(Normal( Vector(Pawn.Rotation)) Dot (actThreat.Location - Pawn.Location));
	}
	for (N=Level.NavigationPointList; N!=nullptr; N=N.nextNavigationPoint)
	{
		if (! N.IsA("NPCPathNode"))
		{
		}
		pnIterator=NPCPathNode(N);
		if ((pnIterator.cControllerUsingNode != nullptr) && (pnIterator.cControllerUsingNode != Self))
		{
		}
		if (actThreat != nullptr)
		{
			if (VSize((pnIterator.Location - actThreat.Location)) < float(1500))
			{
				fpNodeFacing=(Normal( Vector(Pawn.Rotation)) Dot (pnIterator.Location - Pawn.Location));
				if ((((fpNodeFacing > 0) && (fpThreatFacing > 0)) || ((fpNodeFacing < 0) && (fpThreatFacing < 0))) || ((fpNodeFacing == 0) && (fpThreatFacing == 0)))
				{
					NPCLog("Skipping node due to facing is same direction as threat (node: " $ string(fpNodeFacing) $ ", threat: " $ string(fpThreatFacing) $ ")");
				}
				else
				{
					StartTrace=pnIterator.Location;
					StartTrace.Z += float(512);
					EndTrace=actThreat.Location;
					traceHit=pnIterator.Trace(HitLocation,HitNormal,EndTrace,StartTrace,true);
					if (traceHit == actThreat)
					{
						NPCPathLog("Ack - we can directly see the threat from this coverpoint ");
					}
				}
			}
			else
			{
				if (pnCoverNode == pnIterator)
				{
				}
				if (pnBestCover == nullptr)
				{
					pnBestCover=pnIterator;
				}
				else
				{
					if (VSize((pnBestCover.Location - Pawn.Location)) > VSize((pnIterator.Location - Pawn.Location)))
					{
						pnBestCover=pnIterator;
					}
				}
			}
		}
	}
	*/
	return pnBestCover;
}

void ANPCBaseController::ReceiveWarning(APawn* shooter, float projSpeed, FVector FireDir)
{
	float fpChance = 0;
	/*
	if (Pawn == nullptr)
	{
		Return;
	}
	if (Pawn.Health <= 0)
	{
		Return;
	}
	NPCLog("NPC getting warning from: " $ shooter);
	if (IsInState('LiveGrenade'))
	{
		Return;
	}
	if (pnCurrentPathNode != None && pnCurrentPathNode.IsA('NPCCoverPositionPathNode') && NPCCoverPositionPathNode(pnCurrentPathNode).bSafeFromVehiclesImpact)
	{
		Return;
	}
	fpChance=FMath::FRand();
	if (iNPCCurrentOrders == 9)
	{
		fpChance=0;
	}
	NPCSay(1,True,True);
	if (fpChance < 0.66)
	{
		actThreat=shooter;
		GotoState('LiveGrenade');
	}
	else
	{
		Prone();
	}
*/
}

ANPCItemOfInterest* ANPCBaseController::GetNearbyItemOfInterest()
{
	/*
	local NPCItemOfInterest npcioi;
	ForEach RadiusActors('NPCItemOfInterest',npcioi,fpItemOfInterestSearchRange,Pawn.Location)
	{
		if (VSize(npcioi.Location - Pawn.Location) <= npcioi.fpMaxDistanceToNotice)
		{
			return npcioi;
		}
	}
	*/
	return nullptr;
}

bool ANPCBaseController::SelectIdleRelatedAnimation(bool bForcePlaying)
{
	/*
	iCurrentIdleAnimIndex=-1;
	if (Pawn == nullptr || Pawn != None && Pawn.Health <= 0)
	{
		return false;
	}
	if (anpcassNPCIdleAnimations.Length > 0)
	{
		if (FMath::FRand() > 0.5 || bForcePlaying)
		{
			iCurrentIdleAnimIndex=Rand(anpcassNPCIdleAnimations.Length);
			return true;
		}
	}
	*/
	return false;
}

float ANPCBaseController::PlayIdleRelatedAnimation(bool bForcePlaying, bool bLoopAnimation)
{
	/*
	iCurrentIdleAnimIndex=-1;
	if (Pawn == nullptr || Pawn != None && Pawn.Health <= 0)
	{
		return 0;
	}
	NPCLog("PlayIdleRelatedAnimation() - Weapon is: " $ AGP_Pawn(Pawn).Weapon $ " animation length: " $ anpcassNPCIdleAnimations.Length);
	if (AGP_Pawn(Pawn).Weapon == nullptr && anpcassNPCIdleAnimations.Length > 0)
	{
		if (FMath::FRand() > 0.5 || bForcePlaying)
		{
			iCurrentIdleAnimIndex=Rand(anpcassNPCIdleAnimations.Length);
			return PlayCustomAnimation(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animStart,bLoopAnimation);
		}
	}
	*/
	return 0;
}

float ANPCBaseController::PlayCustomAnimation(FName nameAnimation, bool bLoop, float fpRate)
{
	/*
	if (Pawn == nullptr || Pawn != None && Pawn.Health <= 0)
	{
		return 0;
	}
	if (nameAnimation == 'None' || nameAnimation == 'None')
	{
		return 0.5;
	}
	if (fpRate == 0)
	{
		fpRate=1;
	}
	NPCLog(" Mesh: " $ Pawn.Mesh $ " trying to play animation """ $ nameAnimation $ """ of duration " $ Pawn.GetAnimDuration(nameAnimation) $ " seconds, looping: " $ bLoop $ ".");
	if (Pawn.HasAnim(nameAnimation))
	{
		if (Level.NetMode == 0)
		{
			NPCLog(" Pawn has animation """ $ nameAnimation $ """ of " $ Pawn.GetAnimDuration(nameAnimation) $ " seconds.");
			if (bLoop)
			{
				NPCLog("Pawn wants to loop animation " $ nameAnimation);
				Pawn.SetLoopingAnimAction(nameAnimation);
				Pawn.AnimLoopAction=nameAnimation;
			}
			else
			{
				if (IsInState('PawnStartsAsDummy'))
				{
					Pawn.EnableChannelNotify(AnimChannel,1);
					if (AnimChannel > 0)
					{
						Pawn.AnimBlendParams(AnimChannel,1,Pawn.BlendChangeTime,Pawn.BlendChangeTime);
					}
					Pawn.PlayAnim(nameAnimation,fpRate,AnimTime,AnimChannel);
					NPCLog("Playing animation " $ nameAnimation $ " on channel " $ AnimChannel);
				}
				else
				{
					Pawn.EnableChannelNotify(13,1);
					Pawn.AnimBlendParams(13,1,Pawn.BlendChangeTime,Pawn.BlendChangeTime);
					Pawn.PlayAnim(nameAnimation,fpRate,0.05,13);
				}
			}
		}
		else
		{
			if (bLoop)
			{
				Pawn.SetLoopingAnimAction(nameAnimation);
			}
			else
			{
				Pawn.SetLoopingAnimAction('None');
				Pawn.SetAnimAction(nameAnimation);
			}
		}
	}
	else
	{
		NPCLog("*** WARNING *** INVALID Animation " $ nameAnimation $ " for pawn " $ Pawn $ " Mesh: " $ Pawn.Mesh $ " Tag: " $ Pawn.Tag);
		return 0;
	}
	return Pawn.GetAnimDuration(nameAnimation);
	*/
	return 0;    //FAKE   /ELiZ
}

float ANPCBaseController::PlayCustomSound(USoundBase* sndToPlay)
{
	/*
	local Actor SoundActor;
	if (Pawn == nullptr || Pawn != None && Pawn.Health <= 0)
	{
		return 0;
	}
	SoundActor=Spawn(Class'EffectLocation',,,Pawn.Location);
	SoundActor.LifeSpan=GetSoundDuration(sndToPlay);
	SoundActor.PlaySound(sndToPlay,0,1,,,,False);
	NPCLog("PlayCustomSound length: " $ sndToPlay.Duration);
	return sndToPlay.Duration;
	*/
	return 0;   //FAKE  /ELiZ
}
bool ANPCBaseController::NotifyHitWall(FVector HitNormal, AActor* Wall)
{
	/*
	if (Pawn.Health <= 0)
	{
		return true;
	}
	NPCPathLog(Self $ "." $ Pawn $ " Pawn hit wall! " $ Wall $ " normal: " $ HitNormal);
	PickWallAdjust(HitNormal);
*/
	return true;
}
void ANPCBaseController::BackupAfterBump(APawn* pawnBumpedInto)
{
	/*
	if (pawnBumped != None)
	{
		Return;
	}
	pawnBumped=pawnBumpedInto;
	NPCChangeState('MoveBackAfterBump');
*/
}
bool ANPCBaseController::NotifyBump(AActor* Other)
{
	/*
	if (Other == nullptr)
	{
		return true;
	}
	if (Other != None && ! Other.IsA('Pawn'))
	{
		return true;
	}
	AdjustAround(Pawn(Other));
	*/
	return true;
	
}
void ANPCBaseController::Startle(AActor* Feared)
{
	//NPCLog("Pawn startled by " $ Feared);
}
void ANPCBaseController::InitPlayerReplicationInfo()
{
	/*
	if (PlayerReplicationInfo != None)
	{
		NPCLog("NPCBaseController.InitPlayerReplicationInfo() entered");
		InitPlayerReplicationInfo();
		if (PlayerReplicationInfo != None)
		{
			NPCLog("NPCBaseController.InitPlayerReplicationInfo() created PRI for us!");
		}
	}
*/
}

bool ANPCBaseController::NotifyPhysicsVolumeChange(APhysicsVolume* NewVolume)
{
	/*
	NPCLog("New volume for pawn: " $ NewVolume);
	if (NewVolume.IsA('LadderVolume'))
	{
		bOnLadder=True;
	}
	else
	{
		bOnLadder=False;
	}
	NPCLog("Pawn OnLadder: " $ bOnLadder);
	*/
	return true;
}

bool ANPCBaseController::AdjustAround(APawn* Other, bool bNoAdjustOther)
{
	float Speed = false;
	FVector VelDir = FVector(0,0,0);
	FVector OtherDir = FVector(0, 0, 0);
	FVector SideDir = FVector(0, 0, 0);
	/*
	if (Other == nullptr || Pawn == nullptr)
	{
		return true;
	}
	Speed=VSize(Pawn.Acceleration);
	if (Speed == 0)
	{
		NPCLog(Pawn.Name $ " Adjustround returning false");
		return false;
	}
	VelDir=Pawn.Acceleration / Speed;
	VelDir.Z=0;
	OtherDir=Other.Location - Pawn.Location;
	OtherDir.Z=0;
	OtherDir=Normal(OtherDir);
	if (VelDir Dot OtherDir > 0.8)
	{
		bAdjusting=True;
		SideDir.X=VelDir.Y;
		SideDir.Y=-1 * VelDir.X;
		if (SideDir Dot OtherDir > 0)
		{
			SideDir *= -1;
		}
		AdjustLoc=Pawn.Location + 2.5 * Other.CollisionRadius * 0.4 * VelDir + SideDir;
	}
	if (! bNoAdjustOther && NPCBaseController(Other.Controller) != None)
	{
		NPCBaseController(Other.Controller).AdjustAround(Pawn,True);
	}
	*/
	return true;
}

bool ANPCBaseController::NearWall(float walldist)
{
	AActor* HitActor = nullptr;
	FVector HitLocation = FVector(0,0,0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector ViewSpot = FVector(0, 0, 0);
	FVector ViewDist = FVector(0, 0, 0);
	FVector LookDir = FVector(0, 0, 0);
	/*
	LookDir= Vector(Rotation);
	ViewSpot=Pawn.Location + Pawn.BaseEyeHeight * vect(0 0 1);
	ViewDist=LookDir * walldist;
	HitActor=Trace(HitLocation,HitNormal,ViewSpot + ViewDist,ViewSpot,False);
	if (HitActor == nullptr)
	{
		return false;
	}
	ViewDist=Normal(HitNormal Cross vect(0 0 1)) * walldist;
	if (FMath::FRand() < 0.5)
	{
		ViewDist *= -1;
	}
	Focus=None;
	if (FastTrace(ViewSpot + ViewDist,ViewSpot))
	{
		FocalPoint=Pawn.Location + ViewDist;
		return true;
	}
	if (FastTrace(ViewSpot - ViewDist,ViewSpot))
	{
		FocalPoint=Pawn.Location - ViewDist;
		return true;
	}
	FocalPoint=Pawn.Location - LookDir * 300;
	*/
	return true;
}
void ANPCBaseController::WantsToRun()
{
	etsTravelSpeed = ETravelSpeed::TSRun;
}
void ANPCBaseController::WantsToWalk()
{
	etsTravelSpeed = ETravelSpeed::TSWalk;
}
void ANPCBaseController::WantsToCrawl()
{
	etsTravelSpeed = ETravelSpeed::TSCrawl;
}
void ANPCBaseController::WantsToCrouch()
{
	etsTravelSpeed = ETravelSpeed::TSCrouch;
}

bool ANPCBaseController::ShouldRun()
{
	//Return Pawn.bIsSprinting;
	return false;    //FAKE   /ELiZ
}
void ANPCBaseController::ResumeTravelSpeed()
{
	/*
	switch(etsTravelSpeed)
	{
		case 0:
		Prone();
		break;
		case 1:
		Crouch();
		break;
		case 2:
		Walk();
		break;
		case 3:
		Run();
		break;
		default:
	}
*/
}

void ANPCBaseController::PawnDied(APawn* p)
{
	AController* ctrlIterator = nullptr;
	if (!bStart)
	{
		return;
	}
	UpdatePathNodeBonuses(nullptr);
	/*
	NPCLog(string(Self) $ string(Tag) $ " Pawn died!");
	bStart = false;
	if (npcaiccCombatController != nullptr)
	{
		npcaiccCombatController.AddDeadBodyLocation(AGP_Pawn(Pawn));
	}
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (!ctrlIterator.IsA("NPCBaseController"))
		{
		}
		if (ctrlIterator != Self)
		{
			NPCBaseController(ctrlIterator).NotifyAnotherPawnDied(Self);
		}
	}
	NPCChangeState("Dead");
	*/
}

/*
void ANPCBaseController::UnPossess()
{
	
	Log("NPCBasecontroller.UnPossess() entered - not removing pawn though");
	bStart=False;
	NPCChangeState('None');
}
*/
void ANPCBaseController::AddHistoryContact(APawn* pawnSeen, bool bUpdateExistingContactOnly)
{
	/*
	local int iContactIndex;
	local int iOldestContactFound;
	local int iFirstBlankContact;
	local float fpOldestContactTime;
	iFirstBlankContact=-1;
	fpOldestContactTime=GetWorld()->GetTimeSeconds();
	for (iContactIndex=0; iContactIndex<20; iContactIndex++)
	{
		if (arcContactHistory[iContactIndex].pawnContact == nullptr)
		{
			iFirstBlankContact=iContactIndex;
		}
		else
		{
			if (arcContactHistory[iContactIndex].pawnContact == pawnSeen)
			{
				arcContactHistory[iContactIndex].fpClosureRate=VSize(arcContactHistory[iContactIndex].vLocation - Pawn.Location) - VSize(pawnSeen.Location - Pawn.Location);
				arcContactHistory[iContactIndex].fpTimeSeen=GetWorld()->GetTimeSeconds();
				arcContactHistory[iContactIndex].fpThreatLevel=EvaluateEnemyThreat(pawnSeen,False,arcContactHistory[iContactIndex].fpClosureRate);
				arcContactHistory[iContactIndex].bContactLost=False;
				NPCLog("Updated contact record for pawn just seen: " $ pawnSeen);
				if (pawnSeen.Weapon != None && pawnSeen.Weapon.IsA('RocketWeapon') && arcContactHistory[iOldestContactFound].iConfidencePenalty != 3)
				{
					arcContactHistory[iOldestContactFound].iConfidencePenalty=IncreaseNervousness(3);
				}
				Return;
			}
			if (fpOldestContactTime > arcContactHistory[iContactIndex].fpTimeSeen)
			{
				fpOldestContactTime=arcContactHistory[iContactIndex].fpTimeSeen;
				iOldestContactFound=iContactIndex;
			}
		}
	}
	if (bUpdateExistingContactOnly)
	{
		Return;
	}
	if (iFirstBlankContact != -1)
	{
		iOldestContactFound=iFirstBlankContact;
	}
	arcContactHistory[iOldestContactFound].pawnContact=pawnSeen;
	if (pawnSeen.Controller != None)
	{
		arcContactHistory[iOldestContactFound].bHumanControlled=pawnSeen.IsHumanControlled();
		if (pawnSeen.Controller.IsA('NPCBaseController'))
		{
			if (NPCBaseController(pawnSeen.Controller).iNPCTeamID != iNPCTeamID && NPCBaseController(pawnSeen.Controller).iNPCTeamID != 3)
			{
				arcContactHistory[iOldestContactFound].bEnemy=True;
			}
			else
			{
				arcContactHistory[iOldestContactFound].bEnemy=False;
			}
		}
		else
		{
			if (pawnSeen.Controller.GetTeamNum() != iNPCTeamID)
			{
				arcContactHistory[iOldestContactFound].bEnemy=True;
			}
			else
			{
				arcContactHistory[iOldestContactFound].bEnemy=False;
			}
		}
	}
	else
	{
		arcContactHistory[iOldestContactFound].bHumanControlled=False;
		arcContactHistory[iOldestContactFound].bEnemy=False;
	}
	arcContactHistory[iOldestContactFound].vLocation=pawnSeen.Location;
	arcContactHistory[iOldestContactFound].fpThreatLevel=EvaluateEnemyThreat(pawnSeen);
	arcContactHistory[iOldestContactFound].fpTimeSeen=GetWorld()->GetTimeSeconds();
	arcContactHistory[iOldestContactFound].bContactLost=False;
	if (pawnSeen.IsA('Vehicle'))
	{
		arcContactHistory[iOldestContactFound].iConfidencePenalty=IncreaseNervousness(4);
	}
	else
	{
		if (pawnSeen.Weapon != None && pawnSeen.Weapon.IsA('RocketWeapon'))
		{
			arcContactHistory[iOldestContactFound].iConfidencePenalty=IncreaseNervousness(3);
		}
		else
		{
			arcContactHistory[iOldestContactFound].iConfidencePenalty=IncreaseNervousness(2);
		}
	}
	*/
}

void ANPCBaseController::LostHistoryContact(APawn* pawnLost)
{
	/*
	local int iContactIndex;
	NPCLog("LostHistoryContact on pawn: " $ pawnLost);
	for (iContactIndex=0; iContactIndex<20; iContactIndex++)
	{
		if (arcContactHistory[iContactIndex].pawnContact == pawnLost)
		{
			NPCLog("Contact lost: " $ arcContactHistory[iContactIndex].pawnContact);
			arcContactHistory[iContactIndex].fpClosureRate=0;
			arcContactHistory[iContactIndex].bContactLost=True;
			Return;
		}
	}
	*/
}
void ANPCBaseController::AgeHistoryContacts()
{
	/*
	local int iContactIndex;
	for (iContactIndex=0; iContactIndex<20; iContactIndex++)
	{
		if (arcContactHistory[iContactIndex].pawnContact == nullptr)
		{
		}
		if (! arcContactHistory[iContactIndex].bContactLost)
		{
		}
		if (arcContactHistory[iContactIndex].fpThreatLevel <= 0)
		{
			NPCLog("Contact threat dropped, removing it");
			arcContactHistory[iContactIndex].pawnContact=None;
			Return;
		}
		arcContactHistory[iContactIndex].fpThreatLevel -= 0.5;
	}
*/
}

int32 ANPCBaseController::GetHighestThreatContactIndex(bool bRequireLOS)
{
	int32 iContactIndex = 0;
	int32 iHighestThreatContactIndex = 0;
	float fpHighestThreat = 0;
	iHighestThreatContactIndex=-1;
	/*
	for (iContactIndex=0; iContactIndex<20; iContactIndex++)
	{
		if (arcContactHistory[iContactIndex].pawnContact != None)
		{
			if (fpHighestThreat < arcContactHistory[iContactIndex].fpThreatLevel)
			{
				if (bRequireLOS)
				{
					if (! LineOfSightTo(arcContactHistory[iContactIndex].pawnContact))
					{
					}
				}
				else
				{
					iHighestThreatContactIndex=iContactIndex;
					fpHighestThreat=arcContactHistory[iContactIndex].fpThreatLevel;
				}
			}
		}
	}
	*/
	return iHighestThreatContactIndex;
}

void ANPCBaseController::AddGrenadeContact(AThrowWeaponPickup* twpGrenade)
{
	/*
	local int iGrenadeIndex;
	if (! twpGrenade.IsLive())
	{
		NPCLog("Ignoring non-live grenade: " $ twpGrenade);
	}
	NPCLog("Adding grenade """ $ twpGrenade $ """ to contact list");
	for (iGrenadeIndex=0; iGrenadeIndex<10; iGrenadeIndex++)
	{
		if (agtcGrenadeThreats[iGrenadeIndex].twpGrenade == nullptr || GetWorld()->GetTimeSeconds() > agtcGrenadeThreats[iGrenadeIndex].fpTimeSeen + 15)
		{
			NPCLog("Grenade threat detected: " $ twpGrenade);
			agtcGrenadeThreats[iGrenadeIndex].twpGrenade=twpGrenade;
			agtcGrenadeThreats[iGrenadeIndex].fpTimeSeen=GetWorld()->GetTimeSeconds();
			Return;
		}
	}
	*/
}

void ANPCBaseController::SurrenderedThrowDownWeapon()
{
}

void ANPCBaseController::NPCLog(FString sLogText)
{
	if (!bDebugMode)
	{
		return;
	}
	if (GetPawn() != nullptr)
	{
		//NPCPrivateLog(GetWorld()->GetTimeSeconds() $ " - " $ Self $ "." $ Tag $ "." $ GetStateName() $ " - " $ Pawn.Name $ " " $ sLogText);
	}
	else
	{
		//NPCPrivateLog(GetWorld()->GetTimeSeconds() $ " - " $ Self $ "." $ Tag $ "." $ GetStateName() $ " - " $ sLogText);
	}
}

void ANPCBaseController::NPCPathLog(FString sLogText)
{
	if (!bDebugPath)
	{
		return;
	}
	if (GetPawn() != nullptr)
	{
		//NPCPrivateLog(GetWorld()->GetTimeSeconds() $ " - " $ Self $ "." $ Tag $ "." $ GetStateName() $ " - " $ Pawn.Name $ " " $ sLogText);
	}
	else
	{
		//NPCPrivateLog(GetWorld()->GetTimeSeconds() $ " - " $ Self $ "." $ Tag $ "." $ GetStateName() $ " - " $ sLogText);
	}
}
