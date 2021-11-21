// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2DemoQuitPage/UT2DemoQuitPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UUT2DemoQuitPage::UUT2DemoQuitPage()
{
	UGUIButton* QuitButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	QuitButton->Caption = "Quit";
	QuitButton->WinTop = 0.91;
	QuitButton->WinLeft = 0.8;
	QuitButton->WinWidth = 0.15;
	//QuitButton->OnClick=UT2DemoQuitPage.OnQuitClicked;
	//QuitButton->OnKeyEvent=QuitButton.InternalOnKeyEvent;
	UGUIButton* BuyButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BuyButton->Caption = "Buy";
	BuyButton->WinTop = 0.85;
	BuyButton->WinLeft = 0.8;
	BuyButton->WinWidth = 0.15;
	//BuyButton->OnClick=UT2DemoQuitPage.OnBuyClicked;
	//BuyButton->OnKeyEvent=BuyButton.InternalOnKeyEvent;
	UGUIImage* QuitImageA1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageA1->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageA1->WinWidth = 0.25;
	QuitImageA1->WinHeight = 0.25;
	UGUIImage* QuitImageA2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageA2->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageA2->WinLeft = 0.25;
	QuitImageA2->WinWidth = 0.25;
	QuitImageA2->WinHeight = 0.25;
	UGUIImage* QuitImageA3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageA3->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageA3->WinLeft = 0.5;
	QuitImageA3->WinWidth = 0.25;
	QuitImageA3->WinHeight = 0.25;
	UGUIImage* QuitImageA4 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageA4->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageA4->WinLeft = 0.75;
	QuitImageA4->WinWidth = 0.25;
	QuitImageA4->WinHeight = 0.25;
	UGUIImage* QuitImageB1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageB1->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageB1->WinTop = 0.25;
	QuitImageB1->WinWidth = 0.25;
	QuitImageB1->WinHeight = 0.25;
	UGUIImage* QuitImageB2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageB2->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageB2->WinTop = 0.25;
	QuitImageB2->WinLeft = 0.25;
	QuitImageB2->WinWidth = 0.25;
	QuitImageB2->WinHeight = 0.25;
	UGUIImage* QuitImageB3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageB3->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageB3->WinTop = 0.25;
	QuitImageB3->WinLeft = 0.5;
	QuitImageB3->WinWidth = 0.25;
	QuitImageB3->WinHeight = 0.25;
	UGUIImage* QuitImageB4 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageB4->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageB4->WinTop = 0.25;
	QuitImageB4->WinLeft = 0.75;
	QuitImageB4->WinWidth = 0.25;
	QuitImageB4->WinHeight = 0.25;
	UGUIImage* QuitImageC1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageC1->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageC1->WinTop = 0.5;
	QuitImageC1->WinWidth = 0.25;
	QuitImageC1->WinHeight = 0.25;
	UGUIImage* QuitImageC2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageC2->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageC2->WinTop = 0.5;
	QuitImageC2->WinLeft = 0.25;
	QuitImageC2->WinWidth = 0.25;
	QuitImageC2->WinHeight = 0.25;
	UGUIImage* QuitImageC3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageC3->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageC3->WinTop = 0.5;
	QuitImageC3->WinLeft = 0.5;
	QuitImageC3->WinWidth = 0.25;
	QuitImageC3->WinHeight = 0.25;
	UGUIImage* QuitImageC4 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageC4->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageC4->WinTop = 0.5;
	QuitImageC4->WinLeft = 0.75;
	QuitImageC4->WinWidth = 0.25;
	QuitImageC4->WinHeight = 0.25;
	UGUIImage* QuitImageD1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageD1->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageD1->WinTop = 0.75;
	QuitImageD1->WinWidth = 0.25;
	QuitImageD1->WinHeight = 0.25;
	UGUIImage* QuitImageD2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageD2->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageD2->WinTop = 0.75;
	QuitImageD2->WinLeft = 0.25;
	QuitImageD2->WinWidth = 0.25;
	QuitImageD2->WinHeight = 0.25;
	UGUIImage* QuitImageD3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageD3->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageD3->WinTop = 0.75;
	QuitImageD3->WinLeft = 0.5;
	QuitImageD3->WinWidth = 0.25;
	QuitImageD3->WinHeight = 0.25;
	UGUIImage* QuitImageD4 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	QuitImageD4->ImageStyle = EImgStyle::ISTY_Scaled;
	QuitImageD4->WinTop = 0.75;
	QuitImageD4->WinLeft = 0.75;
	QuitImageD4->WinWidth = 0.25;
	QuitImageD4->WinHeight = 0.25;
	TimeLeft = 20;
	Controls = { QuitImageA1,QuitImageA2,QuitImageA3,QuitImageA4,QuitImageB1,QuitImageB2,QuitImageB3,QuitImageB4,QuitImageC1,QuitImageC2,QuitImageC3,QuitImageC4,QuitImageD1,QuitImageD2,QuitImageD3,QuitImageD4,BuyButton,QuitButton };
	WinHeight = 1;
}

void UUT2DemoQuitPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	GUIButton(Controls[17]).Caption = GUIButton(Default.Controls[17]).Caption $ "(" $ string(TimeLeft) $ ")";
	SetTimer(1, true);
	*/
}

void UUT2DemoQuitPage::Timer()
{
	/*
	if (bClickedBuy)
	{
		PlayerOwner().ConsoleCommand("exit");
	}
	else
	{
		(TimeLeft);
		GUIButton(Controls[17]).Caption = GUIButton(Default.Controls[17]).Caption $ "(" $ string(TimeLeft) $ ")";
		if (TimeLeft <= 0)
		{
			OnQuitClicked(Controls[17]);
		}
	}
	*/
}

bool UUT2DemoQuitPage::OnBuyClicked(UGUIComponent* Sender)
{
	/*
	PlayerOwner().ConsoleCommand("start http://www.unrealtournament.com/");
	bClickedBuy = true;
	SetTimer(0.5, true);
	*/
	return true;
}

bool UUT2DemoQuitPage::OnQuitClicked(UGUIComponent* Sender)
{
	//PlayerOwner().ConsoleCommand("exit");
	return true;
}