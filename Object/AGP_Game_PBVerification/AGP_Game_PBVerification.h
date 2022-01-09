// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AGP_Game_PBVerification.generated.h"

UCLASS()
class UAGP_Game_PBVerification : public UObject
{
	GENERATED_BODY()
public:
	UAGP_Game_PBVerification();

	bool VerifyPBInstance();
	bool MPOSCheck();
};
