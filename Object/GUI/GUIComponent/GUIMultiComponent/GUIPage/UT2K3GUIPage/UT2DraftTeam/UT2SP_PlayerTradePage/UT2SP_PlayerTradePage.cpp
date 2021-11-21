// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2DraftTeam/UT2SP_PlayerTradePage/UT2SP_PlayerTradePage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UUT2SP_PlayerTradePage::UUT2SP_PlayerTradePage()
{
	UGUIButton* SPPTSwap = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPPTSwap->Caption = "SWAP";
	SPPTSwap->Hint = "Exchange this character with the active teammate";
	SPPTSwap->WinTop = 0.619584;
	SPPTSwap->WinLeft = 0.71125;
	SPPTSwap->WinWidth = 0.132812;
	SPPTSwap->WinHeight = 0.076563;
	SPPTSwap->bFocusOnWatch = true;
	//SPPTSwap->OnKeyEvent=SPPTSwap.InternalOnKeyEvent;
	MessageTitle = "Single Player | Trade Opportunity";
	MessageTradeConfirm = "Are you sure you want to trade %old% for %new%?";
	MessageTradeInfo = "You have been offered a trade for %player%.";
	MessageTradeCancel = "Are you sure you want to cancel the trade?";
	CaptionBack = "BACK";
	MessageTradePicHint = "This player is available for trade";
	bPlaySounds = false;
	/*
	Controls(0) = GUIImage'XInterface.UT2DraftTeam.SPDTRosterBK0'
	Controls(1) = GUILabel'XInterface.UT2DraftTeam.SPDTMatchData'
	Controls(2) = GUIScrollTextBox'XInterface.UT2DraftTeam.SPDTCharData'
	Controls(3) = GUIListBox'XInterface.UT2DraftTeam.SPDTCharStats'
	Controls(4) = GUICharacterListTeam'XInterface.UT2DraftTeam.SPDTRosterCharList'
	Controls(5) = GUIImage'XInterface.UT2DraftTeam.SPDTCharListBox'
	Controls(6) = GUICharacterListTeam'XInterface.UT2DraftTeam.SPDTPortrait'
	Controls(7) = GUIButton'XInterface.UT2DraftTeam.SPDTDraft'
	Controls(8) = GUIButton'XInterface.UT2DraftTeam.SPDTRelease'
	Controls(9) = GUIButton'XInterface.UT2DraftTeam.SPDTClear'
	Controls(10) = GUIButton'XInterface.UT2DraftTeam.SPDTEnter'
	Controls(11) = GUIGFXButton'XInterface.UT2DraftTeam.SPDTPicLeft'
	Controls(12) = GUIGFXButton'XInterface.UT2DraftTeam.SPDTPicRight'
	Controls(13) = GUILabel'XInterface.UT2DraftTeam.SPDTLblChoose'
	Controls(14) = GUIListBox'XInterface.UT2DraftTeam.SPDTTeamStats'
	Controls(15) = GUITitleBar'XInterface.UT2DraftTeam.SPDTHeader'
	Controls(16) = GUITitleBar'XInterface.UT2DraftTeam.SPDTHints'
	Controls(17) = GUIButton'XInterface.UT2SP_PlayerTradePage.SPPTSwap';
	*/
}

void UUT2SP_PlayerTradePage::Created()
{
	/*
	Super::Created();
	butSwap = GUIButton(Controls[17]);
	*/
}

void UUT2SP_PlayerTradePage::UpdateDraftable(bool bAffordable)
{
}

void UUT2SP_PlayerTradePage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyTitleBar.SetCaption(MessageTitle);
	butSwap.__OnClick__Delegate = ButtonClick;
	butEnter.bVisible = true;
	butEnter.bAcceptsInput = true;
	butClear.Caption = CaptionBack;
	butLeft.bVisible = false;
	butLeft.bNeverFocus = true;
	butLeft.bAcceptsInput = false;
	butRight.bVisible = false;
	butRight.bNeverFocus = true;
	butRight.bAcceptsInput = false;
	butRelease.bVisible = false;
	butRelease.bNeverFocus = true;
	butRelease.bAcceptsInput = false;
	butDraft.bVisible = false;
	butDraft.bNeverFocus = true;
	butDraft.bAcceptsInput = false;
	lblChoose.bVisible = false;
	cltPortrait.bLocked = true;
	cltPortrait.Hint = MessageTradePicHint;
	cltPortrait.__OnChange__Delegate = MyOnChange;
	cltMyTeam.bIgnoreBackClick = true;
	cltMyTeam.bAllowSelectEmpty = false;
	cltMyTeam.__OnChange__Delegate = MyOnChange;
	cltMyTeam.Index = 0;
	*/
}

void UUT2SP_PlayerTradePage::Initialize(FString PlayerName)
{
	/*
	local GUIQuestionPage page;
	SetPlayer(PlayerName);
	MyOnChange(cltPortrait);
	if (Controller.OpenMenu("XInterface.GUIQuestionPage"))
	{
		page = GUIQuestionPage(Controller.ActivePage);
		page.SetupQuestion(page.Replace(MessageTradeInfo, "player", TradingPlayerName), 8, 8);
		page.__OnButtonClick__Delegate = BeginConfirm;
	}
	*/
}

void UUT2SP_PlayerTradePage::BeginConfirm(uint8 bButton)
{
	/*
	bPlaySounds = true;
	PlayerOwner().ClientPlaySound(cltPortrait.GetSound(), , , 6);
	*/
}

void UUT2SP_PlayerTradePage::SetPlayer(FString PlayerName)
{
}

bool UUT2SP_PlayerTradePage::ButtonClick(UGUIComponent* Sender)
{
	/*
	local GUIQuestionPage page;
	FString askstr = "";
	if (Sender == butSwap)
	{
		if (Controller.OpenMenu("XInterface.GUIQuestionPage"))
		{
			page = GUIQuestionPage(Controller.ActivePage);
			askstr = page.Replace(MessageTradeConfirm, "new", TradingPlayerName);
			askstr = page.Replace(askstr, "old", cltMyTeam.GetName());
			page.SetupQuestion(askstr, 48, 32);
			page.__OnButtonClick__Delegate = SwapConfirm;
		}
		return true;
	}
	else
	{
		if ((Sender == butEnter) || (Sender == butClear))
		{
			if (Controller.OpenMenu("XInterface.GUIQuestionPage"))
			{
				page = GUIQuestionPage(Controller.ActivePage);
				page.SetupQuestion(MessageTradeCancel, 48, 32);
				page.__OnButtonClick__Delegate = CancelConfirm;
			}
			return true;
		}
		else
		{
			return Super::ButtonClick(Sender);
		}
	}
	FinishButtonClick();
	*/
	return true;
}

void UUT2SP_PlayerTradePage::SwapConfirm(uint8 bButton)
{
	/*
	local GameProfile GP;
	if (bButton == 16)
	{
		GP = PlayerOwner().Level.Game.CurrentGameProfile;
		Log("SINGLEPLAYER Teammate in spot" @ string(cltMyTeam.Index) @ "is" @ GP.PlayerTeam[cltMyTeam.Index]);
		GP.PlayerTeam[cltMyTeam.Index] = TradingPlayerName;
		Log("SINGLEPLAYER Teammate in spot" @ string(cltMyTeam.Index) @ "is -now-" @ GP.PlayerTeam[cltMyTeam.Index]);
		PlayerOwner().Level.Game.SavePackage(GP.PackageName);
		UT2SinglePlayerMain(Controller.ActivePage.ParentPage).PassThroughProfileUpdated();
		Controller.CloseMenu();
	}
	*/
}

void UUT2SP_PlayerTradePage::CancelConfirm(uint8 bButton)
{
	if (bButton == 16)
	{
		//Controller.CloseMenu();
	}
}

void UUT2SP_PlayerTradePage::MyOnChange(UGUIComponent* Sender)
{
}
