// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BallisticProjectile/BallisticProjectile.h"

ABallisticProjectile::ABallisticProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

/*
replication
{
	reliable if (((Role == ROLE_Authority) && bNetOwner))
		StartPos, StartVel, Azimuth, Elevation;
}
*/

void ABallisticProjectile::Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
{
	FinishedBallistics = true;
	Super::Collision(HitActor, HitLocation, HitNormal, HitMaterial, Type);
}
