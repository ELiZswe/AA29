// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/CallForSupport/FireSupport/AirStrike/AirStrike.h"
#include "AA29/AA29.h"
#include "F18AirStrike.generated.h"

class ASupportEffect;
class UaDamageType;

UCLASS()
class AF18AirStrike : public AAirStrike
{
	GENERATED_BODY()
public:
	AF18AirStrike();

	UPROPERTY()						USoundBase*			GlobalSound;				//var Sound GlobalSound;
	UPROPERTY()						USoundBase*			FireSound;					//var() Sound FireSound;
	UPROPERTY()						FVector				MarkLocation;				//var() Vector MarkLocation;
	UPROPERTY()						ASupportEffect*		SupportEffectClass;			//var() class<SupportEffect> SupportEffectClass;
	UPROPERTY()						int32				Damage;						//var() int32 Damage;
	UPROPERTY()						float				MomentumTransfer;			//var() float MomentumTransfer;
	UPROPERTY()						float				DamageRadius;				//var() float DamageRadius;
	UPROPERTY()						float				KillRadius;					//var() float KillRadius;
	UPROPERTY()						FString				DamageTypeClassName;		//var() FString DamageTypeClassName;
	UPROPERTY()						UaDamageType*		DamageType;					//var() class<DamageType> DamageType;
	UPROPERTY()						FVector				StrikeDirection;			//var Vector StrikeDirection;
	UPROPERTY()						FVector				DamageLocation;				//var Vector DamageLocation;
	UPROPERTY()						FBoneInfo			DamageBone;					//var FBoneInfo DamageBone;
	UPROPERTY()						UMaterialInstance*	DamageMaterial;				//var Material DamageMaterial;
	UPROPERTY()						FVector				ShakeRotMag;				//var() Vector ShakeRotMag;
	UPROPERTY()						FVector				ShakeRotRate;				//var() Vector ShakeRotRate;
	UPROPERTY()						float				ShakeRotTime;				//var() float ShakeRotTime;
	UPROPERTY()						FVector				ShakeOffsetMag;				//var() Vector ShakeOffsetMag;
	UPROPERTY()						FVector				ShakeOffsetRate;			//var() Vector ShakeOffsetRate;
	UPROPERTY()						float				ShakeOffsetTime;			//var() float ShakeOffsetTime;

	void Reset();
	void Respond();
};
