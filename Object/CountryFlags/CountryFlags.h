// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "CountryFlags.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UCountryFlags : public UObject
{
	GENERATED_BODY()
public:
	UCountryFlags();

	UPROPERTY(EditAnywhere)								Fpointer FlagsMap;								//var const native transient pointer FlagsMap;
	UPROPERTY(EditAnywhere)								TArray<FCountryFlag> Flags;						//var config array<CountryFlag> Flags;
	UPROPERTY(EditAnywhere)								UTexture2D* FlagTexture;						//var const Material FlagTexture;

	int32 NumFlags();
	void GetRenderData(FFloatBox &RenderData, FString CountryName);
	FString testonly_GetCountryName(int32 Index);

};
