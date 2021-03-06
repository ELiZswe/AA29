// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/KActor/KConstraint/KConstraint.h"
#include "KHinge.generated.h"

UCLASS()
class AKHinge : public AKConstraint
{
	GENERATED_BODY()
public:
	AKHinge();

	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		EHingeType KHingeType;			//var(KarmaConstraint) Enum EHingeType KHingeType;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KStiffness;				//var(KarmaConstraint) float KStiffness;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KDamping;					//var(KarmaConstraint) float KDamping;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KDesiredAngVel;			//var(KarmaConstraint) float KDesiredAngVel;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KMaxTorque;				//var(KarmaConstraint) float KMaxTorque;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KDesiredAngle;			//var(KarmaConstraint) float KDesiredAngle;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KProportionalGap;			//var(KarmaConstraint) float KProportionalGap;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KAltDesiredAngle;			//var(KarmaConstraint) float KAltDesiredAngle;
	UPROPERTY()													bool KUseAltDesired;			//var bool KUseAltDesired;
	UPROPERTY()													float KCurrentAngle;			//var const float KCurrentAngle;
};
