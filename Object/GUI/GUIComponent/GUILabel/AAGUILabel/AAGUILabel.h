// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AAGUILabel.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAGUILabel : public UGUILabel
{
	GENERATED_BODY()
public:
	UAAGUILabel();
	UPROPERTY()										bool bFitToTextHeight;					//var() bool bFitToTextHeight;
};
