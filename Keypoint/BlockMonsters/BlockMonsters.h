// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/Keypoint.h"
#include "BlockMonsters.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABlockMonsters : public AKeypoint
{
	GENERATED_BODY()
public:
	ABlockMonsters(const FObjectInitializer& objectInitializer);

	//bCollideActors = true;
	//bBlockActors = true;
	//bObsolete = true;
};
