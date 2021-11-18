// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "BallisticProjectile.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABallisticProjectile : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	ABallisticProjectile(const FObjectInitializer& ObjectInitializer);

	//var int PVars;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 PVars;

	//var int GFunction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 GFunction;

	//var int GParams;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 GParams;

	//var bool FinishedBallistics;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool FinishedBallistics;

	//var bool IsInitialized;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool IsInitialized;

	//var float Elevation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float Elevation;

	//var int Roll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 Roll;

	//var int Azimuth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 Azimuth;

	//var FVector Gravity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector Gravity;

	//var FVector StartVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector StartVel;

	//var FVector StartPos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector StartPos;

	//var int NumGFunct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 NumGFunct;

};
