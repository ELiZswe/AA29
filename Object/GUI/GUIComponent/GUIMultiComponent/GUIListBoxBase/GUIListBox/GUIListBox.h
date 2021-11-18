// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "GUIListBox.generated.h"

class UGUIList;
class UGUIListBase;
class UGUIController;
class UGUIComponent;
class UGUIContextMenu;

UCLASS()
class AA29_API UGUIListBox : public UGUIListBoxBase
{
	GENERATED_BODY()
public:
	UGUIListBox();

	UPROPERTY(EditAnywhere)			UGUIList* List;				//var GUIList List;

	void InitBaseList(UGUIListBase* LocalList);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnDblClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	void ItemCount();
	void MyOpen(UGUIContextMenu* Menu);
	void MyClose(UGUIContextMenu* Sender);
};
