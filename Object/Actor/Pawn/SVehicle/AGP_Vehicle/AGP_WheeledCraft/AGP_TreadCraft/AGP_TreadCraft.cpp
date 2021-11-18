// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/AGP_TreadCraft.h"

AAGP_TreadCraft::AAGP_TreadCraft()
{
	SteerThrottleScale = 1;
}


void AAGP_TreadCraft::DisplayVehicleDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	/*
	DisplayVehicleDebug(Canvas, YL, YPos);
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("bTurnThrottle: " $ bTurnThrottle);
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
	/*
	local name BoneName;
	local string BoneVariable;
	local int32 i;
	BoneVariable = "LeftTreadBone";
	BoneName = LeftTreadBone;
	if (LeftTreadBone != 'None' && LeftTreadBone != 'None')
	{
		bFoundBadBones = LogBadBoneNames(Self, LeftTreadBone, bFoundBadBones, BoneVariable);
	}
	BoneVariable = "LeftTreadDamageBone";
	BoneName = LeftTreadDamageBone;
	if (BoneName != 'None' && BoneName != 'None')
	{
		bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
	}
	BoneVariable = "RightTreadBone";
	BoneName = RightTreadBone;
	if (BoneName != 'None' && BoneName != 'None')
	{
		bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
	}
	BoneVariable = "RightTreadDamageBone";
	BoneName = RightTreadDamageBone;
	if (BoneName != 'None' && BoneName != 'None')
	{
		bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
	}
	for (i = 0; i < LeftTreadWheels.Length; i++)
	{
		BoneVariable = "LeftTreadWheels[" $ i $ "]";
		BoneName = LeftTreadWheels[i];
		if (BoneName != 'None' && BoneName != 'None')
		{
			bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
		}
	}
	for (i = 0; i < RightTreadWheels.Length; i++)
	{
		BoneVariable = "RightTreadWheels[" $ i $ "]";
		BoneName = RightTreadWheels[i];
		if (BoneName != 'None' && BoneName != 'None')
		{
			bFoundBadBones = LogBadBoneNames(Self, BoneName, bFoundBadBones, BoneVariable);
		}
	}
	Return VerifyVehicleSystemBones(bFoundBadBones);
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
	/*
	local int32 helpme;
	helpme = GetNextScalerSlot();
	DebugLog(DEBUG_Vehicle, "SetupTreads called with " $ helpme);
	SetBoneScale(GetNextScalerSlot(), 0, LeftTreadDamageBone);
	DebugLog(DEBUG_Vehicle, "and then " $ GetNextScalerSlot());
	SetBoneScale(GetNextScalerSlot(), 0, RightTreadDamageBone);
	LeftTreadPanner = VariableTexPanner(Level.ObjectPool.AllocateObject(Class'VariableTexPanner'));
	if (LeftTreadPanner != None)
	{
		LeftTreadPanner.Material = Skins[LeftTreadSkinNum];
		LeftTreadPanner.PanDirection = TreadPannerRotation;
		LeftTreadPanner.PanRate = 0;
		Skins[LeftTreadSkinNum] = LeftTreadPanner;
	}
	RightTreadPanner = VariableTexPanner(Level.ObjectPool.AllocateObject(Class'VariableTexPanner'));
	if (RightTreadPanner != None)
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

void AAGP_TreadCraft::DrivingStatusChanged()
{
	/*
	Super::DrivingStatusChanged();
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

void AAGP_TreadCraft::Tick(float DeltaTime)
{
	/*
	local float LinTurnSpeed;
	local Actor.KRigidBodyState BodyState;
	local int32 i;
	local Object.Rotator WheelRotation;
	if (Level.NetMode != 1)
	{
		KGetRigidBodyState(BodyState);
		LinTurnSpeed = 0.5 * BodyState.AngVel.Z;
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

void AAGP_TreadCraft::ChangeDamageState(uint8 ZoneNum, uint8 NewStateNum)
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
	Super::ChangeDamageState(ZoneNum, NewStateNum);
	*/
}