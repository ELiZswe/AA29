// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Volume/PhysicsVolume/AA2_PhysicsVolume.h"
#include "WaterVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWaterVolume : public AAA2_PhysicsVolume
{
	GENERATED_BODY()
public:
	AWaterVolume();

	UPROPERTY()			FString PawnEntryActorName;		       	//var string PawnEntryActorName;
	UPROPERTY()			FString EntryActorName;		        	//var string EntryActorName;
	UPROPERTY()			FString ExitSoundName;		        	//var string ExitSoundName;
	UPROPERTY()			FString EntrySoundName;		        	//var string EntrySoundName;

	void PostBeginPlay();
};
