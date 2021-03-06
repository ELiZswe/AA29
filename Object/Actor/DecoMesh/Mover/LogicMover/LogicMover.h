// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "LogicMover.generated.h"

UCLASS()
class ALogicMover : public AMover
{
	GENERATED_BODY()
public:
	ALogicMover();

	UPROPERTY(EditAnywhere)										int32 GroupNumber;							//var() int GroupNumber;

	//void TakeDamage(int32 Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, class<DamageType>  DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
};
