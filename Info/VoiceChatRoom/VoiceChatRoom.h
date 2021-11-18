// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "VoiceChatRoom.generated.h"

class AAA2_PlayerState;

UCLASS()
class AA29_API AVoiceChatRoom : public AAA2_Info
{
	GENERATED_BODY()
public:
	AVoiceChatRoom();

	UPROPERTY()			int32 TeamIndex;								//var int TeamIndex;
	UPROPERTY()			bool bLocal;									//var bool bLocal;
	UPROPERTY()			int32 ChannelIndex;								//var int ChannelIndex;
	UPROPERTY()			FString Password;								//var string Password;
	UPROPERTY()			TArray<AVoiceChatRoom*> AA2_Children;				//var array<VoiceChatRoom> Children;
	UPROPERTY()			AVoiceChatRoom* Parent;							//var VoiceChatRoom Parent;
	//UPROPERTY()		AVoiceChatReplicationInfo* VoiceChatManager;	//var VoiceChatReplicationInfo VoiceChatManager;
	//UPROPERTY()		AGameReplicationInfo* GRI;						//var GameReplicationInfo GRI;



	void GetMembers();
	int32 GetMaxChatters();
	int32 GetMask();
	FString GetPassword();
	bool ValidMask();
	FString GetTitle();
	FString GetTeam();
	bool IsPublicChannel();
	bool IsTeamChannel();
	bool IsPrivateChannel();
	bool CanJoinChannel(AAA2_PlayerState* PRI);
	bool IsFull();
	bool IsMember(AAA2_PlayerState* PRI, bool bNoCascade);
	int32 JoinChannel(AAA2_PlayerState* NewPRI, FString InPassword);
	bool LeaveChannel(AAA2_PlayerState* LeavingPRI);
	void AddMember(AAA2_PlayerState* PRI);
	void RemoveMember(AAA2_PlayerState* PRI);
	void SetTeam(int32 NewTeam);
	void SetMemberMask(int32 NewMask);
	void SetChannelPassword(FString InPassword);
	bool AddChild(AVoiceChatRoom* NewChild);
	bool RemoveChild(AVoiceChatRoom* Child);
	bool NotifyTeamChange(AAA2_PlayerState* PRI, int NewTeamIndex);
};
