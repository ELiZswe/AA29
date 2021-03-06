// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "xPrivilegeBase.generated.h"

UCLASS()
class UxPrivilegeBase : public UObject
{
	GENERATED_BODY()
public:
	UxPrivilegeBase();

	UPROPERTY()			FString			LoadMsg;
	UPROPERTY()			FString			MainPrivs;
	UPROPERTY()			FString			SubPrivs;
	UPROPERTY()			TArray<FString> Tags;

	void Created();
};
