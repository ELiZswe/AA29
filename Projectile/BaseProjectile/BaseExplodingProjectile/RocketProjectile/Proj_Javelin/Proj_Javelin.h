// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/RocketProjectile.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "Proj_Javelin.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AProj_Javelin : public ARocketProjectile
{
	GENERATED_BODY()
public:
	AProj_Javelin(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float CurrentHeight;				//var float CurrentHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float FallDist;						//var float FallDist;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float NewHeight;					//var float NewHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FObjectRange LongArmingTimeRange;	//var Object.Range LongArmingTimeRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 HeightDirSteep;				//var int HeightDirSteep;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 HeightTopSteep;				//var int HeightTopSteep;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 MinHeightDir;					//var int MinHeightDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 MinHeightTop;					//var int MinHeightTop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 MaxHeightDir;					//var int MaxHeightDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 MaxHeightTop;					//var int MaxHeightTop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector TargetLoc;					//var FVector TargetLoc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector StartLocation;				//var FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float TargetRange;					//var float TargetRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float VelMag;						//var float VelMag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float MaxHeight;					//var float MaxHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float TargetDist;					//var float TargetDist;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AJav_Target* Gun_J_Target;		//var Jav_Target Gun_J_Target;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AJav_Target* J_Target;			//var Jav_Target J_Target;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AActor* SeekTarget;					//var Actor SeekTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AActor* HomingTarget;				//var Actor HomingTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bDirectFire;					//var bool bDirectFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bHasCollided;					//var bool bHasCollided;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEmitter* ePuff;				//var Emitter ePuff;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEmitter* cJavPuff;				//var class<Emitter> cJavPuff;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AWEAPON_Javelin* mygun;				//var WEAPON_Javelin mygun;
};
