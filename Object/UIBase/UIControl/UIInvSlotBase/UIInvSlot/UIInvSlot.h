// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvSlotBase.h"
#include "UIInvSlot.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIInvSlot : public UUIInvSlotBase
{
	GENERATED_BODY()
public:
	UUIInvSlot();


	UPROPERTY()										FInvProperties _InvSlot;				//var UIBase.InvProperties _InvSlot;
	UPROPERTY()										int32 nSelection;						//var int nSelection;
	UPROPERTY()										int32 nButtonDownSlot;					//var int nButtonDownSlot;
	UPROPERTY()										bool bButtonDown;						//var bool bButtonDown;


	void ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetItem(int32 Index, int32 Item, int32 Param, int32 Size, float Weight);
	void GetItemID(int32 Index);
	void SetItemID(int32 Index, int32 Id);
	void GetItemParam(int32 Index);
	void SetItemParam(int32 Index, int32 Param);
	void GetItemSize(int32 Index);
	void SetItemSize(int32 Index, int32 Size);
};
