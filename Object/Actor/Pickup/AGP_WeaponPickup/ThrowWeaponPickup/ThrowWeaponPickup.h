// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"
#include "ThrowWeaponPickup.generated.h"

class AThrowWeapon;
class AEmitter;
class ADamageTrigger;

UCLASS()
class AA29_API AThrowWeaponPickup : public AAGP_WeaponPickup
{
	GENERATED_BODY()
public:
	AThrowWeaponPickup();

	UPROPERTY()										bool					bShowThreatenedNodes;	//var bool bShowThreatenedNodes;
	UPROPERTY()										float					DamageHeight;			//var float DamageHeight;
	UPROPERTY()										float					DamageRadius;			//var float DamageRadius;
	UPROPERTY()										ADamageTrigger*			DamageArea;				//var DamageTrigger DamageArea;
	UPROPERTY()										float					_EffectDuration;		//var float _EffectDuration;
	UPROPERTY()										UStaticMesh*			LiveMesh;				//var Mesh LiveMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*>		_sImpactSounds;			//var() array<Sound> _sImpactSounds;
	UPROPERTY()										UStaticMesh*			liveStaticMesh;			//var StaticMesh liveStaticMesh;
	UPROPERTY()										float					_fBounceSpin;			//var float _fBounceSpin;
	UPROPERTY()										float					_fBounceDamp;			//var float _fBounceDamp;
	UPROPERTY()										bool					_bBlewUpProcessed;		//var bool _bBlewUpProcessed;
	UPROPERTY()										bool					_bBlewUp;				//var bool _bBlewUp;
	UPROPERTY()										bool					_bIsLive;				//var bool _bIsLive;
	UPROPERTY()										TArray<USoundBase*>		sMuffled;				//var array<Sound> sMuffled;
	UPROPERTY()										TArray<USoundBase*>		sWater;					//var array<Sound> sWater;
	UPROPERTY()										TArray<USoundBase*>		sMetal;					//var array<Sound> sMetal;
	UPROPERTY()										TArray<USoundBase*>		sDirt;					//var array<Sound> sDirt;
	UPROPERTY()										TArray<USoundBase*>		sWood;					//var array<Sound> sWood;

	void SetDoorBreacherEmitter(AEmitter* EM);
	void StaticPrecache (ALevelInfo* L);
	void RandSpin(float spinRate);
	void Destroyed();
	bool IsLive();
	void PostBeginPlay();
	void SetWeapon(AThrowWeapon* W);
	void InitDroppedPickupFor(AInventory* Inv, bool bFreeze);
	void AgentControllerFearMe();
	void AgentControllerRemoveFearMe();
	void Tick(float DeltaTime);
	void DeleteProjectile();
	void ProcessBlewUp();
	void SpawnSmokeEmitter(AThrowWeapon*  W);
	void SpawnDamageArea(AThrowWeapon*  W);
	void Landed(FVector HitNormal);
	void HitWall(FVector HitNormal, AActor* Wall);
	void Touch(AActor* Other);
	void PlayLandedSound(UTexture2D* HitMaterial);
	float GetMaterialBounceDamp(UTexture2D* HitMaterial);
	void MaybeAdjustCollisionSize();
};
