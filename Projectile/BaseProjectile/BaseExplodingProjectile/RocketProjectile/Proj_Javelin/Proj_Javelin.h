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

	UPROPERTY()		float CurrentHeight;				//var float CurrentHeight;
	UPROPERTY()		float FallDist;						//var float FallDist;
	UPROPERTY()		float NewHeight;					//var float NewHeight;
	UPROPERTY()		FObjectRange LongArmingTimeRange;	//var Object.Range LongArmingTimeRange;
	UPROPERTY()		int32 HeightDirSteep;				//var int HeightDirSteep;
	UPROPERTY()		int32 HeightTopSteep;				//var int HeightTopSteep;
	UPROPERTY()		int32 MinHeightDir;					//var int MinHeightDir;
	UPROPERTY()		int32 MinHeightTop;					//var int MinHeightTop;
	UPROPERTY()		int32 MaxHeightDir;					//var int MaxHeightDir;
	UPROPERTY()		int32 MaxHeightTop;					//var int MaxHeightTop;
	UPROPERTY()		FVector TargetLoc;					//var FVector TargetLoc;
	UPROPERTY()		FVector StartLocation;				//var FVector StartLocation;
	UPROPERTY()		float TargetRange;					//var float TargetRange;
	UPROPERTY()		float VelMag;						//var float VelMag;
	UPROPERTY()		float MaxHeight;					//var float MaxHeight;
	UPROPERTY()		float TargetDist;					//var float TargetDist;
	//UPROPERTY()		AJav_Target* Gun_J_Target;		//var Jav_Target Gun_J_Target;
	//UPROPERTY()		AJav_Target* J_Target;			//var Jav_Target J_Target;
	UPROPERTY()		AActor* SeekTarget;					//var Actor SeekTarget;
	UPROPERTY()		AActor* HomingTarget;				//var Actor HomingTarget;
	UPROPERTY()		bool bDirectFire;					//var bool bDirectFire;
	UPROPERTY()		bool bHasCollided;					//var bool bHasCollided;
	UPROPERTY()		AEmitter* ePuff;					//var Emitter ePuff;
	UPROPERTY()		AEmitter* cJavPuff;					//var class<Emitter> cJavPuff;
	UPROPERTY()		AWEAPON_Javelin* mygun;				//var WEAPON_Javelin mygun;
};
