// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/AAGameMenu_DCDS_Begin/AAGameMenu_DCDS_Begin.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/AAGUILabel/AAGUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAGameMenu_DCDS_Begin::UAAGameMenu_DCDS_Begin()
{
	UGUIButton* DownloadButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DownloadButton->Caption = "Download";
	DownloadButton->WinTop = 0.85;
	DownloadButton->WinLeft = 0.15;
	DownloadButton->WinWidth = 0.25;
	DownloadButton->WinHeight = 0.1;
	DownloadButton->TabOrder = 0;
	DownloadButton->bBoundToParent = true;
	DownloadButton->bScaleToParent = true;
	//DownloadButton->OnClick=AAGameMenu_DCDS_Begin.InternalOnClick;
	//DownloadButton->OnKeyEvent=DownloadButton.InternalOnKeyEvent;
	UGUIButton* CancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CancelButton->Caption = "Cancel";
	CancelButton->WinTop = 0.85;
	CancelButton->WinLeft = 0.6;
	CancelButton->WinWidth = 0.25;
	CancelButton->WinHeight = 0.1;
	CancelButton->TabOrder = 1;
	CancelButton->bBoundToParent = true;
	CancelButton->bScaleToParent = true;
	//CancelButton->OnClick=AAGameMenu_DCDS_Begin.InternalOnClick;
	//CancelButton->OnKeyEvent=CancelButton.InternalOnKeyEvent;
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.85;
	OkButton->WinLeft = 0.375;
	OkButton->WinWidth = 0.25;
	OkButton->WinHeight = 0.1;
	OkButton->TabOrder = 1;
	OkButton->bBoundToParent = true;
	OkButton->bScaleToParent = true;
	OkButton->bVisible = false;
	//OkButton->OnClick=AAGameMenu_DCDS_Begin.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UAAGUILabel* HeadingLabel = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	HeadingLabel->Caption = "DCDS Download";
	HeadingLabel->TextAlign = ETextAlign::TXTA_Center;
	HeadingLabel->TextColor = FColor(200, 200, 200, 255);
	HeadingLabel->TextFont = "AAFontLarge";
	HeadingLabel->StyleName = "LargeText";
	HeadingLabel->WinTop = 0.1;
	HeadingLabel->WinLeft = 0.04;
	HeadingLabel->WinWidth = 0.96;
	HeadingLabel->WinHeight = 0.1;
	HeadingLabel->RenderWeight = 0.3;
	HeadingLabel->bBoundToParent = true;
	HeadingLabel->bScaleToParent = true;
	UAAGUILabel* CaptionLabel = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	CaptionLabel->TextAlign = ETextAlign::TXTA_Center;
	CaptionLabel->TextColor = FColor(200, 200, 200, 255);
	CaptionLabel->TextFont = "AAFontMedium";
	CaptionLabel->bMultiLine = true;
	CaptionLabel->StyleName = "MediumText";
	CaptionLabel->WinTop = 0.3;
	CaptionLabel->WinLeft = 0.04;
	CaptionLabel->WinWidth = 0.96;
	CaptionLabel->WinHeight = 0.1;
	CaptionLabel->RenderWeight = 0.3;
	CaptionLabel->bBoundToParent = true;
	CaptionLabel->bScaleToParent = true;
	l_Heading = HeadingLabel;
	l_Caption = CaptionLabel;
	b_Download = DownloadButton;
	b_Cancel = CancelButton;
	b_OK = OkButton;
	WinTop = 0.225;
	WinLeft = 0.25;
	WinWidth = 0.55;
	WinHeight = 0.5;
}

void UAAGameMenu_DCDS_Begin::HandleParameters(FString Param1, FString Param2)
{
	/*
	local AADeploy_DCDS DCDSPanel;
	Super::HandleParameters(Param1, Param2);
	ForEach AllObjects(class'AGP_Interface.AADeploy_DCDS', DCDSPanel)
	{
		GOTO JL0023;
	JL0023:
	}
	if (DCDSPanel != None)
	{
		AssetFullName = DCDSPanel.GetAssetFullName(Param2);
		if (AssetFullName == "")
		{
			l_Caption.Caption = Repl(class'AGP_Interface.AADeploy_DCDS'.Default.NotFoundCaptionText, "%AssetName%", Param2);
			b_OK.bVisible = true;
			b_Download.bVisible = false;
			b_Cancel.bVisible = false;
		}
		else
		{
			l_Caption.Caption = Repl(class'AGP_Interface.AADeploy_DCDS'.Default.CaptionText, "%AssetTitle%", DCDSPanel.GetLevelMissionName(Param2));
			b_OK.bVisible = false;
			b_Download.bVisible = true;
			b_Cancel.bVisible = true;
		}
	}
	*/
}

void UAAGameMenu_DCDS_Begin::Download()
{
	/*
	local AADeploy_DCDS DCDSPanel;
	ForEach AllObjects(class'AGP_Interface.AADeploy_DCDS', DCDSPanel)
	{
		if (DCDSPanel != None)
		{
			DCDSPanel.DownloadAsset(AssetFullName);
		}
		else
		{
		}
	}
	*/
}

bool UAAGameMenu_DCDS_Begin::InternalOnClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_Download:
		Download();
		Controller.OpenMenu("AGP_Interface.AAMainMenu", "AA BROWSER", "DCDS");
		Controller.CloseMenu();
		return true;
	case b_Cancel:
		Controller.CloseMenu();
		return true;
	case b_OK:
		Controller.CloseMenu();
		return true;
	default:
	}
	*/
	return false;    //FAKE   /ELiZ
}