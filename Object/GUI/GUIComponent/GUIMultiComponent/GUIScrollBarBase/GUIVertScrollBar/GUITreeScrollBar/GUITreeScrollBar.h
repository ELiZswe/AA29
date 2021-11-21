// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIVertScrollBar/GUIVertScrollBar.h"
#include "GUITreeScrollBar.generated.h"

class UGUITreeList;
class UGUIListBase;

UCLASS()
class AA29_API UGUITreeScrollBar : public UGUIVertScrollBar
{
	GENERATED_BODY()
public:
	UGUITreeScrollBar();

	UPROPERTY(EditAnywhere)			UGUITreeList* List;						//var() editconst noexport GUITreeList List;

	void SetList(UGUIListBase* InList);
	void UpdateGripPosition(float NewPos);
	void MoveGripBy(int32 items);
	void AlignThumb();


};
