// All the original content belonged to the US Army

#include "AA29/Object/Actor/Screenplay/LandNavScreenplay/LandNavScreenplay.h"

ALandNavScreenplay::ALandNavScreenplay()
{

}

void ALandNavScreenplay::Init()
{
	NewScene("Init");
	SceneInit_Start();
	Direction("AGP_Script.Dir_SetPlayerLocation", "locPlayerStart;","");
	Direction("AGP_Script.Dir_SetLocation", "locDrillStart;pawnInstructor;", "");
	Direction("AGP_Script.Dir_Fade", "true;true;3.0", "");
	Direction("AGP_Script.Dir_StartTimer", "atmrIntroFade;3.0;", "");
	Direction("AGP_Script.Dir_ControlAnimation", "animInstructor;LoopAnim;DrillIdle;1.0;;;0;", "");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_TriggerActive", "atrigFinish;false;", "");
	Direction("AGP_Script.Dir_HidePlayerCompassObj", "true;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective0;false;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective1;false;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective2;false;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective3;false;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective4;false;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective5;false;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective6;false;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "atmrIntroFade;");
	Direction("AGP_Script.Dir_SceneJump", "Introduction;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("Introduction");
	SceneInit_Start();
	Direction("AGP_Script.Dir_StartSound", "asndSGT01;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_ControlAnimation", "animInstructor;PlayAnim;DrillHandsTransition;1.0;;;;", "");
	Direction("AGP_Script.Dir_ControlAnimation", "animInstructor;LoopAnim;DrillTalkHands;1.0;;;0;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "asndSGT01;");
	Direction("AGP_Script.Dir_StartSound", "asndSGT02;;SLOT_Talk;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "asndSGT02;");
	Direction("AGP_Script.Dir_StartSound", "asndSGT03;;SLOT_Talk;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "asndSGT03;");
	Direction("AGP_Script.Dir_StartSound", "asndSGT04;;SLOT_Talk;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "asndSGT04;");
	Direction("AGP_Script.Dir_StartSound", "asndSGT05;;SLOT_Talk;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "asndSGT05;");
	Direction("AGP_Script.Dir_StartSound", "asndSGT06;;SLOT_Talk;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "asndSGT06;");
	Direction("AGP_Script.Dir_StartSound", "asndSGT07;;SLOT_Talk;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "asndSGT07;");
	Direction("AGP_Script.Dir_StartSound", "asndSGT08;;SLOT_Talk;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "asndSGT08;");
	Direction("AGP_Script.Dir_SceneJump", "PaceCount;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("PaceCount");
	SceneInit_Start();
	Direction("AGP_Script.Dir_StartTimer", "atmrIntroFade;2.0;", "");
	Direction("AGP_Script.Dir_ControlAnimation", "animInstructor;PlayAnim;DrillHandsTransitionBack;1.0;0.25;;;", "");
	Direction("AGP_Script.Dir_ControlAnimation", "animInstructor;LoopAnim;DrillIdle;1.0;;;;", "");
	Direction("AGP_Script.Dir_PlayerLockMovement", "false;false;", "");
	Direction("AGP_Script.Dir_StartTimer", "atmrPaceCount;120.0;", "");
	Direction("AGP_Script.Dir_SetClock", "120.0;true;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChanges", "atrigStart;true;");
	Direction("AGP_Script.Dir_SceneJump", "Begin;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChangesB", "atrigBoundary;false;");
	Direction("AGP_Script.Dir_SceneJump", "OutOfBounds;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "atmrPaceCount;");
	Direction("AGP_Script.Dir_SceneJump", "Begin;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "atmrIntroFade;");
	Direction("AGP_Script.Dir_PlayTip", "To bypass Pace Count, move past;the end of the Pace Line;5;;;;;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("Begin");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_Fade", "false;true;1.0", "");
	Direction("AGP_Script.Dir_StartTimer", "atmrIntroFade;1.0;", "");
	Direction("AGP_Script.Dir_StopClock", "", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "atmrIntroFade;");
	Direction("AGP_Script.Dir_StartSound", "asndSGT10;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_SetPlayerLocation", "alocStart;", "");
	Direction("AGP_Script.Dir_SetClock", "0.0;false", "");
	Direction("AGP_Script.Dir_Fade", "true;true;1.0", "");
	Direction("AGP_Script.Dir_StartTimer", "atmrIntroFade2;1.0;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "atmrIntroFade2;");
	Direction("AGP_Script.Dir_PlayerLockMovement", "false;false;", "");
	Direction("AGP_Script.Dir_SceneJump", "Objectives;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("OutOfBounds");
	SceneInit_Start();
	Direction("AGP_Script.Dir_StartSound", "asndSGT11;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_Fade", "false;true;3.0", "");
	Direction("AGP_Script.Dir_StartTimer", "atmrIntroFade;3.0;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "atmrIntroFade;");
	Direction("AGP_Script.Dir_SetPlayerLocation", "locPlayerStart;", "");
	Direction("AGP_Script.Dir_Fade", "true;true;1.0", "");
	Direction("AGP_Script.Dir_SceneJump", "PaceCount;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("Objectives");
	SceneInit_Start();
	Direction("AGP_Script.Dir_EnableObjective", "Objective1;true;", "");
	Direction("AGP_Script.Dir_StartTimer", "atmrCourse;900;", "");
	Direction("AGP_Script.Dir_SetClockUp", "0.0;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenAGPObjectiveComplete", "Objective1;");
	Direction("AGP_Script.Dir_PlayTip", "Objective A Completed;;3;;;;;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective2;true;", "");
	Direction("AGP_Script.Dir_SetLandNavScore", "scmScore;1;", "");
	Direction("AGP_Script.Dir_TriggerActive", "atrigObj1;false;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenAGPObjectiveComplete", "Objective2;");
	Direction("AGP_Script.Dir_PlayTip", "Objective B Completed;;3;;;;;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective3;true;", "");
	Direction("AGP_Script.Dir_SetLandNavScore", "scmScore;2;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenAGPObjectiveComplete", "Objective3;");
	Direction("AGP_Script.Dir_PlayTip", "Objective C Completed;;3;;;;;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective4;true;", "");
	Direction("AGP_Script.Dir_SetLandNavScore", "scmScore;3;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenAGPObjectiveComplete", "Objective4;");
	Direction("AGP_Script.Dir_PlayTip", "Objective D Completed;;3;;;;;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective5;true;", "");
	Direction("AGP_Script.Dir_SetLandNavScore", "scmScore;4;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenAGPObjectiveComplete", "Objective5;");
	Direction("AGP_Script.Dir_PlayTip", "Objective E Completed;;3;;;;;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective6;true;", "");
	Direction("AGP_Script.Dir_SetLandNavScore", "scmScore;5;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenAGPObjectiveComplete", "Objective6;");
	Direction("AGP_Script.Dir_PlayTip", "Objective F Completed;;3;;;;;", "");
	Direction("AGP_Script.Dir_TriggerActive", "atrigFinish;true;", "");
	Direction("AGP_Script.Dir_EnableObjective", "Objective0;true;", "");
	Direction("AGP_Script.Dir_SetLandNavScore", "scmScore;6;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "atmrCourse;");
	Direction("AGP_Script.Dir_SceneJump", "Failed;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChanges", "atrigFinish;true;");
	Direction("AGP_Script.Dir_EnableObjective", "Objective0;false;", "");
	Direction("AGP_Script.Dir_SetLandNavScore", "scmScore;7;", "");
	Direction("AGP_Script.Dir_SceneJump", "Succeeded;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChangesB", "atrigObj1;true;");
	Direction("AGP_Script.Dir_PlayTip", "Press and hold the <0> key to activate objective;;5;action;;;;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("Succeeded");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayTip", "Course Completed.;Congratulations, Cadet!;3;;;;;", "");
	Direction("AGP_Script.Dir_StartTimer", "atmrIntroFade;3;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "atmrIntroFade;");
	Direction("AGP_Script.Dir_DisplayLandNavScore", "scmScore;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("failed");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayTip", "Time Expired!;;30;;;;;", "");
	Direction("AGP_Script.Dir_StopClock", "", "");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_StartTimer", "atmrIntroFade;1.0;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "atmrIntroFade;");
	Direction("AGP_Script.Dir_Fade", "false;true;1.0", "");
	Direction("AGP_Script.Dir_StartTimer", "atmrIntroFade2;1.0;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "atmrIntroFade2;");
	Direction("AGP_Script.Dir_SetPlayerLocation", "locPlayerStart;", "");
	Direction("AGP_Script.Dir_SetClock", "0.0;false", "");
	Direction("AGP_Script.Dir_Fade", "true;true;1.0", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
}
