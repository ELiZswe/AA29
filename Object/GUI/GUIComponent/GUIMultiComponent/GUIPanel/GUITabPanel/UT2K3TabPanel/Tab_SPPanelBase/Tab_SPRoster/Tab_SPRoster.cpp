// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPRoster/Tab_SPRoster.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICharacterList/GUICharacterListTeam/GUICharacterListTeam.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"

UTab_SPRoster::UTab_SPRoster()
{
	UGUICharacterListTeam* SPRosterCharList = NewObject<UGUICharacterListTeam>(UGUICharacterListTeam::StaticClass());
	SPRosterCharList->bLocked = true;
	SPRosterCharList->bFillBounds = true;
	SPRosterCharList->bAllowSelectEmpty = false;
	SPRosterCharList->FixedItemsPerPage = 7;
	SPRosterCharList->StyleName = "CharButton";
	SPRosterCharList->Hint = "Choose a teammate to play in the next match";
	SPRosterCharList->WinTop = 0.73;
	SPRosterCharList->WinLeft = 0.004688;
	SPRosterCharList->WinWidth = 0.670315;
	SPRosterCharList->WinHeight = 0.17;
	//SPRosterCharList->OnClick=SPRosterCharList.InternalOnClick;
	//SPRosterCharList->OnRightClick=SPRosterCharList.InternalOnRightClick;
	//SPRosterCharList->OnMousePressed=SPRosterCharList.InternalOnMousePressed;
	//SPRosterCharList->OnMouseRelease=SPRosterCharList.InternalOnMouseRelease;
	//SPRosterCharList->OnChange=Tab_SPRoster.CharListClick;
	//SPRosterCharList->OnKeyEvent=SPRosterCharList.InternalOnKeyEvent;
	//SPRosterCharList->OnBeginDrag=SPRosterCharList.InternalOnBeginDrag;
	//SPRosterCharList->OnEndDrag=SPRosterCharList.InternalOnEndDrag;
	//SPRosterCharList->OnDragDrop=SPRosterCharList.InternalOnDragDrop;
	//SPRosterCharList->OnDragEnter=SPRosterCharList.InternalOnDragEnter;
	//SPRosterCharList->OnDragLeave=SPRosterCharList.InternalOnDragLeave;
	//SPRosterCharList->OnDragOver=SPRosterCharList.InternalOnDragOver;
	UGUIGFXButton* btnMate4 = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	btnMate4->Position = EIconPosition::ICP_Scaled;
	btnMate4->bClientBound = true;
	btnMate4->StyleName = "RosterButton";
	btnMate4->Hint = "Assign the selected team member to this roster";
	btnMate4->WinTop = 0.046398;
	btnMate4->WinLeft = 0.01205;
	btnMate4->WinWidth = 0.05835;
	btnMate4->WinHeight = 0.901195;
	btnMate4->Tag = 3;
	//btnMate4->OnClick=Tab_SPRoster.FixLineup;
	//btnMate4->OnKeyEvent=btnMate4.InternalOnKeyEvent;
	UGUIComboBox* cboMate4 = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	cboMate4->Hint = "Set starting position - change with voice menu during match";
	cboMate4->WinTop = 0.567351;
	cboMate4->WinLeft = 0.323564;
	cboMate4->WinWidth = 0.55401;
	cboMate4->WinHeight = 0.23466;
	//cboMate4->OnChange=Tab_SPRoster.PositionChange;
	//cboMate4->OnKeyEvent=cboMate4.InternalOnKeyEvent;
	UGUIGFXButton* imgMate4 = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	imgMate4->Position = EIconPosition::ICP_Scaled;
	imgMate4->WinTop = 0.052442;
	imgMate4->WinLeft = 0.018244;
	imgMate4->WinWidth = 0.14;
	imgMate4->WinHeight = 0.896118;
	//imgMate4->OnKeyEvent=imgMate4.InternalOnKeyEvent;
	UGUIGFXButton* btnMate3 = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	btnMate3->Position = EIconPosition::ICP_Scaled;
	btnMate3->bClientBound = true;
	btnMate3->StyleName = "RosterButton";
	btnMate3->Hint = "Assign the selected team member to this roster";
	btnMate3->WinTop = 0.046398;
	btnMate3->WinLeft = 0.01205;
	btnMate3->WinWidth = 0.05835;
	btnMate3->WinHeight = 0.901195;
	btnMate3->Tag = 2;
	//btnMate3->OnClick=Tab_SPRoster.FixLineup;
	//btnMate3->OnKeyEvent=btnMate3.InternalOnKeyEvent;
	UGUIComboBox* cboMate3 = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	cboMate3->Hint = "Set starting position - change with voice menu during match";
	cboMate3->WinTop = 0.567351;
	cboMate3->WinLeft = 0.323564;
	cboMate3->WinWidth = 0.55401;
	cboMate3->WinHeight = 0.23466;
	//cboMate3->OnChange=Tab_SPRoster.PositionChange;
	//cboMate3->OnKeyEvent=cboMate3.InternalOnKeyEvent;
	UGUIGFXButton* imgMate3 = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	imgMate3->Position = EIconPosition::ICP_Scaled;
	imgMate3->WinTop = 0.052442;
	imgMate3->WinLeft = 0.018244;
	imgMate3->WinWidth = 0.14;
	imgMate3->WinHeight = 0.896118;
	//imgMate3->OnKeyEvent=imgMate3.InternalOnKeyEvent;
	UGUIGFXButton* btnMate2 = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	btnMate2->Position = EIconPosition::ICP_Scaled;
	btnMate2->bClientBound = true;
	btnMate2->StyleName = "RosterButton";
	btnMate2->Hint = "Assign the selected team member to this roster";
	btnMate2->WinTop = 0.046398;
	btnMate2->WinLeft = 0.01205;
	btnMate2->WinWidth = 0.05835;
	btnMate2->WinHeight = 0.901195;
	btnMate2->Tag = 1;
	//btnMate2->OnClick=Tab_SPRoster.FixLineup;
	//btnMate2->OnKeyEvent=btnMate2.InternalOnKeyEvent;
	UGUIComboBox* cboMate2 = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	cboMate2->Hint = "Set starting position - change with voice menu during match";
	cboMate2->WinTop = 0.567351;
	cboMate2->WinLeft = 0.323564;
	cboMate2->WinWidth = 0.55401;
	cboMate2->WinHeight = 0.23466;
	//cboMate2->OnChange=Tab_SPRoster.PositionChange;
	//cboMate2->OnKeyEvent=cboMate2.InternalOnKeyEvent;
	UGUIGFXButton* imgMate2 = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	imgMate2->Position = EIconPosition::ICP_Scaled;
	imgMate2->WinTop = 0.052442;
	imgMate2->WinLeft = 0.018244;
	imgMate2->WinWidth = 0.14;
	imgMate2->WinHeight = 0.896118;
	//imgMate2->OnKeyEvent=imgMate2.InternalOnKeyEvent;
	UGUIGFXButton* btnMate1 = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	btnMate1->Position = EIconPosition::ICP_Scaled;
	btnMate1->bClientBound = true;
	btnMate1->StyleName = "RosterButton";
	btnMate1->Hint = "Assign the selected team member to this roster";
	btnMate1->WinTop = 0.046398;
	btnMate1->WinLeft = 0.01205;
	btnMate1->WinWidth = 0.05835;
	btnMate1->WinHeight = 0.901195;
	btnMate1->Tag = 0;
	//btnMate1->OnClick=Tab_SPRoster.FixLineup;
	//btnMate1->OnKeyEvent=btnMate1.InternalOnKeyEvent;
	UGUIComboBox* cboMate1 = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	cboMate1->Hint = "Set starting position - change with voice menu during match";
	cboMate1->WinTop = 0.567351;
	cboMate1->WinLeft = 0.323564;
	cboMate1->WinWidth = 0.55401;
	cboMate1->WinHeight = 0.23466;
	//cboMate1->OnChange=Tab_SPRoster.PositionChange;
	//cboMate1->OnKeyEvent=cboMate1.InternalOnKeyEvent;
	UGUIGFXButton* imgMate1 = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	imgMate1->Position = EIconPosition::ICP_Scaled;
	imgMate1->WinTop = 0.052442;
	imgMate1->WinLeft = 0.018244;
	imgMate1->WinWidth = 0.14;
	imgMate1->WinHeight = 0.896118;
	//imgMate1->OnKeyEvent=imgMate1.InternalOnKeyEvent;
	UGUIListBox* SPCharStats = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	//SPCharStats->OnCreateComponent=SPCharStats.InternalOnCreateComponent;
	SPCharStats->WinTop = 0.44;
	SPCharStats->WinLeft = 0.015;
	SPCharStats->WinWidth = 0.51;
	SPCharStats->WinHeight = 0.2675;
	SPCharStats->bAcceptsInput = false;
	SPCharStats->bNeverFocus = true;
	UGUIScrollTextBox* SPCharData = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	SPCharData->CharDelay = 0.04;
	SPCharData->EOLDelay = 0.25;
	//SPCharData->OnCreateComponent=SPCharData.InternalOnCreateComponent;
	SPCharData->Hint = "Team members profile";
	SPCharData->WinTop = 0.03;
	SPCharData->WinLeft = 0.15;
	SPCharData->WinWidth = 0.4125;
	SPCharData->WinHeight = 0.4;
	SPCharData->bNeverFocus = true;
	UGUIListBox* SPRTeamStats = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	//SPRTeamStats->OnCreateComponent=SPRTeamStats.InternalOnCreateComponent;
	SPRTeamStats->WinTop = 0.722;
	SPRTeamStats->WinLeft = 0.654063;
	SPRTeamStats->WinWidth = 0.33875;
	SPRTeamStats->WinHeight = 0.186797;
	SPRTeamStats->bAcceptsInput = false;
	SPRTeamStats->bNeverFocus = true;
	UGUIImage* SPRosterBK0 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPRosterBK0->ImageColor = FColor(255, 255, 255, 160);
	SPRosterBK0->ImageStyle = EImgStyle::ISTY_Stretched;
	SPRosterBK0->WinTop = 0.015;
	SPRosterBK0->WinLeft = 0.007187;
	SPRosterBK0->WinWidth = 0.565117;
	SPRosterBK0->WinHeight = 0.7;
	UGUIImage* SPRosterPortrait = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPRosterPortrait->ImageStyle = EImgStyle::ISTY_Scaled;
	SPRosterPortrait->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	SPRosterPortrait->WinTop = 0.031077;
	SPRosterPortrait->WinLeft = 0.016562;
	SPRosterPortrait->WinWidth = 0.130957;
	SPRosterPortrait->WinHeight = 0.395;
	UGUIImage* SPRosterPortraitBorder = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPRosterPortraitBorder->ImageStyle = EImgStyle::ISTY_Stretched;
	SPRosterPortraitBorder->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	SPRosterPortraitBorder->WinTop = 0.03;
	SPRosterPortraitBorder->WinLeft = 0.015;
	SPRosterPortraitBorder->WinWidth = 0.1333;
	SPRosterPortraitBorder->WinHeight = 0.4;
	UGUILabel* SPMatchData = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPMatchData->Caption = "No Game Profile => No MatchData";
	SPMatchData->TextAlign = ETextAlign::TXTA_Center;
	SPMatchData->TextColor = FColor(255, 255, 255, 255);
	SPMatchData->TextFont = "UT2LargeFont";
	SPMatchData->WinTop = -0.12;
	SPMatchData->WinLeft = 0.1;
	SPMatchData->WinWidth = 0.8;
	SPMatchData->WinHeight = 0.1;
	SPMatchData->bVisible = false;
	UGUIImage* SPCharListBox = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPCharListBox->ImageColor = FColor(255, 255, 255, 160);
	SPCharListBox->ImageStyle = EImgStyle::ISTY_Stretched;
	SPCharListBox->WinTop = 0.722;
	SPCharListBox->WinLeft = 0.006836;
	SPCharListBox->WinWidth = 0.622268;
	SPCharListBox->WinHeight = 0.186797;
	UGUIImage* Mate1Back = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Mate1Back->ImageColor = FColor(255, 255, 255, 160);
	Mate1Back->ImageStyle = EImgStyle::ISTY_Stretched;
	Mate1Back->WinHeight = 1;
	Mate1Back->Tag = 0;
	UGUILabel* lblMate1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblMate1->Caption = "Name";
	lblMate1->TextAlign = ETextAlign::TXTA_Center;
	lblMate1->TextColor = FColor(255, 255, 255, 255);
	lblMate1->TextFont = "UT2SmallFont";
	lblMate1->WinTop = 0.249487;
	lblMate1->WinLeft = 0.174012;
	lblMate1->WinWidth = 0.797917;
	lblMate1->WinHeight = 0.213511;
	UGUILabel* lblNA1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblNA1->Caption = "SLOT NOT AVAILABLE";
	lblNA1->TextAlign = ETextAlign::TXTA_Center;
	lblNA1->TextColor = FColor(255, 255, 255, 255);
	lblNA1->TextFont = "UT2SmallFont";
	lblNA1->WinTop = 0.42;
	lblNA1->WinHeight = 0.21;
	UGUIPanel* pnlMates1 = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	pnlMates1->Controls = { Mate1Back,imgMate1,lblMate1,cboMate1,btnMate1,lblNA1 };
	pnlMates1->StyleName = "NoBackground";
	pnlMates1->WinTop = 0.015;
	pnlMates1->WinLeft = 0.59;
	pnlMates1->WinWidth = 0.4;
	pnlMates1->WinHeight = 0.175;
	UGUIImage* Mate2Back = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Mate2Back->ImageColor = FColor(255, 255, 255, 160);
	Mate2Back->ImageStyle = EImgStyle::ISTY_Stretched;
	Mate2Back->WinHeight = 1;
	Mate2Back->Tag = 1;
	UGUILabel* lblMate2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblMate2->Caption = "Name";
	lblMate2->TextAlign = ETextAlign::TXTA_Center;
	lblMate2->TextColor = FColor(255, 255, 255, 255);
	lblMate2->TextFont = "UT2SmallFont";
	lblMate2->WinTop = 0.249487;
	lblMate2->WinLeft = 0.174012;
	lblMate2->WinWidth = 0.797917;
	lblMate2->WinHeight = 0.213511;
	UGUILabel* lblNA2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblNA2->Caption = "SLOT NOT AVAILABLE";
	lblNA2->TextAlign = ETextAlign::TXTA_Center;
	lblNA2->TextColor = FColor(255, 255, 255, 255);
	lblNA2->TextFont = "UT2SmallFont";
	lblNA2->WinTop = 0.42;
	lblNA2->WinHeight = 0.21;
	UGUIPanel* pnlMates2 = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	pnlMates2->Controls = { Mate2Back,imgMate2,lblMate2,cboMate2,btnMate2,lblNA2 };
	pnlMates2->StyleName = "NoBackground";
	pnlMates2->WinTop = 0.19;
	pnlMates2->WinLeft = 0.59;
	pnlMates2->WinWidth = 0.4;
	pnlMates2->WinHeight = 0.175;
	UGUIImage* Mate3Back = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Mate3Back->ImageColor = FColor(255, 255, 255, 160);
	Mate3Back->ImageStyle = EImgStyle::ISTY_Stretched;
	Mate3Back->WinHeight = 1;
	UGUILabel* lblMate3 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblMate3->Caption = "Name";
	lblMate3->TextAlign = ETextAlign::TXTA_Center;
	lblMate3->TextColor = FColor(255, 255, 255, 255);
	lblMate3->TextFont = "UT2SmallFont";
	lblMate3->WinTop = 0.249487;
	lblMate3->WinLeft = 0.174012;
	lblMate3->WinWidth = 0.797917;
	lblMate3->WinHeight = 0.213511;
	UGUILabel* lblNA3 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblNA3->Caption = "SLOT NOT AVAILABLE";
	lblNA3->TextAlign = ETextAlign::TXTA_Center;
	lblNA3->TextColor = FColor(255, 255, 255, 255);
	lblNA3->TextFont = "UT2SmallFont";
	lblNA3->WinTop = 0.42;
	lblNA3->WinHeight = 0.21;
	UGUIPanel* pnlMates3 = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	pnlMates3->Controls = { Mate3Back,imgMate3,lblMate3,cboMate3,btnMate3,lblNA3 };
	pnlMates3->StyleName = "NoBackground";
	pnlMates3->WinTop = 0.365;
	pnlMates3->WinLeft = 0.59;
	pnlMates3->WinWidth = 0.4;
	pnlMates3->WinHeight = 0.175;
	UGUIImage* Mate4Back = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Mate4Back->ImageColor = FColor(255, 255, 255, 160);
	Mate4Back->ImageStyle = EImgStyle::ISTY_Stretched;
	Mate4Back->WinHeight = 1;
	Mate4Back->Tag = 3;
	UGUILabel* lblMate4 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblMate4->Caption = "Name";
	lblMate4->TextAlign = ETextAlign::TXTA_Center;
	lblMate4->TextColor = FColor(255, 255, 255, 255);
	lblMate4->TextFont = "UT2SmallFont";
	lblMate4->WinTop = 0.249487;
	lblMate4->WinLeft = 0.174012;
	lblMate4->WinWidth = 0.797917;
	lblMate4->WinHeight = 0.213511;
	UGUILabel* lblNA4 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblNA4->Caption = "SLOT NOT AVAILABLE";
	lblNA4->TextAlign = ETextAlign::TXTA_Center;
	lblNA4->TextColor = FColor(255, 255, 255, 255);
	lblNA4->TextFont = "UT2SmallFont";
	lblNA4->WinTop = 0.42;
	lblNA4->WinHeight = 0.21;
	UGUIPanel* pnlMates4 = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	pnlMates4->Controls = { Mate4Back,imgMate4,lblMate4,cboMate4,btnMate4,lblNA4 };
	pnlMates4->StyleName = "NoBackground";
	pnlMates4->WinTop = 0.54;
	pnlMates4->WinLeft = 0.59;
	pnlMates4->WinWidth = 0.4;
	pnlMates4->WinHeight = 0.175;
	MessageNoInfo = "No information available.";
	PostStatsMessage = "Stats";
	bFillHeight = true;
	Controls = { SPRosterBK0,SPRosterPortrait,SPRosterPortraitBorder,SPMatchData,SPCharData,SPCharStats,SPRosterCharList,SPCharListBox,pnlMates1,pnlMates2,pnlMates3,pnlMates4,SPRTeamStats };
	WinTop = 0.15;
	WinHeight = 0.77;

}


//const MatesCount = 4;
//const MatesBase = 8;
//const MatesCtrls = 5;

void UTab_SPRoster::Created()
{
	/*
	local GUIPanel Pnl;
	int32 i = 0;
	for (i = 0; i < 4; i++)
	{
		Pnl = GUIPanel(Controls[(i + 8)]);
		pnlMates[i] = Pnl;
		imgMates[i] = GUIGFXButton(Pnl.Controls[1]);
		lblMates[i] = GUILabel(Pnl.Controls[2]);
		cboMates[i] = GUIComboBox(Pnl.Controls[3]);
		btnMates[i] = GUIButton(Pnl.Controls[4]);
		lblNA[i] = GUILabel(Pnl.Controls[5]);
	}
	imgPortrait = GUIImage(Controls[1]);
	lblMatchData = GUILabel(Controls[3]);
	stbPlayerData = GUIScrollTextBox(Controls[4]);
	lboStats = GUIListBox(Controls[5]);
	cltMyTeam = GUICharacterListTeam(Controls[6]);
	lboTeamStats = GUIListBox(Controls[12]);
	*/
}

void UTab_SPRoster::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	int32 j = 0;
	MyController.RegisterStyle(class'XInterface.STY_RosterButton');
	Super::InitComponent(MyController, MyOwner);
	lboStats.List.bAcceptsInput = false;
	lboTeamStats.List.bAcceptsInput = false;
	for (i = 0; i < 4; i++)
	{
		cboMates[i].__OnChange__Delegate = None;
		cboMates[i].ReadOnly(true);
		for (j = 0; j < Class'GameProfile'.GetNumPositions(); j++)
		{
			cboMates[i].addItem(Class'GameProfile'.TextPositionDescription(j));
		}
		cboMates[i].__OnChange__Delegate = PositionChange;
		imgMates[i].__OnClick__Delegate = ClickLineup;
	}
	OnProfileUpdated();
	*/
}

bool UTab_SPRoster::CanShowPanel()
{
	/*
	if (GetProfile() == None)
	{
		return false;
	}
	if (GetProfile().PlayerTeam[0] == "")
	{
		return false;
	}
	return Super::CanShowPanel();
	*/
	return false;    //FAKE   /ELiZ
}

void UTab_SPRoster::OnProfileUpdated()
{
	ReloadPortraits();
	ChangePortraits();
	UpdateMatchInfo();
	BuildTeamStats(lboTeamStats);
}

void UTab_SPRoster::OnMatchUpdated(int32 iLadder, int32 iMatch)
{
	UpdateMatchInfo();
}

bool UTab_SPRoster::ClickLineup(UGUIComponent* Sender)
{
	/*
	int32 i = 0;
	int32 teammate = 0;
	teammate = -1;
	i = 0;
	if (i < 4)
	{
		if (Sender == imgMates[i])
		{
			teammate = i;
		}
		else
		{
			i++;
		}
	}
	if (teammate < 0)
	{
		return false;
	}
	cltMyTeam.Find(lblMates[teammate].Caption);
	ChangePortraits();
	*/
	return true;
}

bool UTab_SPRoster::FixLineup(UGUIComponent* Sender)
{
	/*
	if (GetProfile() != None)
	{
		GetProfile().SetLineup(Sender.Tag, cltMyTeam.Index);
		if (!PlayerOwner().Level.Game.SavePackage(GetProfile().PackageName))
		{
			Log("SINGLEPLAYER couldn't save profile package!");
		}
		UpdateMatchInfo();
	}
	*/
	return true;
}

void UTab_SPRoster::UpdateMatchInfo()
{
	/*
	local GameProfile GP;
	int32 nummates = 0;
	int32 i = 0;
	GP = GetProfile();
	if (GP == None)
	{
		return;
	}
	lblMatchData.Caption = GP.GetMatchDescription();
	nummates = GP.GetNumTeammatesForMatch();
	for (i = 0; i < 4; i++)
	{
		imgMates[i].bVisible = (nummates > i);
		lblMates[i].bVisible = (nummates > i);
		cboMates[i].bVisible = (nummates > i);
		lblNA[i].bVisible = (!(nummates > i));
		btnMates[i].bVisible = false;
	}
	*/
}

void UTab_SPRoster::ReloadPortraits()
{
}

void UTab_SPRoster::CharListClick(UGUIComponent* Sender)
{
	ChangePortraits();
	UpdateMatchInfo();
}

void UTab_SPRoster::ChangePortraits()
{
}

void UTab_SPRoster::BuildTeamStats(UGUIListBox* teambox)
{
}

void UTab_SPRoster::PositionChange(UGUIComponent* Sender)
{
	/*
	int32 lineupnum = 0;
	int32 i = 0;
	FString posn = "";
	lineupnum = -1;
	i = 0;
	if (i < 4)
	{
		if (Sender == cboMates[i])
		{
			lineupnum = i;
		}
		else
		{
			i++;
		}
	}
	posn = GUIComboBox(Sender).GetText();
	if (GetProfile() != None)
	{
		GetProfile().SetPosition(lineupnum, posn);
		if (!PlayerOwner().Level.Game.SavePackage(GetProfile().PackageName))
		{
			Log("SINGLEPLAYER couldn't save profile package!");
		}
	}
	*/
}