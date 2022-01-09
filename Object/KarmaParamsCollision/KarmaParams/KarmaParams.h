// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParamsCollision.h"
#include "KarmaParams.generated.h"

class AKRepulsor;

UCLASS()
class UKarmaParams : public UKarmaParamsCollision
{
	GENERATED_BODY()
public:
	UKarmaParams();

	UPROPERTY()								Fpointer KAng3;									//var const transient Fpointer KAng3;
	UPROPERTY()								Fpointer KTriList;								//var const transient Fpointer KTriList;
	UPROPERTY()								float KLastVel;									//var const transient float KLastVel;
	UPROPERTY(EditAnywhere)					float KMass;									//var() float KMass;
	UPROPERTY(EditAnywhere)					float KLinearDamping;							//var() float KLinearDamping;
	UPROPERTY(EditAnywhere)					float KAngularDamping;							//var() float KAngularDamping;
	UPROPERTY(EditAnywhere)					float KBuoyancy;								//var() float KBuoyancy;
	UPROPERTY(EditAnywhere)					bool KStartEnabled;								//var() bool KStartEnabled;
	UPROPERTY(EditAnywhere)					FVector KStartLinVel;							//var() Vector KStartLinVel;
	UPROPERTY(EditAnywhere)					FVector KStartAngVel;							//var() Vector KStartAngVel;
	UPROPERTY(EditAnywhere)					bool bKNonSphericalInertia;						//var() bool bKNonSphericalInertia;
	UPROPERTY(EditAnywhere)					float KActorGravScale;							//var() float KActorGravScale;
	UPROPERTY(EditAnywhere)					float KVelDropBelowThreshold;					//var() float KVelDropBelowThreshold;
	UPROPERTY(EditAnywhere)					float KMaxSpeed;								//var() float KMaxSpeed;
	UPROPERTY(EditAnywhere)					float KMaxAngularSpeed;							//var() float KMaxAngularSpeed;
	UPROPERTY(EditAnywhere)					bool bHighDetailOnly;							//var() bool bHighDetailOnly;
	UPROPERTY()								bool bClientOnly;								//var bool bClientOnly;
	UPROPERTY(EditAnywhere)					bool bKDoubleTickRate;							//var() const bool bKDoubleTickRate;
	UPROPERTY(EditAnywhere)					bool bKStayUpright;								//var() bool bKStayUpright;
	UPROPERTY(EditAnywhere)					bool bKAllowRotate;								//var() bool bKAllowRotate;
	UPROPERTY()								bool bDestroyOnSimError;						//var bool bDestroyOnSimError;
	UPROPERTY(EditAnywhere)					bool bDestroyOnWorldPenetrate;					//var() bool bDestroyOnWorldPenetrate;
	UPROPERTY(EditAnywhere)					bool bDoSafetime;								//var() bool bDoSafetime;
	UPROPERTY(EditAnywhere)					float StayUprightStiffness;						//var() float StayUprightStiffness;
	UPROPERTY(EditAnywhere)					float StayUprightDamping;						//var() float StayUprightDamping;
	UPROPERTY(EditAnywhere)					TArray<AKRepulsor*> Repulsors;					//var() TArray<KRepulsor> Repulsors;
};
