// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"
#include "TeamPlayerReplicationInfo.generated.h"

UCLASS()
class ATeamPlayerReplicationInfo : public APlayerReplicationInfo
{
	GENERATED_BODY()
public:
	ATeamPlayerReplicationInfo();
	
};
