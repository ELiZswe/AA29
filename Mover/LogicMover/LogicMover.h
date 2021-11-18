// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Mover/Mover.h"
#include "LogicMover.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ALogicMover : public AMover
{
	GENERATED_BODY()
public:
	ALogicMover();

	UPROPERTY(EditAnywhere)										int32 GroupNumber;							//var() int GroupNumber;

	//void TakeDamage(int Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
};
