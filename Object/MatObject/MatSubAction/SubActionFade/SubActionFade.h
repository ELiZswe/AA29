// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "SubActionFade.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API USubActionFade : public UMatSubAction
{
	GENERATED_BODY()
public:
	USubActionFade();

	UPROPERTY(EditAnywhere, Category = "Fade")										bool bFadeOut;								//var(Fade) bool bFadeOut;
	UPROPERTY(EditAnywhere, Category = "Fade")										FColor FadeColor;							//var(Fade) Object.Color FadeColor;
};
