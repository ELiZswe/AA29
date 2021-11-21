// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2Congratulations/UT2Congratulations.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"

UUT2Congratulations::UUT2Congratulations()
{
	UGUIButton* BackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BackButton->Caption = "Continue";
	BackButton->WinTop = 0.94;
	BackButton->WinLeft = 0.79;
	BackButton->WinWidth = 0.3;
	//BackButton->OnKeyEvent=BackButton.InternalOnKeyEvent;
	UGUITitleBar* CongratsHeader = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	CongratsHeader->Caption = "CONGRATULATIONS";
	CongratsHeader->StyleName = "Header";
	CongratsHeader->WinTop = 0.02;
	UGUIImage* CongratsPicture = NewObject<UGUIImage>(UGUIImage::StaticClass());
	CongratsPicture->ImageStyle = EImgStyle::ISTY_Justified;
	CongratsPicture->ImageAlign = EImgAlign::IMGA_Center;
	CongratsPicture->WinTop = 0.1;
	CongratsPicture->WinLeft = 0.1;
	CongratsPicture->WinWidth = 0.8;
	CongratsPicture->WinHeight = 0.7;
	UGUITitleBar* CongratsFooter = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	CongratsFooter->StyleName = "Footer";
	CongratsFooter->WinTop = 0.86;
	Controls = { CongratsHeader,CongratsPicture,CongratsFooter,BackButton };
	WinTop = 0.1;
	WinLeft = 0.1;
	WinWidth = 0.8;
	WinHeight = 0.8;
}

void UUT2Congratulations::SetupPage(FString PageCaption, FString PageMessage, FString ContinueCaption, UMaterialInstance* CongratsPic)
{
	Cast<UGUITitleBar>(Controls[0])->SetCaption(PageCaption);
	Cast<UGUITitleBar>(Controls[2])->SetCaption(PageMessage);
	Cast<UGUIButton>(Controls[3])->Caption = ContinueCaption;
	Cast<UGUIImage>(Controls[1])->Image = CongratsPic;
}