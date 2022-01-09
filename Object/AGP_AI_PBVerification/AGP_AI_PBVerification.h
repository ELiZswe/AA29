// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AGP_AI_PBVerification.generated.h"

UCLASS()
class UAGP_AI_PBVerification : public UObject
{
	GENERATED_BODY()
public:
	UAGP_AI_PBVerification();

	bool VerifyPBInstance();
	bool MPOSCheck();
};
