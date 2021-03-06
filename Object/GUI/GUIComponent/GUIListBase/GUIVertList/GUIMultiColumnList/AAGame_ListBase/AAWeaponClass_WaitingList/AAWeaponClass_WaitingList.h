// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGame_ListBase/AAGame_ListBase.h"
#include "AAWeaponClass_WaitingList.generated.h"

UCLASS()
class UAAWeaponClass_WaitingList : public UAAGame_ListBase
{
	GENERATED_BODY()
public:
	UAAWeaponClass_WaitingList();

	void InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
};
