// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/Security/AGP_Security/AGP_Security.h"
#include "AGP_Checker.generated.h"

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API AAGP_Checker : public AAGP_Security
{
	GENERATED_BODY()
	
public:
	AAGP_Checker();


	UPROPERTY()				int32 Index;							//var int Index;
	UPROPERTY()				FString sResult;						//var string sResult;
	UPROPERTY(config)		int32 WaitSeconds;						//var config int WaitSeconds;
	UPROPERTY(config)		int32 TimeoutSeconds;					//var config int TimeoutSeconds;
	UPROPERTY(config)		TArray<int32> MD5Type;					//var config array<int> MD5Type;
	UPROPERTY(config)		TArray<FString> MD5;					//var config array<String> MD5;
	UPROPERTY(config)		TArray<FString> Checks;					//var config array<String> Checks;


	void PostNetBeginPlay();
	void BadNews(FString S);
	void ServerCallback(int32 SecType, FString Data);
	void CheckContinue();

};
