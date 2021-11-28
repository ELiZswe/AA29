// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "DamageTrigger.generated.h"

class UaDamageType;
class AThrowWeaponPickup;

UCLASS()
class AA29_API ADamageTrigger : public ATriggers
{
	GENERATED_BODY()
public:
	ADamageTrigger();

	UPROPERTY(EditAnywhere)			UaDamageType*				DamageType;					//var() class<DamageType> DamageType;
	UPROPERTY(EditAnywhere)			TArray<AActor*>				DamageClasses;				//var() TArray<class<Actor> > DamageClasses;
	UPROPERTY(EditAnywhere)			float						fDamageCenter;				//var() float fDamageCenter;
	UPROPERTY(EditAnywhere)			float						fDamageEdge;				//var() float fDamageEdge;
	UPROPERTY(EditAnywhere)			float						fDamageTime;				//var() float fDamageTime;
	UPROPERTY(EditAnywhere)			TArray<AActor*>				DamageActors;				//var TArray<Actor> DamageActors;
	UPROPERTY(EditAnywhere)			AController*				InstigatorController;		//var Controller InstigatorController;

	void InitializeFor(AThrowWeaponPickup* p);
	void NotifyLanded(AThrowWeaponPickup* p);
	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
	void AddDamageActor(AActor* Other);
	void Timer();
	void DamageActor(AActor* Other);
};
