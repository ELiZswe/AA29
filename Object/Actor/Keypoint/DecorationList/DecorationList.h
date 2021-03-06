// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/Keypoint.h"
#include "DecorationList.generated.h"

UCLASS()
class ADecorationList : public AKeypoint
{
	GENERATED_BODY()
public:
	ADecorationList(const FObjectInitializer& objectInitializer);

	UPROPERTY(EditAnywhere, Category="List")						TArray<FDecorationType> Decorations;		//var(List) array<DecorationType> Decorations;
};
