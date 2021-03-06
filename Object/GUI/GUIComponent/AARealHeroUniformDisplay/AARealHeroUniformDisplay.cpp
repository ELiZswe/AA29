// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/AARealHeroUniformDisplay/AARealHeroUniformDisplay.h"
#include "AA29/Object/AARealHeroStats/AARealHeroStats.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"

UAARealHeroUniformDisplay::UAARealHeroUniformDisplay()
{
	Uniforms = { "Army Combat (ACU)","Class A" };
	bAcceptsInput = true;
	bCaptureMouse = true;
	bNeverFocus = true;
	//__OnClick__Delegate = "AARealHeroUniformDisplay.InternalOnClick"
}

void UAARealHeroUniformDisplay::dOnDescribeBadge(FString BadgeToDescribe, bool bForceLoad)
{
}

void UAARealHeroUniformDisplay::SwitchUniforms(int32 Index)
{
	if (Index >= Uniforms.Num())
	{
		return;
	}
	switch(Index)
	{
			case 0:
				//MyRealHeroStatsClass
				UniformImage = GetDefault<UAARealHeroStats>()->ACUUniform;
				break;
			case 1:
				UniformImage = GetDefault<UAARealHeroStats>()->ClassAUniform;
				break;
			default:
				break;
	}
	if (UniformIndex != Index)
	{
		dOnDescribeBadge("", false);
	}
	UniformIndex = Index;
}

bool UAARealHeroUniformDisplay::InternalOnClick(UGUIComponent* Sender)
{
	if (HighlightedBadge >= 0)
	{
		switch(UniformIndex)
		{
			case 0:
				//dOnDescribeBadge(MyRealHeroStatsClass.Default.ACUBadges[HighlightedBadge].BadgeName, false);
				break;
			case 1:
				//dOnDescribeBadge(MyRealHeroStatsClass.Default.ClassABadges[HighlightedBadge].BadgeName, false);
				break;
			default:
				break;
		}
	}
	return false;
}
