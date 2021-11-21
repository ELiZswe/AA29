// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2DraftTeam/UT2DraftTeam.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICharacterList/GUICharacterListTeam/GUICharacterListTeam.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"

UUT2DraftTeam::UUT2DraftTeam()
{
	UGUICharacterListTeam* SPDTPortrait = NewObject<UGUICharacterListTeam>(UGUICharacterListTeam::StaticClass());
	SPDTPortrait->bFillBounds = true;
	SPDTPortrait->FixedItemsPerPage = 1;
	SPDTPortrait->StyleName = "CharButton";
	SPDTPortrait->Hint = "Select teammate";
	SPDTPortrait->WinTop = 0.190313;
	SPDTPortrait->WinLeft = 0.6875;
	SPDTPortrait->WinWidth = 0.1333;
	SPDTPortrait->WinHeight = 0.4;
	//SPDTPortrait->OnClick=SPDTPortrait.InternalOnClick;
	//SPDTPortrait->OnRightClick=SPDTPortrait.InternalOnRightClick;
	//SPDTPortrait->OnMousePressed=SPDTPortrait.InternalOnMousePressed;
	//SPDTPortrait->OnMouseRelease=SPDTPortrait.InternalOnMouseRelease;
	//SPDTPortrait->OnKeyEvent=SPDTPortrait.InternalOnKeyEvent;
	//SPDTPortrait->OnBeginDrag=SPDTPortrait.InternalOnBeginDrag;
	//SPDTPortrait->OnEndDrag=SPDTPortrait.InternalOnEndDrag;
	//SPDTPortrait->OnDragDrop=SPDTPortrait.InternalOnDragDrop;
	//SPDTPortrait->OnDragEnter=SPDTPortrait.InternalOnDragEnter;
	//SPDTPortrait->OnDragLeave=SPDTPortrait.InternalOnDragLeave;
	//SPDTPortrait->OnDragOver=SPDTPortrait.InternalOnDragOver;
	UGUICharacterListTeam* SPDTRosterCharList = NewObject<UGUICharacterListTeam>(UGUICharacterListTeam::StaticClass());
	SPDTRosterCharList->bLocked = true;
	SPDTRosterCharList->bFillBounds = true;
	SPDTRosterCharList->bAllowSelectEmpty = false;
	SPDTRosterCharList->FixedItemsPerPage = 7;
	SPDTRosterCharList->StyleName = "CharButton";
	SPDTRosterCharList->Hint = "Choose a teammate to play in the next match";
	SPDTRosterCharList->WinTop = 0.75;
	SPDTRosterCharList->WinLeft = 0.004688;
	SPDTRosterCharList->WinWidth = 0.670315;
	SPDTRosterCharList->WinHeight = 0.17;
	//SPDTRosterCharList->OnClick=SPDTRosterCharList.InternalOnClick;
	//SPDTRosterCharList->OnRightClick=SPDTRosterCharList.InternalOnRightClick;
	//SPDTRosterCharList->OnMousePressed=SPDTRosterCharList.InternalOnMousePressed;
	//SPDTRosterCharList->OnMouseRelease=SPDTRosterCharList.InternalOnMouseRelease;
	//SPDTRosterCharList->OnKeyEvent=SPDTRosterCharList.InternalOnKeyEvent;
	//SPDTRosterCharList->OnBeginDrag=SPDTRosterCharList.InternalOnBeginDrag;
	//SPDTRosterCharList->OnEndDrag=SPDTRosterCharList.InternalOnEndDrag;
	//SPDTRosterCharList->OnDragDrop=SPDTRosterCharList.InternalOnDragDrop;
	//SPDTRosterCharList->OnDragEnter=SPDTRosterCharList.InternalOnDragEnter;
	//SPDTRosterCharList->OnDragLeave=SPDTRosterCharList.InternalOnDragLeave;
	//SPDTRosterCharList->OnDragOver=SPDTRosterCharList.InternalOnDragOver;
	UGUIScrollTextBox* SPDTCharData = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	SPDTCharData->CharDelay = 0.04;
	SPDTCharData->EOLDelay = 0.25;
	//SPDTCharData->OnCreateComponent=SPDTCharData.InternalOnCreateComponent;
	SPDTCharData->Hint = "Team members profile";
	SPDTCharData->WinTop = 0.129167;
	SPDTCharData->WinLeft = 0.024063;
	SPDTCharData->WinWidth = 0.52;
	SPDTCharData->WinHeight = 0.359687;
	SPDTCharData->bNeverFocus = true;
	UGUIListBox* SPDTCharStats = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	//SPDTCharStats->OnCreateComponent=SPDTCharStats.InternalOnCreateComponent;
	SPDTCharStats->WinTop = 0.491249;
	SPDTCharStats->WinLeft = 0.024063;
	SPDTCharStats->WinWidth = 0.52;
	SPDTCharStats->WinHeight = 0.237813;
	SPDTCharStats->bAcceptsInput = false;
	SPDTCharStats->bNeverFocus = true;
	UGUIButton* SPDTDraft = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPDTDraft->Caption = "DRAFT";
	SPDTDraft->Hint = "Add this character to your team";
	SPDTDraft->WinTop = 0.602917;
	SPDTDraft->WinLeft = 0.620626;
	SPDTDraft->WinWidth = 0.132812;
	SPDTDraft->WinHeight = 0.055;
	SPDTDraft->bFocusOnWatch = true;
	//SPDTDraft->OnKeyEvent=SPDTDraft.InternalOnKeyEvent;
	UGUIButton* SPDTRelease = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPDTRelease->Caption = "RELEASE";
	SPDTRelease->Hint = "Remove this character from your team";
	SPDTRelease->WinTop = 0.602917;
	SPDTRelease->WinLeft = 0.804998;
	SPDTRelease->WinWidth = 0.132812;
	SPDTRelease->WinHeight = 0.055;
	SPDTRelease->bFocusOnWatch = true;
	//SPDTRelease->OnKeyEvent=SPDTRelease.InternalOnKeyEvent;
	UGUIButton* SPDTClear = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPDTClear->Caption = "CLEAR";
	SPDTClear->StyleName = "SquareMenuButton";
	SPDTClear->Hint = "Clear your team roster";
	SPDTClear->WinTop = 0.93;
	SPDTClear->WinWidth = 0.12;
	SPDTClear->WinHeight = 0.055;
	SPDTClear->bFocusOnWatch = true;
	//SPDTClear->OnKeyEvent=SPDTClear.InternalOnKeyEvent;
	UGUIButton* SPDTEnter = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPDTEnter->Caption = "PLAY";
	SPDTEnter->StyleName = "SquareMenuButton";
	SPDTEnter->Hint = "Enter tournament with this team";
	SPDTEnter->WinTop = 0.93;
	SPDTEnter->WinLeft = 0.88;
	SPDTEnter->WinWidth = 0.12;
	SPDTEnter->WinHeight = 0.055;
	SPDTEnter->bFocusOnWatch = true;
	//SPDTEnter->OnKeyEvent=SPDTEnter.InternalOnKeyEvent;
	UGUIGFXButton* SPDTPicLeft = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	SPDTPicLeft->Position = EIconPosition::ICP_Scaled;
	SPDTPicLeft->Hint = "Select teammate";
	SPDTPicLeft->WinTop = 0.335833;
	SPDTPicLeft->WinLeft = 0.601563;
	SPDTPicLeft->WinWidth = 0.08;
	SPDTPicLeft->WinHeight = 0.08;
	SPDTPicLeft->bFocusOnWatch = true;
	//SPDTPicLeft->OnKeyEvent=SPDTPicLeft.InternalOnKeyEvent;
	UGUIGFXButton* SPDTPicRight = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	SPDTPicRight->Position = EIconPosition::ICP_Scaled;
	SPDTPicRight->Hint = "Select teammate";
	SPDTPicRight->WinTop = 0.335833;
	SPDTPicRight->WinLeft = 0.870312;
	SPDTPicRight->WinWidth = 0.08;
	SPDTPicRight->WinHeight = 0.08;
	SPDTPicRight->bFocusOnWatch = true;
	//SPDTPicRight->OnKeyEvent=SPDTPicRight.InternalOnKeyEvent;
	UGUIListBox* SPDTTeamStats = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	//SPDTTeamStats->OnCreateComponent=SPDTTeamStats.InternalOnCreateComponent;
	SPDTTeamStats->WinTop = 0.739166;
	SPDTTeamStats->WinLeft = 0.654063;
	SPDTTeamStats->WinWidth = 0.33875;
	SPDTTeamStats->WinHeight = 0.189062;
	SPDTTeamStats->bAcceptsInput = false;
	SPDTTeamStats->bNeverFocus = true;
	UGUIButton* SPDTAuto = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPDTAuto->Caption = "AUTO FILL";
	SPDTAuto->Hint = "Automatically fill your team";
	SPDTAuto->WinTop = 0.666667;
	SPDTAuto->WinLeft = 0.681245;
	SPDTAuto->WinWidth = 0.1875;
	SPDTAuto->WinHeight = 0.055;
	SPDTAuto->bFocusOnWatch = true;
	//SPDTAuto->OnKeyEvent=SPDTAuto.InternalOnKeyEvent;
	UGUITitleBar* SPDTHints = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	SPDTHints->bUseTextHeight = false;
	SPDTHints->StyleName = "Footer";
	SPDTHints->WinTop = 0.93;
	SPDTHints->WinLeft = 0.12;
	SPDTHints->WinWidth = 0.76;
	SPDTHints->WinHeight = 0.055;
	UGUITitleBar* SPDTHeader = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	SPDTHeader->Caption = "Single Player | Draft your team";
	SPDTHeader->StyleName = "Header";
	SPDTHeader->WinTop = 0.036406;
	SPDTHeader->WinHeight = 46;
	UGUILabel* SPDTLblChoose = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPDTLblChoose->Caption = "Choose Teammate";
	SPDTLblChoose->TextAlign = ETextAlign::TXTA_Center;
	SPDTLblChoose->TextColor = FColor(255, 255, 255, 255);
	SPDTLblChoose->TextFont = "UT2HeaderFont";
	SPDTLblChoose->WinTop = 0.122084;
	SPDTLblChoose->WinLeft = 0.592498;
	SPDTLblChoose->WinWidth = 0.36875;
	SPDTLblChoose->WinHeight = 0.079687;
	UGUIImage* SPDTCharListBox = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPDTCharListBox->ImageColor = FColor(255, 255, 255, 160);
	SPDTCharListBox->ImageStyle = EImgStyle::ISTY_Stretched;
	SPDTCharListBox->WinTop = 0.741667;
	SPDTCharListBox->WinLeft = 0.007813;
	SPDTCharListBox->WinWidth = 0.639846;
	SPDTCharListBox->WinHeight = 0.185625;
	UGUILabel* SPDTMatchData = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPDTMatchData->Caption = "No Game Profile => No MatchData";
	SPDTMatchData->TextAlign = ETextAlign::TXTA_Center;
	SPDTMatchData->TextColor = FColor(255, 255, 255, 255);
	SPDTMatchData->TextFont = "UT2LargeFont";
	SPDTMatchData->WinTop = -0.12;
	SPDTMatchData->WinLeft = 0.1;
	SPDTMatchData->WinWidth = 0.8;
	SPDTMatchData->WinHeight = 0.1;
	UGUIImage* SPDTRosterBK0 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPDTRosterBK0->ImageColor = FColor(255, 255, 255, 160);
	SPDTRosterBK0->ImageStyle = EImgStyle::ISTY_Stretched;
	SPDTRosterBK0->WinTop = 0.130833;
	SPDTRosterBK0->WinLeft = 0.586875;
	SPDTRosterBK0->WinWidth = 0.377617;
	SPDTRosterBK0->WinHeight = 0.598438;
	ButtonStyleEnabled = "RoundButton";
	ButtonStyleDisabled = "NoBackground";
	ClearConfirmMessage = "This action will empty your current roster.  Are you sure?";
	EnterConfirmMessage = "Are you ready to enter the tournament?";
	StatsMessage = "Stats";
	bPlaySounds = true;
	Controls = { SPDTRosterBK0,SPDTMatchData,SPDTCharData,SPDTCharStats,SPDTRosterCharList,SPDTCharListBox,SPDTPortrait,SPDTDraft,SPDTRelease,SPDTClear,SPDTEnter,SPDTPicLeft,SPDTPicRight,SPDTLblChoose,SPDTTeamStats,SPDTHeader,SPDTHints,SPDTAuto };
	WinHeight = 1;
	bAcceptsInput = false;
}

void UUT2DraftTeam::Created()
{
	/*
	lblMatchData = GUILabel(Controls[1]);
	stbPlayerData = GUIScrollTextBox(Controls[2]);
	lboStats = GUIListBox(Controls[3]);
	cltMyTeam = GUICharacterListTeam(Controls[4]);
	cltPortrait = GUICharacterListTeam(Controls[6]);
	butDraft = GUIButton(Controls[7]);
	butRelease = GUIButton(Controls[8]);
	butClear = GUIButton(Controls[9]);
	butEnter = GUIButton(Controls[10]);
	butLeft = GUIGFXButton(Controls[11]);
	butRight = GUIGFXButton(Controls[12]);
	lblChoose = GUILabel(Controls[13]);
	lboTeamStats = GUIListBox(Controls[14]);
	MyTitleBar = GUITitleBar(Controls[15]);
	MyHintBar = GUITitleBar(Controls[16]);
	butAuto = GUIButton(Controls[17]);
	__OnKeyEvent__Delegate = MyKeyEvent;
	*/
}

bool UUT2DraftTeam::MyKeyEvent(uint8& Key, uint8& State, float Delta)
{
	if (Key == 27)
	{
		return true;
	}
	return false;
}

void UUT2DraftTeam::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	MyController.RegisterStyle(class'XInterface.STY_RosterButton');
	Super::InitComponent(MyController, MyOwner);
	cltPortrait.InitListInclusive("SP");
	cltPortrait.Find("Gorge");
	cltPortrait.__OnChange__Delegate = CharListChange;
	CharListUpdate(cltPortrait);
	ReloadPortraits();
	butEnter.bVisible = false;
	butEnter.bAcceptsInput = false;
	butDraft.__OnClick__Delegate = ButtonClick;
	butRelease.__OnClick__Delegate = ButtonClick;
	butClear.__OnClick__Delegate = ButtonClick;
	butEnter.__OnClick__Delegate = ButtonClick;
	butLeft.__OnClick__Delegate = ButtonClick;
	butRight.__OnClick__Delegate = ButtonClick;
	butAuto.__OnClick__Delegate = ButtonClick;
	lboStats.List.bAcceptsInput = false;
	lboTeamStats.List.bAcceptsInput = false;
	cltMyTeam.__OnChange__Delegate = CharListChange;
	cltMyTeam.Index = -1;
	*/
}

void UUT2DraftTeam::ReloadPortraits()
{
}

void UUT2DraftTeam::CharListUpdate(UGUIComponent* Sender)
{
}

void UUT2DraftTeam::CharListChange(UGUIComponent* Sender)
{
	/*
	OnChange(Sender);
	if (Sender == cltMyTeam)
	{
		if (cltMyTeam.GetName() == "")
		{
			cltMyTeam.Index = -1;
		}
		else
		{
			cltPortrait.Find(cltMyTeam.GetName());
			CharListUpdate(Sender);
		}
	}
	*/
}

bool UUT2DraftTeam::IsOnTeam(FString botname)
{
	/*
	int32 i = 0;
	local GameProfile GP;
	if (botname == "")
	{
		return false;
	}
	GP = PlayerOwner().Level.Game.CurrentGameProfile;
	if (GP != None)
	{
		for (i = 0; i < GP.7; i++)
		{
			if (GP.PlayerTeam[i] ~= botname)
			{
				return true;
			}
		}
	}
	*/
	return false;
}

bool UUT2DraftTeam::IsTeamFull()
{
	/*
	local GameProfile GP;
	int32 i = 0;
	GP = PlayerOwner().Level.Game.CurrentGameProfile;
	if (GP.PlayerTeam.Length < GP.7)
	{
		return false;
	}
	for (i = 0; i < GP.7; i++)
	{
		if (GP.PlayerTeam[i] == "")
		{
			return false;
		}
	}
	*/
	return true;
}

void UUT2DraftTeam::UpdateDraftable(bool bAffordable)
{
	/*
	bool bOnTeam = false;
	bool bCanDraft = false;
	bCanDraft = (bAffordable && (!IsTeamFull()));
	bOnTeam = IsOnTeam(cltPortrait.GetName());
	butDraft.bAcceptsInput = ((!bOnTeam) && bCanDraft);
	butRelease.bAcceptsInput = bOnTeam;
	butDraft.bVisible = butDraft.bAcceptsInput;
	butRelease.bVisible = butRelease.bAcceptsInput;
	*/
}

void UUT2DraftTeam::AutoFillTeam()
{
	/*
	int32 nextDraft = 0;
	bool oldbPlaySounds = false;
	local GameProfile GP;
	int32 listsize = 0;
	int32 i = 0;
	int32 listoffset = 0;
	GP = PlayerOwner().Level.Game.CurrentGameProfile;
	if (GP == None)
	{
		return;
	}
	oldbPlaySounds = bPlaySounds;
	for (nextDraft = 0; nextDraft < 7; nextDraft++)
	{
		if (GP.PlayerTeam[nextDraft] != "")
		{
		}
		listoffset = (cltPortrait.Index + Rand((listsize - 1)));
		listoffset = int((float(listoffset) % float(listsize)));
		for (i = 0; i < listoffset; i++)
		{
			cltPortrait.ScrollRight();
		}
		if (IsOnTeam(cltPortrait.GetName()))
		{
			cltPortrait.ScrollRight();
		}
		GP.PlayerTeam[nextDraft] = cltPortrait.GetName();
	}
	bPlaySounds = oldbPlaySounds;

	*/
}

bool UUT2DraftTeam::ButtonClick(UGUIComponent* Sender)
{
	/*
	local GameProfile GP;
	local GUIQuestionPage page;
	bool oldbPlaySounds = false;
	GP = PlayerOwner().Level.Game.CurrentGameProfile;
	oldbPlaySounds = bPlaySounds;
	if (Sender == butDraft)
	{
		bPlaySounds = false;
		GP.AddTeammate(cltPortrait.GetName());
	}
	else
	{
		if (Sender == butRelease)
		{
			bPlaySounds = false;
			GP.ReleaseTeammate(cltPortrait.GetName());
			cltMyTeam.Index = -1;
		}
		else
		{
			if (Sender == butClear)
			{
				if (Controller.OpenMenu("XInterface.GUIQuestionPage"))
				{
					page = GUIQuestionPage(Controller.ActivePage);
					page.SetupQuestion(ClearConfirmMessage, 48, 32);
					page.__OnButtonClick__Delegate = ClearConfirm;
				}
				return true;
			}
			else
			{
				if (Sender == butEnter)
				{
					if (Controller.OpenMenu("XInterface.GUIQuestionPage"))
					{
						page = GUIQuestionPage(Controller.ActivePage);
						page.SetupQuestion(EnterConfirmMessage, 48, 32);
						page.__OnButtonClick__Delegate = EnterConfirm;
					}
					return true;
				}
				else
				{
					if (Sender == butLeft)
					{
						cltPortrait.ScrollLeft();
					}
					else
					{
						if (Sender == butRight)
						{
							cltPortrait.ScrollRight();
						}
						else
						{
							if (Sender == butAuto)
							{
								AutoFillTeam();
							}
						}
					}
				}
			}
		}
	}
	FinishButtonClick();
	bPlaySounds = oldbPlaySounds;
	*/
	return true;
}

void UUT2DraftTeam::ChangeHint(FString NewHint)
{
	//MyHintBar.SetCaption(NewHint);
}

void UUT2DraftTeam::FinishButtonClick()
{
	/*
	butEnter.bVisible = IsTeamFull();
	butEnter.bAcceptsInput = IsTeamFull();
	ReloadPortraits();
	CharListUpdate(cltPortrait);
	*/
}

void UUT2DraftTeam::ClearConfirm(uint8 bButton)
{
	/*
	if (bButton == 16)
	{
		PlayerOwner().Level.Game.CurrentGameProfile.ClearTeammates();
		FinishButtonClick();
	}
	*/
}

void UUT2DraftTeam::EnterConfirm(uint8 bButton)
{
	/*
	if (bButton == 16)
	{
		PlayerOwner().Level.Game.SavePackage(PlayerOwner().Level.Game.CurrentGameProfile.PackageName);
		Controller.CloseMenu();
	}
	*/
}