// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvSlotBase.h"
#include "UIInvList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIInvList : public UUIInvSlotBase
{
	GENERATED_BODY()
public:
	UUIInvList();


	UPROPERTY()										int32 iScaledSlotWidth;					//var int iScaledSlotWidth;
	UPROPERTY()										int32 iScaledSlotHeight;				//var int iScaledSlotHeight;
	UPROPERTY()										int32 iSlotWidth;						//var int iSlotWidth;
	UPROPERTY()										int32 iSlotHeight;						//var int iSlotHeight;
	UPROPERTY()										int32 iItemsHeight;						//var int iItemsHeight;
	UPROPERTY()										int32 iItemsWidth;						//var int iItemsWidth;


	void Create(UUIFrame* frame, UUIScreen* screen, int32 pUIID, int32 pUIEvent, int32 pParams);
	void GetNumItems();
	void Draw(UCanvas* Canvas);
	void DrawItem(UCanvas* Canvas, int32 Position, int32 x_pos, int32 y_pos);
	void GetWidth(int32 Index);
	void GetHeight(int32 Index);
	void GetItemsWidth();
	void GetItemsHeight();
	void ScaleControl(UCanvas* Canvas);
};
