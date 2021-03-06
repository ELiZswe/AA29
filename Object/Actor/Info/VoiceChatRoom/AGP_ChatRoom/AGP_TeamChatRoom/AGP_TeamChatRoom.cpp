// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/VoiceChatRoom/AGP_ChatRoom/AGP_TeamChatRoom/AGP_TeamChatRoom.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/VoiceChatRoom.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/AGP_VoiceChatReplicationInfo/TeamVoiceChatReplicationInfo/TeamVoiceChatReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/VoiceChatReplicationInfo.h"

AAGP_TeamChatRoom::AAGP_TeamChatRoom()
{

}

bool AAGP_TeamChatRoom::IsTeamChannel()
{
	//return ((Cast<AVoiceChatReplicationInfo>(GetOwner()) != nullptr) && (!IsPublicChannel()));
	return false;    //FAKE   /EliZ
}

bool AAGP_TeamChatRoom::CanJoinChannel(AAA2_PlayerState* PRI)
{
	/*
	if (!Super::CanJoinChannel(PRI))
	{
		return false;
	}
	if (PRI.Team == nullptr)
	{
		Log("CanJoinChannel returning false PRI.Team == nullptr", "VoiceChat");
		return false;
	}
	if (GetTeam() != PRI.Team.TeamIndex)
	{
		if (IsPublicChannel())
		{
			return true;
		}
		if (IsTeamChannel())
		{
			return false;
		}
		if (Cast<ATeamVoiceChatReplicationInfo>(VoiceChatManager).bTeamChatOnly)
		{
			return false;
		}
	}
	*/
	return true;
}

bool AAGP_TeamChatRoom::NotifyTeamChange(AAA2_PlayerState* PRI, int32 NewTeamIndex)
{
	AVoiceChatRoom* Other = nullptr;
	/*
	if (IsPublicChannel())
	{
		return false;
	}
	if (GetTeam() != NewTeamIndex)
	{
		return false;
	}
	if (IsMember(PRI))
	{
		return false;
	}
	if (IsTeamChannel())
	{
		Other = VoiceChatManager.GetChannelAt(Cast<ATeamVoiceChatReplicationInfo>(VoiceChatManager).GetOpposingTeamChannel(ChannelIndex));
		if (Other != nullptr)
		{
			return Other.IsMember(PRI);
		}
	}
	return Super::NotifyTeamChange(PRI, NewTeamIndex);
	*/
	return false;    //FAKE   /EliZ
}

