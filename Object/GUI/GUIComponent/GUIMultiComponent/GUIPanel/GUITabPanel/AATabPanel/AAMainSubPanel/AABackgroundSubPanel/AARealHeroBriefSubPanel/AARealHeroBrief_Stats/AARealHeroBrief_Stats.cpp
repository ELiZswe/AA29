// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARealHeroBriefSubPanel/AARealHeroBrief_Stats/AARealHeroBrief_Stats.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/AARealHeroStats/AARealHeroStats.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/NMLContent/NMLContent.h"

UAARealHeroBrief_Stats::UAARealHeroBrief_Stats()
{
	UGUIContentBox* NMLBioPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	NMLBioPanel->ItemSpacing=0.02;
	NMLBioPanel->bScaleItemsToWidth=true;
	NMLBioPanel->WinTop=0.12475;
	NMLBioPanel->WinHeight=0.824;
	NMLBioPanel->RenderWeight=0.6;
	NMLBioPanel->bBoundToParent=true;
	NMLBioPanel->bScaleToParent=true;

	gcb_NMLContent = NMLBioPanel;
	PageToParse = "/x_realheroes_%RealHeroName%.nml";
	NMLServer = "dms1.americasarmy.com";

}

void UAARealHeroBrief_Stats::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyNMLContent = new (None) UNMLContent::StaticClass();
	if (MyNMLContent != nullptr)
	{
		if (MyNMLContent.Controller == nullptr)
		{
			MyNMLContent.InitComponent(MyController, MyOwner);
		}
	}
	*/
}

void UAARealHeroBrief_Stats::SetRealHeroStatsClass(UAARealHeroStats* NewRealHeroStatsClass)
{
	/*
	Super::SetRealHeroStatsClass(NewRealHeroStatsClass);
	PageToParse = Repl(Default.PageToParse, "%RealHeroName%", NewRealHeroStatsClass.Default.ShortName);
	if (MyNMLContent != nullptr)
	{
		MyNMLContent.ParseNMLFromServer(PageToParse, NMLServer, 80, gcb_NMLContent, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}
