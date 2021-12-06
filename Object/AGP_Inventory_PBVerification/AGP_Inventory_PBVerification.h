// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AGP_Inventory_PBVerification.generated.h"

UCLASS()
class AA29_API UAGP_Inventory_PBVerification : public UObject
{
	GENERATED_BODY()
public:
	UAGP_Inventory_PBVerification();

	bool VerifyPBInstance();
	bool MPOSCheck();
};
