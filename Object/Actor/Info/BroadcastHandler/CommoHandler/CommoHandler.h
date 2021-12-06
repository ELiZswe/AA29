// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/BroadcastHandler/BroadcastHandler.h"
#include "CommoHandler.generated.h"

class AAGP_GameInfo;
class ALocalMessage;
class AAA2_playerState;

UCLASS()
class AA29_API ACommoHandler : public ABroadcastHandler
{
	GENERATED_BODY()
public:
	ACommoHandler();


	UPROPERTY()				int32			iShoutDistance;						//var int32 iShoutDistance;
	UPROPERTY()				int32			iWhisperDistance;					//var int32 iWhisperDistance;
	UPROPERTY()				AAGP_GameInfo*	agpgame;							//var AGP_GameInfo agpgame;
	UPROPERTY()				int32			_numTextUpdates;					//var int32 _numTextUpdates;

	void PostBeginPlay();
	void UpdateSentText();
	bool AllowsBroadcast(AActor* broadcaster, int32 Len);
	void AllowBroadcastLocalized(AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_playerState* RelatedPRI_1, AAA2_playerState* RelatedPRI_2, UObject* OptionalObject);
	void Broadcast(AActor* Sender, FString Msg, FName Type);
	void BroadcastTeamByIndex(uint8 TeamIndex, FString Msg, FName Type);
	void BroadcastLocalizedTeamByIndex(uint8 TeamIndex, AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_playerState* RelatedPRI_1, AAA2_playerState* RelatedPRI_2, UObject* OptionalObject);

};
