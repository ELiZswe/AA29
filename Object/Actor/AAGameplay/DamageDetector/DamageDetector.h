// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AAGameplay/AAGameplay.h"
#include "AA29/MyEnums.h"

#include "DamageDetector.generated.h"

UCLASS()
class ADamageDetector : public AAAGameplay
{
	GENERATED_BODY()
public:
	ADamageDetector();
	
	//void TakeDamage(int32 Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
	bool ActorNotify(AActor* NotifyActory, EEventType Event, AActor* aInstigator, FString Parms);
};
