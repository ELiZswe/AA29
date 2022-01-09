// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/BroadcastHandler/BroadcastHandler.h"
#include "AGP_ChatHandler.generated.h"

class AAA2_PlayerState;

UCLASS()
class AAGP_ChatHandler : public ABroadcastHandler
{
	GENERATED_BODY()
public:
	AAGP_ChatHandler();

	UPROPERTY()				bool		bDebug;						//var bool bDebug;

	void ToggleChatDebug();
	void DoChatDebug();
	bool AcceptBroadcastText(APlayerController* Receiver, AAA2_PlayerState* SenderPRI, FString& Msg, FName Type);
	bool AcceptBroadcastLocalized(APlayerController * Receiver, AActor * Sender, ALocalMessage * Message, int32 Switch, AAA2_PlayerState * RelatedPRI_1, AAA2_PlayerState * RelatedPRI_2, UObject * obj);
	bool AcceptBroadcastSpeech(APlayerController * Receiver, AAA2_PlayerState * SenderPRI);
	bool AcceptBroadcastVoice(APlayerController * Receiver, AAA2_PlayerState * Sender);
};
