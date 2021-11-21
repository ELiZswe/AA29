// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"

UGUIStyles::UGUIStyles()
{
	AlternateKeyName.SetNum(2);
	FontNames.SetNum(15);
	Fonts.SetNum(15);
	FontColors.SetNum(5);
	FontBKColors.SetNum(5);
	ImgColors.SetNum(5);
	RStyles.SetNum(5);
	Images.SetNum(5);
	ImgStyle.SetNum(5);
	ImgWidths.SetNum(5);
	ImgHeights.SetNum(5);
	BorderOffsets.SetNum(4);

	FontNames = { "UT2SmallFont", "UT2SmallFont", "UT2SmallFont", "UT2SmallFont", "UT2SmallFont", "UT2MenuFont", "UT2MenuFont", "UT2MenuFont", "UT2MenuFont", "UT2MenuFont", "UT2LargeFont", "UT2LargeFont", "UT2LargeFont", "UT2LargeFont", "UT2LargeFont" };
	FontColors = { FColor(64, 0, 0, 255), FColor(64, 0, 0, 255), FColor(80, 32, 32, 255), FColor(80, 32, 32, 255),  FColor(128, 0, 0, 255) };
	FontBKColors = { FColor(0, 0, 0, 255), FColor(0, 0, 0, 255), FColor(0, 0, 0, 255), FColor(0, 0, 0, 255), FColor(0, 0, 0, 255) };
	ImgColors = { FColor(255, 255, 255, 255),FColor(255, 255, 255, 255),FColor(255, 255, 255, 255),FColor(255, 255, 255, 255),FColor(128, 128, 128, 255) };
	RStyles = { EMenuRenderStyle::MSTY_Normal , EMenuRenderStyle::MSTY_Normal, EMenuRenderStyle::MSTY_Normal, EMenuRenderStyle::MSTY_Normal, EMenuRenderStyle::MSTY_Normal };
	ImgStyle = { EImgStyle::ISTY_Stretched, EImgStyle::ISTY_Stretched, EImgStyle::ISTY_Stretched, EImgStyle::ISTY_Stretched, EImgStyle::ISTY_Stretched };
	ImgWidths = {-1, -1, -1, -1, -1};
	ImgHeights = { -1, -1, -1, -1, -1 };
	BorderOffsets = { 10, 10, 10, 10 };
}

void UGUIStyles::OnDraw(UCanvas* Canvas, EMenuState MenuState, float Left, float Top, float Width, float Height)
{
}
void UGUIStyles::OnDrawText(UCanvas* Canvas, EMenuState MenuState, float Left, float Top, float Width, float Height, ETextAlign Align, FString Text, EFontScale FontScale)
{
}

//native static final Function Draw(Canvas Canvas, GUI.eMenuState MenuState, float Left, float Top, float Width, float Height);
void UGUIStyles::Draw(UCanvas* Canvas, EMenuState MenuState, float Left, float Top, float Width, float Height)
{
}

//native static final Function DrawText(Canvas Canvas, GUI.eMenuState MenuState, float Left, float Top, float Width, float Height, GUI.eTextAlign Align, string Text, GUI.eFontScale FontScale);
void UGUIStyles::DrawText(UCanvas* Canvas, EMenuState MenuState, float Left, float Top, float Width, float Height, ETextAlign Align, FString Text, EFontScale FontScale)
{
}

//native static final Function TextSize(Canvas Canvas, GUI.eMenuState MenuState, string Text, out float XL, out float YL, GUI.eFontScale FontScale);
void UGUIStyles::TextSize(UCanvas* Canvas, EMenuState MenuState, FString Text, float& XL, float& YL, EFontScale FontScale)
{

}

void UGUIStyles::Initialize()
{
	/*
	local int i;
	i = 0;
	if (i < 15 && i < 15)
	{
		if (FontNames[i] != "")
		{
			Fonts[i] = Controller.GetMenuFont(FontNames[i]);
		}
		i++;
	}
	*/
}
