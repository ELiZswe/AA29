// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARealHeroesSubPanel/AARealHeroesSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
UAARealHeroesSubPanel::UAARealHeroesSubPanel()
{
	UGUIButton* VisitVROButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	VisitVROButton->Caption="VISIT VRS";
	VisitVROButton->StyleName="SquareMenuButton";
	VisitVROButton->Hint="Meet the U.S. Army's Real Heroes and watch full-motion videos.";
	VisitVROButton->WinTop=0.965;
	VisitVROButton->WinLeft=0.42;
	VisitVROButton->WinWidth=0.16;
	VisitVROButton->WinHeight=0.036;
	VisitVROButton->RenderWeight=0.6;
	//VisitVROButton->OnClick=AARealHeroesSubPanel.ButtonClick;
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
	guicbPanel = MyPanel;
	PanelCaption = "Meet the U.S. Army's Real Heroes";
}

void UAARealHeroesSubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local NMLContent MyNML;
	Super::InitComponent(MyController, MyOwner);
	MyNML = new (None) class'AGP_Interface.NMLContent';
	if (MyNML != None)
	{
		if (MyNML.Controller == None)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
		MyNML.ParseNMLFromServer("/x_RealHeroes.nml", "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}

bool UAARealHeroesSubPanel::ButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case btnVisitVRO:
		Controller.ConsoleCommand("start Recruiting_Station.aao");
		break;
	default:
		break;
	}
	*/
	return true;
}