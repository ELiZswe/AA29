// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AGP_SecureServerActor.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_SecureServerActor : public AAA2_Info
{
	GENERATED_BODY()
public:
	AAGP_SecureServerActor();

	void BeginPlay();
};
