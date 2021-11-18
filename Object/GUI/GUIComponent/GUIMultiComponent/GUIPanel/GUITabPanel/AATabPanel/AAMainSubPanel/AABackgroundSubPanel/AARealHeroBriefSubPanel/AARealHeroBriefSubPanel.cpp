// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARealHeroBriefSubPanel/AARealHeroBriefSubPanel.h"

UAARealHeroBriefSubPanel::UAARealHeroBriefSubPanel()
{
	PanelCaption = "Record Brief for %RealHeroName%";
}



void ShowSubPanel()
{
}

void SetRealHeroStatsClass(UAARealHeroStats* NewRealHeroStatsClass)
{
	/*
	if (NewRealHeroStatsClass != None)
	{
		MyRealHeroStatsClass = NewRealHeroStatsClass;
		h_Header.SetCaption(Repl(Default.PanelCaption, "%RealHeroName%", MyRealHeroStatsClass.Default.HeroNameAndRank));
	}
	*/
}
