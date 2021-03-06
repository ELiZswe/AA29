// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "LineOfSightTrigger.generated.h"

UCLASS()
class ALineOfSightTrigger : public ATriggers
{
	GENERATED_BODY()
public:
	ALineOfSightTrigger();
	
	UPROPERTY(EditAnywhere)		float		MaxViewDist;			//var() float MaxViewDist;
	UPROPERTY()					float		OldTickTime;			//var float OldTickTime;
	UPROPERTY(EditAnywhere)		bool		bEnabled;				//var() bool bEnabled;
	UPROPERTY()					bool		bTriggered;				//var bool bTriggered;
	UPROPERTY(EditAnywhere)		FName		SeenActorTag;			//var() FName SeenActorTag;
	UPROPERTY()					AActor*		SeenActor;				//var Actor SeenActor;
	UPROPERTY(EditAnywhere)		int32		MaxViewAngle;			//var() int32 MaxViewAngle;
	UPROPERTY()					float		RequiredViewDir;		//var float RequiredViewDir;

	void PostBeginPlay();
	void PlayerSeesMe(APlayerController* p);
	void Trigger(AActor* Other, APawn* EventInstigator);
};
