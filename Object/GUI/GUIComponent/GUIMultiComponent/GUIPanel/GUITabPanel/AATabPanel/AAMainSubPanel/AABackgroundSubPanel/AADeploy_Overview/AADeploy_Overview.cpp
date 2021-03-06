// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploy_Overview/AADeploy_Overview.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/NMLContent/NMLContent.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploymentDetailsSubPanel/AADeploymentDetailsSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AADeploymentPanel/AADeploymentPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAMainMenu/AAMainMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUIVertTabControl/GUIVertTabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/AAGUITabControl/AAGUITabControl.h"

UAADeploy_Overview::UAADeploy_Overview()
{
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing = 0.02;
	MyPanel->bScaleItemsToWidth = true;
	MyPanel->WinTop = 0.06625;
	MyPanel->WinHeight = 0.8825;
	MyPanel->RenderWeight = 0.6;
	MyPanel->bBoundToParent = true;
	MyPanel->bScaleToParent = true;
	guicbPanel = MyPanel;
	DefaultPage = "/x_deployment_overview.nml";
	PanelCaption = "America's Army Deployment Overview";
}

void UAADeploy_Overview::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	//MyNML = new (None) UNMLContent::StaticClass();
	if (MyNML != nullptr)
	{
		if (MyNML->Controller == nullptr)
		{
			MyNML->InitComponent(MyController, MyOwner);
		}
		//MyNML.__dInterPanelLink__Delegate = OnInterPanelLink;
		MyNML->ParseNMLFromServer(DefaultPage, "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
	}
}

void UAADeploy_Overview::ShowPanel(bool bShow)
{
	if (bShow && bHasLeftPage)
	{
		bHasLeftPage = false;
		MyNML->ParseNMLFromFile(MyNML->FixFilePath(DefaultPage), guicbPanel);
	}
	else
	{
		bHasLeftPage = true;
	}
}

void UAADeploy_Overview::OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3)
{
	UAAMainMenu* aamm = nullptr;
	UAADeploymentPanel* aadp = nullptr;
	UAADeploymentDetailsSubPanel* aadd = nullptr;
	aamm = Cast<UAAMainMenu>(PageOwner);
	if (aamm != nullptr)
	{
		aadp = Cast<UAADeploymentPanel>(aamm->c_Tab->BorrowPanel("DEPLOYMENT"));
		if (aadp != nullptr)
		{
			aadd = Cast<UAADeploymentDetailsSubPanel>(aadp->c_Tabs->BorrowPanel(PanelName));
			if (aadd != nullptr)
			{
				aadd->co_Tour->SetIndex(0);
				aadp->c_Tabs->ActivateTabByName(PanelName, true);
			}
		}
	}
}
