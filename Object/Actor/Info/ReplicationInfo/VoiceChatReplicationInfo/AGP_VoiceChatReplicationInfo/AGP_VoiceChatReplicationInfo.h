// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/VoiceChatReplicationInfo.h"
#include "AGP_VoiceChatReplicationInfo.generated.h"

class AAGP_ChatHandler;

class AGameReplicationInfo;
class AVoiceChatRoom;
UCLASS()
class AAGP_VoiceChatReplicationInfo : public AVoiceChatReplicationInfo
{
	GENERATED_BODY()
public:
	AAGP_VoiceChatReplicationInfo();

	UPROPERTY()			AAGP_ChatHandler*			ChatBroadcastClass;					//var() class<AGP_ChatHandler> ChatBroadcastClass;
	UPROPERTY()			AAGP_ChatHandler*			ChatBroadcastHandler;					//var AGP_ChatHandler ChatBroadcastHandler;

	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	void PostBeginPlay();
	void PostNetBeginPlay();
	void SetGRI(AGameReplicationInfo* NewGRI);
	void InitChannels();
	void AddVoiceChatter(AAA2_PlayerState* NewPRI);
	void RemoveVoiceChatter(AAA2_PlayerState* PRI);
	bool CanJoinChannel(FString ChannelTitle, AAA2_PlayerState* PRI);
	uint8 JoinChannel(FString ChannelTitle, AAA2_PlayerState* PRI, FString Password);
	uint8 JoinChannelAt(int32 ChannelIndex, AAA2_PlayerState* PRI, FString Password);
	bool LeaveChannel(FString ChannelTitle, AAA2_PlayerState* PRI);
	AVoiceChatRoom* AddVoiceChannel(AAA2_PlayerState* PRI);
	bool RemoveVoiceChannel(AAA2_PlayerState* PRI);
	AVoiceChatRoom* GetChannel(FString ChatRoomName, int32 TeamIndex);
	AVoiceChatRoom* GetChannelAt(int32 Index);
	TArray<int32> GetChannelMembers(FString ChatRoomName, int32 TeamIndex);
	TArray<int32> GetChannelMembersAt(int32 Index);
	TArray<int32> GetMemberChannels(AAA2_PlayerState* PRI);
	TArray<AVoiceChatRoom*> GetChannels();
	int32 GetChannelCount();
	int32 GetChannelIndex(FString ChannelTitle, int32 TeamIndex);
	TArray<AVoiceChatRoom*> GetPublicChannels();
	TArray<AVoiceChatRoom*> GetPlayerChannels();
	int32 GetPublicChannelCount(bool bSingleTeam);
	int32 GetPlayerChannelCount();
	bool IsMember(AAA2_PlayerState* TestPRI, int32 ChannelIndex, bool bNoCascade);
	AVoiceChatRoom* CreateNewVoiceChannel(AAA2_PlayerState* PRI);
	void DestroyVoiceChannel(AVoiceChatRoom* Channel);
};
