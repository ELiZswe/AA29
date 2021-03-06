// All the original content belonged to the US Army

#include "AA29/Object/Actor/Screenplay/SniperRangeScreenplay/SniperRangeScreenplay.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

ASniperRangeScreenplay::ASniperRangeScreenplay()
{

}

void ASniperRangeScreenplay::Init()
{
	bool fUserNotQualified = false;
	/*
	if (_HumanController != nullptr)
	{
		Cast<AHumanController>(_HumanController).LoadJacket();
		Log("Jacket loaded, checking score: " + FString::FromInt(_HumanController.iRifleRangeRating));
		if (_HumanController.iRifleRangeRating < 36)
		{
			fUserNotQualified = true;
		}
		else
		{
			fUserNotQualified = false;
		}
	}
	*/
	SetGlobalEvents();
	NewEvent();
	Condition("AGP_Script.Cond_WhenFriendlyFire", "");
	Direction("AGP_Script.Dir_SceneJump", "GotoJail;","");
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
	NewScene("Init");
	SceneInit_Start();
	Direction("AGP_Script.Dir_SetNoCheats", "", "");
	Direction("AGP_Script.Dir_SetPlayerLocation", "locStart;", "");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_Fade", "true;true;3.0;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;3.0;", "");
	Direction("AGP_Script.Dir_SetClock", "0.0;false;", "");
	Direction("AGP_Script.Dir_SetPlayerInventory", "invStart;", "");
	Direction("AGP_Script.Dir_ControlThrowWeapon", "true;", "");
	SceneInit_Finish();
	if (fUserNotQualified)
	{
		NewEvent();
		Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
		Direction("AGP_Script.Dir_PlayTip", "You are not qualified for the M-24 Rifle Course at;Army Advanced Marksmanship School     Fort Benning, GA;7.0;;;;;", "");
		Direction("AGP_Script.Dir_StartSound", "sndFail;;SLOT_Talk;", "");
		EndEvent();
		NewEvent();
		Condition("AGP_Script.Cond_WhenSoundEnds", "sndFail;");
		Direction("AGP_Script.Dir_RunConsoleCommand", "disconnect;", "");
		EndEvent();
		SceneEnd_Start();
		SceneEnd_Finish();
		EndScene();
		return;
	}
	else
	{
		NewEvent();
		Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
		Direction("AGP_Script.Dir_PlayTip", "M-24 Rifle Course;Army Advanced Marksmanship School     Fort Benning, GA;7.0;;;;;", "");
		Direction("AGP_Script.Dir_StartSound", "sndIntro;;SLOT_Talk;", "");
		EndEvent();
	}
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "sndIntro;");
	Direction("AGP_Script.Dir_SceneJump", "ScopeTraining;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("ScopeTraining");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "false;false;", "");
	Direction("AGP_Script.Dir_StartSound", "sndPracticeFiring;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_SetPlayerInventory", "invGun;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "sndPracticeFiring;");
	Direction("AGP_Script.Dir_StartSound", "sndScope;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_PlayTip", "Expend all ammunition or leave the area to start test.;;7.0;;;;;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "sndScope;");
	Direction("AGP_Script.Dir_PlayTip", "Practice target acquisition.;Press <0> or <1> to zoom.;7.0;Zoom;AltFire;;;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;5.0;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_SceneJump", "SupportTraining;", "");
	EndEvent();
	NewEvent();
	Event_ConditionsOr();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChanges", "trigPractice;false;");
	Condition("AGP_Script.Cond_WhenPlayerOutOfAmmo", "false;");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_SceneJump", "GoToTest;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("SupportTraining");
	SceneInit_Start();
	Direction("AGP_Script.Dir_StartSound", "sndSupport;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_PlayTip", "Press <0> to go prone.;When prone, press <1> to support.;7.0;Crawling;SupportedFire;;;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "sndSupport;");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;5.0;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_SceneJump", "PracticeFiring;,""", "");
	EndEvent();
	NewEvent();
	Event_ConditionsOr();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChanges", "trigPractice;false;");
	Condition("AGP_Script.Cond_WhenPlayerOutOfAmmo", "false;");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_SceneJump", "GoToTest;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("PracticeFiring");
	SceneInit_Start();
	Direction("AGP_Script.Dir_StartTimer", "Timer1;90.0;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_StartSound", "sndHurry;;SLOT_Talk", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer2;90.0;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer2;");
	Direction("AGP_Script.Dir_StartSound", "sndHurry2;;SLOT_Talk", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer2;90.0;", "");
	EndEvent();
	NewEvent();
	Event_ConditionsOr();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChanges", "trigPractice;false;");
	Condition("AGP_Script.Cond_WhenPlayerOutOfAmmo", "false;");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_SceneJump", "GoToTest;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("GoToTest");
	SceneInit_Start();
	Direction("AGP_Script.Dir_StartSound", "sndGoToTest;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_PlayTip", "Time for your test.;;5.0;;;;;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "sndGoToTest;");
	Direction("AGP_Script.Dir_SceneJump", "Test;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("Test");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;false;", "");
	Direction("AGP_Script.Dir_Fade", "false;true;3.0;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;3.0;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_SetPlayerLocation", "locTest;", "");
	Direction("AGP_Script.Dir_Fade", "true;true;3.0;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer2;3.0;", "");
	Direction("AGP_Script.Dir_SetPlayerInventory", "invStart;", "");
	Direction("AGP_Script.Dir_SetPlayerInventory", "invGun;", "");
	Direction("AGP_Script.Dir_Trigger", "SniperTargetFinal;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer2;");
	Direction("AGP_Script.Dir_PlayerLockMovement", "false;false;", "");
	Direction("AGP_Script.Dir_SceneJump", "DoTest;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("DoTest");
	SceneInit_Start();
	Direction("AGP_Script.Dir_Log", "SCENE DOTEST", "");
	Direction("AGP_Script.Dir_StartSound", "sndTest;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_PlayTip", "Engage the white silhouette downrange.;You have one shot.;5.0;;;;;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenSoundEnds", "sndTest;");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;90.0;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_StartSound", "sndHurry3;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;90.0;", "");
	EndEvent();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer2;");
	Direction("AGP_Script.Dir_StartSound", "sndHurry4;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer2;90.0;", "");
	EndEvent();
	NewEvent();
	Event_ConditionsOr();
	Condition("AGP_Script.Cond_WhenPlayerTriggerChanges", "trigTest;false;");
	Condition("AGP_Script.Cond_WhenFire", "");
	Direction("AGP_Script.Dir_SceneJump", "Evaluate;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("Evaluate");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;true;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;0.3;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_SetPlayerInventory", "invStart;", "");
	Direction("AGP_Script.Dir_SceneJump", "EvaluateTwo;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("EvaluateTwo");
	SceneInit_Start();
	Direction("AGP_Script.Dir_JumpOnIntVar", "ivScore;1;1000;Success;", "");
	Direction("AGP_Script.Dir_JumpOnIntVar", "ivScore;0;0;Failure;", "");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("success");
	SceneInit_Start();
	Direction("AGP_Script.Dir_StartSound", "sndSuccess;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_DisplayMissionSuccess", "T_AA2_UI.tour_icons.hud_menu_touricon_sniper_school;Congratulations, training complete!;;128;128;6;FailureReset;", "");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("Failure");
	SceneInit_Start();
	Direction("AGP_Script.Dir_StartSound", "sndFail;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_DisplayMissionFailure", "T_AA2_UI.tour_icons.hud_menu_touricon_sniper_school;You have failed to qualify.;;128;128;6;FailureReset;", "");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("FailureReset");
	SceneInit_Start();
	Direction("AGP_Script.Dir_RunConsoleCommand", "reconnect;", "");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("GotoJail");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;true;", "");
	Direction("AGP_Script.Dir_Fade", "false;true;2.0;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;2.0;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_PlayerLockMovement", "false;false;", "");
	Direction("AGP_Script.Dir_RunConsoleCommand", "start Leavenworth.aao;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("PlayerCheated");
	SceneInit_Start();
	Direction("AGP_Script.Dir_StartSound", "sndFail;;SLOT_Talk;", "");
	Direction("AGP_Script.Dir_DisplayMissionFailure", "T_AA2_UI.tour_icons.hud_menu_touricon_sniper_school;You cheated!;;128;128;6;FailureReset;", "");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("SafetyViolation");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;true;", "");
	Direction("AGP_Script.Dir_PlayTip", "Safety violation.;Come back when you're paying attention.;4.0;;;;;", "");
	Direction("AGP_Script.Dir_StartTimer", "Timer1;4.0;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "Timer1;");
	Direction("AGP_Script.Dir_SceneJump", "FailureReset;", "");
	EndEvent();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
}

