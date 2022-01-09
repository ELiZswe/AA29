// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SupportEffect.generated.h"

class AProjectile;

UCLASS()
class ASupportEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ASupportEffect();

	UPROPERTY()							FVector			HitLocation;					//var Vector HitLocation;
	UPROPERTY()							FVector			HitNormal;					//var Vector HitNormal;
	UPROPERTY()							float			StartTime;					//var float StartTime;
	UPROPERTY(EditAnywhere)				float			DropTime;					//var() float DropTime;
	UPROPERTY()							AProjectile*	StrikeProjectileClass;					//var class<Projectile> StrikeProjectileClass;
	UPROPERTY()							AProjectile*	StrikeProjectile;					//var Projectile StrikeProjectile;
	/*
	replication
	{
		reliable if ((bNetInitial && (Role == ROLE_Authority)))
			HitLocation, HitNormal;
	}
	*/

	void AimAt(FVector hl, FVector hn);
	void PostNetBeginPlay();
	void SpawnEffects();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
