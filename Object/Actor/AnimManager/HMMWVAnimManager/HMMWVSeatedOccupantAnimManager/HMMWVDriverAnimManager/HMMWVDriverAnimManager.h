// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVSeatedOccupantAnimManager.h"
#include "HMMWVDriverAnimManager.generated.h"

UCLASS()
class AHMMWVDriverAnimManager : public AHMMWVSeatedOccupantAnimManager
{
	GENERATED_BODY()
public:
	AHMMWVDriverAnimManager();
};
