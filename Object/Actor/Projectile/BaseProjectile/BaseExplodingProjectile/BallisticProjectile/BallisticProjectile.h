// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "BallisticProjectile.generated.h"

UCLASS()
class ABallisticProjectile : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	ABallisticProjectile(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()		int32		NumGFunct;			//var int32 NumGFunct;
	UPROPERTY()		FVector		StartPos;			//var Vector StartPos;
	UPROPERTY()		FVector		StartVel;			//var Vector StartVel;
	UPROPERTY()		FVector		Gravity;			//var Vector Gravity;
	UPROPERTY()		int32		Azimuth;			//var int32 Azimuth;
	UPROPERTY()		int32		Roll;				//var int32 Roll;
	UPROPERTY()		float		Elevation;			//var float Elevation;
	UPROPERTY()		bool		IsInitialized;		//var bool IsInitialized;
	UPROPERTY()		bool		FinishedBallistics;	//var bool FinishedBallistics;
	UPROPERTY()		int32		GParams;			//var int32 GParams;
	UPROPERTY()		int32		GFunction;			//var int32 GFunction;
	UPROPERTY()		int32		PVars;				//var int32 PVars;

	void Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type);
};
