// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUIPanel::UGUIPanel()
{
	PropagateVisibility = true;
	bTabStop = false;
}

bool UGUIPanel::OnPostDraw(UCanvas* Canvas)
{
	return false;   //FAKE   /ELiZ
}

void UGUIPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < Controls.Num(); i++)
	{
		Controls[i].bBoundToParent = true;
		Controls[i].bScaleToParent = true;
	}
	*/
}

void UGUIPanel::NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3)
{
}
