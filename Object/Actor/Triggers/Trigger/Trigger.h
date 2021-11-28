// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AA29.h"
#include "UObject/ConstructorHelpers.h"


#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "Trigger.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATrigger : public ATriggers
{
	GENERATED_BODY()
public:
	ATrigger();

	UPROPERTY(EditAnywhere)							bool bResetCollisionAtRoundEnd;								//var() bool bResetCollisionAtRoundEnd;
	UPROPERTY()										bool bSavedInitialActive;									//var bool bSavedInitialActive;
	UPROPERTY()										bool bSavedInitialCollision;								//var bool bSavedInitialCollision;
	UPROPERTY()										AActor* TriggerActor2;										//var Actor TriggerActor2;
	UPROPERTY()										AActor* TriggerActor;										//var Actor TriggerActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float DamageThreshold;										//var() float DamageThreshold;
	UPROPERTY()										float TriggerTime;											//var float TriggerTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ReTriggerDelay;										//var() float ReTriggerDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float RepeatTriggerTime;									//var() float RepeatTriggerTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AActor* ClassProximityType;									//var() class<Actor> ClassProximityType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bInitiallyActive;										//var() bool bInitiallyActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bTriggerOnceOnly;										//var() bool bTriggerOnceOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString Message;											//var() localized string Message;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		ETriggerType TriggerType;									//var() ETriggerType TriggerType;

	//From Actor:



	void PlayerToucherDied(APawn* p);
	bool SelfTriggered();
	void PreBeginPlay();
	void PostBeginPlay();
	void Reset();
	void MatchStarting();
	void FindTriggerActor();
	void SpecialHandling(APawn* Other);
	void CheckTouchList();
	void IsRelevant(AActor* Other);
	void FindInstigator(AActor* Other);
	void Touch(AActor* Other);
	void DoTouch(AActor* Other);
	void Timer();
	//void TakeDamage(int Damage, Pawn instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);
	void UnTouch(AActor* Other);
	void SetActive(bool Active);

};
