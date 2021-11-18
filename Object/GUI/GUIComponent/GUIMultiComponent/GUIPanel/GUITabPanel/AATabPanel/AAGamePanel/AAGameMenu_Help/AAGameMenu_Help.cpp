// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_Help/AAGameMenu_Help.h"

UAAGameMenu_Help::UAAGameMenu_Help()
{
	//i_Background = GUIImage'AGP_Interface.AAGameMenu_Help.MyBackground';
	//sb_GameDesc = GUIImage'AGP_Interface.AAGameMenu_Help.sbGameDesc';
	//sb_Hints = GUIImage'AGP_Interface.AAGameMenu_Help.sbHints';
	//sb_IconDesc = GUIImage'AGP_Interface.AAGameMenu_Help.sbGameIcons';
	//GameDescriptionBox = GUIScrollTextBox'AGP_Interface.AAGameMenu_Help.InfoText';
	//HintsBox = GUIScrollTextBox'AGP_Interface.AAGameMenu_Help.HintText';
	//GameIconsBox = GUIMultiColumnListBox'AGP_Interface.AAGameMenu_Help.IconInfo';
	//HintCountLabel = GUILabel'AGP_Interface.AAGameMenu_Help.HintCount';
	//PrevHintButton = GUIButton'AGP_Interface.AAGameMenu_Help.PrevHint';
	//NextHintButton = GUIButton'AGP_Interface.AAGameMenu_Help.NextHint';
	//GameDescriptionLabel = GUILabel'AGP_Interface.AAGameMenu_Help.GameDescriptionCaption';
	//HintLabel = GUILabel'AGP_Interface.AAGameMenu_Help.HintCaption';
	//GameIconsLabel = GUILabel'AGP_Interface.AAGameMenu_Help.GameIconsCaption';
	//__OnPreDraw__Delegate = "AAGameMenu_Help.FixUp";
}

void UAAGameMenu_Help::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	GameIconsBox.bDisplayHeader = False;
	InitComponent(MyController, MyOwner);
	PrevHintButton.bBoundToParent = False;
	PrevHintButton.bScaleToParent = False;
	NextHintButton.bBoundToParent = False;
	NextHintButton.bScaleToParent = False;
	HintCountLabel.bBoundToParent = False;
	HintCountLabel.bScaleToParent = False;
	*/
}

void UAAGameMenu_Help::ShowPanel(bool bShow)
{
	/*
	ShowPanel(bShow);
	if (bShow && !bReceivedGameClass)
	{
		SetTimer(1, True);
		Timer();
	}
	*/
}

void UAAGameMenu_Help::Timer()
{
	/*
	local PlayerController PC;
	local int i;
	PC = PlayerOwner();
	if (PC != None && PC.GameReplicationInfo != None && PC.GameReplicationInfo.GameClass != "")
	{
		GameClass = class<GameInfo>(DynamicLoadObject(PC.GameReplicationInfo.GameClass, Class'Class'));
		if (GameClass != None)
		{
			GameDescriptionBox.SetContent(GameClass.Default.Description);
			AllGameHints = GameClass.GetAllLoadHints();
			if (AllGameHints.Length > 0)
			{
				for (i = 0; i < AllGameHints.Length; i++)
				{
					AllGameHints[i] = GameClass.ParseLoadingHint(AllGameHints[i], PC, HintsBox.Style.FontColors[HintsBox.MenuState]);
					if (AllGameHints[i] == "")
					{
						AllGameHints.remove(i, 1);
						i--;
					}
				}
				HintsBox.SetContent(AllGameHints[CurrentHintIndex]);
				HintCountLabel.Caption = CurrentHintIndex + 1 @ "/" @ AllGameHints.Length;
				EnableComponent(PrevHintButton);
				EnableComponent(NextHintButton);
			}
			KillTimer();
			bReceivedGameClass = True;
		}
	}
	*/
}

bool UAAGameMenu_Help::ButtonClicked(UGUIComponent* Sender)
{
	/*
	if (Sender == PrevHintButton)
	{
		CurrentHintIndex--;
		if (CurrentHintIndex < 0)
		{
			CurrentHintIndex = AllGameHints.Length - 1;
		}
	}
	else
	{
		if (Sender == NextHintButton)
		{
			CurrentHintIndex++;
			if (CurrentHintIndex >= AllGameHints.Length)
			{
				CurrentHintIndex = 0;
			}
		}
	}
	HintsBox.SetContent(AllGameHints[CurrentHintIndex]);
	HintCountLabel.Caption = CurrentHintIndex + 1 @ "/" @ AllGameHints.Length;
	*/
	return true;
}
bool UAAGameMenu_Help::FixUp(UCanvas* C)
{
	return false;
}