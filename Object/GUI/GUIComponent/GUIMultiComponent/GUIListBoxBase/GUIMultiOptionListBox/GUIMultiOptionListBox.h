// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "GUIMultiOptionListBox.generated.h"

class UGUIMultiOptionList;
class UGUIListBase;
class UGUIMenuOption;

class UGUIComponent;
class UGUIController;
UCLASS()
class UGUIMultiOptionListBox : public UGUIListBoxBase
{
	GENERATED_BODY()
public:
	UGUIMultiOptionListBox();

	UPROPERTY()								int32						NumColumns;					//var() int NumColumns;
	UPROPERTY(EditAnywhere)					UGUIMultiOptionList*		List;						//var() editconst GUIMultiOptionList List;

	void InitBaseList(UGUIListBase* LocalList);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	int32 ItemCount();
	void ListLoadIni(UGUIComponent* Sender, FString S);
	FString ListSaveIni(UGUIComponent* Sender);
	void ListCreateComponent(UGUIMenuOption* NewComp, UGUIMultiOptionList* Sender);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void InternalOnScrollRelease(UGUIComponent* Sender);
	void EnableMe();
	void DisableMe();
};
