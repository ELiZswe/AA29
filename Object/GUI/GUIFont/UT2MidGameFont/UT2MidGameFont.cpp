// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIFont/UT2MidGameFont/UT2MidGameFont.h"

UUT2MidGameFont::UUT2MidGameFont()
{
	FontScreenWidth.SetNum(7);
	FontScreenWidth = { 2048, 1600, 1280, 1024, 800, 640, 600 };
	KeyName = "UT2MidGameFont";
	FontArrayNames = { "UT2003Fonts.FontEurostile17","UT2003Fonts.FontEurostile14","UT2003Fonts.FontEurostile11","UT2003Fonts.FontEurostile11","UT2003Fonts.FontEurostile9","UT2003Fonts.FontNeuzeit9","UT2003Fonts.FontSmallText" };
}

UFont* UUT2MidGameFont::GetMidGameFont(int32 XRes)
{
	int32 i=0;
	/*
	for (i = 0; i < 7; i++)
	{
		if (Default.FontScreenWidth[i] <= XRes)
		{
			return LoadFontStatic(i);
		}
	}
	return LoadFontStatic(6);
	*/
	return nullptr;     //FAKE   /ELizZ
}

UFont* UUT2MidGameFont::GetFont(int32 XRes)
{
	return GetMidGameFont(XRes);
}

