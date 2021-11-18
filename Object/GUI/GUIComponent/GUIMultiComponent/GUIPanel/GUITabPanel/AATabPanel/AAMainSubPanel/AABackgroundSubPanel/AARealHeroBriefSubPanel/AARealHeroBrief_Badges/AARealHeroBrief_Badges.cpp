// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARealHeroBriefSubPanel/AARealHeroBrief_Badges/AARealHeroBrief_Badges.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIContentPanel/AAGUIBadgeDescription/AAGUIBadgeDescription.h"
#include "AA29/Object/GUI/GUIComponent/AARealHeroUniformDisplay/AARealHeroUniformDisplay.h"

UAARealHeroBrief_Badges::UAARealHeroBrief_Badges()
{
	UAAGUIBadgeDescription* BadgeDescription = NewObject<UAAGUIBadgeDescription>(UAAGUIBadgeDescription::StaticClass());
	BadgeDescription->WinTop = 0.168254;
	BadgeDescription->WinLeft = 0.65;
	BadgeDescription->WinWidth = 0.34;
	BadgeDescription->WinHeight = 0.75;
	BadgeDescription->RenderWeight = 0.9;
	BadgeDescription->bBoundToParent = true;
	BadgeDescription->bScaleToParent = true;
	//BadgeDescription->OnPreDraw = BadgeDescription.MyPreDraw;
	UAARealHeroUniformDisplay* UniformDisplay = NewObject<UAARealHeroUniformDisplay>(UAARealHeroUniformDisplay::StaticClass());
	UniformDisplay->WinTop = 0.12475;
	UniformDisplay->WinLeft = 0.005;
	UniformDisplay->WinWidth = 0.835;
	UniformDisplay->WinHeight = 0.835;
	UniformDisplay->RenderWeight = 0.8;
	UniformDisplay->bBoundToParent = true;
	UniformDisplay->bScaleToParent = true;
	//UniformDisplay->OnClick = UniformDisplay.InternalOnClick;

	ud_UniformDisplay = UniformDisplay;
	bd_BadgeDescription = BadgeDescription;

}

void UAARealHeroBrief_Badges::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
	//ud_UniformDisplay.__dOnDescribeBadge__Delegate = bd_BadgeDescription.DescribeBadge;
}

void UAARealHeroBrief_Badges::SetRealHeroStatsClass(UAARealHeroStats* NewRealHeroStatsClass)
{
	/*
	Super::SetRealHeroStatsClass(NewRealHeroStatsClass);
	ud_UniformDisplay.MyRealHeroStatsClass = MyRealHeroStatsClass;
	SetUniform(ud_UniformDisplay.UniformIndex);
	ud_UniformDisplay.dOnDescribeBadge("", false);
	*/
}

void UAARealHeroBrief_Badges::SetUniform(int32 UniformIndex)
{
	//ud_UniformDisplay.SwitchUniforms(UniformIndex);
}
