// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIInvSlotBase.generated.h"

class AInvContainer;

UCLASS()
class AA29_API UUIInvSlotBase : public UUIControl
{
	GENERATED_BODY()
public:
	UUIInvSlotBase();


	UPROPERTY()										AInvContainer* _cContainer;				//var InvContainer _cContainer;
	UPROPERTY()										int32 iScaledItemHeight;				//var int iScaledItemHeight;
	UPROPERTY()										int32 iScaledItemWidth;					//var int iScaledItemWidth;
	UPROPERTY()										int32 iItemHeight;						//var int iItemHeight;
	UPROPERTY()										int32 iItemWidth;						//var int iItemWidth;
	UPROPERTY()										int32 iItemsHigh;						//var int iItemsHigh;
	UPROPERTY()										int32 iItemsWide;						//var int iItemsWide;
	UPROPERTY()										bool _bLarge;							//var bool _bLarge;
	UPROPERTY()										bool _bQuick;							//var bool _bQuick;
	UPROPERTY()										int32 _iSlotSize;						//var int _iSlotSize;
	UPROPERTY()										UMaterialInstance* _TexSel;				//var Texture _TexSel;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;


	void Destroyed();
	void CanObjectFitInSlot(int32 object_size, int32 slot_size);
	void SetLarge(bool large);
	void isLarge();
	void SetSize(int32 Size);
	void GetSize();
	void SetQuick(bool quick);
	void IsQuick(int32 Index);
	void SetItem(int32 Index, int32 Item, int32 Param, int32 Size, float Weight);
	void GetItemID(int32 Index);
	void SetItemID(int32 Index, int32 Id);
	void GetItemParam(int32 Index);
	void SetItemParam(int32 Index, int32 Param);
	void SetItemLarge(int32 Index, bool large);
	bool IsItemLarge(int32 Index);
	void SetContainer(AInvContainer* container);
	void GetContainer();
	void ScaleControl(UCanvas* Canvas);
	void SetItemDimensions(int32 Width, int32 Height, int32 wide, int32 High);
	void SetTexture(UMaterialInstance* Tex);
	void SetTexture2(UMaterialInstance* Tex);
};
