// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/AGP_VoiceChatReplicationInfo/AGP_VoiceChatReplicationInfo.h"
#include "TeamVoiceChatReplicationInfo.generated.h"

class AVoiceChatRoom;
UCLASS()
class ATeamVoiceChatReplicationInfo : public AAGP_VoiceChatReplicationInfo
{
	GENERATED_BODY()
public:
	ATeamVoiceChatReplicationInfo();
	
	UPROPERTY()					int32	RedTeamMask;				//var int32 RedTeamMask;
	UPROPERTY()					int32	BlueTeamMask;				//var int32 BlueTeamMask;
	UPROPERTY()					bool	bTeamChatOnly;				//var bool bTeamChatOnly;

	void InitChannels();
	bool ValidRoom(AVoiceChatRoom* Room);
	void SetMask(AVoiceChatRoom* Room, int32 NewMask);
	int32 GetMask(AVoiceChatRoom* Room);
	int32 GetChannelIndex(FString ChannelTitle, int32 TeamIndex);
	AVoiceChatRoom* GetChannel(FString ChatRoomName, int32 TeamIndex);
	uint8 JoinChannel(FString ChannelTitle, AAA2_PlayerState* PRI, FString Password);
	uint8 JoinChannelAt(int32 ChannelIndex, AAA2_PlayerState* PRI, FString Password);
	void NotifyTeamChange(AAA2_PlayerState* PRI, int32 TeamIndex);
	FString GetTitle(AVoiceChatRoom* Room);
	int32 GetOpposingTeamChannel(int32 ChannelIndex);
};
