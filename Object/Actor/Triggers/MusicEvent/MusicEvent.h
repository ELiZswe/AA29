// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "AA29/MyEnums.h"
#include "MusicEvent.generated.h"

UCLASS()
class AMusicEvent : public ATriggers
{
	GENERATED_BODY()
public:
	AMusicEvent();

	UPROPERTY(EditAnywhere)				FString				Song;					//var() FString Song;
	UPROPERTY(EditAnywhere)				EMusicTransition	Transition;				//var() Actor.EMusicTransition Transition;
	UPROPERTY(EditAnywhere)				bool				bSilence;				//var() bool bSilence;
	UPROPERTY(EditAnywhere)				bool				bOnceOnly;				//var() bool bOnceOnly;
	UPROPERTY(EditAnywhere)				bool				bAffectAllPlayers;		//var() bool bAffectAllPlayers;

	void BeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);
};
