// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_Help/AAGameMenu_Help.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAGameMenu_Help::UAAGameMenu_Help()
{
	UGUIButton* NextHint = NewObject<UGUIButton>(UGUIButton::StaticClass());
	NextHint->Caption = "Next Hint";
	NextHint->bAutoSize = true;
	NextHint->MenuState = EMenuState::MSAT_Disabled;
	NextHint->StyleName = "SquareMenuButton";
	NextHint->Hint = "Click here to view the next hint.";
	NextHint->WinTop = 0.82;
	NextHint->WinLeft = 0.7;
	NextHint->WinWidth = 0.15;
	NextHint->WinHeight = 0.06;
	NextHint->TabOrder = 1;
	//NextHint->OnClick=AAGameMenu_Help.ButtonClicked;
	//NextHint->OnKeyEvent=NextHint.InternalOnKeyEvent;
	UGUIButton* PrevHint = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PrevHint->Caption = "Previous Hint";
	PrevHint->bAutoSize = true;
	PrevHint->MenuState = EMenuState::MSAT_Disabled;
	PrevHint->StyleName = "SquareMenuButton";
	PrevHint->Hint = "Click here to view the previous hint.";
	PrevHint->WinTop = 0.82;
	PrevHint->WinLeft = 0.15;
	PrevHint->WinWidth = 0.15;
	PrevHint->WinHeight = 0.06;
	PrevHint->TabOrder = 0;
	//PrevHint->OnClick=AAGameMenu_Help.ButtonClicked;
	//PrevHint->OnKeyEvent=PrevHint.InternalOnKeyEvent;
	UGUIScrollTextBox* HintText = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	HintText->bNoTeletype = true;
	HintText->CharDelay = 0.0025;
	HintText->EOLDelay = 0;
	HintText->TextAlign = EeTextAlign::TXTA_Center;
	//HintText->OnCreateComponent=HintText.InternalOnCreateComponent;
	HintText->WinTop = 0.7;
	HintText->WinLeft = 0.03;
	HintText->WinWidth = 0.94;
	HintText->WinHeight = 0.12;
	HintText->bBoundToParent = true;
	HintText->bScaleToParent = true;
	HintText->bNeverFocus = true;
	UGUIMultiColumnListBox* IconInfo = NewObject<UGUIMultiColumnListBox>(UGUIMultiColumnListBox::StaticClass());
	IconInfo->DefaultListClass = "AGP_Interface.AAHelpList";
	IconInfo->bVisibleWhenEmpty = true;
	//IconInfo->OnCreateComponent=IconInfo.InternalOnCreateComponent;
	IconInfo->WinTop = 0.315;
	IconInfo->WinLeft = 0.02;
	IconInfo->WinWidth = 0.96;
	IconInfo->WinHeight = 0.28;
	IconInfo->RenderWeight = 0.01;
	IconInfo->bBoundToParent = true;
	IconInfo->bScaleToParent = true;
	IconInfo->bAcceptsInput = false;
	IconInfo->bNeverFocus = true;
	UGUIScrollTextBox* InfoText = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	InfoText->bNoTeletype = true;
	InfoText->CharDelay = 0.0025;
	InfoText->EOLDelay = 0;
	InfoText->TextAlign = EeTextAlign::TXTA_Center;
	//InfoText->OnCreateComponent=InfoText.InternalOnCreateComponent;
	InfoText->WinTop = 0.09;
	InfoText->WinLeft = 0.03;
	InfoText->WinWidth = 0.94;
	InfoText->WinHeight = 0.12;
	InfoText->bBoundToParent = true;
	InfoText->bScaleToParent = true;
	InfoText->bNeverFocus = true;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfil_Mat.backgroundfil_Mat'"), NULL, LOAD_None, NULL);
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinTop = 0.01;
	MyBackground->WinLeft = 0.01;
	MyBackground->WinWidth = 0.98;
	MyBackground->WinHeight = 0.89;
	MyBackground->RenderWeight = 0;
	MyBackground->bBoundToParent = true;
	MyBackground->bScaleToParent = true;
	UGUIImage* sbGameDesc = NewObject<UGUIImage>(UGUIImage::StaticClass());
	sbGameDesc->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	sbGameDesc->ImageStyle = EImgStyle::ISTY_Stretched;
	sbGameDesc->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	sbGameDesc->WinTop = 0.02;
	sbGameDesc->WinLeft = 0.02;
	sbGameDesc->WinWidth = 0.96;
	sbGameDesc->WinHeight = 0.28;
	sbGameDesc->bBoundToParent = true;
	sbGameDesc->bScaleToParent = true;
	UGUIImage* sbGameIcons = NewObject<UGUIImage>(UGUIImage::StaticClass());
	sbGameIcons->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	sbGameIcons->ImageStyle = EImgStyle::ISTY_Stretched;
	sbGameIcons->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	sbGameIcons->WinTop = 0.315;
	sbGameIcons->WinLeft = 0.02;
	sbGameIcons->WinWidth = 0.96;
	sbGameIcons->WinHeight = 0.28;
	sbGameIcons->RenderWeight = 0.0001;
	sbGameIcons->bBoundToParent = true;
	sbGameIcons->bScaleToParent = true;
	UGUIImage* sbHints = NewObject<UGUIImage>(UGUIImage::StaticClass());
	sbHints->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	sbHints->ImageStyle = EImgStyle::ISTY_Stretched;
	sbHints->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	sbHints->WinTop = 0.61;
	sbHints->WinLeft = 0.02;
	sbHints->WinWidth = 0.96;
	sbHints->WinHeight = 0.28;
	sbHints->bBoundToParent = true;
	sbHints->bScaleToParent = true;
	UGUILabel* HintCount = NewObject<UGUILabel>(UGUILabel::StaticClass());
	HintCount->TextAlign = ETextAlign::TXTA_Center;
	HintCount->TextColor = FColor(255, 255, 255, 255);
	HintCount->TextFont = "AAFontMedium";
	HintCount->WinTop = 0.82;
	HintCount->WinLeft = 0.3;
	HintCount->WinWidth = 0.4;
	UGUILabel* GameDescriptionCaption = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GameDescriptionCaption->Caption = "Game Description";
	GameDescriptionCaption->TextAlign = ETextAlign::TXTA_Center;
	GameDescriptionCaption->TextColor = FColor(255, 255, 255, 255);
	GameDescriptionCaption->TextFont = "AAFontLarge";
	GameDescriptionCaption->WinTop = 0.02;
	GameDescriptionCaption->WinLeft = 0.03;
	GameDescriptionCaption->WinWidth = 0.94;
	UGUILabel* GameIconsCaption = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GameIconsCaption->Caption = "Icon Key";
	GameIconsCaption->TextAlign = ETextAlign::TXTA_Center;
	GameIconsCaption->TextColor = FColor(255, 255, 255, 255);
	GameIconsCaption->TextFont = "AAFontLarge";
	GameIconsCaption->WinTop = 0.315;
	GameIconsCaption->WinLeft = 0.03;
	GameIconsCaption->WinWidth = 0.94;
	GameIconsCaption->RenderWeight = 1;
	UGUILabel* HintCaption = NewObject<UGUILabel>(UGUILabel::StaticClass());
	HintCaption->Caption = "Helpful Hints";
	HintCaption->TextAlign = ETextAlign::TXTA_Center;
	HintCaption->TextColor = FColor(255, 255, 255, 255);
	HintCaption->TextFont = "AAFontLarge";
	HintCaption->WinTop = 0.61;
	HintCaption->WinLeft = 0.03;
	HintCaption->WinWidth = 0.94;
	i_Background = MyBackground;
	sb_GameDesc = sbGameDesc;
	sb_Hints = sbHints;
	sb_IconDesc = sbGameIcons;
	GameDescriptionBox = InfoText;
	HintsBox = HintText;
	GameIconsBox = IconInfo;
	HintCountLabel = HintCount;
	PrevHintButton = PrevHint;
	NextHintButton = NextHint;
	GameDescriptionLabel = GameDescriptionCaption;
	HintLabel = HintCaption;
	GameIconsLabel = GameIconsCaption;

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