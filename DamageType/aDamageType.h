//// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "AA29/AA29.h"
#include "AA29/MyStructs.h"
#include "aDamageType.generated.h"

class AController;
class USoundBase;
class UTexture2D;

/**
 * 
 */
//class AA29_API UaDamageType : public UDamageType


UCLASS()
class AA29_API UaDamageType : public UObject
{
	GENERATED_BODY()
public:
	UaDamageType();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float MinFragDamageScale;					//var() float MinFragDamageScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bNoKillScore;							//var() bool bNoKillScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bInstantKill;							//var() localized bool bInstantKill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<int32> DirectDamage;					//var() localized int DirectDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<int32> SplashDamage;					//var() localized int SplashDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bOverrideDamageValues;					//var() bool bOverrideDamageValues;
	UPROPERTY()										float VehicleMomentumScaling;				//var float VehicleMomentumScaling;
	UPROPERTY()										float VehicleDamageScaling;					//var float VehicleDamageScaling;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float KDeathUpKick;							//var(Karma) float KDeathUpKick;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float KDeathVel;							//var(Karma) float KDeathVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float KDamageImpulse;						//var(Karma) float KDamageImpulse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float FFMultiplier;							//var() float FFMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float DamageBleedPercent;					//var() float DamageBleedPercent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		EAmmoType AmmoType;							//var() Actor.EAmmoType AmmoType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float GibPerterbation;						//var() float GibPerterbation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float DeathOverlayTime;						//var() float DeathOverlayTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float DamageOverlayTime;					//var() float DamageOverlayTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* DeathOverlayMaterial;			//var() Material DeathOverlayMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* DamageOverlayMaterial;			//var() Material DamageOverlayMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector DamageKick;							//var() FVector DamageKick;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool DamageThreshold;						//var() int DamageThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool DamageDesc;							//var() int DamageDesc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector FlashFog;							//var() FVector FlashFog;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float FlashScale;							//var() float FlashScale;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)	AEmitter* LowDetailEmitter;					//var() class<Emitter> LowDetailEmitter;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)	AEffects* LowDetailEffect;					//var() class<Effects> LowDetailEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> LowGoreDamageSounds;	//var() array<Sound> LowGoreDamageSounds;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)	AEmitter* LowGoreDamageEmitter;				//var() class<Emitter> LowGoreDamageEmitter;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)	AEffects* LowGoreDamageEffect;				//var() class<Effects> LowGoreDamageEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> PawnDamageSounds;		//var() array<Sound> PawnDamageSounds;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)	AEmitter* PawnDamageEmitter;				//var() class<Emitter> PawnDamageEmitter;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)	AEffects* PawnDamageEffect;					//var() class<Effects> PawnDamageEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float GibModifier;							//var() float GibModifier;
	UPROPERTY()										bool bVehicleHit;							//var bool bVehicleHit;
	UPROPERTY()										bool bBulletHit;							//var bool bBulletHit;
	UPROPERTY()										bool bDirectDamage;							//var bool bDirectDamage;
	UPROPERTY()										bool bCausedByWorld;						//var bool bCausedByWorld;
	UPROPERTY()										bool bRubbery;								//var bool bRubbery;
	UPROPERTY()										bool bFlaming;								//var bool bFlaming;
	UPROPERTY()										bool bExtraMomentumZ;						//var bool bExtraMomentumZ;
	UPROPERTY()										bool bLeaveBodyEffect;						//var bool bLeaveBodyEffect;
	UPROPERTY()										bool bRagdollBullet;						//var bool bRagdollBullet;
	UPROPERTY()										bool bThrowRagdoll;							//var bool bThrowRagdoll;
	UPROPERTY()										bool bNeverSevers;							//var bool bNeverSevers;
	UPROPERTY()										bool bDelayedDamage;						//var bool bDelayedDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bKUseTearOffMomentum;					//var() bool bKUseTearOffMomentum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bKUseOwnDeathVel;						//var() bool bKUseOwnDeathVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bCausesBlood;							//var() bool bCausesBlood;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bSuperWeapon;							//var() bool bSuperWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bCauseConvulsions;						//var() bool bCauseConvulsions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bSkeletize;							//var() bool bSkeletize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bDetonatesGoop;						//var() bool bDetonatesGoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bSpecial;								//var() bool bSpecial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bAlwaysSevers;							//var() bool bAlwaysSevers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bLocationalHit;						//var() bool bLocationalHit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bAlwaysGibs;							//var() bool bAlwaysGibs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bFastInstantHit;						//var() bool bFastInstantHit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bInstantHit;							//var() bool bInstantHit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bArmorStops;							//var() bool bArmorStops;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString DamageWeaponName;					//var() string DamageWeaponName;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEffects* DamageEffect;					//var() class<Effects> DamageEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector ViewFog;							//var() FVector ViewFog;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ViewFlash;							//var() float ViewFlash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString MaleSuicide;						//var() localized string MaleSuicide;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString FemaleSuicide;						//var() localized string FemaleSuicide;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString IEDDeathString;						//var() localized string IEDDeathString;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString DeathString;						//var() localized string DeathString;

	void IncrementKills(AController* Killer);
	void ScoreKill(AController* Killer, AController* Killed, UDamageType* DamageType);
	void GetDirectDamage(int32 Armor);
	void GetSplashDamage(int32 Armor);
	void IsInstantKill();
	//void DeathMessage(PlayerReplicationInfo Killer, PlayerReplicationInfo Victim);
	//void SuicideMessage(PlayerReplicationInfo Victim);
	//void IEDDeathMessage(PlayerReplicationInfo Victim);
	void GetPawnDamageEffect(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail);
	void GetPawnDamageEmitter(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail);
	void GetPawnDamageSound();
	void IsOfType(int32 Description);
	//void GetHitEffects(AxEmitter*  HitEffects, int32 VictemHealth);
	void GetWeaponClass();



};
