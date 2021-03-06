//// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "AA29/AA29.h"
#include "AA29/MyEnums.h"
#include "aDamageType.generated.h"

class AController;
class USoundBase;
class UTexture2D;
class AEffects;
class AEmitter;
class AxEmitter;

UCLASS()
class UaDamageType : public UObject
{
	GENERATED_BODY()
public:
	UaDamageType();
	
	UPROPERTY(EditAnywhere)		float MinFragDamageScale;					//var() float MinFragDamageScale;
	UPROPERTY(EditAnywhere)		bool bNoKillScore;							//var() bool bNoKillScore;
	UPROPERTY(EditAnywhere)		bool bInstantKill;							//var() localized bool bInstantKill;
	UPROPERTY(EditAnywhere)		TArray<int32> DirectDamage;					//var() localized int DirectDamage;
	UPROPERTY(EditAnywhere)		TArray<int32> SplashDamage;					//var() localized int SplashDamage;
	UPROPERTY(EditAnywhere)		bool bOverrideDamageValues;					//var() bool bOverrideDamageValues;
	UPROPERTY()										float VehicleMomentumScaling;				//var float VehicleMomentumScaling;
	UPROPERTY()										float VehicleDamageScaling;					//var float VehicleDamageScaling;
	UPROPERTY(EditAnywhere)		float KDeathUpKick;							//var(Karma) float KDeathUpKick;
	UPROPERTY(EditAnywhere)		float KDeathVel;							//var(Karma) float KDeathVel;
	UPROPERTY(EditAnywhere)		float KDamageImpulse;						//var(Karma) float KDamageImpulse;
	UPROPERTY(EditAnywhere)		float FFMultiplier;							//var() float FFMultiplier;
	UPROPERTY(EditAnywhere)		float DamageBleedPercent;					//var() float DamageBleedPercent;
	UPROPERTY(EditAnywhere)		EAmmoType AmmoType;							//var() Actor.EAmmoType AmmoType;
	UPROPERTY(EditAnywhere)		float GibPerterbation;						//var() float GibPerterbation;
	UPROPERTY(EditAnywhere)		float DeathOverlayTime;						//var() float DeathOverlayTime;
	UPROPERTY(EditAnywhere)		float DamageOverlayTime;					//var() float DamageOverlayTime;
	UPROPERTY(EditAnywhere)		UTexture2D* DeathOverlayMaterial;			//var() Material DeathOverlayMaterial;
	UPROPERTY(EditAnywhere)		UTexture2D* DamageOverlayMaterial;			//var() Material DamageOverlayMaterial;
	UPROPERTY(EditAnywhere)		FVector DamageKick;							//var() FVector DamageKick;
	UPROPERTY(EditAnywhere)		bool DamageThreshold;						//var() int DamageThreshold;
	UPROPERTY(EditAnywhere)		bool DamageDesc;							//var() int DamageDesc;
	UPROPERTY(EditAnywhere)		FVector FlashFog;							//var() FVector FlashFog;
	UPROPERTY(EditAnywhere)		float FlashScale;							//var() float FlashScale;
	UPROPERTY(EditAnywhere)		AEmitter* LowDetailEmitter;					//var() class<Emitter> LowDetailEmitter;
	UPROPERTY(EditAnywhere)		AEffects* LowDetailEffect;					//var() class<Effects> LowDetailEffect;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*> LowGoreDamageSounds;	//var() array<Sound> LowGoreDamageSounds;
	UPROPERTY(EditAnywhere)		AEmitter* LowGoreDamageEmitter;				//var() class<Emitter> LowGoreDamageEmitter;
	UPROPERTY(EditAnywhere)		AEffects* LowGoreDamageEffect;				//var() class<Effects> LowGoreDamageEffect;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*> PawnDamageSounds;		//var() array<Sound> PawnDamageSounds;
	UPROPERTY(EditAnywhere)		AEmitter* PawnDamageEmitter;				//var() class<Emitter> PawnDamageEmitter;
	UPROPERTY(EditAnywhere)		AEffects* PawnDamageEffect;					//var() class<Effects> PawnDamageEffect;
	UPROPERTY(EditAnywhere)		float GibModifier;							//var() float GibModifier;
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
	UPROPERTY(EditAnywhere)		bool bKUseTearOffMomentum;					//var() bool bKUseTearOffMomentum;
	UPROPERTY(EditAnywhere)		bool bKUseOwnDeathVel;						//var() bool bKUseOwnDeathVel;
	UPROPERTY(EditAnywhere)		bool bCausesBlood;							//var() bool bCausesBlood;
	UPROPERTY(EditAnywhere)		bool bSuperWeapon;							//var() bool bSuperWeapon;
	UPROPERTY(EditAnywhere)		bool bCauseConvulsions;						//var() bool bCauseConvulsions;
	UPROPERTY(EditAnywhere)		bool bSkeletize;							//var() bool bSkeletize;
	UPROPERTY(EditAnywhere)		bool bDetonatesGoop;						//var() bool bDetonatesGoop;
	UPROPERTY(EditAnywhere)		bool bSpecial;								//var() bool bSpecial;
	UPROPERTY(EditAnywhere)		bool bAlwaysSevers;							//var() bool bAlwaysSevers;
	UPROPERTY(EditAnywhere)		bool bLocationalHit;						//var() bool bLocationalHit;
	UPROPERTY(EditAnywhere)		bool bAlwaysGibs;							//var() bool bAlwaysGibs;
	UPROPERTY(EditAnywhere)		bool bFastInstantHit;						//var() bool bFastInstantHit;
	UPROPERTY(EditAnywhere)		bool bInstantHit;							//var() bool bInstantHit;
	UPROPERTY(EditAnywhere)		bool bArmorStops;							//var() bool bArmorStops;
	UPROPERTY(EditAnywhere)		FString DamageWeaponName;					//var() string DamageWeaponName;
	UPROPERTY(EditAnywhere)		AEffects* DamageEffect;						//var() class<Effects> DamageEffect;
	UPROPERTY(EditAnywhere)		FVector ViewFog;							//var() FVector ViewFog;
	UPROPERTY(EditAnywhere)		float ViewFlash;							//var() float ViewFlash;
	UPROPERTY(EditAnywhere)		FString MaleSuicide;						//var() localized string MaleSuicide;
	UPROPERTY(EditAnywhere)		FString FemaleSuicide;						//var() localized string FemaleSuicide;
	UPROPERTY(EditAnywhere)		FString IEDDeathString;						//var() localized string IEDDeathString;
	UPROPERTY(EditAnywhere)		FString DeathString;						//var() localized string DeathString;

	void IncrementKills(AController* Killer);
	void ScoreKill(AController* Killer, AController* Killed, UDamageType* DamageType);
	int32 GetDirectDamage(int32 Armor);
	int32 GetSplashDamage(int32 Armor);
	bool IsInstantKill();
	FString DeathMessage(AAA2_PlayerState* Killer, AAA2_PlayerState* Victim);
	FString SuicideMessage(AAA2_PlayerState* Victim);
	FString IEDDeathMessage(AAA2_PlayerState* Victim);
	AEffects* GetPawnDamageEffect(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail);
	AEmitter* GetPawnDamageEmitter(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail);
	void GetPawnDamageSound();
	void IsOfType(int32 Description);
	void GetHitEffects(AxEmitter*  HitEffects, int32 VictemHealth);
	FString GetWeaponClass();
};
