// All the original content belonged to the US Army


#include "AA29/Info/VoicePack/VoicePack.h"

AVoicePack::AVoicePack()
{
	//LifeSpan = 10;
}

void AVoicePack::ClientInitialize(AAA2_Playerstate* Sender, AAA2_Playerstate* Recipient, FName messagetype, uint8 messageIndex)
{
}

void AVoicePack::PlayerSpeech(FName Type, int32 Index, FString Callsign, AActor* PackOwner)
{
}

int32 AVoicePack::GetMessageIndex(FName PhraseName)
{
	return 0;
}

int32 AVoicePack::PickRandomTauntFor(AController* C, bool bNoMature, bool bNoHumanOnly)
{
	return 0;
}
