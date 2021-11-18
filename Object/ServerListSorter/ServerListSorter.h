// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "ServerListSorter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UServerListSorter : public UObject
{
	GENERATED_BODY()
public:
	UServerListSorter();

	void SortServerList(TArray<FGameSpyServerItem> &List, FString Field, bool Ascending);
	void testonly_CompareServers(FGameSpyServerItem ServerA, FGameSpyServerItem ServerB, FString Field);

};
