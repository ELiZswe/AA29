// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/GUICustomPropertyPage/GUICustomPropertyPage.h"
#include "GUIArrayPropPage.generated.h"

class UAltSectionBackground;
class UGUIMultiOptionList;
class UGUIMultiOptionListBox;
class UGUIMenuOption;

UCLASS()
class AA29_API UGUIArrayPropPage : public UGUICustomPropertyPage
{
	GENERATED_BODY()
public:
	UGUIArrayPropPage();

	UPROPERTY(EditAnywhere)		FString						PropName;			//var() FString PropName;
	UPROPERTY(EditAnywhere)		TArray<FString>				PropValue;			//var() TArray<FString> PropValue;
	UPROPERTY()					FString						MOType;				//var FString MOType;
	UPROPERTY(EditAnywhere)		UGUIMultiOptionListBox*		lb_Values;			//var() automated XInterface.GUIMultiOptionListBox lb_Values;
	UPROPERTY(EditAnywhere)		UGUIMultiOptionList*		li_Values;			//var() XInterface.GUIMultiOptionList li_Values;
	UPROPERTY(EditAnywhere)		FString						Delim;				//var() FString Delim;
	UPROPERTY(EditAnywhere)		FString						ButtonStyle;		//var() FString ButtonStyle;
	UPROPERTY()					bool						bReadOnly;			//var bool bReadOnly;
	UPROPERTY(EditAnywhere)		bool						bListInitialized;	//var() bool bListInitialized;
	UPROPERTY(EditAnywhere)		UAltSectionBackground*		sb_Bk1;				//var() automated AltSectionBackground sb_Bk1;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetOwner(UGUIComponent* NewOwner);
	void SetReadOnly(bool bValue);
	bool GetReadOnly();
	FString GetDataString();
	bool InternalOnPreDraw(UCanvas* C);
	void InitializeList();
	UGUIMenuOption* AddListItem(int32 Index);
	void Clear();
	void UpdateListCaptions();
	void UpdateListValues();
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	int32 GetMaxValue(FString MaxLength);
	void SetItemOptions(UGUIMenuOption* mo);
};
