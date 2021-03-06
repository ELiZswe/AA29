// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/AGP_TreadCraft.h"

AAGP_TreadCraft::AAGP_TreadCraft()
{
	SteerThrottleScale = 1;
}

void AAGP_TreadCraft::DisplayVehicleDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	/*
	DisplayVehicleDebug(Canvas, YL, YPos);
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("bTurnThrottle: " + bTurnThrottle);
	YPos += YL;
	*/
}

void AAGP_TreadCraft::PostBeginPlay()
{
	//Super::PostBeginPlay();
}

void AAGP_TreadCraft::InitializeDamageZones()
{
	Super::InitializeDamageZones();
	SetupTreads();
}

void AAGP_TreadCraft::Destroyed()
{
	DestroyTreads();
	Super::Destroyed();
}

void AAGP_TreadCraft::rightside(float Size)
{
	//SetBoneScale(0, Size, RightTreadDamageBone);
}

void AAGP_TreadCraft::leftside(float Size)
{
	//SetBoneScale(0, Size, LeftTreadDamageBone);
}

bool AAGP_TreadCraft::VerifyVehicleSystemBones(bool bFoundBadBones)
{
	FName BoneName = "";
	FString BoneVariable = "";
	int32 i = 0;
	/*
	BoneVariable = "LeftTreadBone";
	BoneName = LeftTreadBone;
	if (LeftTreadBone != "None" && LeftTreadBone != "None")
	{
		bFoundBadBones = LogBadBoneNames(this, LeftTreadBone, bFoundBadBones, BoneVariable);
	}
	BoneVariable = "LeftTreadDamageBone";
	BoneName = LeftTreadDamageBone;
	if (BoneName != "None" && BoneName != "None")
	{
		bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
	}
	BoneVariable = "RightTreadBone";
	BoneName = RightTreadBone;
	if (BoneName != "None" && BoneName != "None")
	{
		bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
	}
	BoneVariable = "RightTreadDamageBone";
	BoneName = RightTreadDamageBone;
	if (BoneName != "None" && BoneName != "None")
	{
		bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
	}
	for (i = 0; i < LeftTreadWheels.Num(); i++)
	{
		BoneVariable = "LeftTreadWheels[" + i + "]";
		BoneName = LeftTreadWheels[i];
		if (BoneName != "None" && BoneName != "None")
		{
			bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
		}
	}
	for (i = 0; i < RightTreadWheels.Num(); i++)
	{
		BoneVariable = "RightTreadWheels[" + i + "]";
		BoneName = RightTreadWheels[i];
		if (BoneName != "None" && BoneName != "None")
		{
			bFoundBadBones = LogBadBoneNames(this, BoneName, bFoundBadBones, BoneVariable);
		}
	}
	return VerifyVehicleSystemBones(bFoundBadBones);
	*/
	return false;   //FAKE  /ELiZ
}

void AAGP_TreadCraft::DamageTread(bool bRightTread)
{
	/*
	DebugLog(DEBUG_Vehicle, "DamageTread called");
	if (!bRightTread)
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

void AAGP_TreadCraft::SetupTreads()
{
	int32 helpme = 0;
	/*
	helpme = GetNextScalerSlot();
	DebugLog(DEBUG_Vehicle, "SetupTreads called with " + helpme);
	SetBoneScale(GetNextScalerSlot(), 0, LeftTreadDamageBone);
	DebugLog(DEBUG_Vehicle, "and then " + GetNextScalerSlot());
	SetBoneScale(GetNextScalerSlot(), 0, RightTreadDamageBone);
	LeftTreadPanner = VariableTexPanner(Level.ObjectPool.AllocateObject(Class'VariableTexPanner'));
	if (LeftTreadPanner != nullptr)
	{
		LeftTreadPanner.Material = Skins[LeftTreadSkinNum];
		LeftTreadPanner.PanDirection = TreadPannerRotation;
		LeftTreadPanner.PanRate = 0;
		Skins[LeftTreadSkinNum] = LeftTreadPanner;
	}
	RightTreadPanner = VariableTexPanner(Level.ObjectPool.AllocateObject(Class'VariableTexPanner'));
	if (RightTreadPanner != nullptr)
	{
		RightTreadPanner.Material = Skins[RightTreadSkinNum];
		RightTreadPanner.PanDirection = TreadPannerRotation;
		RightTreadPanner.PanRate = 0;
		Skins[RightTreadSkinNum] = RightTreadPanner;
	}
	*/
}

void AAGP_TreadCraft::DestroyTreads()
{
	/*
	if (LeftTreadPanner != nullptr)
	{
		Level.ObjectPool.FreeObject(LeftTreadPanner);
		LeftTreadPanner = nullptr;
	}
	if (RightTreadPanner != nullptr)
	{
		Level.ObjectPool.FreeObject(RightTreadPanner);
		RightTreadPanner = nullptr;
	}
	*/
}

void AAGP_TreadCraft::DrivingStatusChanged()
{
	/*
	Super::DrivingStatusChanged();
	if (!bDriving)
	{
		if (LeftTreadPanner != nullptr)
		{
			LeftTreadPanner.PanRate = 0;
		}
		if (RightTreadPanner != nullptr)
		{
			RightTreadPanner.PanRate = 0;
		}
	}
	*/
}

void AAGP_TreadCraft::Tick(float DeltaTime)
{
	float LinTurnSpeed = 0;
	int32 i = 0;
	FRotator WheelRotation = FRotator(0,0,0);
	/*
	FKRigidBodyState BodyState = FKRigidBodyState::AngVel;
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		KGetRigidBodyState(BodyState);
		LinTurnSpeed = 0.5 * BodyState.AngVel.Z;
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

void AAGP_TreadCraft::ChangeDamageState(uint8 ZoneNum, uint8 NewStateNum)
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
	Super::ChangeDamageState(ZoneNum, NewStateNum);
	*/
}
