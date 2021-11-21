// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_MOTD/AABrowser_MOTD.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"

UAABrowser_MOTD::UAABrowser_MOTD()
{
	UGUIScrollTextBox* MyMOTDText = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	MyMOTDText->bNoTeletype = true;
	MyMOTDText->CharDelay = 0.05;
	MyMOTDText->EOLDelay = 0.1;
	MyMOTDText->bVisibleWhenEmpty = true;
	//MyMOTDText->OnCreateComponent=MyMOTDText.InternalOnCreateComponent;
	MyMOTDText->StyleName = "ListBox";
	MyMOTDText->WinTop = 0.002679;
	MyMOTDText->WinHeight = 0.833203;
	MyMOTDText->RenderWeight = 0.6;
	MyMOTDText->TabOrder = 1;
	MyMOTDText->bNeverFocus = true;
	UGUIButton* QuickPlay = NewObject<UGUIButton>(UGUIButton::StaticClass());
	QuickPlay->Caption = "QUICK PLAY";
	QuickPlay->bAutoSize = true;
	QuickPlay->Hint = "Open a dialog that can help you easily find the best online server based on your criteria";
	QuickPlay->WinTop = 0.866146;
	QuickPlay->WinLeft = 0.42518;
	QuickPlay->WinWidth = 0.161994;
	QuickPlay->WinHeight = 0.079063;
	QuickPlay->TabOrder = 2;
	//QuickPlay->OnClick=AABrowser_MOTD.InternalOnClick;
	//QuickPlay->OnKeyEvent=QuickPlay.InternalOnKeyEvent;
	UGUILabel* VersionNum = NewObject<UGUILabel>(UGUILabel::StaticClass());
	VersionNum->TextAlign = ETextAlign::TXTA_Right;
	VersionNum->StyleName = "TextLabel";
	VersionNum->WinTop = -0.043415;
	VersionNum->WinLeft = 0.7935;
	VersionNum->WinWidth = 0.202128;
	VersionNum->WinHeight = 0.04;
	VersionNum->RenderWeight = 20.700001;
	lb_MOTD = MyMOTDText;
	l_Version = VersionNum;
	b_QuickConnect = QuickPlay;
	ReReadyPause = 3;
	RetryMax = 10;
	UpgradeCaption = "UPGRADE";
	VersionString = "Version";
	QuickConnectMenu = "AGP_Interface.AAQuickPlay";
	ConnectFailed = "The America's Army master server could not be reached.  Please try again later.";
	ConnectTimeout = "Your connection to the America's Army master server has timed out";
	PanelCaption = "News from Epic";
}

void UAABrowser_MOTD::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	lb_MOTD.MyScrollText.bClickText = true;
	lb_MOTD.MyScrollText.__OnDblClick__Delegate = LaunchURL;
	*/
}

bool UAABrowser_MOTD::LaunchURL(UGUIComponent* Sender)
{
	/*
	local FString ClickString;
	ClickString = StripColorCodes(lb_MOTD.MyScrollText.ClickedString);
	Controller.LaunchURL(ClickString);
	*/
	return true;
}

void UAABrowser_MOTD::Timer()
{
	/*
	if (RetryCount++ < RetryMax)
	{
		GOTO JL0017;
	}
	KillTimer();
JL0017:
*/
}

void UAABrowser_MOTD::Opened(UGUIComponent* Sender)
{
	/*
	l_Version.Caption = VersionString @ PlayerOwner().Level.EngineVersion;
	if (!GotMOTD)
	{
		DisableComponent(b_QuickConnect);
		Refresh();
	}
	Super::Opened(Sender);
	*/
}

void UAABrowser_MOTD::ShowPanel(bool bShow)
{
	//Super::ShowPanel(bShow);
}

void UAABrowser_MOTD::Refresh()
{
	/*
	KillTimer();
	bUpgrade = false;
	lb_MOTD.Stop();
	RetryCount = 0;
	*/
}

void UAABrowser_MOTD::ReceivedMOTD(EMOTDResponse Command, FString Data)
{
	/*
	switch (Command)
	{
	case 0:
		GotMOTD = true;
		EnableComponent(b_QuickConnect);
		lb_MOTD.SetContent(Data, Chr(13));
		break;
	case 2:
		bOptionalUpgrade = true;
		break;
	case 1:
		bUpgrade = true;
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

void UAABrowser_MOTD::OpenStatusMessage(FString Code, FString Data)
{
	//SetTimer(ReReadyPause, false);
}

void UAABrowser_MOTD::QueryComplete(EResponseInfo ResponseInfo, int32 Info)
{
	/*
	switch (ResponseInfo)
	{
	case 3:
		if (Info == 1)
		{
			RetryCount = RetryMax;
			SetTimer(ReReadyPause, false);
		}
		break;
	case 0:
		OpenStatusMessage("RI_AuthenticationFailed");
		break;
	case 5:
		OpenStatusMessage("RI_DevClient");
		break;
	case 6:
		OpenStatusMessage("RI_BadClient");
		break;
	case 7:
	case 1:
		lb_MOTD.SetContent(ConnectFailed);
		break;
	case 2:
		lb_MOTD.SetContent(ConnectTimeout);
		break;
	default:
	}
	*/
}

void UAABrowser_MOTD::JoinClicked()
{
}

bool UAABrowser_MOTD::IsJoinAvailable(FString& ButtonCaption)
{
	return (bUpgrade || bOptionalUpgrade);
}

bool UAABrowser_MOTD::IsRefreshAvailable(FString& ButtonCaption)
{
	return true;
}

bool UAABrowser_MOTD::InternalOnClick(UGUIComponent* Sender)
{
	return false;
}

void UAABrowser_MOTD::ResetQueryClient(AServerQueryClient* Client)
{
	/*
	Super::ResetQueryClient(Client);
	if (MasterServerClient(Client) != None)
	{
		MasterServerClient(Client).Query.Length = 0;
	}
	*/
}

void UAABrowser_MOTD::BindQueryClient(AServerQueryClient* Client)
{
	/*
	Super::BindQueryClient(Client);
	if (MasterServerClient(Client) != None)
	{
		MasterServerClient(Client).__OnReceivedMOTDData__Delegate = ReceivedMOTD;
		MasterServerClient(Client).__OnQueryFinished__Delegate = QueryComplete;
	}
	*/
}

