// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "EmitterSpawner.generated.h"

class UaDamageType;

UCLASS()
class AEmitterSpawner : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	AEmitterSpawner();

	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								float ShakeOffsetTime;						//var(EmitterDamage) float ShakeOffsetTime;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								FVector ShakeOffsetRate;					//var(EmitterDamage) FVector ShakeOffsetRate;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								FVector ShakeOffsetMag;						//var(EmitterDamage) FVector ShakeOffsetMag;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								float ShakeRotTime;							//var(EmitterDamage) float ShakeRotTime;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								FVector ShakeRotRate;						//var(EmitterDamage) FVector ShakeRotRate;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								FVector ShakeRotMag;						//var(EmitterDamage) FVector ShakeRotMag;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								FRange bShakeView;							//var(EmitterDamage) bool bShakeView;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								USoundBase* EmitterSound;					//var(EmitterDamage) Sound EmitterSound;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								UaDamageType* DamageType;					//var(EmitterDamage) class<DamageType> DamageType;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								FString DamageTypeClassName;				//var(EmitterDamage) string DamageTypeClassName;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								float KillRadius;							//var(EmitterDamage) float KillRadius;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								float DamageRadius;							//var(EmitterDamage) float DamageRadius;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								float MomentumTransfer;						//var(EmitterDamage) float MomentumTransfer;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								int32 Damage;								//var(EmitterDamage) int Damage;
	UPROPERTY(EditAnywhere, Category = "EmitterDamage")								bool bDoDestroy;							//var bool bDoDestroy;
	UPROPERTY(EditAnywhere)															TArray<AEmitter*> MyEmitters;				//var array<Emitter> MyEmitters;
	UPROPERTY(EditAnywhere)															TArray<AEmitter*> MyEmitterClasses;			//var array<class<Emitter> > MyEmitterClasses;

	void Trigger(AActor* Other, APawn* EventInstigator);
	void ShakeView();
	void RadiusDamage(float DamageAmount, float DamageRadius, UaDamageType* DamageType, float Momentum, FVector HitLocation, float KillRadius);
	void MatchStarting();
	void Destroyed();
	void DestroyMyEmitters();
	void Tick(float DeltaTime);
};
