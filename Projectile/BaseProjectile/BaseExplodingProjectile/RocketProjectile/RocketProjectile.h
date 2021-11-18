// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "RocketProjectile.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ARocketProjectile : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	ARocketProjectile(const FObjectInitializer& ObjectInitializer);


	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector RocketStart;						//var FVector RocketStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 TempRoll;								//var int TempRoll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 TempYaw;								//var int TempYaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 TempPitch;							//var int TempPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 RandRocketRoll;						//var int RandRocketRoll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 RandRocketYaw;						//var int RandRocketYaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 RandRocketPitch;						//var int RandRocketPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector InitialDir;							//var FVector InitialDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bJacked;								//var bool bJacked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float JackedDuration;						//var() float JackedDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float JackedCounter;						//var() float JackedCounter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float JackedPct;							//var() float JackedPct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float RandomMaxTime;						//var() float RandomMaxTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float RandomMinTime;						//var() float RandomMinTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 SpeedJacked;							//var() int SpeedJacked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 RandomScaleFactor;					//var() int RandomScaleFactor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bOutOfPropellant;						//var bool bOutOfPropellant;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float PropellantDuration;					//var() float PropellantDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float PropellantTimer;						//var() float PropellantTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bReachedMaxSpeed;						//var bool bReachedMaxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float AccelDuration;						//var() float AccelDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float AccelCounter;							//var() float AccelCounter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float AccelRate;							//var() float AccelRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float InitialSpeed;							//var() float InitialSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector RocketTrailOffset;					//var FVector RocketTrailOffset;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AProjAttach_RocketTrail* RocketTrail;	//var ProjAttach_RocketTrail RocketTrail;

};
