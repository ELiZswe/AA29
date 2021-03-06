// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/aLocalMessage.h"
#include "ChatRoomMessage.generated.h"

UCLASS()
class AChatRoomMessage : public AaLocalMessage
{
	GENERATED_BODY()
public:
	AChatRoomMessage();

	UPROPERTY()			TArray<FString> ChatRoomString;				//var localized string ChatRoomString;
	UPROPERTY()			FString AnonText;							//var localized string AnonText;

	FString AssembleMessage(int32 Index, FString ChannelTitle, AAA2_PlayerState* RelatedPRI);
	bool IsConsoleMessage(int32 Index);
};
