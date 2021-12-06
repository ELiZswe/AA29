// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Volume/AA2_Volume.h"
#include "TriggeredPlayerBlockingVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATriggeredPlayerBlockingVolume : public AAA2_Volume
{
	GENERATED_BODY()
public:
	ATriggeredPlayerBlockingVolume();

	UPROPERTY(EditAnywhere)											int32 BlockTeam;				//var() int BlockTeam;

	//From Playerblockingvolume
	UPROPERTY(EditAnywhere)											bool bBlockOnStart;				//var() bool bBlockOnStart;

	//From BlockingVolume
	UPROPERTY(EditAnywhere)											TArray<AActor*> BlockedClasses;			//var() array<class<Actor> > BlockedClasses;
	UPROPERTY(EditAnywhere)											bool bClassBlocker;						//var() bool bClassBlocker;
	UPROPERTY(EditAnywhere)											bool bClampFluid;						//var() bool bClampFluid;

};
