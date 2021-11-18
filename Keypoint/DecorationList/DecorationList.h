// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/Keypoint.h"
#include "DecorationList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADecorationList : public AKeypoint
{
	GENERATED_BODY()
public:
	ADecorationList(const FObjectInitializer& objectInitializer);

	//UPROPERTY(EditEverywhere, Category="List")						TArray<ADecorationType*> Decorations;		//var(List) array<DecorationType> Decorations;
};
