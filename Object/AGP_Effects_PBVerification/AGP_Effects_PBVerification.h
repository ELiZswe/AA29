// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AGP_Effects_PBVerification.generated.h"

UCLASS()
class AA29_API UAGP_Effects_PBVerification : public UObject
{
	GENERATED_BODY()
public:
	UAGP_Effects_PBVerification();

	bool VerifyPBInstance();
	bool MPOSCheck();
};
