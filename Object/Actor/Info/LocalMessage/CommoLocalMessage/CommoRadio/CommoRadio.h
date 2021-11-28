// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "CommoRadio.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ACommoRadio : public ACommoLocalMessage
{
	GENERATED_BODY()
public:
	ACommoRadio();

	void GetSound(int32 Switch, AAA2_PlayerState* SenderPRI, AAA2_PlayerState* LocalPRI);
};
