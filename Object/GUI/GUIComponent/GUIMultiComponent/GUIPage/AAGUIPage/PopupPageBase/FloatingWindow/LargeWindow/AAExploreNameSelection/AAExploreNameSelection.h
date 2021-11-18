// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/LargeWindow.h"
#include "AAExploreNameSelection.generated.h"

class UGUIImage;
class UGUIButton;
class UGUILabel;
class UmoComboBox;
class UAAExploreTheArmySubPanel;

UCLASS()
class AA29_API UAAExploreNameSelection : public ULargeWindow
{
	GENERATED_BODY()
public:
	UAAExploreNameSelection();

	UPROPERTY(EditAnywhere)		UGUIImage* i_Background;			//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)		UGUIButton* btnPlayNow;				//var() automated XInterface.GUIImage btnPlayNow;
	UPROPERTY(EditAnywhere)		UGUIButton* btnPlayLANNow;			//var() automated XInterface.GUIButton btnPlayLANNow;
	UPROPERTY(EditAnywhere)		UGUIButton* btnCancel;				//var() automated XInterface.GUIButton btnCancel;
	UPROPERTY(EditAnywhere)		UGUILabel* guilInstructions;		//var() automated XInterface.GUILabel guilInstructions;
	UPROPERTY(EditAnywhere)		UGUILabel* guilNoXPMessage;			//var() automated XInterface.GUILabel guilNoXPMessage;
	UPROPERTY(EditAnywhere)		UmoComboBox* mcbNickName;			//var() automated XInterface.moComboBox mcbNickName;
	UPROPERTY(EditAnywhere)		UmoComboBox* mcbLastName;			//var() automated XInterface.moComboBox mcbLastName;
	UPROPERTY(EditAnywhere)		UAAExploreTheArmySubPanel* ExploreTheArmySubPanel;	//var AAExploreTheArmySubPanel ExploreTheArmySubPanel;

	void InitComponent(UGUIController* MyC, UGUIComponent* MyO);
	bool OnPlayClick(UGUIComponent* Sender);
	bool OnPlayLANClick(UGUIComponent* Sender);
	bool OnCancelClick(UGUIComponent* Sender);
};
