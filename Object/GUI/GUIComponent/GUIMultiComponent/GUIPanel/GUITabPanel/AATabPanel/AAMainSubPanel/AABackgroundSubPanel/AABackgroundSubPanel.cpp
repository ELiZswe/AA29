// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIBorder.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAABackgroundSubPanel::UAABackgroundSubPanel()
{
	UGUIImage* PanelBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	PanelBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_background_fil_Mat.t_ui_gui_background_fil_Mat'"), NULL, LOAD_None, NULL);
	PanelBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	PanelBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	PanelBackground->WinTop = 0.05125;
	PanelBackground->WinHeight = 0.9125;
	PanelBackground->RenderWeight = 0;
	PanelBackground->bBoundToParent = true;
	PanelBackground->bScaleToParent = true;
	UGUIBorder* PanelHeader = NewObject<UGUIBorder>(UGUIBorder::StaticClass());
	PanelHeader->WinHeight = 0.05;
	PanelHeader->RenderWeight = 0;
	PanelHeader->bBoundToParent = true;
	PanelHeader->bScaleToParent = true;
	UGUIImage* NMLStatusIcon = NewObject<UGUIImage>(UGUIImage::StaticClass());
	NMLStatusIcon->ImageStyle = EImgStyle::ISTY_Scaled;
	NMLStatusIcon->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	NMLStatusIcon->WinTop = 0.9675;
	NMLStatusIcon->WinWidth = 0.025;
	NMLStatusIcon->WinHeight = 0.025;
	NMLStatusIcon->RenderWeight = 0.5;
	NMLStatusIcon->bVisible = false;
	UGUILabel* NMLStatusText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NMLStatusText->TextColor = FColor(204, 255, 255, 255);
	NMLStatusText->FontScale = EFontScale::FNS_Small;
	NMLStatusText->StyleName = "LightTextLabel";
	NMLStatusText->WinTop = 0.955;
	NMLStatusText->WinLeft = 0.035;
	NMLStatusText->WinWidth = 0.4;
	NMLStatusText->WinHeight = 0.053476;
	NMLStatusText->RenderWeight = 0.5;
	NMLStatusText->bNeverFocus = true;
	i_Background = PanelBackground;
	h_Header = PanelHeader;
	i_NMLStatusIcon = NMLStatusIcon;
	l_NMLStatusText = NMLStatusText;
}

void UAABackgroundSubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
	//h_Header.SetCaption(PanelCaption);
}
