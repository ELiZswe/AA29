// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/Keypoint.h"
#include "BlockPlayer.generated.h"

UCLASS()
class ABlockPlayer : public AKeypoint
{
	GENERATED_BODY()
public:
	ABlockPlayer(const FObjectInitializer& objectInitializer);

	//bBlockPlayers = true;
	//bObsolete = true;
};
