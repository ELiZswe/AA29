// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_TrackedCraft/AGP_TrackedCraft.h"
#include "AA29/Object/Actor/KRepulsor/KRepulsor.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParams.h"

AAGP_TrackedCraft::AAGP_TrackedCraft()
{

}

bool AAGP_TrackedCraft::KUpdateState(FKRigidBodyState& NewState)
{
	/*
	if (Role == 4 || !bNewTrackedState)
	{
		return false;
	}
	NewState = ChassisState;
	bNewTrackedState = false;
	*/
	return true;
}

void AAGP_TrackedCraft::PostBeginPlay()
{
	Super::PostBeginPlay();
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		SetupTreads();
	}
}

void AAGP_TrackedCraft::PostNetBeginPlay()
{
	FVector RotX = FVector(0,0,0);
	FVector RotY = FVector(0, 0, 0);
	FVector RotZ = FVector(0, 0, 0);
	UKarmaParams* KP = nullptr;
	AKRepulsor* rep = nullptr;
	int32 i = 0;
	/*
	GetAxes(Rotation, RotX, RotY, RotZ);
	KP = KarmaParams(KParams);
	KP.Repulsors.Num() = ThrusterOffsets.Num();
	for (i = 0; i < ThrusterOffsets.Num(); i++)
	{
		rep = Spawn(AKRepulsor::StaticClass(), this, , Location + ThrusterOffsets[i].X * RotX + ThrusterOffsets[i].Y * RotY + ThrusterOffsets[i].Z * RotZ);
		rep.SetBase(this);
		rep.bHidden = true;
		KP.Repulsors[i] = rep;
	}
	*/
	Super::PostNetBeginPlay();
}

void AAGP_TrackedCraft::Destroyed()
{
	UKarmaParams* KP = nullptr;
	int32 i = 0;
	DestroyTreads();
	KP = Cast<UKarmaParams>(KParams);
	for (i = 0; i < KP->Repulsors.Num(); i++)
	{
		KP->Repulsors[i]->Destroy();
	}
	Super::Destroyed();
}

void AAGP_TrackedCraft::SVehicleUpdateParams()
{
	UKarmaParams* KP = nullptr;
	int32 i = 0;
	Super::SVehicleUpdateParams();
	KP = Cast<UKarmaParams>(KParams);
	for (i = 0; i < KP->Repulsors.Num(); i++)
	{
		KP->Repulsors[i]->Softness = HoverSoftness;
		KP->Repulsors[i]->PenScale = HoverPenScale;
		KP->Repulsors[i]->CheckDist = HoverCheckDist;
	}
	//KSetStayUprightParams(UprightStiffness, UprightDamping);
}

void AAGP_TrackedCraft::DamageTread(bool bRightTread)
{
	if (bRightTread)
	{
		//SetBoneScale(0, 1, LeftTreadDamageBone);
		//SetBoneScale(0, 0, LeftTreadBone);
	}
	else
	{
		//SetBoneScale(0, 1, RightTreadDamageBone);
		//SetBoneScale(0, 0, RightTreadBone);
	}
}

void AAGP_TrackedCraft::SetupTreads()
{
	/*
	SetBoneScale(0, 0, LeftTreadDamageBone);
	SetBoneScale(0, 0, RightTreadDamageBone);
	LeftTreadPanner = VariableTexPanner(Level.ObjectPool.AllocateObject(Class'VariableTexPanner'));
	if (LeftTreadPanner != nullptr)
	{
		LeftTreadPanner.Material = Skins[LeftTreadSkinNum];
		LeftTreadPanner.PanDirection = TreadPannerRotation;
		LeftTreadPanner.PanRate = 0;
		Skins[LeftTreadSkinNum] = LeftTreadPanner;
		Log("Configured left tread panner: " + LeftTreadPanner);
	}
	RightTreadPanner = VariableTexPanner(Level.ObjectPool.AllocateObject(Class'VariableTexPanner'));
	if (RightTreadPanner != nullptr)
	{
		RightTreadPanner.Material = Skins[RightTreadSkinNum];
		RightTreadPanner.PanDirection = TreadPannerRotation;
		RightTreadPanner.PanRate = 0;
		Skins[RightTreadSkinNum] = RightTreadPanner;
		Log("Configured right tread panner: " + RightTreadPanner);
	}
	*/
}

void AAGP_TrackedCraft::DestroyTreads()
{
	if (LeftTreadPanner != nullptr)
	{
		//Level.ObjectPool.FreeObject(LeftTreadPanner);
		LeftTreadPanner = nullptr;
	}
	if (RightTreadPanner != nullptr)
	{
		//Level.ObjectPool.FreeObject(RightTreadPanner);
		RightTreadPanner = nullptr;
	}
}

void AAGP_TrackedCraft::DrivingStatusChanged()
{
	Super::DrivingStatusChanged();
	if (!bDriving)
	{
		if (LeftTreadPanner != nullptr)
		{
			//LeftTreadPanner->PanRate = 0;
		}
		if (RightTreadPanner != nullptr)
		{
			//RightTreadPanner->PanRate = 0;
		}
	}
}

void AAGP_TrackedCraft::Tick(float DeltaTime)
{
	float EnginePitch = 0;
	float LinTurnSpeed = 0;
	FKRigidBodyState BodyState = FKRigidBodyState({});
	UKarmaParams* KP = nullptr;
	int32 i = 0;
	FRotator WheelRotation = FRotator(0,0,0);
	/*
	KGetRigidBodyState(BodyState);
	KP = KarmaParams(KParams);
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		LinTurnSpeed = 0.5 * BodyState.AngVel.Z;
		EnginePitch = 64 + VSize(Velocity) / MaxPitchSpeed * 64;
		SoundPitch =FMath::Clamp(EnginePitch, 64, 128);
		if (LeftTreadPanner != nullptr)
		{
			LeftTreadPanner.PanRate = VSize(Velocity) / TreadVelocityScale;
			if (Velocity Dot  Vector(Rotation) > 0)
			{
				LeftTreadPanner.PanRate = -1 * LeftTreadPanner.PanRate;
			}
			LeftTreadPanner.PanRate += LinTurnSpeed;
			LeftTreadWheelRoll -= LeftTreadPanner.PanRate * WheelVelocityScale * DeltaTime;
			WheelRotation.Pitch = LeftTreadWheelRoll;
			for (i = 0; i < LeftTreadWheels.Num(); i++)
			{
				SetBoneRotation(LeftTreadWheels[i], WheelRotation, 0, 1);
			}
		}
		if (RightTreadPanner != nullptr)
		{
			RightTreadPanner.PanRate = VSize(Velocity) / TreadVelocityScale;
			if (Velocity Dot  Vector(Rotation) > 0)
			{
				RightTreadPanner.PanRate = -1 * RightTreadPanner.PanRate;
			}
			RightTreadPanner.PanRate -= LinTurnSpeed;
			RightTreadWheelRoll -= RightTreadPanner.PanRate * WheelVelocityScale * DeltaTime;
			WheelRotation.Pitch = RightTreadWheelRoll;
			for (i = 0; i < RightTreadWheels.Num(); i++)
			{
				SetBoneRotation(RightTreadWheels[i], WheelRotation, 0, 1);
			}
		}
	}
	*/
	Super::Tick(DeltaTime);
}

void AAGP_TrackedCraft::KDriverEnter(APawn* p)
{
	Super::KDriverEnter(p);
	SVehicleUpdateParams();
}

void AAGP_TrackedCraft::DriverLeft()
{
	Super::DriverLeft();
	SVehicleUpdateParams();
}

void AAGP_TrackedCraft::ChangeDamageState(uint8 ZoneNum, uint8 NewStateNum)
{
	uint8 CurrentStateNum = 0;
	/*
	if (DamageZones[ZoneNum] == nullptr || DamageZones[ZoneNum].DamageStates.Num() == 0)
	{
		return;
	}
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		CurrentStateNum = DamageZones[ZoneNum].CurrentDamageState;
		if (NewStateNum > CurrentStateNum)
		{
			if (DamageZones[ZoneNum].bAttachedToRightTread)
			{
				DamageTread(true);
			}
			else
			{
				if (DamageZones[ZoneNum].bAttachedToLeftTread)
				{
					DamageTread(false);
				}
			}
		}
	}
	ChangeDamageState(ZoneNum, NewStateNum);
	*/
}
