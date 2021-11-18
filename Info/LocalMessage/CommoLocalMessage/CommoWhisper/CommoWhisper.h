// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "CommoWhisper.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ACommoWhisper : public ACommoLocalMessage
{
	GENERATED_BODY()
public:
	ACommoWhisper();

	UPROPERTY()			int32 MsgStatic;						//var int MsgStatic;
};
