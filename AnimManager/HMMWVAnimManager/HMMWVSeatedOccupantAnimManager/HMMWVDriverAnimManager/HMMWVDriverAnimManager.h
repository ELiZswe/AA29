// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVSeatedOccupantAnimManager.h"
#include "HMMWVDriverAnimManager.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHMMWVDriverAnimManager : public AHMMWVSeatedOccupantAnimManager
{
	GENERATED_BODY()
public:
	AHMMWVDriverAnimManager();
};
