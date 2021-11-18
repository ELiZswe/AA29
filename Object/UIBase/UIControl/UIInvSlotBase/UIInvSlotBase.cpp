// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvSlotBase.h"

UUIInvSlotBase::UUIInvSlotBase()
{

}


void UUIInvSlotBase::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
	_TexSel = nullptr;
}
void UUIInvSlotBase::CanObjectFitInSlot(int32 object_size, int32 slot_size)
{
	/*
	Switch(object_size)
	{
			case 0:
				if (slot_size < 2)
				{
					Return True;
				}
				break;
			default:
				if (object_size == slot_size)
				{
					Return True;
				}
				break;
	}
	Return False;
	*/
}
void UUIInvSlotBase::SetLarge(bool large)
{
	_bLarge = large;
}
void UUIInvSlotBase::isLarge()
{
	//return _bLarge;
}
void UUIInvSlotBase::SetSize(int32 Size)
{
	_iSlotSize = Size;
}
void UUIInvSlotBase::GetSize()
{
	//return _iSlotSize;
}
void UUIInvSlotBase::SetQuick(bool quick)
{
	_bQuick = quick;
}
void UUIInvSlotBase::IsQuick(int32 Index)
{
	//return _bQuick;
}
void UUIInvSlotBase::SetItem(int32 Index, int32 Item, int32 Param, int32 Size, float Weight)
{
}
void UUIInvSlotBase::GetItemID(int32 Index)
{
	//return 0;
}
void UUIInvSlotBase::SetItemID(int32 Index, int32 Id)
{
}
void UUIInvSlotBase::GetItemParam(int32 Index)
{
	//return 0;
}
void UUIInvSlotBase::SetItemParam(int32 Index, int32 Param)
{
}
void SetItemLarge(int32 Index, bool large)
{
}
bool UUIInvSlotBase::IsItemLarge(int32 Index)
{
	return false;
}
void UUIInvSlotBase::SetContainer(AInvContainer* container)
{
	_cContainer = container;
	ScaleControl(nullptr);
}
void UUIInvSlotBase::GetContainer()
{
	//return _cContainer;
}
void UUIInvSlotBase::ScaleControl(UCanvas* Canvas)
{
	//Super::ScaleControl(Canvas);
	//iScaledItemWidth = iItemWidth * cFrame->fScaleX;
	//iScaledItemHeight = iItemHeight * cFrame->fScaleY;
}
void UUIInvSlotBase::SetItemDimensions(int32 Width, int32 Height, int32 wide, int32 High)
{
	iItemsWide = wide;
	iItemsHigh = High;
	iItemWidth = Width;
	iItemHeight = Height;
	/*
	iScaledItemWidth = iItemWidth * cFrame->fScaleX;
	iScaledItemHeight = iItemHeight * cFrame->fScaleY;
	*/
}
void UUIInvSlotBase::SetTexture(UMaterialInstance* Tex)
{
	_Texture = Tex;
}
void UUIInvSlotBase::SetTexture2(UMaterialInstance* Tex)
{
	_TexSel = Tex;
}