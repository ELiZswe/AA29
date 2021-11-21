// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2BotInfoPage/UT2BotInfoPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIProgressBar/GUIProgressBar.h"

UUT2BotInfoPage::UUT2BotInfoPage()
{
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.762501;
	OkButton->WinLeft = 0.703125;
	OkButton->WinWidth = 0.2375;
	OkButton->WinHeight = 0.060938;
	//OkButton->OnClick=UT2BotInfoPage.OkClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUIImage* PageBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	PageBack->ImageStyle = EImgStyle::ISTY_Stretched;
	PageBack->WinLeft = 0.0625;
	PageBack->WinWidth = 0.890625;
	PageBack->WinHeight = 1;
	PageBack->bBoundToParent = true;
	PageBack->bScaleToParent = true;
	UGUIImage* BotPortraitBorder = NewObject<UGUIImage>(UGUIImage::StaticClass());
	BotPortraitBorder->ImageStyle = EImgStyle::ISTY_Stretched;
	BotPortraitBorder->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BotPortraitBorder->WinTop = 0.168751;
	BotPortraitBorder->WinLeft = 0.076563;
	BotPortraitBorder->WinWidth = 0.253125;
	BotPortraitBorder->WinHeight = 0.664258;
	UGUIImage* imgBotPic = NewObject<UGUIImage>(UGUIImage::StaticClass());
	imgBotPic->ImageStyle = EImgStyle::ISTY_Justified;
	imgBotPic->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	imgBotPic->WinTop = 0.170834;
	imgBotPic->WinLeft = 0.078125;
	imgBotPic->WinWidth = 0.246875;
	imgBotPic->WinHeight = 0.658008;
	UGUILabel* lblName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblName->Caption = "Unknown";
	lblName->TextAlign = ETextAlign::TXTA_Center;
	lblName->TextColor = FColor(253, 216, 153, 255);
	lblName->WinTop = 0.175781;
	lblName->WinLeft = 0.333008;
	lblName->WinWidth = 0.598437;
	lblName->WinHeight = 0.052539;
	UGUILabel* lblRace = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblRace->Caption = "Unknown";
	lblRace->TextAlign = ETextAlign::TXTA_Center;
	lblRace->TextColor = FColor(253, 216, 153, 255);
	lblRace->TextFont = "UT2SmallFont";
	lblRace->WinTop = 0.231771;
	lblRace->WinLeft = 0.332031;
	lblRace->WinWidth = 0.60918;
	lblRace->WinHeight = 0.047656;
	UGUIProgressBar* myPB = NewObject<UGUIProgressBar>(UGUIProgressBar::StaticClass());
	myPB->BarColor = FColor(0, 160, 0, 255);
	myPB->Value = 45;
	myPB->Caption = "Accuracy";
	myPB->FontName = "UT2SmallFont";
	myPB->WinTop = 0.329167;
	myPB->WinLeft = 0.335938;
	myPB->WinWidth = 0.6;
	myPB->WinHeight = 0.0625;
	UGUIProgressBar* myPB2 = NewObject<UGUIProgressBar>(UGUIProgressBar::StaticClass());
	myPB2->BarColor = FColor(0, 160, 0, 255);
	myPB2->Value = 20;
	myPB2->Caption = "Agility";
	myPB2->FontName = "UT2SmallFont";
	myPB2->WinTop = 0.410417;
	myPB2->WinLeft = 0.335938;
	myPB2->WinWidth = 0.6;
	myPB2->WinHeight = 0.0625;
	UGUIProgressBar* myPB3 = NewObject<UGUIProgressBar>(UGUIProgressBar::StaticClass());
	myPB3->BarColor = FColor(0, 160, 0, 255);
	myPB3->Value = 50;
	myPB3->Caption = "Tactics";
	myPB3->FontName = "UT2SmallFont";
	myPB3->WinTop = 0.491667;
	myPB3->WinLeft = 0.335938;
	myPB3->WinWidth = 0.6;
	myPB3->WinHeight = 0.0625;
	UGUIProgressBar* myPB4 = NewObject<UGUIProgressBar>(UGUIProgressBar::StaticClass());
	myPB4->BarColor = FColor(0, 160, 0, 255);
	myPB4->Value = 75;
	myPB4->Caption = "Aggressiveness";
	myPB4->FontName = "UT2SmallFont";
	myPB4->WinTop = 0.572917;
	myPB4->WinLeft = 0.335938;
	myPB4->WinWidth = 0.6;
	myPB4->WinHeight = 0.0625;
	UGUIProgressBar* myPB5 = NewObject<UGUIProgressBar>(UGUIProgressBar::StaticClass());
	myPB5->BarColor = FColor(0, 160, 0, 255);
	myPB5->Value = 70;
	myPB5->Caption = "...";
	myPB5->FontName = "UT2SmallFont";
	myPB5->WinTop = 0.654167;
	myPB5->WinLeft = 0.335938;
	myPB5->WinWidth = 0.6;
	myPB5->WinHeight = 0.0625;
	myPB5->bVisible = false;
	NoInformation = "No Information Available!";
	Controls = { PageBack,imgBotPic,BotPortraitBorder,lblName,lblRace,myPB,myPB2,myPB3,myPB4,myPB5,OkButton };
	WinTop = 0.15;
	WinHeight = 0.7;
}

void UUT2BotInfoPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	BotPortrait = GUIImage(Controls[1]);
	botname = GUILabel(Controls[3]);
	BotRace = GUILabel(Controls[4]);
	Bars[0] = GUIProgressBar(Controls[5]);
	Bars[1] = GUIProgressBar(Controls[6]);
	Bars[2] = GUIProgressBar(Controls[7]);
	Bars[3] = GUIProgressBar(Controls[8]);
	Bars[4] = GUIProgressBar(Controls[9]);
	*/
}

bool UUT2BotInfoPage::OkClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}