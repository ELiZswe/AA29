// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "AGP_WorldInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_WorldInfo : public AAA2_Info
{
	GENERATED_BODY()
public:
	AAGP_WorldInfo();


	UPROPERTY()						float fTempFactor;						//var float fTempFactor;
	UPROPERTY()						float fTempBase;						//var float fTempBase;
	UPROPERTY()						float fHumidFactor;						//var float fHumidFactor;
	UPROPERTY()						float fHumidBase;						//var float fHumidBase;
	UPROPERTY(EditAnywhere)			float fTemperature;						//var() float fTemperature;
	UPROPERTY(EditAnywhere)			float fHumidity;						//var() float fHumidity;
};
