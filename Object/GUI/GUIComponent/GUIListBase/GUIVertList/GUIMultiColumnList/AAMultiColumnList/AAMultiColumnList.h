// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "AAMultiColumnList.generated.h"

class AGUIComponent;

UCLASS()
class UAAMultiColumnList : public UGUIMultiColumnList
{
	GENERATED_BODY()
public:
	UAAMultiColumnList();

	FString OnGetSortString(AGUIComponent* Sender, int32 Item, int32 Column);
	FString InternalGetSortString(int32 i);
};
