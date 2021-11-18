// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"
#include "LadderButton.generated.h"

class 
	UMatchInfo;

UCLASS()
class AA29_API ULadderButton : public UGUIGFXButton
{
	GENERATED_BODY()
public:
	ULadderButton();

	UPROPERTY()											int32 LadderIndex;							//var int LadderIndex;
	UPROPERTY()											int32 MatchIndex;							//var int MatchIndex;
	UPROPERTY()											UMatchInfo* MatchInfo;						//var MatchInfo MatchInfo;

	void SetState(int32 rung);
};
