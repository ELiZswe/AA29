// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPTutorials/Tab_SPTutorials.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_SPTutorials::UTab_SPTutorials()
{
	UGUIButton* SPTutBRButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPTutBRButton->StyleName = "NoBackground";
	SPTutBRButton->WinTop = 0.46666;
	SPTutBRButton->WinLeft = 0.55;
	SPTutBRButton->WinWidth = 0.4;
	SPTutBRButton->WinHeight = 0.415;
	SPTutBRButton->bFocusOnWatch = true;
	//SPTutBRButton->OnClick=Tab_SPTutorials.InternalOnClick;
	//SPTutBRButton->OnKeyEvent=SPTutBRButton.InternalOnKeyEvent;
	UGUIButton* SPTutCTFButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPTutCTFButton->StyleName = "NoBackground";
	SPTutCTFButton->WinTop = 0.03333;
	SPTutCTFButton->WinLeft = 0.55;
	SPTutCTFButton->WinWidth = 0.4;
	SPTutCTFButton->WinHeight = 0.4;
	SPTutCTFButton->bFocusOnWatch = true;
	//SPTutCTFButton->OnClick=Tab_SPTutorials.InternalOnClick;
	//SPTutCTFButton->OnKeyEvent=SPTutCTFButton.InternalOnKeyEvent;
	UGUIButton* SPTutDOMButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPTutDOMButton->StyleName = "NoBackground";
	SPTutDOMButton->WinTop = 0.46666;
	SPTutDOMButton->WinLeft = 0.05;
	SPTutDOMButton->WinWidth = 0.4;
	SPTutDOMButton->WinHeight = 0.415;
	SPTutDOMButton->bFocusOnWatch = true;
	//SPTutDOMButton->OnClick=Tab_SPTutorials.InternalOnClick;
	//SPTutDOMButton->OnKeyEvent=SPTutDOMButton.InternalOnKeyEvent;
	UGUIButton* SPTutDMButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPTutDMButton->StyleName = "NoBackground";
	SPTutDMButton->WinTop = 0.0333;
	SPTutDMButton->WinLeft = 0.05;
	SPTutDMButton->WinWidth = 0.4;
	SPTutDMButton->WinHeight = 0.4;
	SPTutDMButton->bFocusOnWatch = true;
	//SPTutDMButton->OnClick=Tab_SPTutorials.InternalOnClick;
	//SPTutDMButton->OnKeyEvent=SPTutDMButton.InternalOnKeyEvent;
	UGUIImage* SPTutDM = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPTutDM->ImageStyle = EImgStyle::ISTY_Stretched;
	SPTutDM->X1 = 0;
	SPTutDM->Y1 = 0;
	SPTutDM->X2 = 1023;
	SPTutDM->Y2 = 767;
	SPTutDM->WinTop = 0.05;
	SPTutDM->WinLeft = 0.1;
	SPTutDM->WinWidth = 0.3;
	SPTutDM->WinHeight = 0.3;
	UGUIImage* SPTutDMB = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPTutDMB->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxA_Mat.BorderBoxA_Mat'"), NULL, LOAD_None, NULL);
	SPTutDMB->ImageStyle = EImgStyle::ISTY_Stretched;
	SPTutDMB->WinTop = 0.045846;
	SPTutDMB->WinLeft = 0.097344;
	SPTutDMB->WinWidth = 0.304563;
	SPTutDMB->WinHeight = 0.305562;
	UGUILabel* SPTutDML = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPTutDML->TextAlign = ETextAlign::TXTA_Center;
	SPTutDML->StyleName = "TextButton";
	SPTutDML->WinTop = 0.35;
	SPTutDML->WinLeft = 0.05;
	SPTutDML->WinWidth = 0.4;
	SPTutDML->WinHeight = 0.1;
	UGUIImage* SPTutDOM = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPTutDOM->ImageStyle = EImgStyle::ISTY_Stretched;
	SPTutDOM->X1 = 0;
	SPTutDOM->Y1 = 0;
	SPTutDOM->X2 = 1023;
	SPTutDOM->Y2 = 767;
	SPTutDOM->WinTop = 0.5;
	SPTutDOM->WinLeft = 0.1;
	SPTutDOM->WinWidth = 0.3;
	SPTutDOM->WinHeight = 0.3;
	UGUIImage* SPTutDOMB = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPTutDOMB->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxA_Mat.BorderBoxA_Mat'"), NULL, LOAD_None, NULL);
	SPTutDOMB->ImageStyle = EImgStyle::ISTY_Stretched;
	SPTutDOMB->WinTop = 0.495846;
	SPTutDOMB->WinLeft = 0.097344;
	SPTutDOMB->WinWidth = 0.303;
	SPTutDOMB->WinHeight = 0.304;
	UGUILabel* SPTutDOML = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPTutDOML->TextAlign = ETextAlign::TXTA_Center;
	SPTutDOML->StyleName = "TextButton";
	SPTutDOML->WinTop = 0.8;
	SPTutDOML->WinLeft = 0.05;
	SPTutDOML->WinWidth = 0.4;
	SPTutDOML->WinHeight = 0.1;
	UGUIImage* SPTutCTF = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPTutCTF->ImageStyle = EImgStyle::ISTY_Stretched;
	SPTutCTF->X1 = 0;
	SPTutCTF->Y1 = 0;
	SPTutCTF->X2 = 1023;
	SPTutCTF->Y2 = 767;
	SPTutCTF->WinTop = 0.05;
	SPTutCTF->WinLeft = 0.6;
	SPTutCTF->WinWidth = 0.3;
	SPTutCTF->WinHeight = 0.3;
	UGUIImage* SPTutCTFB = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPTutCTFB->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxA_Mat.BorderBoxA_Mat'"), NULL, LOAD_None, NULL);
	SPTutCTFB->ImageStyle = EImgStyle::ISTY_Stretched;
	SPTutCTFB->WinTop = 0.045846;
	SPTutCTFB->WinLeft = 0.597344;
	SPTutCTFB->WinWidth = 0.303;
	SPTutCTFB->WinHeight = 0.304;
	UGUILabel* SPTutCTFL = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPTutCTFL->TextAlign = ETextAlign::TXTA_Center;
	SPTutCTFL->StyleName = "TextButton";
	SPTutCTFL->WinTop = 0.35;
	SPTutCTFL->WinLeft = 0.55;
	SPTutCTFL->WinWidth = 0.4;
	SPTutCTFL->WinHeight = 0.1;
	UGUIImage* SPTutBR = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPTutBR->ImageStyle = EImgStyle::ISTY_Stretched;
	SPTutBR->X1 = 0;
	SPTutBR->Y1 = 0;
	SPTutBR->X2 = 1023;
	SPTutBR->Y2 = 767;
	SPTutBR->WinTop = 0.5;
	SPTutBR->WinLeft = 0.6;
	SPTutBR->WinWidth = 0.3;
	SPTutBR->WinHeight = 0.3;
	UGUIImage* SPTutBRB = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPTutBRB->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxA_Mat.BorderBoxA_Mat'"), NULL, LOAD_None, NULL);
	SPTutBRB->ImageStyle = EImgStyle::ISTY_Stretched;
	SPTutBRB->WinTop = 0.495846;
	SPTutBRB->WinLeft = 0.597344;
	SPTutBRB->WinWidth = 0.303;
	SPTutBRB->WinHeight = 0.304;
	UGUILabel* SPTutBRL = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPTutBRL->TextAlign = ETextAlign::TXTA_Center;
	SPTutBRL->StyleName = "TextButton";
	SPTutBRL->WinTop = 0.8;
	SPTutBRL->WinLeft = 0.55;
	SPTutBRL->WinWidth = 0.4;
	SPTutBRL->WinHeight = 0.1;
	SelectMessage = "Click to play tutorial for";
	bFillHeight = true;
	Controls = { SPTutDM,SPTutDMB,SPTutDML,SPTutDMButton,SPTutDOM,SPTutDOMB,SPTutDOML,SPTutDOMButton,SPTutCTF,SPTutCTFB,SPTutCTFL,SPTutCTFButton,SPTutBR,SPTutBRB,SPTutBRL,SPTutBRButton };
	WinTop = 0.15;
	WinHeight = 0.77;
}

//const DMIndex = 0;
//const DOMIndex = 1;
//const CTFIndex = 2;
//const BRIndex = 3;
//const NumButtons = 4;

void UTab_SPTutorials::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < 4; i++)
	{
		TutImages[i] = GUIImage(Controls[(i * 4)]);
		TutBorders[i] = GUIImage(Controls[((i * 4) + 1)]);
		TutLabels[i] = GUILabel(Controls[((i * 4) + 2)]);
		TutButtons[i] = GUIButton(Controls[((i * 4) + 3)]);
	}
	for (i = 0; i < 4; i++)
	{
		TutButtons[i].Hint = SelectMessage @ TutLabels[i].Caption;
	}
	*/
}

void UTab_SPTutorials::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (!bShow)
	{
		return;
	}
	bTDMUnlocked = Default.bTDMUnlocked;
	bDOMUnlocked = Default.bDOMUnlocked;
	bCTFUnlocked = Default.bCTFUnlocked;
	bBRUnlocked = Default.bBRUnlocked;
	*/
}

bool UTab_SPTutorials::InternalOnClick(UGUIComponent* Sender)
{
	/*
	FString TutorialName = "";
	if (Sender == TutButtons[0])
	{
		TutorialName = "TUT-DM";
	}
	else
	{
		if (Sender == TutButtons[1])
		{
			TutorialName = "TUT-DOM";
		}
		else
		{
			if (Sender == TutButtons[2])
			{
				TutorialName = "TUT-CTF";
			}
			else
			{
				if (Sender == TutButtons[3])
				{
					TutorialName = "TUT-BR";
				}
				else
				{
					return false;
				}
			}
		}
	}
	if (PlayerOwner().Level.Game.CurrentGameProfile != None)
	{
		PlayerOwner().Level.Game.CurrentGameProfile.bInLadderGame = true;
		PlayerOwner().Level.Game.SavePackage(PlayerOwner().Level.Game.CurrentGameProfile.PackageName);
		PlayerOwner().ConsoleCommand("START" @ TutorialName $ ".ut2?quickstart=true?TeamScreen=false?savegame=" $ PlayerOwner().Level.Game.CurrentGameProfile.PackageName);
	}
	else
	{
		PlayerOwner().ConsoleCommand("START" @ TutorialName $ ".ut2?quickstart=true?TeamScreen=false");
	}
	Controller.CloseAll(false);
	*/
	return true;
}

bool UTab_SPTutorials::CanShowPanel()
{
	//return Super::CanShowPanel();
	return false;    //FAKE   /ELiZ
}