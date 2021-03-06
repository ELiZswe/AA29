// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "MusicTrigger.generated.h"

UCLASS()
class AMusicTrigger : public ATriggers
{
	GENERATED_BODY()
public:
	AMusicTrigger();
	
	UPROPERTY(EditAnywhere)		FString		Song;					//var() FString Song;
	UPROPERTY(EditAnywhere)		float		FadeInTime;				//var() float FadeInTime;
	UPROPERTY(EditAnywhere)		float		FadeOutTime;			//var() float FadeOutTime;
	UPROPERTY(EditAnywhere)		bool		FadeOutAllSongs;		//var() bool FadeOutAllSongs;
	UPROPERTY()					bool		Triggered;				//var transient bool Triggered;
	UPROPERTY()					int32		SongHandle;				//var transient int32 SongHandle;

	void Trigger(AActor* Other, APawn* EventInstigator);
};
