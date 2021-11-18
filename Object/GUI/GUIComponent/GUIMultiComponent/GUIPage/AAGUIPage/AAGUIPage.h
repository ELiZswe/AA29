// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"
#include "AAGUIPage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAGUIPage : public UGUIPage
{
	GENERATED_BODY()
public:
	UAAGUIPage();

	UPROPERTY()						USoundBase*		PopInSound;				//var Sound PopInSound;
	UPROPERTY()						USoundBase*		SlideInSound;			//var Sound SlideInSound;
	UPROPERTY()						USoundBase*		FadeInSound;			//var Sound FadeInSound;
	UPROPERTY()						USoundBase*		BeepSound;				//var Sound BeepSound;
};
