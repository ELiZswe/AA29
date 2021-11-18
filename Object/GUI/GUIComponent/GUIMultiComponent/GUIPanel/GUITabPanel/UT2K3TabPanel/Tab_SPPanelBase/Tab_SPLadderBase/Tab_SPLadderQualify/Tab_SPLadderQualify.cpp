// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPLadderBase/Tab_SPLadderQualify/Tab_SPLadderQualify.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_SPLadderQualify::UTab_SPLadderQualify()
{
	UGUIScrollTextBox* MapInfoScroll = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	MapInfoScroll->CharDelay = 0.0025;
	MapInfoScroll->EOLDelay = 0.5;
	//MapInfoScroll->OnCreateComponent=MapInfoScroll.InternalOnCreateComponent;
	MapInfoScroll->WinTop = 0.619325;
	MapInfoScroll->WinLeft = 0.484569;
	MapInfoScroll->WinWidth = 0.435;
	MapInfoScroll->WinHeight = 0.3;
	MapInfoScroll->bNeverFocus = true;
	UGUIImage* MapPicBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MapPicBack->ImageColor = FColor(255, 255, 255, 160);
	MapPicBack->ImageStyle = EImgStyle::ISTY_Stretched;
	MapPicBack->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MapPicBack->WinTop = 0.091406;
	MapPicBack->WinLeft = 0.477891;
	MapPicBack->WinWidth = 0.45;
	MapPicBack->WinHeight = 0.41;
	UGUIImage* MapPic = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MapPic->ImageStyle = EImgStyle::ISTY_Scaled;
	MapPic->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MapPic->WinTop = 0.093489;
	MapPic->WinLeft = 0.481796;
	MapPic->WinWidth = 0.44375;
	MapPic->WinHeight = 0.405312;
	UGUIImage* MapInfoBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MapInfoBack->ImageColor = FColor(255, 255, 255, 160);
	MapInfoBack->ImageStyle = EImgStyle::ISTY_Stretched;
	MapInfoBack->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MapInfoBack->WinTop = 0.521354;
	MapInfoBack->WinLeft = 0.477891;
	MapInfoBack->WinWidth = 0.45;
	MapInfoBack->WinHeight = 0.41;
	UGUILabel* MapInfoName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MapInfoName->Caption = "No Match Selected";
	MapInfoName->TextAlign = ETextAlign::TXTA_Center;
	MapInfoName->TextColor = FColor(0, 180, 220, 255);
	MapInfoName->TextFont = "UT2HeaderFont";
	MapInfoName->WinTop = 0.526822;
	MapInfoName->WinLeft = 0.512304;
	MapInfoName->WinWidth = 0.382813;
	MapInfoName->WinHeight = 32;
	UGUIImage* DMBar1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	DMBar1->ImageStyle = EImgStyle::ISTY_Scaled;
	DMBar1->WinTop = 0.152813;
	DMBar1->WinLeft = 0.095312;
	DMBar1->WinWidth = 0.003906;
	DMBar1->WinHeight = 0.704102;
	UGUIImage* DMBar2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	DMBar2->ImageStyle = EImgStyle::ISTY_Scaled;
	DMBar2->WinTop = 0.152813;
	DMBar2->WinLeft = 0.095312;
	DMBar2->WinWidth = 0.003906;
	DMBar2->WinHeight = 0.704102;
	DMBar2->bVisible = false;
	UGUILabel* DMLabel0 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DMLabel0->Caption = "Tutorial";
	DMLabel0->TextFont = "UT2SmallFont";
	DMLabel0->WinTop = 0.889387;
	DMLabel0->WinLeft = 0.175001;
	DMLabel0->WinWidth = 0.4;
	DMLabel0->WinHeight = 0.08;
	UGUILabel* DMLabel1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DMLabel1->Caption = "One on One";
	DMLabel1->TextFont = "UT2SmallFont";
	DMLabel1->WinTop = 0.723333;
	DMLabel1->WinLeft = 0.173438;
	DMLabel1->WinWidth = 0.4;
	DMLabel1->WinHeight = 0.08;
	UGUILabel* DMLabel2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DMLabel2->Caption = "One on One";
	DMLabel2->TextFont = "UT2SmallFont";
	DMLabel2->WinTop = 0.555416;
	DMLabel2->WinLeft = 0.173438;
	DMLabel2->WinWidth = 0.4;
	DMLabel2->WinHeight = 0.08;
	UGUILabel* DMLabel3a = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DMLabel3a->Caption = "Cut-throat";
	DMLabel3a->TextFont = "UT2SmallFont";
	DMLabel3a->WinTop = 0.366667;
	DMLabel3a->WinLeft = 0.173438;
	DMLabel3a->WinWidth = 0.4;
	DMLabel3a->WinHeight = 0.08;
	UGUILabel* DMLabel3b = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DMLabel3b->Caption = "Deathmatch";
	DMLabel3b->TextFont = "UT2SmallFont";
	DMLabel3b->WinTop = 0.410416;
	DMLabel3b->WinLeft = 0.173438;
	DMLabel3b->WinWidth = 0.4;
	DMLabel3b->WinHeight = 0.08;
	UGUILabel* DMLabel4a = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DMLabel4a->Caption = "Five-way";
	DMLabel4a->TextFont = "UT2SmallFont";
	DMLabel4a->WinTop = 0.201093;
	DMLabel4a->WinLeft = 0.173438;
	DMLabel4a->WinWidth = 0.4;
	DMLabel4a->WinHeight = 0.08;
	UGUILabel* DMLabel4b = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DMLabel4b->Caption = "Deathmatch";
	DMLabel4b->TextFont = "UT2SmallFont";
	DMLabel4b->WinTop = 0.24427;
	DMLabel4b->WinLeft = 0.173438;
	DMLabel4b->WinWidth = 0.4;
	DMLabel4b->WinHeight = 0.08;
	UGUILabel* DMLabel5a = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DMLabel5a->Caption = "Draft your team";
	DMLabel5a->TextFont = "UT2SmallFont";
	DMLabel5a->WinTop = 0.036927;
	DMLabel5a->WinLeft = 0.171875;
	DMLabel5a->WinWidth = 0.4;
	DMLabel5a->WinHeight = 0.08;
	UGUILabel* DMLabel5b = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DMLabel5b->Caption = "then defeat them";
	DMLabel5b->TextFont = "UT2SmallFont";
	DMLabel5b->WinTop = 0.074219;
	DMLabel5b->WinLeft = 0.173438;
	DMLabel5b->WinWidth = 0.4;
	DMLabel5b->WinHeight = 0.08;
	Controls = { MapPic,MapPicBack,MapInfoBack,MapInfoName,MapInfoScroll,DMBar1,DMBar2,DMLabel0,DMLabel1,DMLabel2,DMLabel3a,DMLabel3b,DMLabel4a,DMLabel4b,DMLabel5a,DMLabel5b };
	WinTop = 0.15;
	WinHeight = 0.77;
}

void UTab_SPLadderQualify::InitPanel()
{
	/*
	int32 i = 0;
	ScrollInfo = GUIScrollTextBox(Controls[4]);
	MapPicHolder = GUIImage(Controls[0]);
	MapNameLabel = GUILabel(Controls[3]);
	for (i = 0; i < 6; i++)
	{
		DMButtons[DMButtons.Length] = NewLadderButton(0, i, 0.050195, (0.799215 - (0.128333 * float(i))));
	}
	OnProfileUpdated();
	*/
}

void UTab_SPLadderQualify::OnProfileUpdated()
{
	/*
	int32 i = 0;
	for (i = 0; i < DMButtons.Length; i++)
	{
		UpdateLadderButton(DMButtons[i], 0, i);
	}
	SetYellowBar(0, 6, DMButtons);
	if (GetProfile() != None)
	{
		SetActiveMatch(0, DMButtons);
	}
	*/
}