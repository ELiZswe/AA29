// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/VoiceChatRoom/AGP_ChatRoom/AGP_TeamChatRoom/AGP_TeamChatRoom.h"

AAGP_TeamChatRoom::AAGP_TeamChatRoom()
{

}

bool AAGP_TeamChatRoom::IsTeamChannel()
{
	//return ((VoiceChatReplicationInfo(Owner) != None) && (!IsPublicChannel()));
	return false;    //FAKE   /EliZ
}

bool AAGP_TeamChatRoom::CanJoinChannel(AAA2_PlayerState* PRI)
{
	/*
	if (!Super::CanJoinChannel(PRI))
	{
		return false;
	}
	if (PRI.Team == None)
	{
		Log("CanJoinChannel returning false PRI.Team == None", "VoiceChat");
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
		if (TeamVoiceChatReplicationInfo(VoiceChatManager).bTeamChatOnly)
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
		Other = VoiceChatManager.GetChannelAt(TeamVoiceChatReplicationInfo(VoiceChatManager).GetOpposingTeamChannel(ChannelIndex));
		if (Other != None)
		{
			return Other.IsMember(PRI);
		}
	}
	return Super::NotifyTeamChange(PRI, NewTeamIndex);
	*/
	return false;    //FAKE   /EliZ
}

