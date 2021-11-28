// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/FSTS_EventLab/EL_VehicleTraining/EL_VehicleTraining_Gunner/EL_VehicleTraining_Gunner.h"
#include "AA29/Object/FSTS_PlayerHint/FSTS_PlayerHint.h"

AEL_VehicleTraining_Gunner::AEL_VehicleTraining_Gunner()
{
	UFSTS_PlayerHint* HintInstance0 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance0->MsgTxt1 = "Press <Action> to enter the vehicle.";
	HintInstance0->TimeBeforeRedisplay = 1;
	HintInstance0->bDisplayOnlyOnce = false;
	//HintInstance0->IsAppropriate = HintInstance0.Always;
	//HintInstance0->IsSatisfied = HintInstance0.Never;
	UFSTS_PlayerHint* HintInstance1 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance1->MsgTxt1 = "Press <SetSeatbelt> to buckle the seat belt.";
	//HintInstance1->IsAppropriate = HintInstance1.Always;
	//HintInstance1->IsSatisfied = HintInstance1.Never;
	UFSTS_PlayerHint* HintInstance2 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance2->MsgTxt1 = "Look at the CROWS display and Press <Action> to activate the weapon system.";
	HintInstance2->TimeToDisplay = 15;
	//HintInstance2->IsAppropriate = HintInstance2.Always;
	//HintInstance2->IsSatisfied = HintInstance2.Never;
	UFSTS_PlayerHint* HintInstance3 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance3->MsgTxt1 = "Use <ZoomIn> and <ZoomOut> in conjunction with the mouse to scan for targets.";
	HintInstance3->TimeToDisplay = 8;
	//HintInstance3->//LSMessage=;
	//HintInstance3->GestureAnim = "HintInstance3.Always";
	//HintInstance3->IsSatisfied = HintInstance3.Never;
	UFSTS_PlayerHint* HintInstance4 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance4->MsgTxt1 = "Press <Zoom> to activate the targeting laser.";
	//HintInstance4->//LSMessage=;
	//HintInstance4->GestureAnim = "HintInstance4.Always";
	//HintInstance4->IsSatisfied = HintInstance4.Never;
	UFSTS_PlayerHint* HintInstance5 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance5->MsgTxt1 = "Press <Fire> to fire the weapon at the target.";
	//HintInstance5->IsAppropriate = HintInstance5.Always;
	//HintInstance5->IsSatisfied = HintInstance5.Never;
	UFSTS_PlayerHint* HintInstance6 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance6->MsgTxt1 = "Go to the instructor and press <ACTION>";
	HintInstance6->MsgTxt2 = "to begin your training.";
	HintInstance6->TimeBeforeRedisplay = 1;
	HintInstance6->bDisplayOnlyOnce = false;
	//HintInstance6->IsAppropriate = HintInstance6.Always;
	//HintInstance6->IsSatisfied = HintInstance6.Never;
	//Movie = MovieTexture'T_AAO_Movies.Training.t_movies_training_bink_crows';
	MovieWidth = 1;
	MovieHeight = 1;
	EnterTheVehicleHint = HintInstance0;
	UseTheSeatbeltHint = HintInstance1;
	ActivateCROWSHint = HintInstance2;
	ZoomHint = HintInstance3;
	LaserHint = HintInstance4;
	FireHint = HintInstance5;
	UseInstructorHint = HintInstance6;
	MovieMessage = "Press the <ShowMenu> key to quit the CROWS introduction.";
	HoverTimeToShowHint = 1.25;
	/*
	LipSyncs(0) = (AnimName = "vt_gunnery_2", TargetID = 0)
		LipSyncs(1) = (AnimName = "vt_gunnery_3", TargetID = 0)
		LipSyncs(2) = (AnimName = "vt_gunnery_4", TargetID = 0)
		LipSyncs(3) = (AnimName = "vt_gunnery_5", TargetID = 0)
		LipSyncs(4) = (AnimName = "vt_gunnery_10", TargetID = 0)
		LipSyncs(5) = (AnimName = "vt_gunnery_31", TargetID = 0)
		LipSyncs(6) = (AnimName = "vt_gunnery_11", TargetID = 0)
		LipSyncs(7) = (AnimName = "vt_gunnery_6", TargetID = 0)
		LipSyncs(8) = (AnimName = "vt_gunnery_7", TargetID = 0)
		LipSyncs(9) = (AnimName = "vt_gunnery_8", TargetID = 0)
		LipSyncs(10) = (AnimName = "vt_gunnery_9", TargetID = 0)
		LipSyncs(11) = (AnimName = "None", TargetID = 0)
		LipSyncs(12) = (AnimName = "None", TargetID = 0)
		LipSyncs(13) = (AnimName = "None", TargetID = 0)
		LipSyncs(14) = (AnimName = "vt_gunnery_12", TargetID = 0)
		LipSyncs(15) = (AnimName = "vt_gunnery_13", TargetID = 0)
		LipSyncs(16) = (AnimName = "vt_gunnery_14", TargetID = 0)
		LipSyncs(17) = (AnimName = "vt_gunnery_15", TargetID = 0)
		LipSyncs(18) = (AnimName = "vt_gunnery_16", TargetID = 0)
		LipSyncs(19) = (AnimName = "vt_gunnery_17", TargetID = 0)
		LipSyncs(20) = (AnimName = "vt_gunnery_18", TargetID = 0)
		LipSyncs(21) = (AnimName = "vt_gunnery_19", TargetID = 0)
		LipSyncs(22) = (AnimName = "vt_gunnery_20", TargetID = 0)
		LipSyncs(23) = (AnimName = "vt_gunnery_21", TargetID = 0)
		LipSyncs(24) = (AnimName = "vt_gunnery_22", TargetID = 0)
		LipSyncs(25) = (AnimName = "vt_gunnery_23", TargetID = 0)
		LipSyncs(26) = (AnimName = "vt_gunnery_24", TargetID = 0)
		LipSyncs(27) = (AnimName = "vt_gunnery_25", TargetID = 0)
		LipSyncs(28) = (AnimName = "vt_gunnery_26", TargetID = 0)
		LipSyncs(29) = (AnimName = "vt_gunnery_32", TargetID = 0)
		LipSyncs(30) = (AnimName = "vt_gunnery_33", TargetID = 0)
		LipSyncs(31) = (AnimName = "None", TargetID = 0)
		LipSyncs(32) = (AnimName = "None", TargetID = 0)
		LipSyncs(33) = (AnimName = "vt_gunnery_1", TargetID = 0);
	LipSyncDebugs(0) = (Line1 = "Go ahead and hop in the CROWS, there's a video queued up for ya.", Line2 = "", Duration = 3)
		LipSyncDebugs(1) = (Line1 = "Don't forget to buckle up.", Line2 = "", Duration = 3)
		LipSyncDebugs(2) = (Line1 = "Alright...", Line2 = "Let's get you warmed up on the stationary range.", Duration = 3)
		LipSyncDebugs(3) = (Line1 = "Go ahead and practice with the CROWS", Line2 = "'til you're out of ammo.", Duration = 3)
		LipSyncDebugs(4) = (Line1 = "That's enough!", Line2 = "Let's see how good you really are.", Duration = 3)
		LipSyncDebugs(5) = (Line1 = "Ok... this is how it's going to work.  I'm going to take it slow and YOU try to hit as many targets as you can.", Line2 = "When we cross the finish line, cease fire.  Don't worry if you can't hit enough to pass, we'll keep going till you qualify.", Duration = 8)
		LipSyncDebugs(6) = (Line1 = "Here we go!", Line2 = "Fire at will!", Duration = 3)
		LipSyncDebugs(7) = (Line1 = "Not bad.", Line2 = "", Duration = 3)
		LipSyncDebugs(8) = (Line1 = "Nice shot.", Line2 = "", Duration = 3)
		LipSyncDebugs(9) = (Line1 = "Looking good.", Line2 = "", Duration = 3)
		LipSyncDebugs(10) = (Line1 = "Getting better.", Line2 = "", Duration = 3)
		LipSyncDebugs(11) = (Line1 = "Whoaaaa there, don't melt the barrel!", Line2 = "", Duration = 3)
		LipSyncDebugs(12) = (Line1 = "What's the matter did she overheat?", Line2 = "", Duration = 3)
		LipSyncDebugs(13) = (Line1 = "Relax kid... no rush!", Line2 = "Let the gun cool down a bit.", Duration = 3)
		LipSyncDebugs(14) = (Line1 = "I've seen better, but you've qualified.", Line2 = "Congratulations.", Duration = 3)
		LipSyncDebugs(15) = (Line1 = "Cutting it close huh?", Line2 = "Don't worry you passed but you might want to practice some more.", Duration = 3)
		LipSyncDebugs(16) = (Line1 = "Nice shoot'n tex.", Line2 = "Promise me I'll never end up on the other side of your barrel!", Duration = 3)
		LipSyncDebugs(17) = (Line1 = "Not bad.  Not bad at all!  Congratulations!", Line2 = "You're qualified to drive and operate the army's newest piece of butt kickin hardware.", Duration = 4)
		LipSyncDebugs(18) = (Line1 = "You have terrible aim! You call your self a soldier?", Line2 = "What do I need to do to help YOU qualify?", Duration = 3)
		LipSyncDebugs(19) = (Line1 = "What's that line they always say in those war movies? It's something like....umm... Oh!...", Line2 = "FAILURE IS NOT AN OPTION!", Duration = 4)
		LipSyncDebugs(20) = (Line1 = "Look kid, I don't want to be out here all day.", Line2 = "How about you actually aim this time?", Duration = 3)
		LipSyncDebugs(21) = (Line1 = "Yah know... I would think with all that computer assisted stuff on the CROWS that even you could qualify.", Line2 = "But maybe I was wrong.", Duration = 4)
		LipSyncDebugs(22) = (Line1 = "Ok.... Let's go over the basics.", Line2 = "You know what a crosshair is right?", Duration = 3)
		LipSyncDebugs(23) = (Line1 = "Round TWO!", Line2 = "", Duration = 3)
		LipSyncDebugs(24) = (Line1 = "Practice makes perfect.", Line2 = "", Duration = 3)
		LipSyncDebugs(25) = (Line1 = "Alrighty, one more time.", Line2 = "", Duration = 3)
		LipSyncDebugs(26) = (Line1 = "Point your weapon at the RANGE NOW!", Line2 = "", Duration = 3)
		LipSyncDebugs(27) = (Line1 = "That is not a TOY soldier. It fires REAL BULLETS.", Line2 = "Keep your gun pointed at the range at all times.", Duration = 3)
		LipSyncDebugs(28) = (Line1 = "This is your last warning!", Line2 = "", Duration = 3)
		LipSyncDebugs(29) = (Line1 = "If you Lase a target, the CROWS will automatically adjust it's firing position ", Line2 = "to match up with your on-screen crosshair at that range.", Duration = 3)
		LipSyncDebugs(30) = (Line1 = "You can use the CROWS multiple optic zoom levels to get the best shot.", Line2 = "Don't forget to lase your targets.", Duration = 3)
		LipSyncDebugs(31) = (Line1 = "", Line2 = "", Duration = 0)
		LipSyncDebugs(32) = (Line1 = "", Line2 = "", Duration = 0)
		LipSyncDebugs(33) = (Line1 = "Hey...  You're back.", Line2 = "Ready for some CROWS gunnery tranin?", Duration = 3.5);
	//GameSounds=;
	//GestureAnim=;

	*/
	//TurnTowardPlayer = false;
	bUseLevelBeginFadeIn = true;
	LevelBeginFadeInTime = 3.5;
}

//const HitsToRegister = 5;
//const MobileTargets = 9;
//const TowerRadius = 1600.0;
//const TimeBetweenComments = 5.0;
//const HighPassScore = 9;
//const LowPassScore = 7;
//const StationaryShots = 20;
//const WarningFrequency = 5.0;
//const AimCheckFrequency = 0.5;
//const TowerTag = 'tower';
//const TrainingVehicleTag = 'TrainingVehicle';
//const MobileBoundsTag = 'MobileBounds';
//const StationaryBoundsTag = 'StationaryBounds';
//const MobileFinishNodeTag = 'MobileFinish';
//const MobileStartNodeTag = 'MobileStart';
//const MobileEntranceNodeTag = 'MobileEntrance';
//const StationaryNodeTag = 'Stationary';
//const GateNodeTag = 'GunneryGate';
//const VehicleStartNodeTag = 'StartHere';
//const VehicleEntryPointTag = 'EntryPoint';


/*
auto State InitialDrive
{
	Function BeginState()
	{
		Super::BeginState();
		if (TrainingVehicle == None)
		{
			AssignTrainingVehicle();
		}
	}
	simulated Function DrillSergeantUsed(AAGP_Character* Sarge)
	{
		if ((Sarge.Tag == 'Frank') && (!bTalkedToFrank))
		{
			bTalkedToFrank = true;
			GotoState('InitialDrive','DSTalk');
		}
	}
	Function PlayCROWSMovie()
	{
		if (Controller.myHUD != None)
		{
			if (FSTS_CROWS_HUD(Controller.myHUD) != None)
			{
				FSTS_CROWS_HUD(Controller.myHUD).SetMessage(ReplaceCommandString(MovieMessage));
				FSTS_CROWS_HUD(Controller.myHUD).bShowMessage = true;
			}
			Controller.myHUD.PlayMovieScaled(Movie,(0.5 - (0.5 * MovieWidth)),(0.5 - (0.5 * MovieHeight)),(0.5 + (0.5 * MovieWidth)),(0.5 + (0.5 * MovieHeight)),true,false);
			Controller.myHUD.TextureMovie.Movie.SetVolume(1);
		}
	}
	Function SetVehicleAtStationary()
	{
		local Actor.EPhysics OldPhysics;
		local AAGP_Vehicle*Node Start;
		if (TrainingVehicle == None)
		{
			AssignTrainingVehicle();
		}
		TrainingVehicle.Ignition();
		Start = GetVehicleNode('node12');
		OldPhysics = TrainingVehicle.Physics;
		TrainingVehicle.SetPhysics(PHYS_None);
		TrainingVehicle.SetLocation(Start.Location);
		TrainingVehicle.SetRotation(rotator((Start.NextNode.Location - Start.Location)));
		TrainingVehicle.SetPhysics(OldPhysics);
		TrainingVehicle.Shifter = 0;
		CROWS_Gunner(TrainingVehicle.Positions[GunnerPosition]).ActivateCrows();
	}
Begin:
	PlayerLock(true,false);
	Sgt.Pawn.bUseActionIcon = false;
	PlayLSMessage(33);
	Sleep(4);
	PlayLSMessage(0);
	Sleep(3.5);
	Sgt.MoveToward(EntryPoint,TrainingVehicle,,true,true);
	Sleep(3.5);
	Sgt.MoveTo(Sgt.Pawn.Location);
	GetInVehicle();
	if (TrainingVehicle != None)
	{
		TrainingVehicle.bDoorsLocked = false;
	}
	PlayerLock(false,false);
	if (bPlayerInCrows)
	{
		PlayLSMessage(1);
		Sleep(3);
	}
	else
	{
		Sleep(2);
		JL'EnterCROWS'
;
	}
	if (IsCrowsActive())
	{
		SetVehicleAtStationary();
		PlayCROWSMovie();
		FadeInBlack(0.5);
	}
	else
	{
		Sleep(0.5);
		JL'DriveToGunnery'
;
	}
	if (!Level.GetLocalPlayerController().myHUD.IsMoviePlaying())
	{
		if (FSTS_CROWS_HUD(Controller.myHUD) != None)
		{
			FSTS_CROWS_HUD(Controller.myHUD).bShowMessage = false;
		}
		TrainingVehicle.bDoorsLocked = true;
		Sleep(0.5);
		PlayLSMessage(2);
		Sleep(5);
		SetPath('GunneryGate','Stationary');
		StartDriving(true);
		TrainingVehicle.Horn();
		Sleep(0.75);
		TrainingVehicle.Horn();
		Sleep(1.5);
		PlayGameSound('vt_gunnery_27',tower,,2,1600);
		Sleep(3);
		TargetManagerPracticeMode(StationaryTargetManager,true);
		TargetManagerActive(StationaryTargetManager,true);
		SetTargetManagerScoreKeeper(StationaryTargetManager);
	}
	else
	{
		Sleep(0.25);
		JL'WaitForMovieEnd'
;
	}
}

State StationaryFiring
{
	Function BeginState()
	{
		Super::BeginState();
		ShotsFired = 0;
		PlayLSMessage(3);
		SetRange('StationaryBounds');
	}
	Function bool TargetMover_Damaged(AGP_Gameplay.TargetMover NotifyActor, AActor* Instigator, FString Parms)
	{
		if (((Level.TimeSeconds - lastCommentMade) > 5) && (FRand() < 0.5))
		{
			PlayLSMessage((7 + Rand(4)));
			lastCommentMade = Level.TimeSeconds;
		}
		return true;
	}
	Function bool VehicleWeapon_Fire(AGP_Vehicles.VehicleWeapon NotifyActor, AActor* Instigator, FString Parms)
	{
		ShotsFired++;
		if (ShotsFired >= 20)
		{
			TargetManagerActive(StationaryTargetManager,false);
			GotoState('DriveToMobile');
		}
		return true;
	}
Begin:
	Sleep(5);
	QueueHint(ZoomHint);
	QueueHint(LaserHint);
	QueueHint(FireHint);
	bCheckAim = true;
	if (FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]) != None)
	{
		FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]).bSafety = false;
	}
}

State DriveToMobile
{
Begin:
	bCheckAim = false;
	if (FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]) != None)
	{
		FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]).bSafety = true;
	}
	Sleep(2);
	PlayLSMessage(4);
	SetPath('Stationary','MobileStart');
	StartDriving(true);
}

State MobileFiring
{
	Function bool TargetMover_Damaged(AGP_Gameplay.TargetMover NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 i = 0;
		for (i = 0; i < 9; i++)
		{
			if (TargetInfos[i].Target == NotifyActor)
			{
				if (TargetInfos[i].Triggered)
				{
					return true;
				}
				TargetInfos[i].hits++;
				if (TargetInfos[i].hits >= 5)
				{
					TargetInfos[i].Target.UnTrigger(NotifyActor,Player);
					TargetInfos[i].Triggered = true;
					MobileTargetManager.ReportTargetDown(NotifyActor.GroupNumber,true);
				}
				return true;
			}
			else
			{
				if (TargetInfos[i].Target == None)
				{
					TargetInfos[i].Target = NotifyActor;
					TargetInfos[i].hits++;
					return true;
				}
			}
		}
		return true;
	}
Begin:
	SetRange('MobileBounds');
	PlayLSMessage(5);
	Sleep(17);
	PlayGameSound('vt_gunnery_28',tower,,2,1600);
	Sleep(4);
	PlayLSMessage(6);
	bCheckAim = true;
	if (FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]) != None)
	{
		FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]).bSafety = false;
	}
	if (FSTS_CROWS_HUD(Controller.myHUD) != None)
	{
		FSTS_CROWS_HUD(Controller.myHUD).SetScore(MobileTargetManager._ScoreKeeper,9);
	}
	SetPath('MobileStart','MobileFinish');
	StartDriving(true);
}

State Finish
{
	Function RetryCourse()
	{
		local XInterface.GUIController gController;
		gController = GUIController(Level.GetLocalPlayerController().Player.GUIController);
		if (gController != None)
		{
			gController.CloseAll(false);
		}
		GotoState('Retrying');
	}
	Function ShowScore()
	{
		FString scoreMessage = "";
		local XInterface.GUIController gController;
		local AGP_Interface.AAMissionCompletePage page;
		local AGP_Interface.AAMissionCompletePageEx pageEx;
		scoreMessage = "Targets Hit:  " $ string(finalScore);
		if (finalScore < 7)
		{
			DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_sf","Mission Failed.",scoreMessage,128,128,7,'None');
		}
		else
		{
			HandlePassResults();
		}
		gController = GUIController(Controller.Player.GUIController);
		if (gController != None)
		{
			pageEx = AAMissionCompletePageEx(gController.ActivePage);
			page = AAMissionCompletePage(gController.ActivePage);
		}
		if (page != None)
		{
			page.__Retry__Delegate = Self.RetryCourse;
		}
		else
		{
			if (pageEx != None)
			{
				pageEx.__Retry__Delegate = Self.RetryCourse;
			}
		}
	}
	Function HandlePassResults()
	{
		local Security secLocalSecurity;
		local class<Security>  scLocalSecurityClass;
		local TArray<FString> asMD5ForMap;
		local TArray<FString> asMD5ForScript;
		FString sMD5ForMap = "";
		FString sMD5ForScript = "";
		if (FSTS_PlayerController(Controller).IsUsingCheats())
		{
			DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_sf","Vehicle Gunner Training Complete","Would you like to try again?",128,128,7,'None',"AGP_Interface.AAMissionCompletePageEx");
			return;
		}
		Controller.SetAuthMissionPassFlag(true);
		Controller.ResetAuthExtraMissionData();
		Controller.AddAuthExtraMissionData(string(finalScore));
		scLocalSecurityClass = class<Security>(DynamicLoadObject("Engine.Security",Class'Class'));
		if (scLocalSecurityClass != None)
		{
			secLocalSecurity = Spawn(scLocalSecurityClass,Controller);
			if (secLocalSecurity != None)
			{
				secLocalSecurity.LocalPerform(2,"../Maps/Vehicle_Training_Gunner.aao","",asMD5ForMap);
				secLocalSecurity.LocalPerform(2,"../System/FSTS.u","",asMD5ForScript);
				sMD5ForMap = asMD5ForMap[0];
				sMD5ForScript = asMD5ForScript[0];
			}
		}
		Controller.AddAuthExtraMissionData("");
		Controller.AddAuthExtraMissionData("");
		Controller.AddAuthExtraMissionData("");
		Controller.AddAuthExtraMissionData("");
		Controller.AddAuthExtraMissionData("");
		Controller.AddAuthExtraMissionData("");
		Controller.AddAuthExtraMissionData("");
		Controller.AddAuthExtraMissionData("");
		Controller.AddAuthExtraMissionData("");
		Controller.AddAuthExtraMissionData("");
		Controller.AddAuthExtraMissionData(sMD5ForMap);
		Controller.AddAuthExtraMissionData(sMD5ForScript);
		DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_sf","Congratulations! You passed ","Vehicle Training - Gunner.",128,128,7,'None',"AGP_Interface.AAMissionCompletePageEx");
	}
	Function MakeComment()
	{
		int32 commentSlot = 0;
		if (finalScore >= 9)
		{
			commentSlot = (16 + Rand(2));
		}
		else
		{
			if (finalScore < 7)
			{
				commentSlot = (18 + Rand(5));
			}
			else
			{
				commentSlot = (14 + Rand(2));
			}
		}
		PlayLSMessage(commentSlot);
	}
Begin:
	bCheckAim = false;
	finalScore = GetTargetManagerTotalScore(MobileTargetManager);
	PlayGameSound('vt_gunnery_30',tower,,2,1600);
	Sleep(4);
	MakeComment();
	Sleep(5);
	ShowScore();
	SetPath('MobileFinish','StartHere');
	StartDriving(true);
	Sleep(2);
	JL'Loop'
;
}

State Retrying
{
	Function ResetPosition()
	{
		local Actor.EPhysics OldPhysics;
		local AAGP_Vehicle*Node Start;
		Start = GetVehicleNode('MobileStart');
		OldPhysics = TrainingVehicle.Physics;
		TrainingVehicle.SetPhysics(PHYS_None);
		TrainingVehicle.SetLocation(Start.Location);
		TrainingVehicle.SetRotation(rotator((Start.NextNode.Location - Start.Location)));
		TrainingVehicle.SetPhysics(OldPhysics);
		TrainingVehicle.Shifter = 0;
	}
	Function ResetTargets()
	{
		int32 i = 0;
		for (i = 0; i < 9; i++)
		{
			TargetInfos[i].Target = None;
			TargetInfos[i].hits = 0;
			TargetInfos[i].Triggered = false;
		}
	}
Begin:
	PlayerLock(true,true);
	if (FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]) != None)
	{
		FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]).bSafety = true;
	}
	PlayLSMessage((23 + Rand(3)));
	Sleep(4);
	FadeOutBlack(1);
	Sleep(1);
	PlayerLock(false,false);
	Sgt.GotoState('None');
	if (CROWS_HMMWV(Sgt.Pawn) != None)
	{
		CROWS_HMMWV(Sgt.Pawn).Shifter = 0;
	}
	ResetPosition();
	ResetTargets();
	Sleep(1);
	FadeInBlack(0.5);
	Vehicle_At(TrainingVehicle,Controller,string('MobileStart'));
}

State FiringError
{
Begin:
	PlayerLock(true,true);
	Sgt.MoveTo(TrainingVehicle.Location);
	PlayGameSound('vt_gunnery_30',tower,,,1600);
	Sleep(2.5);
	DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_sf","Mission Failed.","You must not fire off range.",128,128,7,'None');
}

State NPCWounded
{
Begin:
	PlayerLock(true,true);
	Sgt.MoveTo(TrainingVehicle.Location);
	PlayGameSound('vt_gunnery_30',tower,,,1600);
	Sleep(2.5);
	ConsoleCommand("open Leavenworth");
}
*/

void PostInit()
{
	/*
	local AGP_Gameplay.TargetManager TM;
	Super::PostInit();
	SetUpHints();
	ForEach DynamicActors(Class'AGP_Gameplay.TargetManager', TM)
	{
		if (TM.Tag == 'StationaryRange')
		{
			StationaryTargetManager = TM;
		}
		else
		{
			if (TM.Tag == 'MobileRange')
			{
				MobileTargetManager = TM;
			}
		}
		if ((StationaryTargetManager != None) && (MobileTargetManager != None))
		{
			GOTO JL0081;
		}
	JL0081:
	}
	ForEach AllActors(Class'Actor', tower, 'tower')
	{
		GOTO JL009B;
	JL009B:
	}
	ForEach AllActors(Class'PathNode', EntryPoint, 'EntryPoint')
	{
		GOTO JL00B5;
	JL00B5:
	}
	bCheckAim = false;
	WarningNumber = 0;
	SetTimer(Self.0.5, false);
	*/
}

void AEL_VehicleTraining_Gunner::AssignSgt()
{
	/*
	Super::AssignSgt();
	Sgt.Focus = Player;
	*/
}

AAGP_VehicleNode* AEL_VehicleTraining_Gunner::GetVehicleNode(FName nodeTag)
{
	/*
	local AAGP_Vehicle*Node Node;
	ForEach AllActors(Class'AAGP_Vehicle*Node', Node, nodeTag)
	{
		return Node;
	}
	*/
	return nullptr;
}

void AEL_VehicleTraining_Gunner::AssignTrainingVehicle()
{
	/*
	ForEach AllActors(class'FSTS.CROWS_HMMWV_Gunner', TrainingVehicle, 'TrainingVehicle')
	{
		GOTO JL0019;
	JL0019:
	}
	*/
}

bool AGP_Vehicle_Spawned(AAGP_VehicleFactory* SpawningFactory, AAGP_Vehicle* NewVehicle, FString Parms)
{
	/*
	Super::AGP_Vehicle_Spawned(SpawningFactory, NewVehicle, Parms);
	if ((NewVehicle.Tag == 'TrainingVehicle') && (CROWS_HMMWV_Gunner(NewVehicle) != None))
	{
		TrainingVehicle = CROWS_HMMWV_Gunner(NewVehicle);
		TrainingVehicle.bEnableChangePosition = false;
	}
	else
	{
		if ((NewVehicle == Vehicle) && (AVehicle* != None))
		{
			Vehicle.bEnableChangePosition = false;
			if (CROWS_HMMWV_Gunner(Vehicle) != None)
			{
				CROWS_HMMWV_Gunner(Vehicle).bDoorsLocked = true;
			}
		}
	}
	*/
	return true;
}

bool AEL_VehicleTraining_Gunner::VehiclePosition_Entered(AVehiclePosition* Position, AActor* aController, FString Parms)
{
	/*
	if ((PlayerController(aController) != None) && (Position == TrainingVehicle.Positions[GunnerPosition]))
	{
		bPlayerInCrows = true;
	}
	*/
	return true;
}

bool AEL_VehicleTraining_Gunner::VehiclePosition_Exited(AVehiclePosition* Position, AActor* aController, FString Parms)
{
	/*
	if ((PlayerController(aController) != None) && (Position == TrainingVehicle.Positions[GunnerPosition]))
	{
		bPlayerInCrows = false;
	}
	*/
	return true;
}

void AEL_VehicleTraining_Gunner::GetInVehicle()
{
	/*
	if (TrainingVehicle == None)
	{
		AssignTrainingVehicle();
	}
	TrainingVehicle.Positions[3].KDriverEnter(Sgt.Pawn);
	HMMWVRunningBoardAnimManager(TrainingVehicle.Positions[3].AnimManager).DestVehicle = TrainingVehicle;
	HMMWVRunningBoardAnimManager(TrainingVehicle.Positions[3].AnimManager).PlayVehicleEnterAnim();
	*/
}

void AEL_VehicleTraining_Gunner::SetPath(FName startTag, FName endTag)
{
	/*
	if (startTag != 'None')
	{
		Sgt.SetCurrentNode(GetVehicleNode(startTag));
	}
	else
	{
		Sgt.SetCurrentNode(None);
	}
	if (endTag != 'None')
	{
		Sgt.SetDestination(GetVehicleNode(endTag));
	}
	else
	{
		Sgt.SetDestination(None);
	}
	*/
}

void AEL_VehicleTraining_Gunner::StartDriving(bool startWithNext)
{
	/*
	if (startWithNext)
	{
		Sgt.SetCurrentNode(Sgt.CurIntermediate.NextNode);
	}
	Sgt.Trigger(Self, None);
	*/
}

bool AEL_VehicleTraining_Gunner::Vehicle_At(AAGP_Vehicle* aVehicle, AActor* aController, FString NavigationTag)
{
	/*
	switch (NavigationTag)
	{
	case string('Stationary'):
		CROWS_Base(TrainingVehicle.Positions[GunnerPosition].Gun).Ammo = CROWS_Base(TrainingVehicle.Positions[GunnerPosition].Gun).Default.Ammo;
		GotoState('StationaryFiring');
		break;
	case string('MobileEntrance'):
		PlayGameSound('vt_gunnery_29', tower, , 2, 1600);
		break;
	case string('MobileStart'):
		CROWS_Base(TrainingVehicle.Positions[GunnerPosition].Gun).Ammo = CROWS_Base(TrainingVehicle.Positions[GunnerPosition].Gun).Default.Ammo;
		MobileTargetManager.StartDispatch();
		TargetManagerPracticeMode(MobileTargetManager, true);
		TargetManagerActive(MobileTargetManager, true);
		SetTargetManagerScoreKeeper(MobileTargetManager);
		GotoState('MobileFiring');
		break;
	case string('MobileFinish'):
		TargetManagerActive(MobileTargetManager, false);
		GotoState('Finish');
		break;
	default:
	}
	*/
	return true;
}

void AEL_VehicleTraining_Gunner::RetryCourse()
{
}

void AEL_VehicleTraining_Gunner::Timer()
{
	/*
	if (bCheckAim)
	{
		bPointingAtRange = PointingAtRange();
		if (!bPointingAtRange)
		{
			if ((WarningNumber == 0) || ((Level.TimeSeconds - LastWarningTime) >= 5))
			{
				if (WarningNumber == 3)
				{
					DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_sf", "Mission Failed.", "You must not aim away from the range.", 128, 128, 7, 'None');
				}
				PlayLSMessage((WarningNumber + 26));
				WarningNumber++;
				LastWarningTime = Level.TimeSeconds;
			}
		}
		else
		{
			WarningNumber = 0;
		}
	}
	SetTimer(Self.0.5, false);
	*/
}

void AEL_VehicleTraining_Gunner::SetRange(FName boundsTag)
{
	/*
	local AActor* M;
	local AActor* marker1;
	local AActor* marker2;
	ForEach AllActors(Class'Actor', M, boundsTag)
	{
		if (marker1 == None)
		{
			marker1 = M;
			continue;
		}
		else
		{
			if (marker2 == None)
			{
				marker2 = M;
			}
		}
		else
		{
		}
	}
	Self.RangeStart = marker1.Location;
	Self.RangeBounds = (marker2.Location - marker1.Location);
	Self.RangeBoundsPerp.X = (-Self.RangeBounds.Y);
	Self.RangeBoundsPerp.Y = Self.RangeBounds.X;
	Self.RangeStart.Z = 0;
	Self.RangeBounds.Z = 0;
	Self.RangeBoundsPerp.Z = 0;
	*/
}

bool AEL_VehicleTraining_Gunner::PointingAtRange()
{
	/*
	FVector GunPosition = FVector(0, 0, 0);
	FVector GunDirection = FVector(0, 0, 0);
	FVector GunDirectionPerp = FVector(0, 0, 0);
	FVector RangeStartToGun = FVector(0, 0, 0);
	float rangeIntersect = 0;
	float aimIntersect = 0;
	if (TrainingVehicle == None)
	{
		return false;
	}
	GunPosition = TrainingVehicle.Positions[GunnerPosition].Location;
	GunDirection = Vector(TrainingVehicle.Positions[GunnerPosition].Rotation);
	GunPosition.Z = 0;
	RangeStartToGun = (GunPosition - RangeStart);
	GunDirectionPerp.X = (-GunDirection.Y);
	GunDirectionPerp.Y = GunDirection.X;
	GunDirectionPerp.Z = 0;
	aimIntersect = ((Self.RangeBoundsPerp Dot RangeStartToGun) / (GunDirectionPerp Dot Self.RangeBounds));
	if (aimIntersect < 0)
	{
		return false;
	}
	rangeIntersect = ((GunDirectionPerp Dot RangeStartToGun) / (GunDirectionPerp Dot Self.RangeBounds));
	if ((rangeIntersect < 0) || (rangeIntersect > 1))
	{
		return false;
	}
	*/
	return true;
}

bool AEL_VehicleTraining_Gunner::VehicleWeapon_Fire(AVehicleWeapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	if (bCheckAim)
	{
		if (!bPointingAtRange)
		{
			GotoState('FiringError');
		}
	}
	*/
	return true;
}

bool AEL_VehicleTraining_Gunner::AGP_NPC_Damaged(AAGP_NPC* NotifyActor, AController* aInstigator)
{
	//GotoState('NPCWounded');
	return true;
}

bool AEL_VehicleTraining_Gunner::AGP_NPC_Died(AAGP_NPC* NotifyActor, AController* aInstigator)
{
	//GotoState('NPCWounded');
	return true;
}

bool AEL_VehicleTraining_Gunner::CloseToFrank()
{
	//return (VSize((Player.Location - Sgt.Pawn.Location)) < 256);
	return false;    //FAKE   /ELiZ
}

bool AEL_VehicleTraining_Gunner::HasTalkedToFrank()
{
	//return bTalkedToFrank;
	return false;    //FAKE   /ELiZ
}

bool AEL_VehicleTraining_Gunner::CloseToVehicle()
{
	//return (bTalkedToFrank && (VSize((Player.Location - TrainingVehicle.Location)) < 180));
	return false;    //FAKE   /ELiZ
}

bool AEL_VehicleTraining_Gunner::InCrows()
{
	//return bPlayerInCrows;
	return false;    //FAKE   /ELiZ
}

bool AEL_VehicleTraining_Gunner::IsCrowsActive()
{
	//return CROWS_Gunner(TrainingVehicle.Positions[GunnerPosition]).bInCROWS;
	return false;    //FAKE   /ELiZ
}

bool AEL_VehicleTraining_Gunner::IsWearingSeatbelt()
{
	//return TrainingVehicle.Positions[GunnerPosition].bWearingSeatbelt;
	return false;    //FAKE   /ELiZ
}

bool AEL_VehicleTraining_Gunner::AtStationaryRange()
{
	//return IsInState('StationaryFiring');
	return false;    //FAKE   /ELiZ
}

bool AEL_VehicleTraining_Gunner::AimingAtTarget()
{
	/*
	FVector GunPosition = FVector(0, 0, 0);
	FVector GunRotation = FVector(0, 0, 0);
	local AActor* hitTarget;
	FVector HitLoc = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	if (bHovering)
	{
		return true;
	}
	if (TrainingVehicle == None)
	{
		return false;
	}
	GunPosition = TrainingVehicle.Positions[GunnerPosition].Location;
	GunRotation = Vector(TrainingVehicle.Positions[GunnerPosition].Rotation);
	hitTarget = Trace(HitLoc, HitNormal, (GunPosition + (float(16000) * GunRotation)), GunPosition);
	if ((hitTarget != None) && (TargetMover(hitTarget) != None))
	{
		if (TargetStartTime == 0)
		{
			TargetStartTime = Level.TimeSeconds;
		}
		else
		{
			if ((Level.TimeSeconds - TargetStartTime) >= HoverTimeToShowHint)
			{
				bHovering = true;
				return true;
			}
		}
	}
	else
	{
		TargetStartTime = 0;
	}
	*/
	return false;
}

bool AEL_VehicleTraining_Gunner::HasLased()
{
	/*
	if (AtStationaryRange())
	{
		if ((TrainingVehicle != None) && (FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]) != None))
		{
			return FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]).bHasLased;
		}
	}
	*/
	return false;
}

bool AEL_VehicleTraining_Gunner::HasZoomed()
{
	/*
	if ((TrainingVehicle != None) && (FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]) != None))
	{
		return FSTS_CROWS_Gunner50cal(TrainingVehicle.Positions[GunnerPosition]).bHasZoomed;
	}
	*/
	return false;
}

void AEL_VehicleTraining_Gunner::SetUpHints()
{
	/*
	UseInstructorHint.__IsAppropriate__Delegate = CloseToFrank;
	UseInstructorHint.__IsSatisfied__Delegate = HasTalkedToFrank;
	EnterTheVehicleHint.__IsAppropriate__Delegate = CloseToVehicle;
	EnterTheVehicleHint.__IsSatisfied__Delegate = InCrows;
	UseTheSeatbeltHint.__IsAppropriate__Delegate = InCrows;
	UseTheSeatbeltHint.__IsSatisfied__Delegate = IsWearingSeatbelt;
	ActivateCROWSHint.__IsAppropriate__Delegate = InCrows;
	ActivateCROWSHint.__IsSatisfied__Delegate = IsCrowsActive;
	ZoomHint.__IsAppropriate__Delegate = AtStationaryRange;
	ZoomHint.__IsSatisfied__Delegate = HasZoomed;
	LaserHint.__IsAppropriate__Delegate = AimingAtTarget;
	LaserHint.__IsSatisfied__Delegate = HasLased;
	FireHint.__IsAppropriate__Delegate = HasLased;
	QueueHint(UseInstructorHint);
	QueueHint(EnterTheVehicleHint);
	QueueHint(UseTheSeatbeltHint);
	QueueHint(ActivateCROWSHint);
	*/
}
