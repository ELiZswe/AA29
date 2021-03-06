// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/KActor/KConstraint/KConstraint.h"
#include "KConeLimit.generated.h"

UCLASS()
class AKConeLimit : public AKConstraint
{
	GENERATED_BODY()
public:
	AKConeLimit();

	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KHalfAngle;			//var(KarmaConstraint) float KHalfAngle;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KStiffness;			//var(KarmaConstraint) float KStiffness;
	UPROPERTY(EditAnywhere, Category = "KarmaConstraint")		float KDamping;				//var(KarmaConstraint) float KDamping;
};
