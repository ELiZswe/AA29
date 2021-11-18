// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/Security/Security.h"
#include "AGP_Security.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_Security : public ASecurity
{
	GENERATED_BODY()
public:
	AAGP_Security();

	void ServerCallback(int32 SecType, FString Data);
};
