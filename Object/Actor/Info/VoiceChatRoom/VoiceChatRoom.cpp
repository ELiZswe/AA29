// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/VoiceChatRoom/VoiceChatRoom.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/VoiceChatReplicationInfo.h"

AVoiceChatRoom::AVoiceChatRoom()
{
	ChannelIndex = -1;
	TeamIndex = 255;
}

TArray<AAA2_PlayerState*> AVoiceChatRoom::GetMembers()
{
	return {};    //FAKE    /ELiZ
}
int32 AVoiceChatRoom::GetMaxChatters()
{
	//return VoiceChatManager.MaxChatters;
	return 0;    //FAKE    /ELiZ
}

int32 AVoiceChatRoom::GetMask()
{
	return 0;
}

FString AVoiceChatRoom::GetPassword()
{
	return "";
}

bool AVoiceChatRoom::ValidMask()
{
	//return GetMask() > 0;
	return true;    //FAKE   /ELiZ
}

FString AVoiceChatRoom::GetTitle()
{
	return "";
}

int32 AVoiceChatRoom::GetTeam()
{
	return TeamIndex;
}

bool AVoiceChatRoom::IsPublicChannel()
{
	return true;
}

bool AVoiceChatRoom::IsTeamChannel()
{
	return false;
}

bool AVoiceChatRoom::IsPrivateChannel()
{
	return false;
}

bool AVoiceChatRoom::CanJoinChannel(AAA2_PlayerState* PRI)
{
	return true;
}

bool AVoiceChatRoom::IsFull()
{
	return false;
}

bool AVoiceChatRoom::IsMember(AAA2_PlayerState* PRI, bool bNoCascade)
{
	/*
	int32 i = 0;
	if (bNoCascade)
	{
		return false;
	}
	for (i = 0; i < AA2_Children.Num(); i++)
	{
		if (AA2_Children[i] != nullptr && AA2_Children[i].IsMember(PRI))
		{
			return true;
		}
	}
	*/
	return false;
}

uint8 AVoiceChatRoom::JoinChannel(AAA2_PlayerState* NewPRI, FString InPassword)
{
	return 7;
}

bool AVoiceChatRoom::LeaveChannel(AAA2_PlayerState* LeavingPRI)
{
	return true;
}

void AVoiceChatRoom::AddMember(AAA2_PlayerState* PRI)
{
}

void AVoiceChatRoom::RemoveMember(AAA2_PlayerState* PRI)
{
}

void AVoiceChatRoom::SetTeam(int32 NewTeam)
{
	TeamIndex = NewTeam;
}

void AVoiceChatRoom::SetMemberMask(int32 NewMask)
{
}

void AVoiceChatRoom::SetChannelPassword(FString InPassword)
{
	Password = InPassword;
}

bool AVoiceChatRoom::AddChild(AVoiceChatRoom* NewChild)
{
	return true;
}

bool AVoiceChatRoom::RemoveChild(AVoiceChatRoom* Child)
{
	return false;
}

bool AVoiceChatRoom::NotifyTeamChange(AAA2_PlayerState* PRI, int32 NewTeamIndex)
{
	return false;
}
