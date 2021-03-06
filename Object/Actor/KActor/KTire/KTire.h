// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/KActor/KActor.h"
#include "KTire.generated.h"

class AKCarWheelJoint;

UCLASS()
class AKTire : public AKActor
{
	GENERATED_BODY()
public:
	AKTire();

	UPROPERTY()							AKCarWheelJoint*	WheelJoint;								//var KCarWheelJoint WheelJoint;
	UPROPERTY()							float				RollFriction;							//var float RollFriction;
	UPROPERTY()							float				LateralFriction;						//var float LateralFriction;
	UPROPERTY()							float				RollSlip;								//var float RollSlip;
	UPROPERTY()							float				LateralSlip;							//var float LateralSlip;
	UPROPERTY()							float				MinSlip;								//var float MinSlip;
	UPROPERTY()							float				SlipRate;								//var float SlipRate;
	UPROPERTY()							float				Softness;								//var float Softness;
	UPROPERTY()							float				Adhesion;								//var float Adhesion;
	UPROPERTY()							float				Restitution;							//var float Restitution;
	UPROPERTY()							bool				bTireOnGround;							//var const bool bTireOnGround;
	UPROPERTY()							float				GroundSlipVel;							//var const float GroundSlipVel;
	UPROPERTY()							FVector				GroundSlipVec;							//var const Vector GroundSlipVec;
	UPROPERTY()							float				SpinSpeed;								//var const float SpinSpeed;
	UPROPERTY()							UMaterialInstance*	GroundMaterial;							//var const Material GroundMaterial;
	UPROPERTY()							FKRigidBodyState	ReceiveState;							//var Actor.KRigidBodyState ReceiveState;
	UPROPERTY()							bool				bReceiveStateNew;						//var bool bReceiveStateNew;

	bool KUpdateState(FKRigidBodyState& NewState);
	//void TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial);
};
