// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "AA29/Object/DamageType/aDamageType.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Projectile.generated.h"






UCLASS()
class AA29_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
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
	//UPROPERTY()																			AProjector* ExplosionDecal;					//var class<Projector> ExplosionDecal;
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
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** inits velocity of the projectile in the shoot direction */
	void InitVelocity(const FVector& ShootDirection);

	UFUNCTION() void OnMyHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
