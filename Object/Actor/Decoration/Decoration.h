// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Decoration.generated.h"

class AInventory;
class AFragment;
class ANavigationPoint;

UCLASS()
class AA29_API ADecoration : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ADecoration();


	UPROPERTY(EditAnywhere)			AActor*				EffectWhenDestroyed;		//var() class<Actor> EffectWhenDestroyed;
	UPROPERTY(EditAnywhere)			bool				bPushable;					//var() bool bPushable;
	UPROPERTY(EditAnywhere)			bool				bDamageable;				//var() bool bDamageable;
	UPROPERTY()						bool				bPushSoundPlaying;			//var bool bPushSoundPlaying;
	UPROPERTY()						bool				bSplash;					//var bool bSplash;
	UPROPERTY(EditAnywhere)			USoundBase*			PushSound;					//var() Sound PushSound;
	UPROPERTY(EditAnywhere)			USoundBase*			EndPushSound;				//var() Sound EndPushSound;
	UPROPERTY()						int32				numLandings;				//var const int32 numLandings;
	UPROPERTY(EditAnywhere)			AInventory*			Contents;					//var() class<Inventory> Contents;
	UPROPERTY(EditAnywhere)			int32				NumFrags;					//var() int32 NumFrags;
	UPROPERTY(EditAnywhere)			UMaterialInstance*	FragSkin;					//var() Texture FragSkin;
	UPROPERTY(EditAnywhere)			AFragment*			FragType;					//var() class<Fragment> FragType;
	UPROPERTY()						FVector				FragMomentum;				//var Vector FragMomentum;
	UPROPERTY(EditAnywhere)			int32				Health;						//var() int32 Health;
	UPROPERTY(EditAnywhere)			float				SplashTime;					//var() float SplashTime;
	UPROPERTY()						ANavigationPoint*	LastAnchor;					//var const NavigationPoint LastAnchor;
	UPROPERTY()						float				LastValidAnchorTime;		//var float LastValidAnchorTime;

	void NotReachableBy(APawn* p);
	bool CanSplash();
	void Drop(FVector NewVel);
	void Landed(FVector HitNormal);
	void HitWall(FVector HitNormal, AActor* Wall);
	//void TakeDamage(int32 NDamage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, Actor.BoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial);
	void PhysicsVolumeChange(APhysicsVolume* NewVolume);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void BaseChange();
	void Destroyed();
	void Timer();
	void Bump(AActor* Other);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
