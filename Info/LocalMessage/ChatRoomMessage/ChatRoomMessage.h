// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/aLocalMessage.h"
#include "ChatRoomMessage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AChatRoomMessage : public AaLocalMessage
{
	GENERATED_BODY()
public:
	AChatRoomMessage();

	UPROPERTY()			TArray<FString> ChatRoomString;				//var localized string ChatRoomString;
	UPROPERTY()			FString AnonText;							//var localized string AnonText;


	void AssembleMessage(int32 Index, FString ChannelTitle, AAA2_PlayerState* RelatedPRI);
	bool IsConsoleMessage(int32 Index);
};
