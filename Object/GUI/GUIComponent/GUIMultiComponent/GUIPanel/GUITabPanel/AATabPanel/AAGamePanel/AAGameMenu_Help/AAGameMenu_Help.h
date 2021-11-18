// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_Help.generated.h"

class AGameInfo;
class UGUILabel;
class UGUIButton;
class UGUIMultiColumnListBox;
class UGUIScrollTextBox;
class UGUIImage;

UCLASS()
class AA29_API UAAGameMenu_Help : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_Help();

	UPROPERTY()								int32							CurrentHintIndex;			//var int CurrentHintIndex;
	UPROPERTY()								TArray<FString>					AllGameHints;				//var array<String> AllGameHints;
	UPROPERTY()								AGameInfo*						GameClass;					//var class<GameInfo> GameClass;
	UPROPERTY(EditAnywhere)					UGUILabel*						GameIconsLabel;				//var() XInterface.GUILabel GameIconsLabel;
	UPROPERTY(EditAnywhere)					UGUILabel*						HintLabel;					//var() XInterface.GUILabel HintLabel;
	UPROPERTY(EditAnywhere)					UGUILabel*						GameDescriptionLabel;		//var() XInterface.GUILabel GameDescriptionLabel;
	UPROPERTY(EditAnywhere)					UGUIButton*						NextHintButton;				//var() XInterface.GUIButton NextHintButton;
	UPROPERTY(EditAnywhere)					UGUIButton*						PrevHintButton;				//var() XInterface.GUIButton PrevHintButton;
	UPROPERTY(EditAnywhere)					UGUILabel*						HintCountLabel;				//var() XInterface.GUILabel HintCountLabel;
	UPROPERTY(EditAnywhere)					UGUIMultiColumnListBox*			GameIconsBox;				//var() XInterface.GUIMultiColumnListBox GameIconsBox;
	UPROPERTY(EditAnywhere)					UGUIScrollTextBox*				HintsBox;					//var() XInterface.GUIScrollTextBox HintsBox;
	UPROPERTY(EditAnywhere)					UGUIScrollTextBox*				GameDescriptionBox;			//var() XInterface.GUIScrollTextBox GameDescriptionBox;
	UPROPERTY(EditAnywhere)					UGUIImage*						sb_IconDesc;				//var() XInterface.GUIImage sb_IconDesc;
	UPROPERTY(EditAnywhere)					UGUIImage*						sb_Hints;					//var() XInterface.GUIImage sb_Hints;
	UPROPERTY(EditAnywhere)					UGUIImage*						sb_GameDesc;				//var() XInterface.GUIImage sb_GameDesc;
	UPROPERTY(EditAnywhere)					UGUIImage*						i_Background;				//var() XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)					bool							bReceivedGameClass;			//var bool bReceivedGameClass;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);
	void Timer();
	bool ButtonClicked(UGUIComponent* Sender);
	bool FixUp(UCanvas* C);
};
