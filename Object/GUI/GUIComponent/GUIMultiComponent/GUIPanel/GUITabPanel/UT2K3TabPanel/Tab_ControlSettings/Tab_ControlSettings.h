// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_ControlSettings.generated.h"

class UGUIListBox;
class UGUIStyles;

UCLASS()
class AA29_API UTab_ControlSettings : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_ControlSettings();

	UPROPERTY()			UGUIListBox*				MyListBox;				//var GUIListBox MyListBox;
	UPROPERTY()			FColor						BkColor;				//var Color BkColor;
	UPROPERTY()			TArray<FKeyBinding>			Bindings;				//var TArray<KeyBinding> Bindings;
	UPROPERTY()			TArray<FString>				Labels;					//var localized TArray<FString> Labels;
	UPROPERTY()			bool						bSetNextKeyPress;		//var bool bSetNextKeyPress;
	UPROPERTY()			int32						NewIndex;				//var int32 NewIndex;
	UPROPERTY()			int32						NewSubIndex;			//var int32 NewSubIndex;
	UPROPERTY()			UGUIStyles*					SelStyle;				//var GUIStyles SelStyle;
	UPROPERTY()			int32						row;					//var int32 row;
	UPROPERTY()			int32						HackIndex;				//var int32 HackIndex;
	UPROPERTY()			FString						Header;					//var localized FString Header;
	UPROPERTY()			FString						Footer;					//var localized FString Footer;
	UPROPERTY()			float						SectionLabelMargin;		//var float SectionLabelMargin;
	UPROPERTY()			bool						bListInitialised;		//var bool bListInitialised;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);
	int32 Weight(int32 i);
	void Swap(int32 Index, int32 A, int32 B);
	void AddToBindings(FString Alias, FString KeyLabel, bool bSectionLabel);
	void InitBindings();
	FString GetCurrentKeyBind(int32 Index, int32 bind);
	void DrawBinding(UCanvas* Canvas, int32 Item, float X, float Y, float W, float H, bool bSelected, bool bPending);
	bool ListOnKeyEvent(uint8& Key, uint8& State, float Delta);
	void SearchUp(int32 oldIndex);
	void SearchDown(int32 oldIndex);
	void RemoveExistingKey(int32 Index, int32 SubIndex);
	void RemoveAllOccurance(uint8 NewKey);
	void UpdateHint(int32 Index);
	void AddNewKey(int32 Index, int32 SubIndex, uint8 NewKey);
	bool GetNewKey(UGUIComponent* Sender);
	bool RawKey(uint8 NewKey);
	void ListChange(UGUIComponent* Sender);
	void MyOnAdjustTop(UGUIComponent* Sender);
	bool ResetClicked(UGUIComponent* Sender);
};
