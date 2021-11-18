// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/AARealHeroUniformDisplay/AARealHeroUniformDisplay.h"


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
	/*
	if (Index >= Uniforms.Length)
	{
		Return;
	}
	Switch(Index)
	{
			case 0:
				UniformImage = MyRealHeroStatsClass.Default.ACUUniform;
				break;
			case 1:
				UniformImage = MyRealHeroStatsClass.Default.ClassAUniform;
				break;
			default:
	}
	if (UniformIndex != Index)
	{
		dOnDescribeBadge("", false);
	}
	UniformIndex = Index;
	*/
}
void UAARealHeroUniformDisplay::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (HighlightedBadge >= 0)
	{
		Switch(UniformIndex)
		{
			case 0:
				dOnDescribeBadge(MyRealHeroStatsClass.Default.ACUBadges[HighlightedBadge].BadgeName, false);
				break;
			case 1:
				dOnDescribeBadge(MyRealHeroStatsClass.Default.ClassABadges[HighlightedBadge].BadgeName, false);
				break;
			default:
		}
	}
	Return False;
	*/
}