// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/AA2_PhysicsVolume.h"
#include "AA29/MyEnums.h"
#include "StationTriggerVolume.generated.h"

UCLASS()
class AStationTriggerVolume : public AAA2_PhysicsVolume
{
	GENERATED_BODY()
public:
	AStationTriggerVolume();

	UPROPERTY(EditAnywhere)			FName StationTag;						//var() name StationTag;

	//From TriggerVolume
	UPROPERTY(EditAnywhere)			bool EActorType;						//var() bool EActorType;
	UPROPERTY(EditAnywhere)			TArray<AActor*> SpecificActors;			//var() array<class<Actor> > SpecificActors;
	UPROPERTY(EditAnywhere)			bool bDoUnTrigger;						//var() bool bDoUnTrigger;
	//  UPROPERTY(EditAnywhere)			EActorType ActorType;					//var() EActorType ActorType;

	void PostBeginPlay();
	void Reset();
};
