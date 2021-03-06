// All the original content belonged to the US Army

#include "AA29/Object/Actor/Screenplay/TestScreenplay/TestScreenplay.h"

ATestScreenplay::ATestScreenplay()
{

}

void ATestScreenplay::Init()
{
	NewScene("anim1");
	SceneInit_Start();
	Direction("AGP_Script.Dir_ControlAnimation", "animInstructor;LoopAnim;DrillIdle;1.0;;;-1;","");
	SceneInit_Finish();
	EndScene();
	NewScene("Stop");
	SceneInit_Start();
	Direction("AGP_Script.Dir_ClearAnimation", "animInstructor;", "");
	Direction("AGP_Script.Dir_ControlAnimation", "animInstructor;TweenAnim;DrillTalkHands;1.0;0.5;;;", "");
	Direction("AGP_Script.Dir_ControlAnimation", "animInstructor;LoopAnim;DrillTalkHands;1.0;;;3;", "");
	Direction("AGP_Script.Dir_ControlAnimation", "animInstructor;TweenAnim;DrillIdle;1.0;0.5;;;", "");
	Direction("AGP_Script.Dir_ControlAnimation", "animInstructor;LoopAnim;DrillIdle;1.0;;;-1;", "");
	SceneInit_Finish();
	EndScene();
}
