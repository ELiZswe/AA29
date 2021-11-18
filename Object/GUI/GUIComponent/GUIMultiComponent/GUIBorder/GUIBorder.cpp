// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIBorder.h"

UGUIBorder::UGUIBorder()
{
	Justification = EeTextAlign::TXTA_Center;
	TextIndent = 20;
	PropagateVisibility = true;
	StyleName = "Footer";
	bNeverFocus = true;
	bRequiresStyle = true;
}


void UGUIBorder::SetCaption(FString NewCaption)
{
	Caption = NewCaption;
}

FString UGUIBorder::GetCaption()
{
	return Caption;
}