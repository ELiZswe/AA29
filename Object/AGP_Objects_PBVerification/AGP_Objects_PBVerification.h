// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AGP_Objects_PBVerification.generated.h"

UCLASS()
class AA29_API UAGP_Objects_PBVerification : public UObject
{
	GENERATED_BODY()
public:
	UAGP_Objects_PBVerification();

	bool VerifyPBInstance();
	bool MPOSCheck();
};
