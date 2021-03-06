// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/Security/Security.h"
#include "AGPS.generated.h"

UCLASS()
class AAGPS : public ASecurity
{
	GENERATED_BODY()
public:
	AAGPS();


	UPROPERTY()			TArray<FString> asLocalPackageMD5s;					//var TArray<FString> asLocalPackageMD5s;
	UPROPERTY()			TArray<FString> asPackagesToTest;					//var TArray<FString> asPackagesToTest;
	UPROPERTY()			int32 iEntryBeingTested;							//var int iEntryBeingTested;

	void PostBeginPlay();
	void ServerCallback(int32 iSecType, FString sData);
	void ReportFailure();

};
