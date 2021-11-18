// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_MOTD/AABrowser_MOTD.h"

UAABrowser_MOTD::UAABrowser_MOTD()
{
	/*
	Begin Object Class=GUIScrollTextBox Name=MyMOTDText
		bNoTeletype=True
		CharDelay=0.05
		EOLDelay=0.1
		bVisibleWhenEmpty=True
		OnCreateComponent=MyMOTDText.InternalOnCreateComponent
		StyleName="ListBox"
		WinTop=0.002679
		WinHeight=0.833203
		RenderWeight=0.6
		TabOrder=1
		bNeverFocus=True
	End Object
	Begin Object Class=GUIButton Name=QuickPlay
		Caption="QUICK PLAY"
		bAutoSize=True
		Hint="Open a dialog that can help you easily find the best online server based on your criteria"
		WinTop=0.866146
		WinLeft=0.42518
		WinWidth=0.161994
		WinHeight=0.079063
		TabOrder=2
		OnClick=AABrowser_MOTD.InternalOnClick
		OnKeyEvent=QuickPlay.InternalOnKeyEvent
	End Object
	Begin Object Class=GUILabel Name=VersionNum
		TextAlign=2
		StyleName="TextLabel"
		WinTop=-0.043415
		WinLeft=0.7935
		WinWidth=0.202128
		WinHeight=0.04
		RenderWeight=20.700001
	End Object
	*/
	//lb_MOTD = GUIScrollTextBox'AGP_Interface.AABrowser_MOTD.MyMOTDText';
	//l_Version = GUILabel'AGP_Interface.AABrowser_MOTD.VersionNum';
	//b_QuickConnect = GUIButton'AGP_Interface.AABrowser_MOTD.QuickPlay';
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

