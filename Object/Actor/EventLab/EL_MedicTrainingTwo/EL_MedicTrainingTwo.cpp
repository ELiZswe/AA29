// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MedicTrainingTwo/EL_MedicTrainingTwo.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/AGP_UseTrigger/DoorTrigger/DoorTrigger.h"
#include "AA29/Object/Actor/MedExam/MedExam.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedInstructor/NPC_MedInstructor.h"
#include "AA29/Object/Actor/Info/Security/Security.h"
#include "AA29/Object/Actor/Projector/SlideProjector/SlideProjector.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"

AEL_MedicTrainingTwo::AEL_MedicTrainingTwo()
{
	LSAnims = {
		FLSAnim({"01_Evaluate",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/01_Evaluate_Cue.01_Evaluate_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"02_LossOfBlood",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/02_LossOfBlood_Cue.02_LossOfBlood_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"03_ExposeWound",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/03_ExposeWound_Cue.03_ExposeWound_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"04_DressingIsPad",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/04_DressingIsPad_Cue.04_DressingIsPad_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"05_PlaceDressing",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/05_PlaceDressing_Cue.05_PlaceDressing_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"06_Tails",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/06_Tails_Cue.06_Tails_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"07_Important",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/07_Important_Cue.07_Important_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"09_HoldDressing",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/09_HoldDressing_Cue.09_HoldDressing_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"10_TieTails",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/10_TieTails_Cue.10_TieTails_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"11_TiedFirmly",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/11_TiedFirmly_Cue.11_TiedFirmly_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"12_DirectPressure",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/12_DirectPressure_Cue.12_DirectPressure_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"13_Elevate",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/13_Elevate_Cue.13_Elevate_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"14_BleedingContinues",	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/14_BleedingContinues_Cue.14_BleedingContinues_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"18_AfterDirectPressure",	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/18_AfterDirectPressure_Cue.18_AfterDirectPressure_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"19_Brachial",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/19_Brachial_Cue.19_Brachial_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"20_BleedingStops",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/20_BleedingStops_Cue.20_BleedingStops_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"21_Tourniquet",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/21_Tourniquet_Cue.21_Tourniquet_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"22_TwistStick",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/22_TwistStick_Cue.22_TwistStick_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"23_SecureStick",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/23_SecureStick_Cue.23_SecureStick_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"24_DoNotCover",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/24_DoNotCover_Cue.24_DoNotCover_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"25_MarkForeHead",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/25_MarkForeHead_Cue.25_MarkForeHead_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"27_GetHelp",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Instruction/27_GetHelp_Cue.27_GetHelp_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_BleedingConclude",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_BleedingConclude_Cue.C2_BleedingConclude_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_GetDown",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_GetDown_Cue.C2_GetDown_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_GetStarted",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_GetStarted_Cue.C2_GetStarted_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_GoodJob",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_GoodJob_Cue.C2_GoodJob_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_JustPathetic",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_JustPathetic_Cue.C2_JustPathetic_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_KeepEyes",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_KeepEyes_Cue.C2_KeepEyes_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_LastWarning",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_LastWarning_Cue.C2_LastWarning_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_NotSoGreat",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_NotSoGreat_Cue.C2_NotSoGreat_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_SitDown",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_SitDown_Cue.C2_SitDown_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_StartTest",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_StartTest_Cue.C2_StartTest_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_StepOutside",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_StepOutside_Cue.C2_StepOutside_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_TakeASeat",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_TakeASeat_Cue.C2_TakeASeat_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_TakeSeats",			LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_TakeSeats_Cue.C2_TakeSeats_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_Welcome",				LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_Welcome_Cue.C2_Welcome_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_WillGetStarted",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_WillGetStarted_Cue.C2_WillGetStarted_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"C2_YouJustMadeIt",		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/ClassTwo_Misc/C2_YouJustMadeIt_Cue.C2_YouJustMadeIt_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} })
		};

}

/*
State EnterClass
{
	Function bool ClassVolumeTwo_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		UnCaptureEvent(ClassVolumeTwo);
		PlayLSAnim("C2_Welcome",InstructorTwo,1,512);
		PlayTip("Talk to people in your class by pressing","the <action> key while facing somebody",5);
		if (DoorTriggerTwo.IsOpen())
		{
			DoorTriggerTwo.ToggleOpen();
		}
		DoorTriggerTwo.SetLocked(true);
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
	Function bool InstructorTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (InstructorUseCount == 0)
		{
			PlayLSAnim("C2_WillGetStarted",InstructorTwo,1,512);
			InstructorUseCount ++;
			return true;
		}
		if (InstructorUseCount <= 2)
		{
			PlayLSAnim("C2_TakeASeat",InstructorTwo,1,512);
			InstructorUseCount ++;
			return true;
		}
		return true;
	}
	Function bool SeatTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		UnCaptureEvent(SeatTriggerTwo);
		StartTimer("tmrSatDown",5,false);
		PlayTip("To get out of the chair, press the <jump> key","",5);
		return true;
	}
	Function bool SeatVolumeTwo_Trigger(AGP_Gameplay.AGP_Trigger* Trigger, AActor* Instigator)
	{
		UnCaptureEvent(SeatVolumeTwo);
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
		PlayLSAnim("C2_GetStarted",InstructorTwo,1,512);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "C2_GetStarted")
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
		ReCaptureEvent(SeatTriggerTwo);
		StartTimer("tmrSitDown",5,false);
		StartTimer("TimeToSit_Start",0.01,false);
	}
	Function bool SeatTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
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
			PlayLSAnim("C2_TakeSeats",InstructorTwo,1,512);
			StartTimer("tmrSitDown2",5,false);
			return true;
		}
		if (Name == "tmrSitDown2")
		{
			PlayLSAnim("C2_TakeASeat",InstructorTwo,1,512);
			StartTimer("tmrSitDown3",10,false);
			return true;
		}
		if (Name == "tmrSitDown3")
		{
			PlayLSAnim("C2_SitDown",InstructorTwo,1,512);
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
	Function bool SeatTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
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
				ChangeState("Slide01");
				return true;
			}
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Slide01 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(1);
		StartTimer("Slide01_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide01_Start")
		{
			PlayLSAnim("01_Evaluate",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "01_Evaluate")
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
		SlideProjectorTwo.SetCurrentMaterial(2);
		StartTimer("Slide02_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide02_Start")
		{
			PlayLSAnim("02_LossOfBlood",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "02_LossOfBlood")
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
		SlideProjectorTwo.SetCurrentMaterial(3);
		StartTimer("Slide03_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide03_Start")
		{
			PlayLSAnim("03_ExposeWound",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "03_ExposeWound")
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
		SlideProjectorTwo.SetCurrentMaterial(4);
		StartTimer("Slide04_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide04_Start")
		{
			PlayLSAnim("04_DressingIsPad",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "04_DressingIsPad")
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
		SlideProjectorTwo.SetCurrentMaterial(5);
		StartTimer("Slide05_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide05_Start")
		{
			PlayLSAnim("05_PlaceDressing",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "05_PlaceDressing")
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
		SlideProjectorTwo.SetCurrentMaterial(6);
		StartTimer("Slide06_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		Super::Timer_Timer(Name);
		if (Name == "Slide06_Start")
		{
			PlayLSAnim("06_Tails",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "06_Tails")
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
		SlideProjectorTwo.SetCurrentMaterial(7);
		StartTimer("Slide07_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide07_Start")
		{
			PlayLSAnim("07_Important",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "07_Important")
		{
			ChangeState("Slide08");
			return true;
		}
	}
}
*/

/*
State Slide08 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(8);
		StartTimer("Slide08_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide08_Start")
		{
			ChangeState("Slide09");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Slide09 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(9);
		StartTimer("Slide09_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide09_Start")
		{
			PlayLSAnim("09_HoldDressing",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "09_HoldDressing")
		{
			ChangeState("Slide10");
			return true;
		}
	}
}
*/

/*
State Slide10 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(10);
		StartTimer("Slide10_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide10_Start")
		{
			PlayLSAnim("10_TieTails",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "10_TieTails")
		{
			ChangeState("Slide11");
			return true;
		}
	}
}
*/

/*
State Slide11 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(11);
		StartTimer("Slide11_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide11_Start")
		{
			PlayLSAnim("11_TiedFirmly",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "11_TiedFirmly")
		{
			ChangeState("Slide12");
			return true;
		}
	}
}
*/

/*
State Slide12 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(12);
		StartTimer("Slide12_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide12_Start")
		{
			PlayLSAnim("12_DirectPressure",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "12_DirectPressure")
		{
			ChangeState("Slide13");
			return true;
		}
	}
}
*/

/*
State Slide13 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(13);
		StartTimer("Slide13_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide13_Start")
		{
			PlayLSAnim("13_Elevate",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "13_Elevate")
		{
			ChangeState("Slide14");
			return true;
		}
	}
}
*/

/*
State Slide14 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(14);
		StartTimer("Slide14_Start",2,false);
		StartTimer("Slide14_End",36,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide14_Start")
		{
			PlayLSAnim("14_BleedingContinues",InstructorTwo,1,512);
			return true;
		}
		if (Name == "Slide14_End")
		{
			ChangeState("Slide15");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Slide15 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(15);
		StartTimer("Slide15_End",6,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide15_End")
		{
			ChangeState("Slide16");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Slide16 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(16);
		StartTimer("Slide16_End",14,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide16_End")
		{
			ChangeState("Slide17");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Slide17 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(17);
		StartTimer("Slide17_Start",12,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide17_Start")
		{
			ChangeState("Slide18");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Slide18 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(18);
		StartTimer("Slide18_Start",1,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide18_Start")
		{
			PlayLSAnim("18_AfterDirectPressure",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "18_AfterDirectPressure")
		{
			ChangeState("Slide19");
			return true;
		}
	}
}
*/

/*
State Slide19 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(19);
		StartTimer("Slide19_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide19_Start")
		{
			PlayLSAnim("19_Brachial",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "19_Brachial")
		{
			ChangeState("Slide20");
			return true;
		}
	}
}
*/

/*
State Slide20 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(20);
		StartTimer("Slide20_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide20_Start")
		{
			PlayLSAnim("20_BleedingStops",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "20_BleedingStops")
		{
			ChangeState("Slide21");
			return true;
		}
	}
}
*/

/*
State Slide21 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(21);
		StartTimer("Slide21_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide21_Start")
		{
			PlayLSAnim("21_Tourniquet",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "21_Tourniquet")
		{
			ChangeState("Slide22");
			return true;
		}
	}
}
*/

/*
State Slide22 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(22);
		StartTimer("Slide22_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide22_Start")
		{
			PlayLSAnim("22_TwistStick",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "22_TwistStick")
		{
			ChangeState("Slide23");
			return true;
		}
	}
}
*/

/*
State Slide23 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(23);
		StartTimer("Slide23_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide23_Start")
		{
			PlayLSAnim("23_SecureStick",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "23_SecureStick")
		{
			ChangeState("Slide24");
			return true;
		}
	}
}
*/

/*
State Slide24 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(24);
		StartTimer("Slide24_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide24_Start")
		{
			PlayLSAnim("24_DoNotCover",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "24_DoNotCover")
		{
			ChangeState("Slide25");
			return true;
		}
	}
}
*/

/*
State Slide25 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(25);
		StartTimer("Slide25_Start",2,false);
		StartTimer("Slide25_End",4,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide25_Start")
		{
			PlayLSAnim("25_MarkForeHead",InstructorTwo,1,512);
			return true;
		}
		if (Name == "Slide25_End")
		{
			ChangeState("Slide26");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Slide26 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(26);
		StartTimer("Slide26_End",4,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide26_End")
		{
			ChangeState("Slide27");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Slide27 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorTwo.SetCurrentMaterial(27);
		StartTimer("Slide27_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Slide27_Start")
		{
			PlayLSAnim("27_GetHelp",InstructorTwo,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "27_GetHelp")
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
		SlideProjectorTwo.SetCurrentMaterial(0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrConclude_Start")
		{
			PlayLSAnim("C2_BleedingConclude",InstructorTwo,1,512);
			return true;
		}
		return GlobalTimer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "C2_BleedingConclude")
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
		ReCaptureEvent(SeatVolumeTwo);
		MedExamTwo.SetActive(true);
		StartTimer("BeginTest_Start",2,false);
		StartTimer("TmrTip1",4,false);
		StartTimer("TmrTip2",10,false);
		StartTimer("TmrTip3",16,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "BeginTest_Start")
		{
			PlayLSAnim("C2_StartTest",InstructorTwo,1,512);
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
	Function bool SeatVolumeTwo_UnTrigger(AGP_Gameplay.AGP_Trigger* Trigger, AActor* Instigator)
	{
		PlayTip("When you are through with your test, approach","the instructor and press <action>",5);
		return true;
	}
	Function bool InstructorTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		Grade=int((MedExamTwo.ScoreTest() * float(100)));
		MedExamTwo.Destroy();
		MedExamTwo=nullptr;
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
		PlayLSAnim("C2_GoodJob",InstructorTwo,1,512);
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
		if (Name == "C2_GoodJob")
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
		PlayLSAnim("C2_YouJustMadeIt",InstructorTwo,1,512);
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
		if (Name == "C2_YouJustMadeIt")
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
		PlayLSAnim("C2_NotSoGreat",InstructorTwo,1,512);
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
		if (Name == "C2_NotSoGreat")
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
		PlayLSAnim("C2_JustPathetic",InstructorTwo,1,512);
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
		if (Name == "C2_JustPathetic")
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
	Function bool InstructorTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
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
				secLocalSecurity.LocalPerform(2,"../Maps/Medic_Training2.aao","",asMD5ForMap);
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
				DisplayMissionSuccess("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Congratulations! You can now","move on to Treating Shock.",128,128,7,"None");
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
		StartTimer("BeginFailed",2,false);
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
	Function bool SeatTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
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
		PlayLSAnim("C2_TakeASeat",InstructorTwo,1,512);
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
		PlayLSAnim("C2_SitDown",InstructorTwo,1,512);
		RememberState("Busted",1);
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
		PlayLSAnim("C2_StepOutside",InstructorTwo,1,512);
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
				PlayLSAnim("C2_KeepEyes",InstructorTwo,1,512);
			}
			else
			{
				if (LookCount == 2)
				{
					PlayLSAnim("C2_LastWarning",InstructorTwo,1,512);
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
		if ((Name == "C2_KeepEyes") || (Name == "C2_LastWarning"))
		{
			ChangeState("Testing");
			return true;
		}
	}
}
*/

static const int32 CM_SLIDE28 = 28;
static const int32 CM_SLIDE27 = 27;
static const int32 CM_SLIDE26 = 26;
static const int32 CM_SLIDE25 = 25;
static const int32 CM_SLIDE24 = 24;
static const int32 CM_SLIDE23 = 23;
static const int32 CM_SLIDE22 = 22;
static const int32 CM_SLIDE21 = 21;
static const int32 CM_SLIDE20 = 20;
static const int32 CM_SLIDE19 = 19;
static const int32 CM_SLIDE18 = 18;
static const int32 CM_SLIDE17 = 17;
static const int32 CM_SLIDE16 = 16;
static const int32 CM_SLIDE15 = 15;
static const int32 CM_SLIDE14 = 14;
static const int32 CM_SLIDE13 = 13;
static const int32 CM_SLIDE12 = 12;
static const int32 CM_SLIDE11 = 11;
static const int32 CM_SLIDE10 = 10;
static const int32 CM_SLIDE09 = 9;
static const int32 CM_SLIDE08 = 8;
static const int32 CM_SLIDE07 = 7;
static const int32 CM_SLIDE06 = 6;
static const int32 CM_SLIDE05 = 5;
static const int32 CM_SLIDE04 = 4;
static const int32 CM_SLIDE03 = 3;
static const int32 CM_SLIDE02 = 2;
static const int32 CM_SLIDE01 = 1;
static const int32 CM_SLIDE00 = 0;
static const int32 RS_OUTOFCHAIR = 1;
static const int32 RS_SLIDES = 0;

bool AEL_MedicTrainingTwo::AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "SeatTriggerTwo":
		return SeatTriggerTwo_UsedBy(Trigger, Instigator);
	case "InstructorTriggerTwo":
		return InstructorTriggerTwo_UsedBy(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingTwo::SeatTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingTwo::AGP_Trigger_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "SeatVolumeTwo":
		return SeatVolumeTwo_Trigger(Trigger, Instigator);
	case "DeskVolumeTwo":
		return DeskVolumeTwo_Trigger(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingTwo::AGP_Trigger_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "SeatVolumeTwo":
		return SeatVolumeTwo_UnTrigger(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingTwo::SeatVolumeTwo_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingTwo::SeatVolumeTwo_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingTwo::DoorTrigger_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "DoorTriggerTwo":
		return DoorTriggerTwo_UsedBy(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingTwo::DoorTriggerTwo_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingTwo::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "ClassVolumeTwo":
		return ClassVolumeTwo_Enter(Trigger, Instigator);
	case "LeavingVolumeTwo":
		return LeavingVolumeTwo_Enter(Trigger, Instigator);
	case "TestVolumeTwo":
		return TestVolumeTwo_Enter(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingTwo::ClassVolumeTwo_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingTwo::LeavingVolumeTwo_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_MedicTrainingTwo::TestVolumeTwo_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

void AEL_MedicTrainingTwo::PreInit()
{
	/*
	DoorTriggerTwo = Cast<ADoorTrigger>(CaptureEvent("DoorTriggerTwo"));
	InstructorTriggerTwo = Cast<AAGP_UseTrigger>(CaptureEvent("InstructorTriggerTwo"));
	InstructorTwo = Cast<ANPC_MedInstructor>(CaptureEvent("InstructorTwo"));
	SlideProjectorTwo = Cast<ASlideProjector>(CaptureEvent("SlideProjectorTwo"));
	SeatTriggerTwo = Cast<AAGP_UseTrigger>(CaptureEvent("SeatTriggerTwo"));
	ClassVolumeTwo = Cast<ATriggerVolume>(CaptureEvent("ClassVolumeTwo"));
	TestVolumeTwo = Cast<ATriggerVolume>(CaptureEvent("TestVolumeTwo"));
	LeavingVolumeTwo = Cast<ATriggerVolume>(CaptureEvent("LeavingVolumeTwo"));
	SeatVolumeTwo = Cast<AAGP_Trigger>(CaptureEvent("SeatVolumeTwo"));
	MedExamTwo = Cast<AMedExam>(CaptureEvent("MedExamTwo"));
	CaptureEventGroup("DeskVolumeTwo");
	*/
}

void AEL_MedicTrainingTwo::Init()
{
}

void AEL_MedicTrainingTwo::PostInit()
{
}

void AEL_MedicTrainingTwo::PostPostInit()
{
	/*
	RememberState("OutOfChair1", 1);
	MedExamTwo.SetActive(false);
	PlayerLock(false, false);
	DoorTriggerTwo.ToggleOpen();
	ChangeState("EnterClass");
	PlayTip("When ready, report to the", "class on 'Controlling Bleeding'", 20);
	*/
}

bool AEL_MedicTrainingTwo::DeskVolumeTwo_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	/*
	UnCaptureEventGroup("DeskVolumeTwo");
	StartTimer("ReCaptureDesk", 3, false);
	GoofCount++;
	if (GoofCount == 1)
	{
		PlayLSAnim("C2_GetDown", InstructorTwo, 1, 512);
	}
	else
	{
		if (GoofCount == 2)
		{
			PlayLSAnim("C2_LastWarning", InstructorTwo, 1, 512);
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

bool AEL_MedicTrainingTwo::InstructorTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (!bInstUseDisable)
	{
		bInstUseDisable = true;
		PlayLSAnim("C2_TakeASeat", InstructorTwo, 1, 512);
		StartTimer("C2_TakeASeat", 2, false);
	}
	*/
	return true;
}

bool AEL_MedicTrainingTwo::GlobalTimer(FName Name)
{
	/*
	if (Name == "ReCaptureDesk")
	{
		CaptureEventGroup("DeskVolumeTwo");
		return true;
	}
	if (Name == "TakeASeat")
	{
		bInstUseDisable = false;
		return true;
	}
	*/
	return false;
}

