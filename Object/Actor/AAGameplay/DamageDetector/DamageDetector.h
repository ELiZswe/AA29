// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AAGameplay/AAGameplay.h"
#include "AA29/MyStructs.h"

#include "DamageDetector.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADamageDetector : public AAAGameplay
{
	GENERATED_BODY()
public:
	ADamageDetector();

	
	//void TakeDamage(int Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
	void ActorNotify(AActor* NotifyActory, EEventType Event, AActor* aInstigator, FString Parms);
};
