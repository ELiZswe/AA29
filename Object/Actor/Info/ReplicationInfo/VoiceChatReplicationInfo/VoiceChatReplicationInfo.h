// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/ReplicationInfo.h"
#include "AA29/AA29.h"
#include "VoiceChatReplicationInfo.generated.h"

class AVoiceChatRoom;
class AGameReplicationInfo;
class APlayInfo;

UCLASS()
class AVoiceChatReplicationInfo : public AReplicationInfo
{
	GENERATED_BODY()
public:
	AVoiceChatReplicationInfo();

	UPROPERTY()					int32						PublicMask;					//var int32 PublicMask;
	UPROPERTY()					int32						LocalMask;					//var int32 LocalMask;
	UPROPERTY()					TArray<AVoiceChatRoom*>		Channels;					//var TArray<VoiceChatRoom> Channels;
	UPROPERTY()					TArray<FString>				PublicChannelNames;			//var localized TArray<FString> PublicChannelNames;
	UPROPERTY()					TArray<FString>				VCDisplayText;				//var localized FString VCDisplayText[6];
	UPROPERTY()					TArray<FString>				VCDescText;					//var localized FString VCDescText[6];
	UPROPERTY()					AGameReplicationInfo*		GRI;						//var GameReplicationInfo GRI;
	UPROPERTY()					AVoiceChatRoom*				ChatRoomClass;				//var class<VoiceChatRoom> ChatRoomClass;
	UPROPERTY()					TArray<FVoiceChatCodec>		InstalledCodec;				//var TArray<VoiceChatCodec> InstalledCodec;
	UPROPERTY(globalconfig)		TArray<FString>				VoIPInternetCodecs;			//var globalconfig TArray<FString> VoIPInternetCodecs;
	UPROPERTY(globalconfig)		TArray<FString>				VoIPLANCodecs;				//var globalconfig TArray<FString> VoIPLANCodecs;
	UPROPERTY(globalconfig)		bool						bEnableVoiceChat;			//var globalconfig bool bEnableVoiceChat;
	UPROPERTY(globalconfig)		bool						bAllowLocalBroadcast;		//var globalconfig bool bAllowLocalBroadcast;
	UPROPERTY(globalconfig)		int32						MaxChatters;				//var globalconfig int32 MaxChatters;
	UPROPERTY()					int32						DefaultChannel;				//var int32 DefaultChannel;
	UPROPERTY(globalconfig)		float						LocalBroadcastRange;		//var globalconfig float LocalBroadcastRange;
	UPROPERTY(globalconfig)		float						DefaultBroadcastRadius;		//var globalconfig float DefaultBroadcastRadius;
	UPROPERTY()					float						BroadcastRadius;			//var float BroadcastRadius;
	UPROPERTY()					bool						bPrivateChat;				//var bool bPrivateChat;
	UPROPERTY()					bool						bRefresh;					//var bool bRefresh;

	void Timer();
	void PostBeginPlay();
	void PostNetBeginPlay();
	void InitChannels();
	void AddVoiceChatter(AAA2_PlayerState* NewPRI);
	void RemoveVoiceChatter(AAA2_PlayerState* PRI);
	bool CanJoinChannel(FString ChannelTitle, AAA2_PlayerState* PRI);
	uint8 JoinChannel(FString ChannelTitle, AAA2_PlayerState* PRI, FString Password);
	uint8 JoinChannelAt(int32 ChannelIndex, AAA2_PlayerState* PRI, FString Password);
	bool LeaveChannel(FString ChannelTitle, AAA2_PlayerState* PRI);
	AVoiceChatRoom* AddVoiceChannel(AAA2_PlayerState* PRI);
	bool RemoveVoiceChannel(AAA2_PlayerState* PRI);
	void NotifyTeamChange(AAA2_PlayerState* PRI, int32 TeamIndex);
	int32 GetChannelCount();
	int32 GetChannelIndex(FString ChannelTitle, int32 TeamIndex);
	AVoiceChatRoom* GetChannel(FString ChatRoomName, int32 TeamIndex);
	AVoiceChatRoom* GetChannelAt(int32 Index);
	TArray<int32> GetChannelMembers(FString ChatRoomName, int32 TeamIndex);
	TArray<int32>  GetChannelMembersAt(int32 Index);
	TArray<int32>  GetMemberChannels(AAA2_PlayerState* PRI);
	FString GetDefaultChannel();
	TArray<AVoiceChatRoom*> GetChannels();
	TArray<AVoiceChatRoom*> GetPublicChannels();
	TArray<AVoiceChatRoom*> GetPlayerChannels();
	int32 GetPublicChannelCount(bool bSingleTeam);
	int32 GetPlayerChannelCount();
	bool IsMember(AAA2_PlayerState* TestPRI, int32 ChannelIndex, bool bNoCascade);
	AVoiceChatRoom* CreateNewVoiceChannel(AAA2_PlayerState* PRI);
	void DestroyVoiceChannel(AVoiceChatRoom* Channel);
	void CheckChannels();
	void FillPlayInfo(APlayInfo* PlayInfo);
	FString GetDescriptionText(FString PropName);
	void GetInstalledCodecs(TArray<FString>& Codecs);
	bool GetCodecInfo(FString Codec, FString& CodecName, FString& CodecDescription);
	bool ValidRoom(AVoiceChatRoom* Room);
	void SetMask(AVoiceChatRoom* Room, int32 NewMask);
	int32 GetMask(AVoiceChatRoom* Room);
	FString GetTitle(AVoiceChatRoom* Room);
};
