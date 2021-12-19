// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UTelnet_PBVerification.generated.h"

UCLASS()
class UUTelnet_PBVerification : public UObject
{
	GENERATED_BODY()
public:
	UUTelnet_PBVerification();

	bool VerifyPBInstance();
	bool MPOSCheck();
};
