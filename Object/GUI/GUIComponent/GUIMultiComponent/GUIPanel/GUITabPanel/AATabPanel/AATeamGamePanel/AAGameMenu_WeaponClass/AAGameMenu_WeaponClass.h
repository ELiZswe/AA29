// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AATeamGamePanel.h"
#include "AAGameMenu_WeaponClass.generated.h"

class UGUIImage;
class UmoComboBox;
class UGUIMultiColumnListBox;
class UGUIMultiColumnListHeader;

UCLASS()
class AA29_API UAAGameMenu_WeaponClass : public UAATeamGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_WeaponClass();

	UPROPERTY(EditAnywhere)				UGUIImage*					i_Background;			//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)				UGUIImage*					i_PreferencePanel;		//var() automated XInterface.GUIImage i_PreferencePanel;
	UPROPERTY(EditAnywhere)				UGUIImage*					i_LoadoutPanel;			//var() automated XInterface.GUIImage i_LoadoutPanel;
	UPROPERTY(EditAnywhere)				UmoComboBox*				cb_Loadout;				//var() automated XInterface.moComboBox cb_Loadout;
	UPROPERTY(EditAnywhere)				UmoComboBox*				ch_Medic;				//var() automated XInterface.moCheckBox ch_Medic;
	UPROPERTY(EditAnywhere)				UGUIMultiColumnListBox*		lb_UnassignedTeam;		//var() automated XInterface.GUIMultiColumnListBox lb_UnassignedTeam;
	UPROPERTY(EditAnywhere)				UGUIMultiColumnListBox*		lb_Unit;				//var() automated XInterface.GUIMultiColumnListBox lb_Unit;
	UPROPERTY()							UGUIMultiColumnListHeader*	TeamHead;				//var XInterface.GUIMultiColumnListHeader TeamHead;
	UPROPERTY()							UGUIMultiColumnListHeader*	DeployHead;				//var XInterface.GUIMultiColumnListHeader DeployHead;
	UPROPERTY()							UGUIImage*					TeamBack;				//var XInterface.GUIImage TeamBack;
	UPROPERTY()							UGUIImage*					DeployBack;				//var XInterface.GUIImage DeployBack;
	UPROPERTY()							FString						WarningString;			//var localized FString WarningString;
	UPROPERTY()							FString						QualifyString;			//var localized FString QualifyString;
	UPROPERTY()							FString						WaitString;				//var localized FString WaitString;
	UPROPERTY()							FString						ChooseString;			//var localized FString ChooseString;
	UPROPERTY()							bool						bLastCanSelect;			//var bool bLastCanSelect;
	UPROPERTY()							bool						bInitialized;			//var bool bInitialized;
	UPROPERTY()							int32						lastTeam;				//var int32 lastTeam;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetTeam(ATeamInfo* TI);
	void Refresh();
	void InitializeCombos();
	bool MyOnPreDraw(UCanvas* C);
	bool CanShowPanel();
	void Timer();
	void SetWarning(bool bVisible, uint8 Message);
	void VerifyMedic(bool bWants);
	void InternalOnChange(UGUIComponent* Sender);
	void ShowPanel(bool bShow);
	void InternalOnLoadSet(UGUIComponent* Sender, FString S);
	void InternalOnChangeSet(UGUIComponent* Sender);
};
