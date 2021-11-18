// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Light/VolumeLight/VolumeLight.h"
#include "BHLandingLight.generated.h"

class AAGP_Pawn;
/**
 * 
 */
UCLASS()
class AA29_API ABHLandingLight : public AVolumeLight
{
	GENERATED_BODY()
public:
	ABHLandingLight();

	UPROPERTY()											AAGP_Pawn* Player;						//var AGP.AGP_Pawn Player;
	UPROPERTY()											bool bInit;								//var bool bInit;

	void TurnOn();
	void TurnOff();

};
