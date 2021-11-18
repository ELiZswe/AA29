// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIQuestionPage/AAQuestionPage/AAQuestionPage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAQuestionPage::UAAQuestionPage()
{
	UGUIImage* imgBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	imgBack->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindo_Mat.field_tabwindo_Mat'"), NULL, LOAD_None, NULL);
	imgBack->ImageStyle = EImgStyle::ISTY_Stretched;
	imgBack->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	imgBack->DropShadowY = 10;
	imgBack->WinHeight = 1;
	imgBack->bBoundToParent = true;
	imgBack->bScaleToParent = true;
	UGUILabel* lblQuestion = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblQuestion->TextFont = "AAFontMedium";
	lblQuestion->bMultiLine = true;
	lblQuestion->StyleName = "TextLabel";
	lblQuestion->WinTop = 0.45;
	lblQuestion->WinLeft = 0.15;
	lblQuestion->WinWidth = 0.7;
	lblQuestion->WinHeight = 0.2;
	Controls = { imgBack,lblQuestion };
}

bool UAAQuestionPage::ButtonClick(UGUIComponent* Sender)
{
	/*
	int32 t = 0;
	t = GUIButton(Sender).Tag;
	ParentPage.InactiveFadeColor = ParentPage.Default.InactiveFadeColor;
	if (NewOnButtonClick(byte(t)))
	{
		Controller.CloseMenu(bool((t & (2 | 64))));
	}
	OnButtonClick(byte(t));
	*/
	return true;
}
