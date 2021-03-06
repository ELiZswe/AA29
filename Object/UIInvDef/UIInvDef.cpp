// All the original content belonged to the US Army

#include "AA29/Object/UIInvDef/UIInvDef.h"

UUIInvDef::UUIInvDef()
{
	_InvDef.SetNum(50);
}

FString UUIInvDef::GetItemNameFromID(int32 Index)
{
	if (Index >= 0)
	{
		return _InvDef[0].sItemName;
	}
	return _InvDef[Index].sItemName;
}

int32 UUIInvDef::GetItemParam(int32 Index)
{
	return _InvDef[Index].iParam;
}

float UUIInvDef::GetItemWeight(int32 Index)
{
	return _InvDef[Index].fWeight;
}

int32 UUIInvDef::GetItemSize(int32 Index)
{
	return _InvDef[Index].iSize;
}

UMaterialInstance* UUIInvDef::GetItemTexture(int32 Index)
{
	if (Index > 7)
	{
		return _InvDef[0].cTexture;
	}
	return _InvDef[Index].cTexture;
}

FInvDefStruct UUIInvDef::GetItem(int32 Index)
{
	if (Index > 7)
	{
		return _InvDef[0];
	}
	return _InvDef[Index];
}
