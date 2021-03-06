// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_SpotterRange/EL_SpotterRange.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_DestroyableObjective/AGP_DestroyableObjective.h"
#include "AA29/Object/Actor/AGP_Location/AGP_Location.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AGP_USMortarTeamFDC/AGP_USMortarTeamFDC.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/BaseSmokeEmitter.h"
#include "AA29/Object/Actor/Info/Security/Security.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/fx_BlackSmoke/fx_BlackSmoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_Binoculars.h"

AEL_SpotterRange::AEL_SpotterRange()
{
	sIntroduction = "Welcome to Forward Observer training and qualification.  Two Forward Observer positions have been set up for your use today.  Position One, located up the path and to the left, will let you practice your Call For Fire Skills and get you ready to qualify and Position Two.  Head to Position One now to start practicing, or if you feel you're ready to qualify, head to Position Two Now.  Good luck and Remember to be always check the target area before calling in fire.";
	nameWelcomeIntroduction = "FOTWelcomeIntroduction";
	namePracticeIntroduction = "FOTPracticeIntroduction";
	namePracticeComment = {
		"FOTPracticeComment01",
		"FOTPracticeComment02",
		"FOTPracticeComment03",
		"FOTPracticeComment04"
	};
	namePracticeGoodShot = {
		"FOTGoodAim01",
		"FOTGoodAim02",
		"FOTGoodAim03",
		"FOTGoodAim04",
		"FOTGoodAim05"
	};
	namePracticePoorShot = {
		"FOTPoorAim01",
		"FOTPoorAim02",
		"FOTPoorAim03"
	};
	namePracticeCheckFire = {
		"FOTCheckFire01"
		"FOTCheckFire02"
		"FOTCheckFire03"
		"FOTCheckFire04"
	};
	nameFOTQualificationGoodShotCheckFire = "FOTQualificationGoodShotCheckFire";
	nameFOTQualificationIntro = "FOTQualificationIntro";
	nameFOTQualificationStageOne = "FOTQualificationStageOne";
	nameFOTQualificationStageOneComplete = "FOTQualificationStageOneComplete";
	nameFOTQualificationStageTwoComplete = "FOTQualificationStageTwoComplete";
	nameFOTQualificationFailure = "FOTQualificationFailure";
	nameFOTQualificationMarginal = "FOTQualificationMarginal";
	nameFOTQualificationGood = "FOTQualificationGood";
	nameFOTQualificationCheckFire = "FOTQualificationCheckFire";
	asPracticeTips = {
		"Use your binoculars and the <ZoomIn> and <ZoomOut> keys to set your polar ",
		"Polar firing always fires in the direction your are looking with your binoculars ",
		"You can toggle the Call For Fire tools menu on and off using the <CFFDisplaySpotterTools> key.",
		"Adjust your fire using the Call For Fire tools (<CFFDisplaySpotterTools>) to adjust the direction left, right, or farther",
		"If your rounds are behind the target drop the range by clicking on the 'Drop' button ",
		"When you want to stop a fire mission press the 'Check Fire' button in the Call For Fire menu (<CFFDisplaySpotterTools>).",
		"You can repeat the previous fire mission using Repeat button on the Call For Fire menu (<CFFDisplaySpotterTools>).",
		"Use your in-game menu's Spotter map to make Grid Coordinate Calls for Fire.  The tools on the right side ",
		"Use the range markers as well as other terrain elements to help judge distances.",
		"When you are ready to qualify, lower your binoculars and walk to the qualifying position."
	};
	asPracticeTipsA = {
		"firing range (range displayed as 'CFF Range: xxxx' in meters).",
		"when you radio the command in.",
		"Left click to activate the laser range finder and then use that to adjust your distance.",
		"(Add) or closer (Drop) and then click on the 'Send' button.",
		"and the distance using the keypad in the Call For Fire Tools menu (<CFFDisplaySpotterTools>).",
		"",
		"This can be faster then performing a new Call For fire when needing to hit another nearby target.",
		"of the map let you set the target area.  Then use the Call For Fire menu (<CFFDisplaySpotterTools>) to initiate the Firing command."
	};
}

/*
State InitialIntroduction
{
	Function BeginState()
	{
		Controller.bCFFTrainingDisableCFF=true;
		PlayerLock(true,false);
		Cast<AAGP_HUD>(Controller.myHUD).DisplayCenteredMessageLong(24,sIntroduction);
		agpIntroSgt.PlayLIPSincAnim(nameWelcomeIntroduction,1,256,1);
		SetTimer(25,false);
		iInstructionStep=0;
	}
	Function EndState()
	{
		agpIntroSgt->StopLIPSincAnim();
		PlayerLock(false,false);
		Cast<AAGP_HUD>(Controller.myHUD).DisplayCenteredMessageLong(0,"");
	}
	Function ELPlayerPressedFireNotifier()
	{
		GotoState("MoveToSpotterPosition");
	}
	Function Timer()
	{
		GotoState("MoveToSpotterPosition");
		iInstructionStep ++;
	}
Begin:
	if (agpIntroSgt.Controller != nullptr)
	{
		agpIntroSgt.Controller.Focus=Controller.Pawn;
	}
}
*/

/*
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
*/

/*
State QualificationIntroduction
{
	Function BeginState()
	{
		if (agpQualficationSgt.Controller != nullptr)
		{
			agpQualficationSgt.Controller.Focus=Controller.Pawn;
		}
		Log("Trying to play into to qualification: " + FString::FromInt(nameFOTQualificationIntro) + " has lipsynch: " + FString::FromInt(agpPracticeSgt.HasLIPSincAnim(nameFOTQualificationIntro)));
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationIntro,1,128,1);
		SetTimer(1,true);
	}
	Function ELPlayerPressedFireNotifier()
	{
		if (agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			agpQualficationSgt->StopLIPSincAnim();
		}
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState("SoftTargetInstructions");
		}
	}
}
*/

/*
State SoftTargetInstructions
{
	Function BeginState()
	{
		Controller.bCFFTrainingDisableCFF=true;
		if (agpQualficationSgt.Controller != nullptr)
		{
			agpQualficationSgt.Controller.Focus=Controller.Pawn;
		}
		Controller.bCFFDisableLaser=true;
		Log("Trying to play into to qualification: " + FString::FromInt(nameFOTQualificationStageOne) + " has lipsynch: " + FString::FromInt(agpPracticeSgt.HasLIPSincAnim(nameFOTQualificationStageOne)));
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationStageOne,1,128,1);
		SetTimer(1,true);
	}
	Function ELPlayerPressedFireNotifier()
	{
		if (agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			agpQualficationSgt->StopLIPSincAnim();
		}
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState("BeginSoftTargetCFF");
		}
	}
}
*/

/*
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
	Function MortarDamagedTarget(AActor* agpmrdoTarget, AActor* Instigator)
	{
		int32 iPercentDamaged = 0;
		iSoftTargetRoundsHit ++;
		iPercentDamaged=(100 - AGP_DestroyableObjective(agpmrdoTarget).Health);
	}
	Function MortarDestroyedTarget(AActor* agpmrdoTarget, AActor* Instigator)
	{
		iSoftTargetRoundsFired=agpusmtfdcFDC.iTotalRoundsFired;
		Log("Target destroyed: " + FString::FromInt(agpmrdoTarget));
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationGoodShotCheckFire,1,128,1);
		agpusmtfdcFDC.CheckFire(true);
		SetTimer(1,true);
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState("VehicleTargetInstructions");
		}
	}
}
*/

/*
State VehicleTargetInstructions
{
	Function BeginState()
	{
		iInstructionStep=0;
		Controller.bCFFTrainingDisableCFF=true;
		if (agpQualficationSgt.Controller != nullptr)
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
			agpQualficationSgt->StopLIPSincAnim();
		}
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState("BeginVehicleTargetCFF");
		}
	}
}
*/

/*
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
	Function MortarDamagedTarget(AActor* agpmrdoTarget, AActor* Instigator)
	{
		int32 iPercentDamaged = 0;
		iVehicleTargetRoundsHit ++;
		iPercentDamaged=(100 - AGP_DestroyableObjective(agpmrdoTarget).Health);
		if ((iPercentDamaged > 0) && (iPercentDamaged < 100))
		{
			PlayTip("Nice shooting, keep it up.  You've damaged " + FString::FromInt(iPercentDamaged) + " percent of the target.","",2.5);
		}
	}
	Function MortarDestroyedTarget(AActor* agpmrdoTarget, AActor* Instigator)
	{
		Log("Target destroyed: " + FString::FromInt(agpmrdoTarget));
		iVehicleTargetRoundsFired=agpusmtfdcFDC.iTotalRoundsFired;
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationGoodShotCheckFire,1,128,1);
		agpusmtfdcFDC.CheckFire(true);
		SetTimer(1,true);
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState("GridTargetInstructions");
		}
	}
}
*/

/*
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
			agpQualficationSgt->StopLIPSincAnim();
		}
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState("BeginGridTargetCFF");
		}
	}
}
*/

/*
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
		Log("Round landed distance from target: " + FString::FromInt(VSize((vHitLocation - agpdoCurrentTarget.Location))));
		if (VSize((vHitLocation - agpdoCurrentTarget.Location)) > float(2500))
		{
			PlayTip("That round was at least 50m off target.","Try small adjustments and walk the rounds to your target.",5);
		}
	}
	Function MortarDamagedTarget(AActor* agpmrdoTarget, AActor* Instigator)
	{
		int32 iPercentDamaged = 0;
		iGridTargetRoundsHit ++;
		iPercentDamaged=(100 - AGP_DestroyableObjective(agpmrdoTarget).Health);
		if ((iPercentDamaged > 0) && (iPercentDamaged < 100))
		{
			PlayTip("Nice shooting, keep it up.  You've damaged " + FString::FromInt(iPercentDamaged) + " percent of the target.","",2.5);
		}
	}
	Function MortarDestroyedTarget(AActor* agpmrdoTarget, AActor* Instigator)
	{
		Log("Target destroyed: " + FString::FromInt(agpmrdoTarget));
		iGridTargetRoundsFired=agpusmtfdcFDC.iTotalRoundsFired;
		agpQualficationSgt.PlayLIPSincAnim(nameFOTQualificationGoodShotCheckFire,1,128,1);
		agpusmtfdcFDC.CheckFire(true);
		SetTimer(1,true);
	}
	Function Timer()
	{
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			GotoState("TrainingComplete");
		}
	}
}
*/

/*
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
		Log("Grid Targets hit: " + FString::FromInt(iGridTargetRoundsHit) + " Total shots fired: " + FString::FromInt(iGridTargetRoundsFired));
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
			PlayTip("You failed forward observer training, your accuracy was too low.  Total accuracy: " + FString::FromInt(fpTotalAccuracy),"Soft Target Accuracy: " + FString::FromInt(fpSoftAccuracy) + ", Vehicle: " + FString::FromInt(fpVehicleAccuracy) + ", Grid: " + FString::FromInt(fpGridAccuracy),5);
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
			PlayTip("Congratulations, you completed forward observer training.  Total accuracy: " + FString::FromInt(fpTotalAccuracy),"Soft Target Accuracy: " + FString::FromInt(fpSoftAccuracy) + ", Vehicle: " + FString::FromInt(fpVehicleAccuracy) + ", Grid: " + FString::FromInt(fpGridAccuracy),5);
		}
		SetTimer(1,true);
	}
	Function Timer()
	{
		ASecurity* secLocalSecurity = nullptr;
		ASecurity* scLocalSecurityClass = nullptr;
		TArray<FString> asMD5ForMap = {};
		TArray<FString> asMD5ForScript = {};
		FString sMD5ForMap = "";
		FString sMD5ForScript = "";
		if (! agpQualficationSgt.IsPlayingLIPSincAnim())
		{
			SetTimer(0,false);
			Controller.ResetAuthExtraMissionData();
			Controller.AddAuthExtraMissionData("" + FString::FromInt(iSoftTargetRoundsFired));
			Controller.AddAuthExtraMissionData("" + FString::FromInt(iSoftTargetRoundsHit));
			Controller.AddAuthExtraMissionData("" + FString::FromInt(iVehicleTargetRoundsFired));
			Controller.AddAuthExtraMissionData("" + FString::FromInt(iVehicleTargetRoundsHit));
			Controller.AddAuthExtraMissionData("" + FString::FromInt(iGridTargetRoundsFired));
			Controller.AddAuthExtraMissionData("" + FString::FromInt(iGridTargetRoundsHit));
			Controller.AddAuthExtraMissionData("" + FString::FromInt(iPracticeRoundsFired));
			Controller.AddAuthExtraMissionData("" + FString::FromInt(iPracticeRoundsHit));
			Controller.AddAuthExtraMissionData("" + FString::FromInt(GetWorld()->GetTimeSeconds()));
			scLocalSecurityClass=class<Security>(DynamicLoadObject("Engine.Security",Class'Class'));
			if (scLocalSecurityClass != nullptr)
			{
				secLocalSecurity=Spawn(scLocalSecurityClass,Controller);
				if (secLocalSecurity != nullptr)
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
				Cast<AStudentController>(Controller)->SetAuthMissionPassFlag(false);
				DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_SF","Forward Observer Training Failed","Would you like to save your results to your Personnel Jacket anyway?",128,128,7,"None","AGP_Interface.AAMissionCompletePage");
			}
			else
			{
				Controller.AddAuthExtraMissionData(sMD5ForMap);
				Controller.AddAuthExtraMissionData(sMD5ForScript);
				Cast<AStudentController>(Controller)->SetAuthMissionPassFlag(true);
				DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_SF","Forward Observer Training Complete","Would you like to save your results to your Personnel Jacket?",128,128,7,"None","AGP_Interface.AAMissionCompletePage");
			}
		}
	}
}
*/

/*
State PracticeRoundCFF
{
	Function BeginState()
	{
		if (agpPracticeSgt.Controller != nullptr)
		{
			agpPracticeSgt.Controller.Focus=Controller.Pawn;
		}
		Controller.myHUD.bPortalDebugView=false;
		fpTimeSinceLastCheckFire=0;
		ResetCurrentTarget();
		DetermineRandomTargets();
		if (FMath::FRand() > 0.5)
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
		fpPracticeStartTime=GetWorld()->GetTimeSeconds();
	}
	Function ELPlayerPressedFireNotifier()
	{
		if (agpPracticeSgt.IsPlayingLIPSincAnim())
		{
			agpPracticeSgt->StopLIPSincAnim();
		}
	}
	Function Timer()
	{
		if (((GetWorld()->GetTimeSeconds() - fpPracticeStartTime) > float(30)) && (agpusmtfdcFDC.iTotalRoundsFired == 0))
		{
			if (FMath::FRand() < 0.5)
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
		if (iPracticeTipIndex < (asPracticeTips.Num() - 2))
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
		if (((Controller.Pawn.Weapon == nullptr) || (! Controller.Pawn.Weapon->IsA(AItem_Binoculars::StaticClass()))) || (! Controller.Pawn.Weapon.IsZoomed()))
		{
			Controller.myHUD.bPortalDebugView=false;
		}
	}
	Function MortarTrainingRoundLanded(Vector vHitLocation)
	{
		EnableTargetView();
		if (FMath::Abs((vHitLocation.Y - agpPracticeSgt.Location.Y)) < float(1500))
		{
			if ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastCheckFire) > 10)
			{
				agpPracticeSgt.PlayLIPSincAnim(namePracticeCheckFire[Rand(namePracticeCheckFire.Num())],1,256,1);
				fpTimeSinceLastCheckFire=GetWorld()->GetTimeSeconds();
			}
			RunConsoleCommand("CFFCheckFire");
			return;
		}
		if (VSize((vHitLocation - agpdoCurrentTarget.Location)) > float(1250))
		{
			PlayTip(GetCorrectionNeeded(vHitLocation) + ", that round was too far off target.","Try small adjustments and walk the rounds to your target.",5);
			if ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastComment) > 15)
			{
				agpPracticeSgt.PlayLIPSincAnim(namePracticePoorShot[Rand(namePracticePoorShot.Num())],1,128,1);
				fpTimeSinceLastComment=GetWorld()->GetTimeSeconds();
			}
			return;
		}
		else
		{
			if (VSize((vHitLocation - agpdoCurrentTarget.Location)) < float(550))
			{
				if ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastComment) > 15)
				{
					agpPracticeSgt.PlayLIPSincAnim(namePracticeGoodShot[Rand(namePracticeGoodShot.Num())],1,128,1);
					fpTimeSinceLastComment=GetWorld()->GetTimeSeconds();
				}
				return;
			}
		}
		if ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastComment) > 15)
		{
			if (((float(agpusmtfdcFDC.iTotalRoundsFired) % 6) == 0) && (agpusmtfdcFDC.iTotalRoundsFired > 0))
			{
				agpPracticeSgt.PlayLIPSincAnim(namePracticeComment[Rand(namePracticeComment.Num())],1,128,1);
				fpTimeSinceLastComment=GetWorld()->GetTimeSeconds();
			}
		}
	}
	Function EnableTargetView()
	{
		if (! Controller.myHUD.bPortalDebugView)
		{
			Controller.myHUD.bShowDebugInfo=false;
			Controller.myHUD.bPortalDebugView=true;
			FocusClass(AAGP_DestroyableObjective::StaticClass(),,,agpdoCurrentTarget.Name,true);
		}
	}
	Function bool TriggerVolume_Exit(AGP_Gameplay.TriggerVolume* NotifyActor, AActor* Instigator)
	{
		if ((agpusmtfdcFDC.iRoundsFired < agpusmtfdcFDC.iMaxRoundsPerMission) && agpusmtfdcFDC.bFireMissionInProgress)
		{
			agpusmtfdcFDC.CheckFire(true);
		}
		GotoState("None");
		return true;
	}
	Function FocusClass(class<Actor>  aClass, bool bQuiet, FName TagName, FName ActorName, bool bAIOnly)
	{
		AActor* Other = nullptr;
		AActor* first = nullptr;
		bool bFound = false;
		first=nullptr;
		ForEach AllActors(aClass,Other)
		{
			if (((TagName == "None") || (Other.Tag == TagName)) && ((ActorName == "None") || (Other.Name == ActorName)))
			{
				if (bFound || (first == nullptr))
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
		if (first != nullptr)
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
		if (agpPracticeSgt.Controller != nullptr)
		{
			agpPracticeSgt.Controller.Focus=nullptr;
		}
		Controller.bCFFTrainingRoundsOnly=false;
		Controller.myHUD.bPortalDebugView=false;
	}
}
*/

void AEL_SpotterRange::PreInit()
{
	AAGP_USMortarTeamFDC* agpusmtfdcIterator = nullptr;
	bDebug = false;
	iSoftTargetRoundsHit = 0;
	iVehicleTargetRoundsHit = 0;
	iGridTargetRoundsHit = 0;
	iSoftTargetRoundsFired = 0;
	iVehicleTargetRoundsFired = 0;
	iGridTargetRoundsFired = 0;
	/*
	ForEach AllActors(AAGP_USMortarTeamFDC::StaticClass(), agpusmtfdcIterator)
	{
		agpusmtfdcFDC = agpusmtfdcIterator;
		agpusmtfdcFDC.iTotalRoundsFired = 0;
	}
	*/
	Controller->bCFFTrainingDisableCFF = true;
	agpIntroSgt = Cast<AAGP_Pawn>(CaptureEvent("IntroductionSgt",nullptr));
	agpPracticeSgt = Cast<AAGP_Pawn>(CaptureEvent("NPCPractice", nullptr));
	agpQualficationSgt = Cast<AAGP_Pawn>(CaptureEvent("NPCQualification", nullptr));
	trigSoftTargetDestroyed = Cast<ATrigger>(CaptureEvent("SoftTargetDestroyed", nullptr));
	trigSoftTargetDamaged = Cast<ATrigger>(CaptureEvent("SoftTargetDamaged", nullptr));
	trigVehicleTargetDestroyed = Cast<ATrigger>(CaptureEvent("VehicleTargetDamaged", nullptr));
	trigVehicleTargetDamaged = Cast<ATrigger>(CaptureEvent("VehicleTargetDamaged", nullptr));
	Cast<ATriggerVolume>(CaptureEvent("PracticeSpotterPosition",nullptr));
	Cast<ATriggerVolume>(CaptureEvent("PlayerMannedSpotterPosition", nullptr));
	Cast<ATriggerVolume>(CaptureEvent("SpotterTurnAroundWarning", nullptr));
	Cast<ATriggerVolume>(CaptureEvent("ReadMessageBoardTip", nullptr));
}

void AEL_SpotterRange::DetermineRandomTargets()
{
	int32 iTarget = 0;
	AAGP_DestroyableObjective* agpoIterator = nullptr;
	TArray<AAGP_DestroyableObjective*> aagpdoFoundTargets = {};
	/*
	ForEach AllActors(AAGP_DestroyableObjective::StaticClass(), agpoIterator, "SoftTarget")
	{
		agpoIterator.SetEventLab(this);
		aagpdoFoundTargets.insert(0, 1);
		aagpdoFoundTargets[0] = agpoIterator;
	}
	agpdoRandomSoftTarget = aagpdoFoundTargets[Rand(aagpdoFoundTargets.Num())];
	agpdoRandomGridSoftTarget = aagpdoFoundTargets[Rand(aagpdoFoundTargets.Num())];
	for (iTarget = 0; iTarget < aagpdoFoundTargets.Num(); iTarget++)
	{
		if (aagpdoFoundTargets[iTarget] != agpdoRandomSoftTarget)
		{
			aagpdoFoundTargets[iTarget].bInactive = true;
			aagpdoFoundTargets[iTarget].bHidden = true;
		}
		else
		{
			aagpdoFoundTargets[iTarget].bInactive = false;
			aagpdoFoundTargets[iTarget].bHidden = false;
		}
	}
	agpdoRandomSoftTarget.HUDLetter = 0;
	aagpdoFoundTargets.RemoveAt(0, aagpdoFoundTargets.Num());
	ForEach AllActors(AAGP_DestroyableObjective::StaticClass(), agpoIterator, "VehicleTarget")
	{
		agpoIterator.SetEventLab(this);
		aagpdoFoundTargets.insert(0, 1);
		aagpdoFoundTargets[0] = agpoIterator;
	}
	agpdoRandomVehicleTarget = aagpdoFoundTargets[Rand(aagpdoFoundTargets.Num())];
	for (iTarget = 0; iTarget < aagpdoFoundTargets.Num(); iTarget++)
	{
		if (aagpdoFoundTargets[iTarget] != agpdoRandomVehicleTarget)
		{
			aagpdoFoundTargets[iTarget].bInactive = true;
			aagpdoFoundTargets[iTarget].bHidden = true;
		}
		else
		{
			aagpdoFoundTargets[iTarget].bInactive = false;
			aagpdoFoundTargets[iTarget].bHidden = false;
		}
	}
	agpdoRandomVehicleTarget.HUDLetter = 1;
	Log("Found soft target of " + FString::FromInt(agpdoRandomSoftTarget) + ", hard target " + FString::FromInt(agpdoRandomVehicleTarget));
	agpdoCurrentTarget = agpdoRandomSoftTarget;
	*/
}

void AEL_SpotterRange::SpawnCurrentTargetMarker()
{
	/*
	if (bseCurrentTarget != nullptr)
	{
		bseCurrentTarget.Kill();
	}
	bseCurrentTarget = Spawn(Afx_BlackSmoke::StaticClass(), , , agpdoCurrentTarget->GetActorLocation(), FRotator(16384, 0, 0), true, true);
	bseCurrentTarget._EffectDuration = 99999;
	bseCurrentTarget.SetCollision(false, false, false);
	Log("Spawning smoke " + FString::FromInt(bseCurrentTarget) + " at location " + FString::FromInt(agpdoCurrentTarget.Location));
	*/
}

void AEL_SpotterRange::Init()
{
}

void AEL_SpotterRange::PostInit()
{
}

void AEL_SpotterRange::PostPostInit()
{
	/*
	Controller.bMortarSpotter = true;
	Controller.EventLab = this;
	GotoState("InitialIntroduction");
	*/
}

void AEL_SpotterRange::MortarDamagedTarget(AActor* agpmrdoTarget, AActor* aInstigator)
{
	//Log("Target damaged: " + FString::FromInt(agpmrdoTarget));
}

void AEL_SpotterRange::MortarDestroyedTarget(AActor* agpmrdoTarget, AActor* aInstigator)
{
	//Log("Target destroyed: " + FString::FromInt(agpmrdoTarget));
}

void AEL_SpotterRange::EnableCurrentTarget()
{
	/*
	if (agpdoCurrentTarget != nullptr)
	{
		agpdoCurrentTarget.Reset();
		agpdoCurrentTarget.bInactive = false;
		agpdoCurrentTarget.bHidden = true;
	}
	*/
}

void AEL_SpotterRange::ResetCurrentTarget()
{
	/*
	if (agpdoCurrentTarget != nullptr)
	{
		agpdoCurrentTarget.bInactive = true;
		agpdoCurrentTarget.bHidden = true;
	}
	*/
}

bool AEL_SpotterRange::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	Log("TriggerVolume entered: " + FString::FromInt(Trigger) + " -> " + FString::FromInt(Trigger.Tag));
	switch (Trigger.Tag)
	{
	case "PlayerMannedSpotterPosition":
		GotoState("QualificationIntroduction");
		break;
	case "PracticeSpotterPosition":
		GotoState("PracticeRoundCFF");
		break;
	case "SpotterTurnAroundWarning":
		PlayTip("The two forward observer locations are behind you.  Use the left position to ", "practice, the right position to qualify.", 5);
		break;
	case "ReadMessageBoardTip":
		PlayTip("As you head to the practice position be sure to check out all of the message", "boards to learn the proper techniques for Calling For Fire.", 5);
		break;
	default:
		return false;
	}
	*/
	return false;
}

bool AEL_SpotterRange::TranslateInstructorPosition(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	bInstructorTranslate = true;
	ChangeState("fadeoutstate");
	*/
	return true;
}

FString AEL_SpotterRange::GetCorrectionNeeded(FVector vHitLocation)
{
	float fpDistanceToTarget = 0;
	float fpDistanceToHit = 0;
	float fpErrorDistance = 0;
	/*
	fpDistanceToTarget = VSize((agpdoCurrentTarget.Location - Controller.Pawn.Location));
	fpDistanceToHit = VSize((vHitLocation - Controller.Pawn.Location));
	fpErrorDistance = (fpDistanceToHit - fpDistanceToTarget);
	if (fpErrorDistance > 0)
	{
		return "You must shorten your range by " + FString::FromInt(FMath::Abs(float(int((fpErrorDistance / 55))))) + " meters";
	}
	else
	{
		return "You must increase your range by " + FString::FromInt(FMath::Abs(float(int((fpErrorDistance / 55))))) + " meters";
	}
	*/
	return "FAKE";    //FAKE   /ELiZ
}
