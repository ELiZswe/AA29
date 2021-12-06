// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_SpotterRange/EL_SpotterRange.h"

AEL_SpotterRange::AEL_SpotterRange()
{

}

/*
State InitialIntroduction
{
	Function BeginState()
	{
		Controller.bCFFTrainingDisableCFF=true;
		PlayerLock(true,false);
		AGP_HUD(Controller.myHUD).DisplayCenteredMessageLong(24,sIntroduction);
		agpIntroSgt.PlayLIPSincAnim(nameWelcomeIntroduction,1,256,1);
		SetTimer(25,false);
		iInstructionStep=0;
	}
	Function EndState()
	{
		agpIntroSgt.StopLIPSincAnim();
		PlayerLock(false,false);
		AGP_HUD(Controller.myHUD).DisplayCenteredMessageLong(0,"");
	}
	Function ELPlayerPressedFireNotifier()
	{
		GotoState('MoveToSpotterPosition');
	}
	Function Timer()
	{
		GotoState('MoveToSpotterPosition');
		iInstructionStep ++;
	}
Begin:
	if (agpIntroSgt.Controller != None)
	{
		agpIntroSgt.Controller.Focus=Controller.Pawn;
	}
}
State MoveToSpotterPosition
{
	Function BeginState()
	{
		Timer();
		SetTimer(30,true);
	}
	Function Timer()
	{
		PlayTip("Move either to the qualification forward observer position 2 on the right or ","the practice round forward observer position 1 on the left to start training.",5);
	}
}
State QualificationIntroduction
{
	Function BeginState()
	{
		if (agpQualficationSgt.Controller != None)
		{
			agpQualficationSgt.Controller.Focus=Controller.Pawn;
		}
		Log("Trying to play into to qualification: " $ string(nameFOTQualificationIntro) $ " has lipsynch: " $ string(agpPracticeSgt.HasLIPSincAnim(nameFOTQualificationIntro)));
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationIntro,1,128,1);
		SetTimer(1,true);
	}
	Function ELPlayerPressedFireNotifier()
	{
		if (agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			agpQualficationSgt.StopLIPSincAnim();
		}
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState('SoftTargetInstructions');
		}
	}
}
State SoftTargetInstructions
{
	Function BeginState()
	{
		Controller.bCFFTrainingDisableCFF=true;
		if (agpQualficationSgt.Controller != None)
		{
			agpQualficationSgt.Controller.Focus=Controller.Pawn;
		}
		Controller.bCFFDisableLaser=true;
		Log("Trying to play into to qualification: " $ string(nameFOTQualificationStageOne) $ " has lipsynch: " $ string(agpPracticeSgt.HasLIPSincAnim(nameFOTQualificationStageOne)));
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationStageOne,1,128,1);
		SetTimer(1,true);
	}
	Function ELPlayerPressedFireNotifier()
	{
		if (agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			agpQualficationSgt.StopLIPSincAnim();
		}
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState('BeginSoftTargetCFF');
		}
	}
}
State BeginSoftTargetCFF
{
	Function BeginState()
	{
		Controller.bCFFTrainingDisableCFF=false;
		agpusmtfdcFDC.iTotalRoundsFired=0;
		ResetCurrentTarget();
		DetermineRandomTargets();
		SpawnCurrentTargetMarker();
		agpdoCurrentTarget=agpdoRandomSoftTarget;
		EnableCurrentTarget();
		SetTimer(0,false);
	}
	Function ELPlayerPressedFireNotifier()
	{
		PlayTip("Laser is not available during qualification.","",2.5);
	}
	Function MortarDamagedTarget(Actor agpmrdoTarget, Actor Instigator)
	{
		int32 iPercentDamaged = 0;
		iSoftTargetRoundsHit ++;
		iPercentDamaged=(100 - AGP_DestroyableObjective(agpmrdoTarget).Health);
	}
	Function MortarDestroyedTarget(Actor agpmrdoTarget, Actor Instigator)
	{
		iSoftTargetRoundsFired=agpusmtfdcFDC.iTotalRoundsFired;
		Log("Target destroyed: " $ string(agpmrdoTarget));
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationGoodShotCheckFire,1,128,1);
		agpusmtfdcFDC.CheckFire(true);
		SetTimer(1,true);
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState('VehicleTargetInstructions');
		}
	}
}
State VehicleTargetInstructions
{
	Function BeginState()
	{
		iInstructionStep=0;
		Controller.bCFFTrainingDisableCFF=true;
		if (agpQualficationSgt.Controller != None)
		{
			agpQualficationSgt.Controller.Focus=Controller.Pawn;
		}
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationStageOneComplete,1,128,1);
		SetTimer(1,true);
	}
	Function ELPlayerPressedFireNotifier()
	{
		if (agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			agpQualficationSgt.StopLIPSincAnim();
		}
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState('BeginVehicleTargetCFF');
		}
	}
}
State BeginVehicleTargetCFF
{
	Function BeginState()
	{
		ResetCurrentTarget();
		agpusmtfdcFDC.iTotalRoundsFired=0;
		Controller.bCFFTrainingDisableCFF=false;
		agpdoCurrentTarget=agpdoRandomVehicleTarget;
		SpawnCurrentTargetMarker();
		EnableCurrentTarget();
		SetTimer(0,false);
	}
	Function MortarDamagedTarget(Actor agpmrdoTarget, Actor Instigator)
	{
		int32 iPercentDamaged = 0;
		iVehicleTargetRoundsHit ++;
		iPercentDamaged=(100 - AGP_DestroyableObjective(agpmrdoTarget).Health);
		if ((iPercentDamaged > 0) && (iPercentDamaged < 100))
		{
			PlayTip("Nice shooting, keep it up.  You've damaged " $ string(iPercentDamaged) $ " percent of the target.","",2.5);
		}
	}
	Function MortarDestroyedTarget(Actor agpmrdoTarget, Actor Instigator)
	{
		Log("Target destroyed: " $ string(agpmrdoTarget));
		iVehicleTargetRoundsFired=agpusmtfdcFDC.iTotalRoundsFired;
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationGoodShotCheckFire,1,128,1);
		agpusmtfdcFDC.CheckFire(true);
		SetTimer(1,true);
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState('GridTargetInstructions');
		}
	}
}
State GridTargetInstructions
{
	Function BeginState()
	{
		iInstructionStep=0;
		Controller.bCFFTrainingDisableCFF=true;
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationStageTwoComplete,1,128,1);
		SetTimer(1,true);
	}
	Function ELPlayerPressedFireNotifier()
	{
		if (agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			agpQualficationSgt.StopLIPSincAnim();
		}
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState('BeginGridTargetCFF');
		}
	}
}
State BeginGridTargetCFF
{
	Function BeginState()
	{
		ResetCurrentTarget();
		agpdoCurrentTarget=agpdoRandomGridSoftTarget;
		SpawnCurrentTargetMarker();
		EnableCurrentTarget();
		Controller.bCFFTrainingDisableCFF=false;
		Controller.bCFFTrainingGridOnly=true;
		agpusmtfdcFDC.iTotalRoundsFired=0;
		SetTimer(0,false);
	}
	Function MortarTrainingRoundLanded(Vector vHitLocation)
	{
		Log("Round landed distance from target: " $ string(VSize((vHitLocation - agpdoCurrentTarget.Location))));
		if (VSize((vHitLocation - agpdoCurrentTarget.Location)) > float(2500))
		{
			PlayTip("That round was at least 50m off target.","Try small adjustments and walk the rounds to your target.",5);
		}
	}
	Function MortarDamagedTarget(Actor agpmrdoTarget, Actor Instigator)
	{
		int32 iPercentDamaged = 0;
		iGridTargetRoundsHit ++;
		iPercentDamaged=(100 - AGP_DestroyableObjective(agpmrdoTarget).Health);
		if ((iPercentDamaged > 0) && (iPercentDamaged < 100))
		{
			PlayTip("Nice shooting, keep it up.  You've damaged " $ string(iPercentDamaged) $ " percent of the target.","",2.5);
		}
	}
	Function MortarDestroyedTarget(Actor agpmrdoTarget, Actor Instigator)
	{
		Log("Target destroyed: " $ string(agpmrdoTarget));
		iGridTargetRoundsFired=agpusmtfdcFDC.iTotalRoundsFired;
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationGoodShotCheckFire,1,128,1);
		agpusmtfdcFDC.CheckFire(true);
		SetTimer(1,true);
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState('TrainingComplete');
		}
	}
}
State TrainingComplete
{
	Function BeginState()
	{
		float fpGridAccuracy = 0;
		float fpSoftAccuracy = 0;
		float fpVehicleAccuracy = 0;
		float fpTotalAccuracy = 0;
		int32 iTotalRoundsFired = 0;
		Controller.bCFFTrainingDisableCFF=true;
		SetTimer(6,false);
		Log("Grid Targets hit: " $ string(iGridTargetRoundsHit) $ " Total shots fired: " $ string(iGridTargetRoundsFired));
		iGridTargetRoundsFired=5;
		iGridTargetRoundsHit=2;
		iTotalRoundsFired=((iSoftTargetRoundsFired + iVehicleTargetRoundsFired) + iGridTargetRoundsFired);
		if (iSoftTargetRoundsFired > 0)
		{
			fpSoftAccuracy=((float(iSoftTargetRoundsHit) / float(iSoftTargetRoundsFired)) * 100);
		}
		if (iVehicleTargetRoundsFired > 0)
		{
			fpVehicleAccuracy=((float(iVehicleTargetRoundsHit) / float(iVehicleTargetRoundsFired)) * 100);
		}
		if (iGridTargetRoundsFired > 0)
		{
			fpGridAccuracy=((float(iGridTargetRoundsHit) / float(iGridTargetRoundsFired)) * 100);
		}
		fpTotalAccuracy=((float(((iSoftTargetRoundsHit + iVehicleTargetRoundsHit) + iGridTargetRoundsHit)) / float(((iSoftTargetRoundsFired + iVehicleTargetRoundsFired) + iGridTargetRoundsFired))) * float(100));
		if (iTotalRoundsFired > 108)
		{
			agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationFailure,1,128,1);
			PlayTip("You failed forward observer training, your accuracy was too low.  Total accuracy: " $ string(fpTotalAccuracy),"Soft Target Accuracy: " $ string(fpSoftAccuracy) $ ", Vehicle: " $ string(fpVehicleAccuracy) $ ", Grid: " $ string(fpGridAccuracy),5);
		}
		else
		{
			if (iGridTargetRoundsFired > 36)
			{
				agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationMarginal,1,128,1);
			}
			else
			{
				agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationGood,1,128,1);
			}
			PlayTip("Congratulations, you completed forward observer training.  Total accuracy: " $ string(fpTotalAccuracy),"Soft Target Accuracy: " $ string(fpSoftAccuracy) $ ", Vehicle: " $ string(fpVehicleAccuracy) $ ", Grid: " $ string(fpGridAccuracy),5);
		}
		SetTimer(1,true);
	}
	Function Timer()
	{
		local Security secLocalSecurity;
		local class<Security>  scLocalSecurityClass;
		local TArray<FString> asMD5ForMap;
		local TArray<FString> asMD5ForScript;
		FString sMD5ForMap = "";
		FString sMD5ForScript = "";
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			SetTimer(0,false);
			Controller.ResetAuthExtraMissionData();
			Controller.AddAuthExtraMissionData("" $ string(iSoftTargetRoundsFired));
			Controller.AddAuthExtraMissionData("" $ string(iSoftTargetRoundsHit));
			Controller.AddAuthExtraMissionData("" $ string(iVehicleTargetRoundsFired));
			Controller.AddAuthExtraMissionData("" $ string(iVehicleTargetRoundsHit));
			Controller.AddAuthExtraMissionData("" $ string(iGridTargetRoundsFired));
			Controller.AddAuthExtraMissionData("" $ string(iGridTargetRoundsHit));
			Controller.AddAuthExtraMissionData("" $ string(iPracticeRoundsFired));
			Controller.AddAuthExtraMissionData("" $ string(iPracticeRoundsHit));
			Controller.AddAuthExtraMissionData("" $ string(Level.TimeSeconds));
			scLocalSecurityClass=class<Security>(DynamicLoadObject("Engine.Security",Class'Class'));
			if (scLocalSecurityClass != None)
			{
				secLocalSecurity=Spawn(scLocalSecurityClass,Controller);
				if (secLocalSecurity != None)
				{
					secLocalSecurity.LocalPerform(2,"../Maps/SpotterTraining.aao","",asMD5ForMap);
					secLocalSecurity.LocalPerform(2,"../System/AGP_Script.u","",asMD5ForScript);
					sMD5ForMap=asMD5ForMap[0];
					sMD5ForScript=asMD5ForScript[0];
				}
			}
			if (((iSoftTargetRoundsHit + iVehicleTargetRoundsHit) + iGridTargetRoundsHit) > 108)
			{
				Controller.AddAuthExtraMissionData(sMD5ForMap);
				Controller.AddAuthExtraMissionData(sMD5ForScript);
				StudentController(Controller).SetAuthMissionPassFlag(false);
				DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_SF","Forward Observer Training Failed","Would you like to save your results to your Personnel Jacket anyway?",128,128,7,'None',"AGP_Interface.AAMissionCompletePage");
			}
			else
			{
				Controller.AddAuthExtraMissionData(sMD5ForMap);
				Controller.AddAuthExtraMissionData(sMD5ForScript);
				StudentController(Controller).SetAuthMissionPassFlag(true);
				DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_SF","Forward Observer Training Complete","Would you like to save your results to your Personnel Jacket?",128,128,7,'None',"AGP_Interface.AAMissionCompletePage");
			}
		}
	}
}
State PracticeRoundCFF
{
	Function BeginState()
	{
		if (agpPracticeSgt.Controller != None)
		{
			agpPracticeSgt.Controller.Focus=Controller.Pawn;
		}
		Controller.myHUD.bPortalDebugView=false;
		fpTimeSinceLastCheckFire=0;
		ResetCurrentTarget();
		DetermineRandomTargets();
		if (FRand() > 0.5)
		{
			agpdoCurrentTarget=agpdoRandomSoftTarget;
		}
		else
		{
			agpdoCurrentTarget=agpdoRandomVehicleTarget;
		}
		SpawnCurrentTargetMarker();
		EnableCurrentTarget();
		agpPracticeSgt.PlayLIPSincAnim(namePracticeIntroduction,1,128,1);
		SetTimer(10,false);
		Controller.bCFFTrainingDisableCFF=false;
		Controller.bCFFTrainingRoundsOnly=true;
		fpPracticeStartTime=Level.TimeSeconds;
	}
	Function ELPlayerPressedFireNotifier()
	{
		if (agpPracticeSgt.IsPlayingLIPSincAnim())
		{
			agpPracticeSgt.StopLIPSincAnim();
		}
	}
	Function Timer()
	{
		if (((Level.TimeSeconds - fpPracticeStartTime) > float(30)) && (agpusmtfdcFDC.iTotalRoundsFired == 0))
		{
			if (FRand() < 0.5)
			{
				PlayTip("To get support using Polar Aiming use your binoculars to identify the target, your <ZoomIn> and <ZoomOut> to adjust ","the range, press the <CFFDisplaySpotterTools> key and click the target type and when acknowledged, press 'Fire'.",8);
			}
			else
			{
				PlayTip("To get support using Grid Coordinates use your binoculars to identify the target and then use your map menu to select","the target area.  Then select the target type and once acknowledged use the <CFFDisplaySpotterTools> key and then click 'Fire'.",8);
			}
			SetTimer(15,false);
			return;
		}
		if (agpusmtfdcFDC.iTotalRoundsFired > 0)
		{
			SetTimer(20,false);
		}
		else
		{
			SetTimer(10,false);
		}
		PlayTip(asPracticeTips[iPracticeTipIndex],asPracticeTipsA[iPracticeTipIndex],6.5);
		if (iPracticeTipIndex < (asPracticeTips.Length - 2))
		{
			iPracticeTipIndex ++;
		}
		else
		{
			iPracticeTipIndex=0;
		}
	}
	Function EventLabTick(float fpDeltaTime)
	{
		Super::EventLabTick(fpDeltaTime);
		if (((Controller.Pawn.Weapon == None) || (! Controller.Pawn.Weapon.IsA('Item_Binoculars'))) || (! Controller.Pawn.Weapon.IsZoomed()))
		{
			Controller.myHUD.bPortalDebugView=false;
		}
	}
	Function MortarTrainingRoundLanded(Vector vHitLocation)
	{
		EnableTargetView();
		if (Abs((vHitLocation.Y - agpPracticeSgt.Location.Y)) < float(1500))
		{
			if ((Level.TimeSeconds - fpTimeSinceLastCheckFire) > 10)
			{
				agpPracticeSgt.PlayLIPSincAnim(namePracticeCheckFire[Rand(namePracticeCheckFire.Length)],1,256,1);
				fpTimeSinceLastCheckFire=Level.TimeSeconds;
			}
			RunConsoleCommand("CFFCheckFire");
			return;
		}
		if (VSize((vHitLocation - agpdoCurrentTarget.Location)) > float(1250))
		{
			PlayTip(GetCorrectionNeeded(vHitLocation) $ ", that round was too far off target.","Try small adjustments and walk the rounds to your target.",5);
			if ((Level.TimeSeconds - fpTimeSinceLastComment) > 15)
			{
				agpPracticeSgt.PlayLIPSincAnim(namePracticePoorShot[Rand(namePracticePoorShot.Length)],1,128,1);
				fpTimeSinceLastComment=Level.TimeSeconds;
			}
			return;
		}
		else
		{
			if (VSize((vHitLocation - agpdoCurrentTarget.Location)) < float(550))
			{
				if ((Level.TimeSeconds - fpTimeSinceLastComment) > 15)
				{
					agpPracticeSgt.PlayLIPSincAnim(namePracticeGoodShot[Rand(namePracticeGoodShot.Length)],1,128,1);
					fpTimeSinceLastComment=Level.TimeSeconds;
				}
				return;
			}
		}
		if ((Level.TimeSeconds - fpTimeSinceLastComment) > 15)
		{
			if (((float(agpusmtfdcFDC.iTotalRoundsFired) % 6) == 0) && (agpusmtfdcFDC.iTotalRoundsFired > 0))
			{
				agpPracticeSgt.PlayLIPSincAnim(namePracticeComment[Rand(namePracticeComment.Length)],1,128,1);
				fpTimeSinceLastComment=Level.TimeSeconds;
			}
		}
	}
	Function EnableTargetView()
	{
		if (! Controller.myHUD.bPortalDebugView)
		{
			Controller.myHUD.bShowDebugInfo=false;
			Controller.myHUD.bPortalDebugView=true;
			FocusClass(Class'AGP_Gameplay.AGP_DestroyableObjective',,,agpdoCurrentTarget.Name,true);
		}
	}
	Function bool TriggerVolume_Exit(AGP_Gameplay.TriggerVolume NotifyActor, Actor Instigator)
	{
		if ((agpusmtfdcFDC.iRoundsFired < agpusmtfdcFDC.iMaxRoundsPerMission) && agpusmtfdcFDC.bFireMissionInProgress)
		{
			agpusmtfdcFDC.CheckFire(true);
		}
		GotoState('None');
		return true;
	}
	Function FocusClass(class<Actor>  aClass, bool bQuiet, FName TagName, FName ActorName, bool bAIOnly)
	{
		local Actor Other;
		local Actor first;
		bool bFound = false;
		first=None;
		ForEach AllActors(aClass,Other)
		{
			if (((TagName == 'None') || (Other.Tag == TagName)) && ((ActorName == 'None') || (Other.Name == ActorName)))
			{
				if (bFound || (first == None))
				{
					first=Other;
					if (bFound)
					{
					}
				}
				else
				{
					if (Other == Controller.FocusTarget)
					{
						bFound=true;
					}
				}
			}
		}
		if (first != None)
		{
			Controller.SetFocusTarget(first);
		}
		else
		{
			Controller.SetFocusTarget(Controller.Pawn);
		}
	}
	Function EndState()
	{
		if (agpPracticeSgt.Controller != None)
		{
			agpPracticeSgt.Controller.Focus=None;
		}
		Controller.bCFFTrainingRoundsOnly=false;
		Controller.myHUD.bPortalDebugView=false;
	}
}
*/
