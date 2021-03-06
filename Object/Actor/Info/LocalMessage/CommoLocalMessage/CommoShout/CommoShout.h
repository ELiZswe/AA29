// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "CommoShout.generated.h"

UCLASS()
class ACommoShout : public ACommoLocalMessage
{
	GENERATED_BODY()
public:
	ACommoShout();

	FName GetAnim(int32 Switch);
	bool ReportLocation(int32 Switch);
};
