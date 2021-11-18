// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPLadderBase/Tab_SPLadderBase.h"

UTab_SPLadderBase::UTab_SPLadderBase()
{

}

void UTab_SPLadderBase::UpdateLadderButton(ULadderButton* Btn, int32 LadderIndex, int32 MatchIndex)
{
	/*
	local GameProfile GP;
	GP = PlayerOwner().Level.Game.CurrentGameProfile;
	if (GP != None)
	{
		if (Btn.MatchInfo == None)
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
	Btn = new () class'XInterface.LadderButton';
	Btn.WinLeft = Left;
	Btn.WinWidth = 0.090234;
	Btn.WinHeight = 0.113672;
	Btn.WinTop = Top;
	Btn.__OnClick__Delegate = MatchButtonClick;
	Btn.__OnDblClick__Delegate = MatchDoubleClick;
	Btn.InitComponent(Controller, Self);
	Controls[Controls.Length] = Btn;
	UpdateLadderButton(Btn, LadderIndex, MatchIndex);
	*/
	return Btn;
}

bool UTab_SPLadderBase::SetActiveMatch(int32 Ladder, TArray<ULadderButton*>& Btns)
{
	/*
	int32 rung = 0;
	rung = GetProfile().ladderrung[Ladder];
	if ((rung < 0) || (rung >= Btns.Length))
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
	/*
	local GUITabControl TC;
	int32 i = 0;
	bool retval = false;
	retval = true;
	TC = MyTabControl();
	if ((MI != None) && (TC != None))
	{
		for (i = 0; i < TC.Controls.Length; i++)
		{
			if (Tab_SPLadderBase(TC.Controls[i]) != None)
			{
				retval = (retval && Tab_SPLadderBase(TC.Controls[i]).DoShowMatchInfo(MI));
			}
		}
		return retval;
	}
	*/
	return false;
}

bool UTab_SPLadderBase::DoShowMatchInfo(UMatchInfo* MI)
{
	/*
	local LevelSummary L;
	local Material Screenshot;
	FString S = "";
	FString mName = "";
	int32 p = 0;
	if (MI == None)
	{
		return false;
	}
	L = LevelSummary(DynamicLoadObject(MI.LevelName $ ".LevelSummary", Class'LevelSummary'));
	p = InStr(MI.LevelName, "-");
	if (p < 0)
	{
		mName = MI.LevelName;
	}
	else
	{
		mName = Right(MI.LevelName, ((Len(MI.LevelName) - p) - 1));
	}
	Screenshot = Material(DynamicLoadObject("MapThumbnails.Shot" $ mName, Class'Material'));
	if (Screenshot == None)
	{
		Screenshot = Material(DynamicLoadObject(MI.LevelName $ ".Screenshot", Class'Material'));
	}
	MapPicHolder.Image = Screenshot;
	S = Controller.LoadDecoText("XMaps", mName);
	ScrollInfo.SetContent(S $ class'XInterface.Tab_IABombingRun'.Default.GoalScoreText $ ":" @ string(int(MI.GoalScore)));
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
	/*
	local LadderButton LButton;
	local GameProfile GP;
	GP = GetProfile();
	if ((GP != None) && (LadderButton(Sender) != None))
	{
		ShowMatchInfo(LadderButton(Sender).MatchInfo);
		LButton = LadderButton(GP.NextMatchObject);
		if (LButton != None)
		{
			LButton.SetState(GP.ladderrung[LButton.LadderIndex]);
		}
		LButton = LadderButton(Sender);
		GP.CurrentLadder = LButton.LadderIndex;
		GP.CurrentMenuRung = LButton.MatchIndex;
		GP.NextMatchObject = LButton;
		LButton.StyleName = "LadderButtonActive";
		LButton.Style = Controller.GetStyle(LButton.StyleName, LButton.FontScale);
		MatchUpdated(LButton.LadderIndex, LButton.MatchIndex);
		if (GetProfile().ChampBorderObject != None)
		{
			GUIImage(GetProfile().ChampBorderObject).bVisible = false;
		}
	}
	*/
	return true;
}

bool UTab_SPLadderBase::MatchDoubleClick(UGUIComponent* Sender)
{
	/*
	local UT2SinglePlayerMain SPM;
	SPM = UT2SinglePlayerMain(MyButton.MenuOwner.MenuOwner);
	return SPM.ButtonClick(SPM.ButtonPlay);
	*/
	return false;    //FAKE   /ELiZ
}

int32 UTab_SPLadderBase::SetYellowBar(int32 Ladder, int32 Index, TArray<ULadderButton*>& Buttons)
{
	/*
	int32 rung = 0;
	local GUIComponent Ctrl;
	Ctrl = Controls[Index];
	if (GetProfile() != None)
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
		if (rung >= Buttons.Length)
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
	if (GetProfile() == None)
	{
		return false;
	}
	return Super::CanShowPanel();
	*/
	return false;    //FAKE   /ELiZ
}

UMaterialInstance* UTab_SPLadderBase::DLOMaterial(FString MaterialFullName)
{
	//return Material(DynamicLoadObject(MaterialFullName, Class'Material', true));
	return nullptr;
}
