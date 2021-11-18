// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AGP_AI_PBVerification.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAGP_AI_PBVerification : public UObject
{
	GENERATED_BODY()
public:
	UAGP_AI_PBVerification();

	void VerifyPBInstance();
	void MPOSCheck();

};
