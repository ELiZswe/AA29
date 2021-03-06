// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/ReplicationInfo.h"
#include "VotingReplicationInfoBase.generated.h"

UCLASS()
class AVotingReplicationInfoBase : public AReplicationInfo
{
	GENERATED_BODY()
public:
	AVotingReplicationInfoBase();

	void ProcessCommand(FString Command);
	void ProcessResponse(FString Response);
	void SendCommand(FString Cmd);
	void SendResponse(FString Response);
	bool MatchSetupLocked();
	bool MapVoteEnabled();
	bool KickVoteEnabled();
	bool MatchSetupEnabled();
};
