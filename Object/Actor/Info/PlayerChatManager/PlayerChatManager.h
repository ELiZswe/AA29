// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "PlayerChatManager.generated.h"

class AAA2_PlayerState;
class ALocalMessage;

UCLASS()
class APlayerChatManager : public AAA2_Info
{
	GENERATED_BODY()
public:
	APlayerChatManager();
	
	UPROPERTY()		APlayerController*		PlayerOwner;			//var PlayerController PlayerOwner;

	void PostBeginPlay();
	void ReceiveBanInfo(FString S);
	void TrackNewPlayer(int32 PlayerID, FString PlayerHash, FString PlayerAddress);
	void UnTrackPlayer(int32 PlayerID);
	bool AcceptText(AAA2_PlayerState* Sender, FString& Msg, FName Type);
	bool AcceptLocalized(AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* obj);
	bool AcceptSpeech(AAA2_PlayerState* Sender);
	bool AcceptVoice(AAA2_PlayerState* Sender);
	bool SetRestriction(FString PlayerHash, uint8 Type);
	bool SetRestrictionID(int32 PlayerID, uint8 Type);
	bool AddRestriction(FString PlayerHash, uint8 Type);
	bool AddRestrictionID(int32 PlayerID, uint8 Type);
	bool ClearRestriction(FString PlayerHash, uint8 Type);
	bool ClearRestrictionID(int32 PlayerID, uint8 Type);
	bool IsBanned(AAA2_PlayerState* PRI);
	bool ClientIsBanned(FString PlayerHash);
	uint8 GetPlayerRestriction(int32 PlayerID);
	int32 Count();
	void ChatDebug();
};
