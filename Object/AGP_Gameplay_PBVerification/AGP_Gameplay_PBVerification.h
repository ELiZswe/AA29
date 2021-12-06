// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AGP_Gameplay_PBVerification.generated.h"

UCLASS()
class AA29_API UAGP_Gameplay_PBVerification : public UObject
{
	GENERATED_BODY()
public:
	UAGP_Gameplay_PBVerification();

	bool VerifyPBInstance();
	bool MPOSCheck();
};
