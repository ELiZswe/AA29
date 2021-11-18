// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIQuestionPage/GUIQuestionPage.h"
#include "AAQuestionPage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAQuestionPage : public UGUIQuestionPage
{
	GENERATED_BODY()
public:
	UAAQuestionPage();

	bool ButtonClick(UGUIComponent* Sender);
};
