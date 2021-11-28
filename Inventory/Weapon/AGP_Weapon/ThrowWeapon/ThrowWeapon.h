// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "ThrowWeapon.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AThrowWeapon : public AAGP_Weapon
{
	GENERATED_BODY()
public:
	AThrowWeapon();

	
	UPROPERTY()		bool bShowThreatenedNodes;							//var bool bShowThreatenedNodes;
	UPROPERTY()		bool bPressedFire;									//var bool bPressedFire;
	UPROPERTY()		APlayerController* InstigatorController;			//var Controller InstigatorController;
	UPROPERTY()		uint8 InvGrenadeIndex;								//var byte InvGrenadeIndex;
	UPROPERTY()		float _FuseTime;									//var float _FuseTime;
	UPROPERTY()		float _FuseCounter;									//var float _FuseCounter;
	UPROPERTY()		AThrowWeaponPickup* _PickupPtr;						//var ThrowWeaponPickup _PickupPtr;
	UPROPERTY()		float _fTossTime;									//var float _fTossTime;
	UPROPERTY()		float _fTossSpeed;									//var float _fTossSpeed;
	UPROPERTY()		float _fThrowTime;									//var float _fThrowTime;
	UPROPERTY()		float _fThrowSpeed;									//var float _fThrowSpeed;
	//UPROPERTY()	ABaseSmokeEmitter* cSmokeEmitter;					//var class<AGP_Effects.BaseSmokeEmitter> cSmokeEmitter;
	//UPROPERTY()	AProjector* cExplosionDecal;						//var class<Projector> cExplosionDecal;
	//UPROPERTY()	AEmitter* cExplosionEmitter;						//var class<Emitter> cExplosionEmitter;
	UPROPERTY()		USoundBase* PopSpoonSound;							//var Sound PopSpoonSound;
	UPROPERTY()		USoundBase* BoomSound;								//var Sound BoomSound;
	UPROPERTY()		USoundBase* PullLowSound;							//var Sound PullLowSound;
	UPROPERTY()		USoundBase* PullSound;								//var Sound PullSound;
	UPROPERTY()		bool _bAltFireNotified;								//var bool _bAltFireNotified;
	UPROPERTY()		bool _bUseAnimNotifyAltFire;						//var bool _bUseAnimNotifyAltFire;
	UPROPERTY()		bool _bLostSpoon;									//var bool _bLostSpoon;
	UPROPERTY()		bool _bPulledPin;									//var bool _bPulledPin;
	UPROPERTY()		bool _bBlewUp;										//var bool _bBlewUp;
	UPROPERTY()		float _fEffectDuration;								//var float _fEffectDuration;
	UPROPERTY()		float _fMaxVisIntensity;							//var float _fMaxVisIntensity;
	UPROPERTY()		float _fMaxAudIntensity;							//var float _fMaxAudIntensity;
	UPROPERTY()		float sDamagePerTime;								//var float sDamagePerTime;
	UPROPERTY()		float sDamageAtEdge;								//var float sDamageAtEdge;
	UPROPERTY()		float sDamageAtCenter;								//var float sDamageAtCenter;
	UPROPERTY()		float sDamageRadius;								//var float sDamageRadius;
	UPROPERTY()		float sDamageHeight;								//var float sDamageHeight;
	UPROPERTY()		TSubclassOf<class UDamageType> SmokeDamageType;		//var class<DamageType> SmokeDamageType;
	UPROPERTY()		TArray<AActor*> DamageClasses;						//var array<class<Actor> > DamageClasses;
	UPROPERTY()		TSubclassOf<class UDamageType> MyDamageType;		//var class<DamageType> MyDamageType;
	UPROPERTY()		TSubclassOf<class UDamageType> FragDamageType;		//var class<DamageType> FragDamageType;
	UPROPERTY()		float _fMomentum;									//var float _fMomentum;
	UPROPERTY()		float _fKillRadius;									//var float _fKillRadius;
	UPROPERTY()		float _fDamageRadius;								//var float _fDamageRadius;
	UPROPERTY()		float _fDamage;										//var float _fDamage;
	UPROPERTY()		float _fAddFuseTime;								//var float _fAddFuseTime;
	UPROPERTY()		float _fMinFuseTime;								//var float _fMinFuseTime;

	void Destroyed();
	EUpperBodyAnim GetUpperBodyLowerAnim();
	EUpperBodyAnim GetUpperBodyRaiseAnim();
	EUpperBodyAnim GetUpperBodyReadyAnim();
	virtual void Reload() override;
	virtual void FixJam() override;
	void InitFor(AInventory* Inv);
	void SpawnAmmoFor(AAGP_Weapon* OldW, AAmmunition* oldA);
	void SpawnAndAttachMILESGear();
	void TempLowerWeapon(bool bActive);
	bool IsPinPulled();
	bool isHandsOnly();
	bool IsLostSpoon();
	bool IsTossNotThrow();
	void SetFuseTime(float Time);
	void Tick(float DeltaTime);
	virtual void RecountAmmo() override;
	virtual bool ShouldDrawCrosshair();
	void HandleLive(APawn* NewInstigator);
	void Finish();
	void ClientFinish();
	virtual void Fire(float Value) override;
	void ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus);
	void ServerThrow();
	virtual void DoChangeFireMode() override;
	virtual void PlayChangeFireMode();
	void BlowUp();
	void ClientBlowUp();
	void GetFireStart(FVector X, FVector Y, FVector Z);
	void SpawnPickup(bool bDrop, AThrowWeaponPickup* SetPickupPtr);
	virtual void TweenDown() override;
	virtual void PlaySelect() override;
	virtual void PlayIdleAnim() override;
	virtual void PlayFiring() override;
	void StartCrawling();


};
