// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/Keypoint.h"
#include "SpectatorCam.generated.h"

UCLASS()
class ASpectatorCam : public AKeypoint
{
	GENERATED_BODY()
public:
	ASpectatorCam(const FObjectInitializer& objectInitializer);

	UPROPERTY(EditAnywhere)						float FadeOutTime;						//var() float FadeOutTime;
	UPROPERTY(EditAnywhere)						bool bSkipView;							//var() bool bSkipView;
};
