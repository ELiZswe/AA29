// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "AA29/AA29.h"
#include "Net/UnrealNetwork.h"
#include "DecoMesh.generated.h"


class UaDamageType;
class ABaseObjective; 
class AInventory;

UCLASS()
class AA29_API ADecoMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecoMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)											bool bAICanSeeThrough;						//var() bool bAICanSeeThrough;
	UPROPERTY()																			int32 YoungestDecoDecal;					//var const int YoungestDecoDecal;
	UPROPERTY()																			FVector FragMomentum;						//var FVector FragMomentum;
	UPROPERTY()																			bool bPushSoundPlaying;						//var bool bPushSoundPlaying;
	UPROPERTY()																			bool bInitialDisplayTargetingInfo;			//var bool bInitialDisplayTargetingInfo;
	UPROPERTY()																			bool bInitialBreachable;					//var bool bInitialBreachable;
	UPROPERTY(Replicated)																UStaticMesh* InitialStaticMesh;				//var StaticMesh InitialStaticMesh;
	UPROPERTY()																			int32 InitialDestroyHealth;					//var int InitialDestroyHealth;
	UPROPERTY()																			int32 InitialDamageHealth;					//var int InitialDamageHealth;
	UPROPERTY()																			int32 InitialKillHealth;					//var int InitialKillHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyMesh", Replicated)		uint8 FriendlyTeam;							//var(EnemyMesh) byte FriendlyTeam;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyMesh", Replicated)		UStaticMesh* EnemyDestroyedMesh;			//var(EnemyMesh) StaticMesh EnemyDestroyedMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyMesh", Replicated)		UStaticMesh* EnemyDamagedMesh;				//var(EnemyMesh) StaticMesh EnemyDamagedMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyMesh", Replicated)		UStaticMesh* EnemyStaticMesh;				//var(EnemyMesh) StaticMesh EnemyStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyMesh", Replicated)		bool bUseEnemyMeshes;						//var(EnemyMesh) bool bUseEnemyMeshes;
	UPROPERTY()																			bool bTimerDoVerify;						//var bool bTimerDoVerify;
	UPROPERTY(Replicated)																uint8 VerifyMeshCount;						//var byte VerifyMeshCount;
	UPROPERTY()																			ABaseObjective* DamageObjective;			//var BaseObjective DamageObjective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageType", Replicated)	UaDamageType* DisplayDamageType;			//var(DamageType) class<DamageType> DisplayDamageType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageType")				TArray<UaDamageType*> DamageTypes;			//var(DamageType) array<class<DamageType> > DamageTypes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageType")				bool bCheckDamageType;						//var(DamageType) bool bCheckDamageType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")				int32 DestroyPoints;						//var(LinkDamage) int DestroyPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")				int32 DamagePoints;							//var(LinkDamage) int DamagePoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")				int32 KillHealth;							//var(LinkDamage) int KillHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")				int32 KillEvent;							//var(LinkDamage) name KillEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")				FName DamageTag;							//var(LinkDamage) name DamageTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite			)								FName DestroyEvent;							//var() name DestroyEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)											FName DamageEvent;							//var() name DamageEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)								UStaticMesh* DestroyedMesh;					//var() StaticMesh DestroyedMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)								UStaticMesh* DamagedMesh;					//var() StaticMesh DamagedMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)											USoundBase* DestroySound;					//var() Sound DestroySound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)											USoundBase* DamageSound;					//var() Sound DamageSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)								int32 DestroyHealth;						//var() int DestroyHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)								int32 DamageHealth;							//var() int DamageHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)								bool bDestroyable;							//var() const bool bDestroyable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)								bool bDamageable;							//var() const bool bDamageable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)								bool bReallyDestroy;						//var() const bool bReallyDestroy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)								bool bInstantGrenBreak;						//var() const bool bInstantGrenBreak;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)								bool bDisplayTargetingInfo;					//var() bool bDisplayTargetingInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)								bool bBreachable;							//var() bool bBreachable;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)										AEmitter* BreachedEmitter;					//var() class<Emitter> BreachedEmitter;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)										AFragment* FragType;						//var() class<Fragment> FragType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)											UTexture2D* FragSkin;						//var() Texture FragSkin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)											float FragSize;								//var() float FragSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)											int32 NumFrags;								//var() int NumFrags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)											AInventory* Contents;						//var() class<Inventory> Contents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)											USoundBase* EndPushSound;					//var() Sound EndPushSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)											USoundBase* PushSound;						//var() Sound PushSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)											bool bPushable;								//var() bool bPushable;

	//From Actor
	UPROPERTY(EditAnywhere, Replicated)													bool bFixedRotationDir;						//var(Movement) bool bFixedRotationDir;
	UPROPERTY(EditAnywhere, Replicated, Category = "Sound")								USoundBase* AmbientSound;					//var(Sound) Sound AmbientSound;
	UPROPERTY(EditAnywhere, Replicated, Category = "Sound")								FRotator RotationRate;						//var(Movement) Object.Rotator RotationRate;

	//Mine
	UPROPERTY(EditAnywhere, Replicated)													UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere, Replicated)													USceneComponent* DecoRoot;
	UPROPERTY(EditAnywhere, Replicated)													URotatingMovementComponent* RotatingMovement;

	void PostBeginPlay();
	void Reset();
	void ClientsVerifyMesh(float fAgain);
	void Timer();
	
	void PostNetBeginPlay();
	void VerifyMesh();
	bool IsDamaged();
	bool ShouldTakeDamage(UaDamageType* DamageType);
	bool ShouldDisplayDamageType(UaDamageType* ForDamageType);
	//void TakeDamage (int32 NDamage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, optional Actor ResponsibleActor, Material HitMaterial);
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
	bool ShouldTakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) const;

	void HandleBreachDamage(int32 NDamage);
	void DecoDestroyed();
	void Bump(AActor* Other);


};
