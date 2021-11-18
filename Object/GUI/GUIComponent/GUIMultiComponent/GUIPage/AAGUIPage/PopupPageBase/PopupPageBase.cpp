// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/PopupPageBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/FloatingImage/FloatingImage.h"

UPopupPageBase::UPopupPageBase()
{
	UFloatingImage* FloatingFrameBackground = NewObject<UFloatingImage>(UFloatingImage::StaticClass());
	FloatingFrameBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindo_Mat.field_tabwindo_Mat'"), NULL, LOAD_None, NULL);
	FloatingFrameBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	FloatingFrameBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	FloatingFrameBackground->WinTop = 0.02;
	FloatingFrameBackground->WinLeft = 0;
	FloatingFrameBackground->WinWidth = 1;
	FloatingFrameBackground->WinHeight = 0.98;
	FloatingFrameBackground->RenderWeight = 3E-06;
	i_FrameBG = FloatingFrameBackground;
	FadeTime = 0.35;
	CurFade = 200;
	DesiredFade = 80;
	bRenderWorld = true;
	bRequire640x480 = false;
	BackgroundRStyle = EMenuRenderStyle::MSTY_Modulated;
	//OnPreDraw = PopupPageBase.InternalOnPreDraw;
}


void UPopupPageBase::FadedIn()
{
}

void UPopupPageBase::FadedOut()
{
}

void UPopupPageBase::Opened(UGUIComponent* Sender)
{
	/*
	if (bCaptureInput)
	{
		FadeIn();
	}
	Super::Opened(Sender);
	*/
}

bool UPopupPageBase::InternalOnPreDraw(UCanvas* C)
{
	/*
	if (!bFading)
	{
		return false;
	}
	if (CurFadeTime >= 0)
	{
		(CurFade += byte((float((DesiredFade - CurFade)) * (Controller.RenderDelta / CurFadeTime))));
		InactiveFadeColor = Class'Canvas'.MakeColor(CurFade, CurFade, CurFade);
		(CurFadeTime -= Controller.RenderDelta);
		if (CurFadeTime < 0)
		{
			CurFade = DesiredFade;
			InactiveFadeColor = Class'Canvas'.MakeColor(CurFade, CurFade, CurFade);
			bFading = false;
			if (bClosing)
			{
				bClosing = false;
				FadedOut();
			}
			else
			{
				FadedIn();
			}
		}
	}
	*/
	return false;
}

void UPopupPageBase::FadeIn()
{
	/*
	if (Controller.bModulateStackedMenus)
	{
		bClosing = false;
		bFading = true;
		CurFadeTime = FadeTime;
	}
	else
	{
		FadedIn();
	}
	*/
}

void UPopupPageBase::FadeOut()
{
	/*
	if (Controller.bModulateStackedMenus)
	{
		bFading = true;
		bClosing = true;
		CurFadeTime = FadeTime;
		DesiredFade = Default.CurFade;
	}
	else
	{
		FadedOut();
	}
	*/
}