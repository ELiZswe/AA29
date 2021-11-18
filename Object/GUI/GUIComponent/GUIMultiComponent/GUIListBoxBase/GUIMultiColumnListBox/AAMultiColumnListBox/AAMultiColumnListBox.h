// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AAMultiColumnListBox.generated.h"

class UGUIListBase;
class UGUIComponent;

UCLASS()
class AA29_API UAAMultiColumnListBox : public UGUIMultiColumnListBox
{
	GENERATED_BODY()
public:
	UAAMultiColumnListBox();

	void OnGetSortString(UGUIComponent* Sender, int32 Item, int32 Column);
	void InitBaseList(UGUIListBase* LocalList);
	void InternalOnGetSortString(UGUIComponent* Sender, int32 Item, int32 Column);
};
