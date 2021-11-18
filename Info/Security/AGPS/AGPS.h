// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/Security/Security.h"
#include "AGPS.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGPS : public ASecurity
{
	GENERATED_BODY()
public:
	AAGPS();


	UPROPERTY()			TArray<FString> asLocalPackageMD5s;					//var array<String> asLocalPackageMD5s;
	UPROPERTY()			TArray<FString> asPackagesToTest;					//var array<String> asPackagesToTest;
	UPROPERTY()			int32 iEntryBeingTested;							//var int iEntryBeingTested;

	void PostBeginPlay();
	void ServerCallback(int32 iSecType, FString sData);
	void ReportFailure();

};
