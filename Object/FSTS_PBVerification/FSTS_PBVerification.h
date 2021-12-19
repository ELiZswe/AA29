// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FSTS_PBVerification.generated.h"

UCLASS()
class UFSTS_PBVerification : public UObject
{
	GENERATED_BODY()
public:
	UFSTS_PBVerification();

	bool VerifyPBInstance();
	bool MPOSCheck();
};
