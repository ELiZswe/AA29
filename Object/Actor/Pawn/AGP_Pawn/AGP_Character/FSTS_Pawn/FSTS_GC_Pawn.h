// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_Pawn.h"
#include "FSTS_GC_Pawn.generated.h"

UCLASS()
class AA29_API AFSTS_GC_Pawn : public AFSTS_Pawn
{
	GENERATED_BODY()
public:
	AFSTS_GC_Pawn();

	//void TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, Actor.BoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
};
