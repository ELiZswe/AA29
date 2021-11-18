// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/MapList/MapList.h"
#include "AGP_MapList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_MapList : public AMapList
{
	GENERATED_BODY()
public:
	AAGP_MapList();

	void PreBeginPlay();
	void PostBeginPlay();
	FString GetNextMap();
};
