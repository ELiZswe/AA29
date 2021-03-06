// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/VoiceChatReplicationInfo.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/VoiceChatRoom.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"

AVoiceChatReplicationInfo::AVoiceChatReplicationInfo()
{
	VCDescText.SetNum(6);
	VCDisplayText.SetNum(6);
	PublicChannelNames = {
		"Public",
		"Local"
	};

	VCDisplayText = {
		"Enable Voice Chat",
		"Enable local Channel",
		"Local Chat Range",
		"Local Chat Radius",
		"Allowed VoIP Codecs",
		"Allowed VoIP LAN Codecs"
	};

	VCDescText = {
		"Enable voice chat on the server.",
		"Determines whether the \"local\" voice chat channel is created, which allows players to broadcast voice transmissions to all players in the immediate vicinity.",
		"Maximum distance at which a broadcast on the local channel may be heard",
		"Distance at which local broadcasts begin to fade",
		"Configure which codecs exist on the server and should be used in Internet games.",
		"Configure which codecs exist on the server and should be used in LAN games."
	};
	//ChatRoomClass = AVoiceChatRoom::StaticClass();

	InstalledCodec = {
		FVoiceChatCodec({ "CODEC_48NB","Less Bandwidth","(4.8kbps) - Uses less bandwidth, but sound is not as clear." }),
		FVoiceChatCodec({ "CODEC_96WB","Better Quality","(9.6kbps) - Uses more bandwidth, but sound is much clearer." })
	};
	VoIPInternetCodecs = { "CODEC_48NB" };
	VoIPLANCodecs = {
		"CODEC_48NB",
		"CODEC_96WB" 
	};
	bEnableVoiceChat = true;
	bAllowLocalBroadcast = true;
	LocalBroadcastRange = 1000;
	DefaultBroadcastRadius = 20;
	NetPriority = 3.001;
}
static const int32 NUMPROPS = 6;

/*
replication
{
	reliable if (((Role == ROLE_Authority) && bNetInitial))
		bEnableVoiceChat;
	reliable if ((((Role == ROLE_Authority) && bNetInitial) && bEnableVoiceChat))
		bPrivateChat;
	reliable if (((((Role == ROLE_Authority) && bNetInitial) && bEnableVoiceChat) && bAllowLocalBroadcast))
		BroadcastRadius;
	reliable if ((((Role == ROLE_Authority) && bNetDirty) && bEnableVoiceChat))
		PublicMask, LocalMask;
	reliable if ((((Role == ROLE_Authority) && (bNetInitial || bNetDirty)) && bEnableVoiceChat))
		DefaultChannel;
}
*/

void AVoiceChatReplicationInfo::Timer()
{
	if (bRefresh)
	{
		CheckChannels();
	}
}

void AVoiceChatReplicationInfo::PostBeginPlay()
{
	//Super::PostBeginPlay();
	if (bAllowLocalBroadcast)
	{
		//BroadcastRadius = FMin(LocalBroadcastRange,FMath::Clamp(DefaultBroadcastRadius, 10, 1000));
	}
}

void AVoiceChatReplicationInfo::PostNetBeginPlay()
{
	if (bEnableVoiceChat)
	{
		InitChannels();
		//SetTimer(1, true);
	}
}

void AVoiceChatReplicationInfo::InitChannels()
{
}

void AVoiceChatReplicationInfo::AddVoiceChatter(AAA2_PlayerState* NewPRI)
{
}

void AVoiceChatReplicationInfo::RemoveVoiceChatter(AAA2_PlayerState* PRI)
{
}

bool AVoiceChatReplicationInfo::CanJoinChannel(FString ChannelTitle, AAA2_PlayerState* PRI)
{
	return true;
}

uint8 AVoiceChatReplicationInfo::JoinChannel(FString ChannelTitle, AAA2_PlayerState* PRI, FString Password)
{
	return 0;
}

uint8 AVoiceChatReplicationInfo::JoinChannelAt(int32 ChannelIndex, AAA2_PlayerState* PRI, FString Password)
{
	return 0;
}

bool AVoiceChatReplicationInfo::LeaveChannel(FString ChannelTitle, AAA2_PlayerState* PRI)
{
	return true;
}

AVoiceChatRoom* AVoiceChatReplicationInfo::AddVoiceChannel(AAA2_PlayerState* PRI)
{
	return nullptr;
}

bool AVoiceChatReplicationInfo::RemoveVoiceChannel(AAA2_PlayerState* PRI)
{
	return true;
}

void AVoiceChatReplicationInfo::NotifyTeamChange(AAA2_PlayerState* PRI, int32 TeamIndex)
{
}

int32 AVoiceChatReplicationInfo::GetChannelCount()
{
	return 0;
}

int32 AVoiceChatReplicationInfo::GetChannelIndex(FString ChannelTitle, int32 TeamIndex)
{
	return -1;
}

AVoiceChatRoom* AVoiceChatReplicationInfo::GetChannel(FString ChatRoomName, int32 TeamIndex)
{
	return nullptr;
}

AVoiceChatRoom* AVoiceChatReplicationInfo::GetChannelAt(int32 Index)
{
	return nullptr;
}

TArray<int32> AVoiceChatReplicationInfo::GetChannelMembers(FString ChatRoomName, int32 TeamIndex)
{
	return {};    //FAKE   ELIZ
}

TArray<int32> AVoiceChatReplicationInfo::GetChannelMembersAt(int32 Index)
{
	return {};    //FAKE   ELIZ
}

TArray<int32> AVoiceChatReplicationInfo::GetMemberChannels(AAA2_PlayerState* PRI)
{
	return {};    //FAKE   ELIZ
}

FString AVoiceChatReplicationInfo::GetDefaultChannel()
{
	//return PublicChannelNames[Clamp(DefaultChannel, 0, (PublicChannelNames.Num() - 1))];
	return "FAKE";    //FAKE   ELIZ
}

TArray<AVoiceChatRoom*> AVoiceChatReplicationInfo::GetChannels()
{
	return {};    //FAKE   ELIZ
}

TArray<AVoiceChatRoom*> AVoiceChatReplicationInfo::GetPublicChannels()
{
	return {};    //FAKE   ELIZ
}

TArray<AVoiceChatRoom*> AVoiceChatReplicationInfo::GetPlayerChannels()
{
	return {};    //FAKE   ELIZ
}

int32 AVoiceChatReplicationInfo::GetPublicChannelCount(bool bSingleTeam)
{
	return 0;    //FAKE   ELIZ
}

int32 AVoiceChatReplicationInfo::GetPlayerChannelCount()
{
	return 0;    //FAKE   ELIZ
}

bool AVoiceChatReplicationInfo::IsMember(AAA2_PlayerState* TestPRI, int32 ChannelIndex, bool bNoCascade)
{
	return false;
}

AVoiceChatRoom* AVoiceChatReplicationInfo::CreateNewVoiceChannel(AAA2_PlayerState* PRI)
{
	return nullptr;
}

void AVoiceChatReplicationInfo::DestroyVoiceChannel(AVoiceChatRoom* Channel)
{
}

void AVoiceChatReplicationInfo::CheckChannels()
{
	int32 i = 0;
	/*
	for (i = (Channels.Num() - 1); i >= 0; i--)
	{
		if (Channels[i] == nullptr)
		{
			Channels.RemoveAt(i, 1);
		}
	}
	*/
	bRefresh = false;
}

void AVoiceChatReplicationInfo::FillPlayInfo(APlayInfo* PlayInfo)
{
	/*
	Super::FillPlayInfo(PlayInfo);
	PlayInfo.AddSetting(Default.ChatGroup, "bEnableVoiceChat", Default.VCDisplayText[0], 250, 1, "Check", , "Xv", true, true);
	PlayInfo.AddSetting(Default.ChatGroup, "bAllowLocalBroadcast", Default.VCDisplayText[1], 250, 1, "Check", , "Xv", true, true);
	PlayInfo.AddSetting(Default.ChatGroup, "LocalBroadcastRange", Default.VCDisplayText[2], 100, 1, "Text", "4;10:3000", "Xv", true, true);
	PlayInfo.AddSetting(Default.ChatGroup, "DefaultBroadcastRadius", Default.VCDisplayText[3], 100, 1, "Text", "4;10:1000", "Xv", true, true);
	PlayInfo.AddSetting(Default.ChatGroup, "VoIPInternetCodecs", Default.VCDisplayText[4], 254, 1, "Text", , "Xv", true, true);
	PlayInfo.AddSetting(Default.ChatGroup, "VoIPLANCodecs", Default.VCDisplayText[5], 254, 1, "Text", , "Xv", true, true);
	*/
}

FString AVoiceChatReplicationInfo::GetDescriptionText(FString PropName)
{
	/*
	switch (PropName)
	{
	case "bEnableVoiceChat":
		return Default.VCDescText[0];
	case "bAllowLocalBroadcast":
		return Default.VCDescText[1];
	case "LocalBroadcastRange":
		return Default.VCDescText[2];
	case "DefaultBroadcastRadius":
		return Default.VCDescText[3];
	case "VoIPInternetCodecs":
		return Default.VCDescText[4];
	case "VoIPLANCodecs":
		return Default.VCDescText[5];
	default:
		return Super::GetDescriptionText(PropName);
	}
	*/
	return "FAKE";     //FAKE   /ELiZ
}

void AVoiceChatReplicationInfo::GetInstalledCodecs(TArray<FString>& Codecs)
{
	int32 i = 0;
	/*
	Codecs.Num() = Default.InstalledCodec.Num();
	for (i = 0; i < Default.InstalledCodec.Num(); i++)
	{
		Codecs[i] = Default.InstalledCodec[i].Codec;
	}
	*/
}

bool AVoiceChatReplicationInfo::GetCodecInfo(FString Codec, FString& CodecName, FString& CodecDescription)
{
	int32 i = 0;
	/*
	for (i = 0; i < Default.InstalledCodec.Num(); i++)
	{
		if (Codec ~= Default.InstalledCodec[i].Codec)
		{
			CodecName = Default.InstalledCodec[i].CodecName;
			CodecDescription = Default.InstalledCodec[i].CodecDescription;
			return true;
		}
	}
	*/
	return false;
}

bool AVoiceChatReplicationInfo::ValidRoom(AVoiceChatRoom* Room)
{
	//return (((bEnableVoiceChat && (Room != nullptr)) && (Room.ChannelIndex < 2)) && (Room.Owner == this));
	return false;   //FAKE   /ELiZ
}

void AVoiceChatReplicationInfo::SetMask(AVoiceChatRoom* Room, int32 NewMask)
{
	if (!ValidRoom(Room))
	{
		return;
	}
	if (Room->ChannelIndex == 0)
	{
		PublicMask = NewMask;
	}
	else
	{
		if (Room->ChannelIndex == 1)
		{
			LocalMask = NewMask;
		}
	}
}

int32 AVoiceChatReplicationInfo::GetMask(AVoiceChatRoom* Room)
{
	if (!ValidRoom(Room))
	{
		return 0;
	}
	if (Room->ChannelIndex == 0)
	{
		return PublicMask;
	}
	if (Room->ChannelIndex == 1)
	{
		return LocalMask;
	}
	return 0;
}

FString AVoiceChatReplicationInfo::GetTitle(AVoiceChatRoom* Room)
{
	if (!ValidRoom(Room))
	{
		return "";
	}
	return PublicChannelNames[Room->ChannelIndex];
}
