// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_PlayerStats.generated.h"

class UGUIPage;
class UGUIButton;
class UGUILabel;
class UGUIImage;

UCLASS()
class AA29_API UAAGameMenu_PlayerStats : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_PlayerStats();

	UPROPERTY()								UGUIPage* guipOwner;			//var XInterface.GUIPage guipOwner;
	UPROPERTY(EditAnywhere)					UGUIButton* b_Hidden;			//var() XInterface.GUIButton b_Hidden;
	UPROPERTY(EditAnywhere)					UGUILabel* l_ObjectiveInfo;		//var() XInterface.GUILabel l_ObjectiveInfo;
	UPROPERTY(EditAnywhere)					UGUILabel* l_RoundsInfo;		//var() XInterface.GUILabel l_RoundsInfo;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TimeInfo;			//var() XInterface.GUILabel l_TimeInfo;
	UPROPERTY(EditAnywhere)					UGUILabel* l_GrenadesThrown;	//var() XInterface.GUILabel l_GrenadesThrown;
	UPROPERTY(EditAnywhere)					UGUILabel* l_ShotsHit;			//var() XInterface.GUILabel l_ShotsHit;
	UPROPERTY(EditAnywhere)					UGUILabel* l_ShotsFired;		//var() XInterface.GUILabel l_ShotsFired;
	UPROPERTY(EditAnywhere)					UGUILabel* l_Title;				//var() XInterface.GUILabel l_Title;
	UPROPERTY(EditAnywhere)					UGUIImage* i_Info;				//var() XInterface.GUIImage i_Info;
	UPROPERTY(EditAnywhere)					UGUIImage* i_Background;		//var() XInterface.GUIImage i_Background;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitializeStatRetrieval();
	void ShowPanel(bool bShow);
	bool InternalOnPreDraw(UCanvas* C);
	bool InternalOnClick(UGUIComponent* Sender);
	void NotifyStatsPage(FString sStatRequested, FString sValue);
};

