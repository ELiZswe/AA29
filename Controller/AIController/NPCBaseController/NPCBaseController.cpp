// All the original content belonged to the US Army


#include "NPCBaseController.h"

ANPCBaseController::ANPCBaseController()
{
	nameWaitingAnimation = "acf_checkwatch_a";
	iMaxContactAge = 15;

	sShoutEnemy = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_MoveOut.Voice3_Shout_MoveOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Stop.Voice3_Shout_Stop"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_CoverMe.Voice3_Shout_CoverMe"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_EnemySpotted.Voice3_Shout_EnemySpotted"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover.Voice3_Shout_TakeCover"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_EnemyDown.Voice3_Shout_EnemyDown"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_AreaSecure.Voice3_Shout_AreaSecure"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Roger.Voice3_Shout_Roger"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Negative.Voice3_Shout_Negative"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Up.Voice3_Shout_Up"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Down.Voice3_Shout_Down"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Left.Voice3_Shout_Left"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Right.Voice3_Shout_Right"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_North.Voice3_Shout_North"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_South.Voice3_Shout_South"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_East.Voice3_Shout_East"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_West.Voice3_Shout_West"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Hooah.Voice3_Shout_Hooah"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Sniper.Voice3_Shout_Sniper"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Frag.Voice3_Shout_Frag"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Smoke.Voice3_Shout_Smoke"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Flash.Voice3_Shout_Flash"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Grenade.Voice3_Shout_Grenade"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Ready.Voice3_Shout_Ready"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_ImHit.Voice3_Shout_ImHit"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_GetTheDoor.Voice3_Shout_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_CheckYourFlanks.Voice3_Shout_CheckYourFlanks"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_FragOut.Voice3_Shout_FragOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_WatchOut.Pilot_WatchOut"), NULL, LOAD_None, NULL)
	};

	sWhisperEnemy = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_MoveOut.Voice3_Whisper_MoveOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Stop.Voice3_Whisper_Stop"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_CoverMe.Voice3_Whisper_CoverMe"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_EnemySpotted.Voice3_Whisper_EnemySpotted"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_TakeCover.Voice3_Whisper_TakeCover"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_EnemyDown.Voice3_Whisper_EnemyDown"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_AreaSecure.Voice3_Whisper_AreaSecure"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Roger.Voice3_Whisper_Roger"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Negative.Voice3_Whisper_Negative"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Up.Voice3_Whisper_Up"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Down.Voice3_Whisper_Down"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Left.Voice3_Whisper_Left"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Right.Voice3_Whisper_Right"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_North.Voice3_Whisper_North"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_South.Voice3_Whisper_South"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_East.Voice3_Whisper_East"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_West.Voice3_Whisper_West"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Hooah.Voice3_Whisper_Hooah"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Sniper.Voice3_Whisper_Sniper"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Frag.Voice3_Whisper_Frag"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Smoke.Voice3_Whisper_Smoke"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Flash.Voice3_Whisper_Flash"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Grenade.Voice3_Whisper_Grenade"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_Ready.Voice3_Whisper_Read"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_ImHit.Voice3_Whisper_ImHit"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor.Voice3_Whisper_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_CheckYourFLanks.Voice3_Whisper_CheckYourFLanks"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_FragOut.Voice3_Shout_FragOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_WatchOut.Pilot_WatchOut"), NULL, LOAD_None, NULL)

	};

	sShoutFriendly = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_MoveOut.Voice2_Shout_MoveOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Stop.Voice2_Shout_Stop"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_CoverMe.Voice2_Shout_CoverMe"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_EnemySpotted.Voice2_Shout_EnemySpotted"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_TakeCover.Voice2_Shout_TakeCover"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_EnemyDown.Voice2_Shout_EnemyDown"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_AreaSecure.Voice2_Shout_AreaSecure"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Roger.Voice2_Shout_Roger"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Negative.Voice2_Shout_Negative"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Up.Voice2_Shout_Up"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Down.Voice2_Shout_Down"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Left.Voice2_Shout_Left"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Right.Voice2_Shout_Right"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_North.Voice2_Shout_North"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_South.Voice2_Shout_South"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_East.Voice2_Shout_East"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_West.Voice2_Shout_West"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Hooah.Voice2_Shout_Hooah"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Sniper.Voice2_Shout_Sniper"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Frag.Voice2_Shout_Frag"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Smoke.Voice2_Shout_Smoke"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Flash.Voice2_Shout_Flash"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Grenade.Voice2_Shout_Grenade"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_Ready.Voice2_Shout_Ready"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_ImHit.Voice2_Shout_ImHit"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_GetTheDoor.Voice2_Shout_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_CheckYourFlanks.Voice2_Shout_CheckYourFlanks"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_FragOut.Voice2_Shout_FragOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_GetDown.Pilot_GetDown"), NULL, LOAD_None, NULL)
	};

	sWhisperFriendly = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_MoveOut.Voice2_Whisper_MoveOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Stop.Voice2_Whisper_Stop"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_CoverMe.Voice2_Whisper_CoverMe"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_EnemySpotted.Voice2_Whisper_EnemySpotted"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_TakeCover.Voice2_Whisper_TakeCover"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_EnemyDown.Voice2_Whisper_EnemyDown"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_AreaSecure.Voice2_Whisper_AreaSecure"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Roger.Voice2_Whisper_Roger"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Negative.Voice2_Whisper_Negative"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Up.Voice2_Whisper_Up"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Down.Voice2_Whisper_Down"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Left.Voice2_Whisper_Left"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Right.Voice2_Whisper_Right"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_North.Voice2_Whisper_North"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_South.Voice2_Whisper_South"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_East.Voice2_Whisper_East"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_West.Voice2_Whisper_West"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Hooah.Voice2_Whisper_Hooah"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Sniper.Voice2_Whisper_Sniper"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Frag.Voice2_Whisper_Frag"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Smoke.Voice2_Whisper_Smoke"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Flash.Voice2_Whisper_Flash"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Grenade.Voice2_Whisper_Grenade"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_Ready.Voice2_Whisper_Ready"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_ImHit.Voice2_Whisper_ImHit"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_GetTheDoor.Voice2_Whisper_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Whisper_CheckYourFlanks.Voice2_Whisper_CheckYourFlanks"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice2/Voice2_Shout_FragOut.Voice2_Shout_FragOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_GetDown.Pilot_GetDown"), NULL, LOAD_None, NULL)
	};

	sShoutSquad = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_MoveOut.Voice1_Shout_MoveOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Stop.Voice1_Shout_Stop"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_CoverMe.Voice1_Shout_CoverMe"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_EnemySpotted.Voice1_Shout_EnemySpotted"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_TakeCover.Voice1_Shout_TakeCover"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_EnemyDown.Voice1_Shout_EnemyDown"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_AreaSecure.Voice1_Shout_AreaSecure"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Roger.Voice1_Shout_Roger"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Negative.Voice1_Shout_Negative"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Up.Voice1_Shout_Up"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Down.Voice1_Shout_Down"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Left.Voice1_Shout_Left"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Right.Voice1_Shout_Right"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_North.Voice1_Shout_North"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_South.Voice1_Shout_South"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_East.Voice1_Shout_East"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_West.Voice1_Shout_West"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Hooah.Voice1_Shout_Hooah"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Sniper.Voice1_Shout_Sniper"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Frag.Voice1_Shout_Frag"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Smoke.Voice1_Shout_Smoke"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Flash.Voice1_Shout_Flash"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Grenade.Voice1_Shout_Grenade"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_Ready.Voice1_Shout_Ready"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_ImHit.Voice1_Shout_ImHit"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_GetTheDoor.Voice1_Shout_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_CheckYourFlanks.Voice1_Shout_CheckYourFlanks"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_FragOut.Voice1_Shout_FragOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_EnemySoldiers.Pilot_EnemySoldiers"), NULL, LOAD_None, NULL)
	};

	sWhisperSquad = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_MoveOut.Voice1_Whisper_MoveOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Stop.Voice1_Whisper_Stop"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_CoverMe.Voice1_Whisper_CoverMe"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_EnemySpotted.Voice1_Whisper_EnemySpotted"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_TakeCover.Voice1_Whisper_TakeCover"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_EnemyDown.Voice1_Whisper_EnemyDown"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_AreaSecure.Voice1_Whisper_AreaSecure"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Roger.Voice1_Whisper_Roger"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Negative.Voice1_Whisper_Negative"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Up.Voice1_Whisper_Up"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Down.Voice1_Whisper_Down"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Left.Voice1_Whisper_Left"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Right.Voice1_Whisper_Right"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_North.Voice1_Whisper_North"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_South.Voice1_Whisper_South"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_East.Voice1_Whisper_East"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_West.Voice1_Whisper_West"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Hooah.Voice1_Whisper_Hooah"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Sniper.Voice1_Whisper_Sniper"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Frag.Voice1_Whisper_Frag"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Smoke.Voice1_Whisper_Smoke"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Flash.Voice1_Whisper_Flash"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Grenade.Voice1_Whisper_Grenade"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_Ready.Voice1_Whisper_Ready"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_ImHit.Voice1_Whisper_ImHit"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_GetTheDoor.Voice1_Whisper_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Whisper_CheckYourFlanks.Voice1_Whisper_CheckYourFlanks"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice1/Voice1_Shout_FragOut.Voice1_Shout_FragOut"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/DownedPilot/Pilot_EnemySoldiers.Pilot_EnemySoldiers"), NULL, LOAD_None, NULL)
	};

	sEnemyLeader = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Up.Voice3_Shout_Up"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Down.Voice3_Shout_Down"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Left.Voice3_Shout_Left"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_Right.Voice3_Shout_Right"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor.Voice3_Whisper_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor.Voice3_Whisper_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor.Voice3_Whisper_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor.Voice3_Whisper_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor.Voice3_Whisper_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor.Voice3_Whisper_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_GetTheDoor.Voice3_Whisper_GetTheDoor"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover.Voice3_Shout_TakeCover"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover.Voice3_Shout_TakeCover"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover.Voice3_Shout_TakeCover"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_TakeCover.Voice3_Shout_TakeCover"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_ImHit.Voice3_Whisper_ImHit"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_ImHit.Voice3_Whisper_ImHit"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_ImHit.Voice3_Whisper_ImHit"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Whisper_ImHit.Voice3_Whisper_ImHit"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_ImHit.Voice3_Shout_ImHit"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_PlayerCommo/voice3/Voice3_Shout_ImHit.Voice3_Shout_ImHit"), NULL, LOAD_None, NULL)

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
	Function PlayFinalAnimation ()
	{
		Return PlayCustomAnimation('GrdDigsEar',False,FRand() * 0.25 + 1);
	}
	Function PrepForFlashing ()
	{
		Return 0;
	}
	Function NPCFlashedAudioYell ()
	{
		NPCSay(24,True,True);
	}
	Function Timer ()
	{
		if (Level.TimeSeconds >= fpFlashBangedEndTime)
		{
			FlashBangEffectEnded();
		}
	}
	Function FlashBangEffectEnded ()
	{
		NPCLog(Self $ "." $ GetStateName() $ ".FlashBangEffectEnded()");
		if (GetLastStateName() == 'WalkingPatrol')
		{
			GotoState('ReturnToPatrol');
		}
		else
		{
			if (GetLastStateName() != 'FlashBanged')
			{
				GotoState(GetLastStateName());
			}
			else
			{
				GotoState('FindCover');
			}
		}
	}
	Function AdjustFlashedMentalState ()
	{
		IncreaseNervousness(10);
		IncreaseNervousness(9);
		IncreaseNervousness(7);
		IncreaseNervousness(1);
	}
	Function PerformFlashedAnimation ()
	{
		if (fpFlashBangedAudioIntensity / 1.13 >= 0.8)
		{
			Switch(Rand(3))
			{
				case 0:
				Return PlayCustomAnimation('Smokebanged',False,FRand() * 0.3 + 0.9);
				case 1:
				Return PlayCustomAnimation('FlashBanged',False,FRand() * 0.3 + 0.9);
				case 2:
				Return PlayCustomAnimation('FlashbangedMid',False,FRand() * 0.3 + 0.9);
				default:
				break;
			}
			if (fpFlashBangedAudioIntensity / 1.13 >= 0.25)
			{
				Switch(Rand(3))
				{
					case 0:
					Return PlayCustomAnimation('GrdBiglookAroundLg',False,1.2);
					case 1:
					Return PlayCustomAnimation('FlashbangedFar',False,FRand() * 0.3 + 0.9);
					case 2:
					Return PlayCustomAnimation('GrdSwatFly',False,1);
					default:
					break;
				}
				if (FRand() > 0.5)
				{
					Return PlayCustomAnimation('GrdDigsEar',False,FRand() * 0.3 + 0.9);
					break;
				}
				Return PlayCustomAnimation('StartledLg',False,FRand() * 0.3 + 0.9);
			}
		}
	}
	Function EndState ()
	{
		NPCLog(Self $ GetStateName() $ ".EndState() - exiting, last state name: " $ GetLastStateName());
		fpFlashBangedEndTime=0;
		fpFlashBangedVisualIntensity=0;
		fpFlashBangedAudioIntensity=0;
	}
	Function ArrivedAtPathnode ()
	{
	}
	Function NearWall (float walldist)
	{
	}
	Event NotifyPlayerPawnWatchingMe (Pawn pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound (NPCItemOfInterest npcioi)
	{
	}
	Function AdjustConfidenceByTime ()
	{
	}
	Event Bool NotifyHitWall (FVector HitNormal, Actor Wall)
	{
	}
	Event Bool NotifyBump (Actor Other)
	{
	}
	Function NotifyGrenadeLanded (ThrowWeaponPickup twpGrenade)
	{
	}
	Function ReceiveWarning (Pawn shooter, float projSpeed, FVector FireDir)
	{
	}
}
State WaitForPawnToLeavePathnode
{
}
State WalkingPatrol
{
	Function GetPathNodeFromRoute ()
	{
		local int i;
		if (pnCurrentNodeLeadingToPathNode == None)
		{
			Return PathNode(FindPathToward(pnCurrentPathNode,True));
		}
		for (i=0; i<61; i++)
		{
			if (RouteCache[i] == pnCurrentNodeLeadingToPathNode && RouteCache[i + 1] != None)
			{
				Return PathNode(RouteCache[i + 1]);
			}
			if (RouteCache[i] == None)
			{
				Return PathNode(FindPathToward(pnCurrentPathNode,True));
			}
		}
		Return PathNode(FindPathToward(pnCurrentPathNode,True));
	}
	Function MoverFinished ()
	{
	}
	Function DumpPathNodes ()
	{
		local int i;
		for (i=0; i<apnPathNodesForPatrol.Length; i++)
		{
			DebugLog(DEBUG_AIPathing,"Pathnode[" $ i $ "] -> " $ apnPathNodesForPatrol[i] $ " tag: " $ apnPathNodesForPatrol[i].Tag);
		}
	}
	Event Bool NotifyHitWall (FVector HitNormal, Actor Wall)
	{
		if (Wall.IsA('Mover') && ! Mover(Wall).bNotADoor)
		{
			if (Mover(Wall).bInterpolating)
			{
				Return False;
			}
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState('WalkingPatrol','OpeningDoor');
			Return True;
		}
		Return Global.pos(HitNormal,Wall);
	}
	Function ArrivedAtPathnode ()
	{
		local NPCItemOfInterest npcioi;
		if (bSupportItemOfInterestSearch && pnCurrentPathNode.IsA('NPCWaypointPathNode') && NPCWaypointPathNode(pnCurrentPathNode).bSearchForItemsOfInterest)
		{
			npcioi=GetNearbyItemOfInterest();
			if (npcioi != None)
			{
				if (npcioiLastFound == npcioi && Level.TimeSeconds - fpTimeSinceLastSawIOI < 30)
				{
					Return;
				}
				if (FRand() * 100 < npcioi.fpLikelihoodItemWillBeNoticed)
				{
					fpTimeSinceLastSawIOI=Level.TimeSeconds;
					npcioiLastFound=npcioi;
					NotifyItemOfInterestFound(npcioi);
				}
			}
		}
	}
	Function ShouldMoveToNextPathNode ()
	{
		Return True;
	}
	Function EndState ()
	{
		pnCurrentNodeLeadingToPathNode=None;
	}
	Function PrepActionForIdleAnimation ()
	{
		Return False;
	}
	Function EndActionIdleAnimation ()
	{
		Return False;
	}
}
State PawnStartsAsDummy
{
	simulated Function StopAnimation ()
	{
		StopAnimating(False);
	}
	simulated Function PlayLoopingAnimation ()
	{
		if (AnimChannel >= 1)
		{
			Pawn.AnimBlendParams(AnimChannel,1,Pawn.BlendChangeTime,Pawn.BlendChangeTime);
		}
		if (Level.NetMode == 0)
		{
			Pawn.LoopAnim(AnimSequence);
		}
		else
		{
			Pawn.SetLoopingAnimAction(AnimSequence);
		}
	}
	Function PlayStartupAnim ()
	{
		local float fpLength;
		if (AnimSequence == 'None' || AnimSequence == 'None')
		{
			Return 0;
		}
		fpLength=PlayCustomAnimation(AnimSequence,True);
		NPCLog("Anim: " $ AnimSequence $ " length: " $ fpLength);
		if (fpLength >= 0)
		{
			Return fpLength;
		}
		else
		{
			Return 0;
		}
	}
	Event AnimEnd (int Channel)
	{
		NPCLog("Animation end signalled for channel " $ Channel);
	}
	Function EndState ()
	{
		NPCLog("Pawn is leaving doing nothing (dummy)");
	}
	Function BeginState ()
	{
		NPCLog("Pawn is starting out doing nothing (dummy)");
	}
	Function UsedBy (Pawn User)
	{
		if (npccpCurrentConversation != None)
		{
			NPCLog(Self $ "UsedBy() - should interrupt conversation");
			npccpCurrentConversation.EndConversation();
		}
		Return Global.YPos(User);
	}
	Function ArrivedAtPathnode ()
	{
	}
	Function NotifyTakeDamage (int Damage, Pawn instigatedBy, FVector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
		if (bDummyPawnIgnoreAllEvents)
		{
			Return;
		}
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
	}
	Function NotifyBuzzedByBullet (Actor aShooter)
	{
		if (bDummyPawnIgnoreAllEvents)
		{
			Return;
		}
		Global.YPos(aShooter);
	}
	Function NotifyEnemyGrenadeClose (ThrowWeaponPickup twpGrenade)
	{
		if (bDummyPawnIgnoreAllEvents)
		{
			Return;
		}
		Global.agpwSecondary(twpGrenade);
	}
	Event NotifyPlayerPawnInSight (Pawn pawnSeen)
	{
		local int iRandomAudioIndex;
		if (VSize(Pawn.Location - pawnSeen.Location) > fpAudioTriggerRangeToPlayerUU || fpUnmanagedAudioMinDelayTime == 0)
		{
			Return;
		}
		if (Level.TimeSeconds >= fpUnmanagedAudioTimeNextPlay)
		{
			if (asndIdleRandomAudio.Length > 0 && ! bUseLipSynch || anameIdleRandomLipSyncAudio.Length > 0 && bUseLipSynch)
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
					Pawn.PlaySound(asndIdleRandomAudio[iRandomAudioIndex],0,1,False,fpAudioFullVolumeRadius,,True);
				}
				fpUnmanagedAudioTimeNextPlay=Level.TimeSeconds + FRand() * 10 + fpUnmanagedAudioMinDelayTime;
			}
		}
	}
	Function NotifyHeardPlayerNoise (float fpLoudness, Pawn pawnHeard)
	{
	}
	Function NotifyHeardWeaponNoise (float fpLoudness, AGP_Weapon agpwWeaponHeard, FVector vSoundLocation)
	{
	}
	Function NearWall (float walldist)
	{
	}
	Event NotifyPlayerPawnWatchingMe (Pawn pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound (NPCItemOfInterest npcioi)
	{
	}
	Function AdjustConfidenceByTime ()
	{
	}
	Event Bool NotifyHitWall (FVector HitNormal, Actor Wall)
	{
	}
	Event Bool NotifyBump (Actor Other)
	{
	}
	Event HearNoise (float Loudness, Actor NoiseMaker, optional FVector vSoundLocation)
	{
	}
}
State GuardMode
{
	Function FindClosePathNode ()
	{
		local NPCPathNode npcpnFound;
		local int iTry;
		if (apnPathNodesForPatrol.Length == 0)
		{
			Return None;
		}
		iTry=0;
		if (iTry < apnPathNodesForPatrol.Length * 2)
		{
			npcpnFound=apnPathNodesForPatrol[Rand(apnPathNodesForPatrol.Length)];
			if (fpMaxDistanceForGuardWandering == 0 || VSize(npcpnFound.Location - Pawn.Location) <= fpMaxDistanceForGuardWandering)
			{
				Return npcpnFound;
			}
			iTry ++;
		}
		Return None;
	}
	Function PlayStartupAnim ()
	{
		local float fpLength;
		fpLength=PlayCustomAnimation(AnimSequence,True);
		NPCLog("Anim: " $ AnimSequence $ " length: " $ fpLength);
		if (fpLength >= 0)
		{
			Return fpLength;
		}
		else
		{
			Return 0;
		}
	}
	Event Bool NotifyHitWall (FVector HitNormal, Actor Wall)
	{
		if (Wall.IsA('Mover') && ! Mover(Wall).bNotADoor)
		{
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState('GuardMode','PauseForDoor');
			Return True;
		}
		Return Global.pos(HitNormal,Wall);
	}
	Event AnimEnd (int Channel)
	{
		NPCLog("Animation end signalled for channel " $ Channel);
	}
	Function InitializeGuardMode ()
	{
		Return 0;
	}
	Function PrepPostIdleAnimationPlay ()
	{
	}
	Function PrepIdleAnimationPlay ()
	{
	}
}
State PawnHavingConversation
{
}
State ForcedIdle
{
	Function BeginState ()
	{
	}
	Function NearWall (float walldist)
	{
	}
	Event NotifyPlayerPawnWatchingMe (Pawn pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound (NPCItemOfInterest npcioi)
	{
	}
	Event NotifyPlayerPawnInSight (Pawn pawnSeen)
	{
	}
	Function AdjustConfidenceByTime ()
	{
	}
	Function Timer ()
	{
	}
	Event Bool NotifyHitWall (FVector HitNormal, Actor Wall)
	{
	}
	Event Bool NotifyBump (Actor Other)
	{
	}
	Event HearNoise (float Loudness, Actor NoiseMaker, optional FVector vSoundLocation)
	{
	}
}
State ArrivedAtRestStop
{
	Event PatrolResumeTriggerEvent ()
	{
		NPCLog("PatrolResumeTriggerEvent() entered");
		if (! ShouldMoveToNextPathNode())
		{
			Return;
		}
		DetermineNextPathNode();
		NPCChangeState('WalkingPatrol');
	}
	Function EndState ()
	{
		AGP_Pawn(Pawn).nmNPCIdleAnim='None';
		AGP_Pawn(Pawn).AnimLoopAction='None';
		AGP_Pawn(Pawn).AnimAction='None';
		AGP_Pawn(Pawn).PlayWaiting();
		AGP_Pawn(Pawn).PlayMoving();
		NPCPathLog(" Leaving ArrivedAtRestStop State");
	}
	Function PrepRestStopDeparture ()
	{
	}
	Function PrepRestStopArrival ()
	{
	}
}
State LookAround
{
}
State Cowering
{
	Function Timer ()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		NPCLog("Cowering - current confidence: " $ GetConfidenceLevel() $ " vs. min for movement" $ -40);
		if (GetConfidenceLevel() >= -40)
		{
			NPCLog("");
			NPCLog("");
			NPCLog("");
			NPCLog("Pawn leaving cowering due to confidence change");
			NPCChangeState('ReturnToPatrol');
		}
	}
	Function AdjustConfidenceByTime ()
	{
		local float fpUpdateDeltaTime;
		fpUpdateDeltaTime=5;
		if (Level.TimeSeconds > fpTimeLastNervousnessChange + fpUpdateDeltaTime)
		{
			IncreaseConfidence(14);
		}
	}
	Function PlayCowerAnimation ()
	{
	}
	Function BeginState ()
	{
		NPCLog("");
		NPCLog("");
		NPCLog("");
		NPCLog("ENTERING COWERING");
		NPCLog("Pawn is cowering at current location");
		if (GetConfidenceLevel() > -90)
		{
			SetConfidenceLevel(-90 - 1);
		}
	}
}
State LiveGrenade
{
	Function FinalCoverAction ()
	{
		DesiredRotation=pnCoverNode.Rotation;
		Focus=None;
		FocalPoint=Pawn.Location + 1024 *  Vector(pnCoverNode.Rotation);
		bRotateToDesired=True;
		Return True;
	}
	Function AdjustConfidence ()
	{
		if (GetConfidenceLevel() > -40)
		{
			if (twpLastGrenadeHeard != None && twpLastGrenadeHeard.IsA('Throw_M67_Frag'))
			{
				IncreaseNervousness(8);
				IncreaseNervousness(10);
			}
		}
	}
	Function BeginState ()
	{
		if (twpLastGrenadeHeard != None)
		{
			PerformGrenadeReaction();
		}
	}
	Function InCoverAction ()
	{
		NPCLog("InCoverAction() - default action - stop and crouch");
		StopMovement();
		Crouch();
	}
	Function InLastNodeBeforeCover ()
	{
	}
	Function GetCoverState ()
	{
		Return 'InCover';
	}
	Function GetNoCoverState ()
	{
		Return 'Cowering';
	}
	Function PerformGrenadeReaction ()
	{
	}
	Function GetConfidencePenalty ()
	{
		Return 15;
	}
	Function NotifyEnemyGrenadeClose (ThrowWeaponPickup twpGrenade)
	{
		NPCLog("Another grenade while already in LiveGrenade mode...");
		if (LineOfSightTo(twpGrenade))
		{
			if (VSize(twpGrenade.Location - Pawn.Location) < 1000)
			{
				actThreat=twpGrenade;
				SetConfidenceLevel(-40 - GetConfidencePenalty());
				NPCLog("Close grenade is dangerous to our hiding spot - we've got to move");
				NPCChangeState('LiveGrenade','Begin');
			}
		}
	}
	Function AdjustStateByConfidenceLevel ()
	{
	}
	Function EndState ()
	{
		NPCLog("");
		NPCLog("");
		NPCLog("");
		NPCLog("LEAVING " $ GetStateName());
	}
	Event Bool NotifyHitWall (FVector HitNormal, Actor Wall)
	{
		if (Pawn == None)
		{
			Return True;
		}
		if (Wall.IsA('Mover'))
		{
			if (Mover(Wall).bNotADoor)
			{
				PickWallAdjust(HitNormal);
				Return True;
			}
			else
			{
				if (Mover(Wall).bInterpolating)
				{
					NPCLog(Self $ "." $ Tag $ "." $ GetStateName() $ ".NotifyHitWall() hit mover that is interpolating: " $ Wall);
					Return True;
				}
				OpenDoorFromHere(Pawn.Location,Mover(Wall));
				NPCChangeState(GetStateName(),'PauseAfterBumpOnWayToPath');
				Return True;
			}
			Return False;
		}
		if (Wall.IsA('LevelInfo'))
		{
			Return False;
		}
		if (pnCoverNode == None)
		{
			Return False;
		}
		if (VSize(Pawn.Location - pnCoverNode.Location) < 50 && actThreat != None || ! LineOfSightTo(actThreat))
		{
			InCoverAction();
			Return True;
		}
		Return False;
	}
	Event Bool NotifyBump (Actor Other)
	{
		NPCLog("Running for cover and bumped into something.");
		if (Other.IsA('Pawn') && Other.IsInState('InCover'))
		{
			NPCLog("Running for cover, pawn we bumped is in cover, we must go elsewhere.");
			NPCChangeState(GetStateName());
			Return True;
		}
		if (pnCoverNode != None && VSize(Pawn.Location - pnCoverNode.Location) < 175 && LineOfSightTo(pnCoverNode) && pnCoverNode.cControllerUsingNode != None && pnCoverNode.cControllerUsingNode != Self)
		{
			StopMovement();
			NPCPathLog("PANIC BUMPED someone and destination node is now full, trying somewhere else");
			NPCChangeState(GetStateName());
			Return False;
		}
		Return Global.fpTimeToEndLastInterrupt(Other);
	}
	Function IsInMortalDanger ()
	{
		if (actThreat != None && VSize(Pawn.Location - actThreat.Location) < 600)
		{
			Return True;
		}
		else
		{
			Return False;
		}
	}
	Event WeaponCollision (Actor actorColliding)
	{
		if (actorColliding == None)
		{
			Return;
		}
		if (actorColliding.IsA('Mover') && ! Mover(actorColliding).bNotADoor)
		{
			if (Mover(actorColliding).bInterpolating)
			{
				Return;
			}
			OpenDoorFromHere(Pawn.Location,Mover(actorColliding));
			NPCChangeState(GetStateName(),'PauseAfterBumpOnWayToPath');
		}
		if (actorColliding != None)
		{
			AGP_Pawn(Pawn).GuardWeapon3p(6);
		}
		else
		{
			Pawn.UpperBodyAnimComplete();
		}
	}
	Function GetPathNodeFromRoute (PathNode pnLastNode, PathNode pnDesiredLocation)
	{
		local int i;
		if (pnLastNode == None)
		{
			Return PathNode(FindPathToward(pnDesiredLocation,True));
		}
		for (i=0; i<61; i++)
		{
			if (RouteCache[i] == pnLastNode && RouteCache[i + 1] != None)
			{
				Return PathNode(RouteCache[i + 1]);
			}
			if (RouteCache[i] == None)
			{
				Return PathNode(FindPathToward(pnDesiredLocation,True));
			}
		}
		Return PathNode(FindPathToward(pnDesiredLocation,True));
	}
	Event HearNoise (float Loudness, Actor NoiseMaker, optional FVector vSoundLocation)
	{
	}
	Function NotifyHeardPlayerNoise (float fpLoudness, Pawn pawnHeard)
	{
	}
	Function NotifyHeardWeaponNoise (float fpLoudness, AGP_Weapon agpwWeaponHeard, FVector vSoundLocation)
	{
	}
	Event NotifyPlayerPawnWatchingMe (Pawn pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound (NPCItemOfInterest npcioi)
	{
	}
	Event NotifyPlayerPawnInSight (Pawn pawnSeen)
	{
	}
	Function AdjustConfidenceByTime ()
	{
	}
	Function Timer ()
	{
	}
}
State Panic
{
	Function InitialPanicResponse ()
	{
	}
}
State InCover
{
	Function Timer ()
	{
		NPCLog("Threat is: " $ actThreat);
		if (actThreat == None || Level.TimeSeconds > fpTimeGrenadeHeard + 15)
		{
			NPCLog("Live grenade - current confidence: " $ GetConfidenceLevel() $ " vs. min for movement" $ -40);
			ThreatEnded();
			Global.pnCurrentNodeLeadingToPathNode();
		}
	}
	Function ThreatEnded ()
	{
		if (GetConfidenceLevel() > -40 + 5)
		{
			NPCLog("Ending grenade state because of confidence");
			NPCChangeState('ReturnToPatrol');
		}
	}
	Function AdjustConfidenceByTime ()
	{
		IncreaseConfidence(14);
	}
	Function NotifyEnemyGrenadeClose (ThrowWeaponPickup twpGrenade)
	{
		NPCLog("Another grenade while in cover...");
		if (LineOfSightTo(twpGrenade))
		{
			actThreat=twpGrenade;
			if (VSize(twpGrenade.Location - Pawn.Location) < 1000)
			{
				NPCLog("Close grenade is dangerous to our hiding spot - we've got to move");
				NPCChangeState('LiveGrenade','Begin');
			}
		}
	}
	Function BeginState ()
	{
		NPCLog("ENTERING INCOVER state");
	}
	Function AdjustStateByConfidenceLevel ()
	{
		if (actThreat == None)
		{
			Global.myPRI();
		}
	}
}
State FindCover
{
	Function InCoverAction ()
	{
		StopMovement();
		Crouch();
		fpTimeGrenadeHeard=Level.TimeSeconds;
	}
	Function GetCoverState ()
	{
		Return 'InCover';
	}
	Function GetConfidencePenalty ()
	{
		Return 10;
	}
	Function Timer ()
	{
		Global.pnCurrentNodeLeadingToPathNode();
	}
	Function AdjustStateByConfidenceLevel ()
	{
	}
	Function AdjustConfidenceByTime ()
	{
	}
	Function PerformGrenadeReaction ()
	{
	}
}
State ReturnToPatrol
{
	Function GetPathNodeFromRoute ()
	{
		local int i;
		if (pnCurrentNodeOnPathToCover == None)
		{
			Return PathNode(FindPathToward(pnCurrentPathNode,False));
		}
		for (i=0; i<61; i++)
		{
			if (RouteCache[i] == pnCurrentNodeOnPathToCover && RouteCache[i + 1] != None)
			{
				Return PathNode(RouteCache[i + 1]);
			}
			if (RouteCache[i] == None)
			{
				Return PathNode(FindPathToward(pnCurrentPathNode,False));
			}
		}
		Return PathNode(FindPathToward(pnCurrentPathNode,False));
	}
	Function EndState ()
	{
		NPCPathLog("");
		NPCPathLog("");
		NPCPathLog("Leaving RETURNTOPATROL");
	}
	Event Bool NotifyHitWall (FVector HitNormal, Actor Wall)
	{
		if (Wall.IsA('Mover') && ! Mover(Wall).bNotADoor)
		{
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState('WalkingPatrol','OpeningDoor');
			Return True;
		}
		Return Global.pos(HitNormal,Wall);
	}
}
State StuckByBadPath
{
	Function BeginState ()
	{
	}
}
State HeardPlayer
{
	Event WeaponCollision (Actor actorColliding)
	{
		if (actorColliding == None)
		{
			Return;
		}
		if (actorColliding != None)
		{
			AGP_Pawn(Pawn).GuardWeapon3p(6);
		}
		else
		{
			Pawn.UpperBodyAnimComplete();
		}
	}
	Function PerformFinishedLooking ()
	{
		NPCChangeState('ReturnToPatrol');
	}
	Function PerformPreLook ()
	{
		Return False;
	}
	Event Bool NotifyHitWall (FVector HitNormal, Actor Wall)
	{
		StopMovement();
		Return True;
	}
}
State MoveBackAfterBump
{
	Function ResumePreviousState ()
	{
		NPCLog("Resuming previous state of: " $ GetLastStateName());
		NPCChangeState(GetLastStateName());
	}
	Function PlayBumpedAudio ()
	{
	}
	Event Bool NotifyHitWall (FVector HitNormal, Actor Wall)
	{
		StopMovement();
		Return True;
	}
	Event Bool NotifyBump (Actor Other)
	{
		if (! AdjustAround(Pawn(Other)))
		{
			BackupAfterBump(Pawn(Other));
			Return False;
		}
		Return True;
	}
}
State Dead
{
	Function ServerReStartPlayer ()
	{
		if (Level.NetMode == 3)
		{
			Return;
		}
		NPCLog("Dead:ServerRestartPlayer() entered");
		Level.Game.RestartPlayer(Self);
	}
	Function PawnDied (Pawn p)
	{
		if (Level.NetMode != 3)
		{
			NPCLog(" Pawn died while dead");
		}
	}
	Function BeginState ()
	{
		if (actLastSoundPlayedEffect != None)
		{
			actLastSoundPlayedEffect.StopSound(sndLastSoundPlayed);
		}
		bStart=False;
	}
	Function Timer ()
	{
	}
	Event Bool NotifyBump (Actor Other)
	{
	}
	Event Bool NotifyHitWall (FVector HitNormal, Actor Wall)
	{
	}
	Function NotifyEnemyGrenadeClose (ThrowWeaponPickup twpGrenade)
	{
	}
	Event EnemyNotVisible ()
	{
	}
	Function NotifyTakeDamage (int Damage, Pawn instigatedBy, FVector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
	}
	Function NotifyBuzzedByBullet (Actor aShooter)
	{
	}
	Function Touch (Actor Other)
	{
	}
	Function KilledBy (Pawn EventInstigator)
	{
	}
}
State GameEnded
{
	Function BeginState ()
	{
		NPCLog("GameEnded.BeginState() entered, pawn is " $ Pawn);
		bStart=False;
	}
	Function ReceiveWarning (Pawn shooter, float projSpeed, FVector FireDir)
	{
	}
	Function TakeDamage (int Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
	{
	}
	Function KilledBy (Pawn EventInstigator)
	{
	}
}
State RoundEnded
{
	Function BeginState ()
	{
		NPCLog("RoundEnded.BeginState() entered, pawn is " $ Pawn);
		bStart=False;
	}
	Function ReceiveWarning (Pawn shooter, float projSpeed, FVector FireDir)
	{
	}
	Function TakeDamage (int Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
	{
	}
	Function KilledBy (Pawn EventInstigator)
	{
	}
}
State Surrender
{
	Function PlaySurrenderAnimation ()
	{
		Return PlayCustomAnimation('SurrenderKneesStart');
	}
	Function InitialSurrenderActions ()
	{
		NPCSay(1,True,True);
		Stand();
	}
	Function UsedBy (Pawn User)
	{
		Crouch();
		Return True;
	}
	Function NotifyTakeDamage (int Damage, Pawn instigatedBy, FVector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
	}
	Function BeginState ()
	{
	}
	Function NearWall (float walldist)
	{
	}
	Event NotifyPlayerPawnWatchingMe (Pawn pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound (NPCItemOfInterest npcioi)
	{
	}
	Event NotifyPlayerPawnInSight (Pawn pawnSeen)
	{
	}
	Function AdjustConfidenceByTime ()
	{
	}
	Event Bool NotifyHitWall (FVector HitNormal, Actor Wall)
	{
	}
	Event Bool NotifyBump (Actor Other)
	{
	}
	Event HearNoise (float Loudness, Actor NoiseMaker, optional FVector vSoundLocation)
	{
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
void ANPCBaseController::FastGetPathnodeByTagString(FString sTag)
{
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

void ANPCBaseController::DisplayDebugNoSpam(AAGP_HUD* AGPHUD, UCanvas Canvas, float& YL, float& YPos, FColor NewColor)
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
	/*
		switch(iNewOrders)
		{
			case 0:
			NPCLog("ORDER-PATROL - Starting patrol");
			NPCChangeState('ReturnToPatrol');
			break;
			case 1:
			NPCLog("ORDER_GUARD");
			NPCChangeState('GuardMode');
			break;
			case 2:
			NPCLog("ORDER_AMBUSH");
			if (IsA('NPCBaseSoldierController'))
			{
				NPCLog("Moving to a new fire position in Harass orders mode");
				NPCChangeState('MoveToNewCamperPosition');
			}
			break;
			case 3:
			NPCLog("ORDER_HUNT");
			NPCChangeState('AdvanceOnEnemyLocation');
			break;
			case 4:
			NPCLog("ORDER_DEFEND");
			if (IsA('NPCBaseSoldierController'))
			{
				NPCLog("Moving to a new fire position in Harass orders mode");
				NPCChangeState('MoveToNewFiringPosition');
			}
			break;
			case 5:
			NPCLog("ORDER_HARASS");
			if (IsA('NPCBaseSoldierController'))
			{
				NPCLog("Moving to a new fire position in Harass orders mode");
				NPCChangeState('MoveToNewFiringPosition');
			}
			break;
			case 6:
			NPCLog("ORDER_FLEE");
			if (iNPCCurrentOrders == iNewOrders)
			{
				Return;
			}
			if (IsA('NPCBaseSoldierController'))
			{
				NPCBaseSoldierController(Self).MoveToAlamoFirePosition();
			}
			break;
			case 9:
			if (IsA('NPCBaseSoldierController'))
			{
				NPCBaseSoldierController(Self).NPCChangeState('AssaultLocation');
			}
			break;
			case 8:
			NPCLog("ORDER_RUSH");
			NPCChangeState('AdvanceOnEnemyLocation');
			break;
			default:
			NotifyTacticalOrderChange(iNewOrders);
			Return;
		}
		iNPCCurrentOrders=iNewOrders;
	*/
}
void ANPCBaseController::NPCChangeState(FName nmState, FName nmLabel)
{
	/*
	if (GetStateName() == 'Dead')
	{
		NPCLog("Dead pawn trying to change state from Dead state - discarding");
		Return;
	}
	if (nmState == 'Dead')
	{
		GotoState(nmState,nmLabel);
		Return;
	}
	if (GetStateName() == 'PawnStartsAsDummy')
	{
		if (bDummyPawnIgnoreAllEvents)
		{
			Return;
		}
	}
	if (GetStateName() == 'FlashBanged' && Level.TimeSeconds < fpFlashBangedEndTime)
	{
		if (nmState == 'FlashBanged')
		{
			GotoState(nmState,nmLabel);
		}
		NPCLog("Flashbanged pawn trying to change state from Flashbanged state - discarding");
		Return;
	}
	GotoState(nmState,nmLabel);
*/
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
	if (Pawn == None)
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
		if (Pawn == None)
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
	if (Pawn._InvHands == None)
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
		if (PlayerReplicationInfo == None)
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
	if (AGP_Pawn(Pawn).VisionDistActor == None)
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
	if (Pawn == None)
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
	if (Pawn == None)
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
		if (Level.TimeSeconds > fpTimeLastHeard + 10)
		{
			aLastActorHeard=None;
		}
		if (Level.TimeSeconds > fpTimeLastSeen + 5)
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
	if (Pawn == None)
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
	if (IsInState('LiveGrenade') || IsInState('MoveToAlamoPosition') || IsInState('FindCoverThenFight') && IsA('NPCBaseSoldierController') && NPCBaseSoldierController(Self).sLastAICCMessage == "FallBack" && FRand() >= 0.5)
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
	if (Pawn == None)
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
	if (Pawn == None)
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
	if (Pawn == None)
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
	if (Pawn == None)
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
	if (Pawn == None)
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
	if (Pawn == None)
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
	if (Pawn == None)
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
	if (Pawn == None || Pawn.Health <= 0)
	{
		Return;
	}
	if (VisIntensity / 1.13 < 0.1)
	{
		Return;
	}
	NPCLog(Self $ "." $ GetStateName() $ ".NotifyFlashBanged() - Dur: " $ Duration $ ", VisInt: " $ VisIntensity $ ", AudInt: " $ AudIntensity);
	if (Level.TimeSeconds > fpFlashBangedEndTime)
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
	fpFlashBangedEndTime=Level.TimeSeconds + Duration;
	fpFlashBangDuration=Duration;
	NPCLog(Level.TimeSeconds $ " - Wanting to change to FlashBanged state until " $ fpFlashBangedEndTime $ " duration " $ Duration $ " currently in state " $ GetStateName());
	NPCChangeState('FlashBanged');
*/
}
void ANPCBaseController::NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone)
{
	/*
	local Controller ctrlIterator;
	if (! bStart)
	{
		Return;
	}
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	if (Pawn.Health - Damage <= 0)
	{
		if (Bone.Name == "BN_HeadEnd")
		{
			Return;
		}
	}
	if (DamageType == 'BleedDamage')
	{
		Return;
	}
	ctrlIterator=Level.ControllerList;
	if (ctrlIterator != None)
	{
		if (! ctrlIterator.IsA('NPCBaseController'))
		{
		}
		if (ctrlIterator != Self && instigatedBy != None)
		{
			NPCBaseController(ctrlIterator).NotifyAnotherPawnTookDamage(instigatedBy,Self);
		}
		ctrlIterator=ctrlIterator.nextController;
	}
	NPCLog("Damage """ $ DamageType $ """ received by NPC: " $ Damage);
	IncreaseNervousness(7);
	if (instigatedBy != None)
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
	if (twpGrenade == None)
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
	if (Pawn == None)
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
	if (Pawn == None)
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
			if (twpLastGrenadeHeard == None)
			{
				NPCLog("Saw grenade");
				if (fpDistanceToNoiseLocation < 2000)
				{
					twpLastGrenadeHeard=ThrowWeaponPickup(NoiseMaker);
					fpTimeGrenadeHeard=Level.TimeSeconds;
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
			fpTimeGrenadeHeard=Level.TimeSeconds;
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
	fpTimeLastHeard=Level.TimeSeconds;
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
/*
void ANPCBaseController::NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
{
	
	if (Pawn != None && Pawn.Health <= 0)
	{
		Return;
	}
	NPCLog("Found item of interest: " $ npcioi.Tag);
}
*/

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
	fpPawnHCLastSeen=Level.TimeSeconds;
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
	if (Pawn == None)
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
		fpTimeGrenadeHeard=Level.TimeSeconds;
		NotifyEnemyGrenadeClose(twpGrenade);
	}
*/
}
void ANPCBaseController::IncreaseNervousness(EMentalStateAdjustor msa)
{
	float fpConfidenceDelta = 0;
	/*
	if (bTrainingCadre)
	{
		Return fpConfidenceDelta;
	}
	fpConfidenceDelta=0;
	switch(msa)
	{
		case 1:
		if (GetConfidenceLevel() >= 0)
		{
			Return 0;
		}
		fpConfidenceDelta=1;
		break;
		case 0:
		if (GetConfidenceLevel() < -40)
		{
			Return 0;
		}
		fpConfidenceDelta=1;
		break;
		case 2:
		if (GetConfidenceLevel() < -10)
		{
			Return 0;
		}
		fpConfidenceDelta=2;
		break;
		case 3:
		if (GetConfidenceLevel() < -10)
		{
			Return 0;
		}
		fpConfidenceDelta=3;
		break;
		case 4:
		if (GetConfidenceLevel() < -10)
		{
			Return 0;
		}
		fpConfidenceDelta=5;
		break;
		case 7:
		if (GetConfidenceLevel() < -60)
		{
			Return 0;
		}
		fpConfidenceDelta=30;
		break;
		case 8:
		if (GetConfidenceLevel() < -60)
		{
			Return 0;
		}
		fpConfidenceDelta=2;
		break;
		case 9:
		if (GetConfidenceLevel() < -60)
		{
			Return 0;
		}
		fpConfidenceDelta=5;
		break;
		case 10:
		if (GetConfidenceLevel() < -10)
		{
			Return 0;
		}
		fpConfidenceDelta=1;
		break;
		case 11:
		if (GetConfidenceLevel() < -60)
		{
			Return 0;
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
	fpTimeLastNervousnessChange=Level.TimeSeconds;
	Return fpConfidenceDelta;
*/
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
	if (Level.TimeSeconds > fpTimeLastNervousnessChange + fpUpdateDeltaTime)
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
	fpTimeLastNervousnessChange=Level.TimeSeconds;
*/
}
void ANPCBaseController::CanPawnSeeMe(APawn* pawnSeen, bool bTestForAimingAtMe)
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
	return false;
*/
}
void ANPCBaseController::NotifyNPCSeen(APawn* Seen)
{
}
void ANPCBaseController::SeeMonster(APawn* Seen)
{
	/*
	if (Pawn != None && Pawn.Health <= 0 || Seen == None)
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
void ANPCBaseController::GetMaxVisionCone()
{
	/*
	if (fpNodeVisionConeAngle > 0)
	{
		Return fpNodeVisionConeAngle;
	}
	Return 19660;
*/
}
void ANPCBaseController::GetPawnViewRotation()
{
	/*
	Return Pawn.Rotation;
*/
}
float ANPCBaseController::EvaluateEnemyThreat(APawn* pawnToEvaluate, bool bWatchingMe, float fpClosureRate)
{
	float fpThreatLevel=0;
	/*
	if (pawnToEvaluate == None)
	{
		Return 0;
	}
	if (AGP_Pawn(pawnToEvaluate) == None)
	{
		if (pawnToEvaluate.IsA('SHelicopter'))
		{
			Return 5;
		}
		Return 0;
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
void ANPCBaseController::GetPathnodeByTag(FName Tag)
{
	/*
	local NavigationPoint N;
	if (Tag != 'None')
	{
		N=Level.NavigationPointList;
		if (N != None)
		{
			if (N.IsA('PathNode') && Tag == N.Tag)
			{
				Return PathNode(N);
			}
			N=N.nextNavigationPoint;
		}
	}
	Return None;
*/
}
void ANPCBaseController::GetPathnodeByTagString(FString sTag)
{
	/*
	local NavigationPoint N;
	if (Len(sTag) > 0)
	{
		N=Level.NavigationPointList;
		if (N != None)
		{
			if (N.IsA('PathNode') && sTag == N.Tag)
			{
				Return PathNode(N);
			}
			N=N.nextNavigationPoint;
		}
	}
	Return None;
*/
}
void ANPCBaseController::GetLadderPathnodeByName(FName nameOfNode)
{
	/*
	local NavigationPoint N;
	if (nameOfNode != 'None')
	{
		N=Level.NavigationPointList;
		if (N != None)
		{
			if (! N.IsA('Ladder'))
			{
			}
			if (nameOfNode ~= N.Name)
			{
				Return Ladder(N);
			}
			N=N.nextNavigationPoint;
		}
	}
	Return None;
*/
}
void ANPCBaseController::GetNearbyLadderVolume(APathNode* pnToSearchNear)
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
				Return lvIterator;
			}
		}
	}
	NPCPathLog("Looking for close-by ladder near: " $ pnToSearchNear.Tag);
	ForEach RadiusActors(Class'LadderVolume',lvIterator,250,pnToSearchNear.Location)
	{
		NPCPathLog("Found ladder volume" $ lvIterator.Tag);
		Return lvIterator;
	}
	Return None;
*/
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
void ANPCBaseController::FindNextPatrolPathNode()
{
	/*
	NPCPathLog("Searching for next navpoint to move to: " $ iCurrentPathNodeIndex + 1);
	if (iCurrentPathNodeIndex < apnPathNodesForPatrol.Length)
	{
		NPCPathLog("Found pathnode: " $ apnPathNodesForPatrol[iCurrentPathNodeIndex]);
		pnCurrentPathNode=apnPathNodesForPatrol[iCurrentPathNodeIndex];
		Return pnCurrentPathNode;
	}
	NPCPathLog("FindNextPatrolPathNode() - Couldn't find pathnode");
	Return None;
*/
}
void ANPCBaseController::DetermineNodeAfterCurrentNode()
{
	/*
	local int iSavedCurrentPathNodeIndex;
	local PathNode pnNextNodeFound;
	iSavedCurrentPathNodeIndex=iCurrentPathNodeIndex;
	DetermineNextPathNode();
	pnNextNodeFound=FindNextPatrolPathNode();
	iCurrentPathNodeIndex=iSavedCurrentPathNodeIndex;
	if (pnNextNodeFound != None)
	{
		Return pnNextNodeFound;
	}
	else
	{
		Return None;
	}
*/
}
void ANPCBaseController::CloseDoor(AMover* mDoor)
{
	/*
	if (! mDoor.bClosed)
	{
		mDoor.ReallyDoClose();
	}
*/
}
/*
void ANPCBaseController::OpenDoor(ANPCDoorEntryPathNode* npcdepn)
{
	local Mover mIterator;
	local bool bFirstDoorOpened;
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
				if (mLastDoorOpened == None)
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
	if (mLastDoorOpened == None)
	{
		NPCPathLog("*** WARNING *** - Door not found!");
		return true;
	}
	NPCPathLog("Door locked and can't be opened by this NPC");
	return false;
}
*/
void ANPCBaseController::OpenDoorFromHere(FVector vLocation, AMover* moverBumpedDoor)
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
	if (mLastDoorOpened == None)
	{
		Log("*** WARNING *** - Door not found!");
		return true;
	}
	Log("Door locked and can't be opened by this NPC");
	return false;
*/
}
/*
void ANPCBaseController::FindDoor(ANPCDoorEntryPathNode* npcdepn)
{
	local Mover mIterator;
	if (mLastDoorOpened != None && npcdepn.nameDoorToOpen == mLastDoorOpened.Name)
	{
		Return mLastDoorOpened;
	}
	mLastDoorOpened=None;
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
	Return mLastDoorOpened;
}
*/
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
/*
void ANPCBaseController::UpdatePathNodeBonuses(ANPCPathNode* npcpn)
{
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
}
*/
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
/*
void ANPCBaseController::StartClimbingLadder(ALadderVolume* lvLadder)
{
	Log("Entering ladder");
	bOnLadder=True;
}
*/
/*
void ANPCBaseController::NotifyConversationPackStart(ANPCConversationPack* npccpNew)
{
	NPCLog(Self $ "Pawn conversation start signalled for pack: " $ npccpNew $ " while in state " $ GetStateName());
	npccpCurrentConversation=npccpNew;
	namePreConversationPackState=GetStateName();
	NPCChangeState('PawnHavingConversation');
}
*/
/*
void ANPCBaseController::NotifyConversationPackEnded(ANPCConversationPack* npccpJustEnded)
{
	npccpCurrentConversation=None;
	if (GetStateName() ~= "PawnHavingConversation")
	{
		NPCChangeState(namePreConversationPackState);
	}
}
*/
void ANPCBaseController::GetLookRotationRate()
{
	//Return 8192;
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
	if (Pawn == None)
	{
		Return;
	}
	if (Pawn.Health <= 0)
	{
		Return;
	}
	if (fNPCLastTalkTime < Level.TimeSeconds || forceplay == True)
	{
		fNPCLastTalkTime=Level.TimeSeconds + 5 * FRand() + 5;
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
void ANPCBaseController::FindCoverPathNode(bool bFindFarthestPointFromThreat)
{
	//Return FastFindCoverPathNode(bFindFarthestPointFromThreat);
}
void ANPCBaseController::FindEscapePathNode(float fpMinDistance)
{
	/*
	local NPCPathNode pnIterator;
	local NPCPathNode pnBestCover;
	local Actor traceHit;
	local FVector HitLocation;
	local FVector HitNormal;
	local FVector StartTrace;
	local FVector EndTrace;
	local float fpThreatFacing;
	local float fpNodeFacing;
	local NavigationPoint N;
	if (Pawn == None || Pawn.Health <= 0)
	{
		Return None;
	}
	if (actThreat == None)
	{
		if (GetConfidenceLevel() <= -60)
		{
			N=Level.NavigationPointList;
			if (N != None)
			{
				if (! N.IsA('NPCPathNode'))
				{
				}
				pnIterator=NPCPathNode(N);
				if (pnIterator.cControllerUsingNode != None && pnIterator.cControllerUsingNode != Self)
				{
				}
				if (fpMinDistance > 0 && VSize(pnIterator.Location - Pawn.Location) < fpMinDistance)
				{
				}
				if (pnBestCover == None)
				{
					pnBestCover=pnIterator;
				}
				else
				{
					if (VSize(pnBestCover.Location - Pawn.Location) < VSize(pnIterator.Location - Pawn.Location))
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
			Return pnBestCover;
		}
	}
	if (actThreat != None)
	{
		fpThreatFacing=Normal( Vector(Pawn.Rotation)) Dot actThreat.Location - Pawn.Location;
	}
	N=Level.NavigationPointList;
	if (N != None)
	{
		if (! N.IsA('NPCPathNode'))
		{
		}
		pnIterator=NPCPathNode(N);
		if (pnIterator.cControllerUsingNode != None && pnIterator.cControllerUsingNode != Self)
		{
		}
		if (actThreat != None)
		{
			if (VSize(pnIterator.Location - actThreat.Location) < 1500)
			{
				fpNodeFacing=Normal( Vector(Pawn.Rotation)) Dot pnIterator.Location - Pawn.Location;
				if (fpNodeFacing > 0 && fpThreatFacing > 0 || fpNodeFacing < 0 && fpThreatFacing < 0 || fpNodeFacing == 0 && fpThreatFacing == 0)
				{
					NPCLog("Skipping node due to facing is same direction as threat (node: " $ fpNodeFacing $ ", threat: " $ fpThreatFacing $ ")");
				}
				else
				{
					StartTrace=pnIterator.Location;
					StartTrace.Z += 512;
					EndTrace=actThreat.Location;
					traceHit=pnIterator.Trace(HitLocation,HitNormal,EndTrace,StartTrace,True);
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
				if (pnBestCover == None)
				{
					pnBestCover=pnIterator;
				}
				else
				{
					if (VSize(pnBestCover.Location - Pawn.Location) > VSize(pnIterator.Location - Pawn.Location))
					{
						pnBestCover=pnIterator;
					}
				}
			}
		}
		N=N.nextNavigationPoint;
	}
	Return pnBestCover;
*/
}
void ANPCBaseController::ReceiveWarning(APawn* shooter, float projSpeed, FVector FireDir)
{
	/*
	local float fpChance;
	if (Pawn == None)
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
	fpChance=FRand();
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
void ANPCBaseController::GetNearbyItemOfInterest()
{
	/*
	local NPCItemOfInterest npcioi;
	ForEach RadiusActors('NPCItemOfInterest',npcioi,fpItemOfInterestSearchRange,Pawn.Location)
	{
		if (VSize(npcioi.Location - Pawn.Location) <= npcioi.fpMaxDistanceToNotice)
		{
			Return npcioi;
		}
	}
	Return None;
*/
}
void ANPCBaseController::SelectIdleRelatedAnimation(bool bForcePlaying)
{
	/*
	iCurrentIdleAnimIndex=-1;
	if (Pawn == None || Pawn != None && Pawn.Health <= 0)
	{
		return false;
	}
	if (anpcassNPCIdleAnimations.Length > 0)
	{
		if (FRand() > 0.5 || bForcePlaying)
		{
			iCurrentIdleAnimIndex=Rand(anpcassNPCIdleAnimations.Length);
			return true;
		}
	}
	return false;
*/
}
void ANPCBaseController::PlayIdleRelatedAnimation(bool bForcePlaying, bool bLoopAnimation)
{
	/*
	iCurrentIdleAnimIndex=-1;
	if (Pawn == None || Pawn != None && Pawn.Health <= 0)
	{
		Return 0;
	}
	NPCLog("PlayIdleRelatedAnimation() - Weapon is: " $ AGP_Pawn(Pawn).Weapon $ " animation length: " $ anpcassNPCIdleAnimations.Length);
	if (AGP_Pawn(Pawn).Weapon == None && anpcassNPCIdleAnimations.Length > 0)
	{
		if (FRand() > 0.5 || bForcePlaying)
		{
			iCurrentIdleAnimIndex=Rand(anpcassNPCIdleAnimations.Length);
			Return PlayCustomAnimation(anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].animStart,bLoopAnimation);
		}
	}
	Return 0;
*/
}
void ANPCBaseController::PlayCustomAnimation(FName nameAnimation, bool bLoop, float fpRate)
{
	/*
	if (Pawn == None || Pawn != None && Pawn.Health <= 0)
	{
		Return 0;
	}
	if (nameAnimation == 'None' || nameAnimation == 'None')
	{
		Return 0.5;
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
		Return 0;
	}
	Return Pawn.GetAnimDuration(nameAnimation);
*/
}
void ANPCBaseController::PlayCustomSound(USoundBase* sndToPlay)
{
	/*
	local Actor SoundActor;
	if (Pawn == None || Pawn != None && Pawn.Health <= 0)
	{
		Return 0;
	}
	SoundActor=Spawn(Class'EffectLocation',,,Pawn.Location);
	SoundActor.LifeSpan=GetSoundDuration(sndToPlay);
	SoundActor.PlaySound(sndToPlay,0,1,,,,False);
	NPCLog("PlayCustomSound length: " $ sndToPlay.Duration);
	Return sndToPlay.Duration;
*/
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
	if (Other == None)
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
void ANPCBaseController::NotifyPhysicsVolumeChange(APhysicsVolume* NewVolume)
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
	return true;
*/
}
void ANPCBaseController::AdjustAround(APawn* Other, bool bNoAdjustOther)
{
	/*
	local float Speed;
	local FVector VelDir;
	local FVector OtherDir;
	local FVector SideDir;
	if (Other == None || Pawn == None)
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
	return true;
*/
}
void ANPCBaseController::NearWall(float walldist)
{
	/*
	local Actor HitActor;
	local FVector HitLocation;
	local FVector HitNormal;
	local FVector ViewSpot;
	local FVector ViewDist;
	local FVector LookDir;
	LookDir= Vector(Rotation);
	ViewSpot=Pawn.Location + Pawn.BaseEyeHeight * vect(0 0 1);
	ViewDist=LookDir * walldist;
	HitActor=Trace(HitLocation,HitNormal,ViewSpot + ViewDist,ViewSpot,False);
	if (HitActor == None)
	{
		return false;
	}
	ViewDist=Normal(HitNormal Cross vect(0 0 1)) * walldist;
	if (FRand() < 0.5)
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
	return true;
*/
}
void ANPCBaseController::WantsToRun()
{
	//etsTravelSpeed = 3;
}
void ANPCBaseController::WantsToWalk()
{
	//etsTravelSpeed = 2;
}
void ANPCBaseController::WantsToCrawl()
{
	//etsTravelSpeed = 0;
}
void ANPCBaseController::WantsToCrouch()
{
	//etsTravelSpeed = 1;
}
void ANPCBaseController::ShouldRun()
{
	//Return Pawn.bIsSprinting;
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
	/*
	local Controller ctrlIterator;
	if (! bStart)
	{
		Return;
	}
	UpdatePathNodeBonuses(None);
	NPCLog(Self $ Tag $ " Pawn died!");
	bStart=False;
	if (npcaiccCombatController != None)
	{
		npcaiccCombatController.AddDeadBodyLocation(AGP_Pawn(Pawn));
	}
	ctrlIterator=Level.ControllerList;
	if (ctrlIterator != None)
	{
		if (! ctrlIterator.IsA('NPCBaseController'))
		{
		}
		if (ctrlIterator != Self)
		{
			NPCBaseController(ctrlIterator).NotifyAnotherPawnDied(Self);
		}
		ctrlIterator=ctrlIterator.nextController;
	}
	NPCChangeState('Dead');
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
	fpOldestContactTime=Level.TimeSeconds;
	for (iContactIndex=0; iContactIndex<20; iContactIndex++)
	{
		if (arcContactHistory[iContactIndex].pawnContact == None)
		{
			iFirstBlankContact=iContactIndex;
		}
		else
		{
			if (arcContactHistory[iContactIndex].pawnContact == pawnSeen)
			{
				arcContactHistory[iContactIndex].fpClosureRate=VSize(arcContactHistory[iContactIndex].vLocation - Pawn.Location) - VSize(pawnSeen.Location - Pawn.Location);
				arcContactHistory[iContactIndex].fpTimeSeen=Level.TimeSeconds;
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
	arcContactHistory[iOldestContactFound].fpTimeSeen=Level.TimeSeconds;
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
		if (arcContactHistory[iContactIndex].pawnContact == None)
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
void ANPCBaseController::GetHighestThreatContactIndex(bool bRequireLOS)
{
	/*
	local int iContactIndex;
	local int iHighestThreatContactIndex;
	local float fpHighestThreat;
	iHighestThreatContactIndex=-1;
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
	Return iHighestThreatContactIndex;
*/
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
		if (agtcGrenadeThreats[iGrenadeIndex].twpGrenade == None || Level.TimeSeconds > agtcGrenadeThreats[iGrenadeIndex].fpTimeSeen + 15)
		{
			NPCLog("Grenade threat detected: " $ twpGrenade);
			agtcGrenadeThreats[iGrenadeIndex].twpGrenade=twpGrenade;
			agtcGrenadeThreats[iGrenadeIndex].fpTimeSeen=Level.TimeSeconds;
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
	/*
	if (! bDebugMode)
	{
		Return;
	}
	if (Pawn != None)
	{
		NPCPrivateLog(Level.TimeSeconds $ " - " $ Self $ "." $ Tag $ "." $ GetStateName() $ " - " $ Pawn.Name $ " " $ sLogText);
	}
	else
	{
		NPCPrivateLog(Level.TimeSeconds $ " - " $ Self $ "." $ Tag $ "." $ GetStateName() $ " - " $ sLogText);
	}
*/
}
void ANPCBaseController::NPCPathLog(FString sLogText)
{
	/*
	if (! bDebugPath)
	{
		Return;
	}
	if (Pawn != None)
	{
		NPCPrivateLog(Level.TimeSeconds $ " - " $ Self $ "." $ Tag $ "." $ GetStateName() $ " - " $ Pawn.Name $ " " $ sLogText);
	}
	else
	{
		NPCPrivateLog(Level.TimeSeconds $ " - " $ Self $ "." $ Tag $ "." $ GetStateName() $ " - " $ sLogText);
	}
*/
}
