// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "SpecialEventTrigger.generated.h"

UCLASS()
class ASpecialEventTrigger : public ATriggers
{
	GENERATED_BODY()
public:
	ASpecialEventTrigger();

	UPROPERTY(EditAnywhere)				int32			Damage;							//var() int32 Damage;
	UPROPERTY(EditAnywhere)				UaDamageType*	DamageType;						//var() class<DamageType> DamageType;
	UPROPERTY(EditAnywhere)				USoundBase*		Sound;							//var() Sound Sound;
	UPROPERTY(EditAnywhere)				FString			Message;						//var() localized FString Message;
	UPROPERTY(EditAnywhere)				bool			bBroadcast;						//var() bool bBroadcast;
	UPROPERTY(EditAnywhere)				bool			bPlayerJumpToInterpolation;		//var() bool bPlayerJumpToInterpolation;
	UPROPERTY(EditAnywhere)				bool			bPlayersPlaySoundEffect;		//var() bool bPlayersPlaySoundEffect;
	UPROPERTY(EditAnywhere)				bool			bKillInstigator;				//var() bool bKillInstigator;
	UPROPERTY(EditAnywhere)				bool			bViewTargetInterpolatedActor;	//var() bool bViewTargetInterpolatedActor;
	UPROPERTY(EditAnywhere)				bool			bThirdPersonViewTarget;			//var() bool bThirdPersonViewTarget;
	UPROPERTY(EditAnywhere)				FName			InterpolatedActorTag;			//var() FName InterpolatedActorTag;
	UPROPERTY(EditAnywhere)				FName			PlayerScriptTag;				//var() FName PlayerScriptTag;

	void Trigger(AActor* Other, APawn* EventInstigator);
};
