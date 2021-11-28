// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/FSTS_EventLab/EL_VehicleTraining/EL_VehicleTraining_Driver/EL_VehicleTraining_Driver.h"
#include "AA29/Object/FSTS_PlayerHint/FSTS_PlayerHint.h"

AEL_VehicleTraining_Driver::AEL_VehicleTraining_Driver()
{
	UFSTS_PlayerHint* HintInstance0 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance0->MsgTxt1 = "Look at the door and";
	HintInstance0->MsgTxt2 = "Press <ACTION> to enter.";
	HintInstance0->TimeToDisplay = 9999;
	HintInstance0->TimeBeforeRedisplay = 1;
	HintInstance0->bDisplayOnlyOnce = false;
	//HintInstance0->IsAppropriate = HintInstance0.Always;
	//HintInstance0->IsSatisfied = HintInstance0.Never;
	UFSTS_PlayerHint* HintInstance1 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance1->MsgTxt1 = "Press <SETSEATBELT> to fasten your seatbelt.";
	HintInstance1->TimeToDisplay = 10;
	//HintInstance1->//SatisfiedLSMessage=;
	//HintInstance1->GestureAnim = "HintInstance1.Always";
	//HintInstance1->IsSatisfied = HintInstance1.Never;
	UFSTS_PlayerHint* HintInstance2 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance2->MsgTxt1 = "Look at the steering wheel and";
	HintInstance2->MsgTxt2 = "Press <ACTION> to start the engine.";
	HintInstance2->TimeToDisplay = 9999;
	//HintInstance2->IsAppropriate = HintInstance2.Always;
	//HintInstance2->IsSatisfied = HintInstance2.Never;
	UFSTS_PlayerHint* HintInstance3 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance3->MsgTxt1 = "Press <LeanLeft> or <LeanRight>";
	HintInstance3->MsgTxt2 = "to look in the rear view mirrors.";
	HintInstance3->TimeToDisplay = 10;
	//HintInstance3->//LSMessage=;
	//HintInstance3->GestureAnim = "HintInstance3.Always";
	//HintInstance3->IsSatisfied = HintInstance3.Never;
	UFSTS_PlayerHint* HintInstance4 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance4->MsgTxt1 = "Use <Zoomin> and <Zoomout>";
	HintInstance4->MsgTxt2 = "to shift between Park, Drive, and Reverse.";
	HintInstance4->TimeToDisplay = 10;
	//HintInstance4->IsAppropriate = HintInstance4.Always;
	//HintInstance4->IsSatisfied = HintInstance4.Never;
	UFSTS_PlayerHint* HintInstance5 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance5->MsgTxt1 = "Use <AltFire>";
	HintInstance5->MsgTxt2 = "to switch between Hi and Low gears.";
	HintInstance5->TimeToDisplay = 10;
	//HintInstance5->//LSMessage=;
	//HintInstance5->GestureAnim = "HintInstance5.Always";
	//HintInstance5->IsSatisfied = HintInstance5.Never;
	UFSTS_PlayerHint* HintInstance6 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance6->MsgTxt1 = "Go to the instructor and press <ACTION>";
	HintInstance6->MsgTxt2 = "to begin your training.";
	HintInstance6->TimeToDisplay = 9999;
	//HintInstance6->IsAppropriate = HintInstance6.Always;
	//HintInstance6->IsSatisfied = HintInstance6.Never;
	UFSTS_PlayerHint* HintInstance7 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance7->MsgTxt1 = "Press <MOVEFORWARD> to accelerate the vehicle.";
	HintInstance7->TimeToDisplay = 10;
	//HintInstance7->IsAppropriate = HintInstance7.Always;
	//HintInstance7->IsSatisfied = HintInstance7.Never;
	UFSTS_PlayerHint* HintInstance8 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance8->MsgTxt1 = "Press <StrafeLeft> or <StrafeRight>";
	HintInstance8->MsgTxt2 = "to steer left or right.";
	HintInstance8->TimeToDisplay = 10;
	//HintInstance8->IsAppropriate = HintInstance8.Always;
	//HintInstance8->IsSatisfied = HintInstance8.Never;
	UFSTS_PlayerHint* HintInstance9 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance9->MsgTxt1 = "You seem to have gotten stuck.";
	HintInstance9->MsgTxt2 = "We'll be starting over now.";
	HintInstance9->TimeToDisplay = 10;
	//HintInstance9->//LSMessage=;
	//HintInstance9->GestureAnim = "HintInstance9.Always";
	//HintInstance9->IsSatisfied = HintInstance9.Never;
	UFSTS_PlayerHint* HintInstance10 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance10->MsgTxt1 = "Whoa! You are gonna roll this thing!";
	HintInstance10->MsgTxt2 = "Settle down now.";
	//HintInstance10->//LSMessage=;
	//HintInstance10->GetActorByTag = 5;
	//HintInstance10->IsAppropriate = HintInstance10.Always;
	//HintInstance10->IsSatisfied = HintInstance10.Never;
	UFSTS_PlayerHint* HintInstance11 = NewObject<UFSTS_PlayerHint>(UFSTS_PlayerHint::StaticClass());
	HintInstance11->MsgTxt1 = "You have damaged the vehicle beyond repair.";
	HintInstance11->MsgTxt2 = "We will have to start over.";
	HintInstance11->TimeToDisplay = 6;
	//HintInstance11->//LSMessage=;
	//HintInstance11->GestureAnim = "HintInstance11.Always";
	//HintInstance11->IsSatisfied = HintInstance11.Never;
	CheckpointString1 = "Checkpoint %NUM% reached.";
	CheckpointString2 = "%REMAINING% more to go.";
	VehicleStuckTime = -1;
	RestartMessage = "Level must be restarted to pass.";
	StaticGunnerVehicleTag = "StaticGunnerVehicle";
	MobileGunnerVehicleTag = "MobileGunnerVehicle";
	UseInstructorHint = HintInstance6;
	EnterTheVehicleHint = HintInstance0;
	UseTheSeatbeltHint = HintInstance1;
	StartTheCarHint = HintInstance2;
	LookInTheMirrorHint = HintInstance3;
	ShiftGearsHint = HintInstance4;
	MoveForwardHint = HintInstance7;
	SteeringHint = HintInstance8;
	SpeedRangeHint = HintInstance5;
	VehicleStuckHint = HintInstance9;
	VehicleTippingHint = HintInstance10;
	VehicleDisabledHint = HintInstance11;
	ActionHintString2 = "to get into the driver's seat.";
	ActionHintString4 = "to get out of the driver's seat.";
	/*
	LipSyncs(0) = (AnimName = "vt_driving_1",TargetID = 0)
	LipSyncs(1) = (AnimName = "vt_driving_2",TargetID = 0)
	LipSyncs(2) = (AnimName = "vt_driving_3",TargetID = 0)
	LipSyncs(3) = (AnimName = "vt_driving_4",TargetID = 0)
	LipSyncs(4) = (AnimName = "vt_driving_5",TargetID = 0)
	LipSyncs(5) = (AnimName = "vt_driving_6",TargetID = 0)
	LipSyncs(6) = (AnimName = "vt_driving_7",TargetID = 0)
	LipSyncs(7) = (AnimName = "vt_driving_8",TargetID = 0)
	LipSyncs(8) = (AnimName = "vt_driving_9",TargetID = 0)
	LipSyncs(9) = (AnimName = "vt_driving_10",TargetID = 0)
	LipSyncs(10) = (AnimName = "vt_driving_11",TargetID = 0)
	LipSyncs(11) = (AnimName = "vt_driving_12",TargetID = 0)
	LipSyncs(12) = (AnimName = "vt_driving_13",TargetID = 0)
	LipSyncs(13) = (AnimName = "vt_driving_14",TargetID = 0)
	LipSyncs(14) = (AnimName = "vt_driving_22",TargetID = 0)
	LipSyncs(15) = (AnimName = "vt_driving_15",TargetID = 0)
	LipSyncs(16) = (AnimName = "vt_driving_16",TargetID = 0)
	LipSyncs(17) = (AnimName = "vt_driving_17",TargetID = 0)
	LipSyncs(18) = (AnimName = "vt_driving_18",TargetID = 0)
	LipSyncs(19) = (AnimName = "vt_driving_19",TargetID = 0)
	LipSyncs(20) = (AnimName = "vt_driving_20",TargetID = 0)
	LipSyncs(21) = (AnimName = "vt_driving_21",TargetID = 0)
	LipSyncs(22) = (AnimName = "vt_driving_23",TargetID = 0)
	LipSyncs(23) = (AnimName = "vt_driving_24",TargetID = 0)
	LipSyncs(24) = (AnimName = "vt_driving_25",TargetID = 0);
	LipSyncDebugs(0) = (Line1 = "Hurry it up!",Line2 = "I don't have all day!",Duration = 3)
	LipSyncDebugs(1) = (Line1 = "Remember you're here for train'n",Line2 = "not TV!",Duration = 3)
	LipSyncDebugs(2) = (Line1 = "Come on now!",Line2 = "I know that kiddy show isn't excit'n!",Duration = 3)
	LipSyncDebugs(3) = (Line1 = "What are you fella's watchin?",Line2 = "Springer?",Duration = 3)
	LipSyncDebugs(4) = (Line1 = "About time!",Line2 = "",Duration = 3)
	LipSyncDebugs(5) = (Line1 = "I'm Frank...",Line2 = "",Duration = 3)
	LipSyncDebugs(6) = (Line1 = "... and you kid",Line2 = "have just won the lotto.",Duration = 3)
	LipSyncDebugs(7) = (Line1 = "Let's get started.",Line2 = "You drive; I'll gun.",Duration = 3)
	LipSyncDebugs(8) = (Line1 = "Buckle up!",Line2 = "",Duration = 3)
	LipSyncDebugs(9) = (Line1 = "Let's get this show on the road!",Line2 = "",Duration = 3)
	LipSyncDebugs(10) = (Line1 = "OUCH!",Line2 = "",Duration = 3)
	LipSyncDebugs(11) = (Line1 = "The Paint!",Line2 = "",Duration = 3)
	LipSyncDebugs(12) = (Line1 = "Who taught you to drive?",Line2 = "",Duration = 3)
	LipSyncDebugs(13) = (Line1 = "That's comin' out of your paycheck.",Line2 = "",Duration = 3)
	LipSyncDebugs(14) = (Line1 = "Are you blind?",Line2 = "",Duration = 3)
	LipSyncDebugs(15) = (Line1 = "Whoa whoaa whoaaa...",Line2 = "",Duration = 3)
	LipSyncDebugs(16) = (Line1 = "HEY! This isn't Hazard County...",Line2 = "",Duration = 3)
	LipSyncDebugs(17) = (Line1 = "Nice! I hope you enjoy pushups.",Line2 = "",Duration = 3)
	LipSyncDebugs(18) = (Line1 = "Why me?",Line2 = "",Duration = 3)
	LipSyncDebugs(19) = (Line1 = "Alright Luke, get Cooter on the radio cuz we need a tow.",Line2 = "",Duration = 3)
	LipSyncDebugs(20) = (Line1 = "Whew...",Line2 = "My vehicle and I are still in one piece.",Duration = 3)
	LipSyncDebugs(21) = (Line1 = "Nice job soldier!",Line2 = "You're now qualified to drive the up-armored humvee.",Duration = 3)
	LipSyncDebugs(22) = (Line1 = "You can use your rearview mirrors",Line2 = "for better vehicle awareness.",Duration = 3)
	LipSyncDebugs(23) = (Line1 = "Make sure you always put the vehicle in park when exiting.",Line2 = "You don't want to have to chase your vehicle down.",Duration = 3)
	LipSyncDebugs(24) = (Line1 = "Use the low gear for more torque needed during steep inclines.",Line2 = "",Duration = 3);
	*/
	DrillSergeantTag = "NCO_Frank";
	AltDrillSergeantTag = "Frank";
	//LSAnims=;
	//TurnTowardPlayer = false;
	bUseLevelBeginFadeIn = true;
	LevelBeginFadeInTime = 3.5;
}

/*

State LevelEntryTransition
{
	Function BeginState()
	{
		FadeOut(0,true);
		SetTimerEvent('LevelStartFadeIn',3,0,false);
		FadeIn(3,true);
	}
	Function bool Timer_Timer(FName TimerName)
	{
		GotoState(InitialStateName);
		return true;
	}
}
auto State Familiarization
{
	Function BeginState()
	{
		Super::BeginState();
		QueueHint(UseInstructorHint);
		SetDrillSergeantParams(true,true,true);
		DSController(DrillSergeant.Controller).TurnTowardPlayer();
		bShoutRandomly = true;
		SetTimer(16,false);
	}
	Function Timer()
	{
		int32 Slot = 0;
		if (bShoutRandomly)
		{
			Slot = Rand(2);
			DSController(DrillSergeant.Controller).TurnTowardPlayer();
			PlayLSMessage(Slot);
			Self.SetTimer((10 + (FRand() * 10)),false);
		}
	}
	Function NotifyDrillSergeantUsed()
	{
		bShoutRandomly = false;
		DSController(DrillSergeant.Controller).TurnTowardPlayer();
		SetDrillSergeantParams(false,false,false);
		GotoState('PreDriving');
	}
Begin:
	Sleep(2);
	if (bShoutRandomly)
	{
		JL'Begin'
;
	}
}

State PreDriving
{
	Function bool AGP_Vehicle_Entered(AAGP_Vehicle* EnteredVehicle, AActor* Controller, FString Parms)
	{
		if ((AVehicle* == EnteredVehicle) && (Controller == Self.Controller))
		{
			PlayLSMessage(8);
			bPlayerInVehicle = true;
			GotoState('DrivingCourse','DriverEntered');
		}
		return true;
	}
Begin:
	PlayLSMessage(4);
	Sleep(2);
	PlayLSMessage(7);
	Sleep(3);
	QueueHint(EnterTheVehicleHint);
	DSController(DrillSergeant.Controller).MoveToPoint('FranksDoorNode');
	Sleep(3);
	FSTS_CROWS_Driver_HMMWV(Vehicle).bEntryLocked = false;
	Vehicle.Positions[4].KDriverEnter(DrillSergeant);
	HMMWVRunningBoardAnimManager(Vehicle.Positions[4].AnimManager).DestVehicle = Vehicle.Positions[0];
	HMMWVRunningBoardAnimManager(Vehicle.Positions[4].AnimManager).PlayVehicleEnterAnim();
	DrillSergeant.Controller.Possess(Vehicle.Positions[0]);
}

State DriverExited
{
	Function BeginState()
	{
		Super::BeginState();
		SetTimer(6,false);
	}
	Function Timer()
	{
		int32 Slot = 0;
		if (bShoutRandomly)
		{
			Slot = (Rand(3) * 2);
			PlayLSMessage(16);
			Self.SetTimer((6 + (FRand() * 10)),false);
		}
	}
	Function bool AGP_Vehicle_Entered(AAGP_Vehicle* ExitVehicle, AActor* Controller, FString Parms)
	{
		if ((AVehicle* == ExitVehicle) && (Controller == Self.Controller))
		{
			PlayLSMessage(8);
			bPlayerInVehicle = true;
			GotoState('DrivingCourse','DriverEntered');
		}
		return true;
	}
}

State DrivingCourse
{
	Function BeginState()
	{
		Super::BeginState();
		Self.NextCheckpoint = 0;
		Self.LastCheckpoint = CaptureCheckpoints();
	}
	Function int32 CaptureCheckpoints()
	{
		int32 highestCheckpoint = 0;
		local AAGP_Vehicle*Checkpoint checkpoint;
		highestCheckpoint = -1;
		ForEach AllActors(Class'AAGP_Vehicle*Checkpoint',checkpoint)
		{
			ReCaptureEvent(checkpoint);
			if ((checkpoint.Tag != 'Finish') && (checkpoint.checkpoint > highestCheckpoint))
			{
				highestCheckpoint = checkpoint.checkpoint;
			}
		}
		return highestCheckpoint;
	}
	Function bool AGP_Trigger_Trigger(AGP_Gameplay.AGP_Trigger NotifyActor, AActor* Instigator)
	{
		int32 checkpointNum = 0;
		if (AGP_VehicleCheckpoint(NotifyActor) != None)
		{
			if (NotifyActor.Tag == 'Finish')
			{
				FinishObjective.SetDisabled(true);
				FinishLine();
				return true;
			}
			checkpointNum = AGP_VehicleCheckpoint(NotifyActor).checkpoint;
			if (checkpointNum == NextCheckpoint)
			{
				NextCheckpoint++;
				ReportCheckpoint(checkpointNum);
				if (checkpointNum == 0)
				{
					Checkpoint0Objective.SetDisabled(true);
				}
				else
				{
					if (checkpointNum == 1)
					{
						Checkpoint1Objective.SetDisabled(true);
					}
					else
					{
						if (checkpointNum == 2)
						{
							Checkpoint2Objective.SetDisabled(true);
						}
					}
				}
			}
			else
			{
				if (checkpointNum == (NextCheckpoint - 1))
				{
					return true;
				}
				else
				{
					DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_sf","Mission Failed.","Checkpoints much be reached in order.",128,128,7,'None');
				}
			}
		}
		return true;
	}
	Function ReportCheckpoint(int32 latestCheckpoint)
	{
		FString localCheckpointString1 = "";
		FString localCheckpointString2 = "";
		if (LastCheckpoint != latestCheckpoint)
		{
			localCheckpointString1 = Repl(CheckpointString1,"%NUM%",string((latestCheckpoint + 1)));
			localCheckpointString2 = Repl(CheckpointString2,"%REMAINING%",string((LastCheckpoint - latestCheckpoint)));
		}
		else
		{
			localCheckpointString1 = "Final Checkpoint reached.";
			localCheckpointString2 = "Proceed to the starting area just ahead.";
			PlayLSMessage(20);
		}
		PlayTip(localCheckpointString1,localCheckpointString2,4);
	}
	Function FinishLine()
	{
		int32 checkpointsLeft = 0;
		FString failPartOne = "";
		if (NextCheckpoint > LastCheckpoint)
		{
			GotoState('PostDriving');
		}
		else
		{
			checkpointsLeft = ((LastCheckpoint - NextCheckpoint) + 1);
			failPartOne = "You need" @ string(checkpointsLeft) @ "more checkpoint";
			if (checkpointsLeft > 1)
			{
				(failPartOne $ = "s");
			}
			PlayTip(failPartOne,"to pass.",4);
		}
	}
	Function bool AGP_Vehicle_Exited(AAGP_Vehicle* ExitVehicle, AActor* Controller, FString Parms)
	{
		if ((AVehicle* == ExitVehicle) && (Controller == Self.Controller))
		{
			PlayLSMessage(14);
			bPlayerInVehicle = false;
			GotoState('DriverExited');
		}
		return true;
	}
Begin:
	Sleep(3);
	QueueHint(UseTheSeatbeltHint);
	QueueHint(StartTheCarHint);
	QueueHint(LookInTheMirrorHint);
	QueueHint(ShiftGearsHint);
	QueueHint(MoveForwardHint);
	QueueHint(SteeringHint);
	QueueHint(SpeedRangeHint);
	QueueHint(VehicleStuckHint);
	QueueHint(VehicleTippingHint);
	QueueHint(VehicleDisabledHint);
	FSTS_CROWS_Driver_HMMWV(Vehicle).bEntryLocked = true;
}

State PostDriving
{
	Function BeginState()
	{
	}
Begin:
	Sleep(3);
	FSTS_CROWS_Driver_HMMWV(Vehicle).bEntryLocked = false;
	Vehicle.Velocity = vect(0,0,0);
	Vehicle.Acceleration = vect(0,0,0);
	RemoveHint(VehicleDisabledHint);
	FSTS_CROWS_Driver_HMMWV(Vehicle).bVehicleDisabled = true;
	PlayLSMessage(21);
	Sleep(4);
	PlayLSMessage(23);
	Sleep(4);
	HandlePassResults();
}
*/

void AEL_VehicleTraining_Driver::PostPostInit()
{
	/*
	Super::PostPostInit();
	InitHintDelegates();
	LinkDrillSergeants();
	TargetIDs[0] = DrillSergeant;
	TargetIDs[1] = AltDrillSergeant;
	Checkpoint0Objective = FSTS_Objective(GetActorByTag('Checkpoint0Objective'));
	Checkpoint1Objective = FSTS_Objective(GetActorByTag('Checkpoint1Objective'));
	Checkpoint2Objective = FSTS_Objective(GetActorByTag('Checkpoint2Objective'));
	FinishObjective = FSTS_Objective(GetActorByTag('FinishObjective'));
	SetDrillSergeantParams(true, true, true);
	*/
}

void AEL_VehicleTraining_Driver::RestartLevel()
{
	/*
	FadeOut(5, true);
	if (FSTS_CROWS_Driver_HMMWV(Vehicle) != None)
	{
		FSTS_CROWS_Driver_HMMWV(Vehicle).ResetUserFlags();
	}
	bPlayerInVehicle = false;
	RemoveAllHints();
	if (StaticGunnerVehicle != None)
	{
		StaticGunnerVehicle.Destroy();
	}
	if (MobileGunnerVehicle != None)
	{
		MobileGunnerVehicle.Destroy();
	}
	DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_sf", "Training Mission Failed.", RestartMessage, 128, 128, 7, 'None');
	RestartMessage = "Level must be restarted to pass.";
	*/
}

void AEL_VehicleTraining_Driver::Leavenworth()
{
	//ConsoleCommand("open leavenworth");
}

bool AEL_VehicleTraining_Driver::AGP_NPC_Died(AAGP_NPC* NotifyActor, AController* aInstigator)
{
	/*
	PlayTip("Mission Failed", "", 5);
	FadeOut(5, true);
	SetCustomTimer(1.5, false, 'Leavenworth');
	*/
	return true;
}

bool AEL_VehicleTraining_Driver::AGP_Character_Died(AAGP_Character* NotifyActor, AController* aInstigator)
{
	/*
	PlayTip("Mission Failed", "", 5);
	FadeOut(5, true);
	RestartMessage = "You have died in a training accident.";
	SetCustomTimer(1.5, false, 'RestartLevel');
	*/
	return true;
}

bool AEL_VehicleTraining_Driver::Pawn_Died(APawn* NotifyActor, AController* aInstigator)
{
	/*
	PlayTip("Mission Failed", "", 5);
	FadeOut(5, true);
	RestartMessage = "You have died in a training accident.";
	SetCustomTimer(1.5, false, 'RestartLevel');
	*/
	return true;
}

bool AEL_VehicleTraining_Driver::ActorNotify(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	if ((NotifyActor == Vehicle) && (Event == 8))
	{
		Pawn_Damaged(Pawn(NotifyActor), Controller(aInstigator));
		return true;
	}
	else
	{
		Super::ActorNotify(NotifyActor, Event, aInstigator, Parms);
	}
	*/
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::AGP_NPC_Damaged(AAGP_NPC* NotifyActor, AController* aInstigator)
{
	//return Pawn_Damaged(NotifyActor, aInstigator);
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::Pawn_Damaged(APawn* NotifyActor, AController* aInstigator)
{
	/*
	int32 Slot = 0;
	if (AVehicle* == NotifyActor)
	{
		Slot = (Rand(6) + 10);
		PlayLSMessage(Slot);
	}
	*/
	return true;
}

bool AEL_VehicleTraining_Driver::AGP_Vehicle_Spawned(AAGP_VehicleFactory* SpawningFactory, AAGP_Vehicle* NewVehicle, FString Parms)
{
	/*
	if (NewVehicle.Tag == StaticGunnerVehicleTag)
	{
		return SetupStaticGunnerVehicle(NewVehicle);
	}
	if (NewVehicle.Tag == MobileGunnerVehicleTag)
	{
		return SetupMobileGunnerVehicle(NewVehicle);
	}
	Super::AGP_Vehicle_Spawned(SpawningFactory, NewVehicle, Parms);
	if (AVehicle* != None)
	{
		if (FSTS_CROWS_Driver_HMMWV(Vehicle) != None)
		{
			FSTS_CROWS_Driver_HMMWV(Vehicle).bEntryLocked = true;
		}
	}
	*/
	return true;
}

bool AEL_VehicleTraining_Driver::SetupStaticGunnerVehicle(AVehicle* NewVehicle)
{
	/*
	local ScriptedSequence StaticGunnerScript;
	local ScriptedSequence StaticGunnerDriverScript;
	local Pawn GunnerPositionPawn;
	local Pawn DriverPositionPawn;
	ForEach AllActors(Class'Gameplay.ScriptedSequence', StaticGunnerScript, 'StaticGunnerScript')
	{
		GOTO JL0019;
	JL0019:
	}
	ForEach AllActors(Class'Gameplay.ScriptedSequence', StaticGunnerDriverScript, 'StaticGunnerDriverScript')
	{
		GOTO JL0033;
	JL0033:
	}
	if (AGP_Vehicle(NewVehicle) != None)
	{
		GunnerPositionPawn = AGP_Vehicle(NewVehicle).Positions[0];
		StaticGunnerScript.SpawnControllerFor(GunnerPositionPawn);
		DriverPositionPawn = NewVehicle;
		StaticGunnerDriverScript.SpawnControllerFor(DriverPositionPawn);
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::SetupMobileGunnerVehicle(AVehicle* NewVehicle)
{
	/*
	local ScriptedSequence MobileGunnerScript;
	local ScriptedSequence MobileGunnerDriverScript;
	local Pawn GunnerPositionPawn;
	local Pawn DriverPositionPawn;
	ForEach AllActors(Class'Gameplay.ScriptedSequence', MobileGunnerScript, 'MobileGunnerScript')
	{
		GOTO JL0019;
	JL0019:
	}
	ForEach AllActors(Class'Gameplay.ScriptedSequence', MobileGunnerDriverScript, 'MobileGunnerDriverScript')
	{
		GOTO JL0033;
	JL0033:
	}
	if (AGP_Vehicle(NewVehicle) != None)
	{
		GunnerPositionPawn = AGP_Vehicle(NewVehicle).Positions[0];
		MobileGunnerScript.SpawnControllerFor(GunnerPositionPawn);
		DriverPositionPawn = NewVehicle;
		MobileGunnerDriverScript.SpawnControllerFor(DriverPositionPawn);
		return true;
	}
	else
	{
		return false;
	}
	*/
	return true;
}

void AEL_VehicleTraining_Driver::HandlePassResults()
{
	/*
	local Security secLocalSecurity;
	local class<Security>  scLocalSecurityClass;
	local TArray<FString> asMD5ForMap;
	local TArray<FString> asMD5ForScript;
	FString sMD5ForMap = "";
	FString sMD5ForScript = "";
	DebugLog(DEBUG_EventLab, "uploadStats:");
	if (FSTS_PlayerController(Controller).IsUsingCheats())
	{
		DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_sf", "Vehicle Driver Training Complete", "Would you like to try again?", 128, 128, 7, 'None', "AGP_Interface.AAMissionCompletePageEx");
		return;
	}
	Controller.SetAuthMissionPassFlag(true);
	Controller.ResetAuthExtraMissionData();
	scLocalSecurityClass = class<Security>(DynamicLoadObject("Engine.Security", Class'Class'));
	if (scLocalSecurityClass != None)
	{
		secLocalSecurity = Spawn(scLocalSecurityClass, Controller);
		if (secLocalSecurity != None)
		{
			secLocalSecurity.LocalPerform(2, "../Maps/Vehicle_Training_Driver.aao", "", asMD5ForMap);
			secLocalSecurity.LocalPerform(2, "../System/FSTS.u", "", asMD5ForScript);
			sMD5ForMap = asMD5ForMap[0];
			sMD5ForScript = asMD5ForScript[0];
		}
	}
	Controller.AddAuthExtraMissionData("1");
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
	DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_sf", "Congratulations! You passed ", "Vehicle Training - Driver.", 128, 128, 7, 'None', "AGP_Interface.AAMissionCompletePageEx");
	*/
}

void AEL_VehicleTraining_Driver::InitHintDelegates()
{
	/*
	UseInstructorHint.__IsAppropriate__Delegate = IsUseInstructorHintAppropriate;
	UseInstructorHint.__IsSatisfied__Delegate = IsUseInstructorHintSatisfied;
	EnterTheVehicleHint.__IsAppropriate__Delegate = IsEnterTheVehicleHintAppropriate;
	EnterTheVehicleHint.__IsSatisfied__Delegate = IsEnterTheVehicleHintSatisfied;
	UseTheSeatbeltHint.__IsAppropriate__Delegate = IsUseTheSeatbeltHintAppropriate;
	UseTheSeatbeltHint.__IsSatisfied__Delegate = IsUseTheSeatbeltHintSatisfied;
	StartTheCarHint.__IsAppropriate__Delegate = IsStartTheCarHintAppropriate;
	StartTheCarHint.__IsSatisfied__Delegate = IsStartTheCarHintSatisfied;
	ShiftGearsHint.__IsAppropriate__Delegate = IsShiftGearsHintAppropriate;
	ShiftGearsHint.__IsSatisfied__Delegate = IsShiftGearsHintSatisfied;
	LookInTheMirrorHint.__IsAppropriate__Delegate = IsLookInTheMirrorHintAppropriate;
	LookInTheMirrorHint.__IsSatisfied__Delegate = IsLookInTheMirrorHintSatisfied;
	SpeedRangeHint.__IsAppropriate__Delegate = IsSpeedRangeHintAppropriate;
	SpeedRangeHint.__IsSatisfied__Delegate = IsSpeedRangeHintSatisfied;
	VehicleStuckHint.__IsAppropriate__Delegate = IsVehicleStuckHintAppropriate;
	VehicleStuckHint.__IsSatisfied__Delegate = IsVehicleStuckHintSatisfied;
	VehicleTippingHint.__IsAppropriate__Delegate = IsVehicleTippingHintAppropriate;
	VehicleTippingHint.__IsSatisfied__Delegate = IsVehicleTippingHintSatisfied;
	VehicleDisabledHint.__IsAppropriate__Delegate = IsVehicleDisabledHintAppropriate;
	VehicleDisabledHint.__IsSatisfied__Delegate = IsVehicleDisabledHintSatisfied;
	*/
}

bool AEL_VehicleTraining_Driver::IsUseInstructorHintAppropriate()
{
	//return ((VSize((Player.Location - DrillSergeant.Location)) < 400) && IsInState('Familiarization'));
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::IsUseInstructorHintSatisfied()
{
	//return IsInState('PreDriving');
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::IsUseTheSeatbeltHintAppropriate()
{
	return bPlayerInVehicle;
}

bool AEL_VehicleTraining_Driver::IsUseTheSeatbeltHintSatisfied()
{
	/*
	if (AVehicle* == None)
	{
		return false;
	}
	else
	{
		return Vehicle.bWearingSeatbelt;
	}
	*/
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::IsEnterTheVehicleHintAppropriate()
{
	/*
	if ((FSTS_CROWS_Driver_HMMWV(Vehicle) != None) && (FSTS_CROWS_Driver_HMMWV(Vehicle).bEntryLocked == true))
	{
		return false;
	}
	else
	{
		return (VSize((Player.Location - Vehicle.Location)) < 200);
	}
	*/
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::IsEnterTheVehicleHintSatisfied()
{
	return bPlayerInVehicle;
}

bool AEL_VehicleTraining_Driver::IsStartTheCarHintAppropriate()
{
	return bPlayerInVehicle;
}

bool AEL_VehicleTraining_Driver::IsStartTheCarHintSatisfied()
{
	/*
	if (CROWS_HMMWV(Vehicle) == None)
	{
		return false;
	}
	else
	{
		return CROWS_HMMWV(Vehicle).bHitIgnition;
	}
	*/
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::IsShiftGearsHintAppropriate()
{
	return bPlayerInVehicle;
}

bool AEL_VehicleTraining_Driver::IsShiftGearsHintSatisfied()
{
	/*
	if (FSTS_CROWS_Driver_HMMWV(Vehicle) == None)
	{
		return false;
	}
	else
	{
		return FSTS_CROWS_Driver_HMMWV(Vehicle).bHasShiftedGears;
	}
	*/
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::IsLookInTheMirrorHintAppropriate()
{
	return bPlayerInVehicle;
}

bool AEL_VehicleTraining_Driver::IsLookInTheMirrorHintSatisfied()
{
	/*
	if (FSTS_CROWS_Driver_HMMWV(Vehicle) == None)
	{
		return false;
	}
	else
	{
		return FSTS_CROWS_Driver_HMMWV(Vehicle).bHasLookedInMirror;
	}
	*/
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::IsSpeedRangeHintAppropriate()
{
	return bPlayerInVehicle;
}

bool AEL_VehicleTraining_Driver::IsSpeedRangeHintSatisfied()
{
	/*
	if (FSTS_CROWS_Driver_HMMWV(Vehicle) == None)
	{
		return false;
	}
	else
	{
		return FSTS_CROWS_Driver_HMMWV(Vehicle).bHasChangedSpeed;
	}
	*/
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::IsVehicleStuckHintAppropriate()
{
	/*
	if (!bPlayerInVehicle)
	{
		return false;
	}
	if ((AGP_WheeledCraft(Vehicle).CarMPH < 1) || (!Vehicle.bVehicleOnGround))
	{
		if (VehicleStuckTime < 0)
		{
			VehicleStuckTime = Level.TimeSeconds;
		}
		else
		{
			if ((Level.TimeSeconds - VehicleStuckTime) > 15)
			{
				RestartMessage = "Your vehicle has become stuck or inoperable.";
				PlayerLock(false, false);
				SetCustomTimer(5.5, false, 'RestartLevel');
				return true;
			}
		}
	}
	else
	{
		VehicleStuckTime = -1;
	}
	*/
	return false;
}

bool AEL_VehicleTraining_Driver::IsVehicleStuckHintSatisfied()
{
	return false;
}

bool AEL_VehicleTraining_Driver::IsVehicleTippingHintAppropriate()
{
	//return ((Abs(float(Vehicle.Rotation.Pitch)) > float(4096)) || (Abs(float(Vehicle.Rotation.Roll)) > float(4096)));
	return false;    //FAKE  /ELiZ
}

bool AEL_VehicleTraining_Driver::IsVehicleTippingHintSatisfied()
{
	return false;
}

bool AEL_VehicleTraining_Driver::IsVehicleDisabledHintAppropriate()
{
	/*
	if (!bPlayerInVehicle)
	{
		return false;
	}
	if (FSTS_CROWS_Driver_HMMWV(Vehicle).bVehicleDisabled)
	{
		RestartMessage = "Your vehicle has been heavily damaged by abuse or neglect.";
		SetCustomTimer(5.5, false, 'RestartLevel');
		return true;
	}
	*/
	return false;
}

bool AEL_VehicleTraining_Driver::IsVehicleDisabledHintSatisfied()
{
	return false;
}