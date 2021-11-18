// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "GUIMultiComponentListBox.generated.h"

class UGUIMultiComponentList;
class UGUIListBase;

UCLASS()
class AA29_API UGUIMultiComponentListBox : public UGUIListBoxBase
{
	GENERATED_BODY()
public:
	UGUIMultiComponentListBox();


	UPROPERTY(EditAnywhere)								int32							NumColumns;				//var() int NumColumns;
	UPROPERTY(EditAnywhere)								UGUIMultiComponentList* List;				//var() editconst GUIMultiComponentList List;


	void InitBaseList(UGUIListBase* LocalList);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	void ItemCount();
	void ListLoadIni(UGUIComponent* Sender, FString S);
	void ListSaveIni(UGUIComponent* Sender);
	void ListCreateComponent(UGUIComponent* NewComp, UGUIMultiComponentList* Sender);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void InternalOnScrollRelease(UGUIComponent* Sender);
	
};
