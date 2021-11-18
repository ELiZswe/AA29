// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_MOTD/Browser_MOTD.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UBrowser_MOTD::UBrowser_MOTD()
{
	UGUIButton* MyUpgradeButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyUpgradeButton->Caption="UPGRADE";
	MyUpgradeButton->StyleName="SquareMenuButton";
	MyUpgradeButton->WinLeft=0.8;
	MyUpgradeButton->WinWidth=0.2;
	MyUpgradeButton->WinHeight=0.5;
	MyUpgradeButton->bVisible=false;
	//MyUpgradeButton->OnKeyEvent=MyUpgradeButton.InternalOnKeyEvent;
	UGUIButton* MyRefreshButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyRefreshButton->Caption="REFRESH";
	MyRefreshButton->StyleName="SquareMenuButton";
	MyRefreshButton->WinLeft=0.2;
	MyRefreshButton->WinWidth=0.2;
	MyRefreshButton->WinHeight=0.5;
	//MyRefreshButton->OnKeyEvent=MyRefreshButton.InternalOnKeyEvent;
	UGUIButton* MyBackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyBackButton->Caption="BACK";
	MyBackButton->StyleName="SquareMenuButton";
	MyBackButton->WinWidth=0.2;
	MyBackButton->WinHeight=0.5;
	//MyBackButton->OnKeyEvent=MyBackButton.InternalOnKeyEvent;
	UGUIScrollTextBox* MyMOTDText = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	MyMOTDText->CharDelay=0.004;
	MyMOTDText->EOLDelay=0.1;
	//MyMOTDText->OnCreateComponent=MyMOTDText.InternalOnCreateComponent;
	MyMOTDText->WinTop=0.048;
	MyMOTDText->WinLeft=0.05;
	MyMOTDText->WinWidth=0.9;
	MyMOTDText->WinHeight=0.8;
	MyMOTDText->bNeverFocus=true;
	UGUITitleBar* MyStatus = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	MyStatus->bUseTextHeight=false;
	MyStatus->Justification = EeTextAlign::TXTA_Left;
	MyStatus->StyleName="SquareBar";
	MyStatus->WinTop=0.5;
	MyStatus->WinHeight=0.5;
	UGUIPanel* FooterPanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	FooterPanel->Controls = {MyBackButton,MyRefreshButton,MyUpgradeButton,MyStatus};
	FooterPanel->WinTop=0.9;
	FooterPanel->WinHeight=0.1;
	UGUILabel* VersionNum = NewObject<UGUILabel>(UGUILabel::StaticClass());
	VersionNum->TextAlign = ETextAlign::TXTA_Right;
	VersionNum->TextColor=FColor(160, 100, 100, 255);
	VersionNum->WinTop=0.0025;
	VersionNum->WinLeft=0.495;
	VersionNum->WinWidth=0.5;
	VersionNum->WinHeight=0.04;

	ReReadyPause = 2;
	VersionString = "Ver.";
	Controls = { MyMOTDText,	FooterPanel, VersionNum };
}


void UBrowser_MOTD::Timer()
{
	//StatusBar.SetCaption(ReadyString);
}

void UBrowser_MOTD::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	StatusBar = GUITitleBar(GUIPanel(Controls[1]).Controls[3]);
	StatusBar.SetCaption(ReadyString);
	MSC = PlayerOwner().Level.Spawn(Class'IpDrv.MasterServerClient');
	MSC.__OnReceivedMOTDData__Delegate = MyReceivedMOTDData;
	MSC.__OnQueryFinished__Delegate = MyQueryFinished;
	MOTDTextBox = GUIScrollTextBox(Controls[0]);
	GUIButton(GUIPanel(Controls[1]).Controls[0]).__OnClick__Delegate = BackClick;
	GUIButton(GUIPanel(Controls[1]).Controls[1]).__OnClick__Delegate = RefreshClick;
	UpgradeButton = GUIButton(GUIPanel(Controls[1]).Controls[2]);
	UpgradeButton.__OnClick__Delegate = UpgradeClick;
	if (!GotMOTD)
	{
		UpgradeButton.bVisible = false;
		MustUpgrade = false;
		MSC.StartQuery(1);
		StatusBar.SetCaption(StartQueryString);
		SetTimer(0, false);
	}
	Controls[2].bBoundToParent = false;
	GUILabel(Controls[2]).Caption = "UT2004" @ VersionString @ PlayerOwner().Level.EngineVersion;
	*/
}

void UBrowser_MOTD::MyReceivedMOTDData(EMOTDResponse Command, FString Data)
{
	/*
	switch (Command)
	{
	case 0:
		GotMOTD = true;
		MOTDTextBox.SetContent(Data, Chr(13));
		break;
	case 2:
		UpgradeButton.bVisible = true;
		break;
	case 1:
		MustUpgrade = true;
		UpgradeButton.bVisible = true;
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
	}
	*/
}

void UBrowser_MOTD::MyQueryFinished(EResponseInfo ResponseInfo, int32 Info)
{
	/*
	switch (ResponseInfo)
	{
	case 3:
		StatusBar.SetCaption(QueryCompleteString);
		SetTimer(ReReadyPause, false);
		if (!MustUpgrade)
		{
			Browser.MOTDVerified(true);
		}
		break;
	case 0:
		StatusBar.SetCaption(AuthFailString);
		SetTimer(ReReadyPause, false);
		break;
	case 1:
		StatusBar.SetCaption(ConnFailString);
		SetTimer(ReReadyPause, false);
		Browser.MOTDVerified(false);
		MSC.StartQuery(1);
		break;
	case 2:
		StatusBar.SetCaption(ConnTimeoutString);
		Browser.MOTDVerified(false);
		SetTimer(ReReadyPause, false);
		break;
	default:
	}
	*/
}

void UBrowser_MOTD::OnCloseBrowser()
{
	/*
	if (MSC != None)
	{
		MSC.CancelPings();
		MSC.Destroy();
		MSC = None;
	}
	*/
}

bool UBrowser_MOTD::BackClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(true);
	return true;
}

bool UBrowser_MOTD::RefreshClick(UGUIComponent* Sender)
{
	/*
	MustUpgrade = false;
	UpgradeButton.bVisible = false;
	MSC.Stop();
	MSC.StartQuery(1);
	StatusBar.SetCaption(StartQueryString);
	SetTimer(0, false);
	*/
	return true;
}

bool UBrowser_MOTD::UpgradeClick(UGUIComponent* Sender)
{
	//MSC.LaunchAutoUpdate();
	return true;
}