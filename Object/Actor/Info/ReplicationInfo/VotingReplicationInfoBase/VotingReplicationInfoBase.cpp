// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ReplicationInfo/VotingReplicationInfoBase/VotingReplicationInfoBase.h"

AVotingReplicationInfoBase::AVotingReplicationInfoBase()
{

}
/*
replication
{
	reliable if ((Role == ROLE_Authority))
		SendResponse;
	reliable if ((Role < ROLE_Authority))
		SendCommand;
}
*/

void AVotingReplicationInfoBase::ProcessCommand(FString Command)
{
}

void AVotingReplicationInfoBase::ProcessResponse(FString Response)
{
}

void AVotingReplicationInfoBase::SendCommand(FString Cmd)
{
	ProcessCommand(Cmd);
}

void AVotingReplicationInfoBase::SendResponse(FString Response)
{
	ProcessResponse(Response);
}

bool AVotingReplicationInfoBase::MatchSetupLocked()
{
	return false;
}

bool AVotingReplicationInfoBase::MapVoteEnabled()
{
	return false;
}

bool AVotingReplicationInfoBase::KickVoteEnabled()
{
	return false;
}

bool AVotingReplicationInfoBase::MatchSetupEnabled()
{
	return false;
}
