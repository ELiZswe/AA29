// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AA2_Volume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAA2_Volume : public AVolume
{
	GENERATED_BODY()
public:
	AAA2_Volume();


	UPROPERTY(EditAnywhere)		FName	AssociatedActorTag;
};
