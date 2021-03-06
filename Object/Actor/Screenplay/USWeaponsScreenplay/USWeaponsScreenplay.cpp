// All the original content belonged to the US Army

#include "AA29/Object/Actor/Screenplay/USWeaponsScreenplay/USWeaponsScreenplay.h"

AUSWeaponsScreenplay::AUSWeaponsScreenplay()
{

}

void AUSWeaponsScreenplay::Init()
{
	SetGlobalEvents();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerDead", "");
	Direction("AGP_Script.Dir_SceneJump", "DeadEnd;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenFriendlyFire", "");
	Direction("AGP_Script.Dir_SceneJump", "GotoJail;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenEventSounds", "sndvFireDirection;");
	Direction("AGP_Script.Dir_SceneJump", "SafetyViolation;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenCheats", "");
	Direction("AGP_Script.Dir_SceneJump", "PlayerCheated;", "");
	EndEvent();
	EndGlobalEvents();
	NewScene("Introduction");
	SceneInit_Start();
	Direction("AGP_Script.Dir_SetIntVar", "ivTrainingStationCompleted;SET;0;", "");
	Direction("AGP_Script.Dir_SetNoCheats", "", "");
	Direction("AGP_Script.Dir_SetPlayerLocation", "locStart;", "");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_SetPlayerInventory", "invStart;", "");
	Direction("AGP_Script.Dir_Fade", "true;true;3.0;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;3.0;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_StartSound", "sndIntro;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_PlayTip", "U.S. Weapons Familiarization;Fort Benning, GA;7.0;;;;;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "sndIntro;");
	Direction("AGP_Script.Dir_PlayerLockMovement", "false;false;", "");
	Direction("AGP_Script.Dir_SceneJump", "Wandering;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("Wandering");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "false;false;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChanges", "trigStationOne;true;");
	Direction("AGP_Script.Dir_SceneJump", "StationOne;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChangesB", "trigStationTwo;true;");
	Direction("AGP_Script.Dir_SceneJump", "StationTwo;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChangesC", "trigStationThree;true;");
	Direction("AGP_Script.Dir_SceneJump", "StationThree;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChangesD", "trigStairs;true;");
	Direction("AGP_Script.Dir_SceneJump", "Goodbye;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("StationOne");
	SceneInit_Start();
	Direction("AGP_Script.Dir_SetIntVar", "ivTrainingStationCompleted;INC;1;", "");
	Direction("AGP_Script.Dir_StartSound", "sndIntroM249;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_SetPlayerInventory", "invStart;", "");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_PlayTip", "Press <0> to pick up weapons and ammunition.;;7.0;Action;;;;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenFire", "");
	Direction("AGP_Script.Dir_SceneJump", "SafetyViolation", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "sndIntroM249;");
	Direction("AGP_Script.Dir_PlayerLockMovement", "false;false;", "");
	Direction("AGP_Script.Dir_SceneJump", "StationOneB;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("StationOneB");
	SceneInit_Start();
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChanges", "trigStationOneExit;false;");
	Direction("AGP_Script.Dir_TriggerActive", "trigStationOne;false;", "");
	Direction("AGP_Script.Dir_TriggerActive", "trigStationOneExit;false;", "");
	Direction("AGP_Script.Dir_SceneJump", "Wandering;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("StationTwo");
	SceneInit_Start();
	Direction("AGP_Script.Dir_SetIntVar", "ivTrainingStationCompleted;INC;1;", "");
	Direction("AGP_Script.Dir_StartSound", "sndIntroM203;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_SetPlayerInventory", "invStart;", "");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_PlayTip", "Press <0> to pick up weapon and ammunition.;Press <1> to cycle firing modes and press <2> to switch to grenades.;7.0;Action;AltFire;SupportedFire;;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenFire", "");
	Direction("AGP_Script.Dir_SceneJump", "SafetyViolation", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "sndIntroM203;");
	Direction("AGP_Script.Dir_PlayerLockMovement", "false;false;", "");
	Direction("AGP_Script.Dir_PlayTip", "Elevate the M-203 and fire on distant targets.;Use this opportunity to practice range estimation.;5.0;;;;;", "");
	Direction("AGP_Script.Dir_SceneJump", "StationTwoB;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("StationTwoB");
	SceneInit_Start();
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChanges", "trigStationTwoExit;false;");
	Direction("AGP_Script.Dir_TriggerActive", "trigStationTwo;false;", "");
	Direction("AGP_Script.Dir_TriggerActive", "trigStationTwoExit;false;", "");
	Direction("AGP_Script.Dir_SceneJump", "Wandering;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("StationThree");
	SceneInit_Start();
	Direction("AGP_Script.Dir_SetIntVar", "ivTrainingStationCompleted;INC;1;", "");
	Direction("AGP_Script.Dir_SetPlayerInventory", "invStart;", "");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_PlayTip", "Press <0> to pick up grenades.;Press <1> to select frag grenades, <2> for smoke.;5.0;Action;GrenadeFrag;GrenadeSmoke;;", "");
	Direction("AGP_Script.Dir_StartSound", "sndIntroM67Frag;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;5.0;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_PlayTip", "Press and release <0> to throw grenades.;To roll grenade, press <1>.;5.0;Fire;AltFire;;;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer2;5.0;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer2;");
	Direction("AGP_Script.Dir_PlayTip", "To cook the grenade, hold down <1> and press <0>.;The fuse lasts about 5 seconds.;7.0;AltFire;Fire;;;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "sndIntroM67Frag;");
	Direction("AGP_Script.Dir_PlayerLockMovement", "false;false;", "");
	Direction("AGP_Script.Dir_SceneJump", "StationThreeB;", "");
	Direction("AGP_Script.Dir_StartSound", "sndSmoke;;SLOT_Talk;","");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("StationThreeB");
	SceneInit_Start();
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChanges", "trigStationThreeExit;false;");
	Direction("AGP_Script.Dir_TriggerActive", "trigStationThree;false;","");
	Direction("AGP_Script.Dir_TriggerActive", "trigStationThreeExit;false;","");
	Direction("AGP_Script.Dir_SceneJump", "Wandering;","");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("Goodbye");
	SceneInit_Start();
	Direction("AGP_Script.Dir_JumpOnIntVar", "ivTrainingStationCompleted;0;2;SkippedStation;","");
	Direction("AGP_Script.Dir_StartSound", "sndGoodbye;;SLOT_Talk;","");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;true;","");
	Direction("AGP_Script.Dir_DisplayMissionSuccess", "T_AA2_UI.tour_icons.hud_menu_touricon_BasicBCT;Congratulations!;;128;128;6;SceneReload;","");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("SkippedStation");
	SceneInit_Start();
	Direction("AGP_Script.Dir_StartSound", "sndSkippedStation;;SLOT_Talk;","");
	Direction("AGP_Script.Dir_PlayTip", "You skipped a station.;You must complete all stations to complete this training.;4.0;;;;;","");
	Direction("AGP_Script.Dir_SceneJump", "Wandering;","");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("DeadEnd");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;true;","");
	Direction("AGP_Script.Dir_StartSound", "sndDead;;SLOT_Talk;","");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "sndDead;");
	Direction("AGP_Script.Dir_DisplayMissionFailure", "T_AA2_UI.tour_icons.hud_menu_touricon_BasicBCT;You have died.;;128;128;6;SceneReload;","");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("SafetyViolation");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;true;","");
	Direction("AGP_Script.Dir_PlayTip", "Safety violation.;Come back when you're paying attention.;4.0;;;;;","");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;4.0;","");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_SceneJump", "SceneReload;","");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("SceneReload");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;true;","");
	Direction("AGP_Script.Dir_RunConsoleCommand", "reconnect;","");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("GotoJail");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;true;","");
	Direction("AGP_Script.Dir_Fade", "false;true;2.0;","");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;2.0;","");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_RunConsoleCommand", "Open Leavenworth;","");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("PlayerCheated");
	SceneInit_Start();
	Direction("AGP_Script.Dir_DisplayMissionFailure", "T_AA2_UI.tour_icons.hud_menu_touricon_BasicBCT;You cheated!;;128;128;6;SceneReload;", "");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
}
