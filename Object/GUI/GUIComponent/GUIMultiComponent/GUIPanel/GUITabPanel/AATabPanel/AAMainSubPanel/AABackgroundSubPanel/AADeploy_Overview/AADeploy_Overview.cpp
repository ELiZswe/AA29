// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploy_Overview/AADeploy_Overview.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"

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
	/*
	Super::InitComponent(MyController, MyOwner);
	MyNML = new (None) class'AGP_Interface.NMLContent';
	if (MyNML != None)
	{
		if (MyNML.Controller == None)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
		MyNML.__dInterPanelLink__Delegate = OnInterPanelLink;
		MyNML.ParseNMLFromServer(DefaultPage, "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}

void UAADeploy_Overview::ShowPanel(bool bShow)
{
	/*
	if (bShow && bHasLeftPage)
	{
		bHasLeftPage = false;
		MyNML.ParseNMLFromFile(MyNML.FixFilePath(DefaultPage), guicbPanel);
	}
	else
	{
		bHasLeftPage = true;
	}
	*/
}

void UAADeploy_Overview::OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3)
{
	/*
	local AAMainMenu aamm;
	local AADeploymentPanel aadp;
	local AADeploymentDetailsSubPanel aadd;
	aamm = AAMainMenu(PageOwner);
	if (aamm != None)
	{
		aadp = AADeploymentPanel(aamm.c_Tab.BorrowPanel("DEPLOYMENT"));
		if (aadp != None)
		{
			aadd = AADeploymentDetailsSubPanel(aadp.c_Tabs.BorrowPanel(PanelName));
			if (aadd != None)
			{
				aadd.co_Tour.SetIndex(0);
				aadp.c_Tabs.ActivateTabByName(PanelName, true);
			}
		}
	}
	*/
}