// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_MedicTrainingThree/EL_MedicTrainingThree.h"

AEL_MedicTrainingThree::AEL_MedicTrainingThree()
{

}

/*
State EnterClass
{
	Function bool ClassVolumeThree_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		UnCaptureEvent(ClassVolumeThree);
		PlayLSAnim('C3_Welcome',InstructorThree,1,512);
		PlayTip("Talk to people in your class by pressing","the <action> key while facing somebody",5);
		if (DoorTriggerThree.IsOpen())
		{
			DoorTriggerThree.ToggleOpen();
		}
		DoorTriggerThree.SetLocked(true);
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
	Function bool InstructorTriggerThree_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (InstructorUseCount == 0)
		{
			PlayLSAnim('C3_WillGetStarted',InstructorThree,1,512);
			InstructorUseCount ++;
			return true;
		}
		if (InstructorUseCount <= 2)
		{
			PlayLSAnim('C3_TakeASeat',InstructorThree,1,512);
			InstructorUseCount ++;
			return true;
		}
		return true;
	}
	Function bool SeatTriggerThree_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		UnCaptureEvent(SeatTriggerThree);
		StartTimer('tmrSatDown',5,false);
		PlayTip("To get out of the chair, press the <jump> key","",5);
		return true;
	}
	Function bool SeatVolumeThree_Trigger(AGP_Gameplay.AGP_Trigger Trigger, Actor Instigator)
	{
		UnCaptureEvent(SeatVolumeThree);
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
		PlayLSAnim('C3_GetStarted',InstructorThree,1,512);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == 'C3_GetStarted')
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
		ReCaptureEvent(SeatTriggerThree);
		StartTimer('tmrSitDown',5,false);
		StartTimer('TimeToSit_Start',0.01,false);
	}
	Function bool SeatTriggerThree_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
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
			PlayLSAnim('C3_TakeSeats',InstructorThree,1,512);
			StartTimer('tmrSitDown2',5,false);
			return true;
		}
		if (Name == 'tmrSitDown2')
		{
			PlayLSAnim('C3_TakeASeat',InstructorThree,1,512);
			StartTimer('tmrSitDown3',10,false);
			return true;
		}
		if (Name == 'tmrSitDown3')
		{
			PlayLSAnim('C3_SitDown',InstructorThree,1,512);
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
	Function bool SeatTriggerThree_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
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
				ChangeState('Slide00');
				return true;
			}
		}
		return Super::Timer_Timer(Name);
	}
}
State Slide00 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorThree.SetCurrentMaterial(0);
		StartTimer('Slide00_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide00_Start')
		{
			PlayLSAnim('00_Intro',InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '00_Intro')
		{
			ChangeState('Slide01');
			return true;
		}
	}
}
State Slide01 extends Lecture
{
	Function BeginSlide()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorThree.SetCurrentMaterial(1);
		StartTimer('Slide01_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide01_Start')
		{
			PlayLSAnim('01_ShockMayBeCaused',InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '01_ShockMayBeCaused')
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
		SlideProjectorThree.SetCurrentMaterial(2);
		StartTimer('Slide02_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide02_Start')
		{
			PlayLSAnim('02_SignsAndSymptoms',InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '02_SignsAndSymptoms')
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
		SlideProjectorThree.SetCurrentMaterial(3);
		StartTimer('Slide03_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide03_Start')
		{
			PlayLSAnim('03_ToTreatShock',InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '03_ToTreatShock')
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
		SlideProjectorThree.SetCurrentMaterial(4);
		StartTimer('Slide04_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide04_Start')
		{
			PlayLSAnim('04_LosenClothing',InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '04_LosenClothing')
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
		SlideProjectorThree.SetCurrentMaterial(5);
		StartTimer('Slide05_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide05_Start')
		{
			PlayLSAnim('05_Chilling',InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '05_Chilling')
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
		SlideProjectorThree.SetCurrentMaterial(6);
		StartTimer('Slide06_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		Super::Timer_Timer(Name);
		if (Name == 'Slide06_Start')
		{
			PlayLSAnim('06_Measures',InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '06_Measures')
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
		SlideProjectorThree.SetCurrentMaterial(7);
		StartTimer('Slide07_Start',2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide07_Start')
		{
			PlayLSAnim('07_MedicalAid',InstructorThree,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == '07_MedicalAid')
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
		SlideProjectorThree.SetCurrentMaterial(0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrConclude_Start')
		{
			PlayLSAnim('C3_ShockConclude',InstructorThree,1,512);
			return true;
		}
		return GlobalTimer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == 'C3_ShockConclude')
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
		ReCaptureEvent(SeatVolumeThree);
		MedExamThree.SetActive(true);
		StartTimer('BeginTest_Start',2,false);
		StartTimer('TmrTip1',4,false);
		StartTimer('TmrTip2',10,false);
		StartTimer('TmrTip3',16,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'BeginTest_Start')
		{
			PlayLSAnim('C3_StartTest',InstructorThree,1,512);
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
	Function bool SeatVolumeThree_UnTrigger(AGP_Gameplay.AGP_Trigger Trigger, Actor Instigator)
	{
		PlayTip("When you are through with your test, approach","the instructor and press <action>",5);
		return true;
	}
	Function bool InstructorTriggerThree_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		Grade=int((MedExamThree.ScoreTest() * float(100)));
		MedExamThree.Destroy();
		MedExamThree=None;
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
		PlayLSAnim('C3_GoodJob',InstructorThree,1,512);
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
		if (Name == 'C3_GoodJob')
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
		PlayLSAnim('C3_YouJustMadeIt',InstructorThree,1,512);
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
		if (Name == 'C3_YouJustMadeIt')
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
		PlayLSAnim('C3_NotSoGreat',InstructorThree,1,512);
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
		if (Name == 'C3_NotSoGreat')
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
		PlayLSAnim('C3_JustPathetic',InstructorThree,1,512);
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
		if (Name == 'C3_JustPathetic')
		{
			ChangeState('TestFailed');
			return true;
		}
	}
}
State TestPassed
{
	Function bool InstructorTriggerThree_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
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
				DisplayMissionSuccess("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Congratulations!","You can now begin Field Training.",128,128,7,'None');
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
		StartTimer('BeginFailed',2);
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
	Function bool SeatTriggerThree_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		ChangeState(RecallState(0));
		return true;
	}
}
State OutOfChair1 extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim('C3_TakeASeat',InstructorThree,1,512);
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
		PlayLSAnim('C3_SitDown',InstructorThree,1,512);
		if (LightSwitchThree.IsSwitched())
		{
			RememberState('OutOfChair3',1);
		}
		else
		{
			RememberState('Busted',1);
		}
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
			ChangeState('OutOfChair3');
			return true;
		}
		return GlobalTimer(Name);
	}
}
State OutOfChair3 extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim('C3_NotAGame',InstructorThree,1,512);
		RememberState('Busted',1);
		StartTimer('Escelate',15,false);
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
		PlayLSAnim('C3_StepOutside',InstructorThree,1,512);
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
				PlayLSAnim('C3_KeepEyes',InstructorThree,1,512);
			}
			else
			{
				if (LookCount == 2)
				{
					PlayLSAnim('C3_LastWarning',InstructorThree,1,512);
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
		if ((Name == 'C3_KeepEyes') || (Name == 'C3_LastWarning'))
		{
			ChangeState('Testing');
			return true;
		}
	}
}
*/
