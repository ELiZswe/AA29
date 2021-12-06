// All the original content belonged to the US Army


#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"

AStudentController::AStudentController()
{
	
}

/*
State MedicTraining_SittingAtDesk
{
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(Self) @ "StudentController::BeginState() - in state" @ string(GetStateName()));
		}
		Begin();
		Pawn.SetWalking(false);
		Pawn.SetPhysics(PHYS_None);
	}
	Function Begin()
	{
	}
	exec Function Jump(float F)
	{
		SetViewTarget(Pawn);
		SetFOVAngle(DefaultFOV);
		LockPlayer(false,false);
		Pawn.bHidden=false;
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,31,Pawn,"EXITCHAIR");
		}
		if (_Target != None)
		{
			_Target.Notify();
		}
		GotoState('PlayerWalking');
		bSeated=false;
	}
	Function PlayWaiting()
	{
	}
	exec Function Action()
	{
	}
	Function ServerAction(Actor Other)
	{
	}
	Function AutoTrace()
	{
		_AutoTraceHitActor=None;
		TryToIDActor(None);
		TryToIDPawn(None);
	}
}
State ClassOneSitting extends MedicTraining_SittingAtDesk
{
	Function Begin()
	{
		FRotator NewRotation = FRotator(0,0,0);
		SittingState=GetStateName();
		SetViewTarget(GetActorByTag('VT_DeskOne'));
		SetFOVAngle(65);
		LockPlayer(true,true);
		Pawn.bHidden=true;
		NewRotation=ViewTarget.Rotation;
		NewRotation.Yaw=65000;
		ViewTarget.SetRotation(NewRotation);
		bSeated=true;
		Pawn.GotoState('Hidden');
	}
	exec Function Action()
	{
		GotoState('ClassOneTesting');
	}
	Function PlayerMove(float DeltaTime)
	{
		FRotator NewRotation = FRotator(0,0,0);
		local Actor VA;
		VA=ViewTarget;
		if (VA != None)
		{
			if (GetInvertMouse())
			{
				(aMouseY *= float(-1));
			}
			NewRotation=VA.Rotation;
			(NewRotation.Yaw += int(((aMouseX * DeltaTime) * float(25))));
			(NewRotation.Pitch += int(((aMouseY * DeltaTime) * float(25))));
			if ((NewRotation.Yaw > 73000) && (NewRotation.Pitch < -500))
			{
				bPossiblyCheating=true;
				if (EventLab != None)
				{
					EventLab.ActorNotify(Self,31,Pawn,"CHEATING");
				}
			}
			else
			{
				bPossiblyCheating=false;
			}
			if (NewRotation.Yaw < 45000)
			{
				NewRotation.Yaw=45000;
			}
			else
			{
				if (NewRotation.Yaw > 86000)
				{
					NewRotation.Yaw=86000;
				}
			}
			if (NewRotation.Pitch > 10000)
			{
				NewRotation.Pitch=10000;
			}
			else
			{
				if (NewRotation.Pitch < -6000)
				{
					NewRotation.Pitch=-6000;
				}
			}
			VA.SetRotation(NewRotation);
		}
	}
}
State ClassTwoSitting extends MedicTraining_SittingAtDesk
{
	Function Begin()
	{
		FRotator NewRotation = FRotator(0,0,0);
		SittingState=GetStateName();
		SetViewTarget(GetActorByTag('VT_DeskTwo'));
		SetFOVAngle(65);
		LockPlayer(true,true);
		Pawn.bHidden=true;
		NewRotation=ViewTarget.Rotation;
		NewRotation.Yaw=48616;
		ViewTarget.SetRotation(NewRotation);
		bSeated=true;
		Pawn.GotoState('Hidden');
	}
	exec Function Action()
	{
		GotoState('ClassTwoTesting');
	}
	Function PlayerMove(float DeltaTime)
	{
		FRotator NewRotation = FRotator(0,0,0);
		local Actor VA;
		VA=ViewTarget;
		if (VA != None)
		{
			if (GetInvertMouse())
			{
				(aMouseY *= float(-1));
			}
			NewRotation=VA.Rotation;
			(NewRotation.Yaw += int(((aMouseX * DeltaTime) * float(25))));
			(NewRotation.Pitch += int(((aMouseY * DeltaTime) * float(25))));
			if ((NewRotation.Yaw > 56000) && (NewRotation.Pitch < -500))
			{
				bPossiblyCheating=true;
				if (EventLab != None)
				{
					EventLab.ActorNotify(Self,31,Pawn,"CHEATING");
				}
			}
			else
			{
				bPossiblyCheating=false;
			}
			if (NewRotation.Yaw < 28000)
			{
				NewRotation.Yaw=28000;
			}
			else
			{
				if (NewRotation.Yaw > 68000)
				{
					NewRotation.Yaw=68000;
				}
			}
			if (NewRotation.Pitch > 10000)
			{
				NewRotation.Pitch=10000;
			}
			else
			{
				if (NewRotation.Pitch < -6000)
				{
					NewRotation.Pitch=-6000;
				}
			}
			VA.SetRotation(NewRotation);
		}
	}
}
State ClassThreeSitting extends MedicTraining_SittingAtDesk
{
	Function Begin()
	{
		FRotator NewRotation = FRotator(0,0,0);
		SittingState=GetStateName();
		SetViewTarget(GetActorByTag('VT_DeskThree'));
		SetFOVAngle(65);
		LockPlayer(true,true);
		Pawn.bHidden=true;
		NewRotation=ViewTarget.Rotation;
		NewRotation.Yaw=16000;
		ViewTarget.SetRotation(NewRotation);
		bSeated=true;
		Pawn.GotoState('Hidden');
	}
	exec Function Action()
	{
		GotoState('ClassThreeTesting');
	}
	Function PlayerMove(float DeltaTime)
	{
		FRotator NewRotation = FRotator(0,0,0);
		local Actor VA;
		VA=ViewTarget;
		if (VA != None)
		{
			if (GetInvertMouse())
			{
				(aMouseY *= float(-1));
			}
			NewRotation=VA.Rotation;
			(NewRotation.Yaw += int(((aMouseX * DeltaTime) * float(25))));
			(NewRotation.Pitch += int(((aMouseY * DeltaTime) * float(25))));
			if ((NewRotation.Yaw > 23000) && (NewRotation.Pitch < -500))
			{
				bPossiblyCheating=true;
				if (EventLab != None)
				{
					EventLab.ActorNotify(Self,31,Pawn,"CHEATING");
				}
			}
			else
			{
				bPossiblyCheating=false;
			}
			if (NewRotation.Yaw < -4000)
			{
				NewRotation.Yaw=-4000;
			}
			else
			{
				if (NewRotation.Yaw > 32000)
				{
					NewRotation.Yaw=32000;
				}
			}
			if (NewRotation.Pitch > 10000)
			{
				NewRotation.Pitch=10000;
			}
			else
			{
				if (NewRotation.Pitch < -6000)
				{
					NewRotation.Pitch=-6000;
				}
			}
			VA.SetRotation(NewRotation);
		}
	}
}
State MedicTraining_TakingExam
{
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(Self) @ "StudentController::BeginState() - in state" @ string(GetStateName()));
		}
		Begin();
		AGP_HUD(myHUD).SetHUDActor();
		HUDCrosshair(AGP_HUD(myHUD).GetHUDControl(10)).SetCrossHairColor(1);
		AGP_HUD(myHUD).FreeHUDActor();
	}
	Function Begin()
	{
	}
	exec Function Jump(float F)
	{
		GotoState(SittingState);
	}
	exec Function Action()
	{
		ServerAction(_AutoTraceHitActor);
	}
	exec Function Fire(float F)
	{
		ServerAction(_AutoTraceHitActor);
	}
	Function ServerAction(Actor Other)
	{
		Other.UsedBy(Pawn);
	}
	Function AutoTrace()
	{
		FVector StartTrace = FVector(0,0,0);
		FVector EndTrace = FVector(0,0,0);
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		local Actor Other;
		int32 trace_dist = 0;
		trace_dist=96;
		GetAxes(ViewTarget.Rotation,X,Y,Z);
		StartTrace=ViewTarget.Location;
		EndTrace=StartTrace;
		(EndTrace += (float(trace_dist) * X));
		Other=ActionTrace(EndTrace,StartTrace);
		_AutoTraceHitActor=Other;
		TryToIDActor(Other);
	}
Begin:
	if (bLeanLeft != 0)
	{
		MyExam.Trigger(Self,Pawn);
		Sleep(0.2);
	}
	if (bLeanRight != 0)
	{
		MyExam.UnTrigger(Self,Pawn);
		Sleep(0.2);
	}
	Sleep(0.01);
	JL'Begin'
;
}
State ClassOneTesting extends MedicTraining_TakingExam
{
	Function Begin()
	{
		SetViewTarget(GetActorByTag('VT_PaperOne'));
		SetFOVAngle(DefaultFOV);
		Pawn.bHidden=true;
		MyExam=GetActorByTag('MedExamOne');
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector NewLocation = FVector(0,0,0);
		local Actor VA;
		VA=ViewTarget;
		if (VA != None)
		{
			if (GetInvertMouse())
			{
				(aMouseY *= float(-1));
			}
			NewLocation=VA.Location;
			(NewLocation.Y += ((aMouseX * DeltaTime) * 0.03));
			(NewLocation.X += ((aMouseY * DeltaTime) * 0.03));
			if (NewLocation.Y < float(1408))
			{
				NewLocation.Y=1408;
			}
			else
			{
				if (NewLocation.Y > float(1430))
				{
					NewLocation.Y=1430;
				}
			}
			if (NewLocation.X < float(1875))
			{
				NewLocation.X=1875;
			}
			else
			{
				if (NewLocation.X > float(1900))
				{
					NewLocation.X=1900;
				}
			}
			VA.SetLocation(NewLocation);
		}
	}
}
State ClassTwoTesting extends MedicTraining_TakingExam
{
	Function Begin()
	{
		SetViewTarget(GetActorByTag('VT_PaperTwo'));
		SetFOVAngle(DefaultFOV);
		Pawn.bHidden=true;
		MyExam=GetActorByTag('MedExamTwo');
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector NewLocation = FVector(0,0,0);
		local Actor VA;
		VA=ViewTarget;
		if (VA != None)
		{
			if (GetInvertMouse())
			{
				(aMouseY *= float(-1));
			}
			NewLocation=VA.Location;
			(NewLocation.X += ((aMouseX * DeltaTime) * 0.03));
			(NewLocation.Y += ((aMouseY * DeltaTime) * -0.03));
			if (NewLocation.Y < 766)
			{
				NewLocation.Y=766;
			}
			else
			{
				if (NewLocation.Y > 796)
				{
					NewLocation.Y=796;
				}
			}
			if (NewLocation.X < -16)
			{
				NewLocation.X=-16;
			}
			else
			{
				if (NewLocation.X > 9)
				{
					NewLocation.X=9;
				}
			}
			VA.SetLocation(NewLocation);
		}
	}
}
State ClassThreeTesting extends MedicTraining_TakingExam
{
	Function Begin()
	{
		SetViewTarget(GetActorByTag('VT_PaperThree'));
		SetFOVAngle(DefaultFOV);
		Pawn.bHidden=true;
		MyExam=GetActorByTag('MedExamThree');
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector NewLocation = FVector(0,0,0);
		local Actor VA;
		VA=ViewTarget;
		if (VA != None)
		{
			if (GetInvertMouse())
			{
				(aMouseY *= float(-1));
			}
			NewLocation=VA.Location;
			(NewLocation.X += ((aMouseX * DeltaTime) * -0.03));
			(NewLocation.Y += ((aMouseY * DeltaTime) * 0.03));
			if (NewLocation.Y < float(-440))
			{
				NewLocation.Y=-440;
			}
			else
			{
				if (NewLocation.Y > float(-410))
				{
					NewLocation.Y=-410;
				}
			}
			if (NewLocation.X < float(851))
			{
				NewLocation.X=851;
			}
			else
			{
				if (NewLocation.X > float(877))
				{
					NewLocation.X=877;
				}
			}
			VA.SetLocation(NewLocation);
		}
	}
}
State MedicTraining_Frozen
{
	Function PlayerMove(float DeltaTime)
	{
	}
	Function ProcessMove(float DeltaTime, Vector NewAccel, Actor.EDoubleClickDir DoubleClickMove, Rotator DeltaRot)
	{
	}
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(Self) @ "StudentController::BeginState() - in state" @ string(GetStateName()));
		}
		SetViewTarget(Pawn);
		SetFOVAngle(DefaultFOV);
		LockPlayer(true,true);
		Pawn.bHidden=false;
		Pawn.Velocity.X=0;
		Pawn.Velocity.Y=0;
		Pawn.Velocity.Z=0;
		bSeated=false;
	}
Begin:
	Pawn.Velocity.X=0;
	Pawn.Velocity.Y=0;
	Pawn.Velocity.Z=0;
	Sleep(0.001);
	JL'Begin'
;
}
State SFTraining_SittingAtDesk
{
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(Self) @ "StudentController::BeginState() - in state" @ string(GetStateName()));
		}
		Begin();
		Pawn.SetWalking(false);
		Pawn.SetPhysics(PHYS_None);
	}
	Function Begin()
	{
	}
	exec Function Jump(float F)
	{
		if (bForceSit == true)
		{
			return;
		}
		SetViewTarget(Pawn);
		SetFOVAngle(DefaultFOV);
		LockPlayer(false,false);
		Pawn.bHidden=false;
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,31,Pawn,"EXITCHAIR");
		}
		if (_Target != None)
		{
			_Target.Notify();
		}
		Log(string(Self) @ "StudentController::MedicTraining_SittingAtDesk::Jump	Moving controller to PlayerWalking state");
		GotoState('PlayerWalking');
		bSeated=false;
	}
	Function PlayWaiting()
	{
	}
	exec Function Action()
	{
	}
	Function ServerAction(Actor Other)
	{
	}
	Function AutoTrace()
	{
		_AutoTraceHitActor=None;
		TryToIDActor(None);
		TryToIDPawn(None);
	}
}
State SFClassOneSitting extends SFTraining_SittingAtDesk
{
	Function Begin()
	{
		FRotator NewRotation = FRotator(0,0,0);
		SittingState=GetStateName();
		SetViewTarget(GetActorByTag('VT_DeskOne'));
		SetFOVAngle(65);
		LockPlayer(true,true);
		Pawn.bHidden=true;
		NewRotation=ViewTarget.Rotation;
		NewRotation.Yaw=65000;
		ViewTarget.SetRotation(NewRotation);
		bSeated=true;
		Pawn.GotoState('Hidden');
	}
	exec Function Action()
	{
		if (Level.bSkipTest == false)
		{
			GotoState('SFClassOneTesting');
		}
	}
	Function PlayerMove(float DeltaTime)
	{
		FRotator NewRotation = FRotator(0,0,0);
		local Actor VA;
		VA=ViewTarget;
		if (VA != None)
		{
			if (GetInvertMouse())
			{
				(aMouseY *= float(-1));
			}
			NewRotation=VA.Rotation;
			(NewRotation.Yaw += int(((aMouseX * DeltaTime) * float(25))));
			(NewRotation.Pitch += int(((aMouseY * DeltaTime) * float(25))));
			if ((NewRotation.Yaw > 73000) && (NewRotation.Pitch < -500))
			{
				bPossiblyCheating=true;
				if (EventLab != None)
				{
					EventLab.ActorNotify(Self,31,Pawn,"CHEATING");
				}
			}
			else
			{
				bPossiblyCheating=false;
			}
			if (NewRotation.Yaw < 45000)
			{
				NewRotation.Yaw=45000;
			}
			else
			{
				if (NewRotation.Yaw > 86000)
				{
					NewRotation.Yaw=86000;
				}
			}
			if (NewRotation.Pitch > 10000)
			{
				NewRotation.Pitch=10000;
			}
			else
			{
				if (NewRotation.Pitch < -6000)
				{
					NewRotation.Pitch=-6000;
				}
			}
			VA.SetRotation(NewRotation);
		}
	}
}
State SFClassTwoSitting extends SFTraining_SittingAtDesk
{
	Function Begin()
	{
		FRotator NewRotation = FRotator(0,0,0);
		SittingState=GetStateName();
		SetViewTarget(GetActorByTag('VT_DeskTwo'));
		SetFOVAngle(65);
		LockPlayer(true,true);
		Pawn.bHidden=true;
		NewRotation=ViewTarget.Rotation;
		NewRotation.Yaw=65000;
		ViewTarget.SetRotation(NewRotation);
		bSeated=true;
		Pawn.GotoState('Hidden');
	}
	exec Function Action()
	{
		if (Pawn.Weapon.IsA('item_headphones'))
		{
			GotoState('SFClassTwoTesting');
		}
	}
	Function PlayerMove(float DeltaTime)
	{
		FRotator NewRotation = FRotator(0,0,0);
		local Actor VA;
		VA=ViewTarget;
		if (VA != None)
		{
			if (GetInvertMouse())
			{
				(aMouseY *= float(-1));
			}
			NewRotation=VA.Rotation;
			(NewRotation.Yaw += int(((aMouseX * DeltaTime) * float(25))));
			(NewRotation.Pitch += int(((aMouseY * DeltaTime) * float(25))));
			if ((NewRotation.Yaw > 73000) && (NewRotation.Pitch < -500))
			{
				bPossiblyCheating=true;
				if (EventLab != None)
				{
					EventLab.ActorNotify(Self,31,Pawn,"CHEATING");
				}
			}
			else
			{
				bPossiblyCheating=false;
			}
			if (NewRotation.Yaw < 45000)
			{
				NewRotation.Yaw=45000;
			}
			else
			{
				if (NewRotation.Yaw > 86000)
				{
					NewRotation.Yaw=86000;
				}
			}
			if (NewRotation.Pitch > 10000)
			{
				NewRotation.Pitch=10000;
			}
			else
			{
				if (NewRotation.Pitch < -6000)
				{
					NewRotation.Pitch=-6000;
				}
			}
			VA.SetRotation(NewRotation);
		}
	}
}
State SFTraining_TakingExam
{
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(Self) @ "StudentController::BeginState() - in state" @ string(GetStateName()));
		}
		Begin();
		AGP_HUD(myHUD).SetHUDActor();
		HUDCrosshair(AGP_HUD(myHUD).GetHUDControl(10)).SetCrossHairColor(1);
		AGP_HUD(myHUD).FreeHUDActor();
	}
	Function Begin()
	{
	}
	exec Function Jump(float F)
	{
		GotoState(SittingState);
	}
	exec Function Action()
	{
		ServerAction(_AutoTraceHitActor);
	}
	exec Function Fire(float F)
	{
		ServerAction(_AutoTraceHitActor);
	}
	Function ServerAction(Actor Other)
	{
		Other.UsedBy(Pawn);
	}
	Function AutoTrace()
	{
		FVector StartTrace = FVector(0,0,0);
		FVector EndTrace = FVector(0,0,0);
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		local Actor Other;
		int32 trace_dist = 0;
		trace_dist=96;
		GetAxes(ViewTarget.Rotation,X,Y,Z);
		StartTrace=ViewTarget.Location;
		EndTrace=StartTrace;
		(EndTrace += (float(trace_dist) * X));
		Other=ActionTrace(EndTrace,StartTrace);
		_AutoTraceHitActor=Other;
		TryToIDActor(Other);
	}
Begin:
	if (bLeanLeft != 0)
	{
		MyExam.Trigger(Self,Pawn);
		Sleep(0.2);
	}
	if (bLeanRight != 0)
	{
		MyExam.UnTrigger(Self,Pawn);
		Sleep(0.2);
	}
	Sleep(0.01);
	JL'Begin'
;
}
State SFClassOneTesting extends SFTraining_TakingExam
{
	Function Begin()
	{
		SetViewTarget(GetActorByTag('VT_PaperOne'));
		SetFOVAngle(DefaultFOV);
		Pawn.bHidden=true;
		MyExam=GetActorByTag('SFExamOne');
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector NewLocation = FVector(0,0,0);
		local Actor VA;
		VA=ViewTarget;
		if (VA != None)
		{
			if (GetInvertMouse())
			{
				(aMouseY *= float(-1));
			}
			NewLocation=VA.Location;
			(NewLocation.Y += ((aMouseX * DeltaTime) * 0.03));
			(NewLocation.X += ((aMouseY * DeltaTime) * 0.03));
			if (NewLocation.Y < float(-440))
			{
				NewLocation.Y=-440;
			}
			else
			{
				if (NewLocation.Y > float(-400))
				{
					NewLocation.Y=-400;
				}
			}
			if (NewLocation.X < float(-1776))
			{
				NewLocation.X=-1776;
			}
			else
			{
				if (NewLocation.X > float(-1710))
				{
					NewLocation.X=-1710;
				}
			}
			VA.SetLocation(NewLocation);
		}
	}
}
State SFClassTwoTesting extends SFTraining_TakingExam
{
	Function Begin()
	{
		SetViewTarget(GetActorByTag('VT_PaperTwo'));
		SetFOVAngle(DefaultFOV);
		Pawn.bHidden=true;
		MyExam=GetActorByTag('SFExamOne');
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector NewLocation = FVector(0,0,0);
		local Actor VA;
		VA=ViewTarget;
		if (VA != None)
		{
			if (GetInvertMouse())
			{
				(aMouseY *= float(-1));
			}
			NewLocation=VA.Location;
			(NewLocation.Y += ((aMouseX * DeltaTime) * 0.03));
			(NewLocation.X += ((aMouseY * DeltaTime) * 0.03));
			if (NewLocation.Y < float(2120))
			{
				NewLocation.Y=2120;
			}
			else
			{
				if (NewLocation.Y > float(2138))
				{
					NewLocation.Y=2138;
				}
			}
			if (NewLocation.X < float(1541))
			{
				NewLocation.X=1541;
			}
			else
			{
				if (NewLocation.X > float(1565))
				{
					NewLocation.X=1565;
				}
			}
			VA.SetLocation(NewLocation);
		}
	}
}
State PlayerWalking
{
	Function BeginState()
	{
		Super::BeginState();
		if ("" $ string(Level) ~= "Entry.LevelInfo0")
		{
			LockPlayer(true,true);
			bBehindView=false;
		}
	}
}
State MoveToForcedLocation
{
Begin:
	MoveToward(RouteGoal,RouteGoal,,true,true);
	FocalPoint=(Pawn.Location + (float(512) *  Vector(RouteGoal.Rotation)));
	bRotateToDesired=true;
	FinishRotation();
	GotoState(GetLastStateName());
}
*/
