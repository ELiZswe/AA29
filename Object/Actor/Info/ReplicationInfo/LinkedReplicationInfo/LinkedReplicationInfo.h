// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/ReplicationInfo.h"
#include "LinkedReplicationInfo.generated.h"

UCLASS()
class ALinkedReplicationInfo : public AReplicationInfo
{
	GENERATED_BODY()
public:
	ALinkedReplicationInfo();
	
	UPROPERTY()				ALinkedReplicationInfo*		NextReplicationInfo;							//var ALinkedReplicationInfo* NextReplicationInfo;
};
