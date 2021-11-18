// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "Security.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASecurity : public AAA2_Info
{
	GENERATED_BODY()
public:
	ASecurity();

	UPROPERTY()			FString LastParams;					//var string LastParams;
	UPROPERTY()			int32 LastType;						//var int LastType;

};
