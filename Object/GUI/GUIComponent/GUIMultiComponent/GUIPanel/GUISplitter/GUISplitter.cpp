// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"

UGUISplitter::UGUISplitter()
{
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
	OnCreateComponent(NewComp, Self);
	Controls[Controls.Length] = NewComp;
	NewComp.InitComponent(Controller, Self);
	NewComp.bBoundToParent = True;
	NewComp.bScaleToParent = True;
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
