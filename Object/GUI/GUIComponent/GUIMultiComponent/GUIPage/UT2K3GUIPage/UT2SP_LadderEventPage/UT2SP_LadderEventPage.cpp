// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2SP_LadderEventPage/UT2SP_LadderEventPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UUT2SP_LadderEventPage::UUT2SP_LadderEventPage()
{
	UGUIButton* SPLEPMap = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPLEPMap->Caption = "VIEW TUTORIAL";
	SPLEPMap->WinTop = 0.88;
	SPLEPMap->WinLeft = 0.6;
	SPLEPMap->WinWidth = 0.2;
	SPLEPMap->WinHeight = 0.05;
	SPLEPMap->bVisible = false;
	SPLEPMap->bAcceptsInput = false;
	//SPLEPMap->OnKeyEvent=SPLEPMap.InternalOnKeyEvent;
	UGUIButton* SPLEPOK = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPLEPOK->Caption = "CONTINUE";
	SPLEPOK->WinTop = 0.88;
	SPLEPOK->WinLeft = 0.4;
	SPLEPOK->WinWidth = 0.2;
	SPLEPOK->WinHeight = 0.05;
	//SPLEPOK->OnKeyEvent=SPLEPOK.InternalOnKeyEvent;
	UGUILabel* SPLEPtitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPLEPtitle->Caption = "CONGRATULATIONS!";
	SPLEPtitle->TextAlign = ETextAlign::TXTA_Center;
	SPLEPtitle->TextFont = "UT2LargeFont";
	SPLEPtitle->WinTop = 0.06875;
	SPLEPtitle->WinHeight = 0.1;
	UGUILabel* SPLEPcaption = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPLEPcaption->TextAlign = ETextAlign::TXTA_Center;
	SPLEPcaption->TextFont = "UT2SmallFont";
	SPLEPcaption->bMultiLine = true;
	SPLEPcaption->WinTop = 0.716563;
	SPLEPcaption->WinHeight = 0.35;
	UGUIImage* SPLEPimage = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPLEPimage->ImageStyle = EImgStyle::ISTY_Stretched;
	SPLEPimage->X1 = 0;
	SPLEPimage->Y1 = 0;
	SPLEPimage->X2 = 1023;
	SPLEPimage->Y2 = 767;
	SPLEPimage->WinTop = 0.17;
	SPLEPimage->WinLeft = 0.25;
	SPLEPimage->WinWidth = 0.5;
	SPLEPimage->WinHeight = 0.5;
	UGUIImage* SPLEPimageborder = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPLEPimageborder->ImageStyle = EImgStyle::ISTY_Stretched;
	SPLEPimageborder->WinTop = 0.166354;
	SPLEPimageborder->WinLeft = 0.247265;
	SPLEPimageborder->WinWidth = 0.505078;
	SPLEPimageborder->WinHeight = 0.507421;
	Controls = { SPLEPtitle,SPLEPcaption,SPLEPimage,SPLEPOK,SPLEPimageborder,SPLEPMap };
	WinHeight = 1;
}

void UUT2SP_LadderEventPage::InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(pMyController, MyOwner);
	lblTitle = GUILabel(Controls[0]);
	lblCaption = GUILabel(Controls[1]);
	btnOK = GUIButton(Controls[3]);
	gImage = GUIImage(Controls[2]);
	gImage.Image = Material(DynamicLoadObject("Laddershots.TeamDMShot", Class'Material'));
	btnMap = GUIButton(Controls[5]);
	btnOK.__OnClick__Delegate = InternalOnClick;
	btnMap.__OnClick__Delegate = InternalOnClick;
	*/
}

bool UUT2SP_LadderEventPage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == btnOK)
	{
		return Controller.CloseMenu();
	}
	else
	{
		if (Sender == btnMap)
		{
			PlayerOwner().Level.Game.CurrentGameProfile.bInLadderGame = true;
			PlayerOwner().Level.Game.SavePackage(PlayerOwner().Level.Game.CurrentGameProfile.PackageName);
			PlayerOwner().ConsoleCommand("START" @ TutorialName $ ".ut2?quickstart=true?TeamScreen=false?savegame=" $ PlayerOwner().Level.Game.CurrentGameProfile.PackageName);
			Controller.CloseAll(false);
			return true;
		}
	}
	*/
	return false;
}

void UUT2SP_LadderEventPage::SetTutorialName(FString tutname)
{
	/*
	TutorialName = tutname;
	if (tutname == "")
	{
		btnMap.bVisible = false;
		btnMap.bAcceptsInput = false;
	}
	else
	{
		btnMap.bVisible = true;
		btnMap.bAcceptsInput = true;
		btnOK.WinLeft = 0.2;
	}
	*/
}