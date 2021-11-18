// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "xPrivilegeBase.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UxPrivilegeBase : public UObject
{
	GENERATED_BODY()
public:
	UxPrivilegeBase();

	UPROPERTY()										TArray<FString> Tags;				//var localized array<String> Tags;
	UPROPERTY()										FString SubPrivs;					//var localized string SubPrivs;
	UPROPERTY()										FString MainPrivs;					//var localized string MainPrivs;
	UPROPERTY()										FString LoadMsg;					//var localized string LoadMsg;


	void Created();
};
