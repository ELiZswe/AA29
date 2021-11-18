// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "AAGUIMultiColumnList.generated.h"

class UGUIComponent;
/**
 * 
 */
UCLASS()
class AA29_API UAAGUIMultiColumnList : public UGUIMultiColumnList
{
	GENERATED_BODY()
public:

	UAAGUIMultiColumnList();

	UPROPERTY()						TArray<UGUIComponent*> AttachedComponents;				//var() array<GUIComponent> AttachedComponents;
};
