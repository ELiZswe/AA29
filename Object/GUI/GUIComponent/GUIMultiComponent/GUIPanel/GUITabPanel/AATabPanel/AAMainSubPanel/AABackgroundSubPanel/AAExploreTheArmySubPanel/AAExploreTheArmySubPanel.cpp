// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AAExploreTheArmySubPanel/AAExploreTheArmySubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AABrowserPanel/AABrowserPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploy_Internet/AADeploy_Internet.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploy_LAN/AADeploy_LAN.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAMainMenu/AAMainMenu.h"
#include "AA29/Object/GUI/GUIComponent/NMLContent/NMLContent.h"

UAAExploreTheArmySubPanel::UAAExploreTheArmySubPanel()
{
	
	UGUIButton* PlayNowButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PlayNowButton->Caption="PLAY NOW!";
	PlayNowButton->StyleName="SquareMenuButton";
	PlayNowButton->Hint="Start playing now and earn honor up to level 20!  Click here to see a list of some of the available servers!";
	PlayNowButton->WinTop=0.965;
	PlayNowButton->WinLeft=0.335;
	PlayNowButton->WinWidth=0.16;
	PlayNowButton->WinHeight=0.036;
	PlayNowButton->RenderWeight=0.6;
	//PlayNowButton->OnClick=AAExploreTheArmySubPanel.ButtonClick;
	//PlayNowButton->OnKeyEvent=PlayNowButton.InternalOnKeyEvent;
	UGUIButton* VisitVROButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	VisitVROButton->Caption="VISIT VRS";
	VisitVROButton->StyleName="SquareMenuButton";
	VisitVROButton->Hint="Meet the U.S. Army's Real Heroes and watch full-motion videos of their combat experiences.";
	VisitVROButton->WinTop=0.965;
	VisitVROButton->WinLeft=0.505;
	VisitVROButton->WinWidth=0.16;
	VisitVROButton->WinHeight=0.036;
	VisitVROButton->RenderWeight=0.6;
	//VisitVROButton->OnClick=AAExploreTheArmySubPanel.ButtonClick;
	//VisitVROButton->OnKeyEvent=VisitVROButton.InternalOnKeyEvent;
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing=0.02;
	MyPanel->bScaleItemsToWidth=true;
	MyPanel->WinTop=0.06625;
	MyPanel->WinHeight=0.8825;
	MyPanel->RenderWeight=0.6;
	MyPanel->bBoundToParent=true;
	MyPanel->bScaleToParent=true;
	
	btnVisitVRO = VisitVROButton;
	btnPlayNow = PlayNowButton;
	guicbPanel = MyPanel;
	PanelCaption = "Instant Action";

}

void UAAExploreTheArmySubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	UNMLContent* MyNML = nullptr;
	Super::InitComponent(MyController, MyOwner);
	//MyNML = new (None) UNMLContent::StaticClass();
	if (MyNML != nullptr)
	{
		if (MyNML->Controller == nullptr)
		{
			MyNML->InitComponent(MyController, MyOwner);
		}
		MyNML->ParseNMLFromServer("/x_ExploreTheArmy.nml", "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
	}
}

bool UAAExploreTheArmySubPanel::ButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case btnPlayNow:
		InstantActionFilterConfiguration();
		break;
	case btnVisitVRO:
		Controller.ConsoleCommand("start Recruiting_Station.aao");
		break;
	default:
		break;
	}
	*/
	return true;
}

void UAAExploreTheArmySubPanel::InstantActionFilterConfiguration()
{
	//UAADeploy_Internet::StaticClass().SetExploreTheArmyMode(false);
	//Controller.ReplaceMenu("AGP_Interface.AAMainMenu", "DEPLOYMENT");
}

void UAAExploreTheArmySubPanel::DisplayBrowser()
{
	UAABrowserPanel* aasbBrowser = nullptr;
	UAAMainMenu* aamm = nullptr;
	UAADeploy_Internet* aabslpi = nullptr;
	aamm = Cast<UAAMainMenu>(PageOwner);
	if (aamm != nullptr)
	{
		aasbBrowser = Cast<UAABrowserPanel>(aamm->c_Tab->BorrowPanel("AA BROWSER"));
		if (aasbBrowser != nullptr)
		{
			aabslpi = Cast<UAADeploy_Internet>(aasbBrowser->c_Tabs->BorrowPanel("Internet"));
			if (aabslpi != nullptr)
			{
				aabslpi->SetExploreTheArmyMode(true);
				aamm->c_Tab->ActivateTabByName("AA BROWSER", true);
				aasbBrowser->c_Tabs->ActivateTabByName("Internet", true);
			}
		}
	}
}

void UAAExploreTheArmySubPanel::DisplayLANBrowser()
{
	UAABrowserPanel* aasbBrowser = nullptr;
	UAAMainMenu* aamm = nullptr;
	UAADeploy_LAN* aabslpi = nullptr;
	aamm = Cast<UAAMainMenu>(PageOwner);
	if (aamm != nullptr)
	{
		aasbBrowser = Cast<UAABrowserPanel>(aamm->c_Tab->BorrowPanel("AA BROWSER"));
		if (aasbBrowser != nullptr)
		{
			aamm->c_Tab->ActivateTabByName("AA BROWSER", true);
			aasbBrowser->c_Tabs->ActivateTabByName("LAN", true);
			aabslpi = Cast<UAADeploy_LAN>(aasbBrowser->c_Tabs->BorrowPanel("Internet"));
			if (aabslpi != nullptr)
			{
				aabslpi->ShowPanel(true);
			}
		}
	}
}
