// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LogEntry.generated.h"

UCLASS()
class ULogEntry : public UObject
{
	GENERATED_BODY()
public:
	ULogEntry();



	UPROPERTY(EditAnywhere)			FString		DateTime;		//var() config FString DateTime;
	UPROPERTY(EditAnywhere)			FString		Entry;			//var() config FString Entry;
	UPROPERTY(EditAnywhere)			ULogEntry*	Next;			//var() LogEntry Next;

	void Insert(ULogEntry* newLE);
	ULogEntry* Delete(ULogEntry* delLE);
	int32 Count();
};
