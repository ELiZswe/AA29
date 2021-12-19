// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "RocketProjectile.generated.h"

class AProjAttach_RocketTrail;

UCLASS()
class AA29_API ARocketProjectile : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	ARocketProjectile(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY()										FVector						RocketStart;				//var FVector RocketStart;
	UPROPERTY()										int32						TempRoll;					//var int TempRoll;
	UPROPERTY()										int32						TempYaw;					//var int TempYaw;
	UPROPERTY()										int32						TempPitch;					//var int TempPitch;
	UPROPERTY()										int32						RandRocketRoll;				//var int RandRocketRoll;
	UPROPERTY()										int32						RandRocketYaw;				//var int RandRocketYaw;
	UPROPERTY()										int32						RandRocketPitch;			//var int RandRocketPitch;
	UPROPERTY()										FVector						InitialDir;					//var FVector InitialDir;
	UPROPERTY()										bool						bJacked;					//var bool bJacked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float						JackedDuration;				//var() float JackedDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float						JackedCounter;				//var() float JackedCounter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float						JackedPct;					//var() float JackedPct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float						RandomMaxTime;				//var() float RandomMaxTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float						RandomMinTime;				//var() float RandomMinTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32						SpeedJacked;				//var() int SpeedJacked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32						RandomScaleFactor;			//var() int RandomScaleFactor;
	UPROPERTY()										bool						bOutOfPropellant;			//var bool bOutOfPropellant;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float						PropellantDuration;			//var() float PropellantDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float						PropellantTimer;			//var() float PropellantTimer;
	UPROPERTY()										bool						bReachedMaxSpeed;			//var bool bReachedMaxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float						AccelDuration;				//var() float AccelDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float						AccelCounter;				//var() float AccelCounter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float						AccelRate;					//var() float AccelRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float						InitialSpeed;				//var() float InitialSpeed;
	UPROPERTY()										FVector						RocketTrailOffset;			//var FVector RocketTrailOffset;
	UPROPERTY()										AProjAttach_RocketTrail*	RocketTrail;				//var ProjAttach_RocketTrail RocketTrail;

	void BeginPlay();
	int32 RandSigned(int32 i);
	void Timer();
	bool ShouldExplode();
	void StopTrail();
	void Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type);
	void Destroyed();
};
