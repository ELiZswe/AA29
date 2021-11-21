// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPLadderBase/Tab_SPLadderTeam/Tab_SPLadderTeam.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_SPLadderTeam::UTab_SPLadderTeam()
{
	UGUIGFXButton* SPLChampButton = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	SPLChampButton->Position = EIconPosition::ICP_Scaled;
	SPLChampButton->WinTop = 0.094322;
	SPLChampButton->WinLeft = 0.458633;
	SPLChampButton->WinWidth = 0.083925;
	SPLChampButton->WinHeight = 0.113688;
	SPLChampButton->bVisible = false;
	SPLChampButton->bAcceptsInput = false;
	//SPLChampButton->OnClick=Tab_SPLadderTeam.ChampMatch;
	//SPLChampButton->OnDblClick = Tab_SPLadderTeam.MatchDoubleClick;
	//SPLChampButton->OnKeyEvent=SPLChampButton.InternalOnKeyEvent;
	UGUIScrollTextBox* MapInfoScroll = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	MapInfoScroll->CharDelay = 0.0025;
	MapInfoScroll->EOLDelay = 0.5;
	//MapInfoScroll->OnCreateComponent=MapInfoScroll.InternalOnCreateComponent;
	MapInfoScroll->WinTop = 0.616407;
	MapInfoScroll->WinLeft = 0.299023;
	MapInfoScroll->WinWidth = 0.402539;
	MapInfoScroll->WinHeight = 0.290234;
	MapInfoScroll->bNeverFocus = true;
	UGUIImage* MapPicBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MapPicBack->ImageStyle = EImgStyle::ISTY_Stretched;
	MapPicBack->WinTop = 0.247917;
	MapPicBack->WinLeft = 0.293164;
	MapPicBack->WinWidth = 0.413281;
	MapPicBack->WinHeight = 0.294141;
	UGUIImage* MapPic = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MapPic->ImageStyle = EImgStyle::ISTY_Justified;
	MapPic->ImageAlign = EImgAlign::IMGA_Center;
	MapPic->WinTop = 0.255313;
	MapPic->WinLeft = 0.299219;
	MapPic->WinWidth = 0.401563;
	MapPic->WinHeight = 0.279493;
	UGUIImage* MapInfoBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MapInfoBack->ImageStyle = EImgStyle::ISTY_Stretched;
	MapInfoBack->WinTop = 0.551823;
	MapInfoBack->WinLeft = 0.294141;
	MapInfoBack->WinWidth = 0.412305;
	MapInfoBack->WinHeight = 0.361524;
	UGUILabel* MapInfoName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MapInfoName->Caption = "No Match Selected";
	MapInfoName->TextAlign = ETextAlign::TXTA_Center;
	MapInfoName->TextColor = FColor(0, 180, 220, 255);
	MapInfoName->TextFont = "UT2HeaderFont";
	MapInfoName->WinTop = 0.56224;
	MapInfoName->WinLeft = 0.301172;
	MapInfoName->WinWidth = 0.39668;
	MapInfoName->WinHeight = 0.051406;
	UGUIImage* ImgLock1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	ImgLock1->ImageStyle = EImgStyle::ISTY_Scaled;
	ImgLock1->ImageAlign = EImgAlign::IMGA_Center;
	ImgLock1->WinTop = 0.064322;
	ImgLock1->WinLeft = 0.437695;
	ImgLock1->WinWidth = 0.062891;
	ImgLock1->WinHeight = 0.087305;
	UGUIImage* ImgLock2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	ImgLock2->ImageStyle = EImgStyle::ISTY_Scaled;
	ImgLock2->ImageAlign = EImgAlign::IMGA_Center;
	ImgLock2->WinTop = 0.15026;
	ImgLock2->WinLeft = 0.437695;
	ImgLock2->WinWidth = 0.062891;
	ImgLock2->WinHeight = 0.087305;
	UGUIImage* ImgLock3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	ImgLock3->ImageStyle = EImgStyle::ISTY_Scaled;
	ImgLock3->ImageAlign = EImgAlign::IMGA_Center;
	ImgLock3->WinTop = 0.064322;
	ImgLock3->WinLeft = 0.500195;
	ImgLock3->WinWidth = 0.062891;
	ImgLock3->WinHeight = 0.087305;
	UGUIImage* ImgLock4 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	ImgLock4->ImageStyle = EImgStyle::ISTY_Scaled;
	ImgLock4->ImageAlign = EImgAlign::IMGA_Center;
	ImgLock4->WinTop = 0.15026;
	ImgLock4->WinLeft = 0.500195;
	ImgLock4->WinWidth = 0.062891;
	ImgLock4->WinHeight = 0.087305;
	UGUIImage* TopLeftBar = NewObject<UGUIImage>(UGUIImage::StaticClass());
	TopLeftBar->ImageStyle = EImgStyle::ISTY_Scaled;
	TopLeftBar->WinTop = 0.105729;
	TopLeftBar->WinLeft = 0.099218;
	TopLeftBar->WinWidth = 0.338086;
	TopLeftBar->WinHeight = 0.003906;
	UGUIImage* TopLeftCorner = NewObject<UGUIImage>(UGUIImage::StaticClass());
	TopLeftCorner->ImageStyle = EImgStyle::ISTY_Scaled;
	TopLeftCorner->WinTop = 0.105729;
	TopLeftCorner->WinLeft = 0.095312;
	TopLeftCorner->WinWidth = 0.003906;
	TopLeftCorner->WinHeight = 0.003906;
	UGUIImage* TDMBar1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	TDMBar1->ImageStyle = EImgStyle::ISTY_Scaled;
	TDMBar1->WinTop = 0.109896;
	TDMBar1->WinLeft = 0.095312;
	TDMBar1->WinWidth = 0.003906;
	TDMBar1->WinHeight = 0.682227;
	UGUIImage* TDMBar2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	TDMBar2->ImageStyle = EImgStyle::ISTY_Scaled;
	TDMBar2->WinTop = 0.109896;
	TDMBar2->WinLeft = 0.095312;
	TDMBar2->WinWidth = 0.003906;
	TDMBar2->WinHeight = 0.682227;
	TDMBar2->bVisible = false;
	UGUIImage* TopRightBar = NewObject<UGUIImage>(UGUIImage::StaticClass());
	TopRightBar->ImageStyle = EImgStyle::ISTY_Scaled;
	TopRightBar->WinTop = 0.105729;
	TopRightBar->WinLeft = 0.563085;
	TopRightBar->WinWidth = 0.338086;
	TopRightBar->WinHeight = 0.003906;
	UGUIImage* TopRightCorner = NewObject<UGUIImage>(UGUIImage::StaticClass());
	TopRightCorner->ImageStyle = EImgStyle::ISTY_Scaled;
	TopRightCorner->WinTop = 0.105729;
	TopRightCorner->WinLeft = 0.901171;
	TopRightCorner->WinWidth = 0.003906;
	TopRightCorner->WinHeight = 0.003906;
	UGUIImage* CTFBar1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	CTFBar1->ImageStyle = EImgStyle::ISTY_Scaled;
	CTFBar1->WinTop = 0.109896;
	CTFBar1->WinLeft = 0.901171;
	CTFBar1->WinWidth = 0.003906;
	CTFBar1->WinHeight = 0.682227;
	UGUIImage* CTFBar2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	CTFBar2->ImageStyle = EImgStyle::ISTY_Scaled;
	CTFBar2->WinTop = 0.109896;
	CTFBar2->WinLeft = 0.901171;
	CTFBar2->WinWidth = 0.003906;
	CTFBar2->WinHeight = 0.682227;
	CTFBar2->bVisible = false;
	UGUIImage* MidLeftBar = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MidLeftBar->ImageStyle = EImgStyle::ISTY_Scaled;
	MidLeftBar->WinTop = 0.194218;
	MidLeftBar->WinLeft = 0.222266;
	MidLeftBar->WinWidth = 0.215039;
	MidLeftBar->WinHeight = 0.003906;
	UGUIImage* MidLeftCorner = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MidLeftCorner->ImageStyle = EImgStyle::ISTY_Scaled;
	MidLeftCorner->WinTop = 0.194218;
	MidLeftCorner->WinLeft = 0.219336;
	MidLeftCorner->WinWidth = 0.003906;
	MidLeftCorner->WinHeight = 0.003906;
	UGUIImage* DOMBar1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	DOMBar1->ImageStyle = EImgStyle::ISTY_Scaled;
	DOMBar1->WinTop = 0.198125;
	DOMBar1->WinLeft = 0.219336;
	DOMBar1->WinWidth = 0.003906;
	DOMBar1->WinHeight = 0.594688;
	UGUIImage* DOMBar2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	DOMBar2->ImageStyle = EImgStyle::ISTY_Scaled;
	DOMBar2->WinTop = 0.198125;
	DOMBar2->WinLeft = 0.219336;
	DOMBar2->WinWidth = 0.003906;
	DOMBar2->WinHeight = 0.594688;
	DOMBar2->bVisible = false;
	UGUIImage* MidRightBar = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MidRightBar->ImageStyle = EImgStyle::ISTY_Scaled;
	MidRightBar->WinTop = 0.19427;
	MidRightBar->WinLeft = 0.563085;
	MidRightBar->WinWidth = 0.213086;
	MidRightBar->WinHeight = 0.003906;
	UGUIImage* MidRightCorner = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MidRightCorner->ImageStyle = EImgStyle::ISTY_Scaled;
	MidRightCorner->WinTop = 0.194271;
	MidRightCorner->WinLeft = 0.776171;
	MidRightCorner->WinWidth = 0.003906;
	MidRightCorner->WinHeight = 0.003906;
	UGUIImage* BRBar1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	BRBar1->ImageStyle = EImgStyle::ISTY_Scaled;
	BRBar1->WinTop = 0.19797;
	BRBar1->WinLeft = 0.775976;
	BRBar1->WinWidth = 0.003906;
	BRBar1->WinHeight = 0.594687;
	UGUIImage* BRBar2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	BRBar2->ImageStyle = EImgStyle::ISTY_Scaled;
	BRBar2->WinTop = 0.19797;
	BRBar2->WinLeft = 0.775976;
	BRBar2->WinWidth = 0.003906;
	BRBar2->WinHeight = 0.594687;
	BRBar2->bVisible = false;
	UGUILabel* TDMLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TDMLabel->Caption = "TEAM DEATHMATCH";
	TDMLabel->TextAlign = ETextAlign::TXTA_Center;
	TDMLabel->TextColor = FColor(192, 192, 192, 255);
	TDMLabel->BackColor = FColor(255, 255, 255, 255);
	TDMLabel->WinTop = 0.060833;
	TDMLabel->WinLeft = 0.118437;
	TDMLabel->WinWidth = 0.3475;
	TDMLabel->WinHeight = 0.043125;
	UGUILabel* CTFLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CTFLabel->Caption = "CAPTURE THE FLAG";
	CTFLabel->TextAlign = ETextAlign::TXTA_Center;
	CTFLabel->TextColor = FColor(192, 192, 192, 255);
	CTFLabel->BackColor = FColor(255, 255, 255, 255);
	CTFLabel->WinTop = 0.060833;
	CTFLabel->WinLeft = 0.544064;
	CTFLabel->WinWidth = 0.34625;
	CTFLabel->WinHeight = 0.043125;
	UGUILabel* DOMLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DOMLabel->Caption = "DOMINATION";
	DOMLabel->TextAlign = ETextAlign::TXTA_Center;
	DOMLabel->TextColor = FColor(192, 192, 192, 255);
	DOMLabel->BackColor = FColor(255, 255, 255, 255);
	DOMLabel->WinTop = 0.149167;
	DOMLabel->WinLeft = 0.242813;
	DOMLabel->WinWidth = 0.223122;
	DOMLabel->WinHeight = 0.043125;
	UGUILabel* BRLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	BRLabel->Caption = "BOMBING RUN";
	BRLabel->TextAlign = ETextAlign::TXTA_Center;
	BRLabel->TextColor = FColor(192, 192, 192, 255);
	BRLabel->BackColor = FColor(255, 255, 255, 255);
	BRLabel->WinTop = 0.149166;
	BRLabel->WinLeft = 0.537818;
	BRLabel->WinWidth = 0.221874;
	BRLabel->WinHeight = 0.043125;
	UGUIImage* SPLChampBorder = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPLChampBorder->ImageStyle = EImgStyle::ISTY_Scaled;
	SPLChampBorder->WinTop = 0.064895;
	SPLChampBorder->WinLeft = 0.43793;
	SPLChampBorder->WinWidth = 0.125722;
	SPLChampBorder->WinHeight = 0.172673;
	SPLChampBorder->bVisible = false;
	LockIndexes = { 0,1,3,2,4 };
	bFillHeight = true;
	Controls = { MapPicBack,MapPic,MapInfoBack,MapInfoName,MapInfoScroll,ImgLock1,ImgLock2,ImgLock3,ImgLock4,TopLeftBar,TopLeftCorner,TDMBar1,TDMBar2,TopRightBar,TopRightCorner,CTFBar1,CTFBar2,MidLeftBar,MidLeftCorner,DOMBar1,	DOMBar2,MidRightBar,MidRightCorner,BRBar1,BRBar2,TDMLabel,CTFLabel,DOMLabel,BRLabel,SPLChampButton,SPLChampBorder };
	WinTop = 0.15;
	WinHeight = 0.77;
}

void UTab_SPLadderTeam::InitPanel()
{
	/*
	int32 i = 0;
	ScrollInfo = GUIScrollTextBox(Controls[4]);
	MapPicHolder = GUIImage(Controls[1]);
	MapNameLabel = GUILabel(Controls[3]);
	ChampButton = GUIGFXButton(Controls[29]);
	ChampBorder = GUIImage(Controls[30]);
	for (i = 0; i < 6; i++)
	{
		TDMButtons[TDMButtons.Length] = NewLadderButton(1, i, 0.050195, (0.799215 - (0.128333 * float(i))));
	}
	for (i = 0; i < 5; i++)
	{
		DOMButtons[DOMButtons.Length] = NewLadderButton(2, i, 0.176172, (0.799215 - (0.128333 * float(i))));
	}
	for (i = 0; i < 5; i++)
	{
		BRButtons[BRButtons.Length] = NewLadderButton(4, i, 0.733789, (0.799215 - (0.128333 * float(i))));
	}
	for (i = 0; i < 6; i++)
	{
		CTFButtons[CTFButtons.Length] = NewLadderButton(3, i, 0.860742, (0.799215 - (0.128333 * float(i))));
	}
	ScrollInfo.SetContent("");
	OnProfileUpdated();
	*/
}

void UTab_SPLadderTeam::OnProfileUpdated()
{
	/*
	int32 i = 0;
	for (i = 0; i < 6; i++)
	{
		UpdateLadderButton(TDMButtons[i], 1, i);
		UpdateLadderButton(CTFButtons[i], 3, i);
	}
	for (i = 0; i < 5; i++)
	{
		UpdateLadderButton(DOMButtons[i], 2, i);
		UpdateLadderButton(BRButtons[i], 4, i);
	}
	ChampBorder.bVisible = false;
	SetYellowBar(1, 12, TDMButtons);
	SetYellowBar(2, 20, DOMButtons);
	SetYellowBar(4, 24, BRButtons);
	SetYellowBar(3, 16, CTFButtons);
	SetChampionship(false);
	if (GetProfile() != None)
	{
		GetProfile().ChampBorderObject = ChampBorder;
		if ((((!SetActiveMatch(1, TDMButtons)) && (!SetActiveMatch(2, DOMButtons))) && (!SetActiveMatch(3, CTFButtons))) && (!SetActiveMatch(4, BRButtons)))
		{
			if (GetProfile().ladderrung[5] >= 0)
			{
				Log("SINGLEPLAYER Opening Championship.");
				SetChampionship(true);
				ChampMatch(ChampButton);
			}
		}
	}
	*/
}

int32 UTab_SPLadderTeam::SetYellowBar(int32 Ladder, int32 Index, TArray<ULadderButton*>& Buttons)
{
	/*
	int32 rung = 0;
	int32 lockindex = 0;
	FString HiStr = "";
	Super::SetYellowBar(Ladder, Index, Buttons);
	if (GetProfile() != None)
	{
		rung = GetProfile().ladderrung[Ladder];
		lockindex = Ladder;
		HiStr = "";
		if (rung == Buttons.Length)
		{
			HiStr = "Hi";
		}
	}
	if (HiStr == "Hi")
	{
		return 1;
	}
	else
	{
		return 0;
	}
	*/
	return 0;   //FAKE   /ELiZ
}

bool UTab_SPLadderTeam::ChampMatch(UGUIComponent* Sender)
{
	/*
	local LadderButton LButton;
	local GameProfile GP;
	GP = GetProfile();
	if (GP != None)
	{
		if (GP.ChampBorderObject != None)
		{
			GUIImage(GP.ChampBorderObject).bVisible = true;
		}
		GP.CurrentMenuRung = GP.ladderrung[5];
		GP.CurrentLadder = 5;
		LButton = LadderButton(GP.NextMatchObject);
		if (LButton != None)
		{
			LButton.SetState(GP.ladderrung[LButton.LadderIndex]);
			LButton = None;
		}
		ShowMatchInfo(GP.GetMatchInfo(GP.CurrentLadder, GP.CurrentMenuRung));
		MatchUpdated(GP.CurrentLadder, GP.CurrentMenuRung);
	}
	*/
	return true;
}

void UTab_SPLadderTeam::SetChampionship(bool bEnable)
{
	/*
	local MatchInfo MI;
	local GameProfile GP;
	GP = GetProfile();
	if (GP != None)
	{
		ChampButton.bVisible = bEnable;
		ChampButton.bAcceptsInput = bEnable;
		ChampButton.bNeverFocus = (!bEnable);
		if (bEnable)
		{
			if (GP.ladderrung[5] >= GP.GameLadder.Default.ChampionshipMatches.Length)
			{
				ChampButton.Graphic = DLOMaterial("PlayerPictures.aDOM");
			}
			else
			{
				MI = GP.GetMatchInfo(5, GP.ladderrung[5]);
				ChampButton.Graphic = DLOMaterial("SinglePlayerThumbs." $ MI.LevelName);
			}
		}
	}
	*/
}