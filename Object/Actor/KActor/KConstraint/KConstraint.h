// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/KActor/KActor.h"
#include "KConstraint.generated.h"

UCLASS()
class AKConstraint : public AKActor
{
	GENERATED_BODY()
public:
	AKConstraint();

	UPROPERTY()													Fpointer			KConstraintData;			//var const transient Fpointer KConstraintData;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		AActor*				KConstraintActor1;			//var(KarmaConstraint) edfindable Actor KConstraintActor1;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		AActor*				KConstraintActor2;			//var(KarmaConstraint) edfindable Actor KConstraintActor2;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		FName				KConstraintBone1;			//var(KarmaConstraint) FName KConstraintBone1;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		FName				KConstraintBone2;			//var(KarmaConstraint) FName KConstraintBone2;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		bool				bKDisableCollision;			//var(KarmaConstraint) const bool bKDisableCollision;
	UPROPERTY()													FVector				KPos1;						//var Vector KPos1;
	UPROPERTY()													FVector				KPriAxis1;					//var Vector KPriAxis1;
	UPROPERTY()													FVector				KSecAxis1;					//var Vector KSecAxis1;
	UPROPERTY()													FVector				KPos2;						//var Vector KPos2;
	UPROPERTY()													FVector				KPriAxis2;					//var Vector KPriAxis2;
	UPROPERTY()													FVector				KSecAxis2;					//var Vector KSecAxis2;
	UPROPERTY()													bool				bKForceFrameUpdate;			//var const bool bKForceFrameUpdate;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float				KForceThreshold;			//var(KarmaConstraint) float KForceThreshold;

	void KUpdateConstraintParams();
	void KGetConstraintForce(FVector& Force);
	void KGetConstraintTorque(FVector& Torque);
	void KForceExceed(float forceMag);
};
