// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIFont/AAFontMidGame/AAFontMidGame.h"

UAAFontMidGame::UAAFontMidGame()
{
	FontScreenWidth = { 2048, 1600, 1280, 1024, 800, 640, 600 };
	KeyName = "AAFontMidGame";
	//FontArrayNames =
	CharDelay = 0.0025;
	//EOLDelay = 0.5;
	TextAlign = 2;
	//__OnCreateComponent__Delegate = "ObjectivesList.InternalOnCreateComponent"
	StyleName = "SmallText";
	WinTop = 0.1;
	WinLeft = 0.82;
	WinWidth = 0.15;
	WinHeight = 0.7;
	TabOrder = 1;
	bBoundToParent = true;
}




void UAAFontMidGame::GetMidGameFont(int32 XRes)
{
	/*
	local int i;
	for (i = 0; i < 7; i++)
	{
		if (Default.FontScreenWidth[i] <= XRes)
		{
			Return LoadFontStatic(i);
		}
	}
	Return LoadFontStatic(6);
	*/
}
/*
AFont* UAAFontMidGame::GetFont(int32 XRes)
{
	Return GetMidGameFont(XRes);
}
*/