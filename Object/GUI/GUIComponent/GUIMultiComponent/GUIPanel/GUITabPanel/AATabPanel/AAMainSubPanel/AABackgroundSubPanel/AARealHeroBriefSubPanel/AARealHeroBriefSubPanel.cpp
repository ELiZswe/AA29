// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARealHeroBriefSubPanel/AARealHeroBriefSubPanel.h"
#include "AA29/Object/AARealHeroStats/AARealHeroStats.h"

UAARealHeroBriefSubPanel::UAARealHeroBriefSubPanel()
{
	PanelCaption = "Record Brief for %RealHeroName%";
}

void UAARealHeroBriefSubPanel::ShowSubPanel()
{
}

void UAARealHeroBriefSubPanel::SetRealHeroStatsClass(UAARealHeroStats* NewRealHeroStatsClass)
{
	/*
	if (NewRealHeroStatsClass != nullptr)
	{
		MyRealHeroStatsClass = NewRealHeroStatsClass;
		h_Header.SetCaption(Repl(Default.PanelCaption, "%RealHeroName%", MyRealHeroStatsClass.Default.HeroNameAndRank));
	}
	*/
}
