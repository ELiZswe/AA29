// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/AGP_VoiceChatReplicationInfo/TeamVoiceChatReplicationInfo/TeamVoiceChatReplicationInfo.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/VoiceChatRoom.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/AGP_ChatRoom/AGP_TeamChatRoom/AGP_TeamChatRoom.h"

ATeamVoiceChatReplicationInfo::ATeamVoiceChatReplicationInfo()
{
	PublicChannelNames = {
		"Public",
		"Local",
		"Team",
	};
	//ChatRoomClass = AAGP_TeamChatRoom::StaticClass();
	DefaultChannel = 2;
}
/*
replication
{
	reliable if (((Role == ROLE_Authority) && (bNetDirty || bNetInitial)))
		RedTeamMask, BlueTeamMask, bTeamChatOnly;
}
*/

void ATeamVoiceChatReplicationInfo::InitChannels()
{
	AVoiceChatRoom* TeamVCR = nullptr;
	/*
	Super::InitChannels();
	TeamVCR = AddVoiceChannel();
	if (TeamVCR != nullptr)
	{
		TeamVCR.SetTeam(0);
	}
	TeamVCR = AddVoiceChannel();
	if (TeamVCR != nullptr)
	{
		TeamVCR.SetTeam(1);
	}
	*/
}

bool ATeamVoiceChatReplicationInfo::ValidRoom(AVoiceChatRoom* Room)
{
	return (((bEnableVoiceChat && (Room != nullptr)) && (Room->ChannelIndex < 4)) && (Room->GetOwner() == this));
}

void ATeamVoiceChatReplicationInfo::SetMask(AVoiceChatRoom* Room, int32 NewMask)
{
	if (!ValidRoom(Room))
	{
		return;
	}
	if (Room->ChannelIndex == 2)
	{
		RedTeamMask = NewMask;
	}
	else
	{
		if (Room->ChannelIndex == 3)
		{
			BlueTeamMask = NewMask;
		}
		else
		{
			Super::SetMask(Room, NewMask);
		}
	}
}

int32 ATeamVoiceChatReplicationInfo::GetMask(AVoiceChatRoom* Room)
{
	if (!ValidRoom(Room))
	{
		return 0;
	}
	if (Room->ChannelIndex == 2)
	{
		return RedTeamMask;
	}
	if (Room->ChannelIndex == 3)
	{
		return BlueTeamMask;
	}
	return Super::GetMask(Room);
}

int32 ATeamVoiceChatReplicationInfo::GetChannelIndex(FString ChannelTitle, int32 TeamIndex)
{
	int32 i = 0;
	if (ChannelTitle != "")
	{
		/*
		for (i = 0; i < Channels.Num(); i++)
		{
			if (((Channels[i] != nullptr) && (Channels[i].GetTitle() ~= ChannelTitle)) && (Channels[i].GetTeam() == TeamIndex))
			{
				return Channels[i].ChannelIndex;
			}
		}
		*/
	}
	//return Super::GetChannelIndex(ChannelTitle, TeamIndex);
	return false;    //FAKE  /ELiZ
}

AVoiceChatRoom* ATeamVoiceChatReplicationInfo::GetChannel(FString ChatRoomName, int32 TeamIndex)
{
	int32 i = 0;
	/*
	for (i = 0; i < Channels.Num(); i++)
	{
		if ((((Channels[i] != nullptr) && (Channels[i].GetTitle() ~= ChatRoomName)) && (Channels[i].Owner != nullptr)) && (Channels[i].GetTeam() == TeamIndex))
		{
			return Channels[i];
		}
	}
	return Super::GetChannel(ChatRoomName, TeamIndex);
	*/
	return nullptr;   //FAKE   /EliZ
}

uint8 ATeamVoiceChatReplicationInfo::JoinChannel(FString ChannelTitle, AAA2_PlayerState* PRI, FString Password)
{
	AVoiceChatRoom* VCR = nullptr;
	int32 i = 0;
	if ((PRI != nullptr) || (PRI->Team == nullptr))
	{
		return 0;
	}
	VCR = GetChannel(ChannelTitle, PRI->Team->TeamIndex);
	if (VCR == nullptr)
	{
		return 0;
	}
	if (VCR->GetTeam() != PRI->Team->TeamIndex)
	{
		if (VCR->IsTeamChannel())
		{
			return 6;
		}
		i = GetPublicChannelCount(false);
		if (bTeamChatOnly && (VCR->ChannelIndex > i))
		{
			return 6;
		}
	}
	return VCR->JoinChannel(PRI, Password);
}

uint8 ATeamVoiceChatReplicationInfo::JoinChannelAt(int32 ChannelIndex, AAA2_PlayerState* PRI, FString Password)
{
	AVoiceChatRoom* VCR = nullptr;
	int32 i = 0;
	if ((PRI == nullptr) || (PRI->Team == nullptr))
	{
		return 0;
	}
	VCR = GetChannelAt(ChannelIndex);
	if (VCR->GetTeam() != PRI->Team->TeamIndex)
	{
		if (VCR->IsTeamChannel())
		{
			return 6;
		}
		i = GetPublicChannelCount(false);
		if (bTeamChatOnly && (VCR->ChannelIndex > i))
		{
			return 6;
		}
	}
	return VCR->JoinChannel(PRI, Password);
}

void ATeamVoiceChatReplicationInfo::NotifyTeamChange(AAA2_PlayerState* PRI, int32 TeamIndex)
{
	int32 i = 0;
	int32 j = 0;
	int32 idx = 0;
	/*
	if (Role < 4)
	{
		return;
	}
	j = GetPublicChannelCount();
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i] == nullptr)
		{
		}
		if (Channels[i].ChannelIndex == -1)
		{
			Log(string(Name) @ "NotifyTeamChange" @ FString::FromInt(i) @ FString::FromInt(Channels[i].Name) @ Channels[i].GetTitle() @ "index is -1!", "VoiceChat");
		}
		else
		{
			if (Channels[i].ChannelIndex < j)
			{
				if (Channels[i].NotifyTeamChange(PRI, TeamIndex))
				{
					idx = GetOpposingTeamChannel(Channels[i].ChannelIndex);
					Level.Game.ChangeVoiceChannel(PRI, Channels[i].ChannelIndex, idx);
					if (((Cast<APlayerController>(PRI.Owner) != nullptr) && (Cast<APlayerController>(PRI.Owner).ActiveRoom != nullptr)) && (Cast<APlayerController>(PRI.Owner).ActiveRoom.ChannelIndex == idx))
					{
						Cast<APlayerController>(PRI.Owner).ActiveRoom = Channels[i];
						Cast<APlayerController>(PRI.Owner).ClientSetActiveRoom(Channels[i].ChannelIndex);
					}
				}
			}
			else
			{
				if (((bTeamChatOnly && Channels[i].IsMember(PRI)) && (Channels[i].GetTeam() != TeamIndex)) && (Channels[i].Owner != PRI))
				{
					Level.Game.ChangeVoiceChannel(PRI, -1, Channels[i].ChannelIndex);
				}
			}
		}
	}
	*/
}

FString ATeamVoiceChatReplicationInfo::GetTitle(AVoiceChatRoom* Room)
{
	int32 i = 0;
	int32 idx = 0;
	/*
	if (!ValidRoom(Room))
	{
		return Super::GetTitle(Room);
	}
	idx = Room.ChannelIndex;
	if (idx >= PublicChannelNames.Num())
	{
		i = (PublicChannelNames.Num() - 2);
		(idx -= i);
	}
	return PublicChannelNames[idx];
	*/
	return "FAKE";    //FAKE  /EliZ
}

int32 ATeamVoiceChatReplicationInfo::GetOpposingTeamChannel(int32 ChannelIndex)
{
	int32 i = 0;
	int32 cnt = 0;
	AVoiceChatRoom* Room = nullptr;
	Room = GetChannelAt(ChannelIndex);
	cnt = GetPublicChannelCount(false);
	/*
	for (i = 0; i < cnt; i++)
	{
		if (((Channels[i] != nullptr) && (Channels[i] != Room)) && (Channels[i].GetTitle() == Room.GetTitle()))
		{
			return Channels[i].ChannelIndex;
		}
	}
	*/
	return -1;
}
