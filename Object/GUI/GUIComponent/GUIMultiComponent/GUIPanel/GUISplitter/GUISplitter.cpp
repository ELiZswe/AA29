// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUISplitter::UGUISplitter()
{
	DefaultPanels.SetNum(2);
	SplitPosition = 0.5;
	bDrawSplitter = true;
	SplitAreaSize = 8;
	StyleName = "SquareButton";
	bAcceptsInput = true;
	bNeverFocus = true;
	bRequiresStyle = true;
}

void UGUISplitter::OnReleaseSplitter(UGUIComponent* Sender, float NewPosition)
{
}

void UGUISplitter::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (DefaultPanels[0] != "")
	{
		Panels[0] = AddComponent(DefaultPanels[0], DefaultPanels[1] != "");
		if (DefaultPanels[1] != "")
		{
			Panels[1] = AddComponent(DefaultPanels[1]);
		}
	}
	*/
}

UGUIComponent* UGUISplitter::AppendComponent(UGUIComponent* NewComp, bool SkipRemap)
{
	/*
	OnCreateComponent(NewComp, this);
	Controls[Controls.Num()] = NewComp;
	NewComp.InitComponent(Controller, this);
	NewComp.bBoundToParent = true;
	NewComp.bScaleToParent = true;
	if (!SkipRemap)
	{
		RemapComponents();
	}
	*/
	return NewComp;
}

//native Function SplitterUpdatePositions();
void UGUISplitter::SplitterUpdatePositions()
{

}
