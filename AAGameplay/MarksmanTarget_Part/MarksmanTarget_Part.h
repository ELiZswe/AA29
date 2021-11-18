// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AAGameplay/AAGameplay.h"
#include "MarksmanTarget_Part.generated.h"

class AMarksmanTarget;

UCLASS()
class AA29_API AMarksmanTarget_Part : public AAAGameplay
{
	GENERATED_BODY()
public:
	AMarksmanTarget_Part();

	UPROPERTY()						FString ZoneID;								//var string ZoneID;
	UPROPERTY()						AMarksmanTarget* Target;					//var MarksmanTarget Target;

	void SetMarksmanTarget(AMarksmanTarget* t);
	void SetZoneID(FString Id);
	//void TakeDamage(int Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);

};
