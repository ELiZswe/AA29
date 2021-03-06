// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "MovieTrigger.generated.h"

UCLASS()
class AMovieTrigger : public ATrigger
{
	GENERATED_BODY()
public:
	AMovieTrigger();

	UPROPERTY(EditAnywhere)		FName				TriggerSoundTarget;			//var() FName TriggerSoundTarget;
	UPROPERTY(EditAnywhere)		FName				StaticMeshTarget;			//var() FName StaticMeshTarget;
	UPROPERTY(EditAnywhere)		int32				SkinSlot;					//var() int32 SkinSlot;
	UPROPERTY(EditAnywhere)		UMaterialInstance*	MovieToPlay;				//var() UMovieTexture* MovieToPlay;
	UPROPERTY(EditAnywhere)		bool				bRepeatMovie;				//var() bool bRepeatMovie;

	void DoTouch(AActor* Other);
	void Timer();
};
