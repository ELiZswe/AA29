// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Volume/AA2_Volume.h"
#include "AA29/AA29.h"
#include "RadarImageVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ARadarImageVolume : public AAA2_Volume
{
	GENERATED_BODY()
public:
	ARadarImageVolume();

	UPROPERTY(EditAnywhere)			bool bDisableRadarInVolume;					//var() bool bDisableRadarInVolume;
	UPROPERTY(EditAnywhere)			int32 ImageVolumePriority;					//var() int ImageVolumePriority;
	UPROPERTY(EditAnywhere)			TArray<FImageStratum> ImageStrata;			//var() array<ImageStratum> ImageStrata;

	UMaterialInstance* GetRadarImage(FVector PlayerLocation);
	UMaterialInstance* GetBestRadarImage(APawn* p);
	bool ShouldDisableRadar(APawn* p);
};
