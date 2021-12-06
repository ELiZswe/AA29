// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AGP_Script_PBVerification.generated.h"

UCLASS()
class AA29_API UAGP_Script_PBVerification : public UObject
{
	GENERATED_BODY()
public:
	UAGP_Script_PBVerification();

	bool VerifyPBInstance();
	bool MPOSCheck();
};
