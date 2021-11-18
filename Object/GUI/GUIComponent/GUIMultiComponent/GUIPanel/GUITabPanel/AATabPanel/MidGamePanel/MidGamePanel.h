// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATabPanel.h"
#include "MidGamePanel.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UMidGamePanel : public UAATabPanel
{
	GENERATED_BODY()
public:
	UMidGamePanel();

	UPROPERTY(EditAnywhere)		bool	bLocked;				//var() bool bLocked;

	void ModifiedChatRestriction(UMidGamePanel* Sender, int32 PlayerID);
	void UpdateChatRestriction(int32 PlayerID);
	bool PlayerIDIsMine(int32 idx);
	void Free();
	void LevelChanged();
};
