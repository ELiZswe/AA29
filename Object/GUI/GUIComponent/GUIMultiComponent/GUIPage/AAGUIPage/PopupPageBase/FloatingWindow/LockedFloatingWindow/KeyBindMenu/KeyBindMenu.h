// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/LockedFloatingWindow.h"
#include "KeyBindMenu.generated.h"

class UGUIStyles;
class UGUIMultiColumnListBox;
class UGUIMultiColumnList;
class UGUIImage;
class UGUILabel;

/**
 * 
 */
UCLASS()
class AA29_API UKeyBindMenu : public ULockedFloatingWindow
{
	GENERATED_BODY()
public:
	UKeyBindMenu();

	UPROPERTY(EditAnywhere)			FInputKeyInfo						AllKeys;				//var() editconst noexport InputKeyInfo AllKeys[255];
	UPROPERTY(EditAnywhere)			TArray<FKeyBindMenyKeyBinding>		Bindings;				//var() TArray<KeyBinding> Bindings;       //ELIZ:   Name Conflict with another class
	UPROPERTY(EditAnywhere)			bool								bPendingRawInput;		//var() bool bPendingRawInput;
	UPROPERTY(EditAnywhere)			int32								NewIndex;				//var() editconst noexport int32 NewIndex;
	UPROPERTY(EditAnywhere)			int32								NewSubIndex;			//var() editconst noexport int32 NewSubIndex;
	UPROPERTY(EditAnywhere)			UGUIStyles*							SelStyle;				//var() editconst noexport XInterface.GUIStyles SelStyle;
	UPROPERTY(EditAnywhere)			UGUIStyles*							SectionStyle;			//var() editconst noexport XInterface.GUIStyles SectionStyle;
	UPROPERTY(EditAnywhere)			FString								SectionStyleName;		//var() FString SectionStyleName;
	UPROPERTY(EditAnywhere)			UGUIMultiColumnListBox* lb_Binds;				//var() automated XInterface.GUIMultiColumnListBox lb_Binds;
	UPROPERTY(EditAnywhere)			UGUIMultiColumnList*	li_Binds;				//var() automated XInterface.GUIMultiColumnList li_Binds;
	UPROPERTY(EditAnywhere)			UGUIImage*				i_Bk;					//var() automated XInterface.GUIImage i_Bk;
	UPROPERTY(EditAnywhere)			UGUILabel*				l_Hint;					//var() automated XInterface.GUILabel l_Hint;
	UPROPERTY(EditAnywhere)			TArray<FString>			Headings;				//var() localized FString Headings[4];
	UPROPERTY(EditAnywhere)			float					SectionLabelMargin;		//var() float SectionLabelMargin;
	UPROPERTY(EditAnywhere)			FString					PageCaption;			//var() localized FString PageCaption;
	UPROPERTY(EditAnywhere)			FString					SpeechLabel;			//var() localized FString SpeechLabel;
	UPROPERTY(EditAnywhere)			FString					CloseCaption;			//var() localized FString CloseCaption;
	UPROPERTY(EditAnywhere)			FString					ResetCaption;			//var() localized FString ResetCaption;
	UPROPERTY(EditAnywhere)			FString					ClearCaption;			//var() localized FString ClearCaption;
	UPROPERTY(EditAnywhere)			FString					ActionText;				//var() localized FString ActionText;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitializeBindingsArray();
	void Initialize();
	void InternalOnCloseSetBind(bool bCancelled);
	FString GetSpeechBind(FString Alias);
	bool SetSpeechBind(FString Alias, FString BindPhrase);
	void ResetSpeechBinds();
	void SaveSpeechBinds();
	void LoadCommands();
	void MapBindings();
	void CreateAliasMapping(FString Command, FString FriendlyName, bool bSectionLabel);
	void BindKeyToAlias(int32 BindIndex, int32 KeyIndex);
	void ClearBindings();
	void SetKeyBind(int32 Index, int32 SubIndex, uint8 NewKey);
	bool BeginRawInput(UGUIComponent* Sender);
	bool RawKey(uint8 NewKey);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	FString GetCurrentKeyBind(int32 BindIndex, int32 SubIndex);
	FString ListGetSortString(int32 Index);
	bool ListOnKeyEvent(uint8& Key, uint8& State, float Delta);
	void ListTrack(UGUIComponent* Sender, int32 LastIndex);
	void SearchUp(int32 oldIndex);
	void SearchDown(int32 oldIndex);
	void RemoveExistingKey(int32 Index, int32 SubIndex);
	void RemoveAllOccurance(uint8 NewKey);
	void UpdateHint(int32 BindIndex);
	bool MouseOnCol1();
	bool MouseOnCol2();
	bool MouseOnCol3();
	bool ValidBindIndex(int32 Index);
	bool ValidKeyIndex(int32 Index);
	int32 FindAliasIndex(FString Alias);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void DrawBinding(UCanvas* Canvas, int32 Item, float X, float Y, float W, float H, bool bSelected, bool bPending);
	bool InternalOnClick(UGUIComponent* Sender);
	void OnFadeIn();
};
