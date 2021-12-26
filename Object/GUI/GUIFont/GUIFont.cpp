// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIFont/GUIFont.h"

UGUIFont::UGUIFont()
{

}

//native Event Font GetFont(int XRes);
UFont* UGUIFont::GetFont(int XRes)
{
	return nullptr;    //FAKE   /EliZ
}

UFont* UGUIFont::LoadFontStatic(int32 i)
{
	/*
	if (i >= Default.FontArrayFonts.Length || Default.FontArrayFonts[i] == nullptr)
	{
		Default.FontArrayFonts[i] = Font(DynamicLoadObject(Default.FontArrayNames[i], Class'Font'));
		if (Default.FontArrayFonts[i] == nullptr)
		{
			Log("Warning: " $ Default.Class $ " Couldn't dynamically load font " $ Default.FontArrayNames[i]);
		}
	}
	*/
	return GetDefault<UGUIFont>()->FontArrayFonts[i];
}

UFont* UGUIFont::LoadFont(int32 i)
{
	/*
	if (i >= FontArrayFonts.Length || FontArrayFonts[i] == nullptr)
	{
		FontArrayFonts[i] = Font(DynamicLoadObject(FontArrayNames[i], Class'Font'));
		if (FontArrayFonts[i] == nullptr)
		{
			Log("Warning: " $ Self $ " Couldn't dynamically load font " $ FontArrayNames[i]);
		}
	}
	*/
	return FontArrayFonts[i];
}
