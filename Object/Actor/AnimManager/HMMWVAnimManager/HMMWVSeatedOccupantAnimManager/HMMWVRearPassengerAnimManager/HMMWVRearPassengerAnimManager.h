// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVSeatedOccupantAnimManager.h"
#include "HMMWVRearPassengerAnimManager.generated.h"

UCLASS()
class AHMMWVRearPassengerAnimManager : public AHMMWVSeatedOccupantAnimManager
{
	GENERATED_BODY()
public:
	AHMMWVRearPassengerAnimManager();
};
