// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIFont/GUIFont.h"

UGUIFont::UGUIFont()
{

}

//native Event Font GetFont(int XRes);
/*
AFont* UGUIFont::GetFont(int XRes)
{

}
*/
void UGUIFont::LoadFontStatic(int32 i)
{
	/*
	if (i >= Default.FontArrayFonts.Length || Default.FontArrayFonts[i] == None)
	{
		Default.FontArrayFonts[i] = Font(DynamicLoadObject(Default.FontArrayNames[i], Class'Font'));
		if (Default.FontArrayFonts[i] == None)
		{
			Log("Warning: " $ Default.Class $ " Couldn't dynamically load font " $ Default.FontArrayNames[i]);
		}
	}
	Return Default.FontArrayFonts[i];
	*/
}
void UGUIFont::LoadFont(int32 i)
{
	/*
	if (i >= FontArrayFonts.Length || FontArrayFonts[i] == None)
	{
		FontArrayFonts[i] = Font(DynamicLoadObject(FontArrayNames[i], Class'Font'));
		if (FontArrayFonts[i] == None)
		{
			Log("Warning: " $ Self $ " Couldn't dynamically load font " $ FontArrayNames[i]);
		}
	}
	Return FontArrayFonts[i];
	*/
}