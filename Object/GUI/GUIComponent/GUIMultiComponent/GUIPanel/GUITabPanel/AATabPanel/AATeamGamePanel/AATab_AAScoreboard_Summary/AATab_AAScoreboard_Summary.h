// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AATeamGamePanel.h"
#include "AATab_AAScoreboard_Summary.generated.h"

class UGUILabel;
class UGUIMultiColumnListBox;
class UGUIImage;
class UGUIContentBox;
class UGUIGridLayout;

UCLASS()
class AA29_API UAATab_AAScoreboard_Summary : public UAATeamGamePanel
{
	GENERATED_BODY()
public:
	UAATab_AAScoreboard_Summary();

	UPROPERTY(EditAnywhere)		int32					LastTeamID;			//var int32 LastTeamID;
	UPROPERTY(EditAnywhere)		UGUILabel*				l_Assault;			//var XInterface.GUILabel l_Assault;
	UPROPERTY(EditAnywhere)		UGUILabel*				l_Defense;			//var XInterface.GUILabel l_Defense;
	UPROPERTY(EditAnywhere)		UGUILabel*				l_Spectator;		//var XInterface.GUILabel l_Spectator;
	UPROPERTY(EditAnywhere)		UGUILabel*				l_Spacer;			//var XInterface.GUILabel l_Spacer;
	UPROPERTY(EditAnywhere)		UGUIMultiColumnListBox* lb_UnitAssault;		//var() automated XInterface.GUIMultiColumnListBox lb_UnitAssault;
	UPROPERTY(EditAnywhere)		UGUIMultiColumnListBox* lb_UnitDefense;		//var() automated XInterface.GUIMultiColumnListBox lb_UnitDefense;
	UPROPERTY(EditAnywhere)		UGUIMultiColumnListBox* lb_UnitSpectator;	//var() automated XInterface.GUIMultiColumnListBox lb_UnitSpectator;
	UPROPERTY(EditAnywhere)		UGUIMultiColumnListBox* lb_Blank;			//var() automated XInterface.GUIMultiColumnListBox lb_Blank;
	UPROPERTY(EditAnywhere)		UGUIImage*				i_Background;		//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)		UGUIContentBox*			cb_MainWindow;		//var() automated GUIContentBox cb_MainWindow;
	UPROPERTY(EditAnywhere)		UGUIGridLayout*			Grid;				//var() automated GUIGridLayout Grid;

	void InitGrid(int32 TeamID);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnPreDraw(UCanvas* C);
	bool ButtonClick(UGUIComponent* Sender);
	bool CanShowPanel();
	bool InternalOnDraw(UCanvas* C);

};
