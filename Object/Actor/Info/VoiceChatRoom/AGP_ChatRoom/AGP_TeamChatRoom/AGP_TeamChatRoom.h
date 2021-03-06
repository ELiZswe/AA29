// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/AGP_ChatRoom/AGP_ChatRoom.h"
#include "AGP_TeamChatRoom.generated.h"

UCLASS()
class AAGP_TeamChatRoom : public AAGP_ChatRoom
{
	GENERATED_BODY()
public:
	AAGP_TeamChatRoom();
	
	bool IsTeamChannel();
	bool CanJoinChannel(AAA2_PlayerState* PRI);
	bool NotifyTeamChange(AAA2_PlayerState* PRI, int32 NewTeamIndex);
};
