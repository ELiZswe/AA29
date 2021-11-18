// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "CommoSquad.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ACommoSquad : public ACommoLocalMessage
{
	GENERATED_BODY()
public:
	ACommoSquad();

	void GetAnim(int32 Switch);
};
