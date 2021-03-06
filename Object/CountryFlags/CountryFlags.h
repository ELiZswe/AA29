// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "CountryFlags.generated.h"

UCLASS(Config = Game)
class UCountryFlags : public UObject
{
	GENERATED_BODY()
public:
	UCountryFlags();

	UPROPERTY()				Fpointer				FlagsMap;			//var const native transient pointer FlagsMap;
	UPROPERTY(config)		TArray<FCountryFlag>	Flags;				//var config array<CountryFlag> Flags;
	UPROPERTY()				UTexture2D*				FlagTexture;		//var const Material FlagTexture;

	int32 NumFlags();
	bool GetRenderData(FFloatBox& RenderData, FString CountryName);
	FString testonly_GetCountryName(int32 Index);
};
