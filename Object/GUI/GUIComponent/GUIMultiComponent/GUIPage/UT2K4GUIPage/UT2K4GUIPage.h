// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"
#include "UT2K4GUIPage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUT2K4GUIPage : public UGUIPage
{
	GENERATED_BODY()
public:
	UUT2K4GUIPage();

	UPROPERTY(EditAnywhere)						USoundBase* PopInSound;						//var Sound PopInSound;
	UPROPERTY(EditAnywhere)						USoundBase* SlideInSound;					//var Sound SlideInSound;
	UPROPERTY(EditAnywhere)						USoundBase* FadeInSound;					//var Sound FadeInSound;
	UPROPERTY(EditAnywhere)						USoundBase* BeepSound;						//var Sound BeepSound;

};
