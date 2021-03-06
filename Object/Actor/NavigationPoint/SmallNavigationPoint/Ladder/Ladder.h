// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/SmallNavigationPoint.h"
#include "Ladder.generated.h"

class ALadderVolume;

UCLASS()
class ALadder : public ASmallNavigationPoint
{
	GENERATED_BODY()
public:
	ALadder();

	UPROPERTY()			ALadderVolume*	MyLadder;		//var LadderVolume MyLadder;
	UPROPERTY()			ALadder*		LadderList;		//var Ladder LadderList;

	bool SuggestMovePreparation(APawn* Other);
};
