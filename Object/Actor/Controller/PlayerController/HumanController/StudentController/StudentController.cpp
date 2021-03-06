// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/NPCPathNodeBuilder/NPCPathNodeBuilder.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartCivilian/NPCPlayerStartCivilian.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/LadderVolume/LadderVolume.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCVAERecruiterController/NPCVAERecruiterController.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/item_headphones/item_headphones.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/AGP_UseTrigger/TriggerURL/TriggerURL.h"

AStudentController::AStudentController()
{
	//bProp = true;
}

/*
State MedicTraining_SittingAtDesk
{
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "StudentController::BeginState() - in state" @ FString::FromInt(GetStateName()));
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
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this,31,Pawn,"EXITCHAIR");
		}
		if (_Target != nullptr)
		{
			_Target.Notify();
		}
		GotoState("PlayerWalking");
		bSeated=false;
	}
	Function PlayWaiting()
	{
	}
	exec Function Action()
	{
	}
	Function ServerAction(AActor* Other)
	{
	}
	Function AutoTrace()
	{
		_AutoTraceHitActor=nullptr;
		TryToIDActor(nullptr);
		TryToIDPawn(nullptr);
	}
}
*/

/*
State ClassOneSitting extends MedicTraining_SittingAtDesk
{
	Function Begin()
	{
		FRotator NewRotation = FRotator(0,0,0);
		SittingState=GetStateName();
		SetViewTarget(GetActorByTag("VT_DeskOne"));
		SetFOVAngle(65);
		LockPlayer(true,true);
		Pawn.bHidden=true;
		NewRotation=ViewTarget.Rotation;
		NewRotation.Yaw=65000;
		ViewTarget.SetRotation(NewRotation);
		bSeated=true;
		Pawn.GotoState("Hidden");
	}
	exec Function Action()
	{
		GotoState("ClassOneTesting");
	}
	Function PlayerMove(float DeltaTime)
	{
		FRotator NewRotation = FRotator(0,0,0);
		AActor* VA = nullptr;
		VA=ViewTarget;
		if (VA != nullptr)
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
				if (EventLab != nullptr)
				{
					EventLab.ActorNotify(this,31,Pawn,"CHEATING");
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
*/

/*
State ClassTwoSitting extends MedicTraining_SittingAtDesk
{
	Function Begin()
	{
		FRotator NewRotation = FRotator(0,0,0);
		SittingState=GetStateName();
		SetViewTarget(GetActorByTag("VT_DeskTwo"));
		SetFOVAngle(65);
		LockPlayer(true,true);
		Pawn.bHidden=true;
		NewRotation=ViewTarget.Rotation;
		NewRotation.Yaw=48616;
		ViewTarget.SetRotation(NewRotation);
		bSeated=true;
		Pawn.GotoState("Hidden");
	}
	exec Function Action()
	{
		GotoState("ClassTwoTesting");
	}
	Function PlayerMove(float DeltaTime)
	{
		FRotator NewRotation = FRotator(0,0,0);
		AActor* VA = nullptr;
		VA=ViewTarget;
		if (VA != nullptr)
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
				if (EventLab != nullptr)
				{
					EventLab.ActorNotify(this,31,Pawn,"CHEATING");
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
*/

/*
State ClassThreeSitting extends MedicTraining_SittingAtDesk
{
	Function Begin()
	{
		FRotator NewRotation = FRotator(0,0,0);
		SittingState=GetStateName();
		SetViewTarget(GetActorByTag("VT_DeskThree"));
		SetFOVAngle(65);
		LockPlayer(true,true);
		Pawn.bHidden=true;
		NewRotation=ViewTarget.Rotation;
		NewRotation.Yaw=16000;
		ViewTarget.SetRotation(NewRotation);
		bSeated=true;
		Pawn.GotoState("Hidden");
	}
	exec Function Action()
	{
		GotoState("ClassThreeTesting");
	}
	Function PlayerMove(float DeltaTime)
	{
		FRotator NewRotation = FRotator(0,0,0);
		AActor* VA = nullptr;
		VA=ViewTarget;
		if (VA != nullptr)
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
				if (EventLab != nullptr)
				{
					EventLab.ActorNotify(this,31,Pawn,"CHEATING");
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
*/

/*
State MedicTraining_TakingExam
{
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "StudentController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Begin();
		Cast<AAGP_HUD>(myHUD).SetHUDActor();
		HUDCrosshair(Cast<AAGP_HUD>(myHUD).GetHUDControl(10)).SetCrossHairColor(1);
		Cast<AAGP_HUD>(myHUD).FreeHUDActor();
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
	Function ServerAction(AActor* Other)
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
		AActor* Other = nullptr;
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
		MyExam.Trigger(this,Pawn);
		Sleep(0.2);
	}
	if (bLeanRight != 0)
	{
		MyExam.UnTrigger(this,Pawn);
		Sleep(0.2);
	}
	Sleep(0.01);
	JL"Begin"
;
}
*/

/*
State ClassOneTesting extends MedicTraining_TakingExam
{
	Function Begin()
	{
		SetViewTarget(GetActorByTag("VT_PaperOne"));
		SetFOVAngle(DefaultFOV);
		Pawn.bHidden=true;
		MyExam=GetActorByTag("MedExamOne");
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector NewLocation = FVector(0,0,0);
		AActor* VA = nullptr;
		VA=ViewTarget;
		if (VA != nullptr)
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
*/

/*
State ClassTwoTesting extends MedicTraining_TakingExam
{
	Function Begin()
	{
		SetViewTarget(GetActorByTag("VT_PaperTwo"));
		SetFOVAngle(DefaultFOV);
		Pawn.bHidden=true;
		MyExam=GetActorByTag("MedExamTwo");
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector NewLocation = FVector(0,0,0);
		AActor* VA = nullptr;
		VA=ViewTarget;
		if (VA != nullptr)
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
*/

/*
State ClassThreeTesting extends MedicTraining_TakingExam
{
	Function Begin()
	{
		SetViewTarget(GetActorByTag("VT_PaperThree"));
		SetFOVAngle(DefaultFOV);
		Pawn.bHidden=true;
		MyExam=GetActorByTag("MedExamThree");
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector NewLocation = FVector(0,0,0);
		AActor* VA = nullptr;
		VA=ViewTarget;
		if (VA != nullptr)
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
*/

/*
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
			Log(string(this) @ "StudentController::BeginState() - in state" @ FString::FromInt(GetStateName()));
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
	JL"Begin"
;
}
*/

/*
State SFTraining_SittingAtDesk
{
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "StudentController::BeginState() - in state" @ FString::FromInt(GetStateName()));
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
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this,31,Pawn,"EXITCHAIR");
		}
		if (_Target != nullptr)
		{
			_Target.Notify();
		}
		Log(string(this) @ "StudentController::MedicTraining_SittingAtDesk::Jump	Moving controller to PlayerWalking state");
		GotoState("PlayerWalking");
		bSeated=false;
	}
	Function PlayWaiting()
	{
	}
	exec Function Action()
	{
	}
	Function ServerAction(AActor* Other)
	{
	}
	Function AutoTrace()
	{
		_AutoTraceHitActor=nullptr;
		TryToIDActor(nullptr);
		TryToIDPawn(nullptr);
	}
}
*/

/*
State SFClassOneSitting extends SFTraining_SittingAtDesk
{
	Function Begin()
	{
		FRotator NewRotation = FRotator(0,0,0);
		SittingState=GetStateName();
		SetViewTarget(GetActorByTag("VT_DeskOne"));
		SetFOVAngle(65);
		LockPlayer(true,true);
		Pawn.bHidden=true;
		NewRotation=ViewTarget.Rotation;
		NewRotation.Yaw=65000;
		ViewTarget.SetRotation(NewRotation);
		bSeated=true;
		Pawn.GotoState("Hidden");
	}
	exec Function Action()
	{
		if (Level.bSkipTest == false)
		{
			GotoState("SFClassOneTesting");
		}
	}
	Function PlayerMove(float DeltaTime)
	{
		FRotator NewRotation = FRotator(0,0,0);
		AActor* VA = nullptr;
		VA=ViewTarget;
		if (VA != nullptr)
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
				if (EventLab != nullptr)
				{
					EventLab.ActorNotify(this,31,Pawn,"CHEATING");
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
*/

/*
State SFClassTwoSitting extends SFTraining_SittingAtDesk
{
	Function Begin()
	{
		FRotator NewRotation = FRotator(0,0,0);
		SittingState=GetStateName();
		SetViewTarget(GetActorByTag("VT_DeskTwo"));
		SetFOVAngle(65);
		LockPlayer(true,true);
		Pawn.bHidden=true;
		NewRotation=ViewTarget.Rotation;
		NewRotation.Yaw=65000;
		ViewTarget.SetRotation(NewRotation);
		bSeated=true;
		Pawn.GotoState("Hidden");
	}
	exec Function Action()
	{
		if (Pawn.Weapon->IsA(Aitem_headphones::StaticClass()))
		{
			GotoState("SFClassTwoTesting");
		}
	}
	Function PlayerMove(float DeltaTime)
	{
		FRotator NewRotation = FRotator(0,0,0);
		AActor* VA = nullptr;
		VA=ViewTarget;
		if (VA != nullptr)
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
				if (EventLab != nullptr)
				{
					EventLab.ActorNotify(this,31,Pawn,"CHEATING");
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
*/

/*
State SFTraining_TakingExam
{
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "StudentController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Begin();
		Cast<AAGP_HUD>(myHUD).SetHUDActor();
		HUDCrosshair(Cast<AAGP_HUD>(myHUD).GetHUDControl(10)).SetCrossHairColor(1);
		Cast<AAGP_HUD>(myHUD).FreeHUDActor();
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
	Function ServerAction(AActor* Other)
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
		AActor* Other = nullptr;
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
		MyExam.Trigger(this,Pawn);
		Sleep(0.2);
	}
	if (bLeanRight != 0)
	{
		MyExam.UnTrigger(this,Pawn);
		Sleep(0.2);
	}
	Sleep(0.01);
	JL"Begin"
;
}
*/

/*
State SFClassOneTesting extends SFTraining_TakingExam
{
	Function Begin()
	{
		SetViewTarget(GetActorByTag("VT_PaperOne"));
		SetFOVAngle(DefaultFOV);
		Pawn.bHidden=true;
		MyExam=GetActorByTag("SFExamOne");
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector NewLocation = FVector(0,0,0);
		AActor* VA = nullptr;
		VA=ViewTarget;
		if (VA != nullptr)
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
*/

/*
State SFClassTwoTesting extends SFTraining_TakingExam
{
	Function Begin()
	{
		SetViewTarget(GetActorByTag("VT_PaperTwo"));
		SetFOVAngle(DefaultFOV);
		Pawn.bHidden=true;
		MyExam=GetActorByTag("SFExamOne");
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector NewLocation = FVector(0,0,0);
		AActor* VA = nullptr;
		VA=ViewTarget;
		if (VA != nullptr)
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
*/

/*
State PlayerWalking
{
	Function BeginState()
	{
		Super::BeginState();
		if ("" + FString::FromInt(Level) ~= "Entry.LevelInfo0")
		{
			LockPlayer(true,true);
			bBehindView=false;
		}
	}
}
*/

/*
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

static const int32 MAX_ACTOR_TRACE_DIST = 32767;
static const int32 DEF_ACTOR_TRACE_DIST = 96;

//native Function Texture LoadVRSPosterTextureFromDDS(FString FilePath);
UMaterialInstance* AStudentController::LoadVRSPosterTextureFromDDS(FString FilePath)
{
	return nullptr;    //FAKE   /EliZ
}

bool AStudentController::IsCheating()
{
	return bUsedCheats;
}

bool AStudentController::IsSeated()
{
	return bSeated;
}

bool AStudentController::IsPossiblyCheating()
{
	return bPossiblyCheating;
}

bool AStudentController::SkipSlides()
{
	return bSkipSlides;
}

void AStudentController::Grenade(uint8 Index)
{
	if (npcpnbPathNodeBuilder != nullptr)
	{
		npcpnbPathNodeBuilder->SetValidGrenadePosture();
		return;
	}
	/*
	if (Pawn->_InvGrenades[(Index - 1)] != 0)
	{
		Super::Grenade(Index);
	}
	else
	{
		return;
	}
	*/
}

void AStudentController::DevMode(bool bSet)
{
	bUsedCheats = true;
	/*
	if (Level.Title == "Virtual Recruiting Station")
	{
		ClientMessage("Cheating is not allowed");
		return;
	}
	Super::DevMode(bSet);
	if (EventLab != nullptr)
	{
		EventLab.EventLabNotifyCheat();
	}
	*/
}

void AStudentController::MPCheat(FString cheat)
{
	bUsedCheats = true;
	/*
	if (Level.Title == "Virtual Recruiting Station")
	{
		ClientMessage("Cheating is not allowed");
		return;
	}
	Super::MPCheat(cheat);
	*/
}

void AStudentController::PreBeginPlay()
{
	npcpnbPathNodeBuilder = nullptr;
	//Super::PreBeginPlay();
	SwapAllPosters();
	/*
	if (Level.fpSinglePlayerFadeInTime > 0)
	{
		DoFade(false, true, 0);
	}
	*/
}

void AStudentController::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	SetCustomTimer(0.5, false, "CustomSetupTimer");
	*/
}

void AStudentController::CustomSetupTimer()
{
	/*
	if (Level.bSinglePlayerHideHUD)
	{
		if (Cast<AAGP_HUD>(myHUD) != nullptr)
		{
			Cast<AAGP_HUD>(myHUD).bShowHUD = false;
		}
	}
	if (Level.bSinglePlayerStartUnlocked)
	{
		LockPlayer(false, false);
	}
	if (Level.bSinglePlayerExploreMode)
	{
		LockPlayer(false, false);
		MPCheat_SuperGod();
	}
	StopCustomTimer("CustomSetupTimer");
	*/
}

void AStudentController::Suicide()
{
	/*
	if (Level.GetTourIsTraining(Level.iTour))
	{
		ConsoleCommand("Reconnect");
		return;
	}
	Super::Suicide();
	*/
}

void AStudentController::Timer()
{
	/*
	Super::Timer();
	if (Level.fpSinglePlayerFadeInStart > 0)
	{
		Log(string(GetWorld()->GetTimeSeconds()) + " - Timer() - FadeIN time: " + FString::FromInt(Level.fpSinglePlayerFadeInTime) + " fadestart: " + FString::FromInt(_fFadeStartTime));
		if ((GetWorld()->GetTimeSeconds() >= Level.fpSinglePlayerFadeInStart) && (_fFadeStartTime == 0))
		{
			DoFade(true, true, Level.fpSinglePlayerFadeInTime);
		}
	}
	*/
}

void AStudentController::ETAJoinServer(FString sServerIP, FString sSurName, FString sNickName, FString sPassword)
{
	int32 iIndex = 0;
	bool fGoodName = false;
	/*
	if (((Len(sSurName) == 0) || (Len(sNickName) == 0)) || (Len(sServerIP) == 0))
	{
		ClientMessage("Syntax: ETAJoinServer <Server IP> <SurName> <NickName> [Server Password]");
		return;
	}
	for (iIndex = 0; iIndex < Level.asETASurNames.Num(); iIndex++)
	{
		if (Level.asETASurNames[iIndex] == sSurName)
		{
			fGoodName = true;
		}
	}
	if (!fGoodName)
	{
		for (iIndex = 0; iIndex < Level.asETASurNames.Num(); iIndex++)
		{
			ClientMessage(Level.asETASurNames[iIndex]);
		}
		ClientMessage("Invalid Surname entered.  Use one of these:");
		return;
	}
	fGoodName = false;
	for (iIndex = 0; iIndex < Level.asETANickNames.Num(); iIndex++)
	{
		if (Level.asETANickNames[iIndex] == sNickName)
		{
			fGoodName = true;
		}
	}
	if (!fGoodName)
	{
		for (iIndex = 0; iIndex < Level.asETANickNames.Num(); iIndex++)
		{
			ClientMessage(Level.asETANickNames[iIndex]);
		}
		ClientMessage("Invalid Nick Name entered.  Use one of these:");
		return;
	}
	sETAUserSelectedSurName = sSurName;
	sETAUserSelectedNickName = sNickName;
	if ((UserName != sSurName + "|" + sNickName) && (InStr(UserName, "|") == -1))
	{
		sSavedUserName = UserName;
	}
	UserName = UserName + "|" + sSurName + "|" + sNickName;
	SaveConfig();
	ClientMessage("Trying to connect to \"" + sServerIP + "\" with user \"" + UserName + "\"");
	if (Len(sPassword) > 0)
	{
		ConsoleCommand("start " + sServerIP + "?Password=" + sPassword);
	}
	else
	{
		ConsoleCommand("start " + sServerIP);
	}
	*/
}

void AStudentController::ETARestoreUserName()
{
	RestoreSavedUserNameAndPassword();
}

void AStudentController::ClientMessage(FString S, FName Type)
{
	FColor Color = FColor(0, 0, 0, 0);
	Color.R = 255;
	Color.G = 255;
	Color.B = 0;
	Color.A = 255;
	//Player.Console.Message(S, 20, Color);
}

void AStudentController::FieldSkipIntro()
{
	bUsedCheats = true;
	bFieldSkipIntro = (!bFieldSkipIntro);
	if (bFieldSkipIntro)
	{
		//Log("FIELDTRAINING: SkipIntro Enabled");
	}
	else
	{
		//Log("FIELDTRAINING: SkipIntro Disabled");
	}
	SaveConfig();
}

void AStudentController::TrainingSkipSlides()
{
	bUsedCheats = true;
	bSkipSlides = (!bSkipSlides);
	if (bSkipSlides)
	{
		//Log("SkipSlides Enabled");
	}
	else
	{
		//Log("SkipSlides Disabled");
	}
}

void AStudentController::DebugSpawnNodeTester(bool bShowPathMarkers, FString sNavTag)
{
	ANPCPlayerStartCivilian* npcps = nullptr;
	/*
	npcps = Spawn(ANPCPlayerStartCivilian::StaticClass(), , , ((Pawn.Location + (float(250) * Vector(Pawn.Rotation))) + FVector(0, 0, 50)), Pawn.Rotation, true, true);
	Log("Spawned civilian player start node tester: " + FString::FromInt(npcps));
	if (npcps != nullptr)
	{
		npcps.HUDText = "Node Tester";
		npcps.bShouldFollowUser = true;
		npcps.fpFollowDistance = 200;
		if (Len(sNavTag) > 0)
		{
			npcps.sNPCWaypointTag = sNavTag;
			npcps.enpcoPrimaryOrders = npcps.0;
		}
		else
		{
			npcps.bStartAsDummyPawn = true;
			npcps.sNPCWaypointTag = "CivTester";
		}
		npcps.bDebugPath = bShowPathMarkers;
		npcps.Tag = "CivTester";
		Log("Creating NPC " + FString::FromInt(npcps.CreateNPC()));
	}
	else
	{
		Log("Unsupported Command");
	}
	*/
}

void AStudentController::Help()
{
	/*
	if (Level.GetTourIsTraining(Level.iTour))
	{
		return;
	}
	if (npcpnbPathNodeBuilder != nullptr)
	{
		NPCPathBuilderHelp();
		return;
	}
	else
	{
		ClientMessage("PNB - Activates Path Node Builder");
	}
	Super::Help();
	*/
}

void AStudentController::NPCPathBuilderHelp()
{
	/*
	ClientMessage("");
	ClientMessage("ForceConnection - Force connection from current node to last node selected/dropped " + "(Press " + AGameInfo::StaticClass().GetKeyBindName("ForceConnection", this) + " )");
	ClientMessage("SetCurrentPlayerStartName <newname>");
	ClientMessage("SetCurrentNodeTag <newtag>");
	ClientMessage("ManNodePosition (Press " + AGameInfo::StaticClass().GetKeyBindName("ManNodePosition", this) + " )");
	ClientMessage("Force dropping node: " + AGameInfo::StaticClass().GetKeyBindName("PathBuilderForceDrop", this));
	ClientMessage("DropPathNode (Press " + AGameInfo::StaticClass().GetKeyBindName("DropCustomPathNode", this) + " )");
	ClientMessage("StartPatrolPath <nav tag name>");
	ClientMessage("EndPatrolPath");
	ClientMessage("DropWaypointPathNode (Press " + AGameInfo::StaticClass().GetKeyBindName("DropWaypointPathNode", this) + ")");
	ClientMessage("DropCustomPathNode <type> - " + " Alamo (" + AGameInfo::StaticClass().GetKeyBindName("DropAlamoPathNode", this) + ")" + ", Camper (" + AGameInfo::StaticClass().GetKeyBindName("DropCamperPathNode", this) + ")" + ", Cover (" + AGameInfo::StaticClass().GetKeyBindName("DropCoverPathNode", this) + ")" + ", Firing (" + AGameInfo::StaticClass().GetKeyBindName("DropFiringPathNode", this) + ")" + ", Door, Ladder");
	ClientMessage("ChangePostureAndRotation - edits currently selected node's rotation and posture");
	ClientMessage("[Start/Stop/Toggle]AutoDropMode - enables/disables (toggles: " + AGameInfo::StaticClass().GetKeyBindName("ToggleAutoDropMode", this) + ") automatically dropping nodes ");
	ClientMessage("-----------------------------------------");
	ClientMessage("PNBTogglePaths - Toggles showing existing paths");
	ClientMessage("TestPaths - saves current paths and then loads copy of map to observe AI.");
	ClientMessage("BuildMapWithPaths <filename.aao> - Name of map to create with AI paths in it.");
	ClientMessage("ResetPaths - clears all paths");
	ClientMessage("SavePaths <filename> (do not include extension)");
	ClientMessage("LoadPaths <filename> (do not include extension)");
	ClientMessage("ImportPaths - import existing pathnodes into NPC Path Builder");
	ClientMessage("[Start/Stop]NPCPathBuilder - starts/stops NPC Path Builder");
	ClientMessage("---------------------");
	ClientMessage("NPC Path Builder Help");
	*/
}

void AStudentController::StartNPCPathBuilder()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		//npcpnbPathNodeBuilder = Spawn(ANPCPathNodeBuilder::StaticClass());
	}
	if (npcpnbPathNodeBuilder != nullptr)
	{
		npcpnbPathNodeBuilder->SetPathBuilderOwner(this);
		npcpnbPathNodeBuilder->EnablePathBuilding(true);
	}
	else
	{
		//ClientMessage("Failed to spawn Path Node Builder");
	}
}

void AStudentController::PNBTogglePaths()
{
	Cast<AAGP_HUD>(MyHUD)->bShowPaths = (!(Cast<AAGP_HUD>(MyHUD)->bShowPaths));
}

void AStudentController::SavePaths(FString sFileName)
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	if (sFileName.Len() == 0)
	{
		ClientMessage("Syntax: SavePaths <filename with no extention>","");
		return;
	}
	npcpnbPathNodeBuilder->SavePathNodesToFile(sFileName);
}

void AStudentController::BuildMapWithPaths(FString sFileName)
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	if ((npcpnbPathNodeBuilder->GetPNBFileName().Len()) == 0)
	{
		ClientMessage("You must save your paths first using \"SavePaths <filename>\".","");
		return;
	}
	if (sFileName.Len() == 0)
	{
		ClientMessage("Please supply the name to use for your new map and include the extension \".aao\".","");
		return;
	}
	npcpnbPathNodeBuilder->SaveFinalMapPaths(sFileName);
}

void AStudentController::TestPaths()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	if ((npcpnbPathNodeBuilder->GetPNBFileName().Len()) == 0)
	{
		ClientMessage("You must save your paths first using \"SavePaths <filename>\".","");
		return;
	}
	npcpnbPathNodeBuilder->TestPathNodes();
}

void AStudentController::LoadPaths(FString sFileName)
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	if (sFileName.Len() == 0)
	{
		ClientMessage("Syntax: LoadPaths <filename with no extention>","");
		return;
	}
	npcpnbPathNodeBuilder->LoadPathNodesFromFile(sFileName);
}

void AStudentController::SetCurrentPlayerStartName(FString sNewName)
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	if (sNewName.Len() == 0)
	{
		ClientMessage("Syntax: SetCurrentPlayerStartName <newname>","");
		return;
	}
	npcpnbPathNodeBuilder->SetNPCName(sNewName);
}

void AStudentController::SetCurrentNodeTag(FString sNewTag)
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	if (sNewTag.Len() == 0)
	{
		ClientMessage("Syntax: SetCurrentNodeTag <newtag>","");
		return;
	}
	npcpnbPathNodeBuilder->SetCurrentNodeTag(sNewTag);
}

void AStudentController::StopNPCPathBuilder()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	npcpnbPathNodeBuilder->EnablePathBuilding(false);
}

void AStudentController::DropPathNode()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	npcpnbPathNodeBuilder->DropNode(false);
}

void AStudentController::DropRoadNode()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	npcpnbPathNodeBuilder->DropRoadNode(false);
}

void AStudentController::DropCustomPathNode(FString sType)
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	npcpnbPathNodeBuilder->DropCustomNode(sType);
}

void AStudentController::StartPatrolPath(FString sWaypointNavTag)
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	npcpnbPathNodeBuilder->StartNewPatrolPath(sWaypointNavTag);
}

void AStudentController::EndPatrolPath()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding", "");
		return;
	}
	npcpnbPathNodeBuilder->EndPatrolPath();
}

void AStudentController::DropWaypointPathNode()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding", "");
		return;
	}
	npcpnbPathNodeBuilder->DropWaypointNode();
}

void AStudentController::DeletePathNode()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding", "");
		return;
	}
	npcpnbPathNodeBuilder->RequestDeleteNode();
}

void AStudentController::StartAutoDropMode()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding", "");
		return;
	}
	npcpnbPathNodeBuilder->StartAutoDropMode();
}

void AStudentController::ToggleAutoDropMode()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding", "");
		return;
	}
	if (npcpnbPathNodeBuilder->bInAutoDropMode)
	{
		npcpnbPathNodeBuilder->EndAutoDropMode();
	}
	else
	{
		npcpnbPathNodeBuilder->StartAutoDropMode();
	}
}

void AStudentController::StopAutoDropMode()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	npcpnbPathNodeBuilder->EndAutoDropMode();
}

void AStudentController::EditPathNode()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
}

void AStudentController::Fire(float F)
{
	if (npcpnbPathNodeBuilder != nullptr)
	{
		npcpnbPathNodeBuilder->SetFireWeaponPosture();
	}
	else
	{
		/*
		if (EventLab != nullptr)
		{
			EventLab.ELPlayerPressedFireNotifier();
		}
		Super::Fire(F);
		*/
	}
}

void AStudentController::ManNodePosition()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	npcpnbPathNodeBuilder->ManNodePosition();
}

void AStudentController::ImportPaths()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	npcpnbPathNodeBuilder->ImportPaths();
}

void AStudentController::Action()
{
	AActor* Other = nullptr;
	/*
	if ((npcpnbPathNodeBuilder == nullptr) || (bAltFire == 1))
	{
		Super::Action();
		return;
	}
	Other = ManualTrace(GetTraceDistance());
	if ((Other != nullptr) && Other->IsA(AMover::StaticClass()))
	{
		npcpnbPathNodeBuilder->MoverUsed();
		ServerAction(Other);
		return;
	}
	npcpnbPathNodeBuilder->Action();
	*/
}

void AStudentController::ChangePostureAndRotation()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding","");
		return;
	}
	npcpnbPathNodeBuilder->EditRotationAndPosture();
}

void AStudentController::ResetPaths()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding", "");
		return;
	}
	npcpnbPathNodeBuilder->RequestResetPaths();
}

void AStudentController::ForceConnection()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding", "");
		return;
	}
	npcpnbPathNodeBuilder->ForceConnection();
}

void AStudentController::EditSelected()
{
	if (npcpnbPathNodeBuilder == nullptr)
	{
		ClientMessage("You must initialize the path builder using NPCStartPathNoding", "");
		return;
	}
}

void AStudentController::StartClimbingLadder(ALadderVolume* lvLadder)
{
	if (npcpnbPathNodeBuilder != nullptr)
	{
		//Log("Entering ladder volume: " + FString::FromInt(lvLadder));
		npcpnbPathNodeBuilder->EnteringLadderVolume();
	}
}

void AStudentController::EndClimbingLadder(ALadderVolume* lvLadder)
{
	if (npcpnbPathNodeBuilder != nullptr)
	{
		//Log("Exiting ladder volume: " + FString::FromInt(lvLadder));
		npcpnbPathNodeBuilder->ExitingLadderVolume();
	}
}

void AStudentController::ClientCloseMenu(bool bCloseAll, bool bCancel)
{
	//Super::ClientCloseMenu(bCloseAll, bCancel);
	Cast<AAGP_HUD>(MyHUD)->bShowHUD = true;
	//Player->bShowWindowsMouse = false;
}

void AStudentController::PNB()
{
	ConsoleCommand("playerlock 0");
	ConsoleCommand("mpcheat supergod");
	ConsoleCommand("DebugDisableAllNPCs true");
	ConsoleCommand("mpcheat behindview 1");
	ConsoleCommand("StartNPCPathBuilder");
}

void AStudentController::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	Super::DisplayDebug(Canvas, YL, YPos);
	if (vehUAV != nullptr)
	{
		vehUAV.DisplayDebug(Canvas, YL, YPos);
	}
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Last item viewed: " + FString::FromInt(_LastGlowActor));
	*/
}

void AStudentController::AutoTrace()
{
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	AActor* HitActor = nullptr;
	UMaterialInstance* HitMaterial = nullptr;
	/*
	Super::AutoTrace();
	GetAxes(Pawn.GetViewRotation(), X, Y, Z);
	StartTrace.X = Pawn.Location.X;
	StartTrace.Y = Pawn.Location.Y;
	StartTrace.Z = (Pawn.Location.Z + Pawn.BaseEyeHeight);
	(StartTrace += (Pawn.CollisionRadius * X));
	EndTrace = (StartTrace + (float(100) * X));
	HitActor = Pawn.Trace(HitLocation, HitNormal, EndTrace, StartTrace, true, , HitMaterial);
	if (((HitActor != nullptr) && HitActor->IsA(ATriggerURL::StaticClass())) && (HitActor != actVAELastViewed))
	{
		actVAELastViewed = HitActor;
		Log("Trigger URL in sight: " + FString::FromInt(HitActor) + " for skin " + FString::FromInt(HitActor.Skins[2]));
		HitMaterial = actVAELastViewed.Skins[2];
	}
	else
	{
		if (HitActor == nullptr)
		{
			if (actVAELastViewed != nullptr)
			{
				actVAELastViewed = nullptr;
				HitMaterial = nullptr;
			}
		}
	}
	if ((HitMaterial != nullptr) && (HitMaterial != matVAELastViewed))
	{
		if (HitMaterial.bTrackViewTime)
		{
			fpVAETimeStartedViewingPoster = GetWorld()->GetTimeSeconds();
			matVAELastViewed = HitMaterial;
		}
	}
	else
	{
		if ((HitMaterial == nullptr) && (matVAELastViewed != nullptr))
		{
			VAEUpdatePoster(string(matVAELastViewed), (GetWorld()->GetTimeSeconds() - fpVAETimeStartedViewingPoster));
			fpVAETimeStartedViewingPoster = 0;
			matVAELastViewed = nullptr;
		}
	}
	*/
}

void AStudentController::VAEUpdatePoster(FString sPosterMaterial, float fpTimeViewed)
{
	int32 iPoster = 0;
	/*
	for (iPoster = 0; iPoster < avaepviPosterTracking.Num(); iPoster++)
	{
		if (sPosterMaterial == avaepviPosterTracking[iPoster].sPosterMaterial)
		{
			avaepviPosterTracking[iPoster].fpViewingTime += fpTimeViewed;
			return;
		}
	}
	avaepviPosterTracking.insert(avaepviPosterTracking.Num(), 1);
	avaepviPosterTracking[(avaepviPosterTracking.Num() - 1)].sPosterMaterial = sPosterMaterial;
	avaepviPosterTracking[(avaepviPosterTracking.Num() - 1)].fpViewingTime = fpTimeViewed;
	*/
}

void AStudentController::ShowMenu()
{
	/*
	Log("ShowMenu called for level \"" + Level.Title + "\"");
	if (Level.Title == "Virtual Recruiting Station")
	{
		ClientOpenMenu("AGP_Interface.AAGameMenuVAE", , "Score");
	}
	else
	{
		Super::ShowMenu();
	}
	*/
}

void AStudentController::SwapAllPosters()
{
	AAGP_UseTrigger* turlIterator = nullptr;
	/*
	ForEach AllActors(AAGP_UseTrigger::StaticClass(), turlIterator)
	{
		if (turlIterator.bSwappablePoster && (Len(turlIterator.sSwapName) > 0))
		{
			SwapPoster(turlIterator);
		}
	}
	*/
}

void AStudentController::SwapPoster(AAGP_UseTrigger* agpturl)
{
	UMaterialInstance* textImage = nullptr;
	FString sPosterName = "";
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		return;
	}
	if (agpturl != nullptr)
	{
		sPosterName = "DynamicContent/Posters/" + agpturl->sSwapName + ".dds";
		//Log("Importing poster \"" + sPosterName + "\"");
		textImage = LoadVRSPosterTextureFromDDS(sPosterName);
		if (textImage != nullptr)
		{
			//Log("Swapping poster to " + FString::FromInt(textImage));
			//agpturl->Skins[2] = textImage;
		}
	}
}
