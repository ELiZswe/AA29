// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPPanelBase.h"
#include "Tab_SPLadderBase.generated.h"

class ULadderButton;
class UGUILabel;
class UGUIImage;
class UGUIScrollTextBox;
class UMatchInfo;

UCLASS()
class AA29_API UTab_SPLadderBase : public UTab_SPPanelBase
{
	GENERATED_BODY()
public:
	UTab_SPLadderBase();

	UPROPERTY()			UGUIScrollTextBox*		ScrollInfo;					//var GUIScrollTextBox ScrollInfo;
	UPROPERTY()			UGUIImage*				MapPicHolder;				//var GUIImage MapPicHolder;
	UPROPERTY()			UGUILabel*				MapNameLabel;				//var GUILabel MapNameLabel;
	UPROPERTY()			ULadderButton*			ActiveLadderButton;			//var LadderButton ActiveLadderButton;

	void UpdateLadderButton(ULadderButton* Btn, int32 LadderIndex, int32 MatchIndex);
	ULadderButton* NewLadderButton(int32 LadderIndex, int32 MatchIndex, float Left, float Top);
	bool SetActiveMatch(int32 Ladder, TArray<ULadderButton*>& Btns);
	bool ShowMatchInfo(UMatchInfo* MI);
	bool DoShowMatchInfo(UMatchInfo* MI);
	bool MatchButtonClick(UGUIComponent* Sender);
	bool MatchDoubleClick(UGUIComponent* Sender);
	int32 SetYellowBar(int32 Ladder, int32 Index, TArray<ULadderButton*>& Buttons);
	bool CanShowPanel();
	UMaterialInstance* DLOMaterial(FString MaterialFullName);
};
