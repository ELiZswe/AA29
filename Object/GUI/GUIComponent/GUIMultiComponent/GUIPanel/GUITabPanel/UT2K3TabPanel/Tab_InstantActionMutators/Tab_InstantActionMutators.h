// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_InstantActionMutators.generated.h"

class UGUIScrollTextBox;
class UGUIListBox;

UCLASS(Config = Game)
class AA29_API UTab_InstantActionMutators : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_InstantActionMutators();

	UPROPERTY(config)			FString LastActiveMutators;			//var config FString LastActiveMutators;
	UPROPERTY()					UGUIListBox* MyAvailMutators;		//var GUIListBox MyAvailMutators;
	UPROPERTY()					UGUIListBox* MySelectedMutators;	//var GUIListBox MySelectedMutators;
	UPROPERTY()					UGUIScrollTextBox* MyDescBox;		//var GUIScrollTextBox MyDescBox;
	UPROPERTY()					FString MutConfigMenu;				//var FString MutConfigMenu;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString Play();
	FString ResolveMutator(FString FriendlyName);
	FString GetMutatorConfigMenu(FString FriendlyName);
	FString NextMutatorInString(FString& mut);
	void SelectMutator(FString mutClass);
	bool AvailDBLClick(UGUIComponent* Sender);
	bool SelectedDBLClick(UGUIComponent* Sender);
	bool MutConfigClick(UGUIComponent* Sender);
	void ListChange(UGUIComponent* Sender);
	FString GetGroupFor(FString FriendlyName);
	bool AddMutator(UGUIComponent* Sender);
	bool RemoveMutator(UGUIComponent* Sender);
	bool AddAllMutators(UGUIComponent* Sender);
	bool RemoveAllMutators(UGUIComponent* Sender);
};
