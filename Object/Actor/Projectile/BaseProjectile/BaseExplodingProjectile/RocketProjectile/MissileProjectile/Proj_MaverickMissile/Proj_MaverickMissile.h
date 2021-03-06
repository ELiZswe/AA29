// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/MissileProjectile/MissileProjectile.h"
#include "Proj_MaverickMissile.generated.h"

UCLASS()
class AProj_MaverickMissile : public AMissileProjectile
{
	GENERATED_BODY()
public:
	AProj_MaverickMissile(const FObjectInitializer& ObjectInitializer);
	
};
