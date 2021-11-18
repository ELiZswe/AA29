// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "InternetInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AInternetInfo : public AAA2_Info
{
	GENERATED_BODY()
public:
	AInternetInfo();


	int32 GetBeaconCount();
	FString GetBeaconAddress(int32 i);
	FString GetBeaconText(int32 i);
	void WriteLog(FString Text);
};
