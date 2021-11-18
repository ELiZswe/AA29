// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AGP_UI_PBVerification.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAGP_UI_PBVerification : public UObject
{
	GENERATED_BODY()
public:
	UAGP_UI_PBVerification();

	void VerifyPBInstance();
	void MPOSCheck();

};
