// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_TrackedCraft/AGP_TrackedCraft.h"

AAGP_TrackedCraft::AAGP_TrackedCraft()
{

}


bool AAGP_TrackedCraft::KUpdateState(FKRigidBodyState& NewState)
{
	/*
	if (Role == 4 || !bNewTrackedState)
	{
		Return False;
	}
	NewState = ChassisState;
	bNewTrackedState = False;
	*/
	return true;
}

void AAGP_TrackedCraft::PostBeginPlay()
{
	//Super::PostBeginPlay();
	/*
	if (Level.NetMode != 1)
	{
		SetupTreads();
	}
	*/
}

void AAGP_TrackedCraft::PostNetBeginPlay()
{
	/*
	local Object.Vector RotX;
	local Object.Vector RotY;
	local Object.Vector RotZ;
	local KarmaParams KP;
	local KRepulsor rep;
	local int i;
	GetAxes(Rotation, RotX, RotY, RotZ);
	KP = KarmaParams(KParams);
	KP.Repulsors.Length = ThrusterOffsets.Length;
	for (i = 0; i < ThrusterOffsets.Length; i++)
	{
		rep = Spawn(Class'KRepulsor', Self, , Location + ThrusterOffsets[i].X * RotX + ThrusterOffsets[i].Y * RotY + ThrusterOffsets[i].Z * RotZ);
		rep.SetBase(Self);
		rep.bHidden = true;
		KP.Repulsors[i] = rep;
	}
	*/
	Super::PostNetBeginPlay();
}

void AAGP_TrackedCraft::Destroyed()
{
	/*
	local KarmaParams KP;
	local int i;
	DestroyTreads();
	KP = KarmaParams(KParams);
	for (i = 0; i < KP.Repulsors.Length; i++)
	{
		KP.Repulsors[i].Destroy();
	}
	*/
	Super::Destroyed();
}

void AAGP_TrackedCraft::SVehicleUpdateParams()
{
	/*
	local KarmaParams KP;
	local int i;
	SVehicleUpdateParams();
	KP = KarmaParams(KParams);
	for (i = 0; i < KP.Repulsors.Length; i++)
	{
		KP.Repulsors[i].Softness = HoverSoftness;
		KP.Repulsors[i].PenScale = HoverPenScale;
		KP.Repulsors[i].CheckDist = HoverCheckDist;
	}
	KSetStayUprightParams(UprightStiffness, UprightDamping);
	*/
}

void AAGP_TrackedCraft::DamageTread(bool bRightTread)
{
	/*
	if (bRightTread)
	{
		SetBoneScale(0, 1, LeftTreadDamageBone);
		SetBoneScale(0, 0, LeftTreadBone);
	}
	else
	{
		SetBoneScale(0, 1, RightTreadDamageBone);
		SetBoneScale(0, 0, RightTreadBone);
	}
	*/
}

void AAGP_TrackedCraft::SetupTreads()
{
	/*
	SetBoneScale(0, 0, LeftTreadDamageBone);
	SetBoneScale(0, 0, RightTreadDamageBone);
	LeftTreadPanner = VariableTexPanner(Level.ObjectPool.AllocateObject(Class'VariableTexPanner'));
	if (LeftTreadPanner != None)
	{
		LeftTreadPanner.Material = Skins[LeftTreadSkinNum];
		LeftTreadPanner.PanDirection = TreadPannerRotation;
		LeftTreadPanner.PanRate = 0;
		Skins[LeftTreadSkinNum] = LeftTreadPanner;
		Log("Configured left tread panner: " $ LeftTreadPanner);
	}
	RightTreadPanner = VariableTexPanner(Level.ObjectPool.AllocateObject(Class'VariableTexPanner'));
	if (RightTreadPanner != None)
	{
		RightTreadPanner.Material = Skins[RightTreadSkinNum];
		RightTreadPanner.PanDirection = TreadPannerRotation;
		RightTreadPanner.PanRate = 0;
		Skins[RightTreadSkinNum] = RightTreadPanner;
		Log("Configured right tread panner: " $ RightTreadPanner);
	}
	*/
}

void AAGP_TrackedCraft::DestroyTreads()
{
	/*
	if (LeftTreadPanner != None)
	{
		Level.ObjectPool.FreeObject(LeftTreadPanner);
		LeftTreadPanner = None;
	}
	if (RightTreadPanner != None)
	{
		Level.ObjectPool.FreeObject(RightTreadPanner);
		RightTreadPanner = None;
	}
	*/
}

void AAGP_TrackedCraft::DrivingStatusChanged()
{
	/*
	DrivingStatusChanged();
	if (!bDriving)
	{
		if (LeftTreadPanner != None)
		{
			LeftTreadPanner.PanRate = 0;
		}
		if (RightTreadPanner != None)
		{
			RightTreadPanner.PanRate = 0;
		}
	}
	*/
}

void AAGP_TrackedCraft::Tick(float DeltaTime)
{
	/*
	local float EnginePitch;
	local float LinTurnSpeed;
	local Actor.KRigidBodyState BodyState;
	local KarmaParams KP;
	local int i;
	local Object.Rotator WheelRotation;
	KGetRigidBodyState(BodyState);
	KP = KarmaParams(KParams);
	if (Level.NetMode != 1)
	{
		LinTurnSpeed = 0.5 * BodyState.AngVel.Z;
		EnginePitch = 64 + VSize(Velocity) / MaxPitchSpeed * 64;
		SoundPitch = FClamp(EnginePitch, 64, 128);
		if (LeftTreadPanner != None)
		{
			LeftTreadPanner.PanRate = VSize(Velocity) / TreadVelocityScale;
			if (Velocity Dot  Vector(Rotation) > 0)
			{
				LeftTreadPanner.PanRate = -1 * LeftTreadPanner.PanRate;
			}
			LeftTreadPanner.PanRate += LinTurnSpeed;
			LeftTreadWheelRoll -= LeftTreadPanner.PanRate * WheelVelocityScale * DeltaTime;
			WheelRotation.Pitch = LeftTreadWheelRoll;
			for (i = 0; i < LeftTreadWheels.Length; i++)
			{
				SetBoneRotation(LeftTreadWheels[i], WheelRotation, 0, 1);
			}
		}
		if (RightTreadPanner != None)
		{
			RightTreadPanner.PanRate = VSize(Velocity) / TreadVelocityScale;
			if (Velocity Dot  Vector(Rotation) > 0)
			{
				RightTreadPanner.PanRate = -1 * RightTreadPanner.PanRate;
			}
			RightTreadPanner.PanRate -= LinTurnSpeed;
			RightTreadWheelRoll -= RightTreadPanner.PanRate * WheelVelocityScale * DeltaTime;
			WheelRotation.Pitch = RightTreadWheelRoll;
			for (i = 0; i < RightTreadWheels.Length; i++)
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
	//KDriverEnter(p);
	//SVehicleUpdateParams();
}

void AAGP_TrackedCraft::DriverLeft()
{
	//DriverLeft();
	//SVehicleUpdateParams();
}

void AAGP_TrackedCraft::ChangeDamageState(uint8 ZoneNum, uint8 NewStateNum)
{
	/*
	local byte CurrentStateNum;
	if (DamageZones[ZoneNum] == None || DamageZones[ZoneNum].DamageStates.Length == 0)
	{
		Return;
	}
	if (Level.NetMode != 1)
	{
		CurrentStateNum = DamageZones[ZoneNum].CurrentDamageState;
		if (NewStateNum > CurrentStateNum)
		{
			if (DamageZones[ZoneNum].bAttachedToRightTread)
			{
				DamageTread(True);
			}
			else
			{
				if (DamageZones[ZoneNum].bAttachedToLeftTread)
				{
					DamageTread(False);
				}
			}
		}
	}
	ChangeDamageState(ZoneNum, NewStateNum);
	*/
}