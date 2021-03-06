// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "Proj_FlareGren.generated.h"

UCLASS()
class AProj_FlareGren : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	AProj_FlareGren(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY()		bool bFlareOn;		//var bool bFlareOn;

	void Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type);
	void BeginPlay();
	void Timer();
	void SpawnFlare();
};
