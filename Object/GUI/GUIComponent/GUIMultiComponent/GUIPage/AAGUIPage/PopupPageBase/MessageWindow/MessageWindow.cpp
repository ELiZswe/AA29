// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/MessageWindow.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/FloatingImage/FloatingImage.h"

UMessageWindow::UMessageWindow()
{
	UFloatingImage* MessageWindowFrameBackground = NewObject<UFloatingImage>(UFloatingImage::StaticClass());
	MessageWindowFrameBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindo_Mat.field_tabwindo_Mat'"), NULL, LOAD_None, NULL);
	MessageWindowFrameBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MessageWindowFrameBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MessageWindowFrameBackground->DropShadowX = 0;
	MessageWindowFrameBackground->DropShadowY = 0;
	MessageWindowFrameBackground->WinTop = 0;
	MessageWindowFrameBackground->WinLeft = 0;
	MessageWindowFrameBackground->WinWidth = 1;
	MessageWindowFrameBackground->WinHeight = 1;
	i_FrameBG = MessageWindowFrameBackground;
	WinTop = 0.3;
	WinLeft = 0.125;
	WinWidth = 0.75;
	WinHeight = 0.38;
}