// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIContentPanel/GUIContentPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIScrollBarBase.h"

UGUIContentPanel::UGUIContentPanel()
{
	ItemSpacing = 0.01;
	bInitialPredraw = true;
	RenderWeight = 0;
}

void UGUIContentPanel::ScrollAlignThumb()
{
	float NewPos = 0;
	/*
	if (Elements.Num() == 0)
	{
		NewPos = 0;
	}
	else
	{
		NewPos = TopOffset / PanelSize - ClientBounds[3] - ClientBounds[1];
	}
	MyScrollBar.GripPos =FMath::Clamp(NewPos, 0, 1);
	*/
}

UGUIComponent* UGUIContentPanel::AppendComponent(UGUIComponent* NewComp, bool SkipRemap)
{
	/*
	AppendComponent(NewComp, SkipRemap);
	NewComp.bScaleToParent = true;
	NewComp.bBoundToParent = true;
	Elements[Elements.Num()] = NewComp;
	*/
	return NewComp;
}

UGUIComponent* UGUIContentPanel::InsertComponent(UGUIComponent* NewComp, int32 Index, bool SkipRemap)
{
	/*
	InsertComponent(NewComp, Index, SkipRemap);
	NewComp.bScaleToParent = true;
	NewComp.bBoundToParent = true;
	Elements.insert(Index, 1);
	Elements[Index] = NewComp;
	*/
	return NewComp;
}

bool UGUIContentPanel::RemoveComponent(UGUIComponent* Comp, bool SkipRemap)
{
	/*
	int32 i = 0;
	int32 Num;
	Num = -1;
	i = 0;
	if (i < Elements.Num())
	{
		if (Elements[i] == Comp)
		{
			Num = i;
		}
		else
		{
			i++;
		}
	}
	if (Num < 0)
	{
		return false;
	}
	if (RemoveComponent(Comp, SkipRemap))
	{
		Elements.RemoveAt(Num, 1);
		return true;
	}
	*/
	return false;
}

bool UGUIContentPanel::ValidIndex(int32 idx)
{
	/*
	if (idx < 0 || idx >= Elements.Num())
	{
		return false;
	}
	*/
	return true;
}

UGUIComponent* UGUIContentPanel::GetComponent(int32 idx)
{
	if (ValidIndex(idx))
	{
		return Elements[idx];
	}
	return nullptr;
}

int32 UGUIContentPanel::FindComponent(UGUIComponent* Component)
{
	/*
	int32 i = 0;
	for (i = 0; i < Elements.Num(); i++)
	{
		if (Elements[i] == Component)
		{
			return i;
		}
	}
	*/
	return -1;
}
