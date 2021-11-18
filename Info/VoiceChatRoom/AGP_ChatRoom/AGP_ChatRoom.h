// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/VoiceChatRoom/VoiceChatRoom.h"
#include "AGP_ChatRoom.generated.h"

class AGameReplicationInfo;

/**
 * 
 */
UCLASS()
class AA29_API AAGP_ChatRoom : public AVoiceChatRoom
{
	GENERATED_BODY()
public:
	AAGP_ChatRoom();


	void SetGRI(AGameReplicationInfo* InGRI);
	void Timer();
	void PostNetBeginPlay();
	void GetMask();
	void GetTitle();
	void GetTeam();
	FString GetPassword();
	TArray<AAA2_PlayerState*> GetMembers();
	bool IsPublicChannel();
	bool IsPrivateChannel();
	int32 Count();
	bool IsFull();
	bool IsMember(AAA2_PlayerState* PRI, bool bNoCascade);
	void CanJoinChannel(AAA2_PlayerState* PRI);
	int32 JoinChannel(AAA2_PlayerState* NewPRI, FString InPassword);
	void LeaveChannel(AAA2_PlayerState* LeavingPRI);
	void AddMember(AAA2_PlayerState* PRI);
	void RemoveMember(AAA2_PlayerState* PRI);
	bool IsBanned(AAA2_PlayerState* PRI);
	void SetTeam(int32 NewTeam);
	void SetMask(int32 NewMask);
	void AddChild(AVoiceChatRoom* NewChild);
	void RemoveChild(AVoiceChatRoom* Child);
};
