// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "LevelGameRules.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ALevelGameRules : public AAA2_Info
{
	GENERATED_BODY()
public:
		ALevelGameRules();

		//var() array<class<Mutator> > MapMutator;

		void PreBeginPlay();
		void UpdateGame(AGameInfo* G);

};
