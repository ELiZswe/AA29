// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIContentPanel/GUIContentPanel.h"

UGUIContentPanel::UGUIContentPanel()
{
	ItemSpacing = 0.01;
	bInitialPredraw = true;
	RenderWeight = 0;
}

void UGUIContentPanel::ScrollAlignThumb()
{
	/*
	local float NewPos;
	if (Elements.Length == 0)
	{
		NewPos = 0;
	}
	else
	{
		NewPos = TopOffset / PanelSize - ClientBounds[3] - ClientBounds[1];
	}
	MyScrollBar.GripPos = FClamp(NewPos, 0, 1);
	*/
}

UGUIComponent* UGUIContentPanel::AppendComponent(UGUIComponent* NewComp, bool SkipRemap)
{
	/*
	AppendComponent(NewComp, SkipRemap);
	NewComp.bScaleToParent = True;
	NewComp.bBoundToParent = True;
	Elements[Elements.Length] = NewComp;
	*/
	return NewComp;
}

UGUIComponent* UGUIContentPanel::InsertComponent(UGUIComponent* NewComp, int32 Index, bool SkipRemap)
{
	/*
	InsertComponent(NewComp, Index, SkipRemap);
	NewComp.bScaleToParent = True;
	NewComp.bBoundToParent = True;
	Elements.insert(Index, 1);
	Elements[Index] = NewComp;
	*/
	return NewComp;
}
bool UGUIContentPanel::RemoveComponent(UGUIComponent* Comp, bool SkipRemap)
{
	/*
	local int i;
	local int Num;
	Num = -1;
	i = 0;
	if (i < Elements.Length)
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
		Elements.remove(Num, 1);
		return true;
	}
	*/
	return false;
}

bool UGUIContentPanel::ValidIndex(int32 idx)
{
	/*
	if (idx < 0 || idx >= Elements.Length)
	{
		return false;
	}
	*/
	return true;
}

void UGUIContentPanel::GetComponent(int32 idx)
{
	/*
	if (ValidIndex(idx))
	{
		Return Elements[idx];
	}
	Return None;
	*/
}

int32 UGUIContentPanel::FindComponent(UGUIComponent* Component)
{
	/*
	local int i;
	for (i = 0; i < Elements.Length; i++)
	{
		if (Elements[i] == Component)
		{
			Return i;
		}
	}
	*/
	return -1;
}