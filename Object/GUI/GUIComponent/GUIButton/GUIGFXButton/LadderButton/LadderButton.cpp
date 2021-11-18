// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/LadderButton/LadderButton.h"
#include "AA29/Object/MatchInfo/MatchInfo.h"

ULadderButton::ULadderButton()
{
	Position = EIconPosition::ICP_Scaled;
	bClientBound = true;
	StyleName = "LadderButton";
}


void ULadderButton::SetState(int32 rung)
{
	FString NewStyleName;
	if (MatchInfo == nullptr)
	{
		return;
	}
	if (rung < MatchIndex)
	{
		//Graphic = Material(DynamicLoadObject("SinglePlayerThumbs." $ MatchInfo.LevelName $ "_G", Class'Material', true));
		MenuState = EMenuState::MSAT_Disabled;
		NewStyleName = "LadderButton";
	}
	else
	{
		//Graphic = Material(DynamicLoadObject("SinglePlayerThumbs." $ MatchInfo.LevelName, Class'Material', true));
		MenuState = EMenuState::MSAT_Blurry;
		if (rung == MatchIndex)
		{
			NewStyleName = "LadderButton";
		}
		else
		{
			NewStyleName = "LadderButtonHi";
		}
	}
	if (!(NewStyleName == StyleName))
	{
		StyleName = NewStyleName;
		//Style = Controller.GetStyle(StyleName, FontScale);
		
		/*
		if (Style == nullptr)
		{
			//Log("NewStyle IS None");
		}
		*/
	}
}