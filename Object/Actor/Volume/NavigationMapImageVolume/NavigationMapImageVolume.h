// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Volume/AA2_Volume.h"
#include "NavigationMapImageVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANavigationMapImageVolume : public AAA2_Volume
{
	GENERATED_BODY()
public:
	ANavigationMapImageVolume();


	UPROPERTY(EditAnywhere, Category = "NavMap")			UMaterialInstance*		matMapImage;			//var(NavMap) Material matMapImage;

};
