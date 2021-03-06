// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "CommoHandSignal.generated.h"

UCLASS()
class ACommoHandSignal : public ACommoLocalMessage
{
	GENERATED_BODY()
public:
	ACommoHandSignal();

	USoundBase* GetSound(int32 Switch, AAA2_PlayerState* SenderPRI, AAA2_PlayerState* LocalPRI);
};
