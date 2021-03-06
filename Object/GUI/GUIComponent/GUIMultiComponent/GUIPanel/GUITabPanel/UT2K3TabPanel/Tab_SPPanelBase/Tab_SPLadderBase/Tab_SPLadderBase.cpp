// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPLadderBase/Tab_SPLadderBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/LadderButton/LadderButton.h"
#include "AA29/Object/MatchInfo/MatchInfo.h"
#include "AA29/Object/LevelSummary/LevelSummary.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_InstantActionBaseRules/Tab_IABombingRun/Tab_IABombingRun.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "AA29/Object/GameProfile/GameProfile.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2SinglePlayerMain/UT2SinglePlayerMain.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUITabButton/GUITabButton.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UTab_SPLadderBase::UTab_SPLadderBase()
{

}

void UTab_SPLadderBase::UpdateLadderButton(ULadderButton* Btn, int32 LadderIndex, int32 MatchIndex)
{
	UGameProfile* GP = nullptr;
	/*
	GP = PlayerOwner().Level.Game.CurrentGameProfile;
	if (GP != nullptr)
	{
		if (Btn.MatchInfo == nullptr)
		{
			Btn.MatchInfo = GP.GetMatchInfo(LadderIndex, MatchIndex);
			Btn.MatchIndex = MatchIndex;
			Btn.LadderIndex = LadderIndex;
		}
		Btn.SetState(GP.ladderrung[LadderIndex]);
	}
	else
	{
		Btn.SetState(-1);
	}
	*/
}

ULadderButton* UTab_SPLadderBase::NewLadderButton(int32 LadderIndex, int32 MatchIndex, float Left, float Top)
{
	ULadderButton* Btn = nullptr;
	/*
	Btn = new () ULadderButton::StaticClass();
	Btn.WinLeft = Left;
	Btn.WinWidth = 0.090234;
	Btn.WinHeight = 0.113672;
	Btn.WinTop = Top;
	Btn.__OnClick__Delegate = MatchButtonClick;
	Btn.__OnDblClick__Delegate = MatchDoubleClick;
	Btn.InitComponent(Controller, this);
	Controls[Controls.Num()] = Btn;
	UpdateLadderButton(Btn, LadderIndex, MatchIndex);
	*/
	return Btn;
}

bool UTab_SPLadderBase::SetActiveMatch(int32 Ladder, TArray<ULadderButton*>& Btns)
{
	int32 rung = 0;
	/*
	rung = GetProfile().ladderrung[Ladder];
	if ((rung < 0) || (rung >= Btns.Num()))
	{
		return false;
	}
	if (GetProfile().FindFirstUnfinishedLadder() == Ladder)
	{
		Btns[rung].OnClick(Btns[rung]);
	}
	else
	{
		ShowMatchInfo(Btns[rung].MatchInfo);
	}
	*/
	return true;
}

bool UTab_SPLadderBase::ShowMatchInfo(UMatchInfo* MI)
{
	UGUITabControl* TC = nullptr;
	int32 i = 0;
	bool retval = false;
	retval = true;
	TC = MyTabControl();
	if ((MI != nullptr) && (TC != nullptr))
	{
		for (i = 0; i < TC->Controls.Num(); i++)
		{
			if (Cast<UTab_SPLadderBase>(TC->Controls[i]) != nullptr)
			{
				retval = (retval && Cast<UTab_SPLadderBase>(TC->Controls[i])->DoShowMatchInfo(MI));
			}
		}
		return retval;
	}
	return false;
}

bool UTab_SPLadderBase::DoShowMatchInfo(UMatchInfo* MI)
{
	ULevelSummary* L = nullptr;
	UMaterialInstance* Screenshot = nullptr;
	FString S = "";
	FString mName = "";
	int32 p = 0;
	if (MI == nullptr)
	{
		return false;
	}
	/*
	L = Cast<ULevelSummary>(DynamicLoadObject(MI.LevelName + ".LevelSummary", ULevelSummary::StaticClass()));
	p = InStr(MI.LevelName, "-");
	if (p < 0)
	{
		mName = MI.LevelName;
	}
	else
	{
		mName = Right(MI.LevelName, ((Len(MI.LevelName) - p) - 1));
	}
	Screenshot = Cast<UMaterialInstance>(DynamicLoadObject("MapThumbnails.Shot" + mName, Class'Material'));
	if (Screenshot == nullptr)
	{
		Screenshot = Cast<UMaterialInstance>(DynamicLoadObject(MI.LevelName + ".Screenshot", Class'Material'));
	}
	MapPicHolder.Image = Screenshot;
	S = Controller.LoadDecoText("XMaps", mName);
	ScrollInfo.SetContent(S + UTab_IABombingRun::StaticClass().Default.GoalScoreText + ":" @ FString::FromInt(int(MI.GoalScore)));
	if (MI.MenuName != "")
	{
		MapNameLabel.Caption = MI.MenuName;
	}
	else
	{
		MapNameLabel.Caption = L.Title;
	}
	*/
	return true;
}

bool UTab_SPLadderBase::MatchButtonClick(UGUIComponent* Sender)
{
	ULadderButton* LButton = nullptr;
	UGameProfile* GP = nullptr;
	GP = GetProfile();
	if ((GP != nullptr) && (Cast<ULadderButton>(Sender) != nullptr))
	{
		ShowMatchInfo(Cast<ULadderButton>(Sender)->MatchInfo);
		LButton = Cast<ULadderButton>(GP->NextMatchObject);
		if (LButton != nullptr)
		{
			LButton->SetState(GP->ladderrung[LButton->LadderIndex]);
		}
		LButton = Cast<ULadderButton>(Sender);
		GP->CurrentLadder = LButton->LadderIndex;
		GP->CurrentMenuRung = LButton->MatchIndex;
		GP->NextMatchObject = LButton;
		LButton->StyleName = "LadderButtonActive";
		LButton->Style = Controller->GetStyle(LButton->StyleName, LButton->FontScale);
		MatchUpdated(LButton->LadderIndex, LButton->MatchIndex);
		if (GetProfile()->ChampBorderObject != nullptr)
		{
			Cast<UGUIImage>(GetProfile()->ChampBorderObject)->bVisible = false;
		}
	}
	return true;
}

bool UTab_SPLadderBase::MatchDoubleClick(UGUIComponent* Sender)
{
	UUT2SinglePlayerMain* SPM = nullptr;
	SPM = Cast<UUT2SinglePlayerMain>(MyButton->MenuOwner->MenuOwner);
	return SPM->ButtonClick(SPM->ButtonPlay);
	return false;    //FAKE   /ELiZ
}

int32 UTab_SPLadderBase::SetYellowBar(int32 Ladder, int32 Index, TArray<ULadderButton*>& Buttons)
{
	int32 rung = 0;
	UGUIComponent* Ctrl = nullptr;
	Ctrl = Controls[Index];
	/*
	if (GetProfile() != nullptr)
	{
		rung = GetProfile().ladderrung[Ladder];
	}
	else
	{
		rung = -1;
	}
	if (rung == -1)
	{
		Ctrl.bVisible = false;
	}
	else
	{
		if (rung >= Buttons.Num())
		{
			Ctrl.WinTop = Controls[(Index - 1)].WinTop;
			Ctrl.WinHeight = Controls[(Index - 1)].WinHeight;
			Ctrl.bVisible = true;
			return 1;
		}
		else
		{
			Ctrl.WinTop = (Buttons[rung].WinTop + (Buttons[rung].WinHeight / 2));
			Ctrl.WinHeight = (Buttons[0].WinTop - Ctrl.WinTop);
			Ctrl.bVisible = true;
		}
	}
	*/
	return 0;
}

bool UTab_SPLadderBase::CanShowPanel()
{
	/*
	if (GetProfile() == nullptr)
	{
		return false;
	}
	return Super::CanShowPanel();
	*/
	return false;    //FAKE   /ELiZ
}

UMaterialInstance* UTab_SPLadderBase::DLOMaterial(FString MaterialFullName)
{
	//return Cast<UMaterialInstance>(DynamicLoadObject(MaterialFullName, Class'Material', true));
	return nullptr;
}
