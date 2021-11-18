// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/GUITabPanel.h"

UGUITabPanel::UGUITabPanel()
{

}

void UGUITabPanel::Refresh()
{
}

void UGUITabPanel::InitPanel()
{
}

void UGUITabPanel::OnDestroyPanel(bool bCancelled)
{
	MyButton = nullptr;
}

void UGUITabPanel::Free()
{
	/*
	OnDestroyPanel(true);
	Super::Free();
	*/
}

void UGUITabPanel::ShowPanel(bool bShow)
{
	/*
	if ((Controller != None) && Controller.bModAuthor)
	{
		Log("# # # #" @ MyButton.Caption @ "ShowPanel() " @ string(bShow), 'ModAuthor');
	}
	SetVisibility(bShow);
	*/
}

bool UGUITabPanel::CanShowPanel()
{
	return true;
}
