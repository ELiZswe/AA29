// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "TeamTrigger.generated.h"

UCLASS()
class ATeamTrigger : public ATrigger
{
	GENERATED_BODY()
public:
	ATeamTrigger();
	
	UPROPERTY(EditAnywhere)				uint8 Team;			//var() uint8 Team;
	UPROPERTY(EditAnywhere)				bool bTimed;		//var() bool bTimed;

	void PostBeginPlay();
	void Timer();
	bool IsRelevant(AActor* Other);
	//void TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial);

};
