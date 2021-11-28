// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/Security/Security.h"
#include "AGP_MD5Dumper.generated.h"

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API AAGP_MD5Dumper : public ASecurity
{
	GENERATED_BODY()
public:
	AAGP_MD5Dumper();

	UPROPERTY()			int32 iIndex;							//var int iIndex;
	UPROPERTY(config)	TArray<int32> MD5Type;					//var config array<int> MD5Type;
	UPROPERTY(config)	TArray<FString> Checks;					//var config array<String> Checks;
	UPROPERTY()			int32 bPerformDump;						//var config bool bPerformDump;

	void PerformDump();
	void GetMD5(int32 Type, FString Check);
	void ServerCallback(int32 SecType, FString Data);
};
