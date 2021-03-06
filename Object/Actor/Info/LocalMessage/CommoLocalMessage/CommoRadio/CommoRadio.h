// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "CommoRadio.generated.h"

UCLASS()
class ACommoRadio : public ACommoLocalMessage
{
	GENERATED_BODY()
public:
	ACommoRadio();

	FName GetAnim(int32 Switch);
};
