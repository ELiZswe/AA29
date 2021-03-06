// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "CommoSquad.generated.h"

UCLASS()
class ACommoSquad : public ACommoLocalMessage
{
	GENERATED_BODY()
public:
	ACommoSquad();

	FName GetAnim(int32 Switch);
};
