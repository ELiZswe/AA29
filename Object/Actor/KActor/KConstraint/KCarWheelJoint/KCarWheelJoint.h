// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/KActor/KConstraint/KConstraint.h"
#include "KCarWheelJoint.generated.h"

UCLASS()
class AKCarWheelJoint : public AKConstraint
{
	GENERATED_BODY()
public:
	AKCarWheelJoint();

	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KSteerAngle;					//var(KarmaConstraint) float KSteerAngle;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KProportionalGap;				//var(KarmaConstraint) float KProportionalGap;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KMaxSteerTorque;				//var(KarmaConstraint) float KMaxSteerTorque;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KMaxSteerSpeed;				//var(KarmaConstraint) float KMaxSteerSpeed;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		bool bKSteeringLocked;				//var(KarmaConstraint) bool bKSteeringLocked;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KMotorTorque;					//var(KarmaConstraint) float KMotorTorque;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KMaxSpeed;					//var(KarmaConstraint) float KMaxSpeed;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KBraking;						//var(KarmaConstraint) float KBraking;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KSuspLowLimit;				//var(KarmaConstraint) float KSuspLowLimit;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KSuspHighLimit;				//var(KarmaConstraint) float KSuspHighLimit;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KSuspStiffness;				//var(KarmaConstraint) float KSuspStiffness;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KSuspDamping;					//var(KarmaConstraint) float KSuspDamping;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KSuspRef;						//var(KarmaConstraint) float KSuspRef;
	UPROPERTY()													float KWheelHeight;					//var const float KWheelHeight;
};
