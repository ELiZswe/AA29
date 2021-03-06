// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/VoiceChatRoom.h"
#include "AGP_ChatRoom.generated.h"

class AGameReplicationInfo;
class AAA2_PlayerState;

class AVoiceChatRoom;
UCLASS()
class AAGP_ChatRoom : public AVoiceChatRoom
{
	GENERATED_BODY()
public:
	AAGP_ChatRoom();

	void SetGRI(AGameReplicationInfo* InGRI);
	void Timer();
	void PostNetBeginPlay();
	int32 GetMask();
	FString GetTitle();
	int32 GetTeam();
	FString GetPassword();
	TArray<AAA2_PlayerState*> GetMembers();
	bool IsPublicChannel();
	bool IsPrivateChannel();
	int32 Count();
	bool IsFull();
	bool IsMember(AAA2_PlayerState* PRI, bool bNoCascade);
	bool CanJoinChannel(AAA2_PlayerState* PRI);
	uint8 JoinChannel(AAA2_PlayerState* NewPRI, FString InPassword);
	bool LeaveChannel(AAA2_PlayerState* LeavingPRI);
	void AddMember(AAA2_PlayerState* PRI);
	void RemoveMember(AAA2_PlayerState* PRI);
	bool IsBanned(AAA2_PlayerState* PRI);
	void SetTeam(int32 NewTeam);
	void SetMask(int32 NewMask);
	bool AddChild(AVoiceChatRoom* NewChild);
	bool RemoveChild(AVoiceChatRoom* Child);
};
