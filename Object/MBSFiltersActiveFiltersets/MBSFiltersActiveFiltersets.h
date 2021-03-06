// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "MBSFiltersActiveFiltersets.generated.h"

UCLASS(Config = Game)
class UMBSFiltersActiveFiltersets : public UObject
{
	GENERATED_BODY()
public:
	UMBSFiltersActiveFiltersets();

	UPROPERTY(Config)							TArray<FActiveFilterSet> Set;						//var config MBSFiltersActiveFiltersets.ActiveFilterSet Set;

};
