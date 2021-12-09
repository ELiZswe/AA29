// All the original content belonged to the US Army


#include "AA29/Object/Actor/KActor/KTire/KTire.h"

AKTire::AKTire()
{
	RollFriction = 0.3;
	LateralFriction = 0.3;
	RollSlip = 0.085;
	LateralSlip = 0.06;
	MinSlip = 0.001;
	SlipRate = 0.0005;
	Softness = 0.0002;
	Restitution = 0.1;
	//bNoDelete = false;
	bDisturbFluidSurface = true;
}

bool AKTire::KUpdateState(FKRigidBodyState& NewState)
{
	if (!bReceiveStateNew)
	{
		return false;
	}
	NewState = ReceiveState;
	bReceiveStateNew = false;
	return true;
}
/*
void AKTire::TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, Actor.BoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
}
*/
