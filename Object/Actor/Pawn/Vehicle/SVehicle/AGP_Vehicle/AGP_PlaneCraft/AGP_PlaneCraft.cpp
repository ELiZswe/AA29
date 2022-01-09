// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_PlaneCraft/AGP_PlaneCraft.h"

AAGP_PlaneCraft::AAGP_PlaneCraft()
{
	CameraSwingRatio = 0.02;
	CameraDistance = 900;
}

void AAGP_PlaneCraft::PostNetBeginPlay()
{
	/*
	local Object.Vector RotX;
	local Object.Vector RotY;
	local Object.Vector RotZ;
	local KarmaParams KP;
	local KRepulsor rep;
	int32 i;
	GetAxes(Rotation, RotX, RotY, RotZ);
	KP = KarmaParams(KParams);
	KP.Repulsors.Num() = ThrusterOffsets.Num();
	for (i = 0; i < ThrusterOffsets.Num(); i++)
	{
		rep = Spawn(Class'KRepulsor', this, , Location + ThrusterOffsets[i].X * RotX + ThrusterOffsets[i].Y * RotY + ThrusterOffsets[i].Z * RotZ);
		rep.SetBase(this);
		rep.bHidden = true;
		KP.Repulsors[i] = rep;
	}
	PostNetBeginPlay();
	*/
}

void AAGP_PlaneCraft::Destroyed()
{
	/*
	local KarmaParams KP;
	int32 i;
	KP = KarmaParams(KParams);
	for (i = 0; i < KP.Repulsors.Num(); i++)
	{
		KP.Repulsors[i].Destroy();
	}
	Destroyed();
	*/
}

bool AAGP_PlaneCraft::KUpdateState(FKRigidBodyState NewState)
{
	/*
	if (Role == 4 || !bNewPlaneState)
	{
		return false;
	}
	NewState = ChassisState;
	bNewPlaneState = false;
	*/
	return true;
}

void AAGP_PlaneCraft::SVehicleUpdateParams()
{
	/*
	local KarmaParams KP;
	int32 i;
	SVehicleUpdateParams();
	KP = KarmaParams(KParams);
	for (i = 0; i < KP.Repulsors.Num(); i++)
	{
		KP.Repulsors[i].Softness = HoverSoftness;
		KP.Repulsors[i].PenScale = HoverPenScale;
		KP.Repulsors[i].CheckDist = HoverCheckDist;
	}
	*/
}

int32 AAGP_PlaneCraft::GetRotDiff(int32 A, int32 B)
{
	int32 Comp=0;
	/*
	Comp = (A - B) & 65535;
	if (Comp > 32768)
	{
		Comp -= 65536;
	}
	*/
	return Comp;
}

void AAGP_PlaneCraft::SpecialCalcBehindView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local Object.Vector CamLookAt;
	local Object.Vector HitLocation;
	local Object.Vector HitNormal;
	local float LerpAmount;
	local float CurTime;
	ViewActor = this;
	CurTime = Level.TimeSeconds;
	LerpAmount = 1 - CameraSwingRatio * *CurTime - LastCamTime;
	LastCamTime = CurTime;
	CamLookAt = Location;
	CameraRotation.Roll = 0;
	CameraRotation.Yaw = LastCamRot.Yaw + GetRotDiff(Rotation.Yaw, LastCamRot.Yaw) * LerpAmount;
	CameraRotation.Pitch = -4000;
	CameraLocation = CamLookAt + CameraDistance * vect(-1 0 0) >> CameraRotation;
	if (Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, False, vect(10 10 10)) != nullptr)
	{
		CameraLocation = HitLocation;
	}
	LastCamRot = CameraRotation;
	*/
}

void AAGP_PlaneCraft::SpecialCalcFirstPersonView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local Object.Vector CamLookAt;
	local Object.Vector HitLocation;
	local Object.Vector HitNormal;
	local float LerpAmount;
	local float CurTime;
	ViewActor = this;
	CurTime = Level.TimeSeconds;
	LerpAmount = 1 - CameraSwingRatio * *CurTime - LastCamTime;
	LastCamTime = CurTime;
	CamLookAt = Location;
	CameraRotation.Roll = 0;
	CameraRotation.Yaw = 16384 + LastCamRot.Yaw + GetRotDiff(Rotation.Yaw, LastCamRot.Yaw) * LerpAmount;
	CameraRotation.Pitch = -4000;
	CameraLocation = CamLookAt + CameraDistance * vect(0 1 0) >> CameraRotation;
	if (Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, False, vect(10 10 10)) != nullptr)
	{
		CameraLocation = HitLocation;
	}
	LastCamRot = CameraRotation;
	*/
}
