// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/PlayerChatManager/PlayerChatManager.h"

APlayerChatManager::APlayerChatManager()
{
	//RemoteRole = ROLE_SimulatedProxy;
}

void APlayerChatManager::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	if (Cast<APlayerController>(GetOwner()) == nullptr)
	{
		Destroy();
	}
	if (bDeleteMe)
	{
		return;
	}
	PlayerOwner = Cast<APlayerController>(GetOwner());
	*/
}

void APlayerChatManager::ReceiveBanInfo(FString S)
{
}

void APlayerChatManager::TrackNewPlayer(int32 PlayerID, FString PlayerHash, FString PlayerAddress)
{
}

void APlayerChatManager::UnTrackPlayer(int32 PlayerID)
{
}

bool APlayerChatManager::AcceptText(AAA2_PlayerState* Sender, FString& Msg, FName Type)
{
	return true;
}

bool APlayerChatManager::AcceptLocalized(AActor* Sender,ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* obj)
{
	return true;
}

bool APlayerChatManager::AcceptSpeech(AAA2_PlayerState* Sender)
{
	return true;
}

bool APlayerChatManager::AcceptVoice(AAA2_PlayerState* Sender)
{
	return true;
}

bool APlayerChatManager::SetRestriction(FString PlayerHash, uint8 Type)
{
	return true;
}

bool APlayerChatManager::SetRestrictionID(int32 PlayerID, uint8 Type)
{
	return true;
}

bool APlayerChatManager::AddRestriction(FString PlayerHash, uint8 Type)
{
	return true;
}

bool APlayerChatManager::AddRestrictionID(int32 PlayerID, uint8 Type)
{
	return true;
}

bool APlayerChatManager::ClearRestriction(FString PlayerHash, uint8 Type)
{
	return true;
}

bool APlayerChatManager::ClearRestrictionID(int32 PlayerID, uint8 Type)
{
	return true;
}

bool APlayerChatManager::IsBanned(AAA2_PlayerState* PRI)
{
	return false;
}

bool APlayerChatManager::ClientIsBanned(FString PlayerHash)
{
	return false;
}

uint8 APlayerChatManager::GetPlayerRestriction(int32 PlayerID)
{
	return 0;
}

int32 APlayerChatManager::Count()
{
	return 0;
}

void APlayerChatManager::ChatDebug()
{
}
