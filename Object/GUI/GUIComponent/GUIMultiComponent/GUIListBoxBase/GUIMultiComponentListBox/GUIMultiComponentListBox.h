// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "GUIMultiComponentListBox.generated.h"

class UGUIMultiComponentList;
class UGUIListBase;

class UGUIComponent;
class UGUIController;
UCLASS()
class UGUIMultiComponentListBox : public UGUIListBoxBase
{
	GENERATED_BODY()
public:
	UGUIMultiComponentListBox();


	UPROPERTY(EditAnywhere)				int32						NumColumns;			//var() int NumColumns;
	UPROPERTY(EditAnywhere)				UGUIMultiComponentList*		List;				//var() editconst GUIMultiComponentList List;

	void InitBaseList(UGUIListBase* LocalList);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	int32 ItemCount();
	void ListLoadIni(UGUIComponent* Sender, FString S);
	FString ListSaveIni(UGUIComponent* Sender);
	void ListCreateComponent(UGUIComponent* NewComp, UGUIMultiComponentList* Sender);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void InternalOnScrollRelease(UGUIComponent* Sender);
};
