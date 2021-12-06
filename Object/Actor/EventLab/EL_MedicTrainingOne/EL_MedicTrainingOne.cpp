// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_MedicTrainingOne/EL_MedicTrainingOne.h"

AEL_MedicTrainingOne::AEL_MedicTrainingOne()
{

}

/*
State EnterClass
{
	Function bool ClassVolumeOne_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		UnCaptureEvent(ClassVolumeOne);
		PlayLSAnim('C1_Welcome',InstructorOne,1,512);
		PlayTip("Talk to people in your class by pressing","the <action> key while facing somebody",5);
		if (DoorTriggerOne.IsOpen())
		{
			DoorTriggerOne.ToggleOpen();
		}
		DoorTriggerOne.SetLocked(true);
		ChangeState('inClass');
		return true;
	}
}
State inClass
{
	Function BeginState()
	{
		StartTimer('tmrBeginClass',60,false);
	}
	Function EndState()
	{
	}
	Function bool InstructorTriggerOne_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (InstructorUseCount == 0)
		{
			PlayLSAnim('C1_WillGetStarted',InstructorOne,1,512);
			InstructorUseCount ++;
			return true;
		}
		if (InstructorUseCount <= 2)
		{
			PlayLSAnim('C1_TakeASeat',InstructorOne,1,512);
			InstructorUseCount ++;
			return true;
		}
		return true;
	}
	Function bool SeatTriggerOne_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		UnCaptureEvent(SeatTriggerOne);
		StartTimer('tmrSatDown',5,false);
		PlayTip("To get out of the chair, press the <jump> key","",5);
		return true;
	}
	Function bool SeatVolumeOne_Trigger(AGP_Gameplay.AGP_Trigger Trigger, Actor Instigator)
	{
		UnCaptureEvent(SeatVolumeOne);
		ReCaptureEvent(Controller);
		PlayTip("To enter your chair, face it and press the <action> key","",5);
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == 'tmrBeginClass') || (Name == 'tmrSatDown'))
		{
			StopTimer('tmrBeginClass',0);
			StopTimer('tmrSatDown',0);
			ChangeState('LetsGetStarted');
			return true;
		}
		return GlobalTimer(Name);
	}
}
State LetsGetStarted
{
	Function BeginState()
	{
		PlayLSAnim('C1_GetStarted',InstructorOne,1,512);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == 'C1_GetStarted')
		{
			ChangeState('TimeToSit');
			return true;
		}
		return false;
	}
}
State TimeToSit
{
	Function BeginState()
	{
		ReCaptureEvent(SeatTriggerOne);
		StartTimer('tmrSitDown',5,false);
		StartTimer('TimeToSit_Start',0.01,false);
	}
	Function bool SeatTriggerOne_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		ChangeState('BeginLecture');
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'TimeToSit_Start')
		{
			if (StudentController(Controller).IsSeated())
			{
				ChangeState('BeginLecture');
			}
			return true;
		}
		if (Name == 'tmrSitDown')
		{
			PlayLSAnim('C1_TakeSeats',InstructorOne,1,512);
			StartTimer('tmrSitDown2',5,false);
			return true;
		}
		if (Name == 'tmrSitDown2')
		{
			PlayLSAnim('C1_TakeASeat',InstructorOne,1,512);
			StartTimer('tmrSitDown3',10,false);
			return true;
		}
		if (Name == 'tmrSitDown3')
		{
			PlayLSAnim('C1_SitDown',InstructorOne,1,512);
			StartTimer('tmrSitDown4',5,false);
			return true;
		}
		if (Name == 'tmrSitDown4')
		{
			ChangeState('Busted');
			return true;
		}
		return GlobalTimer(Name);
	}
}
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
	Function bool SeatTriggerOne_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		StopTimer('tmrOutOfChair',0);
		ReCaptureEvent(Controller);
		return true;
	}
	Function bool StudentController_Custom(StudentController SC, Actor Instigator, FString Parms)
	{
		if (Parms == "EXITCHAIR")
		{
			UnCaptureEvent(Controller);
			StartTimer('tmrOutOfChair',1,false);
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
		if (Name == 'tmrOutOfChair')
		{
			ChangeState(RecallState(1));
			return true;
		}
		return GlobalTimer(Name);
	}
}
State BeginLecture extends Lecture
{
	Function BeginSlide()
	{
		StartTimer('tmrBeginLecture',0.01,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrBeginLecture')
		{
			if (StudentController(Controller).SkipSlides())
			{
				ChangeState('LectureConcluded');
				return true;
			}
			else
			{
				ChangeState('Slide01');
				return true;
			}
		}
		return Super::Timer_Timer(Name);
	}
}
State Slide01 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(1);
		StartTimer('Slide01_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide01_Start')
		{
			PlayLSAnim('01_ThroughoutHistory',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '01_ThroughoutHistory')
		{
			ChangeState('Slide02');
			return true;
		}
	}
}
State Slide02 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(2);
		StartTimer('Slide02_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide02_Start')
		{
			PlayLSAnim('02_ThroughoutHistory',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '02_ThroughoutHistory')
		{
			ChangeState('Slide03');
			return true;
		}
	}
}
State Slide03 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(3);
		StartTimer('Slide03_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide03_Start')
		{
			PlayLSAnim('03_CombatLifesavingSteps',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '03_CombatLifesavingSteps')
		{
			ChangeState('Slide04');
			return true;
		}
	}
}
State Slide04 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(4);
		StartTimer('Slide04_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide04_Start')
		{
			PlayLSAnim('04_CheckResponsiveness',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '04_CheckResponsiveness')
		{
			ChangeState('Slide05');
			return true;
		}
	}
}
State Slide05 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(5);
		StartTimer('Slide05_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide05_Start')
		{
			PlayLSAnim('05_OpenTheAirway',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '05_OpenTheAirway')
		{
			ChangeState('Slide06');
			return true;
		}
	}
}
State Slide06 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(6);
		StartTimer('Slide06_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		Super::Timer_Timer(Name);
		if (Name == 'Slide06_Start')
		{
			PlayLSAnim('06_HeadTiltChinLift',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '06_HeadTiltChinLift')
		{
			ChangeState('Slide07');
			return true;
		}
	}
}
State Slide07 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(7);
		StartTimer('Slide07_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide07_Start')
		{
			PlayLSAnim('07_HeadTiltChinLift',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '07_HeadTiltChinLift')
		{
			ChangeState('Slide08');
			return true;
		}
	}
}
State Slide08 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(8);
		StartTimer('Slide08_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide08_Start')
		{
			PlayLSAnim('08_JawThrust',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '08_JawThrust')
		{
			ChangeState('Slide09');
			return true;
		}
	}
}
State Slide09 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(9);
		StartTimer('Slide09_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide09_Start')
		{
			PlayLSAnim('09_CheckTheBreathing',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '09_CheckTheBreathing')
		{
			ChangeState('Slide10');
			return true;
		}
	}
}
State Slide10 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(10);
		StartTimer('Slide10_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide10_Start')
		{
			PlayLSAnim('10_GiveQuickBreaths',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '10_GiveQuickBreaths')
		{
			ChangeState('Slide11');
			return true;
		}
	}
}
State Slide11 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(11);
		StartTimer('Slide11_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide11_Start')
		{
			PlayLSAnim('11_GiveQuickBreaths',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '11_GiveQuickBreaths')
		{
			ChangeState('Slide12');
			return true;
		}
	}
}
State Slide12 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(12);
		StartTimer('Slide12_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide12_Start')
		{
			PlayLSAnim('12_GiveQuickBreaths',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '12_GiveQuickBreaths')
		{
			ChangeState('LectureConcluded');
			return true;
		}
	}
}
State LectureConcluded
{
	Function BeginState()
	{
		StartTimer('tmrConclude_Start',1,false);
		SlideProjectorOne.SetCurrentMaterial(0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrConclude_Start')
		{
			PlayLSAnim('C1_AirwayConclude',InstructorOne,1,512);
			return true;
		}
		return GlobalTimer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == 'C1_AirwayConclude')
		{
			ChangeState('BeginTest');
			return true;
		}
	}
}
State BeginTest
{
	Function BeginState()
	{
		ReCaptureEvent(SeatVolumeOne);
		MedExamOne.SetActive(true);
		StartTimer('BeginTest_Start',2,false);
		StartTimer('TmrTip1',4,false);
		StartTimer('TmrTip2',10,false);
		StartTimer('TmrTip3',16,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'BeginTest_Start')
		{
			PlayLSAnim('C1_StartTest',InstructorOne,1,512);
			return true;
		}
		if (Name == 'TmrTip1')
		{
			PlayTip("To take your test, press the <action> key while","sitting in your chair",5);
			return true;
		}
		if (Name == 'TmrTip2')
		{
			PlayTip("To turn pages in your test, use the icons at","bottom of page, or press <leanleft> and <leanright>",5);
			return true;
		}
		if (Name == 'TmrTip3')
		{
			PlayTip("To mark answers, use your <fire> or","<action> buttons",5);
			ChangeState('Testing');
			return true;
		}
		return GlobalTimer(Name);
	}
}
State Testing
{
	Function BeginState()
	{
	}
	Function bool StudentController_Custom(StudentController SC, Actor Instigator, FString Parms)
	{
		if (Parms == "CHEATING")
		{
			UnCaptureEvent(Controller);
			StartTimer('CheckCheating',1.5,false);
			return true;
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'CheckCheating')
		{
			if (StudentController(Controller).IsPossiblyCheating())
			{
				ChangeState('Cheating');
			}
			else
			{
				ReCaptureEvent(Controller);
			}
			return true;
		}
		return GlobalTimer(Name);
	}
	Function bool SeatVolumeOne_UnTrigger(AGP_Gameplay.AGP_Trigger Trigger, Actor Instigator)
	{
		PlayTip("When you are through with your test, approach","the instructor and press <action>",5);
		return true;
	}
	Function bool InstructorTriggerOne_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		Grade=int((MedExamOne.ScoreTest() * float(100)));
		MedExamOne.Destroy();
		MedExamOne=None;
		if (Grade >= 80)
		{
			ChangeState('Eighty1Hundred');
			return true;
		}
		if (Grade >= 70)
		{
			ChangeState('SeventySeventyNine');
			return true;
		}
		if (Grade >= 60)
		{
			ChangeState('SixtySixtyNine');
			return true;
		}
		else
		{
			ChangeState('ZeroFiftyNine');
			return true;
		}
	}
}
State Eighty1Hundred
{
	Function BeginState()
	{
		PlayLSAnim('C1_GoodJob',InstructorOne,1,512);
		if (StudentController(Controller).IsCheating())
		{
			PlayTip("Cheats Detected. Good job soldier,","you scored " $ string(Grade) $ "%",5);
		}
		else
		{
			PlayTip("Good job soldier,","you scored " $ string(Grade) $ "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == 'C1_GoodJob')
		{
			ChangeState('TestPassed');
			return true;
		}
	}
}
State SeventySeventyNine
{
	Function BeginState()
	{
		PlayLSAnim('C1_YouJustMadeIt',InstructorOne,1,512);
		if (StudentController(Controller).IsCheating())
		{
			PlayTip("Cheats Detected. You passed with","" $ string(Grade) $ "%",5);
		}
		else
		{
			PlayTip("You passed with","" $ string(Grade) $ "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == 'C1_YouJustMadeIt')
		{
			ChangeState('TestPassed');
			return true;
		}
	}
}
State SixtySixtyNine
{
	Function BeginState()
	{
		PlayLSAnim('C1_NotSoGreat',InstructorOne,1,512);
		if (StudentController(Controller).IsCheating())
		{
			PlayTip("Cheats Detected. You Failed!","You scored" $ string(Grade) $ "%",5);
		}
		else
		{
			PlayTip("You Failed!","You scored" $ string(Grade) $ "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == 'C1_NotSoGreat')
		{
			ChangeState('TestFailed');
			return true;
		}
	}
}
State ZeroFiftyNine
{
	Function BeginState()
	{
		PlayLSAnim('C1_JustPathetic',InstructorOne,1,512);
		if (StudentController(Controller).IsCheating())
		{
			PlayTip("Cheats Detected. Pathetic soldier!","You scored " $ string(Grade) $ "%",5);
		}
		else
		{
			PlayTip("Pathetic soldier!","You scored " $ string(Grade) $ "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == 'C1_JustPathetic')
		{
			ChangeState('TestFailed');
			return true;
		}
	}
}
State TestPassed
{
	Function bool InstructorTriggerOne_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
	}
	Function BeginState()
	{
		StartTimer('BeginPassed',0.01);
	}
	Function UpdateCompletionFields()
	{
		local Security secLocalSecurity;
		local class<Security>  scLocalSecurityClass;
		local TArray<FString> asMD5ForMap;
		local TArray<FString> asMD5ForScript;
		FString sMD5ForMap = "";
		FString sMD5ForScript = "";
		scLocalSecurityClass=class<Security>(DynamicLoadObject("Engine.Security",Class'Class'));
		if (scLocalSecurityClass != None)
		{
			secLocalSecurity=Spawn(scLocalSecurityClass,Controller);
			if (secLocalSecurity != None)
			{
				secLocalSecurity.LocalPerform(2,"../Maps/Medic_Training1.aao","",asMD5ForMap);
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
		if (Name == 'BeginPassed')
		{
			StudentController(Controller).ResetAuthExtraMissionData();
			StudentController(Controller).AddAuthExtraMissionData(string(Grade));
			UpdateCompletionFields();
			if (StudentController(Controller).IsCheating())
			{
				StudentController(Controller).SetAuthMissionPassFlag(false);
				DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Congratulations!","Cheats detected, cannot complete.",128,128,7,'None');
			}
			else
			{
				StudentController(Controller).SetAuthMissionPassFlag(true);
				DisplayMissionSuccess("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Congratulations! You can now","move on to Controlling Bleeding.",128,128,7,'None');
			}
			return true;
		}
		return false;
	}
}
State TestFailed
{
	Function BeginState()
	{
		StartTimer('BeginFailed',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'BeginFailed')
		{
			DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Training Failed!","",128,128,7,'None');
			return true;
		}
		return GlobalTimer(Name);
	}
}
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
	Function bool SeatTriggerOne_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		ChangeState(RecallState(0));
		return true;
	}
}
State OutOfChair1 extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim('C1_TakeASeat',InstructorOne,1,512);
		RememberState('OutOfChair2',1);
		StartTimer('Escelate',10,false);
	}
	Function EndTrouble()
	{
		StopTimer('BeginTrouble',0);
		StopTimer('Escelate',0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Escelate')
		{
			ChangeState('OutOfChair2');
			return true;
		}
		return GlobalTimer(Name);
	}
}
State OutOfChair2 extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim('C1_SitDown',InstructorOne,1,512);
		RememberState('Busted',1);
		StartTimer('Escelate',10,false);
	}
	Function EndTrouble()
	{
		StopTimer('BeginTrouble',0);
		StopTimer('Escelate',0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Escelate')
		{
			ChangeState('Busted');
			return true;
		}
		return GlobalTimer(Name);
	}
}
State Busted extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim('C1_StepOutside',InstructorOne,1,512);
		Controller.GotoState('MedicTraining_Frozen');
		FadeOut(2,true);
		PlayerLock(true,true);
		StartTimer('tmrLoadEntry',5,false);
	}
	Function EndTrouble()
	{
		StopTimer('BeginTrouble',0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrLoadEntry')
		{
			RunConsoleCommand("open entry2");
			return true;
		}
		return GlobalTimer(Name);
	}
}
State Cheating
{
	Function BeginState()
	{
		StartTimer('tmrCheating_Start',0.01,false);
	}
	Function EndState()
	{
		ReCaptureEvent(Controller);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrCheating_Start')
		{
			LookCount ++;
			if (LookCount == 1)
			{
				PlayLSAnim('C1_KeepEyes',InstructorOne,1,512);
			}
			else
			{
				if (LookCount == 2)
				{
					PlayLSAnim('C1_LastWarning',InstructorOne,1,512);
				}
				else
				{
					ChangeState('Busted');
				}
			}
		}
		return GlobalTimer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if ((Name == 'C1_KeepEyes') || (Name == 'C1_LastWarning'))
		{
			ChangeState('Testing');
			return true;
		}
	}
}
*/
