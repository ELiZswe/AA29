// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/PlayerChatManager/PlayerChatManager.h"
#include "AA29/AA29.h"
#include "AGP_PlayerChatManager.generated.h"

UCLASS()
class AAGP_PlayerChatManager : public APlayerChatManager
{
	GENERATED_BODY()
public:
	AAGP_PlayerChatManager();

	UPROPERTY(globalconfig)			TArray<FStoredChatBan>				StoredChatRestrictions;			//var globalconfig TArray<StoredChatBan> StoredChatRestrictions;
	UPROPERTY()						TArray<FChatBan>					ChatRestrictions;				//var TArray<ChatBan> ChatRestrictions;

	void ChatDebug();
	void LogChatRestriction(int32 i);
	bool LoadChatBan(FString PlayerHash, uint8& OutRestriction);
	void StoreChatBan(FString PlayerHash, uint8 Restriction);
	void ReceiveBanInfo(FString S);
	void TrackNewPlayer(int32 PlayerID, FString PlayerHash, FString PlayerAddress);
	void UnTrackPlayer(int32 PlayerID);
	bool AcceptText(AAA2_PlayerState* Sender, FString& Msg, FName Type);
	bool AcceptSpeech(AAA2_PlayerState* SenderPRI);
	bool AcceptVoice(AAA2_PlayerState* SenderPRI);
	bool IsBanned(AAA2_PlayerState* PRI);
	bool SetRestriction(FString PlayerHash, uint8 Type);
	bool SetRestrictionID(int32 PlayerID, uint8 Type);
	bool AddRestriction(FString PlayerHash, uint8 Type);
	bool AddRestrictionID(int32 PlayerID, uint8 Type);
	bool ClearRestriction(FString PlayerHash, uint8 Type);
	bool ClearRestrictionID(int32 PlayerID, uint8 Type);
	bool MergeRestriction(int32 Index, uint8 NewType);
	bool UnMergeRestriction(int32 Index, uint8 NewType);
	uint8 GetPlayerRestriction(int32 PlayerID);
	bool ClientIsBanned(FString PlayerHash);
	FString GetPlayerHash(int32 PlayerID);
	int32 GetIDIndex(int32 PlayerID);
	int32 GetHashIndex(FString PlayerHash);
	bool IsValid(int32 i);
	bool IsLocal();
	int32 Count();
};
