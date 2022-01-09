// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"

//#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Projectile.generated.h"

class AProjector;
class UaDamageType;

UCLASS()
class AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AProjectile(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", Replicated)		UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile", Replicated)						USphereComponent* CollisionComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile", Replicated)						UStaticMeshComponent* ProjectileMesh;

	UPROPERTY()																				bool bScriptPostRender;							//var bool bScriptPostRender;
	UPROPERTY()																				float MaxEffectDistance;						//var float MaxEffectDistance;
	UPROPERTY()																				AActor* HurtWall;								//var Actor HurtWall;
	UPROPERTY()																				AActor* LastTouched;							//var Actor LastTouched;
	UPROPERTY()																				APlayerController* InstigatorController;		//var Controller InstigatorController;
	UPROPERTY()																				float ExploWallOut;								//var float ExploWallOut;
	UPROPERTY()																				AProjector* ExplosionDecal;						//var class<Projector> ExplosionDecal;
	UPROPERTY()																				USoundBase* ImpactSound;						//var Sound ImpactSound;
	UPROPERTY()																				USoundBase* SpawnSound;							//var Sound SpawnSound;
	UPROPERTY()																				TSubclassOf<class UaDamageType> MyDamageType;	//var class<DamageType> MyDamageType;
	UPROPERTY()																				float MomentumTransfer;							//var float MomentumTransfer;
	UPROPERTY()																				float DamageRadius;								//var float DamageRadius;
	UPROPERTY()																				float bActiveOnTrigger;							//var float Damage;
	UPROPERTY()																				bool bSpecialCalcView;							//var bool bSpecialCalcView;
	UPROPERTY()																				bool bReadyToSplash;							//var bool bReadyToSplash;
	UPROPERTY()																				bool bNoFX;										//var bool bNoFX;
	UPROPERTY()																				bool bSwitchToZeroCollision;					//var bool bSwitchToZeroCollision;
	UPROPERTY()																				AActor* ZeroCollider;							//var Actor ZeroCollider;
	UPROPERTY()																				float TossZ;									//var float TossZ;
	UPROPERTY()																				float						MaxSpeed;			//var float MaxSpeed;
	UPROPERTY()																				float						Speed;				//var float Speed;

	//FromActor
	UPROPERTY()																				EDrawType					DrawType;
	UPROPERTY()																				int32						Damage;
	UPROPERTY()																				int32						CollisionRadius;
	UPROPERTY()																				int32						CollisionHeight;
	UPROPERTY()																				float						DrawScale;
	UPROPERTY()																				FRotator					Rotation;
	UPROPERTY()																				FVector						DrawScale3D;
	UPROPERTY()																				UStaticMesh*				StaticMesh;
	UPROPERTY()																				uint8						LightHue;
	UPROPERTY()																				uint8						LightSaturation;
	UPROPERTY()																				uint8						LightBrightness;
	UPROPERTY()																				int32						LightRadius;
	UPROPERTY()																				ELightType					LightType;
	UPROPERTY()																				ELightEffect				LightEffect;
	UPROPERTY()																				bool						bDynamicLight;
	UPROPERTY()																				int32						LifeSpan;
	UPROPERTY()																				uint8						AmbientGlow;
	UPROPERTY()																				TArray<UMaterialInstance*>	Skins;

	void PostBeginPlay();
	bool SpecialCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation, bool bBehindView);
	bool CanSplash();
	void Reset();
	bool CheckMaxEffectDistance(APlayerController* p, FVector SpawnLocation);
	void HurtRadius(float DamageAmount, float aDamageRadius, UaDamageType* DamageType, float Momentum, FVector HitLocation);
	void DelayedHurtRadius(float DamageAmount, float aDamageRadius, UaDamageType* DamageType, float Momentum, FVector HitLocation);
	bool EncroachingOn(AActor* Other);
	void Touch(AActor* Other);
	void ClientSideTouch(AActor* Other, FVector HitLocation);
	void ProcessTouch(AActor* Other, FVector HitLocation);
	void HitWall(FVector HitNormal, AActor* Wall);
	void BlowUp(FVector HitLocation);
	void Explode(FVector HitLocation, FVector HitNormal);
	void RandSpin(float spinRate);
	float GetRange();
	bool IsStationary();
	void PostRender2D(UCanvas* C, float ScreenLocX, float ScreenLocY);
	void MatchEnding();

protected:
	
	virtual void BeginPlay() override;
	

public:	
	
	virtual void Tick(float DeltaTime) override;

	/** inits velocity of the projectile in the shoot direction */
	void InitVelocity(const FVector& ShootDirection);

	UFUNCTION() void OnMyHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
