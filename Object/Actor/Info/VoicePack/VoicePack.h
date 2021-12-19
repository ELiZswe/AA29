// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "VoicePack.generated.h"

class AAA2_Playerstate;

UCLASS()
class AA29_API AVoicePack : public AAA2_Info
{
	GENERATED_BODY()
public:
	AVoicePack();

	UPROPERTY(EditAnywhere)			FString VoicePackDescription;			//var() localized string VoicePackDescription;
	UPROPERTY(EditAnywhere)			FString VoicePackName;					//var() localized string VoicePackName;

	void ClientInitialize(AAA2_Playerstate* Sender, AAA2_Playerstate* Recipient, FName messagetype, uint8 messageIndex);
	void PlayerSpeech(FName Type, int32 Index, FString Callsign, AActor* PackOwner);
	uint8 GetMessageIndex(FName PhraseName);
	int32 PickRandomTauntFor(AController* C, bool bNoMature, bool bNoHumanOnly);

};
