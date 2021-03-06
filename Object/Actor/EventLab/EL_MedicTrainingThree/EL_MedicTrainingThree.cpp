// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MedicTrainingThree/EL_MedicTrainingThree.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/AGP_UseTrigger/DoorTrigger/DoorTrigger.h"
#include "AA29/Object/Actor/MedExam/MedExam.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedInstructor/NPC_MedInstructor.h"
#include "AA29/Object/Actor/Info/Security/Security.h"
#include "AA29/Object/Actor/Projector/SlideProjector/SlideProjector.h"
#include "AA29/Object/Actor/AGP_UseTrigger/StaticMeshSwitcher/StaticMeshSwitcher.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"

AEL_MedicTrainingThree::AEL_MedicTrainingThree()
{
	LSAnims = {
		FLSAnim({ "00_Intro",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Instruction/00_Intro_Cue.00_Intro_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "01_ShockMayBeCaused",	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Instruction/01_ShockMayBeCaused_Cue.01_ShockMayBeCaused_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "02_SignsAndSymptoms",	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Instruction/02_SignsAndSymptoms_Cue.02_SignsAndSymptoms_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "03_ToTreatShock",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Instruction/03_ToTreatShock_Cue.03_ToTreatShock_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "04_LosenClothing",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Instruction/04_LosenClothing_Cue.04_LosenClothing_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "05_Chilling",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Instruction/05_Chilling_Cue.05_Chilling_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "06_Measures",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Instruction/06_Measures_Cue.06_Measures_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "07_MedicalAid",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Instruction/07_MedicalAid_Cue.07_MedicalAid_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_GetDown",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_GetDown_Cue.C3_GetDown_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_GetStarted",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_GetStarted_Cue.C3_GetStarted_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_GoodJob",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_GoodJob_Cue.C3_GoodJob_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_JustPathetic",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_JustPathetic_Cue.C3_JustPathetic_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_KeepEyes",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_KeepEyes_Cue.C3_KeepEyes_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_LastWarning",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_LastWarning_Cue.C3_LastWarning_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_NotAGame",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_NotAGame_Cue.C3_NotAGame_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_NotSoGreat",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_NotSoGreat_Cue.C3_NotSoGreat_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_ShockConclude",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_ShockConclude_Cue.C3_ShockConclude_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_SitDown",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_SitDown_Cue.C3_SitDown_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_StartTest",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_StartTest_Cue.C3_StartTest_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_StepOutside",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_StepOutside_Cue.C3_StepOutside_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_TakeASeat",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_TakeASeat_Cue.C3_TakeASeat_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_TakeSeats",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_TakeSeats_Cue.C3_TakeSeats_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_Welcome",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_Welcome_Cue.C3_Welcome_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_WillGetStarted",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_WillGetStarted_Cue.C3_WillGetStarted_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } }),
		FLSAnim({ "C3_YouJustMadeIt",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassThree_Misc/C3_YouJustMadeIt_Cue.C3_YouJustMadeIt_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" } , {0,0,0,0,0,0,0,0,0,0 } })
	};
}

/*
State EnterClass
{
	Function bool ClassVolumeThree_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		UnCaptureEvent(ClassVolumeThree);
		PlayLSAnim("C3_Welcome",InstructorThree,1,512);
		PlayTip("Talk to people in your class by pressing","the <action> key while facing somebody",5);
		if (DoorTriggerThree.IsOpen())
		{
			DoorTriggerThree.ToggleOpen();
		}
		DoorTriggerThree.SetLocked(true);
		ChangeState("inClass");
		return true;
	}
}
*/

/*
State inClass
{
	Function BeginState()
	{
		StartTimer("tmrBeginClass",60,false);
	}
	Function EndState()
	{
	}
	Function bool InstructorTriggerThree_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (InstructorUseCount == 0)
		{
			PlayLSAnim("C3_WillGetStarted",InstructorThree,1,512);
			InstructorUseCount ++;
			return true;
		}
		if (InstructorUseCount <= 2)
		{
			PlayLSAnim("C3_TakeASeat",InstructorThree,1,512);
			InstructorUseCount ++;
			return true;
		}
		return true;
	}
	Function bool SeatTriggerThree_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		UnCaptureEvent(SeatTriggerThree);
		StartTimer("tmrSatDown",5,false);
		PlayTip("To get out of the chair, press the <jump> key","",5);
		return true;
	}
	Function bool SeatVolumeThree_Trigger(AGP_Gameplay.AGP_Trigger* Trigger, AActor* Instigator)
	{
		UnCaptureEvent(SeatVolumeThree);
		ReCaptureEvent(Controller);
		PlayTip("To enter your chair, face it and press the <action> key","",5);
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "tmrBeginClass") || (Name == "tmrSatDown"))
		{
			StopTimer("tmrBeginClass",0);
			StopTimer("tmrSatDown",0);
			ChangeState("LetsGetStarted");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State LetsGetStarted
{
	Function BeginState()
	{
		PlayLSAnim("C3_GetStarted",InstructorThree,1,512);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "C3_GetStarted")
		{
			ChangeState("TimeToSit");
			return true;
		}
		return false;
	}
}
*/

/*
State TimeToSit
{
	Function BeginState()
	{
		ReCaptureEvent(SeatTriggerThree);
		StartTimer("tmrSitDown",5,false);
		StartTimer("TimeToSit_Start",0.01,false);
	}
	Function bool SeatTriggerThree_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		ChangeState("BeginLecture");
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "TimeToSit_Start")
		{
			if (Cast<AStudentController>(Controller)->IsSeated())
			{
				ChangeState("BeginLecture");
			}
			return true;
		}
		if (Name == "tmrSitDown")
		{
			PlayLSAnim("C3_TakeSeats",InstructorThree,1,512);
			StartTimer("tmrSitDown2",5,false);
			return true;
		}
		if (Name == "tmrSitDown2")
		{
			PlayLSAnim("C3_TakeASeat",InstructorThree,1,512);
			StartTimer("tmrSitDown3",10,false);
			return true;
		}
		if (Name == "tmrSitDown3")
		{
			PlayLSAnim("C3_SitDown",InstructorThree,1,512);
			StartTimer("tmrSitDown4",5,false);
			return true;
		}
		if (Name == "tmrSitDown4")
		{
			ChangeState("Busted");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State Lecture
{
	Function BeginState()
	{
		ReCaptureEvent(Controller);
		BeginSlide();
	}
	Function BeginSlide()
	{
	}
	Function bool SeatTriggerThree_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		StopTimer("tmrOutOfChair",0);
		ReCaptureEvent(Controller);
		return true;
	}
	Function bool StudentController_Custom(AStudentController* SC, AActor* Instigator, FString Parms)
	{
		if (Parms == "EXITCHAIR")
		{
			UnCaptureEvent(Controller);
			StartTimer("tmrOutOfChair",1,false);
			return true;
		}
		if (Parms == "CHEATING")
		{
			return true;
		}
		return false;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrOutOfChair")
		{
			ChangeState(RecallState(1));
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State BeginLecture extends Lecture
{
	Function BeginSlide()
	{
		StartTimer("tmrBeginLecture",0.01,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrBeginLecture")
		{
			if (Cast<AStudentController>(Controller)->SkipSlides())
			{
				ChangeState("LectureConcluded");
				return true;
			}
			else
			{
				ChangeState("Slide00");
				return true;
			}
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Slide00 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorThree.SetCurrentMaterial(0);
		StartTimer("Slide00_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide00_Start")
		{
			PlayLSAnim("00_Intro",InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "00_Intro")
		{
			ChangeState("Slide01");
			return true;
		}
	}
}
*/

/*
State Slide01 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorThree.SetCurrentMaterial(1);
		StartTimer("Slide01_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide01_Start")
		{
			PlayLSAnim("01_ShockMayBeCaused",InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "01_ShockMayBeCaused")
		{
			ChangeState("Slide02");
			return true;
		}
	}
}
*/

/*
State Slide02 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorThree.SetCurrentMaterial(2);
		StartTimer("Slide02_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide02_Start")
		{
			PlayLSAnim("02_SignsAndSymptoms",InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "02_SignsAndSymptoms")
		{
			ChangeState("Slide03");
			return true;
		}
	}
}
*/

/*
State Slide03 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorThree.SetCurrentMaterial(3);
		StartTimer("Slide03_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide03_Start")
		{
			PlayLSAnim("03_ToTreatShock",InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "03_ToTreatShock")
		{
			ChangeState("Slide04");
			return true;
		}
	}
}
*/

/*
State Slide04 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorThree.SetCurrentMaterial(4);
		StartTimer("Slide04_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide04_Start")
		{
			PlayLSAnim("04_LosenClothing",InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "04_LosenClothing")
		{
			ChangeState("Slide05");
			return true;
		}
	}
}
*/

/*
State Slide05 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorThree.SetCurrentMaterial(5);
		StartTimer("Slide05_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide05_Start")
		{
			PlayLSAnim("05_Chilling",InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "05_Chilling")
		{
			ChangeState("Slide06");
			return true;
		}
	}
}
*/

/*
State Slide06 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorThree.SetCurrentMaterial(6);
		StartTimer("Slide06_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		Super::Timer_Timer(Name);
		if (Name == "Slide06_Start")
		{
			PlayLSAnim("06_Measures",InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "06_Measures")
		{
			ChangeState("Slide07");
			return true;
		}
	}
}
*/

/*
State Slide07 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorThree.SetCurrentMaterial(7);
		StartTimer("Slide07_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide07_Start")
		{
			PlayLSAnim("07_MedicalAid",InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "07_MedicalAid")
		{
			ChangeState("LectureConcluded");
			return true;
		}
	}
}
*/

/*
State LectureConcluded
{
	Function BeginState()
	{
		StartTimer("tmrConclude_Start",1,false);
		SlideProjectorThree.SetCurrentMaterial(0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrConclude_Start")
		{
			PlayLSAnim("C3_ShockConclude",InstructorThree,1,512);
			return true;
		}
		return GlobalTimer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "C3_ShockConclude")
		{
			ChangeState("BeginTest");
			return true;
		}
	}
}
*/

/*
State BeginTest
{
	Function BeginState()
	{
		ReCaptureEvent(SeatVolumeThree);
		MedExamThree.SetActive(true);
		StartTimer("BeginTest_Start",2,false);
		StartTimer("TmrTip1",4,false);
		StartTimer("TmrTip2",10,false);
		StartTimer("TmrTip3",16,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "BeginTest_Start")
		{
			PlayLSAnim("C3_StartTest",InstructorThree,1,512);
			return true;
		}
		if (Name == "TmrTip1")
		{
			PlayTip("To take your test, press the <action> key while","sitting in your chair",5);
			return true;
		}
		if (Name == "TmrTip2")
		{
			PlayTip("To turn pages in your test, use the icons at","bottom of page, or press <leanleft> and <leanright>",5);
			return true;
		}
		if (Name == "TmrTip3")
		{
			PlayTip("To mark answers, use your <fire> or","<action> buttons",5);
			ChangeState("Testing");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State Testing
{
	Function BeginState()
	{
	}
	Function bool StudentController_Custom(AStudentController* SC, AActor* Instigator, FString Parms)
	{
		if (Parms == "CHEATING")
		{
			UnCaptureEvent(Controller);
			StartTimer("CheckCheating",1.5,false);
			return true;
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "CheckCheating")
		{
			if (Cast<AStudentController>(Controller)->IsPossiblyCheating())
			{
				ChangeState("Cheating");
			}
			else
			{
				ReCaptureEvent(Controller);
			}
			return true;
		}
		return GlobalTimer(Name);
	}
	Function bool SeatVolumeThree_UnTrigger(AGP_Gameplay.AGP_Trigger* Trigger, AActor* Instigator)
	{
		PlayTip("When you are through with your test, approach","the instructor and press <action>",5);
		return true;
	}
	Function bool InstructorTriggerThree_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		Grade=int((MedExamThree.ScoreTest() * float(100)));
		MedExamThree.Destroy();
		MedExamThree=nullptr;
		if (Grade >= 80)
		{
			ChangeState("Eighty1Hundred");
			return true;
		}
		if (Grade >= 70)
		{
			ChangeState("SeventySeventyNine");
			return true;
		}
		if (Grade >= 60)
		{
			ChangeState("SixtySixtyNine");
			return true;
		}
		else
		{
			ChangeState("ZeroFiftyNine");
			return true;
		}
	}
}
*/

/*
State Eighty1Hundred
{
	Function BeginState()
	{
		PlayLSAnim("C3_GoodJob",InstructorThree,1,512);
		if (Cast<AStudentController>(Controller)->IsCheating())
		{
			PlayTip("Cheats Detected. Good job soldier,","you scored " + FString::FromInt(Grade) + "%",5);
		}
		else
		{
			PlayTip("Good job soldier,","you scored " + FString::FromInt(Grade) + "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "C3_GoodJob")
		{
			ChangeState("TestPassed");
			return true;
		}
	}
}
*/

/*
State SeventySeventyNine
{
	Function BeginState()
	{
		PlayLSAnim("C3_YouJustMadeIt",InstructorThree,1,512);
		if (Cast<AStudentController>(Controller)->IsCheating())
		{
			PlayTip("Cheats Detected. You passed with","" + FString::FromInt(Grade) + "%",5);
		}
		else
		{
			PlayTip("You passed with","" + FString::FromInt(Grade) + "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "C3_YouJustMadeIt")
		{
			ChangeState("TestPassed");
			return true;
		}
	}
}
*/

/*
State SixtySixtyNine
{
	Function BeginState()
	{
		PlayLSAnim("C3_NotSoGreat",InstructorThree,1,512);
		if (Cast<AStudentController>(Controller)->IsCheating())
		{
			PlayTip("Cheats Detected. You Failed!","You scored" + FString::FromInt(Grade) + "%",5);
		}
		else
		{
			PlayTip("You Failed!","You scored" + FString::FromInt(Grade) + "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "C3_NotSoGreat")
		{
			ChangeState("TestFailed");
			return true;
		}
	}
}
*/

/*
State ZeroFiftyNine
{
	Function BeginState()
	{
		PlayLSAnim("C3_JustPathetic",InstructorThree,1,512);
		if (Cast<AStudentController>(Controller)->IsCheating())
		{
			PlayTip("Cheats Detected. Pathetic soldier!","You scored " + FString::FromInt(Grade) + "%",5);
		}
		else
		{
			PlayTip("Pathetic soldier!","You scored " + FString::FromInt(Grade) + "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "C3_JustPathetic")
		{
			ChangeState("TestFailed");
			return true;
		}
	}
}
*/

/*
State TestPassed
{
	Function bool InstructorTriggerThree_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
	}
	Function BeginState()
	{
		StartTimer("BeginPassed",0.01);
	}
	Function UpdateCompletionFields()
	{
		ASecurity* secLocalSecurity = nullptr;
		ASecurity* scLocalSecurityClass = nullptr;
		TArray<FString> asMD5ForMap = {};
		TArray<FString> asMD5ForScript = {};
		FString sMD5ForMap = "";
		FString sMD5ForScript = "";
		scLocalSecurityClass=class<Security>(DynamicLoadObject("Engine.Security",Class'Class'));
		if (scLocalSecurityClass != nullptr)
		{
			secLocalSecurity=Spawn(scLocalSecurityClass,Controller);
			if (secLocalSecurity != nullptr)
			{
				secLocalSecurity.LocalPerform(2,"../Maps/Medic_Training3.aao","",asMD5ForMap);
				secLocalSecurity.LocalPerform(2,"../System/AGP_Script.u","",asMD5ForScript);
				sMD5ForMap=asMD5ForMap[0];
				sMD5ForScript=asMD5ForScript[0];
			}
		}
		Controller.AddAuthExtraMissionData(sMD5ForMap);
		Controller.AddAuthExtraMissionData(sMD5ForScript);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "BeginPassed")
		{
			Cast<AStudentController>(Controller)->ResetAuthExtraMissionData();
			Cast<AStudentController>(Controller)->AddAuthExtraMissionData(string(Grade));
			UpdateCompletionFields();
			if (Cast<AStudentController>(Controller)->IsCheating())
			{
				Cast<AStudentController>(Controller)->SetAuthMissionPassFlag(false);
				DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Congratulations!","Cheats detected, cannot complete.",128,128,7,"None");
			}
			else
			{
				Cast<AStudentController>(Controller)->SetAuthMissionPassFlag(true);
				DisplayMissionSuccess("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Congratulations!","You can now begin Field Training.",128,128,7,"None");
			}
			return true;
		}
		return false;
	}
}
*/

/*
State TestFailed
{
	Function BeginState()
	{
		StartTimer("BeginFailed",2);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "BeginFailed")
		{
			DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Training Failed!","",128,128,7,"None");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State Trouble
{
	Function BeginState()
	{
		BeginTrouble();
	}
	Function EndState()
	{
		EndTrouble();
	}
	Function BeginTrouble()
	{
	}
	Function EndTrouble()
	{
	}
	Function bool SeatTriggerThree_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		ChangeState(RecallState(0));
		return true;
	}
}
*/

/*
State OutOfChair1 extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim("C3_TakeASeat",InstructorThree,1,512);
		RememberState("OutOfChair2",1);
		StartTimer("Escelate",10,false);
	}
	Function EndTrouble()
	{
		StopTimer("BeginTrouble",0);
		StopTimer("Escelate",0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Escelate")
		{
			ChangeState("OutOfChair2");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State OutOfChair2 extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim("C3_SitDown",InstructorThree,1,512);
		if (LightSwitchThree.IsSwitched())
		{
			RememberState("OutOfChair3",1);
		}
		else
		{
			RememberState("Busted",1);
		}
		StartTimer("Escelate",10,false);
	}
	Function EndTrouble()
	{
		StopTimer("BeginTrouble",0);
		StopTimer("Escelate",0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Escelate")
		{
			ChangeState("OutOfChair3");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State OutOfChair3 extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim("C3_NotAGame",InstructorThree,1,512);
		RememberState("Busted",1);
		StartTimer("Escelate",15,false);
	}
	Function EndTrouble()
	{
		StopTimer("BeginTrouble",0);
		StopTimer("Escelate",0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Escelate")
		{
			ChangeState("Busted");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State Busted extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim("C3_StepOutside",InstructorThree,1,512);
		Controller.GotoState("MedicTraining_Frozen");
		FadeOut(2,true);
		PlayerLock(true,true);
		StartTimer("tmrLoadEntry",5,false);
	}
	Function EndTrouble()
	{
		StopTimer("BeginTrouble",0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrLoadEntry")
		{
			RunConsoleCommand("open entry2");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State Cheating
{
	Function BeginState()
	{
		StartTimer("tmrCheating_Start",0.01,false);
	}
	Function EndState()
	{
		ReCaptureEvent(Controller);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrCheating_Start")
		{
			LookCount ++;
			if (LookCount == 1)
			{
				PlayLSAnim("C3_KeepEyes",InstructorThree,1,512);
			}
			else
			{
				if (LookCount == 2)
				{
					PlayLSAnim("C3_LastWarning",InstructorThree,1,512);
				}
				else
				{
					ChangeState("Busted");
				}
			}
		}
		return GlobalTimer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if ((Name == "C3_KeepEyes") || (Name == "C3_LastWarning"))
		{
			ChangeState("Testing");
			return true;
		}
	}
}
*/

bool AEL_MedicTrainingThree::StaticMeshSwitcher_UsedBy(AStaticMeshSwitcher* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "LightSwitchThree":
		return LightSwitchThree_UsedBy(Trigger, aInstigator);
	default:
		return false;
	}
	*/

	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::LightSwitchThree_UsedBy(AStaticMeshSwitcher* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "SeatTriggerThree":
		return SeatTriggerThree_UsedBy(Trigger, Instigator);
	case "InstructorTriggerThree":
		return InstructorTriggerThree_UsedBy(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::SeatTriggerThree_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::AGP_Trigger_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "SeatVolumeThree":
		return SeatVolumeThree_Trigger(Trigger, Instigator);
	case "DeskVolumeThree":
		return DeskVolumeThree_Trigger(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::AGP_Trigger_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "SeatVolumeThree":
		return SeatVolumeThree_UnTrigger(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::SeatVolumeThree_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::SeatVolumeThree_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::DoorTrigger_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "DoorTriggerThree":
		return DoorTriggerThree_UsedBy(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::DoorTriggerThree_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "ClassVolumeThree":
		return ClassVolumeThree_Enter(Trigger, Instigator);
	case "LeavingVolumeThree":
		return LeavingVolumeThree_Enter(Trigger, Instigator);
	case "TestVolumeThree":
		return TestVolumeThree_Enter(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::ClassVolumeThree_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::LeavingVolumeThree_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingThree::TestVolumeThree_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

void AEL_MedicTrainingThree::PreInit()
{
	LightSwitchThree = Cast<AStaticMeshSwitcher>(CaptureEvent("LightSwitchThree", nullptr));
	DoorTriggerThree = Cast<ADoorTrigger>(CaptureEvent("DoorTriggerThree", nullptr));
	InstructorTriggerThree = Cast<AAGP_UseTrigger>(CaptureEvent("InstructorTriggerThree", nullptr));
	InstructorThree = Cast<ANPC_MedInstructor>(CaptureEvent("InstructorThree", nullptr));
	SlideProjectorThree = Cast<ASlideProjector>(CaptureEvent("SlideProjectorThree", nullptr));
	SeatTriggerThree = Cast<AAGP_UseTrigger>(CaptureEvent("SeatTriggerThree", nullptr));
	ClassVolumeThree = Cast<ATriggerVolume>(CaptureEvent("ClassVolumeThree", nullptr));
	TestVolumeThree = Cast<ATriggerVolume>(CaptureEvent("TestVolumeThree", nullptr));
	LeavingVolumeThree = Cast<ATriggerVolume>(CaptureEvent("LeavingVolumeThree", nullptr));
	SeatVolumeThree = Cast<AAGP_Trigger>(CaptureEvent("SeatVolumeThree", nullptr));
	MedExamOne = Cast<AMedExam>(CaptureEvent("MedExamOne", nullptr));
	MedExamTwo = Cast<AMedExam>(CaptureEvent("MedExamTwo", nullptr));
	MedExamThree = Cast<AMedExam>(CaptureEvent("MedExamThree", nullptr));
	CaptureEventGroup("DeskVolumeThree");
}

void AEL_MedicTrainingThree::Init()
{
}

void AEL_MedicTrainingThree::PostInit()
{
}

void AEL_MedicTrainingThree::PostPostInit()
{
	/*
	RememberState("OutOfChair1", 1);
	MedExamThree.SetActive(false);
	PlayerLock(false, false);
	DoorTriggerThree.ToggleOpen();
	ChangeState("EnterClass");
	PlayTip("When ready, report to the ", "class on 'Treating Shock'", 20);
	*/
}

bool AEL_MedicTrainingThree::DeskVolumeThree_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	/*
	UnCaptureEventGroup("DeskVolumeThree");
	StartTimer("ReCaptureDesk", 3, false);
	GoofCount++;
	if (GoofCount == 1)
	{
		PlayLSAnim("C3_GetDown", InstructorThree, 1, 512);
	}
	else
	{
		if (GoofCount == 2)
		{
			PlayLSAnim("C3_LastWarning", InstructorThree, 1, 512);
		}
		else
		{
			if (GoofCount > 2)
			{
				ChangeState("Busted");
			}
		}
	}
	*/
	return true;
}

bool AEL_MedicTrainingThree::InstructorTriggerThree_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (!bInstUseDisable)
	{
		bInstUseDisable = true;
		PlayLSAnim("C3_TakeASeat", InstructorThree, 1, 512);
		StartTimer("C3_TakeASeat", 2, false);
	}
	*/
	return true;
}

bool AEL_MedicTrainingThree::GlobalTimer(FName Name)
{
	if (Name == "ReCaptureDesk")
	{
		//CaptureEventGroup("DeskVolumeThree");
		return true;
	}
	if (Name == "TakeASeat")
	{
		bInstUseDisable = false;
		return true;
	}

	return false;
}
