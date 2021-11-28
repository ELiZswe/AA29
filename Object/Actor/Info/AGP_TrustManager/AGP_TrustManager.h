// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AGP_TrustManager.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_TrustManager : public AAA2_Info
{
	GENERATED_BODY()
public:
	AAGP_TrustManager();

	UPROPERTY()			TArray<int32> ExperienceLevel;					//var int ExperienceLevel[101];

	int32 CalculateTrust(int32 Experience);
	int32 LookupTrust(int32 Experience);
	int32 GetTrust(int32 Level);

};
