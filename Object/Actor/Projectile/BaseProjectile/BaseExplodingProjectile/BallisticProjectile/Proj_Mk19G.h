// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BallisticProjectile/BallisticProjectile.h"
#include "Proj_Mk19G.generated.h"

UCLASS()
class AProj_Mk19G : public ABallisticProjectile
{
	GENERATED_BODY()
public:
	AProj_Mk19G(const FObjectInitializer& ObjectInitializer);

	void Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type);
	void Boom(FVector HitLocation, FVector HitNormal);
	void Tick(float DeltaTime);
};
