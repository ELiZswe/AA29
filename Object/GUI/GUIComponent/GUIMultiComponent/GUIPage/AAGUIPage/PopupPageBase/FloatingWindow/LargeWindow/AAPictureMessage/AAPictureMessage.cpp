// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/AAPictureMessage/AAPictureMessage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAPictureMessage::UAAPictureMessage()
{
	UGUIButton* SPMbtnOk = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPMbtnOk->Caption = "OK";
	SPMbtnOk->FontScale = EFontScale::FNS_Small;
	SPMbtnOk->WinTop = 0.765625;
	SPMbtnOk->WinLeft = 0.401563;
	SPMbtnOk->WinWidth = 0.2;
	//SPMbtnOk->OnClick=AAPictureMessage.btnOkOnClick;
	//SPMbtnOk->OnKeyEvent=SPMbtnOk.InternalOnKeyEvent;
	UGUIImage* SPMimgPicture = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPMimgPicture->ImageStyle = EImgStyle::ISTY_Scaled;
	SPMimgPicture->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	SPMimgPicture->X1 = 0;
	SPMimgPicture->Y1 = 0;
	SPMimgPicture->X2 = 1023;
	SPMimgPicture->Y2 = 767;
	SPMimgPicture->WinTop = 0.2925;
	SPMimgPicture->WinLeft = 0.24;
	SPMimgPicture->WinWidth = 0.51875;
	SPMimgPicture->WinHeight = 0.435;
	SPMimgPicture->RenderWeight = 0.3;
	UGUIImage* SPMimgPictureBg = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPMimgPictureBg->ImageStyle = EImgStyle::ISTY_Scaled;
	SPMimgPictureBg->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	SPMimgPictureBg->WinTop = 0.278166;
	SPMimgPictureBg->WinLeft = 0.239;
	SPMimgPictureBg->WinWidth = 0.52075;
	SPMimgPictureBg->WinHeight = 0.46325;
	SPMimgPictureBg->RenderWeight = 0.2;
	UGUILabel* SPLlblTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPLlblTitle->Caption = "no title";
	SPLlblTitle->TextAlign = ETextAlign::TXTA_Center;
	SPLlblTitle->FontScale = EFontScale::FNS_Large;
	SPLlblTitle->StyleName = "TextLabel";
	SPLlblTitle->WinTop = 0.176667;
	SPLlblTitle->WinLeft = 0.16;
	SPLlblTitle->WinWidth = 0.68;
	SPLlblTitle->WinHeight = 0.07875;
	imgPictureBg = SPMimgPictureBg;
	imgPicture = SPMimgPicture;
	btnOK = SPMbtnOk;
	lblTitle = SPLlblTitle;
	WinTop = 0.15;
	WinLeft = 0.15;
	WinWidth = 0.7;
	WinHeight = 0.7;
}

bool btnOkOnClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}

void HandleParameters(FString Param1, FString Param2)
{
	/*
	local Material img;
	Super::HandleParameters(Param1, Param2);
	lblTitle.Caption = Param1;
	img = Material(DynamicLoadObject(Param2, Class'Material'));
	if (img != None)
	{
		imgPicture.Image = img;
	}
	*/
}