// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPLadderBase/Tab_SPLadderBase.h"
#include "Tab_SPLadderTeam.generated.h"

class UGUIGFXButton;
class ULadderButton;
class UGUIImage;

UCLASS()
class AA29_API UTab_SPLadderTeam : public UTab_SPLadderBase
{
	GENERATED_BODY()
public:
	UTab_SPLadderTeam();

	UPROPERTY()			TArray<ULadderButton*>		TDMButtons;			//var TArray<LadderButton> TDMButtons;
	UPROPERTY()			TArray<ULadderButton*>		DOMButtons;			//var TArray<LadderButton> DOMButtons;
	UPROPERTY()			TArray<ULadderButton*>		BRButtons;			//var TArray<LadderButton> BRButtons;
	UPROPERTY()			TArray<ULadderButton*>		CTFButtons;			//var TArray<LadderButton> CTFButtons;
	UPROPERTY()			TArray<int32>				LockIndexes;		//var TArray<int32> LockIndexes;
	UPROPERTY()			UGUIGFXButton*				ChampButton;		//var GUIGFXButton ChampButton;
	UPROPERTY()			UGUIImage*					ChampBorder;		//var GUIImage ChampBorder;

	void InitPanel();
	void OnProfileUpdated();
	int32 SetYellowBar(int32 Ladder, int32 Index, TArray<ULadderButton*>& Buttons);
	bool ChampMatch(UGUIComponent* Sender);
	void SetChampionship(bool bEnable);
};
