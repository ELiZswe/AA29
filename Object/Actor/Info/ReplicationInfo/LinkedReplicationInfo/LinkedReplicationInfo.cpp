// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ReplicationInfo/LinkedReplicationInfo/LinkedReplicationInfo.h"

ALinkedReplicationInfo::ALinkedReplicationInfo()
{
	NetUpdateFrequency = 1;
}

/*
replication
{
	reliable if ((bNetInitial && (Role == ROLE_Authority)))
		NextReplicationInfo;
}
*/
