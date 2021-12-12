// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Manifest.generated.h"

UCLASS()
class UManifest : public UObject
{
	GENERATED_BODY()
public:
	UManifest();

	UPROPERTY(EditAnywhere)			TArray<FString>		ManifestEntries;			//var() const TArray<FString> ManifestEntries;
};
