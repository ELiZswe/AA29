// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Palette.generated.h"

UCLASS()
class UPalette : public UObject
{
	GENERATED_BODY()
public:
	UPalette();

	UPROPERTY()				TArray<FColor>		Colors;					//var const native TArray<Color> Colors;
};
