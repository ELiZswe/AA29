// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/MessagingSpectator/MessagingSpectator.h"

AMessagingSpectator::AMessagingSpectator()
{

}

/*
auto State NotPlaying
{
}
*/

void AMessagingSpectator::PostBeginPlay()
{
	//Super::PostBeginPlay();
	//bIsPlayer = false;
}

void AMessagingSpectator::InitPlayerReplicationInfo()
{
	//Super::InitPlayerReplicationInfo();
	/*
	PlayerReplicationInfo->PlayerName = "WebAdmin";
	PlayerReplicationInfo->bIsSpectator = true;
	PlayerReplicationInfo->bOnlySpectator = true;
	PlayerReplicationInfo->bOutOfLives = true;
	PlayerReplicationInfo->bWaitingPlayer = false;
	*/
}
