// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIScrollingText/GUIScrollingText.h"

UGUIScrollingText::UGUIScrollingText()
{
	TextAlign = EeTextAlign::TXTA_Center;
	TextColor = FColor(156, 201, 168, 255);
	FocusedTextColor = FColor(229, 248, 251, 255);
	TextStyle = EMenuRenderStyle::MSTY_Normal;
	TextFont = "AAFontMedium";
	bTransparent = true;
	BackColor = FColor(0, 0, 0, 255);
	ScrollRate = 2;
}

void UGUIScrollingText::AddLine(FString sString)
{
	//Content[Content.Length] = sString;
}

void UGUIScrollingText::LoadTextFromFile(FString Filename)
{
	/*
	FString Line = "";
	Content.remove(0, Content.Length);
	if (FOpen(Filename))
	{
		if (FReadLine(Line))
		{
			AddLine(Line);
		}
		FClose();
	}
	else
	{
		AddLine("Could not load file");
		AddLine(Filename);
	}
	*/
}