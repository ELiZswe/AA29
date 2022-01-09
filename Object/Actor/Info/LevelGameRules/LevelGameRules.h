// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "LevelGameRules.generated.h"

class AGameInfo;

UCLASS()
class ALevelGameRules : public AAA2_Info
{
	GENERATED_BODY()
public:
	ALevelGameRules();

	//var() array<class<Mutator> > MapMutator;

	void PreBeginPlay();
	void UpdateGame(AGameInfo* G);
};
